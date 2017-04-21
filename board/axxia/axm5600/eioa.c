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

/*
  Notes:

  - Virtual registers (0.769.0.OFFSET) are described in
    rte/api/nca/include/ncp_dev_config_regs.h.
*/

/*#define DEBUG*/
/*#define NCR_DEBUG*/
/*#define LSI_LOGIO*/
#include <config.h>
#include <common.h>
#include <malloc.h>
#include <asm/io.h>
#include <net.h>
#include <miiphy.h>

/*#define TRACE_ALLOCATION*/

#define NCP_TASKIO_LITE
#define NCP_TASKIO_UBOOT_ENV
#define NCP_TASKIO_LITE_UBOOT_ENV_DEFINE_GLOBALS

#define NCP_USE_ALL_PORTS 0xff

#include "ncp_task_basetypes.h"
#include "ncp_task.h"
#include "ncp_nca_regs.h"
#include "ncp_nodes.h"
#include "../common/ncp_nca_reg_defines.h"

DECLARE_GLOBAL_DATA_PTR;

/*==============================================================================
  ==============================================================================
  Private Interface
  ==============================================================================
  ==============================================================================
*/

static int initialized = 0;
/* dummy NCP handle. Needed for task APIs. */
ncp_t gNCP = { 0 };
static ncp_task_hdl_t taskHdl = NULL;

/* these needs to match with generated C code from ASE */
static ncp_uint8_t threadQueueSetId = 0;
static ncp_uint8_t ncaQueueId = 0;
static ncp_uint8_t recvQueueId = 0;
static ncp_uint8_t sendVpId = 0;

static int eioaPort = NCP_USE_ALL_PORTS;
static int loopback = 0;
static int rxtest = 0;

extern int dumprx;
extern int dumptx;

#define NCP_EIOA_GEN_CFG_REG_OFFSET(portIndex)                                  \
    0x100000 +                                                                  \
    ((portIndex > 0) ? 0x10000 : 0) +                                           \
    ((portIndex > 0) ? (0x1000 * (portIndex - 1)) : 0)


/* 
 * With this release we support only native damain and 
 * only gmacs.
 */
static int port_by_index[] = 
    {  0,   1,  2,  3,  4,  /* eioa0 */
      16,  17, 18, 		    /* eioa1 */
      /*32,  33,*/             /* eioa2 */
      /*48,  49,*/             /* eioa3 */
      /*64,  65,*/             /* eioa4 */
      /*80,  81,*/             /* eioa5 */
      /*96,  97,*/             /* eioa6 */
      /*112, 113*/ };          /* eioa7 */

static int index_by_port[] = 
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   /* eioa0 */
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   /* eioa1 */
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   /* eioa2 */
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   /* eioa3 */
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   /* eioa4 */
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   /* eioa5 */
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   /* eioa6 */
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; /* eioa7 */

static int index_by_port_gmac[] = 
    {  0,  1,  2,  3,  4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   /* eioa0 */
       16, 17, 18, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  /* eioa1 */
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   /* eioa2 */
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   /* eioa3 */
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   /* eioa4 */
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   /* eioa5 */
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   /* eioa6 */
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; /* eioa7 */

static int index_by_port_xgmac[] = 
    {  0,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   /* eioa0 */
       5,  6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   /* eioa1 */
      10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   /* eioa2 */
      12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   /* eioa3 */
      14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   /* eioa4 */
      16, 17, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   /* eioa5 */
      18, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   /* eioa6 */
      20, 21, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; /* eioa7 */

#define EIOA_NUM_PORT_INDEXES (sizeof(index_by_port)/sizeof(int))

typedef enum 
{
    EIOA_PORT_TYPE_XGMAC,
    EIOA_PORT_TYPE_GMAC
} eioa_port_type;
/* 
 * port type: 1 - gmac, 0 - xgmac
 * By default all are set to gmac.
 */
static int port_type_by_index[] = 
{ 
    EIOA_PORT_TYPE_GMAC, EIOA_PORT_TYPE_GMAC, EIOA_PORT_TYPE_GMAC, 
    EIOA_PORT_TYPE_GMAC, EIOA_PORT_TYPE_GMAC, EIOA_PORT_TYPE_GMAC,
    EIOA_PORT_TYPE_GMAC, EIOA_PORT_TYPE_GMAC, EIOA_PORT_TYPE_GMAC, 
    EIOA_PORT_TYPE_GMAC, EIOA_PORT_TYPE_GMAC, EIOA_PORT_TYPE_GMAC,
    EIOA_PORT_TYPE_GMAC, EIOA_PORT_TYPE_GMAC, EIOA_PORT_TYPE_GMAC, 
    EIOA_PORT_TYPE_GMAC, EIOA_PORT_TYPE_GMAC, EIOA_PORT_TYPE_GMAC,
    EIOA_PORT_TYPE_GMAC, EIOA_PORT_TYPE_GMAC, EIOA_PORT_TYPE_GMAC, 
    EIOA_PORT_TYPE_GMAC 
};


/* TODO: fix the phy addresses upon ASE
   - fixed 0x12 (gmac0) through 0x1a (gmac18) */
int phy_by_index[] = 
{ 
    0x12, 0x13, 0x18, 0x19, 0x1b,
	0x16, 0x17, 0x1a, 0x11, 0x10, 0x20, 0x21, 
    0x30, 0x31, 0x40, 0x41, 0x50, 0x51, 0x60, 0x61, 0x70, 0x71 
};

typedef enum
{
    EIOA_PHY_MEDIA_FIBER,
    EIOA_PHY_MEDIA_COPPER
} eioa_phy_media;

/* 
 * phy type: 1 - copper, 0 - fiber 
 * By default all are set to copper.
 */
static int phy_media_by_index[] = 
{ 
    EIOA_PHY_MEDIA_COPPER, EIOA_PHY_MEDIA_COPPER, EIOA_PHY_MEDIA_COPPER, 
    EIOA_PHY_MEDIA_COPPER, EIOA_PHY_MEDIA_COPPER, EIOA_PHY_MEDIA_COPPER,
    EIOA_PHY_MEDIA_COPPER, EIOA_PHY_MEDIA_COPPER, EIOA_PHY_MEDIA_COPPER, 
    EIOA_PHY_MEDIA_COPPER, EIOA_PHY_MEDIA_COPPER, EIOA_PHY_MEDIA_COPPER,
    EIOA_PHY_MEDIA_COPPER, EIOA_PHY_MEDIA_COPPER, EIOA_PHY_MEDIA_COPPER, 
    EIOA_PHY_MEDIA_COPPER, EIOA_PHY_MEDIA_COPPER, EIOA_PHY_MEDIA_COPPER,
    EIOA_PHY_MEDIA_COPPER, EIOA_PHY_MEDIA_COPPER, EIOA_PHY_MEDIA_COPPER, 
    EIOA_PHY_MEDIA_COPPER, 
};

#define EIOA_NUM_PORTS (sizeof(port_by_index)/sizeof(int))

#undef TRACE
#define TRACE
#ifdef TRACE
#define NCR_CALL(x) { \
if (0 != (rc = (x))) { \
printf("%s:%s:%d - FAILED\n", __FILE__, __FUNCTION__, __LINE__); \
goto ncp_return; \
} \
}
#else
#define NCR_CALL(x) { \
if (0 != (rc = (x))) { \
goto ncp_return; \
} \
}
#endif

typedef struct {
	unsigned region;
	unsigned offset;
} ncr_location_t;

typedef enum {
	NCR_COMMAND_NULL,
	NCR_COMMAND_WRITE,
	NCR_COMMAND_WRITE64,
	NCR_COMMAND_READ,
	NCR_COMMAND_MODIFY,
	NCR_COMMAND_USLEEP,
	NCR_COMMAND_POLL,
} ncr_command_code_t;

typedef int (*func_config_port)(int index);

typedef struct {
	ncr_command_code_t command;
	unsigned region;
	unsigned offset;
	unsigned value;
	unsigned mask;
} ncr_command_t;

static int
ncp_dev_configure(ncr_command_t *commands);

void
axxia_dump_packet(const char *header, void *packet, int length);

void
ncp_task_uboot_domain_bundle_clear(void);

ncp_st_t
ncp_task_uboot_config(void);

void
ncp_task_uboot_unconfig(void);

#if defined(CONFIG_AXXIA_56XX)
#include "EIOA56xx/mme.c"
#include "EIOA56xx/pbm.c"
#include "EIOA56xx/vp.c"
#include "EIOA56xx/nca.c"
#include "EIOA56xx/eioa.c"
#else
#error "EIOA is not defined for this architecture!"
#endif

ncp_uint32_t
ncp_caal_regions_acp56xx[] =
{
    NCP_REGION_ID(0x0b, 0x05),      /* SPPV2   */
    NCP_REGION_ID(0x0c, 0x05),      /* SED     */
    NCP_REGION_ID(0x0e, 0x05),      /* DPI_HFA */
    NCP_REGION_ID(0x14, 0x05),      /* MTM     */
    NCP_REGION_ID(0x14, 0x0a),      /* MTM2    */
    NCP_REGION_ID(0x15, 0x00),      /* MME     */
    NCP_REGION_ID(0x16, 0x05),      /* NCAV2   */
    NCP_REGION_ID(0x16, 0x10),      /* NCAV22  */
    NCP_REGION_ID(0x17, 0x05),      /* EIOAM1  */
    NCP_REGION_ID(0x19, 0x05),      /* TMGR    */
    NCP_REGION_ID(0x1a, 0x05),      /* MPPY    */
    NCP_REGION_ID(0x1a, 0x23),      /* MPPY2   */
    NCP_REGION_ID(0x1a, 0x21),      /* MPPY3   */
    NCP_REGION_ID(0x1b, 0x05),      /* PIC     */
    NCP_REGION_ID(0x1c, 0x05),      /* PAB     */
    NCP_REGION_ID(0x1f, 0x05),      /* EIOAM0  */
    NCP_REGION_ID(0x31, 0x05),      /* ISB     */
    NCP_REGION_ID(0xff, 0xff) 
};

ncp_uint32_t
ncp_cnal_regions_acp56xx[] =
{
    NCP_REGION_ID(0x28, 0x05),      /* EIOASM0 */
    NCP_REGION_ID(0x29, 0x05),      /* EIOASM1 */
    NCP_REGION_ID(0x2a, 0x05),      /* EIOAS2  */
    NCP_REGION_ID(0x2b, 0x05),      /* EIOAS3  */
    NCP_REGION_ID(0x2c, 0x05),      /* EIOAS4  */
    NCP_REGION_ID(0x2d, 0x05),      /* EIOAS5  */
    NCP_REGION_ID(0x32, 0x05),      /* ISBS    */
    NCP_REGION_ID(0xff, 0xff) 
};

/*
  ------------------------------------------------------------------------------
  ncp_dev_reset
*/

