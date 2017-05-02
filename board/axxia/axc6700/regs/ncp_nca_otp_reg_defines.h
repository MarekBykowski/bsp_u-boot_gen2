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


#ifndef _NCP_NCA_OTP_REG_DEFINES_H_
#define _NCP_NCA_OTP_REG_DEFINES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"


    /* NODE 0x101 , TARGET 0xffffffff*/


#define     NCP_NCA_OTP_APB_BRIDGE_STATUS                       (0x00000000)
#define     NCP_NCA_OTP_INTERFACE_0000                          (0x00000004)
#define     NCP_NCA_OTP_INTERFACE_0020                          (0x00000008)
#define     NCP_NCA_OTP_INTERFACE_0040                          (0x0000000c)
#define     NCP_NCA_OTP_SYNDROME_CFG                            (0x00000070)
#define     NCP_NCA_OTP_SYNDROME_EVENT                          (0x00000074)
#define     NCP_NCA_OTP_SYNDROME_DATA00                         (0x00000078)
#define     NCP_NCA_OTP_SYNDROME_DATA01                         (0x0000007c)
#define     NCP_NCA_OTP_SYNDROME_DATA02                         (0x00000080)
#define     NCP_NCA_OTP_SYNDROME_DATA03                         (0x00000084)
#define     NCP_NCA_OTP_PARAMETER_00                            (0x00000090)
#define     NCP_NCA_OTP_PARAMETER_01                            (0x00000094)
#define     NCP_NCA_OTP_AW_SMON00_SMON                          (0x000000e0)
#define     NCP_NCA_OTP_AW_SMON01_SMON                          (0x000000e4)
#define     NCP_NCA_OTP_AW_SMON02_SMON                          (0x000000e8)
#define     NCP_NCA_OTP_AW_SMON03_SMON                          (0x000000ec)
#define     NCP_NCA_OTP_AW_SMON04_SMON                          (0x000000f0)
#define     NCP_NCA_OTP_AW_SMON05_SMON                          (0x000000f4)
#define     NCP_NCA_OTP_AW_SMON06_SMON                          (0x000000f8)
#define     NCP_NCA_OTP_AW_SMON07_SMON                          (0x000000fc)
#define     NCP_NCA_OTP_CONTROL_GENERAL_00                      (0x00000100)
#define     NCP_NCA_OTP_CONTROL_GENERAL_01                      (0x00000104)
#define     NCP_NCA_OTP_CONTROL_MEMINTF_00                      (0x00000108)
#define     NCP_NCA_OTP_CONTROL_MEMINTF_01                      (0x0000010c)
#define     NCP_NCA_OTP_CONTROL_MEMINTF_02                      (0x00000110)
#define     NCP_NCA_OTP_CONTROL_MEMINTF_03                      (0x00000114)
#define     NCP_NCA_OTP_CONTROL_GENERAL_04                      (0x00000118)
#define     NCP_NCA_OTP_CONTROL_GENERAL_05                      (0x0000011c)
#define     NCP_NCA_OTP_CONTROL_DESTIPCQ_00                     (0x00000120)
#define     NCP_NCA_OTP_CONTROL_DESTIPCQ_01                     (0x00000124)
#define     NCP_NCA_OTP_CONTROL_DESTIPCQ_02                     (0x00000128)
#define     NCP_NCA_OTP_CONTROL_DESTIPCQ_03                     (0x0000012c)
#define     NCP_NCA_OTP_CONTROL_DESTIPCQ_04                     (0x00000130)
#define     NCP_NCA_OTP_CONTROL_DESTIPCQ_05                     (0x00000134)
#define     NCP_NCA_OTP_CONTROL_DESTIPCQ_06                     (0x00000138)
#define     NCP_NCA_OTP_CONTROL_DESTIPCQ_07                     (0x0000013c)
#define     NCP_NCA_OTP_CONTROL_GENERAL_16                      (0x00000140)
#define     NCP_NCA_OTP_CONTROL_GENERAL_17                      (0x00000144)
#define     NCP_NCA_OTP_CREDIT_FIFO_STAT                        (0x00000700)
#define     NCP_NCA_OTP_CREDIT_FIFO_WM                          (0x00000704)
#define     NCP_NCA_OTP_MULTIRES_FIFO_STAT                      (0x00000708)
#define     NCP_NCA_OTP_MULTIRES_FIFO_WM                        (0x0000070c)
#define     NCP_NCA_OTP_ITP_FIFO_STAT                           (0x00000710)
#define     NCP_NCA_OTP_ITP_FIFO_WM                             (0x00000714)
#define     NCP_NCA_OTP_NOOP_FIFO_STAT                          (0x00000718)
#define     NCP_NCA_OTP_NOOP_FIFO_WM                            (0x0000071c)
#define     NCP_NCA_OTP_SNDTSK_FIFO_STAT                        (0x00000720)
#define     NCP_NCA_OTP_SNDTSK_FIFO_WM                          (0x00000724)
#define     NCP_NCA_OTP_SNDTSKRES_FIFO_STAT                     (0x00000728)
#define     NCP_NCA_OTP_SNDTSKRES_FIFO_WM                       (0x0000072c)
#define     NCP_NCA_OTP_CPCQ_FIFO_STAT                          (0x00000730)
#define     NCP_NCA_OTP_CPCQ_FIFO_WM                            (0x00000734)
#define     NCP_NCA_OTP_MTP_FIFO_STAT                           (0x00000738)
#define     NCP_NCA_OTP_MTP_FIFO_WM                             (0x0000073c)
#define     NCP_NCA_OTP_MTP_SNDTSKPRE_FIFO_STAT                 (0x00000740)
#define     NCP_NCA_OTP_MTP_SNDTSKPRE_FIFO_WM                   (0x00000744)
#define     NCP_NCA_OTP_MTP_SNDTSKPOST_FIFO_STAT                (0x00000748)
#define     NCP_NCA_OTP_MTP_SNDTSKPOST_FIFO_WM                  (0x0000074c)
#define     NCP_NCA_OTP_RSELRES_FIFO_STAT                       (0x00000750)
#define     NCP_NCA_OTP_RSELRES_FIFO_WM                         (0x00000754)
#define     NCP_NCA_OTP_MTP_ITP_FIFO_STAT                       (0x00000758)
#define     NCP_NCA_OTP_MTP_ITP_FIFO_WM                         (0x0000075c)
#define     NCP_NCA_OTP_STATUS_OLL_ISEL_STATUS                  (0x00000800)
#define     NCP_NCA_OTP_STATUS_OLL_RSEL_STATUS                  (0x00000804)
#define     NCP_NCA_OTP_STATUS_OLL_SNDTSK_STATUS                (0x00000808)
#define     NCP_NCA_OTP_STATUS_FIFO_OTP_CPU_OUT                 (0x0000080c)
#define     NCP_NCA_OTP_STATUS_FIFO_OTP_CPU_RD                  (0x00000810)
#define     NCP_NCA_OTP_STATUS_FIFO_OTP_CPU_RR                  (0x00000814)
#define     NCP_NCA_OTP_STATUS_FIFO_OTP_DATA_OUT                (0x00000818)
#define     NCP_NCA_OTP_STATUS_FIFO_OTP_DATA_RD                 (0x0000081c)
#define     NCP_NCA_OTP_STATUS_FIFO_OTP_DATA_RR                 (0x00000820)
#define     NCP_NCA_OTP_STATUS_STATE00                          (0x00000824)
#define     NCP_NCA_OTP_STATUS_STATE01                          (0x00000828)
#define     NCP_NCA_OTP_STATUS_STATE02                          (0x0000082c)
#define     NCP_NCA_OTP_STATUS_STATE03                          (0x00000830)
#define     NCP_NCA_OTP_STATUS_STATE04                          (0x00000834)
#define     NCP_NCA_OTP_STATUS_STATE10                          (0x0000085c)
#define     NCP_NCA_OTP_COUNTER_DROP                            (0x00000e00)
#define     NCP_NCA_OTP_COUNTER_NOOP                            (0x00000e04)
#define     NCP_NCA_OTP_COUNTER_SNDTSK                          (0x00000e08)
#define     NCP_NCA_OTP_COUNTER_CPCQ                            (0x00000e0c)
#define     NCP_NCA_OTP_COUNTER_ADPAH                           (0x00000e10)
#define     NCP_NCA_OTP_COUNTER_ADPAE                           (0x00000e14)
#define     NCP_NCA_OTP_COUNTER_COMPLETION                      (0x00000e18)
#define     NCP_NCA_OTP_COUNTER_COPY                            (0x00000e1c)
#define     NCP_NCA_OTP_COUNTER_FLOWCONTROL                     (0x00000e20)
#define     NCP_NCA_OTP_COUNTER_NLINK                           (0x00000e24)
#define     NCP_NCA_OTP_COUNTER_TDGL                            (0x00000e28)
#define     NCP_NCA_OTP_COUNTER_NCAV3_OPCQ_REQ_AWREADY          (0x00000e2c)
#define     NCP_NCA_OTP_COUNTER_NCAV3_OPCQ_RES_AWREADY          (0x00000e30)
#define     NCP_NCA_OTP_COUNTER_TDGL_ENG_BP                     (0x00000e34)
#define     NCP_NCA_OTP_COUNTER_CMN_CPCQ_REQ_AWREADY            (0x00000e38)
#define     NCP_NCA_OTP_COUNTER_CMN_CPCQ_RESP_AWREADY           (0x00000e3c)
#define     NCP_NCA_OTP_COUNTER_OTP_ITP_TX_AWREADY              (0x00000e40)
#define     NCP_NCA_OTP_COUNTER_OTP_MTP_REQ_AWREADY             (0x00000e44)
#define     NCP_NCA_OTP_COUNTER_MTP_OTP_RES_AWREADY             (0x00000e48)
#define     NCP_NCA_OTP_COUNTER_DMA_READ_CPU_RR_READY           (0x00000e4c)
#define     NCP_NCA_OTP_COUNTER_DMA_READ_DATA_RR_READY          (0x00000e50)
#define     NCP_NCA_OTP_COUNTER_MULTI_FIFO_FIFO_AFULL           (0x00000e54)
#define     NCP_NCA_OTP_COUNTER_OLL_ISEL_FULL                   (0x00000e58)
#define     NCP_NCA_OTP_COUNTER_OLL_RSEL_FULL                   (0x00000e5c)
#define     NCP_NCA_OTP_COUNTER_OLL_SNDTSK_FULL                 (0x00000e60)
#define     NCP_NCA_OTP_COUNTER_FIFOAFULL0                      (0x00000e64)
#define     NCP_NCA_OTP_COUNTER_FIFOAFULL1                      (0x00000e68)
#define     NCP_NCA_OTP_COUNTER_FIFOAFULL2                      (0x00000e6c)
#define     NCP_NCA_OTP_COUNTER_FIFOAFULL3                      (0x00000e70)
#define     NCP_NCA_OTP_COUNTER_FIFOAFULL4                      (0x00000e74)
#define     NCP_NCA_OTP_COUNTER_FIFOAFULL5                      (0x00000e78)
#define     NCP_NCA_OTP_COUNTER_FIFOAFULL6                      (0x00000e7c)
#define     NCP_NCA_OTP_COUNTER_FIFOAFULL7                      (0x00000e80)
#define     NCP_NCA_OTP_COUNTER_FIFOAFULL8                      (0x00000e84)
#define     NCP_NCA_OTP_COUNTER_FIFOAFULL9                      (0x00000e88)
#define     NCP_NCA_OTP_COUNTER_FIFOAFULL10                     (0x00000e8c)
#define     NCP_NCA_OTP_COUNTER_FIFOAFULL11                     (0x00000e90)
#define     NCP_NCA_OTP_COUNTER_POINTER_ENTRY                   (0x00000e94)
#define     NCP_NCA_OTP_COUNTER_POINTER_HEADER0                 (0x00000e98)
#define     NCP_NCA_OTP_COUNTER_POINTER_HEADER1                 (0x00000e9c)
#define     NCP_NCA_OTP_COUNTER_POINTER_ITP                     (0x00000ea0)
#define     NCP_NCA_OTP_COUNTER_POINTER_MTP_INC                 (0x00000ea4)
#define     NCP_NCA_OTP_COUNTER_POINTER_MTP_DEC                 (0x00000ea8)
#define     NCP_NCA_OTP_COUNTER_POINTER_TDGL                    (0x00000eac)
#define     NCP_NCA_OTP_COUNTER_POINTER_SNDTSK_RCCD1_PKTCOPY_MREFIS0  (0x00000eb0)
#define     NCP_NCA_OTP_COUNTER_CP                              (0x00000eb4)
#define     NCP_NCA_OTP_COUNTER_REFCNTI                         (0x00000eb8)
#define     NCP_NCA_OTP_COUNTER_REFCNTD                         (0x00000ebc)
#define     NCP_NCA_OTP_COUNTER_MQGI                            (0x00000ec0)
#define     NCP_NCA_OTP_COUNTER_MQGD                            (0x00000ec4)
#define     NCP_NCA_OTP_COUNTER_PTRCNT0                         (0x00000ec8)
#define     NCP_NCA_OTP_COR_COUNTER_DROP                        (0x00000f00)
#define     NCP_NCA_OTP_COR_COUNTER_NOOP                        (0x00000f04)
#define     NCP_NCA_OTP_COR_COUNTER_SNDTSK                      (0x00000f08)
#define     NCP_NCA_OTP_COR_COUNTER_CPCQ                        (0x00000f0c)
#define     NCP_NCA_OTP_COR_COUNTER_ADPAH                       (0x00000f10)
#define     NCP_NCA_OTP_COR_COUNTER_ADPAE                       (0x00000f14)
#define     NCP_NCA_OTP_COR_COUNTER_COMPLETION                  (0x00000f18)
#define     NCP_NCA_OTP_COR_COUNTER_COPY                        (0x00000f1c)
#define     NCP_NCA_OTP_COR_COUNTER_FLOWCONTROL                 (0x00000f20)
#define     NCP_NCA_OTP_COR_COUNTER_NLINK                       (0x00000f24)
#define     NCP_NCA_OTP_COR_COUNTER_TDGL                        (0x00000f28)
#define     NCP_NCA_OTP_COR_COUNTER_NCAV3_OPCQ_REQ_AWREADY      (0x00000f2c)
#define     NCP_NCA_OTP_COR_COUNTER_NCAV3_OPCQ_RES_AWREADY      (0x00000f30)
#define     NCP_NCA_OTP_COR_COUNTER_TDGL_ENG_BP                 (0x00000f34)
#define     NCP_NCA_OTP_COR_COUNTER_CMN_CPCQ_REQ_AWREADY        (0x00000f38)
#define     NCP_NCA_OTP_COR_COUNTER_CMN_CPCQ_RESP_AWREADY       (0x00000f3c)
#define     NCP_NCA_OTP_COR_COUNTER_OTP_ITP_TX_AWREADY          (0x00000f40)
#define     NCP_NCA_OTP_COR_COUNTER_OTP_MTP_REQ_AWREADY         (0x00000f44)
#define     NCP_NCA_OTP_COR_COUNTER_MTP_OTP_RES_AWREADY         (0x00000f48)
#define     NCP_NCA_OTP_COR_COUNTER_DMA_READ_CPU_RR_READY       (0x00000f4c)
#define     NCP_NCA_OTP_COR_COUNTER_DMA_READ_DATA_RR_READY      (0x00000f50)
#define     NCP_NCA_OTP_COR_COUNTER_MULTI_FIFO_FIFO_AFULL       (0x00000f54)
#define     NCP_NCA_OTP_COR_COUNTER_OLL_ISEL_FULL               (0x00000f58)
#define     NCP_NCA_OTP_COR_COUNTER_OLL_RSEL_FULL               (0x00000f5c)
#define     NCP_NCA_OTP_COR_COUNTER_OLL_SNDTSK_FULL             (0x00000f60)
#define     NCP_NCA_OTP_COR_COUNTER_FIFOAFULL0                  (0x00000f64)
#define     NCP_NCA_OTP_COR_COUNTER_FIFOAFULL1                  (0x00000f68)
#define     NCP_NCA_OTP_COR_COUNTER_FIFOAFULL2                  (0x00000f6c)
#define     NCP_NCA_OTP_COR_COUNTER_FIFOAFULL3                  (0x00000f70)
#define     NCP_NCA_OTP_COR_COUNTER_FIFOAFULL4                  (0x00000f74)
#define     NCP_NCA_OTP_COR_COUNTER_FIFOAFULL5                  (0x00000f78)
#define     NCP_NCA_OTP_COR_COUNTER_FIFOAFULL6                  (0x00000f7c)
#define     NCP_NCA_OTP_COR_COUNTER_FIFOAFULL7                  (0x00000f80)
#define     NCP_NCA_OTP_COR_COUNTER_FIFOAFULL8                  (0x00000f84)
#define     NCP_NCA_OTP_COR_COUNTER_FIFOAFULL9                  (0x00000f88)
#define     NCP_NCA_OTP_COR_COUNTER_FIFOAFULL10                 (0x00000f8c)
#define     NCP_NCA_OTP_COR_COUNTER_FIFOAFULL11                 (0x00000f90)
#define     NCP_NCA_OTP_COR_COUNTER_POINTER_ENTRY               (0x00000f94)
#define     NCP_NCA_OTP_COR_COUNTER_POINTER_HEADER0             (0x00000f98)
#define     NCP_NCA_OTP_COR_COUNTER_POINTER_HEADER1             (0x00000f9c)
#define     NCP_NCA_OTP_COR_COUNTER_POINTER_ITP                 (0x00000fa0)
#define     NCP_NCA_OTP_COR_COUNTER_POINTER_MTP_INC             (0x00000fa4)
#define     NCP_NCA_OTP_COR_COUNTER_POINTER_MTP_DEC             (0x00000fa8)
#define     NCP_NCA_OTP_COR_COUNTER_POINTER_TDGL                (0x00000fac)
#define     NCP_NCA_OTP_COR_COUNTER_POINTER_SNDTSK_RCCD1_PKTCOPY_MREFIS0  (0x00000fb0)
#define     NCP_NCA_OTP_COR_COUNTER_CP                          (0x00000fb4)
#define     NCP_NCA_OTP_COR_COUNTER_REFCNTI                     (0x00000fb8)
#define     NCP_NCA_OTP_COR_COUNTER_REFCNTD                     (0x00000fbc)
#define     NCP_NCA_OTP_COR_COUNTER_MQGI                        (0x00000fc0)
#define     NCP_NCA_OTP_COR_COUNTER_MQGD                        (0x00000fc4)
#define     NCP_NCA_OTP_COR_COUNTER_PTRCNT0                     (0x00000fc8)
#define     NCP_NCA_OTP_CFG_SETUP                               (0x00000ffc)

