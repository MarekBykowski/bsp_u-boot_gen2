/**************************************************************************
 **                                                                       *
 **    Copyright (c) 2001-2017, Intel Corporation.                        *
 **                                                                       *
 **************************************************************************/

#define  NCP_TASK_NCA_GLOBALS
#include "ncp_task_basetypes.h"
#include "ncp_task_pvt.h"
//#include "ncp_task_ext.h"
#include "ncp_ncav3_ext.h"
#include "ncp_ncav3_pvt.h"

#if defined(NCP_DEV_SOCKET)
#include "ncp_task_socket.h"
#elif defined(NCP_DEV_FBRS) || defined(NCP_DEV_FBDEV) 
#include "ncp_task_fb.h"
#else
#include "ncp_task_hw.h"
#endif



#if !defined(NCP_DEV_SOCKET) && !defined(NCP_DEV_FBRS) && !defined(NCP_DEV_FBDEV)
#include "ncp_task_inline_funcs.h"
#endif

/* 
 * Export are reuired for kernel entry points
 */
NCP_EXPORT_SYMBOL(ncp_task_shutdown);
NCP_EXPORT_SYMBOL(ncp_task_shutdown_wait);
NCP_EXPORT_SYMBOL(ncp_task_attach);
NCP_EXPORT_SYMBOL(ncp_task_tqs_configure);
NCP_EXPORT_SYMBOL(ncp_task_tqs_shutdown);
NCP_EXPORT_SYMBOL(ncp_task_tqs_configure_flags_get);
NCP_EXPORT_SYMBOL(ncp_task_nca_queue_configure);
NCP_EXPORT_SYMBOL(ncp_task_tqs_bind);
NCP_EXPORT_SYMBOL(ncp_task_tqs_hdl_recover);
NCP_EXPORT_SYMBOL(ncp_task_tqs_unbind);
NCP_EXPORT_SYMBOL(ncp_task_tqs_disable);
NCP_EXPORT_SYMBOL(ncp_task_tqs_enable);
NCP_EXPORT_SYMBOL(ncp_task_nca_queue_disable);
NCP_EXPORT_SYMBOL(ncp_task_nca_queue_enable);
NCP_EXPORT_SYMBOL(ncp_task_rx_queue_flush);
NCP_EXPORT_SYMBOL(ncp_task_tx_queue_flush);
NCP_EXPORT_SYMBOL(ncp_task_send);
NCP_EXPORT_SYMBOL(ncp_task_recv);
NCP_EXPORT_SYMBOL(ncp_task_deferred_consume);
NCP_EXPORT_SYMBOL(ncp_task_complete);
NCP_EXPORT_SYMBOL(ncp_task_unscheduled_queue_push);
NCP_EXPORT_SYMBOL(ncp_task_unscheduled_queue_pop);
NCP_EXPORT_SYMBOL(ncp_task_unscheduled_queue_pop_task);
NCP_EXPORT_SYMBOL(ncp_task_buffer_alloc);
NCP_EXPORT_SYMBOL(ncp_task_buffer_free);
NCP_EXPORT_SYMBOL(ncp_task_free);
NCP_EXPORT_SYMBOL(ncp_task_mmio_buffer_alloc);
NCP_EXPORT_SYMBOL(ncp_task_mmio_buffer_free);
NCP_EXPORT_SYMBOL(ncp_task_buffer_pool_get);
NCP_EXPORT_SYMBOL(ncp_task_buffer_size_get);
NCP_EXPORT_SYMBOL(ncp_task_buffer_size_and_start_get);
NCP_EXPORT_SYMBOL(ncp_task_buffer_refill);
NCP_EXPORT_SYMBOL(ncp_task_refill);
NCP_EXPORT_SYMBOL(ncp_task_quota_transfer);
NCP_EXPORT_SYMBOL(ncp_task_tqs_queue_group_set);
NCP_EXPORT_SYMBOL(ncp_task_tqs_queue_group_get);
NCP_EXPORT_SYMBOL(ncp_task_nca_queue_group_set);
NCP_EXPORT_SYMBOL(ncp_task_queue_group_membership_get);
NCP_EXPORT_SYMBOL(ncp_task_queue_group_name_get);
NCP_EXPORT_SYMBOL(ncp_task_queue_group_add);
NCP_EXPORT_SYMBOL(ncp_task_queue_group_delete);
NCP_EXPORT_SYMBOL(ncp_task_queue_group_modify);
NCP_EXPORT_SYMBOL(ncp_task_tqs_name_get);
NCP_EXPORT_SYMBOL(ncp_task_nca_queue_name_get);
NCP_EXPORT_SYMBOL(ncp_task_queue_group_id_get);
NCP_EXPORT_SYMBOL(ncp_task_tqs_id_get);
NCP_EXPORT_SYMBOL(ncp_task_nca_queue_id_get);
NCP_EXPORT_SYMBOL(ncp_task_nca_queue_profile_name_get);
NCP_EXPORT_SYMBOL(ncp_task_nca_queue_profile_id_get);
NCP_EXPORT_SYMBOL(ncp_task_tqs_cpu_affinity_get);
NCP_EXPORT_SYMBOL(ncp_task_stats_get);
NCP_EXPORT_SYMBOL(ncp_task_global_stats_get);
NCP_EXPORT_SYMBOL(ncp_task_stats_reset);
NCP_EXPORT_SYMBOL(ncp_task_global_stats_reset);
NCP_EXPORT_SYMBOL(ncp_task_set_wait_profile);
NCP_EXPORT_SYMBOL(ncp_task_pool_name_get);
NCP_EXPORT_SYMBOL(ncp_task_pool_id_get);
NCP_EXPORT_SYMBOL(ncp_task_tbr_task_take);
NCP_EXPORT_SYMBOL(ncp_task_tbr_buffer_take);
NCP_EXPORT_SYMBOL(ncp_task_tbr_task_give);
NCP_EXPORT_SYMBOL(ncp_task_tbr_buffer_give);
NCP_EXPORT_SYMBOL(ncp_task_tbr_task_transfer);
NCP_EXPORT_SYMBOL(ncp_task_tbr_buffer_transfer);
NCP_EXPORT_SYMBOL(ncp_task_pid_get);
NCP_EXPORT_SYMBOL(ncp_task_process_name_pid_get);
NCP_EXPORT_SYMBOL(ncp_task_shared_region_virtual_base_get_by_id);
NCP_EXPORT_SYMBOL(ncp_task_shared_region_virtual_base_get_by_name);
NCP_EXPORT_SYMBOL(ncp_task_completion_mode_get);
NCP_EXPORT_SYMBOL(ncp_task_consumption_mode_get);
NCP_EXPORT_SYMBOL(ncp_task_tqs_memory_quota_group_get);
NCP_EXPORT_SYMBOL(ncp_task_app_profile_pool_mapping_get);
NCP_EXPORT_SYMBOL(ncp_task_fixed_pool_virtual_base_get);
NCP_EXPORT_SYMBOL(ncp_task_cpu_pool_mutex_attrib_set);
NCP_EXPORT_SYMBOL(ncp_task_cpu_pool_mutex_attrib_get);
NCP_EXPORT_SYMBOL(ncp_task_tqs_mutex_attrib_set);
NCP_EXPORT_SYMBOL(ncp_task_tqs_mutex_attrib_get);


/* 
 * Internal Functions
 */

NCP_API ncp_st_t
ncp_task_shutdown(
    ncp_uint32_t devNum)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_dev_hdl_t devHdl;


    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_shutdown_entry,
                          NCP_MSG_ENTRY,
                          "devNum=%d\n", devNum);

#ifndef NCP_DEV_SOCKET
    devHdl = NULL;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_CHECK(devNum < NCP_MAX_DEVS, NCP_ST_INVALID_PARAMETER);

    NCP_CALL(ncp_dev_open(devNum, 0, &devHdl));
    NCP_TASK_INITIATE_SHUTDOWN(devHdl);

    /* Unmap the domain bundle */
    ncpTaskDomainBundleMapCnt--;
    if (0 == ncpTaskDomainBundleMapCnt)
    {
        NCP_CALL(NCP_TASK_DOMAIN_BUNDLE_DETACH(myNcpHdl, (void *)pNcpTaskSwState->domainMemMap.domainBundle_VA));

        NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                              ncp_xlf_task_shutdown_domainBundleDeattachOk,
                              NCP_MSG_DEBUG,
                              "DOMAIN_BUNDLE_DEATTACH OK, pDomainBundle = %p\r\n",
                              (void *)pNcpTaskSwState->domainMemMap.domainBundle_VA);
    }

    ncpStatus = ncp_dev_close(devHdl);

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_shutdown_ok);
    }
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_shutdown_err);
        NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                              ncp_xlf_task_shutdown_ncpTaskShutdownFailed,
                              NCP_MSG_ERROR,
                              "ncpTaskShutdown failed. status=%s.\n",
                              ncp_status_get(ncpStatus));
    }

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
#endif
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_shutdown_exit,
                          NCP_MSG_EXIT,
                          "ncpStatus=%d\n",
                          ncpStatus);
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_shutdown_wait(
    ncp_hdl_t ncpHdl)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)    
    
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_shutdown_wait_entry,
                          NCP_MSG_ENTRY,
                          "ncpHdl=%p\n", ncpHdl);

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));


    
     
NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_shutdown_wait_ok);        
    }        
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_shutdown_wait_err);        
    }  
    
    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);    
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_shutdown_wait_exit,
                          NCP_MSG_EXIT,
                          "ncpStatus=%d\n", ncpStatus);
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_attach(
    ncp_t *ncp)
{
    ncp_st_t ncpStatus   = NCP_ST_SUCCESS;
    ncp_ncav3_hdl_t *nca = NULL;
    void *pDomainBundle;  
#ifdef NCP_KERNEL
    ncp_dev_t *dev;
#endif
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_attach_entry,
                          NCP_MSG_ENTRY,
                          "ncp=%p\n", ncp);
    NCP_CHECK((NULL != ncp), NCP_ST_INVALID_PARAMETER);
    
#ifdef NCP_KERNEL  
    /* Is it really necessary to look this up for kmode? */  
    dev     = (ncp_dev_t *)ncp;    
    ncp     = (ncp_t *)ncp_hdls[dev->num];
#endif  

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    nca  = (ncp_ncav3_hdl_t *)ncp->ncaHdl;

    if (NULL == nca)
    {
        /* 
         * Return success if the NCA isn't configured,  so that ncp_config_attach can proceed.
         * This allows the EIOA (and other non-NCA) CLIs to execute without having the NCA configured. 
         */
        NCP_RETURN(NCP_ST_SUCCESS);
    }

    if (NULL == (pNcpTaskSwState = nca->taskSwState))
    {    
            NCP_CALL(NCP_ST_TASK_NO_GSM);
    }
    
    if (0 == ncpTaskDomainBundleMapCnt &&
        0 != pNcpTaskSwState->domainMemMap.domainBundle_VA)
    {     
        NCP_CALL(NCP_TASK_DOMAIN_BUNDLE_ATTACH(ncp, &pDomainBundle)); 

        NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                              ncp_xlf_task_attach_domainBundleAttachOk,
                              NCP_MSG_DEBUG,
                              "DOMAIN_BUNDLE_ATTACH OK, pDomainBundle = %p\r\n",
                              pDomainBundle);
    }
    else
    {
        NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                              ncp_xlf_task_attach_domainBundleAttachSkipped,
                              NCP_MSG_DEBUG,
                              "DOMAIN_BUNDLE_ATTACH SKIPPED,%s curr useCnt=%d\r\n",
                              (ncpTaskDomainBundleMapCnt != 0) ? " already mapped," : "",
                              ncpTaskDomainBundleMapCnt);
    }
    ncpTaskDomainBundleMapCnt++;
    
    myNcpHdl = (ncp_hdl_t *)ncp;
    myDevHdl = ncp_dev_hdls[ncp->id];

    NCP_CALL(ncp_ncav3_map_unscheduled_queues());

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_attach_ok);        
    }        
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_attach_err);        
    }
    
    if (NULL != pNcpTaskSwState)
    {
        NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    }
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_attach_exit,
                          NCP_MSG_EXIT,
                          "ncpStatus=%d\n", ncpStatus);
    return(ncpStatus);
}

#if 0 /* not in header not called */
NCP_API ncp_st_t
ncp_task_detach(
    ncp_t *ncp)
{
    ncp_st_t ncpStatus   = NCP_ST_SUCCESS;
    ncp_ncav3_hdl_t *nca = NULL;  
#ifdef NCP_KERNEL
    ncp_dev_t *dev;
#endif
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)

    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);    
    NCP_CHECK((NULL != ncp), NCP_ST_INVALID_PARAMETER);  
    
#ifdef NCP_KERNEL    
    /* Is this lookup really required? */
    dev     = (ncp_dev_t *)ncp;    
    ncp     = (ncp_t *)ncp_hdls[dev->num];
#endif  

    nca  = ncp->ncaHdl;
    if (NULL == (pNcpTaskSwState = nca->taskSwState))
    {    
            NCP_CALL(NCP_ST_TASK_NO_GSM);
    }

    ncpTaskDomainBundleMapCnt--;
    if (0 == ncpTaskDomainBundleMapCnt)
    {     
        NCP_CALL(NCP_TASK_DOMAIN_BUNDLE_DETACH(ncp, (void *)pNcpTaskSwState->domainMemMap.domainBundle_VA)); 

        NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                              ncp_xlf_task_detach_domainBundleDeattachOk,
                              NCP_MSG_DEBUG,
                              "DOMAIN_BUNDLE_DEATTACH OK, pDomainBundle = %p\r\n",
                              (void *)pNcpTaskSwState->domainMemMap.domainBundle_VA);
    }
    else
    {
        NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                              ncp_xlf_task_detach_domainBundleDeattachSkipped,
                              NCP_MSG_DEBUG,
                              "DOMAIN_BUNDLE_DEATTACH SKIPPED, still in use, new useCnt=%d\r\n",
                              ncpTaskDomainBundleMapCnt);
    }

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_detach_ok);        
    }        
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_detach_err);        
    } 
    
    if (pNcpTaskSwState)
    {
        NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);     
    }
    return(ncpStatus);
}
#endif /* 0 */

NCP_API ncp_st_t
ncp_task_stats_get(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t tqsId,
    ncp_uint32_t bufferSize,
    ncp_task_stats_t *pStats)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_tqs_swState_t *pTqs;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)    
        
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_stats_get_entry,
                          NCP_MSG_ENTRY,
                          "ncpHdl=%p tqsId=%u, bufferSize=%u "
                          "pStats=%p"
                          "\n",
                          ncpHdl, tqsId, bufferSize, pStats);
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK((NULL != pStats), NCP_ST_INVALID_PARAMETER); 
    NCP_CHECK(tqsId < NCP_NCAV3_NUM_CPU_TQSETS, NCP_ST_INVALID_PARAMETER);


                    
    pTqs = &pNcpTaskSwState->tqsSwState[tqsId];

    if (FALSE == pTqs->configured)
    {
        pTqs = NULL;
        NCP_CALL(NCP_ST_TASK_TQS_NOT_CONFIGURED);
    }

    /* Don't access past end of our struct */
    if (bufferSize > sizeof(ncp_task_stats_t))
    {
        bufferSize = sizeof(ncp_task_stats_t);
    }
          
   
    if (pTqs->pAppProfile->baseProfile.uMode == pNcpTaskSwState->uMode)
    {
        /* 
         * copy at most the size passed in by the caller,   regardless of 
         * the real size of the struct.   Provides a level of 
         * binary compatibilty, while also helping to prevent buffer overruns.
         */
        memcpy(pStats, &pTqs->taskStats, bufferSize);
    }    
    else 
    {
        /* TODO - add when kernel mode task I/O implemented */
        NCP_CALL(NCP_ST_NOT_IMPLEMENTED);
    }        

NCP_RETURN_LABEL    

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_stats_get_exit,
                          NCP_MSG_EXIT,
                          "ncpStatus=%d\n",
                          ncpStatus);
    return(ncpStatus);
}        

NCP_API ncp_st_t
ncp_task_stats_reset(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t tqsId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_tqs_swState_t *pTqs;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)    

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_stats_reset_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p tqsId=%u"
                   "\n",
                   ncpHdl, tqsId);
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK(tqsId < NCP_NCAV3_NUM_CPU_TQSETS, NCP_ST_INVALID_PARAMETER);
                
                
    pTqs = &pNcpTaskSwState->tqsSwState[tqsId];

    if (FALSE == pTqs->configured)
    {
        pTqs = NULL;
        NCP_CALL(NCP_ST_TASK_TQS_NOT_CONFIGURED);
    }

    if (pTqs->pAppProfile->baseProfile.uMode == pNcpTaskSwState->uMode)
    {
        memset(&pTqs->taskStats, 0, sizeof(ncp_task_stats_t));
    }    
    else 
    {
        /* TODO - add when kernel mode task I/O implemented */
        NCP_CALL(NCP_ST_NOT_IMPLEMENTED);
    }        
    
NCP_RETURN_LABEL

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_stats_reset_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "\n",
                   ncpStatus);
    return(ncpStatus);
}    

NCP_API ncp_st_t
ncp_task_global_stats_get(
    ncp_hdl_t ncpHdl,
    ncp_task_execution_modes_t mode,
    ncp_uint32_t bufferSize,
    ncp_task_global_stats_t *pStats)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)    

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_global_stats_get_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p mode=%d bufferSize=%u pStats=%p"
                   "\n",
                   ncpHdl, mode, bufferSize, pStats
        );

    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);    
    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK((NULL != pStats), NCP_ST_INVALID_PARAMETER); 

    /* Don't access past end of our struct */
    if (bufferSize > sizeof(ncp_task_global_stats_t))
    {
        bufferSize = sizeof(ncp_task_global_stats_t);
    }
    
          
   
    /* 
     * copy at most the size passed in by the caller,   regardless of 
     * the real size of the struct.   Provides a level of 
     * binary compatibilty, while also helping to prevent buffer overruns.
     */
    if (NCP_TASK_STATS_MODE_USER == mode)
    {       
        memcpy(pStats, &pNcpTaskSwState->taskStats, bufferSize);
    }  
    else if (NCP_TASK_STATS_MODE_KERNEL == mode)
    {
        NCP_CALL(NCP_ST_NOT_IMPLEMENTED);
    }
    else
    {
        NCP_CALL(NCP_ST_INVALID_PARAMETER);
    }            

NCP_RETURN_LABEL 

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_global_stats_get_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "\n",
                   ncpStatus

        );
    return(ncpStatus);
}        

NCP_API ncp_st_t
ncp_task_global_stats_reset(
    ncp_hdl_t ncpHdl,
    ncp_task_execution_modes_t mode)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_global_stats_reset_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p mode=%d"
                   "\n",
                   ncpHdl, mode);
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));

        
    if (NCP_TASK_STATS_MODE_USER == mode)
    {    
        memset(&pNcpTaskSwState->taskStats, 0, sizeof(ncp_task_global_stats_t));
    }
    else if (NCP_TASK_STATS_MODE_KERNEL == mode)
    {
        NCP_CALL(NCP_ST_NOT_IMPLEMENTED);
    }
    else
    {
        NCP_CALL(NCP_ST_INVALID_PARAMETER);
    }                
            
    
NCP_RETURN_LABEL

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_global_stats_reset_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "\n",
                   ncpStatus

        );
    return(ncpStatus);
} 

NCP_API ncp_st_t
ncp_task_tqs_configure(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t tqsId,
    ncp_task_resource_name_t *tqsName,
    ncp_task_resource_name_t *appProfileName,
    ncp_task_tqs_shared_t *pFlags,
    ncp_uint32_t mqgId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_application_profile_t *appProfile;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    ncp_bool_t kernelConfigureFlagSet = FALSE;
    ncp_t *ncp;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tqs_configure_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p tqsId=%u tqsName=%s appProfileName=%s "
                   "pFlags=%p{sharedRxQueue=%u "
                   "sharedTxQueue0=%u "
                   "sharedTxQueue1=%u} "
                   "mqgId=%u"
                   "\n",
                   ncpHdl, tqsId,
                   ((tqsName) ? (tqsName->name) : "(null)"),
                   ((appProfileName) ? (appProfileName->name) : "(null)"),
                   pFlags,
                   (pFlags) ? (pFlags->sharedRxQueue) : 0,
                   (pFlags) ? (pFlags->sharedTxQueue0) : 0,
                   (pFlags) ? (pFlags->sharedTxQueue1) : 0,
                   mqgId
        );
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CHECK(tqsId < NCP_NCAV3_NUM_CPU_TQSETS, NCP_ST_INVALID_PARAMETER);
    NCP_CHECK(mqgId < NCP_NCAV3_NUM_MEMORY_QUOTA_GROUPS,
        NCP_ST_INVALID_PARAMETER);
    NCP_CHECK((NULL != pFlags), NCP_ST_INVALID_PARAMETER);

    /* Validate supplied name */
    NCP_CHECK((NULL != appProfileName), NCP_ST_INVALID_PARAMETER);
    NCP_TASK_VALIDATE_RESOURCE_NAME(appProfileName,
        NCP_ST_TASK_BAD_RESOURCE_NAME);

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    ncp = (ncp_t *) ncpHdl;

    /* Get the TQS's new profile */
    NCP_CALL(ncp_ncav3_get_app_profile_from_name(
        ncp,
        appProfileName->name,
        &appProfile));

    NCP_ASSERT(appProfile->profileType == CPU_PROFILE,
        NCP_ST_INVALID_PARAMETER);

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    NCP_ASSERT(appProfile->baseProfile.uMode == pNcpTaskSwState->uMode,
        NCP_ST_TASK_TQS_MODE_CONFLICT);

    /* Perform validation checks and do the hardware configuration in the
     * kernel. */
    NCP_CALL(ncp_ncav3_tqs_configure(
        myDevHdl,
        tqsId,
        tqsName,
        appProfileName,
        pFlags,
        mqgId,
        pNcpTaskSwState->uMode));

    kernelConfigureFlagSet = TRUE;

    /* Kernel-portion of the configure succeeded. Now, set the task I/O state
     * in the caller's space (user or kernel). */

    /* The taskIoResourceLock protects concurrent execution from threads in the
     * same user/kernel space. But what if this code runs in user/kernel space
     * while a kernel/user thread calls ncp_ncav3_tqs_configure()? That's ok.
     * ncp_ncav3_tqs_configure() will fail for the second caller, because the
     * TQS is already configured.
     */

    /* Update TQS s/w state associated with the profile and sharing flags */
    NCP_CALL(ncp_ncav3_init_tqs_configuration_state(
                (ncp_ncav3_hdl_t *) ((ncp_t *) myNcpHdl)->ncaHdl,
                tqsId,
                appProfile,
                pFlags,
                TRUE));

    /* Initialize the rest of the TQS s/w state (PCQ state, etc.) */
    NCP_CALL(ncp_task_initialize_tqs_state(myNcpHdl, tqsId));

    /* After initializing TQS state, perDomainPoolsMask may contain a new pool,
     * so re-run initalize TBR arrays in case. */
    NCP_TASK_INITIALIZE_TBR_ARRAYS();

    /* If the function reached this point, the kernel-maintained tqsEnabled
     * was TRUE. So, propagate that value to the user-maintained copy. */
    pNcpTaskSwState->tqsSwState[tqsId].tqsEnabled = TRUE;

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_configure_ok);
    }
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_configure_err);

        if (kernelConfigureFlagSet)
        {
            /* Reset the kernel copy of 'configured' */
            NCP_CLEANUP_CALL(   ncp_ncav3_set_tqs_configured_state(
                                myDevHdl,
                                tqsId,
                                FALSE)  );

            /* Reset the user copy of 'configured' */
            pNcpTaskSwState->tqsSwState[tqsId].configured = FALSE;
        }
    }

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tqs_configure_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "\n",
                   ncpStatus
        );
    return ncpStatus;
}
 
NCP_API ncp_st_t
ncp_task_tqs_configure_flags_get(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t tqsId,
    ncp_task_tqs_shared_t *pFlags)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tqs_configure_flags_get_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p tqsId=%u pFlags=%p"
                   "\n",
                   ncpHdl, tqsId, pFlags);
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK((NULL != pFlags), NCP_ST_INVALID_PARAMETER);
    NCP_CHECK(tqsId < NCP_NCAV3_NUM_CPU_TQSETS, NCP_ST_INVALID_PARAMETER);

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    NCP_CALL(ncp_ncav3_tqs_configure_flags_get(myDevHdl, tqsId, pFlags));

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_configure_flags_get_ok);
    }
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_configure_flags_get_err);
    }

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tqs_configure_flags_get_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "pFlags=%p{sharedRxQueue=%u "
                   "sharedTxQueue0=%u "
                   "sharedTxQueue1=%u} "
                   "\n",
                   ncpStatus,
                   pFlags,
                   (pFlags) ? (pFlags->sharedRxQueue) : 0,
                   (pFlags) ? (pFlags->sharedTxQueue0) : 0,
                   (pFlags) ? (pFlags->sharedTxQueue1) : 0
        );
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_tqs_memory_quota_group_get(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t tqsId,
    ncp_uint32_t *pMemoryQuotaGroupId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_tqs_memory_quota_group_get_entry,
                          NCP_MSG_ENTRY,
                          "ncpHdl=%p tqsId=%u pMemoryQuotaGroupId=%p"
                          "\n",
                          ncpHdl, tqsId, pMemoryQuotaGroupId);
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK((NULL != pMemoryQuotaGroupId), NCP_ST_INVALID_PARAMETER);
    NCP_CHECK(tqsId < NCP_NCAV3_NUM_CPU_TQSETS, NCP_ST_INVALID_PARAMETER);

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    NCP_CALL(ncp_ncav3_tqs_memory_quota_group_get(
        myDevHdl,
        tqsId,
        pMemoryQuotaGroupId));

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_configure_flags_get_ok);
    }
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_configure_flags_get_err);
    }

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_tqsk_tqs_memory_quota_group_get_exit,
                          NCP_MSG_EXIT,
                          "ncpStatus=%d pMemoryQuotaGroupId=%p(%u)"
                          "\n",
                          ncpStatus,
                          pMemoryQuotaGroupId,
                          (pMemoryQuotaGroupId) ? *pMemoryQuotaGroupId : 0);
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_nca_queue_configure(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t ncaQueueId,
    ncp_task_resource_name_t *queueName,
    ncp_task_resource_name_t *queueProfileName,
    ncp_int32_t queueGroupId,
    ncp_uint32_t paramsSize,
    ncp_task_nca_queue_sched_params_t *params)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)
    ncp_dev_hdl_t dev;

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_xlf_task_nca_queue_configure_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p ncaQueueId=%u queueName=%s queueProfileName=%s "
                   "queueGroupId=%d paramsSize=%u params=%p"
                   "\n",
                   ncpHdl, ncaQueueId, queueName ? queueName->name : "(null)",
                   queueProfileName ? queueProfileName->name : "(null)",
                   queueGroupId, paramsSize, params
        );

    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK(ncaQueueId < NCP_NCAV3_MAX_NUM_NCAQS, NCP_ST_INVALID_PARAMETER);
    NCP_CHECK(queueName != NULL, NCP_ST_INVALID_PARAMETER);

    dev = ncp_dev_hdls[((ncp_t *) ncpHdl)->id];

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    NCP_CALL(ncp_ncav3_nca_queue_configure(
        dev,
        ncaQueueId,
        queueName,
        queueProfileName,
        queueGroupId,
        paramsSize,
        params));

