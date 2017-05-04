/*
 *  Copyright (C) 2011 LSI Corporation
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
#include <malloc.h>
#include <asm/io.h>
#include <net.h>
#include <miiphy.h>
#include "ncp_task_pvt.h"

DECLARE_GLOBAL_DATA_PTR;



#define DEBUG
#include <config.h>

/*==============================================================================
  ==============================================================================
  Private Interface
  ==============================================================================
  ==============================================================================
*/

int static initialized = 0;

typedef enum {
	NCR_COMMAND_NULL,
	NCR_COMMAND_WRITE,
	NCR_COMMAND_WRITE64,
	NCR_COMMAND_READ,
	NCR_COMMAND_MODIFY,
	NCR_COMMAND_USLEEP,
	NCR_COMMAND_POLL,
} ncr_command_code_t;

typedef struct {
	ncr_command_code_t command;
	unsigned region;
	unsigned offset;
	unsigned value;
	unsigned mask;
} ncr_command_t;

static int
ncp_dev_configure(ncr_command_t *commands);


/*
  ------------------------------------------------------------------------------
  ncp_dev_reset
*/

static int
ncp_dev_reset(void)
{
	return 0;
}

/*
  ------------------------------------------------------------------------------
  ncp_dev_do_read
*/

static int
ncp_dev_do_read(ncr_command_t *command, unsigned *value)
{
	if (NCP_REGION_ID(0x200, 1) == command->region) {
		*value = *(volatile unsigned*)(unsigned long)command->offset;
	} else if (0 != ncr_read32(command->region, command->offset, value)) {
		debug("READ ERROR: n=0x%x t=0x%x o=0x%x\n",
			    NCP_NODE_ID(command->region),
			    NCP_TARGET_ID(command->region), command->offset);
		return -1;
	}

#ifdef NCR_DEBUG
	debug("Read 0x%08x from n=0x%x t=0x%x o=0x%x\n",
		    *value, NCP_NODE_ID(command->region),
		    NCP_TARGET_ID(command->region),
		    command->offset);
#endif
	return 0;
}

/*
  ------------------------------------------------------------------------------
  ncp_dev_do_write
*/

static int
ncp_dev_do_write(ncr_command_t *command)
{
	switch (command->region) {
	case NCP_REGION_ID(0x200, 1):
	{
		unsigned int read_back = *(volatile unsigned*)(unsigned long)command->offset;

 		*(volatile unsigned*)(unsigned long)(command->offset) = (unsigned) command->value;
		if (read_back != command->value) {
			printf("WRITE ERROR: n=0x%x t=0x%x o=0x%x "
				"v=0x%x\n",
				NCP_NODE_ID(command->region),
				NCP_TARGET_ID(command->region),
				command->offset, command->value);
			return -1;
		}
		break;
	}
	default:
		if (0 != ncr_write32(command->region, command->offset,
					 command->value)) {
			printf("WRITE ERROR: n=0x%x t=0x%x o=0x%x "
					"v=0x%x\n",
					NCP_NODE_ID(command->region),
					NCP_TARGET_ID(command->region),
					command->offset, command->value);

			return -1;
		}
#if 1
		if (NCP_NODE_ID(command->region) == 0x168) {
			unsigned int read_back = ncr_write32(command->region, command->offset,
						 command->value);
			if (read_back != command->value) {
				printf("read_back != write: n=0x%x t=0x%x o=0x%x "
					"v=0x%x\n",
					NCP_NODE_ID(command->region),
					NCP_TARGET_ID(command->region),
					command->offset, command->value);
				return -1;                                  
			}
		}
#endif
		break;
	}
	
	return 0;
}

/*
  ------------------------------------------------------------------------------
  ncp_dev_do_write_64
	
  This is only for the memory writes. Most likely not necessary as the current 
  traces do not use the values over 1 word (32 bits) but maybe they will in future
  so keeping.
*/

