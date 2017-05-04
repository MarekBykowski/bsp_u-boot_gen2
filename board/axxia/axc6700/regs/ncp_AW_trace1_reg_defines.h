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


#ifndef _NCP_AW_TRACE1_REG_DEFINES_H_
#define _NCP_AW_TRACE1_REG_DEFINES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"


    /* NODE 0x101 , TARGET 0xffffffff*/


#define     NCP_AW_TRACE1_CONTROL                               (0x00000100)
#define     NCP_AW_TRACE1_RESET_ATM                             (0x00000104)
#define     NCP_AW_TRACE1_POOL_ID                               (0x00000120)
#define     NCP_AW_TRACE1_TTYPE_TRACE_RECORD                    (0x00000124)
#define     NCP_AW_TRACE1_TTYPE_DIAGNOSTIC_RECORD               (0x00000128)
#define     NCP_AW_TRACE1_MATCH_ENABLE                          (0x0000012c)
#define     NCP_AW_TRACE1_ORDER_FIFO_CONTROL                    (0x00000130)
#define     NCP_AW_TRACE1_RESP_FIFO_1_STATUS                    (0x00000700)
#define     NCP_AW_TRACE1_RESP_FIFO_1_CONTROL                   (0x00000704)
#define     NCP_AW_TRACE1_REQ_FIFO_STATUS                       (0x00000708)
#define     NCP_AW_TRACE1_REQ_FIFO_CONTROL                      (0x0000070c)
#define     NCP_AW_TRACE1_STATUS                                (0x00000800)
#define     NCP_AW_TRACE1_ORDER_FIFO_STATUS                     (0x00000814)
#define     NCP_AW_TRACE1_COUNTER_INPUT_REQ_R                   (0x00000e00)
#define     NCP_AW_TRACE1_COUNTER_OUTPUT_REQ_R                  (0x00000e04)
#define     NCP_AW_TRACE1_COR_COUNTER_INPUT_REQ_R               (0x00000f00)
#define     NCP_AW_TRACE1_COR_COUNTER_OUTPUT_REQ_R              (0x00000f04)
#define     NCP_AW_TRACE1_CFG_SETUP                             (0x00000ffc)
#define     NCP_AW_TRACE1_TRACE_INT_REG_STATUS                  (0x00000010)
#define     NCP_AW_TRACE1_TRACE_INT_REG_EN                      (0x00000030)
#define     NCP_AW_TRACE1_TRACE_INT_REG_FRC                     (0x00000050)
#define     NCP_AW_TRACE1_WRAP_THRESH                           (0x00000108)
#define     NCP_AW_TRACE1_WRAP_THRESH_ACCESS_SIZE               (0x00000008) /* Bytes */
#define     NCP_AW_TRACE1_TRACE_FIRST                           (0x00000110)
#define     NCP_AW_TRACE1_TRACE_FIRST_ACCESS_SIZE               (0x00000008) /* Bytes */
#define     NCP_AW_TRACE1_TRACE_LAST                            (0x00000118)
#define     NCP_AW_TRACE1_TRACE_LAST_ACCESS_SIZE                (0x00000008) /* Bytes */
#define     NCP_AW_TRACE1_TRACE_WP                              (0x00000804)
#define     NCP_AW_TRACE1_TRACE_WP_ACCESS_SIZE                  (0x00000008) /* Bytes */
#define     NCP_AW_TRACE1_WRAP_CNTR                             (0x0000080c)
#define     NCP_AW_TRACE1_WRAP_CNTR_ACCESS_SIZE                 (0x00000008) /* Bytes */
#define     NCP_AW_TRACE1_MATCH_PATTERN_0                       (0x00001000)
#define     NCP_AW_TRACE1_MATCH_PATTERN_0_ACCESS_SIZE           (0x00000010) /* Bytes */
#define     NCP_AW_TRACE1_MATCH_PATTERN_1                       (0x00001010)
#define     NCP_AW_TRACE1_MATCH_PATTERN_1_ACCESS_SIZE           (0x00000010) /* Bytes */
#define     NCP_AW_TRACE1_MATCH_PATTERN_2                       (0x00001020)
#define     NCP_AW_TRACE1_MATCH_PATTERN_2_ACCESS_SIZE           (0x00000010) /* Bytes */
#define     NCP_AW_TRACE1_MATCH_PATTERN_3                       (0x00001030)
#define     NCP_AW_TRACE1_MATCH_PATTERN_3_ACCESS_SIZE           (0x00000010) /* Bytes */
#define     NCP_AW_TRACE1_MATCH_PATTERN_4                       (0x00001040)
#define     NCP_AW_TRACE1_MATCH_PATTERN_4_ACCESS_SIZE           (0x00000010) /* Bytes */
#define     NCP_AW_TRACE1_MATCH_PATTERN_5                       (0x00001050)
#define     NCP_AW_TRACE1_MATCH_PATTERN_5_ACCESS_SIZE           (0x00000010) /* Bytes */
#define     NCP_AW_TRACE1_MATCH_PATTERN_6                       (0x00001060)
#define     NCP_AW_TRACE1_MATCH_PATTERN_6_ACCESS_SIZE           (0x00000010) /* Bytes */
#define     NCP_AW_TRACE1_MATCH_MASK_0                          (0x00001070)
#define     NCP_AW_TRACE1_MATCH_MASK_0_ACCESS_SIZE              (0x00000010) /* Bytes */
#define     NCP_AW_TRACE1_MATCH_MASK_1                          (0x00001080)
#define     NCP_AW_TRACE1_MATCH_MASK_1_ACCESS_SIZE              (0x00000010) /* Bytes */
#define     NCP_AW_TRACE1_MATCH_MASK_2                          (0x00001090)
#define     NCP_AW_TRACE1_MATCH_MASK_2_ACCESS_SIZE              (0x00000010) /* Bytes */
#define     NCP_AW_TRACE1_MATCH_MASK_3                          (0x000010a0)
#define     NCP_AW_TRACE1_MATCH_MASK_3_ACCESS_SIZE              (0x00000010) /* Bytes */
#define     NCP_AW_TRACE1_MATCH_MASK_4                          (0x000010b0)
#define     NCP_AW_TRACE1_MATCH_MASK_4_ACCESS_SIZE              (0x00000010) /* Bytes */
#define     NCP_AW_TRACE1_MATCH_MASK_5                          (0x000010c0)
#define     NCP_AW_TRACE1_MATCH_MASK_5_ACCESS_SIZE              (0x00000010) /* Bytes */
#define     NCP_AW_TRACE1_MATCH_MASK_6                          (0x000010d0)
#define     NCP_AW_TRACE1_MATCH_MASK_6_ACCESS_SIZE              (0x00000010) /* Bytes */
#ifdef __cplusplus
}
#endif

#endif /* _NCP_AW_TRACE1_REG_DEFINES_H_ */