#define     NCP_NCA_OTP_MULTI_FIFO_STATE_RAM_0_BASE             (0x00002000)
#define     NCP_NCA_OTP_MULTI_FIFO_STATE_RAM_0(n)               (0x00002000 + (4*(n)))
#define     NCP_NCA_OTP_MULTI_FIFO_STATE_RAM_0_COUNT            (0x00000010)
#define     NCP_NCA_OTP_MULTI_FIFO_STATE_RAM_0_IDX(addr) \
     (((addr) - NCP_NCA_OTP_MULTI_FIFO_STATE_RAM_0_BASE) / 4)
#define     NCP_NCA_OTP_MULTI_FIFO_STATE_RAM_0_END              (0x00002040)
#define     NCP_NCA_OTP_MULTI_FIFO_STATE_RAM_0_RANGE(addr) \
  (((addr) >= NCP_NCA_OTP_MULTI_FIFO_STATE_RAM_0_BASE) && \
  ((addr) < NCP_NCA_OTP_MULTI_FIFO_STATE_RAM_0_END))


#define     NCP_NCA_OTP_ODTD_RAM_BASE                           (0x0000e800)
#define     NCP_NCA_OTP_ODTD_RAM(n)                             (0x0000e800 + (4*(n)))
#define     NCP_NCA_OTP_ODTD_RAM_COUNT                          (0x00000100)
#define     NCP_NCA_OTP_ODTD_RAM_IDX(addr) \
                   (((addr) - NCP_NCA_OTP_ODTD_RAM_BASE) / 4)        
