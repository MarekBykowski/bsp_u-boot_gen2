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


#ifndef _NCP_NCA_ITP_REG_DEFINES_H_
#define _NCP_NCA_ITP_REG_DEFINES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"


    /* NODE 0x101 , TARGET 0xffffffff*/


#define     NCP_NCA_ITP_APB_BRIDGE_STATUS                       (0x00000000)
#define     NCP_NCA_ITP_INTERFACE_0000                          (0x00000004)
#define     NCP_NCA_ITP_INTERFACE_0020                          (0x00000008)
#define     NCP_NCA_ITP_INTERFACE_0040                          (0x0000000c)
#define     NCP_NCA_ITP_SYNDROME_CFG                            (0x00000070)
#define     NCP_NCA_ITP_SYNDROME_EVENT                          (0x00000074)
#define     NCP_NCA_ITP_SYNDROME_DATA00                         (0x00000078)
#define     NCP_NCA_ITP_SYNDROME_DATA01                         (0x0000007c)
#define     NCP_NCA_ITP_SYNDROME_DATA02                         (0x00000080)
#define     NCP_NCA_ITP_SYNDROME_DATA03                         (0x00000084)
#define     NCP_NCA_ITP_PARAMETER_SIZE_ITP_COMPLETION_LL        (0x00000090)
#define     NCP_NCA_ITP_PARAMETER_SIZE_ITP_ORDERED_BCAM         (0x00000094)
#define     NCP_NCA_ITP_PARAMETER_SIZE_ITP_ORDERED_LL           (0x00000098)
#define     NCP_NCA_ITP_PARAMETER_SIZE_ITP_UNORDERED_LL         (0x0000009c)
#define     NCP_NCA_ITP_PARAMETER_SIZE_ITP_UNSCHED_LL           (0x000000a0)
#define     NCP_NCA_ITP_PARAMETER_SIZE_ITP_COPY_LL              (0x000000a4)
#define     NCP_NCA_ITP_PARAMETER_SIZE_ITP_PREPROC_LL           (0x000000a8)
#define     NCP_NCA_ITP_PARAMETER_NUM_GIDPRI                    (0x000000ac)
#define     NCP_NCA_ITP_PARAMETER_NUM_TQPRI                     (0x000000b0)
#define     NCP_NCA_ITP_PARAMETER_NUM_GIDPERIPCQ                (0x000000b4)
#define     NCP_NCA_ITP_PARAMETER_NUM_GID                       (0x000000b8)
#define     NCP_NCA_ITP_PARAMETER_NUM_TQ                        (0x000000bc)
#define     NCP_NCA_ITP_AW_SMON00_SMON2                         (0x000000c0)
#define     NCP_NCA_ITP_AW_SMON01_SMON2                         (0x000000c4)
#define     NCP_NCA_ITP_AW_SMON02_SMON2                         (0x000000c8)
#define     NCP_NCA_ITP_AW_SMON03_SMON2                         (0x000000cc)
#define     NCP_NCA_ITP_AW_SMON04_SMON2                         (0x000000d0)
#define     NCP_NCA_ITP_AW_SMON05_SMON2                         (0x000000d4)
#define     NCP_NCA_ITP_AW_SMON06_SMON2                         (0x000000d8)
#define     NCP_NCA_ITP_AW_SMON07_SMON2                         (0x000000dc)
#define     NCP_NCA_ITP_AW_SMON00_SMON                          (0x000000e0)
#define     NCP_NCA_ITP_AW_SMON01_SMON                          (0x000000e4)
#define     NCP_NCA_ITP_AW_SMON02_SMON                          (0x000000e8)
#define     NCP_NCA_ITP_AW_SMON03_SMON                          (0x000000ec)
#define     NCP_NCA_ITP_AW_SMON04_SMON                          (0x000000f0)
#define     NCP_NCA_ITP_AW_SMON05_SMON                          (0x000000f4)
#define     NCP_NCA_ITP_AW_SMON06_SMON                          (0x000000f8)
#define     NCP_NCA_ITP_AW_SMON07_SMON                          (0x000000fc)
#define     NCP_NCA_ITP_CONTROL_GENERAL_00                      (0x00000100)
#define     NCP_NCA_ITP_CONTROL_GENERAL_01                      (0x00000104)
#define     NCP_NCA_ITP_CONTROL_GENERAL_02                      (0x00000108)
#define     NCP_NCA_ITP_CONTROL_GENERAL_03                      (0x0000010c)
#define     NCP_NCA_ITP_CONTROL_GENERAL_04                      (0x00000110)
#define     NCP_NCA_ITP_CONTROL_MEMINTF_00                      (0x00000114)
#define     NCP_NCA_ITP_CONTROL_MEMINTF_01                      (0x00000118)
#define     NCP_NCA_ITP_CONTROL_MEMINTF_02                      (0x0000011c)
#define     NCP_NCA_ITP_CONTROL_GENERAL_08                      (0x00000120)
#define     NCP_NCA_ITP_CONTROL_GENERAL_09                      (0x00000124)
#define     NCP_NCA_ITP_CONTROL_GENERAL_10                      (0x00000128)
#define     NCP_NCA_ITP_CONTROL_GENERAL_11                      (0x0000012c)
#define     NCP_NCA_ITP_CONTROL_GENERAL_12                      (0x00000130)
#define     NCP_NCA_ITP_CONTROL_GENERAL_13                      (0x00000134)
#define     NCP_NCA_ITP_CONTROL_GENERAL_QOS_01                  (0x00000138)
#define     NCP_NCA_ITP_CONTROL_GENERAL_QOS_02                  (0x0000013c)
#define     NCP_NCA_ITP_MAXBCAM_AFULL_BP_00                     (0x00000140)
#define     NCP_NCA_ITP_MAXBCAM_AFULL_BP_01                     (0x00000144)
#define     NCP_NCA_ITP_MAXBCAM_AFULL_BP_02                     (0x00000148)
#define     NCP_NCA_ITP_MAXBCAM_AFULL_BP_03                     (0x0000014c)
#define     NCP_NCA_ITP_MAXBCAM_AFULL_BP_04                     (0x00000150)
#define     NCP_NCA_ITP_MAXBCAM_AFULL_BP_05                     (0x00000154)
#define     NCP_NCA_ITP_MAXBCAM_AFULL_BP_06                     (0x00000158)
#define     NCP_NCA_ITP_CONTROL_GENERAL_23                      (0x0000015c)
#define     NCP_NCA_ITP_MAXBCAM_FULL_BP_00                      (0x00000160)
#define     NCP_NCA_ITP_MAXBCAM_FULL_BP_01                      (0x00000164)
#define     NCP_NCA_ITP_MAXBCAM_FULL_BP_02                      (0x00000168)
#define     NCP_NCA_ITP_MAXBCAM_FULL_BP_03                      (0x0000016c)
#define     NCP_NCA_ITP_MAXBCAM_FULL_BP_04                      (0x00000170)
#define     NCP_NCA_ITP_MAXBCAM_FULL_BP_05                      (0x00000174)
#define     NCP_NCA_ITP_MAXBCAM_FULL_BP_06                      (0x00000178)
#define     NCP_NCA_ITP_CONTROL_GENERAL_31                      (0x0000017c)
#define     NCP_NCA_ITP_MAXIEORD_FULL_BP_00                     (0x00000180)
#define     NCP_NCA_ITP_MAXIEORD_FULL_BP_01                     (0x00000184)
#define     NCP_NCA_ITP_MAXIEORD_FULL_BP_02                     (0x00000188)
#define     NCP_NCA_ITP_MAXIEORD_FULL_BP_03                     (0x0000018c)
#define     NCP_NCA_ITP_MAXIEORD_FULL_BP_04                     (0x00000190)
#define     NCP_NCA_ITP_MAXIEORD_FULL_BP_05                     (0x00000194)
#define     NCP_NCA_ITP_MAXIEORD_FULL_BP_06                     (0x00000198)
#define     NCP_NCA_ITP_CONTROL_GENERAL_40                      (0x0000019c)
#define     NCP_NCA_ITP_MAXIEUNORD_FULL_BP_00                   (0x000001a0)
#define     NCP_NCA_ITP_MAXIEUNORD_FULL_BP_01                   (0x000001a4)
#define     NCP_NCA_ITP_MAXIEUNORD_FULL_BP_02                   (0x000001a8)
#define     NCP_NCA_ITP_MAXIEUNORD_FULL_BP_03                   (0x000001ac)
#define     NCP_NCA_ITP_MAXIEUNORD_FULL_BP_04                   (0x000001b0)
#define     NCP_NCA_ITP_MAXIEUNORD_FULL_BP_05                   (0x000001b4)
#define     NCP_NCA_ITP_MAXIEUNORD_FULL_BP_06                   (0x000001b8)
#define     NCP_NCA_ITP_CONTROL_GENERAL_47                      (0x000001bc)
#define     NCP_NCA_ITP_CONTROL_GENERAL_48                      (0x000001c0)
#define     NCP_NCA_ITP_CONTROL_GENERAL_49                      (0x000001c4)
#define     NCP_NCA_ITP_CONTROL_GENERAL_50                      (0x000001c8)
#define     NCP_NCA_ITP_CONTROL_GENERAL_51                      (0x000001cc)
#define     NCP_NCA_ITP_INPUT_FIFO_STAT                         (0x00000700)
#define     NCP_NCA_ITP_INPUT_FIFO_WM                           (0x00000704)
#define     NCP_NCA_ITP_ENQUEUE_FIFO_STAT                       (0x00000708)
#define     NCP_NCA_ITP_ENQUEUE_FIFO_WM                         (0x0000070c)
#define     NCP_NCA_ITP_WRITEACK_FIFO_STAT                      (0x00000710)
#define     NCP_NCA_ITP_WRITEACK_FIFO_WM                        (0x00000714)
#define     NCP_NCA_ITP_OUTPUT_FIFO_STAT                        (0x00000718)
#define     NCP_NCA_ITP_OUTPUT_FIFO_WM                          (0x0000071c)
#define     NCP_NCA_ITP_IEUNORDRAM_FIFO_STAT                    (0x00000720)
#define     NCP_NCA_ITP_IEUNORDRAM_FIFO_WM                      (0x00000724)
#define     NCP_NCA_ITP_IEORDRAM_FIFO_STAT                      (0x00000728)
#define     NCP_NCA_ITP_IEORDRAM_FIFO_WM                        (0x0000072c)
#define     NCP_NCA_ITP_INPUT_COPY_FIFO_STAT                    (0x00000730)
#define     NCP_NCA_ITP_INPUT_COPY_FIFO_WM                      (0x00000734)
#define     NCP_NCA_ITP_COMPLETION_FIFO_STAT                    (0x00000738)
#define     NCP_NCA_ITP_COMPLETION_FIFO_WM                      (0x0000073c)
#define     NCP_NCA_ITP_PTRS_FIFO_STAT                          (0x00000740)
#define     NCP_NCA_ITP_PTRS_FIFO_WM                            (0x00000744)
#define     NCP_NCA_ITP_IEUNORDLL_FIFO_STAT                     (0x00000748)
#define     NCP_NCA_ITP_IEUNORDLL_FIFO_WM                       (0x0000074c)
#define     NCP_NCA_ITP_IEORDLL_FIFO_STAT                       (0x00000750)
#define     NCP_NCA_ITP_IEORDLL_FIFO_WM                         (0x00000754)
#define     NCP_NCA_ITP_SCHEDULE0_PARM_FIFO_STAT                (0x00000758)
#define     NCP_NCA_ITP_SCHEDULE0_PARM_FIFO_WM                  (0x0000075c)
#define     NCP_NCA_ITP_SCHEDULE0_LL_FIFO_STAT                  (0x00000760)
#define     NCP_NCA_ITP_SCHEDULE0_LL_FIFO_WM                    (0x00000764)
#define     NCP_NCA_ITP_INPUT_CPUHEADER_FIFO_STAT               (0x00000768)
#define     NCP_NCA_ITP_INPUT_CPUHEADER_FIFO_WM                 (0x0000076c)
#define     NCP_NCA_ITP_INPUTPTR_COPY_FIFO_STAT                 (0x00000770)
#define     NCP_NCA_ITP_INPUTPTR_COPY_FIFO_WM                   (0x00000774)
#define     NCP_NCA_ITP_DMA_FIFO_STAT                           (0x00000778)
#define     NCP_NCA_ITP_DMA_FIFO_WM                             (0x0000077c)
#define     NCP_NCA_ITP_INPUTPTR_CPUHEADER_FIFO_STAT            (0x00000780)
#define     NCP_NCA_ITP_INPUTPTR_CPUHEADER_FIFO_WM              (0x00000784)
#define     NCP_NCA_ITP_TCRI_FIFO_STAT                          (0x00000788)
#define     NCP_NCA_ITP_TCRI_FIFO_WM                            (0x0000078c)
#define     NCP_NCA_ITP_WRITEACK1_FIFO_STAT                     (0x00000790)
#define     NCP_NCA_ITP_WRITEACK1_FIFO_WM                       (0x00000794)
#define     NCP_NCA_ITP_DEALLOC_FIFO_STAT                       (0x00000798)
#define     NCP_NCA_ITP_DEALLOC_FIFO_WM                         (0x0000079c)
#define     NCP_NCA_ITP_MTP_REQ_HS_FIFO_STAT                    (0x000007a0)
#define     NCP_NCA_ITP_MTP_REQ_HS_FIFO_WM                      (0x000007a4)
#define     NCP_NCA_ITP_MTP_REQ_COPY_FIFO_STAT                  (0x000007a8)
#define     NCP_NCA_ITP_MTP_REQ_COPY_FIFO_WM                    (0x000007ac)
#define     NCP_NCA_ITP_MTP_RESP_HS_FIFO_STAT                   (0x000007b0)
#define     NCP_NCA_ITP_MTP_RESP_HS_FIFO_WM                     (0x000007b4)
#define     NCP_NCA_ITP_MTP_RESP_COPY_FIFO_STAT                 (0x000007b8)
#define     NCP_NCA_ITP_MTP_RESP_COPY_FIFO_WM                   (0x000007bc)
#define     NCP_NCA_ITP_ICOMPLETION_FIFO_STAT                   (0x000007c0)
#define     NCP_NCA_ITP_ICOMPLETION_FIFO_WM                     (0x000007c4)
#define     NCP_NCA_ITP_STATUS_LL_PREPROC_STATUS                (0x00000800)
#define     NCP_NCA_ITP_STATUS_LL_IEUNORD_STATUS                (0x00000804)
#define     NCP_NCA_ITP_STATUS_LL_IEORD_STATUS                  (0x00000808)
#define     NCP_NCA_ITP_STATUS_LL_IEORDREADY_STATUS             (0x0000080c)
#define     NCP_NCA_ITP_STATUS_LL_IEORDSCHED_STATUS             (0x00000810)
#define     NCP_NCA_ITP_STATUS_LL_COMPLETION_STATUS             (0x00000814)
#define     NCP_NCA_ITP_STATUS_CAM_IEORDERED                    (0x00000818)
#define     NCP_NCA_ITP_STATUS_FIFO_ITP_SYSTEM_IN0              (0x0000081c)
#define     NCP_NCA_ITP_STATUS_FIFO_ITP_SYSTEM_OUT0             (0x00000820)
#define     NCP_NCA_ITP_STATUS_FIFO_ITP_SYSTEM_IN1              (0x00000824)
#define     NCP_NCA_ITP_STATUS_FIFO_ITP_SYSTEM_OUT1             (0x00000828)
#define     NCP_NCA_ITP_STATUS_FIFO_ITP_SYSTEM_IN2              (0x0000082c)
#define     NCP_NCA_ITP_STATUS_FIFO_ITP_SYSTEM_OUT2             (0x00000830)
#define     NCP_NCA_ITP_STATUS_STATE00                          (0x00000834)
#define     NCP_NCA_ITP_STATUS_STATE01                          (0x00000838)
#define     NCP_NCA_ITP_STATUS_STATE02                          (0x0000083c)
#define     NCP_NCA_ITP_STATUS_STATE03                          (0x00000840)
#define     NCP_NCA_ITP_STATUS_STATE04                          (0x00000844)
#define     NCP_NCA_ITP_STATUS_STATE05                          (0x00000848)
#define     NCP_NCA_ITP_STATUS_STATE06                          (0x0000084c)
#define     NCP_NCA_ITP_STATUS_STATE07                          (0x00000850)
#define     NCP_NCA_ITP_STATUS_STATE08                          (0x00000854)
#define     NCP_NCA_ITP_STATUS_STATE09                          (0x00000858)
#define     NCP_NCA_ITP_STATUS_STATE10                          (0x0000085c)
#define     NCP_NCA_ITP_STATUS_TQBP0                            (0x00000860)
#define     NCP_NCA_ITP_STATUS_TQBP1                            (0x00000864)
#define     NCP_NCA_ITP_STATUS_TQBP2                            (0x00000868)
#define     NCP_NCA_ITP_STATUS_TQBP3                            (0x0000086c)
#define     NCP_NCA_ITP_STATUS_TQBP4                            (0x00000870)
#define     NCP_NCA_ITP_STATUS_TQBP5                            (0x00000874)
#define     NCP_NCA_ITP_STATUS_TQBP6                            (0x00000878)
#define     NCP_NCA_ITP_STATUS_TQSEQUENCE                       (0x0000087c)
#define     NCP_NCA_ITP_IPCQ_SIZE00                             (0x00000880)
#define     NCP_NCA_ITP_IPCQ_SIZE01                             (0x00000884)
#define     NCP_NCA_ITP_IPCQ_SIZE02                             (0x00000888)
#define     NCP_NCA_ITP_IPCQ_SIZE03                             (0x0000088c)
#define     NCP_NCA_ITP_IPCQ_SIZE04                             (0x00000890)
#define     NCP_NCA_ITP_IPCQ_SIZE05                             (0x00000894)
#define     NCP_NCA_ITP_IPCQ_SIZE06                             (0x00000898)
#define     NCP_NCA_ITP_IPCQ_SIZE07                             (0x0000089c)
#define     NCP_NCA_ITP_IPCQ_SIZE08                             (0x000008a0)
#define     NCP_NCA_ITP_IPCQ_SIZE09                             (0x000008a4)
#define     NCP_NCA_ITP_IPCQ_SIZE10                             (0x000008a8)
#define     NCP_NCA_ITP_IPCQ_SIZE11                             (0x000008ac)
#define     NCP_NCA_ITP_IPCQ_SIZE12                             (0x000008b0)
#define     NCP_NCA_ITP_IPCQ_SIZE13                             (0x000008b4)
#define     NCP_NCA_ITP_IPCQ_SIZE14                             (0x000008b8)
#define     NCP_NCA_ITP_IPCQ_SIZE15                             (0x000008bc)
#define     NCP_NCA_ITP_IPCQ_SIZE16                             (0x000008c0)
#define     NCP_NCA_ITP_IPCQ_SIZE17                             (0x000008c4)
#define     NCP_NCA_ITP_IPCQ_SIZE18                             (0x000008c8)
#define     NCP_NCA_ITP_IPCQ_SIZE19                             (0x000008cc)
#define     NCP_NCA_ITP_IPCQ_SIZE20                             (0x000008d0)
#define     NCP_NCA_ITP_IPCQ_SIZE21                             (0x000008d4)
#define     NCP_NCA_ITP_IPCQ_WORKING00                          (0x000008d8)
#define     NCP_NCA_ITP_COUNTER_COUNTER_COPY_HEADER             (0x00000e00)
#define     NCP_NCA_ITP_COUNTER_COUNTER_COPY_B32A               (0x00000e04)
#define     NCP_NCA_ITP_COUNTER_COUNTER_COPY_FORMAT1            (0x00000e08)
#define     NCP_NCA_ITP_COUNTER_COUNTER_COPY_FORMAT2            (0x00000e0c)
#define     NCP_NCA_ITP_COUNTER_COUNTER_COPY_FORMAT3            (0x00000e10)
#define     NCP_NCA_ITP_COUNTER_COUNTER_COPY_FORMAT4            (0x00000e14)
#define     NCP_NCA_ITP_COUNTER_COUNTER_STARTTASK_DROP          (0x00000e18)
#define     NCP_NCA_ITP_COUNTER_COUNTER_COPY_FORMAT5            (0x00000e1c)
#define     NCP_NCA_ITP_COUNTER_COUNTER_TILBP                   (0x00000e20)
#define     NCP_NCA_ITP_COUNTER_COUNTER_TCRIBP                  (0x00000e24)
#define     NCP_NCA_ITP_COUNTER_COUNTER_INPUTFIFO_AFULL         (0x00000e28)
#define     NCP_NCA_ITP_COUNTER_COUNTER_CAM_IEORDERED_AVAL_V    (0x00000e2c)
#define     NCP_NCA_ITP_COUNTER_COUNTER_LL_IEORD_FULL           (0x00000e30)
#define     NCP_NCA_ITP_COUNTER_COUNTER_LL_IEUNORD_FULL         (0x00000e34)
#define     NCP_NCA_ITP_COUNTER_COUNTER_LL_PREPROC_FULL         (0x00000e38)
#define     NCP_NCA_ITP_COUNTER_COUNTER_LL_COMPLETION_FULL      (0x00000e3c)
#define     NCP_NCA_ITP_COUNTER_COUNTER_TQBP                    (0x00000e40)
#define     NCP_NCA_ITP_COUNTER_COUNTER_IPCQFULL                (0x00000e44)
#define     NCP_NCA_ITP_COUNTER_COUNTER_MULTIFULL               (0x00000e48)
#define     NCP_NCA_ITP_COUNTER_COUNTER_NLINKREADY              (0x00000e4c)
#define     NCP_NCA_ITP_COUNTER_COUNTER_CREDITS                 (0x00000e50)
#define     NCP_NCA_ITP_COUNTER_COUNTER_ITP_OTP_DEALLOC_BP      (0x00000e54)
#define     NCP_NCA_ITP_COUNTER_COUNTER_MMBR_ENG_BP             (0x00000e58)
#define     NCP_NCA_ITP_COUNTER_COUNTER_ITP_MTP_REQ_CORE_ARREADY  (0x00000e5c)
#define     NCP_NCA_ITP_COUNTER_COUNTER_ITP_MTP_TX_CORE_AWREADY  (0x00000e60)
#define     NCP_NCA_ITP_COUNTER_COUNTER_QPM_CORE_AWREADY        (0x00000e64)
#define     NCP_NCA_ITP_COUNTER_COUNTER_TRACE_DATA_CORE_AWREADY  (0x00000e68)
#define     NCP_NCA_ITP_COUNTER_COUNTER_ACTIVITYCOUNTER_WRITEACK0  (0x00000e6c)
#define     NCP_NCA_ITP_COUNTER_COUNTER_ACTIVITYCOUNTER_WRITEACK1  (0x00000e70)
#define     NCP_NCA_ITP_COUNTER_COUNTER_ACTIVITYCOUNTER_MTP     (0x00000e74)
#define     NCP_NCA_ITP_COUNTER_COUNTER_TILSTART                (0x00000e78)
#define     NCP_NCA_ITP_COUNTER_COUNTER_PP                      (0x00000e7c)
#define     NCP_NCA_ITP_COUNTER_COUNTER_PP_PTRCNT0              (0x00000e80)
#define     NCP_NCA_ITP_COUNTER_COUNTER_PP_COPY                 (0x00000e84)
#define     NCP_NCA_ITP_COUNTER_COUNTER_PP_HS                   (0x00000e88)
#define     NCP_NCA_ITP_COUNTER_COUNTER_PP_ERR                  (0x00000e8c)
#define     NCP_NCA_ITP_COUNTER_COUNTER_ENQUEUE_CAMHIT          (0x00000e90)
#define     NCP_NCA_ITP_COUNTER_COUNTER_ENQUEUE_CAMMISS         (0x00000e94)
#define     NCP_NCA_ITP_COUNTER_COUNTER_ENQUEUE_ORDERED         (0x00000e98)
#define     NCP_NCA_ITP_COUNTER_COUNTER_ENQUEUE_UNORDER         (0x00000e9c)
#define     NCP_NCA_ITP_COUNTER_COUNTER_ENQUEUE_UNSCHED         (0x00000ea0)
#define     NCP_NCA_ITP_COUNTER_COUNTER_ENQUEUE_UNSCHED_ACK     (0x00000ea4)
#define     NCP_NCA_ITP_COUNTER_COUNTER_SCHED_ORDEREDSCHED      (0x00000ea8)
#define     NCP_NCA_ITP_COUNTER_COUNTER_SCHED_ORDEREDREADY      (0x00000eac)
#define     NCP_NCA_ITP_COUNTER_COUNTER_SCHED_UNORDER           (0x00000eb0)
#define     NCP_NCA_ITP_COUNTER_COUNTER_NLINKREQ                (0x00000eb4)
#define     NCP_NCA_ITP_COUNTER_COUNTER_COMPLETE_ORDERED        (0x00000eb8)
#define     NCP_NCA_ITP_COUNTER_COUNTER_COMPLETE_UNORDER        (0x00000ebc)
#define     NCP_NCA_ITP_COUNTER_COUNTER_POINTERALLOC            (0x00000ec0)
#define     NCP_NCA_ITP_COUNTER_COUNTER_POINTERDEALLOC0         (0x00000ec4)
#define     NCP_NCA_ITP_COUNTER_COUNTER_POINTERDEALLOC1         (0x00000ec8)
#define     NCP_NCA_ITP_COUNTER_COUNTER_POINTERTASK             (0x00000ecc)
#define     NCP_NCA_ITP_COUNTER_COUNTER_MQG_INC                 (0x00000ed0)
#define     NCP_NCA_ITP_COUNTER_COUNTER_POINTERNACK             (0x00000ed4)
#define     NCP_NCA_ITP_COUNTER_COUNTER_STATETRANS_00           (0x00000ed8)
#define     NCP_NCA_ITP_COUNTER_COUNTER_STATETRANS_01           (0x00000edc)
#define     NCP_NCA_ITP_COUNTER_COUNTER_STATETRANS_02           (0x00000ee0)
#define     NCP_NCA_ITP_COUNTER_COUNTER_STATETRANS_03           (0x00000ee4)
#define     NCP_NCA_ITP_COUNTER_COUNTER_STATETRANS_04           (0x00000ee8)
#define     NCP_NCA_ITP_COUNTER_COUNTER_STATETRANS_05           (0x00000eec)
#define     NCP_NCA_ITP_COUNTER_COUNTER_STATETRANS_06           (0x00000ef0)
#define     NCP_NCA_ITP_COUNTER_COUNTER_STATETRANS_07           (0x00000ef4)
#define     NCP_NCA_ITP_COUNTER_COUNTER_STATETRANS_08           (0x00000ef8)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_COPY_HEADER         (0x00000f00)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_COPY_B32A           (0x00000f04)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_COPY_FORMAT1        (0x00000f08)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_COPY_FORMAT2        (0x00000f0c)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_COPY_FORMAT3        (0x00000f10)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_COPY_FORMAT4        (0x00000f14)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_STARTTASK_DROP      (0x00000f18)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_COPY_FORMAT5        (0x00000f1c)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_TILBP               (0x00000f20)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_TCRIBP              (0x00000f24)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_INPUTFIFO_AFULL     (0x00000f28)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_CAM_IEORDERED_AVAL_V  (0x00000f2c)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_LL_IEORD_FULL       (0x00000f30)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_LL_IEUNORD_FULL     (0x00000f34)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_LL_PREPROC_FULL     (0x00000f38)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_LL_COMPLETION_FULL  (0x00000f3c)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_TQBP                (0x00000f40)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_IPCQFULL            (0x00000f44)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_MULTIFULL           (0x00000f48)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_NLINKREADY          (0x00000f4c)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_CREDITS             (0x00000f50)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_ITP_OTP_DEALLOC_BP  (0x00000f54)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_MMBR_ENG_BP         (0x00000f58)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_ITP_MTP_REQ_CORE_ARREADY  (0x00000f5c)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_ITP_MTP_TX_CORE_AWREADY  (0x00000f60)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_QPM_CORE_AWREADY    (0x00000f64)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_TRACE_DATA_CORE_AWREADY  (0x00000f68)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_ACTIVITYCOUNTER_WRITEACK0  (0x00000f6c)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_ACTIVITYCOUNTER_WRITEACK1  (0x00000f70)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_ACTIVITYCOUNTER_MTP  (0x00000f74)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_TILSTART            (0x00000f78)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_PP                  (0x00000f7c)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_PP_PTRCNT0          (0x00000f80)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_PP_COPY             (0x00000f84)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_PP_HS               (0x00000f88)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_PP_ERR              (0x00000f8c)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_ENQUEUE_CAMHIT      (0x00000f90)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_ENQUEUE_CAMMISS     (0x00000f94)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_ENQUEUE_ORDERED     (0x00000f98)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_ENQUEUE_UNORDER     (0x00000f9c)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_ENQUEUE_UNSCHED     (0x00000fa0)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_ENQUEUE_UNSCHED_ACK  (0x00000fa4)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_SCHED_ORDEREDSCHED  (0x00000fa8)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_SCHED_ORDEREDREADY  (0x00000fac)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_SCHED_UNORDER       (0x00000fb0)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_NLINKREQ            (0x00000fb4)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_COMPLETE_ORDERED    (0x00000fb8)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_COMPLETE_UNORDER    (0x00000fbc)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_POINTERALLOC        (0x00000fc0)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_POINTERDEALLOC0     (0x00000fc4)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_POINTERDEALLOC1     (0x00000fc8)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_POINTERTASK         (0x00000fcc)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_MQG_INC             (0x00000fd0)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_POINTERNACK         (0x00000fd4)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_STATETRANS_00       (0x00000fd8)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_STATETRANS_01       (0x00000fdc)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_STATETRANS_02       (0x00000fe0)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_STATETRANS_03       (0x00000fe4)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_STATETRANS_04       (0x00000fe8)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_STATETRANS_05       (0x00000fec)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_STATETRANS_06       (0x00000ff0)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_STATETRANS_07       (0x00000ff4)
#define     NCP_NCA_ITP_COR_COUNTER_COUNTER_STATETRANS_08       (0x00000ff8)
#define     NCP_NCA_ITP_CFG_SETUP                               (0x00000ffc)

