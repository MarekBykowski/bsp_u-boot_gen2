/**************************************************************************
 **                                                                       *
 **    Copyright (c) 2001-2017, Intel Corporation.                        *
 **                                                                       *
 **************************************************************************/

/**************************************************************************/
/* Contains NCAv3 config-related functions that exist in kernel module.   */
/**************************************************************************/

#include <ncp.h>
#include <ncp_pvt.h>
#include <ncp_task_pvt.h>
#include <ncp_ncav3_pvt.h>
#include <ncp_task_hw.h>
#include <ncp_dev_pvt.h>

#include "regs/ncp_nca_itp_regs.h"
#include "regs/ncp_nca_otp_regs.h"
#include "regs/ncp_nca_mtp_regs.h"
#include "regs/ncp_nca_cfg_regs.h"
#include "regs/ncp_nu_tcld_regs.h"
#include "regs/ncp_nu_til_regs.h"
#include "regs/ncp_AW_trace0_regs.h"
#include "regs/ncp_AW_trace1_regs.h"

#include "regs/ncp_nca_itp_reg_defines.h"
#include "regs/ncp_nca_otp_reg_defines.h"
#include "regs/ncp_nca_mtp_reg_defines.h"
#include "regs/ncp_nca_cfg_reg_defines.h"
#include "regs/ncp_nca_core_reg_defines.h"
#include "regs/ncp_nu_tcld_reg_defines.h"
#include "regs/ncp_nu_til_reg_defines.h"
#include "regs/ncp_AW_trace0_reg_defines.h"
#include "regs/ncp_AW_trace1_reg_defines.h"

static ncp_task_v3_mutex_t ipcqOnlineLock;

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
    
    if (((ncp_dev_t *)dev)->config->rev.isFpga)
    {
        NCP_CALL(ncp_ncav3_fpga_lookup_ipd_entry(dev, ncapId, relTqsId, &pgitId));
    }

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
ncp_ncav3_disable_ipcq(
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

    if (((ncp_dev_t *)dev)->config->rev.isFpga)
    {
        NCP_CALL(ncp_ncav3_fpga_lookup_ipd_entry(dev, ncapId, relTqsId, &pgitId));
    }

    NCP_TASK_LOCK_FLAGS(flags);

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

        r0.online &= ~(1 << pgitId);
        r3.valid  &= ~(1 << pgitId);

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

        r1.online &= ~(1 << (pgitId % 32));
        r4.valid  &= ~(1 << (pgitId % 32));

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

        r2.online &= ~(1 << (pgitId % 32));
        r5.valid  &= ~(1 << (pgitId % 32));

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
ncp_ncav3_queue_group_add(
    ncp_dev_hdl_t dev,
    ncp_uint32_t queueGroupId,
    ncp_task_resource_name_t *name,
    ncp_ncav3_recv_queue_type_t ordering)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    int i;
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_CHECK(queueGroupId <= 254, NCP_ST_INVALID_PARAMETER);

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    /* Sanity check */
    NCP_ASSERT(pNcpTaskSwState->queueGroups[queueGroupId].groupId == queueGroupId,
            NCP_ST_INTERNAL_ERROR);

    /*
     * No need to check if there any available queue groups. If there aren't,
     * this check will fail.
     */
    NCP_ASSERT(pNcpTaskSwState->queueGroups[queueGroupId].enabled == FALSE,
            NCP_ST_INVALID_PARAMETER);

    for (i = 0; i < NCP_NCAV3_MAX_NUM_QUEUE_GROUPS; i++)
    {
        if (strncmp(name->name,
                    pNcpTaskSwState->queueGroups[i].name.name,
                    sizeof(ncp_task_resource_name_t)) == 0)
        {
            NCP_RETURN(NCP_ST_TASK_BAD_RESOURCE_NAME);
        }
    }

    pNcpTaskSwState->queueGroups[queueGroupId].enabled = TRUE;
    pNcpTaskSwState->queueGroups[queueGroupId].queueType = ordering;
    strncpy(pNcpTaskSwState->queueGroups[queueGroupId].name.name,
            name->name,
            sizeof(ncp_task_resource_name_t));

NCP_RETURN_LABEL

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_queue_group_delete(
    ncp_dev_hdl_t dev,
    ncp_uint32_t queueGroupId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    ncp_ncav3_nca_queue_state_t *queue;
    ncp_ncav3_nca_queue_group_t *queueGroup;
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_CHECK(queueGroupId <= 254, NCP_ST_INVALID_PARAMETER);

    queueGroup = &pNcpTaskSwState->queueGroups[queueGroupId];

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    /* Sanity check */
    NCP_ASSERT(queueGroup->groupId == queueGroupId, NCP_ST_INTERNAL_ERROR);

    NCP_ASSERT(queueGroup->enabled == TRUE, NCP_ST_INVALID_PARAMETER);

    NCP_ASSERT(ncp_bitmap_count(queueGroup->tqsBitmap, TRUE) == 0,
        NCP_ST_TASK_QUEUE_GROUP_FEEDS_IPCQ);

    queue = queueGroup->groupMembers;

    while (queue != NULL)
    {
        NCP_ASSERT(!queue->enabled,
                NCP_ST_TASK_QUEUE_GROUP_HAS_ENABLED_NCA_QUEUE);

        queue = queue->next;
    }

    queue = queueGroup->groupMembers;

    while (queue != NULL)
    {
        ncp_ncav3_nca_queue_state_t *nextQueue;

        nextQueue = queue->next;

        queue->groupId = -1;

        queue = nextQueue;
    }

    queueGroup->groupMembers = NULL;

    queueGroup->name.name[0] = '\0';

    queueGroup->enabled = FALSE;

NCP_RETURN_LABEL

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_queue_group_modify(
    ncp_dev_hdl_t dev,
    ncp_uint32_t queueGroupId,
    ncp_ncav3_recv_queue_type_t ordering)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    ncp_ncav3_nca_queue_state_t *queue;
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_CHECK(queueGroupId <= 254, NCP_ST_INVALID_PARAMETER);

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    /* Sanity check */
    NCP_ASSERT(pNcpTaskSwState->queueGroups[queueGroupId].groupId == queueGroupId,
            NCP_ST_INTERNAL_ERROR);

    NCP_ASSERT(pNcpTaskSwState->queueGroups[queueGroupId].enabled == TRUE,
            NCP_ST_INVALID_PARAMETER);

    queue = pNcpTaskSwState->queueGroups[queueGroupId].groupMembers;

    while (queue != NULL)
    {
        NCP_ASSERT(!queue->enabled,
                NCP_ST_TASK_QUEUE_GROUP_HAS_ENABLED_NCA_QUEUE);

        queue = queue->next;
    }

    pNcpTaskSwState->queueGroups[queueGroupId].queueType = ordering;

NCP_RETURN_LABEL

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    return ncpStatus;
}

static ncp_st_t
ncp_ncav3_change_nca_queue_group_membership(
    ncp_dev_hdl_t dev,
    ncp_uint8_t   queueId,
    ncp_uint8_t   groupId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_nca_itp_tpd_ram_r_t r0;

    NCP_CALL(ncp_block_read32(
                dev,
                NCP_REGION_NCAV3_CORE,
                NCP_NCA_ITP_TPD_RAM(queueId) + NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                (ncp_uint32_t *) &r0,
                sizeof(r0)/4,
                0));

    r0.gid = groupId;

    r0.class = pNcpTaskSwState->queueGroups[groupId].queueType;

    NCP_CALL(ncp_block_write32(
                dev,
                NCP_REGION_NCAV3_CORE,
                NCP_NCA_ITP_TPD_RAM(queueId) + NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                (ncp_uint32_t *) &r0,
                sizeof(r0)/4,
                0));

NCP_RETURN_LABEL

    return ncpStatus;
}

static ncp_st_t
ncp_ncav3_remove_queue_from_queue_group_list(
    ncp_uint32_t groupId,
    ncp_uint32_t queueId)
{
    ncp_ncav3_nca_queue_group_t *queueGroup;
    ncp_ncav3_nca_queue_state_t *queue;
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    NCP_CHECK(groupId < NCP_NCAV3_MAX_NUM_QUEUE_GROUPS,
               NCP_ST_INTERNAL_ERROR);

    queueGroup = &pNcpTaskSwState->queueGroups[groupId];

    queue = queueGroup->groupMembers;

    NCP_ASSERT(queue != NULL, NCP_ST_INTERNAL_ERROR);

    if (queue->tqId == queueId)
    {
        queueGroup->groupMembers = queue->next;
    }
    else
    {
        while (queue != NULL)
        {
            /*
             * The current and previous queues in the list don't have the
             *  right tqId, so there must be at least one more queue in the
             *  list.
             */
            NCP_ASSERT(queue->next != NULL,
                    NCP_ST_TASK_NCA_QUEUE_NOT_A_MEMBER);

            if (queue->next->tqId == queueId)
            {
                break;
            }

            queue = queue->next;
        }

        NCP_ASSERT(queue != NULL, NCP_ST_INTERNAL_ERROR);

        queue->next = queue->next->next;
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

static ncp_st_t
ncp_ncav3_add_queue_to_queue_group_list(
    ncp_uint32_t groupId,
    ncp_uint32_t queueId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_nca_queue_group_t *queueGroup;
    ncp_ncav3_nca_queue_state_t *queue;

    NCP_CHECK(groupId < NCP_NCAV3_MAX_NUM_QUEUE_GROUPS,
               NCP_ST_INTERNAL_ERROR);

    NCP_CHECK(queueId < NCP_NCAV3_MAX_NUM_NCAQS,
               NCP_ST_INVALID_PARAMETER);

    queueGroup = &pNcpTaskSwState->queueGroups[groupId];

    queue = &pNcpTaskSwState->ncaQueueState[queueId];

    queue->next = queueGroup->groupMembers;

    queueGroup->groupMembers = queue;

NCP_RETURN_LABEL

    return ncpStatus;
}

NCP_API ncp_st_t
ncp_ncav3_nca_queue_group_set(
    ncp_dev_hdl_t dev,
    ncp_uint32_t ncaQueueId,
    ncp_uint32_t queueGroupId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_nca_queue_state_t     *queue;
    ncp_ncav3_application_profile_t *appProfile;
    ncp_task_tqs_swState_t          *tqs;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    ncp_hdl_t                        ncpHdl = myNcpHdl;
    int i;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_ncav3_nca_queue_group_set_entry,
                          NCP_MSG_ENTRY,
                          "dev=%p ncaQueueId=%u queueGroupId=%u"
                          "\n",
                          dev, ncaQueueId, queueGroupId);
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK(ncaQueueId < NCP_NCAV3_MAX_NUM_NCAQS,
               NCP_ST_INVALID_PARAMETER);
    NCP_CHECK(queueGroupId < NCP_NCAV3_MAX_NUM_QUEUE_GROUPS,
               NCP_ST_INVALID_PARAMETER);

    NCP_CHECK(pNcpTaskSwState->queueGroups[queueGroupId].enabled == TRUE,
        NCP_ST_INVALID_PARAMETER);

    NCP_ASSERT(pNcpTaskSwState->ncaQueueState[ncaQueueId].profile != NULL,
            NCP_ST_TASK_NCA_QUEUE_NOT_CONFIGURED);

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    /*
     * The RTE ensures that:
     *  - For each iPCQ that can be fed by the NCA queue in the new
     *      TQG, the app profile's pool set is a superset of the queue's
     *      allowed pools.
     */

    queue = &pNcpTaskSwState->ncaQueueState[ncaQueueId];

    NCP_CALL(ncp_ncav3_get_app_profile(
                (ncp_t *) ncpHdl,
                queue->profile->appProfileId,
                &appProfile));

    for (i = 0; i < NCP_NCAV3_MAX_NUM_TQSETS; i++)
    {
        ncp_ncav3_cpu_profile_t *queueProfile;
        ncp_ncav3_cpu_profile_t *tqsProfile;
        int j;

        if (ncp_bitmap_isset(pNcpTaskSwState->queueGroups[queueGroupId].tqsBitmap, i) == FALSE)
        {
            continue;
        }

        tqs = &pNcpTaskSwState->tqsSwState[i];

        queueProfile = &appProfile->baseProfile;

        tqsProfile = &tqs->pAppProfile->baseProfile;

        if (queueProfile->cpuPoolMap.enabled)
        {
            NCP_ASSERT(tqsProfile->cpuPoolMap.enabled,
                    NCP_ST_TASK_ALLOWED_POOLS_MISMATCH);
        }

        for (j = 0; j < queueProfile->numSharedPoolMaps; j++)
        {
            if (queueProfile->sharedPoolMaps[j].poolMap.enabled)
            {
                NCP_ASSERT(tqsProfile->sharedPoolMaps[j].poolMap.enabled,
                        NCP_ST_TASK_ALLOWED_POOLS_MISMATCH);
            }
        }

        if (queueProfile->fixedPoolMap.enabled)
        {
            NCP_ASSERT(tqsProfile->fixedPoolMap.enabled,
                    NCP_ST_TASK_ALLOWED_POOLS_MISMATCH);
        }
    }

    if (queue->groupId != -1)
    {
        NCP_CALL(ncp_ncav3_remove_queue_from_queue_group_list(
                    queue->groupId,
                    ncaQueueId));
    }

    queue->groupId = queueGroupId;

    NCP_CALL(ncp_ncav3_take_nca_queue_offline(myDevHdl, ncaQueueId));

    NCP_CALL(ncp_ncav3_change_nca_queue_group_membership(
                myDevHdl,
                ncaQueueId,
                queueGroupId));

    NCP_CALL(ncp_ncav3_add_queue_to_queue_group_list(
        queue->groupId,
        ncaQueueId));

    /* If the queue is disabled, leave it offline */
    if (queue->enabled)
    {
        NCP_CALL(ncp_ncav3_bring_nca_queue_online(myDevHdl, ncaQueueId));
    }

NCP_RETURN_LABEL

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_nca_queue_group_set_ok);
    }
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_nca_queue_group_set_err);
    }


    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_ncav3_nca_queue_group_set_exit,
                          NCP_MSG_EXIT,
                          "ncpStatus=%d\n",
                          ncpStatus);
    return(ncpStatus);
}