NCP_RETURN_LABEL

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
                   ncp_xlf_task_nca_queue_configure_exit, NCP_MSG_EXIT,
                   "ncpStatus=%d\n", ncpStatus);
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_tqs_bind(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t tqsId,
    ncp_task_tqs_usage_t *pParams,
    ncp_task_resource_name_t *processName,
    ncp_task_resource_name_t *threadName,
    ncp_task_tqs_hdl_t *pTqsHdl)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = NULL;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    ncp_bool_t pidInitDone=FALSE;
    ncp_bool_t tqsAttachDone=FALSE;
    ncp_task_process_info_t *pProcess = NULL;
    ncp_pid_t  myPid = ncp_get_pid();
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_xlf_task_tqs_bind_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p tqsId=%u pParams=%p processName=%s threadName=%s pTqsHdl=%p"
                   "\n",
                   ncpHdl, tqsId, pParams,
                   ((processName) ? (processName->name) : "(null)"),
                   ((threadName) ? (threadName->name) : "(null)"),
                   pTqsHdl);
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK(tqsId < NCP_NCAV3_NUM_CPU_TQSETS, NCP_ST_INVALID_PARAMETER);
    NCP_CHECK((NULL != pParams), NCP_ST_INVALID_PARAMETER);
    NCP_CHECK((NULL != pTqsHdl), NCP_ST_INVALID_PARAMETER);

    /* Validate supplied name */
    NCP_TASK_VALIDATE_RESOURCE_NAME(processName, NCP_ST_TASK_BAD_RESOURCE_NAME);
    NCP_TASK_VALIDATE_RESOURCE_NAME(threadName, NCP_ST_TASK_BAD_RESOURCE_NAME);

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    if (pNcpTaskSwState->domainId !=
        pNcpTaskSwState->tqsSwState[tqsId].domainId)
    {
        NCP_CALL(NCP_ST_TASK_QUESET_NOT_IN_LOCAL_DOMAIN);
    }

    /* If configured is true, the other tqsSwState variables are valid for
     * the caller's mode. */
    if (FALSE == pNcpTaskSwState->tqsSwState[tqsId].configured)
    {
        NCP_CALL(NCP_ST_TASK_TQS_NOT_CONFIGURED);
    }

    if (pNcpTaskSwState->uMode !=
        pNcpTaskSwState->tqsSwState[tqsId].pAppProfile->baseProfile.uMode)
    {
        NCP_CALL(NCP_ST_TASK_TQS_MODE_CONFLICT);
    }

    if (FALSE == pNcpTaskSwState->tqsSwState[tqsId].tqsEnabled)
    {
        NCP_CALL(NCP_ST_TASK_TQS_DISABLED);
    }

    if (NCP_MUTEX_PROCESS_PRIVATE == pNcpTaskSwState->tqsSwState[tqsId].mtxAttr.attr &&
        pNcpTaskSwState->tqsSwState[tqsId].mtxAttr.pid != myPid)
    {
        NCP_RETURN(NCP_ST_TASK_PID_MISMATCH);
    }
    /*
     * Be optimistic that the tqs handle does not need to be recovered,
     * i.e. that app is not restarting and TBR is ON.
     */
/*TODO*/
    NCP_CALL(ncp_nvm_robust_malloc(sizeof(ncp_task_pvt_tqsHdl_data_t),
                                   (void **)&pvtTqsHdl, 
                                   NCP_DO_MEMSET));

    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);

    NCP_CALL(ncp_task_add_thread(pvtTqsHdl, processName, threadName, tqsId, &pProcess));
    pidInitDone = TRUE;

    /* Bind to tqs, validating shared flags and usage */

    NCP_CALL(ncp_task_attach_tqs(ncpHdl, pvtTqsHdl, tqsId, pParams));
    tqsAttachDone = TRUE;

    NCP_CALL(ncp_task_init_wait_profile(pvtTqsHdl));

    /*
     * TASK SEND 
     */
    pvtTqsHdl->taskSendDefaultCmdBits.u.opcqDword[1]           = 0; /* zero init flags portion of entry */
    pvtTqsHdl->taskSendDefaultCmdBits.u.opcqEntry.cmd          = NCP_NCAV3_CMD_SENDTH;
    pvtTqsHdl->taskSendDefaultCmdBits.u.opcqEntry.interruptEn  = 1;
    
    /*
     * TASK BUFFER FREE
     */
    pvtTqsHdl->taskBufferFreeDefaultCmdBits.u.opcqDword[1]  = 0; /* zero init flags portion of entry */
    pvtTqsHdl->taskBufferFreeDefaultCmdBits.u.opcqEntry.cmd =  NCP_NCAV3_CMD_ADPAE;
    pvtTqsHdl->taskBufferFreeDefaultCmdBits.u.opcqEntry.interruptEn = 1;
    pvtTqsHdl->taskBufferFreeDefaultCmdBits.u.opcqEntry.flowControlDisabled = 0;
    pvtTqsHdl->taskBufferFreeDefaultCmdBits.u.opcqEntry.headerPoolMref = 0; /* note: mref is a don't care for CPU pools */
    pvtTqsHdl->taskBufferFreeDefaultCmdBits.u.opcqEntry.headerPool = 0;
    pvtTqsHdl->taskBufferFreeDefaultCmdBits.u.opcqEntry.returnHeader  = NCP_NCAV3_ADPAE_RCCH_NOOP;
    pvtTqsHdl->taskBufferFreeDefaultCmdBits.u.opcqEntry.returnData    = NCP_NCAV3_ADPAE_RCCD_DEC_REFCNT;
    pvtTqsHdl->taskBufferFreeDefaultCmdBits.u.opcqEntry.quotaTransfer = NCP_NCAV3_ADPAE_MQGC_DEC_SOURCE;        

    /*
     * TASK FREE
     */
     
    pvtTqsHdl->taskFreeDefaultCmdBits.u.opcqDword[1]  = 0; /* zero init flags portion of entry */     
    pvtTqsHdl->taskFreeDefaultCmdBits.u.opcqEntry.cmd = NCP_NCAV3_CMD_ADPAH;
    pvtTqsHdl->taskFreeDefaultCmdBits.u.opcqEntry.interruptEn = 1;
    /* pvtTqsHdl->taskFreeDefaultCmdBits.u.opcqEntry.flowControlDisabled = 0; */    /* already zero */
    /* entry.quotaIncludeHeader    = NCP_NCAV3_ADPAH_MQGI_INCL_HDR; */              /* already zero */
    pvtTqsHdl->taskFreeDefaultCmdBits.u.opcqEntry.returnData     = NCP_NCAV3_ADPAH_RCCD_DEC_REFCNT;
    pvtTqsHdl->taskFreeDefaultCmdBits.u.opcqEntry.quotaTransfer  = NCP_NCAV3_ADPAH_MQGC_DEC_SOURCE;    
     
    /* 
     * TASK COMPLETE
     */
     
    pvtTqsHdl->taskCompleteDefaultCmdBits.u.opcqDword[1]  = 0; /* zero init flags portion of entry */     
    pvtTqsHdl->taskCompleteDefaultCmdBits.u.opcqEntry.cmd = NCP_NCAV3_CMD_NOOP;     
    pvtTqsHdl->taskCompleteDefaultCmdBits.u.opcqEntry.taskCompletion = 1;
    pvtTqsHdl->taskCompleteDefaultCmdBits.u.opcqEntry.interruptEn = 1;
    /* pvtTqsHdl->taskCompleteDefaultCmdBits.u.opcqEntry.flowControlDisabled = 0; */ /* already zero */
    
     
    /* Supply NCA buffers if this is the first user of a CPU pool. */
    if (pNcpTaskSwState->tqsSwState[tqsId].tqsUseCnt == 1)
    {
        NCP_CALL(ncp_ncav3_supply_nca_buffers((ncp_t *) ncpHdl, pvtTqsHdl));
    }

NCP_RETURN_LABEL
    if (NCP_ST_SUCCESS == ncpStatus)
    {
        /* Add to list of active tqs handles */
        pvtTqsHdl->nextTqsHdl = pNcpTaskSwState->activeTqsHdls;
        pNcpTaskSwState->activeTqsHdls = pvtTqsHdl;

        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs,  api_task_tqs_hdl_bind_ok);
        *pTqsHdl = (ncp_task_tqs_hdl_t *)pvtTqsHdl;
    }
    else
    {
        if (pvtTqsHdl)
        {
            NCP_TASK_INC_ERROR_STAT_VIA_PTQS(&pNcpTaskSwState->tqsSwState[tqsId],
                                             api_task_tqs_hdl_bind_err);
        }
        else
        {
            NCP_TASK_INC_GLOBAL_STAT(api_task_tqs_hdl_bind_err);
        }
        if (pidInitDone)
        {
            /*TODO*/
            NCP_CLEANUP_CALL(ncp_task_delete_thread(pvtTqsHdl, threadName));
        }
        if (tqsAttachDone)
        {
            ncp_task_detach_tqs(pvtTqsHdl);
        }
        if (pvtTqsHdl)
        {
            NCP_CLEANUP_MUTEX_CALL(ncp_nvm_robust_free((void **)&(pvtTqsHdl)));
            pvtTqsHdl = NULL;
        }
        *pTqsHdl = NULL; /* return null tqs handle */

        /*
         * If process restart and TBR enabled,   then attempt to recover resources.
         *
         * Application responsibilities include:
         * 1) if TQS_DISABLED,   then free any buffers, and unbind (if currently bound)
         * 2) repeatedly call ncp_task_tqs_bind(),  performing a small delay in between attempts,
         *    until RTE reenables TQS,   at which time bind will succeed if same parameters were used
         *    as in thread's initial bind.
         *
         * RTE will reenable all TQSets only after last client performs its unbind.
         * RTE will recover all buffers.
         * RTE will issue completions, if necessary.
         * RTE will perform NCA RX buffer refills, if necessary
         */


        if (ncpStatus == NCP_ST_TASK_PROCESS_RESTART_DETECTED)
        {
            /* Temporarily set this threads crit sec count to zero */
            NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
            NCP_TASK_TBR_INITIATE_RECOVERY(pProcess, &ncpStatus);
            NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
        }

    }

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));
    
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_xlf_task_tqs_bind_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d pTqsHdl=%p(%p)"
                   "\n",
                   ncpStatus, pTqsHdl, ((pTqsHdl) ? (*pTqsHdl) : 0));
    return(ncpStatus);
}

ncp_st_t
ncp_task_tqs_hdl_recover(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t tqsId,
    ncp_task_tqs_usage_t *pParams,
    ncp_task_resource_name_t *processName,
    ncp_task_resource_name_t *threadName,    
    ncp_task_tqs_hdl_t *pTqsHdl)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = NULL;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)    
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tqs_hdl_recover_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p tqsId=%u "
                   "pParams=%p{useRxQueue=%u "
                   "useTxQueue0=%u "
                   "useTxQueue1=%u} "
                   "processName=%s threadName=%s pTqsHdl=%p"
                   "\n",
                   ncpHdl, tqsId, pParams,
                   (pParams) ? (pParams->useRxQueue) : 0,
                   (pParams) ? (pParams->useTxQueue0) : 0,
                   (pParams) ? (pParams->useTxQueue1) : 0,
                   ((processName) ? (processName->name) : "(null)"),
                   ((threadName) ? (threadName->name) : "(null)"),
                   pTqsHdl);
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);    
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));  
    NCP_CHECK(tqsId < NCP_NCAV3_NUM_CPU_TQSETS, NCP_ST_INVALID_PARAMETER);
    NCP_CHECK((NULL != pParams), NCP_ST_INVALID_PARAMETER);
    NCP_CHECK((NULL != pTqsHdl), NCP_ST_INVALID_PARAMETER);    
                    
    /* Validate supplied name */ 
    NCP_TASK_VALIDATE_RESOURCE_NAME(processName, NCP_ST_TASK_BAD_RESOURCE_NAME);               
    NCP_TASK_VALIDATE_RESOURCE_NAME(threadName, NCP_ST_TASK_BAD_RESOURCE_NAME);     

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    
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

    if (pNcpTaskSwState->uMode !=
        pNcpTaskSwState->tqsSwState[tqsId].pAppProfile->baseProfile.uMode)  
    {
        NCP_CALL(NCP_ST_TASK_TQS_MODE_CONFLICT);
    }    
     
    if (FALSE == pNcpTaskSwState->tqsSwState[tqsId].tqsEnabled)
    {
        NCP_CALL(NCP_ST_TASK_TQS_DISABLED);
    }   
    
    NCP_CALL(ncp_task_recover_tqs_hdl_by_thread(processName, threadName, tqsId, &pvtTqsHdl));
    if (FALSE == NCP_NCA_TEST_CRITICAL_SECTION(pvtTqsHdl->inCriticalSection, 0))
    {
        NCP_CALL(NCP_ST_TASK_PROCESS_IN_CRITICAL_SECTION);
    }
                    
NCP_RETURN_LABEL    
    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs,  api_task_tqs_hdl_recover_ok);        
        if (NCP_MUTEX_PROCESS_PRIVATE == pNcpTaskSwState->tqsSwState[tqsId].mtxAttr.attr)
        {
            NCP_CLEANUP_CALL(ncp_task_tqs_cleanup_locks(tqsId));
        }
        *pTqsHdl = (ncp_task_tqs_hdl_t *)pvtTqsHdl;
    }  
    else
    {
        if (pvtTqsHdl)
        {   
            NCP_TASK_INC_ERROR_STAT_VIA_PTQS(&pNcpTaskSwState->tqsSwState[tqsId],
                                             api_task_tqs_hdl_recover_err); 
        }
        else
        {
            NCP_TASK_INC_GLOBAL_STAT(api_task_tqs_hdl_recover_err);    
        } 
                   
        *pTqsHdl = NULL; /* return null tqs handle */
        
    }  

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));          
    
    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tqs_hdl_recover_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d pTqsHdl=%p(%p)"
                   "\n",
                   ncpStatus, pTqsHdl, (pTqsHdl) ? (*pTqsHdl) : 0);
    return(ncpStatus);    
}        

NCP_API ncp_st_t
ncp_task_tqs_unbind(
    ncp_task_tqs_hdl_t tqsHdl)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t * )tqsHdl;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_xlf_task_tqs_unbind_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p"
                   "\n",
                   tqsHdl
        );

    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    /*
     * Flush the oPCQ(s) to issue any outstanding send done callbacks.
     * App must free buffers in order to avoid a memmory leak.
     */

    if (pvtTqsHdl->useFlags.useTxQueue[0])
    {
        NCP_CALL(ncp_task_tx_queue_flush(tqsHdl, 0));
    }

    if (pvtTqsHdl->useFlags.useTxQueue[1])
    {
        NCP_CALL(ncp_task_tx_queue_flush(tqsHdl, 1));
    }

    /* Unbind. Clean up TQS software state if tqsUseCnt is 0. */
    NCP_CALL(ncp_task_internal_tqs_unbind(pvtTqsHdl,
                                          FALSE, /* NOT in recovery */
                                          TRUE));

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {

        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs,  api_task_tqs_hdl_unbind_ok);
        /*
         * Nuke cookie in callers task handle.
         * Otherwise we can't necessarily detect a bad (already freed) handle
         */
        pvtTqsHdl->cookie = 0xDEADD00D;
        NCP_CLEANUP_CALL( ncp_nvm_robust_free((void **)&(pvtTqsHdl)));
        pvtTqsHdl = NULL;
    }
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,   api_task_tqs_hdl_unbind_err);
    }

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca, ncp_xlf_task_tqs_unbind_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d\n",
                   ncpStatus
        );
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_tqs_shutdown(
    ncp_hdl_t    ncpHdl,
    ncp_uint32_t tqsId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = NULL;
    ncp_task_resource_name_t internalThreadName = {"__rteShutdownThread__"};
    ncp_task_resource_name_t internalProcessName = {"__rteShutdownProcess__"};
    ncp_bool_t addThreadDone = FALSE;
    ncp_bool_t tqsAttachDone = FALSE;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    int i;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tqs_shutdown_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p tqsId=%u"
                   "\n",
                   ncpHdl, tqsId);
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    NCP_ASSERT(pNcpTaskSwState->tqsSwState[tqsId].tqsUseCnt == 0,
        NCP_ST_TASK_NONZERO_USE_COUNT);

    /* Check that TQS is configured. If not, return success. Also check
     * that TQS uMode matches caller's, and if not return an error. */
    ncpStatus = ncp_ncav3_perform_tqs_bind_checks(
        myDevHdl,
        tqsId,
        pNcpTaskSwState->uMode);

    if (ncpStatus == NCP_ST_TASK_TQS_NOT_CONFIGURED)
    {
        NCP_RETURN(NCP_ST_SUCCESS);
    }
    else if (ncpStatus != NCP_ST_SUCCESS)
    {
        NCP_CALL(ncpStatus);
    }

    /* Check that the TQS isn't the last consumer of an enabled NCA queue. */
    /* (Must be done in the kernel, since it maintains the queue state) */
    for (i = 0; i < NCP_NCAV3_NUM_QUEUE_GROUPS_PER_IPCQ; i++)
    {
        NCP_CALL(ncp_ncav3_check_queue_group_for_orphaned_queues(
            myDevHdl,
            tqsId,
            i,
            pNcpTaskSwState->uMode));
    }

    /*
     * Bind the TQS for ncp_ncav3_task_pgit_offline(). For user-mode TQSes, no
     * need to check kernel state, because kernel-mode threads couldn't have
     * reconfigured the TQS without the user-mode thread already having called
     * this function.
     */
    {
        ncp_task_tqs_usage_t params;
        ncp_task_process_info_t *pProcess;
        int poolId;

        params.useRxQueue  = TRUE;
        params.useTxQueue0 = TRUE;
        params.useTxQueue1 = TRUE;

        for (poolId = NCP_NCAV3_FIRST_SHARED_POOL_ID; 
             poolId < NCP_NCAV3_MAX_SHARED_POOLS; 
             poolId++)
        {
            params.useAllocator[poolId] = (1 == (pNcpTaskSwState->tqsSwState[tqsId].validPoolsMask & (1<<poolId)));
        }

        /* If this process is already in the activeProcesses list, we need
            to use its processName. */
        pProcess = pNcpTaskSwState->activeProcesses;
        while (pProcess != NULL)
        {
            ncpStatus = ncp_task_os_pid_match_check(
                    pProcess,
                    TRUE,
                    NCP_ST_ERROR);

            if (ncpStatus == NCP_ST_SUCCESS)
            {
                break;
            }
        }
/*TODO*/
        NCP_CALL(ncp_nvm_robust_malloc(sizeof(ncp_task_pvt_tqsHdl_data_t),
                                      (void **)&pvtTqsHdl, 
                                      NCP_DO_MEMSET));

        NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);

        /* Add the thread so we can attach the TQS */
        if (pProcess == NULL)
        {
            NCP_CALL(ncp_task_add_thread(
                        pvtTqsHdl,
                       &internalProcessName,
                       &internalThreadName,
                        tqsId,
                       &pProcess));
        }
        else
        {
            NCP_CALL(ncp_task_add_thread(
                        pvtTqsHdl,
                       &pProcess->clientProcess,
                       &internalThreadName,
                        tqsId,
                       &pProcess));
        }

        addThreadDone = TRUE;

        /* Bind to tqs, validating shared flags and usage */
        NCP_CALL(ncp_task_attach_tqs(ncpHdl, pvtTqsHdl, tqsId, &params));
        tqsAttachDone = TRUE;

        /* Add to list of active tqs handles */
        pvtTqsHdl->nextTqsHdl = pNcpTaskSwState->activeTqsHdls;
        pNcpTaskSwState->activeTqsHdls = pvtTqsHdl;

        NCP_CALL(ncp_task_init_wait_profile(pvtTqsHdl));
    }

    /* Take the PCQ group offline. */
    {
        int ncapId, relTqsId;
        ncp_bool_t useTxQueue;
        ncp_bool_t useRxQueue;

        ncapId = pvtTqsHdl->tqsId >> 3;
        relTqsId = pvtTqsHdl->tqsId % 8;

        /* Override the previous usage value so we can flush the iPCQ and free
         * memory through TXQ0. Doesn't matter if they're shared or exclusive,
         * since no other thread is using this TQS.
         */
        useTxQueue = pvtTqsHdl->useFlags.useTxQueue[0];
        useRxQueue = pvtTqsHdl->useFlags.useRxQueue;

        pvtTqsHdl->useFlags.useTxQueue[0] = TRUE;
        pvtTqsHdl->useFlags.useRxQueue    = TRUE;

        /* Since TQS unbind takes the PGIT offline, some NCA queues may not have
         * any iPCQs to feed, and internal NCA memory will fill. For now, allow
         * this. Assumption is user will re-bind soon.
         */

        NCP_CALL(ncp_ncav3_take_pgit_offline(
                    (ncp_task_tqs_hdl_t *) pvtTqsHdl,
                    myDevHdl,
                    ncapId,
                    relTqsId,
                    pvtTqsHdl->tqsId));

        NCP_CALL(ncp_ncav3_init_pgit_monitor_grp_indexes(
                    myDevHdl,
                    ncapId,
                    relTqsId));

        NCP_CALL(ncp_ncav3_reset_pgit_indexes(
                    myNcpHdl,
                    (ncp_ncav3_hdl_t *) ((ncp_t *) myNcpHdl)->ncaHdl,
                    tqsId));

        pvtTqsHdl->useFlags.useTxQueue[0] = useTxQueue;
        pvtTqsHdl->useFlags.useRxQueue    = useRxQueue;
    }

    /* Unbind and clean up TQS software state. */
    NCP_CALL(ncp_task_internal_tqs_unbind(pvtTqsHdl,
                                          FALSE, /* NOT in recovery */
                                          FALSE));
    tqsAttachDone = FALSE;

    NCP_CALL(ncp_task_delete_thread(pvtTqsHdl, &internalThreadName));
    addThreadDone = FALSE;

    if (pvtTqsHdl->cpuPoolHdl)
    {
        NCP_TASK_TBR_REMOVE_FROM_CPUPOOL_TQS_LIST(pvtTqsHdl);
    }

    /* Free all of the TQS' memory. It will be re-allocated the next time the
     * TQS is configured. */
    NCP_CALL(ncp_ncav3_free_tqs_state(pvtTqsHdl->tqsId));

    /* Set the local copy of configured, to prevent bind from succeeding. */
    pNcpTaskSwState->tqsSwState[tqsId].configured = FALSE;

    /* Set the kernel copy of configured, to allow tqs_configure to succeed */
    NCP_CALL(ncp_ncav3_set_tqs_configured_state(
        myDevHdl,
        tqsId,
        FALSE));

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        if (NULL != pvtTqsHdl)
        {
            NCP_TASK_INC_STAT(pvtTqsHdl->pTqs,  api_task_tqs_shutdown_ok);
            /*
             * Nuke cookie in callers task handle.
             * Otherwise we can't necessarily detect a bad (already freed) handle.
             */
            pvtTqsHdl->cookie = 0xDEADD00D;
            NCP_CLEANUP_CALL( ncp_nvm_robust_free((void **)&(pvtTqsHdl)));
            pvtTqsHdl = NULL;
        }
    }
    else
    {
        if (tqsAttachDone)
        {
            ncp_task_detach_tqs(pvtTqsHdl);
        }

        if (addThreadDone)
        {
            ncp_task_delete_thread(pvtTqsHdl, &internalThreadName);
        }

        if (pvtTqsHdl)
        {
            NCP_CLEANUP_CALL( ncp_nvm_robust_free((void **)&(pvtTqsHdl)));
            pvtTqsHdl = NULL;
        }
    }

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_xlf_task_tqs_shutdown_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "\n",
                   ncpStatus);
    return ncpStatus;
}

NCP_API ncp_st_t
ncp_task_tqs_disable(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t tqsId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_tqs_swState_t *pTqs=NULL;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)
    NCP_TASK_LOCK_FLAGS(flags);
    
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_xlf_task_tqs_disable_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p tqsId=%u"
                   "\n",
                   ncpHdl, tqsId);
    NCP_ASSERT((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK(tqsId < NCP_NCAV3_MAX_NUM_TQSETS, NCP_ST_INVALID_PARAMETER);

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    
    pTqs = &pNcpTaskSwState->tqsSwState[tqsId];
    
    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired)); 

    if (pNcpTaskSwState->uMode == TRUE)
    {
        /* Set the kernel-maintained copy of tqsEnabled to FALSE. */
        ncpStatus = ncp_ncav3_enable_kernel_tqs(
            myDevHdl,
            tqsId,
            FALSE);

        /* This function gets called by ncp_task_disable_umode_tqsets() at
         * config time. If the driver was removed, then loaded, the driver
         * won't have any GSM. In that case, ignore it.
         */
        if (ncpStatus == NCP_ST_TASK_NO_GSM)
        {
            ncpStatus = NCP_ST_SUCCESS;
        }
    }
    else
    {
        /* FIXME: Return error if kernel thread tried to disable a
         * user-mode TQS. This else-block gets executed by user-mode ioctls, so
         * be careful.
         */
    }

    NCP_TASK_TQS_DISABLE(tqsId);        

NCP_RETURN_LABEL  

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));         
      
    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pTqs, api_task_tqs_disable_ok);        
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQS(pTqs, api_task_tqs_disable_err);        
    }       
    
    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tqs_disable_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "\n",
                   ncpStatus);
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_tqs_enable(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t tqsId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_tqs_swState_t *pTqs=NULL;    
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)
    NCP_TASK_LOCK_FLAGS(flags);
    
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tqs_enable_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p tqsId=%u"
                   "\n",
                   ncpHdl, tqsId);
    NCP_ASSERT((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK(tqsId < NCP_NCAV3_MAX_NUM_TQSETS, NCP_ST_INVALID_PARAMETER);

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    
    pTqs = &pNcpTaskSwState->tqsSwState[tqsId];
    
    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired)); 

    if (pNcpTaskSwState->uMode == TRUE)
    {
        /* Set the kernel-maintained copy of tqsEnabled to TRUE. */
        NCP_CALL(ncp_ncav3_enable_kernel_tqs(
            myDevHdl,
            tqsId,
            TRUE));
    }
    else
    {
        /* FIXME: Return error if kernel thread tried to enable a
         * user-mode TQS. This else-block gets executed by user-mode ioctls, so
         * be careful.
         */
    }

    NCP_TASK_TQS_ENABLE(tqsId);        

