/**************************************************************************
 ** INTEL CONFIDENTIAL
 ** Copyright 2008 - 2015 Intel Corporation All Rights Reserved.
 **
 ** The source code contained or described herein and all documents related to 
 ** the source code ("Material") are owned by Intel Corporation or its 
 ** suppliers or licensors. Title to the Material remains with 
 ** Intel Corporation or its suppliers and licensors. 
 ** The Material contains trade secrets and proprietary and confidential
 ** information of Intel or its suppliers and licensors. The Material is 
 ** protected by worldwide copyright and trade secret laws and treaty 
 ** provisions. No part of the Material may be used, copied, reproduced, 
 ** modified, published, uploaded, posted, transmitted, distributed, or 
 ** disclosed in any way without Intel's prior express written permission.
 **
 ** No license under any patent, copyright, trade secret or other 
 ** intellectual property right is granted to or conferred upon you by 
 ** disclosure or delivery of the Materials, either expressly, by implication, 
 ** inducement, estoppel or otherwise. Any license under such intellectual 
 ** property rights must be express and approved by Intel in writing.
 *************************************************************************/
#include <linux/string.h>

#include "uboot/ncp_sal_types_linux.h"
#include "uboot/ncp_status.h"
#include "uboot/axxia.h"
#include "uboot/ncp_task_basetypes.h"

#include "uboot/ncp.h"
#include "uboot/ncp_pvt.h"

#define NCP_RELEASE_VARIABLES

/* --- Exportable State Data --- */
ncp_hdl_t **ncp_hdls = NULL;
ncp_dev_hdl_t ncp_dev_hdls[NCP_MAX_DEVS] =
{
  (ncp_dev_hdl_t)-1
};

ncp_uint8_t ncp_dev_hdl_users[NCP_MAX_DEVS] = {0};

void *ncpHwioTraceFuncArg = NULL;
ncp_hwio_trace_func_t ncpHwioTraceFunc = NULL;

ncp_uint32_t sc_nodes[NCP_SYSCACHE_NUM_NODES] = 
                    {0x20, 0x1e, 0x21, 0x1d, 0x11, 0x12, 0x10, 0x13};
ncp_uint32_t sm_nodes[NCP_EXTMEM_NUM_NODES] = {0x22, 0x0f, 0x08, 0x09};

ncp_bool_t ncp_dev_initialized = FALSE;

/* --- Published Functions --- */

/*
 * ncp_cold_start
 *
 *   Re-initialize the ncp_hdls pointer and NVM allocator.
 *   Note that this will wipe out EVERYTHING stored in NVM.
 */
ncp_st_t 
ncp_cold_start(void)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_TRACEPOINT (Intel_AXXIA_ncp_common, ncp_cold_start_entry, NCP_MSG_ENTRY, " ");

    /* clear ncp_hdls */
    ncp_hdls = NULL;

    /* initialize NVM */
    if (ncp_nvm_init(TRUE) < 0)
    {
        NCP_CALL(NCP_ST_NVM_ERROR);
    }

    ncp_dev_initialized = FALSE;

NCP_RETURN_LABEL
    NCP_TRACEPOINT (Intel_AXXIA_ncp_common, ncp_cold_start_exit, NCP_MSG_EXIT,
                "ncpStatus=%d\n", ncpStatus);
    return ncpStatus;
}

/* --- Internal Functions --- */

/*
 * temporory "not yet" functions
 *
 */
void
ncp_hw_not_yet(const char *s)
{
    //printf("no hw mod for: %s\n",s);
}

void
ncp_stub_not_yet(const char *s)
{
    //printf("no api or hw mod for %s\n",s);
}


/*
 * ncp_comment
 */
void
ncp_comment(
    const char *msg)
{
    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    if (msg != NULL) {
        tracepoint(Intel_AXXIA_ncp_custom,
                   ncp_custom_hwio_comment,
                   NCP_HWIO_COMMENT,
                   msg
                  );
    }
#endif

    if ((ncpHwioTraceFunc != NULL) && (msg != NULL)) {
        ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_COMMENT,
                0,
                (void *)msg);
    }
}


/*
 * ncp_usleep
 */
int
ncp_usleep(
    unsigned long usecs)
{
    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    tracepoint(Intel_AXXIA_ncp_custom,
               ncp_custom_hwio_generic,
               NCP_HWIO_USLEEP,
               0,
               usecs
              );
#endif

    if (ncpHwioTraceFunc != NULL) {
        ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_USLEEP,
                0,
                (void *)usecs);
    }

    return ncp_sys_usleep(usecs);
}


#if 0 
this is implemented in uboot
/*
 * ncp_reset
 */
ncp_st_t
ncp_reset(
    ncp_dev_hdl_t devHdl)
{
    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_generic,
                       NCP_HWIO_RESET,
                       devNum,
                       0
                       );
        }
    }
#endif

    if (ncpHwioTraceFunc != NULL) {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_RESET,
                devNum,
                NULL);
        }
    }

    return ncp_dev_reset(devHdl);
}
#endif

/*
 * ncp_read8
 *
 *   Read a 8-bit value from NCP device space.
 */
ncp_st_t
ncp_read8(
    ncp_dev_hdl_t devHdl,
    ncp_region_id_t regionId,       /* IN: Node/target address */
    ncp_uint64_t offset,            /* IN: Node/target offset */
    ncp_uint8_t *value)             /* OUT: Pointer to read data buffer */
{
    ncp_st_t ncpStatus;

    /* Write to NCP device space */
    ncpStatus = ncp_dev_read8(
            devHdl,
            regionId,
            offset,
            value);

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_rw,
                       NCP_HWIO_READ8,
                       devNum,
                       regionId,
                       offset,
                       (ncp_uint8_t *) value,
                       sizeof(ncp_uint8_t),
                       1, /* count */
                       0,
                       0 /* flags */
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {

             rw.regionId = regionId;
             rw.offset = offset;
             rw.buffer = (ncp_uint32_t *) value;
             rw.count = 1;
             rw.flags = 0;
             ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_READ8,
                devNum,
                &rw);
        }
    }

    return ncpStatus;
}

