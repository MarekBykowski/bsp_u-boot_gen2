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


#ifndef _NCP_AXIS_AXI2SER8_REGIONS_H_
#define _NCP_AXIS_AXI2SER8_REGIONS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "../ncp_task_basetypes.h"




#include "ncp_nodes.h"

#define    NCP_REGION_AXIS_AXI2SER8_A53_NCAP_NLINKS(n)          NCP_REGION_ID(NCP_NODE_AXIS_AXI2SER8, n + 1)

#define    NCP_REGION_AXIS_AXI2SER8_NCAV3_NLINKS                NCP_REGION_ID(NCP_NODE_AXIS_AXI2SER8, 0x0000) /* 360.0 */
#define    NCP_REGION_AXIS_AXI2SER8_A53_0_NCAP_NLINKS           NCP_REGION_ID(NCP_NODE_AXIS_AXI2SER8, 0x0001) /* 360.1 */
#define    NCP_REGION_AXIS_AXI2SER8_A53_1_NCAP_NLINKS           NCP_REGION_ID(NCP_NODE_AXIS_AXI2SER8, 0x0002) /* 360.2 */
#define    NCP_REGION_AXIS_AXI2SER8_A53_2_NCAP_NLINKS           NCP_REGION_ID(NCP_NODE_AXIS_AXI2SER8, 0x0003) /* 360.3 */
#define    NCP_REGION_AXIS_AXI2SER8_A53_3_NCAP_NLINKS           NCP_REGION_ID(NCP_NODE_AXIS_AXI2SER8, 0x0004) /* 360.4 */
#define    NCP_REGION_AXIS_AXI2SER8_A53_4_NCAP_NLINKS           NCP_REGION_ID(NCP_NODE_AXIS_AXI2SER8, 0x0005) /* 360.5 */
#define    NCP_REGION_AXIS_AXI2SER8_A53_5_NCAP_NLINKS           NCP_REGION_ID(NCP_NODE_AXIS_AXI2SER8, 0x0006) /* 360.6 */
#define    NCP_REGION_AXIS_AXI2SER8_A53_6_NCAP_NLINKS           NCP_REGION_ID(NCP_NODE_AXIS_AXI2SER8, 0x0007) /* 360.7 */
#define    NCP_REGION_AXIS_AXI2SER8_A53_7_NCAP_NLINKS           NCP_REGION_ID(NCP_NODE_AXIS_AXI2SER8, 0x0008) /* 360.8 */
#define    NCP_REGION_AXIS_AXI2SER8_FES_NCAP_NLINKS             NCP_REGION_ID(NCP_NODE_AXIS_AXI2SER8, 0x0009) /* 360.9 */
#define    NCP_REGION_AXIS_AXI2SER8_CDC_0_NCAPD_NLINKS          NCP_REGION_ID(NCP_NODE_AXIS_AXI2SER8, 0x000a) /* 360.10 */
#define    NCP_REGION_AXIS_AXI2SER8_CDC_1_NCAPD_NLINKS          NCP_REGION_ID(NCP_NODE_AXIS_AXI2SER8, 0x000b) /* 360.11 */
#define    NCP_REGION_AXIS_AXI2SER8_CDC_2_NCAPD_NLINKS          NCP_REGION_ID(NCP_NODE_AXIS_AXI2SER8, 0x000c) /* 360.12 */
#define    NCP_REGION_AXIS_AXI2SER8_CDC_3_NCAPD_NLINKS          NCP_REGION_ID(NCP_NODE_AXIS_AXI2SER8, 0x000d) /* 360.13 */


#ifdef __cplusplus
}
#endif

#endif /* _NCP_AXIS_AXI2SER8_REGIONS_H_ */