#define     NCP_NCA_OTP_ODTD_RAM_END                            (0x0000ec00)
#define     NCP_NCA_OTP_ODTD_RAM_RANGE(addr) \
                (((addr) >= NCP_NCA_OTP_ODTD_RAM_BASE) && \
                      ((addr) < NCP_NCA_OTP_ODTD_RAM_END))


#define     NCP_NCA_OTP_LL_ISEL_STATE_RAM_BASE                  (0x0000f000)
#define     NCP_NCA_OTP_LL_ISEL_STATE_RAM(n)                    (0x0000f000 + (4*(n)))
#define     NCP_NCA_OTP_LL_ISEL_STATE_RAM_COUNT                 (0x00000100)
#define     NCP_NCA_OTP_LL_ISEL_STATE_RAM_IDX(addr) \
          (((addr) - NCP_NCA_OTP_LL_ISEL_STATE_RAM_BASE) / 4)
#define     NCP_NCA_OTP_LL_ISEL_STATE_RAM_END                   (0x0000f400)
#define     NCP_NCA_OTP_LL_ISEL_STATE_RAM_RANGE(addr) \
       (((addr) >= NCP_NCA_OTP_LL_ISEL_STATE_RAM_BASE) && \
       ((addr) < NCP_NCA_OTP_LL_ISEL_STATE_RAM_END))


