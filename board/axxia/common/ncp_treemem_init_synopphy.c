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
#include "ncp_sysmem_lsiphy.h" /* for macros and stuff mainly */
#include "ncp_sysmem_synopphy.h"
#include "ncp_treemem_synopphy.h"
#else
#include <stdio.h>
#include "ncp.h"
#include "ncp_pvt.h"
#include "ncp_sysmem_ext.h"
#include "ncp_sysmem_lsiphy.h" /* for macros and stuff mainly */
#include "ncp_sysmem_synopphy.h"
#include "ncp_treemem_synopphy.h"
#endif

ncp_st_t
ncp_cm_ddr4_phy_reg_dump(
		ncp_dev_hdl_t   dev,
		ncp_uint32_t    cmNode)
{
	ncp_st_t		ncpStatus = NCP_ST_SUCCESS;
	ncp_region_id_t 	phyRegion = NCP_REGION_ID(cmNode, 0x0a);
	ncp_uint32_t		numbytes = 0, bytecnt = 0, tmp = 0, period = 0, freq = 0, numranks = 0, numislands = 0;
	ncp_uint32_t		errorindicated = 0, vreferrorindicated = 0, bits = 0, field = 0, val = 0;
	ncp_uint32_t		warnindicated = 0, vrefwarnindicated = 0;

	ncp_phy_DX0GCR0_t regDX0GCR0 = {0};
	ncp_phy_DX0GCR5_t regDX0GCR5 = {0};
	ncp_phy_DX0GCR6_t regDX0GCR6 = {0};
	ncp_phy_DCR_t regDCR = {0};
	ncp_phy_PGCR2_t regPGCR2 = {0};
	ncp_phy_PGCR3_t regPGCR3 = {0};
	ncp_phy_PTR0_t regPTR0 = {0};
	ncp_phy_PTR1_t regPTR1 = {0};
	ncp_phy_PLLCR0_t regPLLCR0 = {0};
	/*ncp_phy_PLLCR_t regPLLCR = {0};*/
	ncp_phy_ZQCR_t regZQCR = {0};
	ncp_phy_MR0_t regMR0 = {0};
	ncp_phy_MR1_t regMR1 = {0};
	ncp_phy_MR2_t regMR2 = {0};
	/*ncp_phy_MR3_t regMR3 = {0};*/
	ncp_phy_MR4_t regMR4 = {0};
	ncp_phy_MR5_t regMR5 = {0};
	ncp_phy_MR6_t regMR6 = {0};
	ncp_phy_DTPR0_t regDTPR0 = {0};
	ncp_phy_DTPR1_t regDTPR1 = {0};
	ncp_phy_DTPR4_t regDTPR4 = {0};
	ncp_phy_DTPR5_t regDTPR5 = {0};
	ncp_phy_PTR3_t regPTR3 = {0};
	ncp_phy_PTR4_t regPTR4 = {0};
	ncp_phy_DXCCR_t regDXCCR = {0};
	ncp_phy_DTCR0_t regDTCR0 = {0};
	ncp_phy_DTCR1_t regDTCR1 = {0};
	ncp_phy_VTCR0_t regVTCR0 = {0};
	ncp_phy_ZQ0PR_t regZQ0PR = {0};
	ncp_phy_DX0RSR0_t regDX0RSR0 = {0};
	ncp_phy_DX0RSR1_t regDX0RSR1 = {0};
	ncp_phy_DX0RSR2_t regDX0RSR2 = {0};
	ncp_phy_DX0RSR3_t regDX0RSR3 = {0};
	ncp_phy_DX0GSR3_t regDX0GSR3 = {0};
	ncp_phy_DX0GSR2_t regDX0GSR2 = {0};
	ncp_phy_RANKIDR_t regRANKIDR = {0};
	ncp_phy_DX0MDLR0_t regDX0MDLR0 = {0};
	ncp_phy_DX0MDLR1_t regDX0MDLR1 = {0};
	ncp_phy_DX0GSR0_t regDX0GSR0 = {0};
	ncp_phy_DX0LCDLR0_t regDX0LCDLR0 = {0};
	ncp_phy_DX0LCDLR1_t regDX0LCDLR1 = {0};
	ncp_phy_DX0LCDLR2_t regDX0LCDLR2 = {0};
	ncp_phy_DX0LCDLR3_t regDX0LCDLR3 = {0};
	ncp_phy_DX0LCDLR4_t regDX0LCDLR4 = {0};
	ncp_phy_DX0GTR0_t regDX0GTR0 = {0};

	for (bytecnt = 0; bytecnt < 2; bytecnt++)
	{
		/* DXnGCR0 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GCR0 + (bytecnt * 0x100)), (ncp_uint32_t *)&regDX0GCR0);
		if (regDX0GCR0.dxen)
		{
			numbytes++;
		}
	}
	printf ("NUM BYTES calculated as %d\n", numbytes);

	/* DCR */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DCR, (ncp_uint32_t *)&regDCR);
	if (regDCR.ddrmd != 0x4)
	{
		printf ("ERROR: DCR[2:0] - Expect DDR4\n");
	}
	if (regDCR.ddr2t != 0x1)
	{
		printf ("ERROR: DCR[28] - Expect DDR2T\n");
	}
	if (regDCR.udimm != 0x1)
	{
		printf ("WARNING: DCR[29] - Expect Address Mirroring\n");
	}
	if (regDCR.ubg)
	{
		printf ("PHY is configured for x16 DRAM devices\n");
	}
	else
	{
		printf ("PHY is configured for x8 DRAM devices\n");
	}

	/* PGCR0-5 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PGCR2, (ncp_uint32_t *)&regPGCR2);
	period = (7800 * 9 * 2 * 1000/regPGCR2.trefprd);
	freq = (1000000 / period);
	printf ("PGCR2 - Best Guess DDR Clock Frequency = %d MHz\n",freq);

	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PGCR3, (ncp_uint32_t *)&regPGCR3);
	if (regPGCR3.rdmode != 1)
	{
		printf ("ERROR: PGCR3 RDMODE should be -Static Read Response\n");
	}

	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PGCR4, &tmp);
	if (tmp != 0)
	{
		printf ("ERROR: Check PGCR4 value - 0x%x!\n", tmp);
	}

	/* PTR0-2 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PTR0, (ncp_uint32_t *)&regPTR0);
	printf ("tPLLGS = %d ns clocks(min 4000 ns?)\n",(regPTR0.tpllgs * period)/1000);
	printf ("tPLLPD = %d ns clocks(min 1000 ns?)\n",(regPTR0.tpllpd * period)/1000);

	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PTR1, (ncp_uint32_t *)&regPTR1);
	printf ("tPLLRST = %d ns clocks(min 9000 ns?)\n",(regPTR1.tpllrst * period)/1000);
	printf ("tPLLLOCK = %d ns clocks(min 100000 ns?)\n",(regPTR1.tplllock * period)/1000);

	/* PLLCR0 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PLLCR0, (ncp_uint32_t *)&regPLLCR0);
	if (((regPLLCR0.frqsel == 0) && (freq < 440)) || ((regPLLCR0.frqsel == 1) && ((freq < 225) || (freq > 490))))
	{
		printf ("ERROR: PLLCR0.FRQSEL is incorrect for frequency of %d MHz\n",freq);
	}

	/*ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PLLCR, (ncp_uint32_t *)&regPLLCR);
	  if (((regPLLCR.frqsel == 0) && (freq < 440)) || ((regPLLCR.frqsel == 1) && ((freq < 225) || (freq > 490))))
	  {
	  printf ("ERROR: PLLCR.FRQSEL is incorrect for frequency of %d MHz\n",freq);
	  }*/

	/* ZQCR */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_ZQCR, (ncp_uint32_t *)&regZQCR);
	if ((regZQCR.term_off != 0x0) || (regZQCR.zqpd != 0x0))
	{
		printf ("ZQCR[7:0] should be all 0\n");
	}
	if (regZQCR.pgwait != 0x7)
	{
		printf ("ERROR: ZQCR.PGWAIT should be 0x7, but got 0x%d\n",regZQCR.pgwait);
	}

	/* MR0-6 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_MR0, (ncp_uint32_t *)&regMR0);
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_MR0, &tmp);
	printf ("MR0 = 0x%x\n",tmp);
	printf ("    - Write Recover/RTP = %s\n", ((regMR0.wr == 0) ? "10/5" :
				(regMR0.wr == 1) ? "12/6" :
				(regMR0.wr == 2) ? "14/7" :
				(regMR0.wr == 3) ? "16/8" :
				(regMR0.wr == 4) ? "18/9" :
				(regMR0.wr == 5) ? "20/10" :
				(regMR0.wr == 6) ? "24/12" :
				"Err/Err"));
	printf ("    - CAS \t\t= %s\n", ((((regMR0.cl_6_4 * 2) + (regMR0.cl_2)) == 0) ? "9" :
				(((regMR0.cl_6_4 * 2) + (regMR0.cl_2)) == 1) ? "10" :
				(((regMR0.cl_6_4 * 2) + (regMR0.cl_2)) == 2) ? "11" :
				(((regMR0.cl_6_4 * 2) + (regMR0.cl_2)) == 3) ? "12" :
				(((regMR0.cl_6_4 * 2) + (regMR0.cl_2)) == 4) ? "13" :
				(((regMR0.cl_6_4 * 2) + (regMR0.cl_2)) == 5) ? "14" :
				(((regMR0.cl_6_4 * 2) + (regMR0.cl_2)) == 6) ? "15" :
				(((regMR0.cl_6_4 * 2) + (regMR0.cl_2)) == 7) ? "16" :
				(((regMR0.cl_6_4 * 2) + (regMR0.cl_2)) == 8) ? "18" :
				(((regMR0.cl_6_4 * 2) + (regMR0.cl_2)) == 9) ? "20" :
				(((regMR0.cl_6_4 * 2) + (regMR0.cl_2)) == 10) ? "22" :
				(((regMR0.cl_6_4 * 2) + (regMR0.cl_2)) == 11) ? "24" :
				"ERROR"));

	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_MR1, (ncp_uint32_t *)&regMR1);
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_MR1, &tmp);
	printf ("MR1 = 0x%x\n",tmp);
	printf ("    - RTT_NOM \t\t= %s\n", ((((tmp & 0x700) >> 8) == 0) ? "RTT_NOM disabled" :
				(((tmp & 0x700) >> 8) == 1) ? "RZQ/4 (60 ohm)" :
				(((tmp & 0x700) >> 8) == 2) ? "RZQ/2 (120 ohm)" :
				(((tmp & 0x700) >> 8) == 3) ? "RZQ/6 (40 ohm)" :
				(((tmp & 0x700) >> 8) == 4) ? "RZQ/1 (240 ohm)" :
				(((tmp & 0x700) >> 8) == 5) ? "RZQ/5 (48 ohm)" :
				(((tmp & 0x700) >> 8) == 6) ? "RZQ/3 (80 ohm)" :
				"RZQ/7 (38 ohm)"));
	printf ("    - AL \t\t= %d\n", regMR1.al);
	printf ("    - DRV Impedance\t= %s\n", ((((tmp & 0x6) >> 1) == 0) ? "RZQ/7 (34 ohm)" :
				(((tmp & 0x6) >> 1) == 1) ? "RZQ/5 (48 ohm)" :
				"ERROR"));

	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_MR2, (ncp_uint32_t *)&regMR2);
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_MR2, &tmp);
	printf ("MR2 = 0x%x\n",tmp);
	printf ("    - Write CRC \t= %s\n", ((tmp & 0x1000) >> 12) ? "ENABLED" : "DISABLED"); /* per jedec */
	printf ("    - RTT_WR \t\t= %s\n", ((regMR2.rttwr == 0) ? "Dynamic ODT OFF" :
				(regMR2.rttwr == 1) ? "RZQ/2 (120 ohm)" :
				(regMR2.rttwr == 2) ? "RZQ/1 (240 ohm)" :
				"High-Z"));
	printf ("    - CWL \t\t= %s\n", ((regMR2.cwl == 0) ? "9  - 1600" :
				(regMR2.cwl == 1) ? "10 - 1866" :
				(regMR2.cwl == 2) ? "11 - 2133,1600" :
				(regMR2.cwl == 3) ? "12 - 2400,1866" :
				(regMR2.cwl == 4) ? "14 - 2133" :
				(regMR2.cwl == 5) ? "16 - 2400" :
				(regMR2.cwl == 6) ? "18 - ??" :
				"ERROR"));

	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_MR3, &tmp);
	printf ("MR3 = 0x%x\n",tmp);

	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_MR4, (ncp_uint32_t *)&regMR4);
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_MR4, &tmp);
	printf ("MR4 = 0x%x\n",tmp);
	printf ("    - Wr/Rd Preamble \t= %d/%d\n", regMR4.wrp, regMR4.rdp);
	printf ("    - CS to CMD/ADDR latency = %d\n", (regMR4.cs2cmdl == 0) ? 0/*"DISABLED"*/ : (regMR4.cs2cmdl+2));

	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_MR5, (ncp_uint32_t *)&regMR5);
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_MR5, &tmp);
	printf ("MR5 = 0x%x\n",tmp);
	printf ("    - Wr/Rd DBI \t= %d/%d\n", regMR5.wdbi, regMR5.rdbi);
	printf ("    - CA Parity Latency = %s\n", ((regMR5.capm == 0) ? "DISABLED" :
				(regMR5.capm == 1) ? "4 - 1600,1866,2133" :
				(regMR5.capm == 2) ? "5 - 2400" :
				"ERROR"));

	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_MR6, (ncp_uint32_t *)&regMR6);
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_MR6, &tmp);
	printf ("MR6 = 0x%x\n",tmp);
	printf ("    - tCCD_L \t\t= %s\n", ((regMR6.tccdl == 0) ? "4 - <= 1333" :
				(regMR6.tccdl == 1) ? "5 - <= 1600/1866" :
				(regMR6.tccdl == 2) ? "6 - <= 2133/2400" :
				"ERROR"));
	printf ("    - VREF Trained value = 0x%X\n",(tmp & 0x7f)); /* from jedec */

	/* DTPR0-6 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DTPR0, (ncp_uint32_t *)&regDTPR0);
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DTPR1, (ncp_uint32_t *)&regDTPR1);
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DTPR4, (ncp_uint32_t *)&regDTPR4);
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DTPR5, (ncp_uint32_t *)&regDTPR5);

	printf ("tRC  \t= %d\t",  regDTPR5.trc);
	printf ("tRRD \t= %d\n",  regDTPR0.trrd);

	printf ("tRP  \t= %d\t",  regDTPR0.trp);
	printf ("tWTR \t= %d\t",  regDTPR5.twtr);
	printf ("tRAS \t= %d\n",  regDTPR0.tras);

	printf ("tRTP \t= %d\t",  regDTPR0.trtp);
	printf ("tFAW \t= %d\t",  regDTPR1.tfaw);
	printf ("tRCD \t= %d\n",  regDTPR5.trcd);

	printf ("tRFC \t= %d\t",  regDTPR4.trfc);
	printf ("tMRD \t= %d\t",  regDTPR1.tmrd + 8);
	printf ("tMOD \t= %d\t",  regDTPR1.tmod + 24);
	printf ("tWLMRD \t= %d\t",regDTPR1.twlmrd);
	printf ("tWLO \t= %d\n",  regDTPR4.twlo);

	/* PTR3-4 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PTR3, (ncp_uint32_t *)&regPTR3);
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PTR4, (ncp_uint32_t *)&regPTR4);

	printf ("tDINIT0 = %d ns (min 500000 ns?)\n",((regPTR3.tdinit0) * period)/1000);
	printf ("tDINIT1 = %d clocks (tRFC + 5 ?)\n",regPTR3.tdinit1);
	printf ("tDINIT2 = %d ns (min 200000 ns?)\n",((regPTR4.tdinit2) * period)/1000);

	/* DXCCR */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DXCCR, (ncp_uint32_t *)&regDXCCR);
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DXCCR, &tmp);

	printf ("DXCCR register = 0x%x\n", tmp);
	printf ("MSBDQ = %d\n",regDXCCR.msbudq);

	/* DTCR0-1 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DTCR0, (ncp_uint32_t *)&regDTCR0);
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DTCR1, (ncp_uint32_t *)&regDTCR1);

	if (regDTCR0.dtmpr == 0) {
		printf ("ERROR: DQS Gate Training does NOT use MPR. Not Recommended for DDR4\n");
	}
	if (regDTCR0.dtcmpd == 0) {
		printf ("NOTE: DQS Gate Training does NOT use data comparison.\n");
	}

	if (regDTCR1.ranken == 1)  
	{
		numranks = 1;
	}
	else if (regDTCR1.ranken == 3)  
	{
		numranks = 2;
	}
	else if (regDTCR1.ranken == 7)  
	{
		numranks = 3;
	}
	else if (regDTCR1.ranken == 15) 
	{
		numranks = 4;
	}
	printf ("NUMBER of RANKS configured = %d\n", numranks);

	/* VTCR0-1 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_VTCR0, (ncp_uint32_t *)&regVTCR0);
	printf ("tVREF = %d ns (min 150 ns?)\n",((1 << (regVTCR0.tvref + 4)) * period)/1000);

	printf ("\n************** ODT and Impedance config - Assuming RZQ=240ohm ******************\n");
	printf ("\t\t\t");
	numislands = 4;
	for (bytecnt = 0; bytecnt < numislands; bytecnt++) 
	{
		printf ("Island %d \t", bytecnt);
	}
	printf ("\n");

	/* ZQnPR */
	printf ("Output Impedance   \t");
	for (bytecnt = 0; bytecnt < numislands; bytecnt++) 
	{
		ncr_read32(phyRegion, (NCP_PHY_ZQ0PR + (0x10 * bytecnt)), (ncp_uint32_t *)&regZQ0PR);
		printf (" %s \t", ((regZQ0PR.zprog_asym_drv_pu == 0 ) ? "480 ohm" :
					(regZQ0PR.zprog_asym_drv_pu == 1 ) ? "240 ohm" :
					(regZQ0PR.zprog_asym_drv_pu == 2 ) ? "160 ohm" :
					(regZQ0PR.zprog_asym_drv_pu == 3 ) ? "120 ohm" :
					(regZQ0PR.zprog_asym_drv_pu == 4 ) ? "96 ohm" :
					(regZQ0PR.zprog_asym_drv_pu == 5 ) ? "80 ohm" :
					(regZQ0PR.zprog_asym_drv_pu == 6 ) ? "68.6 ohm" :
					(regZQ0PR.zprog_asym_drv_pu == 7 ) ? "60 ohm" :
					(regZQ0PR.zprog_asym_drv_pu == 8 ) ? "53.3 ohm" :
					(regZQ0PR.zprog_asym_drv_pu == 9 ) ? "48 ohm" :
					(regZQ0PR.zprog_asym_drv_pu == 10 ) ? "43.6 ohm" :
					(regZQ0PR.zprog_asym_drv_pu == 11 ) ? "40 ohm" :
					(regZQ0PR.zprog_asym_drv_pu == 12 ) ? "36.9 ohm" :
					(regZQ0PR.zprog_asym_drv_pu == 13 ) ? "34.3 ohm" :
					(regZQ0PR.zprog_asym_drv_pu == 14 ) ? "32 ohm" :
					(regZQ0PR.zprog_asym_drv_pu == 15 ) ? "30 ohm" :
					"UNKNOWN"));
	}
	printf ("\n");
	printf ("ODT settings   \t\t");
	for (bytecnt = 0; bytecnt < numislands; bytecnt++) 
	{
		ncr_read32(phyRegion, (NCP_PHY_ZQ0PR + (0x10 * bytecnt)), (ncp_uint32_t *)&regZQ0PR);
		printf (" %s \t", ((regZQ0PR.zprog_pu_odt_only == 0 ) ? "480 ohm" :
					(regZQ0PR.zprog_pu_odt_only == 1 ) ? "240 ohm" :
					(regZQ0PR.zprog_pu_odt_only == 2 ) ? "160 ohm" :
					(regZQ0PR.zprog_pu_odt_only == 3 ) ? "120 ohm" :
					(regZQ0PR.zprog_pu_odt_only == 4 ) ? "96 ohm" :
					(regZQ0PR.zprog_pu_odt_only == 5 ) ? "80 ohm" :
					(regZQ0PR.zprog_pu_odt_only == 6 ) ? "68.6 ohm" :
					(regZQ0PR.zprog_pu_odt_only == 7 ) ? "60 ohm" :
					(regZQ0PR.zprog_pu_odt_only == 8 ) ? "53.3 ohm" :
					(regZQ0PR.zprog_pu_odt_only == 9 ) ? "48 ohm" :
					(regZQ0PR.zprog_pu_odt_only == 10 ) ? "43.6 ohm" :
					(regZQ0PR.zprog_pu_odt_only == 11 ) ? "40 ohm" :
					(regZQ0PR.zprog_pu_odt_only == 12 ) ? "36.9 ohm" :
					(regZQ0PR.zprog_pu_odt_only == 13 ) ? "34.3 ohm" :
					(regZQ0PR.zprog_pu_odt_only == 14 ) ? "32 ohm" :
					(regZQ0PR.zprog_pu_odt_only == 15 ) ? "30 ohm" :
					"UNKNOWN"));
	}
	printf ("\n");


	/* Data Training Results */
	printf ("\n***********************************************************\n");
	printf (" ** DDR Training typically occurs in the following order **\n");
	printf ("***********************************************************\n");
	printf (" *  1) PHY INIT \t\t-> PHY PLLs are initialized, and delay lines are calibrated\n");
	printf (" *  2) Write Leveling \t\t-> DQS at DRAM each is aligned to the Clock at each DRAM\n");
	printf (" *  3) Gate Training \t\t-> The timing for expecting a DQS from DRAM during a read is determined\n");
	printf (" *  4) Write Latency Adjust \t-> The correct write latency is determined after write leveling\n");
	printf (" *  5) Static Read Training \t-> Minimum amount of time to leave read data in read FIFOs is determined\n");
	printf (" *  6) Read bit de-skew \t-> Each bit in a data lane is adjusted for timing to optimize reads\n");
	printf (" *  7) Write bit de-skew \t-> Each bit in a data lane is adjusted for timing to optimize writes\n");
	printf (" *  8) Read eye training \t-> Read DQS is adjusted to optimally place DQS edge in center of data eye\n");
	printf (" *  9) Write eye training \t-> Write DQS is adjusted to optimally place DQS edge in center of data eye\n");
	printf (" * 10) VREF training \t\t-> Adjust VREF settings in DRAM and in PHY for optimal placement\n");

	printf ("\n**************** Training Errors *******************\n");
	printf ("***** All Values in Binary with Error per rank *****\n");
	printf ("\t\t\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		printf ("Byte %d \t", bytecnt);
	}
	printf ("\n");
	errorindicated = 0;
	warnindicated = 0;
	vreferrorindicated = 0;
	vrefwarnindicated = 0;

	printf ("Gate Train Error\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnRSR0 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0RSR0 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0RSR0);
		errorindicated += regDX0RSR0.qsgerr;
		printf (" %d%d%d%d \t", 
				((regDX0RSR0.qsgerr & 0x8) ? 1 : 0),
				((regDX0RSR0.qsgerr & 0x4) ? 1 : 0),
				((regDX0RSR0.qsgerr & 0x2) ? 1 : 0),
				((regDX0RSR0.qsgerr & 0x1) ? 1 : 0));
	}
	printf ("\n");

	printf ("Read Leveling Error\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnRSR1 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0RSR1 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0RSR1);
		errorindicated += regDX0RSR1.rdlvlerr;
		printf (" %d%d%d%d \t", 
				((regDX0RSR1.rdlvlerr & 0x8) ? 1 : 0),
				((regDX0RSR1.rdlvlerr & 0x4) ? 1 : 0),
				((regDX0RSR1.rdlvlerr & 0x2) ? 1 : 0),
				((regDX0RSR1.rdlvlerr & 0x1) ? 1 : 0));
	}
	printf ("\n");

	printf ("WriteLatencyDQ Error\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnRSR2 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0RSR2 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0RSR2);
		errorindicated += regDX0RSR2.wlawn;
		printf (" %d%d%d%d \t", 
				((regDX0RSR2.wlawn & 0x8) ? 1 : 0),
				((regDX0RSR2.wlawn & 0x4) ? 1 : 0),
				((regDX0RSR2.wlawn & 0x2) ? 1 : 0),
				((regDX0RSR2.wlawn & 0x1) ? 1 : 0));
	}
	printf ("\n");

	printf ("Write Latency Error\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnRSR3 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0RSR3 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0RSR3);
		errorindicated += regDX0RSR3.wlaerr;
		printf (" %d%d%d%d \t", 
				((regDX0RSR3.wlaerr & 0x8) ? 1 : 0),
				((regDX0RSR3.wlaerr & 0x4) ? 1 : 0),
				((regDX0RSR3.wlaerr & 0x2) ? 1 : 0),
				((regDX0RSR3.wlaerr & 0x1) ? 1 : 0));
	}
	printf ("\n");

	printf ("Host VREF Error\t\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 	
	{
		/* DXnGSR3 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GSR3 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0GSR3);
		errorindicated += regDX0GSR3.hverr;
		vreferrorindicated += regDX0GSR3.hverr;
		printf (" %d%d%d%d \t", 
				((regDX0GSR3.hverr & 0x8) ? 1 : 0),
				((regDX0GSR3.hverr & 0x4) ? 1 : 0),
				((regDX0GSR3.hverr & 0x2) ? 1 : 0),
				((regDX0GSR3.hverr & 0x1) ? 1 : 0));
	}
	printf ("\n");

	printf ("Host VREF Warning\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnGSR3 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GSR3 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0GSR3);
		warnindicated += regDX0GSR3.hvwrn;
		vrefwarnindicated += regDX0GSR3.hvwrn;
		printf (" %d%d%d%d \t", 
				((regDX0GSR3.hvwrn & 0x8) ? 1 : 0),
				((regDX0GSR3.hvwrn & 0x4) ? 1 : 0),
				((regDX0GSR3.hvwrn & 0x2) ? 1 : 0),
				((regDX0GSR3.hvwrn & 0x1) ? 1 : 0));
	}
	printf ("\n");

	printf ("DRAM VREF Error\t\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnGSR3 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GSR3 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0GSR3);
		errorindicated += regDX0GSR3.dverr;
		vreferrorindicated += regDX0GSR3.dverr;
		printf (" %d%d%d%d \t", 
				((regDX0GSR3.dverr & 0x8) ? 1 : 0),
				((regDX0GSR3.dverr & 0x4) ? 1 : 0),
				((regDX0GSR3.dverr & 0x2) ? 1 : 0),
				((regDX0GSR3.dverr & 0x1) ? 1 : 0));
	}
	printf ("\n");

	printf ("DRAM VREF Warning\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnGSR3 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GSR3 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0GSR3);
		warnindicated += regDX0GSR3.dvwrn;
		vrefwarnindicated += regDX0GSR3.dvwrn;
		printf (" %d%d%d%d \t", 
				((regDX0GSR3.dvwrn & 0x8) ? 1 : 0),
				((regDX0GSR3.dvwrn & 0x4) ? 1 : 0),
				((regDX0GSR3.dvwrn & 0x2) ? 1 : 0),
				((regDX0GSR3.dvwrn & 0x1) ? 1 : 0));
	}
	printf ("\n");

	if (vreferrorindicated) 
	{
		printf ("VREF Debug Code\t");
		for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
		{
			/* DXnGSR3 */
			ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GSR3 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0GSR3);
			errorindicated += regDX0GSR3.estat;
			vreferrorindicated += regDX0GSR3.estat;
			printf (" %d%d%d%d \t", 
					((regDX0GSR3.estat & 0x8) ? 1 : 0),
					((regDX0GSR3.estat & 0x4) ? 1 : 0),
					((regDX0GSR3.estat & 0x2) ? 1 : 0),
					((regDX0GSR3.estat & 0x1) ? 1 : 0));
		}
		printf ("\n");
	}

	printf ("\n**************** Training Errors *******************\n");
	printf ("******** All Values in Binary. NOT per rank *********\n");
	printf ("\t\t\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		printf ("Byte %d \t", bytecnt);
	}
	printf ("\n");

	printf ("Read bit deskew Error\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnGSR2 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GSR2 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0GSR2);
		errorindicated += regDX0GSR2.rderr;
		printf (" %d%d%d%d \t", 
				((regDX0GSR2.rderr & 0x8) ? 1 : 0),
				((regDX0GSR2.rderr & 0x4) ? 1 : 0),
				((regDX0GSR2.rderr & 0x2) ? 1 : 0),
				((regDX0GSR2.rderr & 0x1) ? 1 : 0));
	}
	printf ("\n");

	printf ("Read bit deskew Warn\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnGSR2 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GSR2 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0GSR2);
		warnindicated += regDX0GSR2.rdwn;
		printf (" %d%d%d%d \t", 
				((regDX0GSR2.rdwn & 0x8) ? 1 : 0),
				((regDX0GSR2.rdwn & 0x4) ? 1 : 0),
				((regDX0GSR2.rdwn & 0x2) ? 1 : 0),
				((regDX0GSR2.rdwn & 0x1) ? 1 : 0));
	}
	printf ("\n");

	printf ("Write bit deskew Error\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnGSR2 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GSR2 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0GSR2);
		errorindicated += regDX0GSR2.wderr;
		printf (" %d%d%d%d \t", 
				((regDX0GSR2.wderr & 0x8) ? 1 : 0),
				((regDX0GSR2.wderr & 0x4) ? 1 : 0),
				((regDX0GSR2.wderr & 0x2) ? 1 : 0),
				((regDX0GSR2.wderr & 0x1) ? 1 : 0));
	}
	printf ("\n");

	printf ("Write bit deskew Warn\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnGSR2 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GSR2 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0GSR2);
		warnindicated += regDX0GSR2.wdwn;
		printf (" %d%d%d%d \t", 
				((regDX0GSR2.wdwn & 0x8) ? 1 : 0),
				((regDX0GSR2.wdwn & 0x4) ? 1 : 0),
				((regDX0GSR2.wdwn & 0x2) ? 1 : 0),
				((regDX0GSR2.wdwn & 0x1) ? 1 : 0));
	}
	printf ("\n");

	printf ("Read eye Center Error\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnGSR2 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GSR2 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0GSR2);
		errorindicated += regDX0GSR2.reerr;
		printf (" %d%d%d%d \t", 
				((regDX0GSR2.reerr & 0x8) ? 1 : 0),
				((regDX0GSR2.reerr & 0x4) ? 1 : 0),
				((regDX0GSR2.reerr & 0x2) ? 1 : 0),
				((regDX0GSR2.reerr & 0x1) ? 1 : 0));
	}
	printf ("\n");

	printf ("Read eye Center Warn\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnGSR2 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GSR2 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0GSR2);
		warnindicated += regDX0GSR2.rewn;
		printf (" %d%d%d%d \t", 
				((regDX0GSR2.rewn & 0x8) ? 1 : 0),
				((regDX0GSR2.rewn & 0x4) ? 1 : 0),
				((regDX0GSR2.rewn & 0x2) ? 1 : 0),
				((regDX0GSR2.rewn & 0x1) ? 1 : 0));
	}
	printf ("\n");

	printf ("Write eye Center Error\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnGSR2 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GSR2 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0GSR2);
		errorindicated += regDX0GSR2.weerr;
		printf (" %d%d%d%d \t", 
				((regDX0GSR2.weerr & 0x8) ? 1 : 0),
				((regDX0GSR2.weerr & 0x4) ? 1 : 0),
				((regDX0GSR2.weerr & 0x2) ? 1 : 0),
				((regDX0GSR2.weerr & 0x1) ? 1 : 0));
	}
	printf ("\n");

	printf ("Write eye Center Warn\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnGSR2 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GSR2 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0GSR2);
		warnindicated += regDX0GSR2.wewn;
		printf (" %d%d%d%d \t", 
				((regDX0GSR2.wewn & 0x8) ? 1 : 0),
				((regDX0GSR2.wewn & 0x4) ? 1 : 0),
				((regDX0GSR2.wewn & 0x2) ? 1 : 0),
				((regDX0GSR2.wewn & 0x1) ? 1 : 0));
	}
	printf ("\n");

	printf ("Static Read Error\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnGSR2 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GSR2 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0GSR2);
		errorindicated += regDX0GSR2.srderr;
		printf (" %d%d%d%d \t", 
				((regDX0GSR2.srderr & 0x8) ? 1 : 0),
				((regDX0GSR2.srderr & 0x4) ? 1 : 0),
				((regDX0GSR2.srderr & 0x2) ? 1 : 0),
				((regDX0GSR2.srderr & 0x1) ? 1 : 0));
	}
	printf ("\n");

	if (errorindicated) {
		printf ("\nERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR\n");
		printf ("ERROR: See above for a training error indicated\n");
		printf ("ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR\n");
	}

	if (warnindicated) {
		printf ("\nWarning: See above for a training warning indicated\n");
	}

	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_RANKIDR, (ncp_uint32_t *)&regRANKIDR);

	printf ("\n***********************************************************\n");
	printf ("************ All Results are based on Rank #%d *************\n", regRANKIDR.rankrid);
	printf ("***********************************************************\n");

	printf ("\n**************** Period Measurement Results *******************\n");
	printf ("\t\t\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		printf ("Byte %d \t", bytecnt);
	}
	printf ("\n");

	printf ("Master Delay Initial\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnMDLR0 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0MDLR0 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0MDLR0);
		printf (" 0x%X \t",regDX0MDLR0.iprd);
	}
	printf ("\n");

	printf ("Master Delay Target\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnMDLR0 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0MDLR0 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0MDLR0);
		printf (" 0x%X \t",regDX0MDLR0.tprd);
	}
	printf ("\n");

	printf ("Master Delay Selected\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnMDLR1 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0MDLR1 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0MDLR1);
		printf (" 0x%X \t",regDX0MDLR1.mdld);
	}
	printf ("\n");

	printf ("Write Level Period\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnGSR0 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GSR0 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0GSR0);
		printf (" 0x%X \t",regDX0GSR0.wlprd);
	}
	printf ("\n");

	printf ("Read Level Period\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnGSR0 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GSR0 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0GSR0);
		printf (" 0x%X \t",regDX0GSR0.gdqsprd);
	}
	printf ("\n");

	printf ("\n**************** LCDL Training Results *******************\n");
	printf ("\t\t\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		printf ("Byte %d \t", bytecnt);
	}
	printf ("\n");

	printf ("Write DQS Delay\t\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnLCDLR0 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0LCDLR0 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0LCDLR0);
		printf (" 0x%X \t",regDX0LCDLR0.wld);
	}
	printf ("\n");

	printf ("Write Adjust\t\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnGTR0 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GTR0 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0GTR0);
		printf (" %s \t",((regDX0GTR0.wlsl == 0) ? "-1" :
					(regDX0GTR0.wlsl == 1) ? "-0.5" :
					(regDX0GTR0.wlsl == 2) ? "+-0" :
					(regDX0GTR0.wlsl == 3) ? "+0.5" :
					(regDX0GTR0.wlsl == 4) ? "+1" :
					(regDX0GTR0.wlsl == 5) ? "+1.5" :
					(regDX0GTR0.wlsl == 6) ? "+2" :
					(regDX0GTR0.wlsl == 7) ? "+2.5" :
					(regDX0GTR0.wlsl == 8) ? "+3" :
					(regDX0GTR0.wlsl == 9) ? "+3.5" :
					"ERROR"));
	}
	printf ("\n");

	printf ("Write Data Delay\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnLCDLR1 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0LCDLR1 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0LCDLR1);
		printf (" 0x%X \t",regDX0LCDLR1.wdqd);
	}
	printf ("\n");

	printf ("DQS Gate Delay\t\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnLCDLR2 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0LCDLR2 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0LCDLR2);
		printf (" 0x%X \t",regDX0LCDLR2.dqsgd);
	}
	printf ("\n");

	printf ("DQS Gate Adjust\t\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnGTR0 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GTR0 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0GTR0);
		if (regDX0GTR0.dgsl == 0) 
		{
			printf (" +-0 \t");
		}
		else 
		{
			printf (" +%d \t",(regDX0GTR0.dgsl/2));
		}		      
	}
	printf ("\n");

	printf ("Read DQS Delay\t\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnLCDLR3 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0LCDLR3 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0LCDLR3);
		printf (" 0x%X \t",regDX0LCDLR3.rdqsd);
	}
	printf ("\n");

	printf ("Read DQSN Delay\t\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		/* DXnLCDLR4 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0LCDLR4 + (0x100 * bytecnt)), (ncp_uint32_t *)&regDX0LCDLR4);
		printf (" 0x%X \t",regDX0LCDLR4.rdqsnd);
	}
	printf ("\n");

	printf ("\n**************** Other Training Results *******************\n");
	printf ("\t\t\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		printf ("Byte %d \t", bytecnt);
	}
	printf ("\n");

	printf ("Static Read Delay\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++)
	{
		/* DXnGCR0 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GCR0 + (bytecnt * 0x100)), (ncp_uint32_t *)&regDX0GCR0);
		printf (" 0x%X \t",regDX0GCR0.rddly);
	}
	printf ("\n");

	/* VREF training */
	printf ("Host VREF rank0\t\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++)
	{
		/* DXnGCR5 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GCR5 + (bytecnt * 0x100)), (ncp_uint32_t *)&regDX0GCR5);
		printf (" 0x%X \t",regDX0GCR5.dxrefiselr0);
	}
	printf ("\n");

	printf ("Host VREF rank1\t\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++)
	{
		/* DXnGCR5 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GCR5 + (bytecnt * 0x100)), (ncp_uint32_t *)&regDX0GCR5);
		printf (" 0x%X \t",regDX0GCR5.dxrefiselr1);
	}
	printf ("\n");

	printf ("DRAM VREF rank0\t\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++)
	{
		/* DXnGCR6 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GCR6 + (bytecnt * 0x100)), (ncp_uint32_t *)&regDX0GCR6);
		printf (" 0x%X \t",regDX0GCR6.dxdqvrefr0);
	}
	printf ("\n");

	printf ("DRAM VREF rank1\t\t");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++)
	{
		/* DXnGCR6 */
		ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0GCR6 + (bytecnt * 0x100)), (ncp_uint32_t *)&regDX0GCR6);
		printf (" 0x%X \t",regDX0GCR6.dxdqvrefr1);
	}
	printf ("\n");

	printf ("\n**************** Read Data bit deskew Results *******************\n");
	printf ("         D  |  D  |  D  |  D  |  D  |  D  |  D  |  D  |  D  |  D  |  D  |\n");
	printf ("         Q  |  Q  |  Q  |  Q  |  Q  |  Q  |  Q  |  Q  |  M  |  Q  |  Q  |\n");
	printf ("         0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |     |  S  |  SN |\n");
	printf ("------------------------------------------------------------------\n");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		printf ("Byte %d ", bytecnt);
		printf ("  ");
		for (bits = 0; bits <= 10; bits++) 
		{
			field = bits % 4;
			/* DXnBDLR3-6 */
			ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0BDLR3 + (bytecnt * 0x100)), &tmp);
			switch (field)
			{
				case 0:
					val = (tmp & 0x3f);
					break;
				case 1:
					val = (tmp & 0x3f00) >> 8;
					break;
				case 2:
					val = (tmp & 0x3f0000) >> 16;
					break;
				case 3:
					val = (tmp & 0x3f000000) >> 24;
					break;
			}
			printf ("%d|  ", val);
		}
		printf ("\n");
	}
	printf ("\n");

	printf ("**************** Write Data bit deskew Results *******************\n");
	printf ("         D  |  D  |  D  |  D  |  D  |  D  |  D  |  D  |  D  |  D  |  O  |\n");
	printf ("         Q  |  Q  |  Q  |  Q  |  Q  |  Q  |  Q  |  Q  |  M  |  Q  |  E  |\n");
	printf ("         0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |     |  S  |     |\n");
	printf ("------------------------------------------------------------------\n");
	for (bytecnt = 0; bytecnt < numbytes; bytecnt++) 
	{
		printf ("Byte %d ", bytecnt);
		printf ("  ");
		for (bits = 0; bits <= 10; bits++) 
		{
			field = bits % 4;
			/* DXnBDLR0-2 */
			ncr_read32(phyRegion, (ncp_uint32_t) (NCP_PHY_DX0BDLR0 + (bytecnt * 0x100)), &tmp);
			switch (field)
			{
				case 0:
					val = (tmp & 0x3f);
					break;
				case 1:
					val = (tmp & 0x3f00) >> 8;
					break;
				case 2:
					val = (tmp & 0x3f0000) >> 16;
					break;
				case 3:
					val = (tmp & 0x3f000000) >> 24;
					break;
			}
			printf ("%d|  ", val);
		}
		printf ("\n");
	}
	printf ("\n");

	/* Trained Registers
#ACLCDLR0
#ACMDLR0
#ACMDLR1
#DXnGTR0
#DXnGTR1
#DXnGTR2
#DXnGTR3
#DXnGSR0
#DXnGSR1
#DXnGSR2
#DXnGSR3
#DXnGSR4
#DXnGSR5
*/

	NCP_RETURN_LABEL
		return ncpStatus;
}