/*
 * ncp_read16
 *
 *   Read a 16-bit value from NCP device space.
 */
ncp_st_t
ncp_read16(
    ncp_dev_hdl_t devHdl,
    ncp_region_id_t regionId,        /* IN: Node/target address */
    ncp_uint64_t offset,             /* IN: Node/target offset */
    ncp_uint16_t *value)             /* OUT: Pointer to read data buffer */
{
    ncp_st_t ncpStatus;

    /* Write to NCP device space */
    ncpStatus = ncp_dev_read16(
            devHdl,
            regionId,
            offset,
            value);

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_rw,
                       NCP_HWIO_READ16,
                       devNum,
                       regionId,
                       offset,
                       (ncp_uint8_t *) value,
                       sizeof(ncp_uint16_t),
                       1, /* count */
                       0,
                       0 /* flags */
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {

             rw.regionId = regionId;
             rw.offset = offset;
             rw.buffer = (ncp_uint32_t *) value;
             rw.count = 1;
             rw.flags = 0;
             ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_READ16,
                devNum,
                &rw);
        }
    }

    return ncpStatus;
}

/*
 * ncp_read32
 *
 *   Read a 32-bit value from NCP device space.
 */
ncp_st_t
ncp_read32(
    ncp_dev_hdl_t devHdl,
    ncp_region_id_t regionId,        /* IN: Node/target address */
    ncp_uint64_t offset,             /* IN: Node/target offset */
    ncp_uint32_t *value)             /* OUT: Pointer to read data buffer */
{
    ncp_st_t ncpStatus;
    /* Write to NCP device space */
    ncpStatus = ncp_dev_read32(
            devHdl,
            regionId,
            offset,
            value);

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_rw,
                       NCP_HWIO_READ32,
                       devNum,
                       regionId,
                       offset,
                       (ncp_uint8_t *) value,
                       sizeof(ncp_uint32_t),
                       1, /* count */
                       0,
                       0 /* flags */
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {

             rw.regionId = regionId;
             rw.offset = offset;
             rw.buffer = value;
             rw.count = 1;
             rw.flags = 0;
             ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_READ32,
                devNum,
                &rw);
        }
    }

    return ncpStatus;
}

/*
 * ncp_read64
 *
 *   Read a 64-bit value from NCP device space.
 */
ncp_st_t
ncp_read64(
    ncp_dev_hdl_t devHdl,
    ncp_region_id_t regionId,        /* IN: Node/target address */
    ncp_uint64_t offset,             /* IN: Node/target offset */
    ncp_uint64_t *value)             /* OUT: Pointer to read data buffer */
{
    ncp_st_t ncpStatus;

    /* Write to NCP device space */
    ncpStatus = ncp_dev_read64(
            devHdl,
            regionId,
            offset,
            value);

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_rw,
                       NCP_HWIO_READ64,
                       devNum,
                       regionId,
                       offset,
                       (ncp_uint8_t *) value,
                       sizeof(ncp_uint64_t),
                       1, /* count */
                       0,
                       0 /* flags */
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {

             rw.regionId = regionId;
             rw.offset = offset;
             rw.buffer = (ncp_uint32_t *) value;
             rw.count = 1;
             rw.flags = 0;
             ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_READ64,
                devNum,
                &rw);
        }
    }

    return ncpStatus;
}

/*
 * ncp_block_read8
 *
 *   Read 8-bit values from NCP device space.
 */
ncp_st_t
ncp_block_read8(
    ncp_dev_hdl_t devHdl,
    ncp_region_id_t regionId,       /* IN: Node/target address */
    ncp_uint64_t offset,            /* IN: Node/target offset */
    ncp_uint8_t *buffer,            /* IN: Pointer to read data */
    ncp_uint32_t count,             /* IN: Number of 8-bit values to write */
    ncp_uint32_t flags)             /* IN: I/O flags */
{
    ncp_st_t ncpStatus;

    /* Read from NCP device space */
    ncpStatus = ncp_dev_block_read8(
            devHdl,
            regionId,
            offset,
            buffer,
            count,
            flags);

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_rw,
                       NCP_HWIO_READ8,
                       devNum,
                       regionId,
                       offset,
                       (ncp_uint8_t *) buffer,
                       count * sizeof(ncp_uint8_t),
                       count,
                       0,
                       flags
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {

            rw.regionId = regionId;
            rw.offset = offset;
            rw.buffer = (ncp_uint32_t *) buffer;
            rw.count = count;
            rw.flags = flags;
            ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_READ8,
                devNum,
                &rw);
        }
    }

    return ncpStatus;
}

/*
 * ncp_block_read16
 *
 *   Read 16-bit values from NCP device space.
 */
ncp_st_t
ncp_block_read16(
    ncp_dev_hdl_t devHdl,
    ncp_region_id_t regionId,        /* IN: Node/target address */
    ncp_uint64_t offset,             /* IN: Node/target offset */
    ncp_uint16_t *buffer,            /* IN: Pointer to read data */
    ncp_uint32_t count,              /* IN: Number of 16-bit words to write */
    ncp_uint32_t flags)              /* IN: I/O flags */
{
    ncp_st_t ncpStatus;

    /* Read from NCP device space */
    ncpStatus = ncp_dev_block_read16(
            devHdl,
            regionId,
            offset,
            buffer,
            count,
            flags);

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_rw,
                       NCP_HWIO_READ16,
                       devNum,
                       regionId,
                       offset,
                       (ncp_uint8_t *) buffer,
                       count * sizeof(ncp_uint16_t),
                       count,
                       0,
                       flags
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {

            rw.regionId = regionId;
            rw.offset = offset;
            rw.buffer = (ncp_uint32_t *) buffer;
            rw.count = count;
            rw.flags = flags;
            ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_READ16,
                devNum,
                &rw);
        }
    }

    return ncpStatus;
}

