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


/*
 * NCP UNIX API <--> Driver System Call Interfaces
 */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "uboot/ncp_sal_types_linux.h"
#include "uboot/ncp_status.h"
#include "uboot/axxia.h"
#include "uboot/ncp_task_basetypes.h"

#include "uboot/ncp.h"
#include "uboot/ncp_pvt.h"
#include "uboot/ncp_dev_linux.h"
#include "uboot/ncp_dev_pvt.h"
#include "uboot/ncp_task.h"
#include "uboot/ncp_task_pvt.h"

#ifdef __linux__


/* --- Types & Definitions --- */

#define NCP_MAX_DEV_NAME_LEN    (25)


/* --- Internal Functions ---- */

/*
 * ncp_status_code
 *
 *   Translate UNIX errno into an appropriate NCP status code.
 */
static ncp_st_t
ncp_status_code(void)
{
    switch (errno)
    {
        case EBADF:
        case ENOTTY:
            return NCP_ST_DEV_INVALID_HANDLE;

        case ENOENT:
            return NCP_ST_DEV_DEVICE_FILE_NOT_FOUND;

        case ENXIO:
        case ENODEV:
            return NCP_ST_DEV_DEVICE_NOT_FOUND;

        case EFAULT:
            return NCP_ST_DEV_INVALID_BUFFER;

        case EINVAL:
            return NCP_ST_DEV_INVALID_IOCTL_COMMAND;
    }

    NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_status_code_unexpectedIoctl, NCP_MSG_ERROR,
                   "Unexpected ioctl error : %d\n", errno);

    return NCP_ST_DEV_UNMAPPED_ERROR;
}


/* --- External Functions ---- */

ncp_st_t
ncp_dev_init(void)
{
    return NCP_ST_SUCCESS;
}

ncp_st_t
ncp_dev_open(
    ncp_uint32_t devNum,            /* IN: Device instance number */
    ncp_uint32_t flags,             /* IN: Open flags (not used; set to zero) */
    ncp_dev_hdl_t *devHdl)      /* OUT: Return location for NCP handle */
{
    int  fd;
    char devName[NCP_MAX_DEV_NAME_LEN] = {'\0'};

    sprintf(devName, "/dev/ncp%d", devNum);

    fd = open(devName, O_RDWR);
    if(fd == -1)
    {
        return ncp_status_code();
    }

    *devHdl = (void *)((intptr_t)fd);

    return NCP_ST_SUCCESS;
}

ncp_st_t
ncp_dev_close(
    ncp_dev_hdl_t devHdl)       /* IN: Device handle */
{
    if (close((intptr_t)devHdl) == -1) {
        return ncp_status_code();
    }

    return NCP_ST_SUCCESS;
}

ncp_st_t
ncp_dev_read8(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_region_id_t regionId,   /* IN: Node/target address */
    ncp_uint64_t offset,             /* IN: Node/target offset */
    ncp_uint8_t *value)              /* OUT: Return location for read data */
{
    return ncp_dev_block_read8(
            devHdl,
            regionId,
            offset,
            value,
            1,
            0);
}

ncp_st_t
ncp_dev_read16(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_region_id_t regionId,   /* IN: Node/target address */
    ncp_uint64_t offset,             /* IN: Node/target offset */
    ncp_uint16_t *value)             /* OUT: Return location for read data */
{
    return ncp_dev_block_read16(
            devHdl,
            regionId,
            offset,
            value,
            1,
            0);
}

ncp_st_t
ncp_dev_read32(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_region_id_t regionId,   /* IN: Node/target address */
    ncp_uint64_t offset,             /* IN: Node/target offset */
    ncp_uint32_t *value)             /* OUT: Return location for read data */
{
    return ncp_dev_block_read32(
            devHdl,
            regionId,
            offset,
            value,
            1,
            0);
}

ncp_st_t
ncp_dev_read64(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_region_id_t regionId,   /* IN: Node/target address */
    ncp_uint64_t offset,             /* IN: Node/target offset */
    ncp_uint64_t *value)             /* OUT: Return location for read data */
{
    return ncp_dev_block_read64(
            devHdl,
            regionId,
            offset,
            value,
            1,
            0);
}

ncp_st_t
ncp_dev_write8(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_region_id_t regionId,   /* IN: Node/target address */
    ncp_uint64_t offset,             /* IN: Node/target offset */
    ncp_uint8_t value)               /* IN: Write data */
{
    return ncp_dev_block_write8(
            devHdl,
            regionId,
            offset,
            &value,
            1,
            0);
}

ncp_st_t
ncp_dev_write16(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_region_id_t regionId,   /* IN: Node/target address */
    ncp_uint64_t offset,             /* IN: Node/target offset */
    ncp_uint16_t value)              /* IN: Write data */
{
    return ncp_dev_block_write16(
            devHdl,
            regionId,
            offset,
            &value,
            1,
            0);
}

ncp_st_t
ncp_dev_write32(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_region_id_t regionId,   /* IN: Node/target address */
    ncp_uint64_t offset,             /* IN: Node/target offset */
    ncp_uint32_t value)              /* IN: Write data */
{
    return ncp_dev_block_write32(
            devHdl,
            regionId,
            offset,
            &value,
            1,
            0);
}

ncp_st_t
ncp_dev_write64(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_region_id_t regionId,   /* IN: Node/target address */
    ncp_uint64_t offset,        /* IN: Node/target offset */
    ncp_uint64_t value)         /* IN: Write data */
{
    return ncp_dev_block_write64(
            devHdl,
            regionId,
            offset,
            &value,
            1,
            0);
}

ncp_st_t
ncp_dev_block_read8(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_region_id_t regionId,   /* IN: Node/target address */
    ncp_uint64_t offset,        /* IN: Node/target offset */
    ncp_uint8_t *buffer,        /* OUT: Return location for read data */
    ncp_uint32_t count,         /* IN: Number of 8-bit words to read */
    ncp_uint32_t flags)         /* IN: Operational control flags */
{
    ncp_ioc_rw_t rw;
    ncp_st_t     ncpStatus = NCP_ST_SUCCESS;

    rw.regionId = regionId;
    rw.offset   = offset;
    rw.NCP_POINTER(buffer) = (void *)buffer;
    rw.count    = count;
    rw.flags    = flags;
    rw.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(buffer));
    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_READ8, &rw) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL
    return ncpStatus;
}

ncp_st_t
ncp_dev_block_read16(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_region_id_t regionId,   /* IN: Node/target address */
    ncp_uint64_t offset,        /* IN: Node/target offset */
    ncp_uint16_t *buffer,       /* OUT: Return location for read data */
    ncp_uint32_t count,         /* IN: Number of 16-bit words to read */
    ncp_uint32_t flags)         /* IN: Operational control flags */
{
    ncp_ioc_rw_t rw;
    ncp_st_t     ncpStatus = NCP_ST_SUCCESS;

    rw.regionId = regionId;
    rw.offset   = offset;
    rw.NCP_POINTER(buffer) = (void *)buffer;
    rw.count    = count;
    rw.flags    = flags;
    rw.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(buffer));
    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_READ16, &rw) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL
    return ncpStatus;
}

ncp_st_t
ncp_dev_block_read32(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_region_id_t regionId,   /* IN: Node/target address */
    ncp_uint64_t offset,        /* IN: Node/target offset */
    ncp_uint32_t *buffer,       /* OUT: Return location for read data */
    ncp_uint32_t count,         /* IN: Number of 32-bit words to read */
    ncp_uint32_t flags)         /* IN: Operational control flags */
{
    ncp_ioc_rw_t rw;
    ncp_st_t     ncpStatus = NCP_ST_SUCCESS;

    rw.regionId = regionId;
    rw.offset   = offset;
    rw.NCP_POINTER(buffer) = (void *)buffer;
    rw.count    = count;
    rw.flags    = flags;
    rw.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(buffer));
    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_READ32, &rw) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}

ncp_st_t
ncp_dev_block_read64(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_region_id_t regionId,   /* IN: Node/target address */
    ncp_uint64_t offset,            /* IN: Node/target offset */
    ncp_uint64_t *buffer,           /* OUT: Return location for read data */
    ncp_uint32_t count,             /* IN: Number of 64-bit values to read */
    ncp_uint32_t flags)             /* IN: Operational control flags */
{
    ncp_ioc_rw_t rw;
    ncp_st_t     ncpStatus = NCP_ST_SUCCESS;

    rw.regionId = regionId;
    rw.offset   = offset;
    rw.NCP_POINTER(buffer) = (void *)buffer;
    rw.count    = count;
    rw.flags    = flags;
    rw.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(buffer));
    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_READ64, &rw) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}

ncp_st_t
ncp_dev_block_write8(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_region_id_t regionId,   /* IN: Node/target address */
    ncp_uint64_t offset,        /* IN: Node/target offset */
    ncp_uint8_t *buffer,        /* IN: Pointer to write data */
    ncp_uint32_t count,         /* IN: Number of 8-bit words to write */
    ncp_uint32_t flags)         /* IN: Operational control flags */
{
    ncp_ioc_rw_t rw;
    ncp_st_t     ncpStatus = NCP_ST_SUCCESS;

    rw.regionId = regionId;
    rw.offset   = offset;
    rw.NCP_POINTER(buffer) = (void *)buffer;
    rw.count    = count;
    rw.flags    = flags;
    rw.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(buffer));
    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_WRITE8, &rw) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL
    return ncpStatus;
}

ncp_st_t
ncp_dev_block_write16(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_region_id_t regionId,   /* IN: Node/target address */
    ncp_uint64_t offset,        /* IN: Node/target offset */
    ncp_uint16_t *buffer,       /* IN: Pointer to write data */
    ncp_uint32_t count,         /* IN: Number of 16-bit words to write */
    ncp_uint32_t flags)         /* IN: Operational control flags */
{
    ncp_ioc_rw_t rw;
    ncp_st_t     ncpStatus = NCP_ST_SUCCESS;

    rw.regionId = regionId;
    rw.offset   = offset;
    rw.NCP_POINTER(buffer) = (void *)buffer;
    rw.count    = count;
    rw.flags    = flags;
    rw.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(buffer));
    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_WRITE16, &rw) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL
    return ncpStatus;
}

