/*
 * Copyright (C) 2015 Intel
 *
 * Common definitions for Axxia.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __AXXIA_H
#define __AXXIA_H

#define CONFIG_AXXIA

#if defined(CONFIG_AXXIA_XLF_SIM) || \
  defined(CONFIG_AXXIA_XLF_EMU) || \
  defined(CONFIG_AXXIA_XLF)
#define CONFIG_AXXIA_ANY_XLF
#endif

#if defined(CONFIG_AXXIA_56XX_SIM) || \
  defined(CONFIG_AXXIA_56XX_EMU) || \
  defined(CONFIG_AXXIA_56XX)
#define CONFIG_AXXIA_ANY_56XX
#endif

#define CONFIG_AXXIA_SERIAL

/*
 */

#define CONFIG_LSI_NCR

#ifndef __ASSEMBLY__
void ncr_tracer_enable(void);
void ncr_tracer_disable(void);
int ncr_tracer_is_enabled(void);
void ncr_sysmem_init_mode_enable(void);
void ncr_sysmem_init_mode_disable(void);
#endif

/*
  ==============================================================================
  ==============================================================================
  Parameters
  ==============================================================================
  ==============================================================================
*/

#ifndef __ASSEMBLY__

#define PARAMETERS_MAGIC 0x12af34ec

#define PARAMETERS_GLOBAL_SET_VOLTAGE             0x00000001
#define PARAMETERS_GLOBAL_SET_CLOCKS              0x00000002
#define PARAMETERS_GLOBAL_SET_PEI                 0x00000004
#define PARAMETERS_GLOBAL_SET_SMEM                0x00000008
#define PARAMETERS_GLOBAL_SET_CMEM                0x00000010
#define PARAMETERS_GLOBAL_ENABLE_RETENTION        0x00000020
#define PARAMETERS_GLOBAL_ENABLE_SW_MEM_ECC_TEST  0x00400000
#define PARAMETERS_GLOBAL_ENABLE_SW_MEM_MTEST     0x00800000
#define PARAMETERS_GLOBAL_ENABLE_SW_MEM_ADDR_TEST 0x01000000
#define PARAMETERS_GLOBAL_ENABLE_SW_MEM_DATA_TEST 0x02000000
#define PARAMETERS_GLOBAL_DISABLE_RESET           0x10000000
#define PARAMETERS_GLOBAL_RUN_CMEM_BIST           0x20000000
#define PARAMETERS_GLOBAL_RUN_SMEM_RANGES         0x40000000
#define PARAMETERS_GLOBAL_RUN_SMEM_BIST           0x80000000

typedef void *                  ncp_dev_hdl_t;
typedef unsigned                ncp_region_id_t;


/*!
 * Returns the string equivalent of a specific status code.
 */
const char *ncp_status_get(
    ncp_st_t    st);            /*! Status code */


/*
 * enumerated type for the four 'standard' topologies
 * the values are assigned as a bit mask of which ranks
 * (chip selects) exist.
 */
/*
typedef enum {
	NCP_SM_TOPO_ONE_SINGLE_RANK = 0x1,
	NCP_SM_TOPO_ONE_DUAL_RANK   = 0x3,
	NCP_SM_TOPO_TWO_SINGLE_RANK = 0x5,
	NCP_SM_TOPO_TWO_DUAL_RANK   = 0xf
} ncp_sm_topology_t;
*/
/*
typedef enum {
	//
	  NCP_SM_SDRAM_DENSITY_256MBIT  = 0,
	//
	NCP_SM_SDRAM_DENSITY_512MBIT  = 1,
	NCP_SM_SDRAM_DENSITY_1GBIT    = 2,
	NCP_SM_SDRAM_DENSITY_2GBIT    = 3,
	NCP_SM_SDRAM_DENSITY_4GBIT    = 4,
	NCP_SM_SDRAM_DENSITY_8GBIT    = 5,
	NCP_SM_SDRAM_DENSITY_16GBIT   = 6
} ncp_sm_sdram_density_t;
*/

/*
typedef enum {
	NCP_SM_SDRAM_WIDTH_4BITS  = 0,
	NCP_SM_SDRAM_WIDTH_8BITS  = 1,
	NCP_SM_SDRAM_WIDTH_16BITS = 2,
	NCP_SM_SDRAM_WIDTH_32BITS = 3
} ncp_sm_sdram_width_t;
*/