#define     NCP_NCA_OTP_LL_ISEL_POINTER_RAM_BASE                (0x00010000)
#define     NCP_NCA_OTP_LL_ISEL_POINTER_RAM(n)                  (0x00010000 + (4*(n)))
#define     NCP_NCA_OTP_LL_ISEL_POINTER_RAM_COUNT               (0x00000010)
#define     NCP_NCA_OTP_LL_ISEL_POINTER_RAM_IDX(addr) \
        (((addr) - NCP_NCA_OTP_LL_ISEL_POINTER_RAM_BASE) / 4)
#define     NCP_NCA_OTP_LL_ISEL_POINTER_RAM_END                 (0x00010040)
#define     NCP_NCA_OTP_LL_ISEL_POINTER_RAM_RANGE(addr) \
     (((addr) >= NCP_NCA_OTP_LL_ISEL_POINTER_RAM_BASE) && \
     ((addr) < NCP_NCA_OTP_LL_ISEL_POINTER_RAM_END))


#define     NCP_NCA_OTP_LL_RSEL_STATE_RAM_BASE                  (0x00013000)
#define     NCP_NCA_OTP_LL_RSEL_STATE_RAM(n)                    (0x00013000 + (4*(n)))
#define     NCP_NCA_OTP_LL_RSEL_STATE_RAM_COUNT                 (0x00000080)
#define     NCP_NCA_OTP_LL_RSEL_STATE_RAM_IDX(addr) \
          (((addr) - NCP_NCA_OTP_LL_RSEL_STATE_RAM_BASE) / 4)
#define     NCP_NCA_OTP_LL_RSEL_STATE_RAM_END                   (0x00013200)
#define     NCP_NCA_OTP_LL_RSEL_STATE_RAM_RANGE(addr) \
       (((addr) >= NCP_NCA_OTP_LL_RSEL_STATE_RAM_BASE) && \
       ((addr) < NCP_NCA_OTP_LL_RSEL_STATE_RAM_END))


#define     NCP_NCA_OTP_LL_RSEL_POINTER_RAM_BASE                (0x00014000)
#define     NCP_NCA_OTP_LL_RSEL_POINTER_RAM(n)                  (0x00014000 + (4*(n)))
#define     NCP_NCA_OTP_LL_RSEL_POINTER_RAM_COUNT               (0x00000010)
#define     NCP_NCA_OTP_LL_RSEL_POINTER_RAM_IDX(addr) \
        (((addr) - NCP_NCA_OTP_LL_RSEL_POINTER_RAM_BASE) / 4)
