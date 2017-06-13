/*
 * Copyright 2014 Freescale Semiconductor, Inc.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/io.h>
#include <asm/errno.h>
#include <asm/system.h>
#include <asm/armv8/mmu.h>
#include <asm/io.h>
#include "xlat.h"

#define SECTION_SHIFT_L0		39UL
#define SECTION_SHIFT_L1		30UL
#define SECTION_SHIFT_L2		21UL
#define BLOCK_SIZE_L0			0x8000000000
#define BLOCK_SIZE_L1			0x40000000
#define BLOCK_SIZE_L2			0x200000

#define NUM_OF_ENTRY		512

#define TCR_EL2_PS_40BIT	(2 << 16)
#define LSCH3_VA_BITS		(40)
#define LSCH3_TCR	(TCR_TG0_4K		| \
			TCR_EL2_PS_40BIT	| \
			TCR_SHARED_NON		| \
			TCR_ORGN_NC		| \
			TCR_IRGN_NC		| \
			TCR_T0SZ(LSCH3_VA_BITS))
#define LSCH3_TCR_FINAL	(TCR_TG0_4K		| \
			TCR_EL2_PS_40BIT	| \
			TCR_SHARED_OUTER	| \
			TCR_ORGN_WBWA		| \
			TCR_IRGN_WBWA		| \
			TCR_T0SZ(LSCH3_VA_BITS))

#define CONFIG_SYS_FSL_CCSR_BASE	0x00000000
#define CONFIG_SYS_FSL_CCSR_SIZE	0x10000000
#define CONFIG_SYS_FSL_QSPI_BASE1	0x20000000
#define CONFIG_SYS_FSL_QSPI_SIZE1	0x10000000
#define CONFIG_SYS_FSL_IFC_BASE1	0x30000000
#define CONFIG_SYS_FSL_IFC_SIZE1	0x10000000
#define CONFIG_SYS_FSL_IFC_SIZE1_1	0x400000
#define CONFIG_SYS_FSL_DRAM_BASE1	0x80000000
#define CONFIG_SYS_FSL_DRAM_SIZE1	0x80000000
#define CONFIG_SYS_FSL_QSPI_BASE2	0x400000000
#define CONFIG_SYS_FSL_QSPI_SIZE2	0x100000000
#define CONFIG_SYS_FSL_IFC_BASE2	0x500000000
#define CONFIG_SYS_FSL_IFC_SIZE2	0x100000000
#define CONFIG_SYS_FSL_DCSR_BASE	0x700000000
#define CONFIG_SYS_FSL_DCSR_SIZE	0x40000000
#define CONFIG_SYS_FSL_MC_BASE		0x80c000000
#define CONFIG_SYS_FSL_MC_SIZE		0x4000000
#define CONFIG_SYS_FSL_NI_BASE		0x810000000
#define CONFIG_SYS_FSL_NI_SIZE		0x8000000
#define CONFIG_SYS_FSL_QBMAN_BASE	0x818000000
#define CONFIG_SYS_FSL_QBMAN_SIZE	0x8000000
#define CONFIG_SYS_FSL_QBMAN_SIZE_1	0x4000000
#define CONFIG_SYS_PCIE1_PHYS_SIZE	0x200000000
#define CONFIG_SYS_PCIE2_PHYS_SIZE	0x200000000
#define CONFIG_SYS_PCIE3_PHYS_SIZE	0x200000000
#define CONFIG_SYS_PCIE4_PHYS_SIZE	0x200000000
#define CONFIG_SYS_FSL_WRIOP1_BASE	0x4300000000
#define CONFIG_SYS_FSL_WRIOP1_SIZE	0x100000000
#define CONFIG_SYS_FSL_AIOP1_BASE	0x4b00000000
#define CONFIG_SYS_FSL_AIOP1_SIZE	0x100000000
#define CONFIG_SYS_FSL_PEBUF_BASE	0x4c00000000
#define CONFIG_SYS_FSL_PEBUF_SIZE	0x400000000
#define CONFIG_SYS_FSL_DRAM_BASE2	0x8080000000
#define CONFIG_SYS_FSL_DRAM_SIZE2	0x7F80000000

struct sys_mmu_table {
	u64 virt_addr;
	u64 phys_addr;
	u64 size;
	u64 memory_type;
	u64 share;
};

static const struct sys_mmu_table lsch3_early_mmu_table[] = {
	{ 0x8031000000, 0x8031000000, 
	  256*1024, MT_NORMAL_NC, PMD_SECT_NON_SHARE },
	{ 0, 0,
	  0x40000000, MT_NORMAL, PMD_SECT_NON_SHARE },
};


struct table_info {
	u64 *ptr;
	u64 table_base;
	u64 entry_size;
};

/*
 * Set the block entries according to the information of the table.
 */
static int set_block_entry(const struct sys_mmu_table *list,
			   struct table_info *table)
{
	u64 block_size = 0, block_shift = 0;
	u64 block_addr, index;
	int j;

	if (table->entry_size == BLOCK_SIZE_L1) {
		block_size = BLOCK_SIZE_L1;
		block_shift = SECTION_SHIFT_L1;
	} else if (table->entry_size == BLOCK_SIZE_L2) {
		block_size = BLOCK_SIZE_L2;
		block_shift = SECTION_SHIFT_L2;
	} else {
		return -EINVAL;
	}

