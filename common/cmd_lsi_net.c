/*
 * common/cmd_lsi_net.c
 *
 * (C) Copyright 2009
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

#ifndef CONFIG_SPL_BUILD

#include <config.h>
#include <common.h>
#include <exports.h>
#include <command.h>

DECLARE_GLOBAL_DATA_PTR;

extern int dumprx;
extern int dumptx;

/*
  ======================================================================
  Local Stuff
*/

/*
  ----------------------------------------------------------------------
  do_net
*/
  
int
do_net(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	if( 0 == strncmp( argv[1], "dr", strlen( "dr" ) ) ) {
		dumprx = dumprx ? 0 : 1;
		printf("Dump receive packets %s\n", dumprx ? "On" : "Off");

		return 0;
	}

	if( 0 == strncmp( argv[1], "dt", strlen( "dt" ) ) ) {
		dumptx = dumptx ? 0 : 1;
		printf("Dump transmit packets %s\n", dumptx ? "On" : "Off");

		return 0;
	}

	if( 0 == strncmp( argv[1], "l", strlen( "l" ) ) ) {
		int test = 0;

		if (3 == argc) {
			if (0 == strncmp(argv[2], "n", strlen("n"))) {
				test = 1;
			} else if (0 == strncmp(argv[2], "p", strlen("p"))) {
				test = 2;
			} else {
				printf("Unknow Loopback Type!\n");
				return -1;
			}
		}

		printf("Starting Loopback Test -- Ctrl-C to Exit.\n");
		lsi_net_loopback_test(eth_get_dev(), test);

		return 0;
	}

	if( 0 == strncmp( argv[1], "r", strlen( "r" ) ) ) {
		printf( "Receiving Packets -- Ctrl-C to Exit.\n" );
		lsi_net_receive_test(eth_get_dev());

		return 0;
	}

	if( 0 == strncmp( argv[1], "s", strlen( "s" ) ) ) {
		char * buffer = malloc( 60 );
		/* Copy Uboot to buffer */
		memmove(buffer, 0, 60);

		if( ( char * ) 0 == buffer ) {
			printf( "malloc() failed!\n" );
			printf( "%s", cmdtp->usage);

			return -1;
		} else {
			printf( "Sending Packet...\n" );
			eth_init( );
			eth_send( ( void * ) buffer, 60 );
			eth_halt( );
			free( buffer );

			return 0;
		}
	}

	printf( "%s", cmdtp->usage );

	return -1;
}

int
do_l3locking(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	unsigned tmp, i;
	/*RNI accepts secure and non-secure*/
	ncr_write32(NCP_REGION_ID(0x170, 0x1), 0x8, 0x1);
	/*override HN to signal secure*/
	ncr_write32(NCP_REGION_ID(0x170, 0x1), 0x43800, 0x2);
	/*override RNI to signal secure*/
	ncr_write32(NCP_REGION_ID(0x170, 0x1), 0x42800, 0x2);

	/*L3 locked ways*/
	for (i=0x20; i <= 0x27; i++) {
		ncr_write32(NCP_REGION_ID(0x1e0, i), 0x40, 0x4);
		ncr_read32(NCP_REGION_ID(0x1e0, i), 0x40, &tmp);
		printf("mb: 0x1e0.0x20.0x40 read back 0x%x\n", tmp);
	}
	return 0;
}

/*
  ======================================================================
  Command Definitions
  ======================================================================
*/

U_BOOT_CMD(lock, 1, 0, do_l3locking,  
          "access L3 locking\n",  
          "");                     

U_BOOT_CMD(net, 3, 0, do_net,
	   "net loopback|receive|send|dr|dt [type]\n",
	   "l,oopback loop all received packets back, specify the type\n"
	   "     net -- loop packets from the network back out\n"
	   "     phy -- expect the phy to loop packets back\n"
	   "            Remeber to put the PHY in loopback mode!\n"
	   "r,ecevie packets, and dump them to the screen\n"
	   "s,end send one packet\n"
	   "dr toggle the \"dumprx\" flag\n"
	   "dt toggle the \"dumptx\" flag\n");

#endif /* CONFIG_SPL_BUILD */