/*
 * ncp_block_read32
 *
 *   Read 32-bit values from NCP device space.
 */
ncp_st_t
ncp_block_read32(
    ncp_dev_hdl_t devHdl,
    ncp_region_id_t regionId,    /* IN: Node/target address */
    ncp_uint64_t offset,             /* IN: Node/target offset */
    ncp_uint32_t *buffer,            /* IN: Pointer to read data */
    ncp_uint32_t count,              /* IN: Number of 32-bit words to write */
    ncp_uint32_t flags)              /* IN: I/O flags */
{
    ncp_st_t ncpStatus;

    /* Read from NCP device space */
    ncpStatus = ncp_dev_block_read32(
            devHdl,
            regionId,
            offset,
            buffer,
            count,
            flags);

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_rw,
                       NCP_HWIO_READ32,
                       devNum,
                       regionId,
                       offset,
                       (ncp_uint8_t *) buffer,
                       count * sizeof(ncp_uint32_t),
                       count,
                       0,
                       flags
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {

            rw.regionId = regionId;
            rw.offset = offset;
            rw.buffer = buffer;
            rw.count = count;
            rw.flags = flags;
            ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_READ32,
                devNum,
                &rw);
        }
    }

    return ncpStatus;
}

/*
 * ncp_block_read64
 *
 *   Read 64-bit values from NCP device space.
 */
ncp_st_t
ncp_block_read64(
    ncp_dev_hdl_t devHdl,
    ncp_region_id_t regionId,    /* IN: Node/target address */
    ncp_uint64_t offset,             /* IN: Node/target offset */
    ncp_uint64_t *buffer,            /* IN: Pointer to read data */
    ncp_uint32_t count,              /* IN: Number of 64-bit words to write */
    ncp_uint32_t flags)              /* IN: I/O flags */
{
    ncp_st_t ncpStatus;

    /* Read from NCP device space */
    ncpStatus = ncp_dev_block_read64(
            devHdl,
            regionId,
            offset,
            buffer,
            count,
            flags);

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_rw,
                       NCP_HWIO_READ64,
                       devNum,
                       regionId,
                       offset,
                       (ncp_uint8_t *) buffer,
                       count * sizeof(ncp_uint64_t),
                       count,
                       0,
                       flags
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {

            rw.regionId = regionId;
            rw.offset = offset;
            rw.buffer = (ncp_uint32_t *) buffer;
            rw.count = count;
            rw.flags = flags;
            ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_READ64,
                devNum,
                &rw);
        }
    }

    return ncpStatus;
}


/*
 * ncp_write8
 *
 *   Write a 8-bit value to NCP device space.
 */
ncp_st_t
ncp_write8(
    ncp_dev_hdl_t devHdl,
    ncp_region_id_t regionId,       /* IN: Node/target address */
    ncp_uint64_t offset,            /* IN: Node/target offset */
    ncp_uint8_t value)              /* IN: 8-bit data value */
{
    ncp_st_t ncpStatus;

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_rw,
                       NCP_HWIO_WRITE8,
                       devNum,
                       regionId,
                       offset,
                       (ncp_uint8_t *) &value,
                       sizeof(ncp_uint8_t),
                       1, /* count */
                       0,
                       0 /* flags */
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        NCP_CALL(ncp_dev_num_get(devHdl, &devNum));

        rw.regionId = regionId;
        rw.offset = offset;
        rw.buffer = (ncp_uint32_t *) &value;
        rw.count = 1;
        rw.flags = 0;
        ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_WRITE8,
                devNum,
                &rw);
    }

    /* Write to NCP device space */
    ncpStatus = ncp_dev_write8(
            devHdl,
            regionId,
            offset,
            value);

NCP_RETURN_LABEL
    return ncpStatus;
}

/*
 * ncp_write16
 *
 *   Write a 16-bit value to NCP device space.
 */
ncp_st_t
ncp_write16(
    ncp_dev_hdl_t devHdl,
    ncp_region_id_t regionId,        /* IN: Node/target address */
    ncp_uint64_t offset,             /* IN: Node/target offset */
    ncp_uint16_t value)              /* IN: 16-bit data value */
{
    ncp_st_t ncpStatus;

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_rw,
                       NCP_HWIO_WRITE16,
                       devNum,
                       regionId,
                       offset,
                       (ncp_uint8_t *) &value,
                       sizeof(ncp_uint32_t),
                       1, /* count */
                       0,
                       0 /* flags */
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        NCP_CALL(ncp_dev_num_get(devHdl, &devNum));

        rw.regionId = regionId;
        rw.offset = offset;
        rw.buffer = (ncp_uint32_t *) &value;
        rw.count = 1;
        rw.flags = 0;
        ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_WRITE16,
                devNum,
                &rw);
    }

    /* Write to NCP device space */
    ncpStatus = ncp_dev_write16(
            devHdl,
            regionId,
            offset,
            value);

NCP_RETURN_LABEL
    return ncpStatus;
}


/*
 * ncp_write32
 *
 *   Write a 32-bit value to NCP device space.
 */
ncp_st_t
ncp_write32(
    ncp_dev_hdl_t devHdl,
    ncp_region_id_t regionId,    /* IN: Node/target address */
    ncp_uint64_t offset,             /* IN: Node/target offset */
    ncp_uint32_t value)              /* IN: 32-bit data value */
{
    ncp_st_t ncpStatus;

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_rw,
                       NCP_HWIO_WRITE32,
                       devNum,
                       regionId,
                       offset,
                       (ncp_uint8_t *) &value,
                       sizeof(ncp_uint32_t),
                       1, /* count */
                       0,
                       0 /* flags */
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        NCP_CALL(ncp_dev_num_get(devHdl, &devNum));

        rw.regionId = regionId;
        rw.offset = offset;
        rw.buffer = &value;
        rw.count = 1;
        rw.flags = 0;
        ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_WRITE32,
                devNum,
                &rw);
    }

    /* Write to NCP device space */
    ncpStatus = ncp_dev_write32(
            devHdl,
            regionId,
            offset,
            value);

