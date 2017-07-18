/*
 *  board/axxia/axc6700/secure.c
 *
 *  Copyright (C) 2015 Intel (john.jacques@intel.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307	 USA
 */

#include <config.h>
#include <common.h>
#include <version.h>
#include <serial.h>
#include <malloc.h>
#include <spl.h>
#include <asm/io.h>

/*
  ==============================================================================
  ==============================================================================
  Local Stuff
  ==============================================================================
  ==============================================================================
*/

/*
  ==============================================================================
  ==============================================================================
  Global Stuff
  ==============================================================================
  ==============================================================================
*/

/*
  ------------------------------------------------------------------------------
  setup_security
*/

int bar(int kkk)
{
	return kkk++;
}

int foo(int l)
{
	int k=4, ll;
	ll = bar(k);
	return ll+l;
}

int
setup_security(void)
{
		int ret = foo(5);
		ret = 0;
        /*
          For now, allow access from anywhere, to anywhere.
	*/

        /* MMAP-GPREG is 0x8032900000 (0x170.0.0) */
        /* MMAP-SCB is 0x8032000000 (0x170.1.0) */
        /* PERIPH-GPREG is 0x8080230000 (0x171.0.0) */
        /* PERIPH-SCB is 0x8080400000 (0x171.1.0) */
        /* TZC is 0x8004140000 (0x1d2.0.0) */

        /* 0x171.1.0x10 = 0xffff */
        writel(0xffff, (PERIPH_SCB + 0x10));
        /* 0x171.1.0x18 = 0xffff */
        writel(0xffff, (PERIPH_SCB + 0x18));
        /* 0x171.1.0x20 = 0xffff */
        writel(0xffff, (PERIPH_SCB + 0x20));
        /* 0x170.1.0x10 = 0xffff */
        writel(0xffff, (MMAP_SCB + 0x10));
        /* 0x170.1.0x43800 0x2 */
        writel(0x2, (MMAP_SCB + 0x43800));
        /* 0x170.1.0x8 = 1 */
        writel(0x1, (MMAP_SCB + 0x8));

#ifdef SYSCACHE_ONLY_MODE
        /*
          The RNI NIC-400 is currently configured to signal non-secured transactions only. 
          Override all transactions coming out of RNI as a SECURE. Use it only in a Secure state.
        */
        writel(0x2, (MMAP_SCB + 0x42800));
#endif

	/*
	  Set up the TZC
	*/

	/* Make sure the TZC has finished internal configuration. */
	(void)readl(TZC + 8);
	/* 0x1d2.0.0x8 = 0x1 */
	writel(0x1, (TZC + 0x8));
	/* 0x1d2.0.0x110 = 0xc000000f */
	writel(0xc000000f, (TZC + 0x110));
        /* 0x1d2.0.0x114 = 0xffffffff */
        writel(0xffffffff, (TZC + 0x114));

	return ret;
}
