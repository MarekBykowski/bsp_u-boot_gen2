#include "ncp_task_basetypes.h"
#include "ncp_task_pvt.h"

ncp_dev_hdl_t ncp_dev_hdls[NCP_MAX_DEVS];
ncp_hwio_trace_func_t ncpHwioTraceFunc = NULL;
void *ncpHwioTraceFuncArg = NULL;



ncp_st_t ncp_dev_num_get(ncp_dev_hdl_t devHdl, ncp_uint32_t *devNum){
	return NCP_ST_SUCCESS;
}


ncp_st_t
ncp_task_os_pid_match_check(ncp_task_process_info_t *pProcess, ncp_bool_t expectedResult, ncp_st_t specificError)
{
    ncp_st_t ncpStatus = NCP_ST_SUCCESS;  /* Always return success for kernel mode */

NCP_RETURN_LABEL
     return(ncpStatus);
 }

ncp_st_t ncp_task_os_pid_store(ncp_task_process_info_t *pProcess)
{
	ncp_st_t ncpStatus = NCP_ST_SUCCESS;  /* Always return success for kernel mode */

	NCP_RETURN_LABEL
		return(ncpStatus);
}


void *ncp_malloc(ncp_size_t size){
	return NULL;
}



ncp_pid_t ncp_get_pid(void){
	return 0;
}

ncp_st_t ncp_validate_handle(ncp_hdl_t ncpHdl){
	return NCP_ST_SUCCESS;
}
ncp_st_t ncp_dev_open(ncp_uint32_t devNum, ncp_uint32_t flags, ncp_dev_hdl_t *devHdl){
	return NCP_ST_SUCCESS;
}
ncp_st_t ncp_dev_close(ncp_dev_hdl_t *devHdl){
	return NCP_ST_SUCCESS;
}

ncp_st_t ncp_nvm_robust_realloc(void *origPtr, ncp_size_t size, void **ptr){
	return NCP_ST_SUCCESS;
}
ncp_st_t ncp_nvm_robust_malloc(ncp_size_t size, void **ptr, ncp_bool_t doMemset){
	return NCP_ST_SUCCESS;
}
ncp_st_t ncp_nvm_robust_free(void **pPtr){
	return NCP_ST_SUCCESS;
}

ncp_st_t ncp_dev_nca_wait_for_isr_wakeup(ncp_dev_hdl_t dev, ncp_uint32_t intrType, ncp_uint8_t grp, ncp_uint32_t grpRelQueueId, ncp_uint8_t  tqsID){
	return NCP_ST_SUCCESS;
}

size_t ncp_strnlen(const char *s, size_t maxLen){
	return 0;
}
void arch_prefetch_data(const void *mva){
	return;
}
void arch_prefetch_data_for_write(const void *mva){
	return;
}
void *ncp_calloc(ncp_size_t no, ncp_size_t size){
	return NULL;
}
void *ncp_nvm_calloc(ncp_size_t no, ncp_size_t size){
	return NULL;
}
void  ncp_free(void *ptr){
	return;
}

void  ncp_hr_gettime_us(ncp_timespec_us_t *timespec){
	return;
}
int   ncp_hr_time_compare(ncp_timespec_us_t *timespecStart_us, ncp_timespec_us_t *timespecEnd_us){
	return 0;
}
void  ncp_hr_addtime_us(ncp_timespec_us_t *timespecStart_us, ncp_timespec_us_t *timespecEnd_us, ncp_uint64_t uSecs){
	return;
}

ncp_st_t ncp_block_write32(ncp_dev_hdl_t devHdl, ncp_region_id_t regionId, ncp_uint64_t offset, ncp_uint32_t *buffer, ncp_uint32_t count, ncp_uint32_t flags){
	return NCP_ST_SUCCESS;
}

ncp_st_t ncp_block_write64(ncp_dev_hdl_t devHdl, ncp_region_id_t regionId, ncp_uint64_t offset, ncp_uint64_t *buffer, ncp_uint32_t count, ncp_uint32_t flags){
	return NCP_ST_SUCCESS;
}


ncp_st_t ncp_block_read32(ncp_dev_hdl_t devHdl, ncp_region_id_t regionId, ncp_uint64_t offset, ncp_uint32_t *buffer, ncp_uint32_t count, ncp_uint32_t flags){
	return NCP_ST_SUCCESS;
}


ncp_st_t ncp_block_read64(ncp_dev_hdl_t devHdl, ncp_region_id_t regionId, ncp_uint64_t offset, ncp_uint64_t *buffer, ncp_uint32_t count, ncp_uint32_t flags){
	return NCP_ST_SUCCESS;
}



ncp_st_t ncp_dev_block_read32(ncp_dev_hdl_t devHdl, ncp_region_id_t regionId, ncp_uint64_t offset, ncp_uint32_t *buffer, ncp_uint32_t count, ncp_uint32_t flags){
	return NCP_ST_SUCCESS;
}



ncp_st_t
ncp_dev_block_write32(ncp_dev_hdl_t devHdl, ncp_region_id_t regionId, ncp_uint64_t offset, ncp_uint32_t *buffer, ncp_uint32_t count, ncp_uint32_t flags){
	return NCP_ST_SUCCESS;
}