static int
ncp_dev_do_write_64(ncr_command_t *command)
{
	if (NCP_REGION_ID(0x200, 1) == command->region) {
		printf("val 0x%lx @ addr 0x%lx\n", 
				(unsigned long)command->value,  (unsigned long)command->offset);

 		*(volatile unsigned long*)(unsigned long)(command->offset) = (unsigned long) command->value;
		
		unsigned long read_back = *(volatile unsigned long*)(unsigned long)command->offset;
		if (read_back != command->value) {
			printf("WRITE ERROR: n=0x%x t=0x%x o=0x%x "
				"v=0x%x\n",
				NCP_NODE_ID(command->region),
				NCP_TARGET_ID(command->region),
				command->offset, command->value);
			return -1;
		}
		
		return 0;
	}

	return -1;
}

/*
  ------------------------------------------------------------------------------
  ncp_dev_do_modify
*/

static int
ncp_dev_do_modify(ncr_command_t *command)
{
    if (NCP_REGION_ID(0x200, 1) == command->region) {
        ncp_dev_do_read(command, &command->value);

        command->value &= ~command->mask;
        command->value |= command->value;

        ncp_dev_do_write(command);

		return 0;
	} 

	if (0 != ncr_modify32(command->region, command->offset,
			      command->mask, command->value)) {
		debug("MODIFY ERROR: n=0x%x t=0x%x o=0x%x m=0x%x "
			    "v=0x%x\n",
			    NCP_NODE_ID(command->region),
			    NCP_TARGET_ID(command->region), command->offset,
			    command->mask, command->value);

		return -1;
	} 

#ifdef NCR_DEBUG
		debug("MODIFY: r=0x%x o=0x%x m=0x%x v=0x%x\n",
			    command->region, command->offset,
			    command->mask, command->value);
#endif

    return 0;
}

/*
  ------------------------------------------------------------------------------
  ncp_dev_do_poll
*/

static int
ncp_dev_do_poll(ncr_command_t *command)
{
	int timeout = 1000;
	int delay = 1000;
	unsigned value;

	do {
		udelay(delay);

		if (0 != ncp_dev_do_read(command, &value)) {
			printf("ncp_dev_do_read() failed!\n");
			return -1;
		}
	} while (((value & command->mask) != command->value) &&
		 0 < --timeout);

	if (0 == timeout) {
		printf("ncp_dev_do_poll() timed out!\n");
		return -1;
	}

	return 0;
}

/*
  ------------------------------------------------------------------------------
  ncp_dev_configure
*/

static int
ncp_dev_configure(ncr_command_t *commands) {
	int rc = 0;
	unsigned value;
    ncr_command_t *startCmd = commands;

	while (NCR_COMMAND_NULL != commands->command) {
		switch (commands->command) {
		case NCR_COMMAND_WRITE:
			rc = ncp_dev_do_write(commands);
			break;
		case NCR_COMMAND_WRITE64:
			rc = ncp_dev_do_write_64(commands);
			break;
		case NCR_COMMAND_READ:
			rc = ncp_dev_do_read(commands, &value);
			break;
		case NCR_COMMAND_MODIFY:
			rc = ncp_dev_do_modify(commands);
			break;
		case NCR_COMMAND_USLEEP:
#ifdef NCR_DEBUG
			debug("USLEEP: v=0x%x\n", commands->value);
#endif
			udelay(commands->value);
			break;
		case NCR_COMMAND_POLL:
			rc = ncp_dev_do_poll(commands);
			break;
		default:
			printf("Unknown Command: 0x%x, startCmd=%p, curCmd=%p\n",
			       (unsigned int)commands->command,
			       startCmd,
			       commands);
			rc = -1;
			break;
		}

		if (ctrlc()) {
			printf("Canceling configuration.\n");
			break;
		}

		++commands;
	}

	return rc;
}