/*
typedef enum {
	NCP_SM_PRIMARY_BUS_WIDTH_8BITS  = 0,
	NCP_SM_PRIMARY_BUS_WIDTH_16BITS = 1,
	NCP_SM_PRIMARY_BUS_WIDTH_32BITS = 2,
	NCP_SM_PRIMARY_BUS_WIDTH_64BITS = 3
} ncp_sm_primary_bus_width_t;
*/

/*
typedef struct __attribute__((packed)) {
	unsigned char sdram_rtt_nom[4];
	unsigned char sdram_rtt_wr[4];
	unsigned char sdram_data_drv_imp[4];
	unsigned long phy_min_cal_delay;
	unsigned long phy_adr_phase_select;
	unsigned long phy_dp_io_vref_set;
	unsigned long phy_adr_io_vref_set;
	unsigned long phy_rdlvl_cmp_even;
	unsigned long phy_rdlvl_cmp_odd;
	unsigned long phy_write_align_finetune;
} ncp_per_sysmem_parms_t;
*/

/*
typedef enum {
	NCP_SM_DDR3_MODE = 6,
	NCP_SM_DDR4_MODE = 10
} ncp_dram_class_t;

typedef enum {
	NCP_SM_REFRESH_MODE_1X = 0,
	NCP_SM_REFRESH_MODE_2X = 1,
	NCP_SM_REFRESH_MODE_4X = 2
} ncp_refresh_mode_t;
*/

extern ncp_uint32_t sm_nodes[];

#ifdef CONFIG_AXXIA_ARM

typedef struct {
	unsigned version;
	unsigned flags;
	unsigned baud_rate;
	unsigned memory_ranges[16];
	unsigned sequence;
	char description[128];
	unsigned bist_bit_masks[4];
} __attribute__((packed)) parameters_global_t;

#else  /* CONFIG_AXXIA_ARM */

typedef struct {
	unsigned version;
	unsigned flags;
} __attribute__((packed)) parameters_global_t;

#endif	/* CONFIG_AXXIA_ARM */

#ifdef CONFIG_AXXIA_ARM
typedef struct {
	unsigned version;
	unsigned char offsets[128];
} __attribute__((packed)) parameters_voltage_t;
#else
typedef struct {
	unsigned checksum;
	unsigned version;
	unsigned vofs;
	unsigned tvid;
	unsigned long long twait;
	unsigned VIDChecks;
	unsigned char vidLT[64];
} __attribute__((packed)) parameters_voltage_t;
#endif

typedef struct {
	unsigned version;
	unsigned flags;
	unsigned syspll_flags;
	unsigned syspll_div;
	unsigned syspll_frac;
	unsigned syspll_psd;
	unsigned cpupll_flags;
	unsigned cpupll_div;
	unsigned cpupll_frac;
	unsigned cpupll_psd;
	unsigned sm0pll_flags;
	unsigned sm0pll_div;
	unsigned sm0pll_frac;
	unsigned sm0pll_psd;
	unsigned sm1pll_flags;
	unsigned sm1pll_div;
	unsigned sm1pll_frac;
	unsigned sm1pll_psd;
#ifdef CONFIG_AXXIA_ANY_XLF
	unsigned sm2pll_flags;
	unsigned sm2pll_div;
	unsigned sm2pll_frac;
	unsigned sm2pll_psd;
	unsigned sm3pll_flags;
	unsigned sm3pll_div;
	unsigned sm3pll_frac;
	unsigned sm3pll_psd;
#endif
	unsigned tm0pll_flags;
	unsigned tm0pll_div;
	unsigned tm0pll_frac;
	unsigned tm0pll_psd;
	unsigned fabpll_flags;
	unsigned fabpll_div;
	unsigned fabpll_frac;
	unsigned fabpll_psd;
#ifdef CONFIG_AXXIA_ANY_56XX
	unsigned nrcp0pll_flags;
	unsigned nrcp0pll_div;
	unsigned nrcp0pll_frac;
	unsigned nrcp0pll_psd;
#endif
#ifdef CONFIG_AXXIA_ANY_XLF
	unsigned dsppll_flags;
	unsigned dsppll_div;
	unsigned dsppll_frac;
	unsigned dsppll_psd;
#endif
	unsigned cpu_csw;
#ifdef CONFIG_AXXIA_ANY_XLF
	unsigned dsp_csw;
#endif
	unsigned sys_csw;
} __attribute__ ((packed)) parameters_clocks_t;

