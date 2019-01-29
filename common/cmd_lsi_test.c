/*
 * common/cmd_lsi_test.c
 *
 * (C) Copyright 2010
 * LSI, john.jacques@lsi.com
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <config.h>
#include <common.h>
#include <command.h>

/*
  ======================================================================
  Local Stuff
  ======================================================================
*/

/*
  ======================================================================
  U-Boot Stuff
  ======================================================================
*/

/*
  ----------------------------------------------------------------------
  do_test
*/
  
int
do_smccc(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
#if 0
	*((unsigned long*) (unsigned long) (0x3000000)) = 0xdeadbeef;
#else
	enter_ns();
	printf("smc #0 completed\n");
#endif

	return 0;
}

/*
  ======================================================================
  Command Definitions
  ======================================================================
*/

U_BOOT_CMD(
	   smccc, 1, 0, do_smccc,
	   "test smc",
	   ""
);
