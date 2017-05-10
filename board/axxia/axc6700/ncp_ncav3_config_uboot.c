#include "ncp_task_pvt.h"



ncp_st_t
ncp_task_initialize_tqs_task_state(
    ncp_hdl_t   ncpHdl,
    ncp_bool_t  uMode);


ncp_st_t
ncp_ncav3_get_ncap_id_list(
    ncp_t         *ncp,
    int           *numNCAPs,
    ncp_uint32_t **ncapList);


ncp_st_t
ncp_ncav3_configure_tqs_hw(
    ncp_t                   *ncp,
    ncp_dev_hdl_t            dev,
    int                      ncapId,
    int                      relTqsId,
    ncp_ncav3_cpu_profile_t *profile);


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
	debug_task("enter");
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

	debug_task("get id list");
    NCP_CALL(ncp_ncav3_get_ncap_id_list(
                myNcpHdl,
                &numNCAPs,
                &ncapList));

    /* Confirm that the requested TQS' NCAP exists. Will always succeed
       on ASIC devices. */
	debug_task("find ncap");
    for (i = 0; i < numNCAPs; i++)
    {
        if ((tqsId / 8) == ncapList[i])
        {
            ncapFound = TRUE;
            break;
        }
    }
	debug_task("found ncap");

    NCP_ASSERT(ncapFound, NCP_ST_TASK_NCAP_DOES_NOT_EXIST);

    /* If calling from the kernel, the lock is already held. */
    if (uMode == TRUE)
    {
        NCP_CALL(NCP_TASK_CLAIM_LOCK(pNcpTaskSwState->taskIoResourceLock, flags, &unlockRequired));
    }

	debug_task("get tqs");
    tqs = &pNcpTaskSwState->tqsSwState[tqsId];

    /* The TQS must be shut down before it can be configured. */
    NCP_ASSERT(tqs->configured == FALSE, NCP_ST_TASK_TQS_ALREADY_CONFIGURED);

    /* The TQS must be shut down before it can be configured. */
    NCP_ASSERT(tqs->tqsEnabled == TRUE, NCP_ST_TASK_TQS_DISABLED);

    /* Get the TQS's new profile */
	debug_task("get app profile %s",(appProfileName) ? (appProfileName->name) : "(null)");
    NCP_CALL(ncp_ncav3_get_app_profile_from_name(
        myNcpHdl,
        appProfileName->name,
        &appProfile));

    NCP_ASSERT(appProfile->profileType == CPU_PROFILE,
        NCP_ST_INVALID_PARAMETER);

	debug_task("check if in use");
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

	debug_task("set app profile");

    tqs->pAppProfile = appProfile;

    tqs->profileId = appProfile->baseProfile.id;

    /* Set the MQG for ncp_ncav3_tqs_memory_quota_group_get() to use. */
    tqs->mqg = mqgId;

	debug_task("init tqs control");
    NCP_CALL(ncp_ncav3_initialize_tqs_control(
                myNcpHdl,
                tqsId,
               &appProfile->baseProfile));

    /* Calling in the kernel relies on the fact that the kernel maintains the
     * iPCQ<->QG mappings.
     */

/* LAPAJ: this is done by trace files ?
	debug_task("config tqs hw");
    NCP_CALL(ncp_ncav3_configure_tqs_hw(
                myNcpHdl,
                myDevHdl,
                tqsId >> 3,
                tqsId % 8,
               &appProfile->baseProfile));
*/
    tqs->configured = TRUE;
	debug_task("end");