ncp_st_t
ncp_dev_block_write32(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_region_id_t regionId,   /* IN: Node/target address */
    ncp_uint64_t offset,        /* IN: Node/target offset */
    ncp_uint32_t *buffer,       /* IN: Pointer to write data */
    ncp_uint32_t count,         /* IN: Number of 32-bit words to write */
    ncp_uint32_t flags)         /* IN: Operational control flags */
{
    ncp_ioc_rw_t rw;
    ncp_st_t     ncpStatus = NCP_ST_SUCCESS;

    rw.regionId = regionId;
    rw.offset   = offset;
    rw.NCP_POINTER(buffer) = (void *)buffer;
    rw.count    = count;
    rw.flags    = flags;
    rw.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(buffer));
    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_WRITE32, &rw) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}

ncp_st_t
ncp_dev_block_write64(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_region_id_t regionId,   /* IN: Node/target address */
    ncp_uint64_t offset,        /* IN: Node/target offset */
    ncp_uint64_t *buffer,       /* IN: Pointer to write data */
    ncp_uint32_t count,         /* IN: Number of 64-bit values to write */
    ncp_uint32_t flags)         /* IN: Operational control flags */
{
    ncp_ioc_rw_t rw;
    ncp_st_t     ncpStatus = NCP_ST_SUCCESS;

    rw.regionId = regionId;
    rw.offset   = offset;
    rw.NCP_POINTER(buffer) = (void *)buffer;
    rw.count    = count;
    rw.flags    = flags;
    rw.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(buffer));
    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_WRITE64, &rw) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}

ncp_st_t
ncp_dev_block_fill(
    ncp_dev_hdl_t   devHdl,       /* IN: Device handle */
    ncp_region_id_t regionId,     /* IN: Node/target address */
    ncp_uint64_t    offset,       /* IN: Node/target offset */
    ncp_fill_t     *buffer,       /* IN: 32-bit fill value */
    ncp_uint32_t    flags)        /* IN: Operational control flags */
{
    ncp_ioc_rw_t rw;
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    rw.regionId = regionId;
    rw.offset   = offset;
    rw.NCP_POINTER(buffer) = (void *) buffer;
    rw.flags    = flags;
    rw.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(buffer));
    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(buffer->NCP_POINTER_64(value));

    if (ioctl((intptr_t)devHdl, NCP_IOC_FILL, &rw) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}


ncp_st_t
ncp_dev_read_modify_write(
    ncp_dev_hdl_t   devHdl,       /* IN: Device handle */
    ncp_region_id_t regionId,     /* IN: Node/target address */
    ncp_uint64_t    offset,       /* IN: Node/target offset */
    ncp_rmw_t      *ncp_rmw_p,    /* IN: pointer to RMW structure */
    ncp_uint32_t    flags)        /* IN: Operational control flags */
{
    ncp_ioc_rw_t rw;
    ncp_st_t     ncpStatus = NCP_ST_SUCCESS;

    rw.regionId = regionId;
    rw.offset   = offset;
    rw.NCP_POINTER(buffer) = (void *) ncp_rmw_p;
    rw.flags    = flags;
    rw.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(buffer));
    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(ncp_rmw_p->NCP_POINTER_64(rmw_buffer));

    if (ioctl((intptr_t)devHdl, NCP_IOC_RMW, &rw) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}


ncp_st_t
ncp_dev_scatter_write(
    ncp_dev_hdl_t   devHdl,         /* IN: Device handle */
    ncp_region_id_t regionId,       /* IN: Node/target address */
    ncp_crsw_t     *crsw_p,         /* IN: pointer to CRSW structure */
    ncp_uint32_t    flags)          /* IN: Operational control flags */
{
    ncp_ioc_rw_t rw;
    ncp_st_t     ncpStatus = NCP_ST_SUCCESS;

    rw.regionId = regionId;
    rw.offset   = 0;
    rw.NCP_POINTER(buffer) = (void *) crsw_p;
    rw.flags    = flags;
    rw.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(buffer));
    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(crsw_p->NCP_POINTER_64(swvector));

    if (ioctl((intptr_t)devHdl, NCP_IOC_SW, &rw) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}


ncp_st_t
ncp_dev_broadcast_block_write(
    ncp_dev_hdl_t   devHdl,         /* IN: Device handle */
    ncp_region_id_t regionId,       /* IN: Node/target address */
    ncp_uint64_t    offset,         /* IN: Node/target offset */
    ncp_crbbw_t    *crbbw_p,        /* IN: pointer to CRBBW structure */
    ncp_uint32_t    flags)          /* IN: Operational control flags */
{
    ncp_ioc_rw_t rw;
    ncp_st_t     ncpStatus = NCP_ST_SUCCESS;

    rw.regionId = regionId;
    rw.offset   = offset;
    rw.NCP_POINTER(buffer) = (void *) crbbw_p;
    rw.flags    = flags;
    rw.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(buffer));
    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(crbbw_p->NCP_POINTER_64(data));

    if (ioctl((intptr_t)devHdl, NCP_IOC_BBW, &rw) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}


ncp_st_t
ncp_dev_broadcast_scatter_write(
    ncp_dev_hdl_t   devHdl,         /* IN: Device handle */
    ncp_region_id_t regionId,       /* IN: Node/target address */
    ncp_crbsw_t    *crbsw_p,        /* IN: pointer to CRBSW structure */
    ncp_uint32_t    flags)          /* IN: Operational control flags */
{
    ncp_ioc_rw_t rw;
    ncp_st_t     ncpStatus = NCP_ST_SUCCESS;

    rw.regionId = regionId;
    rw.offset   = 0;
    rw.NCP_POINTER(buffer) = (void *) crbsw_p;
    rw.flags    = flags;
    rw.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(buffer));
    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(crbsw_p->NCP_POINTER_64(bswvector));

    if (ioctl((intptr_t)devHdl, NCP_IOC_BSW, &rw) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}


ncp_st_t
ncp_dev_broadcast_block_fill(
    ncp_dev_hdl_t   devHdl,         /* IN: Device handle */
    ncp_region_id_t regionId,       /* IN: Node/target address */
    ncp_uint64_t    offset,         /* IN: Node/target offset */
    ncp_fill_t     *ncp_fill_p,     /* IN: pointer to ncp_fill_t structure */
    ncp_uint32_t    flags)          /* IN: Operational control flags */
{
    ncp_ioc_rw_t rw;
    ncp_st_t     ncpStatus = NCP_ST_SUCCESS;

    rw.regionId = regionId;
    rw.offset   = offset;
    rw.NCP_POINTER(buffer) = (void *) ncp_fill_p;
    rw.flags    = flags;
    rw.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(buffer));
    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(ncp_fill_p->NCP_POINTER_64(value));

    if (ioctl((intptr_t)devHdl, NCP_IOC_BBF, &rw) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}


ncp_st_t
ncp_dev_coherent_sysmem_read(
    ncp_dev_hdl_t   devHdl,         /* IN: Device handle */
    ncp_region_id_t regionId,       /* IN: Engine Node/target */
    ncp_uint64_t    address,        /* IN: System Memory address */
    ncp_uint8_t    *buffer,         /* OUT: read data */
    ncp_uint32_t    count,          /* IN: number of bytes to read */
    ncp_uint32_t    xferWidth,      /* IN: width of data unit in bytes */
    ncp_uint32_t    flags)          /* IN: Operational control flags */
{
    ncp_ioc_rw_t rw;
    ncp_st_t     ncpStatus = NCP_ST_SUCCESS;

    rw.regionId = regionId;
    rw.offset   = address;
    rw.NCP_POINTER(buffer) = (void *) buffer;
    rw.count    = count;
    rw.flags    = flags;
    rw.xferWidth = xferWidth;
    rw.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(buffer));
    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_CSMBR, &rw) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}


ncp_st_t
ncp_dev_coherent_sysmem_write(
    ncp_dev_hdl_t   devHdl,         /* IN: Device handle */
    ncp_region_id_t regionId,       /* IN: Engine Node/target */
    ncp_uint64_t    address,        /* IN: System Memory address */
    ncp_uint8_t    *buffer,         /* IN: Write data */
    ncp_uint32_t    count,          /* IN: number of bytes to write */
    ncp_uint32_t    xferWidth,      /* IN: width of data unit in bytes */
    ncp_uint32_t    flags)          /* IN: Operational control flags */
{
    ncp_ioc_rw_t rw;
    ncp_st_t     ncpStatus = NCP_ST_SUCCESS;

    rw.regionId = regionId;
    rw.offset   = address;
    rw.NCP_POINTER(buffer) = (void *) buffer;
    rw.count    = count;
    rw.flags    = flags;
    rw.xferWidth = xferWidth;
    rw.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(buffer));
    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_CSMBW, &rw) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}


