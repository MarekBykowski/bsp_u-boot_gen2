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


#ifndef _NCP_AXIS_AXI2SER8_REG_DEFINES_H_
#define _NCP_AXIS_AXI2SER8_REG_DEFINES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"


    /* NODE 0x168 , TARGET 0xffffffff*/



#define     NCP_AXIS_AXI2SER8_NCAV3_NLINKS_BASE                 (0x00000000)
#define     NCP_AXIS_AXI2SER8_NCAV3_NLINKS_END                  (0x00040000)
#define     NCP_AXIS_AXI2SER8_NCAV3_NLINKS_RANGE(addr) \
      (((addr) >= NCP_AXIS_AXI2SER8_NCAV3_NLINKS_BASE) && \
      ((addr) < NCP_AXIS_AXI2SER8_NCAV3_NLINKS_END))


#define     NCP_AXIS_AXI2SER8_A53_0_NCAP_NLINKS_BASE            (0x00000000)
#define     NCP_AXIS_AXI2SER8_A53_0_NCAP_NLINKS_END             (0x00040000)
#define     NCP_AXIS_AXI2SER8_A53_0_NCAP_NLINKS_RANGE(addr) \
 (((addr) >= NCP_AXIS_AXI2SER8_A53_0_NCAP_NLINKS_BASE) && \
  ((addr) < NCP_AXIS_AXI2SER8_A53_0_NCAP_NLINKS_END))


#define     NCP_AXIS_AXI2SER8_A53_1_NCAP_NLINKS_BASE            (0x00000000)
#define     NCP_AXIS_AXI2SER8_A53_1_NCAP_NLINKS_END             (0x00040000)
#define     NCP_AXIS_AXI2SER8_A53_1_NCAP_NLINKS_RANGE(addr) \
 (((addr) >= NCP_AXIS_AXI2SER8_A53_1_NCAP_NLINKS_BASE) && \
  ((addr) < NCP_AXIS_AXI2SER8_A53_1_NCAP_NLINKS_END))


#define     NCP_AXIS_AXI2SER8_A53_2_NCAP_NLINKS_BASE            (0x00000000)
#define     NCP_AXIS_AXI2SER8_A53_2_NCAP_NLINKS_END             (0x00040000)
#define     NCP_AXIS_AXI2SER8_A53_2_NCAP_NLINKS_RANGE(addr) \
 (((addr) >= NCP_AXIS_AXI2SER8_A53_2_NCAP_NLINKS_BASE) && \
  ((addr) < NCP_AXIS_AXI2SER8_A53_2_NCAP_NLINKS_END))


#define     NCP_AXIS_AXI2SER8_A53_3_NCAP_NLINKS_BASE            (0x00000000)
#define     NCP_AXIS_AXI2SER8_A53_3_NCAP_NLINKS_END             (0x00040000)
#define     NCP_AXIS_AXI2SER8_A53_3_NCAP_NLINKS_RANGE(addr) \
 (((addr) >= NCP_AXIS_AXI2SER8_A53_3_NCAP_NLINKS_BASE) && \
  ((addr) < NCP_AXIS_AXI2SER8_A53_3_NCAP_NLINKS_END))


#define     NCP_AXIS_AXI2SER8_A53_4_NCAP_NLINKS_BASE            (0x00000000)
#define     NCP_AXIS_AXI2SER8_A53_4_NCAP_NLINKS_END             (0x00040000)
#define     NCP_AXIS_AXI2SER8_A53_4_NCAP_NLINKS_RANGE(addr) \
 (((addr) >= NCP_AXIS_AXI2SER8_A53_4_NCAP_NLINKS_BASE) && \
  ((addr) < NCP_AXIS_AXI2SER8_A53_4_NCAP_NLINKS_END))


#define     NCP_AXIS_AXI2SER8_A53_5_NCAP_NLINKS_BASE            (0x00000000)
#define     NCP_AXIS_AXI2SER8_A53_5_NCAP_NLINKS_END             (0x00040000)
#define     NCP_AXIS_AXI2SER8_A53_5_NCAP_NLINKS_RANGE(addr) \
 (((addr) >= NCP_AXIS_AXI2SER8_A53_5_NCAP_NLINKS_BASE) && \
  ((addr) < NCP_AXIS_AXI2SER8_A53_5_NCAP_NLINKS_END))