ncp_st_t
ncp_ncav3_check_queue_group_for_orphaned_queues(
    ncp_dev_hdl_t dev,
    ncp_uint32_t tqsId,
    ncp_uint32_t groupIndex,
    ncp_bool_t   takeLock)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_nca_queue_group_t *queueGroup;
    ncp_task_tqs_swState_t *pTqs;
    iPCQ_info_t *ipcqInfo;
    ncp_uint32_t queueGroupId;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_TASK_LOCK_FLAGS(flags);

    if (takeLock)
    {
        NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));
    }

    pTqs = &pNcpTaskSwState->tqsSwState[tqsId];

    ipcqInfo = &pTqs->rxQ.u.ipcq_info;

    queueGroupId = ipcqInfo->groupIndexes[groupIndex];

    if (queueGroupId == -1)
    {
        /* This queue group entry is unused, skip it */
        NCP_RETURN(NCP_ST_SUCCESS);
    }

    queueGroup = &pNcpTaskSwState->queueGroups[queueGroupId];

    /* If the TQS isn't in the queueGroup's bitmap, the bitmap is invalid. */
    NCP_ASSERT(ncp_bitmap_isset(queueGroup->tqsBitmap, tqsId), NCP_ST_INTERNAL_ERROR);

    /*
     * If the TQS is the only member of the queueGroup, ensure all its
     *  NCA queues are disabled.
     */
    if (ncp_bitmap_count(queueGroup->tqsBitmap, TRUE) == 1)
    {
        ncp_ncav3_nca_queue_state_t *queue = queueGroup->groupMembers;

        while (queue != NULL)
        {
            NCP_ASSERT(!queue->enabled,
                    NCP_ST_TASK_QUEUE_GROUP_HAS_ENABLED_NCA_QUEUE);

            queue = queue->next;
        }
    }

NCP_RETURN_LABEL

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

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
    iPCQ_info_t *ipcqInfo;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)
    ncp_task_tqs_swState_t *pTqs;
    /* localQueueGroupSet possible values:
     * -2: Delete this GID entry
     * -1: Don't delete this GID entry
     * >= 0: Delete this GID entry and add this group ID
     */
    int localQueueGroupSet[8] = {-2, -2, -2, -2, -2, -2, -2, -2};
    int localQueueGroupPrioritySet[8];
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    ncp_hdl_t ncpHdl = myNcpHdl;
    int i, j;
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK(tqsId < NCP_NCAV3_MAX_NUM_TQSETS, NCP_ST_INVALID_PARAMETER);
    NCP_CHECK((NULL != pGrp), NCP_ST_INVALID_PARAMETER);
    NCP_CHECK((numQueueGroups <= 8), NCP_ST_INVALID_PARAMETER);

    dev = myDevHdl;

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    pTqs = &pNcpTaskSwState->tqsSwState[tqsId];

    NCP_ASSERT(pNcpTaskSwState->domainId == pTqs->domainId,
        NCP_ST_TASK_QUESET_NOT_IN_LOCAL_DOMAIN);

    NCP_ASSERT(pTqs->configured == TRUE, NCP_ST_TASK_TQS_NOT_CONFIGURED);

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    ipcqInfo = &pTqs->rxQ.u.ipcq_info;

    for (i = 0; i < numQueueGroups; i++)
    {
        /* Assume all groups will succeed */
        pGrp[i].queueGroupStatus = NCP_ST_SUCCESS;
    }

    /*
     * This double for loop compares each new queue group entry to each old
     * entry, looking for matching queue group IDs (worst-case 64 comparisons).
     * If a match is found, localQueueGroupSet[i] is set to -1, so that we
     * skip the GID delete for that group. If a match isn't found, that queue
     * group is put in an unoccupied entry.
     */
    for (i = 0; i < numQueueGroups; i++)
    {
        ncp_bool_t found = FALSE;
        int tmpIndex = -1;

        for (j = 0; j < NCP_NCAV3_NUM_QUEUE_GROUPS_PER_IPCQ; j++)
        {
            /*
             *  If the current queue group list and the new queue group list
             *  share an entry, mark that entry -1 so as not to delete it.
             */
            if (pGrp[i].queueGroup == ipcqInfo->groupIndexes[j])
            {
                localQueueGroupSet[j] = -1;
                ipcqInfo->groupPriorities[j] = pGrp[i].queueGroupPriority;
                found = TRUE;
                break;
            }
            /*
             *  Else, grab the first unoccupied entry in the local queue group
             *  list. If we later find a match between the two lists, we'll
             *  undo this entry.
             */
            else if (tmpIndex == -1 && localQueueGroupSet[j] == -2)
            {
                localQueueGroupSet[j]         = pGrp[i].queueGroup;
                localQueueGroupPrioritySet[j] = pGrp[i].queueGroupPriority;
                tmpIndex = j;
            }
        }
        /*
         * pGrp[i].queueGroup was found in the current queue group list, so
         * delete the temporary entry (if one was created).
         */
        if (found && (tmpIndex != -1))
        {
            localQueueGroupSet[tmpIndex] = -2;
        }
    }

    /*
     * If this TQS is the last consumer of ipcqInfo->groupIndexes[i],
     * that group's constituent NCA queues must be disabled.
     */
    for (i = 0; i < NCP_NCAV3_NUM_QUEUE_GROUPS_PER_IPCQ; i++)
    {
        if (localQueueGroupSet[i] == -1)
        {
            /* We're not deleting this group, so don't check its queues */
            continue;
        }

        /* If the check fails, NCP_ST_ERROR will indicate that this group was
         * responsible */
        pGrp[i].queueGroupStatus = NCP_ST_ERROR;

        NCP_CALL(ncp_ncav3_check_queue_group_for_orphaned_queues(
            myDevHdl,
            tqsId,
            i,
            FALSE));

        pGrp[i].queueGroupStatus = NCP_ST_SUCCESS;
    }

    /*
     * For each queue that feeds pGrp[i].queueGroup, its virtual region
     * must be the same as the TQS's, and that queue's pools must be a
     * subset of this TQS's allowed pools.
     */
    for (i = 0; i < numQueueGroups; i++)
    {
        ncp_ncav3_nca_queue_group_t *queueGroup;
        ncp_ncav3_nca_queue_state_t *queue;

        queueGroup = &pNcpTaskSwState->queueGroups[pGrp[i].queueGroup];

        queue = queueGroup->groupMembers;

        /* If the check fails, NCP_ST_ERROR will indicate that this group was
         * responsible */
        pGrp[i].queueGroupStatus = NCP_ST_ERROR;

        while (queue != NULL)
        {
            ncp_ncav3_application_profile_t *appProfile;
            ncp_ncav3_cpu_profile_t *queueProfile;
            ncp_ncav3_cpu_profile_t *tqsProfile;
            int j;

            NCP_CALL(ncp_ncav3_get_app_profile(
                        (ncp_t *) ncpHdl,
                        queue->profile->appProfileId,
                        &appProfile));

            queueProfile = &appProfile->baseProfile;

            tqsProfile = &pTqs->pAppProfile->baseProfile;

            NCP_ASSERT(queueProfile->virtualRegionId ==
                        tqsProfile->virtualRegionId,
                    NCP_ST_TASK_VIRTUAL_REGION_MISMATCH);

            if (queueProfile->cpuPoolMap.enabled)
            {
                NCP_ASSERT(tqsProfile->cpuPoolMap.enabled,
                        NCP_ST_TASK_ALLOWED_POOLS_MISMATCH);
            }

            for (j = 0; j < queueProfile->numSharedPoolMaps; j++)
            {
                if (queueProfile->sharedPoolMaps[j].poolMap.enabled)
                {
                    NCP_ASSERT(tqsProfile->sharedPoolMaps[j].poolMap.enabled,
                            NCP_ST_TASK_ALLOWED_POOLS_MISMATCH);
                }
            }

            if (queueProfile->fixedPoolMap.enabled)
            {
                NCP_ASSERT(tqsProfile->fixedPoolMap.enabled,
                        NCP_ST_TASK_ALLOWED_POOLS_MISMATCH);
            }

            queue = queue->next;
        }

        pGrp[i].queueGroupStatus = NCP_ST_SUCCESS;
    }

    for (i = 0; i < NCP_NCAV3_NUM_QUEUE_GROUPS_PER_IPCQ; i++)
    {
        ncp_ncav3_nca_queue_group_t *queueGroup;

        if (localQueueGroupSet[i] == -1)
        {
            /* Don't delete this queue group*/
            continue;
        }

        if (ipcqInfo->groupIndexes[i] == -1)
        {
            /* This group entry is unused, skip it */
            continue;
        }

        NCP_CALL(ncp_ncav3_delete_gid_from_ipcq(
            (ncp_t *) ncpHdl,
            dev,
            i,
            ipcqInfo->groupIndexes[i],
            ipcqInfo->groupPriorities[i],
            tqsId));

        queueGroup = &pNcpTaskSwState->queueGroups[ipcqInfo->groupIndexes[i]];

        /* If the TQS isn't in the queueGroup's bitmap, the bitmap is invalid. */
        NCP_ASSERT(ncp_bitmap_isset(queueGroup->tqsBitmap, tqsId), NCP_ST_INTERNAL_ERROR);

        ncp_bitmap_clr(queueGroup->tqsBitmap, tqsId);

        ipcqInfo->groupIndexes[i] = -1;

        ipcqInfo->numQueueGroupMappings--;
    }

    for (i = 0; i < NCP_NCAV3_NUM_QUEUE_GROUPS_PER_IPCQ; i++)
    {
        ncp_ncav3_nca_queue_group_t *queueGroup;

        if (localQueueGroupSet[i] == -2)
        {
            /* Don't add this queue group*/
            continue;
        }

        if (localQueueGroupSet[i] >= 0)
        {
            ipcqInfo->groupIndexes[i]    = localQueueGroupSet[i];
            ipcqInfo->groupPriorities[i] = localQueueGroupPrioritySet[i];
        }

        /*
         * If localQueueGroupSet[i] == -1, the queue group ID is unchanged. The
         * queue group's priority may have changed, though. In both cases, it's
         * safe to overwrite the previous GID entry without deleting it.
         */
        NCP_CALL(ncp_ncav3_add_gid_to_ipcq(
            (ncp_t *) ncpHdl,
            dev,
            i,
            ipcqInfo->groupIndexes[i],
            ipcqInfo->groupPriorities[i],
            tqsId));

        queueGroup = &pNcpTaskSwState->queueGroups[ipcqInfo->groupIndexes[i]];

        /* If localQueueGroupSet[i] == -1, it wasn't deleted */
        if (localQueueGroupSet[i] >= 0)
        {
            /* If the TQS is in the queueGroup's bitmap, the bitmap is invalid. */
            NCP_ASSERT(ncp_bitmap_isset(queueGroup->tqsBitmap, tqsId) == FALSE,
                NCP_ST_INTERNAL_ERROR);

            ncp_bitmap_set(queueGroup->tqsBitmap, tqsId);

            ipcqInfo->numQueueGroupMappings++;
        }
    }