NCP_RETURN_LABEL  

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));         
    
    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pTqs, api_task_tqs_enable_ok);        
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQS(pTqs, api_task_tqs_enable_err);        
    }  
    
    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tqs_enable_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "\n",
                   ncpStatus);
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_nca_queue_disable(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t ncaQueueId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_dev_hdl_t dev;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_xlf_task_nca_queue_disable_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p ncaQueueId=%u"
                   "\n",
                   ncpHdl, ncaQueueId);
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));

    NCP_CHECK(ncaQueueId < NCP_NCAV3_MAX_NUM_NCAQS, NCP_ST_INVALID_PARAMETER);

    dev = ncp_dev_hdls[((ncp_t *) ncpHdl)->id];

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    NCP_CALL(ncp_ncav3_nca_queue_disable(dev, ncaQueueId));

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_nca_queue_disable_ok);
    }
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_nca_queue_disable_err);
    }

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_nca_queue_disable_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "\n",
                   ncpStatus);
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_nca_queue_enable(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t ncaQueueId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_dev_hdl_t dev;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_xlf_task_nca_queue_enable_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p ncaQueueId=%u"
                   "\n",
                   ncpHdl, ncaQueueId);
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));

    NCP_CHECK(ncaQueueId < NCP_NCAV3_MAX_NUM_NCAQS, NCP_ST_INVALID_PARAMETER);

    dev = ncp_dev_hdls[((ncp_t *) ncpHdl)->id];

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    NCP_CALL(ncp_ncav3_nca_queue_enable(dev, ncaQueueId));

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_nca_queue_enable_ok);
    }
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_nca_queue_enable_err);
    }

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_xlf_task_nca_queue_enable_exit, NCP_MSG_EXIT,
                   "ncpStatus=%d\n", ncpStatus);
    return(ncpStatus);
}

#define NCP_TASK_NUM_RXFLUSH_TASKS 32
#define NCP_TASK_FLUSH_MAX_CONSECUTIVE_RX_EMPTY 128
NCP_API ncp_st_t
ncp_task_rx_queue_flush(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint32_t txQueueId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    ncp_task_tqs_swState_t *pTqs = NULL;    
    ncp_task_pcq_t *p_oPCQ = NULL;    
    NCP_MUTEX_LOCKED_FLAG_DECL(txUnlockRequired);    
    ncp_task_pcq_t *p_iPCQ = NULL;
    NCP_MUTEX_LOCKED_FLAG_DECL(rxUnlockRequired); 
    ncp_task_header_t *tasks[NCP_TASK_NUM_RXFLUSH_TASKS];
    ncp_uint32_t numReceived;
    ncp_uint32_t numFreed; 
    ncp_bool_t   issueCompletions;  
    ncp_ipcq_entry_t *pInputQueueEntry;
    int loops=0;
    int numEmpty=0;
    ncp_bool_t needPollStateReset = TRUE;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    /* ncp_uint32_t numFlushed = 0; */  /* DEBUG */
    NCP_TASK_LOCK_FLAGS(txqLockFlags); 
    NCP_TASK_LOCK_FLAGS(rxqLockFlags);    
    
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_rx_queue_flush_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p txQueueId=%u"
                   "\n",
                   tqsHdl, txQueueId);
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    NCP_TASKIO_CHECK((txQueueId == NCP_TASK_TXQ_0 
               || txQueueId == NCP_TASK_TXQ_1),
               NCP_ST_INVALID_PARAMETER);
    NCP_TASKIO_CHECK((TRUE == pvtTqsHdl->useFlags.useTxQueue[txQueueId]), 
              NCP_ST_TASK_TQS_SHARING_VIOLATION);
    NCP_TASKIO_CHECK((TRUE == pvtTqsHdl->useFlags.useRxQueue), 
              NCP_ST_TASK_TQS_SHARING_VIOLATION); 
              
    NCP_TASKIO_CHECK((TRUE != pvtTqsHdl->inOpcqCallbackDoneFn[txQueueId]), 
                      NCP_ST_TASK_SENDQUEUE_CALLBACK_RECURSION_DETECTED);               
              
/*
 *  Remove tasks from the specified receive queue until it and 
 *  the NCA queues that feed it are depleted.
 *
 *  This function may issue manual completions or task frees 
 *  on the specified transmit queue.
 */

    pTqs = pvtTqsHdl->pTqs;
    NCP_TASK_PREFETCH_PGIT_FOR_WRITE(pTqs->pCpuPgit);
    NCP_TASK_PREFETCH_PGIT(pTqs->pNcaPgit);    
    
    p_iPCQ = &pTqs->rxQ;
    if (p_iPCQ->shared == TRUE)
    {
        NCP_CALL(NCP_TASK_CLAIM_LOCK_HDL(&p_iPCQ->qLock, rxqLockFlags, &rxUnlockRequired));
    }
        
    if (NCP_TASK_TXQ_0 == txQueueId)
    {
        p_oPCQ = &pTqs->txQ0;
    }
    else
    {
        p_oPCQ = &pTqs->txQ1;
    }  

    if (p_oPCQ->shared)
    {
        NCP_CALL(NCP_TASK_CLAIM_LOCK_HDL(&p_oPCQ->qLock, txqLockFlags, &txUnlockRequired));
    }


    /*
     * TODO - take parent NCA queues offline if no other TQSets
     * are actively using them.
     */
     
    issueCompletions = (FALSE == p_iPCQ->u.ipcq_info.autoCompletionMode);

    pInputQueueEntry = p_iPCQ->u.ipcq_info.pIPCQentry;
    NCP_TASK_PREFETCH_PCQ_ENTRY((pInputQueueEntry));
    NCP_TASK_PREFETCH_TASK_HEADER(pInputQueueEntry);

    do 
    {
        loops++;

        if (p_iPCQ->u.ipcq_info.autoConsumptionMode)
        {
            ncpStatus = ncp_task_recv_normal(
                    pvtTqsHdl,
                    p_iPCQ,
                    p_iPCQ->u.ipcq_info.pIPCQentry,
                    NCP_TASK_NUM_RXFLUSH_TASKS,
                    &numReceived,
                    &tasks[0],
                    FALSE);
        }
        else
        {
            ncpStatus = ncp_task_recv_deferred(
                    pvtTqsHdl,
                    p_iPCQ,
                    p_iPCQ->u.ipcq_info.pIPCQentry,
                    NCP_TASK_NUM_RXFLUSH_TASKS,
                    &numReceived,
                    &tasks[0],
                    FALSE);
        }

        if (NCP_ST_SUCCESS != ncpStatus)
        {                             
            if (NCP_ST_TASK_RECV_QUEUE_EMPTY == ncpStatus)
            {  
                numEmpty++;
                if (numEmpty < NCP_TASK_FLUSH_MAX_CONSECUTIVE_RX_EMPTY)
                { 
                    ncp_st_t tmpStatus;
                    
                    if (needPollStateReset)
                    {       
                        needPollStateReset = FALSE;             
                        NCP_TASK_RESET_POLL_STATE(
                            &pvtTqsHdl->waitProfile[NCP_TASK_API_CLASS_RECV_QUEUE_FLUSH]);
                    }        
                               
                    if (NCP_ST_SUCCESS != (tmpStatus = NCP_TASK_DO_WAIT(
                            pvtTqsHdl,
                            (&pvtTqsHdl->waitProfile[NCP_TASK_API_CLASS_RECV_QUEUE_FLUSH]),
                            myDevHdl,
                            pvtTqsHdl->tqsId)))
                    {
                        ncpStatus = tmpStatus;
                        NCP_JUMP_RETURN();
                    }
                    continue; 
                } 
                else
                {
                    /* Assume the queue is really drained and exit early */
                    break;
                }        
            }
            else 
            {
                NCP_CALL(ncpStatus);
            }        
        }
        else
        {
            numEmpty = 0; /* reset */
        }           

        /* Free the tasks just received, issueing completions if 
         * required.   Note if this TQS uses a cpu pool,   then this
         * free will resupply the NCA with same buffers that were 
         * received above.
         */
        NCP_CALL(ncp_task_bulk_task_free(
                pvtTqsHdl,
                p_oPCQ,
                numReceived,
                &numFreed,
                &tasks[0],
                TRUE,
                issueCompletions,
                TRUE));
                
        /* numFlushed += numReceived; */ /* DEBUG */

        NCP_ASSERT((numReceived ==  numFreed), NCP_ST_INTERNAL_ERROR);

        if (issueCompletions)
        {
            pvtTqsHdl->completionsIssued[txQueueId] += numFreed;
            NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                                  ncp_xlf_task_rx_queue_flush_txCompletionInfo,
                                  NCP_MSG_DEBUG,
                                  "[%s()] TxQ_%d completions issued incremented by %d, total = %d\n",
                                  __func__, txQueueId, numFreed,
                                  pvtTqsHdl->completionsIssued[txQueueId]);
        }

    } while(1);   
    
NCP_RETURN_LABEL

    /* DEBUG */
#if 0
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_rx_queue_flush_results, NCP_MSG_INFO,
                          "Flushed %d tasks, loops=%d, numEmpty=%d\r\n",
                          numFlushed, loops, numEmpty);
#endif

    if ((NCP_ST_SUCCESS == ncpStatus)
     || (NCP_ST_TASK_RECV_QUEUE_EMPTY == ncpStatus))
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_rx_queue_flush_ok); 
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_rx_queue_flush_err);      
    }  
    
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);   
    
    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK_HDL(&p_oPCQ->qLock, txqLockFlags, &txUnlockRequired));
    
    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK_HDL(&p_iPCQ->qLock, rxqLockFlags, &rxUnlockRequired));
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_rx_queue_flush_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "\n",
                   ncpStatus);
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_tx_queue_flush(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint32_t txQueueId) 
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
#ifndef NCP_DEV_SOCKET
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    ncp_task_tqs_swState_t *pTqs = NULL;
    ncp_task_pcq_t *p_oPCQ = NULL;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    NCP_TASK_LOCK_FLAGS(txqLockFlags);      
            
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tx_queue_flush_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p txQueueId=%u"
                   "\n",
                   tqsHdl, txQueueId);
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    NCP_TASKIO_CHECK((txQueueId == NCP_TASK_TXQ_0 
               || txQueueId == NCP_TASK_TXQ_1),
               NCP_ST_INVALID_PARAMETER);    
    NCP_TASKIO_CHECK((TRUE == pvtTqsHdl->useFlags.useTxQueue[txQueueId]), 
              NCP_ST_TASK_TQS_SHARING_VIOLATION);
              
    NCP_TASKIO_CHECK((TRUE != pvtTqsHdl->inOpcqCallbackDoneFn[txQueueId]), 
                      NCP_ST_TASK_SENDQUEUE_CALLBACK_RECURSION_DETECTED);              

    pTqs = pvtTqsHdl->pTqs;
    NCP_TASK_PREFETCH_PGIT_FOR_WRITE(pTqs->pCpuPgit);
    NCP_TASK_PREFETCH_PGIT(pTqs->pNcaPgit);    
    
    if (NCP_TASK_TXQ_0 == txQueueId)
    {
        p_oPCQ = &pTqs->txQ0;
    }
    else
    {
        p_oPCQ = &pTqs->txQ1;
    }  

    if (p_oPCQ->shared)
    {
        NCP_CALL(NCP_TASK_CLAIM_LOCK_HDL(&p_oPCQ->qLock, txqLockFlags, &unlockRequired));
    }         

    do {
        /* We wait for empty to be reflected in the PGIT */
        if (*(p_oPCQ->pProducerIdx) == *(p_oPCQ->pConsumerIdx))
        {    
            break;  /* Empty, get out */
        }  
        else
        {
#ifndef NCP_KERNEL
            ncp_sys_usleep(NCP_SLEEP_POLL_INTERVAL);
#endif
        }

    } while(1);

    /*
     * Force send done dispatch to thread local pcq
     */
    NCP_TASK_UPDATE_NUM_TX_ENTRIES_AVAIL(pvtTqsHdl, p_oPCQ);     
    


NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_tx_queue_flush_ok); 
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_tx_queue_flush_err);      
    }  

    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    
    /* must unlock before allowing callbacks */    
    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK_HDL(&p_oPCQ->qLock, txqLockFlags, &unlockRequired));
    
    NCP_TASK_PROCESS_SEND_DONE(pvtTqsHdl, txQueueId);
        
#endif  /* NCP_DEV_SOCKET */
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tx_queue_flush_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "\n",
                   ncpStatus);
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_send( 
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint8_t  txQueueId,
    ncp_uint32_t numTasks, 
    ncp_uint32_t *pNumSent, 
    ncp_task_send_meta_t *pMetadata, 
    ncp_bool_t wait) 
{
#if defined(NCP_DEV_SOCKET)  
    return NCP_ST_NOT_IMPLEMENTED;
#else
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    
#ifdef NCP_TASKIO_CHECK_DISABLED    
    /* Optimized init block. Saves ~6 cycles (~3%) for the performance path */
    ncp_task_tqs_swState_t *pTqs;
    ncp_task_pcq_t *p_oPCQ;
    ncp_int32_t completionsIssued;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    NCP_TASK_LOCK_FLAGS(txqLockFlags); 
    /* end optimized init block */        

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_task_send_check_disabled_entry,
                          NCP_MSG_ENTRY,
                          "tqsHdl=%p txQueueId=%u numTasks=%u pNumSent=%p pMetadata=%p wait=%u"
                          "\n",
                          tqsHdl, txQueueId, numTasks, pNumSent, pMetadata, wait);
#else    
    /* Unoptimized init block.   Provides sane values for premature returns due to check failing */
    ncp_task_tqs_swState_t *pTqs = NULL;
    ncp_task_pcq_t *p_oPCQ = NULL;
    ncp_int32_t completionsIssued = 0;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    NCP_TASK_LOCK_FLAGS(txqLockFlags);  
    /* end unoptimized init block */  

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_task_send_entry,
                          NCP_MSG_ENTRY,
                          "tqsHdl=%p txQueueId=%u numTasks=%u pNumSent=%p pMetadata=%p wait=%u"
                          "\n",
                          tqsHdl, txQueueId, numTasks, pNumSent, pMetadata, wait);
    /* 
     * API Parameter Validation 
     */
    NCP_TASKIO_CHECK((NULL != pNumSent), NCP_ST_INVALID_PARAMETER);
    *pNumSent = 0;
    
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    NCP_TASKIO_CHECK((txQueueId == NCP_TASK_TXQ_0 
               || txQueueId == NCP_TASK_TXQ_1),
               NCP_ST_INVALID_PARAMETER);    
    NCP_TASKIO_CHECK((NULL != pMetadata), NCP_ST_INVALID_PARAMETER);  
    NCP_TASKIO_CHECK((TRUE == pvtTqsHdl->useFlags.useTxQueue[txQueueId]), 
              NCP_ST_TASK_TQS_SHARING_VIOLATION);
              
    NCP_TASKIO_CHECK((TRUE != pvtTqsHdl->inOpcqCallbackDoneFn[txQueueId]), 
                      NCP_ST_TASK_SENDQUEUE_CALLBACK_RECURSION_DETECTED);              
    if (NCP_TASK_RESTRICT_BULK_APIS)
    {    
        NCP_TASKIO_CHECK((numTasks <= NCP_TASK_API_MAX_BULK_ITEM_COUNT),
                   NCP_ST_TASK_BULK_REQUEST_TOO_BIG);              
    }                        
#endif

             

    pTqs = pvtTqsHdl->pTqs;
        
    NCP_TASK_PREFETCH_PGIT_FOR_WRITE(pTqs->pCpuPgit);
    NCP_TASK_PREFETCH_PGIT(pTqs->pNcaPgit);    

    if (FALSE == pTqs->tqsEnabled)
    {
        /*TODO*/
        *pNumSent = 0;                  /* Need sane value in exit path if checks OFF */
        completionsIssued = 0;          /* Need sane value in exit path if checks OFF */
        NCP_CALL(NCP_ST_TASK_TQS_DISABLED);
    }
        
    if (NCP_TASK_TXQ_0 == txQueueId)
    {
        p_oPCQ = &pTqs->txQ0;
    }
    else
    {
        p_oPCQ = &pTqs->txQ1;
    }  

    if (FALSE == p_oPCQ->shared)
    {
        /* Intentional NULL body */            
    }
    else        
    {
        NCP_CALL(NCP_TASK_CLAIM_LOCK_HDL(&p_oPCQ->qLock, txqLockFlags, &unlockRequired));
    } 
     
    NCP_TASK_PREFETCH_PCQ_ENTRY_FOR_WRITE(p_oPCQ->u.opcq_info.pOPCQentry);
         
    /*
     * Force any send done callbacks to be executed now.
     * This ensures that we do not overflow the send done PCQ.
     */
        
    NCP_TASK_PROCESS_SEND_DONE(pvtTqsHdl, txQueueId);
    
    /*
     * Do the send - optimized for single send case 
     */

    if (1 == numTasks)
    {
        ncpStatus = ncp_task_single_task_send(
                pvtTqsHdl,
                p_oPCQ,
                numTasks, 
                pNumSent,
                pMetadata,
                &completionsIssued,                        
                wait);
    }
    else if (0 != numTasks)
    {                                 
        ncpStatus = ncp_task_bulk_task_send(
                pvtTqsHdl,
                p_oPCQ,
                numTasks, 
                pNumSent,
                pMetadata,
                &completionsIssued,                        
                wait);
    }
    else
    {
        *pNumSent = 0;
        completionsIssued = 0;
        
    }        
            
NCP_RETURN_LABEL

    pvtTqsHdl->completionsIssued[txQueueId] += completionsIssued;
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_send_txCompletionInfo, NCP_MSG_DEBUG,
                          "in send: TxQ_%d completions issued incremented by %d, total = %d\r\n",
                          txQueueId,
                          completionsIssued,
                          pvtTqsHdl->completionsIssued[txQueueId]);

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_send_ok); 
        NCP_TASK_ADD_TXSTAT(pvtTqsHdl->pTqs, TxTask, txQueueId, *pNumSent);        
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_send_err);      
    }  
     
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);            

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK_HDL(&p_oPCQ->qLock, txqLockFlags, &unlockRequired));

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_send_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d pNumSent=%p(%u)"
                   "\n",
                   ncpStatus, pNumSent, (pNumSent) ? (*pNumSent) : 0);
    return(ncpStatus);
    
#endif /* SOCKET */    
}

NCP_API ncp_st_t
ncp_task_recv(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint32_t numTasks, 
    ncp_uint32_t *pNumReceived, 
    ncp_task_header_t **pTasks,
    ncp_bool_t wait) 
{
#ifdef NCP_DEV_SOCKET
    return(ncpStatus);
#else
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pcq_t *p_iPCQ = NULL;
    ncp_ipcq_entry_t *pInputQueueEntry = NULL;    
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);    
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl =
        (ncp_task_pvt_tqsHdl_data_t *) tqsHdl;
    ncp_task_tqs_swState_t *pTqs;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    NCP_TASK_LOCK_FLAGS(flags);     
    
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_recv_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p numTasks=%u pNumReceived=%p pTasks=%p wait=%u"
                   "\n",
                   tqsHdl, numTasks, pNumReceived, pTasks, wait);
    NCP_TASKIO_CHECK((NULL != pNumReceived), NCP_ST_INVALID_PARAMETER);
    *pNumReceived = 0;

    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    NCP_TASKIO_CHECK((NULL != pTasks), NCP_ST_INVALID_PARAMETER);    
    NCP_TASKIO_CHECK(((TRUE != pvtTqsHdl->inOpcqCallbackDoneFn[NCP_TASK_TXQ_0])
                   && (TRUE != pvtTqsHdl->inOpcqCallbackDoneFn[NCP_TASK_TXQ_1])),
                   NCP_ST_TASK_SENDQUEUE_CALLBACK_RECURSION_DETECTED);
    NCP_TASKIO_CHECK((TRUE == pvtTqsHdl->useFlags.useRxQueue), 
              NCP_ST_TASK_TQS_SHARING_VIOLATION);

    pTqs = pvtTqsHdl->pTqs;
    NCP_TASK_PREFETCH_PGIT_FOR_WRITE(pTqs->pCpuPgit);
    NCP_TASK_PREFETCH_PGIT(pTqs->pNcaPgit);    
    
    p_iPCQ = &pTqs->rxQ;
    if (p_iPCQ->shared == TRUE)
    {
        NCP_CALL(NCP_TASK_CLAIM_LOCK_HDL(&p_iPCQ->qLock, flags, &unlockRequired));
    }
    
    pInputQueueEntry = p_iPCQ->u.ipcq_info.pIPCQentry;
    NCP_TASK_PREFETCH_PCQ_ENTRY((pInputQueueEntry));
    NCP_TASK_PREFETCH_TASK_HEADER(pInputQueueEntry);
        
    if (p_iPCQ->u.ipcq_info.autoConsumptionMode)
    {
        NCP_TASKIO_CHECK(0 != numTasks, NCP_ST_INVALID_PARAMETER);
        if (NCP_ST_SUCCESS != (ncpStatus = ncp_task_recv_normal(pvtTqsHdl,
                                      p_iPCQ,
                                      pInputQueueEntry,
                                      numTasks, 
                                      pNumReceived, 
                                      pTasks,
                                      wait)))
        {                             
            if (NCP_ST_TASK_RECV_QUEUE_EMPTY == ncpStatus)
            {    
                NCP_JUMP_RETURN(); /* silent return */
            }
            else 
            {
                NCP_CALL(ncpStatus);
            }        
        }    
    }
    else
    {
        /* 
         * We allow caller to specify zero.   
         * Can be used to complete all outstanding without receiving more. 
         */
        if (NCP_ST_SUCCESS != (ncpStatus = ncp_task_recv_deferred(pvtTqsHdl,
                                        p_iPCQ,
                                        pInputQueueEntry,                                        
                                        numTasks, 
                                        pNumReceived, 
                                        pTasks,
                                        wait))) 
        {                             
            if (NCP_ST_TASK_RECV_QUEUE_EMPTY == ncpStatus)
            {    
                NCP_JUMP_RETURN(); /* silent return */
            }
            else 
            {
                NCP_CALL(ncpStatus);
            }        
        }                                                 
    }                
    
NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_recv_ok);
        NCP_TASK_ADD_STAT(pvtTqsHdl->pTqs, RxTask, *pNumReceived);
    }
    else
    {    
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_recv_err);
    }     
    
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    
    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK_HDL(&p_iPCQ->qLock, flags, &unlockRequired));
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_recv_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d pNumReceived=%p(%u)"
                   "\n",
                   ncpStatus,
                   pNumReceived, (pNumReceived) ? (*pNumReceived) : 0);
    return(ncpStatus);
#endif /* #ifdef NCP_DEV_SOCKET */    
}

NCP_API ncp_st_t
ncp_task_deferred_consume( 
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint32_t numTasks)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;    
    ncp_task_tqs_swState_t *pTqs = NULL;
    ncp_task_pcq_t *p_iPCQ = NULL;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    ncp_uint8_t strippedHwConsumerVal;
    ncp_uint8_t newStrippedHwConsumerVal;    
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    NCP_TASK_LOCK_FLAGS(flags);
         
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_deferred_consume_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p numTasks=%u"
                   "\n",
                   tqsHdl, numTasks);
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
      
    pTqs = pvtTqsHdl->pTqs;
    NCP_TASK_PREFETCH_PGIT_FOR_WRITE(pTqs->pCpuPgit);
    NCP_TASK_PREFETCH_PGIT(pTqs->pNcaPgit);    
                
    p_iPCQ = &pTqs->rxQ; 
    if (p_iPCQ->u.ipcq_info.autoConsumptionMode)
    {
        NCP_CALL(NCP_ST_TASK_WRONG_CONSUMPTION_MODE);
    }        
                      
    if (0 != numTasks) /* zero is technically valid,  so allow it, but do nothing */
    {     
        if (p_iPCQ->shared == TRUE)
        {
            NCP_CALL(NCP_TASK_CLAIM_LOCK_HDL(&p_iPCQ->qLock, flags, &unlockRequired));
        }
                
        if (numTasks > pvtTqsHdl->consumptionsOwed)
        {
            /* App attempted to consume more tasks than it currently owns */
            NCP_CALL(NCP_ST_TASK_INVALID_NUMTASKS);
        }   
        
        pvtTqsHdl->consumptionsOwed -= numTasks;
        
        /*
         * Increment HW pgit index by numTasks and write it to the hardware, already checked for overflow.
         */
         
        strippedHwConsumerVal = p_iPCQ->hwConsumerVal & NCP_PCQ_TOGGLE_BIT_MASK;
        newStrippedHwConsumerVal = ((strippedHwConsumerVal + numTasks) & p_iPCQ->nEntriesMinusOne);
        if (newStrippedHwConsumerVal <= strippedHwConsumerVal) 
        {
            /* update caused queue to rollover,  invert toggle bit */
            p_iPCQ->toggleBit ^= (1 << NCP_PCQ_TOGGLE_BIT_SHIFT);
        }        
        /* Write the updated index to the PGIT,   so the NCA sees the change */         
        *(p_iPCQ->pConsumerIdx) = p_iPCQ->hwConsumerVal = (newStrippedHwConsumerVal | p_iPCQ->toggleBit);
    } /* not zero */
             
NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_deferred_consume_ok); 
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_deferred_consume_err);      
    } 
    
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    
    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK_HDL(&p_iPCQ->qLock, flags, &unlockRequired));
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_deferred_consume_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "\n",
                   ncpStatus);
    return(ncpStatus);
}
    
