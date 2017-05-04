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


#ifndef _NCP_NCA_MTP_REG_DEFINES_H_
#define _NCP_NCA_MTP_REG_DEFINES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"


    /* NODE 0x101 , TARGET 0xffffffff*/


#define     NCP_NCA_MTP_APB_BRIDGE_STATUS                       (0x00000000)
#define     NCP_NCA_MTP_INTERFACE_31_0                          (0x00000004)
#define     NCP_NCA_MTP_INTERFACE_63_32                         (0x00000008)
#define     NCP_NCA_MTP_INTERFACE_95_64                         (0x0000000c)
#define     NCP_NCA_MTP_ERROR_SYNDROME                          (0x00000070)
#define     NCP_NCA_MTP_PARAMETERS_31_0                         (0x00000090)
#define     NCP_NCA_MTP_PARAMETERS_63_32                        (0x00000094)
#define     NCP_NCA_MTP_PARAMETERS_95_64                        (0x00000098)
#define     NCP_NCA_MTP_AW_SMON00_SMON                          (0x000000e0)
#define     NCP_NCA_MTP_AW_SMON01_SMON                          (0x000000e4)
#define     NCP_NCA_MTP_AW_SMON02_SMON                          (0x000000e8)
#define     NCP_NCA_MTP_AW_SMON03_SMON                          (0x000000ec)
#define     NCP_NCA_MTP_AW_SMON04_SMON                          (0x000000f0)
#define     NCP_NCA_MTP_AW_SMON05_SMON                          (0x000000f4)
#define     NCP_NCA_MTP_AW_SMON06_SMON                          (0x000000f8)
#define     NCP_NCA_MTP_AW_SMON07_SMON                          (0x000000fc)
#define     NCP_NCA_MTP_PF_REQUEST_SELECT                       (0x00000100)
#define     NCP_NCA_MTP_PF_SERVICE_SELECT                       (0x00000104)
#define     NCP_NCA_MTP_CONTROL                                 (0x00000108)
#define     NCP_NCA_MTP_DMM_RREQ_SMON_COMP_MASK                 (0x0000010c)
#define     NCP_NCA_MTP_DMM_WREQ_SMON_COMP_MASK                 (0x00000110)
#define     NCP_NCA_MTP_OTP_REQ_SMON_COMP_MASK                  (0x00000114)
#define     NCP_NCA_MTP_ITP_TX_SMON_COMP_MASK                   (0x00000118)
#define     NCP_NCA_MTP_ITP_REQ_SMON_COMP_MASK                  (0x0000011c)
#define     NCP_NCA_MTP_MPCQ_RES_SMON_COMP_MASK                 (0x00000120)
#define     NCP_NCA_MTP_MPCQ_REQ_SMON_COMP_MASK                 (0x00000124)
#define     NCP_NCA_MTP_MISC_SMON_COMP_MASK                     (0x00000128)
#define     NCP_NCA_MTP_INJECT_NACK_PROB                        (0x0000012c)
#define     NCP_NCA_MTP_OTP_HOLD_FIFO_STAT                      (0x00000700)
#define     NCP_NCA_MTP_OTP_HOLD_FIFO_WM                        (0x00000704)
#define     NCP_NCA_MTP_MPCQ_OUTPUT_FIFO_STAT                   (0x00000708)
#define     NCP_NCA_MTP_MPCQ_OUTPUT_FIFO_WM                     (0x0000070c)
#define     NCP_NCA_MTP_ITP_OUTPUT_FIFO_STAT                    (0x00000710)
#define     NCP_NCA_MTP_ITP_OUTPUT_FIFO_WM                      (0x00000714)
#define     NCP_NCA_MTP_DMM_OUTPUT_FIFO_STAT                    (0x00000718)
#define     NCP_NCA_MTP_DMM_OUTPUT_FIFO_WM                      (0x0000071c)
#define     NCP_NCA_MTP_MCIP_HOLD_FIFO_STAT                     (0x00000720)
#define     NCP_NCA_MTP_MCIP_HOLD_FIFO_WM                       (0x00000724)
#define     NCP_NCA_MTP_SNARF_FIFO_STAT                         (0x00000728)
#define     NCP_NCA_MTP_SNARF_FIFO_WM                           (0x0000072c)
#define     NCP_NCA_MTP_MPCQ_MQG_UPD_FIFO_STAT                  (0x00000730)
#define     NCP_NCA_MTP_MPCQ_MQG_UPD_FIFO_WM                    (0x00000734)
#define     NCP_NCA_MTP_DMM_MQG_UPD_FIFO_STAT                   (0x00000738)
#define     NCP_NCA_MTP_DMM_MQG_UPD_FIFO_WM                     (0x0000073c)
#define     NCP_NCA_MTP_MQG0_GTT_STATUS                         (0x00000800)
#define     NCP_NCA_MTP_MQG1_GTT_STATUS                         (0x00000804)
#define     NCP_NCA_MTP_MQG2_GTT_STATUS                         (0x00000808)
#define     NCP_NCA_MTP_MQG3_GTT_STATUS                         (0x0000080c)
#define     NCP_NCA_MTP_MQG4_GTT_STATUS                         (0x00000810)
#define     NCP_NCA_MTP_MQG5_GTT_STATUS                         (0x00000814)
#define     NCP_NCA_MTP_MQG6_GTT_STATUS                         (0x00000818)
#define     NCP_NCA_MTP_MQG7_GTT_STATUS                         (0x0000081c)
#define     NCP_NCA_MTP_MQG8_GTT_STATUS                         (0x00000820)
#define     NCP_NCA_MTP_MQG9_GTT_STATUS                         (0x00000824)
#define     NCP_NCA_MTP_MQG10_GTT_STATUS                        (0x00000828)
#define     NCP_NCA_MTP_MQG11_GTT_STATUS                        (0x0000082c)
#define     NCP_NCA_MTP_MQG12_GTT_STATUS                        (0x00000830)
#define     NCP_NCA_MTP_MQG13_GTT_STATUS                        (0x00000834)
#define     NCP_NCA_MTP_MQG14_GTT_STATUS                        (0x00000838)
#define     NCP_NCA_MTP_MQG15_GTT_STATUS                        (0x0000083c)
#define     NCP_NCA_MTP_MQG16_GTT_STATUS                        (0x00000840)
#define     NCP_NCA_MTP_MQG17_GTT_STATUS                        (0x00000844)
#define     NCP_NCA_MTP_MQG18_GTT_STATUS                        (0x00000848)
#define     NCP_NCA_MTP_MQG19_GTT_STATUS                        (0x0000084c)
#define     NCP_NCA_MTP_MQG20_GTT_STATUS                        (0x00000850)
#define     NCP_NCA_MTP_MQG21_GTT_STATUS                        (0x00000854)
#define     NCP_NCA_MTP_MQG22_GTT_STATUS                        (0x00000858)
#define     NCP_NCA_MTP_MQG23_GTT_STATUS                        (0x0000085c)
#define     NCP_NCA_MTP_MQG24_GTT_STATUS                        (0x00000860)
#define     NCP_NCA_MTP_MQG25_GTT_STATUS                        (0x00000864)
#define     NCP_NCA_MTP_MQG26_GTT_STATUS                        (0x00000868)
#define     NCP_NCA_MTP_MQG27_GTT_STATUS                        (0x0000086c)
#define     NCP_NCA_MTP_MQG28_GTT_STATUS                        (0x00000870)
#define     NCP_NCA_MTP_MQG29_GTT_STATUS                        (0x00000874)
#define     NCP_NCA_MTP_MQG30_GTT_STATUS                        (0x00000878)
#define     NCP_NCA_MTP_MQG31_GTT_STATUS                        (0x0000087c)
#define     NCP_NCA_MTP_MQG0_GTM_STATUS                         (0x00000880)
#define     NCP_NCA_MTP_MQG1_GTM_STATUS                         (0x00000884)
#define     NCP_NCA_MTP_MQG2_GTM_STATUS                         (0x00000888)
#define     NCP_NCA_MTP_MQG3_GTM_STATUS                         (0x0000088c)
#define     NCP_NCA_MTP_MQG4_GTM_STATUS                         (0x00000890)
#define     NCP_NCA_MTP_MQG5_GTM_STATUS                         (0x00000894)
#define     NCP_NCA_MTP_MQG6_GTM_STATUS                         (0x00000898)
#define     NCP_NCA_MTP_MQG7_GTM_STATUS                         (0x0000089c)
#define     NCP_NCA_MTP_MQG8_GTM_STATUS                         (0x000008a0)
#define     NCP_NCA_MTP_MQG9_GTM_STATUS                         (0x000008a4)
#define     NCP_NCA_MTP_MQG10_GTM_STATUS                        (0x000008a8)
#define     NCP_NCA_MTP_MQG11_GTM_STATUS                        (0x000008ac)
#define     NCP_NCA_MTP_MQG12_GTM_STATUS                        (0x000008b0)
#define     NCP_NCA_MTP_MQG13_GTM_STATUS                        (0x000008b4)
#define     NCP_NCA_MTP_MQG14_GTM_STATUS                        (0x000008b8)
#define     NCP_NCA_MTP_MQG15_GTM_STATUS                        (0x000008bc)
#define     NCP_NCA_MTP_MQG16_GTM_STATUS                        (0x000008c0)
#define     NCP_NCA_MTP_MQG17_GTM_STATUS                        (0x000008c4)
#define     NCP_NCA_MTP_MQG18_GTM_STATUS                        (0x000008c8)
#define     NCP_NCA_MTP_MQG19_GTM_STATUS                        (0x000008cc)
#define     NCP_NCA_MTP_MQG20_GTM_STATUS                        (0x000008d0)
#define     NCP_NCA_MTP_MQG21_GTM_STATUS                        (0x000008d4)
#define     NCP_NCA_MTP_MQG22_GTM_STATUS                        (0x000008d8)
#define     NCP_NCA_MTP_MQG23_GTM_STATUS                        (0x000008dc)
#define     NCP_NCA_MTP_MQG24_GTM_STATUS                        (0x000008e0)
#define     NCP_NCA_MTP_MQG25_GTM_STATUS                        (0x000008e4)
#define     NCP_NCA_MTP_MQG26_GTM_STATUS                        (0x000008e8)
#define     NCP_NCA_MTP_MQG27_GTM_STATUS                        (0x000008ec)
#define     NCP_NCA_MTP_MQG28_GTM_STATUS                        (0x000008f0)
#define     NCP_NCA_MTP_MQG29_GTM_STATUS                        (0x000008f4)
#define     NCP_NCA_MTP_MQG30_GTM_STATUS                        (0x000008f8)
#define     NCP_NCA_MTP_MQG31_GTM_STATUS                        (0x000008fc)
#define     NCP_NCA_MTP_MQG0_LT0_STATUS                         (0x00000900)
#define     NCP_NCA_MTP_MQG1_LT0_STATUS                         (0x00000904)
#define     NCP_NCA_MTP_MQG2_LT0_STATUS                         (0x00000908)
#define     NCP_NCA_MTP_MQG3_LT0_STATUS                         (0x0000090c)
#define     NCP_NCA_MTP_MQG4_LT0_STATUS                         (0x00000910)
#define     NCP_NCA_MTP_MQG5_LT0_STATUS                         (0x00000914)
#define     NCP_NCA_MTP_MQG6_LT0_STATUS                         (0x00000918)
#define     NCP_NCA_MTP_MQG7_LT0_STATUS                         (0x0000091c)
#define     NCP_NCA_MTP_MQG8_LT0_STATUS                         (0x00000920)
#define     NCP_NCA_MTP_MQG9_LT0_STATUS                         (0x00000924)
#define     NCP_NCA_MTP_MQG10_LT0_STATUS                        (0x00000928)
#define     NCP_NCA_MTP_MQG11_LT0_STATUS                        (0x0000092c)
#define     NCP_NCA_MTP_MQG12_LT0_STATUS                        (0x00000930)
#define     NCP_NCA_MTP_MQG13_LT0_STATUS                        (0x00000934)
#define     NCP_NCA_MTP_MQG14_LT0_STATUS                        (0x00000938)
#define     NCP_NCA_MTP_MQG15_LT0_STATUS                        (0x0000093c)
#define     NCP_NCA_MTP_MQG16_LT0_STATUS                        (0x00000940)
#define     NCP_NCA_MTP_MQG17_LT0_STATUS                        (0x00000944)
#define     NCP_NCA_MTP_MQG18_LT0_STATUS                        (0x00000948)
#define     NCP_NCA_MTP_MQG19_LT0_STATUS                        (0x0000094c)
#define     NCP_NCA_MTP_MQG20_LT0_STATUS                        (0x00000950)
#define     NCP_NCA_MTP_MQG21_LT0_STATUS                        (0x00000954)
#define     NCP_NCA_MTP_MQG22_LT0_STATUS                        (0x00000958)
#define     NCP_NCA_MTP_MQG23_LT0_STATUS                        (0x0000095c)
#define     NCP_NCA_MTP_MQG24_LT0_STATUS                        (0x00000960)
#define     NCP_NCA_MTP_MQG25_LT0_STATUS                        (0x00000964)
#define     NCP_NCA_MTP_MQG26_LT0_STATUS                        (0x00000968)
#define     NCP_NCA_MTP_MQG27_LT0_STATUS                        (0x0000096c)
#define     NCP_NCA_MTP_MQG28_LT0_STATUS                        (0x00000970)
#define     NCP_NCA_MTP_MQG29_LT0_STATUS                        (0x00000974)
#define     NCP_NCA_MTP_MQG30_LT0_STATUS                        (0x00000978)
#define     NCP_NCA_MTP_MQG31_LT0_STATUS                        (0x0000097c)
#define     NCP_NCA_MTP_STRIPE0_UNDERFLOW_31_0                  (0x00000980)
#define     NCP_NCA_MTP_STRIPE0_UNDERFLOW_63_32                 (0x00000984)
#define     NCP_NCA_MTP_STRIPE0_UNDERFLOW_95_64                 (0x00000988)
#define     NCP_NCA_MTP_STRIPE1_UNDERFLOW_31_0                  (0x0000098c)
#define     NCP_NCA_MTP_STRIPE1_UNDERFLOW_63_32                 (0x00000990)
#define     NCP_NCA_MTP_STRIPE1_UNDERFLOW_95_64                 (0x00000994)
#define     NCP_NCA_MTP_STRIPE0_OVERFLOW_31_0                   (0x00000998)
#define     NCP_NCA_MTP_STRIPE0_OVERFLOW_63_32                  (0x0000099c)
#define     NCP_NCA_MTP_STRIPE0_OVERFLOW_95_64                  (0x000009a0)
#define     NCP_NCA_MTP_STRIPE1_OVERFLOW_31_0                   (0x000009a4)
#define     NCP_NCA_MTP_STRIPE1_OVERFLOW_63_32                  (0x000009a8)
#define     NCP_NCA_MTP_STRIPE1_OVERFLOW_95_64                  (0x000009ac)
#define     NCP_NCA_MTP_NCAP0_MPCQ_INPUT_FIFO_STAT              (0x000009b0)
#define     NCP_NCA_MTP_NCAP1_MPCQ_INPUT_FIFO_STAT              (0x000009b4)
#define     NCP_NCA_MTP_NCAP2_MPCQ_INPUT_FIFO_STAT              (0x000009b8)
#define     NCP_NCA_MTP_NCAP3_MPCQ_INPUT_FIFO_STAT              (0x000009bc)
#define     NCP_NCA_MTP_NCAP4_MPCQ_INPUT_FIFO_STAT              (0x000009c0)
#define     NCP_NCA_MTP_NCAP5_MPCQ_INPUT_FIFO_STAT              (0x000009c4)
#define     NCP_NCA_MTP_NCAP6_MPCQ_INPUT_FIFO_STAT              (0x000009c8)
#define     NCP_NCA_MTP_NCAP7_MPCQ_INPUT_FIFO_STAT              (0x000009cc)
#define     NCP_NCA_MTP_NCAP8_MPCQ_INPUT_FIFO_STAT              (0x000009d0)
#define     NCP_NCA_MTP_NCAP9_MPCQ_INPUT_FIFO_STAT              (0x000009d4)
#define     NCP_NCA_MTP_NCAP10_MPCQ_INPUT_FIFO_STAT             (0x000009d8)
#define     NCP_NCA_MTP_NCAP11_MPCQ_INPUT_FIFO_STAT             (0x000009dc)
#define     NCP_NCA_MTP_NCAP12_MPCQ_INPUT_FIFO_STAT             (0x000009e0)
#define     NCP_NCA_MTP_STATUS                                  (0x000009e4)
#define     NCP_NCA_MTP_PF_FIFO_V_31_0                          (0x000009e8)
#define     NCP_NCA_MTP_PF_FIFO_V_63_32                         (0x000009ec)
#define     NCP_NCA_MTP_PF_FIFO_V_95_64                         (0x000009f0)
#define     NCP_NCA_MTP_PF_NACK_MODE_31_0                       (0x000009f4)
#define     NCP_NCA_MTP_PF_NACK_MODE_63_32                      (0x000009f8)
#define     NCP_NCA_MTP_PF_NACK_MODE_95_64                      (0x000009fc)
#define     NCP_NCA_MTP_PF_NEEDS_SERVICE_31_0                   (0x00000a00)
#define     NCP_NCA_MTP_PF_NEEDS_SERVICE_63_32                  (0x00000a04)
#define     NCP_NCA_MTP_PF_NEEDS_SERVICE_95_64                  (0x00000a08)
#define     NCP_NCA_MTP_PF_SERVICING_31_0                       (0x00000a0c)
#define     NCP_NCA_MTP_PF_SERVICING_63_32                      (0x00000a10)
#define     NCP_NCA_MTP_PF_SERVICING_95_64                      (0x00000a14)
#define     NCP_NCA_MTP_MCIP_ALLOC_REQ_COUNTER                  (0x00000e00)
#define     NCP_NCA_MTP_MCIP_ALLOC_ACK_COUNTER                  (0x00000e04)
#define     NCP_NCA_MTP_MCIP_ALLOC_NACK_COUNTER                 (0x00000e08)
#define     NCP_NCA_MTP_MPCQ_ALLOC_REQ_COUNTER                  (0x00000e0c)
#define     NCP_NCA_MTP_MPCQ_ALLOC_ACK_COUNTER                  (0x00000e10)
#define     NCP_NCA_MTP_MPCQ_ALLOC_NACK_COUNTER                 (0x00000e14)
#define     NCP_NCA_MTP_ITP_ALLOC_REQ_COUNTER                   (0x00000e18)
#define     NCP_NCA_MTP_ITP_ALLOC_ACK_COUNTER                   (0x00000e1c)
#define     NCP_NCA_MTP_ITP_ALLOC_NACK_COUNTER                  (0x00000e20)
#define     NCP_NCA_MTP_DMM_ALLOC_REQ_COUNTER                   (0x00000e24)
#define     NCP_NCA_MTP_DMM_ALLOC_ACK_COUNTER                   (0x00000e28)
#define     NCP_NCA_MTP_DMM_ALLOC_NACK_COUNTER                  (0x00000e2c)
#define     NCP_NCA_MTP_MCIP_REFCNT_INC_COUNTER                 (0x00000e30)
#define     NCP_NCA_MTP_MCIP_REFCNT_DEC_COUNTER                 (0x00000e34)
#define     NCP_NCA_MTP_REFCNT_SNARFABLE_COUNTER                (0x00000e38)
#define     NCP_NCA_MTP_MCIP_REFCNT_RESP_COUNTER                (0x00000e3c)
#define     NCP_NCA_MTP_COW_REFCNT_INC_COUNTER                  (0x00000e40)
#define     NCP_NCA_MTP_COW_REFCNT_RESP_COUNTER                 (0x00000e44)
#define     NCP_NCA_MTP_DMM_REFCNT_DEC_COUNTER                  (0x00000e48)
#define     NCP_NCA_MTP_OTP_REFCNT_INC_COUNTER                  (0x00000e4c)
#define     NCP_NCA_MTP_OTP_REFCNT_DEC_COUNTER                  (0x00000e50)
#define     NCP_NCA_MTP_ITP_REFCNT_INC_COUNTER                  (0x00000e54)
#define     NCP_NCA_MTP_OTP_SNARFED_COUNTER                     (0x00000e58)
#define     NCP_NCA_MTP_DMM_SNARFED_COUNTER                     (0x00000e5c)
#define     NCP_NCA_MTP_MCIP_ALLOC_REQ_COUNTER_COR              (0x00000f00)
#define     NCP_NCA_MTP_MCIP_ALLOC_ACK_COUNTER_COR              (0x00000f04)
#define     NCP_NCA_MTP_MCIP_ALLOC_NACK_COUNTER_COR             (0x00000f08)
#define     NCP_NCA_MTP_MPCQ_ALLOC_REQ_COUNTER_COR              (0x00000f0c)
#define     NCP_NCA_MTP_MPCQ_ALLOC_ACK_COUNTER_COR              (0x00000f10)
#define     NCP_NCA_MTP_MPCQ_ALLOC_NACK_COUNTER_COR             (0x00000f14)
#define     NCP_NCA_MTP_ITP_ALLOC_REQ_COUNTER_COR               (0x00000f18)
#define     NCP_NCA_MTP_ITP_ALLOC_ACK_COUNTER_COR               (0x00000f1c)
#define     NCP_NCA_MTP_ITP_ALLOC_NACK_COUNTER_COR              (0x00000f20)
#define     NCP_NCA_MTP_DMM_ALLOC_REQ_COUNTER_COR               (0x00000f24)
#define     NCP_NCA_MTP_DMM_ALLOC_ACK_COUNTER_COR               (0x00000f28)
#define     NCP_NCA_MTP_DMM_ALLOC_NACK_COUNTER_COR              (0x00000f2c)
#define     NCP_NCA_MTP_MCIP_REFCNT_INC_COUNTER_COR             (0x00000f30)
#define     NCP_NCA_MTP_MCIP_REFCNT_DEC_COUNTER_COR             (0x00000f34)
#define     NCP_NCA_MTP_REFCNT_SNARFABLE_COUNTER_COR            (0x00000f38)
#define     NCP_NCA_MTP_MCIP_REFCNT_RESP_COUNTER_COR            (0x00000f3c)
#define     NCP_NCA_MTP_COW_REFCNT_INC_COUNTER_COR              (0x00000f40)
#define     NCP_NCA_MTP_COW_REFCNT_RESP_COUNTER_COR             (0x00000f44)
#define     NCP_NCA_MTP_DMM_REFCNT_DEC_COUNTER_COR              (0x00000f48)
#define     NCP_NCA_MTP_OTP_REFCNT_INC_COUNTER_COR              (0x00000f4c)
#define     NCP_NCA_MTP_OTP_REFCNT_DEC_COUNTER_COR              (0x00000f50)
#define     NCP_NCA_MTP_ITP_REFCNT_INC_COUNTER_COR              (0x00000f54)
#define     NCP_NCA_MTP_OTP_SNARFED_COUNTER_COR                 (0x00000f58)
#define     NCP_NCA_MTP_DMM_SNARFED_COUNTER_COR                 (0x00000f5c)
#define     NCP_NCA_MTP_CFG_SETUP                               (0x00000ffc)