static ncp_st_t
ncp_dev_quiesce(void)
{
    ncp_st_t         ncpStatus = NCP_ST_SUCCESS;
    ncp_uint32_t    *pCnalRegions = ncp_cnal_regions_acp56xx;
    ncp_uint32_t    *pCaalRegions = ncp_caal_regions_acp56xx;
    ncp_uint32_t    *pRegion;
    ncp_uint32_t     ort, owt;
    ncp_uint32_t     buf = 0;
    ncp_uint32_t     loop;

    pRegion = pCnalRegions;
    while (*pRegion != NCP_REGION_ID(0xff, 0xff) )
    {

        /* set read/write transaction limits to zero */
        NCP_CALL(ncr_write32(*pRegion, 0x8, buf));
        NCP_CALL(ncr_write32(*pRegion, 0xc, buf));
        pRegion++;
    }

    pRegion = pCaalRegions;
    while (*pRegion != NCP_REGION_ID(0xff, 0xff) )
    {

        /* set read/write transaction limits to zero */
        NCP_CALL(ncr_write32(*pRegion, 0x8, buf));
        NCP_CALL(ncr_write32(*pRegion, 0xc, buf));
        pRegion++;
    }


    pRegion = pCaalRegions;
    loop = 0;
    while (*pRegion != NCP_REGION_ID(0xff, 0xff) )
    {
        /* read the number of outstanding read/write transactions */
        NCP_CALL(ncr_read32(*pRegion, 0xf8, &ort));
        NCP_CALL(ncr_read32(*pRegion, 0xfc, &owt));

        if ( (ort == 0) && (owt == 0) )
        {
            /* this engine has been quiesced, move on to the next */
            loop = 0;
            pRegion++;
        }
        else 
        {
            if (loop++ > 10000) {
                NCP_MSG(NCP_MSG_ERROR, "unable to quiesce region 0x%02x.0x%02x! \n",
                        NCP_NODE_ID(*pRegion), NCP_TARGET_ID(*pRegion));
                loop = 0;
                continue;
            }
        }
    }

    pRegion = pCnalRegions;
    loop = 0;
    while (*pRegion != NCP_REGION_ID(0xff, 0xff) )
    {
        /* read the number of outstanding read/write transactions */
        NCP_CALL(ncr_read32(*pRegion, 0x1c0, &ort));
        NCP_CALL(ncr_read32(*pRegion, 0x1c4, &owt));

        if ( (ort == 0) && (owt == 0) )
        {
            /* this engine has been quiesced, move on to the next */
            loop = 0;
            pRegion++;
        }
        else 
        {
            if (loop++ > 10000) {
                NCP_MSG(NCP_MSG_ERROR, "unable to quiesce region 0x%02x.0x%02x! \n",
                        NCP_NODE_ID(*pRegion), NCP_TARGET_ID(*pRegion));
                loop = 0;
                continue;
            }
        }
    }


NCP_RETURN_LABEL
    return ncpStatus;
}

typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      rcaltest_rst                              :  1;
     unsigned      sm0_sm1_pll_rst                           :  1;
     unsigned      smc1_rst                                  :  1;
     unsigned      smc0_rst                                  :  1;
     unsigned      ioctl_rst                                 :  1;
     unsigned      gic500_rst                                :  1;
     unsigned      reserved0                                 :  1;
     unsigned      pbm_rst                                   :  1;
     unsigned      nic_rst                                   :  1;
     unsigned      pkt_buffer_rst                            :  1;
     unsigned      ccms_rst                                  :  1;
     unsigned      isbs_rst                                  :  1;
     unsigned      eioasm5_rst                               :  1;
     unsigned      eioasm4_rst                               :  1;
     unsigned      eioasm3_rst                               :  1;
     unsigned      eioasm2_rst                               :  1;
     unsigned      eioasm1_rst                               :  1;
     unsigned      eioasm0_rst                               :  1;
     unsigned      eioam1_rst                                :  1;
     unsigned      eioam0_rst                                :  1;
     unsigned      ccm_rst                                   :  1;
     unsigned      pcx_rst                                   :  1;
     unsigned      isb_rst                                   :  1;
     unsigned      ring_bp_rst                               :  1;
     unsigned      scnt_dist_rst                             :  1;
     unsigned      tmgr_rst                                  :  1;
     unsigned      mtm_rst                                   :  1;
     unsigned      sed_rst                                   :  1;
     unsigned      pab_rst                                   :  1;
     unsigned      pic_rst                                   :  1;
     unsigned      dpi_rst                                   :  1;
     unsigned      spp_rst                                   :  1;
          /* word 1 */
     unsigned      mme_rst                                   :  1;
     unsigned      nca_rst                                   :  1;
     unsigned      mppy_rst                                  :  1;
     unsigned      elm1_rst                                  :  1;
     unsigned      elm0_rst                                  :  1;
     unsigned      cmem1_rst                                 :  1;
     unsigned      cmem0_rst                                 :  1;
     unsigned      smem1_phy_io_rst                          :  1;
     unsigned      smem0_phy_io_rst                          :  1;
     unsigned      cmem1_phy_io_rst                          :  1;
     unsigned      cmem0_phy_io_rst                          :  1;
     unsigned      reserved1                                 :  3;
     unsigned      treemem_rst                               :  1;
     unsigned      eioa_phy9_rst                             :  1;
     unsigned      eioa_phy8_rst                             :  1;
     unsigned      eioa_phy7_rst                             :  1;
     unsigned      eioa_phy6_rst                             :  1;
     unsigned      eioa_phy5_rst                             :  1;
     unsigned      eioa_phy4_rst                             :  1;
     unsigned      eioa_phy3_rst                             :  1;
     unsigned      eioa_phy2_rst                             :  1;
     unsigned      eioa_phy1_rst                             :  1;
     unsigned      eioa_phy0_rst                             :  1;
     unsigned      pci_srio_phy_rst                          :  1;
     unsigned      reserved2                                 :  6;
#else    /* Little Endian */
          /* word 0 */
     unsigned      spp_rst                                   :  1;
     unsigned      dpi_rst                                   :  1;
     unsigned      pic_rst                                   :  1;
     unsigned      pab_rst                                   :  1;
     unsigned      sed_rst                                   :  1;
     unsigned      mtm_rst                                   :  1;
     unsigned      tmgr_rst                                  :  1;
     unsigned      scnt_dist_rst                             :  1;
     unsigned      ring_bp_rst                               :  1;
     unsigned      isb_rst                                   :  1;
     unsigned      pcx_rst                                   :  1;
     unsigned      ccm_rst                                   :  1;
     unsigned      eioam0_rst                                :  1;
     unsigned      eioam1_rst                                :  1;
     unsigned      eioasm0_rst                               :  1;
     unsigned      eioasm1_rst                               :  1;
     unsigned      eioasm2_rst                               :  1;
     unsigned      eioasm3_rst                               :  1;
     unsigned      eioasm4_rst                               :  1;
     unsigned      eioasm5_rst                               :  1;
     unsigned      isbs_rst                                  :  1;
     unsigned      ccms_rst                                  :  1;
     unsigned      pkt_buffer_rst                            :  1;
     unsigned      nic_rst                                   :  1;
     unsigned      pbm_rst                                   :  1;
     unsigned      reserved0                                 :  1;
     unsigned      gic500_rst                                :  1;
     unsigned      ioctl_rst                                 :  1;
     unsigned      smc0_rst                                  :  1;
     unsigned      smc1_rst                                  :  1;
     unsigned      sm0_sm1_pll_rst                           :  1;
     unsigned      rcaltest_rst                              :  1;
          /* word 1 */
     unsigned      reserved2                                 :  6;
     unsigned      pci_srio_phy_rst                          :  1;
     unsigned      eioa_phy0_rst                             :  1;
     unsigned      eioa_phy1_rst                             :  1;
     unsigned      eioa_phy2_rst                             :  1;
     unsigned      eioa_phy3_rst                             :  1;
     unsigned      eioa_phy4_rst                             :  1;
     unsigned      eioa_phy5_rst                             :  1;
     unsigned      eioa_phy6_rst                             :  1;
     unsigned      eioa_phy7_rst                             :  1;
     unsigned      eioa_phy8_rst                             :  1;
     unsigned      eioa_phy9_rst                             :  1;
     unsigned      treemem_rst                               :  1;
     unsigned      reserved1                                 :  3;
     unsigned      cmem0_phy_io_rst                          :  1;
     unsigned      cmem1_phy_io_rst                          :  1;
     unsigned      smem0_phy_io_rst                          :  1;
     unsigned      smem1_phy_io_rst                          :  1;
     unsigned      cmem0_rst                                 :  1;
     unsigned      cmem1_rst                                 :  1;
     unsigned      elm0_rst                                  :  1;
     unsigned      elm1_rst                                  :  1;
     unsigned      mppy_rst                                  :  1;
     unsigned      nca_rst                                   :  1;
     unsigned      mme_rst                                   :  1;
#endif
} __attribute__ ( ( packed ) ) ncp_syscon_reset_mod_r_t;

typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      cpm_rst                                   :  1;
     unsigned      reserved0                                 : 13;
     unsigned      sata1_rst                                 :  1;
     unsigned      sata0_rst                                 :  1;
     unsigned      reserved1                                 :  4;
     unsigned      nrcp_rst                                  :  1;
     unsigned      reserved2                                 :  1;
     unsigned      srio_gpreg_rst                            :  1;
     unsigned      reserved3                                 :  3;
     unsigned      pei2_rst                                  :  1;
     unsigned      pei1_rst                                  :  1;
     unsigned      pei0_rst                                  :  1;
     unsigned      ipi_rst                                   :  1;
     unsigned      jtag2axi_rst                              :  1;
     unsigned      timer_rst                                 :  1;
          /* word 1 */
     unsigned      lsm_rst                                   :  1;
     unsigned      sbb_rst                                   :  1;
     unsigned      gic490_rst                                :  1;
     unsigned      gpio_rst                                  :  1;
     unsigned      usb_rst                                   :  1;
     unsigned      axi2ser7_rst                              :  1;
     unsigned      axi2ser6_rst                              :  1;
     unsigned      axi2ser5_rst                              :  1;
     unsigned      axi2ser4_rst                              :  1;
     unsigned      axi2ser3_rst                              :  1;
     unsigned      axi2ser2_rst                              :  1;
     unsigned      axi2ser1_rst                              :  1;
     unsigned      axi2ser0_rst                              :  1;
     unsigned      mtc_rst                                   :  1;
     unsigned      usb_phy_rst                               :  1;
     unsigned      gpdma_1_rst                               :  1;
     unsigned      gpdma_0_rst                               :  1;
     unsigned      trng_rst                                  :  1;
     unsigned      pka__rst                                  :  1;
     unsigned      mdio_rst                                  :  1;
     unsigned      ssp_rst                                   :  1;
     unsigned      uart_3_rst                                :  1;
     unsigned      uart_2_rst                                :  1;
     unsigned      uart_1_rst                                :  1;
     unsigned      uart_0_rst                                :  1;
     unsigned      smb_rst                                   :  1;
     unsigned      i2c_2_rst                                 :  1;
     unsigned      i2c_1_rst                                 :  1;
     unsigned      i2c_0_rst                                 :  1;
     unsigned      emmc_rst                                  :  1;
     unsigned      gemac_rst                                 :  1;
     unsigned      axis_rst                                  :  1;