NCP_RETURN_LABEL

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_tqs_queue_group_set_ok);
    }
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_tqs_queue_group_set_err);
    }

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    return(ncpStatus);
}

NCP_API ncp_st_t
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
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)
    ncp_hdl_t ncpHdl = myNcpHdl;
    ncp_ncav3_nca_queue_state_t     *queue;
    ncp_ncav3_application_profile_t *appProfile;
    ncp_task_tqs_swState_t          *tqs;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    int i;
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_ncav3_nca_queue_configure_entry,
                          NCP_MSG_ENTRY,
                          "dev=%p ncaQueueId=%d queueName=%s "
                          "queueProfileName=%s queueGroupId=%d "
                          "paramsSize=%d params=%p"
                          "\n",
                          dev, ncaQueueId,
                          (queueName) ? queueName->name : "(null)",
                          (queueProfileName) ? queueProfileName->name : "(null)",
                          queueGroupId, paramsSize, params);
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK(ncaQueueId < NCP_NCAV3_MAX_NUM_NCAQS, NCP_ST_INVALID_PARAMETER);
    NCP_CHECK(queueName != NULL, NCP_ST_INVALID_PARAMETER);

    dev = myDevHdl;

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    /* Check if NCA queue name is already in use */
    for (i = 0; i < pNcpTaskSwState->numNcaQueues; i++)
    {
        ncp_ncav3_nca_queue_state_t *queue =
            &pNcpTaskSwState->ncaQueueState[i];

        if (queue->tqId == ncaQueueId)
        {
            continue;
        }

        if (strncmp(queueName->name,
                    queue->name.name,
                    sizeof(ncp_task_resource_name_t)) == 0)
        {
            NCP_CALL(NCP_ST_TASK_BAD_RESOURCE_NAME);
        }
    }

    /*
     * The RTE ensures that:
     *  - For each iPCQ that can be fed by the NCA queue in the new
     *      TQG, the app profile's pool set is a superset of the queue's
     *      allowed pools.
     */

    queue = &pNcpTaskSwState->ncaQueueState[ncaQueueId];

    strncpy(queue->name.name,
            queueName->name,
            sizeof(ncp_task_resource_name_t));

    if (queueProfileName != NULL)
    {
        NCP_CALL(ncp_ncav3_get_queue_profile_from_name(
                    queueProfileName,
                    &queue->profile));

        queue->queueProfileId = queue->profile->id;
    }
    else
    {
        NCP_ASSERT(queue->profile != NULL, NCP_ST_INVALID_PARAMETER);
    }

    NCP_CALL(ncp_ncav3_get_app_profile(
                (ncp_t *) ncpHdl,
                queue->profile->appProfileId,
                &appProfile));

    if (queueGroupId == -1)
    {
        queueGroupId = queue->groupId;
    }

    NCP_ASSERT(queueGroupId != -1, NCP_ST_TASK_NCA_QUEUE_GROUP_NOT_SPECIFIED);

    NCP_ASSERT(pNcpTaskSwState->queueGroups[queueGroupId].enabled,
        NCP_ST_TASK_QUEUE_GROUP_NOT_ENABLED);

    for (i = 0; i < NCP_NCAV3_MAX_NUM_TQSETS; i++)
    {
        ncp_ncav3_nca_queue_group_t *queueGroup;
        ncp_ncav3_cpu_profile_t *queueAppProfile;
        ncp_ncav3_cpu_profile_t *tqsProfile;
        int j;

        queueGroup = &pNcpTaskSwState->queueGroups[queueGroupId];

        if (ncp_bitmap_isset(queueGroup->tqsBitmap, i) == FALSE)
        {
            continue;
        }

        tqs = &pNcpTaskSwState->tqsSwState[i];

        queueAppProfile = &appProfile->baseProfile;

        tqsProfile = &tqs->pAppProfile->baseProfile;

        if (queueAppProfile->cpuPoolMap.enabled)
        {
            NCP_ASSERT(tqsProfile->cpuPoolMap.enabled,
                    NCP_ST_TASK_ALLOWED_POOLS_MISMATCH);
        }

        for (j = 0; j < queueAppProfile->numSharedPoolMaps; j++)
        {
            if (queueAppProfile->sharedPoolMaps[j].poolMap.enabled)
            {
                NCP_ASSERT(tqsProfile->sharedPoolMaps[j].poolMap.enabled,
                        NCP_ST_TASK_ALLOWED_POOLS_MISMATCH);
            }
        }

        if (queueAppProfile->fixedPoolMap.enabled)
        {
            NCP_ASSERT(tqsProfile->fixedPoolMap.enabled,
                    NCP_ST_TASK_ALLOWED_POOLS_MISMATCH);
        }
    }

    if (params != NULL)
    {
        if (params->wrrWeight != -1)
        {
            queue->wrrWeight = params->wrrWeight;
        }

        if (params->priority != -1)
        {
            queue->priority = params->priority;
        }
    }

    if (queue->groupId != -1)
    {
        NCP_CALL(ncp_ncav3_remove_queue_from_queue_group_list(
                    queue->groupId,
                    ncaQueueId));
    }

    queue->groupId = queueGroupId;

    NCP_CALL(ncp_ncav3_take_nca_queue_offline(dev, ncaQueueId));

    NCP_CALL(ncp_ncav3_write_itp_tpd_ram_entry(
        dev,
        queue));

    NCP_CALL(ncp_ncav3_add_queue_to_queue_group_list(
        queue->groupId,
        ncaQueueId));

    /* If the queue is disabled, leave it offline */
    if (queue->enabled)
    {
        NCP_CALL(ncp_ncav3_bring_nca_queue_online(dev, ncaQueueId));
    }

NCP_RETURN_LABEL

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_nca_queue_configure_ok);
    }
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_nca_queue_configure_err);
    }

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_ncav3_nca_queue_configure_exit,
                          NCP_MSG_EXIT,
                          "ncpStatus=%d\n",
                          ncpStatus);
    return(ncpStatus);
}

static ncp_st_t
ncp_ncav3_map_domain_memory(
    ncp_t           *ncp,
    ncp_ncav3_hdl_t *nca,
    ncp_dev_hdl_t    dev)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_domain_info_t *domInfo =
        &nca->configInfo.domainInfo[ncp->domainId];
    void *taskIOMem;

    pNcpTaskSwState->domainMemMap.domainBundle_PA = domInfo->physBase;
    pNcpTaskSwState->domainMemMap.domainBundle_Size = domInfo->size;

    taskIOMem = NCP_TASK_MEM_MMAP(
        dev,
        NULL,
        pNcpTaskSwState->domainMemMap.domainBundle_Size,
        pNcpTaskSwState->domainMemMap.domainBundle_PA);

    pNcpTaskSwState->domainMemMap.domainBundle_VA = (ncp_uintptr_t) taskIOMem;

    NCP_ASSERT(taskIOMem != NULL, NCP_ST_TASK_MMAP_FAILED);

    nca->tqsArray = (ncp_ncav3_tqs_control_t *) taskIOMem;

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_alloc_task_state(
    ncp_t              *ncp,
    ncp_ncav3_hdl_t    *nca,
    ncp_task_swState_t *userState)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_CALL(ncp_nvm_robust_malloc(sizeof(ncp_task_swState_t),
            (void **)&pNcpTaskSwState,
            NCP_DO_MEMSET));

    pNcpTaskSwState->ncp = ncp;
    pNcpTaskSwState->nca = ncp->ncaHdl;

    ncp->domainIsInternal = userState->domainIsInternal;
    pNcpTaskSwState->domainIsInternal = userState->domainIsInternal;


NCP_RETURN_LABEL

    return ncpStatus;
}