#define     NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_0_BASE   (0x00002000)
#define     NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_0(n)     (0x00002000 + (4*(n)))
#define     NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_0_COUNT  (0x00000060)
#define     NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_0_IDX(addr) \
  (((addr) - NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_0_BASE) / 4)
#define     NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_0_END    (0x00002180)
#define     NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_0_RANGE(addr) \
 (((addr) >= NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_0_BASE) && \
  ((addr) < NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_0_END))


#define     NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_1_BASE   (0x00002200)
#define     NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_1(n)     (0x00002200 + (4*(n)))
#define     NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_1_COUNT  (0x00000060)
#define     NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_1_IDX(addr) \
  (((addr) - NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_1_BASE) / 4)
#define     NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_1_END    (0x00002380)
#define     NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_1_RANGE(addr) \
 (((addr) >= NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_1_BASE) && \
  ((addr) < NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_1_END))


#define     NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_WRITE_BASE  (0x00002400)
#define     NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_WRITE(n)  (0x00002400 + (4*(n)))
#define     NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_WRITE_COUNT  (0x00000060)
#define     NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_WRITE_IDX(addr) \
  (((addr) - NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_WRITE_BASE) / 4)
#define     NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_WRITE_END  (0x00002580)
#define     NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_WRITE_RANGE(addr) \
 (((addr) >= NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_WRITE_BASE) && \
  ((addr) < NCP_NCA_MTP_PREFETCH_FIFO_STATE_RAM_STRIPE_WRITE_END))