#else    /* Little Endian */
          /* word 0 */
     unsigned      timer_rst                                 :  1;
     unsigned      jtag2axi_rst                              :  1;
     unsigned      ipi_rst                                   :  1;
     unsigned      pei0_rst                                  :  1;
     unsigned      pei1_rst                                  :  1;
     unsigned      pei2_rst                                  :  1;
     unsigned      reserved3                                 :  3;
     unsigned      srio_gpreg_rst                            :  1;
     unsigned      reserved2                                 :  1;
     unsigned      nrcp_rst                                  :  1;
     unsigned      reserved1                                 :  4;
     unsigned      sata0_rst                                 :  1;
     unsigned      sata1_rst                                 :  1;
     unsigned      reserved0                                 : 13;
     unsigned      cpm_rst                                   :  1;
          /* word 1 */
     unsigned      axis_rst                                  :  1;
     unsigned      gemac_rst                                 :  1;
     unsigned      emmc_rst                                  :  1;
     unsigned      i2c_0_rst                                 :  1;
     unsigned      i2c_1_rst                                 :  1;
     unsigned      i2c_2_rst                                 :  1;
     unsigned      smb_rst                                   :  1;
     unsigned      uart_0_rst                                :  1;
     unsigned      uart_1_rst                                :  1;
     unsigned      uart_2_rst                                :  1;
     unsigned      uart_3_rst                                :  1;
     unsigned      ssp_rst                                   :  1;
     unsigned      mdio_rst                                  :  1;
     unsigned      pka__rst                                  :  1;
     unsigned      trng_rst                                  :  1;
     unsigned      gpdma_0_rst                               :  1;
     unsigned      gpdma_1_rst                               :  1;
     unsigned      usb_phy_rst                               :  1;
     unsigned      mtc_rst                                   :  1;
     unsigned      axi2ser0_rst                              :  1;
     unsigned      axi2ser1_rst                              :  1;
     unsigned      axi2ser2_rst                              :  1;
     unsigned      axi2ser3_rst                              :  1;
     unsigned      axi2ser4_rst                              :  1;
     unsigned      axi2ser5_rst                              :  1;
     unsigned      axi2ser6_rst                              :  1;
     unsigned      axi2ser7_rst                              :  1;
     unsigned      usb_rst                                   :  1;
     unsigned      gpio_rst                                  :  1;
     unsigned      gic490_rst                                :  1;
     unsigned      sbb_rst                                   :  1;
     unsigned      lsm_rst                                   :  1;
#endif
} __attribute__ ( ( packed ) ) ncp_syscon_reset_axis_r_t;

#define NCP_NODE_TIMER          0x19
#define NCP_NODE_AXIS_APB2SER3  0x156

#define NCP_REGION_TIMER_TMGR_SYSTEM_COUNT  NCP_REGION_ID(NCP_NODE_TIMER, 0x0012) /* 25.18 */
#define NCP_REGION_AXIS_APB2SER3_SYSCON     NCP_REGION_ID(NCP_NODE_AXIS_APB2SER3, 0x0000) /* 342.0 */

#define NCP_TMGR_SYSTEM_COUNT_CFG_SYSTEM_COUNTER_CONTROL       (0x00000114)
#define NCP_SYSCON_KEY                                         (0x00002000)
#define NCP_SYSCON_RESET_MOD                                   (0x00002038)
#define NCP_SYSCON_RESET_AXIS                                  (0x00002040)

static ncp_st_t
ncp_dev_reset_hw(void)
{
    ncp_st_t                    ncpStatus = NCP_ST_SUCCESS;
    ncp_st_t                    st = NCP_ST_SUCCESS;
    /*ncp_uint32_t 				ubootCmemInit = 0;*/
    ncp_uint32_t                *reg = NULL;
    ncp_syscon_reset_mod_r_t    resetReg = {0};
    ncp_syscon_reset_axis_r_t   resetAxisReg = {0};

    /* Make sure the boot counter is decoupled from the Nuevo timestamp */
    NCP_CALL(ncr_write32(NCP_REGION_TIMER_TMGR_SYSTEM_COUNT,
         NCP_TMGR_SYSTEM_COUNT_CFG_SYSTEM_COUNTER_CONTROL, 0));

    /* wait for the PIO to complete */
    udelay(100000);

    /* quiesce the system */
    ncpStatus = ncp_dev_quiesce();
    if (ncpStatus != NCP_ST_SUCCESS)
    {
        NCP_MSG(NCP_MSG_ERROR, "ncp_dev_quiesce failed with %d\n", ncpStatus);
    }

    /* Enable protected writes.  Key is the only field in this register. */
    NCP_CALL(ncr_write32(NCP_REGION_AXIS_APB2SER3_SYSCON, NCP_SYSCON_KEY, 0xAB));

    resetReg.eioa_phy0_rst    = 1;
    resetReg.eioa_phy1_rst    = 1;
    resetReg.eioa_phy2_rst    = 1;
    resetReg.eioa_phy3_rst    = 1;
    resetReg.eioa_phy4_rst    = 1;
    resetReg.eioa_phy5_rst    = 1;
    resetReg.eioa_phy6_rst    = 1;
    resetReg.eioa_phy7_rst    = 1;
    resetReg.eioa_phy8_rst    = 1;
    resetReg.eioa_phy9_rst    = 1;
    resetReg.treemem_rst      = 1;
    resetReg.mppy_rst         = 1;
    resetReg.nca_rst          = 1;
    resetReg.mme_rst          = 1;

    resetReg.spp_rst          = 1;
    resetReg.dpi_rst          = 1;
    resetReg.pic_rst          = 1;
    resetReg.pab_rst          = 1;
    resetReg.sed_rst          = 1;
    resetReg.mtm_rst          = 1;
    resetReg.tmgr_rst         = 1;
    resetReg.ring_bp_rst      = 1;
    resetReg.isb_rst          = 1;
    resetReg.pcx_rst          = 1;
    resetReg.ccm_rst          = 1;
    resetReg.eioam0_rst       = 1;
    resetReg.eioam1_rst       = 1;
    resetReg.eioasm0_rst      = 1;
    resetReg.eioasm1_rst      = 1;
    resetReg.eioasm2_rst      = 1;
    resetReg.eioasm3_rst      = 1;
    resetReg.eioasm4_rst      = 1;
    resetReg.eioasm5_rst      = 1;
    resetReg.isbs_rst         = 1;
    resetReg.ccms_rst         = 1;
    resetReg.pkt_buffer_rst   = 1;
    resetReg.nic_rst          = 1;
    resetReg.pbm_rst          = 1;

 /* 
 *  Read the NTEMC0 local config node scratch register.
 *  If set then u-boot has initialized the external 
 *  CMEM and we should not reset it.
    ncr_read32(NCP_REGION_ID(NCP_NODE_NTEMC(0), 0xff), 0x20, &ubootCmemInit);
	if(0 == ubootCmemInit) {
		resetReg.cmem0_rst        = 1;
		resetReg.cmem1_rst        = 1;
		resetReg.cmem0_phy_io_rst = 1;
		resetReg.cmem1_phy_io_rst = 1;
	}
 */ 

#define NCP_DEV_ACE
#ifndef NCP_DEV_ACE
    resetReg.smem0_phy_io_rst = 1;
    resetReg.smem1_phy_io_rst = 1;
    resetReg.smc0_rst         = 1;
    resetReg.smc1_rst         = 1;
    resetReg.elm0_rst         = 1;
    resetReg.elm1_rst         = 1;
    resetReg.gic500_rst       = 1;
    resetReg.scnt_dist_rst    = 1;
#endif


    debug("writing NCP_SYSCON_RESET_MOD\n");
    reg = (ncp_uint32_t *)&resetReg;
    ncr_write32(NCP_REGION_AXIS_APB2SER3_SYSCON,
                         NCP_SYSCON_RESET_MOD, 
                         *reg);
    reg++;
    ncr_write32(NCP_REGION_AXIS_APB2SER3_SYSCON,
                         NCP_SYSCON_RESET_MOD + 4, 
                         *reg);
    debug("Done\n");
    debug("before writing NCP_SYSCON_RESET_AXIS\n");

    resetAxisReg.nrcp_rst = 1;
    debug("writing NCP_SYSCON_RESET_AXIS\n");
    reg = (ncp_uint32_t *)&resetAxisReg;
    ncr_write32(NCP_REGION_AXIS_APB2SER3_SYSCON,
                       NCP_SYSCON_RESET_AXIS,
                       *reg);
    reg++;
    ncr_write32(NCP_REGION_AXIS_APB2SER3_SYSCON,
                       NCP_SYSCON_RESET_AXIS + 4,
                       *reg);
    debug("Done\n");
    udelay(100000);
    
    debug("zeroing NCP_SYSCON_RESET_MOD\n");
    ncr_write32(NCP_REGION_AXIS_APB2SER3_SYSCON,
                         NCP_SYSCON_RESET_MOD, 
                         0);
    ncr_write32(NCP_REGION_AXIS_APB2SER3_SYSCON,
                         NCP_SYSCON_RESET_MOD + 4, 
                         0);
    debug("Done\n");

    debug("zeroing NCP_SYSCON_RESET_AXIS\n");
    ncr_write32(NCP_REGION_AXIS_APB2SER3_SYSCON,
                         NCP_SYSCON_RESET_AXIS,
                         0);
    ncr_write32(NCP_REGION_AXIS_APB2SER3_SYSCON,
                         NCP_SYSCON_RESET_AXIS + 4,
                         0);
    debug("Done\n");
    udelay(100000);

    /* Disable protected writes */
    ncr_write32(NCP_REGION_AXIS_APB2SER3_SYSCON, NCP_SYSCON_KEY, 0x0);

NCP_RETURN_LABEL
    if(st != NCP_ST_SUCCESS)
        ncpStatus = st;
    return ncpStatus;
}

ncp_st_t
ncp_dev_reset_sw(void)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_uint32_t reg = 0;
    ncp_nca_config_init_reg_t *nca_cfg_init = NULL;
    ncp_nca_cfg_ring_parity_reg_t *nca_cfg_ring_parity = NULL;

    /* Enable NCA config ring timeouts */
    ncr_read32(NCP_REGION_ID(0x101, 0), NCP_NCA_CONFIG_INIT_55XX, &reg);
    nca_cfg_init = (ncp_nca_config_init_reg_t *) &reg;
    nca_cfg_init->cfg_ring_ack_timer_en = 1;
    ncr_write32(NCP_REGION_ID(0x101, 0), NCP_NCA_CONFIG_INIT_55XX, reg);

    ncr_write32(NCP_REGION_ID(0x101, 0), NCP_NCA_CFG_RING_ACK_TIMER_CNT, 0x5f5e10);

    /* Enable config ring parity checking */
    ncr_read32(NCP_REGION_ID(0x101, 0), NCP_NCA_CFG_RING_PARITY, &reg);
    nca_cfg_ring_parity = (ncp_nca_cfg_ring_parity_reg_t *) &reg;
    nca_cfg_ring_parity->cfg_parity_err_en_ring0 = 1;
    nca_cfg_ring_parity->cfg_parity_err_en_ring1 = 1;
    nca_cfg_ring_parity->cfg_parity_err_en_ring2 = 1;
    nca_cfg_ring_parity->multibit_ecc_detect_en = 1;
    nca_cfg_ring_parity->singlebit_ecc_detect_en = 1;
    nca_cfg_ring_parity->singlebit_ecc_correct_en = 1;
    ncr_write32(NCP_REGION_ID(0x101, 0), NCP_NCA_CFG_RING_PARITY, reg);

    /* Make all masters secure */
    writel(0x2, MMAP_SCB + 0x47800);

    /* Enable Gate keeper register to allow secure access from tzc */  
    writel(0x1, TZC + 0x0008);
    /*  Enable read/write acccess */                                     
    writel(0xc0000001, TZC + 0x0110);

NCP_RETURN_LABEL
    return ncpStatus;
}

/*
  ------------------------------------------------------------------------------
  ncp_dev_reset
*/