#define     NCP_NCA_OTP_LL_RSEL_POINTER_RAM_END                 (0x00014040)
#define     NCP_NCA_OTP_LL_RSEL_POINTER_RAM_RANGE(addr) \
     (((addr) >= NCP_NCA_OTP_LL_RSEL_POINTER_RAM_BASE) && \
     ((addr) < NCP_NCA_OTP_LL_RSEL_POINTER_RAM_END))


#define     NCP_NCA_OTP_LL_SNDTSK_STATE_RAM_BASE                (0x00018000)
#define     NCP_NCA_OTP_LL_SNDTSK_STATE_RAM(n)                  (0x00018000 + (4*(n)))
#define     NCP_NCA_OTP_LL_SNDTSK_STATE_RAM_COUNT               (0x00000100)
#define     NCP_NCA_OTP_LL_SNDTSK_STATE_RAM_IDX(addr) \
        (((addr) - NCP_NCA_OTP_LL_SNDTSK_STATE_RAM_BASE) / 4)
#define     NCP_NCA_OTP_LL_SNDTSK_STATE_RAM_END                 (0x00018400)
#define     NCP_NCA_OTP_LL_SNDTSK_STATE_RAM_RANGE(addr) \
     (((addr) >= NCP_NCA_OTP_LL_SNDTSK_STATE_RAM_BASE) && \
     ((addr) < NCP_NCA_OTP_LL_SNDTSK_STATE_RAM_END))


#define     NCP_NCA_OTP_LL_SNDTSK_POINTER_RAM_BASE              (0x00019000)
#define     NCP_NCA_OTP_LL_SNDTSK_POINTER_RAM(n)                (0x00019000 + (4*(n)))
#define     NCP_NCA_OTP_LL_SNDTSK_POINTER_RAM_COUNT             (0x00000010)
#define     NCP_NCA_OTP_LL_SNDTSK_POINTER_RAM_IDX(addr) \
      (((addr) - NCP_NCA_OTP_LL_SNDTSK_POINTER_RAM_BASE) / 4)
#define     NCP_NCA_OTP_LL_SNDTSK_POINTER_RAM_END               (0x00019040)
#define     NCP_NCA_OTP_LL_SNDTSK_POINTER_RAM_RANGE(addr) \
   (((addr) >= NCP_NCA_OTP_LL_SNDTSK_POINTER_RAM_BASE) && \
   ((addr) < NCP_NCA_OTP_LL_SNDTSK_POINTER_RAM_END))

#define     NCP_NCA_OTP_INTERRUPT_STATUS0                       (0x00000010)
#define     NCP_NCA_OTP_INTERRUPT_STATUS0_ALARM_MASK            (0xfffff807)
#define     NCP_NCA_OTP_INTERRUPT_STATUS0_SERVICE_MASK          (0x000007f8)
#define     NCP_NCA_OTP_INTERRUPT_STATUS1                       (0x00000014)
#define     NCP_NCA_OTP_INTERRUPT_STATUS1_ALARM_MASK            (0xffffffff)
#define     NCP_NCA_OTP_INTERRUPT_STATUS2                       (0x00000018)
#define     NCP_NCA_OTP_INTERRUPT_STATUS2_ALARM_MASK            (0xff000000)
#define     NCP_NCA_OTP_INTERRUPT_STATUS2_SERVICE_MASK          (0x00ffffff)
#define     NCP_NCA_OTP_INTERRUPT_STATUS3                       (0x0000001c)
#define     NCP_NCA_OTP_INTERRUPT_STATUS3_ALARM_MASK            (0xffffffff)
#define     NCP_NCA_OTP_INTERRUPT_EN0                           (0x00000030)
#define     NCP_NCA_OTP_INTERRUPT_EN0_ALARM_MASK                (0xfffff807)
#define     NCP_NCA_OTP_INTERRUPT_EN0_SERVICE_MASK              (0x000007f8)
#define     NCP_NCA_OTP_INTERRUPT_EN1                           (0x00000034)
#define     NCP_NCA_OTP_INTERRUPT_EN1_ALARM_MASK                (0xffffffff)
#define     NCP_NCA_OTP_INTERRUPT_EN2                           (0x00000038)
#define     NCP_NCA_OTP_INTERRUPT_EN2_ALARM_MASK                (0xff000000)
#define     NCP_NCA_OTP_INTERRUPT_EN2_SERVICE_MASK              (0x00ffffff)
#define     NCP_NCA_OTP_INTERRUPT_EN3                           (0x0000003c)
#define     NCP_NCA_OTP_INTERRUPT_EN3_ALARM_MASK                (0xffffffff)
#define     NCP_NCA_OTP_INTERRUPT_FRC0                          (0x00000050)
#define     NCP_NCA_OTP_INTERRUPT_FRC0_ALARM_MASK               (0xfffff807)
#define     NCP_NCA_OTP_INTERRUPT_FRC0_SERVICE_MASK             (0x000007f8)
#define     NCP_NCA_OTP_INTERRUPT_FRC1                          (0x00000054)
#define     NCP_NCA_OTP_INTERRUPT_FRC1_ALARM_MASK               (0xffffffff)
#define     NCP_NCA_OTP_INTERRUPT_FRC2                          (0x00000058)
#define     NCP_NCA_OTP_INTERRUPT_FRC2_ALARM_MASK               (0xff000000)
#define     NCP_NCA_OTP_INTERRUPT_FRC2_SERVICE_MASK             (0x00ffffff)
#define     NCP_NCA_OTP_INTERRUPT_FRC3                          (0x0000005c)
#define     NCP_NCA_OTP_INTERRUPT_FRC3_ALARM_MASK               (0xffffffff)


#define     NCP_NCA_OTP_MULTI_FIFO_CFG_RAM_0_BASE               (0x00001000)
#define     NCP_NCA_OTP_MULTI_FIFO_CFG_RAM_0(n)                 (0x00001000 + (8*(n)))
#define     NCP_NCA_OTP_MULTI_FIFO_CFG_RAM_0_ACCESS_SIZE        (0x00000008) /* Bytes */
#define     NCP_NCA_OTP_MULTI_FIFO_CFG_RAM_0_COUNT              (0x00000010)
#define     NCP_NCA_OTP_MULTI_FIFO_CFG_RAM_0_IDX(addr) \
       (((addr) - NCP_NCA_OTP_MULTI_FIFO_CFG_RAM_0_BASE) / 8)
