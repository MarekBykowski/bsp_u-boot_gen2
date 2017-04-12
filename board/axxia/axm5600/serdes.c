/*
 * serdes.c
 *
 * HSS reference clock select set.
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

#define DEBUG
#include <config.h>
#include <common.h>
#include <command.h>
#include "../common/ncp_nca_reg_defines.h"
#include "eioa.h"
	
#define PORT_ENABLE (1 << 2)
#define GMAC_RX_EN (1 << 3)
#define RX_EN (1 << 0)
#define TX_EN (1 << 1)

#define NCP_EIOA_HSS_CFG_REGION_ID(hss)            \
    NCP_REGION_ID(NCP_NODE_EIOA_PHY0 + (hss), 0x0000)

#define NCP_EIOA_PHY_CFG(n)                 \
    ((n < 17) ? 0x110 : 0x111)                 \

/*
 * ref_range
 * Specifies the frequency range of the input reference clock (post
 * ref_clk_div2_en division if any). The code mapping of ref_range is as follows:
 * 3'b000 : 1 - 26MHz
 * 3'b001 : 26.1 - 52MHz
 * 3'b010 : 52.1 - 78MHz
 * 3'b011 : 78.1 - 104MHz
 * 3'b100 : 104.1 - 130MHz
 * 3'b101 : 130.1 - 156MHz
 * 3'b110 : 156.1 - 182MHz
 * 3'b111 : 182.1 - 200MHz
 * Any change in this input must be followed by phy_reset assertion.
*/

static int
dev_eioa_core_port_enable_set(
		ncp_uint32_t hwPortIndex, 
		ncp_uint32_t eioaRegion, 
		ncp_uint32_t gmacRegion, 
		ncp_uint32_t gmacPortOffset,
		ncp_uint32_t controlRegisterOffset,
		short enable)
{
#ifdef DEBUG
	unsigned ncr_status[3];
#endif
    /*
     * Sequencing of RX and TX enables/disables required
     * RX enable and TX enable
     *   1. Core RX enable
     *   2. Mac RX enable
     *   3. Core TX enable
     * RX Disable and TX Disable
     *   1. Mac RX disable
     *   2. Core RX disable
     *   3. Core TX disable
     */
	
	if (enable == 1) {
		ncr_modify32(eioaRegion, NCP_EIOA_GEN_CFG_REG_OFFSET(hwPortIndex), 0x1, RX_EN);
		ncr_modify32(gmacRegion, gmacPortOffset + controlRegisterOffset, 0xc, (PORT_ENABLE | GMAC_RX_EN)); 
		ncr_modify32(eioaRegion, NCP_EIOA_GEN_CFG_REG_OFFSET(hwPortIndex), 0x2, TX_EN);
	} else {
		/* PORT_ENABLE must always be true */
		ncr_modify32(gmacRegion, gmacPortOffset + controlRegisterOffset, 0xc, (PORT_ENABLE | ~GMAC_RX_EN)); 
		ncr_modify32(eioaRegion, NCP_EIOA_GEN_CFG_REG_OFFSET(hwPortIndex), 0x1, ~RX_EN);
		ncr_modify32(eioaRegion, NCP_EIOA_GEN_CFG_REG_OFFSET(hwPortIndex), 0x2, ~TX_EN);
	}


#ifdef DEBUG
	ncr_read32(eioaRegion, NCP_EIOA_GEN_CFG_REG_OFFSET(hwPortIndex), &ncr_status[0]);
	ncr_read32(eioaRegion, gmacPortOffset + controlRegisterOffset, &ncr_status[1]);
	ncr_read32(eioaRegion, NCP_EIOA_GEN_CFG_REG_OFFSET(hwPortIndex), &ncr_status[2]);
	debug("%s() -> enable %u core rx 0x%x, mac rx 0x%x, tx enable 0x%x\n", __func__, enable, ncr_status[0], ncr_status[1], ncr_status[2] );
#endif

	return 0;
}



