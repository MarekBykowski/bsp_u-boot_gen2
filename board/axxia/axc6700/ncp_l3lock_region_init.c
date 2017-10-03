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
#include "ncp_sysmem_ext.h"
#include "ncp_sysmem_lsiphy.h" 
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
	ncp_st_t        ncpStatus = NCP_ST_SUCCESS;
	ncp_uint32_t	numLockedWays=0;
	int		i=0, j=0;
	ncp_uint64_t	regValue = 0;
        ncp_uint32_t tmp, tmp1;

#ifndef __UBOOT__	
	NCP_ASSERT(l3lock_params != NULL, NCP_ST_INVALID_PARAMETER);
#endif
	printf("mb: Enables Non-secure access to Secure registers\n");
	ncr_write32( NCP_REGION_ID(0x1e0, 0x0), 0x0, 1);

#define MANUALLY 1
#if MANUALLY
{
	unsigned int base = 0x80000c80;
	l3lock_params->totalL3LockedSize = 2; /*2, 4, 8, 16M*/

	for (j=0; j<4; j++) 
		l3lock_params->region[j] = 0;

	switch (l3lock_params->totalL3LockedSize) {
	case (2):
		l3lock_params->region[0] = base;
		break;
	case (4):
		l3lock_params->region[0] = base;
		l3lock_params->region[1] = base += (SZ_2M >> 20);
		break;
	case (8):
		l3lock_params->region[0] = base;
		l3lock_params->region[1] = base += (SZ_2M >> 20);
		l3lock_params->region[2] = base += (SZ_2M >> 20);
		l3lock_params->region[3] = base += (SZ_2M >> 20);
		break;
	case (16):
		l3lock_params->region[0] = base;
		l3lock_params->region[1] = base += (SZ_4M >> 20); 
		l3lock_params->region[2] = base += (SZ_4M >> 20);
		l3lock_params->region[3] = base += (SZ_4M >> 20);
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
                	NCP_CALL(NCP_ST_INVALID_PARAMETER);
		}
	} else {
		if (l3lock_params->totalL3LockedSize == 2) {
			numLockedWays = 1;
		} else if (l3lock_params->totalL3LockedSize == 4) {
			numLockedWays = 2;
		} else if (l3lock_params->totalL3LockedSize == 8) {
			numLockedWays = 4;
		} else if (l3lock_params->totalL3LockedSize == 16) {
			numLockedWays = 8;
		} else {
			printf("Total Locked size supported on ASIC is either 2/4/8/16 MB\n");
                	NCP_CALL(NCP_ST_INVALID_PARAMETER);
		}
	}

	/* Setup secure mode */
    ncr_read32( NCP_REGION_ID(0x170, 0x1), 0x42800, &tmp);
	printf("mb: read 0x170,0x1,0x42800 = 0x%x\n", tmp);

	ncr_write32( NCP_REGION_ID(0x170, 1), 0x42800, 0x2);

    ncr_read32( NCP_REGION_ID(0x170, 0x1), 0x42800, &tmp1);
	printf("mb: wrote 0x2, read back 0x170,0x1,0x42800 = 0x%x\n", tmp1);

	/* setup regions */
	for (j=0; j < 4; j++)
	{
		/* region setup */
		regValue = (((ncp_uint64_t)(l3lock_params->region[j] & 0x80000000)) <<32) |
			(((ncp_uint64_t)(l3lock_params->region[j] & 0xFFFFFF)) << 20);
			
		for (i=0x20; i <= 0x27; i++)
		{
			ncr_write32( NCP_REGION_ID(0x1e0, i), 0x0048+(j*8), 
					(ncp_uint32_t)(regValue & 0xFFFFFFFF));
			ncr_write32( NCP_REGION_ID(0x1e0, i), 0x0048+(j*8)+4, 
					(ncp_uint32_t)((regValue >> 32) & 0xFFFFFFFF));
		}
	}

	/* setup number of locked ways */
	for (i=0x20; i <= 0x27; i++)
	{
			printf("mb: %s(): ncr_write32( NCP_REGION_ID(0x1e0, i), 0x0040, numLockedWays) 0x%x\n", __func__, numLockedWays);
        	ncr_write32( NCP_REGION_ID(0x1e0, i), 0x0040, numLockedWays);
			ncr_read32( NCP_REGION_ID(0x1e0, i), 0x0040, &tmp1);
			printf("mb: %s(): ncr_read32( NCP_REGION_ID(0x1e0, i), 0x0040, numLockedWays ) 0x%x\n",
				__func__, tmp1);

	}

	/* Set it back to non-secure mode or the mode we started with. */
	ncr_write32( NCP_REGION_ID(0x170, 1), 0x42800, tmp);
    ncr_read32( NCP_REGION_ID(0x170, 0x1), 0x42800, &tmp1);
	printf("mb: wrote 0x%x, read back 0x170,0x1,0x42800 = 0x%x\n", tmp, tmp1);

NCP_RETURN_LABEL
	return ncpStatus;
}