static int
ncp_dev_reset(void)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

	/* Reset Modules */
    ncpStatus = ncp_dev_reset_hw();
    debug("ncp_dev_reset_hw\n");
    if(ncpStatus != NCP_ST_SUCCESS)
    {
        NCP_MSG(NCP_MSG_ERROR, "ncp_dev_reset_hw failed with %d\n", ncpStatus);
        return -1;
    }

    ncpStatus = ncp_dev_reset_sw();
    debug("ncp_dev_reset_sw\n");
    if(ncpStatus != NCP_ST_SUCCESS)
    {
        NCP_MSG(NCP_MSG_ERROR, "ncp_dev_reset_sw failed with %d\n", ncpStatus);
        return -1;
    }

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
	if (NCP_REGION_ID(0x200, 1) == command->region) {
 		*(volatile unsigned*)(unsigned long)(command->offset) = (unsigned) command->value;
		
		unsigned int read_back = *(volatile unsigned*)(unsigned long)command->offset;
		if (read_back != command->value) {
			printf("WRITE ERROR: n=0x%x t=0x%x o=0x%x "
				"v=0x%x\n",
				NCP_NODE_ID(command->region),
				NCP_TARGET_ID(command->region),
				command->offset, command->value);
			return -1;
		}
	} else {
		if (0 != ncr_write32(command->region, command->offset,
					 command->value)) {
			printf("WRITE ERROR: n=0x%x t=0x%x o=0x%x "
					"v=0x%x\n",
					NCP_NODE_ID(command->region),
					NCP_TARGET_ID(command->region),
					command->offset, command->value);

			return -1;
		}
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

/*
  ------------------------------------------------------------------------------
  task_send
*/

static int
task_send(ncp_task_ncaV2_send_meta_t *taskMetaData)
{
	ncp_st_t ncpStatus;

	do {
#ifdef USE_CACHE_SYNC
		flush_cache((unsigned long)taskMetaData->pduSegAddr0,
			    taskMetaData->pduSegSize0);
#endif

		if(dumptx) {
		axxia_dump_packet("LSI_EIOA TX",
			(void *)(taskMetaData->pduSegAddr0), 
				taskMetaData->pduSegSize0);
		}
        
		ncpStatus = ncp_task_ncav2_send(taskHdl, NULL, taskMetaData, TRUE,
             		NULL, NULL);
        debug("task_send(): status=%d\n", ncpStatus);
        
	} while (NCP_ST_TASK_SEND_QUEUE_FULL == ncpStatus);

	if (NCP_ST_SUCCESS != ncpStatus) {
		return 0;
   	}	

	return taskMetaData->pduSegSize0;
}

#define DELAY() udelay(5000)

/*
  ------------------------------------------------------------------------------
  take_snapshot: this allows seeing the rx/tx counters at the interfaces
*/
static int
take_snapshot(int gmac) 
{
	int rc, target = 0xdead, offset = 0xdead, val, number = 56;
	int offset_rx = 0xf00, offset_tx = 0xe00;

	switch (gmac) {
	case 0:
		target = 0x11;                 
		offset = 0xd0c; /*gmac00_config*/
		val = 0x0;                    
		break;
	case 1:
		target = 0x12;
		offset = 0xd0c;
		val = 0x0;
		break;
	case 2: 
		target = 0x12;
		offset = 0xd10;
		val = 0x1;
		break;
	case 3:
		target = 0x12;
		offset = 0xd14;
		val = 0x2;
		break;
	default:
		debug("Snapshot for gmac%d not supported\n", gmac);
		return -1;
	}

	ncr_write32(NCP_REGION_ID(0x1f, target), offset, 0x45ee);
	ncr_write32(NCP_REGION_ID(0x1f, target), 0xd40, val);
	
	debug("Snapshot for gmac%d\n", gmac);
	while (0 < number--) {
		rc = ncr_read(NCP_REGION_ID(0x1f, target), 0, offset_tx, 4, &val);
		if (0 != val) 
			debug("value 0x%x\n", val);

		if (0 != rc)
			return -1;

		offset_tx += 4;
	}

	number = 56;
	while (0 < number--) {
		rc = ncr_read(NCP_REGION_ID(0x1f, target), 0, offset_rx, 4, &val);
		if (0 != val) 
			debug("value 0x%x\n", val);

		if (0 != rc)
			return -1;

		offset_rx += 4;
	}
	return 0;
}


/*
  ------------------------------------------------------------------------------
  line_setup
*/

static int
line_setup(int index, struct eth_device *dev)
{
	int rc;
#if defined(CONFIG_AXXIA_56XX)
	int retries = 100000;
#endif
#if defined(CONFIG_AXXIA_56XX) || defined(CONFIG_AXXIA_56XX_EMU)
	unsigned short ad_value;
	unsigned short ge_ad_value;
#elif defined(CONFIG_AXXIA_56XX)
	unsigned short ad_value;
	unsigned short ge_ad_value;
#endif
	unsigned eioaRegion;
	unsigned gmacRegion;
	unsigned gmacPortOffset;
	unsigned hwPortIndex;
	unsigned ncr_status;
	unsigned top;
	unsigned bottom;
	char *envstring;
	unsigned short control;
	unsigned short status;

    if(index >= 128 || (index < 128 && index_by_port[port_by_index[index]] == -1))
    {
        printf("Invalid gmac port %d (index=%d)\n", port_by_index[index],
            index);
	    return -1;
    }

    debug("line_setup for port=%d\n", port_by_index[index]);


	/* Set the region and offset. */
    if (5 > index) {
        hwPortIndex = ((index == 0) ? 0 : (index - 1));
		eioaRegion = NCP_REGION_ID(31, 16); /* 0x1f.0x10 */
		gmacRegion = ((index == 0) ? NCP_REGION_ID(31, 17) : /* 0x1f.0x11 */ 
                                     NCP_REGION_ID(31, 18)); /* 0x1f.0x12 */
		gmacPortOffset = 0xc0 * hwPortIndex;
	} else if (10 > index) {
	    hwPortIndex = ((index == 5) ? 0 : (index - 6));
		eioaRegion = NCP_REGION_ID(23, 16); /* 0x17.0x10 */
        gmacRegion = ((index == 5) ? NCP_REGION_ID(23, 17) : /* 0x1f.0x11 */ 
                                     NCP_REGION_ID(23, 18)); /* 0x1f.0x12 */
		gmacPortOffset = 0xc0 * hwPortIndex;
	} else if (12 > index) {
	    hwPortIndex = 0;
		eioaRegion = NCP_REGION_ID(40, 16); /* 0x28.0x10 */
        gmacRegion = ((index == 10) ? NCP_REGION_ID(40, 17) : /* 0x1f.0x11 */ 
                                      NCP_REGION_ID(40, 18)); /* 0x1f.0x12 */
		gmacPortOffset = 0xc0 * hwPortIndex;
	} else if (14 > index) {
	    hwPortIndex = 0;
		eioaRegion = NCP_REGION_ID(41, 16); /* 0x29.0x10 */
        gmacRegion = ((index == 12) ? NCP_REGION_ID(41, 17) : /* 0x1f.0x11 */ 
                                      NCP_REGION_ID(41, 18)); /* 0x1f.0x12 */
		gmacPortOffset = 0xc0 * hwPortIndex;
	} else if (16 > index) {
	    hwPortIndex = 0;
		eioaRegion = NCP_REGION_ID(42, 16); /* 0x2a.0x10 */
        gmacRegion = ((index == 14) ? NCP_REGION_ID(42, 17) : /* 0x1f.0x11 */ 
                                      NCP_REGION_ID(42, 18)); /* 0x1f.0x12 */
		gmacPortOffset = 0xc0 * hwPortIndex;
	} else if (18 > index) {
	    hwPortIndex = 0;
		eioaRegion = NCP_REGION_ID(43, 16); /* 0x2b.0x10 */
        gmacRegion = ((index == 16) ? NCP_REGION_ID(43, 17) : /* 0x1f.0x11 */ 
                                      NCP_REGION_ID(43, 18)); /* 0x1f.0x12 */
		gmacPortOffset = 0xc0 * hwPortIndex;
	} else if (20 > index) {
	    hwPortIndex = 0;
		eioaRegion = NCP_REGION_ID(44, 16); /* 0x2c.0x10 */
        gmacRegion = ((index == 18) ? NCP_REGION_ID(44, 17) : /* 0x1f.0x11 */ 
                                      NCP_REGION_ID(44, 18)); /* 0x1f.0x12 */
		gmacPortOffset = 0xc0 * hwPortIndex;
	} else if (22 > index) {
	    hwPortIndex = 0;
		eioaRegion = NCP_REGION_ID(45, 16); /* 0x2d.0x10 */
        gmacRegion = ((index == 20) ? NCP_REGION_ID(45, 17) : /* 0x1f.0x11 */ 
                                      NCP_REGION_ID(45, 18)); /* 0x1f.0x12 */
		gmacPortOffset = 0xc0 * hwPortIndex;
	} else {
	    printf("Invalid gmac port %d\n", port_by_index[index]);
	    return -1;
    }

	debug("gmac1-4 -> nemac1 @0x1f.0x12.0x0) \n"
		" hwPortIndex 0x%x eioaRegion 0x%x gmacRegion 0x%x gmacPortOffset 0x%x\n",
			hwPortIndex, eioaRegion, gmacRegion, gmacPortOffset);

	/* Disable stuff. */
	NCR_CALL(ncr_modify32(gmacRegion, 0x330 + gmacPortOffset, 0x3f, 0));
	ncr_read32(gmacRegion, 0x330 + gmacPortOffset, &ncr_status);
	debug("ncr_status 0x%x (expecting 0x0)\n", ncr_status); 
	NCR_CALL(ncr_modify32(gmacRegion, 0x300 + gmacPortOffset, 0x8, 0x0));
	NCR_CALL(ncr_modify32(eioaRegion, 
                NCP_EIOA_GEN_CFG_REG_OFFSET(hwPortIndex) + 0x0, 
                0x00000003, 0x0));
	NCR_CALL(ncr_modify32(gmacRegion, 0x300 + gmacPortOffset, 0x4, 0x0));

    if(phy_media_by_index[index] == EIOA_PHY_MEDIA_COPPER) 
    {
        envstring = getenv("phy_address");

		if (envstring)
        {
			phy_by_index[index] = simple_strtoul(envstring, NULL, 0);
		}

    	mdio_initialize();
    }

	/* Check for "macspeed".  If set, ignore the PHYs... */
	envstring = getenv("macspeed");

	if (NULL != envstring) {
		debug("Setting gmac%d to %s\n", port_by_index[index], envstring);

		NCR_CALL(ncr_read32(gmacRegion, 0x324 + gmacPortOffset,
				    &ncr_status));

		ncr_status &= ~0x3c;
		ncr_status |= 0x08; /* Force Link Up */

		if (0 == strcmp("10MH", envstring)) {
		} else if (0 == strcmp("10MF", envstring)) {
			ncr_status |= 0x04;
		} else if (0 == strcmp("100MH", envstring)) {
			ncr_status |= 0x10;
		} else if (0 == strcmp("100MF", envstring)) {
			ncr_status |= 0x14;
		} else if (0 == strcmp("1G", envstring)) {
			ncr_status |= 0x24;
		} else {
			printf("macspeed must be set to 10MH, 10MF, 100MH, "
			       "100MF, or 1G\n");
			return -1;
		}

        /* fiber vs copper */
        if(phy_media_by_index[index] == EIOA_PHY_MEDIA_FIBER) {
            ncr_status |= 0x400;
        } else {
            ncr_status &= 0xfffffbff;
        }

		NCR_CALL(ncr_write32(gmacRegion, 0x324 + gmacPortOffset,
				     ncr_status));

        /* do phy configuration for copper PHY */
        if(phy_media_by_index[index] == EIOA_PHY_MEDIA_COPPER) {
			/* GMAC2, 3, 4, 18 are special ports on Victoria i.e. 
 			   they are pure Copper and go through Vitesse PHY’s.
			   They need correct PHY addresses in ASE also:
			   GMAC2 (phy 0x18), 3 (phy 0x19), 4 (phy 0x1b), 18 (phy 0x1a)
			 */
			switch (phy_by_index[index]) {
			case 0x18:
			case 0x19:
			case 0x1a:
			case 0x1b:
				mdio_write(0x18, 0x1f, 0x0000);
				mdio_write(0x19, 0x1f, 0x0000);
				mdio_write(0x1a, 0x1f, 0x0000);
				mdio_write(0x1b, 0x1f, 0x0000);

				mdio_write(0x18, 0x17, 0x0000);
				mdio_write(0x19, 0x17, 0x0000);
				mdio_write(0x1a, 0x17, 0x0000);
				mdio_write(0x1b, 0x17, 0x0000);

				mdio_write(0x18, 0x1f, 0x0003);
				mdio_write(0x19, 0x1f, 0x0003);
				mdio_write(0x1a, 0x1f, 0x0003);
				mdio_write(0x1b, 0x1f, 0x0003);

				mdio_write(0x18, 0x10, 0x3080);
				mdio_write(0x19, 0x10, 0x3080);
				mdio_write(0x1a, 0x10, 0x3080);
				mdio_write(0x1b, 0x10, 0x3080);

				mdio_write(0x18, 0x1f, 0x0010);
				mdio_write(0x19, 0x1f, 0x0000);
				mdio_write(0x1a, 0x1f, 0x0000);
				mdio_write(0x1b, 0x1f, 0x0000);

				mdio_write(0x18, 0x13, 0x000f);
				mdio_write(0x18, 0x12, 0x80f0);
				mdio_write(0x18, 0x1f, 0x0000);
				break;
			default:
				control = mdio_read(phy_by_index[index], 0);    
				ad_value = mdio_read(phy_by_index[index], 4);   
				ge_ad_value = mdio_read(phy_by_index[index], 9);

				control &= 0xdebf; /* clear bit 6, 8 and 13 */
				ad_value &= 0xfe1f; /* clear bits 5, 6, 7, 8 */
				ge_ad_value &= 0xcff; /* clear bits 8, 9 */
				
				if (0 == strcmp("10MH", envstring)) {
					ad_value |= 0x20;       /* set bit 5 */
				} else if (0 == strcmp("10MF", envstring)) {
					ad_value |= 0x40;       /* set bit 6 */
					control |= 0x100; /* set bit 8 */
				} else if (0 == strcmp("100MH", envstring)) {
					ad_value |= 0x80;       /* set bit 7 */
					control |= 0x2000; /* set bit 13 */
				} else if (0 == strcmp("100MF", envstring)) {
					ad_value |= 0x100;      /* set bit 8 */
					control |= 0x2100; /* set bit 8, 13 */
				} else if (0 == strcmp("1G", envstring)) {
					ge_ad_value |= 0x300;   /* set bit 8, 9 */
					control |= 0x40;        /* set bit 6 */
					control &= 0xdfff;      /* clear bit 13 */
				} else {

					printf("macspeed must be set to 10MH, 10MF, 100MH, "
						   "100MF, or 1G\n");
					return -1;
				}
				
				mdio_write(phy_by_index[index], 4, ad_value);    
				mdio_write(phy_by_index[index], 9, ge_ad_value); 
				mdio_write(phy_by_index[index], 0, control);     
				break;
			}
			DELAY();
			take_snapshot(port_by_index[index]);
        }
	} else {
	    /* do phy configuration for copper PHY */
        if(phy_media_by_index[index] == EIOA_PHY_MEDIA_COPPER) {
#if defined(CONFIG_AXXIA_56XX)
    		/* Get ad_value and ge_ad_value from the environment. */
    		envstring = getenv("ad_value");

    		if (NULL == envstring) {
    			ad_value = 0x1e1;
    		} else {
    			ad_value = simple_strtoul(envstring, NULL, 0);
    		}

    		envstring = getenv("ge_ad_value");

    		if (NULL == envstring) {
    			ge_ad_value = 0x300;
    		} else {
    			ge_ad_value = simple_strtoul(envstring, NULL, 0);
    		}

    		/* Set the AN advertise values. */
			mdio_write(phy_by_index[index], 4, ad_value);
			mdio_write(phy_by_index[index], 9, ge_ad_value);

    		/* Force re-negotiation. */
    		control = mdio_read(phy_by_index[index], 0);
    		control |= 0x1200;
			mdio_write(phy_by_index[index], 0, control);

    		DELAY();

    		/* Wait for AN complete. */
    		for (;;) {
				status = mdio_read(phy_by_index[index], 1);

    			if (0 != (status & 0x20))
    				break;

    			if (0 == retries--) {
    				printf("GMAC%d: AN Timed Out.\n",
    					    port_by_index[index]);
    				return -1;
    			}

    			DELAY();
    		}

    		if (0 == (status & 0x4)) {
    			printf("GMAC%d: LINK is Down.\n",
    				    port_by_index[index]);

    			if (NCP_USE_ALL_PORTS != eioaPort)
    				return -1; /* Don't Error Out in AUTO Mode. */
    		} else {
				status = mdio_read(phy_by_index[index], 0x1c);
            }
#else
    		status = 0x28; /* For FPGA, its 100MF */
#endif
    		printf("GMAC%d: ", port_by_index[index]);

    		switch ((status & 0x18) >> 3) {
    		case 0:
    			puts("10M");
    			break;
    		case 1:
    			puts("100M");
    			break;
    		case 2:
    			puts("1G");
    			break;
    		default:
    			puts("UNKNOWN");
    			break;
    		}

    		printf(" %s AN\n",
    		       (0 == (status & 0x20)) ?
    		       "Half Duplex" : "Full Duplex");
    		DELAY();
            

    		/* Make the MAC match. */

    		NCR_CALL(ncr_read32(gmacRegion, 0x324 + gmacPortOffset,
    				    &ncr_status));
    		ncr_status &= ~0x3c;
    		ncr_status |= 0x08;	/* Force Link Up */
            ncr_status &= 0xfffffbff; /* clear fiber */

    		if (0 != (status & 0x20))
    			ncr_status |= 0x04; /* Force Full Duplex */

    		/* Set the Speed */
    		ncr_status |= (((status & 0x18) >> 3) << 4);

    		NCR_CALL(ncr_write32(gmacRegion, 0x324 + gmacPortOffset,
    				     ncr_status));
        } else {
            /* enable AN in mac */
    		NCR_CALL(ncr_read32(gmacRegion, 0x324 + gmacPortOffset,
    				    &ncr_status));
    		ncr_status &= ~0x3c;
            ncr_status |= 0x400; /* set fiber */

            ncr_status |= 0x3;

    		NCR_CALL(ncr_write32(gmacRegion, 0x324 + gmacPortOffset,
    				     ncr_status));
        }
	}

	/*
	  Set the Ethernet addresses...
	*/

	top = (ethernet_address[0] << 8) | ethernet_address[1];
	bottom = (ethernet_address[2] << 24) | (ethernet_address[3] << 16) |
	  (ethernet_address[4] << 8) | (ethernet_address[5]);

	/* - EIOA */
	NCR_CALL(ncr_write32(eioaRegion, NCP_EIOA_GEN_CFG_REG_OFFSET(hwPortIndex) + 0x4, bottom));
	NCR_CALL(ncr_write32(eioaRegion, NCP_EIOA_GEN_CFG_REG_OFFSET(hwPortIndex) + 0x8, top));

	/* - Source */
	NCR_CALL(ncr_write32(gmacRegion, 0x304 + gmacPortOffset, bottom));
	NCR_CALL(ncr_write32(gmacRegion, 0x308 + gmacPortOffset, top));

	/* - Unicast */
	NCR_CALL(ncr_write32(gmacRegion, 0x344 + gmacPortOffset, bottom));
	NCR_CALL(ncr_write32(gmacRegion, 0x348 + gmacPortOffset, bottom));
	NCR_CALL(ncr_write32(gmacRegion, 0x34c + gmacPortOffset,
			     ((top & 0xffff) << 16) | (top & 0xffff)));
	NCR_CALL(ncr_write32(gmacRegion, 0x350 + gmacPortOffset, bottom));
	NCR_CALL(ncr_write32(gmacRegion, 0x354 + gmacPortOffset, top));

	/* Enable stuff. */
	NCR_CALL(ncr_modify32(gmacRegion, 0x300 + gmacPortOffset, 0x8, 0x8));
    NCR_CALL(ncr_modify32(eioaRegion, 
                NCP_EIOA_GEN_CFG_REG_OFFSET(hwPortIndex) + 0x0, 
                0x00000003, 0x3));
	NCR_CALL(ncr_modify32(gmacRegion, 0x300 + gmacPortOffset, 0x4, 0x4));

	/* Unicast Filtering based on the Ethernet Address set above. */
	if (0 == rxtest && 0 == loopback)
		NCR_CALL(ncr_modify32(gmacRegion, 0x330 + gmacPortOffset,
				      0x3f, 0x09));

	return 0;

 ncp_return:

	return -1;
}

static int *memset_int(int *s, int c, size_t count)
{
    int indx = 0;
    for(indx = 0; indx < count; indx++) {
        s[indx] = c;
    }

    return s;
}

/*
  -------------------------------------------------------------------------------
  initialize_task_io
*/

static int
initialize_task_io(struct eth_device *dev)
{
	ncp_st_t ncpStatus = NCP_ST_SUCCESS;
	char *eioaport = NULL;
	int i = 0;
    char *phy_media_str = getenv("phymedia");
    eioa_phy_media phy_media = EIOA_PHY_MEDIA_FIBER;

    /* set phy media type */
    if(phy_media_str) {
        if(strcmp(phy_media_str, "copper") == 0) {
            phy_media = EIOA_PHY_MEDIA_COPPER;
        } else if(strcmp(phy_media_str, "fiber") == 0) {
            phy_media = EIOA_PHY_MEDIA_FIBER;
        } else {
            printf("Invalid PHY media: %s\n", phy_media_str);
            return -1;
        }
    }
    /* set all ports to same media type */
    memset_int(phy_media_by_index, phy_media, EIOA_NUM_PORTS);

    /* Set the port. */
	eioaport = getenv("eioaport");

    debug("eioaport=%s\n", eioaport);

    if (NULL != eioaport) {
        if(strcmp(eioaport, "rx-gmac") == 0) {
            /* set same port type for all ports */
            memset_int(port_type_by_index, EIOA_PORT_TYPE_GMAC, EIOA_NUM_PORTS);
            memcpy(index_by_port, index_by_port_gmac, sizeof(index_by_port));
            eioaPort = NCP_USE_ALL_PORTS;
		} else if(strncmp(eioaport, "gmac", 4) == 0) {
            eioaPort = simple_strtoul(&eioaport[4], NULL, 10);
            if(eioaPort < EIOA_NUM_PORT_INDEXES && index_by_port_gmac[eioaPort] != -1) {
                index_by_port[eioaPort] = index_by_port_gmac[eioaPort];
                /* set same port type for all ports */
                memset_int(port_type_by_index, EIOA_PORT_TYPE_GMAC, 
                    EIOA_NUM_PORTS);
            } else {
                printf("Invalid gmac port %d\n", eioaPort);
			    return -1;
            }
        } else if (0 == strcmp(eioaport, "rx-xgmac")) {
            /* set same port type for all ports */
            memset_int(port_type_by_index, EIOA_PORT_TYPE_XGMAC, 
                    EIOA_NUM_PORTS);
            memcpy(index_by_port, index_by_port_xgmac, sizeof(index_by_port));
            eioaPort = NCP_USE_ALL_PORTS;
		} else if(strncmp(eioaport, "xgmac", 5) == 0) {
            eioaPort = simple_strtoul(&eioaport[5], NULL, 10);
            if(eioaPort < EIOA_NUM_PORT_INDEXES && index_by_port_xgmac[eioaPort] != -1) {
                index_by_port[eioaPort] = index_by_port_xgmac[eioaPort];
                /* set same port type for all ports */
                memset_int(port_type_by_index, EIOA_PORT_TYPE_XGMAC, 
                        EIOA_NUM_PORTS);
            } else {
                printf("Invalid xgmac port %d\n", eioaPort);
			    return -1;
            }
        } else {
		printf("If set, eioaport must be one of the following:\n"
                "\tgmac[0-4,16-20,32,33,48,49,64,65,80,81,96,97,112,113],\n"
                "\txgmac[0,1,16,17,32,33,48,49,64,65,80,81,96,97,112,113]\n"
                "\trx-gmac,\n"
                "\trx-xgmac,\n");
			return -1;
		}
    }

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

    debug("Configuring Uboot task io...");
    /* initialize task io */
    NCP_CALL(ncp_task_uboot_config());
    debug("done\n");

    if((NCP_USE_ALL_PORTS == eioaPort && port_type_by_index[0] == EIOA_PORT_TYPE_GMAC) ||
       (NCP_USE_ALL_PORTS != eioaPort && port_type_by_index[index_by_port[eioaPort]] == EIOA_PORT_TYPE_GMAC)) {
        debug("Configuring all HSS for GMAC...");
    } else if((NCP_USE_ALL_PORTS == eioaPort && port_type_by_index[0] == EIOA_PORT_TYPE_XGMAC) ||
       (NCP_USE_ALL_PORTS != eioaPort && port_type_by_index[index_by_port[eioaPort]] == EIOA_PORT_TYPE_XGMAC)) {
        debug("Configuring all HSS for XGMAC...");
    }
    debug("done\n");

    debug("Creating task hdl.\n");
    /* create task handle */
    NCP_CALL(ncp_task_hdl_create(
                &gNCP,              /* dummy NCP handle */
                threadQueueSetId,   /* thread queue set id */    
                FALSE,              /* shared */
                FALSE,              /* ordered task completion - dont care */
                &taskHdl));         /* task handle */

    debug("Binding to nca queue %d and task recv queue %d.\n", 
            ncaQueueId, recvQueueId);
    /* allocate recv queue */
    NCP_CALL(ncp_task_recv_queue_bind(
                taskHdl,        /* task handle */
                ncaQueueId,     /* NCA queue id */
                16,             /* weight */
                FALSE,          /* shared */
                TRUE,           /* fixed receive queue id */
                &recvQueueId)); /* receive queue id if not fixed */

 ncp_return:
	if (NCP_ST_SUCCESS != ncpStatus) {
        printf("ERROR: status=%d\n", ncpStatus);
		lsi_eioa_eth_halt(dev);
		return -1;
	} else 
		debug("%s() taskHdl %p recvQueueId %d\n", __func__, taskHdl, (int) recvQueueId);

	/*
	  Make sure the network is connected.
	*/
	

	if (NCP_USE_ALL_PORTS == eioaPort) {
	    /* Use all ports. */
	    for (i = 0; i < EIOA_NUM_PORTS; ++i) {
	        debug("index_by_port[i] %d, port_type_by_index[i] %d\n",
			index_by_port[i], port_type_by_index[i]);
                if (index_by_port[i] != -1 && (port_type_by_index[i] == EIOA_PORT_TYPE_GMAC)){
    			if (0 != line_setup(i, dev)) {
                            printf("line_setup failed for gmac%d (all)\n", port_by_index[i]);
    			    return -1;
    			}
            }    
	    }
	} else {
            if ((index_by_port[eioaPort] != -1) && (port_type_by_index[index_by_port[eioaPort]] == EIOA_PORT_TYPE_GMAC)) {
                printf("Using EIOA Port GMAC%d\n", eioaPort);
    		if (0 != line_setup(index_by_port[eioaPort], dev)) {
                    printf("line_setup failed for gmac%d\n",  eioaPort);
		    return -1;
    		}
            } else {
                  printf("Using EIOA Port XGMAC%02d\n", eioaPort);
            }
	}

	initialized = 1;

	return 0;
}

 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      tx_rxdetresetn                            :  4;
     unsigned      tx_rxdetena                               :  4;
     unsigned      txdata_valid                              :  4;
     unsigned      txwclk_external                           :  4;
     unsigned      tx_ratechange_ena                         :  4;
     unsigned      rx_ratechange_ena                         :  4;
     unsigned      txpd                                      :  4;
     unsigned      rxpd                                      :  4;
#else    /* Little Endian */
     unsigned      rxpd                                      :  4;
     unsigned      txpd                                      :  4;
     unsigned      rx_ratechange_ena                         :  4;
     unsigned      tx_ratechange_ena                         :  4;
     unsigned      txwclk_external                           :  4;
     unsigned      txdata_valid                              :  4;
     unsigned      tx_rxdetena                               :  4;
     unsigned      tx_rxdetresetn                            :  4;
#endif
} ncp_cfg_phy_ctrl2_r_t;

typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  2;
     unsigned      synce1_clk_en                             :  2;
     unsigned      reserved1                                 :  2;
     unsigned      synce0_clk_en                             :  2;
     unsigned      reserved2                                 :  2;
     unsigned      auto_los_detect                           :  1;
     unsigned      reserved3                                 :  3;
     unsigned      tbi_clk_en                                :  2;
     unsigned      tt_debug_lane_sel                         :  2;
     unsigned      cr_clk_div_sel                            :  2;
     unsigned      mdio_soft_rst                             :  1;
     unsigned      serdes_reset_0                            :  1;
     unsigned      phy_soft_rst_0                            :  1;
     unsigned      reg_reset_0                               :  1;
     unsigned      reserved4                                 :  2;
     unsigned      lane_qsgmii                               :  2;
     unsigned      reserved5                                 :  2;
     unsigned      lane_xfi                                  :  2;
#else    /* Little Endian */
     unsigned      lane_xfi                                  :  2;
     unsigned      reserved5                                 :  2;
     unsigned      lane_qsgmii                               :  2;
     unsigned      reserved4                                 :  2;
     unsigned      reg_reset_0                               :  1;
     unsigned      phy_soft_rst_0                            :  1;
     unsigned      serdes_reset_0                            :  1;
     unsigned      mdio_soft_rst                             :  1; 
     unsigned      cr_clk_div_sel                            :  2;
     unsigned      tt_debug_lane_sel                         :  2;
     unsigned      tbi_clk_en                                :  2;
     unsigned      reserved3                                 :  3;
     unsigned      auto_los_detect                           :  1;
     unsigned      reserved2                                 :  2;
     unsigned      synce0_clk_en                             :  2;
     unsigned      reserved1                                 :  2;
     unsigned      synce1_clk_en                             :  2;
     unsigned      reserved0                                 :  2;