#define     NCP_NCA_OTP_MULTI_FIFO_CFG_RAM_0_END                (0x00001080)
#define     NCP_NCA_OTP_MULTI_FIFO_CFG_RAM_0_RANGE(addr) \
    (((addr) >= NCP_NCA_OTP_MULTI_FIFO_CFG_RAM_0_BASE) && \
    ((addr) < NCP_NCA_OTP_MULTI_FIFO_CFG_RAM_0_END))



#define     NCP_NCA_OTP_MULTI_FIFO_DATA_RAM_0_BASE              (0x00003000)
#define     NCP_NCA_OTP_MULTI_FIFO_DATA_RAM_0(n)                (0x00003000 + (32*(n)))
#define     NCP_NCA_OTP_MULTI_FIFO_DATA_RAM_0_ACCESS_SIZE       (0x00000020) /* Bytes */
#define     NCP_NCA_OTP_MULTI_FIFO_DATA_RAM_0_COUNT             (0x00000200)
#define     NCP_NCA_OTP_MULTI_FIFO_DATA_RAM_0_IDX(addr) \
      (((addr) - NCP_NCA_OTP_MULTI_FIFO_DATA_RAM_0_BASE) / 32)
#define     NCP_NCA_OTP_MULTI_FIFO_DATA_RAM_0_END               (0x00007000)
#define     NCP_NCA_OTP_MULTI_FIFO_DATA_RAM_0_RANGE(addr) \
   (((addr) >= NCP_NCA_OTP_MULTI_FIFO_DATA_RAM_0_BASE) && \
   ((addr) < NCP_NCA_OTP_MULTI_FIFO_DATA_RAM_0_END))



#define     NCP_NCA_OTP_ADDRCONVERT_ENTRY_POOLBASEINDEX_BASE    (0x0000b000)
#define     NCP_NCA_OTP_ADDRCONVERT_ENTRY_POOLBASEINDEX(n)      (0x0000b000 + (32*(n)))
#define     NCP_NCA_OTP_ADDRCONVERT_ENTRY_POOLBASEINDEX_ACCESS_SIZE  (0x00000020) /* Bytes */
#define     NCP_NCA_OTP_ADDRCONVERT_ENTRY_POOLBASEINDEX_COUNT   (0x00000018)
#define     NCP_NCA_OTP_ADDRCONVERT_ENTRY_POOLBASEINDEX_IDX(addr) \
  (((addr) - NCP_NCA_OTP_ADDRCONVERT_ENTRY_POOLBASEINDEX_BASE) / 32)
#define     NCP_NCA_OTP_ADDRCONVERT_ENTRY_POOLBASEINDEX_END     (0x0000b300)
#define     NCP_NCA_OTP_ADDRCONVERT_ENTRY_POOLBASEINDEX_RANGE(addr) \
 (((addr) >= NCP_NCA_OTP_ADDRCONVERT_ENTRY_POOLBASEINDEX_BASE) && \
  ((addr) < NCP_NCA_OTP_ADDRCONVERT_ENTRY_POOLBASEINDEX_END))



#define     NCP_NCA_OTP_ADDRCONVERT_ENTRY_VIRTUALBASE_BASE      (0x0000b600)
#define     NCP_NCA_OTP_ADDRCONVERT_ENTRY_VIRTUALBASE(n)        (0x0000b600 + (8*(n)))
#define     NCP_NCA_OTP_ADDRCONVERT_ENTRY_VIRTUALBASE_ACCESS_SIZE  (0x00000008) /* Bytes */
#define     NCP_NCA_OTP_ADDRCONVERT_ENTRY_VIRTUALBASE_COUNT     (0x00000080)
#define     NCP_NCA_OTP_ADDRCONVERT_ENTRY_VIRTUALBASE_IDX(addr) \
  (((addr) - NCP_NCA_OTP_ADDRCONVERT_ENTRY_VIRTUALBASE_BASE) / 8)
#define     NCP_NCA_OTP_ADDRCONVERT_ENTRY_VIRTUALBASE_END       (0x0000ba00)
#define     NCP_NCA_OTP_ADDRCONVERT_ENTRY_VIRTUALBASE_RANGE(addr) \
 (((addr) >= NCP_NCA_OTP_ADDRCONVERT_ENTRY_VIRTUALBASE_BASE) && \
  ((addr) < NCP_NCA_OTP_ADDRCONVERT_ENTRY_VIRTUALBASE_END))



#define     NCP_NCA_OTP_ADDRCONVERT_DATA0_POOLBASEINDEX_BASE    (0x0000bc00)
#define     NCP_NCA_OTP_ADDRCONVERT_DATA0_POOLBASEINDEX(n)      (0x0000bc00 + (32*(n)))
#define     NCP_NCA_OTP_ADDRCONVERT_DATA0_POOLBASEINDEX_ACCESS_SIZE  (0x00000020) /* Bytes */
#define     NCP_NCA_OTP_ADDRCONVERT_DATA0_POOLBASEINDEX_COUNT   (0x00000018)
#define     NCP_NCA_OTP_ADDRCONVERT_DATA0_POOLBASEINDEX_IDX(addr) \
  (((addr) - NCP_NCA_OTP_ADDRCONVERT_DATA0_POOLBASEINDEX_BASE) / 32)
#define     NCP_NCA_OTP_ADDRCONVERT_DATA0_POOLBASEINDEX_END     (0x0000bf00)
#define     NCP_NCA_OTP_ADDRCONVERT_DATA0_POOLBASEINDEX_RANGE(addr) \
 (((addr) >= NCP_NCA_OTP_ADDRCONVERT_DATA0_POOLBASEINDEX_BASE) && \
  ((addr) < NCP_NCA_OTP_ADDRCONVERT_DATA0_POOLBASEINDEX_END))