static ncp_st_t
ncp_ncav3_copy_task_state_from_user(
    ncp_t              *ncp,
    ncp_ncav3_hdl_t    *nca,
    ncp_task_swState_t *userState,
    ncp_bool_t          internal)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    int i, j;

    /* Copy domain bundle mapping info */
    if (NCP_COPY_FROM_USER(
                &pNcpTaskSwState->domainMemMap,
                &userState->domainMemMap,
                sizeof(ncp_task_domain_bundle_t)))
    {
        NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                       ncp_xlf_nca_cfg_ncav3_copy_task_state_from_user_domainBundleCopyFromUserFailed,
                       NCP_MSG_ERROR, "Domain bundle copy from user failed.\n");
        NCP_CALL(NCP_ST_INTERNAL_ERROR);
    }

    /* Domain memory mapping is needed for A53 NCAPs only. No need to perform
     * on an external host.
     */
    if (internal)
    {
        NCP_CALL(ncp_ncav3_map_domain_memory(ncp, ncp->ncaHdl, myDevHdl));
    }

    /* Copy pool state */
    if (NCP_COPY_FROM_USER(
                &pNcpTaskSwState->taskPools,
                &userState->taskPools,
                NCP_NCAV3_NUM_TASK_MEMORY_POOLS * sizeof(ncp_task_pool_t)))
    {
        NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                       ncp_xlf_nca_cfg_ncav3_copy_task_state_from_user_taskPoolsCopyFromUserFailed,
                       NCP_MSG_ERROR, "Task pools copy from user failed.\n");
        NCP_CALL(NCP_ST_INTERNAL_ERROR);
    }

    /* Copy TQS state */
    if (NCP_COPY_FROM_USER(
                &pNcpTaskSwState->tqsSwState,
                &userState->tqsSwState,
                NCP_NCAV3_MAX_NUM_TQSETS * sizeof(ncp_task_tqs_swState_t)))
    {
        NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                       ncp_xlf_nca_cfg_copy_task_state_from_user_tqsStateCopyFromUserFailed,
                       NCP_MSG_ERROR, "TQS state copy from user failed.\n");
        NCP_CALL(NCP_ST_INTERNAL_ERROR);
    }

    for (i = 0; i < NCP_NCAV3_MAX_NUM_TQSETS; i++)
    {
        ncp_task_tqs_swState_t *tqs;

        tqs = &pNcpTaskSwState->tqsSwState[i];

        /* PGIT index pointers needed for interrupt handlers */
        tqs->rxQ.pProducerIdx = &nca->tqsArray[i].tqs.ncatable.ip_index;
        tqs->rxQ.pConsumerIdx = &nca->tqsArray[i].tqs.cputable.ic_index;

        tqs->txQ0.pProducerIdx = &nca->tqsArray[i].tqs.cputable.op0_index;
        tqs->txQ0.pConsumerIdx = &nca->tqsArray[i].tqs.ncatable.oc0_index;

        tqs->txQ1.pProducerIdx = &nca->tqsArray[i].tqs.cputable.op1_index;
        tqs->txQ1.pConsumerIdx = &nca->tqsArray[i].tqs.ncatable.oc1_index;

        if (tqs->pAppProfile == NULL)
        {
            continue;
        }

        NCP_CALL(ncp_ncav3_get_app_profile(ncp, tqs->profileId, &tqs->pAppProfile));
    }

    /* Copy NCA queue state */
    if (NCP_COPY_FROM_USER(
                &pNcpTaskSwState->numNcaQueues,
                &userState->numNcaQueues,
                sizeof(ncp_uint32_t)))
    {
        NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                       ncp_xlf_nca_cfg_ncav3_copy_task_state_from_user_ncaQueueCountCopyFromUserFailed,
                       NCP_MSG_ERROR, "NCA queue count copy from user failed.\n");
        NCP_CALL(NCP_ST_INTERNAL_ERROR);
    }

    if (NCP_COPY_FROM_USER(
                &pNcpTaskSwState->ncaQueueState,
                &userState->ncaQueueState,
                NCP_NCAV3_MAX_NUM_NCAQS * sizeof(ncp_ncav3_nca_queue_state_t)))
    {
        NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                       ncp_xlf_nca_cfg_ncav3_copy_task_state_from_user_ncaQueueStateCopyFromUserFailed,
                       NCP_MSG_ERROR, "NCA queue state copy from user failed.\n");
        NCP_CALL(NCP_ST_INTERNAL_ERROR);
    }

    /* Zero-out the queue's next pointer */
    for (i = 0; i < NCP_NCAV3_MAX_NUM_NCAQS; i++)
    {
        pNcpTaskSwState->ncaQueueState[i].next = NULL;
    }

    /* Set profile pointers with kernel addresses */
    for (i = 0; i < NCP_NCAV3_MAX_NUM_NCAQS; i++)
    {
        ncp_ncav3_nca_queue_state_t *queue;

        queue = &pNcpTaskSwState->ncaQueueState[i];

        if (queue->queueProfileId == -1)
        {
            queue->profile = NULL;
            continue;
        }

        NCP_CALL(ncp_ncav3_get_queue_profile(
                    queue->queueProfileId,
                   &queue->profile));
    }

    /* Copy queue group state */
    if (NCP_COPY_FROM_USER(
                &pNcpTaskSwState->numQueueGroups,
                &userState->numQueueGroups,
                sizeof(ncp_uint32_t)))
    {
        NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                       ncp_xlf_nca_cfg_ncav3_copy_task_state_from_user_ncaQueueGroupCountCopyFromUserFailed,
                       NCP_MSG_ERROR, "NCA queue group count copy failed.\n");
        NCP_CALL(NCP_ST_INTERNAL_ERROR);
    }

    if (NCP_COPY_FROM_USER(
                &pNcpTaskSwState->queueGroups,
                &userState->queueGroups,
                NCP_NCAV3_MAX_NUM_QUEUE_GROUPS *
                    sizeof(ncp_ncav3_nca_queue_group_t)))
    {
        NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                       ncp_xlf_nca_cfg_ncav3_copy_task_state_from_user_ncaQueueGroupStateCopyFromUserFailed,
                       NCP_MSG_ERROR, "NCA queue group state copy failed.\n");
        NCP_CALL(NCP_ST_INTERNAL_ERROR);
    }

    /* Set groupMembers pointers with kernel addresses */
    for (i = 0; i < NCP_NCAV3_MAX_NUM_QUEUE_GROUPS; i++)
    {
        ncp_ncav3_nca_queue_group_t *queueGroup;

        queueGroup = &pNcpTaskSwState->queueGroups[i];

        queueGroup->groupMembers = NULL;
    }

    for (i = 0; i < NCP_NCAV3_MAX_NUM_NCAQS; i++)
    {
        ncp_ncav3_nca_queue_group_t *queueGroup;
        ncp_ncav3_nca_queue_state_t *queue;
        ncp_ncav3_nca_queue_state_t *tail;

        queue = &pNcpTaskSwState->ncaQueueState[i];

        if (queue->groupId == -1)
        {
            continue;
        }

        queueGroup = &pNcpTaskSwState->queueGroups[queue->groupId];

        if (queueGroup->groupMembers == NULL)
        {
            queueGroup->groupMembers = queue;
        }
        else
        {
            tail = queueGroup->groupMembers;

            while (tail->next != NULL)
            {
                tail = tail->next;
            }

            tail->next = queue;
        }
    }

    /* Initialize tqsBitmaps */
    for (i = 0; i < NCP_NCAV3_MAX_NUM_QUEUE_GROUPS; i++)
    {
        ncp_ncav3_nca_queue_group_t *queueGroup;

        queueGroup = &pNcpTaskSwState->queueGroups[i];

        queueGroup->tqsBitmap = ncp_bitmap_create(NCP_NCAV3_MAX_NUM_TQSETS);
    }

    /* Construct tqsBitmaps */
    for (i = 0; i < NCP_NCAV3_MAX_NUM_TQSETS; i++)
    {
        ncp_task_tqs_swState_t *tqs;
        iPCQ_info_t *ipcq_info;

        tqs = &pNcpTaskSwState->tqsSwState[i];

        if (tqs->configured == FALSE)
        {
            continue;
        }

        ipcq_info = &tqs->rxQ.u.ipcq_info;

        for (j = 0; j < NCP_NCAV3_NUM_QUEUE_GROUPS_PER_IPCQ; j++)
        {
            ncp_ncav3_nca_queue_group_t *queueGroup;
            int groupId;

            groupId = ipcq_info->groupIndexes[j];

            if (groupId == -1)
            {
                continue;
            }

            queueGroup = &pNcpTaskSwState->queueGroups[groupId];

            ncp_bitmap_set(queueGroup->tqsBitmap, tqs->tqsId);
        }
    }

    /* Clear out unused lock state */
    for (i = 0; i < NCP_NCAV3_NUM_TASK_MEMORY_POOLS; i++)
    {
        NCP_TASK_V3_MUTEX_CLEAR(&pNcpTaskSwState->taskPools[i].poolLock);
    }

    /* Copy fixed pool info */
    if (NCP_COPY_FROM_USER(
                &pNcpTaskSwState->fixedPoolInfo,
                &userState->fixedPoolInfo,
                sizeof(ncp_ncav3_fixed_pool_t)))
    {
        NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                       ncp_xlf_nca_cfg_ncav3_copy_fixed_pool_info_from_user_domain_failed,
                       NCP_MSG_ERROR, "Fixed pool info copy from user failed.\n");
        NCP_CALL(NCP_ST_INTERNAL_ERROR);
    }

    pNcpTaskSwState->fixedPoolInfo.virtualBase = 0ULL;

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_copy_nca_from_user(
    ncp_ncav3_hdl_t **nca,
    ncp_ncav3_hdl_t *userNca)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    int i;

    NCP_CALL(ncp_nvm_robust_malloc(sizeof(ncp_ncav3_hdl_t),
                    (void **)nca,  /* already addr of ptr to return */
                    NCP_DO_NOT_MEMSET));

    if (NCP_COPY_FROM_USER(*nca, userNca, sizeof(ncp_ncav3_hdl_t)))
    {
        NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                       ncp_xlf_nca_cfg_ncav3_copy_nca_from_user_ncaHdlCopyFromUserFailed,
                       NCP_MSG_ERROR, "NCA handle copy from user failed.\n");
        NCP_CALL(NCP_ST_INTERNAL_ERROR);
    }

    /* Zero-out unneeded user-space pointers */
    (*nca)->tqsArray = NULL;
    (*nca)->configInfo.memoryQuotas = NULL;
    (*nca)->configInfo.unscheduledQueueConfig.pipelines = NULL;

    if ((*nca)->configInfo.taskReceiveQueues.numProfiles != 0)
    {
        ncp_ncav3_nca_queue_profile_t *queueProfiles;
        ncp_ncav3_task_receive_queue_config_t *queueConfig;

        queueConfig = &(*nca)->configInfo.taskReceiveQueues;

        NCP_CALL(ncp_nvm_robust_malloc(sizeof(ncp_ncav3_nca_queue_profile_t) * queueConfig->numProfiles,
                (void **)&queueProfiles,
                NCP_DO_NOT_MEMSET));

        if (NCP_COPY_FROM_USER(
                queueProfiles,
                queueConfig->queueProfiles,
                sizeof(ncp_ncav3_nca_queue_profile_t) *
                    queueConfig->numProfiles))
        {
            NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                           ncp_xlf_nca_cfg_ncav3_copy_nca_from_user_queueProfilesCopyFromUserFailed,
                           NCP_MSG_ERROR, "Queue profiles copy from user failed.\n");

            NCP_CALL(ncp_nvm_robust_free((void**)&queueProfiles));

            NCP_CALL(NCP_ST_INTERNAL_ERROR);
        }

        (*nca)->configInfo.taskReceiveQueues.queueProfiles = queueProfiles;
    }
    else
    {
        (*nca)->configInfo.taskReceiveQueues.queueProfiles = NULL;
    }

    /* Copy unscheduled monitored queue information into kernel-space */
    if ((*nca)->configInfo.unscheduledQueueConfig.numMonitoredQueues != 0)
    {
        ncp_ncav3_unscheduled_queue_t *queues;
        ncp_ncav3_unscheduled_queue_config_t *queueConfig;

        queueConfig = &(*nca)->configInfo.unscheduledQueueConfig;

        NCP_CALL(ncp_nvm_robust_malloc(sizeof(ncp_ncav3_unscheduled_queue_t) * queueConfig->numMonitoredQueues,
                                (void **)&queues,
                                NCP_DO_NOT_MEMSET));

        if (NCP_COPY_FROM_USER(
                queues,
                queueConfig->monitoredQueues,
                sizeof(ncp_ncav3_unscheduled_queue_t) *
                    queueConfig->numMonitoredQueues))
        {
            NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                           ncp_xlf_nca_cfg_ncav3_copy_nca_from_user_monitoredQueuesCopyFromUserFailed,
                           NCP_MSG_ERROR, "Monitored queues copy from user failed.\n");

            NCP_CLEANUP_MUTEX_CALL(ncp_nvm_robust_free((void**)&queues));

            NCP_CALL(NCP_ST_INTERNAL_ERROR);
        }

        (*nca)->configInfo.unscheduledQueueConfig.monitoredQueues = queues;
    }
    else
    {
        (*nca)->configInfo.unscheduledQueueConfig.monitoredQueues = NULL;
    }

    /* Copy unscheduled unmonitored queue information into kernel-space */
    if ((*nca)->configInfo.unscheduledQueueConfig.numUnmonitoredQueues != 0)
    {
        ncp_ncav3_unscheduled_queue_t *queues;
        ncp_ncav3_unscheduled_queue_config_t *queueConfig;

        queueConfig = &(*nca)->configInfo.unscheduledQueueConfig;

        NCP_CALL(ncp_nvm_robust_malloc(sizeof(ncp_ncav3_unscheduled_queue_t) * queueConfig->numUnmonitoredQueues,
                       (void **)&queues,
                       NCP_DO_NOT_MEMSET));

        if (NCP_COPY_FROM_USER(
                queues,
                queueConfig->unmonitoredQueues,
                sizeof(ncp_ncav3_unscheduled_queue_t) *
                    queueConfig->numUnmonitoredQueues))
        {
            NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                           ncp_xlf_nca_cfg_ncav3_copy_nca_from_user_unmonitoredQueuesCopyFromUserFailed,
                           NCP_MSG_ERROR, "Unmonitored queues copy from user failed.\n");

            NCP_CLEANUP_MUTEX_CALL(ncp_nvm_robust_free((void**) &queues));

            NCP_CALL(NCP_ST_INTERNAL_ERROR);
        }

        (*nca)->configInfo.unscheduledQueueConfig.unmonitoredQueues = queues;
        queues = NULL;
    }
    else
    {
        (*nca)->configInfo.unscheduledQueueConfig.unmonitoredQueues = NULL;
    }

    /* Copy unscheduled queue profiles into kernel-space */
    if ((*nca)->configInfo.unscheduledQueueConfig.numProfiles != 0)
    {
        ncp_ncav3_nca_queue_profile_t *profiles;
        ncp_ncav3_unscheduled_queue_config_t *queueConfig;

        queueConfig = &(*nca)->configInfo.unscheduledQueueConfig;

        NCP_CALL(ncp_nvm_robust_malloc(sizeof(ncp_ncav3_nca_queue_profile_t) *
                                queueConfig->numProfiles,
				(void**)&profiles,
				NCP_DO_NOT_MEMSET));

        if (NCP_COPY_FROM_USER(
                profiles,
                queueConfig->queueProfiles,
                sizeof(ncp_ncav3_nca_queue_profile_t) *
                    queueConfig->numProfiles))
        {
            NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                           ncp_xlf_nca_cfg_ncav3_copy_nca_from_user_unschedQueueProfilesFailed,
                           NCP_MSG_ERROR, "Unscheduled queue profiles copy failed.\n");

            NCP_CLEANUP_MUTEX_CALL(ncp_nvm_robust_free((void**)&profiles));

            NCP_CALL(NCP_ST_INTERNAL_ERROR);
        }

        (*nca)->configInfo.unscheduledQueueConfig.queueProfiles = profiles;
    }
    else
    {
        (*nca)->configInfo.unscheduledQueueConfig.queueProfiles = NULL;
    }

    /* Copy app profile information into kernel-space */
    if ((*nca)->configInfo.numProfiles != 0)
    {
        ncp_ncav3_application_profile_t *profiles;

        NCP_CALL(ncp_nvm_robust_malloc(sizeof(ncp_ncav3_application_profile_t) * (*nca)->configInfo.numProfiles,
                       (void **)&profiles,
                       NCP_DO_NOT_MEMSET));

        if (NCP_COPY_FROM_USER(
                    profiles,
                    (*nca)->configInfo.profiles,
                    sizeof(ncp_ncav3_application_profile_t) *
                        (*nca)->configInfo.numProfiles))
        {
            NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                           ncp_xlf_nca_cfg_ncav3_copy_nca_from_user_appProfilesCopyFromUserFailed,
                           NCP_MSG_ERROR, "App profiles copy from user failed.\n");

            NCP_CLEANUP_MUTEX_CALL(ncp_nvm_robust_free((void**)&profiles));

            NCP_CALL(NCP_ST_INTERNAL_ERROR);
        }

        (*nca)->configInfo.profiles = profiles;

        for (i = 0; i < (*nca)->configInfo.numProfiles; i++)
        {
            ncp_ncav3_application_profile_t *profile;
            ncp_ncav3_shared_data_region_map_t *sharedDataRegionMap;

            profile = &((*nca)->configInfo.profiles[i]);

            if (profile->baseProfile.sharedDataRegionMap)
            {
                int numMaps = profile->baseProfile.numSharedDataRegionMaps;

                NCP_CALL(ncp_nvm_robust_malloc(
                        numMaps * sizeof(ncp_ncav3_shared_data_region_map_t),
                        (void **)&sharedDataRegionMap,
                        NCP_DO_NOT_MEMSET));

                if (NCP_COPY_FROM_USER(
                            sharedDataRegionMap,
                            profile->baseProfile.sharedDataRegionMap,
                            numMaps * sizeof(ncp_ncav3_shared_data_region_map_t)))
                {
                    NCP_TRACEPOINT(Intel_AXXIA_ncp_nca,
                                   ncp_xlf_nca_cfg_ncav3_copy_nca_from_user_sharedDataRegionCopyFromUserFailed,
                                   NCP_MSG_ERROR, "Shared data region copy failed.\n");

                    NCP_CLEANUP_MUTEX_CALL(ncp_nvm_robust_free((void**)&sharedDataRegionMap));

                    NCP_CALL(NCP_ST_INTERNAL_ERROR);
                }

                profile->baseProfile.sharedDataRegionMap = sharedDataRegionMap;
            }

            profile->auxiliaryInfo = NULL;
        }
    }
    else
    {
        (*nca)->configInfo.profiles = NULL;
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_initialize_kernel_locks(void)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    NCP_CALL(NCP_TASK_INIT_LOCK(&ipcqOnlineLock, TRUE));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_configure_qpm_interrupt_queue_support(
    ncp_t           *ncp,
    ncp_ncav3_hdl_t *nca,
    ncp_dev_hdl_t    dev)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_uint16_t maxQueueId = 0;
    ncp_ncav3_unscheduled_queue_config_t *queueConfig;
    int i;

    queueConfig = &nca->configInfo.unscheduledQueueConfig;

    for (i = 0; i < queueConfig->numMonitoredQueues; i++)
    {
        if (queueConfig->monitoredQueues[i].maxQueueId > maxQueueId)
        {
            maxQueueId = queueConfig->monitoredQueues[i].maxQueueId;
        }
    }

    for (i = 0; i < queueConfig->numUnmonitoredQueues; i++)
    {
        if (queueConfig->unmonitoredQueues[i].maxQueueId > maxQueueId)
        {
            maxQueueId = queueConfig->unmonitoredQueues[i].maxQueueId;
        }
    }

    ((ncp_dev_t *) dev)->lastQpmEventQueueId = maxQueueId;

    ((ncp_dev_t *) dev)->numQpmEventQueues = queueConfig->numMonitoredQueues +
                                             queueConfig->numUnmonitoredQueues;

NCP_RETURN_LABEL

    return ncpStatus;
}

