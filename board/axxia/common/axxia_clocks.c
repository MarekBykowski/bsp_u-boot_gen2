/*
 *  Copyright (C) 2015 Intel
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

#include <config.h>
#include <common.h>
#include <asm/io.h>

/*
  ==============================================================================
  ==============================================================================
  Public Interface
  ==============================================================================
  ==============================================================================
*/

unsigned int pfuse __attribute__ ((section ("data")));
#if defined(CONFIG_AXXIA_SIM)
static int clocks_uninitialized = 1;
#endif

#ifndef CONFIG_AXXIA_EMU

static ncp_uint32_t get_pll(ncp_uint32_t, ncp_uint32_t);

/*
  ------------------------------------------------------------------------------
  pll_init_frac
*/

static int
pll_init_frac(ncp_uint32_t region, ncp_uint32_t *parameters)
{
	int timeout = 10000;
	ncp_uint32_t ctrl, value;

	/* Assert all power down bits and put the PLL in bypass.  */
	ctrl = 0x0000007f;
	ncr_write32(region, 0x08, ctrl);

	/* Check if the PLL should be programmed */
	if (!(parameters[0] & 0x0001)) {
		return 0;
	}

	/* Set divider values.  */
	ncr_write32(region, 0x00, parameters[1]);

	/* If in fractional mode, write the fraction */
	if (parameters[0] & 0x0100) {
		ncr_write32(region, 0x04, parameters[2]);
	}
    
	/* Clear loss of lock counter and interrupts */
	ncr_write32(region, 0x0c, 0x0);
	ncr_write32(region, 0x10, 0x7);

	/* Set control if using external FB divider */
	if (parameters[0] & 0x1000) {
		ctrl |= 0x100;
		ncr_write32(region, 0x08, ctrl);
	}

	/* Insure at least 1us between deassert/assert of PD bits */
	udelay(1);

	/* De-assert pll PD, as well as DACPD and DSMPD in fractional mode */
	ctrl &= ~0x40;
	if (parameters[0] & 0x0100) {
		ctrl &= ~0x30;
	}
	ncr_write32(region, 0x08, ctrl);

	/* Wait for PLL Lock indication */
	udelay(1);
	do {
		ncr_read32(region, 0x20, &value);
	} while ((0 == (value & 0x80000000) &&
		  (0 < --timeout)));

	if (0 == timeout)
		return -1;

	/* Take the PLL out of bypass */
	ctrl &= ~0x01;
	ncr_write32(region, 0x08, ctrl);

	/* De-assert Fout PD bits */
	ctrl &= ~0x0c;
	ncr_write32(region, 0x08, ctrl);

	/* Enable loss of lock counter */
	if ((parameters[0] & 0x0010)) {
		ctrl |= 0x80;
		ncr_write32(region, 0x08, ctrl);
	}
	udelay(parameters[3]);

	return 0;
}


static ncp_uint32_t
get_pll(ncp_uint32_t plldiv, ncp_uint32_t seldiv)
{
	ncp_uint32_t frequency;
	ncp_uint32_t postdiv1, postdiv2;
	ncp_uint32_t fbdiv;
	ncp_uint32_t refdiv;

	fbdiv = plldiv & 0xfff;
	refdiv = (plldiv & 0x3f000) >> 12;
	postdiv2 = (plldiv & 0x1c0000) >> 18;
	postdiv1 = (plldiv & 0xe00000) >> 21;
	frequency =  CLK_REF0 / 1000;
	frequency *= fbdiv; /* Can't account for the fraction with integer math */
	frequency /= (refdiv * postdiv1 * postdiv2 * seldiv);

	return frequency;
}


#ifdef CONFIG_AXXIA_56XX
void
serdes_clock_en(void)
{
	int node;

	for (node = 0x110; node <= 0x11a; node++)
	{
		if (node == 0x115)
		{
			ncr_or(NCP_REGION_ID(node, 0), 0x4, 0x08000108);
			ncr_or(NCP_REGION_ID(node, 0), 0x8, 0x80000000);
		}
		else
		{
			ncr_or(NCP_REGION_ID(node, 0), 0x4, 0x05000000);
		}
	}
}

#else

