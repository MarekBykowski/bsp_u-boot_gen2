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


#ifndef _NCP_A53_3_NCAP_NLINKS_REG_DEFINES_H_
#define _NCP_A53_3_NCAP_NLINKS_REG_DEFINES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"


    /* NODE 0x168 , TARGET 0x4*/



#define     NCP_A53_3_NCAP_NLINKS_NCAP_BASE                     (0x00000000)
#define     NCP_A53_3_NCAP_NLINKS_NCAP_END                      (0x00020000)
#define     NCP_A53_3_NCAP_NLINKS_NCAP_RANGE(addr) \
          (((addr) >= NCP_A53_3_NCAP_NLINKS_NCAP_BASE) && \
          ((addr) < NCP_A53_3_NCAP_NLINKS_NCAP_END))


#define     NCP_A53_3_NCAP_NLINKS_NLINK_IPCQ_REQ_BASE           (0x00020000)
#define     NCP_A53_3_NCAP_NLINKS_NLINK_IPCQ_REQ_END            (0x00021000)
#define     NCP_A53_3_NCAP_NLINKS_NLINK_IPCQ_REQ_RANGE(addr) \
 (((addr) >= NCP_A53_3_NCAP_NLINKS_NLINK_IPCQ_REQ_BASE) && \
  ((addr) < NCP_A53_3_NCAP_NLINKS_NLINK_IPCQ_REQ_END))


#define     NCP_A53_3_NCAP_NLINKS_NLINK_IPCQ_RSP_BASE           (0x00021000)
#define     NCP_A53_3_NCAP_NLINKS_NLINK_IPCQ_RSP_END            (0x00022000)
#define     NCP_A53_3_NCAP_NLINKS_NLINK_IPCQ_RSP_RANGE(addr) \
 (((addr) >= NCP_A53_3_NCAP_NLINKS_NLINK_IPCQ_RSP_BASE) && \
  ((addr) < NCP_A53_3_NCAP_NLINKS_NLINK_IPCQ_RSP_END))


#define     NCP_A53_3_NCAP_NLINKS_NLINK_OPCQ_REQ_BASE           (0x00022000)
#define     NCP_A53_3_NCAP_NLINKS_NLINK_OPCQ_REQ_END            (0x00023000)
#define     NCP_A53_3_NCAP_NLINKS_NLINK_OPCQ_REQ_RANGE(addr) \
 (((addr) >= NCP_A53_3_NCAP_NLINKS_NLINK_OPCQ_REQ_BASE) && \
  ((addr) < NCP_A53_3_NCAP_NLINKS_NLINK_OPCQ_REQ_END))


#define     NCP_A53_3_NCAP_NLINKS_NLINK_OPCQ_RSP_BASE           (0x00023000)
#define     NCP_A53_3_NCAP_NLINKS_NLINK_OPCQ_RSP_END            (0x00024000)
#define     NCP_A53_3_NCAP_NLINKS_NLINK_OPCQ_RSP_RANGE(addr) \
 (((addr) >= NCP_A53_3_NCAP_NLINKS_NLINK_OPCQ_RSP_BASE) && \
  ((addr) < NCP_A53_3_NCAP_NLINKS_NLINK_OPCQ_RSP_END))


#define     NCP_A53_3_NCAP_NLINKS_NLINK_MPCQ_REQ_BASE           (0x00024000)
#define     NCP_A53_3_NCAP_NLINKS_NLINK_MPCQ_REQ_END            (0x00025000)
#define     NCP_A53_3_NCAP_NLINKS_NLINK_MPCQ_REQ_RANGE(addr) \
 (((addr) >= NCP_A53_3_NCAP_NLINKS_NLINK_MPCQ_REQ_BASE) && \
  ((addr) < NCP_A53_3_NCAP_NLINKS_NLINK_MPCQ_REQ_END))


#define     NCP_A53_3_NCAP_NLINKS_NLINK_MPCQ_RSP_BASE           (0x00025000)
#define     NCP_A53_3_NCAP_NLINKS_NLINK_MPCQ_RSP_END            (0x00026000)
#define     NCP_A53_3_NCAP_NLINKS_NLINK_MPCQ_RSP_RANGE(addr) \
 (((addr) >= NCP_A53_3_NCAP_NLINKS_NLINK_MPCQ_RSP_BASE) && \
  ((addr) < NCP_A53_3_NCAP_NLINKS_NLINK_MPCQ_RSP_END))

#ifdef __cplusplus
}
#endif

#endif /* _NCP_A53_3_NCAP_NLINKS_REG_DEFINES_H_ */