#if defined(CONFIG_AXXIA_XLF)
#include "EIOA67xx/mme.c"
#include "EIOA67xx/pbm.c"
#include "EIOA67xx/vp.c"
#include "EIOA67xx/nca.c"
#include "EIOA67xx/eioa.c"
#else
#error "EIOA is not defined for this architecture!"
#endif

/*
  ------------------------------------------------------------------------------
  take_snapshot: this allows seeing the rx/tx counters at the interfaces
*/
int __weak
take_snapshot(int gmac) 
{
	int rc, val, number = 56;
	int offset_rx = 0xf00, offset_tx = 0xe00;
	/*unsigned eioaRegion;*/
	unsigned gmacRegion;
	unsigned gmacPortOffset;
	unsigned hwPortgmac;

	/* Set the region and offset. Just native dmain:
  		EIOA0: gmac0-5
  		EIOA1: gmac16-20. gmac20 is Nokia!!!*/
    if (5 > gmac) {
        hwPortgmac = ((gmac == 0) ? 0 : (gmac - 1));
		/*eioaRegion = NCP_REGION_ID(31, 16);*/ /* 0x1f.0x10 */
		gmacRegion = ((gmac == 0) ? NCP_REGION_ID(31, 17) : /* 0x1f.0x11 */ 
                                     NCP_REGION_ID(31, 18)); /* 0x1f.0x12 */
		gmacPortOffset = 0xd0c * (hwPortgmac+1);
	} else if (16 > gmac && 20 < gmac) {
	    hwPortgmac = ((gmac == 16) ? 0 : (gmac - 17));
		/*eioaRegion = NCP_REGION_ID(23, 16);*/ /* 0x17.0x10 */
        gmacRegion = ((gmac == 16) ? NCP_REGION_ID(23, 17) : /* 0x17.0x11 */ 
                                     NCP_REGION_ID(23, 18)); /* 0x17.0x12 */
		gmacPortOffset = 0xd0c * (hwPortgmac+1);
	} else {
		debug("Snapshot for gmac%d not supported\n", gmac);
		return -1;
	}
	

	/* eg. gmac00_config @0x17.0x11.0xd0c */
	debug("gmac0x_config @gmacRegion 0x%x, gmacPortOffset 0x%x, v 0x45ee\n", gmacRegion, gmacPortOffset);
	ncr_write32(gmacRegion, gmacPortOffset, 0x45ee);
	/* snapshot @gmacRegion.0xd40 */
	debug("snapshot @gmacRegion 0x%x, gmacPortOffset 0x%x, v 0x%x\n", gmacRegion, 0xd40, hwPortgmac);
	ncr_write32(gmacRegion, 0xd40, hwPortgmac);	

	debug("Snapshot for gmac%d\n", gmac);
	while (0 < number--) {
		rc = ncr_read(gmacRegion, 0, offset_tx, 4, &val);
		if (0 != val) 
			debug("value 0x%x\n", val);

		if (0 != rc)
			return -1;

		offset_tx += 4;
	}

	number = 56;
	while (0 < number--) {
		rc = ncr_read(gmacRegion, 0, offset_rx, 4, &val);
		if (0 != val) 
			debug("value 0x%x\n", val);

		if (0 != rc)
			return -1;

		offset_rx += 4;
	}
	return 0;
}

/*
  -------------------------------------------------------------------------------
  ncp_task_uboot_domain_bundle_clear
*/

void static
ncp_task_uboot_domain_bundle_clear(void)
{
	return;
}

/*
  -------------------------------------------------------------------------------
  initialize_task_io
*/