#ifdef CONFIG_AXXIA_XLF
void
serdes_clock_en(void)
{
	int node;

	for (node = 0x110; node <= 0x11f; node++)
	{
		if (node == 0x115)
		{
			ncr_or(NCP_REGION_ID(node, 0), 0x00, 0x00000040);
			ncr_or(NCP_REGION_ID(node, 0), 0x04, 0x00000100);
			ncr_or(NCP_REGION_ID(node, 0), 0x58, 0x00000004);
		}
		else
		{
			ncr_or(NCP_REGION_ID(node, 0), 0x04, 0x05000000);
		}
	}
}

#else
void
serdes_clock_en(void)
{
}
#endif

#endif




#ifdef CONFIG_AXXIA_ANY_56XX
/*
  ------------------------------------------------------------------------------
  clocks_init
*/

int
clocks_init( int ddrRecovery )
{
	ncp_uint32_t value, i;

#ifdef DISPLAY_PARAMETERS
	printf("-- -- Clocks\n"
	       "0x%x, 0x%x\n"
	       "0x%x 0x%x 0x%x 0x%x\n"
	       "0x%x 0x%x 0x%x 0x%x\n"
	       "0x%x 0x%x 0x%x 0x%x\n"
	       "0x%x 0x%x 0x%x 0x%x\n"
	       "0x%x 0x%x 0x%x 0x%x\n"
	       "0x%x 0x%x 0x%x 0x%x\n"
	       "0x%x 0x%x 0x%x 0x%x\n"
	       "0x%x 0x%x\n",
	       clocks->version, clocks->flags,
	       clocks->syspll_flags, clocks->syspll_div, clocks->syspll_frac,
	       clocks->syspll_psd, clocks->cpupll_flags, clocks->cpupll_div,
	       clocks->cpupll_frac, clocks->cpupll_psd, clocks->sm0pll_flags,
	       clocks->sm0pll_div, clocks->sm0pll_frac, clocks->sm0pll_psd,
	       clocks->sm1pll_flags, clocks->sm1pll_div, clocks->sm1pll_frac,
	       clocks->sm1pll_psd, clocks->tm0pll_flags, clocks->tm0pll_div,
	       clocks->tm0pll_frac, clocks->tm0pll_psd, clocks->fabpll_flags,
	       clocks->fabpll_div, clocks->fabpll_frac, clocks->fabpll_psd,
	       clocks->nrcp0pll_flags, clocks->nrcp0pll_div, clocks->nrcp0pll_frac,
	       clocks->nrcp0pll_psd,
	       clocks->cpu_csw, clocks->sys_csw);
#endif

	/*
	  ----------------------------------------------------------------------
	  PLL Setup
	  ----------------------------------------------------------------------
	*/

	if (ddrRecovery == 0) {
		/* sm0pll */
		if (0 != pll_init_frac(NCP_REGION_ID(0x155, 6), &clocks->sm0pll_flags))
			return -1;
		/* sm1pll */
		if (0 != pll_init_frac(NCP_REGION_ID(0x165, 1), &clocks->sm1pll_flags))
			return -1;
	} else {
		printf("skipping SM PLL setup for ddrRecovery\n");
	}

	/* cpupll */
	if (0 != pll_init_frac(NCP_REGION_ID(0x155, 7), &clocks->cpupll_flags))
		return -1;

	/* syspll */
	if (0 != pll_init_frac(NCP_REGION_ID(0x155, 8), &clocks->syspll_flags))
		return -1;

	/* fabpll */
	if (0 != pll_init_frac(NCP_REGION_ID(0x155, 9), &clocks->fabpll_flags))
		return -1;

	/* tm0pll */
	if (0 != pll_init_frac(NCP_REGION_ID(0x165, 0), &clocks->tm0pll_flags))
		return -1;


	/* CPU switch. Switch the 4 CPU cluster clocks individually */
	value = 0;
	for (i = 0; i < 4; i++) {
		value |= clocks->cpu_csw & (0x3 << (i * 2));
		ncr_write32(NCP_REGION_ID(0x156,0), 0x0, value);
		udelay(clocks->cpupll_psd);
	}

	/* SYS/FAB switch. Switch System and FAB clocks individually */
	value = 0;

	/* clk_nrcp (bits 1:0) */
	value |= clocks->sys_csw & 0x003;
	ncr_write32(NCP_REGION_ID(0x156,0), 0x4, value);
	udelay(clocks->syspll_psd);

	/* clk_sys (bits 3:2) */
	value |= clocks->sys_csw & 0x00C;
	ncr_write32(NCP_REGION_ID(0x156,0), 0x4, value);
	udelay(clocks->syspll_psd);

	/* clk_fab (bits 5:4) */
	value |= clocks->sys_csw & 0x030;
	ncr_write32(NCP_REGION_ID(0x156,0), 0x4, value);
	udelay(clocks->fabpll_psd);

	/* clk_gic (bits 8:7) */
	value |= clocks->sys_csw & 0x180;
	ncr_write32(NCP_REGION_ID(0x156,0), 0x4, value);
	udelay(clocks->syspll_psd);

	/* clk_atclk (bits 10:9) */
	value |= clocks->sys_csw & 0x600;
	ncr_write32(NCP_REGION_ID(0x156,0), 0x4, value);
	udelay(clocks->syspll_psd);

	/* clk_nuevo (bit 11) */
	value |= clocks->sys_csw & 0x800;
	ncr_write32(NCP_REGION_ID(0x156,0), 0x4, value);
	udelay(clocks->syspll_psd);

	/* clk_per (bit 6) */
	value |= clocks->sys_csw & 0x040;
	ncr_write32(NCP_REGION_ID(0x156,0), 0x4, value);
	udelay(clocks->syspll_psd);

#if defined(CONFIG_AXXIA_SIM)
	clocks_uninitialized = 0;
#endif

    /* enable serdes clocks */
    serdes_clock_en();

	return 0;
}
#endif /* CONFIG_AXXIA_ANY_56XX */