typedef struct {
	unsigned version;
	unsigned control;
	/*
	  The following are only available when version = 2.
	*/
	unsigned primary_input_clock;
	unsigned input_ref_clock_range;
	unsigned lane_0_eq_main;
	unsigned lane_0_eq_pre;
	unsigned lane_0_eq_post;
	unsigned lane_0_vboost;
	unsigned lane_1_eq_main;
	unsigned lane_1_eq_pre;
	unsigned lane_1_eq_post;
	unsigned lane_1_vboost;
} __attribute__((packed)) parameters_pciesrio_t;

/* RWXXX duplicated */
/* typedef unsigned ncp_uint32_t;
typedef void *   ncp_dev_hdl_t;
typedef unsigned ncp_region_id_t;
*/

typedef struct {
	unsigned char sdram_rtt_nom[4];
	unsigned char sdram_rtt_wr[4];
	unsigned char sdram_data_drv_imp[4];
	unsigned phy_min_cal_delay;
	unsigned phy_adr_phase_select;
	unsigned phy_dp_io_vref_set;
	unsigned phy_adr_io_vref_set;
	unsigned phy_rdlvl_cmp_even;
	unsigned phy_rdlvl_cmp_odd;
	unsigned phy_write_align_finetune;
} __attribute__((packed)) per_sysmem_parms_t;

typedef struct {
	unsigned char sdram_rtt_nom[4];
	unsigned char sdram_rtt_wr[4];
	unsigned char sdram_data_drv_imp[4];
	unsigned char sdram_rtt_park[4];
	unsigned char dq_map_0[18];
 	unsigned char unused_0[2];
	unsigned char dq_map_1[18];
 	unsigned char unused_1[2];
	ncp_uint32_t dq_map_odd_rank_swap_0;
	ncp_uint32_t dq_map_odd_rank_swap_1;
} __attribute__((packed)) per_sysmem_sdram_parms_t;

typedef struct {
	ncp_uint32_t version;
	ncp_uint32_t ddrClockSpeedMHz;
	ncp_uint32_t autoDetect;
	ncp_uint32_t num_interfaces;
	ncp_uint32_t num_ranks_per_interface;
	ncp_uint32_t primary_bus_width;
	ncp_uint32_t topology;
	ncp_uint32_t minCtrlRoundtripDelay;
	ncp_uint32_t phy_rdlat;
	ncp_uint32_t addedRankSwitchDly;
	ncp_uint32_t zqcs_interval;
	ncp_uint32_t enableECC;
	ncp_uint32_t enableRuntime;
	ncp_uint32_t dramPrechargePolicy;
	ncp_uint32_t open_page_size;
	ncp_uint32_t syscacheControl;
	ncp_uint32_t sdram_device_density;
	ncp_uint32_t sdram_device_width;
	ncp_uint32_t CAS_latency;
	ncp_uint32_t CAS_write_latency;
	ncp_uint32_t address_mirroring;
	ncp_uint32_t registeredDimm;
	ncp_uint32_t rdimm_ctl_0_0;
	ncp_uint32_t rdimm_ctl_0_1;
	ncp_uint32_t rdimm_misc;
	ncp_uint32_t write_ODT_ctl;
	ncp_uint32_t read_ODT_ctl;
	ncp_uint32_t singleBitMPR;
	ncp_uint32_t high_temp_dram;
	per_sysmem_parms_t per_sysmem[2];
	ncp_uint32_t dram_class;
	ncp_uint32_t additive_latency;
	ncp_uint32_t binned_CAS_latency;
	ncp_uint32_t tck_ps;
	ncp_uint32_t refresh_mode;
	ncp_uint32_t address_inversion;
	ncp_uint32_t bstlen;
	ncp_uint32_t dm_masking;
	ncp_uint32_t rdimm_ctl_0_2;
	ncp_uint32_t rdimm_ctl_0_3;
	ncp_uint32_t rdimm_ctl_0_4;
	ncp_uint32_t rdimm_ctl_1_0;
	ncp_uint32_t rdimm_ctl_1_1;
	ncp_uint32_t rdimm_ctl_1_2;
	ncp_uint32_t rdimm_ctl_1_3;
	ncp_uint32_t rdimm_ctl_1_4;
	ncp_uint32_t vref_cs;
	ncp_uint32_t vref_val;
	ncp_uint32_t wr_protect_en_mask;
	ncp_uint32_t dbi_rd_en;
	ncp_uint32_t dbi_wr_en;
	ncp_uint32_t ca_parity_en;  
	ncp_uint32_t rdlvl_interval;	
	ncp_uint32_t rdlvl_gate_interval;
	ncp_uint32_t preamble_support;
	ncp_uint32_t crc_mode;
	per_sysmem_sdram_parms_t per_smem[4];
	ncp_uint32_t packedDqDmDqsODT;
	ncp_uint32_t packedAddrCmdCtrlOI;
	ncp_uint32_t packedClockOI;
	ncp_uint32_t packedDqDmDqsOI;
	ncp_uint32_t packedAddrCmdCtrlClkSlewRates;
	ncp_uint32_t packedDqDmDqsSlewRates;
	ncp_uint32_t packedPHYTrainingOptions;
	ncp_uint32_t interface_sel;
	/* This is the ncp_l3lock_region_info_t structure from the RTE. */
	ncp_uint32_t total_l3_locked_size;
	ncp_uint32_t region[4];
	/* Only used in U-Boot, not part of the RTE structure. */
	unsigned long long totalSize;
} __attribute__((packed)) parameters_mem_t;

