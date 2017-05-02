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


#ifndef _NCP_NCA_REG_DEFINES_H_
#define _NCP_NCA_REG_DEFINES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"


    /* NODE 0x101 , TARGET 0xffffffff*/




#define     NCP_NCA_NCAV3_DMM_BASE                              (0x00000000)
#define     NCP_NCA_NCAV3_DMM(n)                                (0x00000000 + (8*(n)))
#define     NCP_NCA_NCAV3_DMM_ACCESS_SIZE                       (0x00000008) /* Bytes */
#define     NCP_NCA_NCAV3_DMM_COUNT                             (0x00100000)
#define     NCP_NCA_NCAV3_DMM_IDX(addr) \
                      (((addr) - NCP_NCA_NCAV3_DMM_BASE) / 8)           
#define     NCP_NCA_NCAV3_DMM_END                               (0x00800000)
#define     NCP_NCA_NCAV3_DMM_RANGE(addr) \
                   (((addr) >= NCP_NCA_NCAV3_DMM_BASE) && \
                            ((addr) < NCP_NCA_NCAV3_DMM_END))


#define     NCP_NCA_CMN_AXI_MAP_BASE                            (0x00000000)
#define     NCP_NCA_CMN_AXI_MAP_END                             (0x00040000)
#define     NCP_NCA_CMN_AXI_MAP_RANGE(addr) \
                 (((addr) >= NCP_NCA_CMN_AXI_MAP_BASE) && \
                        ((addr) < NCP_NCA_CMN_AXI_MAP_END))


#define     NCP_NCA_QPM_ADDRESS_MAP_BASE                        (0x00000000)
#define     NCP_NCA_QPM_ADDRESS_MAP_END                         (0x00002000)
#define     NCP_NCA_QPM_ADDRESS_MAP_RANGE(addr) \
             (((addr) >= NCP_NCA_QPM_ADDRESS_MAP_BASE) && \
                ((addr) < NCP_NCA_QPM_ADDRESS_MAP_END))


#define     NCP_NCA_CORE_ADDR_MAP_BASE                          (0x00000000)
#define     NCP_NCA_CORE_ADDR_MAP_END                           (0x00400000)
#define     NCP_NCA_CORE_ADDR_MAP_RANGE(addr) \
               (((addr) >= NCP_NCA_CORE_ADDR_MAP_BASE) && \
                    ((addr) < NCP_NCA_CORE_ADDR_MAP_END))

#ifdef __cplusplus
}
#endif

#endif /* _NCP_NCA_REG_DEFINES_H_ */