NCP_API ncp_st_t
ncp_task_complete( 
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint8_t txQueueId,
    ncp_uint32_t numTasks,
    ncp_uint32_t *pNumTasksCompleted,
    ncp_bool_t wait)     
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    ncp_task_tqs_swState_t *pTqs = NULL;
    ncp_task_pcq_t *p_oPCQ = NULL;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);    
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    NCP_TASK_LOCK_FLAGS(txqLockFlags);    
    
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_complete_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p txQueueId=%u numTasks=%u pNumTasksCompleted=%p wait=%u"
                   "\n",
                   tqsHdl, txQueueId, numTasks, pNumTasksCompleted, wait);
    NCP_TASKIO_CHECK((NULL != pNumTasksCompleted), NCP_ST_INVALID_PARAMETER);
    *pNumTasksCompleted = 0;
        
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    NCP_TASKIO_CHECK((txQueueId == NCP_TASK_TXQ_0 
               || txQueueId == NCP_TASK_TXQ_1),
               NCP_ST_INVALID_PARAMETER);    
    NCP_TASKIO_CHECK((TRUE == pvtTqsHdl->useFlags.useTxQueue[txQueueId]), 
              NCP_ST_TASK_TQS_SHARING_VIOLATION);  
    NCP_TASKIO_CHECK((TRUE != pvtTqsHdl->inOpcqCallbackDoneFn[txQueueId]), 
                      NCP_ST_TASK_SENDQUEUE_CALLBACK_RECURSION_DETECTED);  
    NCP_TASKIO_CHECK(FALSE == pvtTqsHdl->pTqs->rxQ.u.ipcq_info.autoCompletionMode,     
              NCP_ST_TASK_WRONG_COMPLETION_MODE);
    NCP_TASKIO_CHECK(numTasks <= pvtTqsHdl->completionsOwed,
              NCP_ST_TASK_TOO_MANY_TASK_COMPLETIONS);

    pTqs = pvtTqsHdl->pTqs;
    NCP_TASK_PREFETCH_PGIT_FOR_WRITE(pTqs->pCpuPgit);
    NCP_TASK_PREFETCH_PGIT(pTqs->pNcaPgit);    
         
    if (NCP_TASK_TXQ_0 == txQueueId)
    {
        p_oPCQ = &pTqs->txQ0;
    }
    else
    {
        p_oPCQ = &pTqs->txQ1;
    }  
    
    if (p_oPCQ->shared)
    {
        NCP_CALL(NCP_TASK_CLAIM_LOCK_HDL(&p_oPCQ->qLock, txqLockFlags, &unlockRequired));
    }     

    NCP_TASK_PREFETCH_PCQ_ENTRY_FOR_WRITE(p_oPCQ->u.opcq_info.pOPCQentry);
    
    if (1 == numTasks)    
    {
        
        ncpStatus = ncp_task_single_complete(pvtTqsHdl,
                                    p_oPCQ,
                                    pNumTasksCompleted,
                                    wait);         
                                    
    }
    else 
    {
               
        ncpStatus = ncp_task_bulk_complete(pvtTqsHdl,
                                    p_oPCQ,
                                    numTasks,
                                    pNumTasksCompleted,
                                    wait); 
                                    
    }                                
                                    
    if (ncpStatus != NCP_ST_SUCCESS &&
        ncpStatus != NCP_ST_TASK_SEND_QUEUE_FULL)
    {
        NCP_CALL(ncpStatus);
    }
                                        
NCP_RETURN_LABEL

    pvtTqsHdl->completionsIssued[txQueueId] += *pNumTasksCompleted;
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_complete_txCompletionInfo, NCP_MSG_DEBUG,
                          "in complete: TxQ_%d completions issued incremented by %d, total = %d\r\n",
                          txQueueId,
                          *pNumTasksCompleted,
                          pvtTqsHdl->completionsIssued[txQueueId]);

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_complete_ok); 
        NCP_TASK_ADD_TXSTAT(pvtTqsHdl->pTqs, TaskCompletions, txQueueId, *pNumTasksCompleted);             
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_complete_err);      
    } 
    
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);  
    
    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK_HDL(&p_oPCQ->qLock, txqLockFlags, &unlockRequired));
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_complete_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d pNumTasksCompleted=%p(%u)"
                   "\n",
                   ncpStatus,
                   pNumTasksCompleted,
                   (pNumTasksCompleted) ? (*pNumTasksCompleted) : 0);
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_unscheduled_queue_push(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t unscheduledQueueId,
    ncp_uint64_t data)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)
    ncp_dev_hdl_t dev;

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_unscheduled_queue_push_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p unscheduledQueueId=%u data=%"PRIu64
                   "\n",
                   ncpHdl, unscheduledQueueId, data);
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_TASKIO_VALIDATE_NCP_HDL(ncpHdl));
    NCP_TASKIO_CHECK(unscheduledQueueId < NCP_NCAV3_MAX_NUM_UNSCHEDULED_QUEUES,
                NCP_ST_INVALID_PARAMETER);

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    
    dev = ncp_dev_hdls[((ncp_t *) ncpHdl)->id];

    NCP_CALL(ncp_ncav3_push_unscheduled_queue_tail(
                dev,
                unscheduledQueueId,
                data));

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_unscheduled_queue_push_ok);
    }
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_unscheduled_queue_push_err);
    }

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_unscheduled_queue_push_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "\n",
                   ncpStatus);
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_unscheduled_queue_pop(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t unscheduledQueueId,
    ncp_uint64_t *pData)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)
    ncp_dev_hdl_t dev;

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_unscheduled_queue_pop_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p unscheduledQueueId=%u pData=%p"
                   "\n",
                   ncpHdl, unscheduledQueueId, pData);
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_TASKIO_VALIDATE_NCP_HDL(ncpHdl));    
    NCP_TASKIO_CHECK((NULL != pData), NCP_ST_INVALID_PARAMETER);
    NCP_TASKIO_CHECK(unscheduledQueueId < NCP_NCAV3_MAX_NUM_UNSCHEDULED_QUEUES,
                NCP_ST_INVALID_PARAMETER);

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    
    dev = ncp_dev_hdls[((ncp_t *) ncpHdl)->id];

    NCP_CALL(ncp_ncav3_pop_unscheduled_queue_head(
                dev,
                unscheduledQueueId,
                pData));

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_unscheduled_queue_pop_ok);
    }
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_unscheduled_queue_pop_err);
    }

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_unscheduled_queue_pop_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d pData=%p(%"PRIu64")"
                   "\n",
                   ncpStatus, pData, (pData) ? (*pData) : 0);
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_unscheduled_queue_pop_task(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint32_t unscheduledQueueId,
    ncp_task_header_t **pHeader)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
#ifndef NCP_TASK_VALIDATE_UNSCHEDULED_QUEUE_TASK_DISABLE    
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl =
        (ncp_task_pvt_tqsHdl_data_t *) tqsHdl;
#endif        
    ncp_task_header_t *header;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)
    NCP_TASK_TBR_STATE_PTRS_DECL()
#ifndef NCP_TASK_VALIDATE_UNSCHEDULED_QUEUE_TASK_DISABLE
    ncp_uint8_t poolId;
#endif
    ncp_uint64_t data;

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_unscheduled_queue_pop_task_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p unscheduledQueueId=%u pHeader=%p"
                   "\n",
                   tqsHdl, unscheduledQueueId, pHeader);
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_TASKIO_CHECK((NULL != pHeader), NCP_ST_INVALID_PARAMETER);
    NCP_TASKIO_CHECK(unscheduledQueueId < NCP_NCAV3_MAX_NUM_UNSCHEDULED_QUEUES,
                NCP_ST_INVALID_PARAMETER);

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    NCP_CALL(ncp_ncav3_pop_unscheduled_queue_head(
                myDevHdl,
                unscheduledQueueId,
               &data));

    header = *pHeader = (ncp_task_header_t *)(ncp_uint64_t) data;

    /* This function only works if the unscheduled queue contents are only
     * task pointers. Since 0x0 is never a valid task pointer, it must mean
     * the queue is empty. */
    NCP_ASSERT(header != NULL, NCP_ST_TASK_UNSCHEDULED_QUEUE_IS_EMPTY);

#ifndef NCP_TASK_VALIDATE_UNSCHEDULED_QUEUE_TASK_DISABLE
    /* Next, verify that the header and its PDUs have valid addresses */
    /* (poolId is ignored, this function is just used to validate the
     *  buffer's address) */
    NCP_CALL(NCP_TASK_BUFFER_POOL_GET(
        pvtTqsHdl,
        header,
       &poolId));

    switch (header->ptrCnt)
    {
        case 6:
            NCP_CALL(NCP_TASK_BUFFER_ADDRESS_VALIDATE(
                        pvtTqsHdl,
                        (void *) header->pduSegAddr5,
                        header->pool5));
        case 5:
            NCP_CALL(NCP_TASK_BUFFER_ADDRESS_VALIDATE(
                        pvtTqsHdl,
                        (void *) header->pduSegAddr4,
                        header->pool4));
        case 4:
            NCP_CALL(NCP_TASK_BUFFER_ADDRESS_VALIDATE(
                        pvtTqsHdl,
                        (void *) header->pduSegAddr3,
                        header->pool3));
        case 3:
            NCP_CALL(NCP_TASK_BUFFER_ADDRESS_VALIDATE(
                        pvtTqsHdl,
                        (void *) header->pduSegAddr2,
                        header->pool2));
        case 2:
            NCP_CALL(NCP_TASK_BUFFER_ADDRESS_VALIDATE(
                        pvtTqsHdl,
                        (void *) header->pduSegAddr1,
                        header->pool1));
        case 1:
            NCP_CALL(NCP_TASK_BUFFER_ADDRESS_VALIDATE(
                        pvtTqsHdl,
                        (void *) header->pduSegAddr0,
                        header->pool0));
        case 0:
        default:
            break;
    }
#endif

    /* Update the task's TBR state. Receiving a task from an unscheduled queue
     * is equivalent to receiving it from an iPCQ, from TBR's perspective.
     */
    NCP_TASK_TBR_STATE_PTRS_INIT();
    NCP_TASK_TBR_RXTASK_STATE_PREFETCH(pvtTqsHdl, header, pTbr);
    NCP_TASK_RXTASK_TBR_BUFFER_STATE_UPDATE_MREF(pTbr);

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_unscheduled_queue_pop_ok);
    }
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_unscheduled_queue_pop_err);
    }

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_unscheduled_queue_pop_task_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d pHeader=%p(%p)"
                   "\n",
                   ncpStatus, pHeader, (pHeader) ? (*pHeader) : 0);
    return(ncpStatus);
}


NCP_API ncp_st_t
ncp_task_unscheduled_queue_depth_get(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t unscheduledQueueId,
    ncp_uint16_t *pQDepth)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)
    ncp_dev_hdl_t dev;

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_task_unscheduled_queue_depth_get_entry,
                          NCP_MSG_ENTRY,
                          "ncpHdl=%p unscheduledQueueId=%u pQDepth=%p"
                          "\n",
                          ncpHdl, unscheduledQueueId, pQDepth);
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_TASKIO_VALIDATE_NCP_HDL(ncpHdl));
    NCP_TASKIO_CHECK((NULL != pQDepth), NCP_ST_INVALID_PARAMETER);
    NCP_TASKIO_CHECK(unscheduledQueueId < NCP_NCAV3_MAX_NUM_UNSCHEDULED_QUEUES,
                NCP_ST_INVALID_PARAMETER);

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    dev = ncp_dev_hdls[((ncp_t *) ncpHdl)->id];

    NCP_CALL(ncp_ncav3_get_unscheduled_queue_depth(
                dev,
                unscheduledQueueId,
                pQDepth));

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_unscheduled_queue_depth_get_ok);
    }
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_unscheduled_queue_depth_get_err);
    }

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_task_unscheduled_queue_depth_get_exit,
                          NCP_MSG_EXIT,
                          "ncpStatus=%d pQDepth=%p(%u)"
                          "\n",
                          ncpStatus,
                          pQDepth, (pQDepth) ? (*pQDepth) : 0);
    return(ncpStatus);
}

NCP_API ncp_st_t 
ncp_task_buffer_alloc( 
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint32_t numTaskBuffers, 
    ncp_uint32_t *pNumAllocated, 
    ncp_uint32_t *pBufferSizes, 
    ncp_uint8_t    bufferPoolId, 
    void **pTaskBuffers, 
    ncp_bool_t wait) 
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    ncp_task_pool_t         *pPool;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)    

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_buffer_alloc_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p numTaskBuffers=%u pNumAllocated=%p pBufferSizes=%p bufferPoolId=%u pTaskBuffers=%p wait=%u"
                   "\n",
                   tqsHdl, numTaskBuffers, pNumAllocated, pBufferSizes, bufferPoolId, pTaskBuffers, wait);
    NCP_TASKIO_CHECK((NULL != pNumAllocated), NCP_ST_INVALID_PARAMETER);
    *pNumAllocated = 0;
    
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_TASKIO_CHECK((NULL != pBufferSizes), NCP_ST_INVALID_PARAMETER);
    NCP_TASKIO_CHECK((NULL != pTaskBuffers), NCP_ST_INVALID_PARAMETER);    
    NCP_TASKIO_CHECK(((bufferPoolId >= NCP_NCAV3_FIRST_SHARED_POOL_ID 
                && bufferPoolId < NCP_NCAV3_NUM_TASK_MEMORY_POOLS)
                || (NCP_TASK_CPU_POOL_ALIAS == bufferPoolId)), 
                NCP_ST_INVALID_PARAMETER); 
    NCP_TASKIO_CHECK((0 != (pvtTqsHdl->pTqs->validPoolsMask & (1<<bufferPoolId))), 
               NCP_ST_TASK_BUFFER_POOL_NOT_CONFIGURED_FOR_TQS);
               
    if (NCP_TASK_RESTRICT_BULK_APIS)
    {    
        NCP_TASKIO_CHECK((numTaskBuffers <= NCP_TASK_API_MAX_BULK_ITEM_COUNT),
                  NCP_ST_TASK_BULK_REQUEST_TOO_BIG);                     
    }
    
        
    if (0 == bufferPoolId) /* CPU Pool Alias? */
    {
        if (NULL == (pPool = pvtTqsHdl->cpuPoolHdl))
        {
            NCP_CALL(NCP_ST_TASK_TQS_INVALID_POOL);    
        }    
        if (TRUE == pPool->disabledForReinit)
        {
            NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                                  ncp_xlf_task_buffer_alloc_disabledForReinit,
                                  NCP_MSG_ERROR,
                                  "It is invalid to operate on a task handle while its pool is being reinitialized.\n");
            NCP_CALL(NCP_ST_TASK_POOL_IS_BEING_REINITIALIZED);
        }
        
        /**
         *  If wait is TRUE, repeatedly alloc until at least 1 buffer
         *   is allocated.
         */
        while (1)
        {

            ncpStatus = ncp_task_bulk_buffer_alloc_cpu_pool(
                    pvtTqsHdl,
                    pPool,
                    pTaskBuffers,
                    pBufferSizes,
                    numTaskBuffers,
                    pNumAllocated);

            if ( NCP_ST_PTHREAD_MUTEX_OWNER_DEAD  == ncpStatus )
            {
                NCP_CALL(ncpStatus);
            }


            if (!(wait == TRUE
                        && ncpStatus == NCP_ST_NO_MEMORY
                        && *pNumAllocated == 0))
            {
                break;
            }

            /** Give another thread a chance to free **/
#ifndef NCP_KERNEL
            ncp_sys_usleep(10);
#endif
        }
    }
    else 
    {
        ncp_task_tqs_swState_t *pTqs;
        ncp_task_mme_allocator_t *pAllocator;
        
        pTqs = pvtTqsHdl->pTqs;
        NCP_TASK_PREFETCH_PGIT_FOR_WRITE(pTqs->pCpuPgit);
        NCP_TASK_PREFETCH_PGIT(pTqs->pNcaPgit);    
        
        pAllocator = &pTqs->mmeAllocator[bufferPoolId];  
        
        ncpStatus = ncp_task_bulk_MMEpool_alloc(
                    pvtTqsHdl, 
                    pAllocator,
                    numTaskBuffers,
                    pNumAllocated,
                    pBufferSizes, 
                    pTaskBuffers,
                    bufferPoolId,
                    wait);

        if ((ncpStatus != NCP_ST_SUCCESS) && (ncpStatus != NCP_ST_NO_MEMORY))
        {
            NCP_CALL(ncpStatus);
        }    
    }

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_buffer_alloc_ok);
        NCP_TASK_ADD_STAT(pvtTqsHdl->pTqs, BuffAllocs, *pNumAllocated);        
    }
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_buffer_alloc_err);
    }
    
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);        
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_task_buffer_alloc_exit,
                          NCP_MSG_EXIT,
                          "ncpStatus=%d "
                          "pNumAllocated=%p(%u) pBufferSizes=%p(%u) pTaskBuffers=%p(%p)"
                          "\n",
                          ncpStatus,
                          pNumAllocated, (pNumAllocated) ? (*pNumAllocated) : 0,
                          pBufferSizes, (pBufferSizes) ? (*pBufferSizes) : 0,
                          pTaskBuffers, (pTaskBuffers) ? (*pTaskBuffers) : 0);
    return(ncpStatus);         
}

NCP_API ncp_st_t 
ncp_task_buffer_free( 
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint8_t txQueueId,
    ncp_uint32_t numTaskBuffers, 
    ncp_uint32_t *pNumFreed, 
    ncp_uint8_t bufferPoolId,
    void        **pTaskBuffers,    
    ncp_bool_t  *pMrefBitSet,
    ncp_bool_t wait) 
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    ncp_task_pcq_t *p_oPCQ = NULL; /* fix compiler warning */   
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);    
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    NCP_TASK_LOCK_FLAGS(txqLockFlags);     

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_buffer_free_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p txQueueId=%u numTaskBuffers=%u pNumFreed=%p bufferPoolId=%u pTaskBuffers=%p pMrefBitSet=%p wait=%u"
                   "\n",
                   tqsHdl, txQueueId, numTaskBuffers, pNumFreed, bufferPoolId, pTaskBuffers, pMrefBitSet, wait);
    NCP_TASKIO_CHECK((NULL != pNumFreed), NCP_ST_INVALID_PARAMETER);
    *pNumFreed = 0;
    
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    NCP_TASKIO_CHECK((txQueueId == NCP_TASK_TXQ_0 
               || txQueueId == NCP_TASK_TXQ_1),
               NCP_ST_INVALID_PARAMETER);    

    NCP_TASKIO_CHECK((NULL != pTaskBuffers), NCP_ST_INVALID_PARAMETER);
    NCP_TASKIO_CHECK((NULL != pvtTqsHdl->cpuPoolHdl || NULL != pMrefBitSet), NCP_ST_INVALID_PARAMETER);  
    NCP_TASKIO_CHECK(((bufferPoolId >= NCP_NCAV3_FIRST_SHARED_POOL_ID 
                && bufferPoolId < NCP_NCAV3_NUM_TASK_MEMORY_POOLS)
                || (NCP_TASK_CPU_POOL_ALIAS == bufferPoolId)), 
                NCP_ST_INVALID_PARAMETER);   
    NCP_TASKIO_CHECK((0 != (pvtTqsHdl->pTqs->validPoolsMask & (1<<bufferPoolId))), 
               NCP_ST_TASK_BUFFER_POOL_NOT_CONFIGURED_FOR_TQS);                
    
    if (NCP_TASK_RESTRICT_BULK_APIS)
    {    
        NCP_TASKIO_CHECK((numTaskBuffers <= NCP_TASK_API_MAX_BULK_ITEM_COUNT),
                  NCP_ST_TASK_BULK_REQUEST_TOO_BIG);     
    }

                      
    NCP_TASKIO_CHECK((TRUE == pvtTqsHdl->useFlags.useTxQueue[txQueueId]), 
              NCP_ST_TASK_TQS_SHARING_VIOLATION);
         
    if (0 == bufferPoolId) /* CPU Pool Alias? */
    {
        if (NULL == pvtTqsHdl->cpuPoolHdl)
        {
            NCP_CALL(NCP_ST_TASK_TQS_INVALID_POOL);    
        }    
        if (TRUE == pvtTqsHdl->cpuPoolHdl->disabledForReinit)
        {
            NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                                  ncp_xlf_task_buffer_free_disabledForReinit,
                                  NCP_MSG_ERROR,
                                  "It is invalid to operate on a task handle while its pool is being reinitialized.\n");
            NCP_CALL(NCP_ST_TASK_POOL_IS_BEING_REINITIALIZED);
        }
        
        /* TODO - make inline */
        NCP_CALL(ncp_task_bulk_cpu_pool_buffer_free(pvtTqsHdl,
                                  numTaskBuffers,
                                  pNumFreed, 
                                  pTaskBuffers));
    }   
    else
    { 
        ncp_task_tqs_swState_t *pTqs;
        
        NCP_TASKIO_CHECK((TRUE != pvtTqsHdl->inOpcqCallbackDoneFn[txQueueId]), 
                      NCP_ST_TASK_SENDQUEUE_CALLBACK_RECURSION_DETECTED);
                              
        pTqs = pvtTqsHdl->pTqs;
        NCP_TASK_PREFETCH_PGIT_FOR_WRITE(pTqs->pCpuPgit);
        NCP_TASK_PREFETCH_PGIT(pTqs->pNcaPgit);    
            
        if (NCP_TASK_TXQ_0 == txQueueId)
        {
            p_oPCQ = &pTqs->txQ0;
        }
        else
        {
            p_oPCQ = &pTqs->txQ1;
        }  
    
        if (p_oPCQ->shared)
        {
            NCP_CALL(NCP_TASK_CLAIM_LOCK_HDL(&p_oPCQ->qLock, txqLockFlags, &unlockRequired));
        }  

        NCP_TASK_PREFETCH_PCQ_ENTRY_FOR_WRITE(p_oPCQ->u.opcq_info.pOPCQentry);
            
        /* TODO - make inline */
        ncpStatus = ncp_task_bulk_buffer_free(pvtTqsHdl,
                                  p_oPCQ,
                                  bufferPoolId,
                                  numTaskBuffers,
                                  pNumFreed, 
                                  pTaskBuffers,
                                  pMrefBitSet,
                                  wait);    
                                  
        if (ncpStatus != NCP_ST_SUCCESS &&
            ncpStatus != NCP_ST_TASK_SEND_QUEUE_FULL)
        {
            NCP_CALL(ncpStatus);
        }                                  
    }
                                  
NCP_RETURN_LABEL
       
    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_buffer_free_ok);
        NCP_TASK_ADD_TXSTAT(pvtTqsHdl->pTqs, BuffFrees, txQueueId, *pNumFreed);          
    }
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_buffer_free_err);
    }

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK_HDL(&p_oPCQ->qLock, txqLockFlags, &unlockRequired));

    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_buffer_free_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d "
                   "pNumFreed=%p(%u) pTaskBuffers=%p(%p) pMrefBitSet=%p(%u)"
                   "\n",
                   ncpStatus,
                   pNumFreed, (pNumFreed) ? (*pNumFreed) : 0,
                   pTaskBuffers, (pTaskBuffers) ? (*pTaskBuffers) : 0,
                   pMrefBitSet, (pMrefBitSet) ? (*pMrefBitSet) : 0);
    return(ncpStatus);
}

NCP_API ncp_st_t 
ncp_task_free(ncp_task_tqs_hdl_t tqsHdl,
              ncp_uint8_t  txQueueId,
              ncp_uint32_t numTasks,
              ncp_uint32_t *pNumFreed,
              ncp_task_free_meta_t *metadata,
              ncp_bool_t   wait) 
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    ncp_task_tqs_swState_t *pTqs = NULL;
    ncp_task_pcq_t *p_oPCQ = NULL;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)    

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_free_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p txQueueId=%u"
                   "numTasks=%u pNumFreed=%p metadata=%p wait=%u"
                   "\n",
                   tqsHdl, txQueueId,
                   numTasks, pNumFreed, metadata, wait);
    NCP_TASKIO_CHECK((NULL != pNumFreed), NCP_ST_INVALID_PARAMETER);
    *pNumFreed = 0;        
    
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);    
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    NCP_TASKIO_CHECK((txQueueId == NCP_TASK_TXQ_0 
               || txQueueId == NCP_TASK_TXQ_1),
               NCP_ST_INVALID_PARAMETER);    

    NCP_TASKIO_CHECK((NULL != metadata), NCP_ST_INVALID_PARAMETER); 
    NCP_TASKIO_CHECK(numTasks != 0, NCP_ST_INVALID_PARAMETER);


    if (NCP_TASK_RESTRICT_BULK_APIS)
    {    
        NCP_TASKIO_CHECK((numTasks <= NCP_TASK_API_MAX_BULK_ITEM_COUNT),
                  NCP_ST_TASK_BULK_REQUEST_TOO_BIG);             
    }
                  
    NCP_TASKIO_CHECK((TRUE == pvtTqsHdl->useFlags.useTxQueue[txQueueId]), 
              NCP_ST_TASK_TQS_SHARING_VIOLATION);
                  
    pTqs = pvtTqsHdl->pTqs;
    NCP_TASK_PREFETCH_PGIT_FOR_WRITE(pTqs->pCpuPgit);
    NCP_TASK_PREFETCH_PGIT(pTqs->pNcaPgit);    
        
    if (NCP_TASK_TXQ_0 == txQueueId)
    {
        p_oPCQ = &pTqs->txQ0;
    }
    else
    {
        p_oPCQ = &pTqs->txQ1;
    }  
    NCP_TASK_PREFETCH_PCQ_ENTRY_FOR_WRITE(p_oPCQ->u.opcq_info.pOPCQentry);
        
    if (NULL == pvtTqsHdl->cpuPoolHdl)
    {
        NCP_TASKIO_CHECK((TRUE != pvtTqsHdl->inOpcqCallbackDoneFn[txQueueId]), 
                          NCP_ST_TASK_SENDQUEUE_CALLBACK_RECURSION_DETECTED);
                          
        if (1 == numTasks)
        {    
            
            ncpStatus = ncp_task_free_single_by_metadata(
                    pvtTqsHdl,
                    p_oPCQ,
                    pNumFreed,
                    metadata,
                    wait);
        }            
        else 
        {                        
            ncpStatus = ncp_task_bulk_task_free_by_metadata(
                    pvtTqsHdl,
                    p_oPCQ,
                    numTasks,
                    pNumFreed,
                    metadata,
                    wait);
        }            
    }    
    else
    {
        
        ncpStatus = ncp_task_bulk_cpu_pool_task_free(
                            pvtTqsHdl,
                            p_oPCQ,
                            numTasks,
                            pNumFreed,
                            metadata,
                            wait);

    }               
    if (ncpStatus != NCP_ST_SUCCESS &&
        ncpStatus != NCP_ST_TASK_SEND_QUEUE_FULL)
    {
        NCP_CALL(ncpStatus);
    }
                