#endif
} ncp_global_global_ctrl0_r_t;


/*
  -------------------------------------------------------------------------------
  finalize_task_io
*/

void
finalize_task_io(void)
{
    int rc = 0;
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    
    /*
     *  Stop the queue.
     */

    /* Disable EIOA gmac NEMACs. */
    ncr_modify32(NCP_REGION_ID(0x1f, 0x11), 0x300, 0x0000000c, 0x0);
    ncr_modify32(NCP_REGION_ID(0x1f, 0x12), 0x300, 0x0000000c, 0x0);
    ncr_modify32(NCP_REGION_ID(0x1f, 0x12), 0x3c0, 0x0000000c, 0x0);
    ncr_modify32(NCP_REGION_ID(0x1f, 0x12), 0x480, 0x0000000c, 0x0);
    ncr_modify32(NCP_REGION_ID(0x1f, 0x12), 0x540, 0x0000000c, 0x0);
    ncr_modify32(NCP_REGION_ID(0x17, 0x11), 0x300, 0x0000000c, 0x0);
    ncr_modify32(NCP_REGION_ID(0x17, 0x12), 0x300, 0x0000000c, 0x0);
    ncr_modify32(NCP_REGION_ID(0x17, 0x12), 0x3c0, 0x0000000c, 0x0);
    ncr_modify32(NCP_REGION_ID(0x17, 0x12), 0x480, 0x0000000c, 0x0);
    ncr_modify32(NCP_REGION_ID(0x17, 0x12), 0x540, 0x0000000c, 0x0);

    /* Disable EIOA xgmac NEMACs. */
#if 0 /* not supported yet */
    ncr_modify32(NCP_REGION_ID(0x1f, 0x11), 0xc00, 0x0000000c, 0x0);
    ncr_modify32(NCP_REGION_ID(0x1f, 0x12), 0xc00, 0x0000000c, 0x0);
    ncr_modify32(NCP_REGION_ID(0x17, 0x11), 0xc00, 0x0000000c, 0x0);
    ncr_modify32(NCP_REGION_ID(0x17, 0x12), 0xc00, 0x0000000c, 0x0);
#endif

    /* swreset gmac */
    ncr_or(NCP_REGION_ID(0x1f, 0x11), 0x20, 0x10f);
    ncr_or(NCP_REGION_ID(0x1f, 0x12), 0x20, 0x10f);
    ncr_or(NCP_REGION_ID(0x17, 0x11), 0x20, 0x10f);
    ncr_or(NCP_REGION_ID(0x17, 0x12), 0x20, 0x10f);

    /* Disable ports in EIOA Cores. */
    NCR_CALL(ncr_modify32(NCP_REGION_ID(0x1f, 0x10), 
                NCP_EIOA_GEN_CFG_REG_OFFSET(0), 0x00000003, 0x0));
    NCR_CALL(ncr_modify32(NCP_REGION_ID(0x1f, 0x10), 
                NCP_EIOA_GEN_CFG_REG_OFFSET(1), 0x00000003, 0x0));
    NCR_CALL(ncr_modify32(NCP_REGION_ID(0x1f, 0x10), 
                NCP_EIOA_GEN_CFG_REG_OFFSET(2), 0x00000003, 0x0));
    NCR_CALL(ncr_modify32(NCP_REGION_ID(0x1f, 0x10), 
                NCP_EIOA_GEN_CFG_REG_OFFSET(3), 0x00000003, 0x0));
    NCR_CALL(ncr_modify32(NCP_REGION_ID(0x1f, 0x10), 
                NCP_EIOA_GEN_CFG_REG_OFFSET(4), 0x00000003, 0x0));
    NCR_CALL(ncr_modify32(NCP_REGION_ID(0x17, 0x10), 
                NCP_EIOA_GEN_CFG_REG_OFFSET(0), 0x00000003, 0x0));
    NCR_CALL(ncr_modify32(NCP_REGION_ID(0x17, 0x10), 
                NCP_EIOA_GEN_CFG_REG_OFFSET(1), 0x00000003, 0x0));
    NCR_CALL(ncr_modify32(NCP_REGION_ID(0x17, 0x10), 
                NCP_EIOA_GEN_CFG_REG_OFFSET(2), 0x00000003, 0x0));
    NCR_CALL(ncr_modify32(NCP_REGION_ID(0x17, 0x10), 
                NCP_EIOA_GEN_CFG_REG_OFFSET(3), 0x00000003, 0x0));
    NCR_CALL(ncr_modify32(NCP_REGION_ID(0x17, 0x10), 
                NCP_EIOA_GEN_CFG_REG_OFFSET(4), 0x00000003, 0x0));

    /*
     Shut down task lite.
    */

    if (taskHdl) {
        NCP_CALL(ncp_task_recv_queue_unbind(taskHdl, recvQueueId));
        NCP_CALL(ncp_task_hdl_remove(taskHdl));
    }

    ncp_task_uboot_unconfig();

    initialized = 0;

ncp_return:
	return;
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
		if (0 != initialize_task_io(dev)) {
			printf("Failed to Initialize TaskIO Lite!\n");
			return -1;
		}

	return 0;
}