NCP_RETURN_LABEL
    return ncpStatus;
}

/*
 * ncp_write64
 *
 *   Write a 64-bit value to NCP device space.
 */
ncp_st_t
ncp_write64(
    ncp_dev_hdl_t devHdl,
    ncp_region_id_t regionId,        /* IN: Node/target address */
    ncp_uint64_t offset,             /* IN: Node/target offset */
    ncp_uint64_t value)              /* IN: 64-bit data value */
{
    ncp_st_t ncpStatus;

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_rw,
                       NCP_HWIO_WRITE64,
                       devNum,
                       regionId,
                       offset,
                       (ncp_uint8_t *) &value,
                       sizeof(ncp_uint64_t),
                       1, /* count */
                       0,
                       0 /* flags */
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        NCP_CALL(ncp_dev_num_get(devHdl, &devNum));

        rw.regionId = regionId;
        rw.offset = offset;
        rw.buffer = (ncp_uint32_t *) &value;
        rw.count = 1;
        rw.flags = 0;
        ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_WRITE64,
                devNum,
                &rw);
    }

    /* Write to NCP device space */
    ncpStatus = ncp_dev_write64(
            devHdl,
            regionId,
            offset,
            value);

NCP_RETURN_LABEL
    return ncpStatus;
}

/*
 * ncp_block_write8
 *
 *   Write 8-bit values to NCP device space.
 */
ncp_st_t
ncp_block_write8(
    ncp_dev_hdl_t devHdl,
    ncp_region_id_t regionId,        /* IN: Node/target address */
    ncp_uint64_t offset,             /* IN: Node/target offset */
    ncp_uint8_t *buffer,             /* IN: Pointer to write data */
    ncp_uint32_t count,              /* IN: Number of 8-bit values to write */
    ncp_uint32_t flags)              /* IN: I/O flags */
{
    ncp_st_t ncpStatus;

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_rw,
                       NCP_HWIO_WRITE8,
                       devNum,
                       regionId,
                       offset,
                       (ncp_uint8_t *) buffer,
                       count * sizeof(ncp_uint8_t),
                       count,
                       0,
                       flags
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        NCP_CALL(ncp_dev_num_get(devHdl, &devNum));

        rw.regionId = regionId;
        rw.offset = offset;
        rw.buffer = (ncp_uint32_t *) buffer;
        rw.count = count;
        rw.flags = flags;
        ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_WRITE8,
                devNum,
                &rw);
    }

    /* Write to NCP device space */
    ncpStatus = ncp_dev_block_write8(
            devHdl,
            regionId,
            offset,
            buffer,
            count,
            flags);

NCP_RETURN_LABEL
    return ncpStatus;
}

/*
 * ncp_block_write16
 *
 *   Write 16-bit values to NCP device space.
 */
ncp_st_t
ncp_block_write16(
    ncp_dev_hdl_t devHdl,
    ncp_region_id_t regionId,        /* IN: Node/target address */
    ncp_uint64_t offset,             /* IN: Node/target offset */
    ncp_uint16_t *buffer,            /* IN: Pointer to write data */
    ncp_uint32_t count,              /* IN: Number of 16-bit words to write */
    ncp_uint32_t flags)              /* IN: I/O flags */
{
    ncp_st_t ncpStatus;

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_rw,
                       NCP_HWIO_WRITE16,
                       devNum,
                       regionId,
                       offset,
                       (ncp_uint8_t *) buffer,
                       count * sizeof(ncp_uint16_t),
                       count,
                       0,
                       flags
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        NCP_CALL(ncp_dev_num_get(devHdl, &devNum));

        rw.regionId = regionId;
        rw.offset = offset;
        rw.buffer = (ncp_uint32_t *) buffer;
        rw.count = count;
        rw.flags = flags;
        ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_WRITE16,
                devNum,
                &rw);
    }

    /* Write to NCP device space */
    ncpStatus = ncp_dev_block_write16(
            devHdl,
            regionId,
            offset,
            buffer,
            count,
            flags);

NCP_RETURN_LABEL
    return ncpStatus;
}

/*
 * ncp_block_write32
 *
 *   Write 32-bit values to NCP device space.
 */
ncp_st_t
ncp_block_write32(
    ncp_dev_hdl_t devHdl,
    ncp_region_id_t regionId,    /* IN: Node/target address */
    ncp_uint64_t offset,             /* IN: Node/target offset */
    ncp_uint32_t *buffer,            /* IN: Pointer to write data */
    ncp_uint32_t count,              /* IN: Number of 32-bit words to write */
    ncp_uint32_t flags)              /* IN: I/O flags */
{
    ncp_st_t ncpStatus;

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_rw,
                       NCP_HWIO_WRITE32,
                       devNum,
                       regionId,
                       offset,
                       (ncp_uint8_t *) buffer,
                       count * sizeof(ncp_uint32_t),
                       count,
                       0,
                       flags
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        NCP_CALL(ncp_dev_num_get(devHdl, &devNum));

        rw.regionId = regionId;
        rw.offset = offset;
        rw.buffer = buffer;
        rw.count = count;
        rw.flags = flags;
        ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_WRITE32,
                devNum,
                &rw);
    }

    /* Write to NCP device space */
    ncpStatus = ncp_dev_block_write32(
            devHdl,
            regionId,
            offset,
            buffer,
            count,
            flags);

NCP_RETURN_LABEL
    return ncpStatus;
}

/*
 * ncp_block_write64
 *
 *   Write 64-bit values to NCP device space.
 */