	block_addr = list->phys_addr;
	index = (list->virt_addr - table->table_base) >> block_shift;

	for (j = 0; j < (list->size >> block_shift); j++) {
		set_pgtable_section(table->ptr,
				    index,
				    block_addr,
				    list->memory_type,
				    list->share);
		block_addr += block_size;
		index++;
	}

	return 0;
}

/*
 * Find the corresponding table entry for the list.
 */
static int find_table(const struct sys_mmu_table *list,
		      struct table_info *table, u64 *level0_table)
{
	u64 index = 0, level = 0;
	u64 *level_table = level0_table;
	u64 temp_base = 0, block_size = 0, block_shift = 0;

	while (level < 3) {
		if (level == 0) {
			block_size = BLOCK_SIZE_L0;
			block_shift = SECTION_SHIFT_L0;
		} else if (level == 1) {
			block_size = BLOCK_SIZE_L1;
			block_shift = SECTION_SHIFT_L1;
		} else if (level == 2) {
			block_size = BLOCK_SIZE_L2;
			block_shift = SECTION_SHIFT_L2;
		}

		index = 0;
		while (list->virt_addr >= temp_base) {
			index++;
			temp_base += block_size;
		}

		temp_base -= block_size;

		if ((level_table[index - 1] & PMD_TYPE_MASK) ==
		    PMD_TYPE_TABLE) {
			level_table = (u64 *)(level_table[index - 1] &
				      ~PMD_TYPE_MASK);
			level++;
			continue;
		} else {
			if (level == 0)
				return -EINVAL;

			if ((list->phys_addr + list->size) >
			    (temp_base + block_size * NUM_OF_ENTRY))
				return -EINVAL;

			/*
			 * Check the address and size of the list member is
			 * aligned with the block size.
			 */
			if (((list->phys_addr & (block_size - 1)) != 0) ||
			    ((list->size & (block_size - 1)) != 0))
				return -EINVAL;

			table->ptr = level_table;
			table->table_base = temp_base -
					    ((index - 1) << block_shift);
			table->entry_size = block_size;

			return 0;
		}
	}
	return -EINVAL;
}

/*
 * To start MMU before DDR is available, we create MMU table in SRAM.
 * The base address of SRAM is CONFIG_SYS_FSL_OCRAM_BASE. We use three
 * levels of translation tables here to cover 40-bit address space.
 * We use 4KB granule size, with 40 bits physical address, T0SZ=24
 * Level 0 IA[39], table address @0
 * Level 1 IA[38:30], table address @0x1000, 0x2000
 * Level 2 IA[29:21], table address @0x3000, 0x4000
 * Address above 0x5000 is free for other purpose.
 */
static inline void early_mmu_setup(u64* pgt)
{
	unsigned int el, i;
	u64 *level0_table = (u64 *) pgt;
	u64 *level1_table0 = (u64 *)(pgt + 0x1000);
	u64 *level1_table1 = (u64 *)(pgt + 0x2000);
	u64 *level2_table0 = (u64 *)(pgt + 0x3000);
	u64 *level2_table1 = (u64 *)(pgt + 0x4000);
	struct table_info table = {level0_table, 0, BLOCK_SIZE_L0};

	printf("mb: %s() -> pgt is %p\n", __func__, (void*)pgt);
	asm volatile("mb2: b mb2\n");

	/* Invalidate all table entries */
	memset(level0_table, 0, 0x5000);

	/* Fill in the table entries */
	set_pgtable_table(level0_table, 0, level1_table0);
	set_pgtable_table(level0_table, 1, level1_table1);
	set_pgtable_table(level1_table0, 0, level2_table0);
	set_pgtable_table(level1_table0,
			  /*CONFIG_SYS_FLASH_BASE >> SECTION_SHIFT_L1*/ 1,
			  level2_table1);

	/* Find the table and fill in the block entries */
	for (i = 0; i < ARRAY_SIZE(lsch3_early_mmu_table); i++) {
		if (find_table(&lsch3_early_mmu_table[i],
			       &table, level0_table) == 0) {
			/*
			 * If find_table() returns error, it cannot be dealt
			 * with here. Breakpoint can be added for debugging.
			 */
			set_block_entry(&lsch3_early_mmu_table[i], &table);
			/*
			 * If set_block_entry() returns error, it cannot be
			 * dealt with here too.
			 */
		}
	}

	el = current_el();
	set_ttbr_tcr_mair(el, (u64)level0_table, LSCH3_TCR, MEMORY_ATTRIBUTES);
	set_sctlr(get_sctlr() | CR_M);
}

/*
 * The final tables look similar to early tables, but different in detail.
 * These tables are in DRAM. Sub tables are added to enable cache for
 * QBMan and OCRAM.
 *
 * Level 1 table 0 contains 512 entries for each 1GB from 0 to 512GB.
 * Level 1 table 1 contains 512 entries for each 1GB from 512GB to 1TB.
 * Level 2 table 0 contains 512 entries for each 2MB from 0 to 1GB.
 * Level 2 table 1 contains 512 entries for each 2MB from 32GB to 33GB.
 */

int axxia_xlat_init(u64 *pgt)
{
	/*icache_enable();
	__asm_invalidate_dcache_all();
	__asm_invalidate_tlb_all();*/
	early_mmu_setup(pgt);
	/*set_sctlr(get_sctlr() | CR_C);*/
	return 0;
}
