/*
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 *
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Alex Zuepke <azu@sysgo.de>
 *
 * (C) Copyright 2002
 * Gary Jennejohn, DENX Software Engineering, <garyj@denx.de>
 *
 * (C) Copyright 2004
 * DAVE Srl
 * http://www.dave-tech.it
 * http://www.wawnet.biz
 * mailto:info@wawnet.biz
 *
 * (C) Copyright 2004 Texas Insturments
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */


#include <common.h>
#include <asm/io.h>

__weak void reset_misc(void)
{
}

int do_reset(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	if (getenv("retention_reset")) {
		puts("retention resetting\n");
		writel(readl(SYSCON+0xdc) | 1, SYSCON+0xdc);
		printf("mb: Read back Persisten Scratch Reg %x\n", readl(SYSCON+0xdc));
	} else {
		puts ("resetting ...\n");
	}

	udelay (50000);				/* wait 50 ms */

	disable_interrupts();

	if (getenv("retention_reset")) {
		reset_misc();
		for(;;) /* You never should get here */
			;
	}
	reset_cpu(0);

	/*NOTREACHED*/
	return 0;
}