ncp_st_t
ncp_block_write64(
    ncp_dev_hdl_t devHdl,
    ncp_region_id_t regionId,    /* IN: Node/target address */
    ncp_uint64_t offset,             /* IN: Node/target offset */
    ncp_uint64_t *buffer,            /* IN: Pointer to write data */
    ncp_uint32_t count,              /* IN: Number of 64-bit words to write */
    ncp_uint32_t flags)              /* IN: I/O flags */
{
    ncp_st_t ncpStatus;

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_rw,
                       NCP_HWIO_WRITE64,
                       devNum,
                       regionId,
                       offset,
                       (ncp_uint8_t *) buffer,
                       count * sizeof(ncp_uint64_t),
                       count,
                       0,
                       flags
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        NCP_CALL(ncp_dev_num_get(devHdl, &devNum));

        rw.regionId = regionId;
        rw.offset = offset;
        rw.buffer = (ncp_uint32_t *) buffer;
        rw.count = count;
        rw.flags = flags;
        ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_WRITE64,
                devNum,
                &rw);
    }

    /* Write to NCP device space */
    ncpStatus = ncp_dev_block_write64(
            devHdl,
            regionId,
            offset,
            buffer,
            count,
            flags);

NCP_RETURN_LABEL
    return ncpStatus;
}


ncp_st_t
ncp_block_fill(
    ncp_dev_hdl_t   devHdl,
    ncp_region_id_t regionId,
    ncp_uint64_t    offset,
    ncp_fill_t     *ncp_fill_p,
    ncp_uint32_t    flags)
{
    ncp_st_t ncpStatus;

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_fill,
                       NCP_HWIO_CRBF,
                       devNum,
                       regionId,
                       offset,
                       ncp_fill_p->NCP_POINTER(value),
                       ncp_fill_p->u.width, /* bufferLen */
                       ncp_fill_p->u.width,
                       ncp_fill_p->count,
                       ncp_fill_p->stride,
                       flags
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        NCP_CALL(ncp_dev_num_get(devHdl, &devNum));

        rw.regionId = regionId;
        rw.offset = offset;
        rw.buffer = (ncp_uint32_t *) ncp_fill_p;
        rw.flags = flags;
        ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_CRBF,
                devNum,
                &rw);
    }

    /* Write to NCP device space */
    ncpStatus = ncp_dev_block_fill(
            devHdl,
            regionId,
            offset,
            ncp_fill_p,
            flags);

NCP_RETURN_LABEL
    return ncpStatus;
}



ncp_st_t
ncp_read_modify_write(
    ncp_dev_hdl_t   devHdl,
    ncp_region_id_t regionId,
    ncp_uint64_t    offset,
    ncp_rmw_t      *ncp_rmw_p,
    ncp_uint32_t    flags)
{
    ncp_st_t ncpStatus;

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_rmw,
                       NCP_HWIO_CRRMW,
                       devNum,
                       regionId,
                       offset,
                       (ncp_uint64_t *)(ncp_rmw_p->NCP_POINTER(rmw_buffer)),
                       ncp_rmw_p->count, /* bufferLen */
                       ncp_rmw_p->count,
                       flags
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        NCP_CALL(ncp_dev_num_get(devHdl, &devNum));

        rw.regionId = regionId;
        rw.offset = offset;
        rw.buffer = (ncp_uint32_t *) ncp_rmw_p;
        rw.flags = flags;
        ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_CRRMW,
                devNum,
                &rw);
    }

    /* Write to NCP device space */
    ncpStatus = ncp_dev_read_modify_write(
            devHdl,
            regionId,
            offset,
            ncp_rmw_p,
            flags);

NCP_RETURN_LABEL
    return ncpStatus;
}

ncp_st_t
ncp_scatter_write(
    ncp_dev_hdl_t   devHdl,
    ncp_region_id_t regionId,
    ncp_crsw_t     *crsw_p,
    ncp_uint32_t    flags)
{
    ncp_st_t ncpStatus;

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_sw,
                       NCP_HWIO_CRSW,
                       devNum,
                       regionId,
                       (ncp_uint64_t *)(crsw_p->NCP_POINTER(swvector)),
                       crsw_p->length, /* bufferLen */
                       crsw_p->length,
                       flags
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        NCP_CALL(ncp_dev_num_get(devHdl, &devNum));

        rw.regionId = regionId;
        rw.buffer = (ncp_uint32_t *) crsw_p;
        rw.flags = flags;
        ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_CRSW,
                devNum,
                &rw);
    }

    /* Write to NCP device space */
    ncpStatus = ncp_dev_scatter_write(
            devHdl,
            regionId,
            crsw_p,
            flags);

NCP_RETURN_LABEL
    return ncpStatus;
}

ncp_st_t
ncp_broadcast_block_write(
    ncp_dev_hdl_t   devHdl,
    ncp_region_id_t regionId,
    ncp_uint64_t    offset,
    ncp_crbbw_t    *crbbw_p,
    ncp_uint32_t    flags)
{
    ncp_st_t ncpStatus;

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_bbw,
                       NCP_HWIO_CRBBW,
                       devNum,
                       regionId,
                       offset,
                       (ncp_uint64_t *)(crbbw_p->NCP_POINTER(data)),
                       crbbw_p->length, /* bufferLen */
                       crbbw_p->length,
                       crbbw_p->nvector,
                       flags
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        NCP_CALL(ncp_dev_num_get(devHdl, &devNum));

        rw.regionId = regionId;
        rw.offset = offset;
        rw.buffer = (ncp_uint32_t *) crbbw_p;
        rw.flags = flags;
        ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_CRBBW,
                devNum,
                &rw);
    }

    /* Write to NCP device space */
    ncpStatus = ncp_dev_broadcast_block_write(
            devHdl,
            regionId,
            offset,
            crbbw_p,
            flags);

NCP_RETURN_LABEL
    return ncpStatus;
}