#ifdef CONFIG_AXXIA_ANY_XLF
/*
  ------------------------------------------------------------------------------
  clocks_init
*/

int
clocks_init( int ddrRecovery )
{
	ncp_uint32_t value, i;

#ifdef DISPLAY_PARAMETERS
	printf("-- -- Clocks\n"
	       "0x%x, 0x%x\n"
	       "0x%x 0x%x 0x%x 0x%x\n"
	       "0x%x 0x%x 0x%x 0x%x\n"
	       "0x%x 0x%x 0x%x 0x%x\n"
	       "0x%x 0x%x 0x%x 0x%x\n"
	       "0x%x 0x%x 0x%x 0x%x\n"
	       "0x%x 0x%x 0x%x 0x%x\n"
	       "0x%x 0x%x 0x%x 0x%x\n"
	       "0x%x 0x%x 0x%x 0x%x\n"
	       "0x%x 0x%x 0x%x 0x%x\n"
	       "0x%x 0x%x 0x%x\n",
	       clocks->version, clocks->flags,
	       clocks->syspll_flags, clocks->syspll_div, clocks->syspll_frac,
	       clocks->syspll_psd, clocks->cpupll_flags, clocks->cpupll_div,
	       clocks->cpupll_frac, clocks->cpupll_psd, clocks->sm0pll_flags,
	       clocks->sm0pll_div, clocks->sm0pll_frac, clocks->sm0pll_psd,
	       clocks->sm1pll_flags, clocks->sm1pll_div, clocks->sm1pll_frac,
	       clocks->sm1pll_psd, clocks->sm2pll_flags, clocks->sm2pll_div,
           clocks->sm2pll_frac, clocks->sm2pll_psd, clocks->sm3pll_flags,
           clocks->sm3pll_div, clocks->sm3pll_frac, clocks->sm3pll_psd,
           clocks->tm0pll_flags, clocks->tm0pll_div, clocks->tm0pll_frac,
           clocks->tm0pll_psd, clocks->fabpll_flags, clocks->fabpll_div,
           clocks->fabpll_frac, clocks->fabpll_psd, clocks->dsppll_flags,
           clocks->dsppll_div, clocks->dsppll_frac, clocks->dsppll_psd,
	       clocks->cpu_csw, clocks->dsp_csw, clocks->sys_csw);
#endif

    /* Configure system counter to run at 256Mhz (125Mhz reference) */
    ncr_write32(NCP_REGION_ID(0x19,0x12), 0x244, 0x18);
    ncr_write32(NCP_REGION_ID(0x19,0x12), 0x248, 0x08);
    ncr_write32(NCP_REGION_ID(0x19,0x12), 0x254, 0x7d);

	/*
	  ----------------------------------------------------------------------
	  PLL Setup
	  ----------------------------------------------------------------------
	*/

	if (ddrRecovery == 0) {
		/* sm0pll */
		if (0 != pll_init_frac(NCP_REGION_ID(0x155, 0), &clocks->sm0pll_flags))
			return -1;
		/* sm1pll */
		if (0 != pll_init_frac(NCP_REGION_ID(0x155, 1), &clocks->sm1pll_flags))
			return -1;
		/* sm2pll */
		if (0 != pll_init_frac(NCP_REGION_ID(0x155, 2), &clocks->sm2pll_flags))
			return -1;
		/* sm3pll */
		if (0 != pll_init_frac(NCP_REGION_ID(0x155, 3), &clocks->sm3pll_flags))
			return -1;
	} else {
		printf("skipping SM PLL setup for ddrRecovery\n");
	}

	/* cpupll */
	if (0 != pll_init_frac(NCP_REGION_ID(0x155, 4), &clocks->cpupll_flags))
		return -1;

	/* dsppll */
	if (0 != pll_init_frac(NCP_REGION_ID(0x155, 5), &clocks->dsppll_flags))
		return -1;

	/* syspll */
	if (0 != pll_init_frac(NCP_REGION_ID(0x155, 6), &clocks->syspll_flags))
		return -1;

	/* fabpll */
	if (0 != pll_init_frac(NCP_REGION_ID(0x155, 7), &clocks->fabpll_flags))
		return -1;

	/* tm0pll */
	if (0 != pll_init_frac(NCP_REGION_ID(0x155, 8), &clocks->tm0pll_flags))
		return -1;


	/* CPU switch. Switch the 8 CPU cluster clocks individually */
	value = 0;
	for (i = 0; i < 8; i++) {
		value |= clocks->cpu_csw & (0x3 << (i * 2));
		ncr_write32(NCP_REGION_ID(0x156,0), 0x0, value);
		udelay(clocks->cpupll_psd);
	}

	/* DSP switch. Switch the 4 DSP cluster clocks individually */
	value = 0;
	for (i = 0; i < 4; i++) {
		value |= clocks->dsp_csw & (0x3 << (i * 2));
		ncr_write32(NCP_REGION_ID(0x156,0), 0x4, value);
		udelay(clocks->dsppll_psd);
	}

	/* SYS switch. Switch System clocks individually */
	value = 0;

	/* clk_atclk (bits 1:0) */
	value |= clocks->sys_csw & 0x0003;
	ncr_write32(NCP_REGION_ID(0x156,0), 0x8, value);
	udelay(clocks->cpupll_psd);

	/* clk_dec (bit 3) */
	value |= clocks->sys_csw & 0x0008;
	ncr_write32(NCP_REGION_ID(0x156,0), 0x8, value);
	udelay(clocks->syspll_psd);

	/* clk_fab (bits 5:4) */
	value |= clocks->sys_csw & 0x0030;
	ncr_write32(NCP_REGION_ID(0x156,0), 0x8, value);
	udelay(clocks->fabpll_psd);

	/* clk_fes (bits 7:6) */
	value |= clocks->sys_csw & 0x00c0;
	ncr_write32(NCP_REGION_ID(0x156,0), 0x8, value);
	udelay(clocks->dsppll_psd);

	/* clk_nrcp (bits 9:8) */
	value |= clocks->sys_csw & 0x0300;
	ncr_write32(NCP_REGION_ID(0x156,0), 0x8, value);
	udelay(clocks->syspll_psd);

	/* clk_per (bit 12) */
	value |= clocks->sys_csw & 0x1000;
	ncr_write32(NCP_REGION_ID(0x156,0), 0x8, value);
	udelay(clocks->syspll_psd);

	/* clk_sys2x (bits 14:13) */
	value |= clocks->sys_csw & 0x6000;
	ncr_write32(NCP_REGION_ID(0x156,0), 0x8, value);
	udelay(clocks->syspll_psd);

#if defined(CONFIG_AXXIA_SIM)
	clocks_uninitialized = 0;
#endif

    /* enable serdes clocks */
    serdes_clock_en();

	return 0;
}
#endif /* CONFIG_AXXIA_ANY_XLF */
#endif/* CONFIG_AXXIA_EMU */

