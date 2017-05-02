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


#ifndef _NCP_QPM_REG_DEFINES_H_
#define _NCP_QPM_REG_DEFINES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"


    /* NODE 0x101 , TARGET 0x1*/


#define     NCP_QPM_INIT_REG                                    (0x00000020)
#define     NCP_QPM_CONTROL_REG                                 (0x00000030)
#define     NCP_QPM_ERR_CNTL_ECC_REG                            (0x00000060)
#define     NCP_QPM_ERR_INJ_ECC_REG                             (0x00000068)
#define     NCP_QPM_ERR_CNTL_PARITY_REG                         (0x00000070)
#define     NCP_QPM_ERR_INJ_PARITY_REG                          (0x00000078)
#define     NCP_QPM_MAX_QADDR_REG                               (0x00000098)
#define     NCP_QPM_MAX_VAL_REG                                 (0x000000a0)
#define     NCP_QPM_CFG_RAM_CNTL_REG                            (0x000000b0)
#define     NCP_QPM_THRESH_INIT_VAL_LS_REG                      (0x000000c0)
#define     NCP_QPM_THRESH_INIT_VAL_MS_REG                      (0x000000c8)
#define     NCP_QPM_CFG_IA_ARB_MODE_REG                         (0x000000f0)

#define     NCP_QPM_QSTATUS_DELTA_REG_BASE                      (0x00000100)
#define     NCP_QPM_QSTATUS_DELTA_REG(n)                        (0x00000100 + (8*(n)))
#define     NCP_QPM_QSTATUS_DELTA_REG_COUNT                     (0x00000008)
#define     NCP_QPM_QSTATUS_DELTA_REG_IDX(addr) \
              (((addr) - NCP_QPM_QSTATUS_DELTA_REG_BASE) / 8)   
#define     NCP_QPM_QSTATUS_DELTA_REG_END                       (0x00000140)
#define     NCP_QPM_QSTATUS_DELTA_REG_RANGE(addr) \
           (((addr) >= NCP_QPM_QSTATUS_DELTA_REG_BASE) && \
            ((addr) < NCP_QPM_QSTATUS_DELTA_REG_END))

