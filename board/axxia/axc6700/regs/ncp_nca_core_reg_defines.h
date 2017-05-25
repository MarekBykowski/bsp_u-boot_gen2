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


#ifndef _NCP_NCA_CORE_REG_DEFINES_H_
#define _NCP_NCA_CORE_REG_DEFINES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"


    /* NODE 0x101 , TARGET 0x2*/



#define     NCP_NCA_CORE_AW_TRACE0_BASE                         (0x00000000)
#define     NCP_NCA_CORE_AW_TRACE0_END                          (0x00002000)
#define     NCP_NCA_CORE_AW_TRACE0_RANGE(addr) \
              (((addr) >= NCP_NCA_CORE_AW_TRACE0_BASE) && \
                  ((addr) < NCP_NCA_CORE_AW_TRACE0_END))


#define     NCP_NCA_CORE_CFG_ADDR_MAP_BASE                      (0x00080000)
#define     NCP_NCA_CORE_CFG_ADDR_MAP_END                       (0x000a0000)
#define     NCP_NCA_CORE_CFG_ADDR_MAP_RANGE(addr) \
           (((addr) >= NCP_NCA_CORE_CFG_ADDR_MAP_BASE) && \
            ((addr) < NCP_NCA_CORE_CFG_ADDR_MAP_END))


#define     NCP_NCA_CORE_ITP_ADDR_MAP_BASE                      (0x00100000)
#define     NCP_NCA_CORE_ITP_ADDR_MAP_END                       (0x00180000)
#define     NCP_NCA_CORE_ITP_ADDR_MAP_RANGE(addr) \
           (((addr) >= NCP_NCA_CORE_ITP_ADDR_MAP_BASE) && \
            ((addr) < NCP_NCA_CORE_ITP_ADDR_MAP_END))


#define     NCP_NCA_CORE_OTP_ADDR_MAP_BASE                      (0x00180000)
#define     NCP_NCA_CORE_OTP_ADDR_MAP_END                       (0x001a0000)
#define     NCP_NCA_CORE_OTP_ADDR_MAP_RANGE(addr) \
           (((addr) >= NCP_NCA_CORE_OTP_ADDR_MAP_BASE) && \
            ((addr) < NCP_NCA_CORE_OTP_ADDR_MAP_END))


#define     NCP_NCA_CORE_MTP_ADDR_MAP_BASE                      (0x00200000)
#define     NCP_NCA_CORE_MTP_ADDR_MAP_END                       (0x00210000)
#define     NCP_NCA_CORE_MTP_ADDR_MAP_RANGE(addr) \
           (((addr) >= NCP_NCA_CORE_MTP_ADDR_MAP_BASE) && \
            ((addr) < NCP_NCA_CORE_MTP_ADDR_MAP_END))


#define     NCP_NCA_CORE_AW_TRACE1_BASE                         (0x00280000)
#define     NCP_NCA_CORE_AW_TRACE1_END                          (0x00282000)
#define     NCP_NCA_CORE_AW_TRACE1_RANGE(addr) \
              (((addr) >= NCP_NCA_CORE_AW_TRACE1_BASE) && \
                  ((addr) < NCP_NCA_CORE_AW_TRACE1_END))

#ifdef __cplusplus
}
#endif

#endif /* _NCP_NCA_CORE_REG_DEFINES_H_ */