ncp_st_t
ncp_dev_info(
    ncp_dev_info_t *devInfo)    /* OUT: Return location for device info */
{
    ncp_st_t       ncpStatus = NCP_ST_SUCCESS;
    ncp_dev_hdl_t  devHdl=0;
    ncp_ioc_info_t ioc_info;

    ncpStatus = ncp_dev_open(0, 0, &devHdl);
    if (ncpStatus != NCP_ST_SUCCESS)
    {
        goto error;
    }

    ioc_info.NCP_POINTER(info) = devInfo;
    ioc_info.NCP_POINTER(st)   = &ncpStatus;

    NCP_POINTER_FIXUP(ioc_info.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(ioc_info.NCP_POINTER_64(info));

    if (ioctl((intptr_t)devHdl, NCP_IOC_INFO, &ioc_info) == -1)
    {
        ncpStatus = ncp_status_code();
    }

error:
    if (devHdl)
    {
        ncp_dev_close(devHdl);
    }
    return ncpStatus;
}


ncp_st_t
ncp_dev_gsm_info_get(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_dev_gsm_info_t  *gsmInfo)
{
    ncp_st_t           ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_gsm_info_t ioc_gsm_info;

    ioc_gsm_info.NCP_POINTER(info) = gsmInfo;
    ioc_gsm_info.NCP_POINTER(st)   = &ncpStatus;

    NCP_POINTER_FIXUP(ioc_gsm_info.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(ioc_gsm_info.NCP_POINTER_64(info));

    if (ioctl((intptr_t)devHdl, NCP_IOC_TASK_GSM_INFO_GET, &ioc_gsm_info) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}

ncp_st_t
ncp_dev_info_get(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_uint32_t *flags)        /* OUT: Return location for device info */
{
    ncp_st_t           ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_info_get_t ioc_info;

    ioc_info.NCP_POINTER(info) = flags;
    ioc_info.NCP_POINTER(st)   = &ncpStatus;

    NCP_POINTER_FIXUP(ioc_info.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(ioc_info.NCP_POINTER_64(info));

    if (ioctl((intptr_t)devHdl, NCP_IOC_INFO_GET, &ioc_info) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}

ncp_st_t
ncp_dev_info_set(
    ncp_dev_hdl_t devHdl,            /* IN: Device handle */
    ncp_uint32_t  flags)             /* IN: New device flag info */
{
    ncp_st_t           ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_info_set_t ioc_info;

    ioc_info.info            = flags;
    ioc_info.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(ioc_info.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_INFO_SET, &ioc_info) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}

ncp_st_t ncp_dev_stats(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_dev_stats_t *devStats)  /* OUT: Return location for device stats */
{
    ncp_st_t        ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_stats_t ioc_stats;

    ioc_stats.NCP_POINTER(stats) = devStats;
    ioc_stats.NCP_POINTER(st)    = &ncpStatus;

    NCP_POINTER_FIXUP(ioc_stats.NCP_POINTER_64(stats));
    NCP_POINTER_FIXUP(ioc_stats.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_STATS, &ioc_stats) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}

ncp_st_t
ncp_dev_version(
    char *version)                  /* OUT: Return location for version info */
{
    ncp_dev_hdl_t devHdl;
    ncp_ioc_version_t ver;
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncpStatus = ncp_dev_open(0, 0, &devHdl);
    if (ncpStatus != NCP_ST_SUCCESS)
    {
        goto error;
    }

    ver.NCP_POINTER(version) = version;
    ver.NCP_POINTER(st)      = &ncpStatus;

    NCP_POINTER_FIXUP(ver.NCP_POINTER_64(version));
    NCP_POINTER_FIXUP(ver.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_VERSION, &ver) == -1)
    {
        ncpStatus = ncp_status_code();
    }

    ncp_dev_close(devHdl);

error:
    return ncpStatus;
}

ncp_st_t
ncp_dev_hw_version_get(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_version_t *version)     /* OUT: Return location for dev version */
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_hw_version_t ioc_hw_version;

    ioc_hw_version.NCP_POINTER(version) = version;
    ioc_hw_version.NCP_POINTER(st)      = &ncpStatus;

    NCP_POINTER_FIXUP(ioc_hw_version.NCP_POINTER_64(version));
    NCP_POINTER_FIXUP(ioc_hw_version.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_HW_VERSION, &ioc_hw_version) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}

ncp_st_t
ncp_dev_unref(
    ncp_dev_hdl_t devHdl)       /* IN: Device handle */
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    if (ioctl((intptr_t)devHdl, NCP_IOC_UNREF, NULL) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}

ncp_st_t
ncp_dev_trace_level_get(
    ncp_dev_hdl_t devHdl,        /* IN: Device handle */
    ncp_uint32_t *traceLevel)        /* OUT: Current trace level */
{
    ncp_ioc_tr_lvl_get_t trace;
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    trace.NCP_POINTER(level) = traceLevel;
    trace.NCP_POINTER(st)    = &ncpStatus;

    NCP_POINTER_FIXUP(trace.NCP_POINTER_64(level));
    NCP_POINTER_FIXUP(trace.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_TR_LVL_GET, &trace) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}

ncp_st_t
ncp_dev_trace_level_set(
    ncp_dev_hdl_t devHdl,        /* IN: Device handle */
    ncp_uint32_t traceLevel)         /* IN: Selected trace level */
{
    ncp_ioc_tr_lvl_set_t trace;
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    trace.level = traceLevel;
    trace.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(trace.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_TR_LVL_SET, &trace) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}

ncp_st_t
ncp_dev_pci_config_space_reinit(
    ncp_dev_hdl_t devHdl)       /* IN: Device handle */
{
    ncp_ioc_status_t status;
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    status.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(status.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_PCI_REINIT, &status) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}

ncp_st_t
ncp_dev_isr_disable(
    ncp_dev_hdl_t devHdl)       /* IN: Device handle */
{
    ncp_ioc_status_t status;
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    status.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(status.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_ISR_DISABLE, &status) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}

ncp_st_t
ncp_dev_reset(
    ncp_dev_hdl_t devHdl)       /* IN: Device handle */
{
    ncp_ioc_status_t status;
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    status.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(status.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_RESET, &status) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}

ncp_st_t
ncp_dev_pci_reset(
    ncp_dev_hdl_t devHdl)       /* IN: Device handle */
{
    ncp_ioc_status_t status;
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    status.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(status.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_PCI_RESET, &status) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}


int
ncp_dev_fd_get(
    ncp_dev_hdl_t devHdl)       /*   IN: Device handle */
{
    return (intptr_t) devHdl;
}

ncp_st_t
ncp_dev_num_get(
    ncp_dev_hdl_t devHdl,    /* IN: Device handle */
    ncp_uint32_t *devNum)        /* OUT: Device number */
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_dev_num_get_t ioc;

    ioc.NCP_POINTER(devNum) = devNum;
    ioc.NCP_POINTER(st)     = &ncpStatus;

    NCP_POINTER_FIXUP(ioc.NCP_POINTER_64(devNum));
    NCP_POINTER_FIXUP(ioc.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_DEV_NUM_GET, &ioc) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}


ncp_st_t
ncp_dev_alarm_irq_get(
        ncp_dev_hdl_t   devHdl,
        ncp_bool_t      blocking,
        ncp_alarm_bitmask_t     *alarm)
{
    ncp_st_t    ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_alarm_t al;

    al.blocking = blocking;
    al.NCP_POINTER(alarm) = alarm;
    al.NCP_POINTER(st)    = &ncpStatus;

    NCP_POINTER_FIXUP(al.NCP_POINTER_64(alarm));
    NCP_POINTER_FIXUP(al.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_ALARM_IRQ_GET, &al) == -1) 
    {
        return ncp_status_code();
    }

    return ncpStatus;
}

ncp_st_t
ncp_dev_se_fem_event_get(ncp_dev_hdl_t devHdl)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    if ((ncpStatus = ioctl((intptr_t)devHdl, NCP_IOC_SE_FEM_WAIT_FOR_INTERRUPT, NULL)) == -1)
    {
        if (0 != errno)
        {    
            NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_se_fem_wait_for_interrupt_failed, NCP_MSG_ERROR,
                           "NCP_IOC_SE_FEM_WAIT_FOR_INTERRUPT failed with errno=0x%x for handle %p\r\n",
                           errno, devHdl);
            NCP_CALL(NCP_ST_ERROR);
        }    
    }  

NCP_RETURN_LABEL
    return(ncpStatus);
}

ncp_st_t
ncp_dev_timer_sync_external(ncp_dev_hdl_t devHdl)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    if ((ncpStatus = ioctl((intptr_t)devHdl, NCP_IOC_TIMER_SYNC_EXTERNAL, NULL)) == -1)
    {
        if (0 != errno)
        {
            NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_timer_sync_external_failed, NCP_MSG_ERROR,
                           "NCP_IOC_TIMER_SYNC_EXTERNAL failed with errno=0x%x for handle %p\r\n",
                           errno, devHdl);
            NCP_CALL(NCP_ST_ERROR);
        }
    }

NCP_RETURN_LABEL
    return(ncpStatus);
}

ncp_st_t
ncp_dev_timer_event_get(ncp_dev_hdl_t devHdl, ncp_uint64_t *ticks)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_timestamp_t ts;

    ts.NCP_POINTER(ticks) = ticks;
    ts.NCP_POINTER(st) = 0;

    NCP_POINTER_FIXUP(ts.NCP_POINTER_64(ticks));
    NCP_POINTER_FIXUP(ts.NCP_POINTER_64(st));

    if ( ( ncpStatus = ioctl((intptr_t)devHdl, NCP_IOC_TIMER_WAIT_FOR_INTERRUPT, &ts)) == -1)
    {
        if (0 != errno)
        {    
            NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_timer_wait_for_interrupt_failed, NCP_MSG_ERROR,
                           "NCP_IOC_TIMER_WAIT_FOR_INTERRUPT failed with errno=0x%x for handle %p\r\n",
                           errno, devHdl);
            ncpStatus = NCP_ST_ERROR;
        }    
    }  

    return(ncpStatus);
}