typedef parameters_mem_t ncp_sm_parms_t;

#ifdef CONFIG_AXXIA_ARM
typedef struct {
	unsigned magic;
	unsigned size;
	unsigned checksum;
	unsigned version;
	unsigned chipType;
	unsigned globalOffset;
	unsigned globalSize;
	unsigned pciesrioOffset;
	unsigned pciesrioSize;
	unsigned voltageOffset;
	unsigned voltageSize;
	unsigned clocksOffset;
	unsigned clocksSize;
	unsigned systemMemoryOffset;
	unsigned systemMemorySize;
	unsigned classifierMemoryOffset;
	unsigned classifierMemorySize;
	unsigned systemMemoryRetentionOffset;
	unsigned systemMemoryRetentionSize;
} __attribute__((packed)) parameters_header_t;
#else  /* CONFIG_AXXIA_ARM */
typedef struct {
	unsigned sysmemSize;
	unsigned sysmemOffset;
	unsigned clocksSize;
	unsigned clocksOffset;
	unsigned voltageSize;
	unsigned voltageOffset;
	unsigned pciesrioSize;
	unsigned pciesrioOffset;
	unsigned globalSize;
	unsigned globalOffset;
	unsigned version;
	unsigned checksum;
	unsigned size;
	unsigned magic;
} __attribute__((packed)) parameters_header_t;
#endif	/* CONFIG_AXXIA_ARM */

typedef struct {
	parameters_header_t *header;
	parameters_global_t *global;
	parameters_voltage_t *voltage;
	parameters_clocks_t *clocks;
	parameters_pciesrio_t *pciesrio;
	parameters_mem_t *sysmem;
	parameters_mem_t *cmem;
} parameters_t;

extern parameters_header_t *header;
extern parameters_global_t *global;
extern parameters_pciesrio_t *pciesrio;
extern parameters_voltage_t *voltage;
extern parameters_clocks_t *clocks;
extern parameters_mem_t *sysmem;
extern parameters_mem_t *cmem;
#ifdef CONFIG_AXXIA_ARM
extern void *retention;
#endif

int read_parameters(void);
int write_parameters(void);

#ifndef CONFIG_SPL_BUILD
#define CONFIG_CMD_LSI_PARAMETERS
#endif

#endif	/* __ASSEMBLY__ */

/*
  ==============================================================================
  ==============================================================================
  Networking
  ==============================================================================
  ==============================================================================
*/

#ifndef CONFIG_SPL_BUILD

#if defined(CONFIG_AXXIA_FEMAC) || defined(CONFIG_AXXIA_EIOA) || defined(CONFIG_AXXIA_NEMAC)
#define CONFIG_AXXIA_NET
#define CONFIG_AXXIA_MDIO
#define CONFIG_CMD_NET
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_PING
#define CONFIG_CMD_MII
#define CONFIG_PHYLIB
#define CONFIG_MII
#define CONFIG_PHY_BROADCOM
#define CONFIG_PHY_DAVICOM
#define CONFIG_PHY_MICREL
#define CONFIG_PHY_VITESSE
#endif

#define MDIO_CONTROL_RD_DATA (0x0)
#define MDIO_STATUS_RD_DATA  (0x4)
#define MDIO_CLK_OFFSET      (0x8)
#define MDIO_CLK_PERIOD      (0xc)

