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


#ifndef _NCP_NCA_CFG_REG_DEFINES_H_
#define _NCP_NCA_CFG_REG_DEFINES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"


    /* NODE 0x101 , TARGET 0xffffffff*/


#define     NCP_NCA_CFG_APB_BRIDGE_STATUS                       (0x00000000)
#define     NCP_NCA_CFG_INTERFACE0004                           (0x00000004)
#define     NCP_NCA_CFG_INTERFACE0008                           (0x00000008)
#define     NCP_NCA_CFG_INTERFACE000C                           (0x0000000c)
#define     NCP_NCA_CFG_CONTROL0100                             (0x00000100)
#define     NCP_NCA_CFG_CONTROL0104                             (0x00000104)
#define     NCP_NCA_CFG_CONTROL0108                             (0x00000108)
#define     NCP_NCA_CFG_CONTROL010C                             (0x0000010c)
#define     NCP_NCA_CFG_STATUS0800                              (0x00000800)
#define     NCP_NCA_CFG_STATUS0804                              (0x00000804)
#define     NCP_NCA_CFG_STATUS0808                              (0x00000808)
#define     NCP_NCA_CFG_STATUS080C                              (0x0000080c)
#define     NCP_NCA_CFG_STATUS0810                              (0x00000810)
#define     NCP_NCA_CFG_STATUS0814                              (0x00000814)
#define     NCP_NCA_CFG_STATUS0818                              (0x00000818)
#define     NCP_NCA_CFG_STATUS081C                              (0x0000081c)
#define     NCP_NCA_CFG_STATUS0820                              (0x00000820)
#define     NCP_NCA_CFG_STATUS0824                              (0x00000824)
#define     NCP_NCA_CFG_STATUS0828                              (0x00000828)
#define     NCP_NCA_CFG_STATUS082C                              (0x0000082c)
#define     NCP_NCA_CFG_STATUS0830                              (0x00000830)
#define     NCP_NCA_CFG_STATUS0834                              (0x00000834)
#define     NCP_NCA_CFG_STATUS0838                              (0x00000838)
#define     NCP_NCA_CFG_STATUS083C                              (0x0000083c)
#define     NCP_NCA_CFG_STATUS0840                              (0x00000840)
#define     NCP_NCA_CFG_STATUS0844                              (0x00000844)
#define     NCP_NCA_CFG_STATUS0848                              (0x00000848)
#define     NCP_NCA_CFG_STATUS084C                              (0x0000084c)
#define     NCP_NCA_CFG_STATUS0850                              (0x00000850)
#define     NCP_NCA_CFG_STATUS0854                              (0x00000854)
#define     NCP_NCA_CFG_STATUS0858                              (0x00000858)
#define     NCP_NCA_CFG_STATUS085C                              (0x0000085c)
#define     NCP_NCA_CFG_STATUS0860                              (0x00000860)
#define     NCP_NCA_CFG_STATUS0864                              (0x00000864)
#define     NCP_NCA_CFG_STATUS0868                              (0x00000868)
#define     NCP_NCA_CFG_STATUS086C                              (0x0000086c)
#define     NCP_NCA_CFG_STATUS0870                              (0x00000870)
#define     NCP_NCA_CFG_STATUS0874                              (0x00000874)
#define     NCP_NCA_CFG_STATUS0878                              (0x00000878)
#define     NCP_NCA_CFG_STATUS087C                              (0x0000087c)
#define     NCP_NCA_CFG_CFG_SETUP                               (0x00000ffc)
#define     NCP_NCA_CFG_CFG_DYNAMIC_CMD                         (0x00010000)
#define     NCP_NCA_CFG_CFG_DYNAMIC_STATUS                      (0x00010004)
#define     NCP_NCA_CFG_INTERRUPT_STATUS0                       (0x00000010)
#define     NCP_NCA_CFG_INTERRUPT_STATUS0_ALARM_MASK            (0xffffff00)
#define     NCP_NCA_CFG_INTERRUPT_STATUS0_SERVICE_MASK          (0x000000ff)
#define     NCP_NCA_CFG_INTERRUPT_STATUS1                       (0x00000014)
#define     NCP_NCA_CFG_INTERRUPT_STATUS1_ALARM_MASK            (0xffffffff)
#define     NCP_NCA_CFG_INTERRUPT_STATUS2                       (0x00000018)
#define     NCP_NCA_CFG_INTERRUPT_STATUS2_ALARM_MASK            (0xfffffff7)
#define     NCP_NCA_CFG_INTERRUPT_STATUS2_SERVICE_MASK          (0x00000008)
#define     NCP_NCA_CFG_INTERRUPT_STATUS3                       (0x0000001c)
#define     NCP_NCA_CFG_INTERRUPT_STATUS3_ALARM_MASK            (0xffffffff)
#define     NCP_NCA_CFG_INTERRUPT_EN0                           (0x00000030)
#define     NCP_NCA_CFG_INTERRUPT_EN0_ALARM_MASK                (0xffffff00)
#define     NCP_NCA_CFG_INTERRUPT_EN0_SERVICE_MASK              (0x000000ff)
#define     NCP_NCA_CFG_INTERRUPT_EN1                           (0x00000034)
#define     NCP_NCA_CFG_INTERRUPT_EN1_ALARM_MASK                (0xffffffff)
#define     NCP_NCA_CFG_INTERRUPT_EN2                           (0x00000038)
#define     NCP_NCA_CFG_INTERRUPT_EN2_ALARM_MASK                (0xfffffff7)
#define     NCP_NCA_CFG_INTERRUPT_EN2_SERVICE_MASK              (0x00000008)
#define     NCP_NCA_CFG_INTERRUPT_EN3                           (0x0000003c)
#define     NCP_NCA_CFG_INTERRUPT_EN3_ALARM_MASK                (0xffffffff)
#define     NCP_NCA_CFG_INTERRUPT_FRC0                          (0x00000050)
#define     NCP_NCA_CFG_INTERRUPT_FRC0_ALARM_MASK               (0xffffff00)
#define     NCP_NCA_CFG_INTERRUPT_FRC0_SERVICE_MASK             (0x000000ff)
#define     NCP_NCA_CFG_INTERRUPT_FRC1                          (0x00000054)
#define     NCP_NCA_CFG_INTERRUPT_FRC1_ALARM_MASK               (0xffffffff)
#define     NCP_NCA_CFG_INTERRUPT_FRC2                          (0x00000058)
#define     NCP_NCA_CFG_INTERRUPT_FRC2_ALARM_MASK               (0xfffffff7)
#define     NCP_NCA_CFG_INTERRUPT_FRC2_SERVICE_MASK             (0x00000008)
#define     NCP_NCA_CFG_INTERRUPT_FRC3                          (0x0000005c)
#define     NCP_NCA_CFG_INTERRUPT_FRC3_ALARM_MASK               (0xffffffff)
#ifdef __cplusplus
}
#endif

#endif /* _NCP_NCA_CFG_REG_DEFINES_H_ */