ncp_st_t
ncp_dev_timer_cpu_timer_event_wait(ncp_hdl_t hdl, ncp_uint32_t timerIndex, ncp_uint64_t lastSeq, ncp_uint64_t *currentSeq, ncp_uint32_t flags)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_cpu_timer_info_t cpu_info = {0};
    ncp_t *ncp = (ncp_t *)hdl;
    ncp_dev_hdl_t devHdl = ncp_dev_hdls[ncp->id];
    NCP_TRACEPOINT (Intel_AXXIA_ncp_sal, ncp_dev_timer_cpu_timer_event_wait_sal_entry, NCP_MSG_ENTRY,
        "hdl=%p timerIndex=%d lastSeq=%" PRIu64 " currentSeq=%p flags=%d\n", 
        hdl, timerIndex, lastSeq, currentSeq, flags);

    cpu_info.lastSeq = lastSeq;
    cpu_info.NCP_POINTER(currentSeq) = currentSeq;
    cpu_info.flags = flags;
    cpu_info.timerIndex = timerIndex;

    NCP_POINTER_FIXUP(cpu_info.NCP_POINTER_64(currentSeq));
    NCP_POINTER_FIXUP(cpu_info.NCP_POINTER_64(st));

    if ( ( ncpStatus = ioctl((intptr_t)devHdl, NCP_IOC_TIMER_WAIT_FOR_CPU_INTERRUPT, &cpu_info)) == -1)
    {
        if (0 != errno)
        {    
            NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_timer_wait_for_cpu_interrupt_failed, NCP_MSG_ERROR,
                           "NCP_IOC_TIMER_WAIT_FOR_CPU_INTERRUPT failed with errno=0x%x for handle %p\r\n",
                           errno, devHdl);
            ncpStatus = NCP_ST_ERROR;
        }    
    }  

    NCP_TRACEPOINT (Intel_AXXIA_ncp_sal, ncp_dev_timer_cpu_timer_event_wait_sal_exit, NCP_MSG_EXIT,
                "ncpStatus=%d currentSeq=%"PRIu64 "\n", ncpStatus,
                currentSeq ? *currentSeq : 0);
    return(ncpStatus);
}

ncp_st_t
ncp_dev_eioa_hss_los_hdlr_start (ncp_hdl_t hdl,
                                      ncp_uint32_t timerInterval)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_eioa_hss_los_hdlr_t kCalStart;
    ncp_t *ncp = (ncp_t *)hdl;
    ncp_dev_hdl_t devHdl = ncp_dev_hdls[ncp->id];

    kCalStart.timerInterval = timerInterval;

    if ((ncpStatus = ioctl((intptr_t)devHdl, NCP_IOC_EIOA_HSS_LOS_HDLR_START, &kCalStart)) == -1)
    {
        if (0 != errno)
        {
            NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_eioa_hss_los_hdlr_start_failed, NCP_MSG_ERROR,
                           "NCP_IOC_EIOA_HSS_LOS_HDLR_START failed with errno=0x%x for handle %p\r\n",
                           errno, devHdl);
            NCP_CALL(NCP_ST_ERROR);
        }
    }

NCP_RETURN_LABEL
    return(ncpStatus);
}

ncp_st_t
ncp_dev_eioa_hss_los_hdlr_stop(ncp_hdl_t hdl)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_eioa_hss_los_hdlr_t kCalStart;
    ncp_t *ncp = (ncp_t *)hdl;
    ncp_dev_hdl_t devHdl = ncp_dev_hdls[ncp->id];

    if ((ncpStatus = ioctl((intptr_t)devHdl, NCP_IOC_EIOA_HSS_LOS_HDLR_STOP, &kCalStart)) == -1)
    {
        if (0 != errno)
        {
            NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_eioa_hss_los_hdlr_stop_failed, NCP_MSG_ERROR,
                           "NCP_IOC_EIOA_HSS_LOS_HDLR_STOP failed with errno=0x%x for handle %p\r\n",
                           errno, devHdl);
            NCP_CALL(NCP_ST_ERROR);
        }
    }

NCP_RETURN_LABEL
    return(ncpStatus);
} /* ncp_dev_eioa_hss_los_hdlr_stop() */


#ifdef SUPPORT_TRANSACTION_FNS
ncp_st_t
ncp_dev_transaction_start(
    ncp_dev_hdl_t devHdl)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_status_t status;
    NCP_TRACEPOINT (Intel_AXXIA_ncp_sal, ncp_dev_transaction_start_sal_entry, NCP_MSG_ENTRY,
        "devHdl=%p\n", devHdl);

    status.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(status.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_TRANS_START, &status) == -1)
    {
        ncpStatus=ncp_status_code();
    }

    NCP_TRACEPOINT (Intel_AXXIA_ncp_sal, ncp_dev_transaction_start_sal_exit, NCP_MSG_ENTRY,
        "ncpStatus=%d\n", ncpStatus);
    return ncpStatus;
}

ncp_st_t
ncp_dev_transaction_add(
    ncp_dev_hdl_t devHdl,
    ncp_dev_trans_type_t transType,
    void *trans,
    ncp_uint32_t flags)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_trans_add_t iocArg;
    NCP_TRACEPOINT (Intel_AXXIA_ncp_sal, ncp_dev_transaction_add_sal_entry, NCP_MSG_ENTRY,
        "devHdl=%p transType=%d trans=%p flags=%d\n", devHdl, transType, trans, flags);

    iocArg.flags = flags;
    iocArg.transType = transType;
    switch(transType)
    {
    case NCP_DEV_TRANS_UDELAY:
        iocArg.u.udelay = (ncp_dev_trans_udelay_t)trans;
        break;
    case NCP_DEV_TRANS_BLOCK_FILL32:
        iocArg.u.bf32 = *(ncp_dev_trans_block_fill32_t *)trans;
        break;
    case NCP_DEV_TRANS_CE_WRITE32:
    case NCP_DEV_TRANS_BLOCK_WRITE32:
    case NCP_DEV_TRANS_BLOCK_SCATTER32:
        iocArg.u.bw32 = *(ncp_dev_trans_block_write32_t *)trans;
        break;
    default:
        break;
    }

    iocArg.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(iocArg.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_TRANS_ADD, &iocArg) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}

ncp_st_t
ncp_dev_transaction_end(
    ncp_dev_hdl_t devHdl)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_status_t status;
    NCP_TRACEPOINT (Intel_AXXIA_ncp_sal, ncp_dev_transaction_end_sal_entry, NCP_MSG_ENTRY,
        "devHdl=%p\n", devHdl);

    status.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(status.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_TRANS_END, &status) == -1)
    {
        ncpStatus = ncp_status_code();
    }

    NCP_TRACEPOINT (Intel_AXXIA_ncp_sal, ncp_dev_transaction_end_sal_exit, NCP_MSG_ENTRY,
        "ncpStatus=%d\n", ncpStatus);
    return ncpStatus;
}
#endif

ncp_st_t
ncp_dev_event_dispatch_cfg_start(
    ncp_dev_hdl_t devHdl)    /* IN: Device handle */
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    if (ioctl((intptr_t)devHdl, NCP_IOC_EVENT_CFG_START, NULL) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}


ncp_st_t
ncp_dev_event_dispatch_cfg_complete(
    ncp_dev_hdl_t devHdl)    /* IN: Device handle */
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    if (ioctl((intptr_t)devHdl, NCP_IOC_EVENT_CFG_COMPLETE, NULL) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}

ncp_st_t
ncp_dev_event_dispatch_cfg_destroy(
    ncp_dev_hdl_t devHdl)    /* IN: Device handle */
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    if (ioctl((intptr_t)devHdl, NCP_IOC_EVENT_CFG_DESTROY, NULL) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}

#ifdef NCP_ARCH_ARM
#ifndef PROC_ARMA53 /* TEMP! not supported for XLF (yet?) */
ncp_st_t
ncp_display_mem_attributes(ncp_dev_hdl_t devHdl, void *va)
{
    ncp_st_t ncpStatus=NCP_ST_SUCCESS;
    ncp_task_display_mem_atttributes_t getAttrStruct;
    
    getAttrStruct.NCP_POINTER(va) = va;

    NCP_POINTER_FIXUP(getAttrStruct.NCP_POINTER_64(va));

    printf("Get Mem Attributes for va=%p\r\n",va);
    if ((ncpStatus = ioctl((intptr_t)devHdl, NCP_IOC_TASK_DISPLAY_MEM_ATTTRIBUTES, &getAttrStruct)) == -1) 
    {
        NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_task_display_mem_attributes_failed, NCP_MSG_ERROR,
                       "NCP_IOC_TASK_DISPLAY_MEM_ATTTRIBUTES failed with errno=0x%x for handle %p\r\n",
                       ncpStatus, devHdl);
        NCP_CALL(NCP_ST_ERROR);
    }   
    
NCP_RETURN_LABEL
    return(ncpStatus);       
}    
#endif
#endif

ncp_st_t ncp_task_initiate_shutdown(ncp_dev_hdl_t devHdl)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    if ((ncpStatus = ioctl((intptr_t)devHdl, NCP_IOC_TASK_INITIATE_SHUTDOWN , NULL)) == -1)
    {
        if (0 != errno)
        {    
            NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_task_initiate_shutdown_failed, NCP_MSG_ERROR,
                           "NCP_IOC_TASK_INITIATE_SHUTDOWN failed with errno=0x%x for handle %p\r\n",
                           errno, devHdl);
            NCP_CALL(NCP_ST_ERROR);
        }    
    }  

NCP_RETURN_LABEL
    return(ncpStatus);        
}

/* only called it application is required to run in 32bit mode */
ncp_st_t ncp_dev_appMode_is32bit(ncp_dev_hdl_t devHdl)
{
    ncp_ioc_status_t data;
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    
    ncp_memset(&data, 0, sizeof(ncp_ioc_status_t));
    if ((ncpStatus = ioctl((intptr_t)devHdl, NCP_IOC_APPMODE_IS32BIT , &data)) == -1)
    {
        if (0 != errno)
        {    
            NCP_TRACEPOINT(Intel_AXXIA_ncp_sal,
                           ncp_sal_dev_appMode_is32bit_failed, NCP_MSG_ERROR,
                           "NCP_IOC_TASK_APPMODE_IS32BIT  failed with errno=0x%x for handle %p\r\n",
                           errno, devHdl);
            NCP_CALL(NCP_ST_ERROR);
        }    
    }  

NCP_RETURN_LABEL
    return(ncpStatus);        
}