ncp_st_t
ncp_cm_ddr4_phy_training_error_check(
		ncp_dev_hdl_t   dev,
		ncp_uint32_t    cmNode)
{
	ncp_st_t		ncpStatus = NCP_ST_SUCCESS;
	ncp_region_id_t     	phyRegion;

	ncp_phy_PGSR0_t regPGSR0 = {0};

	phyRegion = NCP_REGION_ID(cmNode, 0x0a);

	/* Checking Gate Training Error */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PGSR0, (ncp_uint32_t *)&regPGSR0);

	/* ncpStatus = return <appropriate return code TBD> */

	if (regPGSR0.verr)
	{
		errprintf("VREF Training Error CMEM(0x%x)\n",cmNode);
		ncpStatus = NCP_ST_ERROR;
	}

	if (regPGSR0.zcerr)
	{
		errprintf("Impedance Calibration Error CMEM(0x%x)\n",cmNode);
		ncpStatus = NCP_ST_ERROR;
	}

	if (regPGSR0.wlerr)
	{
		errprintf("Write Leveling Error CMEM(0x%x)\n",cmNode);
		ncpStatus = NCP_ST_ERROR;
	}

	if (regPGSR0.qsgerr)
	{
		errprintf("DQS Gate Training Error CMEM(0x%x)\n",cmNode);
		ncpStatus = NCP_ST_ERROR;
	}

	if (regPGSR0.wlaerr)
	{
		errprintf("Write Leveling Adjustment Error CMEM(0x%x)\n",cmNode);
		ncpStatus = NCP_ST_ERROR;
	}

	if (regPGSR0.rderr)
	{
		errprintf("Read Bit Deskew Error CMEM(0x%x)\n",cmNode);
		ncpStatus = NCP_ST_ERROR;
	}

	if (regPGSR0.wderr)
	{
		errprintf("Write Bit Deskew Error CMEM(0x%x)\n",cmNode);
		ncpStatus = NCP_ST_ERROR;
	}

	if (regPGSR0.reerr)
	{
		errprintf("Read Eye Training Error CMEM(0x%x)\n",cmNode);
		ncpStatus = NCP_ST_ERROR;
	}

	if (regPGSR0.weerr)
	{
		errprintf("Write Eye Training Error CMEM(0x%x)\n",cmNode);
		ncpStatus = NCP_ST_ERROR;
	}

	if (regPGSR0.caerr)
	{
		errprintf("CA Training Error CMEM(0x%x)\n",cmNode);
		ncpStatus = NCP_ST_ERROR;
	}

	if (regPGSR0.cawrn)
	{
		errprintf("CA Training Warning\n");
	}

	if (regPGSR0.srderr)
	{
		errprintf("Static Read Error CMEM(0x%x)\n",cmNode);
		ncpStatus = NCP_ST_ERROR;
	}

	NCP_RETURN_LABEL
		return ncpStatus;
}