static ncp_st_t
ncp_ncav3_initialize_fixed_pool(
    ncp_ncav3_hdl_t *nca,
    ncp_dev_hdl_t dev)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    int i;

    if (FALSE == pNcpTaskSwState->fixedPoolInfo.valid)
    {
        NCP_RETURN(NCP_ST_SUCCESS);
    }

    /* Loop over all CPU profiles, find a kernel TQS profile that uses the
     * fixed pool. Once found, map in the fixed pool.
     */
    for (i = 0; i < nca->configInfo.numProfiles; i++) {
        ncp_ncav3_application_profile_t *profile;

        profile = &nca->configInfo.profiles[i];

        if (CPU_PROFILE != profile->profileType ||
            FALSE == profile->baseProfile.fixedPoolMap.enabled ||
            TRUE == profile->baseProfile.uMode)
        {
            continue;
        }

        ncp_ncav3_map_fixed_pool(&profile->baseProfile);
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_config_kernel(
    ncp_t                    *ncp,
    ncp_ncav3_hdl_t          *userNca,
    ncp_dev_hdl_t             dev,
    ncp_ncav3_struct_sizes_t  sizes,
    ncp_bool_t                internal)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_swState_t *userState = pNcpTaskSwState;
    ncp_ncav3_hdl_t *nca;

    /*
     * Check whether the user-space structure sizes match the kernel ones.
     * Since we do COPY_FROM_USER with sizeof(), these must match.
     */
    NCP_ASSERT(sizes.domainBundleSize == sizeof(ncp_task_domain_bundle_t),
        NCP_ST_INTERNAL_ERROR);
    NCP_ASSERT(sizes.taskPoolSize == sizeof(ncp_task_pool_t),
        NCP_ST_INTERNAL_ERROR);
    NCP_ASSERT(sizes.tqsSwStateSize == sizeof(ncp_task_tqs_swState_t),
        NCP_ST_INTERNAL_ERROR);
    NCP_ASSERT(sizes.queueStateSize ==
                sizeof(ncp_ncav3_nca_queue_state_t),
        NCP_ST_INTERNAL_ERROR);
    NCP_ASSERT(sizes.queueGroupStateSize == sizeof(ncp_ncav3_nca_queue_group_t),
        NCP_ST_INTERNAL_ERROR);
    NCP_ASSERT(sizes.ncaHdlSize == sizeof(ncp_ncav3_hdl_t),
        NCP_ST_INTERNAL_ERROR);
    NCP_ASSERT(sizes.queueProfileSize == sizeof(ncp_ncav3_nca_queue_profile_t),
        NCP_ST_INTERNAL_ERROR);
    NCP_ASSERT(sizes.unscheduledQueueSize ==
                sizeof(ncp_ncav3_unscheduled_queue_t),
        NCP_ST_INTERNAL_ERROR);
    NCP_ASSERT(sizes.appProfileSize == sizeof(ncp_ncav3_application_profile_t),
        NCP_ST_INTERNAL_ERROR);
    NCP_ASSERT(sizes.fixedPoolSize == sizeof(ncp_ncav3_fixed_pool_t),
        NCP_ST_INTERNAL_ERROR);
    NCP_ASSERT(sizes.sharedDataRegionMapSize ==
                sizeof(ncp_ncav3_shared_data_region_map_t),
        NCP_ST_INTERNAL_ERROR);

    /* Initialize the process-global handles, required for
     * ncp_ncav3_supply_nca_buffers() and kernel task I/O. */
    myDevHdl = dev;
    myNcpHdl = (ncp_hdl_t) ncp;

    NCP_CALL(ncp_ncav3_copy_nca_from_user(&nca, userNca));

    ncp->ncaHdl = (ncp_hdl_t) nca;

    NCP_CALL(ncp_ncav3_alloc_task_state(ncp, nca, userState));

    /* Run this after copying configInfo, since tqsSwState and ncaQueueState
     * searches the profiles stored in configInfo.
     */
    NCP_CALL(ncp_ncav3_copy_task_state_from_user(ncp, nca, userState, internal));

    nca->taskSwState = pNcpTaskSwState;

    NCP_CALL(ncp_ncav3_initialize_kernel_locks());

    NCP_CALL(ncp_task_init_sw_state(ncp));

    NCP_CALL(ncp_ncav3_initialize_cpu_pools(dev, FALSE));

    NCP_CALL(ncp_ncav3_configure_cpu_pool_addr_convert_ram(dev, FALSE));

    NCP_CALL(ncp_ncav3_initialize_fixed_pool(nca, dev));

    NCP_CALL(ncp_ncav3_configure_fixed_pool_addr_convert_ram(nca, dev, FALSE));

    /* Copy the device handle's revision info into the ncp handle. This copy
     * happens for user-space ncp handles at config attach time.
     */
    memcpy(&ncp->rev, &((ncp_dev_t *) dev)->config->rev, sizeof(ncp_rev_id_t));

    NCP_CALL(ncp_task_initialize_tqs_task_state(myNcpHdl, FALSE));

    NCP_CALL(ncp_ncav3_static_supply_nca_buffers(ncp, nca, dev, FALSE));

    NCP_CALL(ncp_ncav3_configure_qpm_interrupt_queue_support(ncp, nca, dev));

    nca->inConfigurationPhase = FALSE;

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_kernel_destroy(
    ncp_t        *ncp,
    ncp_dev_hdl_t dev)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    NCP_CALL(ncp_ncav3_config_free(ncp->ncaHdl, dev));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_get_qpm_stats(
    ncp_dev_hdl_t  devHdl,
    ncp_uint16_t   queueId,
    ncp_uint64_t  *fullQueue,
    ncp_uint64_t  *emptyQueue,
    ncp_uint64_t  *overflow)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_dev_t *dev = (ncp_dev_t *) devHdl;
    ncp_bool_t unlockRequired = FALSE;
    unsigned long flags;

    /* Parameter validation */

    dev->isr_spin.lock(&dev->qpmISRLock, &flags);
    unlockRequired = TRUE;

    *fullQueue  = dev->qpmStats[queueId].numEvents[0];
    *emptyQueue = dev->qpmStats[queueId].numEvents[1];
    *overflow   = dev->qpmStats[queueId].numEvents[2];

NCP_RETURN_LABEL

    if (unlockRequired)
    {
        dev->isr_spin.unlock(&dev->qpmISRLock, flags);
    }

    return(ncpStatus);
}

static ncp_st_t
ncp_ncav3_change_nca_queue_online_state(
    ncp_dev_hdl_t dev,
    ncp_uint32_t  queueId,
    ncp_bool_t    online)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_nca_itp_tpd_ram_r_t r0;

    NCP_CALL(ncp_block_read32(
                dev,
                NCP_REGION_NCAV3_CORE,
                NCP_NCA_ITP_TPD_RAM(queueId) + NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                (ncp_uint32_t *) &r0,
                sizeof(r0)/4,
                0));

    r0.online = online;

    NCP_CALL(ncp_block_write32(
                dev,
                NCP_REGION_NCAV3_CORE,
                NCP_NCA_ITP_TPD_RAM(queueId) + NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                (ncp_uint32_t *) &r0,
                sizeof(r0)/4,
                0));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_bring_nca_queue_online(
    ncp_dev_hdl_t dev,
    ncp_uint32_t  queueId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_nca_queue_state_t *queue;

    queue = &pNcpTaskSwState->ncaQueueState[queueId];

    NCP_ASSERT(queue->tqId == queueId, NCP_ST_INTERNAL_ERROR);

    if (queue->enabled == TRUE) {
        NCP_RETURN(NCP_ST_SUCCESS);
    }

    NCP_ASSERT(queue->profile != NULL, NCP_ST_TASK_NCA_QUEUE_NOT_CONFIGURED);

    NCP_ASSERT(queue->groupId != -1,
        NCP_ST_TASK_NCA_QUEUE_GROUP_NOT_SPECIFIED);

    NCP_CALL(ncp_ncav3_change_nca_queue_online_state(dev, queueId, TRUE));

    queue->enabled = TRUE;

    NCP_CALL(ncp_ncav3_config_cow_task_queue(queue));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_nca_queue_enable(
    ncp_dev_hdl_t dev,
    ncp_uint32_t  queueId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));
    NCP_CALL(ncp_ncav3_bring_nca_queue_online(dev, queueId));