#define     NCP_NCA_MTP_PREFETCH_FIFO_DATA_RAM_STRIPE_1_BASE    (0x00003000)
#define     NCP_NCA_MTP_PREFETCH_FIFO_DATA_RAM_STRIPE_1(n)      (0x00003000 + (4*(n)))
#define     NCP_NCA_MTP_PREFETCH_FIFO_DATA_RAM_STRIPE_1_COUNT   (0x00000400)
#define     NCP_NCA_MTP_PREFETCH_FIFO_DATA_RAM_STRIPE_1_IDX(addr) \
  (((addr) - NCP_NCA_MTP_PREFETCH_FIFO_DATA_RAM_STRIPE_1_BASE) / 4)
#define     NCP_NCA_MTP_PREFETCH_FIFO_DATA_RAM_STRIPE_1_END     (0x00004000)
#define     NCP_NCA_MTP_PREFETCH_FIFO_DATA_RAM_STRIPE_1_RANGE(addr) \
 (((addr) >= NCP_NCA_MTP_PREFETCH_FIFO_DATA_RAM_STRIPE_1_BASE) && \
  ((addr) < NCP_NCA_MTP_PREFETCH_FIFO_DATA_RAM_STRIPE_1_END))


#define     NCP_NCA_MTP_PREFETCH_FIFO_DATA_RAM_STRIPE_0_BASE    (0x00004000)
#define     NCP_NCA_MTP_PREFETCH_FIFO_DATA_RAM_STRIPE_0(n)      (0x00004000 + (4*(n)))
#define     NCP_NCA_MTP_PREFETCH_FIFO_DATA_RAM_STRIPE_0_COUNT   (0x00000400)
#define     NCP_NCA_MTP_PREFETCH_FIFO_DATA_RAM_STRIPE_0_IDX(addr) \
  (((addr) - NCP_NCA_MTP_PREFETCH_FIFO_DATA_RAM_STRIPE_0_BASE) / 4)