ncp_st_t
ncp_cm_ddr4_phy_training(
		ncp_dev_hdl_t   dev,
		ncp_uint32_t    cmNode,
		ncp_sm_parms_t *parms)
{
	ncp_st_t		ncpStatus = NCP_ST_SUCCESS;
	unsigned int		tmp = 0;

	ncp_region_id_t     	phyRegion;

	ncp_phy_DTCR0_t 	regDTCR0 = {0};
	ncp_phy_DTCR1_t 	regDTCR1 = {0};
	/*ncp_phy_DTAR0_t 	regDTAR0 = {0};*/
	ncp_phy_PIR_t 		regPIR = {0};
	ncp_phy_PGCR0_t 	regPGCR0 = {0};
	ncp_phy_PGCR1_t 	regPGCR1 = {0};
	ncp_phy_PGCR3_t 	regPGCR3 = {0};
	ncp_phy_BISTAR1_t 	regBISTAR1 = {0};
	ncp_phy_DXCCR_t 	regDXCCR = {0};
	ncp_phy_VTCR1_t 	regVTCR1 = {0};


	phyRegion = NCP_REGION_ID(cmNode, 0x0a);

	/* PGCR1 */
	ncr_read32(phyRegion, NCP_PHY_PGCR1, (ncp_uint32_t *)&regPGCR1);
	/* Enables if set the PUB to control the interface to the PHY and SDRAM.
	 * In this mode the DFI commands from the controller are ignored. The bit must
	 * be set to 0 after the system determines it is convenient to pass control of the DFI
	 * bus to the controller. When set to 0 the DFI interface has control of the PHY and SDRAM
	 * interface except when trigerring pub operations such as BIST, DCU or data training.
	 */
	regPGCR1.pubmode = 0x1;
	ncr_write32(phyRegion, NCP_PHY_PGCR1, *((ncp_uint32_t *)&regPGCR1));

	/* ZQCR set asymmetric ODT based on number of islands ZQnDR regs */
	ncr_read32(phyRegion, NCP_PHY_RIDR, &tmp);

	/* Started Data Training */
	/*************************/

	/* DTCR0 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DTCR0, (ncp_uint32_t *)&regDTCR0);
	regDTCR0.dtrptn = 0x7; /* Data Training Repeat Number */
	regDTCR0.dtmpr = (parms->dram_class == NCP_SM_DDR4_MODE) ? 0x1 : 0x0; /* Data Training using MPR */ /* check flip */
	regDTCR0.dtcmpd = 0x1; /* DQS Gate training compare data */
	regDTCR0.rfshent = 0x1; /* Assuming PHY refresh enabled during training */
	regDTCR0.dtwbddm = parms->dm_masking; /* Data training write bit deskew data mask */
	regDTCR0.dtbdc = 0x1; /* Data training bit deskew centering enables */
	regDTCR0.dtdrs = 0x0; /* DTDRS Data training debug rank select */
	regDTCR0.dtdbs = 0x0; /* DTDBS Data training debug byte select */
	/* RDBI deskewing is not performed */
	if (parms->dbi_rd_en)
	{
		regDTCR0.dtrdbitr = 0x2;
	}
	else
	{
		regDTCR0.dtrdbitr = 0x0;
	}
	regDTCR0.dtden = 0x0; /* DTDEN Data training debug enable */
	regDTCR0.dtdstp = 0x0; /* DTDSTP Data training debug step */
	regDTCR0.dtexd = 0x0; /* DTEXD Data training extended write DQ */
	regDTCR0.dtexg = 0x0; /* DTEXG Data training early/extended gate */
	regDTCR0.rfshdt = 0x0; /* Assuming PHY refresh enabled during training */
	ncr_write32(phyRegion, NCP_PHY_DTCR0, *((ncp_uint32_t *)&regDTCR0));

	/* DTCR1 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DTCR1, (ncp_uint32_t *)&regDTCR1);
	regDTCR1.bsten = 0x1;
	regDTCR1.rdlvlen = 0x1;
	regDTCR1.rdprmvl_trn = 0x1;
	regDTCR1.rdlvlgs = 0x3;
	regDTCR1.rdlvlgdiff = 0x2;
	regDTCR1.dtrank = 0x0;
	regDTCR1.ranken = parms->topology; /* Each bit will enable each rank */
	ncr_write32(phyRegion, NCP_PHY_DTCR1, *((ncp_uint32_t *)&regDTCR1));

	/* DTAR0 */
#if 0
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DTAR0, (ncp_uint32_t *)&regDTAR0);
	regDTAR0.mprloc = 0x1;
	ncr_write32(phyRegion, NCP_PHY_DTAR0, *((ncp_uint32_t *)&regDTAR0));