ncp_st_t
ncp_broadcast_scatter_write(
    ncp_dev_hdl_t   devHdl,
    ncp_region_id_t regionId,
    ncp_crbsw_t    *crbsw_p,
    ncp_uint32_t    flags)
{
    ncp_st_t ncpStatus;

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {

            /* The LTTng ctf_sequence() macro only supports integer types, not
             * struct, so we need to copy the 32-bit and 64-bit field of each
             * ncp_bswspec_t into a separate array and then give those to the
             * tracepoint call. */

            ncp_uint32_t *addrBuf;
            ncp_uint64_t *dataBuf;
            int i;

            addrBuf = ncp_malloc(crbsw_p->length * sizeof(ncp_uint32_t));
            if (addrBuf == NULL) {
                NCP_CALL(NCP_ST_NO_MEMORY);
            }

            dataBuf = ncp_malloc(crbsw_p->length * sizeof(ncp_uint64_t));
            if (dataBuf == NULL) {
                ncp_free(addrBuf);
                NCP_CALL(NCP_ST_NO_MEMORY);
            }

            for (i = 0; i < crbsw_p->length; i++) {
                addrBuf[i] = crbsw_p->NCP_POINTER(bswvector)[i].addr;
                memcpy(&dataBuf[i], &crbsw_p->NCP_POINTER(bswvector)[i].data, sizeof(ncp_uint64_t));
            }

            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_bsw,
                       NCP_HWIO_CRBSW,
                       devNum,
                       regionId,
                       addrBuf,
                       dataBuf,
                       crbsw_p->length, /* bufferLen */
                       crbsw_p->length,
                       crbsw_p->nvector,
                       flags
                      );

            ncp_free(addrBuf);
            ncp_free(dataBuf);
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        NCP_CALL(ncp_dev_num_get(devHdl, &devNum));

        rw.regionId = regionId;
        rw.buffer = (ncp_uint32_t *) crbsw_p;
        rw.flags = flags;
        ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_CRBSW,
                devNum,
                &rw);
    }

    /* Write to NCP device space */
    ncpStatus = ncp_dev_broadcast_scatter_write(
            devHdl,
            regionId,
            crbsw_p,
            flags);

NCP_RETURN_LABEL
    return ncpStatus;
}

ncp_st_t
ncp_broadcast_block_fill(
    ncp_dev_hdl_t   devHdl,
    ncp_region_id_t regionId,
    ncp_uint64_t    offset,
    ncp_fill_t     *ncp_fill_p,
    ncp_uint32_t    flags)
{
    ncp_st_t ncpStatus;

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_fill,
                       NCP_HWIO_CRBBF,
                       devNum,
                       regionId,
                       offset,
                       ncp_fill_p->NCP_POINTER(value),
                       2, /* bufferLen; we combine 32-bit words 0 and 1 into a 64-bit int and fill that */
                       ncp_fill_p->u.nvector, /* union type; we put the broadcast nvector in the width field */
                       ncp_fill_p->count,
                       ncp_fill_p->stride,
                       flags
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        NCP_CALL(ncp_dev_num_get(devHdl, &devNum));

        rw.regionId = regionId;
        rw.offset = offset;
        rw.buffer = (ncp_uint32_t *) ncp_fill_p;
        rw.flags = flags;
        ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_CRBBF,
                devNum,
                &rw);
    }

    /* Write to NCP device space */
    ncpStatus = ncp_dev_broadcast_block_fill(
            devHdl,
            regionId,
            offset,
            ncp_fill_p,
            flags);

NCP_RETURN_LABEL
    return ncpStatus;
}

ncp_st_t
ncp_coherent_sysmem_read(
    ncp_dev_hdl_t   devHdl,
    ncp_region_id_t regionId,
    ncp_uint64_t    address,
    ncp_uint8_t    *buffer,
    ncp_uint32_t    count,
    ncp_uint32_t    xferWidth,
    ncp_uint32_t    flags)
{
    ncp_st_t ncpStatus;

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_rw,
                       NCP_HWIO_CSMBR,
                       devNum,
                       regionId,
                       address,
                       (ncp_uint8_t *) buffer,
                       count * xferWidth * sizeof(ncp_uint8_t),
                       count,
                       xferWidth,
                       flags
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        NCP_CALL(ncp_dev_num_get(devHdl, &devNum));

        rw.regionId = regionId;
        rw.offset = address;
        rw.buffer = (ncp_uint32_t *) buffer;
        rw.flags = flags;
        rw.count = count;
        rw.xferWidth = xferWidth;
        ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_CSMBR,
                devNum,
                &rw);
    }

    /* Write to NCP device space */
    ncpStatus = ncp_dev_coherent_sysmem_read(
            devHdl,
            regionId,
            address,
            buffer,
            count,
            xferWidth,
            flags);

NCP_RETURN_LABEL
    return ncpStatus;
}

ncp_st_t
ncp_coherent_sysmem_write(
    ncp_dev_hdl_t   devHdl,
    ncp_region_id_t regionId,
    ncp_uint64_t    address,
    ncp_uint8_t    *buffer,
    ncp_uint32_t    count,
    ncp_uint32_t    xferWidth,
    ncp_uint32_t    flags)
{
    ncp_st_t ncpStatus;

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    {
        ncp_uint32_t devNum;
        if (ncp_dev_num_get(devHdl, &devNum) == NCP_ST_SUCCESS) {
            tracepoint(Intel_AXXIA_ncp_custom,
                       ncp_custom_hwio_rw,
                       NCP_HWIO_CSMBW,
                       devNum,
                       regionId,
                       address,
                       (ncp_uint8_t *) buffer,
                       count * xferWidth * sizeof(ncp_uint8_t),
                       count,
                       xferWidth,
                       flags
                      );
        }
    }
#endif

    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        NCP_CALL(ncp_dev_num_get(devHdl, &devNum));

        rw.regionId = regionId;
        rw.offset = address;
        rw.buffer = (ncp_uint32_t *)buffer;
        rw.flags = flags;
        rw.count = count;
        rw.xferWidth = xferWidth;
        ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_CSMBW,
                devNum,
                &rw);
    }

    /* Write to NCP device space */
    ncpStatus = ncp_dev_coherent_sysmem_write(
            devHdl,
            regionId,
            address,
            buffer,
            count,
            xferWidth,
            flags);

NCP_RETURN_LABEL
    return ncpStatus;
}