#if (1 == USE_NCA)
ncp_st_t ncp_task_manage_kmode_stats(
    ncp_hdl_t ncpHdl,
    ncp_task_manage_stats_cmd_t cmd,        /* Internally supplied - request type */
    void                        *pStats,    /* IN/OUT - location to copy kmode stats to */
    ncp_int32_t                 sizeStats,  /* IN - size of stats struct */
    ncp_uint8_t                 poolId)     /* IN,  which CPU Pool */
{
    ncp_st_t        ncpStatus = NCP_ST_SUCCESS;
    ncp_t           *ncp = (ncp_t *)ncpHdl;
    ncp_dev_hdl_t   devHdl = ncp_dev_hdls[ncp->id];
    ncp_ioc_get_task_stats_t ioc_get_task_stats;
    
    ioc_get_task_stats.cmd                = (ncp_int32_t)cmd;
    ioc_get_task_stats.poolId             = poolId;
    ioc_get_task_stats.copySize           = sizeStats;
    ioc_get_task_stats.NCP_POINTER(pTaskStats) = pStats;
    ioc_get_task_stats.NCP_POINTER(st)    = &ncpStatus;
 
    NCP_POINTER_FIXUP(ioc_get_task_stats.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(ioc_get_task_stats.NCP_POINTER_64(pTaskStats));
    
    if (ioctl((intptr_t)devHdl, NCP_IOC_TASK_MANAGE_KMODE_STATS, &ioc_get_task_stats) == -1)
    {
        NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_task_manage_kmode_stats_failed, NCP_MSG_INFO,
                       "NCP_IOC_TASK_MANAGE_KMODE_STATS failed with ec=%d, sc=%d\r\n",
                       ncpStatus, ncp_status_code());

        return ncp_status_code();
    }

    return ncpStatus;
}
#endif

ncp_st_t ncp_task_tqs_state_modify(ncp_dev_hdl_t devHdl,
                                   ncp_uint8_t grp,
                                   ncp_uint8_t tqsID,
                                   ncp_bool_t  disableTQS)

{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_tqs_state_modify_t tqs_state_modify;    

    tqs_state_modify.tqsID      = tqsID;      
    tqs_state_modify.disableTQS = disableTQS;
    tqs_state_modify.grp        = grp;   
    tqs_state_modify.NCP_POINTER(st)   = &ncpStatus;
    
    NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_task_tqs_state_modify_entry, NCP_MSG_DEBUG,
                   "NCP_IOC_TASK_TQS_STATE_MODIFY tqs=%hhd. grp=%hhd, disab=%d\r\n",
                   tqsID, grp, disableTQS);

    NCP_POINTER_FIXUP(tqs_state_modify.NCP_POINTER_64(st));

    if ((ncpStatus = ioctl((intptr_t)devHdl, 
                            NCP_IOC_TASK_TQS_STATE_MODIFY, 
                            &tqs_state_modify)) == -1)
    {
        if (0 != errno)
        {    
            NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_task_tqs_state_modify_failed, NCP_MSG_ERROR,
                           "NCP_IOC_TASK_TQS_STATE_MODIFY failed with errno=0x%x for handle %p\r\n",
                           errno, devHdl);
            NCP_CALL(NCP_ST_ERROR);
        }
        else
        {
            NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_task_tqs_state_modify_failed_errno_zero, NCP_MSG_ERROR,
                           "NCP_IOC_TASK_TQS_STATE_MODIFY failed with errno=0, st=%d!\r\n",
                           ncpStatus);
        }    
    }  
    else
    {
        NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_task_tqs_state_modify_success,
                       NCP_MSG_DEBUG, "NCP_IOC_TASK_TQS_STATE_MODIFY success!\r\n");
    }        
                 
NCP_RETURN_LABEL
    return(ncpStatus);    
}    

ncp_st_t
ncp_task_waiter_thread_operation(
    ncp_dev_hdl_t devHdl,
    ncp_uint32_t  opCode,
    ncp_uint32_t  poolID,
    ncp_uint32_t  pid)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_waiter_operation_t ioc;

    ioc.NCP_POINTER(st) = &ncpStatus;
    ioc.opCode = opCode;
    ioc.poolID = poolID;
    ioc.pid = pid;

    NCP_POINTER_FIXUP(ioc.NCP_POINTER_64(st));

    if (ioctl((intptr_t) devHdl,
                NCP_IOC_TASK_WAITER_THREADS_OP,
                &ioc) == -1)
    {
        if (0 != errno)
        {
            NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_task_waiter_threads_op_failed,
                           NCP_MSG_ERROR, "[%s()] failed with errno=0x%x for handle %p\n",
                           __func__, errno, devHdl);
            return ncp_status_code();
        }
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t ncp_task_register_grp_interrupts(ncp_dev_hdl_t devHdl,
                                          ncp_uint32_t  activeGrpMask)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_u32_t ioc_u32;

    ioc_u32.value = activeGrpMask;
    ioc_u32.NCP_POINTER(st) = &ncpStatus;
    
    NCP_POINTER_FIXUP(ioc_u32.NCP_POINTER_64(st));

    if ((ioctl((intptr_t)devHdl, NCP_IOC_TASK_REGISTER_GRP_INTERRUPTS , &ioc_u32)) == -1)
    {
        if (0 != errno)
        {    
            NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_task_register_grp_interrupts_failed, NCP_MSG_ERROR,
                           "ncp_task_register_grp_interrupts failed with errno=0x%x for handle %p\r\n",
                           errno, devHdl);
            return ncp_status_code();
        }    
    }  

NCP_RETURN_LABEL
    return(ncpStatus);        
}

ncp_st_t ncp_task_register_ncav3_interrupts(
    ncp_dev_hdl_t devHdl,
    ncp_uint64_t  activeTQSMask)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_u64_t ioc_u64;

    ioc_u64.value = activeTQSMask;
    ioc_u64.NCP_POINTER(st) = &ncpStatus;
    
    NCP_POINTER_FIXUP(ioc_u64.NCP_POINTER_64(st));

    if ((ioctl((intptr_t)devHdl, NCP_IOC_TASK_REGISTER_NCAV3_INTERRUPTS, &ioc_u64))
            == -1)
    {
        if (0 != errno)
        {    
            NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_task_register_ncav3_interrupts_failed, NCP_MSG_ERROR,
                           "ncp_task_register_grp_interrupts failed with errno=0x%x for handle %p\r\n",
                           errno, devHdl);
            return ncp_status_code();
        }    
    }  

NCP_RETURN_LABEL

    return ncpStatus;        
}

ncp_st_t
ncp_task_finish_kmode_config(ncp_hdl_t ncpHdl,
                             ncp_uint32_t kmodePoolSz,
                             ncp_dev_gsm_info_t *pGSMinfo) 
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_t *ncp = (ncp_t *)ncpHdl;
    ncp_ioc_task_nca_kmode_finish_cfg_t kmodeFinishCfg;
    ncp_dev_hdl_t devHdl = ncp_dev_hdls[ncp->id];

    kmodeFinishCfg.NCP_POINTER(st)      = &ncpStatus; 
    kmodeFinishCfg.kmodePoolSz          = kmodePoolSz;
    kmodeFinishCfg.NCP_POINTER(pGSMinfo) = pGSMinfo;

    NCP_POINTER_FIXUP(kmodeFinishCfg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(kmodeFinishCfg.NCP_POINTER_64(pGSMinfo));

    NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_task_nca_finish_kmode_cfg_issued, NCP_MSG_DEBUG,
                   "NCP_IOC_TASK_NCA_FINISH_KMODE_CFG issued with buf=%p, st=%p\r\n",
                   &kmodeFinishCfg, kmodeFinishCfg.NCP_POINTER(st));

    if ((ioctl((intptr_t)devHdl, NCP_IOC_TASK_NCA_FINISH_KMODE_CFG , &kmodeFinishCfg)) == -1) 
    {
        NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_task_nca_finish_kmode_cfg_failed, NCP_MSG_ERROR,
                       "NCP_IOC_TASK_NCA_FINISH_KMODE_CFG failed with errno=0x%x for handle %p\r\n",
                       ncpStatus, devHdl);
        NCP_CALL(NCP_ST_ERROR);
    }  
    if (NCP_ST_SUCCESS != ncpStatus)
    {
        NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_task_nca_finish_kmode_cfg_failed, NCP_MSG_ERROR,
                       "NCP_IOC_TASK_NCA_FINISH_KMODE_CFG failed with err=0x%x for handle %p\r\n",
                       ncpStatus, devHdl);
        NCP_CALL(ncpStatus);
    }      
    
NCP_RETURN_LABEL
    return(ncpStatus);        
}   