#ifdef CONFIG_AXXIA_ANY_56XX
/*
  ------------------------------------------------------------------------------
  axxia_clock_get
*/

int
acp_clock_get(acp_clock_t clock, ncp_uint32_t *frequency)
{
#if defined(CONFIG_AXXIA_EMU)

	switch (clock) {
	case clock_system:
		*frequency = COUNTER_FREQUENCY / 1000;
		break;
	case clock_peripheral:
		*frequency = 2000;
		break;
	case clock_core:
		*frequency = 2000;
		break;
	case clock_emmc:
		*frequency = 2000;
		break;
	default:
		*frequency = 0ULL;
		return -1;
		break;
	}

	return 0;

#else

	ncp_uint32_t csw;
	ncp_uint32_t div;

#if defined(CONFIG_AXXIA_SIM)

	if (0 != clocks_uninitialized) {
		switch (clock) {
		case clock_system:
			*frequency = COUNTER_FREQUENCY / 1000;
			break;
		case clock_peripheral:
			*frequency = 250;
			break;
		case clock_core:
			*frequency = 125000;
			break;
		case clock_emmc:
			*frequency = 50000;
			break;
		default:
			*frequency = 0ULL;
			return -1;
			break;
		}

		return 0;
	}
#endif

	switch (clock) {
	case clock_fab:
		ncr_read32(NCP_REGION_ID(0x156,0), 0x4, &csw);

		if (0 == (csw & 0x00000030)) {
			*frequency = CLK_REF0 / 1000;
		} else if (1 == (csw & 0x00000030) >> 4) {
			ncr_read32(NCP_REGION_ID(0x155,9), 0x0, &div);
			*frequency = get_pll(div, 1);
		} else {
			ncr_read32(NCP_REGION_ID(0x155,9), 0x0, &div);
			*frequency = get_pll(div, 2);
		}
		break;

	case clock_system:
		ncr_read32(NCP_REGION_ID(0x156,0), 0x4, &csw);

		if (0 == (csw & 0x0000000c)) {
			*frequency = CLK_REF0 / 1000;
		} else if (1 == (csw & 0x0000000c) >> 2) {
			ncr_read32(NCP_REGION_ID(0x155,8), 0x0, &div);
			*frequency = get_pll(div, 1);
		} else {
			ncr_read32(NCP_REGION_ID(0x155,8), 0x0, &div);
			*frequency = get_pll(div, 2);
		}
		break;

	case clock_core:  /* returns cluster0 speed */
		ncr_read32(NCP_REGION_ID(0x156,0), 0x0, &csw);

		if (0 == (csw & 0x00000003)) {
			*frequency = CLK_REF0 / 1000;
		} else if (1 == (csw & 0x00000003)) {
			ncr_read32(NCP_REGION_ID(0x155,7), 0x0, &div);
			*frequency = get_pll(div, 1);
		} else {
			ncr_read32(NCP_REGION_ID(0x155,7), 0x0, &div);
			*frequency = get_pll(div, 2);
		}
		break;

	case clock_memory:   /* returns sm0 speed */
		ncr_read32(NCP_REGION_ID(0x155,6), 0x0, &div);
		*frequency = get_pll(div, 1);
		break;

	case clock_treemem:
		ncr_read32(NCP_REGION_ID(0x165,0), 0x0, &div);
		*frequency = get_pll(div, 1);
		break;

	case clock_peripheral:
		ncr_read32(NCP_REGION_ID(0x156,0), 0x4, &csw);

		if (0 == (csw & 0x00000040)) {
			*frequency = CLK_REF0 / 1000;
		} else {
			ncr_read32(NCP_REGION_ID(0x155,8), 0x0, &div);
			*frequency = get_pll(div, 2);
		}
		break;

	case clock_emmc:
		ncr_read32(NCP_REGION_ID(0x156,0), 0x4, &csw);

		if (0 == (csw & 0x00000040)) {
			*frequency = CLK_REF0 / (1000 * 5);
		} else {
			ncr_read32(NCP_REGION_ID(0x155,8), 0x0, &div);
			*frequency = get_pll(div, (2 * 5));
		}
		break;

	default:
		return -1;
		break;
	}

	return 0;

#endif	/* CONFIG_AXXIA_EMU */
}