#endif

	/* Used by VREF training. BIST */
	ncr_write32(phyRegion, NCP_PHY_BISTRR, 0x007e4008);
	ncr_write32(phyRegion, NCP_PHY_BISTMSKR1, 0x01000000); /* CIDMSK */

	/* BISTAR1 */
	ncr_read32(phyRegion, NCP_PHY_BISTAR1, (ncp_uint32_t *)&regBISTAR1);
	regBISTAR1.brank = 0x0;/* was parms->topology - 1;*/
	regBISTAR1.bainc = 0x8; /* for BL8 lower bits should be 000 to mark beginning of burst boundary */
	regBISTAR1.bmrank = parms->num_ranks_per_interface - 1; /* BIST Maximum rank */
	ncr_write32(phyRegion, NCP_PHY_BISTAR1, *((ncp_uint32_t *)&regBISTAR1));

	ncr_write32(phyRegion, NCP_PHY_BISTAR2, 0x000000c8); /* 31:28 BIST max bank address, 11:0 BIST max col address */
	ncr_write32(phyRegion, NCP_PHY_BISTAR4, 0x00003fff); /* 17:0 is BIST max row address */
	ncr_write32(phyRegion, NCP_PHY_BISTUDPR, 0xa5a5a5a5); /* user-data-patter 2 16-bits */

	/* VTCR1 */
	ncr_read32(phyRegion, NCP_PHY_VTCR1, (ncp_uint32_t *)&regVTCR1);
	regVTCR1.Enum = 0x1; /* number of LCDL eye points for which training is repeated */
	regVTCR1.vwcr = 0xf; /* VREF word count */
	regVTCR1.hvss = 0x0; /* host vref step size */
	ncr_write32(phyRegion, NCP_PHY_VTCR1, *((ncp_uint32_t *)&regVTCR1));

	/* PIR */
	if ((parms->packedPHYTrainingOptions >> 9) & 0x1)
	{
		ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PIR, (ncp_uint32_t *)&regPIR);
		regPIR.init = 1; 
		/* Actual init involves selection among the following steps:
		 * ZCAL: impedance calibration
		 * CA: CA training
		 * PLLINIT: pll init (pll power, reset, gear shift, wait for lock)
		 * DCAL: digital delay line calibration
		 * PHYRST: reset the AC and DATX8
		 * DRAMRST: reset, wait 200us
		 * DRAMINIT: executes DRAM init sequence
		 * WL: write leveling
		 * QSGATE: read dqs gate training
		 * WLADJ: write leveling adjust
		 * RDDSKW: read data bit deskew
		 * WRDSKW: write data bit deskew
		 * RDEYE: read data eye training
		 * WREYE: write data eye training
		 *
		 *
		 * <specials are>
		 * SRD: static read training
		 * VREF: vref training
		 * CTLDINIT: controller performs DRAM init
		 * RDIMMINIT: rdimm init
		 */
		regPIR.zcal = 0; 
		regPIR.ca = 0; 
		regPIR.pllinit = 0; 
		regPIR.dcal = 0; 
		regPIR.phyrst = 0; 
		regPIR.dramrst = 0; 
		regPIR.draminit = 0; 
		regPIR.wl = 1; 
		regPIR.qsgate = 0; 
		regPIR.wladj = 0; 
		regPIR.rddskw = 0; 
		regPIR.wrdskw = 0; 
		regPIR.rdeye = 0; 
		regPIR.wreye = 0; 
		regPIR.srd = 0; 
		regPIR.vref = 0; 
		regPIR.ctldinit = 0; 
		regPIR.rdimminit = 0; 
		ncr_write32(phyRegion, NCP_PHY_PIR, *((ncp_uint32_t *)&regPIR));

		/* Check the General Status register */

		/* poll for idone(bit 0) */
		ncpStatus = (ncr_poll(phyRegion, NCP_PHY_PGSR0,  0x21,  0x21,  1000,  10000));

		if (ncpStatus == NCP_ST_POLL_TIMEOUT)
		{
			ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
			errprintf("POLL timeout while waiting for write levelling training to complete [line:%d] PGSR0= 0x%x\n",__LINE__, tmp);
			NCP_CALL(NCP_ST_POLL_TIMEOUT);
		}

		/* Checking for Error's */
		ncpStatus = (ncp_cm_ddr4_phy_training_error_check(dev, cmNode));
		if (ncpStatus == NCP_ST_ERROR)
		{
			NCP_CALL(NCP_ST_ERROR);
		}

		ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
		dbgprintf("SUCCESS: result while waiting for write levelling training to complete [line:%d] PGSR0= 0x%x\n",__LINE__, tmp);
	}

	/* work-around for Star 9000952604 */
	/* Disable data training data compare by writing DTCR0[7]=1'b0 (DTCMPD) and enable read preamble
	 * training enable by writing DTCR1[2]=1'b1 (RDPRMBL_TRN) */

	ncr_read32(phyRegion, NCP_PHY_DTCR0, (ncp_uint32_t *)&regDTCR0);
	regDTCR0.dtcmpd = 0x0;
	ncr_write32(phyRegion, NCP_PHY_DTCR0, *((ncp_uint32_t *)&regDTCR0));

	ncr_read32(phyRegion, NCP_PHY_DTCR1, (ncp_uint32_t *)&regDTCR1);
	regDTCR1.rdprmvl_trn = 0x1;
	ncr_write32(phyRegion, NCP_PHY_DTCR1, *((ncp_uint32_t *)&regDTCR1));

	/* select to run basic gate training and read levelling by writing DTCR1[0]=1'b1 BSTEN and
	 * DTCR1[1]=1'b1 RDLVLEN */
	ncr_read32(phyRegion, NCP_PHY_DTCR1, (ncp_uint32_t *)&regDTCR1);
	regDTCR1.bsten = 0x1;
	regDTCR1.rdlvlen = 0x1;
	ncr_write32(phyRegion, NCP_PHY_DTCR1, *((ncp_uint32_t *)&regDTCR1));

	/* Disable QS counter enable by writing DXCCR[22]=1'b0 QSCNTEN */
	ncr_read32(phyRegion, NCP_PHY_DXCCR, (ncp_uint32_t *)&regDXCCR);
	regDXCCR.qscnten = 0x0;
	ncr_write32(phyRegion, NCP_PHY_DXCCR, *((ncp_uint32_t *)&regDXCCR));

	/* Select to run Read DQS Gate training */
	/*************************************/
	if ((parms->packedPHYTrainingOptions >> 10) & 0x1)
	{
		/* PIR */
		ncr_read32(phyRegion, NCP_PHY_PIR, (ncp_uint32_t *)&regPIR);
		regPIR.init = 1; 
		/* Actual init involves selection among the following steps:
		 * ZCAL: impedance calibration
		 * CA: CA training
		 * PLLINIT: pll init (pll power, reset, gear shift, wait for lock)
		 * DCAL: digital delay line calibration
		 * PHYRST: reset the AC and DATX8
		 * DRAMRST: reset, wait 200us
		 * DRAMINIT: executes DRAM init sequence
		 * WL: write leveling
		 * QSGATE: read dqs gate training
		 * WLADJ: write leveling adjust
		 * RDDSKW: read data bit deskew
		 * WRDSKW: write data bit deskew
		 * RDEYE: read data eye training
		 * WREYE: write data eye training
		 *
		 *
		 * <specials are>
		 * SRD: static read training
		 * VREF: vref training
		 * CTLDINIT: controller performs DRAM init
		 * RDIMMINIT: rdimm init
		 */
		regPIR.zcal = 0; 
		regPIR.ca = 0; 
		regPIR.pllinit = 0; 
		regPIR.dcal = 0; 
		regPIR.phyrst = 0; 
		regPIR.dramrst = 0; 
		regPIR.draminit = 0; 
		regPIR.wl = 0; 
		regPIR.qsgate = 1; 
		regPIR.wladj = 0; 
		regPIR.rddskw = 0; 
		regPIR.wrdskw = 0; 
		regPIR.rdeye = 0; 
		regPIR.wreye = 0; 
		regPIR.srd = 0; 
		regPIR.vref = 0; 
		regPIR.ctldinit = 0;
		regPIR.rdimminit = 0; 
		ncr_write32(phyRegion, NCP_PHY_PIR, *((ncp_uint32_t *)&regPIR));

		/* Check the General Status register */

		/* poll for idone(bit 0) */
		ncpStatus = (ncr_poll(phyRegion, NCP_PHY_PGSR0,  0x41,  0x41,  1000,  10000));

		if (ncpStatus == NCP_ST_POLL_TIMEOUT)
		{
			ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
			errprintf("POLL timeout while waiting for read DQS gate training to complete [line:%d] PGSR0= 0x%x\n",__LINE__, tmp);
			NCP_CALL(NCP_ST_POLL_TIMEOUT);
		}

		/* Checking for Error's */
		ncpStatus = (ncp_cm_ddr4_phy_training_error_check(dev, cmNode));
		if (ncpStatus == NCP_ST_ERROR)
		{
			NCP_CALL(NCP_ST_ERROR);
		}

		ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
		dbgprintf("SUCCESS: result while waiting for read DQS gate training to complete [line:%d] PGSR0= 0x%x\n",__LINE__, tmp);
	}

	/* Enable QS counter enable by writing DXCCR[22]=1'b1 QSCNTEN */
	ncr_read32(phyRegion, NCP_PHY_DXCCR, (ncp_uint32_t *)&regDXCCR);
	regDXCCR.qscnten = 0x1;
	ncr_write32(phyRegion, NCP_PHY_DXCCR, *((ncp_uint32_t *)&regDXCCR));

	/* Perform Write Level Adjustment */
	/*************************************/
	if ((parms->packedPHYTrainingOptions >> 11) & 0x1)
	{
		/* PIR */
		ncr_read32(phyRegion, NCP_PHY_PIR, (ncp_uint32_t *)&regPIR);
		regPIR.init = 1; 
		/* Actual init involves selection among the following steps:
		 * ZCAL: impedance calibration
		 * CA: CA training
		 * PLLINIT: pll init (pll power, reset, gear shift, wait for lock)
		 * DCAL: digital delay line calibration
		 * PHYRST: reset the AC and DATX8
		 * DRAMRST: reset, wait 200us
		 * DRAMINIT: executes DRAM init sequence
		 * WL: write leveling
		 * QSGATE: read dqs gate training
		 * WLADJ: write leveling adjust
		 * RDDSKW: read data bit deskew
		 * WRDSKW: write data bit deskew
		 * RDEYE: read data eye training
		 * WREYE: write data eye training
		 *
		 *
		 * <specials are>
		 * SRD: static read training
		 * VREF: vref training
		 * CTLDINIT: controller performs DRAM init
		 * RDIMMINIT: rdimm init
		 */
		regPIR.zcal = 0; 
		regPIR.ca = 0; 
		regPIR.pllinit = 0; 
		regPIR.dcal = 0; 
		regPIR.phyrst = 0; 
		regPIR.dramrst = 0; 
		regPIR.draminit = 0; 
		regPIR.wl = 0; 
		regPIR.qsgate = 0; 
		regPIR.wladj = 1; 
		regPIR.rddskw = 0; 
		regPIR.wrdskw = 0; 
		regPIR.rdeye = 0; 
		regPIR.wreye = 0; 
		regPIR.srd = 0; 
		regPIR.vref = 0; 
		regPIR.ctldinit = 0;
		regPIR.rdimminit = 0; 
		ncr_write32(phyRegion, NCP_PHY_PIR, *((ncp_uint32_t *)&regPIR));

		/* Check the General Status register */

		/* poll for idone(bit 0) */
		ncpStatus = (ncr_poll(phyRegion, NCP_PHY_PGSR0,  0x81,  0x81,  1000,  10000));

		if (ncpStatus == NCP_ST_POLL_TIMEOUT)
		{
			ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
			errprintf("POLL timeout while waiting for write level adjustment to complete [line:%d] PGSR0= 0x%x\n",__LINE__, tmp);
			NCP_CALL(NCP_ST_POLL_TIMEOUT);
		}

		/* Checking for Error's */
		ncpStatus = (ncp_cm_ddr4_phy_training_error_check(dev, cmNode));
		if (ncpStatus == NCP_ST_ERROR)
		{
			NCP_CALL(NCP_ST_ERROR);
		}

		ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
		dbgprintf("SUCCESS: result while waiting for write level adjustment to complete [line:%d] PGSR0= 0x%x\n",__LINE__, tmp);
	}


	/* Perform Static Read Data Training */
	/*************************************/

	/* PGCR0 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PGCR0, (ncp_uint32_t *)&regPGCR0);
	/* PHY FIFO Reset: 0 resets AC and DATX8 FIFO's without resetting PUB logic.
	 * write 1 to de-assert the reset later */
	regPGCR0.phyfrst = 0x0; 
	ncr_write32(phyRegion, NCP_PHY_PGCR0, *((ncp_uint32_t *)&regPGCR0));

	/* PGCR3 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PGCR3, (ncp_uint32_t *)&regPGCR3);
	regPGCR3.rdmode = 0x1;  /* Static read response */
	ncr_write32(phyRegion, NCP_PHY_PGCR3, *((ncp_uint32_t *)&regPGCR3));

	/* PGCR0 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PGCR0, (ncp_uint32_t *)&regPGCR0);
	/* PHY FIFO Reset: 0 resets AC and DATX8 FIFO's without resetting PUB logic.
	 * write 1 to de-assert the reset later */
	regPGCR0.phyfrst = 0x1; 
	ncr_write32(phyRegion, NCP_PHY_PGCR0, *((ncp_uint32_t *)&regPGCR0));

	/* Start SRD trainings */
	/*****************************/
	if ((parms->packedPHYTrainingOptions >> 16) & 0x1)
	{
		/* PIR */
		ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PIR, (ncp_uint32_t *)&regPIR);
		regPIR.init = 1; 
		/* Actual init involves selection among the following steps:
		 * ZCAL: impedance calibration
		 * CA: CA training
		 * PLLINIT: pll init (pll power, reset, gear shift, wait for lock)
		 * DCAL: digital delay line calibration
		 * PHYRST: reset the AC and DATX8
		 * DRAMRST: reset, wait 200us
		 * DRAMINIT: executes DRAM init sequence
		 * WL: write leveling
		 * QSGATE: read dqs gate training
		 * WLADJ: write leveling adjust
		 * RDDSKW: read data bit deskew
		 * WRDSKW: write data bit deskew
		 * RDEYE: read data eye training
		 * WREYE: write data eye training
		 *
		 *
		 * <specials are>
		 * SRD: static read training
		 * VREF: vref training
		 * CTLDINIT: controller performs DRAM init
		 * RDIMMINIT: rdimm init
		 */
		regPIR.zcal = 0; 
		regPIR.ca = 0; 
		regPIR.pllinit = 0; 
		regPIR.dcal = 0; 
		regPIR.phyrst = 0; 
		regPIR.dramrst = 0; 
		regPIR.draminit = 0; 
		regPIR.wl = 0; 
		regPIR.qsgate = 0; 
		regPIR.wladj = 0; 
		regPIR.rddskw = 0; 
		regPIR.wrdskw = 0; 
		regPIR.rdeye = 0; 
		regPIR.wreye = 0; 
		regPIR.srd = 1; 
		regPIR.vref = 0; 
		regPIR.ctldinit = 0; 
		regPIR.rdimminit = 0; 
		ncr_write32(phyRegion, NCP_PHY_PIR, *((ncp_uint32_t *)&regPIR));

		/* Check the General Status register */

		/* poll for idone(bit 0) */
		ncpStatus = (ncr_poll(phyRegion, NCP_PHY_PGSR0,  0x2001,  0x2001,  1000,  10000));

		if (ncpStatus == NCP_ST_POLL_TIMEOUT)
		{
			ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
			errprintf("POLL timeout while SRD training [line:%d] PGSR0= 0x%x\n",__LINE__, tmp);
			NCP_CALL(NCP_ST_POLL_TIMEOUT);
		}

		/* Checking for Error's */
		ncpStatus = (ncp_cm_ddr4_phy_training_error_check(dev, cmNode));
		if (ncpStatus == NCP_ST_ERROR)
		{
			NCP_CALL(NCP_ST_ERROR);
		}

		ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
		dbgprintf("SUCCESS: result while waiting for srd training to complete [line:%d] PGSR0= 0x%x\n",__LINE__, tmp);
	}

	/* Read Data Bit Deskew Training */
	/*********************************/
	if ((parms->packedPHYTrainingOptions >> 12) & 0x1)
	{
		/* PIR */
		ncr_read32(phyRegion, NCP_PHY_PIR, (ncp_uint32_t *)&regPIR);
		regPIR.init = 1; 
		/* Actual init involves selection among the following steps:
		 * ZCAL: impedance calibration
		 * CA: CA training
		 * PLLINIT: pll init (pll power, reset, gear shift, wait for lock)
		 * DCAL: digital delay line calibration
		 * PHYRST: reset the AC and DATX8
		 * DRAMRST: reset, wait 200us
		 * DRAMINIT: executes DRAM init sequence
		 * WL: write leveling
		 * QSGATE: read dqs gate training
		 * WLADJ: write leveling adjust
		 * RDDSKW: read data bit deskew
		 * WRDSKW: write data bit deskew
		 * RDEYE: read data eye training
		 * WREYE: write data eye training
		 *
		 *
		 * <specials are>
		 * SRD: static read training
		 * VREF: vref training
		 * CTLDINIT: controller performs DRAM init
		 * RDIMMINIT: rdimm init
		 */
		regPIR.zcal = 0; 
		regPIR.ca = 0; 
		regPIR.pllinit = 0; 
		regPIR.dcal = 0; 
		regPIR.phyrst = 0; 
		regPIR.dramrst = 0; 
		regPIR.draminit = 0; 
		regPIR.wl = 0; 
		regPIR.qsgate = 0; 
		regPIR.wladj = 0; 
		regPIR.rddskw = 1; 
		regPIR.wrdskw = 0; 
		regPIR.rdeye = 0; 
		regPIR.wreye = 0; 
		regPIR.srd = 0; 
		regPIR.vref = 0; 
		regPIR.ctldinit = 0; 
		regPIR.rdimminit = 0; 
		ncr_write32(phyRegion, NCP_PHY_PIR, *((ncp_uint32_t *)&regPIR));

		/* Check the General Status register */

		/* poll for idone(bit 0) */
		ncpStatus = (ncr_poll(phyRegion, NCP_PHY_PGSR0,  0x101,  0x101,  1000,  10000));

		if (ncpStatus == NCP_ST_POLL_TIMEOUT)
		{
			ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
			errprintf("POLL timeout while read data bit deskew training [line:%d] PGSR0= 0x%x\n",__LINE__, tmp);
			NCP_CALL(NCP_ST_POLL_TIMEOUT);
		}

		/* Checking for Error's */
		ncpStatus = (ncp_cm_ddr4_phy_training_error_check(dev, cmNode));
		if (ncpStatus == NCP_ST_ERROR)
		{
			NCP_CALL(NCP_ST_ERROR);
		}

		ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
		dbgprintf("SUCCESS: result while waiting for read deskew training to complete [line:%d] PGSR0= 0x%x\n",__LINE__, tmp);
	}

	/* Write Data Bit Deskew Training */
	/**********************************/
	if ((parms->packedPHYTrainingOptions >> 13) & 0x1)
	{
		/* PIR */
		ncr_read32(phyRegion, NCP_PHY_PIR, (ncp_uint32_t *)&regPIR);
		regPIR.init = 1; 
		/* Actual init involves selection among the following steps:
		 * ZCAL: impedance calibration
		 * CA: CA training
		 * PLLINIT: pll init (pll power, reset, gear shift, wait for lock)
		 * DCAL: digital delay line calibration
		 * PHYRST: reset the AC and DATX8
		 * DRAMRST: reset, wait 200us
		 * DRAMINIT: executes DRAM init sequence
		 * WL: write leveling
		 * QSGATE: read dqs gate training
		 * WLADJ: write leveling adjust
		 * RDDSKW: read data bit deskew
		 * WRDSKW: write data bit deskew
		 * RDEYE: read data eye training
		 * WREYE: write data eye training
		 *
		 *
		 * <specials are>
		 * SRD: static read training
		 * VREF: vref training
		 * CTLDINIT: controller performs DRAM init
		 * RDIMMINIT: rdimm init
		 */
		regPIR.zcal = 0; 
		regPIR.ca = 0; 
		regPIR.pllinit = 0; 
		regPIR.dcal = 0; 
		regPIR.phyrst = 0; 
		regPIR.dramrst = 0; 
		regPIR.draminit = 0; 
		regPIR.wl = 0; 
		regPIR.qsgate = 0; 
		regPIR.wladj = 0; 
		regPIR.rddskw = 0; 
		regPIR.wrdskw = 1; 
		regPIR.rdeye = 0; 
		regPIR.wreye = 0; 
		regPIR.srd = 0; 
		regPIR.vref = 0; 
		regPIR.ctldinit = 0; 
		regPIR.rdimminit = 0; 
		ncr_write32(phyRegion, NCP_PHY_PIR, *((ncp_uint32_t *)&regPIR));

		/* Check the General Status register */

		/* poll for idone(bit 0) */
		ncpStatus = (ncr_poll(phyRegion, NCP_PHY_PGSR0,  0x201,  0x201,  1000,  10000));

		if (ncpStatus == NCP_ST_POLL_TIMEOUT)
		{
			ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
			errprintf("POLL timeout while write data bit deskew training [line:%d] PGSR0= 0x%x\n",__LINE__, tmp);
			NCP_CALL(NCP_ST_POLL_TIMEOUT);
		}

		/* Checking for Error's */
		ncpStatus = (ncp_cm_ddr4_phy_training_error_check(dev, cmNode));
		if (ncpStatus == NCP_ST_ERROR)
		{
			NCP_CALL(NCP_ST_ERROR);
		}

		ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
		dbgprintf("SUCCESS: result while waiting for write deskew training to complete [line:%d] PGSR0= 0x%x\n",__LINE__, tmp);
	}

	/* Read Data Eye Training */
	/**********************************/
	/* PIR */
	if ((parms->packedPHYTrainingOptions >> 14) & 0x1)
	{
		ncr_read32(phyRegion, NCP_PHY_PIR, (ncp_uint32_t *)&regPIR);
		regPIR.init = 1; 
		/* Actual init involves selection among the following steps:
		 * ZCAL: impedance calibration
		 * CA: CA training
		 * PLLINIT: pll init (pll power, reset, gear shift, wait for lock)
		 * DCAL: digital delay line calibration
		 * PHYRST: reset the AC and DATX8
		 * DRAMRST: reset, wait 200us
		 * DRAMINIT: executes DRAM init sequence
		 * WL: write leveling
		 * QSGATE: read dqs gate training
		 * WLADJ: write leveling adjust
		 * RDDSKW: read data bit deskew
		 * WRDSKW: write data bit deskew
		 * RDEYE: read data eye training
		 * WREYE: write data eye training
		 *
		 *
		 * <specials are>
		 * SRD: static read training
		 * VREF: vref training
		 * CTLDINIT: controller performs DRAM init
		 * RDIMMINIT: rdimm init
		 */
		regPIR.zcal = 0; 
		regPIR.ca = 0; 
		regPIR.pllinit = 0; 
		regPIR.dcal = 0; 
		regPIR.phyrst = 0; 
		regPIR.dramrst = 0; 
		regPIR.draminit = 0; 
		regPIR.wl = 0; 
		regPIR.qsgate = 0; 
		regPIR.wladj = 0; 
		regPIR.rddskw = 0; 
		regPIR.wrdskw = 0; 
		regPIR.rdeye = 1; 
		regPIR.wreye = 0; 
		regPIR.srd = 0; 
		regPIR.vref = 0; 
		regPIR.ctldinit = 0; 
		regPIR.rdimminit = 0; 
		ncr_write32(phyRegion, NCP_PHY_PIR, *((ncp_uint32_t *)&regPIR));

		/* Check the General Status register */

		/* poll for idone(bit 0) */
		ncpStatus = (ncr_poll(phyRegion, NCP_PHY_PGSR0,  0x401,  0x401,  1000,  10000));

		if (ncpStatus == NCP_ST_POLL_TIMEOUT)
		{
			ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
			errprintf("POLL timeout while read data eye training [line:%d] PGSR0= 0x%x\n",__LINE__, tmp);
			NCP_CALL(NCP_ST_POLL_TIMEOUT);
		}

		/* Checking for Error's */
		ncpStatus = (ncp_cm_ddr4_phy_training_error_check(dev, cmNode));
		if (ncpStatus == NCP_ST_ERROR)
		{
			NCP_CALL(NCP_ST_ERROR);
		}

		ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
		dbgprintf("SUCCESS: result while waiting for read eye training to complete [line:%d] PGSR0= 0x%x\n",__LINE__, tmp);
	}

	/* Write Data Eye Training */
	/**********************************/
	if ((parms->packedPHYTrainingOptions >> 15) & 0x1)
	{
		/* PIR */
		ncr_read32(phyRegion, NCP_PHY_PIR, (ncp_uint32_t *)&regPIR);
		regPIR.init = 1; 
		/* Actual init involves selection among the following steps:
		 * ZCAL: impedance calibration
		 * CA: CA training
		 * PLLINIT: pll init (pll power, reset, gear shift, wait for lock)
		 * DCAL: digital delay line calibration
		 * PHYRST: reset the AC and DATX8
		 * DRAMRST: reset, wait 200us
		 * DRAMINIT: executes DRAM init sequence
		 * WL: write leveling
		 * QSGATE: read dqs gate training
		 * WLADJ: write leveling adjust
		 * RDDSKW: read data bit deskew
		 * WRDSKW: write data bit deskew
		 * RDEYE: read data eye training
		 * WREYE: write data eye training
		 *
		 *
		 * <specials are>
		 * SRD: static read training
		 * VREF: vref training
		 * CTLDINIT: controller performs DRAM init
		 * RDIMMINIT: rdimm init
		 */
		regPIR.zcal = 0; 
		regPIR.ca = 0; 
		regPIR.pllinit = 0; 
		regPIR.dcal = 0; 
		regPIR.phyrst = 0; 
		regPIR.dramrst = 0; 
		regPIR.draminit = 0; 
		regPIR.wl = 0; 
		regPIR.qsgate = 0; 
		regPIR.wladj = 0; 
		regPIR.rddskw = 0; 
		regPIR.wrdskw = 0; 
		regPIR.rdeye = 0; 
		regPIR.wreye = 1; 
		regPIR.srd = 0; 
		regPIR.vref = 0; 
		regPIR.ctldinit = 0; 
		regPIR.rdimminit = 0; 
		ncr_write32(phyRegion, NCP_PHY_PIR, *((ncp_uint32_t *)&regPIR));

		/* Check the General Status register */

		/* poll for idone(bit 0) */
		ncpStatus = (ncr_poll(phyRegion, NCP_PHY_PGSR0,  0x801,  0x801,  1000,  10000));

		if (ncpStatus == NCP_ST_POLL_TIMEOUT)
		{
			ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
			errprintf("POLL timeout while write data eye training [line:%d] PGSR0= 0x%x\n",__LINE__, tmp);
			NCP_CALL(NCP_ST_POLL_TIMEOUT);
		}

		/* Checking for Error's */
		ncpStatus = (ncp_cm_ddr4_phy_training_error_check(dev, cmNode));
		if (ncpStatus == NCP_ST_ERROR)
		{
			NCP_CALL(NCP_ST_ERROR);
		}

		ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
		dbgprintf("SUCCESS: result while waiting for write eye training to complete [line:%d] PGSR0= 0x%x\n",__LINE__, tmp);
	}

	/* VREF Training */
	/*****************/
	if ((parms->packedPHYTrainingOptions >> 17) & 0x1)
	{

		/* PIR */
		ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PIR, (ncp_uint32_t *)&regPIR);
		regPIR.init = 1; 
		/* Actual init involves selection among the following steps:
		 * ZCAL: impedance calibration
		 * CA: CA training
		 * PLLINIT: pll init (pll power, reset, gear shift, wait for lock)
		 * DCAL: digital delay line calibration
		 * PHYRST: reset the AC and DATX8
		 * DRAMRST: reset, wait 200us
		 * DRAMINIT: executes DRAM init sequence
		 * WL: write leveling
		 * QSGATE: read dqs gate training
		 * WLADJ: write leveling adjust
		 * RDDSKW: read data bit deskew
		 * WRDSKW: write data bit deskew
		 * RDEYE: read data eye training
		 * WREYE: write data eye training
		 *
		 *
		 * <specials are>
		 * SRD: static read training
		 * VREF: vref training
		 * CTLDINIT: controller performs DRAM init
		 * RDIMMINIT: rdimm init
		 */
		regPIR.zcal = 0; 
		regPIR.ca = 0; 
		regPIR.pllinit = 0; 
		regPIR.dcal = 0; 
		regPIR.phyrst = 0; 
		regPIR.dramrst = 0; 
		regPIR.draminit = 0; 
		regPIR.wl = 0; 
		regPIR.qsgate = 0; 
		regPIR.wladj = 0; 
		regPIR.rddskw = 0; 
		regPIR.wrdskw = 0; 
		regPIR.rdeye = 0; 
		regPIR.wreye = 0; 
		regPIR.srd = 0; 
		regPIR.vref = 1; 
		regPIR.ctldinit = 0; 
		regPIR.rdimminit = 0; 
		ncr_write32(phyRegion, NCP_PHY_PIR, *((ncp_uint32_t *)&regPIR));

		/* Check the General Status register */

		/* poll for idone(bit 0) */
		ncpStatus = (ncr_poll(phyRegion, NCP_PHY_PGSR0,  0x4001,  0x4001,  1000,  10000));

		if (ncpStatus == NCP_ST_POLL_TIMEOUT)
		{
			ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
			errprintf("POLL timeout while VREF training [line:%d] PGSR0= 0x%x\n",__LINE__, tmp);
			NCP_CALL(NCP_ST_POLL_TIMEOUT);
		}

		/* Checking for Error's */
		ncpStatus = (ncp_cm_ddr4_phy_training_error_check(dev, cmNode));
		if (ncpStatus == NCP_ST_ERROR)
		{
			NCP_CALL(NCP_ST_ERROR);
		}

		ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
		dbgprintf("SUCCESS: result while waiting for vref training to complete [line:%d] PGSR0= 0x%x\n",__LINE__, tmp);
	}

	ncr_read32(phyRegion, NCP_PHY_VTDR, &tmp);
	/*dbgprintf("After VREF training VTDR result = 0x%x\n",tmp);*/

	ncr_read32(phyRegion, NCP_PHY_DTCR0, (ncp_uint32_t *)&regDTCR0);
	regDTCR0.rfshdt = 0x9; /* Assuming PHY refresh enabled during training */
	ncr_write32(phyRegion, NCP_PHY_DTCR0, *((ncp_uint32_t *)&regDTCR0));

	/* PGCR1 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PGCR1, (ncp_uint32_t *)&regPGCR1);
	/* Enables if set the PUB to control the interface to the PHY and SDRAM.
	 * In this mode the DFI commands from the controller are ignored. The bit must
	 * be set to 0 after the system determines it is convenient to pass control of the DFI
	 * bus to the controller. When set to 0 the DFI interface has control of the PHY and SDRAM
	 * interface except when trigerring pub operations such as BIST, DCU or data training.
	 */
	regPGCR1.pubmode = 0x0;
	ncr_write32(phyRegion, NCP_PHY_PGCR1, *((ncp_uint32_t *)&regPGCR1));

	NCP_RETURN_LABEL
		return ncpStatus;
}