#define     NCP_NCA_MTP_PREFETCH_FIFO_DATA_RAM_STRIPE_0_END     (0x00005000)
#define     NCP_NCA_MTP_PREFETCH_FIFO_DATA_RAM_STRIPE_0_RANGE(addr) \
 (((addr) >= NCP_NCA_MTP_PREFETCH_FIFO_DATA_RAM_STRIPE_0_BASE) && \
  ((addr) < NCP_NCA_MTP_PREFETCH_FIFO_DATA_RAM_STRIPE_0_END))


#define     NCP_NCA_MTP_MQG_COUNT_256B_RAM_BASE                 (0x00007000)
#define     NCP_NCA_MTP_MQG_COUNT_256B_RAM(n)                   (0x00007000 + (4*(n)))
#define     NCP_NCA_MTP_MQG_COUNT_256B_RAM_COUNT                (0x000000c0)
#define     NCP_NCA_MTP_MQG_COUNT_256B_RAM_IDX(addr) \
         (((addr) - NCP_NCA_MTP_MQG_COUNT_256B_RAM_BASE) / 4)
#define     NCP_NCA_MTP_MQG_COUNT_256B_RAM_END                  (0x00007300)
#define     NCP_NCA_MTP_MQG_COUNT_256B_RAM_RANGE(addr) \
      (((addr) >= NCP_NCA_MTP_MQG_COUNT_256B_RAM_BASE) && \
      ((addr) < NCP_NCA_MTP_MQG_COUNT_256B_RAM_END))


