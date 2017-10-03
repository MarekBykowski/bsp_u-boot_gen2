/*
 *  Copyright (C) 2016 Intel (john.jacques@intel.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifdef __UBOOT__
#include <common.h>
#include <asm/io.h>
#include "ncp_l3lock_region.h" 
#else
#include <stdio.h>
#include "ncp.h"
#include "ncp_pvt.h"
#include "ncp_sysmem_ext.h"
#include "ncp_sysmem_lsiphy.h"
#include "ncp_l3lock_region.h"

#endif

ncp_st_t
ncp_l3lock_region_init ( ncp_dev_hdl_t   dev, ncp_l3lock_region_info_t *l3lock_params, ncp_bool_t isFPGA )
{
	unsigned j, i, numLockedWays = 0;
	unsigned long regValue;
	printf("mb: Enables Non-secure access to Secure registers\n");
	writel(1, DICKENS + 0x0);
	printf("mb: Enables Non-secure access to Secure registers (LSBit set?) 0x%x\n", readl(DICKENS + 0x0)); 

#define MANUALLY 1
#if MANUALLY
{
	unsigned int base = 0xc8000001;
	l3lock_params->totalL3LockedSize = 2; /*1, 2, 4, 6M*/

	for (j=0; j<4; j++) 
		l3lock_params->region[j] = 0;

	switch (l3lock_params->totalL3LockedSize) {
	case (1):
		l3lock_params->region[0] = base;
		l3lock_params->region[1] = base += SZ_512K;
		break;
	case (2):
		l3lock_params->region[0] = base;
		l3lock_params->region[1] = base += SZ_512K;
		l3lock_params->region[2] = base += SZ_512K;
		l3lock_params->region[3] = base += SZ_512K;
		break;
	case (4):
		l3lock_params->region[0] = base;
		l3lock_params->region[1] = base += SZ_1M;
		l3lock_params->region[2] = base += SZ_1M;
		l3lock_params->region[3] = base += SZ_1M;
		break;
	case (6):
		l3lock_params->region[0] = base;
		l3lock_params->region[1] = base += SZ_1M;
		l3lock_params->region[2] = base += SZ_2M;
		l3lock_params->region[3] = base += SZ_2M;
		break;
	default:
		return 0;
	}
}
#endif 

	printf("mb: l3lock_params->totalL3LockedSize %08x\n"
		"l3lock_params->regions[0-3]\t %08x %08x %08x %08x\n",
		l3lock_params->totalL3LockedSize,
		l3lock_params->region[0], l3lock_params->region[1],
		l3lock_params->region[2], l3lock_params->region[3]);

	if (l3lock_params->totalL3LockedSize == 0) return NCP_ST_SUCCESS;

	if (isFPGA) 
	{
		if (l3lock_params->totalL3LockedSize == 8) {
			numLockedWays = 8;
		} else if (l3lock_params->totalL3LockedSize == 12) {
			numLockedWays = 12;
		} else {
			printf("Total Locked size supported on FPGA is either 8 or 12 MB\n");
		}
	} else {
		if (l3lock_params->totalL3LockedSize == 1) {
			numLockedWays = 2;
		} else if (l3lock_params->totalL3LockedSize == 2) {
			numLockedWays = 4;
		} else if (l3lock_params->totalL3LockedSize == 4) {
			numLockedWays = 8;
		} else if (l3lock_params->totalL3LockedSize == 6) {
			numLockedWays = 12;
		} else {
			printf("Total Locked size supported on ASIC is either 2/4/8/12 MB\n");
		}
	}

	/* setup regions */
	for (j=0; j < 4; j++)
	{
		/* region setup.*/ 
		regValue = (((unsigned long)l3lock_params->region[j]&0x1)<<63) | /*Set valid bit 63rd */
			(l3lock_params->region[j] & 0xFFFFFFFE); /*Clear Valid bit from address*/
			
		for (i=0x20; i <= 0x27; i++)
		{
			unsigned int val = (unsigned int)(regValue & 0xFFFFFFFF);
			unsigned long addr = (unsigned long)(DICKENS + (i<<16) + 0x0048 + (j*8));
			writel(val, addr);
			printf("mb: writing 0x%x @ 0x%lx\n", val, addr);
			val = (unsigned int)((regValue >> 32) & 0xFFFFFFFF);
			addr = (unsigned long)(DICKENS + (i<<16) + 0x0048 + (j*8) + 4);
			writel(val, addr);
			printf("mb: writing 0x%x @ 0x%lx\n", val, addr);
		}
	}

	/* setup number of locked ways */
	for (i=0x20; i <= 0x27; i++) {
		unsigned long addr = (unsigned long) (DICKENS + (i<<16) + 0x0040);
		writel(numLockedWays, addr);
		printf("mb: writing numLockedWays 0x%x @ 0x%lx\n", numLockedWays, addr);
	}

	return 0;
}