NCP_RETURN_LABEL

	debug_task("exit. return code %d",ncpStatus);
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
ncp_ncav3_config_uboot(ncp_hdl_t *oncpHdl){

	debug_task("enter");
    ncp_task_pvt_tqsHdl_data_t *pvtTqsHdl;
	pvtTqsHdl = malloc(sizeof(ncp_task_pvt_tqsHdl_data_t));
	memset(pvtTqsHdl,0,sizeof(ncp_task_pvt_tqsHdl_data_t));

	ncp_hdl_t ncpHdl = pvtTqsHdl;
	*oncpHdl = ncpHdl;

	ncp_task_process_info_t *pProcess;
	pProcess = malloc(sizeof(ncp_task_process_info_t));
	memset(pProcess,0,sizeof(ncp_task_process_info_t));
	pvtTqsHdl->pProcess = pProcess;
	pvtTqsHdl->nextTqsHdl = pvtTqsHdl;
	pProcess->activeThreads = &pvtTqsHdl->thisThread;

	ncp_uint32_t tqsId = 0;
	ncp_task_tqs_hdl_t tqsHdl = NULL;

	ncp_task_swState_t *tqsSwState;
	tqsSwState = malloc(sizeof(ncp_task_swState_t));
	memset(tqsSwState,0,sizeof(ncp_task_swState_t));
	pNcpTaskSwState = tqsSwState;
    pNcpTaskSwState->uMode = FALSE;
	pNcpTaskSwState->tqsSwState[tqsId].configured = TRUE;
	pNcpTaskSwState->tqsSwState[tqsId].tqsEnabled = TRUE;
	pNcpTaskSwState->tqsSwState[tqsId].staticConfiguration = TRUE;
    pNcpTaskSwState->tqsSwState[tqsId].domainId = pNcpTaskSwState->domainId;
	pNcpTaskSwState->tqsSwState[tqsId].validPoolsMask = 4; // just poolid 2
	pNcpTaskSwState->activeTqsHdls = ncpHdl;



	ncpTaskPoolMapCnt[2]++;
	pNcpTaskSwState->taskPools[2].poolPA             = 0x9B800000; // physical address
	pNcpTaskSwState->taskPools[2].poolSize           = 268409088;  // actualSize
	pNcpTaskSwState->taskPools[2].poolVA             = 0x9B800000; // physical address
	pNcpTaskSwState->taskPools[2].poolVAEnd          = 0xAB7F9900; // physical address + actual size

	// blockId = 0, for NCAv3 block size is 65535, see MME engine configuration source code
	pNcpTaskSwState->taskPools[2].numBlocks[0]       = 1638; // from numblocks
	pNcpTaskSwState->taskPools[2].numBlocksForNCA[0] = 1638; // check
	pNcpTaskSwState->taskPools[2].blocksPA[0]        = 0x9B800000; // blockId physicalBaseAddress
	pNcpTaskSwState->taskPools[2].blocksVA[0]        = 0x9B800000; // blockId physicalBaseAddress
	pNcpTaskSwState->taskPools[2].blocksVAend[0]     = 0xA1E5FFFF; // blocksVa + (65535 * numBlocks)

	// blockId = 1, for NCAv3 block size is 16384, see MME enginer congiguration source code
	pNcpTaskSwState->taskPools[2].numBlocks[1]       = 4096; // from numblocks
	pNcpTaskSwState->taskPools[2].numBlocksForNCA[1] = 4096; // check
	pNcpTaskSwState->taskPools[2].blocksPA[1]        = 0xA1E60000; // blockId physicalBaseAddress
	pNcpTaskSwState->taskPools[2].blocksVA[1]        = 0xA1E60000; // blockId physicalBaseAddress
	pNcpTaskSwState->taskPools[2].blocksVAend[1]     = 0xA5E5FFFF; // blocksVa + (4096 * numBlocks)

	// blockId = 2, for NCAv3 block size is 2048, see MME enginer congiguration source code
	pNcpTaskSwState->taskPools[2].numBlocks[2]       = 32768; // from numblocks
	pNcpTaskSwState->taskPools[2].numBlocksForNCA[2] = 32768; // check
	pNcpTaskSwState->taskPools[2].blocksPA[2]        = 0xA5E60000; // blockId physicalBaseAddress
	pNcpTaskSwState->taskPools[2].blocksVA[2]        = 0xA5E60000; // blockId physicalBaseAddress
	pNcpTaskSwState->taskPools[2].blocksVAend[2]     = 0xA9E5FFFF; // blocksVa + (2048 * numBlocks)

	// blockId = 3, for NCAv3 block size is 256, see MME enginer congiguration source code
	pNcpTaskSwState->taskPools[2].numBlocks[3]       = 104857; // from numblocks
	pNcpTaskSwState->taskPools[2].numBlocksForNCA[3] = 104857; // check
	pNcpTaskSwState->taskPools[2].blocksPA[3]        = 0xA9E60000; // blockId physicalBaseAddress
	pNcpTaskSwState->taskPools[2].blocksVA[3]        = 0xA9E60000; // blockId physicalBaseAddress
	pNcpTaskSwState->taskPools[2].blocksVAend[3]     = 0xAB7F9900; // blocksVa + (256 * numBlocks)

	
	pNcpTaskSwState->domainId                       = 0;
	// Engines.NCA.NcaDomainInfo.[id=0].startOffset
	pNcpTaskSwState->domainMemMap.domainBundle_VA   = 0x82000000;
	pNcpTaskSwState->domainMemMap.domainBundle_PA   = 0x82000000;
	// Engines.NCA.NcaDomainInfo.[id=0].size
	pNcpTaskSwState->domainMemMap.domainBundle_Size = 524288;






	ncp_ncav3_application_profile_t *appProfile;
	appProfile = malloc(sizeof(ncp_ncav3_application_profile_t));
	memset(appProfile,0,sizeof(ncp_ncav3_application_profile_t));
	appProfile->baseProfile.uMode = FALSE;
	appProfile->baseProfile.completionMode = NCP_TASK_AUTO_COMPLETION_MODE;
	appProfile->baseProfile.consumptionMode = NCP_TASK_IMMEDIATE_CONSUMPTION_MODE;
	strncpy(appProfile->baseProfile.name.name, "CPU_APP_PROFILE_1", sizeof("CPU_APP_PROFILE_1"));
	pNcpTaskSwState->tqsSwState[tqsId].pAppProfile = appProfile;

	ncp_ncav3_shared_data_region_map_t *sharedDataRegionMap;
	sharedDataRegionMap = malloc(sizeof(ncp_ncav3_shared_data_region_map_t));
	memset(sharedDataRegionMap,0,sizeof(ncp_ncav3_shared_data_region_map_t));
	pNcpTaskSwState->tqsSwState[tqsId].pAppProfile->baseProfile.sharedDataRegionMap = sharedDataRegionMap;
	ncp_task_process_info_t **pidArray;
	pidArray = malloc(sizeof(ncp_task_process_info_t*)*10);
	memset(pidArray,0,sizeof(ncp_task_process_info_t*)*10);
	pNcpTaskSwState->currPidArrayEntries = 10;
	pNcpTaskSwState->pidArray = pidArray;



	debug_task("before ncp_task_initialize_tqs_task_state");
	ncp_ncav3_hdl_t *nca = malloc(sizeof(ncp_ncav3_hdl_t));
	memset(nca,0,sizeof(ncp_ncav3_hdl_t));
	ncp_t *ncp = (ncp_t *) ncpHdl;
	ncp->ncaHdl = nca;
	nca->inConfigurationPhase = TRUE;
	nca->configInfo.numProfiles = 1;
	nca->configInfo.profiles = appProfile; 
	ncp->domainIsInternal = TRUE;
	myNcpHdl = ncpHdl;
	ncp_task_initialize_tqs_task_state(ncpHdl,FALSE);

	debug_task("exit");
	return NCP_ST_SUCCESS;
}