#define     NCP_NCA_ITP_MULTI_OUPTUT_FIFO_STATE_RAM_BASE        (0x00003e00)
#define     NCP_NCA_ITP_MULTI_OUPTUT_FIFO_STATE_RAM(n)          (0x00003e00 + (4*(n)))
#define     NCP_NCA_ITP_MULTI_OUPTUT_FIFO_STATE_RAM_COUNT       (0x0000000d)
#define     NCP_NCA_ITP_MULTI_OUPTUT_FIFO_STATE_RAM_IDX(addr) \
  (((addr) - NCP_NCA_ITP_MULTI_OUPTUT_FIFO_STATE_RAM_BASE) / 4)
#define     NCP_NCA_ITP_MULTI_OUPTUT_FIFO_STATE_RAM_END         (0x00003e34)
#define     NCP_NCA_ITP_MULTI_OUPTUT_FIFO_STATE_RAM_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_MULTI_OUPTUT_FIFO_STATE_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_MULTI_OUPTUT_FIFO_STATE_RAM_END))


#define     NCP_NCA_ITP_IPD2_RAM_BASE                           (0x00008800)
#define     NCP_NCA_ITP_IPD2_RAM(n)                             (0x00008800 + (4*(n)))
#define     NCP_NCA_ITP_IPD2_RAM_COUNT                          (0x00000080)
#define     NCP_NCA_ITP_IPD2_RAM_IDX(addr) \
                   (((addr) - NCP_NCA_ITP_IPD2_RAM_BASE) / 4)        