NCP_RETURN_LABEL

    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_free_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d "
                   "pNumFreed=%p(%u)"
                   "\n",
                   ncpStatus,
                   pNumFreed, (pNumFreed) ? (*pNumFreed) : 0);
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_mmio_buffer_alloc(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint8_t sharedPoolId,
    ncp_uint8_t bufferSize,
    void **pBuffer) 
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl =
        (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    ncp_uint64_t ptr;

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_mmio_buffer_alloc_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p sharedPoolId=%u bufferSize=%u pBuffer=%p"
                   "\n",
                   tqsHdl, sharedPoolId, bufferSize, pBuffer);
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_TASKIO_CHECK((NULL != pBuffer), NCP_ST_INVALID_PARAMETER);  
    NCP_TASKIO_CHECK((sharedPoolId >= NCP_NCAV3_FIRST_SHARED_POOL_ID 
               && sharedPoolId <= NCP_NCAV3_LAST_SHARED_POOL_ID), 
               NCP_ST_INVALID_PARAMETER);  
    NCP_TASKIO_CHECK((0 != (pvtTqsHdl->pTqs->validPoolsMask & (1<<sharedPoolId))), 
               NCP_ST_TASK_BUFFER_POOL_NOT_CONFIGURED_FOR_TQS);                     

    NCP_CALL(ncp_ncav3_dmm_allocate(
                pvtTqsHdl,
                pvtTqsHdl->tqsId,
                sharedPoolId,
                bufferSize,
                &ptr));

    *pBuffer = (void *) (ncp_uintptr_t) ptr;

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_mmio_buffer_alloc_ok); 
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,
            api_task_mmio_buffer_alloc_err);
    }  
    
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_mmio_buffer_alloc_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d pBuffer=%p(%p)"
                   "\n",
                   ncpStatus,
                   pBuffer, (pBuffer) ? (*pBuffer) : 0);
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_mmio_buffer_free(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint8_t sharedPoolId,
    ncp_bool_t mrefBitIsSet,
    void *pBuffer) 
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl =
        (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    int i;

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_mmio_buffer_free_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p sharedPoolId=%u mrefBitIsSet=%u pBuffer=%p"
                   "\n",
                   tqsHdl, sharedPoolId, mrefBitIsSet, pBuffer);
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    NCP_TASKIO_CHECK((NULL != pBuffer), NCP_ST_INVALID_PARAMETER);
    NCP_TASKIO_CHECK((sharedPoolId >= NCP_NCAV3_FIRST_SHARED_POOL_ID
                && sharedPoolId <= NCP_NCAV3_LAST_SHARED_POOL_ID),
                NCP_ST_INVALID_PARAMETER);
    NCP_TASKIO_CHECK((0 != (pvtTqsHdl->pTqs->validPoolsMask & (1<<sharedPoolId))),
               NCP_ST_TASK_BUFFER_POOL_NOT_CONFIGURED_FOR_TQS);

    for (i = 0; i < NCP_TASK_NUM_BUFF_SIZES; i++)
    {
        if ((ncp_uintptr_t)pBuffer >= pNcpTaskSwState->taskPools[sharedPoolId].blocksVA[i] &&
            (ncp_uintptr_t)pBuffer < pNcpTaskSwState->taskPools[sharedPoolId].blocksVAend[i])
        {
            break;
        }
    }

    NCP_ASSERT(i != NCP_TASK_NUM_BUFF_SIZES,
            NCP_ST_INVALID_BUFF_FOR_TASK_FREE);

    NCP_CALL(ncp_ncav3_dmm_free(
                pvtTqsHdl,
                pvtTqsHdl->tqsId,
                sharedPoolId,
                i,
                mrefBitIsSet,
                (ncp_uint64_t) pBuffer));

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_mmio_buffer_free_ok); 
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,
                api_task_mmio_buffer_free_err);
    }  
    
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_mmio_buffer_free_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "\n",
                   ncpStatus);
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_buffer_pool_get(
    ncp_task_tqs_hdl_t tqsHdl,
    void *pBuffer,
    ncp_uint8_t *pBufferPoolId) 
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_buffer_pool_get_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p pBuffer=%p pBufferPoolId=%p"
                   "\n",
                   tqsHdl, pBuffer, pBufferPoolId);
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_CHECK((NULL != pBuffer), NCP_ST_INVALID_PARAMETER);
    NCP_CHECK((NULL != pBufferPoolId), NCP_ST_INVALID_PARAMETER);        

    NCP_CALL(NCP_TASK_BUFFER_POOL_GET(pvtTqsHdl, pBuffer, pBufferPoolId));
    
NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_buffer_pool_get_ok); 
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_buffer_pool_get_err);      
    }
    
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_buffer_pool_get_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d pBufferPoolId=%p(%u)"
                   "\n",
                   ncpStatus,
                   pBufferPoolId, (pBufferPoolId) ? (*pBufferPoolId) : 0);
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_buffer_size_get(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint8_t   bufferPoolId,    
    void *pBuffer,
    ncp_uint32_t *pBufferSize) 
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_buffer_size_get_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p bufferPoolId=%u pBuffer=%p pBufferSize=%p"
                   "\n",
                   tqsHdl, bufferPoolId, pBuffer, pBufferSize);
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag); 
    NCP_TASKIO_CHECK(((bufferPoolId >= NCP_TASK_FIXED_POOL_ENCODED_ID 
                && bufferPoolId < NCP_NCAV3_NUM_TASK_MEMORY_POOLS)
                || (NCP_TASK_CPU_POOL_ALIAS == bufferPoolId)), 
                NCP_ST_INVALID_PARAMETER); 
    NCP_TASKIO_CHECK((0 != (pvtTqsHdl->pTqs->validPoolsMask & (1<<bufferPoolId))), 
               NCP_ST_TASK_BUFFER_POOL_NOT_CONFIGURED_FOR_TQS);                       
    NCP_TASKIO_CHECK((NULL != pBuffer), NCP_ST_INVALID_PARAMETER);
    NCP_TASKIO_CHECK((NULL != pBufferSize), NCP_ST_INVALID_PARAMETER);       


    NCP_CALL(NCP_TASK_BUFFER_SIZE_GET(pvtTqsHdl, bufferPoolId, pBuffer, pBufferSize));
    
NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_buffer_size_get_ok); 
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_buffer_size_get_err);      
    }
    
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_buffer_size_get_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d pBufferSize=%p(%u)"
                   "\n",
                   ncpStatus,
                   pBufferSize, (pBufferSize) ? (*pBufferSize) : 0);
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_buffer_size_and_start_get(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint8_t   bufferPoolId,
    void *pBuffer,
    ncp_uint32_t *pBufferSize,
    void **pBufferStart)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_buffer_size_and_start_get_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p bufferPoolId=%u pBuffer=%p pBufferSize=%p pBufferStart=%p"
                   "\n",
                   tqsHdl, bufferPoolId, pBuffer, pBufferSize, pBufferStart);
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag); 
    NCP_TASKIO_CHECK(((bufferPoolId >= NCP_TASK_FIXED_POOL_ENCODED_ID 
                && bufferPoolId < NCP_NCAV3_NUM_TASK_MEMORY_POOLS)
                || (NCP_TASK_CPU_POOL_ALIAS == bufferPoolId)), 
                NCP_ST_INVALID_PARAMETER); 
    NCP_TASKIO_CHECK((0 != (pvtTqsHdl->pTqs->validPoolsMask & (1<<bufferPoolId))), 
               NCP_ST_TASK_BUFFER_POOL_NOT_CONFIGURED_FOR_TQS);                       
    NCP_TASKIO_CHECK((NULL != pBuffer), NCP_ST_INVALID_PARAMETER);
    NCP_TASKIO_CHECK((NULL != pBufferSize), NCP_ST_INVALID_PARAMETER);       
    NCP_TASKIO_CHECK((NULL != pBufferStart), NCP_ST_INVALID_PARAMETER);

    NCP_CALL(NCP_TASK_BUFFER_SIZE_AND_START_GET(pvtTqsHdl, bufferPoolId, pBuffer, pBufferSize, pBufferStart));
    
NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_buffer_size_and_start_get_ok); 
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_buffer_size_and_start_get_err);      
    }
    
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_buffer_size_and_start_get_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "pBufferSize=%p(%u) pBufferStart=%p(%p)"
                   "\n",
                   ncpStatus,
                   pBufferSize, (pBufferSize) ? (*pBufferSize) : 0,
                   pBufferStart, (pBufferStart) ? (*pBufferStart) : 0);
    return(ncpStatus);
}            

NCP_API ncp_st_t
ncp_task_buffer_refill(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint8_t  txQueueId,
    ncp_uint32_t numTaskBuffers,
    ncp_uint32_t *pNumRefilled,
    void **pTaskBuffers,
    ncp_bool_t wait) 
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    ncp_task_tqs_swState_t *pTqs = NULL;    
    ncp_task_pcq_t *p_oPCQ = NULL;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);    
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    NCP_TASK_LOCK_FLAGS(txqLockFlags); 

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_buffer_refill_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p txQueueId=%u numTaskBuffers=%u pNumRefilled=%p pTaskBuffers=%p wait=%u"
                   "\n",
                   tqsHdl, txQueueId, numTaskBuffers, pNumRefilled, pTaskBuffers, wait);
    NCP_TASKIO_CHECK((NULL != pNumRefilled), NCP_ST_INVALID_PARAMETER);
    *pNumRefilled = 0;
    
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);    
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    NCP_TASKIO_CHECK((txQueueId == NCP_TASK_TXQ_0 
               || txQueueId == NCP_TASK_TXQ_1),
               NCP_ST_INVALID_PARAMETER);    
    NCP_TASKIO_CHECK((NULL != pTaskBuffers), NCP_ST_INVALID_PARAMETER); 

    if (NCP_TASK_RESTRICT_BULK_APIS)
    {    
        NCP_TASKIO_CHECK((numTaskBuffers <= NCP_TASK_API_MAX_BULK_ITEM_COUNT),
                  NCP_ST_TASK_BULK_REQUEST_TOO_BIG);             
    }
    NCP_TASKIO_CHECK((TRUE == pvtTqsHdl->useFlags.useTxQueue[txQueueId]), 
              NCP_ST_TASK_TQS_SHARING_VIOLATION);
    NCP_TASKIO_CHECK((TRUE != pvtTqsHdl->inOpcqCallbackDoneFn[txQueueId]), 
                      NCP_ST_TASK_SENDQUEUE_CALLBACK_RECURSION_DETECTED);              
       
    pTqs = pvtTqsHdl->pTqs;
    NCP_TASK_PREFETCH_PGIT_FOR_WRITE(pTqs->pCpuPgit);
    NCP_TASK_PREFETCH_PGIT(pTqs->pNcaPgit);    
           
    if (NCP_TASK_TXQ_0 == txQueueId)
    {
        p_oPCQ = &pTqs->txQ0;
    }
    else
    {
        p_oPCQ = &pTqs->txQ1;
    }  

    if (p_oPCQ->shared)
    {
        NCP_CALL(NCP_TASK_CLAIM_LOCK_HDL(&p_oPCQ->qLock, txqLockFlags, &unlockRequired));
    }  

    NCP_TASK_PREFETCH_PCQ_ENTRY_FOR_WRITE(p_oPCQ->u.opcq_info.pOPCQentry);
            
    /* TODO - make inline */
    ncpStatus = ncp_task_bulk_buffer_free(pvtTqsHdl,
                                  p_oPCQ,
                                  NCP_TASK_CPU_POOL_ALIAS,
                                  numTaskBuffers,
                                  pNumRefilled,
                                  pTaskBuffers,
                                  FALSE, /* no mRef for CPU pools */
                                  wait);

    if (ncpStatus != NCP_ST_SUCCESS &&
        ncpStatus != NCP_ST_TASK_SEND_QUEUE_FULL)
    {
        NCP_CALL(ncpStatus);
    }
                     
NCP_RETURN_LABEL
        
    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_buffer_refill_ok);
        NCP_TASK_ADD_TXSTAT(pvtTqsHdl->pTqs, BuffRefills, txQueueId, *pNumRefilled);          
    }
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_buffer_refill_err);
    }
    
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK_HDL(&p_oPCQ->qLock, txqLockFlags, &unlockRequired));
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_buffer_refill_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d "
                   "pNumRefilled=%p(%u) pTaskBuffers=%p(%p)"
                   "\n",
                   ncpStatus,
                   pNumRefilled, (pNumRefilled) ? (*pNumRefilled) : 0,
                   pTaskBuffers, (pTaskBuffers) ? (*pTaskBuffers) : 0);
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_refill(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint8_t txQueueId,
    ncp_uint32_t numTasks, 
    ncp_uint32_t *pNumTasksRefilled,
    ncp_task_header_t **pHeaders,
    ncp_bool_t issueCompletions,
    ncp_bool_t wait) 
{
#if defined(NCP_DEV_SOCKET)  
    return NCP_ST_NOT_IMPLEMENTED;
#else
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    ncp_task_tqs_swState_t *pTqs;
    ncp_task_pcq_t *p_oPCQ=NULL;
    ncp_uint32_t numSent = 0;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_refill_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p txQueueId=%u numTasks=%d pNumTasksRefilled=%p pHeaders=%p issueCompletions=%u wait=%u"
                   "\n",
                   tqsHdl, txQueueId, numTasks, pNumTasksRefilled, pHeaders, issueCompletions, wait);
    NCP_TASKIO_CHECK((NULL != pNumTasksRefilled), NCP_ST_INVALID_PARAMETER);
    *pNumTasksRefilled = 0;
    
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    NCP_TASKIO_CHECK((txQueueId == NCP_TASK_TXQ_0 
               || txQueueId == NCP_TASK_TXQ_1),
               NCP_ST_INVALID_PARAMETER);    

    NCP_TASKIO_CHECK((NULL != pHeaders), NCP_ST_INVALID_PARAMETER);        
    NCP_TASKIO_CHECK(numTasks != 0, NCP_ST_INVALID_PARAMETER);
    NCP_TASKIO_CHECK((TRUE != pvtTqsHdl->inOpcqCallbackDoneFn[txQueueId]), 
                     NCP_ST_TASK_SENDQUEUE_CALLBACK_RECURSION_DETECTED);
    NCP_TASKIO_CHECK(!(issueCompletions 
        && (pvtTqsHdl->pTqs->rxQ.u.ipcq_info.autoCompletionMode)),
        NCP_ST_TASK_RX_QUEUE_IS_AUTOMATIC_COMPLETION);
    if (issueCompletions)
    {
        NCP_TASKIO_CHECK(numTasks <= pvtTqsHdl->completionsOwed,
                  NCP_ST_TASK_TOO_MANY_TASK_COMPLETIONS);
    }

    if (NCP_TASK_RESTRICT_BULK_APIS)
    {    
        NCP_TASKIO_CHECK((numTasks <= NCP_TASK_API_MAX_BULK_ITEM_COUNT),
                  NCP_ST_TASK_BULK_REQUEST_TOO_BIG);             
    }
                  
    NCP_TASKIO_CHECK((TRUE == pvtTqsHdl->useFlags.useTxQueue[txQueueId]), 
              NCP_ST_TASK_TQS_SHARING_VIOLATION);
    
    pTqs = pvtTqsHdl->pTqs;
    NCP_TASK_PREFETCH_PGIT_FOR_WRITE(pTqs->pCpuPgit);
    NCP_TASK_PREFETCH_PGIT(pTqs->pNcaPgit);    
                        
    if (NCP_TASK_TXQ_0 == txQueueId)
    {
        p_oPCQ = &pTqs->txQ0;
    }
    else
    {
        p_oPCQ = &pTqs->txQ1;
    }  

    if (p_oPCQ->shared)
    {
        NCP_CALL(NCP_TASK_CLAIM_LOCK_HDL(&p_oPCQ->qLock, txqLockFlags, &unlockRequired));
    } 

    NCP_TASK_PREFETCH_PCQ_ENTRY_FOR_WRITE(p_oPCQ->u.opcq_info.pOPCQentry);
        
    ncpStatus = ncp_task_bulk_task_free(
                pvtTqsHdl,
                p_oPCQ,
                numTasks,
                &numSent,
                pHeaders,
                TRUE, /* freeHeaders */
                issueCompletions,
                wait);

    if (ncpStatus != NCP_ST_SUCCESS &&
        ncpStatus != NCP_ST_TASK_SEND_QUEUE_FULL)
    {
        NCP_CALL(ncpStatus);
    }
        
NCP_RETURN_LABEL

    if (issueCompletions)
    {    
        pvtTqsHdl->completionsIssued[txQueueId] += numSent;
        NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                              ncp_xlf_task_refill_txCompletionInfo,
                              NCP_MSG_DEBUG,
                              "in refill: TxQ_%d completions issued incremented by %d, total = %d\r\n",
                              txQueueId,
                              numSent,
                              pvtTqsHdl->completionsIssued[txQueueId]);
    }

    *pNumTasksRefilled = numSent;
    
    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_refill_ok); 
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_refill_err);      
    }
    
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    
    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK_HDL(&p_oPCQ->qLock, txqLockFlags, &unlockRequired));
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_refill_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d pNumTasksRefilled=%p(%u) pHeaders=%p(%p)"
                   "\n",
                   ncpStatus,
                   pNumTasksRefilled, (pNumTasksRefilled) ? (*pNumTasksRefilled) : 0,
                   pHeaders, (pHeaders) ? (*pHeaders) : 0);
    return(ncpStatus);
#endif /* SOCKET */    
}

NCP_API ncp_st_t
ncp_task_quota_transfer(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint8_t txQueueId,
    ncp_uint32_t numTasks,
    ncp_uint32_t *pNumTransferred,
    ncp_task_header_t **pTasks,
    ncp_task_transfer_done_fn_t *pFns,
    void **pTransferDoneArgs,
    ncp_bool_t *pTransferHeader,
    ncp_uint8_t destTQS,
    ncp_bool_t wait)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    ncp_task_tqs_swState_t *pTqs = NULL;
    ncp_task_pcq_t *p_oPCQ = NULL;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    NCP_TASK_LOCK_FLAGS(txqLockFlags);

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_quota_transfer_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p txQueueId=%u numTasks=%u pNumTransferred=%p pTasks=%p pFns=%p pTransferDoneArgs=%p pTransferHeader=%p destTQS=%u wait=%u"
                   "\n",
                   tqsHdl, txQueueId, numTasks, pNumTransferred, pTasks, pFns, pTransferDoneArgs, pTransferHeader, destTQS, wait);
    NCP_TASKIO_CHECK((NULL != pNumTransferred), NCP_ST_INVALID_PARAMETER);
    *pNumTransferred = 0;

    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_TASKIO_CHECK((txQueueId == NCP_TASK_TXQ_0
                   || txQueueId == NCP_TASK_TXQ_1),
               NCP_ST_INVALID_PARAMETER);

    if (pFns != NULL)
    {
        NCP_TASKIO_CHECK((NULL != pTransferDoneArgs),
                         NCP_ST_INVALID_PARAMETER);
    }
    NCP_TASKIO_CHECK((NULL != pTasks), NCP_ST_INVALID_PARAMETER);
    NCP_TASKIO_CHECK((NULL != pTransferHeader), NCP_ST_INVALID_PARAMETER);

    if (NCP_TASK_RESTRICT_BULK_APIS)
    {
        NCP_TASKIO_CHECK((numTasks <= NCP_TASK_API_MAX_BULK_ITEM_COUNT),
                  NCP_ST_TASK_BULK_REQUEST_TOO_BIG);
    }

    NCP_TASKIO_CHECK((TRUE == pvtTqsHdl->useFlags.useTxQueue[txQueueId]),
              NCP_ST_TASK_TQS_SHARING_VIOLATION);
    NCP_TASKIO_CHECK((TRUE != pvtTqsHdl->inOpcqCallbackDoneFn[txQueueId]), 
                      NCP_ST_TASK_SENDQUEUE_CALLBACK_RECURSION_DETECTED);              

    pTqs = pvtTqsHdl->pTqs;
    NCP_TASK_PREFETCH_PGIT_FOR_WRITE(pTqs->pCpuPgit);
    NCP_TASK_PREFETCH_PGIT(pTqs->pNcaPgit);

    if (NCP_TASK_TXQ_0 == txQueueId)
    {
        p_oPCQ = &pTqs->txQ0;
    }
    else
    {
        p_oPCQ = &pTqs->txQ1;
    }

    if (p_oPCQ->shared)
    {
        NCP_CALL(NCP_TASK_CLAIM_LOCK_HDL(&p_oPCQ->qLock, txqLockFlags, &unlockRequired));
    }

    NCP_TASK_PREFETCH_PCQ_ENTRY_FOR_WRITE(p_oPCQ->u.opcq_info.pOPCQentry);

    /*
     * Force any send done callbacks to be executed now.
     * This ensures that we do not overflow the send done PCQ.
     */

    NCP_TASK_PROCESS_SEND_DONE(pvtTqsHdl, txQueueId);

    if (0 != numTasks)
    {
        ncpStatus = ncp_task_bulk_task_quota_transfer(
                pvtTqsHdl,
                p_oPCQ,
                destTQS,
                numTasks,
                pTasks,
                pNumTransferred,
                pTransferHeader,
                pFns,
                pTransferDoneArgs,
                wait);

        if (ncpStatus != NCP_ST_SUCCESS &&
            ncpStatus != NCP_ST_TASK_SEND_QUEUE_FULL)
        {
            NCP_CALL(ncpStatus);
        }
    }

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_quota_transfer_ok);
    }
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_quota_transfer_err);
    }

    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK_HDL(&p_oPCQ->qLock, txqLockFlags, &unlockRequired));
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_quota_transfer_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d "
                   "pNumTransferred=%p(%u)"
                   "\n",
                   ncpStatus, pNumTransferred, (pNumTransferred) ? (*pNumTransferred) : 0);
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_buffer_quota_transfer(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint8_t txQueueId,
    ncp_uint32_t numDescs,
    ncp_uint32_t *pNumTransferred,
    ncp_task_buffer_desc_t *pDescs,
    ncp_task_buffer_transfer_done_fn_t *pFns,
    void **pTransferDoneArgs,
    ncp_uint8_t destTQS,
    ncp_bool_t wait)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    ncp_task_tqs_swState_t *pTqs = NULL;
    ncp_task_pcq_t *p_oPCQ = NULL;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    NCP_TASK_LOCK_FLAGS(txqLockFlags);


    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_buffer_quota_transfer_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p txQueueId=%u numDescs=%u pNumTransferred=%p pDescs=%p pFns=%p pTransferDoneArgs=%p destTQS=%u wait=%u"
                   "\n",
                   tqsHdl, txQueueId, numDescs, pNumTransferred,
                   pDescs, pFns, pTransferDoneArgs, destTQS, wait
        );

    NCP_TASKIO_CHECK((NULL != pNumTransferred), NCP_ST_INVALID_PARAMETER);
    *pNumTransferred = 0;

    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_TASKIO_CHECK((txQueueId == NCP_TASK_TXQ_0
                   || txQueueId == NCP_TASK_TXQ_1),
               NCP_ST_INVALID_PARAMETER);
    if (pFns != NULL)
    {
        NCP_TASKIO_CHECK((NULL != pTransferDoneArgs),
                            NCP_ST_INVALID_PARAMETER);
    }
    NCP_TASKIO_CHECK((NULL != pDescs), NCP_ST_INVALID_PARAMETER);

    if (NCP_TASK_RESTRICT_BULK_APIS)
    {
        NCP_TASKIO_CHECK((numDescs <= NCP_TASK_API_MAX_BULK_ITEM_COUNT),
                  NCP_ST_TASK_BULK_REQUEST_TOO_BIG);
    }

    NCP_TASKIO_CHECK((TRUE == pvtTqsHdl->useFlags.useTxQueue[txQueueId]),
              NCP_ST_TASK_TQS_SHARING_VIOLATION);
    NCP_TASKIO_CHECK((TRUE != pvtTqsHdl->inOpcqCallbackDoneFn[txQueueId]), 
                      NCP_ST_TASK_SENDQUEUE_CALLBACK_RECURSION_DETECTED);              

    pTqs = pvtTqsHdl->pTqs;
    NCP_TASK_PREFETCH_PGIT_FOR_WRITE(pTqs->pCpuPgit);
    NCP_TASK_PREFETCH_PGIT(pTqs->pNcaPgit);

    if (NCP_TASK_TXQ_0 == txQueueId)
    {
        p_oPCQ = &pTqs->txQ0;
    }
    else
    {
        p_oPCQ = &pTqs->txQ1;
    }

    if (p_oPCQ->shared)
    {
        NCP_CALL(NCP_TASK_CLAIM_LOCK_HDL(&p_oPCQ->qLock, txqLockFlags, &unlockRequired));
    }

    NCP_TASK_PREFETCH_PCQ_ENTRY_FOR_WRITE(p_oPCQ->u.opcq_info.pOPCQentry);

    /*
     * Force any send done callbacks to be executed now.
     * This ensures that we do not overflow the send done PCQ.
     */

    NCP_TASK_PROCESS_SEND_DONE(pvtTqsHdl, txQueueId);

    if (0 != numDescs)
    {
        ncpStatus = ncp_task_bulk_buffer_quota_transfer(
                pvtTqsHdl,
                p_oPCQ,
                destTQS,
                numDescs,
                pDescs,
                pNumTransferred,
                pFns,
                pTransferDoneArgs,
                wait);

        if (ncpStatus != NCP_ST_SUCCESS &&
            ncpStatus != NCP_ST_TASK_SEND_QUEUE_FULL)
        {
            NCP_CALL(ncpStatus);
        }
    }

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_buffer_quota_transfer_ok);
    }
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_buffer_quota_transfer_err);
    }

    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK_HDL(&p_oPCQ->qLock, txqLockFlags, &unlockRequired));
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_buffer_quota_transfer_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d pNumTransferred=%p(%u)"
                   "\n",
                   ncpStatus, pNumTransferred, (pNumTransferred) ? (*pNumTransferred) : 0);

    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_refCnt_increment(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint8_t txQueueId,
    ncp_uint32_t numTasks,
    ncp_uint32_t *pNumIncremented,
    ncp_task_header_t **pTasks,
    ncp_task_refCnt_inc_done_fn_t *pFns,
    void **pRefCntIncDoneArgs,
    ncp_bool_t wait)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    ncp_task_tqs_swState_t *pTqs = NULL;
    ncp_task_pcq_t *p_oPCQ = NULL;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    NCP_TASK_LOCK_FLAGS(txqLockFlags);


    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_refCnt_increment_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p txQueueId=%u numTasks=%u pNumIncremented=%p "
                   "pTasks=%p pFns=%p pRefCntIncDoneArgs=%p wait=%u"
                   "\n",
                   tqsHdl, txQueueId, numTasks,
                   pNumIncremented, pTasks, pFns, pRefCntIncDoneArgs, wait
        );
    NCP_TASKIO_CHECK((NULL != pNumIncremented), NCP_ST_INVALID_PARAMETER);
    *pNumIncremented = 0;

    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_TASKIO_CHECK((txQueueId == NCP_TASK_TXQ_0
                   || txQueueId == NCP_TASK_TXQ_1),
               NCP_ST_INVALID_PARAMETER);
    NCP_TASKIO_CHECK((NULL != pFns), NCP_ST_INVALID_PARAMETER);
    NCP_TASKIO_CHECK((NULL != pRefCntIncDoneArgs), NCP_ST_INVALID_PARAMETER);
    NCP_TASKIO_CHECK((NULL != pTasks), NCP_ST_INVALID_PARAMETER);

    if (NCP_TASK_RESTRICT_BULK_APIS)
    {
        NCP_TASKIO_CHECK((numTasks <= NCP_TASK_API_MAX_BULK_ITEM_COUNT),
                  NCP_ST_TASK_BULK_REQUEST_TOO_BIG);
    }

    NCP_TASKIO_CHECK((TRUE == pvtTqsHdl->useFlags.useTxQueue[txQueueId]),
              NCP_ST_TASK_TQS_SHARING_VIOLATION);
    NCP_TASKIO_CHECK((TRUE != pvtTqsHdl->inOpcqCallbackDoneFn[txQueueId]), 
                      NCP_ST_TASK_SENDQUEUE_CALLBACK_RECURSION_DETECTED);              

    pTqs = pvtTqsHdl->pTqs;
    NCP_TASK_PREFETCH_PGIT_FOR_WRITE(pTqs->pCpuPgit);
    NCP_TASK_PREFETCH_PGIT(pTqs->pNcaPgit);

    if (NCP_TASK_TXQ_0 == txQueueId)
    {
        p_oPCQ = &pTqs->txQ0;
    }
    else
    {
        p_oPCQ = &pTqs->txQ1;
    }

    if (p_oPCQ->shared)
    {
        NCP_CALL(NCP_TASK_CLAIM_LOCK_HDL(&p_oPCQ->qLock, txqLockFlags, &unlockRequired));
    }

    NCP_TASK_PREFETCH_PCQ_ENTRY_FOR_WRITE(p_oPCQ->u.opcq_info.pOPCQentry);

    /*
     * Force any send done callbacks to be executed now.
     * This ensures that we do not overflow the send done PCQ.
     */

    NCP_TASK_PROCESS_SEND_DONE(pvtTqsHdl, txQueueId);

    if (0 != numTasks)
    {
        ncpStatus = ncp_task_bulk_task_refCnt_increment(
                pvtTqsHdl,
                p_oPCQ,
                numTasks,
                pTasks,
                pNumIncremented,
                pFns,
                pRefCntIncDoneArgs,
                wait);

        if (ncpStatus != NCP_ST_SUCCESS &&
            ncpStatus != NCP_ST_TASK_SEND_QUEUE_FULL)
        {
            NCP_CALL(ncpStatus);
        }
    }

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_refCnt_increment_ok);
    }
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl, api_task_refCnt_increment_err);
    }

    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK_HDL(&p_oPCQ->qLock, txqLockFlags, &unlockRequired));
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_refCnt_increment_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d pNumIncremented=%p(%u)"
                   "\n",
                   ncpStatus,
                   pNumIncremented, (pNumIncremented) ? (*pNumIncremented) : 0
        );
    return ncpStatus;
}

