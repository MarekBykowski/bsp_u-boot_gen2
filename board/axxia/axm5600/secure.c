/*
 *  board/axxia/axm5600/secure.c
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

int
setup_security(void)
{
	/*
	  For now, allow access from anywhere, to anywhere.
	*/

	/* MMAP-GPREG is 0x8032900000 (0x170.0.0) */
	/* MMAP-SCB is 0x8032000000 (0x170.1.0) */
	/* PERIPH-GPREG is 0x8080230000 (0x171.0.0) */
	/* PERIPH-SCB is 0x8080400000 (0x171.1.0) */
	/* TZC is 0x8004140000 (0x1d2.0.0) */

	/* 0x171.1.0xc = 0xffff */
	writel(0xffff, (PERIPH_SCB + 0xc));
	/* 0x171.1.0x10 = 0xffff */
	writel(0xffff, (PERIPH_SCB + 0x10));
	/* 0x170.1.0x54 = 0xffff */
	writel(0xffff, (MMAP_SCB + 0x54));
	/* 0x170.1.0x43800 0x2 */
	writel(0x2, (MMAP_SCB + 0x43800));
	/* 0x170.1.0x48 = 1 */
	writel(0x1, (MMAP_SCB + 0x48));

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

	/*
	  Handle sRIO and GPDMA
	*/

#if 0
#if defined(CONFIG_AXXIA_PCI) && defined(CONFIG_AXXIA_ANY_56XX)

	unsigned int value;

	switch ((pciesrio->control >> 22) & 0xf) {
	case 4:
		value = readl(PCIAXISCB + 0x18);
		value |= 1;
		writel(value, (PCIAXISCB + 0x18));
		value = readl(PCIAXISCB + 0x47800);
		value |= 3;
		writel(value, (PCIAXISCB + 0x47800));
		/* intentionaly fall through */
	case 3:
		value = readl(PCIAXISCB + 0x14);
		value |= 1;
		writel(value, (PCIAXISCB + 0x14));
		value = readl(PCIAXISCB + 0x46800);
		value |= 3;
		writel(value, (PCIAXISCB + 0x46800));
		break;
	default:
		break;
	}

#endif	/* CONFIG_AXXIA_PCI && CONFIG_AXXIA_ANY_56XX */
#endif

	return 0;
}