#define     NCP_NCA_ITP_IPD2_RAM_END                            (0x00008a00)
#define     NCP_NCA_ITP_IPD2_RAM_RANGE(addr) \
                (((addr) >= NCP_NCA_ITP_IPD2_RAM_BASE) && \
                      ((addr) < NCP_NCA_ITP_IPD2_RAM_END))


#define     NCP_NCA_ITP_LL_PREPROC_STATE_RAM_BASE               (0x00010000)
#define     NCP_NCA_ITP_LL_PREPROC_STATE_RAM(n)                 (0x00010000 + (4*(n)))
#define     NCP_NCA_ITP_LL_PREPROC_STATE_RAM_COUNT              (0x000000cc)
#define     NCP_NCA_ITP_LL_PREPROC_STATE_RAM_IDX(addr) \
       (((addr) - NCP_NCA_ITP_LL_PREPROC_STATE_RAM_BASE) / 4)
#define     NCP_NCA_ITP_LL_PREPROC_STATE_RAM_END                (0x00010330)
#define     NCP_NCA_ITP_LL_PREPROC_STATE_RAM_RANGE(addr) \
    (((addr) >= NCP_NCA_ITP_LL_PREPROC_STATE_RAM_BASE) && \
    ((addr) < NCP_NCA_ITP_LL_PREPROC_STATE_RAM_END))


