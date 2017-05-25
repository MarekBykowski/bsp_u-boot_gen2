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


#ifndef _NCP_CAAL_NCA_SYS_MEM_REG_DEFINES_H_
#define _NCP_CAAL_NCA_SYS_MEM_REG_DEFINES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"


    /* NODE 0x16 , TARGET 0x10*/


#define     NCP_CAAL_NCA_SYS_MEM_APB_BRIDGE_STATUS              (0x00000000)
#define     NCP_CAAL_NCA_SYS_MEM_CONTROL                        (0x00000004)
#define     NCP_CAAL_NCA_SYS_MEM_ORT_LIMIT                      (0x00000008)
#define     NCP_CAAL_NCA_SYS_MEM_OWT_LIMIT                      (0x0000000c)
#define     NCP_CAAL_NCA_SYS_MEM_ADDR_CHK_ENB                   (0x0000001c)

#define     NCP_CAAL_NCA_SYS_MEM_CRR_WRR_WEIGHTS_BASE           (0x00000040)
#define     NCP_CAAL_NCA_SYS_MEM_CRR_WRR_WEIGHTS(n)             (0x00000040 + (4*(n)))
#define     NCP_CAAL_NCA_SYS_MEM_CRR_WRR_WEIGHTS_COUNT          (0x00000007)
#define     NCP_CAAL_NCA_SYS_MEM_CRR_WRR_WEIGHTS_IDX(addr) \
   (((addr) - NCP_CAAL_NCA_SYS_MEM_CRR_WRR_WEIGHTS_BASE) / 4)
#define     NCP_CAAL_NCA_SYS_MEM_CRR_WRR_WEIGHTS_END            (0x0000005c)
#define     NCP_CAAL_NCA_SYS_MEM_CRR_WRR_WEIGHTS_RANGE(addr) \
 (((addr) >= NCP_CAAL_NCA_SYS_MEM_CRR_WRR_WEIGHTS_BASE) && \
  ((addr) < NCP_CAAL_NCA_SYS_MEM_CRR_WRR_WEIGHTS_END))


#define     NCP_CAAL_NCA_SYS_MEM_CWR_WRR_WEIGHTS_BASE           (0x00000080)
#define     NCP_CAAL_NCA_SYS_MEM_CWR_WRR_WEIGHTS(n)             (0x00000080 + (4*(n)))
#define     NCP_CAAL_NCA_SYS_MEM_CWR_WRR_WEIGHTS_COUNT          (0x00000005)
#define     NCP_CAAL_NCA_SYS_MEM_CWR_WRR_WEIGHTS_IDX(addr) \
   (((addr) - NCP_CAAL_NCA_SYS_MEM_CWR_WRR_WEIGHTS_BASE) / 4)
#define     NCP_CAAL_NCA_SYS_MEM_CWR_WRR_WEIGHTS_END            (0x00000094)
#define     NCP_CAAL_NCA_SYS_MEM_CWR_WRR_WEIGHTS_RANGE(addr) \
 (((addr) >= NCP_CAAL_NCA_SYS_MEM_CWR_WRR_WEIGHTS_BASE) && \
  ((addr) < NCP_CAAL_NCA_SYS_MEM_CWR_WRR_WEIGHTS_END))