#define     NCP_AXIS_AXI2SER8_A53_6_NCAP_NLINKS_BASE            (0x00000000)
#define     NCP_AXIS_AXI2SER8_A53_6_NCAP_NLINKS_END             (0x00040000)
#define     NCP_AXIS_AXI2SER8_A53_6_NCAP_NLINKS_RANGE(addr) \
 (((addr) >= NCP_AXIS_AXI2SER8_A53_6_NCAP_NLINKS_BASE) && \
  ((addr) < NCP_AXIS_AXI2SER8_A53_6_NCAP_NLINKS_END))


#define     NCP_AXIS_AXI2SER8_A53_7_NCAP_NLINKS_BASE            (0x00000000)
#define     NCP_AXIS_AXI2SER8_A53_7_NCAP_NLINKS_END             (0x00040000)
#define     NCP_AXIS_AXI2SER8_A53_7_NCAP_NLINKS_RANGE(addr) \
 (((addr) >= NCP_AXIS_AXI2SER8_A53_7_NCAP_NLINKS_BASE) && \
  ((addr) < NCP_AXIS_AXI2SER8_A53_7_NCAP_NLINKS_END))


#define     NCP_AXIS_AXI2SER8_FES_NCAP_NLINKS_BASE              (0x00000000)
#define     NCP_AXIS_AXI2SER8_FES_NCAP_NLINKS_END               (0x00040000)
#define     NCP_AXIS_AXI2SER8_FES_NCAP_NLINKS_RANGE(addr) \
   (((addr) >= NCP_AXIS_AXI2SER8_FES_NCAP_NLINKS_BASE) && \
   ((addr) < NCP_AXIS_AXI2SER8_FES_NCAP_NLINKS_END))


#define     NCP_AXIS_AXI2SER8_CDC_0_NCAPD_NLINKS_BASE           (0x00000000)
#define     NCP_AXIS_AXI2SER8_CDC_0_NCAPD_NLINKS_END            (0x00040000)
#define     NCP_AXIS_AXI2SER8_CDC_0_NCAPD_NLINKS_RANGE(addr) \
 (((addr) >= NCP_AXIS_AXI2SER8_CDC_0_NCAPD_NLINKS_BASE) && \
  ((addr) < NCP_AXIS_AXI2SER8_CDC_0_NCAPD_NLINKS_END))


#define     NCP_AXIS_AXI2SER8_CDC_1_NCAPD_NLINKS_BASE           (0x00000000)
#define     NCP_AXIS_AXI2SER8_CDC_1_NCAPD_NLINKS_END            (0x00040000)
#define     NCP_AXIS_AXI2SER8_CDC_1_NCAPD_NLINKS_RANGE(addr) \
 (((addr) >= NCP_AXIS_AXI2SER8_CDC_1_NCAPD_NLINKS_BASE) && \
  ((addr) < NCP_AXIS_AXI2SER8_CDC_1_NCAPD_NLINKS_END))


#define     NCP_AXIS_AXI2SER8_CDC_2_NCAPD_NLINKS_BASE           (0x00000000)
#define     NCP_AXIS_AXI2SER8_CDC_2_NCAPD_NLINKS_END            (0x00040000)
#define     NCP_AXIS_AXI2SER8_CDC_2_NCAPD_NLINKS_RANGE(addr) \
 (((addr) >= NCP_AXIS_AXI2SER8_CDC_2_NCAPD_NLINKS_BASE) && \
  ((addr) < NCP_AXIS_AXI2SER8_CDC_2_NCAPD_NLINKS_END))


#define     NCP_AXIS_AXI2SER8_CDC_3_NCAPD_NLINKS_BASE           (0x00000000)
#define     NCP_AXIS_AXI2SER8_CDC_3_NCAPD_NLINKS_END            (0x00040000)
#define     NCP_AXIS_AXI2SER8_CDC_3_NCAPD_NLINKS_RANGE(addr) \
 (((addr) >= NCP_AXIS_AXI2SER8_CDC_3_NCAPD_NLINKS_BASE) && \
  ((addr) < NCP_AXIS_AXI2SER8_CDC_3_NCAPD_NLINKS_END))

#ifdef __cplusplus
}
#endif

#endif /* _NCP_AXIS_AXI2SER8_REG_DEFINES_H_ */