/*
  ------------------------------------------------------------------------------
*/

void
axxia_display_clocks(void)
{
#if !defined(CONFIG_AXXIA_EMU)
	ncp_uint32_t speed;
	ncp_uint32_t ctrl;
	ncp_uint32_t loss_count;

	printf("\n== PLL/Clock Speeds ==\n");

	acp_clock_get(clock_system, &speed);
	speed /= 1000;
	printf("        System: %4u MHz Loss of Lock Count ", speed);
	ncr_read32(NCP_REGION_ID(0x155, 8), 0x8, &ctrl);
	if (0 == (ctrl & 0x80))
		printf("Disabled\n");
	else {
		ncr_read32(NCP_REGION_ID(0x155, 8), 0xc, &loss_count);
		printf("%u\n", loss_count);
	}

	acp_clock_get(clock_core, &speed);
	speed /= 1000;
	printf("           CPU: %4u MHz Loss of Lock Count ", speed);
	ncr_read32(NCP_REGION_ID(0x155, 7), 0x8, &ctrl);
	if (0 == (ctrl & 0x80))
		printf("Disabled\n");
	else {
		ncr_read32(NCP_REGION_ID(0x155, 7), 0xc, &loss_count);
		printf("%u\n", loss_count);
	}

	acp_clock_get(clock_memory, &speed);
	speed /= 1000;
	printf("        Memory: %4u MHz Loss of Lock Count ", speed);
	ncr_read32(NCP_REGION_ID(0x155, 6), 0x8, &ctrl);
	if (0 == (ctrl & 0x80))
		printf("Disabled / ");
	else {
		ncr_read32(NCP_REGION_ID(0x155, 6), 0xc, &loss_count);
		printf("%u / ", loss_count);
	}
	ncr_read32(NCP_REGION_ID(0x165, 1), 0x8, &ctrl);
	if (0 == (ctrl & 0x80))
		printf("Disabled\n");
	else {
		ncr_read32(NCP_REGION_ID(0x165, 1), 0xc, &loss_count);
		printf("%u\n", loss_count);
	}

	acp_clock_get(clock_fab, &speed);
	speed /= 1000;
	printf("        Fabric: %4u MHz Loss of Lock Count ", speed);
	ncr_read32(NCP_REGION_ID(0x155, 9), 0x8, &ctrl);
	if (0 == (ctrl & 0x80))
		printf("Disabled\n");
	else {
		ncr_read32(NCP_REGION_ID(0x155, 9), 0xc, &loss_count);
		printf("%u\n", loss_count);
	}

	acp_clock_get(clock_treemem, &speed);
	speed /= 1000;
	printf("          Tree: %4u MHz Loss of Lock Count ", speed);
	ncr_read32(NCP_REGION_ID(0x165, 0), 0x8, &ctrl);
	if (0 == (ctrl & 0x80))
		printf("Disabled\n");
	else {
		ncr_read32(NCP_REGION_ID(0x165, 0), 0xc, &loss_count);
		printf("%u\n", loss_count);
	}

	acp_clock_get(clock_peripheral, &speed);
	speed /= 1000;
	printf("    Peripheral: %4u MHz\n", speed);

	acp_clock_get(clock_emmc, &speed);
	speed /= 1000;
	printf("       SD/eMMC: %4u MHz\n\n", speed);
#endif	/* CONFIG_AXXIA_EMU */

	return;
}
#endif /* CONFIG_AXXIA_ANY_56XX */