#ifndef MDIO_CLK_OFFSET_DEFAULT
#ifdef CONFIG_AXXIA_EMU
/*#define MDIO_CLK_OFFSET_DEFAULT 0x10*/
#define MDIO_CLK_OFFSET_DEFAULT 0x5
#else
#define MDIO_CLK_OFFSET_DEFAULT 0x1c
#endif
#endif

#ifndef MDIO_CLK_PERIOD_DEFAULT
#ifdef CONFIG_AXXIA_EMU
/*#define MDIO_CLK_PERIOD_DEFAULT 0x2c*/
#define MDIO_CLK_PERIOD_DEFAULT 0xc
#else
#define MDIO_CLK_PERIOD_DEFAULT 0xf0
#endif
#endif

#ifndef __ASSEMBLY__
int mdio_initialize(void);
unsigned short mdio_read(int phy, int reg);
void mdio_write(int phy, int reg, unsigned short value);
#endif

#endif	/* CONFIG_SPL_BUILD */

/*
  ==============================================================================
  ==============================================================================
  SSP Access
  ==============================================================================
  ==============================================================================
*/

#define SSP_CR0       0x000
#define SSP_CR1       0x004
#define SSP_DR        0x008
#define SSP_SR        0x00c
#define SSP_CPSR      0x010
#define SSP_IMSC      0x014
#define SSP_RIS       0x018
#define SSP_MIS       0x01c
#define SSP_ICR       0x020
#define SSP_DMACR     0x024
#define SSP_CSR       0x030
#define SSP_PERIPHID0 0xfe0
#define SSP_PERIPHID1 0xfe4
#define SSP_PERIPHID2 0xfe8
#define SSP_PERIPHID3 0xfec
#define SSP_PCELLID0  0xff0
#define SSP_PCELLID1  0xff4
#define SSP_PCELLID2  0xff8
#define SSP_PCELLID3  0xffc

#define SSP_MAXIMUM_CLOCK 25000000

#ifndef __ASSEMBLY__
int ssp_read(void *, unsigned, unsigned);
int ssp_set_speed(unsigned *);
int ssp_init(int);
#endif

/*
  ==============================================================================
  ==============================================================================
  Clocks
  ==============================================================================
  ==============================================================================
*/

#ifndef __ASSEMBLY__

#define CLK_REF0 125000000

typedef enum {
	clock_system, clock_core, clock_memory, clock_peripheral,
	clock_fab, clock_treemem, clock_emmc, clock_dsp
} acp_clock_t;

int acp_clock_get(acp_clock_t, ncp_uint32_t *);

unsigned int spi_get_per_clk(void);

#endif /* __ASSEMBLY__ */

/*
  ==============================================================================
  ==============================================================================
  System Memory
  ==============================================================================
  ==============================================================================
*/

#ifndef __ASSEMBLY__
int sysmem_reset(void);
unsigned long long sysmem_size(void);
unsigned long long cmem_size(void);
#endif

/*
  ==============================================================================
  ==============================================================================
  Special Test
  ==============================================================================
  ==============================================================================
*/

#define CONFIG_SYS_ALT_MEMTEST

#define CONFIG_SPL_MTEST
/*#define SM_PLL_533_MHZ*/
/*#define RUN_UNCACHED*/
/*#define RUN_NONSECURE*/
/*#define SINGLE_SMEM_MODE*/
/*#define DISPLAY_PARAMETERS*/

#define CONFIG_LSI
#define UBOOT

#define CONFIG_CMD_NCR

/*
  ==============================================================================
  ==============================================================================
  Version
  ==============================================================================
  ==============================================================================
*/

#ifndef __ASSEMBLY__
const char *get_lsi_version(void);
#endif /* __ASSEMBLY__ */

/*
  ==============================================================================
  ==============================================================================
  Nuevo Conf Ring Access (see board/lsi/common/ncr.c for the implementation)
  ==============================================================================
  ==============================================================================
*/

#ifndef __ASSEMBLY__

#define NCP_NODE_MASK             (0xFFFF)
#define NCP_TARGET_MASK           (0xFFFF)

#define NCP_MAX_NODE              (0xFFFF)
#define NCP_MAX_TARGET            (0xFFFF)
#define NCP_CFG_NODE_TARGET       (0xFF)

#define NCP_MAX_CONFIG_RING_NODE  (0xFF)