ncp_st_t
ncp_mdio_write(
    ncp_dev_hdl_t   devHdl,
    ncp_region_id_t regionId,
    ncp_uint64_t    offset,
    ncp_uint32_t    *buffer,
    ncp_uint32_t    count,
    ncp_uint32_t    flags)
{
    ncp_st_t ncpStatus;

#ifdef IO_DIAGNOSTICS
    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;

        NCP_CALL(ncp_dev_num_get(devHdl, &devNum));

        rw.regionId = regionId;
        rw.offset = offset;
        rw.buffer = buffer;
        rw.flags = flags;
        rw.count = count;
        ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                0, 
                devNum,
                &rw);
    }
#endif
    /* Write to NCP device space */
    ncpStatus = ncp_dev_mdioWrite(
            devHdl,
            regionId,
            offset,
            buffer,
            count,
            flags);

NCP_RETURN_LABEL
    return ncpStatus;
}

ncp_st_t
ncp_mdio_read(
    ncp_dev_hdl_t   devHdl,
    ncp_region_id_t regionId,
    ncp_uint64_t    offset,
    ncp_uint32_t    *buffer,
    ncp_uint32_t    count,
    ncp_uint32_t    flags)
{
    ncp_st_t ncpStatus;

#ifdef IO_DIAGNOSTICS
    /* Call user hardware I/O trace function, if requested */
    if (ncpHwioTraceFunc != NULL) {
        ncp_hwio_rw_t rw;
        ncp_uint32_t devNum;
                
        NCP_CALL(ncp_dev_num_get(devHdl, &devNum));
                
        rw.regionId = regionId;
        rw.offset = offset;
        rw.buffer = buffer;
        rw.flags = flags;
        rw.count = count;
        ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                0, 
                devNum,
                &rw);
    }
#endif
    /* Write to NCP device space */
    ncpStatus = ncp_dev_mdioRead(
            devHdl,
            regionId,
            offset,
            buffer,
            count,
            flags);

NCP_RETURN_LABEL
    return ncpStatus;
}               



#ifdef IO_TRANSACTION_FNS
/*
 * ncp_hdl_transaction_start
 */
ncp_st_t
ncp_hdl_transaction_start(
    ncp_dev_hdl_t devHdl)
{
    ncp_st_t ncpStatus;
    ncp_uint32_t devNum;

    ncp_comment("### BEGIN Transaction");

    NCP_CALL(ncp_dev_num_get(devHdl, &devNum));

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    tracepoint(Intel_AXXIA_ncp_custom,
               ncp_custom_hwio_generic,
               NCP_HWIO_TRANS_START,
               devNum,
               0
              );
#endif

    if (ncpHwioTraceFunc != NULL) {
        ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_TRANS_START,
                devNum,
                NULL);
    }

    ncpStatus = ncp_dev_transaction_start(devHdl);

NCP_RETURN_LABEL
    return ncpStatus;
}

/*
 * ncp_hdl_transaction_add
 */
ncp_st_t
ncp_hdl_transaction_add(
    ncp_dev_hdl_t devHdl,
    ncp_dev_trans_type_t transType,
    void *trans)
{
    ncp_st_t ncpStatus;

    if (ncpHwioTraceFunc != NULL) {
        switch (transType) {
            case NCP_DEV_TRANS_UDELAY:
            {
                ncp_uint32_t devNum;

                NCP_CALL(ncp_dev_num_get(devHdl, &devNum));

                /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
                tracepoint(Intel_AXXIA_ncp_custom,
                           ncp_custom_hwio_generic,
                           NCP_HWIO_TRANS_UDELAY,
                           devNum,
                           trans
                          );
#endif

                ncpHwioTraceFunc(
                        ncpHwioTraceFuncArg,
                        NCP_HWIO_TRANS_UDELAY,
                        devNum,
                        trans);
                break;
            }
            case NCP_DEV_TRANS_BLOCK_FILL32:
            {
                ncp_uint32_t devNum;
                ncp_hwio_rw_t rw;
                ncp_dev_trans_block_fill32_t *bf32 =
                        (ncp_dev_trans_block_fill32_t *)trans;

                NCP_CALL(ncp_dev_num_get(devHdl, &devNum));
                rw.regionId = bf32->regionId;
                rw.offset = bf32->offset;
                rw.buffer = &bf32->value;
                rw.count = bf32->count;
                rw.flags = NCP_IO_PIO | NCP_IO_TRANS;
                ncpHwioTraceFunc(
                        ncpHwioTraceFuncArg,
                        NCP_HWIO_FILL32,
                        devNum,
                        &rw);
                break;
            }
            case NCP_DEV_TRANS_BLOCK_FILL64:
            {
                ncp_uint32_t devNum;
                ncp_hwio_rw_t rw;
                ncp_dev_trans_block_fill64_t *bf64 =
                        (ncp_dev_trans_block_fill64_t *)trans;

                NCP_CALL(ncp_dev_num_get(devHdl, &devNum));
                rw.regionId = bf64->regionId;
                rw.offset = bf64->offset;
                rw.buffer = (ncp_uint32_t *) &bf64->value;
                rw.count = bf64->count;
                rw.flags = NCP_IO_PIO | NCP_IO_TRANS;
                ncpHwioTraceFunc(
                        ncpHwioTraceFuncArg,
                        NCP_HWIO_FILL64,
                        devNum,
                        &rw);
                break;
            }
            case NCP_DEV_TRANS_BLOCK_WRITE32:
            {
                ncp_uint32_t devNum;
                ncp_hwio_rw_t rw;
                ncp_dev_trans_block_write32_t *bw32 =
                        (ncp_dev_trans_block_write32_t *)trans;

                NCP_CALL(ncp_dev_num_get(devHdl, &devNum));

                rw.regionId = bw32->regionId;
                rw.offset = bw32->offset;
                rw.buffer = bw32->NCP_POINTER(dataBuf);
                rw.count = bw32->count;
                rw.flags = NCP_IO_PIO | NCP_IO_TRANS;
                ncpHwioTraceFunc(
                        ncpHwioTraceFuncArg,
                        NCP_HWIO_WRITE32,
                        devNum,
                        &rw);
                break;
            }
            default:
                break;
        }
    }

    ncpStatus = ncp_dev_transaction_add(devHdl, transType, trans, 0);

NCP_RETURN_LABEL
    return ncpStatus;
}