NCP_RETURN_LABEL

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_take_nca_queue_offline(
    ncp_dev_hdl_t dev,
    ncp_uint32_t  queueId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    NCP_ASSERT(pNcpTaskSwState->ncaQueueState[queueId].tqId == queueId,
            NCP_ST_INTERNAL_ERROR);

    NCP_CALL(ncp_ncav3_change_nca_queue_online_state(dev, queueId, FALSE));

    pNcpTaskSwState->ncaQueueState[queueId].enabled = FALSE;

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_nca_queue_disable(
    ncp_dev_hdl_t dev,
    ncp_uint32_t  queueId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));
    NCP_CALL(ncp_ncav3_take_nca_queue_offline(dev, queueId));

NCP_RETURN_LABEL

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_tqs_enable(
    ncp_uint16_t tqsId)
{
    return ncp_task_tqs_enable(myNcpHdl, tqsId);
}

ncp_st_t
ncp_ncav3_tqs_disable(
    ncp_uint16_t tqsId)
{
    return ncp_task_tqs_disable(myNcpHdl, tqsId);
}

ncp_st_t
ncp_ncav3_enable_kernel_tqs(
    ncp_dev_hdl_t dev,
    ncp_uint16_t  tqsId,
    ncp_bool_t    enable)
{
    /* This function should *never* be called in the kernel. */
    return NCP_ST_INTERNAL_ERROR;
}

/*********************************************************************/
/************** Dynamic Configuration ********************************/
/*********************************************************************/

/* The iPCQ value passed to the dynamic configuration register is the packed
 * iPCQ ID, which is the index into the IPD RAM. For the ASIC and the
 * simulator, the IPD index is equal to the absolute iPCQ number. For the
 * FPGA, this is not the case.
 *
 * These functions must be called with the task I/O resource lock held.
 */

ncp_st_t
ncp_ncav3_add_gid_to_ipcq(
    ncp_t         *ncp,
    ncp_dev_hdl_t  dev,
    ncp_uint8_t    gidSlot,
    ncp_uint8_t    groupId,
    ncp_uint8_t    priority,
    ncp_uint8_t    ipcqId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_nca_cfg_cfg_dynamic_cmd_r_t r0;
    ncp_nca_cfg_cfg_dynamic_status_r_t r1;

    NCP_CHECK(gidSlot <= 7, NCP_ST_INVALID_PARAMETER);
    NCP_CHECK(ipcqId <= 85, NCP_ST_INVALID_PARAMETER);

    /* FIXME - Create IPD entry variable in TQS s/w state */
    if (ncp->isFPGA)
    {
        ncp_uint8_t ncapId, relTqsId;

        if (ipcqId < 64)
        {
            ncapId =   ipcqId / 8;
            relTqsId = ipcqId % 8;
        }
        else if (ipcqId < 80)
        {
            ncapId =   ((ipcqId - 64) / 4) + 9;
            relTqsId = ((ipcqId - 64) % 4);
        }
        else
        {
            ncapId = 8;
            relTqsId = ipcqId - 80;
        }
        NCP_CALL(ncp_ncav3_fpga_lookup_ipd_entry(dev, ncapId, relTqsId, &ipcqId));
    }

    r0.command = 1;
    r0.parameters = ((priority & 0x7) << 19) |
                    ((gidSlot  & 0x7) << 16) |
                    ((groupId       ) << 8 ) |
                      ipcqId;

    /* Double-check that no dynamic command is currently active */
    NCP_DEV_NCA_READ_REG32(dev,
            NCP_REGION_NCAV3_CORE,
            NCP_NCA_CORE_CFG_ADDR_MAP_BASE + NCP_NCA_CFG_CFG_DYNAMIC_STATUS,
            (ncp_uint32_t *)&r1);

    NCP_ASSERT(r1.active == FALSE, NCP_ST_ERROR);

    NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
            NCP_REGION_NCAV3_CORE,
            NCP_NCA_CORE_CFG_ADDR_MAP_BASE + NCP_NCA_CFG_CFG_DYNAMIC_CMD,
            (ncp_uint32_t *)&r0);

    /* Don't return until the command completes. */
    do {
        NCP_DEV_NCA_READ_REG32(dev,
                NCP_REGION_NCAV3_CORE,
                NCP_NCA_CORE_CFG_ADDR_MAP_BASE +
                    NCP_NCA_CFG_CFG_DYNAMIC_STATUS,
                (ncp_uint32_t *)&r1);
    } while (r1.done == FALSE);

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_delete_gid_from_ipcq(
    ncp_t         *ncp,
    ncp_dev_hdl_t  dev,
    ncp_uint8_t    gidSlot,
    ncp_uint8_t    groupId,
    ncp_uint8_t    priority,
    ncp_uint8_t    ipcqId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_nca_cfg_cfg_dynamic_cmd_r_t r0;
    ncp_nca_cfg_cfg_dynamic_status_r_t r1;

    NCP_CHECK(gidSlot <= 7, NCP_ST_INVALID_PARAMETER);
    NCP_CHECK(ipcqId <= 85, NCP_ST_INVALID_PARAMETER);

    /* FIXME - Create IPD entry variable in TQS s/w state */
    if (ncp->isFPGA)
    {
        ncp_uint8_t ncapId, relTqsId;

        NCP_CALL(ncp_ncav3_get_ncap_and_tqs_id_from_absolute_group_id(
            ipcqId,
            &ncapId,
            &relTqsId));

        NCP_CALL(ncp_ncav3_fpga_lookup_ipd_entry(dev, ncapId, relTqsId, &ipcqId));
    }

    r0.command = 2;
    r0.parameters = (priority & 0x7) << 19 |
                    (gidSlot  & 0x7) << 16 |
                    (groupId       ) << 8  |
                     ipcqId;

    /* Double-check that no dynamic command is currently active */
    NCP_DEV_NCA_READ_REG32(dev,
            NCP_REGION_NCAV3_CORE,
            NCP_NCA_CORE_CFG_ADDR_MAP_BASE + NCP_NCA_CFG_CFG_DYNAMIC_STATUS,
            (ncp_uint32_t *)&r1);

    NCP_ASSERT(r1.active == FALSE, NCP_ST_ERROR);

    NCP_DEV_NCA_WRITE_INDIRECT_REG32(dev,
            NCP_REGION_NCAV3_CORE,
            NCP_NCA_CORE_CFG_ADDR_MAP_BASE + NCP_NCA_CFG_CFG_DYNAMIC_CMD,
            (ncp_uint32_t *)&r0);

    /* Don't return until the command completes. */
    do {
        NCP_DEV_NCA_READ_REG32(dev,
                NCP_REGION_NCAV3_CORE,
                NCP_NCA_CORE_CFG_ADDR_MAP_BASE +
                    NCP_NCA_CFG_CFG_DYNAMIC_STATUS,
                (ncp_uint32_t *)&r1);
    } while (r1.done == FALSE);

NCP_RETURN_LABEL

    return ncpStatus;
}

/***************************************************************/
/************** COW Task Queues ********************************/
/***************************************************************/

/* These COW functions aren't yet available in the kernel, so they've been
 * copied into the NCAv3 kernel code and tailored to the NCAv3 codepath.
 */
static ncp_st_t
ncp_ncav3_cow_til_input_queue_weight_set(
    ncp_dev_hdl_t     devHdl,
    ncp_uint32_t      queue,
    ncp_uint32_t      wrrWeight)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_nu_til_in_q_weight_t inpq_weight = { 0 };
    ncp_uint32_t *reg = (ncp_uint32_t *)&inpq_weight;

    /* weight cannot be > 0xf */
    NCP_ASSERT(wrrWeight <= 0xf, NCP_ST_COW_INVALID_INPUT_QUEUE_WEIGHT);

    /* do register update */
    inpq_weight.weight = wrrWeight;

    NCP_CALL(ncp_write32(devHdl,
                NCP_REGION_ID(NCP_NODE_NCA, 1),
                NCP_NU_TIL_TASK_IN_Q_WEIGHT_INST(queue),
                *reg));

NCP_RETURN_LABEL

    return ncpStatus;
}

static ncp_st_t
ncp_ncav3_cow_tcld_task_queue_enable(
    ncp_dev_hdl_t     devHdl,
    ncp_uint32_t      queue,
    ncp_bool_t        enable)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_nu_tcld_queue_discard_thresh_group_r_t qDiscardThres = { 0 };
    ncp_uint32_t *reg = (ncp_uint32_t *)&qDiscardThres;

    /* read the current value */
    NCP_CALL(ncp_read32(devHdl,
         NCP_REGION_ID(NCP_NODE_NCA, 0),
         NCP_NU_TCLD_INST_RANGE_0_QUEUE_DISCARD_THRESH_GROUP_ARRAY(queue),
         reg));

    qDiscardThres.dest_id_drop = enable ? 0 : 1;

    /* configure queue discard thres id in the HW */
    NCP_CALL(ncp_write32(devHdl,
         NCP_REGION_ID(NCP_NODE_NCA, 0),
         NCP_NU_TCLD_INST_RANGE_0_QUEUE_DISCARD_THRESH_GROUP_ARRAY(queue),
         *reg));

NCP_RETURN_LABEL

    return ncpStatus;
}

static ncp_st_t
ncp_ncav3_cow_tcld_bp_grp_id_set(
    ncp_dev_hdl_t     devHdl,
    ncp_uint8_t       instRange,
    ncp_uint8_t       queue,
    ncp_uint8_t       thresGroupId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_nu_tcld_task_queue_rf_5600_t taskQ_56xx = { 0 };
    ncp_uint32_t *reg = NULL;
    ncp_uint32_t offset = 0;
    ncp_uint8_t words = 0;

    thresGroupId <<= 1;

    offset = NCP_NU_TCLD_REG_TASK_QUEUE_MEMORY_5600(queue);
    words = sizeof(ncp_nu_tcld_task_queue_rf_5600_t)/sizeof(ncp_uint32_t);

    reg = (ncp_uint32_t *)&taskQ_56xx;

    /* read, update and write back queue memory */
    NCP_CALL(ncp_block_read32(devHdl,
                    NCP_REGION_ID(NCP_NODE_NCA, 0),
                    offset,
                    reg,
                    words,
                    0));

    taskQ_56xx.bp_thresh_group = thresGroupId;

    NCP_CALL(ncp_block_write32(devHdl,
                    NCP_REGION_ID(NCP_NODE_NCA, 0),
                    offset,
                    reg,
                    words,
                    0));

NCP_RETURN_LABEL

    return ncpStatus;
}

