/**************************************************************************
 **                                                                       *
 **    Copyright (c) 2001-2017, Intel Corporation.                        *
 **                                                                       *
 **************************************************************************/

/**************************************************************************/
/* Contains NCAv3 config-related functions that exist in both the         */
/* user-space library and the kernel module.                              */
/**************************************************************************/

#include "ncp_task_basetypes.h"
#include "ncp_ncav3_pvt.h"
#include "ncp_task_pvt.h"
//#include "ncp_ncav3.h"


#include "regs/ncp_axis_axi2ser8_regions.h"

#include "regs/ncp_nca_itp_regs.h"
#include "regs/ncp_nca_otp_regs.h"
#include "regs/ncp_nca_mtp_regs.h"
#include "regs/ncp_nca_cfg_regs.h"
#include "regs/ncp_qpm_regs.h"
#include "regs/ncp_caal_nca_sys_mem_regs.h"
#include "regs/ncp_AW_trace0_regs.h"
#include "regs/ncp_AW_trace1_regs.h"
#include "regs/ncp_nca_itp_reg_defines.h"
#include "regs/ncp_nca_otp_reg_defines.h"
#include "regs/ncp_nca_mtp_reg_defines.h"
#include "regs/ncp_nca_cfg_reg_defines.h"
#include "regs/ncp_nca_core_reg_defines.h"
#include "regs/ncp_qpm_reg_defines.h"
#include "regs/ncp_caal_nca_sys_mem_reg_defines.h"
#include "regs/ncp_AW_trace0_reg_defines.h"
#include "regs/ncp_AW_trace1_reg_defines.h"



#include "regs/ncp_ncap_regs.h"
#include "ncp_ncav3_qpm.h"

#if defined(NCP_DEV_SOCKET)
#include <ncp_task_socket.h>
#elif defined(NCP_DEV_FBRS) || defined(NCP_DEV_FBDEV)
#include <ncp_task_fb.h>
#else
#include "ncp_task_hw.h"
#endif

/* Process global mmap counters */
static int *sharedDataRegionMapCnt = NULL;
static int fixedPoolMapCnt = 0;
static ncp_uint8_t *qpmMMIOBaseAddr = NULL;



ncp_st_t
ncp_ncav3_enable_ipcq(
    ncp_dev_hdl_t dev,
    ncp_uint8_t  ncapId,
    ncp_uint8_t  relTqsId,
    ncp_uint8_t  pgitId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);

    ncp_nca_itp_ipcq_online00_r_t r0;
    ncp_nca_itp_ipcq_online01_r_t r1;
    ncp_nca_itp_ipcq_online02_r_t r2;

    ncp_nca_itp_ipcq_valid00_r_t r3;
    ncp_nca_itp_ipcq_valid01_r_t r4;
    ncp_nca_itp_ipcq_valid02_r_t r5;

    NCP_TASK_LOCK_FLAGS(flags);
    
    /*  lapaj no fpga 
	if (((ncp_dev_t *)dev)->config->rev.isFpga)
    {
        NCP_CALL(ncp_ncav3_fpga_lookup_ipd_entry(dev, ncapId, relTqsId, &pgitId));
    }
	*/

    NCP_CALL(NCP_TASK_CLAIM_LOCK(&ipcqOnlineLock, flags, &unlockRequired));

    if (pgitId < 32)
    {
        NCP_DEV_NCA_READ_REG32(dev,
                NCP_REGION_NCAV3_CORE,
                NCP_NCA_ITP_IPCQ_ONLINE00 + NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                (ncp_uint32_t *)&r0);

        NCP_DEV_NCA_READ_REG32(dev,
                NCP_REGION_NCAV3_CORE,
                NCP_NCA_ITP_IPCQ_VALID00 + NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                (ncp_uint32_t *)&r3);

        r0.online |= 1 << pgitId;
        r3.valid  |= 1 << pgitId;

        NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
                NCP_REGION_NCAV3_CORE,
                NCP_NCA_ITP_IPCQ_ONLINE00 + NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                (ncp_uint32_t *)&r0);

        NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
                NCP_REGION_NCAV3_CORE,
                NCP_NCA_ITP_IPCQ_VALID00 + NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                (ncp_uint32_t *)&r3);
    }
    else if (pgitId < 64)
    {
        NCP_DEV_NCA_READ_REG32(dev,
                NCP_REGION_NCAV3_CORE,
                NCP_NCA_ITP_IPCQ_ONLINE01 + NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                (ncp_uint32_t *)&r1);

        NCP_DEV_NCA_READ_REG32(dev,
                NCP_REGION_NCAV3_CORE,
                NCP_NCA_ITP_IPCQ_VALID01 + NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                (ncp_uint32_t *)&r4);

        r1.online |= 1 << (pgitId % 32);
        r4.valid  |= 1 << (pgitId % 32);

        NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
                NCP_REGION_NCAV3_CORE,
                NCP_NCA_ITP_IPCQ_ONLINE01 + NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                (ncp_uint32_t *)&r1);

        NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
                NCP_REGION_NCAV3_CORE,
                NCP_NCA_ITP_IPCQ_VALID01 + NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                (ncp_uint32_t *)&r4);
    }
    else
    {
        NCP_DEV_NCA_READ_REG32(dev,
                NCP_REGION_NCAV3_CORE,
                NCP_NCA_ITP_IPCQ_ONLINE02 + NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                (ncp_uint32_t *)&r2);

        NCP_DEV_NCA_READ_REG32(dev,
                NCP_REGION_NCAV3_CORE,
                NCP_NCA_ITP_IPCQ_VALID02 + NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                (ncp_uint32_t *)&r5);

        r2.online |= 1 << (pgitId % 32);
        r5.valid  |= 1 << (pgitId % 32);

        NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
                NCP_REGION_NCAV3_CORE,
                NCP_NCA_ITP_IPCQ_ONLINE02 + NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                (ncp_uint32_t *)&r2);

        NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
                NCP_REGION_NCAV3_CORE,
                NCP_NCA_ITP_IPCQ_VALID02 + NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                (ncp_uint32_t *)&r5);
    }

NCP_RETURN_LABEL

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(&ipcqOnlineLock, flags, &unlockRequired));

    return ncpStatus;
}







