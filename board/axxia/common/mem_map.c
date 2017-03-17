#include <config.h>
#include "xlat_tables.h"

/*******************************************************************************
 * Macro generating the code for the function setting up the pagetables as per
 * the platform memory map & initialize the mmu, for the given exception level
 ******************************************************************************/
#define DEFINE_CONFIGURE_MMU_EL(_el)				               \
	void configure_mmu_el##_el(unsigned long total_base,	               \
				  unsigned long total_size,	               \
				  unsigned long ro_start,	               \
				  unsigned long ro_limit)	               \
	{							               \
	       mmap_add_region(total_base,total_base, \
			       total_size,             \
			       MT_MEMORY | MT_RW | MT_SECURE);	\
                                                                  \
	       mmap_add_region(DICKENS, DICKENS, 0x0040000000,       \
			       MT_DEVICE | MT_RW | MT_SECURE);                 \
		                                                               \
	       mmap_add_region(IO, IO, 0x0040000000,       \
			       MT_DEVICE | MT_RW | MT_SECURE);                 \
													\
	       mmap_add_region(0, 0, CONFIG_UBOOT_MAX_MEM, \
					MT_MEMORY | MT_RW | MT_SECURE | MT_CACHED);     \
		                                                               \
	       init_xlat_tables();				               \
								               \
	       enable_mmu_el##_el(DISABLE_DCACHE);		               \
	}


/* Define EL2 and EL3 variants of the function initialising the MMU */
/*DEFINE_CONFIGURE_MMU_EL(2)*/
DEFINE_CONFIGURE_MMU_EL(3)