#define     NCP_NCA_MTP_MQG_COUNT_2KB_RAM_BASE                  (0x00007400)
#define     NCP_NCA_MTP_MQG_COUNT_2KB_RAM(n)                    (0x00007400 + (4*(n)))
#define     NCP_NCA_MTP_MQG_COUNT_2KB_RAM_COUNT                 (0x000000c0)
#define     NCP_NCA_MTP_MQG_COUNT_2KB_RAM_IDX(addr) \
          (((addr) - NCP_NCA_MTP_MQG_COUNT_2KB_RAM_BASE) / 4)
#define     NCP_NCA_MTP_MQG_COUNT_2KB_RAM_END                   (0x00007700)
#define     NCP_NCA_MTP_MQG_COUNT_2KB_RAM_RANGE(addr) \
       (((addr) >= NCP_NCA_MTP_MQG_COUNT_2KB_RAM_BASE) && \
       ((addr) < NCP_NCA_MTP_MQG_COUNT_2KB_RAM_END))


#define     NCP_NCA_MTP_MQG_COUNT_16KB_RAM_BASE                 (0x00007800)
#define     NCP_NCA_MTP_MQG_COUNT_16KB_RAM(n)                   (0x00007800 + (4*(n)))
#define     NCP_NCA_MTP_MQG_COUNT_16KB_RAM_COUNT                (0x000000c0)
#define     NCP_NCA_MTP_MQG_COUNT_16KB_RAM_IDX(addr) \
         (((addr) - NCP_NCA_MTP_MQG_COUNT_16KB_RAM_BASE) / 4)
#define     NCP_NCA_MTP_MQG_COUNT_16KB_RAM_END                  (0x00007b00)
#define     NCP_NCA_MTP_MQG_COUNT_16KB_RAM_RANGE(addr) \
      (((addr) >= NCP_NCA_MTP_MQG_COUNT_16KB_RAM_BASE) && \
      ((addr) < NCP_NCA_MTP_MQG_COUNT_16KB_RAM_END))


#define     NCP_NCA_MTP_MQG_COUNT_64KB_RAM_BASE                 (0x00007c00)
#define     NCP_NCA_MTP_MQG_COUNT_64KB_RAM(n)                   (0x00007c00 + (4*(n)))
#define     NCP_NCA_MTP_MQG_COUNT_64KB_RAM_COUNT                (0x000000c0)
#define     NCP_NCA_MTP_MQG_COUNT_64KB_RAM_IDX(addr) \
         (((addr) - NCP_NCA_MTP_MQG_COUNT_64KB_RAM_BASE) / 4)
#define     NCP_NCA_MTP_MQG_COUNT_64KB_RAM_END                  (0x00007f00)
#define     NCP_NCA_MTP_MQG_COUNT_64KB_RAM_RANGE(addr) \
      (((addr) >= NCP_NCA_MTP_MQG_COUNT_64KB_RAM_BASE) && \
      ((addr) < NCP_NCA_MTP_MQG_COUNT_64KB_RAM_END))


#define     NCP_NCA_MTP_MQG_THRESH_256B_RAM_BASE                (0x00008000)
#define     NCP_NCA_MTP_MQG_THRESH_256B_RAM(n)                  (0x00008000 + (4*(n)))
#define     NCP_NCA_MTP_MQG_THRESH_256B_RAM_COUNT               (0x000000c0)
#define     NCP_NCA_MTP_MQG_THRESH_256B_RAM_IDX(addr) \
        (((addr) - NCP_NCA_MTP_MQG_THRESH_256B_RAM_BASE) / 4)
#define     NCP_NCA_MTP_MQG_THRESH_256B_RAM_END                 (0x00008300)
#define     NCP_NCA_MTP_MQG_THRESH_256B_RAM_RANGE(addr) \
     (((addr) >= NCP_NCA_MTP_MQG_THRESH_256B_RAM_BASE) && \
     ((addr) < NCP_NCA_MTP_MQG_THRESH_256B_RAM_END))