ncp_st_t
ncp_task_do_kmode_config(ncp_hdl_t ncpHdl,
                         void *pSwState,
                         ncp_int32_t  sizeSwState,
                         ncp_dev_gsm_info_t *pGSMinfo)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_t *ncp = (ncp_t *)ncpHdl;
    ncp_ioc_task_nca_kmode_cfg_t kmodeCfg;
    ncp_dev_hdl_t devHdl = ncp_dev_hdls[ncp->id];

    kmodeCfg.NCP_POINTER(cfgPtr)  = pSwState;
    kmodeCfg.cfgSize = sizeSwState;
    
    kmodeCfg.NCP_POINTER(st)       = &ncpStatus; 
    kmodeCfg.NCP_POINTER(pGSMinfo) = pGSMinfo;   
    
    NCP_POINTER_FIXUP(kmodeCfg.NCP_POINTER_64(cfgPtr));
    NCP_POINTER_FIXUP(kmodeCfg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(kmodeCfg.NCP_POINTER_64(pGSMinfo));

    NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_task_nca_do_kmode_cfg_issued, NCP_MSG_DEBUG,
                   "NCP_IOC_TASK_NCA_DO_KMODE_CFG issued with buf=%p, cfgSize=%d, st=%p\r\n",
                   &kmodeCfg, kmodeCfg.cfgSize, kmodeCfg.NCP_POINTER(st));

    if (((ioctl((intptr_t)devHdl, NCP_IOC_TASK_NCA_DO_KMODE_CFG , &kmodeCfg)) == -1))
    {
        NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_task_nca_do_kmode_cfg_ioctl_failed, NCP_MSG_ERROR,
                       "NCP_IOC_TASK_NCA_DO_KMODE_CFG failed with errno=0x%x for handle %p\r\n",
                       (unsigned int)ncpStatus, devHdl);
        NCP_CALL(NCP_ST_ERROR);
    }  
    if (NCP_ST_SUCCESS != ncpStatus)
    {
        NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_task_nca_do_kmode_cfg_failed, NCP_MSG_ERROR,
                       "NCP_IOC_TASK_NCA_DO_KMODE_CFG failed with err=0x%x for handle %p\r\n",
                       ncpStatus, devHdl);
        NCP_CALL(ncpStatus);
    }  
    
NCP_RETURN_LABEL
    return(ncpStatus);        
}    


#undef NCP_TASK_DBG_ISR_LATENCY

ncp_st_t ncp_task_block_on_hw_interrupt(ncp_dev_hdl_t devHdl, ncp_uint32_t intrType, 
                                        ncp_uint8_t grp, ncp_uint32_t grpRelQueueId, ncp_uint8_t tqsID)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_interrupt_t waitIntr;
#if defined(NCP_ARCH_ARM) && defined(NCP_TASK_DBG_ISR_LATENCY)
    struct timeval                  sTime = {0};
    struct timeval                  eTime = {0};
    double                          timeSec;
#endif    

    waitIntr.intrType   = intrType;
    waitIntr.grp        = grp;  
    waitIntr.grpRelQueueId   = grpRelQueueId;  
    waitIntr.tqsID           = tqsID;
    
#if 0 /* DEBUG */   
    NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_task_block_on_hw_interrupt, NCP_MSG_INFO,
                   "TaskIO Wait Type=%d, grp=%d, grpRel=%d, tqs(s)=%d\r\n",
                   (int)intrType, (int)grp, (int)grpRelQueueId, (int)tqsID);
#endif
                        
#if defined(NCP_ARCH_ARM) && defined(NCP_TASK_DBG_ISR_LATENCY)
/* Get start time */
gettimeofday(&sTime, NULL);    
#endif    
    if ((ncpStatus = ioctl((intptr_t)devHdl, NCP_IOC_TASK_WAIT_FOR_INTERRUPT, &waitIntr)) == -1)
    {
        if (0 != errno)
        {    
            NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_ioc_task_wait_for_interrupt_failed, NCP_MSG_ERROR,
                           "NCP_IOC_TASK_WAIT_FOR_INTERRUPT failed with errno=0x%x for handle %p\r\n",
                           errno, devHdl);
            NCP_CALL(NCP_ST_ERROR);
        }    
    }  
    else
    {

#if defined(NCP_ARCH_ARM) && defined(NCP_TASK_DBG_ISR_LATENCY)
/* Get start time */
gettimeofday(&eTime, NULL);    
timeSec = (double)(eTime.tv_sec  - sTime.tv_sec) +
          (double)(eTime.tv_usec  - sTime.tv_usec) / 1000000.0;
printf("IRQ Latency @ APP: %.9f seconds\r\n",timeSec); 
gettimeofday(&sTime, NULL);
gettimeofday(&eTime, NULL);    
timeSec = (double)(eTime.tv_sec  - sTime.tv_sec) +
          (double)(eTime.tv_usec  - sTime.tv_usec) / 1000000.0;
printf("Measurement overhead is: %.9f seconds\r\n",timeSec);           
#endif   

    }    

NCP_RETURN_LABEL
    return(ncpStatus);        
}

void *
ncp_mem_mmap(ncp_dev_hdl_t devHdl, void *startAddr, ncp_uint32_t size, 
             ncp_uint64_t physAddr)
{
    void *mmapPtr = NULL;

    mmapPtr = mmap(startAddr, size, (PROT_READ | PROT_WRITE), MAP_SHARED,
                           (intptr_t)devHdl, (off_t) physAddr);
    
    if (((NULL != startAddr) && (startAddr != mmapPtr)) || (NULL == mmapPtr))
    {
        NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_mem_mmap_failed, NCP_MSG_ERROR,
                       "ncp_mem_mmap(): mmap failed startAddr=%p, retAddr=%p, physAddr=0x%s, size=0x%x, errno=0x%x\r\n",
                       startAddr, mmapPtr,
                       NCP_CONVERT_LONG_TO_HEX_STR_FORMAT("%012", physAddr),
                       size, errno);
        perror("mmap");
        if (mmapPtr)
        {
            munmap(mmapPtr, size);
        }
        mmapPtr = NULL; /* so caller see's the error */
    }
    else
    {
        NCP_TRACEPOINT(Intel_AXXIA_ncp_sal, ncp_sal_mem_mmap_success, NCP_MSG_DEBUG,
                       "ncp_mem_mmap(): mmap success:  startAddr=%p, retAddr=%p, physAddr=0x%s, size=0x%x, errno=0x%x\r\n",
                       startAddr, mmapPtr,
                       NCP_CONVERT_LONG_TO_HEX_STR_FORMAT("%012", physAddr),
                       size, errno);
    }

NCP_RETURN_LABEL
    return mmapPtr;
}

ncp_st_t
ncp_dev_mdioRead(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_region_id_t regionId,   /* IN: Node/target address */
    ncp_uint64_t offset,        /* IN: Device/Register number */
    ncp_uint32_t *buffer,       /* OUT: Return location for read data */
    ncp_uint32_t count,         /* IN: Number of 32-bit words to read */
    ncp_uint32_t flags)         /* IN: Operational control flags */
{
    ncp_ioc_rw_t rw;
    ncp_st_t         ncpStatus = NCP_ST_SUCCESS;

    rw.regionId = regionId;
    rw.offset   = offset;
    rw.NCP_POINTER(buffer) = (void *)buffer;
    rw.count    = count;
    rw.flags    = flags;
    rw.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(buffer));
    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_MDIO_READ, &rw) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}

ncp_st_t
ncp_dev_mdioWrite(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_region_id_t regionId,   /* IN: Node/target address */
    ncp_uint64_t offset,        /* IN: Device/Register number */
    ncp_uint32_t *buffer,       /* IN: Write data */
    ncp_uint32_t count,         /* IN: Number of 32-bit words to read */
    ncp_uint32_t flags)         /* IN: Operational control flags */
{
    ncp_ioc_rw_t rw;
    ncp_st_t         ncpStatus = NCP_ST_SUCCESS;

    rw.regionId = regionId;
    rw.offset   = offset;
    rw.NCP_POINTER(buffer) = (void *)buffer;
    rw.count    = count;
    rw.flags    = flags;
    rw.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(buffer));
    NCP_POINTER_FIXUP(rw.NCP_POINTER_64(st));

    if (ioctl((intptr_t)devHdl, NCP_IOC_MDIO_WRITE, &rw) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}