#define     NCP_NCA_OTP_ADDRCONVERT_DATA0_VIRTUALBASE_BASE      (0x0000c200)
#define     NCP_NCA_OTP_ADDRCONVERT_DATA0_VIRTUALBASE(n)        (0x0000c200 + (8*(n)))
#define     NCP_NCA_OTP_ADDRCONVERT_DATA0_VIRTUALBASE_ACCESS_SIZE  (0x00000008) /* Bytes */
#define     NCP_NCA_OTP_ADDRCONVERT_DATA0_VIRTUALBASE_COUNT     (0x00000080)
#define     NCP_NCA_OTP_ADDRCONVERT_DATA0_VIRTUALBASE_IDX(addr) \
  (((addr) - NCP_NCA_OTP_ADDRCONVERT_DATA0_VIRTUALBASE_BASE) / 8)
#define     NCP_NCA_OTP_ADDRCONVERT_DATA0_VIRTUALBASE_END       (0x0000c600)
#define     NCP_NCA_OTP_ADDRCONVERT_DATA0_VIRTUALBASE_RANGE(addr) \
 (((addr) >= NCP_NCA_OTP_ADDRCONVERT_DATA0_VIRTUALBASE_BASE) && \
  ((addr) < NCP_NCA_OTP_ADDRCONVERT_DATA0_VIRTUALBASE_END))



#define     NCP_NCA_OTP_ADDRCONVERT_DATA1_POOLBASEINDEX_BASE    (0x0000c800)
#define     NCP_NCA_OTP_ADDRCONVERT_DATA1_POOLBASEINDEX(n)      (0x0000c800 + (32*(n)))
#define     NCP_NCA_OTP_ADDRCONVERT_DATA1_POOLBASEINDEX_ACCESS_SIZE  (0x00000020) /* Bytes */
#define     NCP_NCA_OTP_ADDRCONVERT_DATA1_POOLBASEINDEX_COUNT   (0x00000018)
#define     NCP_NCA_OTP_ADDRCONVERT_DATA1_POOLBASEINDEX_IDX(addr) \
  (((addr) - NCP_NCA_OTP_ADDRCONVERT_DATA1_POOLBASEINDEX_BASE) / 32)
#define     NCP_NCA_OTP_ADDRCONVERT_DATA1_POOLBASEINDEX_END     (0x0000cb00)
#define     NCP_NCA_OTP_ADDRCONVERT_DATA1_POOLBASEINDEX_RANGE(addr) \
 (((addr) >= NCP_NCA_OTP_ADDRCONVERT_DATA1_POOLBASEINDEX_BASE) && \
  ((addr) < NCP_NCA_OTP_ADDRCONVERT_DATA1_POOLBASEINDEX_END))



#define     NCP_NCA_OTP_ADDRCONVERT_DATA1_VIRTUALBASE_BASE      (0x0000ce00)
#define     NCP_NCA_OTP_ADDRCONVERT_DATA1_VIRTUALBASE(n)        (0x0000ce00 + (8*(n)))
#define     NCP_NCA_OTP_ADDRCONVERT_DATA1_VIRTUALBASE_ACCESS_SIZE  (0x00000008) /* Bytes */
#define     NCP_NCA_OTP_ADDRCONVERT_DATA1_VIRTUALBASE_COUNT     (0x00000080)
#define     NCP_NCA_OTP_ADDRCONVERT_DATA1_VIRTUALBASE_IDX(addr) \
  (((addr) - NCP_NCA_OTP_ADDRCONVERT_DATA1_VIRTUALBASE_BASE) / 8)
#define     NCP_NCA_OTP_ADDRCONVERT_DATA1_VIRTUALBASE_END       (0x0000d200)
#define     NCP_NCA_OTP_ADDRCONVERT_DATA1_VIRTUALBASE_RANGE(addr) \
 (((addr) >= NCP_NCA_OTP_ADDRCONVERT_DATA1_VIRTUALBASE_BASE) && \
  ((addr) < NCP_NCA_OTP_ADDRCONVERT_DATA1_VIRTUALBASE_END))



#define     NCP_NCA_OTP_ODTS_RAM_BASE                           (0x0000e000)
#define     NCP_NCA_OTP_ODTS_RAM(n)                             (0x0000e000 + (8*(n)))
#define     NCP_NCA_OTP_ODTS_RAM_ACCESS_SIZE                    (0x00000008) /* Bytes */
#define     NCP_NCA_OTP_ODTS_RAM_COUNT                          (0x00000100)
#define     NCP_NCA_OTP_ODTS_RAM_IDX(addr) \
                   (((addr) - NCP_NCA_OTP_ODTS_RAM_BASE) / 8)        
#define     NCP_NCA_OTP_ODTS_RAM_END                            (0x0000e800)
#define     NCP_NCA_OTP_ODTS_RAM_RANGE(addr) \
                (((addr) >= NCP_NCA_OTP_ODTS_RAM_BASE) && \
                      ((addr) < NCP_NCA_OTP_ODTS_RAM_END))



#define     NCP_NCA_OTP_LL_ISEL_COMPLETE_RAM_BASE               (0x00011000)
#define     NCP_NCA_OTP_LL_ISEL_COMPLETE_RAM(n)                 (0x00011000 + (128*(n)))
#define     NCP_NCA_OTP_LL_ISEL_COMPLETE_RAM_ACCESS_SIZE        (0x00000080) /* Bytes */
#define     NCP_NCA_OTP_LL_ISEL_COMPLETE_RAM_COUNT              (0x00000010)
#define     NCP_NCA_OTP_LL_ISEL_COMPLETE_RAM_IDX(addr) \
       (((addr) - NCP_NCA_OTP_LL_ISEL_COMPLETE_RAM_BASE) / 128)
#define     NCP_NCA_OTP_LL_ISEL_COMPLETE_RAM_END                (0x00011800)
#define     NCP_NCA_OTP_LL_ISEL_COMPLETE_RAM_RANGE(addr) \
    (((addr) >= NCP_NCA_OTP_LL_ISEL_COMPLETE_RAM_BASE) && \
    ((addr) < NCP_NCA_OTP_LL_ISEL_COMPLETE_RAM_END))



