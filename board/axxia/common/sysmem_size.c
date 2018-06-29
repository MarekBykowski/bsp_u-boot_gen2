/*
 * sysmem_size.c
 *
 * Copyright (C) 2010 LSI Corporation
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software;you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation;either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY;without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program;if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>

DECLARE_GLOBAL_DATA_PTR;

/*
  ------------------------------------------------------------------------------
  sysmem_size
*/

unsigned long long
sysmem_size(void)
{
	/*unsigned long long sdram_capacity_bytes;
	unsigned long sdram_device_width_bits;
	unsigned long primary_bus_width_bits;*/
#ifndef CONFIG_SPL_BUILD
	/*int rc;*/
#endif

#ifdef CONFIG_AXXIA_EMU
	sysmem->totalSize = 4ULL * (1ULL << 30);

	return sysmem->totalSize;
#endif

#if 0
#ifndef CONFIG_SPL_BUILD
	rc = read_parameters();

#ifdef CONFIG_AXXIA_SIM
	if (0 != rc) {
		sysmem->totalSize = 16ULL * (1ULL << 30);

		return sysmem->totalSize;
	}
#else  /* CONFIG_AXXIA_SIM */
	if (0 != rc)
		acp_failure(__FILE__, __FUNCTION__, __LINE__);
#endif	/* CONFIG_AXXIA_SIM */
#endif	/* CONFIG_SPL_BUILD */

	sdram_capacity_bytes =
		(1ULL << sysmem->sdram_device_density) *
		((256 * 1024 * 1024) / 8);
	sdram_device_width_bits = 4 * (1 << sysmem->sdram_device_width);
	primary_bus_width_bits = 8 * (1 << sysmem->primary_bus_width);
	sdram_capacity_bytes =
		sysmem->num_interfaces * sysmem->num_ranks_per_interface *
		sdram_capacity_bytes *
		(primary_bus_width_bits / sdram_device_width_bits);
	sysmem->totalSize = sdram_capacity_bytes;

	return sysmem->totalSize;
#endif
	return (unsigned long long)((unsigned long)(16384*1024)*1024);
}

/*
  ------------------------------------------------------------------------------
  get_effective_memsize
*/

phys_size_t
get_effective_memsize(void)
{
	return CONFIG_UBOOT_MAX_MEM;
}

/*
  ------------------------------------------------------------------------------
  dram_init_banksize
*/

void
dram_init_banksize(void)
{
	gd->bd->bi_dram[0].start = 0;
	gd->bd->bi_dram[0].size = CONFIG_UBOOT_MAX_MEM;

	return;
}