/*
  -------------------------------------------------------------------------------
  lsi_eioa_eth_send
*/

int
lsi_eioa_eth_send(struct eth_device *dev, void *packet, int length)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    int bytes_sent = 0;
    void *taskAddr;
    int i;
    ncp_task_ncaV2_send_meta_t taskMetaData;

    debug("%s(): packet=0x%p, length=%d\n",
	  __func__, packet, length);

	for (i = 0; i < EIOA_NUM_PORTS; ++i) {
        /* if sending on single port, skip other ports */
        if((eioaPort != NCP_USE_ALL_PORTS && port_by_index[i] != eioaPort)
			/* if send to all skip unsued ports */
			 || (index_by_port[i] == -1))	{
            continue;
        }	
        debug("lsi_eioa_eth_send(): sending to port=%d\n"
			"index_by_port[%d] %u\n", eioaPort, i, index_by_port[i]);

        bytes_sent = 0;
        
        NCP_CALL(ncp_task_ncav2_buffer_alloc(taskHdl, length, &taskAddr));   /* V2 */ 

		if (NULL == taskAddr) {
			printf("Couldn't allocate send buffer.\n");
			return 0;
		}

        /* copy the task to buffer */
	memcpy(taskAddr, (void *)packet, length);
/* HACK: Temporary invalidate until cache coherency is figured in uboot */
#ifdef USE_CACHE_SYNC
        flush_cache((unsigned long)taskAddr, length);
#endif

        /* init task meta data */
		memset(&taskMetaData, 0, sizeof(taskMetaData));
        taskMetaData.virtualFlowID  = sendVpId;
        taskMetaData.priority       = 0;
        taskMetaData.pduSegSize0    = length;
        taskMetaData.ptrCnt         = 1;
        taskMetaData.pduSegAddr0    = (ncp_uint64_t)((unsigned long)taskAddr);
        taskMetaData.params[0]   	= port_by_index[i]; /* parametrized OP */
		debug("%s(): Send over VP CPUtoEIOA output port %u\n", __func__,
			(unsigned int) taskMetaData.params[0]);

/* HACK: Temporary invalidate until cache coherency is figured in uboot */
#ifdef USE_CACHE_SYNC
		flush_cache((unsigned long)&taskMetaData, sizeof(taskMetaData));
#endif

		if (length != task_send(&taskMetaData)) {
			debug("Send Failed on Port %d\n", port_by_index[i]);
		} else {
			debug("Send %d bytes on Port %d\n", length, port_by_index[i]);
			bytes_sent = length;
		}

        /* if sending on single port, skip rest of the ports */
        if(eioaPort != NCP_USE_ALL_PORTS && port_by_index[i] != eioaPort) {
            break;
        }
	}

ncp_return:
    if(ncpStatus != NCP_ST_SUCCESS) {
        printf("Failed to send packet. status=%d\n", ncpStatus);
    }
	return bytes_sent;
}

/*
  -------------------------------------------------------------------------------
  lsi_eioa_eth_rx
*/

int
lsi_eioa_eth_rx(struct eth_device *dev)
{
    ncp_st_t ncpStatus;
    ncp_task_ncaV2_recv_buf_t *task;
    int bytes_received = 0;
    ncp_vp_hdl_t vpHdl;
    ncp_uint8_t engineSeqId;
    ncp_uint8_t recvQueueId;
    static short first = 1;
    static void* shared_pool_start = NULL;
	static long unsigned packets_received = 0;

    /* receive the task */
    NCP_CALL(ncp_task_ncav2_recv(taskHdl, &recvQueueId, &vpHdl, &engineSeqId, 
                &task, NULL, FALSE));

	if ((task != NULL) && (first == 1)) {
		shared_pool_start = (void*) task;
		first = 0;
		debug("Shared Pool 2 for the Size start at %p\n", 
				shared_pool_start);
	}

    if(dumprx) {
    	axxia_dump_packet("LSI_EIOA RX", (void *)(task->pduSegAddr0), 
                task->pduSegSize0);
    }

/* HACK: Temporary invalidate until cache coherency is figured in uboot */
#ifdef USE_CACHE_SYNC
    invalidate_dcache_all();
#endif

    debug("\nlsi_eioa_eth_rx(): received task:"
			"1st arrived task_addr=0x%p task_addr=0x%p, port=%d, size=%d\n",
               shared_pool_start, task, task->params[0], task->pduSegSize0);
	debug("  packets received up to now %ld\n", packets_received++);

    /* 
     * If receiving on any port or on the single configured port, handle the 
     * packet and give it to the up layer. Otherwise, free it and return.
     */
	if ((NCP_USE_ALL_PORTS == eioaPort) ||
        (NCP_USE_ALL_PORTS != eioaPort && task->params[0] == eioaPort)) {

    	if (NCP_USE_ALL_PORTS == eioaPort) {
    		eioaPort = task->params[0];
            if(port_type_by_index[index_by_port[eioaPort]] == EIOA_PORT_TYPE_GMAC) {
    		    printf("Using EIOA Port GMAC%02d\n", eioaPort);
            } else {
                printf("Using EIOA Port XGMAC%02d\n", eioaPort);
            }
    	}

    	bytes_received = task->pduSegSize0;

		unsigned char *pkt = (unsigned char *)/*le64_to_cpu*/(task->pduSegAddr0);
        /* copy the received packet to the up layer buffer */
    	if (0 == loopback && 0 == rxtest)
			net_process_received_packet(pkt, bytes_received);
    }
    /* free the buffer */
    NCP_CALL(ncp_task_ncav2_free_rx_task(taskHdl, task));

 ncp_return:
    if (NCP_ST_TASK_RECV_QUEUE_EMPTY == ncpStatus) {
		return 0;
	} else if (NCP_ST_SUCCESS != ncpStatus) {
		printf("%s:%d - NCP_CALL() Failed: 0x%08x\n",
		       __FILE__, __LINE__, ncpStatus);
		return 0;
	}

	return bytes_received;
}

/*
  -------------------------------------------------------------------------------
  lsi_eioa_receive_test
*/

void
lsi_eioa_receive_test(struct eth_device *dev)
{
	long int packets_received = 0;

	eth_halt();

	if (0 != eth_init()) {
        rxtest = 0;
		eth_halt();
		return;
	}

	for (;;) {
        int packet_len = eth_rx();
		if (0 != packet_len) {
			++packets_received;
        }

		if (ctrlc())
			break;
	}

    	rxtest = 0;
	eth_halt();
	printf("EIOA Receive Test Interrupted.  Received %ld packets.\n",
	       packets_received);

	return;
}

/*
  -------------------------------------------------------------------------------
  lsi_eioa_loopback_test
*/

void
lsi_eioa_loopback_test(struct eth_device *dev)
{
	int bytes_received;
	int packets_looped = 0;

	loopback = 1;
	eth_halt();

	if (0 != eth_init()) {
        loopback = 0;
		eth_halt();
		return;
	}

	for (;;) {
		if (0 != (bytes_received = eth_rx())) {
			unsigned char *pkt = NULL;
			if (bytes_received != eth_send((void *)pkt, bytes_received)) {
				printf("lsi_eioa_eth_send() failed.\n");
			} else {
				++packets_looped;
			}
		}

		if (ctrlc())
			break;
	}

	loopback = 0;
	eth_halt();
	printf("EIOA Loopback Test Interrupted.  Looped back %d packets.\n",
	       packets_looped);

	return;
}


#if 0
/*
  ------------------------------------------------------------------------------
  line_setup_xgmac
*/