#define NCP_NODE_ID(regionId)    (((regionId) >> 16) & NCP_NODE_MASK)
#define NCP_TARGET_ID(regionId)  ((regionId) & NCP_TARGET_MASK)

#define NCP_REGION_ID(node, target) \
    ((ncp_region_id_t) \
     ((((node) & NCP_NODE_MASK) << 16) | ((target) & NCP_TARGET_MASK)))

#define NCP_REGION_DRIVER_CFG              (NCP_REGION_ID(0x301,  0))

int ncr_read(ncp_uint32_t, ncp_uint32_t, ncp_uint32_t, int, void *);
int ncr_read8( ncp_uint32_t, ncp_uint32_t, unsigned char * );
int ncr_read16( ncp_uint32_t, ncp_uint32_t, unsigned short * );
int ncr_read32( ncp_uint32_t, ncp_uint32_t, ncp_uint32_t * );
int ncr_write(ncp_uint32_t, ncp_uint32_t, ncp_uint32_t, int, void *);
int ncr_write8( ncp_uint32_t, ncp_uint32_t, unsigned char );
int ncr_write16( ncp_uint32_t, ncp_uint32_t, unsigned short );
int ncr_write32( ncp_uint32_t, ncp_uint32_t, ncp_uint32_t );
int ncr_modify32( ncp_uint32_t, ncp_uint32_t, ncp_uint32_t, ncp_uint32_t );
int ncr_and( ncp_uint32_t, ncp_uint32_t, ncp_uint32_t );
int ncr_or( ncp_uint32_t, ncp_uint32_t, ncp_uint32_t );
int ncr_poll( ncp_uint32_t, ncp_uint32_t, ncp_uint32_t,
              ncp_uint32_t, ncp_uint32_t, ncp_uint32_t );
void ncr_tracer_enable( void );
void ncr_tracer_disable( void );
int ncr_tracer_is_enabled( void );
void ncr_enable( void );
void ncr_disable( void );
#endif

/*
  ==============================================================================
  ==============================================================================
  Watchdog
  ==============================================================================
  ==============================================================================
*/

#define WATCHDOG_TIMEOUT_SECS 16
#ifndef CONFIG_TARGET_EMULATION
/*#define CONFIG_HW_WATCHDOG*/
#endif
/*#define LEAVE_WATCHDOG_ON*/
/*#define MAKE_WATCHDOG_PERMANENT*/
/*#define WATCHDOG_RESET_SYSTEM*/

#ifndef __ASSEMBLY__
int start_watchdog(unsigned int);
void stop_watchdog(void);
int get_watchdog_timeout(void);
unsigned int set_watchdog_timeout(unsigned int);
#endif

/*
  ==============================================================================
  ==============================================================================
  Pre-Watchdog and ATF Datalogger #defines
  ==============================================================================
  ==============================================================================
*/

/* Must be defined if ATF datalogger functionality is enabled */
#define CONFIG_ATF_DATALOGGER

#if defined(CONFIG_ATF_DATALOGGER)
/* Number of secs prewatchdog timeout is less than watchdog timeout */
#define PRE_WATCHDOG_DIFF  1
#define PRE_WATCHDOG_TIMEOUT_SECS (WATCHDOG_TIMEOUT_SECS - PRE_WATCHDOG_DIFF)

/*
  If prewatchdog timeout is 0 or >= watchdog timer, stop compilation
   (Prewatchdog time must always be less than watchdog time.
*/
#if PRE_WATCHDOG_TIMEOUT_SECS == 0
#error "PRE_WATCHDOG_TIMEOUT_SECS is zero !"
#endif

#if PRE_WATCHDOG_TIMEOUT_SECS > PRE_WATCHDOG_TIMEOUT_SECS
#error "PRE_WATCHDOG_TIMEOUT_SECS is greater than WATCHDOG_TIMEOUT_SECS!"
#endif

#endif  /* CONFIG_ATF_DATALOGGER */

/*
  ==============================================================================
  ==============================================================================
  USB
  ==============================================================================
  ==============================================================================
*/

#if defined(CONFIG_AXXIA_USB0) || defined(CONFIG_AXXIA_USB1)
#define CONFIG_USB_XHCI_AXXIA
#define CONFIG_CMD_USB 1
#define CONFIG_USB_XHCI 1
#define CONFIG_SYS_USB_XHCI_MAX_ROOT_PORTS 4
#define CONFIG_USB_STORAGE 1
#define CONFIG_CMD_USB_STORAGE 1
#define CONFIG_CMD_EXT2 1
#define CONFIG_CMD_EXT4 1
#define CONFIG_DOS_PARTITION 1