#define     NCP_NCA_MTP_MQG_THRESH_2KB_RAM_BASE                 (0x00008400)
#define     NCP_NCA_MTP_MQG_THRESH_2KB_RAM(n)                   (0x00008400 + (4*(n)))
#define     NCP_NCA_MTP_MQG_THRESH_2KB_RAM_COUNT                (0x000000c0)
#define     NCP_NCA_MTP_MQG_THRESH_2KB_RAM_IDX(addr) \
         (((addr) - NCP_NCA_MTP_MQG_THRESH_2KB_RAM_BASE) / 4)
#define     NCP_NCA_MTP_MQG_THRESH_2KB_RAM_END                  (0x00008700)
#define     NCP_NCA_MTP_MQG_THRESH_2KB_RAM_RANGE(addr) \
      (((addr) >= NCP_NCA_MTP_MQG_THRESH_2KB_RAM_BASE) && \
      ((addr) < NCP_NCA_MTP_MQG_THRESH_2KB_RAM_END))


#define     NCP_NCA_MTP_MQG_THRESH_16KB_RAM_BASE                (0x00008800)
#define     NCP_NCA_MTP_MQG_THRESH_16KB_RAM(n)                  (0x00008800 + (4*(n)))
#define     NCP_NCA_MTP_MQG_THRESH_16KB_RAM_COUNT               (0x000000c0)
#define     NCP_NCA_MTP_MQG_THRESH_16KB_RAM_IDX(addr) \
        (((addr) - NCP_NCA_MTP_MQG_THRESH_16KB_RAM_BASE) / 4)
#define     NCP_NCA_MTP_MQG_THRESH_16KB_RAM_END                 (0x00008b00)
#define     NCP_NCA_MTP_MQG_THRESH_16KB_RAM_RANGE(addr) \
     (((addr) >= NCP_NCA_MTP_MQG_THRESH_16KB_RAM_BASE) && \
     ((addr) < NCP_NCA_MTP_MQG_THRESH_16KB_RAM_END))


#define     NCP_NCA_MTP_MQG_THRESH_64KB_RAM_BASE                (0x00008c00)
#define     NCP_NCA_MTP_MQG_THRESH_64KB_RAM(n)                  (0x00008c00 + (4*(n)))
#define     NCP_NCA_MTP_MQG_THRESH_64KB_RAM_COUNT               (0x000000c0)
#define     NCP_NCA_MTP_MQG_THRESH_64KB_RAM_IDX(addr) \
        (((addr) - NCP_NCA_MTP_MQG_THRESH_64KB_RAM_BASE) / 4)
#define     NCP_NCA_MTP_MQG_THRESH_64KB_RAM_END                 (0x00008f00)
#define     NCP_NCA_MTP_MQG_THRESH_64KB_RAM_RANGE(addr) \
     (((addr) >= NCP_NCA_MTP_MQG_THRESH_64KB_RAM_BASE) && \
     ((addr) < NCP_NCA_MTP_MQG_THRESH_64KB_RAM_END))


#define     NCP_NCA_MTP_DMM_LOOKUP_BASE                         (0x00009000)
#define     NCP_NCA_MTP_DMM_LOOKUP(n)                           (0x00009000 + (4*(n)))
#define     NCP_NCA_MTP_DMM_LOOKUP_COUNT                        (0x00000100)
#define     NCP_NCA_MTP_DMM_LOOKUP_IDX(addr) \
                 (((addr) - NCP_NCA_MTP_DMM_LOOKUP_BASE) / 4)      
#define     NCP_NCA_MTP_DMM_LOOKUP_END                          (0x00009400)
#define     NCP_NCA_MTP_DMM_LOOKUP_RANGE(addr) \
              (((addr) >= NCP_NCA_MTP_DMM_LOOKUP_BASE) && \
                  ((addr) < NCP_NCA_MTP_DMM_LOOKUP_END))


#define     NCP_NCA_MTP_MPCQ_LOOKUP_BASE                        (0x0000a000)
#define     NCP_NCA_MTP_MPCQ_LOOKUP(n)                          (0x0000a000 + (4*(n)))
#define     NCP_NCA_MTP_MPCQ_LOOKUP_COUNT                       (0x00000100)
#define     NCP_NCA_MTP_MPCQ_LOOKUP_IDX(addr) \
                (((addr) - NCP_NCA_MTP_MPCQ_LOOKUP_BASE) / 4)     
#define     NCP_NCA_MTP_MPCQ_LOOKUP_END                         (0x0000a400)
#define     NCP_NCA_MTP_MPCQ_LOOKUP_RANGE(addr) \
             (((addr) >= NCP_NCA_MTP_MPCQ_LOOKUP_BASE) && \
                ((addr) < NCP_NCA_MTP_MPCQ_LOOKUP_END))


#define     NCP_NCA_MTP_HYSTERESIS_RAM_BASE                     (0x0000f000)
#define     NCP_NCA_MTP_HYSTERESIS_RAM(n)                       (0x0000f000 + (4*(n)))
#define     NCP_NCA_MTP_HYSTERESIS_RAM_COUNT                    (0x00000060)
#define     NCP_NCA_MTP_HYSTERESIS_RAM_IDX(addr) \
             (((addr) - NCP_NCA_MTP_HYSTERESIS_RAM_BASE) / 4)  
#define     NCP_NCA_MTP_HYSTERESIS_RAM_END                      (0x0000f180)
#define     NCP_NCA_MTP_HYSTERESIS_RAM_RANGE(addr) \
          (((addr) >= NCP_NCA_MTP_HYSTERESIS_RAM_BASE) && \
          ((addr) < NCP_NCA_MTP_HYSTERESIS_RAM_END))