#define     NCP_CAAL_NCA_SYS_MEM_COUNTER_CTL                    (0x000000c0)
#define     NCP_CAAL_NCA_SYS_MEM_COUNTER_SEL                    (0x000000c4)
#define     NCP_CAAL_NCA_SYS_MEM_COUNTER_ID                     (0x000000c8)
#define     NCP_CAAL_NCA_SYS_MEM_TORT_CNT                       (0x000000f8)
#define     NCP_CAAL_NCA_SYS_MEM_TOWT_CNT                       (0x000000fc)
#define     NCP_CAAL_NCA_SYS_MEM_CRR_SYNDROME0                  (0x00000100)
#define     NCP_CAAL_NCA_SYS_MEM_CRR_SYNDROME1                  (0x00000104)
#define     NCP_CAAL_NCA_SYS_MEM_CRR_SYNDROME2                  (0x00000108)
#define     NCP_CAAL_NCA_SYS_MEM_CRR_SYNDROME3                  (0x0000010c)
#define     NCP_CAAL_NCA_SYS_MEM_CRR_SYNDROME4                  (0x00000110)
#define     NCP_CAAL_NCA_SYS_MEM_CRR_SYNDROME5                  (0x00000114)
#define     NCP_CAAL_NCA_SYS_MEM_CWR_SYNDROME0                  (0x00000118)
#define     NCP_CAAL_NCA_SYS_MEM_CWR_SYNDROME1                  (0x0000011c)
#define     NCP_CAAL_NCA_SYS_MEM_CWR_SYNDROME2                  (0x00000120)
#define     NCP_CAAL_NCA_SYS_MEM_CWR_SYNDROME3                  (0x00000124)
#define     NCP_CAAL_NCA_SYS_MEM_CWR_SYNDROME4                  (0x00000128)
#define     NCP_CAAL_NCA_SYS_MEM_CWR_SYNDROME5                  (0x0000012c)
#define     NCP_CAAL_NCA_SYS_MEM_CWD_SYNDROME                   (0x00000130)
#define     NCP_CAAL_NCA_SYS_MEM_R_SYNDROME                     (0x00000134)
#define     NCP_CAAL_NCA_SYS_MEM_B_SYNDROME                     (0x00000138)
#define     NCP_CAAL_NCA_SYS_MEM_WECC                           (0x0000013c)
#define     NCP_CAAL_NCA_SYS_MEM_CRR_REQ_STATUS                 (0x00000140)
#define     NCP_CAAL_NCA_SYS_MEM_CWR_REQ_STATUS                 (0x00000144)
#define     NCP_CAAL_NCA_SYS_MEM_CWD_REQ_STATUS                 (0x00000148)
#define     NCP_CAAL_NCA_SYS_MEM_AR_CHANNEL_STATUS              (0x0000014c)
#define     NCP_CAAL_NCA_SYS_MEM_AW_CHANNEL_STATUS              (0x00000150)
#define     NCP_CAAL_NCA_SYS_MEM_W_CHANNEL_STATUS               (0x00000154)
#define     NCP_CAAL_NCA_SYS_MEM_R_CHANNEL_STATUS               (0x00000158)
#define     NCP_CAAL_NCA_SYS_MEM_B_CHANNEL_STATUS               (0x0000015c)
#define     NCP_CAAL_NCA_SYS_MEM_PARAMS0                        (0x00000160)
#define     NCP_CAAL_NCA_SYS_MEM_PARAMS1                        (0x00000164)
#define     NCP_CAAL_NCA_SYS_MEM_PARAMS2                        (0x00000168)
#define     NCP_CAAL_NCA_SYS_MEM_PARAMS3                        (0x0000016c)
#define     NCP_CAAL_NCA_SYS_MEM_PARAMS4                        (0x00000170)
#define     NCP_CAAL_NCA_SYS_MEM_PARAMS5                        (0x00000174)
#define     NCP_CAAL_NCA_SYS_MEM_PARAMS6                        (0x00000178)
#define     NCP_CAAL_NCA_SYS_MEM_RECC                           (0x0000017c)
#define     NCP_CAAL_NCA_SYS_MEM_CLA_TABLE_READ_PTR             (0x00000200)
#define     NCP_CAAL_NCA_SYS_MEM_CLA_TABLE_COUNT_HIGH_WM        (0x00000204)
#define     NCP_CAAL_NCA_SYS_MEM_ACELITE_READ_CONTROL_0         (0x00000240)
#define     NCP_CAAL_NCA_SYS_MEM_ACELITE_READ_CONTROL_1         (0x00000244)
#define     NCP_CAAL_NCA_SYS_MEM_ACELITE_READ_CONTROL_2         (0x00000248)
#define     NCP_CAAL_NCA_SYS_MEM_ACELITE_READ_CONTROL_3         (0x0000024c)
#define     NCP_CAAL_NCA_SYS_MEM_ACELITE_READ_CONTROL_4         (0x00000250)
#define     NCP_CAAL_NCA_SYS_MEM_ACELITE_READ_CONTROL_5         (0x00000254)
#define     NCP_CAAL_NCA_SYS_MEM_ACELITE_READ_CONTROL_6         (0x00000258)
#define     NCP_CAAL_NCA_SYS_MEM_ACELITE_READ_CONTROL_7         (0x0000025c)
#define     NCP_CAAL_NCA_SYS_MEM_ACELITE_READ_QOS_CONTROL_0     (0x0000026c)
#define     NCP_CAAL_NCA_SYS_MEM_ACELITE_READ_QOS_CONTROL_1     (0x00000270)
#define     NCP_CAAL_NCA_SYS_MEM_ACELITE_WRITE_CONTROL_0        (0x00000280)
#define     NCP_CAAL_NCA_SYS_MEM_ACELITE_WRITE_CONTROL_1        (0x00000284)
#define     NCP_CAAL_NCA_SYS_MEM_ACELITE_WRITE_CONTROL_2        (0x00000288)
#define     NCP_CAAL_NCA_SYS_MEM_ACELITE_WRITE_CONTROL_3        (0x0000028c)
#define     NCP_CAAL_NCA_SYS_MEM_ACELITE_WRITE_CONTROL_4        (0x00000290)
#define     NCP_CAAL_NCA_SYS_MEM_ACELITE_WRITE_CONTROL_5        (0x00000294)
#define     NCP_CAAL_NCA_SYS_MEM_ACELITE_WRITE_CONTROL_6        (0x00000298)
#define     NCP_CAAL_NCA_SYS_MEM_ACELITE_WRITE_CONTROL_7        (0x0000029c)
#define     NCP_CAAL_NCA_SYS_MEM_ACELITE_WRITE_QOS_CONTROL_0    (0x000002a4)
#define     NCP_CAAL_NCA_SYS_MEM_ACELITE_WRITE_QOS_CONTROL_1    (0x000002a8)
#define     NCP_CAAL_NCA_SYS_MEM_MAX_CLA_TABLE_COUNT            (0x00000300)
#define     NCP_CAAL_NCA_SYS_MEM_CLA_TABLE_COUNT                (0x00000304)
#define     NCP_CAAL_NCA_SYS_MEM_CLA_TABLE_HPTR                 (0x00000308)
#define     NCP_CAAL_NCA_SYS_MEM_CLA_TABLE_TPTR                 (0x0000030c)
#define     NCP_CAAL_NCA_SYS_MEM_CLA_TABLE_COUNT_FULL           (0x00000310)
#define     NCP_CAAL_NCA_SYS_MEM_CLA_TABLE_COUNT_EMPTY          (0x00000314)
#define     NCP_CAAL_NCA_SYS_MEM_CLA_TABLE_COUNT_OVERFLOW       (0x00000318)
#define     NCP_CAAL_NCA_SYS_MEM_CLA_TABLE_COUNT_UNDERFLOW      (0x0000031c)
#define     NCP_CAAL_NCA_SYS_MEM_READ_REQ_SENT_CNT              (0x00000380)
#define     NCP_CAAL_NCA_SYS_MEM_WRITE_REQ_SENT_CNT             (0x00000384)
#define     NCP_CAAL_NCA_SYS_MEM_ID_FREELIST_ERROR              (0x00000388)
#define     NCP_CAAL_NCA_SYS_MEM_LAT_INT_CTL                    (0x000003c0)
#define     NCP_CAAL_NCA_SYS_MEM_AVG_LAT_CNT                    (0x000003c4)
#define     NCP_CAAL_NCA_SYS_MEM_NU_CAAL_CFG_LOCK_CTRL          (0x000003fc)
#define     NCP_CAAL_NCA_SYS_MEM_INTERRUPT_STATUS               (0x00000010)
#define     NCP_CAAL_NCA_SYS_MEM_INTERRUPT_STATUS_ALARM_MASK    (0x1fbd3aff)
#define     NCP_CAAL_NCA_SYS_MEM_INTERRUPT_STATUS_SERVICE_MASK  (0x00424400)
#define     NCP_CAAL_NCA_SYS_MEM_INTERRUPT_EN                   (0x00000014)
#define     NCP_CAAL_NCA_SYS_MEM_INTERRUPT_EN_ALARM_MASK        (0x1fbd3aff)
#define     NCP_CAAL_NCA_SYS_MEM_INTERRUPT_EN_SERVICE_MASK      (0x00424400)
#define     NCP_CAAL_NCA_SYS_MEM_INTERRUPT_FRC                  (0x00000018)
#define     NCP_CAAL_NCA_SYS_MEM_INTERRUPT_FRC_ALARM_MASK       (0x1fbd3aff)
#define     NCP_CAAL_NCA_SYS_MEM_INTERRUPT_FRC_SERVICE_MASK     (0x00424400)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL0                   (0x00001000)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL0_ACCESS_SIZE       (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL1                   (0x00001010)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL1_ACCESS_SIZE       (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL2                   (0x00001020)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL2_ACCESS_SIZE       (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL3                   (0x00001030)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL3_ACCESS_SIZE       (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL4                   (0x00001040)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL4_ACCESS_SIZE       (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL5                   (0x00001050)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL5_ACCESS_SIZE       (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL6                   (0x00001060)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL6_ACCESS_SIZE       (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL7                   (0x00001070)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL7_ACCESS_SIZE       (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL8                   (0x00001080)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL8_ACCESS_SIZE       (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL9                   (0x00001090)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL9_ACCESS_SIZE       (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL10                  (0x000010a0)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL10_ACCESS_SIZE      (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL11                  (0x000010b0)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL11_ACCESS_SIZE      (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL12                  (0x000010c0)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL12_ACCESS_SIZE      (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL13                  (0x000010d0)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL13_ACCESS_SIZE      (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL14                  (0x000010e0)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL14_ACCESS_SIZE      (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL15                  (0x000010f0)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL15_ACCESS_SIZE      (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL16                  (0x00001100)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL16_ACCESS_SIZE      (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL17                  (0x00001110)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL17_ACCESS_SIZE      (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL18                  (0x00001120)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL18_ACCESS_SIZE      (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL19                  (0x00001130)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL19_ACCESS_SIZE      (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL20                  (0x00001140)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL20_ACCESS_SIZE      (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL21                  (0x00001150)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL21_ACCESS_SIZE      (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL22                  (0x00001160)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL22_ACCESS_SIZE      (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL23                  (0x00001170)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RF_POOL23_ACCESS_SIZE      (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL0               (0x00001200)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL0_ACCESS_SIZE   (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL1               (0x00001210)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL1_ACCESS_SIZE   (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL2               (0x00001220)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL2_ACCESS_SIZE   (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL3               (0x00001230)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL3_ACCESS_SIZE   (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL4               (0x00001240)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL4_ACCESS_SIZE   (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL5               (0x00001250)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL5_ACCESS_SIZE   (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL6               (0x00001260)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL6_ACCESS_SIZE   (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL7               (0x00001270)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL7_ACCESS_SIZE   (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL8               (0x00001280)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL8_ACCESS_SIZE   (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL9               (0x00001290)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL9_ACCESS_SIZE   (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL10              (0x000012a0)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL10_ACCESS_SIZE  (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL11              (0x000012b0)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL11_ACCESS_SIZE  (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL12              (0x000012c0)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL12_ACCESS_SIZE  (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL13              (0x000012d0)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL13_ACCESS_SIZE  (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL14              (0x000012e0)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL14_ACCESS_SIZE  (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL15              (0x000012f0)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL15_ACCESS_SIZE  (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL16              (0x00001300)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL16_ACCESS_SIZE  (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL17              (0x00001310)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL17_ACCESS_SIZE  (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL18              (0x00001320)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL18_ACCESS_SIZE  (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL19              (0x00001330)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL19_ACCESS_SIZE  (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL20              (0x00001340)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL20_ACCESS_SIZE  (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL21              (0x00001350)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL21_ACCESS_SIZE  (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL22              (0x00001360)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL22_ACCESS_SIZE  (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL23              (0x00001370)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_RAW_RF_POOL23_ACCESS_SIZE  (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_DEFAULT_RF_POOL_DEFAULT    (0x000013e0)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_DEFAULT_RF_POOL_DEFAULT_ACCESS_SIZE  (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_VAT_DEFAULT_RAW_RF_POOL_DEFAULT  (0x000013f0)
#define     NCP_CAAL_NCA_SYS_MEM_VAT_DEFAULT_RAW_RF_POOL_DEFAULT_ACCESS_SIZE  (0x00000010) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_CRR_MIN_ADDR                   (0x00000020)
#define     NCP_CAAL_NCA_SYS_MEM_CRR_MIN_ADDR_ACCESS_SIZE       (0x00000008) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_CRR_MAX_ADDR                   (0x00000028)
#define     NCP_CAAL_NCA_SYS_MEM_CRR_MAX_ADDR_ACCESS_SIZE       (0x00000008) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_CWR_MIN_ADDR                   (0x00000030)
#define     NCP_CAAL_NCA_SYS_MEM_CWR_MIN_ADDR_ACCESS_SIZE       (0x00000008) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_CWR_MAX_ADDR                   (0x00000038)
#define     NCP_CAAL_NCA_SYS_MEM_CWR_MAX_ADDR_ACCESS_SIZE       (0x00000008) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_CLK_COUNTER                    (0x000000d0)
#define     NCP_CAAL_NCA_SYS_MEM_CLK_COUNTER_ACCESS_SIZE        (0x00000008) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_COUNTER0                       (0x000000d8)
#define     NCP_CAAL_NCA_SYS_MEM_COUNTER0_ACCESS_SIZE           (0x00000008) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_COUNTER1                       (0x000000e0)
#define     NCP_CAAL_NCA_SYS_MEM_COUNTER1_ACCESS_SIZE           (0x00000008) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_COUNTER2                       (0x000000e8)
#define     NCP_CAAL_NCA_SYS_MEM_COUNTER2_ACCESS_SIZE           (0x00000008) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_COUNTER3                       (0x000000f0)
#define     NCP_CAAL_NCA_SYS_MEM_COUNTER3_ACCESS_SIZE           (0x00000008) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_ARID_STATUS                    (0x00000180)
#define     NCP_CAAL_NCA_SYS_MEM_ARID_STATUS_ACCESS_SIZE        (0x00000020) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_AWID_STATUS                    (0x000001a0)
#define     NCP_CAAL_NCA_SYS_MEM_AWID_STATUS_ACCESS_SIZE        (0x00000020) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_IJID_STATUS                    (0x000001c0)
#define     NCP_CAAL_NCA_SYS_MEM_IJID_STATUS_ACCESS_SIZE        (0x00000020) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_INVALIDATE_IJID_STATUS         (0x00000320)
#define     NCP_CAAL_NCA_SYS_MEM_INVALIDATE_IJID_STATUS_ACCESS_SIZE  (0x00000020) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_RID_TABLE_V                    (0x00000340)
#define     NCP_CAAL_NCA_SYS_MEM_RID_TABLE_V_ACCESS_SIZE        (0x00000020) /* Bytes */
#define     NCP_CAAL_NCA_SYS_MEM_BID_TABLE_V                    (0x00000360)
#define     NCP_CAAL_NCA_SYS_MEM_BID_TABLE_V_ACCESS_SIZE        (0x00000020) /* Bytes */
#ifdef __cplusplus
}
#endif

#endif /* _NCP_CAAL_NCA_SYS_MEM_REG_DEFINES_H_ */