ncp_st_t
ncp_cm_ddr4_phy_init(
		ncp_dev_hdl_t   dev,
		ncp_uint32_t    cmNode,
		ncp_sm_parms_t *parms,
		ncp_common_timing_parameters_t *ctm)
{
	ncp_st_t		ncpStatus = NCP_ST_SUCCESS;

	ncp_region_id_t     	phyRegion;
	ncp_region_id_t     	ddrRegion;

	ncp_phy_PGCR2_t 	regPGCR2 = {0};
	ncp_phy_DTPR0_t 	regDTPR0 = {0};
	ncp_phy_DTPR1_t 	regDTPR1 = {0};
	ncp_phy_DTPR2_t 	regDTPR2 = {0};
	ncp_phy_DTPR3_t 	regDTPR3 = {0};
	ncp_phy_DTPR4_t 	regDTPR4 = {0};
	ncp_phy_DTPR5_t 	regDTPR5 = {0};
#if 1
	ncp_phy_PTR3_t 		regPTR3 = {0};
	ncp_phy_PTR4_t 		regPTR4 = {0};
#endif
	ncp_phy_PGCR0_t		regPGCR0 = {0};
	ncp_phy_PGCR1_t		regPGCR1 = {0};
	ncp_phy_DX1GCR0_t	regDX1GCR0 = {0};
	ncp_phy_DXCCR_t		regDXCCR = {0};
	ncp_phy_PIR_t		regPIR = {0};
	ncp_phy_DX0GCR1_t	regDX0GCR1 = {0};
	ncp_phy_DX1GCR1_t	regDX1GCR1 = {0};
	ncp_phy_DX0GCR3_t	regDX0GCR3 = {0};
	ncp_phy_DX1GCR3_t	regDX1GCR3 = {0};
	ncp_phy_DX0GCR4_t	regDX0GCR4 = {0};
	ncp_phy_DX1GCR4_t	regDX1GCR4 = {0};
	ncp_phy_DX0GCR5_t	regDX0GCR5 = {0};
	ncp_phy_DX1GCR5_t	regDX1GCR5 = {0};
	ncp_phy_DCR_t		regDCR = {0};
	ncp_phy_PGSR0_t		regPGSR0 = {0};
	ncp_phy_BISTRR_t 	regBISTRR = {0};
	ncp_phy_BISTUDPR_t 	regBISTUDPR = {0};
	ncp_phy_DSGCR_t 	regDSGCR = {0};
	ncp_phy_IOVCR0_t 	regIOVCR0 = {0};
	ncp_phy_IOVCR1_t 	regIOVCR1 = {0};
	ncp_phy_ZQCR_t 		regZQCR = {0};
	ncp_phy_ZQ0PR_t 	regZQ0PR = {0};
	ncp_phy_ZQ1PR_t 	regZQ1PR = {0};
	ncp_phy_ZQ2PR_t 	regZQ2PR = {0};
	ncp_phy_ZQ3PR_t 	regZQ3PR = {0};
	ncp_phy_ACIOCR0_t 	regACIOCR0 = {0};
	ncp_phy_PLLCR0_t 	regPLLCR0 = {0};

	ncp_memory_controller_DENALI_CTL_00_t reg00 = {0};
#ifndef __UBOOT__
	ncp_memory_controller_DENALI_CTL_85_t reg85 = {0};
	ncp_memory_controller_DENALI_CTL_86_t reg86 = {0};
#endif /* __UBOOT__ */

	ncp_uint32_t 		tmp = 0, i =0;

	phyRegion = NCP_REGION_ID(cmNode, 0x0a);
	ddrRegion = NCP_REGION_ID(cmNode, 0x09); /* memory_controller */

	NCP_COMMENT("## PHY init CMEM%d config", cmNode);

	/* check if PHY is already configured */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PGSR0, (ncp_uint32_t *)&regPGSR0);
	if (regPGSR0.aplock)
	{
		/* AC PLL lock set */
		errprintf("WARNING: PHY still configured!! PLEASE RESET. \n");
		NCP_RETURN(NCP_ST_SUCCESS);
	}

	/* PLLCR0 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PLLCR0, (ncp_uint32_t *)&regPLLCR0);
	/* PLL frequency select- select the operating range of the PLL. Supports upto 2400Mbps
	 * this is one-fourth DRAM rate */
	if (((parms->ddrClockSpeedMHz/2) >= 561) && ((parms->ddrClockSpeedMHz/2) <= 667))
	{
		regPLLCR0.frqsel = 0;
	}
	else if (((parms->ddrClockSpeedMHz/2) >= 472) && ((parms->ddrClockSpeedMHz/2) <= 560))
	{
		regPLLCR0.frqsel = 1;
	}
	else if (((parms->ddrClockSpeedMHz/2) >= 397) && ((parms->ddrClockSpeedMHz/2) <= 471))
	{
		regPLLCR0.frqsel = 2;
	}
	else if (((parms->ddrClockSpeedMHz/2) >= 333) && ((parms->ddrClockSpeedMHz/2) <= 396))
	{
		regPLLCR0.frqsel = 3;
	}
	else if (((parms->ddrClockSpeedMHz/2) >= 280) && ((parms->ddrClockSpeedMHz/2) <= 332))
	{
		regPLLCR0.frqsel = 4;
	}
	else if (((parms->ddrClockSpeedMHz/2) >= 236) && ((parms->ddrClockSpeedMHz/2) <= 279))
	{
		regPLLCR0.frqsel = 5;
	}
	else if (((parms->ddrClockSpeedMHz/2) >= 198) && ((parms->ddrClockSpeedMHz/2) <= 235))
	{
		regPLLCR0.frqsel = 6;
	}
	else if (((parms->ddrClockSpeedMHz/2) >= 166) && ((parms->ddrClockSpeedMHz/2) <= 197))
	{
		regPLLCR0.frqsel = 7;
	}
	ncr_write32(phyRegion, NCP_PHY_PLLCR0, *((ncp_uint32_t *)&regPLLCR0));

	/* PGCR0 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PGCR0, (ncp_uint32_t *)&regPGCR0);
	regPGCR0.icpc = 1;
	ncr_write32(phyRegion, NCP_PHY_PGCR0, *((ncp_uint32_t *)&regPGCR0));

	if (parms->enableECC == FALSE)
	{
		/* DXCCR */
		ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DXCCR, (ncp_uint32_t *)&regDXCCR);
		regDXCCR.msbudq = 0;
		ncr_write32(phyRegion, NCP_PHY_DXCCR, *((ncp_uint32_t *)&regDXCCR));
	}
	else
	{
		/* DXCCR */
		ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DXCCR, (ncp_uint32_t *)&regDXCCR);
		regDXCCR.msbudq = 6;
		ncr_write32(phyRegion, NCP_PHY_DXCCR, *((ncp_uint32_t *)&regDXCCR));
	}

	for (i = 0; i < 2; i++)
	{
		/* DX0BDLR0 .. DX1BDLR2 */
		ncr_read32(phyRegion, (NCP_PHY_DX0BDLR0 + (0x100 * i)), &tmp);
		tmp = 0x04040404;
		ncr_write32(phyRegion, (NCP_PHY_DX0BDLR0 + (0x100 * i)), tmp);

		ncr_read32(phyRegion, (NCP_PHY_DX0BDLR1 + (0x100 * i)), &tmp);
		tmp = 0x04040404;
		ncr_write32(phyRegion, (NCP_PHY_DX0BDLR1 + (0x100 * i)), tmp);

		ncr_read32(phyRegion, (NCP_PHY_DX0BDLR2 + (0x100 * i)), &tmp);
		tmp = 0x04040404;
		ncr_write32(phyRegion, (NCP_PHY_DX0BDLR2 + (0x100 * i)), tmp);
	}

	/* PGCR1 */
	ncr_read32(phyRegion, NCP_PHY_PGCR1, (ncp_uint32_t *)&regPGCR1);
	regPGCR1.wlstep = 1; /* write leveling step */
	/*regPGCR1.pubmode = 1;*/ /* PUB controls the interface to PHY and SDRAM */
	regPGCR1.ioddrm = 1; /* DDR4 */
	ncr_write32(phyRegion, NCP_PHY_PGCR1, *((ncp_uint32_t *)&regPGCR1));

	/* setup BIST early to UserDataPattern for VREF training bug */
	ncr_read32(phyRegion, NCP_PHY_BISTRR, (ncp_uint32_t *)&regBISTRR);
	regBISTRR.bmode = 1;
	regBISTRR.bdxen = 1; /* bist datx8 enable */
	regBISTRR.bdpat = 3;
	ncr_write32(phyRegion, NCP_PHY_BISTRR, *((ncp_uint32_t *)&regBISTRR));
	ncr_read32(phyRegion, NCP_PHY_BISTUDPR, (ncp_uint32_t *)&regBISTUDPR);
	regBISTUDPR.budp0 = 0xaaaa;
	regBISTUDPR.budp1 = 0x5555;
	ncr_write32(phyRegion, NCP_PHY_BISTUDPR, *((ncp_uint32_t *)&regBISTUDPR));
