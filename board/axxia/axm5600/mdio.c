/*
 * mdio.c
 *
 * Basic MDIO access using the custom LSI controller.
 *
 * Copyright (C) 2009 LSI Corporation
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/*#define DEBUG*/

#include <config.h>
#include <common.h>
#include <asm/io.h>
#include <miiphy.h>
#include <malloc.h>

#undef BZ33327_WA
/*#define BZ33327_WA*/

#define MDIO_REG_CTRL		0x00
#define MDIO_REG_STATUS		0x04
#define MDIO_REG_CLK_OFFSET	0x08
#define MDIO_REG_CLK_PERIOD	0x0c

static int initialize = 0;

extern int axxia_mdio_reset(struct mii_dev *bus);
extern int axxia_mdio_write(struct mii_dev *bus, int addr, int devad, int reg, u16 val);
extern int axxia_mdio_read(struct mii_dev *bus, int addr, int devad, int reg);
extern int phy_by_index[];


/*
  ----------------------------------------------------------------------
  mdio_initialize
*/

int
mdio_initialize(const char *mdio_dev)
{
	unsigned long offset, period;
	struct mii_dev *dev0;

    if(initialize)
		return 0;

	offset = getenv_ulong("mdio_clk_offset", 0, MDIO_CLK_OFFSET_DEFAULT);
	period = getenv_ulong("mdio_clk_period", 0, MDIO_CLK_PERIOD_DEFAULT);
	printf("MDIO: offset is 0x%lx, period is 0x%lx\n", offset, period);

	dev0 = mdio_alloc();                                    
	snprintf(dev0->name, MDIO_NAME_LEN, mdio_dev);     
	/*dev0->priv = (void *)(unsigned long)phy_by_index[1];*/  /*MDIO addr of port gmac1*/
	dev0->priv  = (void *)CONFIG_AXXIA_MDIO0_BASE;
	dev0->read = axxia_mdio_read;                           
	dev0->write = axxia_mdio_write;                         
	dev0->reset = axxia_mdio_reset;                         
															
	if (mdio_register(dev0) < 0) {                          
		debug("Failed to register MDIO %s\n", dev0->name);  
		free(dev0);                                         
															
		return -1;                                          
	}                                                       
															
	writel(offset, dev0->priv + MDIO_REG_CLK_OFFSET);       
	writel(period, dev0->priv + MDIO_REG_CLK_PERIOD);       

	/* Enable the MDIO Clock. */
#ifndef CONFIG_TARGET_EMULATION
#ifdef CONFIG_AXXIA_ANY_56XX
	writel(0x10, PERIPH_GPREG + 0x18);
#endif
#endif

	/*
	  Set the RGMII Clock Pad Skew

	  This is PHY specific, and may only apply to Victoria/Waco.
	*/

#ifdef CONFIG_TARGET_HARDWARE
	dev0->write(dev0, phy_by_index[1], 0, 0xd, 2);
	dev0->write(dev0, phy_by_index[1], 0, 0xe, 8);
	dev0->write(dev0, phy_by_index[1], 0, 0xd, 0x4002);
	dev0->write(dev0, phy_by_index[1], 0, 0xe, 0x3ff);
#endif

	initialize = 1;

	return 0;
}