NCP_API ncp_st_t
ncp_task_buffer_refCnt_increment(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint8_t txQueueId,
    ncp_uint32_t numDescs,
    ncp_uint32_t *pNumIncremented,
    ncp_task_buffer_desc_t *pDescs,
    ncp_task_buffer_refCnt_inc_done_fn_t *pFns,
    void **pRefCntIncDoneArgs,
    ncp_bool_t wait)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    ncp_task_tqs_swState_t *pTqs = NULL;
    ncp_task_pcq_t *p_oPCQ = NULL;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    NCP_TASK_LOCK_FLAGS(txqLockFlags);

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_buffer_refCnt_increment_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p txQueueId=%u numDescs=%u pNumIncremented=%p "
                   "pDescs=%p pFns=%p pRefCntIncDoneArgs=%p wait=%u"
                   "\n",
                   tqsHdl, txQueueId, numDescs, pNumIncremented,
                   pDescs, pFns, pRefCntIncDoneArgs, wait
        );

    NCP_TASKIO_CHECK((NULL != pNumIncremented), NCP_ST_INVALID_PARAMETER);
    *pNumIncremented = 0;

    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_TASKIO_CHECK((txQueueId == NCP_TASK_TXQ_0
                   || txQueueId == NCP_TASK_TXQ_1),
               NCP_ST_INVALID_PARAMETER);
    NCP_TASKIO_CHECK((NULL != pFns), NCP_ST_INVALID_PARAMETER);
    NCP_TASKIO_CHECK((NULL != pRefCntIncDoneArgs), NCP_ST_INVALID_PARAMETER);
    NCP_TASKIO_CHECK((NULL != pDescs), NCP_ST_INVALID_PARAMETER);

    if (NCP_TASK_RESTRICT_BULK_APIS)
    {
        NCP_TASKIO_CHECK((numDescs <= NCP_TASK_API_MAX_BULK_ITEM_COUNT),
                  NCP_ST_TASK_BULK_REQUEST_TOO_BIG);
    }

    NCP_TASKIO_CHECK((TRUE == pvtTqsHdl->useFlags.useTxQueue[txQueueId]),
              NCP_ST_TASK_TQS_SHARING_VIOLATION);
    NCP_TASKIO_CHECK((TRUE != pvtTqsHdl->inOpcqCallbackDoneFn[txQueueId]), 
                      NCP_ST_TASK_SENDQUEUE_CALLBACK_RECURSION_DETECTED);              

    pTqs = pvtTqsHdl->pTqs;
    NCP_TASK_PREFETCH_PGIT_FOR_WRITE(pTqs->pCpuPgit);
    NCP_TASK_PREFETCH_PGIT(pTqs->pNcaPgit);

    if (NCP_TASK_TXQ_0 == txQueueId)
    {
        p_oPCQ = &pTqs->txQ0;
    }
    else
    {
        p_oPCQ = &pTqs->txQ1;
    }

    if (p_oPCQ->shared)
    {
        NCP_CALL(NCP_TASK_CLAIM_LOCK_HDL(&p_oPCQ->qLock, txqLockFlags, &unlockRequired));
    }

    NCP_TASK_PREFETCH_PCQ_ENTRY_FOR_WRITE(p_oPCQ->u.opcq_info.pOPCQentry);

    /*
     * Force any send done callbacks to be executed now.
     * This ensures that we do not overflow the send done PCQ.
     */

    NCP_TASK_PROCESS_SEND_DONE(pvtTqsHdl, txQueueId);

    if (0 != numDescs)
    {
        ncpStatus = ncp_task_bulk_buffer_refCnt_increment(
                pvtTqsHdl,
                p_oPCQ,
                numDescs,
                pDescs,
                pNumIncremented,
                pFns,
                pRefCntIncDoneArgs,
                wait);

        if (ncpStatus != NCP_ST_SUCCESS &&
            ncpStatus != NCP_ST_TASK_SEND_QUEUE_FULL)
        {
            NCP_CALL(ncpStatus);
        }
    }

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_refCnt_increment_ok);
    }
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl, api_task_refCnt_increment_err);
    }

    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK_HDL(&p_oPCQ->qLock, txqLockFlags, &unlockRequired));
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_buffer_refCnt_increment_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d pNumIncremented=%p(%u) "
                   "\n",
                   ncpStatus, pNumIncremented, (pNumIncremented) ? (*pNumIncremented) : 0
        );
    return ncpStatus;
}

NCP_API ncp_st_t
ncp_task_tqs_queue_group_set(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t tqsId,
    ncp_task_queue_group_set_t pGrp[8],
    ncp_uint8_t numQueueGroups)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_dev_hdl_t dev;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tqs_queue_group_set_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p tqsId=%u pGrp=%p numQueueGroups=%u"
                   "\n",
                   ncpHdl, tqsId, pGrp, numQueueGroups
        );
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK(tqsId < NCP_NCAV3_MAX_NUM_TQSETS, NCP_ST_INVALID_PARAMETER);
    NCP_CHECK((NULL != pGrp), NCP_ST_INVALID_PARAMETER);
    NCP_CHECK((numQueueGroups <= 8), NCP_ST_INVALID_PARAMETER);

    dev = ncp_dev_hdls[((ncp_t *) ncpHdl)->id];

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    NCP_CALL(ncp_ncav3_tqs_queue_group_set(
        dev,
        tqsId,
        pGrp,
        numQueueGroups));

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_tqs_queue_group_set_ok);
    }
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_tqs_queue_group_set_err);
    }

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tqs_queue_group_set_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "\n",
                   ncpStatus
        );
    return(ncpStatus);
}


NCP_API ncp_st_t
ncp_task_tqs_queue_group_get(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t tqsId,
    ncp_task_queue_group_set_t pGrp[8],
    ncp_uint8_t *pNumQueueGroups)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tqs_queue_group_get_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p tqsId=%u pGrp=%p pNumQueueGroups=%p"
                   "\n",
                   ncpHdl, tqsId, pGrp, pNumQueueGroups);
    NCP_CHECK((NULL != pNumQueueGroups), NCP_ST_INVALID_PARAMETER);
    *pNumQueueGroups = 0;

    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK(tqsId < NCP_NCAV3_MAX_NUM_TQSETS, NCP_ST_INVALID_PARAMETER);
    NCP_CHECK((NULL != pGrp), NCP_ST_INVALID_PARAMETER);

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    NCP_CALL(ncp_ncav3_tqs_queue_group_get(
        myDevHdl,
        tqsId,
        pGrp,
        pNumQueueGroups));

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_tqs_queue_group_get_ok);
    }
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_tqs_queue_group_get_err);
    }

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tqs_queue_group_get_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d pNumQueueGroups=%p(%u)"
                   "\n",
                   ncpStatus,
                   pNumQueueGroups, (pNumQueueGroups) ? (*pNumQueueGroups) : 0
        );
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_nca_queue_group_set(
    ncp_hdl_t    ncpHdl,
    ncp_uint32_t ncaQueueId,
    ncp_uint32_t queueGroupId) 
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)
    ncp_dev_hdl_t dev;

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_nca_queue_group_set_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p ncaQueueId=%u queueGroupId=%u"
                   "\n",
                   ncpHdl, ncaQueueId, queueGroupId
        );

    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK(ncaQueueId < NCP_NCAV3_MAX_NUM_NCAQS, NCP_ST_INVALID_PARAMETER);
    NCP_CHECK(queueGroupId < NCP_NCAV3_MAX_NUM_QUEUE_GROUPS,
        NCP_ST_INVALID_PARAMETER);

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    dev = ncp_dev_hdls[((ncp_t *) ncpHdl)->id];

    NCP_CALL(ncp_ncav3_nca_queue_group_set(
        dev,
        ncaQueueId,
        queueGroupId));

NCP_RETURN_LABEL

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
                   ncp_task_nca_queue_group_set_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "\n",
                   ncpStatus
        );
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_queue_group_membership_get(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t ncaQueueId,
    ncp_uint32_t *pQueueGroupId) 
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_task_queue_group_membership_get_entry,
                          NCP_MSG_ENTRY,
                          "ncpHdl=%p ncaQueueId=%u pQueueGroupId=%p"
                          "\n",
                          ncpHdl, (ncaQueueId), pQueueGroupId);

    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK(ncaQueueId < NCP_NCAV3_MAX_NUM_NCAQS, NCP_ST_INVALID_PARAMETER);
    NCP_CHECK((NULL != pQueueGroupId), NCP_ST_INVALID_PARAMETER);    

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    NCP_CALL(ncp_ncav3_queue_group_membership_get(
        myDevHdl,
        ncaQueueId,
        pQueueGroupId));
    
NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_queue_group_membership_get_ok); 
    }        
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_queue_group_membership_get_err);      
    }
    
    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);     
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_task_queue_group_membership_get_exit,
                          NCP_MSG_EXIT,
                          "ncpStatus=%d "
                          "pQueueGroupId=%p(%u)"
                          "\n",
                          ncpStatus,
                          pQueueGroupId, (pQueueGroupId) ? (*pQueueGroupId) : 0);
    return(ncpStatus);
}
    
NCP_API ncp_st_t
ncp_task_queue_group_name_get(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t queueGroupId,
    ncp_task_resource_name_t *name) 
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_queue_group_name_get_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p queueGroupId=%u name=%p"
                   "\n",
                   ncpHdl, queueGroupId, name
        );

    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK(queueGroupId < NCP_NCAV3_MAX_NUM_QUEUE_GROUPS,
        NCP_ST_INVALID_PARAMETER);
    NCP_CHECK((NULL != name), NCP_ST_INVALID_PARAMETER);
    
    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
        
    NCP_CALL(ncp_ncav3_queue_group_name_get(myDevHdl, queueGroupId, name));

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_queue_group_name_get_ok); 
    }        
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_queue_group_name_get_err);      
    }

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_queue_group_name_get_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d name=%p(%s)"
                   "\n",
                   ncpStatus, name, ((name) ? (name->name) : "(null)")
        );
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_tqs_name_get(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t tqsId,
    ncp_task_resource_name_t *pResourceName) 
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tqs_name_get_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p tqsId=%u pResourceName=%p"
                   "\n",
                   ncpHdl, tqsId, pResourceName
        );

    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK(tqsId < NCP_NCAV3_MAX_NUM_TQSETS, NCP_ST_INVALID_PARAMETER);
    NCP_CHECK((NULL != pResourceName), NCP_ST_INVALID_PARAMETER); 
    
    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
 
    NCP_CALL(ncp_ncav3_tqs_name_get(myDevHdl, tqsId, pResourceName));

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_tqs_name_get_ok); 
    }        
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_tqs_name_get_err);      
    }

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tqs_name_get_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d pResourceName=%p(%s)"
                   "\n",
                   ncpStatus, pResourceName, ((pResourceName) ? (pResourceName->name) : "(null)"));

    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_nca_queue_name_get(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t ncaQueueId,
    ncp_task_resource_name_t *name) 
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_nca_queue_name_get_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p ncaQueueId=%u name=%p"
                   "\n",
                   ncpHdl, ncaQueueId, name
        );

    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK(ncaQueueId < NCP_NCAV3_MAX_NUM_NCAQS,
               NCP_ST_INVALID_PARAMETER);
    NCP_CHECK((NULL != name), NCP_ST_INVALID_PARAMETER);     

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    NCP_CALL(ncp_ncav3_nca_queue_name_get(myDevHdl, ncaQueueId, name));

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_nca_queue_name_get_ok); 
    }        
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_nca_queue_name_get_err);      
    }

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_nca_queue_name_get_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d name=%p(%s)"
                   "\n",
                   ncpStatus, name, ((name) ? (name->name) : "(null)")
        );
    return(ncpStatus);
}
    
NCP_API ncp_st_t
ncp_task_queue_group_id_get(
    ncp_hdl_t ncpHdl,
    ncp_task_resource_name_t *name,
    ncp_uint32_t *pQueueGroupId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_queue_group_id_get_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p name=%s pQueueGroupId=%p"
                   "\n",
                   ncpHdl, ((name) ? (name->name) : "(null)"), pQueueGroupId
        );
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK((NULL != pQueueGroupId), NCP_ST_INVALID_PARAMETER);

    /* Validate supplied name */
    NCP_CHECK((NULL != name), NCP_ST_INVALID_PARAMETER);
    NCP_TASK_VALIDATE_RESOURCE_NAME(name, NCP_ST_TASK_BAD_RESOURCE_NAME);

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    NCP_CALL(ncp_ncav3_queue_group_id_get(myDevHdl, name, pQueueGroupId));

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_queue_group_id_get_ok);
    }
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_queue_group_id_get_err);
    }

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_queue_group_id_get_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d pQueueGroupId=%p(%u)"
                   "\n",
                   ncpStatus,
                   pQueueGroupId, ((pQueueGroupId) ? (*pQueueGroupId) : 0));
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_tqs_id_get(
    ncp_hdl_t ncpHdl,
    ncp_task_resource_name_t *pResourceName,
    ncp_uint32_t *pTqsId) 
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tqs_id_get_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p pResourceName=%s pTqsId=%p"
                   "\n",
                   ncpHdl, ((pResourceName) ? (pResourceName->name) : "(null)"),
                   pTqsId);
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK((NULL != pTqsId), NCP_ST_INVALID_PARAMETER);  

    /* Validate supplied name */  
    NCP_TASK_VALIDATE_RESOURCE_NAME(pResourceName,
        NCP_ST_TASK_BAD_RESOURCE_NAME);              
    
    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    NCP_CALL(ncp_ncav3_tqs_id_get(myDevHdl, pResourceName, pTqsId));

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_tqs_id_get_ok); 
    }        
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_tqs_id_get_err);      
    }
    
    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tqs_id_get_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d pTqsId=%p(%u)"
                   "\n",
                   ncpStatus, pTqsId, ((pTqsId) ? (*pTqsId) : 0));
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_nca_queue_id_get(
    ncp_hdl_t ncpHdl,
    ncp_task_resource_name_t *name,
    ncp_uint32_t *pNcaQueueId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_task_nca_queue_id_get_entry,
                          NCP_MSG_ENTRY,
                          "ncpHdl=%p name=%s pNcaQueueId=%p"
                          "\n",
                          ncpHdl, (name) ? (name->name) : "(null)",
                          pNcaQueueId);

    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK((NULL != pNcaQueueId), NCP_ST_INVALID_PARAMETER);
    NCP_TASK_VALIDATE_RESOURCE_NAME(name, NCP_ST_TASK_BAD_RESOURCE_NAME);

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    NCP_CALL(ncp_ncav3_nca_queue_id_get(myDevHdl, name, pNcaQueueId));

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_nca_queue_id_get_ok);
    }
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_nca_queue_id_get_err);
    }

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_task_nca_queue_id_get_exit,
                          NCP_MSG_EXIT,
                          "ncpStatus=%d(%s) *pNcaQueueId=%d\n",
                          ncpStatus, ncp_status_get(ncpStatus),
                          (pNcaQueueId) ? (*pNcaQueueId) : 0
        );
    return(ncpStatus);
}
NCP_API ncp_st_t
ncp_task_nca_queue_profile_name_get(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t profileId,
    ncp_task_resource_name_t *name)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)
    ncp_ncav3_task_receive_queue_config_t *queueConfig;

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_nca_queue_profile_name_get_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p profileId=%u name=%p"
                   "\n",
                   ncpHdl, profileId, name);
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);

    queueConfig = &pNcpTaskSwState->nca->configInfo.taskReceiveQueues;

    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK(profileId < queueConfig->numProfiles,
              NCP_ST_INVALID_PARAMETER);
    NCP_CHECK((NULL != name), NCP_ST_INVALID_PARAMETER);

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    NCP_CALL(ncp_ncav3_nca_queue_profile_name_get(myDevHdl, profileId, name));

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_nca_queue_profile_name_get_ok);
    }
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_nca_queue_profile_name_get_err);
    }

    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_nca_queue_profile_name_get_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d name=%s"
                   "\n",
                   ncpStatus, ((name) ? (name->name) : "(null)"));
    return(ncpStatus);
}
NCP_API ncp_st_t
ncp_task_nca_queue_profile_id_get(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t ncaQueueId,
    ncp_uint32_t *pProfileId) 
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_xlf_task_nca_queue_profile_id_get_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p ncaQueueId=%u pProfileId=%p"
                   "\n",
                   ncpHdl, ncaQueueId, pProfileId
        );

    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK((NULL != pProfileId), NCP_ST_INVALID_PARAMETER); 
    NCP_CHECK(ncaQueueId < NCP_NCAV3_MAX_NUM_NCAQS, NCP_ST_INVALID_PARAMETER);

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    NCP_CALL(ncp_ncav3_nca_queue_profile_id_get(
        myDevHdl,
        ncaQueueId,
        pProfileId));

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_nca_queue_profile_id_get_ok); 
    }        
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_nca_queue_profile_id_get_err);      
    }
    
    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);     
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_xlf_task_nca_queue_profile_id_get_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d pProfileId=%p(%u)"
                   "\n",
                   ncpStatus, pProfileId, (pProfileId) ? *pProfileId : 0);
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_tqs_cpu_affinity_get(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t tqsId,
    ncp_uint32_t *pCpuId) 
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_xlf_task_tqs_cpu_affinity_get_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p tqsId=%u pCpuId=%p"
                   "\n",
                   ncpHdl, tqsId, pCpuId
            );

    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK((NULL != pCpuId), NCP_ST_INVALID_PARAMETER);    
    NCP_CHECK(tqsId < NCP_NCAV3_NUM_CPU_TQSETS, NCP_ST_INVALID_PARAMETER);

    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    
    if (pNcpTaskSwState->domainId !=  
        pNcpTaskSwState->tqsSwState[tqsId].domainId)    
    {    
        NCP_CALL(NCP_ST_TASK_QUESET_NOT_IN_LOCAL_DOMAIN);
    }  

    if (FALSE == pNcpTaskSwState->tqsSwState[tqsId].configured)
    {
        NCP_CALL(NCP_ST_TASK_TQS_NOT_CONFIGURED);
    }

    *pCpuId = pNcpTaskSwState->tqsSwState[tqsId].coreId;
    
NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_tqs_cpu_affinity_get_ok); 
    }        
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_tqs_cpu_affinity_get_err);      
    }
   
    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);     
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_xlf_task_tqs_cpu_affinity_get_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d pCpuId=%p(%u)"
                   "\n",
                   ncpStatus, pCpuId, (pCpuId) ? (*pCpuId) : 0);
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_set_wait_profile(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_task_api_class_t api_class,
    ncp_task_wait_profile_type_t wait_profile,
    ncp_uint32_t poll_timeout_value,
    ncp_task_poll_type_t poll_type,
    ncp_uint32_t sleep_poll_value)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    ncp_bool_t real_isr_wait_type_set = FALSE;
    ncp_uint32_t tqsRelId = 0;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    NCP_TASK_LOCK_FLAGS(flags);

   NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                  ncp_xlf_task_set_wait_profile_entry,
                  NCP_MSG_ENTRY,
                  "tqsHdl=%p api_class=%d wait_profile=%d poll_timeout_value=%u poll_type=%d sleep_poll_value=%u"
                  "\n",
                  tqsHdl, api_class, wait_profile, poll_timeout_value, poll_type, sleep_poll_value
       );

    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);    
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));
    
    switch(api_class)
    {
        case NCP_TASK_API_CLASS_RECV:
            switch(wait_profile)
            {
                case NCP_TASK_WAIT_ISR:
                    pvtTqsHdl->waitProfile[api_class].isr_wait_type
                        = NCP_NCA_WAIT_FOR_RX_INTR;
                    real_isr_wait_type_set = TRUE;
                    break;
                case NCP_TASK_WAIT_WFI:
#if !defined(PROC_ARMA15) && !defined(PROC_ARMA57) && !defined(PROC_ARMA53)
                    NCP_CALL(NCP_ST_TASK_BAD_WFI_TARGET);
#else
                    pvtTqsHdl->waitProfile[api_class].isr_wait_type
                        = NCP_NCA_WAIT_FOR_RX_INTR_USING_WFI;
                    real_isr_wait_type_set = TRUE;
                    break;
#endif
                case NCP_TASK_WAIT_TIMEOUT:
                    break;
                default:
                    NCP_CALL(NCP_ST_INVALID_VALUE);
                    /* break; */ /* make coverity happy */
            }
            break;
        
        case NCP_TASK_API_CLASS_RECV_QUEUE_FLUSH:
            switch(wait_profile)
            {
                case NCP_TASK_WAIT_TIMEOUT:
                    break;
                default:
                    NCP_CALL(NCP_ST_INVALID_VALUE);
            }
            break;    
                        
        case NCP_TASK_API_CLASS_SEND_TXQ1:
            tqsRelId = 1;
        case NCP_TASK_API_CLASS_SEND_TXQ0:
            switch(wait_profile)
            {
                case NCP_TASK_WAIT_ISR:
                    pvtTqsHdl->waitProfile[api_class].isr_wait_type
                        = NCP_NCA_WAIT_FOR_TX0_INTR + tqsRelId;
                    real_isr_wait_type_set = TRUE;
                case NCP_TASK_WAIT_TIMEOUT:
                    break;
                default:
                    NCP_CALL(NCP_ST_INVALID_VALUE);
                    /* break; */  /* make coverity happy */
            }
            break;
                    
        case NCP_TASK_API_CLASS_ALLOC:
            switch(wait_profile)
            {
                case NCP_TASK_WAIT_TIMEOUT:
                    break;
                default:
                    NCP_CALL(NCP_ST_INVALID_VALUE);
            }
            break;                        

        case NCP_TASK_API_CLASS_REFILL_TXQ1:
            tqsRelId = 1;            
        case NCP_TASK_API_CLASS_REFILL_TXQ0:  
            switch(wait_profile)
            {
                case NCP_TASK_WAIT_ISR:
                    pvtTqsHdl->waitProfile[api_class].isr_wait_type
                        = NCP_NCA_WAIT_FOR_TX0_INTR + tqsRelId;
                    real_isr_wait_type_set = TRUE;
                case NCP_TASK_WAIT_TIMEOUT:
                    break;
                default:
                    NCP_CALL(NCP_ST_INVALID_VALUE);
                    /* break; */  /* make coverity happy */
            }
            break;

        case NCP_TASK_API_CLASS_FREE_TXQ1:
            tqsRelId = 1;           
        case NCP_TASK_API_CLASS_FREE_TXQ0:   
            switch(wait_profile)
            {
                case NCP_TASK_WAIT_TIMEOUT:
                    break;
                case NCP_TASK_WAIT_ISR:
                    NCP_CHECK((NULL == pvtTqsHdl->cpuPoolHdl), NCP_ST_INVALID_WAIT_PROFILE_FOR_POOL_TYPE);
                    pvtTqsHdl->waitProfile[api_class].isr_wait_type
                        = NCP_NCA_WAIT_FOR_TX0_INTR + tqsRelId;
                    real_isr_wait_type_set = TRUE;
                    break;
                default:
                    NCP_CALL(NCP_ST_INVALID_VALUE);
            }
            break;

        default:
            NCP_CALL(NCP_ST_INVALID_VALUE);
    }

    if ((NCP_TASK_POLL_TYPE_SLEEP_POLL != poll_type)
        && (NCP_TASK_POLL_TYPE_HARD_POLL != poll_type))
    {
        NCP_CALL(NCP_ST_INVALID_VALUE);
    }

    pvtTqsHdl->waitProfile[api_class].wait_profile             = wait_profile;
    if (FALSE == real_isr_wait_type_set)
    {
        pvtTqsHdl->waitProfile[api_class].isr_wait_type     = NCP_NCA_WAIT_NONE;
    }
    pvtTqsHdl->waitProfile[api_class].poll_timeout_value_us = poll_timeout_value;
    pvtTqsHdl->waitProfile[api_class].poll_type             = poll_type;
    pvtTqsHdl->waitProfile[api_class].sleep_poll_value_us   = sleep_poll_value;
    pvtTqsHdl->waitProfile[api_class].tqsRelId              = tqsRelId;