#define     NCP_NCA_ITP_LL_PREPROC_POINTER_RAM_BASE             (0x00014000)
#define     NCP_NCA_ITP_LL_PREPROC_POINTER_RAM(n)               (0x00014000 + (4*(n)))
#define     NCP_NCA_ITP_LL_PREPROC_POINTER_RAM_COUNT            (0x00000010)
#define     NCP_NCA_ITP_LL_PREPROC_POINTER_RAM_IDX(addr) \
     (((addr) - NCP_NCA_ITP_LL_PREPROC_POINTER_RAM_BASE) / 4)
#define     NCP_NCA_ITP_LL_PREPROC_POINTER_RAM_END              (0x00014040)
#define     NCP_NCA_ITP_LL_PREPROC_POINTER_RAM_RANGE(addr) \
  (((addr) >= NCP_NCA_ITP_LL_PREPROC_POINTER_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_LL_PREPROC_POINTER_RAM_END))


#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUED_THRESH_RAM_BASE     (0x0001e000)
#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUED_THRESH_RAM(n)       (0x0001e000 + (4*(n)))
#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUED_THRESH_RAM_COUNT    (0x00000100)
#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUED_THRESH_RAM_IDX(addr) \
  (((addr) - NCP_NCA_ITP_TQBP_PERTQ_UNISSUED_THRESH_RAM_BASE) / 4)
#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUED_THRESH_RAM_END      (0x0001e400)
#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUED_THRESH_RAM_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_TQBP_PERTQ_UNISSUED_THRESH_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_TQBP_PERTQ_UNISSUED_THRESH_RAM_END))


#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUEDQUEUED_THRESH_RAM_BASE  (0x0001e400)
#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUEDQUEUED_THRESH_RAM(n)  (0x0001e400 + (4*(n)))
#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUEDQUEUED_THRESH_RAM_COUNT  (0x00000100)
#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUEDQUEUED_THRESH_RAM_IDX(addr) \
  (((addr) - NCP_NCA_ITP_TQBP_PERTQ_UNISSUEDQUEUED_THRESH_RAM_BASE) / 4)
#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUEDQUEUED_THRESH_RAM_END  (0x0001e800)
#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUEDQUEUED_THRESH_RAM_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_TQBP_PERTQ_UNISSUEDQUEUED_THRESH_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_TQBP_PERTQ_UNISSUEDQUEUED_THRESH_RAM_END))


#define     NCP_NCA_ITP_TQBP_PERGID_UNISSUED_THRESH_RAM_BASE    (0x0001e800)
#define     NCP_NCA_ITP_TQBP_PERGID_UNISSUED_THRESH_RAM(n)      (0x0001e800 + (4*(n)))
#define     NCP_NCA_ITP_TQBP_PERGID_UNISSUED_THRESH_RAM_COUNT   (0x00000100)
#define     NCP_NCA_ITP_TQBP_PERGID_UNISSUED_THRESH_RAM_IDX(addr) \
  (((addr) - NCP_NCA_ITP_TQBP_PERGID_UNISSUED_THRESH_RAM_BASE) / 4)
#define     NCP_NCA_ITP_TQBP_PERGID_UNISSUED_THRESH_RAM_END     (0x0001ec00)
#define     NCP_NCA_ITP_TQBP_PERGID_UNISSUED_THRESH_RAM_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_TQBP_PERGID_UNISSUED_THRESH_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_TQBP_PERGID_UNISSUED_THRESH_RAM_END))


#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUED_CNT_RAM_BASE        (0x0001f000)
#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUED_CNT_RAM(n)          (0x0001f000 + (4*(n)))
#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUED_CNT_RAM_COUNT       (0x00000100)
#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUED_CNT_RAM_IDX(addr) \
  (((addr) - NCP_NCA_ITP_TQBP_PERTQ_UNISSUED_CNT_RAM_BASE) / 4)
#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUED_CNT_RAM_END         (0x0001f400)
#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUED_CNT_RAM_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_TQBP_PERTQ_UNISSUED_CNT_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_TQBP_PERTQ_UNISSUED_CNT_RAM_END))


#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUEDQUEUED_CNT_RAM_BASE  (0x0001f400)
#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUEDQUEUED_CNT_RAM(n)    (0x0001f400 + (4*(n)))
#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUEDQUEUED_CNT_RAM_COUNT  (0x00000100)
#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUEDQUEUED_CNT_RAM_IDX(addr) \
  (((addr) - NCP_NCA_ITP_TQBP_PERTQ_UNISSUEDQUEUED_CNT_RAM_BASE) / 4)
#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUEDQUEUED_CNT_RAM_END   (0x0001f800)
#define     NCP_NCA_ITP_TQBP_PERTQ_UNISSUEDQUEUED_CNT_RAM_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_TQBP_PERTQ_UNISSUEDQUEUED_CNT_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_TQBP_PERTQ_UNISSUEDQUEUED_CNT_RAM_END))


#define     NCP_NCA_ITP_TQBP_PERGID_UNISSUED_CNT_RAM_BASE       (0x0001f800)
#define     NCP_NCA_ITP_TQBP_PERGID_UNISSUED_CNT_RAM(n)         (0x0001f800 + (4*(n)))
#define     NCP_NCA_ITP_TQBP_PERGID_UNISSUED_CNT_RAM_COUNT      (0x00000100)
#define     NCP_NCA_ITP_TQBP_PERGID_UNISSUED_CNT_RAM_IDX(addr) \
  (((addr) - NCP_NCA_ITP_TQBP_PERGID_UNISSUED_CNT_RAM_BASE) / 4)
#define     NCP_NCA_ITP_TQBP_PERGID_UNISSUED_CNT_RAM_END        (0x0001fc00)
#define     NCP_NCA_ITP_TQBP_PERGID_UNISSUED_CNT_RAM_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_TQBP_PERGID_UNISSUED_CNT_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_TQBP_PERGID_UNISSUED_CNT_RAM_END))


#define     NCP_NCA_ITP_LL_IEUNORD_STATE_RAM_BASE               (0x00020000)
#define     NCP_NCA_ITP_LL_IEUNORD_STATE_RAM(n)                 (0x00020000 + (4*(n)))
#define     NCP_NCA_ITP_LL_IEUNORD_STATE_RAM_COUNT              (0x00000800)
#define     NCP_NCA_ITP_LL_IEUNORD_STATE_RAM_IDX(addr) \
       (((addr) - NCP_NCA_ITP_LL_IEUNORD_STATE_RAM_BASE) / 4)