int
eioa_hss_synce_pll_refclk_select_set(ncp_uint32_t serdesId, ncp_uint32_t gmacId, ncp_eioa_serdes_ref_clk_range_t ref_clock)
{
	ncp_uint32_t hwPortIndex, eioaRegion, gmacRegion, gmacPortOffset, controlRegisterOffset;
	unsigned ncr_status[2], count = 0, pll_locked = 0;
	unsigned txX_ack = 1, rxX_ack = 1;
	unsigned ncr_read;

	/*gmac3*/
/*
	port_index = 3;                                     
	eioa_index = NCP_EIOA0;                             
	core_regID = (ncp_uint32_t)NCP_REGION_EIOA0_CORE;   
	epp_regID = (ncp_uint32_t)NCP_REGION_EIOA0_EPP0;    
	ipp_regID = (ncp_uint32_t)NCP_REGION_EIOA0_IPP0;    
	nemac_regID = (ncp_uint32_t)NCP_REGION_EIOA0_NEMAC0;
	hss_num = 0;                                        
	hss_lane = 0;                                       
	node_id = NCP_EIOA_PHY0_CFG;
	lane_id = 1; 
	pll_used = NCP_EIOA_SERDES_PLLB;*/

	/* Disable both tx and rx of this port */
    if (5 > gmacId) {
        hwPortIndex = ((gmacId == 0) ? 0 : (gmacId - 1));
		eioaRegion = NCP_REGION_ID(31, 16); /* 0x1f.0x10 */
		gmacRegion = ((gmacId == 0) ? NCP_REGION_ID(31, 17) : /* 0x1f.0x11 */ 
                                     NCP_REGION_ID(31, 18)); /* 0x1f.0x12 */
		gmacPortOffset = 0xc0 * hwPortIndex;
		controlRegisterOffset = 0x300;
	} else {
		return -1;
	}

	/* read current clock */
	ncr_read32(NCP_REGION_ID(NCP_EIOA_PHY_CFG(gmacId),0x0000), 0x4c, &ncr_status[0]);
	debug("Read current clock 0x%x (0x101.0x0.0x4c)\n", ncr_status[0]);
	
	/* Disable both tx and rx of this port */
	dev_eioa_core_port_enable_set(hwPortIndex, eioaRegion, gmacRegion, gmacPortOffset, controlRegisterOffset, 0);
	
	/* Hold PLL in reset */
	ncr_read32(NCP_REGION_ID(NCP_EIOA_PHY_CFG(gmacId),0x0000), 0x0, &ncr_read);
	/* clear bit 9 */
	ncr_read &= ~(1 << 9);
	/*ncr_write32(NCP_REGION_ID(NCP_EIOA_PHY_CFG(gmacId),0x0000), 0x0, ncr_read);
	ncr_read32(NCP_REGION_ID(NCP_EIOA_PHY_CFG(gmacId),0x0000), 0x0, &ncr_read);
	debug("Hold PLL in reset (clear bit 9) (0x101.0x0.0x0) 0x%x\n", ncr_read);*/

	/* Change ref clk selection */
	debug("%s() modify bits 4,5,6 set clock to 0x%x (0x101.0x0.0x4c)\n",__func__,  ref_clock);
	ncr_read32(NCP_REGION_ID(NCP_EIOA_PHY_CFG(gmacId),0x0000), 0x4c, &ncr_read);
	/* set bits 4,5,6 if appripriate */
	ncr_read |= (ref_clock << 4);
	ncr_write32(NCP_REGION_ID(NCP_EIOA_PHY_CFG(gmacId),0x0000), 0x4c, ncr_read);
	ncr_read32(NCP_REGION_ID(NCP_EIOA_PHY_CFG(gmacId),0x0000), 0x4c, &ref_clock);
	udelay(5000);
	debug("%s() done! 0x%x\n",__func__, ref_clock);

	/* Pull it out from reset */
	ncr_read32(NCP_REGION_ID(NCP_EIOA_PHY_CFG(gmacId),0x0000), 0x0, &ncr_read);
	/* clear bit 9 */
	ncr_read |= (1 << 9);
	ncr_write32(NCP_REGION_ID(NCP_EIOA_PHY_CFG(gmacId),0x0000), 0x0, ncr_read);
	ncr_read32(NCP_REGION_ID(NCP_EIOA_PHY_CFG(gmacId),0x0000), 0x0, &ncr_read);
	debug("Pull it out from reset (set bit 9) (0x101.0x0.0x0) 0x%x\n", ncr_read);

	/* Ensure PLL lock and Tx/RxPhy Ready for the lane */                     
	while(pll_locked == 0x0)
	{
		ncr_read32(NCP_REGION_ID(NCP_EIOA_PHY_CFG(gmacId),0x0000), 0x8c, &ncr_read);
		pll_locked = (ncr_read & (1 << 21));
		debug("pll locked count %d 0x%x ncr 0x%x\n",count, pll_locked, ncr_read);
		udelay(5000);
		count++;
		if (20 < count)
			return -1;
	}

	/* wait for txX_acks to go low */
	count = 0;
	ncr_read32(NCP_REGION_ID(NCP_EIOA_PHY_CFG(gmacId),0x0000), 0x8c, &ncr_read);
	/* Bit 0 corresponds to lane 0 and bit 1 corresponds to lane 1 (gmac3) */
	txX_ack = (ncr_read & (1 << 1));
	debug("txX_ack coutn %d 0x%x ncr 0x%x\n", count, txX_ack, ncr_read);
	udelay(5000);
	while( ((txX_ack >> 1) & 0x1) == 1)
	{
		ncr_read32(NCP_REGION_ID(NCP_EIOA_PHY_CFG(gmacId),0x0000), 0x8c, &ncr_read);
		/* Bit 0 corresponds to lane 0 and bit 1 corresponds to lane 1 (gmac3) */
		txX_ack = (ncr_read & (1 << 1));
		debug("txX_ack coutn %d 0x%x ncr 0x%x\n", count, txX_ack, ncr_read);
		udelay(5000);
		count++;
		if (10 < count)
			return -1;
	}

	/* wait for rxX_acks to go low */
	count = 0;
	ncr_read32(NCP_REGION_ID(NCP_EIOA_PHY_CFG(gmacId),0x0000), 0x8c, &ncr_read);
	/* Bit 16 corresponds to lane 0 and bit 17 corresponds to lane 1 (gmac3) */
	rxX_ack = (ncr_read & (1 << 17)); 
	debug("rxX_ack count %d 0x%x ncr 0x%x\n", count,rxX_ack, ncr_read);
	udelay(5000);
	while( ((rxX_ack >> 17) & 0x1) == 1)
	{
		ncr_read32(NCP_REGION_ID(NCP_EIOA_PHY_CFG(gmacId),0x0000), 0x8c, &ncr_read);
		/* Bit 16 corresponds to lane 0 and bit 17 corresponds to lane 1 (gmac3) */
		rxX_ack = (ncr_read & (1 << 17)); 
		debug("rxX_ack count %d 0x%x ncr 0x%x\n", count,rxX_ack, ncr_read);
		udelay(5000);
		count++;
		if (10 < count)
			return -1;
	}

	/* Enable both tx and rx of this port */
	dev_eioa_core_port_enable_set(hwPortIndex, eioaRegion, gmacRegion, gmacPortOffset, controlRegisterOffset, 1);

	ncr_read32(NCP_REGION_ID(NCP_EIOA_PHY_CFG(gmacId),0x0000), 0x4c, &ncr_status[1]);
	debug("%s() ref_clock set from 0x%x to 0x%x\n", __func__, ncr_status[0], ncr_status[1]);
	
	return 0;
}