NCP_RETURN_LABEL   

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_set_wait_profile_ok); 
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_set_wait_profile_err);      
    }
    
    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));
        
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_xlf_task_set_wait_profile_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "\n",
                   ncpStatus
        );
    return(ncpStatus);
}

NCP_API ncp_st_t
ncp_task_pool_name_get(
    ncp_hdl_t ncpHdl,
    ncp_uint8_t bufferPoolId,
    ncp_task_resource_name_t *name)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_xlf_task_pool_name_get_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p bufferPoolId=%u name=%p"
                   "\n",
                   ncpHdl, bufferPoolId, name);

    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK(bufferPoolId >= NCP_TASK_FIXED_POOL_ENCODED_ID 
                && bufferPoolId <= NCP_NCAV3_LAST_CPU_POOL_ID,  
              NCP_ST_INVALID_PARAMETER); 
    NCP_CHECK((NULL != name), NCP_ST_INVALID_PARAMETER); 
    
    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    NCP_CALL(ncp_ncav3_pool_name_get(myDevHdl, bufferPoolId, name));

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_pool_name_get_ok); 
    }        
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_pool_name_get_err);      
    }
    
    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_pool_name_get_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d name=%s"
                   "\n",
                   ncpStatus, (name) ? (name->name) : "(null)");
    return(ncpStatus);
}    

NCP_API ncp_st_t
ncp_task_pool_id_get(
    ncp_hdl_t ncpHdl,
    ncp_task_resource_name_t *name,
    ncp_uint8_t *bufferPoolId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)
    
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_task_pool_id_get_entry,
                          NCP_MSG_ENTRY,
                          "ncpHdl=%p name=%s bufferPoolId=%p"
                          "\n",
                          ncpHdl, (name) ? (name->name) : "(null)",
                          bufferPoolId);
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);    
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK((NULL != bufferPoolId), NCP_ST_INVALID_PARAMETER); 
    NCP_TASK_VALIDATE_RESOURCE_NAME(name,  NCP_ST_TASK_BAD_RESOURCE_NAME);
    
    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);

    NCP_CALL(ncp_ncav3_pool_id_get(myDevHdl, name, bufferPoolId));

NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_pool_id_get_ok); 
    }        
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_pool_id_get_err);      
    }
    
    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);     
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_pool_id_get_exit,
                          NCP_MSG_EXIT,
                          "ncpStatus=%d bufferPoolId=%p(%d)"
                          "\n",
                          ncpStatus,
                          bufferPoolId, (bufferPoolId) ? (*bufferPoolId) : 0);
    return(ncpStatus);
}

/* 
 * TBR APIs
 */

#if (1 == NCP_TASK_TBR_ENABLED) 

NCP_API ncp_st_t
ncp_task_tbr_task_take(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_task_header_t  *taskHeader)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t * )tqsHdl;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    NCP_TASK_TBR_STATE_PTRS_DECL()
        
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_tbr_task_take_entry,
                          NCP_MSG_ENTRY,
                          "tqsHdl=%p taskHeader=%p"
                          "\n",
                          tqsHdl, taskHeader);
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    NCP_TASKIO_CHECK((NULL != taskHeader), NCP_ST_INVALID_PARAMETER); 
         

    /* NCP_TASK_VALIDATE_OUTPUT_TASK(pvtTqsHdl, taskHeader); */

    NCP_TASK_TBR_STATE_PTRS_INIT();
    NCP_TASK_TBR_TASK_TAKE_STATE_PREFETCH(pvtTqsHdl, taskHeader, pTbr);
    NCP_TASK_TBR_BUFFER_STATE_UPDATE(pTbr, FALSE);
      
NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_tbr_task_take_ok);        
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_tbr_task_take_err);        
    } 
    
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_tbr_task_take_exit,
                          NCP_MSG_EXIT,
                          "ncpStatus=%d "
                          "taskHeader=%p"
                          "\n",
                          ncpStatus, taskHeader);
    return(ncpStatus);
}        

NCP_API ncp_st_t
ncp_task_tbr_buffer_take(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint8_t    bufferPoolId,
    void *taskBuffer)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t * )tqsHdl;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    NCP_TASK_TBR_STATE_PTRS_DECL()    
    
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_tbr_buffer_take_entry,
                          NCP_MSG_ENTRY,
                          "tqsHdl=%p bufferPoolId=%u taskBuffer=%p"
                          "\n",
                          tqsHdl, bufferPoolId, taskBuffer);
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);        
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    NCP_TASKIO_CHECK((NULL != taskBuffer), NCP_ST_INVALID_PARAMETER);    
    NCP_TASKIO_CHECK(((bufferPoolId >= NCP_NCAV3_FIRST_SHARED_POOL_ID 
                && bufferPoolId < NCP_NCAV3_NUM_TASK_MEMORY_POOLS)
                || (NCP_TASK_CPU_POOL_ALIAS == bufferPoolId)), 
                NCP_ST_INVALID_PARAMETER); 
    NCP_TASKIO_CHECK((0 != (pvtTqsHdl->pTqs->validPoolsMask & (1<<bufferPoolId))), 
               NCP_ST_TASK_BUFFER_POOL_NOT_CONFIGURED_FOR_TQS);                
 
    NCP_TASK_TBR_STATE_PTRS_INIT();
    NCP_TASK_TBR_BUFFER_TAKE_STATE_PREFETCH(pvtTqsHdl, bufferPoolId, taskBuffer, pTbr);
    NCP_TASK_TBR_BUFFER_STATE_UPDATE(pTbr, FALSE);
        
NCP_RETURN_LABEL

    
    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_tbr_buffer_take_ok);        
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_tbr_buffer_take_err);        
    } 
    
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_task_tbr_buffer_take_exit,
                          NCP_MSG_EXIT,
                          "ncpStatus=%d"
                          "\n",
                          ncpStatus);
    return(ncpStatus);
}        

NCP_API ncp_st_t
ncp_task_tbr_task_give(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_task_header_t  *taskHeader)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t * )tqsHdl;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    NCP_TASK_TBR_STATE_PTRS_DECL()    
    
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_tbr_task_give_entry,
                          NCP_MSG_ENTRY,
                          "tqsHdl=%p taskHeader=%p"
                          "\n",
                          tqsHdl, taskHeader);
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);    
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl); 
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    NCP_TASKIO_CHECK((NULL != taskHeader), NCP_ST_INVALID_PARAMETER);
        
     
    /* NCP_TASK_VALIDATE_OUTPUT_TASK(pvtTqsHdl, taskHeader); */

    NCP_TASK_TBR_STATE_PTRS_INIT();
    NCP_TASK_TBR_TASK_GIVE_STATE_PREFETCH(pvtTqsHdl, taskHeader, pTbr);
    NCP_TASK_TBR_BUFFER_GIVE_STATE_UPDATE(pTbr);
        
NCP_RETURN_LABEL

    
    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_task_give_ok);
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_task_give_err);        
    } 
    
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_tbr_task_give_exit,
                          NCP_MSG_EXIT,
                          "ncpStatus=%d"
                          "\n",
                          ncpStatus);
    return(ncpStatus);
}        
    
NCP_API ncp_st_t
ncp_task_tbr_buffer_give(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint8_t    bufferPoolId,
    void *taskBuffer)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t * )tqsHdl;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    NCP_TASK_TBR_STATE_PTRS_DECL()
    
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_tbr_buffer_give_entry,
                          NCP_MSG_ENTRY,
                          "tqsHdl=%p bufferPoolId=%u taskBuffer=%p"
                          "\n",
                          tqsHdl, bufferPoolId, taskBuffer);
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);    
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl); 
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    NCP_TASKIO_CHECK((NULL != taskBuffer), NCP_ST_INVALID_PARAMETER);
        
 
    NCP_TASKIO_CHECK(((bufferPoolId >= NCP_NCAV3_FIRST_SHARED_POOL_ID 
                && bufferPoolId < NCP_NCAV3_NUM_TASK_MEMORY_POOLS)
                || (NCP_TASK_CPU_POOL_ALIAS == bufferPoolId)), 
                NCP_ST_INVALID_PARAMETER); 
    NCP_TASKIO_CHECK((0 != (pvtTqsHdl->pTqs->validPoolsMask & (1<<bufferPoolId))), 
               NCP_ST_TASK_BUFFER_POOL_NOT_CONFIGURED_FOR_TQS);                

    NCP_TASK_TBR_STATE_PTRS_INIT();    
    NCP_TASK_TBR_BUFFER_GIVE_STATE_PREFETCH(pvtTqsHdl, bufferPoolId, taskBuffer, pTbr);
    NCP_TASK_TBR_BUFFER_GIVE_STATE_UPDATE(pTbr);
        
NCP_RETURN_LABEL

    
    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_tbr_buffer_give_ok);        
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_tbr_buffer_give_err);        
    } 
    
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_tbr_buffer_give_exit,
                          NCP_MSG_EXIT,
                          "ncpStatus=%d\n",
                          ncpStatus);
    return(ncpStatus);
}   
     
     
ncp_st_t  
ncp_task_tbr_buffer_ownership_get( ncp_task_tqs_hdl_t tqsHdl,
                            ncp_uint8_t poolId,
                            void *taskBuffer,  
                            ncp_task_pid_t *pPid)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t * )tqsHdl;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);    
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl); 
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag); 
    NCP_TASKIO_CHECK((NULL != pPid), NCP_ST_INVALID_PARAMETER);       
    NCP_TASKIO_CHECK((NULL != taskBuffer), NCP_ST_INVALID_PARAMETER);

    NCP_TASK_TBR_TASK_BUFFER_OWNERSHIP_GET(pvtTqsHdl, poolId, taskBuffer, pPid);
        
NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_tbr_buffer_ownership_get_ok);        
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_tbr_buffer_ownership_get_err);        
    } 
        
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    return(ncpStatus);        
}                                 
                            
/* Atomic task transfer */     
ncp_st_t  
ncp_task_tbr_task_transfer( ncp_task_tqs_hdl_t tqsHdl,
                            ncp_task_header_t *taskHeader,  
                            ncp_task_pid_t pid) 
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t * )tqsHdl;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    NCP_TASK_TBR_STATE_PTRS_DECL()

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tbr_task_transfer_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p taskHeader=%p pid=%u"
                   "\n",
                   tqsHdl, taskHeader, pid);
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl); 
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    NCP_TASKIO_CHECK((NULL != taskHeader), NCP_ST_INVALID_PARAMETER);
     
    if (pid < NCP_TASK_TBR_FIRST_APPLICATION_PID)
    {
        NCP_CALL(NCP_ST_TASK_INVALID_PID);
    }  
    
    NCP_TASK_TBR_STATE_PTRS_INIT();          
    NCP_TASK_TBR_TASK_ATOMIC_TRANSFER_STATE_PREFETCH(pvtTqsHdl, pid, taskHeader, pTbr);
    NCP_TASK_TBR_BUFFER_TRANSFER_STATE_UPDATE(pTbr);
        
NCP_RETURN_LABEL

    
    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_task_transfer_ok);        
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_task_transfer_err);        
    } 
    
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tbr_task_transfer_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "\n",
                   ncpStatus);
    return(ncpStatus);
}

/* Atomic task buffer transfer */
ncp_st_t  
ncp_task_tbr_buffer_transfer( ncp_task_tqs_hdl_t tqsHdl,
                              void *taskBuffer,
                              ncp_uint8_t    bufferPoolId,                                
                              ncp_task_pid_t pid) 
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t * )tqsHdl;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)
    NCP_TASK_TBR_STATE_PTRS_DECL()

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tbr_buffer_transfer_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p taskBuffer=%p bufferPoolId=%u pid=%u"
                   "\n",
                   tqsHdl, taskBuffer, bufferPoolId, pid);
    NCP_TASKIO_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl); 
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    
    NCP_TASKIO_CHECK((NULL != taskBuffer), NCP_ST_INVALID_PARAMETER);
    NCP_TASKIO_CHECK(((bufferPoolId >= NCP_NCAV3_FIRST_SHARED_POOL_ID 
                && bufferPoolId < NCP_NCAV3_NUM_TASK_MEMORY_POOLS)
                || (NCP_TASK_CPU_POOL_ALIAS == bufferPoolId)), 
                NCP_ST_INVALID_PARAMETER); 
    NCP_TASKIO_CHECK((0 != (pvtTqsHdl->pTqs->validPoolsMask & (1<<bufferPoolId))), 
               NCP_ST_TASK_BUFFER_POOL_NOT_CONFIGURED_FOR_TQS);                
    NCP_TASKIO_CHECK((pid >= NCP_TASK_TBR_FIRST_APPLICATION_PID), NCP_ST_TASK_INVALID_PID);
    
    NCP_TASK_TBR_STATE_PTRS_INIT();
    NCP_TASK_TBR_BUFFER_ATOMIC_TRANSFER_STATE_PREFETCH(pvtTqsHdl, pid, bufferPoolId, taskBuffer, pTbr);
    NCP_TASK_TBR_BUFFER_TRANSFER_STATE_UPDATE(pTbr);
        
NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_tbr_buffer_transfer_ok);        
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_tbr_buffer_transfer_err);        
    } 
    
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);    

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_tbr_buffer_transfer_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "\n",
                   ncpStatus);
    return(ncpStatus);
}
#else

NCP_API ncp_st_t
ncp_task_tbr_task_take(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_task_header_t  *taskHeader)
{
    return NCP_ST_SUCCESS;
}

NCP_API ncp_st_t
ncp_task_tbr_buffer_take(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint8_t    bufferPoolId,
    void *taskBuffer)
{
    return NCP_ST_SUCCESS;
}

NCP_API ncp_st_t
ncp_task_tbr_task_give(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_task_header_t  *taskHeader)
{
    return NCP_ST_SUCCESS;
}

NCP_API ncp_st_t
ncp_task_tbr_buffer_give(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint8_t    bufferPoolId,
    void *taskBuffer)
{
    return NCP_ST_SUCCESS;
}

ncp_st_t  
ncp_task_tbr_buffer_ownership_get( ncp_task_tqs_hdl_t tqsHdl,
                            ncp_uint8_t poolId,
                            void *taskBuffer,  
                            ncp_task_pid_t *pPid)
{
    return NCP_ST_SUCCESS;
}

ncp_st_t  
ncp_task_tbr_task_transfer( ncp_task_tqs_hdl_t tqsHdl,
                            ncp_task_header_t *taskHeader,  
                            ncp_task_pid_t pid) 
{
    return NCP_ST_SUCCESS;
}

ncp_st_t  
ncp_task_tbr_buffer_transfer( ncp_task_tqs_hdl_t tqsHdl,
                              void *taskBuffer,
                              ncp_uint8_t    bufferPoolId,                                
                              ncp_task_pid_t pid) 
{
    return NCP_ST_SUCCESS;
}

#endif
                              
/* Return the PID associated with the caller */                              
ncp_st_t 
ncp_task_pid_get(ncp_task_tqs_hdl_t tqsHdl, 
                 ncp_task_pid_t *pid) 
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t * )tqsHdl;
#if defined(NCP_NCA_CRITICAL_SECTION_TRACKING) || !defined(NCP_TASK_COLLECT_STATS_DISABLED)
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)    
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
#endif

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_pid_get_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p pid=%p"
                   "\n",
                   tqsHdl, pid);
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CHECK((NULL != pid), NCP_ST_INVALID_PARAMETER);
 
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);

    
    if ((*pid = pvtTqsHdl->pProcess->pid) < NCP_TASK_TBR_FIRST_APPLICATION_PID)
    {
        NCP_CALL(NCP_ST_TASK_PID_LOOKUP_FAILURE);
    }    
     
NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_pid_get_ok);        
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_pid_get_err);        
    } 
    
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_pid_get_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d pid=%p(%u)"
                   "\n",
                   ncpStatus, pid, (pid) ? (*pid) : 0);
    return(ncpStatus);
}
                            
/* Return the PID for the active named process */                            
ncp_st_t 
ncp_task_process_name_pid_get(ncp_hdl_t ncpHdl, 
                              ncp_task_resource_name_t *processName, 
                              ncp_task_pid_t *pid)     
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_process_info_t *pProcess=NULL;   
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(globalCritSecFlag)    
    
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);    
    NCP_NCA_INC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK((NULL != processName), NCP_ST_INVALID_PARAMETER);     
    NCP_CHECK((NULL != pid), NCP_ST_INVALID_PARAMETER);    
    
    pProcess = pNcpTaskSwState->activeProcesses;
    while (NULL != pProcess)
    {
        if (0 == strncmp(pProcess->clientProcess.name,
                         processName->name,
                         sizeof(ncp_task_resource_name_t)))
        {
            *pid = pProcess->pid;
            break;
        }                     
        pProcess = pProcess->pNextProcess;
    }    
    if (NULL == pProcess)
    {    
        NCP_CALL(NCP_ST_TASK_PID_LOOKUP_FAILURE);    
    }
        
NCP_RETURN_LABEL


    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_process_name_pid_get_ok);        
    }        
    else
    {
        NCP_TASK_INC_GLOBAL_STAT(api_task_process_name_pid_get_err);        
    }  
    
    NCP_NCA_DEC_GLOBAL_CRITICAL_SECTION(globalCritSecFlag);    
    return(ncpStatus);
}    

NCP_API ncp_st_t
ncp_task_shared_region_virtual_base_get_by_id(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint32_t regionId,
    void **addr)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_cpu_profile_t *profile;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl =
        (ncp_task_pvt_tqsHdl_data_t *) tqsHdl;
    int i;

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_shared_region_virtual_base_get_by_id_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p regionId=%u addr=%p"
                   "\n",
                   tqsHdl, regionId, addr);

    NCP_CHECK((NULL != addr), NCP_ST_INVALID_PARAMETER);    
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);    
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);                       

    profile = &pvtTqsHdl->pTqs->pAppProfile->baseProfile;

    for (i = 0; i < profile->numSharedDataRegionMaps; i++)
    {
        if (profile->sharedDataRegionMap[i].regionId == regionId)
        {
            *addr = (void *) profile->sharedDataRegionMap[i].virtualStartAddress;
            NCP_RETURN(NCP_ST_SUCCESS);
        }
    }

    ncpStatus = NCP_ST_TASK_SHARED_REGION_NOT_FOUND;

NCP_RETURN_LABEL
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_shared_region_virtual_base_get_by_id_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d addr=%p(%p)"
                   "\n",
                   ncpStatus, addr, (addr) ? (*addr) : 0);
    return ncpStatus;
}

NCP_API ncp_st_t
ncp_task_shared_region_virtual_base_get_by_name(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_task_resource_name_t *name,
    void **addr)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_cpu_profile_t *profile;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl =
        (ncp_task_pvt_tqsHdl_data_t *) tqsHdl;
    int i;

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_shared_region_virtual_base_get_by_name_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p name=%s addr=%p"
                   "\n",
                   tqsHdl, ((name) ? (name->name) : "(null)"), addr);
    NCP_CHECK((NULL != addr), NCP_ST_INVALID_PARAMETER);
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);    
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);                       

    profile = &pvtTqsHdl->pTqs->pAppProfile->baseProfile;

    for (i = 0; i < profile->numSharedDataRegionMaps; i++)
    {
        if (0 == strncmp(
                    profile->sharedDataRegionMap[i].name.name,
                    name->name,
                    sizeof(ncp_task_resource_name_t)))
        {
            *addr = (void *) profile->sharedDataRegionMap[i].virtualStartAddress;
            NCP_RETURN(NCP_ST_SUCCESS);
        }
    }

    ncpStatus = NCP_ST_TASK_SHARED_REGION_NOT_FOUND;

NCP_RETURN_LABEL
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_shared_region_virtual_base_get_by_name_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d addr=%p(%p)"
                   "\n",
                   ncpStatus, addr, (addr) ? (*addr) : 0);
    return ncpStatus;
}

ncp_st_t
ncp_task_shared_region_size_get_by_id(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_uint32_t regionId,
    ncp_uint64_t *size)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_cpu_profile_t *profile;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl =
        (ncp_task_pvt_tqsHdl_data_t *) tqsHdl;
    int i;

    NCP_CHECK((NULL != size), NCP_ST_INVALID_PARAMETER);    
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);    
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);                       

    profile = &pvtTqsHdl->pTqs->pAppProfile->baseProfile;

    for (i = 0; i < profile->numSharedDataRegionMaps; i++)
    {
        if (profile->sharedDataRegionMap[i].regionId == regionId)
        {
            *size = (ncp_uint64_t) profile->sharedDataRegionMap[i].size;
            NCP_RETURN(NCP_ST_SUCCESS);
        }
    }

    ncpStatus = NCP_ST_TASK_SHARED_REGION_NOT_FOUND;

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_task_shared_region_size_get_by_name(
    ncp_task_tqs_hdl_t tqsHdl,
    ncp_task_resource_name_t *name,
    ncp_uint64_t *size)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_ncav3_cpu_profile_t *profile;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl =
        (ncp_task_pvt_tqsHdl_data_t *) tqsHdl;
    int i;

    NCP_CHECK((NULL != size), NCP_ST_INVALID_PARAMETER);    
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);    
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);                       

    profile = &pvtTqsHdl->pTqs->pAppProfile->baseProfile;

    for (i = 0; i < profile->numSharedDataRegionMaps; i++)
    {
        if (0 == strncmp(
                    profile->sharedDataRegionMap[i].name.name,
                    name->name,
                    sizeof(ncp_task_resource_name_t)))
        {
            *size = (ncp_uint64_t) profile->sharedDataRegionMap[i].size;
            NCP_RETURN(NCP_ST_SUCCESS);
        }
    }

    ncpStatus = NCP_ST_TASK_SHARED_REGION_NOT_FOUND;

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t 
ncp_task_completion_mode_get(ncp_task_tqs_hdl_t tqsHdl,  
                             ncp_ncav3_task_completion_mode_e *completionMode)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag)

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_completion_mode_get_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p completionMode=%p"
                   "\n",
                   tqsHdl, completionMode);
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_CHECK((NULL != completionMode), NCP_ST_INVALID_PARAMETER);

    if (pvtTqsHdl->pTqs->rxQ.u.ipcq_info.autoCompletionMode)
    {
        *completionMode = NCP_TASK_AUTO_COMPLETION_MODE;
    }
    else
    {
        *completionMode = NCP_TASK_MANUAL_COMPLETION_MODE;                    
    }
        
NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_completion_mode_get_ok); 
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_completion_mode_get_err);      
    }
    
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_completion_mode_get_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d completionMode=%p(%d)"
                   "\n",
                   ncpStatus, completionMode,
                   (completionMode) ? (*completionMode) : 0);
    return(ncpStatus);
}  
                               
NCP_API ncp_st_t
ncp_task_consumption_mode_get(ncp_task_tqs_hdl_t tqsHdl, 
                              ncp_ncav3_task_consumption_mode_e *consumptionMode)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    NCP_NCA_CRITICAL_SECTION_FLAG_DECL(critSecFlag);

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_consumption_mode_get_entry,
                   NCP_MSG_ENTRY,
                   "tqsHdl=%p consumptionMode=%p"
                   "\n",
                   tqsHdl, consumptionMode);
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    NCP_NCA_INC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_CHECK((NULL != consumptionMode), NCP_ST_INVALID_PARAMETER);

    if (pvtTqsHdl->pTqs->rxQ.u.ipcq_info.autoConsumptionMode)
    {
        *consumptionMode = NCP_TASK_IMMEDIATE_CONSUMPTION_MODE;
    }
    else
    {
        *consumptionMode = NCP_TASK_DEFERRED_CONSUMPTION_MODE;                    
    }
        
NCP_RETURN_LABEL

    if (NCP_ST_SUCCESS == ncpStatus)
    {
        NCP_TASK_INC_STAT(pvtTqsHdl->pTqs, api_task_consumption_mode_get_ok); 
    }        
    else
    {
        NCP_TASK_INC_ERROR_STAT_VIA_PTQSHDL(pvtTqsHdl,  api_task_consumption_mode_get_err);      
    }
    
    NCP_NCA_DEC_CRITICAL_SECTION(pvtTqsHdl, critSecFlag);
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_consumption_mode_get_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d consumptionMode=%p(%d)"
                   "\n",
                   ncpStatus, consumptionMode,
                   (consumptionMode) ? (*consumptionMode) : 0);
    return(ncpStatus);
}                                  

NCP_API ncp_st_t
ncp_task_queue_group_add(
    ncp_hdl_t    ncpHdl,
    ncp_uint32_t queueGroupId,
    ncp_task_resource_name_t *name,
    ncp_ncav3_recv_queue_type_t ordering)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_dev_hdl_t dev;

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_queue_group_add_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p queueGroupId=%u name=%s ordering=%d"
                   "\n",
                   ncpHdl, queueGroupId,
                   ((name) ? (name->name) : "(null)"),
                   ordering);
    NCP_CHECK(queueGroupId <= 254, NCP_ST_INVALID_PARAMETER);

    dev = ncp_dev_hdls[((ncp_t *) ncpHdl)->id];

    NCP_CALL(ncp_ncav3_queue_group_add(
        dev,
        queueGroupId,
        name,
        ordering));

NCP_RETURN_LABEL
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_queue_group_add_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "\n",
                   ncpStatus);
    return ncpStatus;
}

NCP_API ncp_st_t
ncp_task_queue_group_delete(
    ncp_hdl_t    ncpHdl,
    ncp_uint32_t queueGroupId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_dev_hdl_t dev;

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_queue_group_delete_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p queueGroupId=%u"
                   "\n",
                   ncpHdl, queueGroupId);
    NCP_CHECK(queueGroupId <= 254, NCP_ST_INVALID_PARAMETER);

    dev = ncp_dev_hdls[((ncp_t *) ncpHdl)->id];

    NCP_CALL(ncp_ncav3_queue_group_delete(dev, queueGroupId));

NCP_RETURN_LABEL
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_queue_group_delete_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "\n",
                   ncpStatus);
    return ncpStatus;
}

NCP_API ncp_st_t
ncp_task_queue_group_modify(
    ncp_hdl_t    ncpHdl,
    ncp_uint32_t queueGroupId,
    ncp_ncav3_recv_queue_type_t ordering)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_dev_hdl_t dev;

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_queue_group_modify_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p queueGroupId=%u ordering=%d"
                   "\n",
                   ncpHdl, queueGroupId, ordering);
    NCP_CHECK(queueGroupId <= 254, NCP_ST_INVALID_PARAMETER);

    dev = ncp_dev_hdls[((ncp_t *) ncpHdl)->id];

    NCP_CALL(ncp_ncav3_queue_group_modify(
        dev,
        queueGroupId,
        ordering));

NCP_RETURN_LABEL
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_queue_group_modify_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d"
                   "\n",
                   ncpStatus);
    return ncpStatus;
}