#if 1
	/* PTR3 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PTR3, (ncp_uint32_t *)&regPTR3);
	/* dram init time in cke, use 500us per dwc pub */
	regPTR3.tdinit0 = ncp_ps_to_clk(parms->tck_ps, 500000000); /* sv mentions 1300 dec */
	regPTR3.tdinit1 = Max(5, (ctm->tRFC + ncp_ps_to_clk(parms->tck_ps, 10000))); /* sv mentions 550 dec */
	ncr_write32(phyRegion, NCP_PHY_PTR3, *((ncp_uint32_t *)&regPTR3));

	/* PTR4 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PTR4, (ncp_uint32_t *)&regPTR4);
	/* 200us on power up */
	regPTR4.tdinit2 = ncp_ps_to_clk(parms->tck_ps, 200000000); /* sv mentions 500 dec */
	/* time from ZQ init to first command */
	regPTR4.tdinit3 = ctm->tZQinit; /* check 1024 */
	ncr_write32(phyRegion, NCP_PHY_PTR4, *((ncp_uint32_t *)&regPTR4));
#endif
	/* DTPR0 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DTPR0, (ncp_uint32_t *)&regDTPR0);
	regDTPR0.trtp = ctm->tRTP;
	regDTPR0.trp = ctm->tRP;
	regDTPR0.tras = ctm->tRAS;
	regDTPR0.trrd = ctm->tRRD_S;
	ncr_write32(phyRegion, NCP_PHY_DTPR0, *((ncp_uint32_t *)&regDTPR0));

	/* DTPR1 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DTPR1, (ncp_uint32_t *)&regDTPR1);
	regDTPR1.tmrd = ctm->tMRD - 8; /* per Synopsys 8000923590 */
	switch(ctm->tMOD)
	{
		case 24:
			regDTPR1.tmod = 0;
			break;
		case 25:
			regDTPR1.tmod = 1;
			break;
		case 26:
			regDTPR1.tmod = 2;
			break;
		case 27:
			regDTPR1.tmod = 3;
			break;
		case 28:
			regDTPR1.tmod = 4;
			break;
		case 29:
			regDTPR1.tmod = 5;
			break;
		case 30:
			regDTPR1.tmod = 6;
			break;
		default:
			regDTPR1.tmod = 4; /* power-up-default */
	}
	regDTPR1.tfaw = ctm->tFAW;
	/*regDTPR1.twlmrd = default */
	ncr_write32(phyRegion, NCP_PHY_DTPR1, *((ncp_uint32_t *)&regDTPR1));

	/* DTPR2 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DTPR2, (ncp_uint32_t *)&regDTPR2);
	regDTPR2.txs = ctm->tXS;
	regDTPR2.tcke = ctm->tCKE;
	/*regDTPR2.trtodt = default */
	/*regDTPR2.trtw = default */
	ncr_write32(phyRegion, NCP_PHY_DTPR2, *((ncp_uint32_t *)&regDTPR2));

	/* DTPR3 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DTPR3, (ncp_uint32_t *)&regDTPR3);
	/*regDTPR3.tdqsck = default */
	/*regDTPR3.tdqsckmax = default */
	/*regDTPR3.tdllk = default */
	regDTPR3.tccd = 0x1;/* For PHY and DDR4 */ /* ctm->tCCD_L check */
	/*regDTPR3.tofdx = default */ /* ODT turn-off delay extension */
	ncr_write32(phyRegion, NCP_PHY_DTPR3, *((ncp_uint32_t *)&regDTPR3));

	/* DTPR4 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DTPR4, (ncp_uint32_t *)&regDTPR4);
	/*regDTPR4.txp = default */
	regDTPR4.twlo = 0xf; /* write-levelling output delay */
	regDTPR4.trfc = ctm->tRFC;
	ncr_write32(phyRegion, NCP_PHY_DTPR4, *((ncp_uint32_t *)&regDTPR4));

	/* DTPR5 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DTPR5, (ncp_uint32_t *)&regDTPR5);
	regDTPR5.twtr = ctm->tWTR_L;
	regDTPR5.trcd = ctm->tRCD;
	regDTPR5.trc = ctm->tRC;
	ncr_write32(phyRegion, NCP_PHY_DTPR5, *((ncp_uint32_t *)&regDTPR5));

	/* Initializing the ddr4 phy */

	/* Power Down OFF in PHY */

	/* DX0GCR1 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DX0GCR1, (ncp_uint32_t *)&regDX0GCR1);
	regDX0GCR1.dxpdrmode = 0x0;
	regDX0GCR1.dxpddmode = 0;
	ncr_write32(phyRegion, NCP_PHY_DX0GCR1, *((ncp_uint32_t *)&regDX0GCR1));

	/* DX1GCR1 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DX1GCR1, (ncp_uint32_t *)&regDX1GCR1);
	regDX1GCR1.dxpdrmode = 0x0;
	regDX1GCR1.dxpddmode = 0;
	ncr_write32(phyRegion, NCP_PHY_DX1GCR1, *((ncp_uint32_t *)&regDX1GCR1));

	/* DX0GCR3 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DX0GCR3, (ncp_uint32_t *)&regDX0GCR3);
	regDX0GCR3.dspdrmode = 0;
	ncr_write32(phyRegion, NCP_PHY_DX0GCR3, *((ncp_uint32_t *)&regDX0GCR3));

	/* DX1GCR3 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DX1GCR3, (ncp_uint32_t *)&regDX1GCR3);
	regDX1GCR3.dspdrmode = 0;
	ncr_write32(phyRegion, NCP_PHY_DX1GCR3, *((ncp_uint32_t *)&regDX1GCR3));

	/* DX0GCR4 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DX0GCR4, (ncp_uint32_t *)&regDX0GCR4);
	regDX0GCR4.dxrefien = 0x3; /* vref enable control for DQ IO buffers of a byte lane */
	regDX0GCR4.dxrefssel = 0x9; /* 50.35%(mid-rail) */
	regDX0GCR4.dxrefiom = 0x2;
	/* default for others ?? */
	ncr_write32(phyRegion, NCP_PHY_DX0GCR4, *((ncp_uint32_t *)&regDX0GCR4));

	/* DX1GCR4 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DX1GCR4, (ncp_uint32_t *)&regDX1GCR4);
	regDX1GCR4.dxrefien = 0x3; /* vref enable control for DQ IO buffers of a byte lane */
	regDX1GCR4.dxrefssel = 0x9; /* 50.35%(mid-rail) */
	regDX1GCR4.dxrefiom = 0x2;
	/* default for others ?? */
	ncr_write32(phyRegion, NCP_PHY_DX1GCR4, *((ncp_uint32_t *)&regDX1GCR4));

	/* DX0GCR5 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DX0GCR5, (ncp_uint32_t *)&regDX0GCR5);
	regDX0GCR5.dxrefiselr0 = 0x2e; /* 76.17% byte lane internal vref select for rank 0 */
	regDX0GCR5.dxrefiselr1 = 0x2e; /* 76.17% byte lane internal vref select for rank 1 */
	/* default for others ?? */
	ncr_write32(phyRegion, NCP_PHY_DX0GCR5, *((ncp_uint32_t *)&regDX0GCR5));

	/* DX1GCR5 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DX1GCR5, (ncp_uint32_t *)&regDX1GCR5);
	regDX1GCR5.dxrefiselr0 = 0x2e; /* 76.17% byte lane internal vref select for rank 0 */
	regDX1GCR5.dxrefiselr1 = 0x2e; /* 76.17% byte lane internal vref select for rank 1 */
	/* default for others ?? */
	ncr_write32(phyRegion, NCP_PHY_DX1GCR5, *((ncp_uint32_t *)&regDX1GCR5));

	/* DSGCR */
	ncr_read32(phyRegion, NCP_PHY_DSGCR, (ncp_uint32_t *)&regDSGCR);
	regDSGCR.wrrmode = 1;
	regDSGCR.rrrmode = 1;
	regDSGCR.puren = 0;
	ncr_write32(phyRegion, NCP_PHY_DSGCR, *((ncp_uint32_t *)&regDSGCR));

	/* DCR */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DCR, (ncp_uint32_t *)&regDCR);
	regDCR.ddrmd = (parms->dram_class == NCP_SM_DDR4_MODE) ? 0x4 : 0x3;
	regDCR.ddr8bnk = 0x1; /* SDRAM uses 8 banks or less */
	regDCR.pdq = 0x0; /* which if the 0..7 DQ pins is primary for MPR */
	regDCR.mprdq = 0x1; /* both primary and other DQ pins all drive same data from MPR */
	/* This is for read data on all byte lanes during read DQS gate training */
#if 0
	if (parms->primary_bus_width == 2)
	{
		/* half-datapath feature */
		regDCR.bytemask = 0xf; 
	}
	else
	{
		regDCR.bytemask = 0xff; 
	}