#if (1 == USE_EIOAXLF)
ncp_st_t
ncp_dev_nrcp_event_wait(
    ncp_dev_hdl_t devHdl,       /* IN: Device handle */
    ncp_uint32_t *nrcpIntrStat) /* OUT: NRCP interrupt status */
{
    ncp_st_t           ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_info_get_t ioc_info;

    ioc_info.NCP_POINTER(info) = nrcpIntrStat;
    ioc_info.NCP_POINTER(st)   = &ncpStatus;

    NCP_POINTER_FIXUP(ioc_info.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(ioc_info.NCP_POINTER_64(info));

    if (ioctl((intptr_t)devHdl, NCP_IOC_NRCP_EVENT_WAIT, &ioc_info) == -1)
    {
        return ncp_status_code();
    }

    return ncpStatus;
}
#endif

/* ------------------------------------------------------------------------- */
/*
 * BEGIN: CAT interface functions
 */

ncp_st_t
ncp_dev_cat_config(
    ncp_dev_hdl_t devHdl,            /* IN: Device handle */
    ncp_bool_t    catMemoryEnable,   /* IN: Enable use of CAT */
    ncp_uint64_t  catMemoryPhysAddr, /* IN: Start of memory to use for CAT */
    ncp_uint64_t  catMemorySize,     /* IN: Size of memory to use for CAT */
    ncp_uint64_t *oCatMemoryNeeded)  /* OUT: Min memory needed for CAT */
{
    ncp_st_t              ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_cat_config_t  cfg;

    cfg.catMemoryEnable               = catMemoryEnable;
    cfg.catMemoryPhysAddr             = catMemoryPhysAddr;
    cfg.catMemorySize                 = catMemorySize;
    cfg.NCP_POINTER(oCatMemoryNeeded) = oCatMemoryNeeded;
    cfg.NCP_POINTER(ncp_status)       = &ncpStatus;

    NCP_POINTER_FIXUP(cfg.NCP_POINTER_64(oCatMemoryNeeded));
    NCP_POINTER_FIXUP(cfg.NCP_POINTER_64(ncp_status));

    if (ioctl((intptr_t)devHdl, NCP_IOC_CAT_CONFIG, &cfg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL
    return ncpStatus;
}

ncp_st_t
ncp_dev_cat_write(
    ncp_dev_hdl_t           devHdl)
{
    ncp_st_t            ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_cat_write_t wr;

    wr.flags                   = 0;
    wr.NCP_POINTER(ncp_status) = &ncpStatus;

    NCP_POINTER_FIXUP(wr.NCP_POINTER_64(ncp_status));

    if (ioctl((intptr_t)devHdl, NCP_IOC_CAT_WRITE, &wr) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL
    return ncpStatus;
}

ncp_st_t
ncp_dev_cat_write_raw(
    ncp_dev_hdl_t       devHdl,
    ncp_uint32_t        count,
    void               *buffer)
{
    ncp_st_t            ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_cat_write_raw_t wr;

    wr.count      = count;
    wr.NCP_POINTER(buffer) = buffer;
    wr.flags      = 0;
    wr.NCP_POINTER(ncp_status) = &ncpStatus;

    NCP_POINTER_FIXUP(wr.NCP_POINTER_64(ncp_status));
    NCP_POINTER_FIXUP(wr.NCP_POINTER_64(buffer));

    if (ioctl((intptr_t)devHdl, NCP_IOC_CAT_WRITE_RAW, &wr) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL
    return ncpStatus;
}

ncp_st_t
ncp_dev_cat_write_finalize(
    ncp_dev_hdl_t           devHdl)
{
    ncp_st_t            ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_cat_write_finalize_t wr;

    wr.flags                   = 0;
    wr.NCP_POINTER(ncp_status) = &ncpStatus;

    NCP_POINTER_FIXUP(wr.NCP_POINTER_64(ncp_status));

    if (ioctl((intptr_t)devHdl, NCP_IOC_CAT_WRITE_FINALIZE, &wr) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL
    return ncpStatus;
}

ncp_st_t
ncp_dev_cat_read(
    ncp_dev_hdl_t       devHdl,
    ncp_uint8_t        *buffer,
    ncp_uint32_t        bufferSize,
    ncp_uint64_t       *offset,
    ncp_uint32_t       *readSize)
{
    ncp_st_t            ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_cat_read_t  rd;

    rd.NCP_POINTER(buffer) = (void*)buffer;
    rd.bufferSize          = bufferSize;
    rd.NCP_POINTER(offset) = offset;
    rd.NCP_POINTER(readSize) = (void*)readSize;
    rd.flags               = 0;
    rd.NCP_POINTER(ncp_status) = &ncpStatus;

    NCP_POINTER_FIXUP(rd.NCP_POINTER_64(buffer));
    NCP_POINTER_FIXUP(rd.NCP_POINTER_64(offset));
    NCP_POINTER_FIXUP(rd.NCP_POINTER_64(readSize));
    NCP_POINTER_FIXUP(rd.NCP_POINTER_64(ncp_status));

    if (ioctl((intptr_t)devHdl, NCP_IOC_CAT_READ, &rd) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL
    return ncpStatus;
}

ncp_st_t
ncp_dev_cat_size(
    ncp_dev_hdl_t      devHdl,
    ncp_uint64_t      *catMemorySize)
{
    ncp_st_t           ncpStatus = NCP_ST_SUCCESS;
    ncp_ioc_cat_size_t sz;

    sz.NCP_POINTER(catMemorySize) = (ncp_uint32_t *)catMemorySize;
    sz.NCP_POINTER(ncp_status)    = &ncpStatus;

    NCP_POINTER_FIXUP(sz.NCP_POINTER_64(catMemorySize));
    NCP_POINTER_FIXUP(sz.NCP_POINTER_64(ncp_status));

    if (ioctl((intptr_t)devHdl, NCP_IOC_CAT_SIZE, &sz) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL
    return ncpStatus;
}


/* ------------------------------------------------------------------------- */

/*
 * Daemonize ourself.
 * Prevent ncpCfgTool from being marked defunct and hanging up tclsh exec
 * if executed programatically.
 */ 
ncp_st_t
ncp_daemonize_self(void)
{
    ncp_st_t ncpStatus=NCP_ST_SUCCESS;
    pid_t sid;
         
    /* Change the file mode mask */
    umask(0);
    
    /* Create a new SID for the child process */
    
    sid = setsid();
    if (sid < 0)
    {
        NCP_CALL(NCP_ST_SAL_SSID_FAILURE);
    }
    
    /* Change the current working directory.  This prevents the current
       directory from being locked; hence not being able to remove it. */
    if ((chdir("/")) < 0)
    {
        NCP_CALL(NCP_ST_SAL_CHDIR_FAILURE);
    }
    
    /* Redirect standard files to /dev/null */
    freopen( "/dev/null", "r", stdin);
    freopen( "/dev/null", "w", stdout);
    freopen( "/dev/null", "w", stderr);
        
NCP_RETURN_LABEL        
    return(ncpStatus);
}

#if (1 == USE_NCAV3)
ncp_st_t
ncp_ncav3_config_kernel(
    ncp_t                    *ncp,
    ncp_ncav3_hdl_t          *nca,
    ncp_dev_hdl_t             dev,
    ncp_ncav3_struct_sizes_t  sizes,
    ncp_bool_t                internal)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_cfg_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.NCP_POINTER(nca) = nca;
    arg.NCP_POINTER(swState) = pNcpTaskSwState;
    arg.structSizes = sizes;
    arg.internal = internal;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(nca));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(swState));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_CFG, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return(ncpStatus);
}

ncp_st_t
ncp_ncav3_kernel_destroy(
    ncp_t        *ncp,
    ncp_dev_hdl_t dev)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_cfg_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_KERNEL_DESTROY, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return(ncpStatus);
}

ncp_st_t
ncp_ncav3_enable_ipcq(
    ncp_dev_hdl_t dev,
    ncp_uint8_t   ncapId,
    ncp_uint8_t   relTqsId,
    ncp_uint8_t   pgitId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_ipcq_modify_t arg;

    /*
     * This function performs a read-modify-write operation on the ITP's IPCQ
     * online and IPCQ valid registers. Since user- and kernel-space could call
     * this (or disable_ipcq) at any time, their accesses must be synchronized.
     * Hence, the operation is centralized in the kernel module.
     */

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.ncapId = ncapId;
    arg.relTqsId = relTqsId;
    arg.pgitId = pgitId;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_ENABLE_IPCQ, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return(ncpStatus);
}

ncp_st_t
ncp_ncav3_disable_ipcq(
    ncp_dev_hdl_t dev,
    ncp_uint8_t   ncapId,
    ncp_uint8_t   relTqsId,
    ncp_uint8_t   pgitId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_ipcq_modify_t arg;

    /*
     * This function performs a read-modify-write operation on the ITP's IPCQ
     * online and IPCQ valid registers. Since user- and kernel-space could call
     * this (or enable_ipcq) at any time, their accesses must be synchronized.
     * Hence, the operation is centralized in the kernel module.
     */

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.ncapId = ncapId;
    arg.relTqsId = relTqsId;
    arg.pgitId = pgitId;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_DISABLE_IPCQ, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return(ncpStatus);
}

ncp_st_t
ncp_ncav3_get_qpm_stats(
    ncp_dev_hdl_t  dev,
    ncp_uint16_t   queueId,
    ncp_uint64_t  *fullQueue,
    ncp_uint64_t  *emptyQueue,
    ncp_uint64_t  *overflow)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_GET_QPM_STATS;
    arg.v[0] = queueId;
    arg.p[0] = (void *) fullQueue;
    arg.p[1] = (void *) emptyQueue;
    arg.p[2] = (void *) overflow;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 1));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 2));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return(ncpStatus);
}

ncp_st_t
ncp_ncav3_enable_kernel_tqs(
    ncp_dev_hdl_t dev,
    ncp_uint16_t  tqsId,
    ncp_bool_t    enable)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_ENABLE_KERNEL_TQS;
    arg.v[0] = tqsId;
    arg.v[1] = enable;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return(ncpStatus);
}

ncp_st_t
ncp_ncav3_nca_queue_disable(
    ncp_dev_hdl_t dev,
    ncp_uint32_t  queueId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_DISABLE_NCA_QUEUE;
    arg.v[0] = queueId;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return(ncpStatus);
}

ncp_st_t
ncp_ncav3_nca_queue_enable(
    ncp_dev_hdl_t dev,
    ncp_uint32_t  queueId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_ENABLE_NCA_QUEUE;
    arg.v[0] = queueId;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return(ncpStatus);
}

ncp_st_t
ncp_ncav3_queue_group_add(
    ncp_dev_hdl_t dev,
    ncp_uint32_t queueGroupId,
    ncp_task_resource_name_t *name,
    ncp_ncav3_recv_queue_type_t ordering)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_ADD_QUEUE_GROUP;
    arg.v[0] = queueGroupId;
    arg.p[0] = name;
    arg.v[1] = ordering;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return(ncpStatus);
}

ncp_st_t
ncp_ncav3_queue_group_delete(
    ncp_dev_hdl_t dev,
    ncp_uint32_t queueGroupId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_DELETE_QUEUE_GROUP;
    arg.v[0] = queueGroupId;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return(ncpStatus);
}