static ncp_st_t
ncp_ncav3_cow_tcld_thresh_group_id_set(
    ncp_dev_hdl_t     devHdl,
    ncp_uint32_t      queue,
    ncp_uint32_t      threshGroupId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_nu_tcld_queue_discard_thresh_group_r_t qDiscardThres = { 0 };
    ncp_uint32_t *reg = (ncp_uint32_t *)&qDiscardThres;

    /* read the current value */
    NCP_CALL(ncp_read32(devHdl,
         NCP_REGION_ID(NCP_NODE_NCA, 0),
         NCP_NU_TCLD_INST_RANGE_0_QUEUE_DISCARD_THRESH_GROUP_ARRAY(queue),
         reg));

    qDiscardThres.queue_discard_thresh_group_number = threshGroupId;

    /* configure queue discard thres id in the HW */
    NCP_CALL(ncp_write32(devHdl,
         NCP_REGION_ID(NCP_NODE_NCA, 0),
         NCP_NU_TCLD_INST_RANGE_0_QUEUE_DISCARD_THRESH_GROUP_ARRAY(queue),
         *reg));

    /*
     * Configure backpressure id in task/logical queue
     */
    NCP_CALL(ncp_ncav3_cow_tcld_bp_grp_id_set(
        devHdl,
        0,
        queue,
        threshGroupId));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_config_cow_task_queue(
    ncp_ncav3_nca_queue_state_t *queue)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    if (queue->queueProfileId == -1)
    {
        NCP_RETURN(NCP_ST_SUCCESS);
    }

    if (queue->enabled == FALSE)
    {
        NCP_RETURN(NCP_ST_SUCCESS);
    }

    NCP_CALL(ncp_ncav3_cow_tcld_task_queue_enable(
                myDevHdl,
                queue->tqId,
                queue->enabled));

    NCP_CALL(ncp_ncav3_cow_tcld_thresh_group_id_set(
                myDevHdl,
                queue->tqId,
                queue->profile->thresholdGroupId));

    NCP_CALL(ncp_ncav3_cow_til_input_queue_weight_set(
                myDevHdl,
                queue->tqId,
                queue->wrrWeight));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_tqs_configure_flags_get(
    ncp_dev_hdl_t devHdl,
    ncp_uint32_t  tqsId,
    ncp_task_tqs_shared_t *pFlags)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_tqs_swState_t *pTqsSwState;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    if (pNcpTaskSwState->domainId !=
        pNcpTaskSwState->tqsSwState[tqsId].domainId)
    {
        NCP_CALL(NCP_ST_TASK_QUESET_NOT_IN_LOCAL_DOMAIN);
    }

    if (FALSE == pNcpTaskSwState->tqsSwState[tqsId].configured)
    {
        NCP_CALL(NCP_ST_TASK_TQS_NOT_CONFIGURED);
    }

    pTqsSwState = &pNcpTaskSwState->tqsSwState[tqsId];

    memcpy(pFlags,
            &pTqsSwState->shareCtl.shareFlags,
            sizeof(ncp_task_tqs_shared_t));

NCP_RETURN_LABEL

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_tqs_memory_quota_group_get(
    ncp_dev_hdl_t devHdl,
    ncp_uint32_t tqsId,
    ncp_uint32_t *pMemoryQuotaGroupId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    if (pNcpTaskSwState->domainId !=
        pNcpTaskSwState->tqsSwState[tqsId].domainId)
    {
        NCP_CALL(NCP_ST_TASK_QUESET_NOT_IN_LOCAL_DOMAIN);
    }

    if (FALSE == pNcpTaskSwState->tqsSwState[tqsId].configured)
    {
        NCP_CALL(NCP_ST_TASK_TQS_NOT_CONFIGURED);
    }

    *pMemoryQuotaGroupId = pNcpTaskSwState->tqsSwState[tqsId].mqg;

NCP_RETURN_LABEL

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_tqs_queue_group_get(
    ncp_dev_hdl_t devHdl,
    ncp_uint32_t tqsId,
    ncp_task_queue_group_set_t pGrp[8],
    ncp_uint8_t *pNumQueueGroups)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    iPCQ_info_t *ipcqInfo;
    ncp_task_tqs_swState_t *pTqs;
    ncp_task_queue_group_set_t *pGrpEntry;
    int i;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_TASK_LOCK_FLAGS(flags);

    pTqs = &pNcpTaskSwState->tqsSwState[tqsId];

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    if (pNcpTaskSwState->domainId != pTqs->domainId)
    {
        NCP_CALL(NCP_ST_TASK_QUESET_NOT_IN_LOCAL_DOMAIN);
    }

    if (FALSE == pTqs->configured)
    {
        pTqs = NULL;
        NCP_CALL(NCP_ST_TASK_TQS_NOT_CONFIGURED);
    }

    ipcqInfo = &pTqs->rxQ.u.ipcq_info;

    pGrpEntry = &pGrp[0];

    for (i = 0; i < NCP_NCAV3_NUM_QUEUE_GROUPS_PER_IPCQ; i++)
    {
        if (ipcqInfo->groupIndexes[i] != -1)
        {
            pGrpEntry->queueGroup = ipcqInfo->groupIndexes[i];
            pGrpEntry->queueGroupPriority = ipcqInfo->groupPriorities[i];
            pGrpEntry->queueGroupStatus = NCP_ST_SUCCESS;
            pGrpEntry++;
        }
    }

    *pNumQueueGroups = ipcqInfo->numQueueGroupMappings;

NCP_RETURN_LABEL

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_queue_group_membership_get(
    ncp_dev_hdl_t  devHdl,
    ncp_uint32_t   ncaQueueId,
    ncp_uint32_t  *pQueueGroupId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    *pQueueGroupId = pNcpTaskSwState->ncaQueueState[ncaQueueId].groupId;

NCP_RETURN_LABEL

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_queue_group_name_get(
    ncp_dev_hdl_t devHdl,
    ncp_uint32_t queueGroupId,
    ncp_task_resource_name_t *name)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    strncpy(name->name,
            pNcpTaskSwState->queueGroups[queueGroupId].name.name,
            sizeof(ncp_task_resource_name_t));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_tqs_name_get(
    ncp_dev_hdl_t devHdl,
    ncp_uint32_t tqsId,
    ncp_task_resource_name_t *pResourceName)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    if (pNcpTaskSwState->domainId !=
        pNcpTaskSwState->tqsSwState[tqsId].domainId)
    {
        NCP_CALL(NCP_ST_TASK_QUESET_NOT_IN_LOCAL_DOMAIN);
    }

    if (FALSE == pNcpTaskSwState->tqsSwState[tqsId].configured)
    {
        NCP_CALL(NCP_ST_TASK_TQS_NOT_CONFIGURED);
    }

    strncpy(pResourceName->name,
            pNcpTaskSwState->tqsSwState[tqsId].name.name,
            sizeof(ncp_task_resource_name_t));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_nca_queue_name_get(
    ncp_dev_hdl_t devHdl,
    ncp_uint32_t ncaQueueId,
    ncp_task_resource_name_t *name)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_nca_queue_state_t *queue;

    queue = &pNcpTaskSwState->ncaQueueState[ncaQueueId];

    strncpy(name->name, queue->name.name, sizeof(ncp_task_resource_name_t));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_queue_group_id_get(
    ncp_dev_hdl_t devHdl,
    ncp_task_resource_name_t *name,
    ncp_uint32_t *pQueueGroupId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_bool_t found = FALSE;
    int i;

    for (i = 0; i < NCP_NCAV3_MAX_NUM_QUEUE_GROUPS; i++)
    {
        ncp_ncav3_nca_queue_group_t *group = &pNcpTaskSwState->queueGroups[i];

        if (FALSE == group->enabled)
        {
            continue;
        }

        if (strncmp(name->name,
                    group->name.name,
                    sizeof(ncp_task_resource_name_t)) == 0)
        {
            *pQueueGroupId = group->groupId;
            found = TRUE;
            break;
        }
    }

    if (found == FALSE)
    {
        ncpStatus = NCP_ST_TASK_QUEUE_GROUP_NOT_FOUND;
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_tqs_id_get(
    ncp_dev_hdl_t devHdl,
    ncp_task_resource_name_t *pResourceName,
    ncp_uint32_t *pTqsId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)
    int tqsId;

    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK((NULL != pTqsId), NCP_ST_INVALID_PARAMETER);

    /* Validate supplied name */
    NCP_TASK_VALIDATE_RESOURCE_NAME(pResourceName,
        NCP_ST_TASK_BAD_RESOURCE_NAME);

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    for (tqsId=0; tqsId < NCP_NCAV3_MAX_NUM_TQSETS; tqsId++)
    {
        if (FALSE == pNcpTaskSwState->tqsSwState[tqsId].configured)
        {
            continue;
        }
        if (0 == strncmp(pResourceName->name,
                    pNcpTaskSwState->tqsSwState[tqsId].name.name,
                    sizeof(ncp_task_resource_name_t)))
        {
            *pTqsId = tqsId;
            NCP_JUMP_RETURN();
        }
    }

    ncpStatus = NCP_ST_TASK_TQSNAME_NOT_FOUND;

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_nca_queue_id_get(
    ncp_dev_hdl_t devHdl,
    ncp_task_resource_name_t *name,
    ncp_uint32_t *pNcaQueueId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_bool_t found = FALSE;
    int i;

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_ncav3_nca_queue_id_get_entry,
                          NCP_MSG_ENTRY,
                          "devHdl=%p name=%s pNcaQueueId=%p"
                          "\n",
                          devHdl, (name) ? (name->name) : "(null)",
                          pNcaQueueId);
    for (i = 0; i < pNcpTaskSwState->numNcaQueues; i++)
    {
        ncp_ncav3_nca_queue_state_t *queue =
            &pNcpTaskSwState->ncaQueueState[i];

        if (strncmp(name->name,
                    queue->name.name,
                    sizeof(ncp_task_resource_name_t)) == 0)
        {
            *pNcaQueueId = queue->tqId;
            found = TRUE;
            break;
        }
    }

    if (found == FALSE)
    {
        ncpStatus = NCP_ST_TASK_NCA_QUEUE_NOT_FOUND;
    }

NCP_RETURN_LABEL

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_ncav3_nca_queue_id_get_exit,
                          NCP_MSG_EXIT,
                          "ncpStatus=%d pNcaQueueId=%p(%d)\n",
                          ncpStatus, pNcaQueueId,
                          (pNcaQueueId) ? (*pNcaQueueId) : 0);
    return ncpStatus;
}

ncp_st_t
ncp_ncav3_cpu_app_profile_name_get(
    ncp_dev_hdl_t devHdl,
    ncp_uint32_t profileId,
    ncp_task_resource_name_t *name)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_application_profile_t *profile;

    NCP_CALL(ncp_ncav3_get_app_profile((ncp_t *) myNcpHdl, profileId, &profile));

    strncpy(name->name,
            profile->baseProfile.name.name,
            sizeof(ncp_task_resource_name_t));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_nca_queue_profile_name_get(
    ncp_dev_hdl_t devHdl,
    ncp_uint32_t  profileId,
    ncp_task_resource_name_t *name)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_task_receive_queue_config_t *queueConfig;

    queueConfig = &pNcpTaskSwState->nca->configInfo.taskReceiveQueues;

    strncpy(name->name,
            queueConfig->queueProfiles[profileId].name.name,
            sizeof(ncp_task_resource_name_t));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_nca_queue_profile_id_get(
    ncp_dev_hdl_t devHdl,
    ncp_uint32_t ncaQueueId,
    ncp_uint32_t *pProfileId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    NCP_CHECK(pNcpTaskSwState->ncaQueueState[ncaQueueId].profile != NULL,
            NCP_ST_INVALID_PARAMETER);

    *pProfileId = pNcpTaskSwState->ncaQueueState[ncaQueueId].profile->id;

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_pool_name_get(
    ncp_dev_hdl_t ncpHdl,
    ncp_uint8_t bufferPoolId,
    ncp_task_resource_name_t *name)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    strncpy(name->name,
            pNcpTaskSwState->taskPools[bufferPoolId].name.name,
            sizeof(ncp_task_resource_name_t));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_pool_id_get(
    ncp_dev_hdl_t devHdl,
    ncp_task_resource_name_t *name,
    ncp_uint8_t *bufferPoolId)
{
    ncp_st_t ncpStatus = NCP_ST_TASK_POOL_NOT_FOUND;
    int i;

    for (i = 0; i < NCP_NCAV3_NUM_TASK_MEMORY_POOLS; i++)
    {
        if (strncmp(pNcpTaskSwState->taskPools[i].name.name,
                    name->name,
                    sizeof(ncp_task_resource_name_t)) == 0)
        {
            *bufferPoolId = i;
            ncpStatus = NCP_ST_SUCCESS;
            break;
        }
    }

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_perform_tqs_bind_checks(
    ncp_dev_hdl_t devHdl,
    ncp_uint32_t  tqsId,
    ncp_bool_t    uMode)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_TASK_LOCK_FLAGS(flags);

    if (uMode)
    {
        NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));
    }

    if (pNcpTaskSwState->domainId !=
        pNcpTaskSwState->tqsSwState[tqsId].domainId)
    {
        NCP_CALL(NCP_ST_TASK_QUESET_NOT_IN_LOCAL_DOMAIN);
    }

    if (FALSE == pNcpTaskSwState->tqsSwState[tqsId].configured)
    {
        NCP_CALL(NCP_ST_TASK_TQS_NOT_CONFIGURED);
    }

    if (uMode != pNcpTaskSwState->tqsSwState[tqsId].pAppProfile->baseProfile.uMode)
    {
        NCP_CALL(NCP_ST_TASK_TQS_MODE_CONFLICT);
    }

NCP_RETURN_LABEL

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_set_tqs_configured_state(
    ncp_dev_hdl_t devHdl,
    ncp_uint32_t  tqsId,
    ncp_bool_t    configured)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    /* No lock necessary. This function is called with the resourceLock held
     * in the caller's space (user or kernel), and the other space can't
     * reach this point since TQSes are either user or kernel, but not both.
     */

    pNcpTaskSwState->tqsSwState[tqsId].configured = configured;

NCP_RETURN_LABEL

    return ncpStatus;
}

NCP_API ncp_st_t
ncp_ncav3_tqs_configure(
    ncp_dev_hdl_t devHdl,
    ncp_uint32_t tqsId,
    ncp_task_resource_name_t *tqsName,
    ncp_task_resource_name_t *appProfileName,
    ncp_task_tqs_shared_t *pFlags,
    ncp_uint32_t mqgId,
    ncp_bool_t   uMode)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_tqs_swState_t *tqs = NULL;
    ncp_ncav3_application_profile_t *appProfile;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    ncp_uint32_t *ncapList;
    int numNCAPs;
    ncp_bool_t ncapFound = FALSE;
    int i;
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_ncav3_tqs_configure_entry,
                          NCP_MSG_ENTRY,
                          "devHdl=%p tqsId=%d tqsName=%s "
                          "appProfileName=%s pFlags=%p mqgId=%d uMode=%d"
                          "\n",
                          devHdl, tqsId,
                          (tqsName) ? (tqsName->name) : "(null)",
                          (appProfileName) ? (appProfileName->name) : "(null)",
                          pFlags, mqgId, uMode
        );
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);

    NCP_CALL(ncp_ncav3_get_ncap_id_list(
                myNcpHdl,
                &numNCAPs,
                &ncapList));

    /* Confirm that the requested TQS' NCAP exists. Will always succeed
       on ASIC devices. */
    for (i = 0; i < numNCAPs; i++)
    {
        if ((tqsId / 8) == ncapList[i])
        {
            ncapFound = TRUE;
            break;
        }
    }

    NCP_ASSERT(ncapFound, NCP_ST_TASK_NCAP_DOES_NOT_EXIST);

    /* If calling from the kernel, the lock is already held. */
    if (uMode == TRUE)
    {
        NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));
    }

    tqs = &pNcpTaskSwState->tqsSwState[tqsId];

    /* The TQS must be shut down before it can be configured. */
    NCP_ASSERT(tqs->configured == FALSE, NCP_ST_TASK_TQS_ALREADY_CONFIGURED);

    /* The TQS must be shut down before it can be configured. */
    NCP_ASSERT(tqs->tqsEnabled == TRUE, NCP_ST_TASK_TQS_DISABLED);

    /* Get the TQS's new profile */
    NCP_CALL(ncp_ncav3_get_app_profile_from_name(
        myNcpHdl,
        appProfileName->name,
        &appProfile));

    NCP_ASSERT(appProfile->profileType == CPU_PROFILE,
        NCP_ST_INVALID_PARAMETER);

    /* Check if TQS name is already in use (except by this TQS) */
    for (i = 0; i < NCP_NCAV3_MAX_NUM_TQSETS; i++)
    {
        if (FALSE == pNcpTaskSwState->tqsSwState[i].configured ||
            tqsId == i)
        {
            continue;
        }

        if (0 == strncmp(tqsName->name,
                    pNcpTaskSwState->tqsSwState[i].name.name,
                    sizeof(ncp_task_resource_name_t)))
        {
            NCP_CALL(NCP_ST_TASK_BAD_RESOURCE_NAME);
        }
    }

    strncpy(tqs->name.name,
            tqsName->name,
            sizeof(ncp_task_resource_name_t));

    memcpy(&tqs->shareCtl.shareFlags,
            pFlags,
            sizeof(ncp_task_tqs_shared_t));

    tqs->pAppProfile = appProfile;

    tqs->profileId = appProfile->baseProfile.id;

    /* Set the MQG for ncp_ncav3_tqs_memory_quota_group_get() to use. */
    tqs->mqg = mqgId;

    NCP_CALL(ncp_ncav3_initialize_tqs_control(
                myNcpHdl,
                tqsId,
               &appProfile->baseProfile));

    /* Calling in the kernel relies on the fact that the kernel maintains the
     * iPCQ<->QG mappings.
     */
    NCP_CALL(ncp_ncav3_configure_tqs_hw(
                myNcpHdl,
                myDevHdl,
                tqsId >> 3,
                tqsId % 8,
               &appProfile->baseProfile));

    tqs->configured = TRUE;

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_configure_ok);
    }
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_configure_err);
    }

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_ncav3_tqs_configure_exit,
                          NCP_MSG_EXIT,
                          "ncpStatus=%d\n",
                          ncpStatus);
    return ncpStatus;
}