#define     NCP_QPM_QSTATUS_GLOBAL_DELTA_REG                    (0x00000140)
#define     NCP_QPM_FLCP_FIFO_FIFO_STAT                         (0x00000180)
#define     NCP_QPM_FLCP_FIFO_FIFO_WM                           (0x00000188)
#define     NCP_QPM_INTQFL_FIFO_FIFO_STAT                       (0x00000190)
#define     NCP_QPM_INTQFL_FIFO_FIFO_WM                         (0x00000198)
#define     NCP_QPM_AW_SMON00_QPM_SMON                          (0x00000200)
#define     NCP_QPM_AW_SMON01_QPM_SMON                          (0x00000208)
#define     NCP_QPM_AW_SMON02_QPM_SMON                          (0x00000210)
#define     NCP_QPM_AW_SMON03_QPM_SMON                          (0x00000218)
#define     NCP_QPM_AW_SMON04_QPM_SMON                          (0x00000220)
#define     NCP_QPM_AW_SMON05_QPM_SMON                          (0x00000228)
#define     NCP_QPM_AW_SMON06_QPM_SMON                          (0x00000230)
#define     NCP_QPM_AW_SMON07_QPM_SMON                          (0x00000238)
#define     NCP_QPM_QM_TOTPUSHED_REG                            (0x00000300)
#define     NCP_QPM_QM_TOTPOPPED_REG                            (0x00000308)
#define     NCP_QPM_QM_TOTQM_REG                                (0x00000310)
#define     NCP_QPM_QM_TOTDROPPED_REG                           (0x00000318)
#define     NCP_QPM_QM_TOTFREE_REG                              (0x00000320)
#define     NCP_QPM_FL_FREE_COUNT_REG                           (0x00000328)
#define     NCP_QPM_GLOBAL_LOCK_CTRL                            (0x000003f8)
#define     NCP_QPM_LLC_INTQ_STATUS_REG                         (0x00001000)
#define     NCP_QPM_LLC_INTQ_FL_STATUS_REG                      (0x00001008)
#define     NCP_QPM_FL_STATUS_REG                               (0x00001010)
#define     NCP_QPM_LLC_STATE_REG                               (0x00001018)
#define     NCP_QPM_LLC_INTQ_FL_COUNT_REG                       (0x00001020)
#define     NCP_QPM_DEBUG_RDATA_R                               (0x00001e00)
#define     NCP_QPM_DEBUG_WDATA_R                               (0x00001e08)
#define     NCP_QPM_ALARM_INT_STATUS                            (0x00000008)
#define     NCP_QPM_ALARM_INT_STATUS_ALARM_MASK                 (0x7846a060)
#define     NCP_QPM_ALARM_INT_STATUS_SERVICE_MASK               (0x87b95f9f)
#define     NCP_QPM_ALARM_INT_EN                                (0x00000010)
#define     NCP_QPM_ALARM_INT_EN_ALARM_MASK                     (0x7846a060)
#define     NCP_QPM_ALARM_INT_EN_SERVICE_MASK                   (0x87b95f9f)
#define     NCP_QPM_ALARM_INT_FRC                               (0x00000018)
#define     NCP_QPM_ALARM_INT_FRC_ALARM_MASK                    (0x7846a060)
#define     NCP_QPM_ALARM_INT_FRC_SERVICE_MASK                  (0x87b95f9f)
#define     NCP_QPM_SERVICE_INT_STATUS                          (0x00000040)
#define     NCP_QPM_SERVICE_INT_EN                              (0x00000048)
#define     NCP_QPM_SERVICE_INT_FRC                             (0x00000050)
#define     NCP_QPM_STICKY_SYNDROME_HW_ERR_REG                  (0x00000400)
#define     NCP_QPM_STICKY_SYNDROME_ICF_CNT_REG                 (0x00000408)
#define     NCP_QPM_STICKY_SYNDROME_ICF_TP_REG                  (0x00000410)
#define     NCP_QPM_STICKY_SYNDROME_ICF_HP_REG                  (0x00000418)
#define     NCP_QPM_STICKY_SYNDROME_INTQ_ERR_REG                (0x00000420)
#define     NCP_QPM_STICKY_SYNDROME_OF_COND_REG                 (0x00000428)
#define     NCP_QPM_STICKY_SYNDROME_UF_COND_REG                 (0x00000430)
#define     NCP_QPM_STICKY_SYNDROME_FL_UF_COND_REG              (0x00000438)
#define     NCP_QPM_STICKY_SYNDROME_SW_ERR_REG                  (0x00000440)
#define     NCP_QPM_STICKY_SYNDROME_MISCONFIG_REG               (0x00000448)
#define     NCP_QPM_STICKY_SYNDROME_EMPTY_COND_REG              (0x00000450)
#define     NCP_QPM_STICKY_SYNDROME_AEMPTY_COND_REG             (0x00000458)
#define     NCP_QPM_STICKY_SYNDROME_AFULL_COND_REG              (0x00000460)
#define     NCP_QPM_STICKY_SYNDROME_FULL_COND_REG               (0x00000468)
#define     NCP_QPM_STICKY_SYNDROME_PARITY_REG                  (0x00000470)
#define     NCP_QPM_STICKY_SYNDROME_ECC1_REG                    (0x00000478)
#define     NCP_QPM_STICKY_SYNDROME_ECC0_REG                    (0x00000480)
#define     NCP_QPM_STICKY_SYNDROME_CMEM_ERR_ADDR_REG           (0x00000488)
#define     NCP_QPM_STICKY_SYNDROME_UCMEM_ERR_ADDR_REG          (0x00000490)
#define     NCP_QPM_HW_PARAMS_0                                 (0x00000500)
#define     NCP_QPM_HW_PARAMS_1                                 (0x00000508)
#define     NCP_QPM_HW_PARAMS_2                                 (0x00000510)
#define     NCP_QPM_HW_PARAMS_3                                 (0x00000518)
#ifdef __cplusplus
}
#endif

#endif /* _NCP_QPM_REG_DEFINES_H_ */