#define     NCP_NCA_ITP_LL_IEUNORD_STATE_RAM_END                (0x00022000)
#define     NCP_NCA_ITP_LL_IEUNORD_STATE_RAM_RANGE(addr) \
    (((addr) >= NCP_NCA_ITP_LL_IEUNORD_STATE_RAM_BASE) && \
    ((addr) < NCP_NCA_ITP_LL_IEUNORD_STATE_RAM_END))


#define     NCP_NCA_ITP_LL_IEUNORD_POINTER_RAM_BASE             (0x00024000)
#define     NCP_NCA_ITP_LL_IEUNORD_POINTER_RAM(n)               (0x00024000 + (4*(n)))
#define     NCP_NCA_ITP_LL_IEUNORD_POINTER_RAM_COUNT            (0x00000400)
#define     NCP_NCA_ITP_LL_IEUNORD_POINTER_RAM_IDX(addr) \
     (((addr) - NCP_NCA_ITP_LL_IEUNORD_POINTER_RAM_BASE) / 4)
#define     NCP_NCA_ITP_LL_IEUNORD_POINTER_RAM_END              (0x00025000)
#define     NCP_NCA_ITP_LL_IEUNORD_POINTER_RAM_RANGE(addr) \
  (((addr) >= NCP_NCA_ITP_LL_IEUNORD_POINTER_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_LL_IEUNORD_POINTER_RAM_END))


#define     NCP_NCA_ITP_LL_IEORD_STATE_RAM_BASE                 (0x00030000)
#define     NCP_NCA_ITP_LL_IEORD_STATE_RAM(n)                   (0x00030000 + (4*(n)))
#define     NCP_NCA_ITP_LL_IEORD_STATE_RAM_COUNT                (0x00001000)
#define     NCP_NCA_ITP_LL_IEORD_STATE_RAM_IDX(addr) \
         (((addr) - NCP_NCA_ITP_LL_IEORD_STATE_RAM_BASE) / 4)
#define     NCP_NCA_ITP_LL_IEORD_STATE_RAM_END                  (0x00034000)
#define     NCP_NCA_ITP_LL_IEORD_STATE_RAM_RANGE(addr) \
      (((addr) >= NCP_NCA_ITP_LL_IEORD_STATE_RAM_BASE) && \
      ((addr) < NCP_NCA_ITP_LL_IEORD_STATE_RAM_END))


#define     NCP_NCA_ITP_LL_IEORD_POINTER_RAM_BASE               (0x00034000)
#define     NCP_NCA_ITP_LL_IEORD_POINTER_RAM(n)                 (0x00034000 + (4*(n)))
#define     NCP_NCA_ITP_LL_IEORD_POINTER_RAM_COUNT              (0x00000400)
#define     NCP_NCA_ITP_LL_IEORD_POINTER_RAM_IDX(addr) \
       (((addr) - NCP_NCA_ITP_LL_IEORD_POINTER_RAM_BASE) / 4)
#define     NCP_NCA_ITP_LL_IEORD_POINTER_RAM_END                (0x00035000)
#define     NCP_NCA_ITP_LL_IEORD_POINTER_RAM_RANGE(addr) \
    (((addr) >= NCP_NCA_ITP_LL_IEORD_POINTER_RAM_BASE) && \
    ((addr) < NCP_NCA_ITP_LL_IEORD_POINTER_RAM_END))


#define     NCP_NCA_ITP_LL_IEORDREADY_STATE_RAM_BASE            (0x00040000)
#define     NCP_NCA_ITP_LL_IEORDREADY_STATE_RAM(n)              (0x00040000 + (4*(n)))
#define     NCP_NCA_ITP_LL_IEORDREADY_STATE_RAM_COUNT           (0x00000100)
#define     NCP_NCA_ITP_LL_IEORDREADY_STATE_RAM_IDX(addr) \
    (((addr) - NCP_NCA_ITP_LL_IEORDREADY_STATE_RAM_BASE) / 4)
#define     NCP_NCA_ITP_LL_IEORDREADY_STATE_RAM_END             (0x00040400)
#define     NCP_NCA_ITP_LL_IEORDREADY_STATE_RAM_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_LL_IEORDREADY_STATE_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_LL_IEORDREADY_STATE_RAM_END))


#define     NCP_NCA_ITP_LL_IEORDREADY_POINTER_RAM_BASE          (0x00044000)
#define     NCP_NCA_ITP_LL_IEORDREADY_POINTER_RAM(n)            (0x00044000 + (4*(n)))
#define     NCP_NCA_ITP_LL_IEORDREADY_POINTER_RAM_COUNT         (0x00000400)
#define     NCP_NCA_ITP_LL_IEORDREADY_POINTER_RAM_IDX(addr) \
  (((addr) - NCP_NCA_ITP_LL_IEORDREADY_POINTER_RAM_BASE) / 4)
#define     NCP_NCA_ITP_LL_IEORDREADY_POINTER_RAM_END           (0x00045000)
#define     NCP_NCA_ITP_LL_IEORDREADY_POINTER_RAM_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_LL_IEORDREADY_POINTER_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_LL_IEORDREADY_POINTER_RAM_END))


#define     NCP_NCA_ITP_LL_IEORDREADY_ALLOCATE_RAM_BASE         (0x00048000)
#define     NCP_NCA_ITP_LL_IEORDREADY_ALLOCATE_RAM(n)           (0x00048000 + (4*(n)))
#define     NCP_NCA_ITP_LL_IEORDREADY_ALLOCATE_RAM_COUNT        (0x00000400)
#define     NCP_NCA_ITP_LL_IEORDREADY_ALLOCATE_RAM_IDX(addr) \
  (((addr) - NCP_NCA_ITP_LL_IEORDREADY_ALLOCATE_RAM_BASE) / 4)
#define     NCP_NCA_ITP_LL_IEORDREADY_ALLOCATE_RAM_END          (0x00049000)
#define     NCP_NCA_ITP_LL_IEORDREADY_ALLOCATE_RAM_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_LL_IEORDREADY_ALLOCATE_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_LL_IEORDREADY_ALLOCATE_RAM_END))


#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_STATE_RAM_BASE        (0x00050000)
#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_STATE_RAM(n)          (0x00050000 + (4*(n)))
#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_STATE_RAM_COUNT       (0x000002b0)
#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_STATE_RAM_IDX(addr) \
  (((addr) - NCP_NCA_ITP_LL_IEORDSCHEDULED_STATE_RAM_BASE) / 4)
#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_STATE_RAM_END         (0x00050ac0)
#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_STATE_RAM_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_LL_IEORDSCHEDULED_STATE_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_LL_IEORDSCHEDULED_STATE_RAM_END))


#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_POINTER_RAM_BASE      (0x00054000)
#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_POINTER_RAM(n)        (0x00054000 + (4*(n)))
#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_POINTER_RAM_COUNT     (0x00000400)
#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_POINTER_RAM_IDX(addr) \
  (((addr) - NCP_NCA_ITP_LL_IEORDSCHEDULED_POINTER_RAM_BASE) / 4)
#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_POINTER_RAM_END       (0x00055000)
#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_POINTER_RAM_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_LL_IEORDSCHEDULED_POINTER_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_LL_IEORDSCHEDULED_POINTER_RAM_END))


#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_TPOINTER_RAM_BASE     (0x00055000)
#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_TPOINTER_RAM(n)       (0x00055000 + (4*(n)))
#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_TPOINTER_RAM_COUNT    (0x00000400)
#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_TPOINTER_RAM_IDX(addr) \
  (((addr) - NCP_NCA_ITP_LL_IEORDSCHEDULED_TPOINTER_RAM_BASE) / 4)
#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_TPOINTER_RAM_END      (0x00056000)
#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_TPOINTER_RAM_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_LL_IEORDSCHEDULED_TPOINTER_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_LL_IEORDSCHEDULED_TPOINTER_RAM_END))


#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_ALLOCATE_RAM_BASE     (0x00058000)
#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_ALLOCATE_RAM(n)       (0x00058000 + (4*(n)))
#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_ALLOCATE_RAM_COUNT    (0x00000400)
#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_ALLOCATE_RAM_IDX(addr) \
  (((addr) - NCP_NCA_ITP_LL_IEORDSCHEDULED_ALLOCATE_RAM_BASE) / 4)
#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_ALLOCATE_RAM_END      (0x00059000)
#define     NCP_NCA_ITP_LL_IEORDSCHEDULED_ALLOCATE_RAM_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_LL_IEORDSCHEDULED_ALLOCATE_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_LL_IEORDSCHEDULED_ALLOCATE_RAM_END))


#define     NCP_NCA_ITP_LL_COMPLETION_POINTER_RAM_BASE          (0x00064000)
#define     NCP_NCA_ITP_LL_COMPLETION_POINTER_RAM(n)            (0x00064000 + (4*(n)))
#define     NCP_NCA_ITP_LL_COMPLETION_POINTER_RAM_COUNT         (0x00000800)
#define     NCP_NCA_ITP_LL_COMPLETION_POINTER_RAM_IDX(addr) \
  (((addr) - NCP_NCA_ITP_LL_COMPLETION_POINTER_RAM_BASE) / 4)
#define     NCP_NCA_ITP_LL_COMPLETION_POINTER_RAM_END           (0x00066000)
#define     NCP_NCA_ITP_LL_COMPLETION_POINTER_RAM_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_LL_COMPLETION_POINTER_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_LL_COMPLETION_POINTER_RAM_END))


#define     NCP_NCA_ITP_QPM_QSTATUS_RAM_BASE                    (0x00071000)
#define     NCP_NCA_ITP_QPM_QSTATUS_RAM(n)                      (0x00071000 + (4*(n)))
#define     NCP_NCA_ITP_QPM_QSTATUS_RAM_COUNT                   (0x00000400)
#define     NCP_NCA_ITP_QPM_QSTATUS_RAM_IDX(addr) \
            (((addr) - NCP_NCA_ITP_QPM_QSTATUS_RAM_BASE) / 4) 