#if 0
int
initialize_task_io(struct eth_device *dev)
#else 
int
initialize_task_io(void)
#endif
{
    debug("Resetting device...");
	if (0 != ncp_dev_reset()) {
		printf("Device reset Failed\n");
		return -1;
	}
    debug("done\n");

    debug("Clearing NCA domain bundle...");
    ncp_task_uboot_domain_bundle_clear();
    debug("done\n");

	debug("Configuring MME...");
    if (0 != ncp_dev_configure(mme)) {
            printf("MME Configuration Failed\n");
            return -1;
    }
	debug("done\n");

	debug("Configuring PBM...");
	if (0 != ncp_dev_configure(pbm)) {
				printf("PBM Configuration Failed\n");
				return -1;
		}
	debug("done\n");

	debug("Configuring VP...");
		if (0 != ncp_dev_configure(vp)) {
				printf("Virtual Pipeline Configuration Failed\n");
				return -1;
		}
	debug("done\n");

	debug("Configuring NCA...");
		if (0 != ncp_dev_configure(nca)) {
				printf("NCA Configuration Failed\n");
				return -1;
		}
	debug("done\n");

	debug("Configuring EIOA...");
		if (0 != ncp_dev_configure(eioa)) {
				printf("EIOA Configuration Failed\n");
				return -1;
		}
	debug("done\n");

	ncp_hdl_t ncpHdl = NULL;
	ncp_uint32_t tqsId = 0;
	ncp_task_tqs_usage_t params;
	ncp_task_resource_name_t processName;
	strncpy(processName.name, "TaskRecvLoop", sizeof("TaskRecvLoop"));
	ncp_task_tqs_hdl_t tqsHdl = NULL;
	ncp_task_tqs_bind(ncpHdl,tqsId,&params,&processName,&processName,tqsHdl);
	ncp_st_t                 ncpStatus = NCP_ST_ERROR;
	ncp_uint32_t             numRx;
	ncp_task_header_t        *task;
	ncpStatus = ncp_task_recv(tqsHdl, 1, &numRx, &task, FALSE);

	ncp_task_send_meta_t    meta_data;
	ncp_uint32_t numSent;
	/* in addition to copying into the sub-buffer, send a CM  Tx task.*/
	memset(&meta_data, 0x0, sizeof(ncp_task_send_meta_t));

	/* Fill meta data fields */
	meta_data.sendDoneFn = NULL;
	meta_data.sendDoneArg = NULL;
	meta_data.freeHeader = TRUE;
	meta_data.freeDataPointers = FALSE;
	meta_data.issueCompletion = FALSE;
	meta_data.taskHeader = task;

	ncp_task_send (tqsHdl, 0, 1, &numSent, &meta_data, TRUE);
	ncp_task_tqs_unbind(ncpHdl);

	return 0;
}

/*
  -------------------------------------------------------------------------------
  initialize_task_io
*/

static int
finalize_task_io(void)
{
	return 0;
}
 
/*
  ==============================================================================
  ==============================================================================
  Public Interface
  ==============================================================================
  ==============================================================================
*/


/*
  -------------------------------------------------------------------------------
  lsi_eioae_eth_halt
*/

void
lsi_eioa_eth_halt(struct eth_device *dev)
{
	if (0 != initialized)
		finalize_task_io();

	return;
}

/*
  ----------------------------------------------------------------------
  lsi_eioa_eth_init
*/

int
lsi_eioa_eth_init(struct eth_device *dev, bd_t *bd)
{
	if (0 == initialized)
		if (0 != initialize_task_io()) {
			printf("Failed to Initialize TaskIO Lite!\n");
			return -1;
		}

	initialized = 1;
	return 0;
}

/*
  -------------------------------------------------------------------------------
  lsi_eioa_eth_send
*/

int __weak
lsi_eioa_eth_send(struct eth_device *dev, void *packet, int length)
{
	return 0;
}

/*
  -------------------------------------------------------------------------------
  lsi_eioa_eth_rx
*/

int __weak
lsi_eioa_eth_rx(struct eth_device *dev)
{
	return 0;
}

/*
  -------------------------------------------------------------------------------
  lsi_eioa_receive_test
*/

void __weak
lsi_eioa_receive_test(struct eth_device *dev)
{
	return;
}

/*
  -------------------------------------------------------------------------------
  lsi_eioa_loopback_test
*/

void __weak
lsi_eioa_loopback_test(struct eth_device *dev)
{
	return;
}