#endif

	/* No simultaneous Rank Access on same clock cycle allowed */
	regDCR.nosra = parms->address_mirroring; 

	/* 2T timing should be used by PUB generated sdram transactions */
	regDCR.ddr2t = 0x1; 

	/* UDIMM address mirroring */
	/* PUB will rescramble bank and address when sending MR cmds to second rank */
	regDCR.udimm = parms->address_mirroring; 

	if (parms->sdram_device_width == 2)
	{
		/* x16 */
		regDCR.ubg = 0x1; /* un-used bank group */
	}
	ncr_write32(phyRegion, NCP_PHY_DCR, *((ncp_uint32_t *)&regDCR));

	ncr_read32(phyRegion, NCP_PHY_RIDR, &tmp);
	if ((tmp & 0xff) == 0x22)
	{
		ncr_write32(phyRegion, NCP_PHY_PLLCR2, 0x5140e7c0);
		ncr_write32(phyRegion, NCP_PHY_PLLCR3, 0x0000e670);
	}

	/* IOVCR0 Register */
	ncr_read32(phyRegion, NCP_PHY_IOVCR0, (ncp_uint32_t *)&regIOVCR0);
	regIOVCR0.acvrefisel = 0x9; /* 50.35% mid-rail */
	regIOVCR0.acrefsen = 0x0;
	regIOVCR0.acrefiom = 0x2;
	ncr_write32(phyRegion, NCP_PHY_IOVCR0, *((ncp_uint32_t *)&regIOVCR0));

	/* IOVCR1 Register */
	ncr_read32(phyRegion, NCP_PHY_IOVCR1, (ncp_uint32_t *)&regIOVCR1);
	regIOVCR1.zqrefisel = 0x9; /* 50.35% mid-rail */
	ncr_write32(phyRegion, NCP_PHY_IOVCR1, *((ncp_uint32_t *)&regIOVCR1));

	/* ZQCR Register */
	ncr_read32(phyRegion, NCP_PHY_ZQCR, (ncp_uint32_t *)&regZQCR);
	regZQCR.term_off = 0x0;
	regZQCR.zqpd = 0x0;
	regZQCR.pgwait = 0x7; /* 467 clock */
	regZQCR.zcalt = 0x1; /* continous cal */ /* check was 3 */
	regZQCR.avgmax = 0x2; /* 8 rounds */
	regZQCR.avgen = 0x1; /* averaging on */
	regZQCR.iodlmt = 0x2;
	regZQCR.asym_drv_en = 0x1;
	regZQCR.pu_odt_only = 0x1;
	regZQCR.dis_non_lin_comp = 0x0;
	regZQCR.force_zcal_vt_update = 0x0;
	regZQCR.zctrl_upper = 0x0;
	ncr_write32(phyRegion, NCP_PHY_ZQCR, *((ncp_uint32_t *)&regZQCR));

	ncr_read32(phyRegion, NCP_PHY_RIDR, &tmp);
	if ((tmp & 0xff) == 0x33)
	{
		/* ZQCR for D4MU IOs */
		regZQCR.zctrl_upper = 0x3;
		ncr_write32(phyRegion, NCP_PHY_ZQCR, *((ncp_uint32_t *)&regZQCR));
	}

	ncr_read32(phyRegion, NCP_PHY_RIDR, &tmp);
#if 0
	for (i = 0; i < 4; i++)
	{
		/* ZQCR set asymmetric ODT (based on number of islands) ZQnDR regs */
		ncr_read32(phyRegion, (NCP_PHY_ZQ0DR + (0x10 * i)), (ncp_uint32_t *)&regZQ0DR);
		if ((tmp & 0xff) != 0x22)
		{
			regZQ0DR.odt_zden = 0x1;
			regZQ0DR.zdata = 28 << 21;
		}
		ncr_write32(phyRegion, (NCP_PHY_ZQ0DR + (0x10 * i)), *((ncp_uint32_t *)&regZQ0DR));
	}
#endif
	ncr_read32(phyRegion, NCP_PHY_ZQ0PR, (ncp_uint32_t *)&regZQ0PR);
	ncr_read32(phyRegion, NCP_PHY_ZQ2PR, (ncp_uint32_t *)&regZQ2PR);
	ncr_read32(phyRegion, NCP_PHY_ZQ1PR, (ncp_uint32_t *)&regZQ1PR);
	ncr_read32(phyRegion, NCP_PHY_ZQ3PR, (ncp_uint32_t *)&regZQ3PR);
	ncr_read32(phyRegion, NCP_PHY_ACIOCR0, (ncp_uint32_t *)&regACIOCR0);
	ncr_read32(phyRegion, NCP_PHY_DXCCR, (ncp_uint32_t *)&regDXCCR);

	switch (cmNode) {
		case 0x8:
			/* X9/XLF */
			regZQ0PR.zprog_asym_drv_pu = parms->packedAddrCmdCtrlOI & 0xf;
			regZQ0PR.zprog_asym_drv_pd = parms->packedAddrCmdCtrlOI & 0xf;
			regZQ2PR.zprog_asym_drv_pu = parms->packedAddrCmdCtrlOI & 0xf;
			regZQ2PR.zprog_asym_drv_pd = parms->packedAddrCmdCtrlOI & 0xf;

			regZQ1PR.zprog_asym_drv_pu = parms->packedClockOI & 0xf;
			regZQ1PR.zprog_asym_drv_pd = parms->packedClockOI & 0xf;

			regZQ3PR.zprog_pu_odt_only = parms->packedDqDmDqsODT & 0xf;

			regZQ3PR.zprog_asym_drv_pu = parms->packedDqDmDqsOI & 0xf;
			regZQ3PR.zprog_asym_drv_pd = parms->packedDqDmDqsOI & 0xf;

			regACIOCR0.acsr = parms->packedAddrCmdCtrlClkSlewRates & 0xf;

			regDXCCR.dxsr = parms->packedDqDmDqsSlewRates & 0xf;
			break;
		case 0x9:
			/* X9 */
			regZQ0PR.zprog_asym_drv_pu = (parms->packedAddrCmdCtrlOI >> 8) & 0xf;
			regZQ0PR.zprog_asym_drv_pd = (parms->packedAddrCmdCtrlOI >> 8) & 0xf;
			regZQ2PR.zprog_asym_drv_pu = (parms->packedAddrCmdCtrlOI >> 8) & 0xf;
			regZQ2PR.zprog_asym_drv_pd = (parms->packedAddrCmdCtrlOI >> 8) & 0xf;

			regZQ1PR.zprog_asym_drv_pu = (parms->packedClockOI >> 8) & 0xf;
			regZQ1PR.zprog_asym_drv_pd = (parms->packedClockOI >> 8) & 0xf;

			regZQ3PR.zprog_pu_odt_only = (parms->packedDqDmDqsODT >> 8) & 0xf;

			regZQ3PR.zprog_asym_drv_pu = (parms->packedDqDmDqsOI >> 8) & 0xf;
			regZQ3PR.zprog_asym_drv_pd = (parms->packedDqDmDqsOI >> 8) & 0xf;

			regACIOCR0.acsr = (parms->packedAddrCmdCtrlClkSlewRates >> 8) & 0xf;

			regDXCCR.dxsr = (parms->packedDqDmDqsSlewRates >> 8) & 0xf;
			break;
#if 0
		case 0x23:
			/* XLF */
			regZQ0PR.zprog_asym_drv_pu = (parms->packedAddrCmdCtrlOI >> 16) & 0xf;
			regZQ0PR.zprog_asym_drv_pd = (parms->packedAddrCmdCtrlOI >> 16) & 0xf;
			regZQ2PR.zprog_asym_drv_pu = (parms->packedAddrCmdCtrlOI >> 16) & 0xf;
			regZQ2PR.zprog_asym_drv_pd = (parms->packedAddrCmdCtrlOI >> 16) & 0xf;

			regZQ1PR.zprog_asym_drv_pu = (parms->packedClockOI >> 16) & 0xf;
			regZQ1PR.zprog_asym_drv_pd = (parms->packedClockOI >> 16) & 0xf;

			regZQ3PR.zprog_pu_odt_only = (parms->packedDqDmDqsODT >> 16) & 0xf;

			regZQ3PR.zprog_asym_drv_pu = (parms->packedDqDmDqsOI >> 16) & 0xf;
			regZQ3PR.zprog_asym_drv_pd = (parms->packedDqDmDqsOI >> 16) & 0xf;

			regACIOCR0.acsr = (parms->packedAddrCmdCtrlClkSlewRates >> 16) & 0xf;

			regDXCCR.dxsr = (parms->packedDqDmDqsSlewRates >> 16) & 0xf;
			break;
		case 0x24:
			/* XLF */
			regZQ0PR.zprog_asym_drv_pu = (parms->packedAddrCmdCtrlOI >> 24) & 0xf;
			regZQ0PR.zprog_asym_drv_pd = (parms->packedAddrCmdCtrlOI >> 24) & 0xf;
			regZQ2PR.zprog_asym_drv_pu = (parms->packedAddrCmdCtrlOI >> 24) & 0xf;
			regZQ2PR.zprog_asym_drv_pd = (parms->packedAddrCmdCtrlOI >> 24) & 0xf;

			regZQ1PR.zprog_asym_drv_pu = (parms->packedClockOI >> 24) & 0xf;
			regZQ1PR.zprog_asym_drv_pd = (parms->packedClockOI >> 24) & 0xf;

			regZQ3PR.zprog_pu_odt_only = (parms->packedDqDmDqsODT >> 24) & 0xf;

			regZQ3PR.zprog_asym_drv_pu = (parms->packedDqDmDqsOI >> 24) & 0xf;
			regZQ3PR.zprog_asym_drv_pd = (parms->packedDqDmDqsOI >> 24) & 0xf;

			regACIOCR0.acsr = (parms->packedAddrCmdCtrlClkSlewRates >> 24) & 0xf;

			regDXCCR.dxsr = (parms->packedDqDmDqsSlewRates >> 24) & 0xf;
			break;
#endif
		default:
			NCP_CALL(NCP_ST_ERROR);
	}

	/*regZQ0PR.zprog_pu_odt_only = 0xd;*/
	ncr_write32(phyRegion, NCP_PHY_ZQ0PR, *((ncp_uint32_t *)&regZQ0PR));

	/*regZQ1PR.zprog_pu_odt_only = 0xd;*/
	ncr_write32(phyRegion, NCP_PHY_ZQ1PR, *((ncp_uint32_t *)&regZQ1PR));

	/*regZQ2PR.zprog_pu_odt_only = 0xd;*/
	ncr_write32(phyRegion, NCP_PHY_ZQ2PR, *((ncp_uint32_t *)&regZQ2PR));

	/*regZQ3PR.zqdiv = (0x7 << 4) | 0xb; *//* DQ ODT value and DQ drive impedance */
	ncr_write32(phyRegion, NCP_PHY_ZQ3PR, *((ncp_uint32_t *)&regZQ3PR));

	ncr_write32(phyRegion, NCP_PHY_ACIOCR0, *((ncp_uint32_t *)&regACIOCR0));

	ncr_write32(phyRegion, NCP_PHY_DXCCR, *((ncp_uint32_t *)&regDXCCR));

	/* PHY PGCR2 Register */

	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PGCR2, (ncp_uint32_t *)&regPGCR2);
	/* 400 is clock safety margin as suggested in PUB */
	regPGCR2.trefprd = (9 * ctm->tREFI) - 400;
	/* other fields as defaults */
	ncr_write32(phyRegion, NCP_PHY_PGCR2, *((ncp_uint32_t *)&regPGCR2));
#if 0 /* check */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_DTPR4, (ncp_uint32_t *)&regDTPR4);
	/* update TRFC - adding 2 clock cycles to prevent round off error- see sv */
	regDTPR4.trfc = ctm->tRFC + 5;
	ncr_write32(phyRegion, NCP_PHY_DTPR4, *((ncp_uint32_t *)&regDTPR4));
#endif
	/* PHY MR0 Register */
	tmp = ctm->mr0;
	ncr_write32(phyRegion, NCP_PHY_MR0, tmp);

	/* PHY MR1 Register */
	tmp = ctm->mr1;
	ncr_write32(phyRegion, NCP_PHY_MR1, tmp);

	/* PHY MR2 Register */
	tmp = ctm->mr2;
	ncr_write32(phyRegion, NCP_PHY_MR2, tmp);

	/* PHY MR3 Register */
	tmp = ctm->mr3;
	ncr_write32(phyRegion, NCP_PHY_MR3, tmp);

	/* PHY MR4 Register */
	tmp = ctm->mr4;
	ncr_write32(phyRegion, NCP_PHY_MR4, tmp);

	/* PHY MR5 Register */
	tmp = ctm->mr5;
	ncr_write32(phyRegion, NCP_PHY_MR5, tmp);

	/* PHY MR6 Register */
	tmp = ctm->mr6;
	ncr_write32(phyRegion, NCP_PHY_MR6, tmp);

	/* Force ZQ calibration */
	ncr_read32(phyRegion, NCP_PHY_ZQCR, (ncp_uint32_t *)&regZQCR);
	regZQCR.force_zcal_vt_update = 0x1;
	ncr_write32(phyRegion, NCP_PHY_ZQCR, *((ncp_uint32_t *)&regZQCR));
	regZQCR.force_zcal_vt_update = 0x0;
	ncr_write32(phyRegion, NCP_PHY_ZQCR, *((ncp_uint32_t *)&regZQCR));

	/* First: PLL init and Impedance Calibration */

	/* PIR */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PIR, (ncp_uint32_t *)&regPIR);
	/* Init trigger for DDR system init including PHY init, DRAM init, and PHY training */
	regPIR.init = 1; 
	/* Actual init involves selection among the following steps:
	 * ZCAL: impedance calibration
	 * CA: CA training
	 * PLLINIT: pll init (pll power, reset, gear shift, wait for lock)
	 * DCAL: digital delay line calibration
	 * PHYRST: reset the AC and DATX8
	 * DRAMRST: reset, wait 200us
	 * DRAMINIT: executes DRAM init sequence
	 * WL: write leveling
	 * QSGATE: read dqs gate training
	 * WLADJ: write leveling adjust
	 * RDDSKW: read data bit deskew
	 * WRDSKW: write data bit deskew
	 * RDEYE: read data eye training
	 * WREYE: write data eye training
	 *
	 *
	 * <specials are>
	 * SRD: static read training
	 * VREF: vref training
	 * CTLDINIT: controller performs DRAM init
	 * RDIMMINIT: rdimm init
	 */
	regPIR.zcal = 1; 
	regPIR.ca = 0; 
	regPIR.pllinit = 1; 
	regPIR.dcal = 1; 
	regPIR.phyrst = 1; 
	regPIR.dramrst = 0; 
	regPIR.draminit = 0; 
	regPIR.wl = 0; 
	regPIR.qsgate = 0; 
	regPIR.wladj = 0; 
	regPIR.rddskw = 0; 
	regPIR.wrdskw = 0; 
	regPIR.rdeye = 0; 
	regPIR.wreye = 0; 
	regPIR.srd = 0; 
	regPIR.vref = 0; 
	regPIR.ctldinit = 0; 
	regPIR.rdimminit = 0; 
	regPIR.dcalpse = 0; 	/* digital delay line calibration pause */
	regPIR.zcalbyp = 0;  	/* impedance calibration bypass */
	ncr_write32(phyRegion, NCP_PHY_PIR, *((ncp_uint32_t *)&regPIR));

	/* Check the General Status register */

	/* poll for idone(bit 0), pldone(1), dcdone(2), zcdone(3) */
	ncpStatus = (ncr_poll(phyRegion, NCP_PHY_PGSR0,  0xf,  0xf,  1000,  10000));

	if (ncpStatus == NCP_ST_POLL_TIMEOUT)
	{
		ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
		errprintf("POLL timeout during PHY init [line:%d] exp 0x1f read 0x%x\n",__LINE__, tmp);
		NCP_CALL(NCP_ST_POLL_TIMEOUT);
	}

	/* Checking for Error's */
	ncpStatus = (ncp_cm_ddr4_phy_training_error_check(dev, cmNode));
	if (ncpStatus == NCP_ST_ERROR)
	{
		NCP_CALL(NCP_ST_ERROR);
	}

	ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
	dbgprintf("SUCCESS: result after PHY init PLL init and impedance calibration [line:%d] read 0x%x\n",__LINE__, tmp);

	/* disable all unused bytes */
	if (parms->enableECC == FALSE)
	{
		/* DX1GCR0 */	/* 2nd byte lane */
		ncr_read32(phyRegion, NCP_PHY_DX1GCR0, (ncp_uint32_t *)&regDX1GCR0);
		regDX1GCR0.dxen = 0;
		ncr_write32(phyRegion, NCP_PHY_DX1GCR0, *((ncp_uint32_t *)&regDX1GCR0));
	}

	/* PHY Init done!!! */