#define     NCP_NCA_ITP_QPM_QSTATUS_RAM_END                     (0x00072000)
#define     NCP_NCA_ITP_QPM_QSTATUS_RAM_RANGE(addr) \
         (((addr) >= NCP_NCA_ITP_QPM_QSTATUS_RAM_BASE) && \
         ((addr) < NCP_NCA_ITP_QPM_QSTATUS_RAM_END))


#define     NCP_NCA_ITP_QPM_ONLINE_RAM_BASE                     (0x00073000)
#define     NCP_NCA_ITP_QPM_ONLINE_RAM(n)                       (0x00073000 + (4*(n)))
#define     NCP_NCA_ITP_QPM_ONLINE_RAM_COUNT                    (0x00000400)
#define     NCP_NCA_ITP_QPM_ONLINE_RAM_IDX(addr) \
             (((addr) - NCP_NCA_ITP_QPM_ONLINE_RAM_BASE) / 4)  
#define     NCP_NCA_ITP_QPM_ONLINE_RAM_END                      (0x00074000)
#define     NCP_NCA_ITP_QPM_ONLINE_RAM_RANGE(addr) \
          (((addr) >= NCP_NCA_ITP_QPM_ONLINE_RAM_BASE) && \
          ((addr) < NCP_NCA_ITP_QPM_ONLINE_RAM_END))


#define     NCP_NCA_ITP_BCAM_BASE                               (0x0007f000)
#define     NCP_NCA_ITP_BCAM(n)                                 (0x0007f000 + (4*(n)))
#define     NCP_NCA_ITP_BCAM_COUNT                              (0x00000200)
#define     NCP_NCA_ITP_BCAM_IDX(addr) \
                       (((addr) - NCP_NCA_ITP_BCAM_BASE) / 4)            
#define     NCP_NCA_ITP_BCAM_END                                (0x0007f800)
#define     NCP_NCA_ITP_BCAM_RANGE(addr) \
                    (((addr) >= NCP_NCA_ITP_BCAM_BASE) && \
                              ((addr) < NCP_NCA_ITP_BCAM_END))

#define     NCP_NCA_ITP_IPCQ_ONLINE00                           (0x0007ff40)
#define     NCP_NCA_ITP_IPCQ_ONLINE01                           (0x0007ff44)
#define     NCP_NCA_ITP_IPCQ_ONLINE02                           (0x0007ff48)
#define     NCP_NCA_ITP_IPCQ_VALID00                            (0x0007ff60)
#define     NCP_NCA_ITP_IPCQ_VALID01                            (0x0007ff64)
#define     NCP_NCA_ITP_IPCQ_VALID02                            (0x0007ff68)
#define     NCP_NCA_ITP_IPCQ_EMPTY00                            (0x0007ff80)
#define     NCP_NCA_ITP_IPCQ_EMPTY01                            (0x0007ff84)
#define     NCP_NCA_ITP_IPCQ_EMPTY02                            (0x0007ff88)
#define     NCP_NCA_ITP_IPCQ_FULL00                             (0x0007ffa0)
#define     NCP_NCA_ITP_IPCQ_FULL01                             (0x0007ffa4)
#define     NCP_NCA_ITP_IPCQ_FULL02                             (0x0007ffa8)
#define     NCP_NCA_ITP_NCAP_SIZE00                             (0x0007ffe0)
#define     NCP_NCA_ITP_NCAP_SIZE01                             (0x0007ffe4)
#define     NCP_NCA_ITP_NCAP_SIZE02                             (0x0007ffe8)
#define     NCP_NCA_ITP_NCAP_SIZE03                             (0x0007ffec)
#define     NCP_NCA_ITP_NCAP_CREDITS00                          (0x0007fff0)
#define     NCP_NCA_ITP_NCAP_CREDITS01                          (0x0007fff4)
#define     NCP_NCA_ITP_NCAP_CREDITS02                          (0x0007fff8)
#define     NCP_NCA_ITP_NCAP_CREDITS03                          (0x0007fffc)
#define     NCP_NCA_ITP_INTERRUPT_STATUS0                       (0x00000010)
#define     NCP_NCA_ITP_INTERRUPT_STATUS0_ALARM_MASK            (0x1dff7fff)
#define     NCP_NCA_ITP_INTERRUPT_STATUS0_SERVICE_MASK          (0xe2008000)
#define     NCP_NCA_ITP_INTERRUPT_STATUS1                       (0x00000014)
#define     NCP_NCA_ITP_INTERRUPT_STATUS1_ALARM_MASK            (0xffc7ffff)
#define     NCP_NCA_ITP_INTERRUPT_STATUS1_SERVICE_MASK          (0x00380000)
#define     NCP_NCA_ITP_INTERRUPT_STATUS2                       (0x00000018)
#define     NCP_NCA_ITP_INTERRUPT_STATUS2_ALARM_MASK            (0xffffffff)
#define     NCP_NCA_ITP_INTERRUPT_STATUS3                       (0x0000001c)
#define     NCP_NCA_ITP_INTERRUPT_STATUS3_ALARM_MASK            (0xffffffff)
#define     NCP_NCA_ITP_INTERRUPT_STATUS4                       (0x00000020)
#define     NCP_NCA_ITP_INTERRUPT_STATUS4_SERVICE_MASK          (0xffffffff)
#define     NCP_NCA_ITP_INTERRUPT_STATUS5                       (0x00000024)
#define     NCP_NCA_ITP_INTERRUPT_STATUS5_ALARM_MASK            (0xffffc000)
#define     NCP_NCA_ITP_INTERRUPT_STATUS5_SERVICE_MASK          (0x00003fff)
#define     NCP_NCA_ITP_INTERRUPT_STATUS6                       (0x00000028)
#define     NCP_NCA_ITP_INTERRUPT_STATUS6_ALARM_MASK            (0xffffffff)
#define     NCP_NCA_ITP_INTERRUPT_STATUS7                       (0x0000002c)
#define     NCP_NCA_ITP_INTERRUPT_STATUS7_ALARM_MASK            (0xc003ffff)
#define     NCP_NCA_ITP_INTERRUPT_STATUS7_SERVICE_MASK          (0x3ffc0000)
#define     NCP_NCA_ITP_INTERRUPT_EN0                           (0x00000030)
#define     NCP_NCA_ITP_INTERRUPT_EN0_ALARM_MASK                (0x1dff7fff)
#define     NCP_NCA_ITP_INTERRUPT_EN0_SERVICE_MASK              (0xe2008000)
#define     NCP_NCA_ITP_INTERRUPT_EN1                           (0x00000034)
#define     NCP_NCA_ITP_INTERRUPT_EN1_ALARM_MASK                (0xffc7ffff)
#define     NCP_NCA_ITP_INTERRUPT_EN1_SERVICE_MASK              (0x00380000)
#define     NCP_NCA_ITP_INTERRUPT_EN2                           (0x00000038)
#define     NCP_NCA_ITP_INTERRUPT_EN2_ALARM_MASK                (0xffffffff)
#define     NCP_NCA_ITP_INTERRUPT_EN3                           (0x0000003c)
#define     NCP_NCA_ITP_INTERRUPT_EN3_ALARM_MASK                (0xffffffff)
#define     NCP_NCA_ITP_INTERRUPT_EN4                           (0x00000040)
#define     NCP_NCA_ITP_INTERRUPT_EN4_SERVICE_MASK              (0xffffffff)
#define     NCP_NCA_ITP_INTERRUPT_EN5                           (0x00000044)
#define     NCP_NCA_ITP_INTERRUPT_EN5_ALARM_MASK                (0xffffc000)
#define     NCP_NCA_ITP_INTERRUPT_EN5_SERVICE_MASK              (0x00003fff)
#define     NCP_NCA_ITP_INTERRUPT_EN6                           (0x00000048)
#define     NCP_NCA_ITP_INTERRUPT_EN6_ALARM_MASK                (0xffffffff)
#define     NCP_NCA_ITP_INTERRUPT_EN7                           (0x0000004c)
#define     NCP_NCA_ITP_INTERRUPT_EN7_ALARM_MASK                (0xc003ffff)
#define     NCP_NCA_ITP_INTERRUPT_EN7_SERVICE_MASK              (0x3ffc0000)
#define     NCP_NCA_ITP_INTERRUPT_FRC0                          (0x00000050)
#define     NCP_NCA_ITP_INTERRUPT_FRC0_ALARM_MASK               (0x1dff7fff)
#define     NCP_NCA_ITP_INTERRUPT_FRC0_SERVICE_MASK             (0xe2008000)
#define     NCP_NCA_ITP_INTERRUPT_FRC1                          (0x00000054)
#define     NCP_NCA_ITP_INTERRUPT_FRC1_ALARM_MASK               (0xffc7ffff)
#define     NCP_NCA_ITP_INTERRUPT_FRC1_SERVICE_MASK             (0x00380000)
#define     NCP_NCA_ITP_INTERRUPT_FRC2                          (0x00000058)
#define     NCP_NCA_ITP_INTERRUPT_FRC2_ALARM_MASK               (0xffffffff)
#define     NCP_NCA_ITP_INTERRUPT_FRC3                          (0x0000005c)
#define     NCP_NCA_ITP_INTERRUPT_FRC3_ALARM_MASK               (0xffffffff)
#define     NCP_NCA_ITP_INTERRUPT_FRC4                          (0x00000060)
#define     NCP_NCA_ITP_INTERRUPT_FRC4_SERVICE_MASK             (0xffffffff)
#define     NCP_NCA_ITP_INTERRUPT_FRC5                          (0x00000064)
#define     NCP_NCA_ITP_INTERRUPT_FRC5_ALARM_MASK               (0xffffc000)
#define     NCP_NCA_ITP_INTERRUPT_FRC5_SERVICE_MASK             (0x00003fff)
#define     NCP_NCA_ITP_INTERRUPT_FRC6                          (0x00000068)
#define     NCP_NCA_ITP_INTERRUPT_FRC6_ALARM_MASK               (0xffffffff)
#define     NCP_NCA_ITP_INTERRUPT_FRC7                          (0x0000006c)
#define     NCP_NCA_ITP_INTERRUPT_FRC7_ALARM_MASK               (0xc003ffff)
#define     NCP_NCA_ITP_INTERRUPT_FRC7_SERVICE_MASK             (0x3ffc0000)