static int
line_setup_xgmac(int index)
{
	int rc;
	int retries = 100000;
	unsigned long eioaRegion;
	unsigned long xgmacRegion;
	unsigned long xgmacPortOffset;
	unsigned long eioaPortOffset;
    unsigned long hwPortIndex;
	unsigned long ncr_status;
	char *envstring;
	unsigned short status;
	unsigned long top;
	unsigned long bottom;
	unsigned short ad_value;
	unsigned short ge_ad_value;
	unsigned short control;

    if(index >= 128 || (index < 128 && index_by_port_xgmac[port_by_index[index]] != -1))
    {
        printf("Invalid xgmac port %d (index=%d)\n", port_by_index[index],
            index);
	    return -1;
    }
    
	/* Set the region and offset. */
    if (2 > index) {
        hwPortIndex = index;
		eioaRegion = NCP_REGION_ID(31, 16); /* 0x1f.0x10 */
		xgmacRegion = ((hwPortIndex == 0) ? NCP_REGION_ID(31, 17) : /* 0x1f.0x11 */ 
                                            NCP_REGION_ID(31, 18)); /* 0x1f.0x12 */
		xgmacPortOffset = 0xc0 * hwPortIndex;
	} else if (7 > index) {
	    hwPortIndex = index - 5;
		eioaRegion = NCP_REGION_ID(23, 16); /* 0x17.0x10 */
        xgmacRegion = ((hwPortIndex == 0) ? NCP_REGION_ID(23, 17) : /* 0x1f.0x11 */ 
                                            NCP_REGION_ID(23, 18)); /* 0x1f.0x12 */
		xgmacPortOffset = 0xc0 * hwPortIndex;
	} else if (12 > index) {
	    hwPortIndex = index - 10;
		eioaRegion = NCP_REGION_ID(40, 16); /* 0x28.0x10 */
        xgmacRegion = ((hwPortIndex == 0) ? NCP_REGION_ID(40, 17) : /* 0x1f.0x11 */ 
                                            NCP_REGION_ID(40, 18)); /* 0x1f.0x12 */
		xgmacPortOffset = 0xc0 * hwPortIndex;
	} else if (14 > index) {
	    hwPortIndex = index - 12;
		eioaRegion = NCP_REGION_ID(41, 16); /* 0x29.0x10 */
        xgmacRegion = ((hwPortIndex == 0) ? NCP_REGION_ID(41, 17) : /* 0x1f.0x11 */ 
                                            NCP_REGION_ID(41, 18)); /* 0x1f.0x12 */
		xgmacPortOffset = 0xc0 * hwPortIndex;
	} else if (16 > index) {
	    hwPortIndex = index - 14;
		eioaRegion = NCP_REGION_ID(42, 16); /* 0x2a.0x10 */
        xgmacRegion = ((hwPortIndex == 0) ? NCP_REGION_ID(42, 17) : /* 0x1f.0x11 */ 
                                            NCP_REGION_ID(42, 18)); /* 0x1f.0x12 */
		xgmacPortOffset = 0xc0 * hwPortIndex;
	} else if (18 > index) {
	    hwPortIndex = index - 16;
		eioaRegion = NCP_REGION_ID(43, 16); /* 0x2b.0x10 */
        xgmacRegion = ((hwPortIndex == 0) ? NCP_REGION_ID(43, 17) : /* 0x1f.0x11 */ 
                                            NCP_REGION_ID(43, 18)); /* 0x1f.0x12 */
		xgmacPortOffset = 0xc0 * hwPortIndex;
	} else if (20 > index) {
	    hwPortIndex = index - 18;
		eioaRegion = NCP_REGION_ID(44, 16); /* 0x2c.0x10 */
        xgmacRegion = ((hwPortIndex == 0) ? NCP_REGION_ID(44, 17) : /* 0x1f.0x11 */ 
                                            NCP_REGION_ID(44, 18)); /* 0x1f.0x12 */
		xgmacPortOffset = 0xc0 * hwPortIndex;
	} else if (22 > index) {
	    hwPortIndex = index - 20;
		eioaRegion = NCP_REGION_ID(45, 16); /* 0x2d.0x10 */
        xgmacRegion = ((hwPortIndex == 0) ? NCP_REGION_ID(45, 17) : /* 0x1f.0x11 */ 
                                            NCP_REGION_ID(45, 18)); /* 0x1f.0x12 */
		xgmacPortOffset = 0xc0 * hwPortIndex;
	} else {
	    printf("Invalid xgmac port %d\n", port_by_index[index]);
	    return -1;
    }

	/* Disable stuff. */
	NCR_CALL(ncr_modify32(xgmacRegion, 0xc30 + xgmacPortOffset, 0x73f, 0));
	NCR_CALL(ncr_modify32(xgmacRegion, 0xc00 + xgmacPortOffset, 0x8, 0x0));
	NCR_CALL(ncr_modify32(eioaRegion, 
                NCP_EIOA_GEN_CFG_REG_OFFSET(hwPortIndex) + 0x0, 
                0x00000003, 0x0));
	NCR_CALL(ncr_modify32(xgmacRegion, 0xc00 + xgmacPortOffset, 0x4, 0x0));

	/* Check for "macspeed".  If set, ignore the PHYs... */
	envstring = getenv("macspeed");

	if (NULL != envstring) {
		printf("Overriding MAC Speed Settings; Ignoring PHY(s)!"
		       " %s\n", envstring);

		NCR_CALL(ncr_read32(xgmacRegion, 0x324 + xgmacPortOffset,
				    &ncr_status));
		ncr_status &= ~0x3c;
		ncr_status |= 0x08; /* Force Link Up */

		if (0 == strcmp("10MH", envstring)) {
		} else if (0 == strcmp("10MF", envstring)) {
			ncr_status |= 0x04;
		} else if (0 == strcmp("100MH", envstring)) {
			ncr_status |= 0x10;
		} else if (0 == strcmp("100MF", envstring)) {
			ncr_status |= 0x14;
		} else if (0 == strcmp("1G", envstring)) {
			ncr_status |= 0x24;
		} else {
			printf("macspeed must be set to 10MH, 10MF, 100MH, "
			       "100MF, or 1G\n");
			return -1;
		}

		NCR_CALL(ncr_write32(xgmacRegion, 0x324 + xgmacPortOffset,
				     ncr_status));
	} else {
		/* Get ad_value and ge_ad_value from the environment. */
		envstring = getenv("ad_value");

		if (NULL == envstring) {
			ad_value = 0x1e1;
		} else {
			ad_value = simple_strtoul(envstring, NULL, 0);
		}

		envstring = getenv("ge_ad_value");

		if (NULL == envstring) {
			ge_ad_value = 0x300;
		} else {
			ge_ad_value = simple_strtoul(envstring, NULL, 0);
		}

		/* Set the AN advertise values. */
		phy_write(phy_dev, MDIO_DEVAD_NONE, 4, ad_value);
		phy_write(phy_dev, MDIO_DEVAD_NONE, 9, ge_ad_value);

		/* Force re-negotiation. */
		control = phy_read(phy_dev, MDIO_DEVAD_NONE, 0);
		control |= 0x200;
		phy_write(phy_dev, MDIO_DEVAD_NONE, 0, control);

		DELAY();

		/* Wait for AN complete. */
		for (;;) {
			status = phy_read(phy_dev, MDIO_DEVAD_NONE, 1);

			if (0 != (status & 0x20))
				break;

			if (0 == retries--) {
				printf("GMAC%d: AN Timed Out.\n",
					    port_by_index[index]);
				return -1;
			}

			DELAY();
		}

		if (0 == (status & 0x4)) {
			printf("GMAC%d: LINK is Down.\n",
				    port_by_index[index]);

			if (NCP_USE_ALL_PORTS != eioaPort)
				return -1; /* Don't Error Out in AUTO Mode. */
		} else {
			status = phy_read(phy_dev, MDIO_DEVAD_NONE, 0x1c);
			printf("GMAC%02d: ", port_by_index[index]);

			switch ((status & 0x18) >> 3) {
			case 0:
				puts("10M");
				break;
			case 1:
				puts("100M");
				break;
			case 2:
				puts("1G");
				break;
			default:
				puts("UNKNOWN");
				break;
			}

			printf(" %s\n",
			       (0 == (status & 0x20)) ?
			       "Half Duplex" : "Full Duplex");
			DELAY();

			/* Make the MAC match. */

			NCR_CALL(ncr_read32(xgmacRegion, 0x324 + xgmacPortOffset,
					    &ncr_status));
			ncr_status &= ~0x3c;
			ncr_status |= 0x08;	/* Force Link Up */

			if (0 != (status & 0x20))
				ncr_status |= 0x04; /* Force Full Duplex */

			/* Set the Speed */
			ncr_status |= (((status & 0x18) >> 3) << 4);

			NCR_CALL(ncr_write32(xgmacRegion, 0x324 + xgmacPortOffset,
					     ncr_status));
		}
	}

	/*
	  Set the Ethernet addresses...
	*/

	top = (ethernet_address[0] << 8) | ethernet_address[1];
	bottom = (ethernet_address[2] << 24) | (ethernet_address[3] << 16) |
	  (ethernet_address[4] << 8) | (ethernet_address[5]);

	/* - EIOA */
	NCR_CALL(ncr_write32(eioaRegion, 0xa0 + eioaPortOffset, bottom));
	NCR_CALL(ncr_write32(eioaRegion, 0xa4 + eioaPortOffset, top));

	/* - Source */
	NCR_CALL(ncr_write32(xgmacRegion, 0x304 + xgmacPortOffset, bottom));
	NCR_CALL(ncr_write32(xgmacRegion, 0x308 + xgmacPortOffset, top));

	/* - Unicast */
	NCR_CALL(ncr_write32(xgmacRegion, 0x344 + xgmacPortOffset, bottom));
	NCR_CALL(ncr_write32(xgmacRegion, 0x348 + xgmacPortOffset, bottom));
	NCR_CALL(ncr_write32(xgmacRegion, 0x34c + xgmacPortOffset,
			     ((top & 0xffff) << 16) | (top & 0xffff)));
	NCR_CALL(ncr_write32(xgmacRegion, 0x350 + xgmacPortOffset, bottom));
	NCR_CALL(ncr_write32(xgmacRegion, 0x354 + xgmacPortOffset, top));

	/* Enable stuff. */
	NCR_CALL(ncr_modify32(xgmacRegion, 0x300 + xgmacPortOffset, 0x8, 0x8));
	NCR_CALL(ncr_modify32(eioaRegion, 
                NCP_EIOA_GEN_CFG_REG_OFFSET(hwPortIndex) + 0x0, 
                0x00000003, 0x3));
	NCR_CALL(ncr_modify32(xgmacRegion, 0x300 + xgmacPortOffset, 0x4, 0x4));

	/* Unicast Filtering based on the Ethernet Address set above. */
	if (0 == rxtest && 0 == loopback)
		NCR_CALL(ncr_modify32(xgmacRegion, 0x330 + xgmacPortOffset,
				      0x3f, 0x09));

	return 0;

 ncp_return:

	return -1;
}
#endif /* #if 0 */

#if 0
/*
  ------------------------------------------------------------------------------
  line_renegotiate
*/

static int
line_renegotiate(int index)
{
	int rc;
	unsigned eioaRegion;
	unsigned gmacRegion;
	unsigned gmacPortOffset;
	char *envstring;
	unsigned short ad_value;
	unsigned short ge_ad_value;
	unsigned short control;
	struct mii_dev *bus;
	struct phy_device *phy_dev;

	bus = miiphy_get_dev_by_name("axxia-gmac1");
	phy_dev = phy_connect(bus, phy_by_index[index], dev, PHY_INTERFACE_MODE_RGMII);

	/* Set the region and offset. */
	if (4 > index) {
		eioaRegion = NCP_REGION_ID(31, 16); /* 0x1f.0x10 */
		gmacRegion = NCP_REGION_ID(31, 18); /* 0x1f.0x12 */
		gmacPortOffset = 0xc0 * index;
	} else {
		eioaRegion = NCP_REGION_ID(23, 16); /* 0x17.0x10 */
		gmacRegion = NCP_REGION_ID(23, 18); /* 0x17.0x12 */
		gmacPortOffset = 0xc0 * (index - 4);
	}

	/* Disable stuff. */
	NCR_CALL(ncr_modify32(gmacRegion, 0x330 + gmacPortOffset, 0x3f, 0));
	NCR_CALL(ncr_modify32(gmacRegion, 0x300 + gmacPortOffset, 0x8, 0x0));
	NCR_CALL(ncr_modify32(eioaRegion, 0x70, 0x11000000, 0x0));
	NCR_CALL(ncr_modify32(gmacRegion, 0x300 + gmacPortOffset, 0x4, 0x0));

	/* Check for "macspeed".  If set, ignore the PHYs... */
	envstring = getenv("macspeed");

	if (NULL == envstring) {
		/* Get ad_value and ge_ad_value from the environment. */
		envstring = getenv("ad_value");

		if (NULL == envstring) {
			ad_value = 0x1e1;
		} else {
			ad_value = simple_strtoul(envstring, NULL, 0);
		}

		envstring = getenv("ge_ad_value");

		if (NULL == envstring) {
			ge_ad_value = 0x300;
		} else {
			ge_ad_value = simple_strtoul(envstring, NULL, 0);
		}

		/* Set the AN advertise values. */
		phy_write(phy_dev, MDIO_DEVAD_NONE, 4, ad_value);
		phy_write(phy_dev, MDIO_DEVAD_NONE, 9, ge_ad_value);

		/* Force re-negotiation. */
		control = phy_read(phy_dev, MDIO_DEVAD_NONE, 0);
		control |= 0x200;
		phy_write(phy_dev, MDIO_DEVAD_NONE, 0, control);
	}

	return 0;

 ncp_return:

	return -1;
}

/*
  ------------------------------------------------------------------------------
  alloc_nvm
*/

static void *
alloc_nvm(int size)
{
#ifdef TRACE_ALLOCATION
	void *address;

	address = malloc(size);
	printf(" NVM_ALLOC: 0x%08x bytes at 0x%p\n", size, address);

	return address;
#else
	return malloc(size);
#endif
}

/*
  ------------------------------------------------------------------------------
  free_nvm
*/

static void
free_nvm(void *address)
{
	free(address);
#ifdef TRACE_ALLOCATION
	printf("  NVM_FREE: at 0x%p\n", address);
#endif
}

/*
  ------------------------------------------------------------------------------
  va2pa
*/

static ncp_uint32_t
va2pa(void *virtual_address)
{
	return (ncp_uint32_t)virtual_address;
}


#endif /*#if 0*/
