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
 **  **********************************************************************/


#ifndef _NCP_AXIS_AXI2SER8_ACCESS_H_
#define _NCP_AXIS_AXI2SER8_ACCESS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"




#include "regs/ncp_ncav3_nlinks_reg_access.h"
#include "regs/ncp_nlink_ipcq_req_reg_access.h"
#include "regs/ncp_nlink_ipcq_rsp_reg_access.h"
#include "regs/ncp_nlink_opcq_req_reg_access.h"
#include "regs/ncp_nlink_opcq_rsp_reg_access.h"
#include "regs/ncp_nlink_mpcq_req_reg_access.h"
#include "regs/ncp_nlink_mpcq_rsp_reg_access.h"
#include "regs/ncp_a53_0_ncap_nlinks_reg_access.h"
#include "regs/ncp_ncap_reg_access.h"
#include "regs/ncp_caal_ncap_mem_reg_access.h"
#include "regs/ncp_nlink_ipcq_req_reg_access.h"
#include "regs/ncp_nlink_ipcq_rsp_reg_access.h"
#include "regs/ncp_nlink_opcq_req_reg_access.h"
#include "regs/ncp_nlink_opcq_rsp_reg_access.h"
#include "regs/ncp_nlink_mpcq_req_reg_access.h"
#include "regs/ncp_nlink_mpcq_rsp_reg_access.h"
#include "regs/ncp_a53_1_ncap_nlinks_reg_access.h"
#include "regs/ncp_ncap_reg_access.h"
#include "regs/ncp_caal_ncap_mem_reg_access.h"
#include "regs/ncp_nlink_ipcq_req_reg_access.h"
#include "regs/ncp_nlink_ipcq_rsp_reg_access.h"
#include "regs/ncp_nlink_opcq_req_reg_access.h"
#include "regs/ncp_nlink_opcq_rsp_reg_access.h"
#include "regs/ncp_nlink_mpcq_req_reg_access.h"
#include "regs/ncp_nlink_mpcq_rsp_reg_access.h"
#include "regs/ncp_a53_2_ncap_nlinks_reg_access.h"
#include "regs/ncp_ncap_reg_access.h"
#include "regs/ncp_caal_ncap_mem_reg_access.h"
#include "regs/ncp_nlink_ipcq_req_reg_access.h"
#include "regs/ncp_nlink_ipcq_rsp_reg_access.h"
#include "regs/ncp_nlink_opcq_req_reg_access.h"
#include "regs/ncp_nlink_opcq_rsp_reg_access.h"
#include "regs/ncp_nlink_mpcq_req_reg_access.h"
#include "regs/ncp_nlink_mpcq_rsp_reg_access.h"
#include "regs/ncp_a53_3_ncap_nlinks_reg_access.h"
#include "regs/ncp_ncap_reg_access.h"
#include "regs/ncp_caal_ncap_mem_reg_access.h"
#include "regs/ncp_nlink_ipcq_req_reg_access.h"
#include "regs/ncp_nlink_ipcq_rsp_reg_access.h"
#include "regs/ncp_nlink_opcq_req_reg_access.h"
#include "regs/ncp_nlink_opcq_rsp_reg_access.h"
#include "regs/ncp_nlink_mpcq_req_reg_access.h"
#include "regs/ncp_nlink_mpcq_rsp_reg_access.h"
#include "regs/ncp_a53_4_ncap_nlinks_reg_access.h"
#include "regs/ncp_ncap_reg_access.h"
#include "regs/ncp_caal_ncap_mem_reg_access.h"
#include "regs/ncp_nlink_ipcq_req_reg_access.h"
#include "regs/ncp_nlink_ipcq_rsp_reg_access.h"
#include "regs/ncp_nlink_opcq_req_reg_access.h"
#include "regs/ncp_nlink_opcq_rsp_reg_access.h"
#include "regs/ncp_nlink_mpcq_req_reg_access.h"
#include "regs/ncp_nlink_mpcq_rsp_reg_access.h"
#include "regs/ncp_a53_5_ncap_nlinks_reg_access.h"
#include "regs/ncp_ncap_reg_access.h"
#include "regs/ncp_caal_ncap_mem_reg_access.h"
#include "regs/ncp_nlink_ipcq_req_reg_access.h"
#include "regs/ncp_nlink_ipcq_rsp_reg_access.h"
#include "regs/ncp_nlink_opcq_req_reg_access.h"
#include "regs/ncp_nlink_opcq_rsp_reg_access.h"
#include "regs/ncp_nlink_mpcq_req_reg_access.h"
#include "regs/ncp_nlink_mpcq_rsp_reg_access.h"
#include "regs/ncp_a53_6_ncap_nlinks_reg_access.h"
#include "regs/ncp_ncap_reg_access.h"
#include "regs/ncp_caal_ncap_mem_reg_access.h"
#include "regs/ncp_nlink_ipcq_req_reg_access.h"
#include "regs/ncp_nlink_ipcq_rsp_reg_access.h"
#include "regs/ncp_nlink_opcq_req_reg_access.h"
#include "regs/ncp_nlink_opcq_rsp_reg_access.h"
#include "regs/ncp_nlink_mpcq_req_reg_access.h"
#include "regs/ncp_nlink_mpcq_rsp_reg_access.h"
#include "regs/ncp_a53_7_ncap_nlinks_reg_access.h"
#include "regs/ncp_ncap_reg_access.h"
#include "regs/ncp_caal_ncap_mem_reg_access.h"
#include "regs/ncp_nlink_ipcq_req_reg_access.h"
#include "regs/ncp_nlink_ipcq_rsp_reg_access.h"
#include "regs/ncp_nlink_opcq_req_reg_access.h"
#include "regs/ncp_nlink_opcq_rsp_reg_access.h"
#include "regs/ncp_nlink_mpcq_req_reg_access.h"
#include "regs/ncp_nlink_mpcq_rsp_reg_access.h"
#include "regs/ncp_fes_ncap_nlinks_reg_access.h"
#include "regs/ncp_ncap_reg_access.h"
#include "regs/ncp_caal_ncap_mem_reg_access.h"
#include "regs/ncp_nlink_ipcq_req_reg_access.h"
#include "regs/ncp_nlink_ipcq_rsp_reg_access.h"
#include "regs/ncp_nlink_opcq_req_reg_access.h"
#include "regs/ncp_nlink_opcq_rsp_reg_access.h"
#include "regs/ncp_nlink_mpcq_req_reg_access.h"
#include "regs/ncp_nlink_mpcq_rsp_reg_access.h"
#include "regs/ncp_cdc_0_ncapd_nlinks_reg_access.h"
#include "regs/ncp_ncapd_reg_access.h"
#include "regs/ncp_caal_ncapd_mem_reg_access.h"
#include "regs/ncp_ncap_dsp_regs_reg_access.h"
#include "regs/ncp_nlink_ipcq_req_reg_access.h"
#include "regs/ncp_nlink_ipcq_rsp_reg_access.h"
#include "regs/ncp_nlink_opcq_req_reg_access.h"
#include "regs/ncp_nlink_opcq_rsp_reg_access.h"
#include "regs/ncp_nlink_mpcq_req_reg_access.h"
#include "regs/ncp_nlink_mpcq_rsp_reg_access.h"
#include "regs/ncp_cdc_1_ncapd_nlinks_reg_access.h"
#include "regs/ncp_ncapd_reg_access.h"
#include "regs/ncp_caal_ncapd_mem_reg_access.h"
#include "regs/ncp_ncap_dsp_regs_reg_access.h"
#include "regs/ncp_nlink_ipcq_req_reg_access.h"
#include "regs/ncp_nlink_ipcq_rsp_reg_access.h"
#include "regs/ncp_nlink_opcq_req_reg_access.h"
#include "regs/ncp_nlink_opcq_rsp_reg_access.h"
#include "regs/ncp_nlink_mpcq_req_reg_access.h"
#include "regs/ncp_nlink_mpcq_rsp_reg_access.h"
#include "regs/ncp_cdc_2_ncapd_nlinks_reg_access.h"
#include "regs/ncp_ncapd_reg_access.h"
#include "regs/ncp_caal_ncapd_mem_reg_access.h"
#include "regs/ncp_ncap_dsp_regs_reg_access.h"
#include "regs/ncp_nlink_ipcq_req_reg_access.h"
#include "regs/ncp_nlink_ipcq_rsp_reg_access.h"
#include "regs/ncp_nlink_opcq_req_reg_access.h"
#include "regs/ncp_nlink_opcq_rsp_reg_access.h"
#include "regs/ncp_nlink_mpcq_req_reg_access.h"
#include "regs/ncp_nlink_mpcq_rsp_reg_access.h"
#include "regs/ncp_cdc_3_ncapd_nlinks_reg_access.h"
#include "regs/ncp_ncapd_reg_access.h"
#include "regs/ncp_caal_ncapd_mem_reg_access.h"
#include "regs/ncp_ncap_dsp_regs_reg_access.h"
#include "regs/ncp_nlink_ipcq_req_reg_access.h"
#include "regs/ncp_nlink_ipcq_rsp_reg_access.h"
#include "regs/ncp_nlink_opcq_req_reg_access.h"
#include "regs/ncp_nlink_opcq_rsp_reg_access.h"
#include "regs/ncp_nlink_mpcq_req_reg_access.h"
#include "regs/ncp_nlink_mpcq_rsp_reg_access.h"



#ifdef __cplusplus
}
#endif

#endif /* _NCP_AXIS_AXI2SER8_ACCESS_H_ */