#define     NCP_NCA_ITP_TPD_RAM_BASE                            (0x00001000)
#define     NCP_NCA_ITP_TPD_RAM(n)                              (0x00001000 + (16*(n)))
#define     NCP_NCA_ITP_TPD_RAM_ACCESS_SIZE                     (0x00000010) /* Bytes */
#define     NCP_NCA_ITP_TPD_RAM_COUNT                           (0x000000cc)
#define     NCP_NCA_ITP_TPD_RAM_IDX(addr) \
                    (((addr) - NCP_NCA_ITP_TPD_RAM_BASE) / 16)        
#define     NCP_NCA_ITP_TPD_RAM_END                             (0x00001cc0)
#define     NCP_NCA_ITP_TPD_RAM_RANGE(addr) \
                 (((addr) >= NCP_NCA_ITP_TPD_RAM_BASE) && \
                        ((addr) < NCP_NCA_ITP_TPD_RAM_END))



#define     NCP_NCA_ITP_ADDRCONVERT_IN_POOLBASEINDEX_BASE       (0x00003000)
#define     NCP_NCA_ITP_ADDRCONVERT_IN_POOLBASEINDEX(n)         (0x00003000 + (32*(n)))
#define     NCP_NCA_ITP_ADDRCONVERT_IN_POOLBASEINDEX_ACCESS_SIZE  (0x00000020) /* Bytes */
#define     NCP_NCA_ITP_ADDRCONVERT_IN_POOLBASEINDEX_COUNT      (0x00000008)
#define     NCP_NCA_ITP_ADDRCONVERT_IN_POOLBASEINDEX_IDX(addr) \
  (((addr) - NCP_NCA_ITP_ADDRCONVERT_IN_POOLBASEINDEX_BASE) / 32)
#define     NCP_NCA_ITP_ADDRCONVERT_IN_POOLBASEINDEX_END        (0x00003100)
#define     NCP_NCA_ITP_ADDRCONVERT_IN_POOLBASEINDEX_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_ADDRCONVERT_IN_POOLBASEINDEX_BASE) && \
  ((addr) < NCP_NCA_ITP_ADDRCONVERT_IN_POOLBASEINDEX_END))



#define     NCP_NCA_ITP_ADDRCONVERT_IN_VIRTUALBASE_BASE         (0x00003100)
#define     NCP_NCA_ITP_ADDRCONVERT_IN_VIRTUALBASE(n)           (0x00003100 + (8*(n)))
#define     NCP_NCA_ITP_ADDRCONVERT_IN_VIRTUALBASE_ACCESS_SIZE  (0x00000008) /* Bytes */
#define     NCP_NCA_ITP_ADDRCONVERT_IN_VIRTUALBASE_COUNT        (0x00000080)
#define     NCP_NCA_ITP_ADDRCONVERT_IN_VIRTUALBASE_IDX(addr) \
  (((addr) - NCP_NCA_ITP_ADDRCONVERT_IN_VIRTUALBASE_BASE) / 8)
#define     NCP_NCA_ITP_ADDRCONVERT_IN_VIRTUALBASE_END          (0x00003500)
#define     NCP_NCA_ITP_ADDRCONVERT_IN_VIRTUALBASE_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_ADDRCONVERT_IN_VIRTUALBASE_BASE) && \
  ((addr) < NCP_NCA_ITP_ADDRCONVERT_IN_VIRTUALBASE_END))



#define     NCP_NCA_ITP_ADDRCONVERT_COPY_POOLBASEINDEX_BASE     (0x00003500)
#define     NCP_NCA_ITP_ADDRCONVERT_COPY_POOLBASEINDEX(n)       (0x00003500 + (32*(n)))
#define     NCP_NCA_ITP_ADDRCONVERT_COPY_POOLBASEINDEX_ACCESS_SIZE  (0x00000020) /* Bytes */
#define     NCP_NCA_ITP_ADDRCONVERT_COPY_POOLBASEINDEX_COUNT    (0x00000018)
#define     NCP_NCA_ITP_ADDRCONVERT_COPY_POOLBASEINDEX_IDX(addr) \
  (((addr) - NCP_NCA_ITP_ADDRCONVERT_COPY_POOLBASEINDEX_BASE) / 32)
#define     NCP_NCA_ITP_ADDRCONVERT_COPY_POOLBASEINDEX_END      (0x00003800)
#define     NCP_NCA_ITP_ADDRCONVERT_COPY_POOLBASEINDEX_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_ADDRCONVERT_COPY_POOLBASEINDEX_BASE) && \
  ((addr) < NCP_NCA_ITP_ADDRCONVERT_COPY_POOLBASEINDEX_END))



#define     NCP_NCA_ITP_ADDRCONVERT_COPY_VIRTUALBASE_BASE       (0x00003800)
#define     NCP_NCA_ITP_ADDRCONVERT_COPY_VIRTUALBASE(n)         (0x00003800 + (8*(n)))
#define     NCP_NCA_ITP_ADDRCONVERT_COPY_VIRTUALBASE_ACCESS_SIZE  (0x00000008) /* Bytes */
#define     NCP_NCA_ITP_ADDRCONVERT_COPY_VIRTUALBASE_COUNT      (0x00000080)
#define     NCP_NCA_ITP_ADDRCONVERT_COPY_VIRTUALBASE_IDX(addr) \
  (((addr) - NCP_NCA_ITP_ADDRCONVERT_COPY_VIRTUALBASE_BASE) / 8)
#define     NCP_NCA_ITP_ADDRCONVERT_COPY_VIRTUALBASE_END        (0x00003c00)
#define     NCP_NCA_ITP_ADDRCONVERT_COPY_VIRTUALBASE_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_ADDRCONVERT_COPY_VIRTUALBASE_BASE) && \
  ((addr) < NCP_NCA_ITP_ADDRCONVERT_COPY_VIRTUALBASE_END))



#define     NCP_NCA_ITP_NCAP2IPCQ_RAM_BASE                      (0x00003c00)
#define     NCP_NCA_ITP_NCAP2IPCQ_RAM(n)                        (0x00003c00 + (16*(n)))
#define     NCP_NCA_ITP_NCAP2IPCQ_RAM_ACCESS_SIZE               (0x00000010) /* Bytes */
#define     NCP_NCA_ITP_NCAP2IPCQ_RAM_COUNT                     (0x0000000d)
#define     NCP_NCA_ITP_NCAP2IPCQ_RAM_IDX(addr) \
              (((addr) - NCP_NCA_ITP_NCAP2IPCQ_RAM_BASE) / 16)  
#define     NCP_NCA_ITP_NCAP2IPCQ_RAM_END                       (0x00003cd0)
#define     NCP_NCA_ITP_NCAP2IPCQ_RAM_RANGE(addr) \
           (((addr) >= NCP_NCA_ITP_NCAP2IPCQ_RAM_BASE) && \
            ((addr) < NCP_NCA_ITP_NCAP2IPCQ_RAM_END))



#define     NCP_NCA_ITP_MULTI_OUTPUT_FIFO_CFG_RAM_BASE          (0x00003d00)
#define     NCP_NCA_ITP_MULTI_OUTPUT_FIFO_CFG_RAM(n)            (0x00003d00 + (8*(n)))
#define     NCP_NCA_ITP_MULTI_OUTPUT_FIFO_CFG_RAM_ACCESS_SIZE   (0x00000008) /* Bytes */
#define     NCP_NCA_ITP_MULTI_OUTPUT_FIFO_CFG_RAM_COUNT         (0x0000000d)
#define     NCP_NCA_ITP_MULTI_OUTPUT_FIFO_CFG_RAM_IDX(addr) \
  (((addr) - NCP_NCA_ITP_MULTI_OUTPUT_FIFO_CFG_RAM_BASE) / 8)
#define     NCP_NCA_ITP_MULTI_OUTPUT_FIFO_CFG_RAM_END           (0x00003d68)
#define     NCP_NCA_ITP_MULTI_OUTPUT_FIFO_CFG_RAM_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_MULTI_OUTPUT_FIFO_CFG_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_MULTI_OUTPUT_FIFO_CFG_RAM_END))



#define     NCP_NCA_ITP_MULTI_OUPTUT_FIFO_DATA_RAM_BASE         (0x00004000)
#define     NCP_NCA_ITP_MULTI_OUPTUT_FIFO_DATA_RAM(n)           (0x00004000 + (32*(n)))
#define     NCP_NCA_ITP_MULTI_OUPTUT_FIFO_DATA_RAM_ACCESS_SIZE  (0x00000020) /* Bytes */
#define     NCP_NCA_ITP_MULTI_OUPTUT_FIFO_DATA_RAM_COUNT        (0x000001a0)
#define     NCP_NCA_ITP_MULTI_OUPTUT_FIFO_DATA_RAM_IDX(addr) \
  (((addr) - NCP_NCA_ITP_MULTI_OUPTUT_FIFO_DATA_RAM_BASE) / 32)
#define     NCP_NCA_ITP_MULTI_OUPTUT_FIFO_DATA_RAM_END          (0x00007400)
#define     NCP_NCA_ITP_MULTI_OUPTUT_FIFO_DATA_RAM_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_MULTI_OUPTUT_FIFO_DATA_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_MULTI_OUPTUT_FIFO_DATA_RAM_END))



#define     NCP_NCA_ITP_IPD_RAM_BASE                            (0x00008000)
#define     NCP_NCA_ITP_IPD_RAM(n)                              (0x00008000 + (16*(n)))
#define     NCP_NCA_ITP_IPD_RAM_ACCESS_SIZE                     (0x00000010) /* Bytes */
#define     NCP_NCA_ITP_IPD_RAM_COUNT                           (0x00000056)
#define     NCP_NCA_ITP_IPD_RAM_IDX(addr) \
                    (((addr) - NCP_NCA_ITP_IPD_RAM_BASE) / 16)        