/*
 * ncp_hdl_transaction_end
 */
ncp_st_t
ncp_hdl_transaction_end(
    ncp_dev_hdl_t devHdl)
{
    ncp_st_t ncpStatus;
    ncp_uint32_t devNum;

    ncp_comment("### END Transaction");

    NCP_CALL(ncp_dev_num_get(devHdl, &devNum));

    /* Log HWIO tracepoint, if enabled */
#if (defined(NCP_LTTNG_USERSPACE) && !defined(NCP_KERNEL))
    tracepoint(Intel_AXXIA_ncp_custom,
               ncp_custom_hwio_generic,
               NCP_HWIO_TRANS_END,
               devNum,
               0
              );
#endif

    if (ncpHwioTraceFunc != NULL) {
        ncpHwioTraceFunc(
                ncpHwioTraceFuncArg,
                NCP_HWIO_TRANS_END,
                devNum,
                NULL);
    }

    ncpStatus = ncp_dev_transaction_end(devHdl);

NCP_RETURN_LABEL
    return ncpStatus;
}
#endif


/*---------------------------------------------------------*/

/*
 * ncp_rev_init
 * determine FPGA/ASIC and revision.
 */
#ifdef STANDALONE_CHIP_ID_FNS
ncp_st_t
ncp_rev_init(ncp_t *ncp)
{
    ncp_st_t             ncpStatus;
    ncp_uint32_t         u32Val, ver;

    NCP_CALL(ncp_dev_info_get(ncp->devHdl, &u32Val));

    /*
     * If the a version was specified via the SW scratch register,
     * use that instead of retrieving the version from the driver
     */
    if (ncp->scratchPad & NCP_SP_VER_MASK) {
        ver = (ncp->scratchPad & NCP_SP_VER_MASK) >> NCP_SP_VER_SHIFT;
        u32Val |= ver << NCP_DEV_VER_SHIFT;
        /* Odd - FPGA, Even - ASIC */
        if (ver & 1) {
            u32Val &= ~NCP_DEV_IS_ASIC;
        }
        else {
            u32Val |= NCP_DEV_IS_ASIC;
        }
        NCP_CALL(ncp_dev_info_set(ncp->devHdl, u32Val));
        ncp->version = (ncp_version_t)ver;
    }
    else {
        NCP_CALL(ncp_dev_hw_version_get(ncp->devHdl, &ncp->version));
    }

    if (!(u32Val & NCP_DEV_IS_ASIC)) {
        ncp->isFPGA = TRUE;
    }

    if (u32Val & NCP_DEV_FBAPI_MODE) {
        ncp->isFBAPI = TRUE;
    } else {
        ncp->isFBAPI = FALSE;
    }

    if (ncp->version >= AG_APP3K_V_1_0) {
        ncp->isHwAPP3K = TRUE;
    }

NCP_RETURN_LABEL
    return ncpStatus;
}

/* --- Published API Functions --- */

/*
 * ncp_version
 *
 *   Return the NCP version.
 */
ncp_st_t
ncp_version(
    ncp_hdl_t inHdl,
    ncp_version_t *outChipVer)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_t *ncp = (ncp_t *)inHdl;

    NCP_CALL(NCP_CONFIG_VALIDATE_HANDLE(ncp));
    *outChipVer = ncp->version;

NCP_RETURN_LABEL
    return ncpStatus;
}
#endif

/*
 * ncp_user_info()
 *
 *   Copy the NCP userInfo string to the user's buffer.
 */
ncp_st_t
ncp_user_info(
    ncp_hdl_t    inHdl,
    ncp_uint32_t userInfoSizeBytes,
    char       *userInfo)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_t *ncp = (ncp_t *)inHdl;

    NCP_CALL(NCP_CONFIG_VALIDATE_HANDLE(ncp));

    /*
     * Need room for the string terminator, at least.
     */
    if (userInfoSizeBytes == 0) {
        NCP_CALL(NCP_ST_INVALID_PARAMETER);
    }

    if (ncp->userInfo != NULL) {
        userInfoSizeBytes--;    /* make room for the terminator */
        if (strlen(ncp->userInfo) < userInfoSizeBytes) {
            userInfoSizeBytes = strlen(ncp->userInfo);
        }
        strncpy(userInfo, ncp->userInfo, userInfoSizeBytes);
        userInfo[userInfoSizeBytes] = 0;
    } else {
        userInfo[0] = 0;
    }

NCP_RETURN_LABEL
    return ncpStatus;
}

/*
 * ncp_trace_level_set
 *
 *   Set the trace level flags to enable or disable runtime messages.
 */
ncp_st_t
ncp_trace_level_set(
    int traceLevel)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_TRACEPOINT (Intel_AXXIA_ncp_common, ncp_trace_level_set_entry, NCP_MSG_ENTRY,
        "traceLevel=%d\n", traceLevel);

    ncp_trace_level = traceLevel;

NCP_RETURN_LABEL
    NCP_TRACEPOINT (Intel_AXXIA_ncp_common, ncp_trace_level_set_exit, NCP_MSG_EXIT,
                "ncpStatus=%d\n", ncpStatus);
    return ncpStatus;
}

#ifdef NCP_ROBUST_MUTEX_TEST
extern ncp_bool_t ncp_owner_dead;
extern ncp_mutex_t* ncp_mutex_ptr;
NCP_API ncp_st_t
ncp_owner_dead_set(
    ncp_bool_t ownerDead)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_owner_dead = ownerDead;

NCP_RETURN_LABEL
    return ncpStatus;
}
NCP_API ncp_st_t
ncp_mutex_reinit(void)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_CALL(ncp_mutex_destroy(ncp_mutex_ptr));
    NCP_CALL(ncp_mutex_init(ncp_mutex_ptr, TRUE));
NCP_RETURN_LABEL
    return ncpStatus;
}
#endif