ncp_st_t
ncp_task_qpm_queue_stats_get(
    ncp_hdl_t ncpHdl,
    ncp_uint16_t queueId,
    ncp_task_qpm_stats_t *stats)
{
    ncp_st_t ncpStatus = NCP_ST_NOT_IMPLEMENTED;

    /* Parameter validation */
    NCP_ASSERT(stats != NULL, NCP_ST_INVALID_PARAMETER);

    /* Call IOCTL */
    NCP_CALL(ncp_ncav3_get_qpm_stats(
        myDevHdl,
        queueId,
       &stats->numFullQueueExceptions,
       &stats->numEmptyQueueExceptions,
       &stats->numOverflowExceptions));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_task_tracing_enable(
    ncp_hdl_t ncpHdl)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    NCP_CALL(ncp_ncav3_set_tracing_enable(
        myDevHdl,
        TRUE));

NCP_RETURN_LABEL

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    return ncpStatus;
}

ncp_st_t
ncp_task_tracing_disable(
    ncp_hdl_t ncpHdl)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    NCP_CALL(ncp_ncav3_set_tracing_enable(
        myDevHdl,
        FALSE));

NCP_RETURN_LABEL

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    return ncpStatus;
}

ncp_st_t
ncp_task_queue_tracing_enable(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t ncaQueueId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    NCP_CHECK(ncaQueueId < NCP_NCAV3_MAX_NUM_NCAQS, NCP_ST_INVALID_PARAMETER);

    NCP_CALL(ncp_ncav3_queue_set_tracing_enable(
        myDevHdl,
        TRUE,
        ncaQueueId));

NCP_RETURN_LABEL

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    return ncpStatus;
}

ncp_st_t
ncp_task_queue_tracing_disable(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t ncaQueueId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    NCP_CHECK(ncaQueueId < NCP_NCAV3_MAX_NUM_NCAQS, NCP_ST_INVALID_PARAMETER);

    NCP_CALL(ncp_ncav3_queue_set_tracing_enable(
        myDevHdl,
        FALSE,
        ncaQueueId));

NCP_RETURN_LABEL

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    return ncpStatus;
}

ncp_st_t
ncp_task_tracing_reset(
    ncp_hdl_t ncpHdl)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    NCP_CALL(ncp_ncav3_reset_tracing(myDevHdl));

NCP_RETURN_LABEL

    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    return ncpStatus;
}

ncp_st_t
ncp_task_app_profile_pool_mapping_get(
    ncp_hdl_t ncpHdl,
    ncp_task_resource_name_t *appProfileName,
    ncp_bool_t poolEnabled[8])
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_app_profile_pool_mapping_get_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p appProfileName=%s poolEnabled=%p",
                   ncpHdl,
                   ((appProfileName) ? (appProfileName->name) : "(null)"),
                   poolEnabled);
    NCP_CHECK(appProfileName != NULL, NCP_ST_INVALID_PARAMETER);
    NCP_CHECK(poolEnabled != NULL, NCP_ST_INVALID_PARAMETER);

    NCP_CALL(ncp_ncav3_get_app_profile_pool_mapping(
                myDevHdl,
                appProfileName,
                poolEnabled));

NCP_RETURN_LABEL
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_app_profile_pool_mapping_get_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d "
                   "poolEnabled=%p[%d,%d,%d,%d,%d,%d,%d,%d]"
                   "\n",
                   ncpStatus,
                   poolEnabled,
                   (poolEnabled) ? (poolEnabled[0]) : 0,
                   (poolEnabled) ? (poolEnabled[1]) : 0,
                   (poolEnabled) ? (poolEnabled[2]) : 0,
                   (poolEnabled) ? (poolEnabled[3]) : 0,
                   (poolEnabled) ? (poolEnabled[4]) : 0,
                   (poolEnabled) ? (poolEnabled[5]) : 0,
                   (poolEnabled) ? (poolEnabled[6]) : 0,
                   (poolEnabled) ? (poolEnabled[7]) : 0);
    return ncpStatus;
}

ncp_st_t
ncp_task_app_profile_name_get(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t tqsId,
    ncp_task_resource_name_t *appProfileName)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    NCP_CHECK(appProfileName != NULL, NCP_ST_INVALID_PARAMETER);
    NCP_CHECK(tqsId < NCP_NCAV3_NUM_CPU_TQSETS, NCP_ST_INVALID_PARAMETER);

    NCP_CALL(ncp_ncav3_get_app_profile_name(
                myDevHdl,
                tqsId,
                appProfileName));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_task_unscheduled_receive_queue_profile_pool_mapping_get(
    ncp_hdl_t ncpHdl,
    ncp_task_resource_name_t *queueProfileName,
    ncp_bool_t poolEnabled[8])
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    NCP_CHECK(queueProfileName != NULL, NCP_ST_INVALID_PARAMETER);
    NCP_CHECK(poolEnabled != NULL, NCP_ST_INVALID_PARAMETER);

    NCP_CALL(ncp_ncav3_get_unscheduled_receive_queue_profile_pool_mapping(
                myDevHdl,
                queueProfileName,
                poolEnabled));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_task_unscheduled_receive_queue_profile_name_get(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t queueId,
    ncp_task_resource_name_t *queueProfileName)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    NCP_CHECK(queueProfileName != NULL, NCP_ST_INVALID_PARAMETER);
    NCP_CHECK(queueId < NCP_NCAV3_MAX_NUM_UNSCHEDULED_QUEUES,
        NCP_ST_INVALID_PARAMETER);

    NCP_CALL(ncp_ncav3_get_unscheduled_receive_queue_profile_name(
                myDevHdl,
                queueId,
                queueProfileName));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
nca_task_v3_CpuPool_available_blocks_get(ncp_hdl_t ncpHdl,
                                         ncp_uint32_t poolId,
                                         ncp_uint32_t blockSize,
                                         ncp_uint32_t *numBlocks)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pool_t *pPoolEntry;

    NCP_ASSERT(numBlocks != NULL, NCP_ST_INVALID_PARAMETER);

    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));

    if (NULL != pNcpTaskSwState)
    {
        int i = 0;

        pPoolEntry = &pNcpTaskSwState->taskPools[poolId];

        if ( blockSize == 256)
        {
            i = 0;
        }
        else if ( blockSize == 2048)
        {
            i = 1;
        }
        else if ( blockSize == 16384)
        {
            i = 2;
        }
        else if ( blockSize == 65536)
        {
            i = 3;
        }

        *numBlocks = pPoolEntry->numBlocks[i];
    }
    else
    {
        NCP_CALL(NCP_ST_DEV_INVALID_BUFFER);
    }

NCP_RETURN_LABEL
    return ncpStatus;
}

ncp_st_t
ncp_task_ipcq_disable(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t tqsId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_tqs_swState_t *pTqs;
    ncp_dev_hdl_t dev;

    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CHECK(tqsId < NCP_NCAV3_NUM_CPU_TQSETS, NCP_ST_INVALID_PARAMETER);

    pTqs = &pNcpTaskSwState->tqsSwState[tqsId];
    NCP_CHECK(pTqs->configured == TRUE, NCP_ST_TASK_TQS_NOT_CONFIGURED);

    dev = ncp_dev_hdls[((ncp_t *) ncpHdl)->id];

    NCP_CALL(ncp_ncav3_disable_ipcq(dev, tqsId / 8, tqsId % 8, tqsId));

NCP_RETURN_LABEL

    return ncpStatus;
}

ncp_st_t
ncp_task_ipcq_enable(
    ncp_hdl_t ncpHdl,
    ncp_uint32_t tqsId)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_tqs_swState_t *pTqs;
    ncp_dev_hdl_t dev;

    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_CHECK(tqsId < NCP_NCAV3_NUM_CPU_TQSETS, NCP_ST_INVALID_PARAMETER);

    pTqs = &pNcpTaskSwState->tqsSwState[tqsId];
    NCP_CHECK(pTqs->configured == TRUE, NCP_ST_TASK_TQS_NOT_CONFIGURED);

    dev = ncp_dev_hdls[((ncp_t *) ncpHdl)->id];

    NCP_CALL(ncp_ncav3_enable_ipcq(dev, tqsId / 8, tqsId % 8, tqsId));

NCP_RETURN_LABEL

    return ncpStatus;
}

NCP_API ncp_st_t
ncp_task_fixed_pool_virtual_base_get(
    ncp_hdl_t ncpHdl,
    void **addr)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_fixed_pool_virtual_base_get_entry,
                   NCP_MSG_ENTRY,
                   "ncpHdl=%p addr=%p"
                   "\n",
                   ncpHdl, addr);
    NCP_CALL(NCP_VALIDATE_NCP_HDL(ncpHdl));
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_ASSERT((NULL != addr), NCP_ST_INVALID_PARAMETER);

    *addr = (void *) pNcpTaskSwState->fixedPoolInfo.virtualBase;

NCP_RETURN_LABEL
    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_task_fixed_pool_virtual_base_get_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d addr=%p(%p)"
                   "\n",
                   ncpStatus, addr, (addr) ? (*addr) : 0);
    return ncpStatus;
}

static ncp_st_t ncp_task_cpu_pool_mutex_attrib_set_pvt(ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl);
static ncp_st_t ncp_task_cpu_pool_mutex_attrib_set_shared(ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl);
static ncp_st_t ncp_task_cpu_pool_mutex_attrib_set_robust(ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl);

ncp_st_t
ncp_task_cpu_pool_mutex_attrib_set(ncp_task_tqs_hdl_t tqsHdl, ncp_mutex_attr_t mtxType)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    ncp_uint8_t                 poolId;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_cpu_pool_mutex_attrib_set_entry,
                          NCP_MSG_ENTRY,
                          "tqsHdl=%p mtxType=%d\n",
                          tqsHdl, mtxType);

    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    poolId = pvtTqsHdl->cpuPoolId;
    NCP_ASSERT((poolId >= NCP_NCAV3_FIRST_CPU_POOL_ID &&
                poolId <= NCP_NCAV3_LAST_CPU_POOL_ID),
               NCP_ST_INVALID_PARAMETER);
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));
    switch(mtxType) {
    case NCP_MUTEX_PROCESS_PRIVATE:
        NCP_CALL(ncp_task_cpu_pool_mutex_attrib_set_pvt(pvtTqsHdl));
        break;
    case NCP_MUTEX_PROCESS_SHARED:
        NCP_CALL(ncp_task_cpu_pool_mutex_attrib_set_shared(pvtTqsHdl));
        break;
    case NCP_MUTEX_PROCESS_SHARED_ROBUST:
        NCP_CALL(ncp_task_cpu_pool_mutex_attrib_set_robust(pvtTqsHdl));
        break;
    default:
        NCP_RETURN(NCP_ST_INVALID_PARAMETER);
    }

NCP_RETURN_LABEL
    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->NCP_POINTER(taskIoResourceLock), flags, &unlockRequired));

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                   ncp_xlf_task_cpu_pool_mutex_attrib_set_exit,
                   NCP_MSG_EXIT,
                   "ncpStatus=%d\n",
                   ncpStatus
        );
    return ncpStatus;
}

static ncp_st_t
ncp_task_cpu_pool_mutex_attrib_set_pvt(ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_uint8_t poolID = pvtTqsHdl->cpuPoolId;
    ncp_task_pool_t *pPoolEntry = pvtTqsHdl->cpuPoolHdl;
    runtime_mutex_attr_state_t *mtxAttr;
    ncp_pid_t myPid = ncp_get_pid();

    mtxAttr = &pPoolEntry->mtxAttr;

    if (0 == pPoolEntry->poolUseCnt)
    {
        /* no one is referencing this pool so it's safe to change */
    }
    else if (1 == pPoolEntry->poolUseCnt)
    {
        int tqsID;
        ncp_task_tqs_swState_t *pTqs;
        NCP_CALL(ncp_task_os_pid_match_check(
                     pvtTqsHdl->pProcess, TRUE, NCP_ST_TASK_PID_MISMATCH));
        /* Allow mutex type change only if sinlge thread is referencing pool */
        if (1 != pvtTqsHdl->pProcess->numThreads ||
            NULL == pvtTqsHdl->pProcess->activeThreads)
        {
            NCP_RETURN(NCP_ST_TASK_THREAD_NOT_FOUND);
        }
        /* only single owner of this pool so check if all TQS referencing it
         * doesn't have conflicting configuration
         */
        switch(mtxAttr->attr) {
        case NCP_MUTEX_PROCESS_PRIVATE:
            /* If mutex is private then only owning process can change type */
            if (myPid != mtxAttr->pid)
            {
                NCP_RETURN(NCP_ST_TASK_PID_MISMATCH);
            }
            break;
        case NCP_MUTEX_PROCESS_SHARED:
        case NCP_MUTEX_PROCESS_SHARED_ROBUST:
            /* while changing to private mutex check that all TQS referring this
             * pool are private and owned by current PID */
            for (tqsID = 0; tqsID < NCP_NCAV3_MAX_NUM_TQSETS; tqsID++)
            {
                pTqs = &pNcpTaskSwState->tqsSwState[tqsID];
                /* allow setting mutex private only if each TQS referencing me is
                 * private and owned by the same process */
                if (pTqs->cpuPoolId == poolID)
                {
                    if (NCP_MUTEX_PROCESS_PRIVATE != pTqs->mtxAttr.attr ||
                        myPid != pTqs->mtxAttr.pid)
                    {
                        NCP_RETURN(NCP_ST_MUTEX_CANNOT_CHANGE_TYPE);
                    }
                }
            }
            break;
        default:
            NCP_RETURN(NCP_ST_MUTEX_WRONG_STATE);
            break;
        }
    }
    else
    {
        if (NCP_MUTEX_PROCESS_PRIVATE != mtxAttr->attr)
        {
            NCP_RETURN(NCP_ST_MUTEX_CANNOT_CHANGE_TYPE);
        }
        else if(myPid != mtxAttr->pid)
        {
            NCP_RETURN(NCP_ST_TASK_PID_MISMATCH);
        }
        else
        {
            NCP_RETURN(ncpStatus);
        }
    }

    /* Already PRIVATE so no change required */
    if (NCP_MUTEX_PROCESS_PRIVATE != mtxAttr->attr)
    {
        NCP_CALL(ncp_task_v3_destroy_lock(&(pPoolEntry->poolLock)));
        mtxAttr->attr = NCP_MUTEX_PROCESS_PRIVATE;
        mtxAttr->pid = myPid;
        NCP_CALL(ncp_task_v3_create_lock(&(pPoolEntry->poolLock), mtxAttr));
    }

NCP_RETURN_LABEL
    return ncpStatus;
}

static ncp_st_t
ncp_task_cpu_pool_mutex_attrib_set_shared(ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pool_t *pPoolEntry = pvtTqsHdl->cpuPoolHdl;
    runtime_mutex_attr_state_t *mtxAttr;
    ncp_pid_t myPid = ncp_get_pid();

    mtxAttr = &pPoolEntry->mtxAttr;

    if (0 == pPoolEntry->poolUseCnt)
    {
        /* no one is referencing this pool so it's safe to change */
    }
    else if (1 == pPoolEntry->poolUseCnt)
    {
        NCP_CALL(ncp_task_os_pid_match_check(
                     pvtTqsHdl->pProcess, TRUE, NCP_ST_TASK_PID_MISMATCH));
        /* Allow mutex type change only if sinlge thread is referencing pool */
        if (1 != pvtTqsHdl->pProcess->numThreads ||
            NULL == pvtTqsHdl->pProcess->activeThreads)
        {
            NCP_RETURN(NCP_ST_TASK_THREAD_NOT_FOUND);
        }
        /* I'm the only one reffering this mutex */
        switch(mtxAttr->attr) {
        case NCP_MUTEX_PROCESS_PRIVATE:
            /* If mutex is private then only owning process can change type */
            if (myPid != mtxAttr->pid)
            {
                NCP_RETURN(NCP_ST_TASK_PID_MISMATCH);
            }
            break;
        case NCP_MUTEX_PROCESS_SHARED:
            break;
        case NCP_MUTEX_PROCESS_SHARED_ROBUST:
            break;
        default:
            NCP_RETURN(NCP_ST_MUTEX_WRONG_STATE);
            break;
        }
    }
    else
    {
        if (NCP_MUTEX_PROCESS_SHARED != mtxAttr->attr)
        {
            NCP_RETURN(NCP_ST_MUTEX_CANNOT_CHANGE_TYPE);
        }
        else
        {
            NCP_RETURN(ncpStatus);
        }
    }

    /* Already SHARED so no change required */
    if (NCP_MUTEX_PROCESS_SHARED != mtxAttr->attr)
    {
        NCP_CALL(ncp_task_v3_destroy_lock(&(pPoolEntry->poolLock)));
        mtxAttr->attr = NCP_MUTEX_PROCESS_SHARED;
        mtxAttr->pid = 0;
        NCP_CALL(ncp_task_v3_create_lock(&(pPoolEntry->poolLock), mtxAttr));
    }

NCP_RETURN_LABEL
    return ncpStatus;
}

static ncp_st_t
ncp_task_cpu_pool_mutex_attrib_set_robust(ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    ncp_task_pool_t *pPoolEntry = pvtTqsHdl->cpuPoolHdl;
    runtime_mutex_attr_state_t *mtxAttr;
    ncp_pid_t myPid = ncp_get_pid();

    mtxAttr = &pPoolEntry->mtxAttr;

    if (0 == pPoolEntry->poolUseCnt)
    {
        /* no one is referencing this pool so it's safe to change */
    }
    else if (1 == pPoolEntry->poolUseCnt)
    {
        NCP_CALL(ncp_task_os_pid_match_check(
                     pvtTqsHdl->pProcess, TRUE, NCP_ST_TASK_PID_MISMATCH));
        /* Allow mutex type change only if sinlge thread is referencing pool */
        if (1 != pvtTqsHdl->pProcess->numThreads ||
            NULL == pvtTqsHdl->pProcess->activeThreads)
        {
            NCP_RETURN(NCP_ST_TASK_THREAD_NOT_FOUND);
        }
        /* I'm the only one reffering this mutex */
        switch(mtxAttr->attr) {
        case NCP_MUTEX_PROCESS_PRIVATE:
            /* If mutex is private then only owning process can change type */
            if (myPid != mtxAttr->pid)
            {
                NCP_RETURN(NCP_ST_TASK_PID_MISMATCH);
            }
            break;
        case NCP_MUTEX_PROCESS_SHARED:
            break;
        case NCP_MUTEX_PROCESS_SHARED_ROBUST:
            break;
        default:
            NCP_RETURN(NCP_ST_MUTEX_WRONG_STATE);
            break;
        }
    }
    else
    {
        /* multiple referers to this pool */
        if (NCP_MUTEX_PROCESS_SHARED_ROBUST != mtxAttr->attr)
        {
            NCP_RETURN(NCP_ST_MUTEX_CANNOT_CHANGE_TYPE);
        }
        else
        {
            NCP_RETURN(ncpStatus);
        }
    }

    /* Already SHARED so no change required */
    if (NCP_MUTEX_PROCESS_SHARED_ROBUST != mtxAttr->attr)
    {
        NCP_CALL(ncp_task_v3_destroy_lock(&(pPoolEntry->poolLock)));
        mtxAttr->attr = NCP_MUTEX_PROCESS_SHARED_ROBUST;
        mtxAttr->pid = 0;
        NCP_CALL(ncp_task_v3_create_lock(&(pPoolEntry->poolLock), mtxAttr));
    }

NCP_RETURN_LABEL
    return ncpStatus;
}

ncp_st_t
ncp_task_cpu_pool_mutex_attrib_get(ncp_task_tqs_hdl_t tqsHdl,
                                   ncp_mutex_attr_t *mtxType)
{
    ncp_st_t                    ncpStatus = NCP_ST_SUCCESS;
    runtime_mutex_attr_state_t *mtxAttr;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl = (ncp_task_pvt_tqsHdl_data_t *)tqsHdl;
    ncp_uint8_t                 poolId;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_cpu_pool_mutex_attrib_get_entry,
                          NCP_MSG_ENTRY,
                          "tqsHdl=%p mtxType=%p\n",
                          tqsHdl, mtxType);

    NCP_VALIDATE_TQS_HDL(pvtTqsHdl);
    poolId = pvtTqsHdl->cpuPoolId;
    NCP_ASSERT((poolId >= NCP_NCAV3_FIRST_CPU_POOL_ID &&
                poolId <= NCP_NCAV3_LAST_CPU_POOL_ID),
               NCP_ST_INVALID_PARAMETER);
    NCP_ASSERT(NULL != mtxType, NCP_ST_INVALID_PARAMETER);
    NCP_CHECK((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));
    mtxAttr = &pNcpTaskSwState->taskPools[poolId].mtxAttr;

    *mtxType = mtxAttr->attr;

NCP_RETURN_LABEL
    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_cpu_pool_mutex_attrib_get_exit,
                          NCP_MSG_EXIT,
                          "ncpStatus=%d mtxType=%p(%d)\n",
                          ncpStatus, mtxType, ((mtxType) ? (*mtxType) : -1));
    return ncpStatus;
}

ncp_st_t
ncp_task_tqs_mutex_attrib_set(ncp_uint8_t tqsId, ncp_mutex_attr_t mtxType)
{
    ncp_st_t                    ncpStatus  = NCP_ST_SUCCESS;
    ncp_task_tqs_swState_t     *pTqs;
    runtime_mutex_attr_state_t *mtxAttr;
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl  = NULL;
    ncp_pid_t                   myPid      = 0;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_tqs_mutex_attrib_set_entry,
                          NCP_MSG_ENTRY,
                          "tqsId=%d mtxType=%d\n",
                          tqsId, mtxType);

    NCP_ASSERT((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_ASSERT(tqsId < NCP_NCAV3_NUM_CPU_TQSETS, NCP_ST_INVALID_PARAMETER);

    myPid = ncp_get_pid();
    pTqs = &pNcpTaskSwState->tqsSwState[tqsId];
    mtxAttr = &pTqs->mtxAttr;

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));
    if (0 == pTqs->tqsUseCnt)
    {
        /* No one uses TQS change it's mutexes freely */
    }
    else if (1 == pTqs->tqsUseCnt)
    {
        /* pTqs->tqsUseCnt equals 1 =  verify that current process and thread
           are exclusive owners of taskHdl */
        ncp_task_process_info_t *pProcess;
        /* look for my process structure */
        pvtTqsHdl = pTqs->clientTqsHdls;
        if (NULL == pvtTqsHdl ||
            tqsId != pvtTqsHdl->tqsId)
        {
            NCP_RETURN(NCP_ST_TASK_INVALID_TASK_HANDLE);
        }
        pProcess = pvtTqsHdl->pProcess;
        NCP_CALL(ncp_task_os_pid_match_check(pProcess, TRUE,
                                             NCP_ST_TASK_PID_MISMATCH));
        /* Allow mutex type change only if sinlge thread is referencing TQS */
        if (1 != pProcess->numThreads ||
            NULL == pProcess->activeThreads)
        {
            NCP_RETURN(NCP_ST_TASK_THREAD_NOT_FOUND);
        }
        if (tqsId != pProcess->activeThreads->tqsId)
        {
            NCP_RETURN(NCP_ST_TASK_INVALID_TASK_HANDLE);
        }
    }
    else
    {
        if (mtxType != mtxAttr->attr)
        {
            NCP_RETURN(NCP_ST_MUTEX_CANNOT_CHANGE_TYPE);
        }

        if (0 != mtxAttr->pid && myPid != mtxAttr->pid)
        {
            NCP_RETURN(NCP_ST_TASK_INVALID_PID);
        }
        NCP_RETURN(ncpStatus);
    }

    switch (mtxType) {
    case NCP_MUTEX_PROCESS_PRIVATE:
        /* changing to private. Verify that each mapped Pool mutex isn't private
         * owned by other PID */
        if (0 != pTqs->cpuPoolId)
        {
            ncp_task_pool_t *pPoolEntry;
            pPoolEntry = &pNcpTaskSwState->taskPools[pTqs->cpuPoolId];
            if (NCP_MUTEX_PROCESS_PRIVATE == pPoolEntry->mtxAttr.attr &&
                myPid != pPoolEntry->mtxAttr.pid)
            {
                NCP_RETURN(NCP_ST_MUTEX_CANNOT_CHANGE_TYPE);
            }
        }
        break;
    case NCP_MUTEX_PROCESS_SHARED:
        /* changing to shared. */
        break;
    case NCP_MUTEX_PROCESS_SHARED_ROBUST:
        /* changing to robust. */
        break;
    default:
        NCP_RETURN(NCP_ST_INVALID_PARAMETER);
        break;
    }
    if (mtxType != mtxAttr->attr)
    {
        NCP_CALL(ncp_task_tqs_destroy_locks(tqsId));
        /* Change mutex type to be allocated */
        mtxAttr->attr = mtxType;
        if (NCP_MUTEX_PROCESS_PRIVATE == mtxType) {
            mtxAttr->pid = myPid;
        } else {
            mtxAttr->pid = 0;
        }
        NCP_CALL(ncp_task_tqs_create_locks(tqsId, mtxAttr));
    }
    else
    {
        NCP_RETURN(NCP_ST_SUCCESS);
    }

NCP_RETURN_LABEL
    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_tqs_mutex_attrib_set_exit,
                          NCP_MSG_EXIT,
                          "ncpStatus=%d\n",
                          ncpStatus);
    return ncpStatus;
}

ncp_st_t
ncp_task_tqs_mutex_attrib_get(ncp_uint8_t tqsId, ncp_mutex_attr_t *mtxType)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;
    runtime_mutex_attr_state_t *mtxAttr;
    NCP_MUTEX_LOCKED_FLAG_DECL(unlockRequired);
    NCP_TASK_LOCK_FLAGS(flags);

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_tqs_mutex_attrib_get_entry,
                          NCP_MSG_ENTRY,
                          "tqsId=%d mtxType=%p\n",
                          tqsId, mtxType);

    NCP_ASSERT((NULL != pNcpTaskSwState), NCP_ST_TASK_NO_GSM);
    NCP_ASSERT(tqsId < NCP_NCAV3_NUM_CPU_TQSETS, NCP_ST_INVALID_PARAMETER);
    NCP_ASSERT(NULL != mtxType, NCP_ST_INVALID_PARAMETER);

    NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));
    mtxAttr = &pNcpTaskSwState->tqsSwState[tqsId].mtxAttr;

    *mtxType = mtxAttr->attr;

NCP_RETURN_LABEL
    NCP_CLEANUP_MUTEX_CALL(NCP_TASK_FREE_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));

    NCP_TASKIO_TRACEPOINT(Intel_AXXIA_ncp_nca,
                          ncp_xlf_task_tqs_mutex_attrib_get_exit,
                          NCP_MSG_EXIT,
                          "ncpStatus=%d mtxType=%p(%d)\n",
                          ncpStatus, mtxType, ((mtxType) ? (*mtxType) : -1));
    return ncpStatus;
}