#ifdef CONFIG_AXXIA_ANY_XLF
/*
  ------------------------------------------------------------------------------
  axxia_clock_get
*/

int
acp_clock_get(acp_clock_t clock, ncp_uint32_t *frequency)
{
#if defined(CONFIG_AXXIA_EMU)

	switch (clock) {
	case clock_system:
		*frequency = COUNTER_FREQUENCY / 1000;
		break;
	case clock_peripheral:
		*frequency = 2000;
		break;
	case clock_core:
		*frequency = 2000;
		break;
	case clock_fab:
		*frequency = 2000;
		break;
	case clock_dsp:
		*frequency = 2000;
		break;
	default:
		*frequency = 0ULL;
		return -1;
		break;
	}

	return 0;

#else

	ncp_uint32_t csw;
	ncp_uint32_t div;

#if defined(CONFIG_AXXIA_SIM)

	if (0 != clocks_uninitialized) {
		switch (clock) {
		case clock_system:
			*frequency = COUNTER_FREQUENCY / 1000;
			break;
		case clock_peripheral:
			*frequency = 250;
			break;
		case clock_core:
			*frequency = 125000;
			break;
		case clock_emmc:
			*frequency = 50000;
			break;
		default:
			*frequency = 0ULL;
			return -1;
			break;
		}

		return 0;
	}
#endif

	switch (clock) {
	case clock_fab:
		ncr_read32(NCP_REGION_ID(0x156,0), 0x8, &csw);

		if (0 == (csw & 0x00000030)) {
			*frequency = CLK_REF0 / 1000;
		} else if (1 == (csw & 0x00000030) >> 4) {
			ncr_read32(NCP_REGION_ID(0x155,7), 0x0, &div);
			*frequency = get_pll(div, 1);
		} else {
			ncr_read32(NCP_REGION_ID(0x155,7), 0x0, &div);
			*frequency = get_pll(div, 2);
		}
		break;

	case clock_system:
		ncr_read32(NCP_REGION_ID(0x156,0), 0x8, &csw);

		if (0 == (csw & 0x00006000)) {
			*frequency = CLK_REF0 / 1000;
		} else if (1 == (csw & 0x00006000) >> 13) {
			ncr_read32(NCP_REGION_ID(0x155,6), 0x0, &div);
			*frequency = get_pll(div, 1 * 2);
		} else {
			ncr_read32(NCP_REGION_ID(0x155,6), 0x0, &div);
			*frequency = get_pll(div, 2 * 2);
		}
		break;

	case clock_core:  /* returns cluster0 speed */
		ncr_read32(NCP_REGION_ID(0x156,0), 0x0, &csw);

		if (0 == (csw & 0x00000003)) {
			*frequency = CLK_REF0 / 1000;
		} else if (1 == (csw & 0x00000003)) {
			ncr_read32(NCP_REGION_ID(0x155,4), 0x0, &div);
			*frequency = get_pll(div, 1);
		} else {
			ncr_read32(NCP_REGION_ID(0x155,4), 0x0, &div);
			*frequency = get_pll(div, 2);
		}
		break;

	case clock_dsp:  /* returns cluster0 speed */
		ncr_read32(NCP_REGION_ID(0x156,0), 0x4, &csw);

		if (0 == (csw & 0x00000003)) {
			*frequency = CLK_REF0 / 1000;
		} else if (1 == (csw & 0x00000003)) {
			ncr_read32(NCP_REGION_ID(0x155,5), 0x0, &div);
			*frequency = get_pll(div, 1);
		} else {
			ncr_read32(NCP_REGION_ID(0x155,5), 0x0, &div);
			*frequency = get_pll(div, 2);
		}
		break;

	case clock_memory:   /* returns sm0 speed */
		ncr_read32(NCP_REGION_ID(0x155,0), 0x0, &div);
		*frequency = get_pll(div, 1);
		break;

	case clock_treemem:
		ncr_read32(NCP_REGION_ID(0x155,8), 0x0, &div);
		*frequency = get_pll(div, 1);
		break;

	case clock_peripheral:
		ncr_read32(NCP_REGION_ID(0x156,0), 0x8, &csw);

		if (0 == (csw & 0x00001000)) {
			*frequency = CLK_REF0 / 1000;
		} else {
			ncr_read32(NCP_REGION_ID(0x155,6), 0x0, &div);
			*frequency = get_pll(div, 4);
		}
		break;

	default:
		return -1;
		break;
	}

	return 0;

#endif	/* CONFIG_AXXIA_EMU */
}