ncp_st_t
ncp_ncav3_set_tracing_enable(
    ncp_dev_hdl_t dev,
    ncp_bool_t enable)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_aw_trace0_control_r_t r0;
    ncp_aw_trace1_control_r_t r1;

    ncp_memset(&r0, 0, sizeof(r0));
    ncp_memset(&r1, 0, sizeof(r1));

    /* Read-modify-write AW Trace0's control register */
    NCP_CALL(ncp_block_read32(
                dev,
                NCP_REGION_NCAV3_CORE,
                NCP_AW_TRACE0_CONTROL,
                (ncp_uint32_t *) &r0,
                sizeof(r0)/4,
                0));

    r0.enable_trace = enable;

    NCP_CALL(ncp_block_write32(
                dev,
                NCP_REGION_NCAV3_CORE,
                NCP_AW_TRACE0_CONTROL,
                (ncp_uint32_t *) &r0,
                sizeof(r0)/4,
                0));

    /* Read-modify-write AW Trace1's control register */
    NCP_CALL(ncp_block_read32(
                dev,
                NCP_REGION_NCAV3_CORE,
                NCP_AW_TRACE1_CONTROL,
                (ncp_uint32_t *) &r1,
                sizeof(r1)/4,
                0));

    r1.enable_trace = enable;

    NCP_CALL(ncp_block_write32(
                dev,
                NCP_REGION_NCAV3_CORE,
                NCP_AW_TRACE1_CONTROL,
                (ncp_uint32_t *) &r1,
                sizeof(r1)/4,
                0));

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
    ncp_nca_itp_tpd_ram_r_t r0;

    /* Read-modify-write the TPD entry for ncaQueueId */
    NCP_CALL(ncp_block_read32(
                dev,
                NCP_REGION_NCAV3_CORE,
                NCP_NCA_ITP_TPD_RAM(ncaQueueId) +
                    NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                (ncp_uint32_t *) &r0,
                sizeof(r0)/4,
                0));

    r0.traceordered = enable;

    NCP_CALL(ncp_block_write32(
                dev,
                NCP_REGION_NCAV3_CORE,
                NCP_NCA_ITP_TPD_RAM(ncaQueueId) +
                    NCP_NCA_CORE_ITP_ADDR_MAP_BASE,
                (ncp_uint32_t *) &r0,
                sizeof(r0)/4,
                0));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_reset_tracing(
    ncp_dev_hdl_t dev)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_aw_trace0_reset_atm_r_t r0;
    ncp_aw_trace1_reset_atm_r_t r1;

    ncp_memset(&r0, 0, sizeof(r0));
    ncp_memset(&r1, 0, sizeof(r1));

    r0.reset_atm = 1;
    r1.reset_atm = 1;

    /* Reset each AW Trace block then reconfigure them. */
    NCP_CALL(ncp_block_write32(
                dev,
                NCP_REGION_NCAV3_CORE,
                NCP_AW_TRACE0_RESET_ATM,
                (ncp_uint32_t *) &r0,
                sizeof(r0)/4,
                0));

    NCP_CALL(ncp_block_write32(
                dev,
                NCP_REGION_NCAV3_CORE,
                NCP_AW_TRACE1_RESET_ATM,
                (ncp_uint32_t *) &r1,
                sizeof(r1)/4,
                0));

    NCP_CALL(ncp_ncav3_configure_awtrace0(
        ((ncp_t *) myNcpHdl)->ncaHdl,
        dev));

    NCP_CALL(ncp_ncav3_configure_awtrace1(
        ((ncp_t *) myNcpHdl)->ncaHdl,
        dev));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_update_kernel_tqs_state(
    ncp_dev_hdl_t  dev,
    ncp_uint8_t    pgitId,
    ncp_int32_t    profileId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_tqs_swState_t *pTqsSwState;
    ncp_ncav3_application_profile_t *profile;
    ncp_ncav3_hdl_t *nca;
    int i;

    pTqsSwState = &pNcpTaskSwState->tqsSwState[pgitId];

    nca = ((ncp_t *) myNcpHdl)->ncaHdl;

    NCP_CALL(ncp_ncav3_get_app_profile(
        myNcpHdl,
        profileId,
       &profile));

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

    pTqsSwState->pAppProfile = profile;

    pTqsSwState->profileId = profile->baseProfile.id;

    pTqsSwState->configured = TRUE;

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
    ncp_ncav3_application_profile_t *appProfile;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    /* Get the TQS's new profile */
    NCP_CALL(ncp_ncav3_get_app_profile_from_name(
        myNcpHdl,
        appProfileName->name,
        &appProfile));

    poolEnabled[0] = appProfile->baseProfile.cpuPoolMap.enabled;
    poolEnabled[1] = appProfile->baseProfile.fixedPoolMap.enabled;
    poolEnabled[2] = appProfile->baseProfile.sharedPoolMaps[0].poolMap.enabled;
    poolEnabled[3] = appProfile->baseProfile.sharedPoolMaps[1].poolMap.enabled;
    poolEnabled[4] = appProfile->baseProfile.sharedPoolMaps[2].poolMap.enabled;
    poolEnabled[5] = appProfile->baseProfile.sharedPoolMaps[3].poolMap.enabled;
    poolEnabled[6] = appProfile->baseProfile.sharedPoolMaps[4].poolMap.enabled;
    poolEnabled[7] = appProfile->baseProfile.sharedPoolMaps[5].poolMap.enabled;

NCP_RETURN_LABEL

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_get_app_profile_name(
    ncp_dev_hdl_t dev,
    ncp_uint32_t tqsId,
    ncp_task_resource_name_t *appProfileName)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_tqs_swState_t *tqs;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);    
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    /* Get the TQS's profile name */
    tqs = &pNcpTaskSwState->tqsSwState[tqsId];

    NCP_ASSERT(tqs->configured == TRUE, NCP_ST_TASK_TQS_NOT_CONFIGURED);

    strncpy(appProfileName->name,
            tqs->pAppProfile->baseProfile.name.name,
            sizeof(ncp_task_resource_name_t));

NCP_RETURN_LABEL
    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_get_unscheduled_receive_queue_profile_pool_mapping(
    ncp_dev_hdl_t dev,
    ncp_task_resource_name_t *queueProfileName,
    ncp_bool_t poolEnabled[8])
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_nca_queue_profile_t *queueProfile;
    int i;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);    
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    /* Get the TQS's new profile */
    NCP_CALL(ncp_ncav3_get_unscheduled_recv_queue_profile_from_name(
        myNcpHdl,
        queueProfileName->name,
        &queueProfile));

    ncp_memset(poolEnabled, FALSE, 8 * sizeof(ncp_bool_t));

    for (i = 0; i < NCP_NCAV3_NUM_ALLOWED_POOLS; i++)
    {
        ncp_int32_t poolId = queueProfile->allowedPools[i].poolId;

        if (queueProfile->allowedPools[i].enabled)
        {
            NCP_ASSERT(poolId >= 2, NCP_ST_INTERNAL_ERROR);

            if (poolId == 31)
            {
                poolEnabled[1] = TRUE;
            }
            else if (poolId >= 8)
            {
                poolEnabled[0] = TRUE;
            }
            else
            {
                poolEnabled[poolId] = TRUE;
            }
        }
    }

NCP_RETURN_LABEL
    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    return ncpStatus;
}

ncp_st_t
ncp_ncav3_get_unscheduled_receive_queue_profile_name(
    ncp_dev_hdl_t dev,
    ncp_uint32_t queueId,
    ncp_task_resource_name_t *queueProfileName)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_uint32_t profileId;
    ncp_ncav3_unscheduled_queue_config_t *config;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);    
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    profileId = queueId / 256;

    config = &pNcpTaskSwState->nca->configInfo.unscheduledQueueConfig;

    NCP_ASSERT(profileId < config->numProfiles,
        NCP_ST_TASK_UNSCHEDULED_QUEUE_HAS_NO_QUEUE_PROFILE);

    strncpy(queueProfileName->name,
            config->queueProfiles[profileId].name.name,
            sizeof(ncp_task_resource_name_t));

NCP_RETURN_LABEL

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    return ncpStatus;
}