int
do_hss(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	return eioa_hss_synce_pll_refclk_select_set(1, 3, 
		simple_strtoul(argv[1], NULL, 10));
}


U_BOOT_CMD(
	hss, 2, 0, do_hss,
	"hss valuen",
	"serdes select ref clock\n"
	"0 -> CLK_001_0_TO_026_MHZ\n"
	"1 -> CLK_026_1_TO_052_MHZ\n"
	"2 -> CLK_052_1_TO_078_MHZ\n"
	"3 -> CLK_078_1_TO_104_MHZ\n"
	"4 -> CLK_104_1_TO_130_MHZ\n"
	"5 -> CLK_130_1_TO_156_MHZ\n"
	"6 -> CLK_156_1_TO_182_MHZ\n"
	"7 -> CLK_182_1_TO_200_MHZ"
);






#if 0
    if ((rate_mode == NCP_EIOA_SERDES_SLOT_CONFIG_SGMII) || (rate_mode == NCP_EIOA_SERDES_SLOT_CONFIG_QSGMII))
    {
        NCP_CALL(ncr_read32(NCP_EIOA_HSS_CFG_REGION_ID(serdesId),
                            (0x4c + NCP_PLL_CTRL_0),
                            (ncp_uint32_t *)&hss_pll_ctrl_0));
        /*hss_pll_ctrl_0.ref_use_pad = 0x1;*/ /* primaryInputClock should be this */
        /*hss_pll_ctrl_0.ref_clk_div2_en = 0x0;*/ /* enableInputRefClockDiv2 should be this */
        hss_pll_ctrl_0.ref_range = 0x5; /* inputRefClockRange should be this */
        NCP_CALL(ncp_write32(NCP_EIOA_HSS_CFG_REGION_ID(serdesId),
                             (0x4c + NCP_PLL_CTRL_0),
                             *(ncp_uint32_t *)&hss_pll_ctrl_0));
	}
#endif