ncp_st_t
ncp_ncav3_get_absolute_group_id(
    int ncapId,
    int tqsId,
    ncp_uint8_t *grpId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    if (ncapId < NCP_NCAV3_NUM_CPU_NCAPS)
    {
        *grpId = ncapId * NCP_NCAV3_NUM_TQSETS_PER_CPU_NCAP + tqsId;
    }
    else if (ncapId == 8)
    {
        *grpId = 80 + tqsId;
    }
    else if (ncapId >= 9 && ncapId <= 12)
    {
        *grpId = 64 + (ncapId - 9) * 4 + tqsId;
    }
    else
    {
        NCP_RETURN(NCP_ST_ERROR);
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

static ncp_uint32_t asicNCAPs[] = {0, 1, 2, 3, 4, 5, 6, 7};
static ncp_uint32_t fpgaNCAPs[] = {0};
static ncp_uint32_t superFpgaNCAPs[] = {0, 2, 4};

ncp_st_t
ncp_ncav3_get_ncap_id_list(
    ncp_t         *ncp,
    int           *numNCAPs,
    ncp_uint32_t **ncapList)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    if (ncp->isFPGA)
    {
        ncp_bool_t isSuper;

        NCP_CALL(ncp_super_fpga(myDevHdl, &isSuper));

        if (isSuper)
        {
            *ncapList = superFpgaNCAPs;
            *numNCAPs = 3;
        }
        else
        {
            *ncapList = fpgaNCAPs;
            *numNCAPs = 1;
        }
    }
    else
    {
        *ncapList = asicNCAPs;
        *numNCAPs = 8;
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

static ncp_st_t
ncp_ncav3_unmap_cpu_pool(
    ncp_dev_hdl_t dev,
    int poolId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

#if defined(NCP_DEV_FBRS) || defined(NCP_DEV_FBDEV) || defined(NCP_DEV_SOCKET)
#else
    ncp_task_pool_t *pPoolEntry = &pNcpTaskSwState->taskPools[poolId];

    NCP_TASK_MEM_UNMAP(dev,
            (void *) pPoolEntry->poolVA,
                     pPoolEntry->poolSize);
#endif

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_free_tqs_state(
    ncp_uint32_t tqsId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_tqs_swState_t *tqs = &pNcpTaskSwState->tqsSwState[tqsId];
    runtime_mutex_attr_state_t *mtxAttr = &tqs->mtxAttr;

    if (tqs->txQ0.u.opcq_info.pBaseAuxEntry)
    {
        NCP_CALL(ncp_nvm_robust_free((void **)&(tqs->txQ0.u.opcq_info.pBaseAuxEntry)));
        tqs->txQ0.u.opcq_info.pBaseAuxEntry = NULL;
    }

    if (tqs->txQ1.u.opcq_info.pBaseAuxEntry)
    {
        NCP_CALL(ncp_nvm_robust_free((void **)&(tqs->txQ1.u.opcq_info.pBaseAuxEntry)));
        tqs->txQ1.u.opcq_info.pBaseAuxEntry = NULL;
    }

    if (NCP_MUTEX_PROCESS_PRIVATE == mtxAttr->attr)
    {
        NCP_CALL(ncp_task_tqs_destroy_locks(tqsId));
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_config_free(
    ncp_ncav3_hdl_t *nca,
    ncp_dev_hdl_t    dev)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    int i;
#if (1 == NCP_TASK_TBR_ENABLED)    
    int j;
#endif    

    if (nca)
    {
        ncp_ncav3_config_info_t *config = &nca->configInfo;

        /****************************************/
        /* Free app profiles and their contents */
        /****************************************/
        if (config->profiles)
        {
            for (i = 0; i < config->numProfiles; i++)
            {
                ncp_ncav3_cpu_profile_t *profile;

                profile = &config->profiles[i].baseProfile;

                if (profile->sharedDataRegionMap)
                {
                    NCP_CALL(ncp_nvm_robust_free((void **)&(profile->sharedDataRegionMap)));
                }
            }

            NCP_CALL(ncp_nvm_robust_free((void **)&(config->profiles)));
        }

        /*********************************************/
        /* Free memory quotas and NCA queue profiles */
        /*********************************************/
        if (config->memoryQuotas)
        {
            NCP_CALL(ncp_nvm_robust_free((void **)&(config->memoryQuotas)));
        }

        if (config->taskReceiveQueues.queueProfiles)
        {
            NCP_CALL(ncp_nvm_robust_free((void **)&(config->taskReceiveQueues.queueProfiles)));
        }

        /*********************************/
        /* Free unscheduled queue config */
        /*********************************/
        if (config->unscheduledQueueConfig.queueProfiles)
        {
            NCP_CALL(ncp_nvm_robust_free((void **)&(config->unscheduledQueueConfig.queueProfiles)));
        }

        if (config->unscheduledQueueConfig.pipelines)
        {
            NCP_CALL(ncp_nvm_robust_free((void **)&(config->unscheduledQueueConfig.pipelines)));
        }

        if (config->unscheduledQueueConfig.monitoredQueues)
        {
            NCP_CALL(ncp_nvm_robust_free((void **)&(config->unscheduledQueueConfig.monitoredQueues)));
        }

        if (config->unscheduledQueueConfig.unmonitoredQueues)
        {
            NCP_CALL(ncp_nvm_robust_free((void **)&(config->unscheduledQueueConfig.unmonitoredQueues)));
        }

#if defined(NCP_DEV_FBRS) || defined(NCP_DEV_FBDEV) || defined(NCP_DEV_SOCKET)
        if (nca->tqsArray)
        {
            NCP_CALL(ncp_nvm_robust_free((void **)&(nca->tqsArray)));
        }
#endif

        NCP_CALL(ncp_nvm_robust_free((void **)&(nca)));
    }

    /********************************/
    /* Free task I/O software state */
    /********************************/
    if (pNcpTaskSwState)
    {
        /**************************/
        /* Free buffer pool state */
        /**************************/
        for (i = NCP_NCAV3_FIRST_SHARED_POOL_ID;
             i <= NCP_NCAV3_LAST_CPU_POOL_ID;
             i++)
        {
            ncp_task_pool_t *poolEntry = &pNcpTaskSwState->taskPools[i];
            runtime_mutex_attr_state_t *mtxState = &poolEntry->mtxAttr;

            /*
             * Kernel CPU pools are mapped at config time and unmapped at
             * config destroy time.
             */
            if (FALSE == poolEntry->uMode &&
                TRUE == poolEntry->valid  &&
                ncpTaskPoolMapCnt[i] > 0)
            {
                NCP_CALL(ncp_ncav3_unmap_cpu_pool(dev, i));

                ncpTaskPoolMapCnt[i] = 0;
            }

            NCP_CALL(ncp_task_v3_destroy_lock(&poolEntry->poolLock));
            mtxState->pid = 0;

#if (1 == NCP_TASK_TBR_ENABLED)
            for (j = 0; j < NCP_TASK_NUM_BUFF_SIZES; j++)
            {
                if (poolEntry->pTbrArray[j])
                {
                    NCP_CALL(ncp_nvm_robust_free((void **)&(poolEntry->pTbrArray[j])));
                }
                poolEntry->tbrArraysInitialized = FALSE;
            }
#endif

#if defined(NCP_DEV_FBRS) || defined(NCP_DEV_FBDEV) || defined(NCP_DEV_SOCKET)
            if (poolEntry->poolVA)
            {
                NCP_CALL(ncp_nvm_robust_free((void **)&(poolEntry->poolVA)));
            }
#endif
        }

#ifdef NCP_KERNEL
        /************************/
        /* Unmap the fixed pool */
        /************************/
	/*
         * The fixed pool is mapped into the kernel at config time and unmapped
         * at config destroy time.
	 */
        fixedPoolMapCnt = 1;
        NCP_CALL(ncp_ncav3_unmap_fixed_pool());
#endif

        /******************/
        /* Free TQS state */
        /******************/
        for (i = 0; i < NCP_NCAV3_MAX_NUM_TQSETS; i++)
        {
            NCP_CALL(ncp_ncav3_free_tqs_state(i));
        }

#ifndef NCP_KERNEL
        /* tqsBitmaps are allocated in user-space, so don't let the kernel try
         * to free them */
        for (i = 0; i < NCP_NCAV3_MAX_NUM_QUEUE_GROUPS; i++)
        {
            ncp_ncav3_nca_queue_group_t *queueGroup =
                &pNcpTaskSwState->queueGroups[i];

            if (queueGroup->tqsBitmap)
            {
                ncp_bitmap_delete(queueGroup->tqsBitmap);
            }
        }
#endif

        /*********************/
        /* Free global state */
        /*********************/

        if (pNcpTaskSwState->taskIoResourceLock)
        {
            NCP_CALL(ncp_nvm_robust_free((void **)&(pNcpTaskSwState->taskIoResourceLock)));
        }

        if (sharedDataRegionMapCnt != NULL)
        {
            for (i = 0; i < pNcpTaskSwState->numSharedDataRegions; i++)
            {
                ncp_ncav3_shared_region_t *sdr;

                sdr = &pNcpTaskSwState->sharedDataRegions[i];

                if (sharedDataRegionMapCnt[i] > 0)
                {
                    NCP_TASK_MEM_UNMAP(dev,
                            (void *) sdr->virtualBase,
                                     sdr->size);

                    sharedDataRegionMapCnt[i]--;
                }
            }

            ncp_free(sharedDataRegionMapCnt);
        }

        if (pNcpTaskSwState->sharedDataRegions)
        {
            NCP_CALL(ncp_nvm_robust_free((void **)&(pNcpTaskSwState->sharedDataRegions)));
        }

        for (i = 0; i < pNcpTaskSwState->currPidArrayEntries; i++)
        {
            if (pNcpTaskSwState->pidArray[i])
            {
                NCP_CALL(ncp_nvm_robust_free((void **)&(pNcpTaskSwState->pidArray[i])));
            }
        }

        NCP_CALL(ncp_nvm_robust_free((void **)&(pNcpTaskSwState->pidArray)));

        if (pNcpTaskSwState->domainMemMap.domainBundle_VA)
        {
            NCP_TASK_MEM_UNMAP(
                dev->num,
                (void *) pNcpTaskSwState->domainMemMap.domainBundle_VA,
                pNcpTaskSwState->domainMemMap.domainBundle_Size);
        }

        NCP_CALL(ncp_nvm_robust_free((void **)&(pNcpTaskSwState)));

        pNcpTaskSwState = NULL;
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_get_pcq_info(
    ncp_t *ncp,
    ncp_uint32_t tqsId,
    ncp_ncav3_pcq_type_t type,
    ncp_uint8_t opcqIndex,
    ncp_uint8_t poolId,
    ncp_uint8_t bufSizeBits,
    ncp_task_pcq_t *pcq)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_hdl_t *nca = ncp->ncaHdl;
    ncp_ncav3_cpu_profile_t *profile;
    ncp_ncav3_tqs_control_t *tqsControl;

    NCP_ASSERT(tqsId <= 63, NCP_ST_ERROR);
    NCP_ASSERT(NULL != pcq, NCP_ST_ERROR);

    profile = &pNcpTaskSwState->tqsSwState[tqsId].pAppProfile->baseProfile;

    tqsControl = (ncp_ncav3_tqs_control_t *) &nca->tqsArray[tqsId];

    switch (type) {

        case IPCQ:
            pcq->pProducerIdx = &tqsControl->tqs.ncatable.ip_index;
            pcq->pConsumerIdx = &tqsControl->tqs.cputable.ic_index;
            pcq->pPCQbase = (void *) ((ncp_uintptr_t) tqsControl +
                    (tqsControl->tqs.control.ipcq_offset << 4));
            pcq->nEntries = tqsControl->tqs.control.ipcq_depth;
            pcq->u.ipcq_info.autoCompletionMode  =
              (profile->completionMode == NCP_TASK_AUTO_COMPLETION_MODE);
            pcq->u.ipcq_info.autoConsumptionMode =
              (profile->consumptionMode == NCP_TASK_IMMEDIATE_CONSUMPTION_MODE);
            break;

        case OPCQ:
            NCP_ASSERT(opcqIndex <= 1, NCP_ST_ERROR);

            if (opcqIndex == 0)
            {
                pcq->pProducerIdx = &tqsControl->tqs.cputable.op0_index;
                pcq->pConsumerIdx = &tqsControl->tqs.ncatable.oc0_index;
                pcq->pPCQbase = (void *) ((ncp_uintptr_t) tqsControl +
                        (tqsControl->tqs.control.opcq0_offset << 4));
                pcq->nEntries = tqsControl->tqs.control.opcq0_depth;
            }
            else
            {
                pcq->pProducerIdx = &tqsControl->tqs.cputable.op1_index;
                pcq->pConsumerIdx = &tqsControl->tqs.ncatable.oc1_index;
                pcq->pPCQbase = (void *) ((ncp_uintptr_t) tqsControl +
                        (tqsControl->tqs.control.opcq1_offset << 4));
                pcq->nEntries = tqsControl->tqs.control.opcq1_depth;
            }
            break;

        case MPCQ:
            NCP_ASSERT((poolId >= 2) && (poolId <= 7), NCP_ST_ERROR);
            NCP_ASSERT(bufSizeBits <= 3, NCP_ST_ERROR);

#define GET_MPCQ_TQS_INFO(x, y) \
    pcq->pProducerIdx = &tqsControl->tqs.ncatable.mp##x##_indexes[y];  \
    pcq->pConsumerIdx = &tqsControl->tqs.cputable.mc##x##_indexes[y];  \
    pcq->pPCQbase = (void *) ((ncp_uintptr_t) tqsControl +        \
            (tqsControl->tqs.control.mpcq##x##_offsets[y] << 4));     \
    pcq->nEntries = tqsControl->tqs.control.mpcq##x##_depths[y];         \

            if (poolId == 2)
            {
                GET_MPCQ_TQS_INFO(0, bufSizeBits);
            }
            else if (poolId == 3)
            {
                GET_MPCQ_TQS_INFO(1, bufSizeBits);
            }
            else if (poolId == 4)
            {
                GET_MPCQ_TQS_INFO(2, bufSizeBits);
            }
            else if (poolId == 5)
            {
                GET_MPCQ_TQS_INFO(3, bufSizeBits);
            }
            else if (poolId == 6)
            {
                GET_MPCQ_TQS_INFO(4, bufSizeBits);
            }
            else
            {
                GET_MPCQ_TQS_INFO(5, bufSizeBits);
            }
            break;

#undef GET_MPCQ_TQS_INFO

        default:
            NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                           ncp_xlf_nca_cfg_ncav3_get_pcq_info_invalidPcqType,
                           NCP_MSG_ERROR, "[%s()] Invalid pcq type (%d)\n",
                           __func__, type);
            NCP_CALL(NCP_ST_ERROR);
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_supply_nca_buffers(
    ncp_t *ncp,
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_tqs_swState_t *tqs;
    ncp_ncav3_cpu_profile_t *profile;
    ncp_task_pool_t *pool;
    ncp_bool_t useTxQueue;
    int i, j;

    tqs = pvtTqsHdl->pTqs;

    NCP_ASSERT(tqs->pAppProfile != NULL,
        NCP_ST_INTERNAL_ERROR);

    profile = &tqs->pAppProfile->baseProfile;

    NCP_ASSERT(pNcpTaskSwState->uMode == profile->uMode,
        NCP_ST_INTERNAL_ERROR);

    pool = &pNcpTaskSwState->taskPools[profile->cpuPoolMap.poolId];

    /* If TQS doesn't use a CPU pool, return. */
    if (FALSE == profile->cpuPoolMap.enabled)
    {
        NCP_RETURN(NCP_ST_SUCCESS);
    }

    /* If pool buffers already supplied, no need to resupply. */
    if (TRUE == pool->u.cpu.ncaSupplyDone)
    {
        NCP_RETURN(NCP_ST_SUCCESS);
    }

    if (ncp->isFPGA && (profile->cpuPoolMap.poolId >= 12))
    {
        /* There are no IFLS stacks for pools 12-23 on the FPGA */
        NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                       ncp_xlf_nca_cfg_ncav3_fpga_invalid_cpu_pool,
                       NCP_MSG_ERROR,
                       "[%s()] XLF FPGAs do not support CPU pools 12-23.\n",
                       __func__);

        NCP_RETURN(NCP_ST_ERROR);
    }

    /* Overwrite the TXQ0 usage flag. This is safe, since the tqsUseCnt is 0
     * at this point.
     */
    useTxQueue = pvtTqsHdl->useFlags.useTxQueue[0];

    pvtTqsHdl->useFlags.useTxQueue[0] = TRUE;

    for (i = 0; i < NCP_TASK_NUM_BUFF_SIZES; i++)
    {
        for (j = 0; j < pool->numBlocksForNCA[i]; j++)
        {
            ncp_uint32_t numProcessed;
            ncp_uint32_t sizes[4] = {256, 2048, 16384, 65536};
            void *buffer;

            NCP_CALL(ncp_task_buffer_alloc(
                        pvtTqsHdl,
                        1,
                        &numProcessed,
                        &sizes[i],
                        0,
                        &buffer,
                        TRUE));

            NCP_CALL(ncp_task_buffer_refill(
                        pvtTqsHdl,
                        0,
                        1,
                        &numProcessed,
                        &buffer,
                        TRUE));
        }
    }

    pvtTqsHdl->useFlags.useTxQueue[0] = useTxQueue;

    pool->u.cpu.ncaSupplyDone = TRUE;

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_static_supply_nca_buffers(
    ncp_t           *ncp,
    ncp_ncav3_hdl_t *nca,
    ncp_dev_hdl_t    dev,
    ncp_bool_t       uMode)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
#if !(defined(NCP_DEV_FBRS) || defined(NCP_DEV_FBDEV) || defined(NCP_DEV_SOCKET))
    ncp_task_resource_name_t processName = {"configV3\0"};
    ncp_task_resource_name_t threadName = {"main\0"};
    int i;

    /* Supply pools using statically configured TQSes */
    for (i = 0; i < NCP_NCAV3_MAX_NUM_TQSETS; i++)
    {
        ncp_task_tqs_swState_t *tqs;
        ncp_ncav3_cpu_profile_t *profile;
        ncp_task_tqs_hdl_t tqsHdl;
        ncp_task_tqs_usage_t usage;
        ncp_task_pool_t *pool;

        tqs = &pNcpTaskSwState->tqsSwState[i];

        if (NULL == tqs->pAppProfile)
        {
            continue;
        }

        profile = &tqs->pAppProfile->baseProfile;

        if ((FALSE == tqs->staticConfiguration) ||
            (FALSE == profile->cpuPoolMap.enabled) ||
            (uMode != profile->uMode))
        {
            continue;
        }

        pool = &pNcpTaskSwState->taskPools[profile->cpuPoolMap.poolId];

        /* If pool buffers already supplied, continue */
        if (TRUE == pool->u.cpu.ncaSupplyDone)
        {
            continue;
        }

        usage.useRxQueue  = FALSE;
        usage.useTxQueue0 = TRUE;
        usage.useTxQueue1 = FALSE;
        usage.useAllocator[2] = FALSE;
        usage.useAllocator[3] = FALSE;
        usage.useAllocator[4] = FALSE;
        usage.useAllocator[5] = FALSE;
        usage.useAllocator[6] = FALSE;
        usage.useAllocator[7] = FALSE;

        NCP_CALL(ncp_task_tqs_bind(
            ncp,
            i,
            &usage,
            &processName,
            &threadName,
            &tqsHdl));

        NCP_CALL(ncp_ncav3_supply_nca_buffers(ncp, tqsHdl));

        NCP_CALL(ncp_task_tqs_unbind(tqsHdl));

        pool->u.cpu.ncaSupplyDone = TRUE;
    }

    /* If any CPU pools weren't supplied, we have to dynamically configure a
     * TQS. ASE guarantees that each CPU pool has at least one application
     * profile that uses it, so there must be at least one profile we can use.
     *
     * If there are no unconfigured TQSes, we do not supply the CPU pool
     * buffers at this time. If this happens, the MTP prefetch FIFO will hammer
     * the NCA's MCIP with allocation requests until we supply the pool's
     * buffers. We can't dynamically enable the prefetch FIFOs, however, so
     * they must be left on.
     */
    for (i = NCP_NCAV3_FIRST_CPU_POOL_ID; i <= NCP_NCAV3_LAST_CPU_POOL_ID; i++)
    {
        ncp_task_tqs_swState_t *tqs;
        ncp_ncav3_cpu_profile_t *profile;
        ncp_task_tqs_hdl_t tqsHdl;
        ncp_task_tqs_usage_t usage;
        ncp_task_pool_t *pool;
        ncp_task_tqs_shared_t flags = {0};
        ncp_task_resource_name_t tqsName = {"__RTE_INTERNAL_TQS"};
        int j;

        pool = &pNcpTaskSwState->taskPools[i];

        /* Pool is invalid or pool buffers already supplied, so continue */
        if ((FALSE == pool->valid) || (TRUE == pool->u.cpu.ncaSupplyDone))
        {
            continue;
        }

	/* If we reach this point, it means no statically configured TQSes use
	 * this pool. Thus we have to find an unconfigured TQS, configure it
	 * with an app profile that uses this pool, and supply the NCA buffers.
         */

        for (j = 0; j < NCP_NCAV3_MAX_NUM_TQSETS; j++)
        {
            tqs = &pNcpTaskSwState->tqsSwState[j];

            if (FALSE == tqs->staticConfiguration)
            {
                break;
            }
        }

	/* If we can't find an unconfigured TQS, we can't supply the remaining
         * buffers until the user reconfigures a TQS to use that pool.
         */
        if (j == NCP_NCAV3_MAX_NUM_TQSETS)
        {
            break;
        }

        for (j = 0; j < nca->configInfo.numProfiles; j++)
        {
            profile = &nca->configInfo.profiles[j].baseProfile;

            if ((TRUE == profile->cpuPoolMap.enabled) &&
                (i == profile->cpuPoolMap.poolId))
            {
                break;
            }
        }

        /* If no app profile uses this pool, ASE made a mistake. */
        NCP_ASSERT(j != nca->configInfo.numProfiles, NCP_ST_INTERNAL_ERROR);

        /* Only supply buffers for pools owned by the current uMode */
        if (uMode != profile->uMode)
        {
            continue;
        }

        NCP_CALL(ncp_task_tqs_configure(
            (ncp_hdl_t) ncp,
            tqs->tqsId,
           &tqsName,
           &profile->name,
           &flags,
            0));

        usage.useRxQueue  = FALSE;
        usage.useTxQueue0 = TRUE;
        usage.useTxQueue1 = FALSE;
        usage.useAllocator[2] = FALSE;
        usage.useAllocator[3] = FALSE;
        usage.useAllocator[4] = FALSE;
        usage.useAllocator[5] = FALSE;
        usage.useAllocator[6] = FALSE;
        usage.useAllocator[7] = FALSE;

        NCP_CALL(ncp_task_tqs_bind(
            ncp,
            tqs->tqsId,
            &usage,
            &processName,
            &threadName,
            &tqsHdl));

        NCP_CALL(ncp_ncav3_supply_nca_buffers(ncp, tqsHdl));

        NCP_CALL(ncp_task_tqs_unbind(tqsHdl));

        NCP_CALL(ncp_task_tqs_shutdown(
            (ncp_hdl_t) ncp,
            tqs->tqsId));

        pool->u.cpu.ncaSupplyDone = TRUE;
    }

NCP_RETURN_LABEL
#endif

    return ncpStatus;
}


ncp_st_t
ncp_ncav3_configure_cpu_pool_addr_convert_ram(
    ncp_dev_hdl_t dev,
    ncp_bool_t    uMode)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    int poolID;

    ncp_nca_itp_addrconvert_virtualbase_r_t r0;

    ncp_comment("## Configure NCA ADDRCONVERT VIRT BASE RAM\n");

    ncp_memset(&r0, 0, sizeof(r0));

    /* RAM entries 15:0 contain the base addresses 16 CPU pools. */
    for (poolID = 8; poolID < NCP_NCAV3_NUM_TASK_MEMORY_POOLS; poolID++)
    {
        ncp_task_pool_t *pPoolEntry = &pNcpTaskSwState->taskPools[poolID];

        if (pPoolEntry->uMode != uMode)
        {
            continue;
        }

        r0.poolbase_63_32 = (pPoolEntry->poolVA & 0xFFFFFFFF00000000LL) >> 32;
        r0.poolbase_31_0  = (pPoolEntry->poolVA & 0x00000000FFFFFFFFLL);

        ncp_comment("### Writing ITP_ADDRCONVERT_IN_VIRTUALBASE\n");

        NCP_CALL(ncp_block_write32(
                    dev,
                    NCP_REGION_NCAV3_CORE,
                    NCP_NCA_ITP_ADDRCONVERT_IN_VIRTUALBASE(poolID-8) +
                        NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                    (ncp_uint32_t *) &r0,
                    sizeof(r0)/4,
                    0));

        ncp_comment("### Writing MTP_DMM_DEALLOC_ADDRCONVERT_TRANSLATE\n");

        NCP_CALL(ncp_block_write32(
                    dev,
                    NCP_REGION_NCAV3_CORE,
                    NCP_NCA_MTP_DMM_DEALLOC_ADDRCONVERT_TRANSLATE(poolID-8) +
                        NCP_NCA_CORE_MTP_ADDR_MAP_BASE,
                    (ncp_uint32_t *) &r0,
                    sizeof(r0)/4,
                    0));

        ncp_comment("### Writing MTP_DMM_ALLOC_ADDRCONVERT_TRANSLATE\n");

        NCP_CALL(ncp_block_write32(
                    dev,
                    NCP_REGION_NCAV3_CORE,
                    NCP_NCA_MTP_DMM_ALLOC_ADDRCONVERT_TRANSLATE(poolID-8) +
                        NCP_NCA_CORE_MTP_ADDR_MAP_BASE,
                    (ncp_uint32_t *) &r0,
                    sizeof(r0)/4,
                    0));

        ncp_comment("### Writing MTP_MPCQ_ALLOC_ADDRCONVERT_TRANSLATE\n");

        NCP_CALL(ncp_block_write32(
                    dev,
                    NCP_REGION_NCAV3_CORE,
                    NCP_NCA_MTP_MPCQ_ALLOC_ADDRCONVERT_TRANSLATE(poolID-8) +
                        NCP_NCA_CORE_MTP_ADDR_MAP_BASE,
                    (ncp_uint32_t *) &r0,
                    sizeof(r0)/4,
                    0));

        ncp_comment("### Writing OTP_ADDRCONVERT_ENTRY_VIRTUALBASE\n");

        NCP_CALL(ncp_block_write32(
                    dev,
                    NCP_REGION_NCAV3_CORE,
                    NCP_NCA_OTP_ADDRCONVERT_ENTRY_VIRTUALBASE(poolID-8) +
                        NCP_NCA_CORE_OTP_ADDR_MAP_BASE,
                    (ncp_uint32_t *) &r0,
                    sizeof(r0)/4,
                    0));

        ncp_comment("### Writing OTP_ADDRCONVERT_DATA0_VIRTUALBASE\n");

        NCP_CALL(ncp_block_write32(
                    dev,
                    NCP_REGION_NCAV3_CORE,
                    NCP_NCA_OTP_ADDRCONVERT_DATA0_VIRTUALBASE(poolID-8) +
                        NCP_NCA_CORE_OTP_ADDR_MAP_BASE,
                    (ncp_uint32_t *) &r0,
                    sizeof(r0)/4,
                    0));

        ncp_comment("### Writing OTP_ADDRCONVERT_DATA1_VIRTUALBASE\n");

        NCP_CALL(ncp_block_write32(
                    dev,
                    NCP_REGION_NCAV3_CORE,
                    NCP_NCA_OTP_ADDRCONVERT_DATA1_VIRTUALBASE(poolID-8) +
                        NCP_NCA_CORE_OTP_ADDR_MAP_BASE,
                    (ncp_uint32_t *) &r0,
                    sizeof(r0)/4,
                    0));

        ncp_comment("### Writing OTP_ADDRCONVERT_COPY_VIRTUALBASE\n");

        NCP_CALL(ncp_block_write32(
                    dev,
                    NCP_REGION_NCAV3_CORE,
                    NCP_NCA_ITP_ADDRCONVERT_COPY_VIRTUALBASE(poolID-8) +
                        NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                    (ncp_uint32_t *) &r0,
                    sizeof(r0)/4,
                    0));
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_configure_fixed_pool_addr_convert_ram(
    ncp_ncav3_hdl_t *nca,
    ncp_dev_hdl_t dev,
    ncp_bool_t uMode)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    int index;

    ncp_comment("## Configure NCA ADDRCONVERT VIRT BASE RAM\n");

    /* RAM entries 31:16 contain the base addresses of the fixed pool. */
    for (index = 0; index < nca->configInfo.numProfiles; index++)
    {
        ncp_task_pool_t *pPoolEntry;
        ncp_nca_itp_addrconvert_virtualbase_r_t r0;
        ncp_ncav3_application_profile_t *profile;
        ncp_uint64_t poolVA;
        int vrID;

        ncp_memset(&r0, 0, sizeof(r0));

        pPoolEntry = &pNcpTaskSwState->taskPools[NCP_TASK_FIXED_POOL_ENCODED_ID];

        profile = &nca->configInfo.profiles[index];

        if ((FALSE == profile->baseProfile.fixedPoolMap.enabled) ||
            (uMode != profile->baseProfile.uMode))
        {
            continue;
        }

        vrID = profile->baseProfile.virtualRegionId;

        /* Use the profile's VA when mapping from user-space and
         * use the memory-mapped address when mapping from kernel-space.
         */
        poolVA = (uMode) ?
            profile->baseProfile.fixedPoolMap.virtualStartAddress :
            pNcpTaskSwState->fixedPoolInfo.virtualBase;

        r0.poolbase_63_32 = (poolVA & 0xFFFFFFFF00000000LL) >> 32;
        r0.poolbase_31_0  = (poolVA & 0x00000000FFFFFFFFLL);

        ncp_comment("### Writing ITP_ADDRCONVERT_IN_VIRTUALBASE\n");

        NCP_CALL(ncp_block_write32(
                    dev,
                    NCP_REGION_NCAV3_CORE,
                    NCP_NCA_ITP_ADDRCONVERT_IN_VIRTUALBASE(vrID + 16) +
                        NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                    (ncp_uint32_t *) &r0,
                    sizeof(r0)/4,
                    0));

        ncp_comment("### Writing MTP_DMM_DEALLOC_ADDRCONVERT_TRANSLATE\n");

        NCP_CALL(ncp_block_write32(
                    dev,
                    NCP_REGION_NCAV3_CORE,
                    NCP_NCA_MTP_DMM_DEALLOC_ADDRCONVERT_TRANSLATE(vrID + 16) +
                        NCP_NCA_CORE_MTP_ADDR_MAP_BASE,
                    (ncp_uint32_t *) &r0,
                    sizeof(r0)/4,
                    0));

        ncp_comment("### Writing MTP_DMM_ALLOC_ADDRCONVERT_TRANSLATE\n");

        NCP_CALL(ncp_block_write32(
                    dev,
                    NCP_REGION_NCAV3_CORE,
                    NCP_NCA_MTP_DMM_ALLOC_ADDRCONVERT_TRANSLATE(vrID + 16) +
                        NCP_NCA_CORE_MTP_ADDR_MAP_BASE,
                    (ncp_uint32_t *) &r0,
                    sizeof(r0)/4,
                    0));

        ncp_comment("### Writing MTP_MPCQ_ALLOC_ADDRCONVERT_TRANSLATE\n");

        NCP_CALL(ncp_block_write32(
                    dev,
                    NCP_REGION_NCAV3_CORE,
                    NCP_NCA_MTP_MPCQ_ALLOC_ADDRCONVERT_TRANSLATE(vrID + 16) +
                        NCP_NCA_CORE_MTP_ADDR_MAP_BASE,
                    (ncp_uint32_t *) &r0,
                    sizeof(r0)/4,
                    0));

        ncp_comment("### Writing OTP_ADDRCONVERT_ENTRY_VIRTUALBASE\n");

        NCP_CALL(ncp_block_write32(
                    dev,
                    NCP_REGION_NCAV3_CORE,
                    NCP_NCA_OTP_ADDRCONVERT_ENTRY_VIRTUALBASE(vrID + 16) +
                        NCP_NCA_CORE_OTP_ADDR_MAP_BASE,
                    (ncp_uint32_t *) &r0,
                    sizeof(r0)/4,
                    0));

        ncp_comment("### Writing OTP_ADDRCONVERT_DATA0_VIRTUALBASE\n");

        NCP_CALL(ncp_block_write32(
                    dev,
                    NCP_REGION_NCAV3_CORE,
                    NCP_NCA_OTP_ADDRCONVERT_DATA0_VIRTUALBASE(vrID + 16) +
                        NCP_NCA_CORE_OTP_ADDR_MAP_BASE,
                    (ncp_uint32_t *) &r0,
                    sizeof(r0)/4,
                    0));

        ncp_comment("### Writing OTP_ADDRCONVERT_DATA1_VIRTUALBASE\n");

        NCP_CALL(ncp_block_write32(
                    dev,
                    NCP_REGION_NCAV3_CORE,
                    NCP_NCA_OTP_ADDRCONVERT_DATA1_VIRTUALBASE(vrID + 16) +
                        NCP_NCA_CORE_OTP_ADDR_MAP_BASE,
                    (ncp_uint32_t *) &r0,
                    sizeof(r0)/4,
                    0));

        ncp_comment("### Writing OTP_ADDRCONVERT_COPY_VIRTUALBASE\n");

        NCP_CALL(ncp_block_write32(
                    dev,
                    NCP_REGION_NCAV3_CORE,
                    NCP_NCA_ITP_ADDRCONVERT_COPY_VIRTUALBASE(vrID + 16) +
                        NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                    (ncp_uint32_t *) &r0,
                    sizeof(r0)/4,
                    0));
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

static ncp_st_t
ncp_ncav3_map_cpu_pool(
    ncp_dev_hdl_t dev,
    int poolId,
    ncp_bool_t uMode)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pool_t *pPoolEntry = &pNcpTaskSwState->taskPools[poolId];
    ncp_uintptr_t poolVA;

#if defined(NCP_DEV_FBRS) || defined(NCP_DEV_FBDEV) || defined(NCP_DEV_SOCKET)
    NCP_CALL(ncp_nvm_robust_malloc(pPoolEntry->poolSize,
                                (void **)&poolVA,
                                NCP_DO_NOT_MEMSET));

    pPoolEntry->poolVA = poolVA;

    pPoolEntry->poolVAEnd = poolVA + pPoolEntry->poolSize;
#else
    poolVA = (ncp_uintptr_t) NCP_TASK_MEM_MMAP(dev,
            pPoolEntry->poolVA,
            pPoolEntry->poolSize,
            pPoolEntry->poolPA);

    if (uMode == TRUE)
    {
        if (poolVA != pPoolEntry->poolVA)
        {
            NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                           ncp_xlf_nca_cfg_ncav3_map_cpu_pool_gotDifferentVAThanRequested,
                           NCP_MSG_ERROR,
                           "[%s()] Tried to map CPU pool @ %p, but got %p instead.\n",
                           __func__, (void *) pPoolEntry->poolVA, (void *) poolVA);
            NCP_CALL(NCP_ST_ERROR);
        }
    }
    else
    {
        int i;

        pPoolEntry->poolVA = (ncp_uintptr_t) poolVA;

        pPoolEntry->poolVAEnd = pPoolEntry->poolVA + pPoolEntry->poolSize;

        /* For kernel TQSes, just leave the pool mapped */
        ncpTaskPoolMapCnt[poolId]++;

        /*
         * The kernel won't map the pool at pPool->poolVA, but that's OK
         * since there's a only one kernel address space. If we're in
         * the kernel, we update the blocksVA and blocksVAend so TBR
         * can work.
         */

        for (i = NCP_TASK_NUM_BUFF_SIZES - 1; i >= 0; i--)
        {
            int buffSizes[4] = {256, 2048, 16384, 65536};

            pPoolEntry->blocksVA[i] = poolVA;

            pPoolEntry->blocksVAend[i] = pPoolEntry->blocksVA[i] +
                (pPoolEntry->numBlocks[i] * buffSizes[i]);

            poolVA = pPoolEntry->blocksVAend[i];
        }
    }
#endif

NCP_RETURN_LABEL

    return ncpStatus;
}

static ncp_st_t
ncp_ncav3_format_cpu_pool(
    int poolId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pool_t *pPoolEntry = &pNcpTaskSwState->taskPools[poolId];
    ncp_uintptr_t currBaseVA;
    int i;

    currBaseVA = pPoolEntry->poolVA;

    for (i = NCP_TASK_NUM_BUFF_SIZES-1; i >= 0; i--)
    {
        ncp_task_bufflist_t *buffListEntry;
        int j;

        buffListEntry = &pPoolEntry->u.cpu.buffListArray[i];

        buffListEntry->NCP_POINTER(VAstart) = (ncp_uint8_t *) currBaseVA;

        for (j = 0; j < pPoolEntry->numBlocks[i]; j++)
        {
            ncp_buffDescriptor_t *pBuffDesc =
                (ncp_buffDescriptor_t *) currBaseVA;

            if(( ((ncp_uintptr_t) pBuffDesc) + buffListEntry->size) >
               pPoolEntry->poolVAEnd)
            {
                NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                               ncp_xlf_nca_cfg_ncav3_format_cpu_pool_bufferOverrun,
                               NCP_MSG_ERROR,
                               "Buffer overrun for pool=%d: buffer(%p) + size(%d) > max(%p)\r\n",
                               poolId,
                               (void *) pBuffDesc,
                               buffListEntry->size,
                               (void *) pPoolEntry->poolVAEnd);
                NCP_CALL(NCP_ST_TASK_BUFF_POOL_OVERRUN);
            }

            if (0 == j)
            {
                buffListEntry->NCP_POINTER(last) = pBuffDesc;
            }

            /* put it on the free list */
            pBuffDesc->next = buffListEntry->NCP_POINTER(free);
            buffListEntry->NCP_POINTER(free) = pBuffDesc;
            buffListEntry->numFree++;

            currBaseVA += buffListEntry->size;
        }

        buffListEntry->freeLowWaterMark = buffListEntry->numFree;

        buffListEntry->NCP_POINTER(VAend) = (ncp_uint8_t *) currBaseVA;

        NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                       ncp_xlf_nca_cfg_ncav3_format_cpu_pool_cpuPoolParams,
                       NCP_MSG_DEBUG,
                       "format pool: pPool Entry (%d) @%p, total=%d, numFree=%d, sz=%d, vaStart=%p, vaEnd=%p\r\n",
                       i,
                       pPoolEntry,
                       pPoolEntry->numBlocks[i],
                       buffListEntry->numFree,
                       buffListEntry->size,
                       buffListEntry->VAstart,
                       buffListEntry->NCP_POINTER(VAend));
    }

    if (currBaseVA > pPoolEntry->poolVAEnd)
    {
        NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                       ncp_xlf_nca_cfg_ncav3_format_cpu_pool_poolOverflowed,
                       NCP_MSG_ERROR, "Pool %d overflowed! start=%p, end=%p, overFlowAddress=%p\r\n",
                       poolId,
                       (void *)pPoolEntry->poolVA,
                       (void *)pPoolEntry->poolVAEnd,
                       (void *)currBaseVA);

        NCP_CALL(NCP_ST_INTERNAL_ERROR);
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

static ncp_st_t
ncp_ncav3_initialize_cpu_pool(
    int poolId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pool_t *pPoolEntry = &pNcpTaskSwState->taskPools[poolId];
    runtime_mutex_attr_state_t *mtxState = &pPoolEntry->mtxAttr;
    int buffSz[4] = {256, 2048, 16384, 65536};
    int i;

    NCP_CALL(ncp_task_v3_create_lock(&pPoolEntry->poolLock, mtxState));

    for (i = 0; i < NCP_TASK_NUM_BUFF_SIZES; i++)
    {
        pPoolEntry->u.cpu.buffListArray[i].NCP_POINTER(free) = NULL;

        pPoolEntry->u.cpu.buffListArray[i].size = buffSz[i];

        /*
         * Mask is applied to taskAddr to get real buff start.
         * assumes all buffer sizes are power of 2.
         */
        pPoolEntry->u.cpu.buffListArray[i].NCP_POINTER(mask)
            = ~(buffSz[i]-1);
    }

NCP_RETURN_LABEL
    return ncpStatus;
}

ncp_st_t
ncp_ncav3_initialize_cpu_pools(
    ncp_dev_hdl_t dev,
    ncp_bool_t    uMode)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    int i;

    /* Map, initialize & partition, then format */

    for (i = NCP_NCAV3_FIRST_CPU_POOL_ID;
         i < NCP_NCAV3_NUM_TASK_MEMORY_POOLS;
         i++)
    {
        if (uMode != pNcpTaskSwState->taskPools[i].uMode)
        {
            continue;
        }

        if (FALSE == pNcpTaskSwState->taskPools[i].valid)
        {
            continue;
        }

        NCP_CALL(ncp_ncav3_map_cpu_pool(dev, i, uMode));

        NCP_CALL(ncp_ncav3_initialize_cpu_pool(i));

        NCP_CALL(ncp_ncav3_format_cpu_pool(i));

        /* Kernel CPU pools are left mapped until config destroy */
        if (uMode == TRUE)
        {
            NCP_CALL(ncp_ncav3_unmap_cpu_pool(dev, i));
        }
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_map_unscheduled_queues(void)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

#if defined(PROC_ARMA53) && !defined(NCP_KERNEL)
    if (NULL == qpmMMIOBaseAddr)
    {
        qpmMMIOBaseAddr = NCP_TASK_MEM_MMAP(myDevHdl,
                                            NULL,
                                            0x1000000,
                                            0x8021000000);

        NCP_ASSERT(qpmMMIOBaseAddr != NULL, NCP_ST_NO_MEMORY);
    }
#else
    qpmMMIOBaseAddr = NULL;
#endif

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_get_unscheduled_queue_depth(
    ncp_dev_hdl_t dev,
    ncp_uint32_t  unscheduledQueueId,
    ncp_uint16_t *qDepth)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_qpm_cmd_t cmd;
    ncp_uint64_t *cmdPtr = (ncp_uint64_t *) &cmd;
    ncp_ncav3_qpm_elem_count_t data;

    ncp_memset(&cmd, 0, sizeof(cmd));

    cmd.cmd = QPM_RD_ELEMENT_COUNT;
    cmd.axAddr = unscheduledQueueId & 0xFFFF;
#ifdef NCP_KERNEL
    cmd.mmio   = 1;

    /* NCP_REGION_NCAV3_QPM's AXI address is 0x8020080000, but the QPM
     * MMIO operations start at  0x8021000000 so we subtract 0x80000.
     */
    *cmdPtr -= 0x80000;

    NCP_CALL(ncp_block_read64(
                dev,
                NCP_REGION_NCAV3_QPM,
                *cmdPtr,
                (ncp_uint64_t *) &data,
                sizeof(ncp_uint64_t)/8,
                0));
#else
    /* We map the QPM MMIO region into user-space on the A53s. */
    *((ncp_uint64_t *) &data) = *((ncp_uint64_t *) (qpmMMIOBaseAddr + *cmdPtr));
#endif

    *qDepth = data.numElements;

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_pop_unscheduled_queue_head(
    ncp_dev_hdl_t dev,
    ncp_uint32_t unscheduledQueueId,
    ncp_uint64_t *data)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_qpm_cmd_t cmd;
    ncp_uint64_t *cmdPtr = (ncp_uint64_t *) &cmd;

    ncp_memset(&cmd, 0, sizeof(cmd));

    cmd.cmd = QPM_RD_HP;
    cmd.axAddr = unscheduledQueueId & 0xFFFF;
#ifdef NCP_KERNEL
    cmd.mmio   = 1;

    /* NCP_REGION_NCAV3_QPM's AXI address is 0x8020080000, but the QPM
     * MMIO operations start at  0x8021000000 so we subtract 0x80000.
     */
    *cmdPtr -= 0x80000;

    NCP_CALL(ncp_block_read64(
                dev,
                NCP_REGION_NCAV3_QPM,
                *cmdPtr,
                (ncp_uint64_t *) data,
                sizeof(ncp_uint64_t)/8,
                0));
#else
    /* We map the QPM MMIO region into user-space on the A53s. */
    *data = *((ncp_uint64_t *) (qpmMMIOBaseAddr + *cmdPtr));
#endif

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_push_unscheduled_queue_tail(
    ncp_dev_hdl_t dev,
    ncp_uint32_t unscheduledQueueId,
    ncp_uint64_t data)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_qpm_cmd_t cmd;
    ncp_uint64_t *cmdPtr = (ncp_uint64_t *) &cmd;

    ncp_memset(&cmd, 0, sizeof(cmd));

    cmd.cmd = QPM_WR_TP;
    cmd.axAddr = unscheduledQueueId & 0x7FFF;
#ifdef NCP_KERNEL
    cmd.mmio   = 1;

    /* NCP_REGION_NCAV3_QPM's AXI address is 0x8020080000, but the QPM
     * MMIO operations start at  0x8021000000 so we subtract 0x80000.
     */
    *cmdPtr -= 0x80000;

    NCP_CALL(ncp_block_write64(
                dev,
                NCP_REGION_NCAV3_QPM,
                *cmdPtr,
                (ncp_uint64_t *) &data,
                sizeof(ncp_uint64_t)/8,
                0));
#else
    /* We map the QPM MMIO region into user-space on the A53s. */
    *((ncp_uint64_t *) (qpmMMIOBaseAddr + *cmdPtr)) = data;
#endif

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_read_interrupt_queue(
    ncp_dev_hdl_t dev,
    ncp_uint32_t  intQueueId,
    ncp_uint16_t *eventQueueId,
    ncp_uint16_t *intQueueDepth)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_qpm_cmd_t cmd;
    ncp_uint64_t *cmdPtr = (ncp_uint64_t *) &cmd;
    ncp_uint64_t data;

    ncp_memset(&cmd, 0, sizeof(cmd));

    cmd.cmd = QPM_RD_INTQ;
    cmd.axAddr = intQueueId & 0xF;
#ifdef NCP_KERNEL
    cmd.mmio   = 1;

    /* NCP_REGION_NCAV3_QPM's AXI address is 0x8020080000, but the QPM
     * MMIO operations start at  0x8021000000 so we subtract 0x80000.
     */
    *cmdPtr -= 0x80000;

    NCP_CALL(ncp_dev_block_read64(
                dev,
                NCP_REGION_NCAV3_QPM,
               *cmdPtr,
               &data,
                sizeof(ncp_uint64_t)/8,
                0));
#else
    /* We map the QPM MMIO region into user-space on the A53s. */
    data = *((ncp_uint64_t *) (qpmMMIOBaseAddr + *cmdPtr));
#endif

    if (eventQueueId)
    {
        *eventQueueId = data & 0xFFFF;
    }

    if (intQueueDepth)
    {
        *intQueueDepth = (data >> 16) & 0xFFFF;
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_ack_interrupt_queue(
    ncp_dev_hdl_t dev,
    ncp_uint32_t  intQueueId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_qpm_cmd_t cmd;
    ncp_uint64_t *cmdPtr = (ncp_uint64_t *) &cmd;
    ncp_uint64_t data = 0;

    ncp_memset(&cmd, 0, sizeof(cmd));

    cmd.cmd = QPM_WR_INTERRUPT_ACK;
    cmd.axAddr = intQueueId & 0xF;
#ifdef NCP_KERNEL
    cmd.mmio   = 1;

    /* NCP_REGION_NCAV3_QPM's AXI address is 0x8020080000, but the QPM
     * MMIO operations start at  0x8021000000 so we subtract 0x80000.
     */
    *cmdPtr -= 0x80000;

    NCP_CALL(ncp_block_write64(
                dev,
                NCP_REGION_NCAV3_QPM,
               *cmdPtr,
               &data,
                sizeof(ncp_uint64_t)/8,
                0));
#else
    /* We map the QPM MMIO region into user-space on the A53s. */
    *((ncp_uint64_t *) (qpmMMIOBaseAddr + *cmdPtr)) = data;
#endif

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_ack_event_queue_exception(
    ncp_dev_hdl_t dev,
    ncp_uint32_t  eventQueueId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_qpm_cmd_t cmd;
    ncp_uint64_t *cmdPtr = (ncp_uint64_t *) &cmd;
    ncp_uint64_t data = 0;

    ncp_memset(&cmd, 0, sizeof(cmd));

    cmd.cmd = QPM_WR_EXCEPTION_ACK_MM;
    cmd.axAddr = eventQueueId & 0xFFFF;
#ifdef NCP_KERNEL
    cmd.mmio   = 1;

    /* NCP_REGION_NCAV3_QPM's AXI address is 0x8020080000, but the QPM
     * MMIO operations start at  0x8021000000 so we subtract 0x80000.
     */
    *cmdPtr -= 0x80000;

    NCP_CALL(ncp_block_write64(
                dev,
                NCP_REGION_NCAV3_QPM,
               *cmdPtr,
               &data,
                sizeof(ncp_uint64_t)/8,
                0));
#else
    /* We map the QPM MMIO region into user-space on the A53s. */
    *((ncp_uint64_t *) (qpmMMIOBaseAddr + *cmdPtr)) = data;
#endif

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_map_shared_data_regions(
    ncp_task_pvt_tqsHdl_data_t *tqsHdl)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_cpu_profile_t *profile;
    int i;

    if (0 == pNcpTaskSwState->numSharedDataRegions)
    {
        NCP_RETURN(NCP_ST_SUCCESS);
    }

    if (sharedDataRegionMapCnt == NULL)
    {
        sharedDataRegionMapCnt = ncp_malloc(
            sizeof(int) * pNcpTaskSwState->numSharedDataRegions);

        NCP_ASSERT(sharedDataRegionMapCnt != NULL, NCP_ST_ERROR);

        ncp_memset(sharedDataRegionMapCnt,
                0,
                sizeof(int) * pNcpTaskSwState->numSharedDataRegions);
    }

    profile = &tqsHdl->pTqs->pAppProfile->baseProfile;

    for (i = 0; i < profile->numSharedDataRegionMaps; i++)
    {
        ncp_ncav3_shared_data_region_map_t *sdrMap;
        int id;

        sdrMap = &profile->sharedDataRegionMap[i];

        id = sdrMap->regionId;

        if (sdrMap->enabled && (sharedDataRegionMapCnt[id] == 0))
        {
            ncp_uintptr_t mmapVA;

            mmapVA = (ncp_uintptr_t) NCP_TASK_MEM_MMAP(
                    myDevHdl,
                    pNcpTaskSwState->sharedDataRegions[id].virtualBase,
                    pNcpTaskSwState->sharedDataRegions[id].size,
                    pNcpTaskSwState->sharedDataRegions[id].physicalBase);

            NCP_ASSERT(mmapVA ==
                    pNcpTaskSwState->sharedDataRegions[id].virtualBase,
                    NCP_ST_TASK_SHARED_DATA_REGION_MMAP_FAILED);
        }

        sharedDataRegionMapCnt[id]++;
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_unmap_shared_data_regions(
    ncp_task_pvt_tqsHdl_data_t *tqsHdl)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    int i;

    if (sharedDataRegionMapCnt != NULL)
    {
        for (i = 0; i < pNcpTaskSwState->numSharedDataRegions; i++)
        {
            ncp_ncav3_shared_region_t *sdr;

            sdr = &pNcpTaskSwState->sharedDataRegions[i];

            if (sharedDataRegionMapCnt[i] > 0)
            {
                sharedDataRegionMapCnt[i]--;

                if (sharedDataRegionMapCnt[i] == 0)
                {
                    NCP_TASK_MEM_UNMAP(dev,
                            (void *) sdr->virtualBase,
                            sdr->size);
                }
            }
        }
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_map_fixed_pool(
    ncp_ncav3_cpu_profile_t *profile)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pool_t *pPoolEntry;

    if (FALSE == pNcpTaskSwState->fixedPoolInfo.valid)
    {
        NCP_RETURN(NCP_ST_SUCCESS);
    }

    if (FALSE == profile->fixedPoolMap.enabled)
    {
        NCP_RETURN(NCP_ST_SUCCESS);
    }

    pPoolEntry = &pNcpTaskSwState->taskPools[NCP_TASK_FIXED_POOL_ENCODED_ID];

    if (fixedPoolMapCnt == 0)
    {
        ncp_uintptr_t mmapVA;

        mmapVA = (ncp_uintptr_t) NCP_TASK_MEM_MMAP(
                myDevHdl,
#ifdef NCP_KERNEL
                0ULL,
#else
                profile->fixedPoolMap.virtualStartAddress,
#endif
                pNcpTaskSwState->fixedPoolInfo.size,
                pNcpTaskSwState->fixedPoolInfo.physicalBase);

#ifndef NCP_KERNEL
        NCP_ASSERT(mmapVA == profile->fixedPoolMap.virtualStartAddress,
                NCP_ST_TASK_FIXED_POOL_MMAP_FAILED);
#else
        NCP_ASSERT(mmapVA != 0ULL, NCP_ST_TASK_FIXED_POOL_MMAP_FAILED);

        /* virtualBase update required for configuring addr_convert RAM */
        pNcpTaskSwState->fixedPoolInfo.virtualBase = mmapVA;
        /* pPoolEntry update required for task validation */
        pPoolEntry->poolVA = mmapVA;
        pPoolEntry->poolVAEnd = mmapVA + pNcpTaskSwState->fixedPoolInfo.size;
#endif
    }

    fixedPoolMapCnt++;

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_unmap_fixed_pool(void)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    if (fixedPoolMapCnt > 0)
    {
        fixedPoolMapCnt--;

        if (fixedPoolMapCnt == 0)
        {
            NCP_TASK_MEM_UNMAP(dev,
                    (void *) pNcpTaskSwState->fixedPoolInfo.virtualBase,
                    pNcpTaskSwState->fixedPoolInfo.size);

#ifdef NCP_KERNEL
            pNcpTaskSwState->fixedPoolInfo.virtualBase = 0ULL;
#endif
        }
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_dmm_allocate(
    ncp_task_pvt_tqsHdl_data_t *tqsHdl,
    ncp_uint8_t tqsId,
    ncp_uint8_t poolId,
    ncp_uint8_t size,
    ncp_uint64_t *pBuffer)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_uint32_t offset;

    ncp_memset(&offset, 0, sizeof(ncp_uint32_t));

    offset = (tqsId << 15) | ((poolId & 0x7) << 12) | ((size & 0x3) << 6);

    NCP_CALL(ncp_block_read64(
                myDevHdl,
                NCP_REGION_NCAV3_DMM,
                offset,
                pBuffer,
                sizeof(ncp_uint64_t)/8,
                0));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_dmm_free(
    ncp_task_pvt_tqsHdl_data_t *tqsHdl,
    ncp_uint8_t tqsId,
    ncp_uint8_t poolId,
    ncp_uint8_t size,
    ncp_bool_t  mref,
    ncp_uint64_t pBuffer)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_uint32_t offset;

    ncp_memset(&offset, 0, sizeof(ncp_uint32_t));

    offset = (tqsId << 15) | ((poolId & 0x7) << 12) |
             (mref << 8)   | ((size & 0x3) << 6);

    NCP_CALL(ncp_block_write64(
                myDevHdl,
                NCP_REGION_NCAV3_DMM,
                offset,
                &pBuffer,
                sizeof(ncp_uint64_t)/8,
                0));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_init_tqs_configuration_state(
    ncp_ncav3_hdl_t                 *nca,
    ncp_uint8_t                      pgitId,
    ncp_ncav3_application_profile_t *profile,
    ncp_task_tqs_shared_t           *flags,
    ncp_bool_t                       updateKernelTQSState)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_tqs_swState_t *pTqsSwState;
    int i;

    pTqsSwState = &pNcpTaskSwState->tqsSwState[pgitId];

    pTqsSwState->validPoolsMask = 0;

    pTqsSwState->tqsId = pgitId;

    if (profile->baseProfile.cpuPoolMap.enabled)
    {
        /* The real CPU PoolId */
        pTqsSwState->validPoolsMask |= (0x1 << profile->baseProfile.cpuPoolMap.poolId);
        /* The logical CPU PoolId (0) */
        pTqsSwState->validPoolsMask |= (0x1 << 0);
    }

    /* The fixed pool uses encoded pool ID 1 */
    if (profile->baseProfile.fixedPoolMap.enabled)
    {
        pTqsSwState->validPoolsMask |= (0x1 << 1);
    }

    for (i = 0; i < profile->baseProfile.numSharedPoolMaps; i++)
    {
        ncp_ncav3_shared_pool_map_t *poolMap =
            &profile->baseProfile.sharedPoolMaps[i];
        pTqsSwState->validPoolsMask |= (1 << poolMap->poolMap.poolId);
    }

    for (i = 0; i < 8; i++)
    {
        pTqsSwState->mmeAllocator[i].valid = FALSE;
    }

    if (flags != NULL)
    {
        memcpy(&pTqsSwState->shareCtl.shareFlags,
                flags,
                sizeof(ncp_task_tqs_shared_t));
    }

    pTqsSwState->pAppProfile = profile;

    pTqsSwState->profileId = profile->baseProfile.id;

    pTqsSwState->configured = TRUE;

    if (updateKernelTQSState)
    {
        NCP_CALL(ncp_ncav3_update_kernel_tqs_state(
            myDevHdl,
            pgitId,
            pTqsSwState->profileId));
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_fpga_lookup_ipd_entry(
    ncp_dev_hdl_t dev,
    ncp_uint8_t ncapId,
    ncp_uint8_t relTqsId,
    ncp_uint8_t *pgitId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_nca_itp_ipd_ram_r_t r0;
    ncp_bool_t found = FALSE;
    int i;

    NCP_ASSERT(pgitId != NULL, NCP_ST_INTERNAL_ERROR);

    /* ipcq_online[0] and ipcq_valid[0] correspond to IPD[0], *not* iPCQ 0.
     * On the simulator and the ASIC, which have 86 IPD entries, so we can
     * let ipcq_online[X] and ipcq_valid[X] correspond to iPCQ X by
     * entering the IPD entries in order. On the FPGA, which has 16 IPD
     * entries available, we have to pack the entries. So we need to
     * find the IPD entry containing this pgitId before turning it on.
     */

    for (i = 0; i < 16; i++)
    {
        NCP_CALL(ncp_block_read32(
                    dev,
                    NCP_REGION_NCAV3_CORE,
                    NCP_NCA_ITP_IPD_RAM(i) + NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                    (ncp_uint32_t *) &r0,
                    sizeof(r0)/4,
                    0));

        /** ncapaddr resets to 0, so we won't get any false positives */
        if (r0.pgit == relTqsId && r0.ncapaddr == (ncapId + 1))
        {
            found = TRUE;
            break;
        }
    }

    if (found == TRUE)
    {
        *pgitId = i;
    }
    else
    {
        ncpStatus = NCP_ST_ERROR;
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

static ncp_st_t
ncp_ncav3_fpga_find_free_ipd_entry(
    ncp_dev_hdl_t dev,
    ncp_uint8_t *ipdEntry)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_nca_itp_ipd_ram_r_t r0;
    ncp_bool_t found = FALSE;
    int i;

    NCP_ASSERT(ipdEntry != NULL, NCP_ST_INTERNAL_ERROR);

    for (i = 0; i < 16; i++)
    {
        NCP_CALL(ncp_block_read32(
                    dev,
                    NCP_REGION_NCAV3_CORE,
                    NCP_NCA_ITP_IPD_RAM(i) + NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                    (ncp_uint32_t *) &r0,
                    sizeof(r0)/4,
                    0));

        /** ncapaddr resets to 0, so we won't get any false positives */
        if (r0.ncapaddr == 0)
        {
            found = TRUE;
            break;
        }
    }

    NCP_ASSERT(found == TRUE, NCP_ST_ERROR);

    *ipdEntry = i;

NCP_RETURN_LABEL

    return ncpStatus;
}


ncp_st_t
ncp_ncav3_get_app_profile(
    ncp_t *ncp,
    ncp_uint32_t appProfileId,
    ncp_ncav3_application_profile_t **appProfile)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_hdl_t *nca;
    int i;

    NCP_CHECK(NULL != ncp, NCP_ST_INVALID_HANDLE);

    nca = ncp->ncaHdl;

    NCP_CHECK(NULL != nca, NCP_ST_INVALID_HANDLE);

    *appProfile = NULL;

    for (i = 0; i < nca->configInfo.numProfiles; i++)
    {
        ncp_int32_t id = nca->configInfo.profiles[i].baseProfile.id;

        if (id == appProfileId)
        {
            *appProfile = &nca->configInfo.profiles[i];
            break;
        }
    }

    if (*appProfile == NULL)
    {
        ncpStatus = NCP_ST_ERROR;
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_get_app_profile_from_name(
    ncp_t *ncp,
    char  *name,
    ncp_ncav3_application_profile_t **appProfile)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_hdl_t *nca;
    int i;

    NCP_CHECK(NULL != ncp, NCP_ST_INVALID_HANDLE);

    nca = ncp->ncaHdl;

    NCP_CHECK(NULL != nca, NCP_ST_INVALID_HANDLE);

    *appProfile = NULL;

    for (i = 0; i < nca->configInfo.numProfiles; i++)
    {
        char *profileName = nca->configInfo.profiles[i].baseProfile.name.name;

        if (strncmp(name, profileName, sizeof(ncp_task_resource_name_t)) == 0)
        {
            *appProfile = &nca->configInfo.profiles[i];
            break;
        }
    }

    if (*appProfile == NULL)
    {
        ncpStatus = NCP_ST_ERROR;
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_get_app_profile_id_from_name(
    ncp_t *ncp,
    char  *name,
    ncp_uint32_t *appProfileId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_application_profile_t *appProfile;
    ncp_ncav3_hdl_t *nca;
    int i;

    NCP_CHECK(NULL != ncp, NCP_ST_INVALID_HANDLE);

    nca = ncp->ncaHdl;

    NCP_CHECK(NULL != nca, NCP_ST_INVALID_HANDLE);

    appProfile = NULL;

    for (i = 0; i < nca->configInfo.numProfiles; i++)
    {
        char *profileName = nca->configInfo.profiles[i].baseProfile.name.name;

        if (strncmp(name, profileName, sizeof(ncp_task_resource_name_t)) == 0)
        {
            appProfile = &nca->configInfo.profiles[i];

            *appProfileId = appProfile->baseProfile.id;

            break;
        }
    }

    if (appProfile == NULL)
    {
        ncpStatus = NCP_ST_ERROR;
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_get_ncap_and_tqs_id_from_absolute_group_id(
    ncp_uint8_t grpId,
    ncp_uint8_t *ncapId,
    ncp_uint8_t *relTqsId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    if (grpId < 64)
    {
        *ncapId =   grpId / 8;
        *relTqsId = grpId % 8;
    }
    else if (grpId < 80)
    {
        *ncapId =   ((grpId - 64) / 4) + 9;
        *relTqsId = ((grpId - 64) % 4);
    }
    else if (grpId < 86)
    {
        *ncapId = 8;
        *relTqsId = grpId - 80;
    }
    else
    {
        NCP_RETURN(NCP_ST_ERROR);
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_get_unscheduled_recv_queue_profile_from_name(
    ncp_t *ncp,
    char  *name,
    ncp_ncav3_nca_queue_profile_t **queueProfile)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_unscheduled_queue_config_t *config;
    ncp_ncav3_hdl_t *nca;
    int i;

    NCP_CHECK(NULL != ncp, NCP_ST_INVALID_HANDLE);

    nca = ncp->ncaHdl;

    NCP_CHECK(NULL != nca, NCP_ST_INVALID_HANDLE);

    *queueProfile = NULL;

    config = &nca->configInfo.unscheduledQueueConfig;

    for (i = 0; i < config->numProfiles; i++)
    {
        char *profileName = config->queueProfiles[i].name.name;

        if (strncmp(name, profileName, sizeof(ncp_task_resource_name_t)) == 0)
        {
            *queueProfile = &config->queueProfiles[i];
            break;
        }
    }

    if (*queueProfile == NULL)
    {
        ncpStatus = NCP_ST_INVALID_PARAMETER;
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_get_queue_profile(
    ncp_int32_t                     profileId,
    ncp_ncav3_nca_queue_profile_t **queueProfile)
{
    ncp_st_t ncpStatus = NCP_ST_ERROR;
    ncp_ncav3_task_receive_queue_config_t *config;
    ncp_ncav3_nca_queue_profile_t *profiles;
    ncp_int32_t                    numProfiles;
    int i;

    config = &pNcpTaskSwState->nca->configInfo.taskReceiveQueues;

    profiles = config->queueProfiles;
    numProfiles = config->numProfiles;

    NCP_ASSERT(profiles != NULL, NCP_ST_INTERNAL_ERROR);
    NCP_ASSERT(queueProfile != NULL, NCP_ST_INTERNAL_ERROR);

    for (i = 0; i < numProfiles; i++)
    {
        if (profileId == profiles[i].id)
        {
            *queueProfile = &profiles[i];
            NCP_RETURN(NCP_ST_SUCCESS);
        }
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_write_itp_tpd_ram_entry(
    ncp_dev_hdl_t                dev,
    ncp_ncav3_nca_queue_state_t *queue)
{
    ncp_ncav3_nca_queue_profile_t *queueProfile;
    ncp_ncav3_application_profile_t *appProfile;
    ncp_ncav3_task_receive_queue_config_t *config;
    ncp_nca_itp_tpd_ram_r_t r0;
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    int i;

    config = &pNcpTaskSwState->nca->configInfo.taskReceiveQueues;

    ncp_memset(&r0, 0, sizeof(r0));

    NCP_CALL(ncp_ncav3_get_queue_profile(
                queue->queueProfileId,
                &queueProfile));

    NCP_CALL(ncp_ncav3_get_app_profile(
                pNcpTaskSwState->ncp,
                queueProfile->appProfileId,
                &appProfile));

    NCP_ASSERT(queueProfile != NULL, NCP_ST_ERROR);

    for (i = 0; i < queueProfile->numAllowedPools; i++)
    {
        if (queueProfile->allowedPools[i].enabled == FALSE)
        {
            continue;
        }

        switch (queueProfile->allowedPools[i].poolId)
        {
            case 2:
                r0.formatrequirement4_2 = 1;
                break;

            case 3:
                r0.formatrequirement4_3 = 1;
                break;

            case 4:
                r0.formatrequirement4_4 = 1;
                break;

            case 5:
                r0.formatrequirement4_5 = 1;
                break;

            case 6:
                r0.formatrequirement4_6 = 1;
                break;

            case 7:
                r0.formatrequirement4_7 = 1;
                break;

            case 31:
                r0.formatrequirement4_1 = 1;
                break;

            default:
                break;
        }
    }

    r0.formatrequirement5 = queueProfile->copyRuleForceCopy;
    r0.formatrequirement3 = queueProfile->copyRuleMinFirstBlockPduOffset;
    r0.formatrequirement2 = queueProfile->copyRuleMinPduDataInFirstBlock;
    r0.formatrequirement1 = queueProfile->copyRuleMinModifiableLength;
    r0.formatrequirement0 = queueProfile->copyRuleSeparateHeader;

    /* Use 256B blocks for separate task headers */
    r0.size = 0;

    r0.copypool = queueProfile->copyPool;

    r0.endiantaskdata = appProfile->baseProfile.endianness;
    r0.endianparameter = !appProfile->baseProfile.parameterEndianness;

    r0.virtualregion = appProfile->baseProfile.virtualRegionId;

    r0.traceordered = queue->traceEnabled;
    r0.online = 0;
    r0.priority = queue->priority;
    r0.gid = queue->groupId;
    r0.class = pNcpTaskSwState->queueGroups[queue->groupId].queueType;

    NCP_CALL(ncp_block_write32(
                dev,
                NCP_REGION_NCAV3_CORE,
                NCP_NCA_ITP_TPD_RAM(queue->tqId) +
                    NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                (ncp_uint32_t *) &r0,
                sizeof(r0)/4,
                0));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_initialize_tqs_control(
    ncp_t                   *ncp,
    ncp_uint8_t              pgitId,
    ncp_ncav3_cpu_profile_t *profile)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_hdl_t *nca = ncp->ncaHdl;
    ncp_ncav3_tqs_control_t *tqsControl;

    NCP_ASSERT(ncp->domainIsInternal, NCP_ST_INTERNAL_ERROR);

    tqsControl = (ncp_ncav3_tqs_control_t *) &nca->tqsArray[pgitId];

    memcpy(tqsControl, profile->initDataStructure.bin, 256);

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_enable_pgit_timers(
    ncp_dev_hdl_t dev,
    int           ncapId,
    int           relativeTqsId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ncap_grp_load_timer_enable_reg_t   r0;
    ncp_ncap_grp_upload_timer_enable_reg_t r1;

    ncp_memset(&r0, 0, sizeof(r0));
    ncp_memset(&r1, 0, sizeof(r1));

    NCP_ASSERT(relativeTqsId <= 7, NCP_ST_ERROR);

    r0.grp_load_timer_en |= (1 << relativeTqsId);
    r1.grp_upload_timer_en |= (1 << relativeTqsId);

    NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
            NCP_REGION_AXIS_AXI2SER8_A53_NCAP_NLINKS(ncapId),
            NCP_NCAP_GRP_LOAD_TIMER_ENABLE_WOSET,
            (ncp_uint32_t *)&r0);

    NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
            NCP_REGION_AXIS_AXI2SER8_A53_NCAP_NLINKS(ncapId),
            NCP_NCAP_GRP_UPLOAD_TIMER_ENABLE_WOSET,
            (ncp_uint32_t *)&r1);

NCP_RETURN_LABEL

    return ncpStatus;
}

/* FIXME: Move me */
#define PACKED_NCAV3_GRP_ID(ncapId, tqsId) \
    (((ncapId) & 0xf) << 4) | ((tqsId & 0x7) << 1)

static ncp_st_t
ncp_ncav3_config_mtp_mpcq_lookup(
    ncp_dev_hdl_t            dev,
    int                      ncapId,
    int                      relTqsId,
    int                      pgitId,
    ncp_ncav3_cpu_profile_t *profile)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_nca_mtp_mtp_mpcq_lu_r_t r0;

    /* NCAv3 expects NCAP IDs from 1-13 */
    ncp_uint8_t index = PACKED_NCAV3_GRP_ID(ncapId + 1, relTqsId);

    ncp_memset(&r0, 0, sizeof(r0));

    r0.mqg = pNcpTaskSwState->tqsSwState[pgitId].mqg;

    r0.trans_id = profile->virtualRegionId;

    r0.valid = 1;

    NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
            NCP_REGION_NCAV3_CORE,
            NCP_NCA_MTP_MPCQ_LOOKUP(index) + NCP_NCA_CORE_MTP_ADDR_MAP_BASE,
            (ncp_uint32_t *) &r0);

NCP_RETURN_LABEL

    return ncpStatus;
}

static ncp_st_t
ncp_ncav3_config_mtp_dmm_lookup(
    ncp_dev_hdl_t  dev,
    int            pgitId,
    ncp_ncav3_cpu_profile_t *profile)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_nca_mtp_mtp_dmm_lu_r_t r0;

    ncp_uint8_t index = pgitId;

    ncp_memset(&r0, 0, sizeof(r0));

    r0.mqg = pNcpTaskSwState->tqsSwState[pgitId].mqg;

    r0.trans_id = profile->virtualRegionId;

    r0.valid = 1;

    NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
            NCP_REGION_NCAV3_CORE,
            NCP_NCA_MTP_DMM_LOOKUP(index) + NCP_NCA_CORE_MTP_ADDR_MAP_BASE,
            (ncp_uint32_t *) &r0);


NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_init_ipd_ram(
    ncp_t        *ncp,
    ncp_dev_hdl_t dev,
    ncp_uint32_t ncapId,
    ncp_uint32_t relTqsId,
    ncp_uint8_t  pgitId,
    ncp_ncav3_cpu_profile_t *profile)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    iPCQ_info_t *ipcqInfo;
    ncp_uint8_t ipd_entry = 0;
    int i;

    ncp_nca_itp_ipd_ram_r_t r0;

    ncp_memset(&r0, 0, sizeof(r0));

    ipcqInfo = &pNcpTaskSwState->tqsSwState[pgitId].rxQ.u.ipcq_info;

    if (ncp->isFPGA)
    {
        /* Re-use the existing IPD RAM entry, if this TQS has one */
        ncpStatus = ncp_ncav3_fpga_lookup_ipd_entry(dev, ncapId, relTqsId, &ipd_entry);

        if (ncpStatus == NCP_ST_ERROR)
        {
            ncpStatus = ncp_ncav3_fpga_find_free_ipd_entry(dev, &ipd_entry);
        }

        if (ncpStatus != NCP_ST_SUCCESS)
        {
            NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                    ncp_xlf_nca_cfg_ncav3_init_ipd_ram_moreTQSesThanFPGAImageSupports,
                    NCP_MSG_ERROR,
                    "[%s()] The FPGA only contains 16 iPCQs,"
                    " but the configuration file specifies more than 16 enabled"
                    " TQses.\n", __func__);
            NCP_CALL(NCP_ST_TASK_IPCQ_CONFIGURATION_EXCEEDS_16);
        }
    }

    for (i = 0; i < NCP_NCAV3_NUM_QUEUE_GROUPS_PER_IPCQ; i++)
    {
        /* If groupIndexes[i] == -1, that entry is unused */
        if (ipcqInfo->groupIndexes[i] == -1)
        {
            continue;
        }

        switch (i) {
            case 7:
                r0.gid7_enable = 1;
                r0.gid7_pri = ipcqInfo->groupPriorities[7];
                r0.gid7 = ipcqInfo->groupIndexes[7];
                break;
            case 6:
                r0.gid6_enable = 1;
                r0.gid6_pri = ipcqInfo->groupPriorities[6];
                r0.gid6 = ipcqInfo->groupIndexes[6];
                break;
            case 5:
                r0.gid5_enable = 1;
                r0.gid5_pri = ipcqInfo->groupPriorities[5];
                r0.gid5 = ipcqInfo->groupIndexes[5];
                break;
            case 4:
                r0.gid4_enable = 1;
                r0.gid4_pri = ipcqInfo->groupPriorities[4];
                r0.gid4 = ipcqInfo->groupIndexes[4];
                break;
            case 3:
                r0.gid3_enable = 1;
                r0.gid3_pri = ipcqInfo->groupPriorities[3];
                r0.gid3_7_4 = (ipcqInfo->groupIndexes[3] >> 4) & 0xF;
                r0.gid3_3_0 = ipcqInfo->groupIndexes[3] & 0xF;
                break;
            case 2:
                r0.gid2_enable = 1;
                r0.gid2_pri = ipcqInfo->groupPriorities[2];
                r0.gid2 = ipcqInfo->groupIndexes[2];
                break;
            case 1:
                r0.gid1_enable = 1;
                r0.gid1_pri = ipcqInfo->groupPriorities[1];
                r0.gid1 = ipcqInfo->groupIndexes[1];
                break;
            case 0:
                r0.gid0_enable = 1;
                r0.gid0_pri = ipcqInfo->groupPriorities[0];
                r0.gid0 = ipcqInfo->groupIndexes[0];
                break;
        }
    }

    NCP_ASSERT((ncapId + 1) >= 1 && (ncapId + 1 <= 13), NCP_ST_ERROR);
    NCP_ASSERT(relTqsId <= 7, NCP_ST_ERROR);

    r0.ncapaddr = ncapId + 1;
    r0.pgit = relTqsId;
    /* reserved1 controls the ipcq_credit_threshold. 7 is the recommended value
     * to avoid ready-list flow starvation.
     */
    r0.reserved1 = 0x7;

    /* threshold limits the number of active tasks (i.e. delivered to the PE
     * and awaiting task completion). */
    r0.threshold = profile->receiveQueueDepth;

    r0.mqg = pNcpTaskSwState->tqsSwState[pgitId].mqg;

    if (ncp->isFPGA)
    {
        /* We use ipd_entry to index the IPD. On the ASIC, we use the PGIT ID.
         * However, on the FPGA there are only 16 entries, so we have to pack
         * the entries.
         */

        NCP_CALL(ncp_block_write32(
                    dev,
                    NCP_REGION_NCAV3_CORE,
                    NCP_NCA_ITP_IPD_RAM(ipd_entry) + NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                    (ncp_uint32_t *) &r0,
                    sizeof(r0)/4,
                    0));
    }
    else
    {
        NCP_CALL(ncp_block_write32(
                    dev,
                    NCP_REGION_NCAV3_CORE,
                    NCP_NCA_ITP_IPD_RAM(pgitId) + NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                    (ncp_uint32_t *) &r0,
                    sizeof(r0)/4,
                    0));
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

static ncp_st_t
ncp_ncav3_config_otp_odts_ram_entry(
        ncp_t                   *ncp,
        ncp_dev_hdl_t            dev,
        int                      ncapId,
        int                      relTqsId,
        ncp_uint8_t              pgitId,
        ncp_ncav3_cpu_profile_t *profile)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_nca_otp_odts_ram_r_t r0;
    ncp_uint8_t index;
    int i, j;

    ncp_memset(&r0, 0, sizeof(r0));

    for (i = 0; i < NCP_NCAV3_NUM_OPCQS_PER_TQS; i++)
    {
        r0.opcq_2_0 = ((pgitId << 1) + i) & 0x7;
        r0.opcq_9_3 = ((pgitId << 1) >> 3) & 0x7F;

        r0.endiantaskdata = profile->endianness;
        r0.endianparameter = !profile->parameterEndianness;

        if (profile->cpuPoolMap.enabled)
        {
            r0.cpupoolid = profile->cpuPoolMap.poolId;
        }
        else
        {
            r0.cpupoolid = 0;
        }

        r0.virtualregion = profile->virtualRegionId;

        r0.copypool = profile->taskSendCopyPool;

        for (j = 0; j < profile->numSharedPoolMaps; j++)
        {
            ncp_ncav3_shared_pool_map_t *poolMap = &profile->sharedPoolMaps[j];
            r0.allowedpools |= 1 << (poolMap->poolMap.poolId - 1);
        }

        if (profile->fixedPoolMap.enabled)
        {
            r0.allowedpools |= 0x1;
        }

        r0.mqg = pNcpTaskSwState->tqsSwState[pgitId].mqg;

        /* NCAv3 expects NCAP IDs from 1-13 */
        index = PACKED_NCAV3_GRP_ID(ncapId + 1, relTqsId) | i;

        NCP_CALL(ncp_block_write32(
                    dev,
                    NCP_REGION_NCAV3_CORE,
                    NCP_NCA_OTP_ODTS_RAM(index) +
                        NCP_NCA_CORE_OTP_ADDR_MAP_BASE,
                    (ncp_uint32_t *) &r0,
                    sizeof(r0)/4,
                    0));
    }

NCP_RETURN_LABEL

    return ncpStatus;
}


static ncp_st_t
ncp_ncav3_config_otp_odtd_ram_entry(
    ncp_dev_hdl_t            dev,
    ncp_uint8_t              pgitId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_nca_otp_odtd_ram_r_t r0;

    ncp_memset(&r0, 0, sizeof(r0));

    r0.mqg = pNcpTaskSwState->tqsSwState[pgitId].mqg;

    NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
            NCP_REGION_NCAV3_CORE,
            NCP_NCA_OTP_ODTD_RAM(pgitId) + NCP_NCA_CORE_OTP_ADDR_MAP_BASE,
            (ncp_uint32_t *) &r0);

NCP_RETURN_LABEL

    return ncpStatus;
}

static ncp_st_t
ncp_ncav3_config_otp_ctrl_destipcq(
    ncp_dev_hdl_t   dev,
    ncp_uint8_t     pgitId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_nca_otp_control_destipcq_00_r_t r0;
    int word, shift;

    word  = pgitId / 32;
    shift = pgitId % 32;

    ncp_memset(&r0, 0, sizeof(r0));

    NCP_DEV_NCA_READ_REG32(dev,
            NCP_REGION_NCAV3_CORE,
            NCP_NCA_OTP_CONTROL_DESTIPCQ_00 + 4*word +
                NCP_NCA_CORE_OTP_ADDR_MAP_BASE,
            (ncp_uint32_t *) &r0);

    r0.enable_destipcq |= 1 << shift;

    NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
            NCP_REGION_NCAV3_CORE,
            NCP_NCA_OTP_CONTROL_DESTIPCQ_00 + 4*word +
                NCP_NCA_CORE_OTP_ADDR_MAP_BASE,
            (ncp_uint32_t *) &r0);

NCP_RETURN_LABEL

    return ncpStatus;
}

typedef struct {
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 21;
     unsigned      grn                                       :  3;
     unsigned      reserved1                                 :  3;
     unsigned      m_pool_id                                 :  5;
#else    /* Little Endian */
     unsigned      m_pool_id                                 :  5;
     unsigned      reserved1                                 :  3;
     unsigned      grn                                       :  3;
     unsigned      reserved0                                 : 21;
#endif
} ncp_ncap_PCQ_desc_cmbnd_reg0_t;

typedef struct {
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  8;
     unsigned      number_of_queue_entries                   :  8;
     unsigned      reserved1                                 :  4;
     unsigned      atfc                                      :  1;
     unsigned      enable_bit                                :  1;
     unsigned      reserved2                                 :  5;
     unsigned      q_pool_id                                 :  5;
#else    /* Little Endian */
     unsigned      q_pool_id                                 :  5;
     unsigned      reserved2                                 :  5;
     unsigned      enable_bit                                :  1;
     unsigned      atfc                                      :  1;
     unsigned      reserved1                                 :  4;
     unsigned      number_of_queue_entries                   :  8;
     unsigned      reserved0                                 :  8;
#endif
} ncp_ncap_PCQ_desc_cmbnd_reg1_t;

typedef struct {
#ifdef NCP_BIG_ENDIAN
     unsigned      mpcq_almost_full_depth                    :  8;
     unsigned      mpcq_almost_empty_depth                   :  8;
     unsigned      reserved0                                 :  2;
     unsigned      cbit_overide                              :  1;
     unsigned      cpa_overide                               :  1;
     unsigned      apcq_cmplt                                :  1;
     unsigned      apcq_cpa                                  :  1;
     unsigned      mpcq_num_bufs_per_req                     :  2;
     unsigned      reserved1                                 :  4;
     unsigned      q_vi_upper                                :  4;
#else    /* Little Endian */
     unsigned      q_vi_upper                                :  4;
     unsigned      reserved1                                 :  4;
     unsigned      mpcq_num_bufs_per_req                     :  2;
     unsigned      apcq_cpa                                  :  1;
     unsigned      apcq_cmplt                                :  1;
     unsigned      cpa_overide                               :  1;
     unsigned      cbit_overide                              :  1;
     unsigned      reserved0                                 :  2;
     unsigned      mpcq_almost_empty_depth                   :  8;
     unsigned      mpcq_almost_full_depth                    :  8;
#endif
} ncp_ncap_PCQ_desc_cmbnd_reg2_t;

typedef struct {
     unsigned  int                q_vi_lower;
} ncp_ncap_PCQ_desc_cmbnd_reg3_t;

ncp_st_t
ncp_ncav3_init_pcq_descriptor(
    ncp_t                   *ncp,
    ncp_dev_hdl_t            dev,
    ncp_uint32_t             ncapId,
    ncp_uint32_t             relativeTqsId,
    ncp_uint8_t              pgitId,
    ncp_ncav3_cpu_profile_t *profile,
    ncp_ncav3_pcq_type_t     type,
    ncp_uint32_t             queueId,
    ncp_uint32_t             physBase,
    ncp_uint8_t              upperBits)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_hdl_t *nca = ncp->ncaHdl;
    ncp_ncav3_tqs_control_t *tqsControl;
    ncp_uint8_t blockSize = (queueId & 0x3);
    int poolMapIndex = (queueId >> 2);
    ncp_uint32_t offset[4];

    /* ncp_ncap_PCQ_desc_reg0_t is identical to ncp_ncap_PCQ_desc_mme_reg0_t,
        except more reserved entries, so just use the mPCQ version. */
    ncp_ncap_PCQ_desc_cmbnd_reg0_t r0;
    ncp_ncap_PCQ_desc_cmbnd_reg1_t r1;
    ncp_ncap_PCQ_desc_cmbnd_reg2_t r2;
    ncp_ncap_PCQ_desc_cmbnd_reg3_t r3;

    ncp_uint32_t qDepth;
    ncp_uint64_t virtBaseAddr;
    ncp_uint64_t physBaseAddr;

    ncp_memset(&r0, 0, sizeof(r0));
    ncp_memset(&r1, 0, sizeof(r1));
    ncp_memset(&r2, 0, sizeof(r2));
    ncp_memset(&r3, 0, sizeof(r3));

    tqsControl = (ncp_ncav3_tqs_control_t *) profile->initDataStructure.bin;

    if (physBase == 0xFFFFFFFF)
    {
        virtBaseAddr = (ncp_uint64_t)(ncp_uintptr_t) &nca->tqsArray[pgitId];
    }
    else
    {
        virtBaseAddr = (ncp_uint64_t) physBase;
    }

    switch (type)
    {
        case IPCQ:
            offset[0] = NCP_NCAP_PCQ_DESC_IPCQ_R0(relativeTqsId);
            offset[1] = NCP_NCAP_PCQ_DESC_IPCQ_R1(relativeTqsId);
            offset[2] = NCP_NCAP_PCQ_DESC_IPCQ_R2(relativeTqsId);
            offset[3] = NCP_NCAP_PCQ_DESC_IPCQ_R3(relativeTqsId);

            qDepth = tqsControl->tqs.control.ipcq_depth;
            virtBaseAddr += (tqsControl->tqs.control.ipcq_offset << 4);
            break;

        case OPCQ:
            /* 2 oPCQs per TQS */
            offset[0] = NCP_NCAP_PCQ_DESC_OPCQ_R0(relativeTqsId*2 + queueId);
            offset[1] = NCP_NCAP_PCQ_DESC_OPCQ_R1(relativeTqsId*2 + queueId);
            offset[2] = NCP_NCAP_PCQ_DESC_OPCQ_R2(relativeTqsId*2 + queueId);
            offset[3] = NCP_NCAP_PCQ_DESC_OPCQ_R3(relativeTqsId*2 + queueId);

            if (queueId == 0)
            {
                qDepth = tqsControl->tqs.control.opcq0_depth;
                virtBaseAddr += (tqsControl->tqs.control.opcq0_offset << 4);
            }
            else
            {
                qDepth = tqsControl->tqs.control.opcq1_depth;
                virtBaseAddr += (tqsControl->tqs.control.opcq1_offset << 4);
            }
            break;

        case MPCQ:
            /* 24 mPCQs per TQS */
            offset[0] = NCP_NCAP_PCQ_DESC_MPCQ_R0(relativeTqsId*24 + queueId);
            offset[1] = NCP_NCAP_PCQ_DESC_MPCQ_R1(relativeTqsId*24 + queueId);
            offset[2] = NCP_NCAP_PCQ_DESC_MPCQ_R2(relativeTqsId*24 + queueId);
            offset[3] = NCP_NCAP_PCQ_DESC_MPCQ_R3(relativeTqsId*24 + queueId);

            switch (queueId >> 2)
            {
                case 0:
                    qDepth =
                        tqsControl->tqs.control.mpcq0_depths[blockSize];
                    virtBaseAddr +=
                        (tqsControl->tqs.control.mpcq0_offsets[blockSize] << 4);
                    break;
                case 1:
                    qDepth =
                        tqsControl->tqs.control.mpcq1_depths[blockSize];
                    virtBaseAddr +=
                        (tqsControl->tqs.control.mpcq1_offsets[blockSize] << 4);
                    break;
                case 2:
                    qDepth =
                        tqsControl->tqs.control.mpcq2_depths[blockSize];
                    virtBaseAddr +=
                        (tqsControl->tqs.control.mpcq2_offsets[blockSize] << 4);
                    break;
                case 3:
                    qDepth =
                        tqsControl->tqs.control.mpcq3_depths[blockSize];
                    virtBaseAddr +=
                        (tqsControl->tqs.control.mpcq3_offsets[blockSize] << 4);
                    break;
                case 4:
                    qDepth =
                        tqsControl->tqs.control.mpcq4_depths[blockSize];
                    virtBaseAddr +=
                        (tqsControl->tqs.control.mpcq4_offsets[blockSize] << 4);
                    break;
                case 5:
                    qDepth =
                        tqsControl->tqs.control.mpcq5_depths[blockSize];
                    virtBaseAddr +=
                        (tqsControl->tqs.control.mpcq5_offsets[blockSize] << 4);
                    break;
                default:
                    NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                                   ncp_xlf_nca_cfg_ncav3_init_pcq_descriptor_invalidMpcqQueueId,
                                   NCP_MSG_ERROR,
                                   "[%s()] Invalid MPCQ queue ID (%d) specified!\n",
                                   __func__, queueId);
                    NCP_CALL(NCP_ST_ERROR);
            }
            break;

        default:
            NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                           ncp_xlf_nca_cfg_ncav3_init_pcq_descriptor_unknownType,
                           NCP_MSG_ERROR,
                           "[%s()] Unknown type (%d) specified!\n",
                           __func__, type);
            NCP_CALL(NCP_ST_ERROR);
    }

    if (physBase == 0xFFFFFFFF)
    {
        physBaseAddr = pNcpTaskSwState->domainMemMap.domainBundle_PA;

        physBaseAddr += (virtBaseAddr -
                            pNcpTaskSwState->domainMemMap.domainBundle_VA);
    }
    else
    {
        physBaseAddr = virtBaseAddr;
    }

    /* Group number is the relative PGIT ID */
    r0.grn = relativeTqsId;

    /* Define the memory pool to which this queue belongs */
    if (type == MPCQ)
    {
        r0.m_pool_id = (queueId >> 2) + 2;
    }

    if (type == IPCQ || type == OPCQ)
    {
        /* auto_task_completion bit 0: 0 == manual, 1 == automatic */
        r2.apcq_cmplt = (tqsControl->tqs.control.auto_task_completion & 0x1);
    }

    r1.number_of_queue_entries = qDepth;
    r1.enable_bit = (qDepth != 0);
    if (r1.enable_bit == 1 && type == MPCQ)
    {
        r1.enable_bit = ((tqsControl->tqs.control.allocators_bitmap &
                          (1 << r0.m_pool_id)) != 0);
    }
    r1.q_pool_id = NCP_TASK_VP_CONTROL_POOL_ID;

    if (r1.enable_bit == 1 && type == MPCQ)
    {
        ncp_ncav3_queue_depth_t *depth;

        depth = &profile->sharedPoolMaps[poolMapIndex].allocators[blockSize];

        r2.mpcq_almost_empty_depth = depth->almostEmptySize;
        r2.mpcq_almost_full_depth = depth->almostFullSize;

        if (depth->numBuffersPerRequest == 2)
        {
            r2.mpcq_num_bufs_per_req = 0x0;
        }
        else if (depth->numBuffersPerRequest == 4)
        {
            r2.mpcq_num_bufs_per_req = 0x2;
        }
        else /* 8 bufs per request */
        {
            r2.mpcq_num_bufs_per_req = 0x3;
        }

#if !(defined(NCP_DEV_FBRS)  || \
      defined(NCP_DEV_FBDEV) || \
      defined(NCP_DEV_SOCKET))
        switch (r2.mpcq_num_bufs_per_req)
        {
            case 0x0:
            case 0x1:
                /* Must be 16B aligned */
                NCP_ASSERT((physBaseAddr & 0x0f) == 0, NCP_ST_ERROR);
                break;

            case 0x2:
                /* Must be 32B aligned */
                NCP_ASSERT((physBaseAddr & 0x1f) == 0, NCP_ST_ERROR);
                break;

            case 0x3:
                /* Must be 64B aligned */
                NCP_ASSERT((physBaseAddr & 0x3f) == 0, NCP_ST_ERROR);
                break;
        }
#endif
    }

    r2.q_vi_upper = (ncp_uint32_t)((physBaseAddr >> 32) & 0x0f);
    r3.q_vi_lower = (ncp_uint32_t)(physBaseAddr & 0xffffffff);

    if (upperBits != 0)
    {
        r2.q_vi_upper |= upperBits;
    }

    if (type == IPCQ || type == OPCQ)
    {
        /* iPCQs and oPCQs must be 16B aligned. */
#if !(defined(NCP_DEV_FBRS)  || \
      defined(NCP_DEV_FBDEV) || \
      defined(NCP_DEV_SOCKET))
        NCP_ASSERT((physBaseAddr & 0x0f) == 0, NCP_ST_ERROR);
#endif
        NCP_ASSERT(qDepth >= 4, NCP_ST_ERROR);
    }

    NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
            NCP_REGION_AXIS_AXI2SER8_A53_NCAP_NLINKS(ncapId),
            offset[0],
            (ncp_uint32_t *)&r0);

    NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
            NCP_REGION_AXIS_AXI2SER8_A53_NCAP_NLINKS(ncapId),
            offset[2],
            (ncp_uint32_t *)&r2);

    NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
            NCP_REGION_AXIS_AXI2SER8_A53_NCAP_NLINKS(ncapId),
            offset[3],
            (ncp_uint32_t *)&r3);

    /* Word 1 contains the enable bit, so write it last */
    NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
            NCP_REGION_AXIS_AXI2SER8_A53_NCAP_NLINKS(ncapId),
            offset[1],
            (ncp_uint32_t *)&r1);

NCP_RETURN_LABEL

    return ncpStatus;
}


ncp_st_t
ncp_ncav3_initialize_tqs_pcqs(
    ncp_t                   *ncp,
    ncp_dev_hdl_t            dev,
    ncp_uint32_t             ncapId,
    ncp_uint32_t             relTqsId,
    ncp_uint8_t              pgitId,
    ncp_ncav3_cpu_profile_t *profile,
    ncp_uint32_t             physBase,
    ncp_uint8_t              upperBits)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    int queueId;

    /* NCA-level mPCQ configuration */
    NCP_CALL(ncp_ncav3_config_mtp_mpcq_lookup(
                dev,
                ncapId,
                relTqsId,
                pgitId,
                profile));

    NCP_CALL(ncp_ncav3_config_mtp_dmm_lookup(
                dev,
                pgitId,
                profile));

    /* NCA-level iPCQ configuration */
    NCP_CALL(ncp_ncav3_init_ipd_ram(
        ncp,
        dev,
        ncapId,
        relTqsId,
        pgitId,
        profile));

    /* NCA-level oPCQ configuration */
    NCP_CALL(ncp_ncav3_config_otp_odts_ram_entry(
                ncp,
                dev,
                ncapId,
                relTqsId,
                pgitId,
                profile));

    NCP_CALL(ncp_ncav3_config_otp_odtd_ram_entry(dev, pgitId));

    NCP_CALL(ncp_ncav3_config_otp_ctrl_destipcq(dev, pgitId));

    NCP_CALL(ncp_ncav3_init_pcq_descriptor(
                ncp,
                dev,
                ncapId,
                relTqsId,
                pgitId,
                profile,
                IPCQ,
                0,
                physBase,
                upperBits));

    for (queueId = 0; queueId < NCP_NCAV3_NUM_OPCQS_PER_TQS; queueId++)
    {
        NCP_CALL(ncp_ncav3_init_pcq_descriptor(
                    ncp,
                    dev,
                    ncapId,
                    relTqsId,
                    pgitId,
                    profile,
                    OPCQ,
                    queueId,
                    physBase,
                    upperBits));
    }

    for (queueId = 0; queueId < NCP_NCAV3_NUM_MPCQS_PER_TQS; queueId++)
    {
        NCP_CALL(ncp_ncav3_init_pcq_descriptor(
                    ncp,
                    dev,
                    ncapId,
                    relTqsId,
                    pgitId,
                    profile,
                    MPCQ,
                    queueId,
                    physBase,
                    upperBits));
    }

NCP_RETURN_LABEL

    return ncpStatus;
}


ncp_st_t
ncp_ncav3_configure_tqs_hw(
    ncp_t                   *ncp,
    ncp_dev_hdl_t            dev,
    int                      ncapId,
    int                      relTqsId,
    ncp_ncav3_cpu_profile_t *profile)
{
    ncp_st_t ncpStatus;
    ncp_ncav3_hdl_t *nca;
    ncp_uint8_t pgitId;

    nca = ncp->ncaHdl;

    NCP_CALL(ncp_ncav3_get_absolute_group_id(ncapId, relTqsId, &pgitId));

    NCP_CALL(ncp_ncav3_initialize_tqs_pcqs(
                ncp,
                dev,
                ncapId,
                relTqsId,
                pgitId,
                profile,
                0xFFFFFFFF,
                0));

    NCP_CALL(ncp_ncav3_set_pgit_timers(dev, ncapId, relTqsId));

    NCP_CALL(ncp_ncav3_enable_pgit_timers(dev, ncapId, relTqsId));

NCP_RETURN_LABEL

    return ncpStatus;
}

static ncp_st_t
ncp_ncav3_get_num_owed_completions(
    ncp_dev_hdl_t  dev,
    ncp_uint8_t    pgitId,
    ncp_uint8_t   *count)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_nca_itp_ipcq_size00_r_t r0;
    int index;

    index = pgitId / 4;

    NCP_DEV_NCA_READ_REG32(
            dev,
            NCP_REGION_NCAV3_CORE,
            NCP_NCA_CORE_ITP_ADDR_MAP_BASE + NCP_NCA_ITP_IPCQ_WORKING00 + 4*index,
            (ncp_uint32_t *) &r0);

    switch (pgitId % 4)
    {
        case 0:
            *count = r0.ipcq00;
            break;

        case 1:
            *count = r0.ipcq01;
            break;

        case 2:
            *count = r0.ipcq02;
            break;

        case 3:
            *count = r0.ipcq03;
            break;

        default:
            break;
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

static ncp_st_t
ncp_ncav3_disable_mpcq(
    ncp_dev_hdl_t dev,
    ncp_uint32_t  ncapId,
    ncp_uint32_t  relativeTqsId,
    ncp_uint8_t   pgitId,
    ncp_uint32_t  queueId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncap_PCQ_desc_mme_reg1_t r1;

    /* Read-modify-write the PCQ descriptor register */

    NCP_DEV_NCA_READ_REG32(dev,
            NCP_REGION_AXIS_AXI2SER8_A53_NCAP_NLINKS(ncapId),
            NCP_NCAP_PCQ_DESC_MPCQ_R1(relativeTqsId*24 + queueId),
            (ncp_uint32_t *)&r1);

    r1.enable_bit = 0;

    NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
            NCP_REGION_AXIS_AXI2SER8_A53_NCAP_NLINKS(ncapId),
            NCP_NCAP_PCQ_DESC_MPCQ_R1(relativeTqsId*24 + queueId),
            (ncp_uint32_t *)&r1);

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_disable_mpcqs(
    ncp_dev_hdl_t  dev,
    ncp_uint8_t    ncapId,
    ncp_uint8_t    relTqsId,
    ncp_uint8_t    pgitId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    int i, j;

    for (i = NCP_NCAV3_FIRST_SHARED_POOL_ID;
         i <= NCP_NCAV3_LAST_SHARED_POOL_ID;
         i++)
    {
        ncp_uint8_t queueId;

        for (j = 0; j < 4; j++)
        {
            queueId = (i - NCP_NCAV3_FIRST_SHARED_POOL_ID) * 4 + j;

            NCP_CALL(ncp_ncav3_disable_mpcq(
                        dev,
                        ncapId,
                        relTqsId,
                        pgitId,
                        queueId));
        }
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_flush_tqs_mpcqs(
    ncp_task_pvt_tqsHdl_data_t *tqsHdl,
    ncp_uint8_t                 txQueueId,
    ncp_uint8_t                 ncapId,
    ncp_uint8_t                 relTqsId,
    ncp_uint8_t                 pgitId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    int i, j;
    ncp_uint32_t bufferSizes[4] = {256, 2048, 16384, 65536};

    for (i = NCP_NCAV3_FIRST_SHARED_POOL_ID;
         i <= NCP_NCAV3_LAST_SHARED_POOL_ID;
         i++)
    {
        if (0 == (tqsHdl->pTqs->validPoolsMask & (1 << i)))
        {
            continue;
        }

        for (j = 0; j < 4; j++)
        {
            void *taskBuffer;
            ncp_uint32_t numProcessed;
            ncp_bool_t mrefBit = FALSE;

            while (1)
            {
                ncpStatus = ncp_task_buffer_alloc(
                        tqsHdl,
                        1,
                        &numProcessed,
                        &bufferSizes[j],
                        i,
                        &taskBuffer,
                        FALSE);

                if (ncpStatus != NCP_ST_SUCCESS)
                {
                    ncpStatus = NCP_ST_SUCCESS;
                    break;
                }

                NCP_CALL(ncp_task_buffer_free(
                            tqsHdl,
                            txQueueId,
                            1,
                            &numProcessed,
                            i,
                            &taskBuffer,
                            &mrefBit,
                            TRUE));
            }
        }
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_disable_pgit_timers(
    ncp_dev_hdl_t dev,
    int           ncapId,
    int           relativeTqsId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ncap_grp_load_timer_enable_reg_t   r0;
    ncp_ncap_grp_upload_timer_enable_reg_t r1;

    ncp_memset(&r0, 0, sizeof(r0));
    ncp_memset(&r1, 0, sizeof(r1));

    NCP_ASSERT(relativeTqsId <= 7, NCP_ST_ERROR);

    r0.grp_load_timer_en |= 1 << relativeTqsId;
    r1.grp_upload_timer_en |= 1 << relativeTqsId;

    NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
            NCP_REGION_AXIS_AXI2SER8_A53_NCAP_NLINKS(ncapId),
            NCP_NCAP_GRP_LOAD_TIMER_ENABLE_WOCLR,
            (ncp_uint32_t *)&r0);

    NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
            NCP_REGION_AXIS_AXI2SER8_A53_NCAP_NLINKS(ncapId),
            NCP_NCAP_GRP_UPLOAD_TIMER_ENABLE_WOCLR,
            (ncp_uint32_t *)&r1);

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_set_pgit_timers(
    ncp_dev_hdl_t dev,
    int           ncapId,
    int           relativeTqsId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ncap_pgit_grp_load_timer_reg_t            r0;
    ncp_ncap_delay_grp_load_timer_reg_t           r1;
    ncp_ncap_ipcq_etne_delay_grp_load_timer_reg_t r2;
    ncp_ncap_pgit_grp_upload_timer_reg_t          r3;
    ncp_ncap_delay_grp_upload_timer_reg_t         r4;

    ncp_memset(&r0, 0, sizeof(r0));
    ncp_memset(&r1, 0, sizeof(r1));
    ncp_memset(&r2, 0, sizeof(r2));
    ncp_memset(&r3, 0, sizeof(r3));
    ncp_memset(&r4, 0, sizeof(r4));

    NCP_ASSERT(relativeTqsId <= 7, NCP_ST_ERROR);

    /* FIXME: Use profile-defined values. */
    r0.set_timer_cpu_load = 128;
    r1.set_timer_delay_load = 128;
    r2.set_timer_delay_load = 128;
    r3.set_timer_ncap_upload = 128;
    r4.set_timer_delay_upload = 128;

    NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
            NCP_REGION_AXIS_AXI2SER8_A53_NCAP_NLINKS(ncapId),
            NCP_NCAP_PGIT_GRP_LOAD_TIMER(relativeTqsId),
            (ncp_uint32_t *)&r0);

    NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
            NCP_REGION_AXIS_AXI2SER8_A53_NCAP_NLINKS(ncapId),
            NCP_NCAP_DELAY_GRP_LOAD_TIMER(relativeTqsId),
            (ncp_uint32_t *)&r1);

    NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
            NCP_REGION_AXIS_AXI2SER8_A53_NCAP_NLINKS(ncapId),
            NCP_NCAP_IPCQ_ETNE_DELAY_GRP_LOAD_TIMER(relativeTqsId),
            (ncp_uint32_t *)&r2);

    NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
            NCP_REGION_AXIS_AXI2SER8_A53_NCAP_NLINKS(ncapId),
            NCP_NCAP_PGIT_GRP_UPLOAD_TIMER(relativeTqsId),
            (ncp_uint32_t *)&r3);

    NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
            NCP_REGION_AXIS_AXI2SER8_A53_NCAP_NLINKS(ncapId),
            NCP_NCAP_DELAY_GRP_UPLOAD_TIMER(relativeTqsId),
            (ncp_uint32_t *)&r4);

NCP_RETURN_LABEL

    return ncpStatus;
}


/* Steps to reprogram the PCQ blocks:
 * 1. Program the NCA to stop sending input tasks to the PCQ(s) via
 *      ncp_ncav3_disable_ipcq().
 * 2. Program the PEs to stop adding oPCQ entries, except for those in
 *      response to the input tasks and related buffer returns.
 * 3. Wait until all iPCQ(s) are empty.
 * 4. Check the NCA to determine when task flow completion is done for all
 *      input tasks.
 * 5. Disable the mPCQs by clearing the enable bits in the mPCQ desc table.
 * 6. Program the PEs to return all of the buffers in the mPCQs.
 * 7. Wait until the mPCQs are all empty.
 * 8. Turn off the group load/upload timers.
 *
 * Once all the steps are complete, the PCQ blocks can be reprogrammed.
 */

ncp_st_t
ncp_ncav3_take_pgit_offline(
    ncp_task_tqs_hdl_t *hdl,
    ncp_dev_hdl_t       dev,
    ncp_uint8_t         ncapId,
    ncp_uint8_t         relTqsId,
    ncp_uint8_t         pgitId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *tqsHdl = (ncp_task_pvt_tqsHdl_data_t *) hdl;
    ncp_uint8_t uncompletedCount = 0;
    int flushLoopCount = 0;

    NCP_ASSERT(tqsHdl->useFlags.useTxQueue[0] == TRUE,
        NCP_ST_INTERNAL_ERROR);

    NCP_CALL(ncp_ncav3_disable_ipcq(
                dev,
                ncapId,
                relTqsId,
                pgitId));

    /* There is a hardware race between disable_ipcq and rx_queue_flush,
     * wherein a task is scheduled to the iPCQ before we disable the iPCQ, but
     * the PGIT doesn't update until after rx queue flush completes.  If this
     * occurs, there will be one task (and hence one outstanding completion) in
     * the iPCQ.
     *
     * The NCA keeps a counter of all tasks scheduled for an iPCQ but not yet
     * completed -- IPCQ_WORKINGXX. So loop until IPCQ_WORKINGXX goes to 0
     * (but not indefinitely in case the NCAP or NCA is hung).
     */

    do {
        /* Free any tasks sitting in the iPCQ (otherwise they'll be leaked),
         * and complete them (otherwise the PGIT will have 1+ outstanding
         * completions).
         */
        ncpStatus = ncp_task_rx_queue_flush(tqsHdl, 0);

        if ((ncpStatus != NCP_ST_SUCCESS) &&
            (ncpStatus != NCP_ST_TASK_RECV_QUEUE_EMPTY))
        {
            NCP_CALL(ncpStatus);
        }

        NCP_CALL(ncp_ncav3_get_num_owed_completions(
                    dev,
                    pgitId,
                    &uncompletedCount));

        /* Break out after 20 attempts. */
        if (++flushLoopCount >= 20)
        {
            break;
        }
    } while (uncompletedCount != 0);

    NCP_ASSERT(uncompletedCount == 0,
        NCP_ST_TASK_TAKING_PGIT_OFFLINE_WITH_COMPLETIONS_OWED);

    /*
     * Do not allow thread to take PGIT offline if it still owes task
     * completions This indicates an application bug, and if we are using a CPU
     * pool, then it is also likely that the application has not properly
     * refilled the NCA RX buffers.
     */

    if (tqsHdl->completionsOwed !=
        (tqsHdl->completionsIssued[0] + tqsHdl->completionsIssued[1]))
    {
        NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                       ncp_xlf_nca_cfg_ncav3_take_pgit_offline_taskCompletionsOwed,
                       NCP_MSG_ERROR,
                       "Attempt to take pgit offline with %d task completions owed, %d issued on TXQ0, %d issued on TXQ1\r\n",
                       tqsHdl->completionsOwed,
                       tqsHdl->completionsIssued[0],
                       tqsHdl->completionsIssued[1]);
        NCP_CALL(NCP_ST_TASK_TAKING_PGIT_OFFLINE_WITH_COMPLETIONS_OWED);
    }

    /* Disable all 24 mPCQs. When bringing the PGIT back online the RTE will
     * enable only valid mPCQs. */
    NCP_CALL(ncp_ncav3_disable_mpcqs(
        dev,
        ncapId,
        relTqsId,
        pgitId));

    /* Flush mPCQs */
    NCP_CALL(ncp_ncav3_flush_tqs_mpcqs(
        tqsHdl,
        0,
        ncapId,
        relTqsId,
        pgitId));

    /* Wait until all the frees have completed before disabling timers */
    NCP_CALL(ncp_task_tx_queue_flush(tqsHdl, 0));

    /* Turn off timers */
    NCP_CALL(ncp_ncav3_disable_pgit_timers(
                dev,
                ncapId,
                relTqsId));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_init_pgit_monitor_grp_indexes(
    ncp_dev_hdl_t  dev,
    int            ncapId,
    ncp_uint8_t    tqsId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncap_pgitm_init_grp_indexes_reg_t r0;

    ncp_memset(&r0, 0, sizeof(r0));

    ncp_comment("## Initialize PGITM group indexes\n");

    r0.init_index_grp = (1 << tqsId);

    NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
            NCP_REGION_AXIS_AXI2SER8_A53_NCAP_NLINKS(ncapId),
            NCP_NCAP_PGITM_INIT_GRP_INDEXES,
            (ncp_uint32_t *)&r0);

#if !(defined(NCP_DEV_FBRS) || defined(NCP_DEV_FBDEV))
    /* Wait for PGIT initialization to complete */
    do {
        NCP_DEV_NCA_READ_REG32(dev,
                NCP_REGION_AXIS_AXI2SER8_A53_NCAP_NLINKS(ncapId),
                NCP_NCAP_PGITM_INIT_GRP_INDEXES,
                (ncp_uint32_t *)&r0);
    } while ((r0.init_index_grp & (1 << tqsId)) != 0);
#endif

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_reset_pgit_indexes(
    ncp_t           *ncp,
    ncp_ncav3_hdl_t *nca,
    ncp_uint8_t      pgitId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_tqs_control_t *tqsControl;

    ncp_comment("## Reset PGIT indexes\n");

    if (ncp->domainIsInternal)
    {
        tqsControl = (ncp_ncav3_tqs_control_t *) &nca->tqsArray[pgitId];

        memset(&tqsControl->tqs.cputable, 0, sizeof(ncp_tqs_pe_idx_table_t));
        memset(&tqsControl->tqs.ncatable, 0, sizeof(ncp_tqs_nca_idx_table_t));
    }
    else
    {
        NCP_ASSERT(pgitId >= NCP_NCAV3_NUM_CPU_TQSETS, NCP_ST_INTERNAL_ERROR);
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_configure_awtrace0(
    ncp_ncav3_hdl_t *nca,
    ncp_dev_hdl_t    dev)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ncav3_task_trace_config_t *taskTrace;

    ncp_aw_trace0_control_r_t     r0;
    ncp_aw_trace0_trace_first_r_t r1;
    ncp_aw_trace0_trace_last_r_t  r2;
    ncp_aw_trace0_wrap_thresh_r_t r3;

    ncp_uintptr_t logStartVA, logEndVA;

    ncp_memset(&r0, 0, sizeof(r0));
    ncp_memset(&r1, 0, sizeof(r1));
    ncp_memset(&r2, 0, sizeof(r2));
    ncp_memset(&r3, 0, sizeof(r3));

    ncp_comment("## Configure AW Trace0\n");

    taskTrace = &nca->configInfo.taskTrace;

    logStartVA = taskTrace->logBaseAddress;
    logEndVA   = logStartVA + ((taskTrace->numLogEntries - 1) * 128);

    r0.trace_format = 1;
    r0.metadata_pos = 0;
    r0.enable_trace = taskTrace->traceEnabled;

    r0.stop_on_wrap = !taskTrace->unlimitedLogWrap;

    r1.tracefirsth = (logStartVA >> 32) & 0xF;
    r1.tracefirstl =  logStartVA & 0xFFFFFFFF;

    r2.tracelasth = (logEndVA >> 32) & 0xF;
    r2.tracelastl =  logEndVA & 0xFFFFFFFF;

    r3.wrapthreshh = (taskTrace->wrapThreshold >> 32) & 0xFFFFFFFF;
    r3.wrapthreshl =  taskTrace->wrapThreshold & 0xFFFFFFFF;

    NCP_CALL(ncp_block_write32(dev,
            NCP_REGION_NCAV3_CORE,
            NCP_AW_TRACE0_TRACE_FIRST + NCP_NCA_CORE_AW_TRACE0_BASE,
            (ncp_uint32_t *)&r1,
            sizeof(r1)/4,
            0));

    NCP_CALL(ncp_block_write32(dev,
            NCP_REGION_NCAV3_CORE,
            NCP_AW_TRACE0_TRACE_LAST + NCP_NCA_CORE_AW_TRACE0_BASE,
            (ncp_uint32_t *)&r2,
            sizeof(r2)/4,
            0));

    NCP_CALL(ncp_block_write32(dev,
            NCP_REGION_NCAV3_CORE,
            NCP_AW_TRACE0_WRAP_THRESH + NCP_NCA_CORE_AW_TRACE0_BASE,
            (ncp_uint32_t *)&r3,
            sizeof(r3)/4,
            0));

    NCP_CALL(ncp_block_write32(dev,
            NCP_REGION_NCAV3_CORE,
            NCP_AW_TRACE0_CONTROL + NCP_NCA_CORE_AW_TRACE0_BASE,
            (ncp_uint32_t *)&r0,
            sizeof(r0)/4,
            0));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_configure_awtrace1(
    ncp_ncav3_hdl_t *nca,
    ncp_dev_hdl_t    dev)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    ncp_ncav3_task_trace_config_t *taskTrace;

    ncp_aw_trace1_control_r_t     r0;
    ncp_aw_trace1_trace_first_r_t r1;
    ncp_aw_trace1_trace_last_r_t  r2;
    ncp_aw_trace1_wrap_thresh_r_t r3;

    ncp_uintptr_t logStartVA, logEndVA;

    ncp_memset(&r0, 0, sizeof(r0));
    ncp_memset(&r1, 0, sizeof(r1));
    ncp_memset(&r2, 0, sizeof(r2));
    ncp_memset(&r3, 0, sizeof(r3));

    ncp_comment("## Configure AW Trace1\n");

    taskTrace = &nca->configInfo.taskTrace;

    /* ASE leaves space for an additional 1024 small-format trace log entries.
     * Since the small-format log entries are created when a task is
     * completed, they come in a different order than the large-format log
     * entries. To increase the chances that the large-format entries have
     * a matching entry in the small-format log, we store more small-format
     * entries.
     *
     * ASE's algorithm for task trace log memory:
     * sde/plugins/lionfish/src/com/lsi/config/lionfish/AllocationUtilsLionfish.java:allocateNCATaskTraceMemory()
     */
    logStartVA = taskTrace->logBaseAddress + (taskTrace->numLogEntries * 128);
    logEndVA   = logStartVA + ((taskTrace->numLogEntries + 1024 - 1) * 32);

    r0.trace_format = 0;
    r0.metadata_pos = 4;
    r0.enable_trace = taskTrace->traceEnabled;

    r0.stop_on_wrap = !taskTrace->unlimitedLogWrap;

    r1.tracefirsth = (logStartVA >> 32) & 0xF;
    r1.tracefirstl =  logStartVA & 0xFFFFFFFF;

    r2.tracelasth = (logEndVA >> 32) & 0xF;
    r2.tracelastl =  logEndVA & 0xFFFFFFFF;

    r3.wrapthreshh = (taskTrace->wrapThreshold >> 32) & 0xFFFFFFFF;
    r3.wrapthreshl =  taskTrace->wrapThreshold & 0xFFFFFFFF;

    NCP_CALL(ncp_block_write32(dev,
            NCP_REGION_NCAV3_CORE,
            NCP_AW_TRACE1_TRACE_FIRST + NCP_NCA_CORE_AW_TRACE1_BASE,
            (ncp_uint32_t *)&r1,
            sizeof(r1)/4,
            0));

    NCP_CALL(ncp_block_write32(dev,
            NCP_REGION_NCAV3_CORE,
            NCP_AW_TRACE1_TRACE_LAST + NCP_NCA_CORE_AW_TRACE1_BASE,
            (ncp_uint32_t *)&r2,
            sizeof(r2)/4,
            0));

    NCP_CALL(ncp_block_write32(dev,
            NCP_REGION_NCAV3_CORE,
            NCP_AW_TRACE1_WRAP_THRESH + NCP_NCA_CORE_AW_TRACE1_BASE,
            (ncp_uint32_t *)&r3,
            sizeof(r3)/4,
            0));

    NCP_CALL(ncp_block_write32(dev,
            NCP_REGION_NCAV3_CORE,
            NCP_AW_TRACE1_CONTROL + NCP_NCA_CORE_AW_TRACE1_BASE,
            (ncp_uint32_t *)&r0,
            sizeof(r0)/4,
            0));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_task_initialize_tqs_task_state(
    ncp_hdl_t   ncpHdl,
    ncp_bool_t  uMode)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_tqs_swState_t *tqs;
    ncp_uint32_t *ncapList;
    ncp_t *ncp = (ncp_t *) ncpHdl;
    int numNCAPs;
    int ncapIdx;
    int tqsId;

    ncp_ncav3_hdl_t *nca = ncp->ncaHdl;

    NCP_CALL(ncp_ncav3_get_ncap_id_list(
        ncp,
       &numNCAPs,
       &ncapList));

    NCP_ASSERT(nca->inConfigurationPhase, NCP_ST_INTERNAL_ERROR);

    for (ncapIdx = 0; ncapIdx < numNCAPs; ncapIdx++)
    {
        for (tqsId = 0; tqsId < 8; tqsId++)
        {
            ncp_uint8_t pgitId;

            NCP_CALL(ncp_ncav3_get_absolute_group_id(
                        ncapList[ncapIdx],
                        tqsId,
                        &pgitId));

            tqs = pNcpTaskSwState->tqsSwState;

            pNcpTaskSwState->tqsSwState[pgitId].configured = FALSE;

            if (FALSE == tqs[pgitId].staticConfiguration)
            {
                continue;
            }
            else if (ncp->domainIsInternal == FALSE)
            {
                NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                               ncp_xlf_nca_cfg_task_initialize_tqs_task_state_errorNotInternalDomain,
                               NCP_MSG_ERROR,
                               "[%s()] External domains cannot configure enabled CPU thread queue sets.\n",
                               __func__);
                NCP_CALL(NCP_ST_ERROR);
            }

            if (tqs[pgitId].pAppProfile == NULL)
            {
                continue;
            }

            /* Only configure TQS if its mode is correct */
            if (tqs[pgitId].pAppProfile->baseProfile.uMode != uMode)
            {
                continue;
            }

            /* Which profile is this TQS using? */
            NCP_ASSERT(tqs[pgitId].pAppProfile->profileType == CPU_PROFILE,
                        NCP_ST_ERROR);

            /* Perform validation checks and do the hardware configuration in
             * the kernel. */
            NCP_CALL(ncp_ncav3_tqs_configure(
                        myDevHdl,
                        pgitId,
                       &tqs[pgitId].name,
                       &tqs[pgitId].pAppProfile->baseProfile.name,
                       &tqs[pgitId].shareCtl.shareFlags,
                        tqs[pgitId].mqg,
                        TRUE));

            pNcpTaskSwState->tqsSwState[pgitId].configured = TRUE;

            /* Initialize the rest of the TQS s/w state */
            NCP_CALL(ncp_task_initialize_tqs_state(ncp, pgitId));

            NCP_CALL(ncp_ncav3_set_tqs_configured_state(
                myDevHdl,
                pgitId,
                TRUE));

            /* After initializing TQS state, perDomainPoolsMask may contain a
             * new pool, so re-run initalize TBR arrays in case. */
            NCP_TASK_INITIALIZE_TBR_ARRAYS();
        }
    }

NCP_RETURN_LABEL

    return ncpStatus;
}