#define     NCP_NCA_ITP_IPD_RAM_END                             (0x00008560)
#define     NCP_NCA_ITP_IPD_RAM_RANGE(addr) \
                 (((addr) >= NCP_NCA_ITP_IPD_RAM_BASE) && \
                        ((addr) < NCP_NCA_ITP_IPD_RAM_END))



#define     NCP_NCA_ITP_GID2TQ_RAM_BASE                         (0x00009000)
#define     NCP_NCA_ITP_GID2TQ_RAM(n)                           (0x00009000 + (32*(n)))
#define     NCP_NCA_ITP_GID2TQ_RAM_ACCESS_SIZE                  (0x00000020) /* Bytes */
#define     NCP_NCA_ITP_GID2TQ_RAM_COUNT                        (0x00000100)
#define     NCP_NCA_ITP_GID2TQ_RAM_IDX(addr) \
                 (((addr) - NCP_NCA_ITP_GID2TQ_RAM_BASE) / 32)     
#define     NCP_NCA_ITP_GID2TQ_RAM_END                          (0x0000b000)
#define     NCP_NCA_ITP_GID2TQ_RAM_RANGE(addr) \
              (((addr) >= NCP_NCA_ITP_GID2TQ_RAM_BASE) && \
                  ((addr) < NCP_NCA_ITP_GID2TQ_RAM_END))



#define     NCP_NCA_ITP_RAM_IEORDERED_RAM_BASE                  (0x0000c000)
#define     NCP_NCA_ITP_RAM_IEORDERED_RAM(n)                    (0x0000c000 + (32*(n)))
#define     NCP_NCA_ITP_RAM_IEORDERED_RAM_ACCESS_SIZE           (0x00000020) /* Bytes */
#define     NCP_NCA_ITP_RAM_IEORDERED_RAM_COUNT                 (0x00000200)
#define     NCP_NCA_ITP_RAM_IEORDERED_RAM_IDX(addr) \
          (((addr) - NCP_NCA_ITP_RAM_IEORDERED_RAM_BASE) / 32)
#define     NCP_NCA_ITP_RAM_IEORDERED_RAM_END                   (0x00010000)
#define     NCP_NCA_ITP_RAM_IEORDERED_RAM_RANGE(addr) \
       (((addr) >= NCP_NCA_ITP_RAM_IEORDERED_RAM_BASE) && \
       ((addr) < NCP_NCA_ITP_RAM_IEORDERED_RAM_END))



#define     NCP_NCA_ITP_LL_PREPROC_ALLOCATE_RAM_BASE            (0x00018000)
#define     NCP_NCA_ITP_LL_PREPROC_ALLOCATE_RAM(n)              (0x00018000 + (64*(n)))
#define     NCP_NCA_ITP_LL_PREPROC_ALLOCATE_RAM_ACCESS_SIZE     (0x00000040) /* Bytes */
#define     NCP_NCA_ITP_LL_PREPROC_ALLOCATE_RAM_COUNT           (0x00000010)
#define     NCP_NCA_ITP_LL_PREPROC_ALLOCATE_RAM_IDX(addr) \
    (((addr) - NCP_NCA_ITP_LL_PREPROC_ALLOCATE_RAM_BASE) / 64)
#define     NCP_NCA_ITP_LL_PREPROC_ALLOCATE_RAM_END             (0x00018400)
#define     NCP_NCA_ITP_LL_PREPROC_ALLOCATE_RAM_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_LL_PREPROC_ALLOCATE_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_LL_PREPROC_ALLOCATE_RAM_END))



#define     NCP_NCA_ITP_LL_IEUNORD_ALLOCATE_RAM_BASE            (0x00028000)
#define     NCP_NCA_ITP_LL_IEUNORD_ALLOCATE_RAM(n)              (0x00028000 + (32*(n)))
#define     NCP_NCA_ITP_LL_IEUNORD_ALLOCATE_RAM_ACCESS_SIZE     (0x00000020) /* Bytes */
#define     NCP_NCA_ITP_LL_IEUNORD_ALLOCATE_RAM_COUNT           (0x00000400)
#define     NCP_NCA_ITP_LL_IEUNORD_ALLOCATE_RAM_IDX(addr) \
    (((addr) - NCP_NCA_ITP_LL_IEUNORD_ALLOCATE_RAM_BASE) / 32)
#define     NCP_NCA_ITP_LL_IEUNORD_ALLOCATE_RAM_END             (0x00030000)
#define     NCP_NCA_ITP_LL_IEUNORD_ALLOCATE_RAM_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_LL_IEUNORD_ALLOCATE_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_LL_IEUNORD_ALLOCATE_RAM_END))



#define     NCP_NCA_ITP_LL_IEORD_ALLOCATE_RAM_BASE              (0x00038000)
#define     NCP_NCA_ITP_LL_IEORD_ALLOCATE_RAM(n)                (0x00038000 + (32*(n)))
#define     NCP_NCA_ITP_LL_IEORD_ALLOCATE_RAM_ACCESS_SIZE       (0x00000020) /* Bytes */
#define     NCP_NCA_ITP_LL_IEORD_ALLOCATE_RAM_COUNT             (0x00000400)
#define     NCP_NCA_ITP_LL_IEORD_ALLOCATE_RAM_IDX(addr) \
      (((addr) - NCP_NCA_ITP_LL_IEORD_ALLOCATE_RAM_BASE) / 32)
#define     NCP_NCA_ITP_LL_IEORD_ALLOCATE_RAM_END               (0x00040000)
#define     NCP_NCA_ITP_LL_IEORD_ALLOCATE_RAM_RANGE(addr) \
   (((addr) >= NCP_NCA_ITP_LL_IEORD_ALLOCATE_RAM_BASE) && \
   ((addr) < NCP_NCA_ITP_LL_IEORD_ALLOCATE_RAM_END))



#define     NCP_NCA_ITP_LL_COMPLETION_STATE_RAM_BASE            (0x00060000)
#define     NCP_NCA_ITP_LL_COMPLETION_STATE_RAM(n)              (0x00060000 + (8*(n)))
#define     NCP_NCA_ITP_LL_COMPLETION_STATE_RAM_ACCESS_SIZE     (0x00000008) /* Bytes */
#define     NCP_NCA_ITP_LL_COMPLETION_STATE_RAM_COUNT           (0x00000100)
#define     NCP_NCA_ITP_LL_COMPLETION_STATE_RAM_IDX(addr) \
    (((addr) - NCP_NCA_ITP_LL_COMPLETION_STATE_RAM_BASE) / 8)
#define     NCP_NCA_ITP_LL_COMPLETION_STATE_RAM_END             (0x00060800)
#define     NCP_NCA_ITP_LL_COMPLETION_STATE_RAM_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_LL_COMPLETION_STATE_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_LL_COMPLETION_STATE_RAM_END))



#define     NCP_NCA_ITP_LL_COMPLETION_ALLOCATE_RAM_BASE         (0x00068000)
#define     NCP_NCA_ITP_LL_COMPLETION_ALLOCATE_RAM(n)           (0x00068000 + (16*(n)))
#define     NCP_NCA_ITP_LL_COMPLETION_ALLOCATE_RAM_ACCESS_SIZE  (0x00000010) /* Bytes */
#define     NCP_NCA_ITP_LL_COMPLETION_ALLOCATE_RAM_COUNT        (0x00000800)
#define     NCP_NCA_ITP_LL_COMPLETION_ALLOCATE_RAM_IDX(addr) \
  (((addr) - NCP_NCA_ITP_LL_COMPLETION_ALLOCATE_RAM_BASE) / 16)
#define     NCP_NCA_ITP_LL_COMPLETION_ALLOCATE_RAM_END          (0x00070000)
#define     NCP_NCA_ITP_LL_COMPLETION_ALLOCATE_RAM_RANGE(addr) \
 (((addr) >= NCP_NCA_ITP_LL_COMPLETION_ALLOCATE_RAM_BASE) && \
  ((addr) < NCP_NCA_ITP_LL_COMPLETION_ALLOCATE_RAM_END))



#define     NCP_NCA_ITP_TPDQ_RAM_BASE                           (0x00070000)
#define     NCP_NCA_ITP_TPDQ_RAM(n)                             (0x00070000 + (16*(n)))
#define     NCP_NCA_ITP_TPDQ_RAM_ACCESS_SIZE                    (0x00000010) /* Bytes */
#define     NCP_NCA_ITP_TPDQ_RAM_COUNT                          (0x00000080)
#define     NCP_NCA_ITP_TPDQ_RAM_IDX(addr) \
                   (((addr) - NCP_NCA_ITP_TPDQ_RAM_BASE) / 16)       
#define     NCP_NCA_ITP_TPDQ_RAM_END                            (0x00070800)
#define     NCP_NCA_ITP_TPDQ_RAM_RANGE(addr) \
                (((addr) >= NCP_NCA_ITP_TPDQ_RAM_BASE) && \
                      ((addr) < NCP_NCA_ITP_TPDQ_RAM_END))



#define     NCP_NCA_ITP_IPCQ2GID_RAM_BASE                       (0x0007e000)
#define     NCP_NCA_ITP_IPCQ2GID_RAM(n)                         (0x0007e000 + (32*(n)))
#define     NCP_NCA_ITP_IPCQ2GID_RAM_ACCESS_SIZE                (0x00000020) /* Bytes */
#define     NCP_NCA_ITP_IPCQ2GID_RAM_COUNT                      (0x00000056)
#define     NCP_NCA_ITP_IPCQ2GID_RAM_IDX(addr) \
               (((addr) - NCP_NCA_ITP_IPCQ2GID_RAM_BASE) / 32)   
#define     NCP_NCA_ITP_IPCQ2GID_RAM_END                        (0x0007eac0)
#define     NCP_NCA_ITP_IPCQ2GID_RAM_RANGE(addr) \
            (((addr) >= NCP_NCA_ITP_IPCQ2GID_RAM_BASE) && \
              ((addr) < NCP_NCA_ITP_IPCQ2GID_RAM_END))

#ifdef __cplusplus
}
#endif

#endif /* _NCP_NCA_ITP_REG_DEFINES_H_ */