#define     NCP_NCA_MTP_INTERRUPT_STATUS0                       (0x00000010)
#define     NCP_NCA_MTP_INTERRUPT_STATUS0_SERVICE_MASK          (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_STATUS1                       (0x00000014)
#define     NCP_NCA_MTP_INTERRUPT_STATUS1_ALARM_MASK            (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_STATUS2                       (0x00000018)
#define     NCP_NCA_MTP_INTERRUPT_STATUS2_ALARM_MASK            (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_STATUS3                       (0x0000001c)
#define     NCP_NCA_MTP_INTERRUPT_STATUS3_ALARM_MASK            (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_STATUS4                       (0x00000020)
#define     NCP_NCA_MTP_INTERRUPT_STATUS4_ALARM_MASK            (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_STATUS5                       (0x00000024)
#define     NCP_NCA_MTP_INTERRUPT_STATUS5_ALARM_MASK            (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_STATUS6                       (0x00000028)
#define     NCP_NCA_MTP_INTERRUPT_STATUS6_ALARM_MASK            (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_STATUS7                       (0x0000002c)
#define     NCP_NCA_MTP_INTERRUPT_STATUS7_ALARM_MASK            (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_EN0                           (0x00000030)
#define     NCP_NCA_MTP_INTERRUPT_EN0_SERVICE_MASK              (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_EN1                           (0x00000034)
#define     NCP_NCA_MTP_INTERRUPT_EN1_ALARM_MASK                (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_EN2                           (0x00000038)
#define     NCP_NCA_MTP_INTERRUPT_EN2_ALARM_MASK                (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_EN3                           (0x0000003c)
#define     NCP_NCA_MTP_INTERRUPT_EN3_ALARM_MASK                (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_EN4                           (0x00000040)
#define     NCP_NCA_MTP_INTERRUPT_EN4_ALARM_MASK                (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_EN5                           (0x00000044)
#define     NCP_NCA_MTP_INTERRUPT_EN5_ALARM_MASK                (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_EN6                           (0x00000048)
#define     NCP_NCA_MTP_INTERRUPT_EN6_ALARM_MASK                (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_EN7                           (0x0000004c)
#define     NCP_NCA_MTP_INTERRUPT_EN7_ALARM_MASK                (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_FRC0                          (0x00000050)
#define     NCP_NCA_MTP_INTERRUPT_FRC0_SERVICE_MASK             (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_FRC1                          (0x00000054)
#define     NCP_NCA_MTP_INTERRUPT_FRC1_ALARM_MASK               (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_FRC2                          (0x00000058)
#define     NCP_NCA_MTP_INTERRUPT_FRC2_ALARM_MASK               (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_FRC3                          (0x0000005c)
#define     NCP_NCA_MTP_INTERRUPT_FRC3_ALARM_MASK               (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_FRC4                          (0x00000060)
#define     NCP_NCA_MTP_INTERRUPT_FRC4_ALARM_MASK               (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_FRC5                          (0x00000064)
#define     NCP_NCA_MTP_INTERRUPT_FRC5_ALARM_MASK               (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_FRC6                          (0x00000068)
#define     NCP_NCA_MTP_INTERRUPT_FRC6_ALARM_MASK               (0xffffffff)
#define     NCP_NCA_MTP_INTERRUPT_FRC7                          (0x0000006c)
#define     NCP_NCA_MTP_INTERRUPT_FRC7_ALARM_MASK               (0xffffffff)


#define     NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_0_BASE     (0x00001000)
#define     NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_0(n)       (0x00001000 + (8*(n)))
#define     NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_0_ACCESS_SIZE  (0x00000008) /* Bytes */
#define     NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_0_COUNT    (0x00000060)
#define     NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_0_IDX(addr) \
  (((addr) - NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_0_BASE) / 8)
#define     NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_0_END      (0x00001300)
#define     NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_0_RANGE(addr) \
 (((addr) >= NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_0_BASE) && \
  ((addr) < NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_0_END))



#define     NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_1_BASE     (0x00001400)
#define     NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_1(n)       (0x00001400 + (8*(n)))
#define     NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_1_ACCESS_SIZE  (0x00000008) /* Bytes */
#define     NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_1_COUNT    (0x00000060)
#define     NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_1_IDX(addr) \
  (((addr) - NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_1_BASE) / 8)
#define     NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_1_END      (0x00001700)
#define     NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_1_RANGE(addr) \
 (((addr) >= NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_1_BASE) && \
  ((addr) < NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_1_END))



#define     NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_WRITE_BASE  (0x00001800)
#define     NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_WRITE(n)   (0x00001800 + (8*(n)))
#define     NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_WRITE_ACCESS_SIZE  (0x00000008) /* Bytes */
#define     NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_WRITE_COUNT  (0x00000060)
#define     NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_WRITE_IDX(addr) \
  (((addr) - NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_WRITE_BASE) / 8)
#define     NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_WRITE_END  (0x00001b00)
#define     NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_WRITE_RANGE(addr) \
 (((addr) >= NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_WRITE_BASE) && \
  ((addr) < NCP_NCA_MTP_PREFETCH_FIFO_CFG_RAM_STRIPE_WRITE_END))



#define     NCP_NCA_MTP_MPCQ_ALLOC_ADDRCONVERT_POOL_BASE        (0x0000b000)
#define     NCP_NCA_MTP_MPCQ_ALLOC_ADDRCONVERT_POOL(n)          (0x0000b000 + (32*(n)))
#define     NCP_NCA_MTP_MPCQ_ALLOC_ADDRCONVERT_POOL_ACCESS_SIZE  (0x00000020) /* Bytes */
#define     NCP_NCA_MTP_MPCQ_ALLOC_ADDRCONVERT_POOL_COUNT       (0x00000008)
#define     NCP_NCA_MTP_MPCQ_ALLOC_ADDRCONVERT_POOL_IDX(addr) \
  (((addr) - NCP_NCA_MTP_MPCQ_ALLOC_ADDRCONVERT_POOL_BASE) / 32)
#define     NCP_NCA_MTP_MPCQ_ALLOC_ADDRCONVERT_POOL_END         (0x0000b100)
#define     NCP_NCA_MTP_MPCQ_ALLOC_ADDRCONVERT_POOL_RANGE(addr) \
 (((addr) >= NCP_NCA_MTP_MPCQ_ALLOC_ADDRCONVERT_POOL_BASE) && \
  ((addr) < NCP_NCA_MTP_MPCQ_ALLOC_ADDRCONVERT_POOL_END))



#define     NCP_NCA_MTP_DMM_ALLOC_ADDRCONVERT_POOL_BASE         (0x0000b200)
#define     NCP_NCA_MTP_DMM_ALLOC_ADDRCONVERT_POOL(n)           (0x0000b200 + (32*(n)))
#define     NCP_NCA_MTP_DMM_ALLOC_ADDRCONVERT_POOL_ACCESS_SIZE  (0x00000020) /* Bytes */
#define     NCP_NCA_MTP_DMM_ALLOC_ADDRCONVERT_POOL_COUNT        (0x00000008)
#define     NCP_NCA_MTP_DMM_ALLOC_ADDRCONVERT_POOL_IDX(addr) \
  (((addr) - NCP_NCA_MTP_DMM_ALLOC_ADDRCONVERT_POOL_BASE) / 32)