/* Work Around Values */

#define SSP_LANE0_ANA_RX_SCOPE_VDCC_VALUE 1
#define COMPDISTUNE0_VALUE                4
#define OTGTUNE0_VALUE                    4
#define SQRXTUNE0_VALUE                   3
#define TXFSLSTUNE0_VALUE                 3
#define TXHSXVTUNE0_VALUE                 3
#define TXPREEMPAMPTUNE0_VALUE            0
#define TXPREEMPPULSETUNE0_VALUE          0
#define TXRESTUNE0_VALUE                  1
#define TXRISETUNE0_VALUE                 2
#define TXVREFTUNE0_VALUE                 8
#define PCSRXLOSMASK_VALUE                0x3e8
#define PCSTXDEEMPH3P4DB_VALUE            0x16
#define PCSTXDEEMPH6DB_VALUE              0x16
#define PCSTXSWINGFULL_VALUE              0x7a
#define TXVBOOSTLVL_VALUE                 4

/* Work Around Offsets */

#define SSP_LANE0_ANA_RX_SCOPE_VDCC 0x04098
#define COMPDISTUNE0                0x40000
#define OTGTUNE0                    0x40004
#define SQRXTUNE0                   0x40008
#define TXFSLSTUNE0                 0x4000c
#define TXHSXVTUNE0                 0x40010
#define TXPREEMPAMPTUNE0            0x40014
#define TXPREEMPPULSETUNE0          0x40018
#define TXRESTUNE0                  0x4001c
#define TXRISETUNE0                 0x40020
#define TXVREFTUNE0                 0x40024
#define PCSRXLOSMASK                0x40038
#define PCSTXDEEMPH3P4DB            0x4003c
#define PCSTXDEEMPH6DB              0x40040
#define PCSTXSWINGFULL              0x40044
#define TXVBOOSTLVL                 0x40048

#define AXXIA_USB0_BASE (AXI2SER6 + 0)
#define AXXIA_USB1_BASE (AXI2SER6 + 0x80000)

#endif

/*#define DISABLE_USB3*/

/*
  ==============================================================================
  ==============================================================================
  Errata
  ==============================================================================
  ==============================================================================
*/

/*
  U-Boot will only use this much memory when relocating, loading
  images, etc.  The device tree will be updated with the actual size
  of system memory.
*/

#ifdef SYSCACHE_ONLY_MODE
#define CONFIG_UBOOT_MAX_MEM ((phys_size_t) SYSCACHE_SIZE)
#else
#define CONFIG_UBOOT_MAX_MEM ((phys_size_t)1 << 30)
#endif

/*
  Define the following to add a hook to the SPL that allows diagnostic
  code to be run after initializing system memory but before using it.
  Tests can be created in board/axxia/common/spl_diagnostics.c.
*/

/*#define CONFIG_AXXIA_SPL_DIAGNOSTICS*/

#ifndef __ASSEMBLY__
enum bist_type {addr, data};
int axxia_sysmem_check_ecc(void);
int axxia_sysmem_bist(unsigned long long address, unsigned long long length,
		      enum bist_type type);
int axxia_cmem_bist(unsigned long long address, unsigned long long length,
		      enum bist_type type);
int setup_security(void);
int voltage_init(void);
void spl_diagnostics(void);
#endif

#ifndef __ASSEMBLY__
int gpdma_reset(void);
int gpdma_xfer(void *, void *, size_t, int);
#endif	/* __ASSEMBLY__ */

#ifndef __ASSEMBLY__
void __asm_disable_l3_cache(void);
void __asm_enable_l3_cache(void);
#endif	/* __ASSEMBLY__ */

#ifndef __ASSEMBLY__
int handle_cmem_mpr(int, int);
int handle_smem_mpr(int, int);
#endif	/* __ASSEMBLY__ */

#ifndef __ASSEMBLY__
unsigned int calc_chip_vrun(void);
int set_vrm_to_vrun(unsigned int);
int voltage_init(void);
#endif	/* __ASSEMBLY__ */


/* RWXXX copied from RTE  */

typedef int (*ncp_read_fn_t) (
    void *arg,
    void *buf,
    int   len);

/* RWXXX copied end */


#endif /* __AXXIA_H */