/*
  ------------------------------------------------------------------------------
*/

void
axxia_display_clocks(void)
{
#if !defined(CONFIG_AXXIA_EMU)
	ncp_uint32_t speed;
	ncp_uint32_t ctrl;
	ncp_uint32_t loss_count;

	printf("\n== PLL/Clock Speeds ==\n");

	acp_clock_get(clock_system, &speed);
	speed /= 1000;
	printf("        System: %4u MHz Loss of Lock Count ", speed);
	ncr_read32(NCP_REGION_ID(0x155, 6), 0x8, &ctrl);
	if (0 == (ctrl & 0x80))
		printf("Disabled\n");
	else {
		ncr_read32(NCP_REGION_ID(0x155, 6), 0xc, &loss_count);
		printf("%u\n", loss_count);
	}

	acp_clock_get(clock_core, &speed);
	speed /= 1000;
	printf("           CPU: %4u MHz Loss of Lock Count ", speed);
	ncr_read32(NCP_REGION_ID(0x155, 4), 0x8, &ctrl);
	if (0 == (ctrl & 0x80))
		printf("Disabled\n");
	else {
		ncr_read32(NCP_REGION_ID(0x155, 4), 0xc, &loss_count);
		printf("%u\n", loss_count);
	}

	acp_clock_get(clock_memory, &speed);
	speed /= 1000;
	printf("        Memory: %4u MHz Loss of Lock Count ", speed);
	ncr_read32(NCP_REGION_ID(0x155, 0), 0x8, &ctrl);
	if (0 == (ctrl & 0x80))
		printf("Disabled / ");
	else {
		ncr_read32(NCP_REGION_ID(0x155, 0), 0xc, &loss_count);
		printf("%u / ", loss_count);
	}
	ncr_read32(NCP_REGION_ID(0x155, 1), 0x8, &ctrl);
	if (0 == (ctrl & 0x80))
		printf("Disabled\n");
	else {
		ncr_read32(NCP_REGION_ID(0x155, 1), 0xc, &loss_count);
		printf("%u\n", loss_count);
	}
	ncr_read32(NCP_REGION_ID(0x155, 2), 0x8, &ctrl);
	if (0 == (ctrl & 0x80)) {
		printf("                                            ");
		printf("Disabled / ");
    } else {
		ncr_read32(NCP_REGION_ID(0x155, 2), 0xc, &loss_count);
		printf("                                            ");
		printf("%u / ", loss_count);
	}
	ncr_read32(NCP_REGION_ID(0x155, 3), 0x8, &ctrl);
	if (0 == (ctrl & 0x80))
		printf("Disabled\n");
	else {
		ncr_read32(NCP_REGION_ID(0x155, 3), 0xc, &loss_count);
		printf("%u\n", loss_count);
	}

	acp_clock_get(clock_fab, &speed);
	speed /= 1000;
	printf("        Fabric: %4u MHz Loss of Lock Count ", speed);
	ncr_read32(NCP_REGION_ID(0x155, 7), 0x8, &ctrl);
	if (0 == (ctrl & 0x80))
		printf("Disabled\n");
	else {
		ncr_read32(NCP_REGION_ID(0x155, 7), 0xc, &loss_count);
		printf("%u\n", loss_count);
	}

	acp_clock_get(clock_treemem, &speed);
	speed /= 1000;
	printf("          Tree: %4u MHz Loss of Lock Count ", speed);
	ncr_read32(NCP_REGION_ID(0x155, 8), 0x8, &ctrl);
	if (0 == (ctrl & 0x80))
		printf("Disabled\n");
	else {
		ncr_read32(NCP_REGION_ID(0x155, 8), 0xc, &loss_count);
		printf("%u\n", loss_count);
	}

	acp_clock_get(clock_dsp, &speed);
	speed /= 1000;
	printf("           DSP: %4u MHz Loss of Lock Count ", speed);
	ncr_read32(NCP_REGION_ID(0x155, 5), 0x8, &ctrl);
	if (0 == (ctrl & 0x80))
		printf("Disabled\n");
	else {
		ncr_read32(NCP_REGION_ID(0x155, 5), 0xc, &loss_count);
		printf("%u\n", loss_count);
	}

	acp_clock_get(clock_peripheral, &speed);
	speed /= 1000;
	printf("    Peripheral: %4u MHz\n\n", speed);
#endif	/* CONFIG_AXXIA_EMU */

	return;
}
#endif /* CONFIG_AXXIA_ANY_XLF */