#define     NCP_NCA_MTP_DMM_ALLOC_ADDRCONVERT_POOL_END          (0x0000b300)
#define     NCP_NCA_MTP_DMM_ALLOC_ADDRCONVERT_POOL_RANGE(addr) \
 (((addr) >= NCP_NCA_MTP_DMM_ALLOC_ADDRCONVERT_POOL_BASE) && \
  ((addr) < NCP_NCA_MTP_DMM_ALLOC_ADDRCONVERT_POOL_END))



#define     NCP_NCA_MTP_MPCQ_ALLOC_ADDRCONVERT_TRANSLATE_BASE   (0x0000c000)
#define     NCP_NCA_MTP_MPCQ_ALLOC_ADDRCONVERT_TRANSLATE(n)     (0x0000c000 + (8*(n)))
#define     NCP_NCA_MTP_MPCQ_ALLOC_ADDRCONVERT_TRANSLATE_ACCESS_SIZE  (0x00000008) /* Bytes */
#define     NCP_NCA_MTP_MPCQ_ALLOC_ADDRCONVERT_TRANSLATE_COUNT  (0x00000080)
#define     NCP_NCA_MTP_MPCQ_ALLOC_ADDRCONVERT_TRANSLATE_IDX(addr) \
  (((addr) - NCP_NCA_MTP_MPCQ_ALLOC_ADDRCONVERT_TRANSLATE_BASE) / 8)
#define     NCP_NCA_MTP_MPCQ_ALLOC_ADDRCONVERT_TRANSLATE_END    (0x0000c400)
#define     NCP_NCA_MTP_MPCQ_ALLOC_ADDRCONVERT_TRANSLATE_RANGE(addr) \
 (((addr) >= NCP_NCA_MTP_MPCQ_ALLOC_ADDRCONVERT_TRANSLATE_BASE) && \
  ((addr) < NCP_NCA_MTP_MPCQ_ALLOC_ADDRCONVERT_TRANSLATE_END))



#define     NCP_NCA_MTP_DMM_ALLOC_ADDRCONVERT_TRANSLATE_BASE    (0x0000c800)
#define     NCP_NCA_MTP_DMM_ALLOC_ADDRCONVERT_TRANSLATE(n)      (0x0000c800 + (8*(n)))
#define     NCP_NCA_MTP_DMM_ALLOC_ADDRCONVERT_TRANSLATE_ACCESS_SIZE  (0x00000008) /* Bytes */
#define     NCP_NCA_MTP_DMM_ALLOC_ADDRCONVERT_TRANSLATE_COUNT   (0x00000080)
#define     NCP_NCA_MTP_DMM_ALLOC_ADDRCONVERT_TRANSLATE_IDX(addr) \
  (((addr) - NCP_NCA_MTP_DMM_ALLOC_ADDRCONVERT_TRANSLATE_BASE) / 8)
#define     NCP_NCA_MTP_DMM_ALLOC_ADDRCONVERT_TRANSLATE_END     (0x0000cc00)
#define     NCP_NCA_MTP_DMM_ALLOC_ADDRCONVERT_TRANSLATE_RANGE(addr) \
 (((addr) >= NCP_NCA_MTP_DMM_ALLOC_ADDRCONVERT_TRANSLATE_BASE) && \
  ((addr) < NCP_NCA_MTP_DMM_ALLOC_ADDRCONVERT_TRANSLATE_END))



#define     NCP_NCA_MTP_DMM_DEALLOC_ADDRCONVERT_POOL_BASE       (0x0000d000)
#define     NCP_NCA_MTP_DMM_DEALLOC_ADDRCONVERT_POOL(n)         (0x0000d000 + (32*(n)))
#define     NCP_NCA_MTP_DMM_DEALLOC_ADDRCONVERT_POOL_ACCESS_SIZE  (0x00000020) /* Bytes */
#define     NCP_NCA_MTP_DMM_DEALLOC_ADDRCONVERT_POOL_COUNT      (0x00000008)
#define     NCP_NCA_MTP_DMM_DEALLOC_ADDRCONVERT_POOL_IDX(addr) \
  (((addr) - NCP_NCA_MTP_DMM_DEALLOC_ADDRCONVERT_POOL_BASE) / 32)
#define     NCP_NCA_MTP_DMM_DEALLOC_ADDRCONVERT_POOL_END        (0x0000d100)
#define     NCP_NCA_MTP_DMM_DEALLOC_ADDRCONVERT_POOL_RANGE(addr) \
 (((addr) >= NCP_NCA_MTP_DMM_DEALLOC_ADDRCONVERT_POOL_BASE) && \
  ((addr) < NCP_NCA_MTP_DMM_DEALLOC_ADDRCONVERT_POOL_END))



#define     NCP_NCA_MTP_DMM_DEALLOC_ADDRCONVERT_TRANSLATE_BASE  (0x0000e000)
#define     NCP_NCA_MTP_DMM_DEALLOC_ADDRCONVERT_TRANSLATE(n)    (0x0000e000 + (8*(n)))
#define     NCP_NCA_MTP_DMM_DEALLOC_ADDRCONVERT_TRANSLATE_ACCESS_SIZE  (0x00000008) /* Bytes */
#define     NCP_NCA_MTP_DMM_DEALLOC_ADDRCONVERT_TRANSLATE_COUNT  (0x00000080)
#define     NCP_NCA_MTP_DMM_DEALLOC_ADDRCONVERT_TRANSLATE_IDX(addr) \
  (((addr) - NCP_NCA_MTP_DMM_DEALLOC_ADDRCONVERT_TRANSLATE_BASE) / 8)
#define     NCP_NCA_MTP_DMM_DEALLOC_ADDRCONVERT_TRANSLATE_END   (0x0000e400)
#define     NCP_NCA_MTP_DMM_DEALLOC_ADDRCONVERT_TRANSLATE_RANGE(addr) \
 (((addr) >= NCP_NCA_MTP_DMM_DEALLOC_ADDRCONVERT_TRANSLATE_BASE) && \
  ((addr) < NCP_NCA_MTP_DMM_DEALLOC_ADDRCONVERT_TRANSLATE_END))

#ifdef __cplusplus
}
#endif

#endif /* _NCP_NCA_MTP_REG_DEFINES_H_ */