#if 0 	/* Check if this is needed ?? MC is already init'd by this point
	 * should DRAM init be done by PHY-side or should PHY be told Controller will do DRAM init ?? */

	dbgprintf("DRAM init initiated by PHY!!!!!\n");
	/*ncr_read32(phyRegion, NCP_PHY_GPR0, &tmp);
	  dbgprintf("pubmode = %d PHY:GPR0=0x%x\n",regPGCR1.pubmode, tmp);*/

	/* PGCR1 */
	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PGCR1, (ncp_uint32_t *)&regPGCR1);
	/* Enables if set the PUB to control the interface to the PHY and SDRAM.
	 * In this mode the DFI commands from the controller are ignored. The bit must
	 * be set to 0 after the system determines it is convenient to pass control of the DFI
	 * bus to the controller. When set to 0 the DFI interface has control of the PHY and SDRAM
	 * interface except when trigerring pub operations such as BIST, DCU or data training.
	 */
	regPGCR1.pubmode = 0x1;
	ncr_write32(phyRegion, NCP_PHY_PGCR1, *((ncp_uint32_t *)&regPGCR1));

	/* SDRAM Initialization by PHY !!! */

	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PIR, (ncp_uint32_t *)&regPIR);
	regPIR.init = 1; 
	regPIR.zcal = 0; 
	regPIR.ca = 0; 
	regPIR.pllinit = 0; 
	regPIR.dcal = 0; 
	regPIR.phyrst = 0; 
	regPIR.dramrst = 1; 
	regPIR.draminit = 1; 
	regPIR.wl = 0; 
	regPIR.qsgate = 0; 
	regPIR.wladj = 0; 
	regPIR.rddskw = 0; 
	regPIR.wrdskw = 0; 
	regPIR.rdeye = 0; 
	regPIR.wreye = 0; 
	regPIR.srd = 0; 
	regPIR.vref = 0; 
	regPIR.ctldinit = 0; 
	regPIR.rdimminit = 0; 
	ncr_write32(phyRegion, NCP_PHY_PIR, *((ncp_uint32_t *)&regPIR));

	/* Check the General Status register */

	/* poll for idone(bit 0), didone(4) */
	ncpStatus = (ncr_poll(phyRegion, NCP_PHY_PGSR0,  0x11,  0x11,  1000,  10000));

	if (ncpStatus == NCP_ST_POLL_TIMEOUT)
	{
		ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
		errprintf("POLL timeout during SDRAM initialization by PHY [line:%d] exp 0x11 read 0x%x\n",__LINE__, tmp);
		return ncpStatus;
	}

	/* Checking for Error's */
	ncpStatus = (ncp_cm_ddr4_phy_training_error_check(dev, cmNode));
	if (ncpStatus == NCP_ST_ERROR)
	{
		return ncpStatus;
	}

	ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
	dbgprintf("SUCCESS: result during SDRAM initialization by PHY [line:%d] read 0x%x\n",__LINE__, tmp);

	/* SDRAM Initialization by PHY done !!! */
#if 0
	/* start MC init operation */
	ncr_read32(ddrRegion, (ncp_uint32_t) NCP_MEMORY_CONTROLLER_DENALI_CTL_00, (ncp_uint32_t *)&reg00);
	reg00.start = 0x1;
	ncr_write32(ddrRegion, NCP_MEMORY_CONTROLLER_DENALI_CTL_00, *((ncp_uint32_t *)&reg00));

	/* poll for memory init operation bit-8 */
	ncpStatus = ncr_poll(ddrRegion, (ncp_uint32_t) NCP_MEMORY_CONTROLLER_DENALI_CTL_84,  0x100,  0x100,  1000,  10000);

	if (ncpStatus == NCP_ST_POLL_TIMEOUT)
	{
		ncr_read32(ddrRegion, NCP_DENALI_CTL_84, &tmp);
		errprintf("POLL timeout during MC init [line:%d] exp 0x100 read 0x%x\n",__LINE__, tmp);
	}
#endif
#else
	dbgprintf("DRAM init initiated by MC!!!!!\n");
	/*ncr_read32(phyReg, NCP_PHY_PGCR1_5600, (ncp_uint32_t *)&regPGCR1);
	  ncr_read32(phyReg, NCP_PHY_GPR0_5600, &tmp);
	  dbgprintf("pubmode = %d PHY:GPR0=0x%x\n",regPGCR1.pubmode, tmp);*/

	ncr_read32(phyRegion, (ncp_uint32_t) NCP_PHY_PIR, (ncp_uint32_t *)&regPIR);
	regPIR.init = 1; 
	regPIR.zcal = 0; 
	regPIR.ca = 0; 
	regPIR.pllinit = 0; 
	regPIR.dcal = 0; 
	regPIR.phyrst = 0; 
	regPIR.dramrst = 0; 
	regPIR.draminit = 0; 
	regPIR.wl = 0; 
	regPIR.qsgate = 0; 
	regPIR.wladj = 0; 
	regPIR.rddskw = 0; 
	regPIR.wrdskw = 0; 
	regPIR.rdeye = 0; 
	regPIR.wreye = 0; 
	regPIR.srd = 0; 
	regPIR.vref = 0; 
	regPIR.ctldinit = 1; 
	regPIR.rdimminit = 0; 
	ncr_write32(phyRegion, NCP_PHY_PIR, *((ncp_uint32_t *)&regPIR));

	/*ncr_read32(phyRegion, NCP_PHY_PIR, &tmp);
	  dbgprintf("regPIR written as = 0x%x\n",tmp);*/

	ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
	dbgprintf("During MC initialization of the DRAM's [line:%d] PGSR0 = 0x%x\n",__LINE__, tmp);
	/* Check the General Status register */
#if 0
	/* poll for idone(bit 0) */
	ncpStatus = (ncr_poll(phyRegion, NCP_PHY_PGSR0,  0x1f,  0x1f,  1000,  10000));

	if (ncpStatus == NCP_ST_POLL_TIMEOUT)
	{
		ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
		errprintf("POLL timeout during MC initialization the DRAM's [line:%d] exp 0x11 read 0x%x\n",__LINE__, tmp);
		return ncpStatus;
	}

	/* Checking for Error's */
	ncpStatus = (ncp_cm_ddr4_phy_training_error_check(dev, cmNode));
	if (ncpStatus == NCP_ST_ERROR)
	{
		return ncpStatus;
	}

	ncr_read32(phyRegion, NCP_PHY_PGSR0, &tmp);
	dbgprintf("SUCCESS: result during MC initialization the DRAM's [line:%d] exp 0x11 read 0x%x\n",__LINE__, tmp);
#endif

	/* start MC init operation */

#ifdef __UBOOT__

	ncr_read32(ddrRegion, (ncp_uint32_t) NCP_MEMORY_CONTROLLER_DENALI_CTL_00, (ncp_uint32_t *)&reg00);
	reg00.start = 0x1;
	ncr_write32(ddrRegion, NCP_MEMORY_CONTROLLER_DENALI_CTL_00, *((ncp_uint32_t *)&reg00));

	/* poll for memory init operation bit-8 */
	ncpStatus = ncr_poll(ddrRegion, (ncp_uint32_t) NCP_MEMORY_CONTROLLER_DENALI_CTL_84,  0x100,  0x100,  1000,  10000);

	ncr_read32(ddrRegion, (ncp_uint32_t) NCP_MEMORY_CONTROLLER_DENALI_CTL_84, &tmp);
	dbgprintf("CTL_84 int_status = 0x%x looking for 0x100\n",tmp);

	if (ncpStatus == NCP_ST_POLL_TIMEOUT)
	{
		ncr_read32(ddrRegion, (ncp_uint32_t) NCP_MEMORY_CONTROLLER_DENALI_CTL_84, &tmp);
		errprintf("POLL timeout during MC init [line:%d] exp 0x100 read 0x%x\n",__LINE__, tmp);
	}
#else /* __UBOOT__ */

#ifdef FINAL_SOLUTION
	/*
	 * The driver for the controller is functional but all irq's are masked except BIT 8.
	 * The ISR function waits for BIT 8 to finish initialization. It ackowledges irq signal
	 * preventing unpredictable irq storms, and then informs the ncpCfgTool about 
	 * initialization. IRQ mask register bit 8 is used as a backword communication channel,
	 * as this interrupt signal must be masked (till next config reload). 
	 * If this happens, it means the controller driver is fully functional and ncpCfgTool
	 * can go forward with training.
	 *
	 * So the reading of the irq mask change below is a correct and inteded behaviour!!!
         * for additional info look into kernel src 
	 *    -> drivers/edac/axxia_edac-cmc_56xx.c
         */

	ncr_read32(ddrRegion, (ncp_uint32_t) NCP_MEMORY_CONTROLLER_DENALI_CTL_00, (ncp_uint32_t *)&reg00);
	reg00.start = 0x1;
	ncr_write32(ddrRegion, NCP_MEMORY_CONTROLLER_DENALI_CTL_00, *((ncp_uint32_t *)&reg00));

        ncpStatus = NCP_ST_SUCCESS;
        ncpStatus = ncr_poll(ddrRegion, (ncp_uint32_t) NCP_MEMORY_CONTROLLER_DENALI_CTL_86,  0x100,  0x100,  1000,  10000);
        if (ncpStatus == NCP_ST_POLL_TIMEOUT)
        {
                ncr_read32(ddrRegion, (ncp_uint32_t) NCP_MEMORY_CONTROLLER_DENALI_CTL_85, (ncp_uint32_t *)&reg85);
                reg85.int_ack = 0x00000100; /* clears associated bit in int_status */
                ncr_write32(ddrRegion, NCP_MEMORY_CONTROLLER_DENALI_CTL_85, *((ncp_uint32_t *)&reg85));

                ncr_read32(ddrRegion, (ncp_uint32_t) NCP_MEMORY_CONTROLLER_DENALI_CTL_86, &tmp);
                errprintf("POLL timeout during MC init [line:%d] exp 0x100 read 0x%x\n",__LINE__, tmp);
        }
#else /* this is a transition code - it supports all kernels - to be replaced by FINAL_SOLUTION */

	
	/* The code polls for memory init operation: bit-8 set in either int_mask or int_status
         * Updated rte should support all versions of the kernel:
         * -older versions do not ack bit 8 interrupt, and do not mask bit 8
         * -current version does not ack bit 8 interrupt, but it masks bit 8
         * -newer version will ack bit 8 interrupt and mask bit 8
         */

	ncr_read32(ddrRegion, (ncp_uint32_t) NCP_MEMORY_CONTROLLER_DENALI_CTL_00, (ncp_uint32_t *)&reg00);
	reg00.start = 0x1;
	ncr_write32(ddrRegion, NCP_MEMORY_CONTROLLER_DENALI_CTL_00, *((ncp_uint32_t *)&reg00));

	for (ncpStatus = NCP_ST_POLL_TIMEOUT,i=0;i<10;++i) {
                ncpStatus = (ncpStatus == NCP_ST_POLL_TIMEOUT)?
                        ncr_poll(ddrRegion, (ncp_uint32_t) NCP_MEMORY_CONTROLLER_DENALI_CTL_86,  0x100,  0x100,  1000,  500):
                        ncpStatus;

                ncpStatus = (ncpStatus == NCP_ST_POLL_TIMEOUT)?
                        ncr_poll(ddrRegion, (ncp_uint32_t) NCP_MEMORY_CONTROLLER_DENALI_CTL_84,  0x100,  0x100,  1000,  500):
                        ncpStatus;
        }
        ncpStatus = (ncpStatus == NCP_ST_POLL_TIMEOUT)?
                ncr_poll(ddrRegion, (ncp_uint32_t) NCP_MEMORY_CONTROLLER_DENALI_CTL_86,  0x100,  0x100,  1000,  1):
                ncpStatus;

        reg86.int_mask = 0x7fffffff;
        ncr_write32(ddrRegion, NCP_MEMORY_CONTROLLER_DENALI_CTL_86, *((ncp_uint32_t *)&reg86));

        if (ncpStatus == NCP_ST_POLL_TIMEOUT)
        {
                ncr_read32(ddrRegion, (ncp_uint32_t) NCP_MEMORY_CONTROLLER_DENALI_CTL_84, &tmp);
                errprintf("POLL timeout during MC init [line:%d] exp 0x100 read 0x%x\n",__LINE__, tmp);
                ncr_read32(ddrRegion, (ncp_uint32_t) NCP_MEMORY_CONTROLLER_DENALI_CTL_86, &tmp);
                errprintf("POLL timeout during MC init [line:%d] exp 0x100 read 0x%x\n",__LINE__, tmp);
        }

        ncr_read32(ddrRegion, (ncp_uint32_t) NCP_MEMORY_CONTROLLER_DENALI_CTL_85, (ncp_uint32_t *)&reg85);
        reg85.int_ack = 0x00000100; /* clears associated bit in int_status */
        ncr_write32(ddrRegion, NCP_MEMORY_CONTROLLER_DENALI_CTL_85, *((ncp_uint32_t *)&reg85));
#endif /* FINAL SOLUTION */

#endif /* __UBOOT__ */

#endif

	NCP_RETURN_LABEL
		return ncpStatus;
}

ncp_st_t
ncp_cm_ddr4_post_phy_training_mc_setup(
		ncp_dev_hdl_t   dev,
		ncp_uint32_t    cmNode,
		ncp_sm_parms_t *parms)
{
	ncp_st_t		ncpStatus = NCP_ST_SUCCESS;
	ncp_region_id_t     	ddrRegion;

    ncp_memory_controller_DENALI_CTL_23_t reg23 = {0};
	ncp_memory_controller_DENALI_CTL_82_t reg82 = {0};
	ncp_memory_controller_DENALI_CTL_85_t reg85 = {0};
	ncp_memory_controller_DENALI_CTL_86_t reg86 = {0};

	ddrRegion = NCP_REGION_ID(cmNode, 0x09); /* memory_controller */

    ncr_read32(ddrRegion, (ncp_uint32_t) NCP_MEMORY_CONTROLLER_DENALI_CTL_23, (ncp_uint32_t *)&reg23);
    /* enables refresh commands */
    reg23.tref_enable = 0x1;
    ncr_write32(ddrRegion, NCP_MEMORY_CONTROLLER_DENALI_CTL_23, *((ncp_uint32_t *)&reg23));

	/* DENALI_CTL_82 */
	ncr_read32(ddrRegion, (ncp_uint32_t) NCP_MEMORY_CONTROLLER_DENALI_CTL_82, (ncp_uint32_t *)&reg82);
	/* enable an automatic controller initiated update after every refresh */
	reg82.ctrlupd_req_per_aref_en = 0x1;
	ncr_write32(ddrRegion, NCP_MEMORY_CONTROLLER_DENALI_CTL_82, *((ncp_uint32_t *)&reg82));

	/* Clear all interrupts */
	/* DENALI_CTL_85 */
	ncr_read32(ddrRegion, (ncp_uint32_t) NCP_MEMORY_CONTROLLER_DENALI_CTL_85, (ncp_uint32_t *)&reg85);
	reg85.int_ack = 0x7fffffff; /* clears associated bit in int_status */
	ncr_write32(ddrRegion, NCP_MEMORY_CONTROLLER_DENALI_CTL_85, *((ncp_uint32_t *)&reg85));

	/* DENALI_CTL_86 */
	/* int_mask */
	ncr_read32(ddrRegion, (ncp_uint32_t) NCP_MEMORY_CONTROLLER_DENALI_CTL_86, (ncp_uint32_t *)&reg86);
#ifdef __UBOOT__
	reg86.int_mask = 0x0;
#else
    	if (parms->dram_class == NCP_SM_DDR4_MODE) {
		reg86.int_mask = 0x3ddff701;
	} else {
		reg86.int_mask = 0x7fdff701;
	}
#endif /* __UBOOT__ */
	ncr_write32(ddrRegion, NCP_MEMORY_CONTROLLER_DENALI_CTL_86, *((ncp_uint32_t *)&reg86));

	NCP_RETURN_LABEL
		return ncpStatus;
}

ncp_st_t
ncp_treemem_init_synopphy(
		ncp_dev_hdl_t   dev,
		ncp_uint32_t    cmId,
		ncp_sm_parms_t *parms)
{
	ncp_st_t	ncpStatus = NCP_ST_SUCCESS;
	ncp_common_timing_parameters_t	ctm = {0};
	ncp_uint32_t cmNode = 0;

	/* cmem setup
	 * XLF has 1 CMEM, X9 has 2 CMEM's
	 * If cmId == 4 && chip == XLF, then setup CMEM-0
	 * If cmId == 2 && chip == X9, then setup CMEM-0
	 * If cmId == 3 && chip == X9, then setup CMEM-1
	 */

	switch (cmId) {
		case 2:
			cmNode  = 0x8;	/* X9 */
			break;
		case 3:
			cmNode  = 0x9;	/* X9 */
			break;
		case 4:
			cmNode  = 0x8;	/* XLF */
			break;
		default:
			NCP_CALL(NCP_ST_ERROR);
	}

	/* ctm is populated so it can be commonly used during mc,phy setup */
	NCP_CALL(ncp_sm_common_setup_56xx(dev, cmNode, parms, &ctm)); 

	/* Initialize the treemem memory controller... */
	NCP_CALL(ncp_cm_denali_init_56xx(dev, cmNode, parms, &ctm)); 

	NCP_CALL(ncp_cm_ddr4_phy_init(dev, cmNode, parms, &ctm)); 

	/* Now go through training */
	NCP_CALL(ncp_cm_ddr4_phy_training(dev, cmNode, parms));

	NCP_CALL(ncp_cm_ddr4_post_phy_training_mc_setup(dev, cmNode, parms));

	NCP_RETURN_LABEL
#ifdef NCP_SM_PHY_REG_DUMP
		if (NCP_ST_SUCCESS != ncpStatus)
		{
			/* Dump contents of synop phy regs */
			ncp_cm_ddr4_phy_reg_dump(dev, cmNode);
		}
#endif
	return ncpStatus;
}