#define     NCP_NCA_OTP_LL_ISEL_OALLOCATE_RAM_BASE              (0x00012000)
#define     NCP_NCA_OTP_LL_ISEL_OALLOCATE_RAM(n)                (0x00012000 + (32*(n)))
#define     NCP_NCA_OTP_LL_ISEL_OALLOCATE_RAM_ACCESS_SIZE       (0x00000020) /* Bytes */
#define     NCP_NCA_OTP_LL_ISEL_OALLOCATE_RAM_COUNT             (0x00000010)
#define     NCP_NCA_OTP_LL_ISEL_OALLOCATE_RAM_IDX(addr) \
      (((addr) - NCP_NCA_OTP_LL_ISEL_OALLOCATE_RAM_BASE) / 32)
#define     NCP_NCA_OTP_LL_ISEL_OALLOCATE_RAM_END               (0x00012200)
#define     NCP_NCA_OTP_LL_ISEL_OALLOCATE_RAM_RANGE(addr) \
   (((addr) >= NCP_NCA_OTP_LL_ISEL_OALLOCATE_RAM_BASE) && \
   ((addr) < NCP_NCA_OTP_LL_ISEL_OALLOCATE_RAM_END))



#define     NCP_NCA_OTP_LL_ISEL_AALLOCATE_RAM_BASE              (0x00012200)
#define     NCP_NCA_OTP_LL_ISEL_AALLOCATE_RAM(n)                (0x00012200 + (32*(n)))
#define     NCP_NCA_OTP_LL_ISEL_AALLOCATE_RAM_ACCESS_SIZE       (0x00000020) /* Bytes */
#define     NCP_NCA_OTP_LL_ISEL_AALLOCATE_RAM_COUNT             (0x00000010)
#define     NCP_NCA_OTP_LL_ISEL_AALLOCATE_RAM_IDX(addr) \
      (((addr) - NCP_NCA_OTP_LL_ISEL_AALLOCATE_RAM_BASE) / 32)
#define     NCP_NCA_OTP_LL_ISEL_AALLOCATE_RAM_END               (0x00012400)
#define     NCP_NCA_OTP_LL_ISEL_AALLOCATE_RAM_RANGE(addr) \
   (((addr) >= NCP_NCA_OTP_LL_ISEL_AALLOCATE_RAM_BASE) && \
   ((addr) < NCP_NCA_OTP_LL_ISEL_AALLOCATE_RAM_END))



#define     NCP_NCA_OTP_LL_RSEL_ALLOCATE_RAM_BASE               (0x00016000)
#define     NCP_NCA_OTP_LL_RSEL_ALLOCATE_RAM(n)                 (0x00016000 + (8*(n)))
#define     NCP_NCA_OTP_LL_RSEL_ALLOCATE_RAM_ACCESS_SIZE        (0x00000008) /* Bytes */
#define     NCP_NCA_OTP_LL_RSEL_ALLOCATE_RAM_COUNT              (0x00000010)
#define     NCP_NCA_OTP_LL_RSEL_ALLOCATE_RAM_IDX(addr) \
       (((addr) - NCP_NCA_OTP_LL_RSEL_ALLOCATE_RAM_BASE) / 8)
#define     NCP_NCA_OTP_LL_RSEL_ALLOCATE_RAM_END                (0x00016080)
#define     NCP_NCA_OTP_LL_RSEL_ALLOCATE_RAM_RANGE(addr) \
    (((addr) >= NCP_NCA_OTP_LL_RSEL_ALLOCATE_RAM_BASE) && \
    ((addr) < NCP_NCA_OTP_LL_RSEL_ALLOCATE_RAM_END))



#define     NCP_NCA_OTP_LL_SNDTSK_ALLOCATE_RAM_BASE             (0x0001b000)
#define     NCP_NCA_OTP_LL_SNDTSK_ALLOCATE_RAM(n)               (0x0001b000 + (128*(n)))
#define     NCP_NCA_OTP_LL_SNDTSK_ALLOCATE_RAM_ACCESS_SIZE      (0x00000080) /* Bytes */
#define     NCP_NCA_OTP_LL_SNDTSK_ALLOCATE_RAM_COUNT            (0x00000010)
#define     NCP_NCA_OTP_LL_SNDTSK_ALLOCATE_RAM_IDX(addr) \
     (((addr) - NCP_NCA_OTP_LL_SNDTSK_ALLOCATE_RAM_BASE) / 128)
#define     NCP_NCA_OTP_LL_SNDTSK_ALLOCATE_RAM_END              (0x0001b800)
#define     NCP_NCA_OTP_LL_SNDTSK_ALLOCATE_RAM_RANGE(addr) \
  (((addr) >= NCP_NCA_OTP_LL_SNDTSK_ALLOCATE_RAM_BASE) && \
  ((addr) < NCP_NCA_OTP_LL_SNDTSK_ALLOCATE_RAM_END))



#define     NCP_NCA_OTP_RAM_DMA_READ_CPU_ENGINE_BASE            (0x0001c000)
#define     NCP_NCA_OTP_RAM_DMA_READ_CPU_ENGINE(n)              (0x0001c000 + (8*(n)))
#define     NCP_NCA_OTP_RAM_DMA_READ_CPU_ENGINE_ACCESS_SIZE     (0x00000008) /* Bytes */
#define     NCP_NCA_OTP_RAM_DMA_READ_CPU_ENGINE_COUNT           (0x00000040)
#define     NCP_NCA_OTP_RAM_DMA_READ_CPU_ENGINE_IDX(addr) \
    (((addr) - NCP_NCA_OTP_RAM_DMA_READ_CPU_ENGINE_BASE) / 8)
#define     NCP_NCA_OTP_RAM_DMA_READ_CPU_ENGINE_END             (0x0001c200)
#define     NCP_NCA_OTP_RAM_DMA_READ_CPU_ENGINE_RANGE(addr) \
 (((addr) >= NCP_NCA_OTP_RAM_DMA_READ_CPU_ENGINE_BASE) && \
  ((addr) < NCP_NCA_OTP_RAM_DMA_READ_CPU_ENGINE_END))

#ifdef __cplusplus
}
#endif

#endif /* _NCP_NCA_OTP_REG_DEFINES_H_ */