ncp_st_t
ncp_ncav3_queue_group_modify(
    ncp_dev_hdl_t dev,
    ncp_uint32_t queueGroupId,
    ncp_ncav3_recv_queue_type_t ordering)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_MODIFY_QUEUE_GROUP;
    arg.v[0] = queueGroupId;
    arg.v[1] = ordering;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_nca_queue_group_set(
    ncp_dev_hdl_t dev,
    ncp_uint32_t ncaQueueId,
    ncp_uint32_t queueGroupId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_SET_NCA_QUEUE_GROUP;
    arg.v[0] = ncaQueueId;
    arg.v[1] = queueGroupId;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_tqs_queue_group_set(
    ncp_dev_hdl_t dev,
    ncp_uint32_t tqsId,
    ncp_task_queue_group_set_t pGrp[8],
    ncp_uint8_t numQueueGroups)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_SET_TQS_QUEUE_GROUPS;
    arg.v[0] = tqsId;
    arg.p[0] = pGrp;
    arg.v[1] = numQueueGroups;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_nca_queue_configure(
    ncp_dev_hdl_t dev,
    ncp_uint32_t ncaQueueId,
    ncp_task_resource_name_t *queueName,
    ncp_task_resource_name_t *queueProfileName,
    ncp_int32_t queueGroupId,
    ncp_uint32_t paramsSize,
    ncp_task_nca_queue_sched_params_t *params)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_CONFIGURE_NCA_QUEUE;
    arg.v[0] = ncaQueueId;
    arg.p[0] = queueName;
    arg.p[1] = queueProfileName;
    arg.v[1] = queueGroupId;
    arg.v[2] = paramsSize;
    arg.p[2] = params;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 1));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 2));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_tqs_configure_flags_get(
    ncp_dev_hdl_t dev,
    ncp_uint32_t  tqsId,
    ncp_task_tqs_shared_t *pFlags)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_TQS_CONFIGURE_FLAGS_GET;
    arg.v[0] = tqsId;
    arg.p[0] = pFlags;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_tqs_memory_quota_group_get(
    ncp_dev_hdl_t dev,
    ncp_uint32_t tqsId,
    ncp_uint32_t *pMemoryQuotaGroupId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_TQS_MEMORY_QUOTA_GROUP_GET;
    arg.v[0] = tqsId;
    arg.p[0] = pMemoryQuotaGroupId;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_tqs_queue_group_get(
    ncp_dev_hdl_t dev,
    ncp_uint32_t tqsId,
    ncp_task_queue_group_set_t pGrp[8],
    ncp_uint8_t *pNumQueueGroups)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_TQS_QUEUE_GROUP_GET;
    arg.v[0] = tqsId;
    arg.p[0] = pGrp;
    arg.p[1] = pNumQueueGroups;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 1));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_queue_group_membership_get(
    ncp_dev_hdl_t  dev,
    ncp_uint32_t   ncaQueueId,
    ncp_uint32_t  *pQueueGroupId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_QUEUE_GROUP_MEMBERSHIP_GET;
    arg.v[0] = ncaQueueId;
    arg.p[0] = pQueueGroupId;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_queue_group_name_get(
    ncp_dev_hdl_t dev,
    ncp_uint32_t queueGroupId,
    ncp_task_resource_name_t *name)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_QUEUE_GROUP_NAME_GET;
    arg.v[0] = queueGroupId;
    arg.p[0] = name;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_tqs_name_get(
    ncp_dev_hdl_t dev,
    ncp_uint32_t tqsId,
    ncp_task_resource_name_t *pResourceName)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_TQS_NAME_GET;
    arg.v[0] = tqsId;
    arg.p[0] = pResourceName;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_nca_queue_name_get(
    ncp_dev_hdl_t dev,
    ncp_uint32_t ncaQueueId,
    ncp_task_resource_name_t *name)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_NCA_QUEUE_NAME_GET;
    arg.v[0] = ncaQueueId;
    arg.p[0] = name;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_queue_group_id_get(
    ncp_dev_hdl_t dev,
    ncp_task_resource_name_t *name,
    ncp_uint32_t *pQueueGroupId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_QUEUE_GROUP_ID_GET;
    arg.p[0] = name;
    arg.p[1] = pQueueGroupId;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 1));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_tqs_id_get(
    ncp_dev_hdl_t dev,
    ncp_task_resource_name_t *pResourceName,
    ncp_uint32_t *pTqsId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_TQS_ID_GET;
    arg.p[0] = pResourceName;
    arg.p[1] = pTqsId;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 1));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_nca_queue_id_get(
    ncp_dev_hdl_t dev,
    ncp_task_resource_name_t *name,
    ncp_uint32_t *pNcaQueueId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_NCA_QUEUE_ID_GET;
    arg.p[0] = name;
    arg.p[1] = pNcaQueueId;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 1));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_cpu_app_profile_name_get(
    ncp_dev_hdl_t dev,
    ncp_uint32_t profileId,
    ncp_task_resource_name_t *name)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_CPU_APP_PROFILE_NAME_GET;
    arg.v[0] = profileId;
    arg.p[0] = name;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_nca_queue_profile_name_get(
    ncp_dev_hdl_t dev,
    ncp_uint32_t profileId,
    ncp_task_resource_name_t *name)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_NCA_QUEUE_PROFILE_NAME_GET;
    arg.v[0] = profileId;
    arg.p[0] = name;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_nca_queue_profile_id_get(
    ncp_dev_hdl_t  dev,
    ncp_uint32_t   ncaQueueId,
    ncp_uint32_t  *profileId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_NCA_QUEUE_PROFILE_ID_GET;
    arg.v[0] = ncaQueueId;
    arg.p[0] = profileId;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_pool_name_get(
    ncp_dev_hdl_t             dev,
    ncp_uint8_t               bufferPoolId,
    ncp_task_resource_name_t *name)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_NCA_POOL_NAME_GET;
    arg.v[0] = bufferPoolId;
    arg.p[0] = name;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_pool_id_get(
    ncp_dev_hdl_t             dev,
    ncp_task_resource_name_t *name,
    ncp_uint8_t              *bufferPoolId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_NCA_POOL_ID_GET;
    arg.p[0] = name;
    arg.p[1] = bufferPoolId;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 1));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_perform_tqs_bind_checks(
    ncp_dev_hdl_t dev,
    ncp_uint32_t  tqsId,
    ncp_bool_t    uMode)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_NCA_PERFORM_TQS_BIND_CHECKS;
    arg.v[0] = tqsId;
    arg.v[1] = uMode;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_set_tqs_configured_state(
    ncp_dev_hdl_t dev,
    ncp_uint32_t  tqsId,
    ncp_bool_t    configured)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_NCA_SET_TQS_CONFIGURED_STATE;
    arg.v[0] = tqsId;
    arg.v[1] = configured;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_tqs_configure(
    ncp_dev_hdl_t dev,
    ncp_uint32_t  tqsId,
    ncp_task_resource_name_t *tqsName,
    ncp_task_resource_name_t *appProfileName,
    ncp_task_tqs_shared_t *pFlags,
    ncp_uint32_t mqgId,
    ncp_bool_t   uMode)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_NCA_CONFIGURE_TQS;
    arg.v[0] = tqsId;
    arg.p[0] = tqsName;
    arg.p[1] = appProfileName;
    arg.p[2] = pFlags;
    arg.v[1] = mqgId;
    arg.v[2] = uMode;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 1));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 2));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_set_tracing_enable(
    ncp_dev_hdl_t dev,
    ncp_bool_t enable)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_SET_TRACING_ENABLE;
    arg.v[0] = enable;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_queue_set_tracing_enable(
    ncp_dev_hdl_t dev,
    ncp_bool_t enable,
    ncp_uint32_t ncaQueueId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_SET_QUEUE_TRACING_ENABLE;
    arg.v[0] = enable;
    arg.v[1] = ncaQueueId;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_reset_tracing(
    ncp_dev_hdl_t dev)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_RESET_TRACING;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_update_kernel_tqs_state(
    ncp_dev_hdl_t dev,
    ncp_uint8_t   pgitId,
    ncp_int32_t   profileId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_UPDATE_KERNEL_TQS_STATE;
    arg.v[0] = pgitId;
    arg.v[1] = profileId;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_check_queue_group_for_orphaned_queues(
    ncp_dev_hdl_t dev,
    ncp_uint32_t tqsId,
    ncp_uint32_t groupIndex,
    ncp_bool_t   takeLock)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_CHECK_QUEUE_GROUP_ORPHANED_QUEUES;
    arg.v[0] = tqsId;
    arg.v[1] = groupIndex;
    arg.v[2] = takeLock;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_get_app_profile_pool_mapping(
    ncp_dev_hdl_t dev,
    ncp_task_resource_name_t *appProfileName,
    ncp_bool_t poolEnabled[8])
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_GET_APP_PROFILE_POOL_MAPPING;
    arg.p[0] = appProfileName;
    arg.p[1] = poolEnabled;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 1));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_get_app_profile_name(
    ncp_dev_hdl_t dev,
    ncp_uint32_t tqsId,
    ncp_task_resource_name_t *appProfileName)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_GET_APP_PROFILE_NAME;
    arg.v[0] = tqsId;
    arg.p[0] = appProfileName;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_get_unscheduled_receive_queue_profile_pool_mapping(
    ncp_dev_hdl_t dev,
    ncp_task_resource_name_t *queueProfileName,
    ncp_bool_t poolEnabled[8])
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_GET_QPM_QUEUE_PROFILE_POOL_MAPPING;
    arg.p[0] = queueProfileName;
    arg.p[1] = poolEnabled;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 1));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_get_unscheduled_receive_queue_profile_name(
    ncp_dev_hdl_t dev,
    ncp_uint32_t queueId,
    ncp_task_resource_name_t *queueProfileName)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_ncav3_generic_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;
    arg.commandId = NCAV3_GENERIC_GET_QPM_QUEUE_PROFILE_NAME;
    arg.v[0] = queueId;
    arg.p[0] = queueProfileName;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));
    NCP_POINTER_FIXUP(arg.NCP_POINTER_ARRAY_64(p, 0));

    if (ioctl((intptr_t) dev, NCP_IOC_TASK_NCAV3_GENERIC, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return ncpStatus;
}
#endif

ncp_st_t
ncp_enable_pmu_usermode(
    ncp_dev_hdl_t dev)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ioc_status_t arg;

    arg.NCP_POINTER(st) = &ncpStatus;

    NCP_POINTER_FIXUP(arg.NCP_POINTER_64(st));

    if (ioctl((intptr_t) dev, NCP_IOC_PMU_USER_EN, &arg) == -1)
    {
        return ncp_status_code();
    }

NCP_RETURN_LABEL

    return(ncpStatus);
}
#endif /* __linux__ */
