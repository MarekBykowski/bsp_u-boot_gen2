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


#ifndef _NCP_NLINK_IPCQ_RSP_REG_DEFINES_H_
#define _NCP_NLINK_IPCQ_RSP_REG_DEFINES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"


    /* NODE 0x0 , TARGET 0xffffffff*/


#define     NCP_NLINK_IPCQ_RSP_CTL                              (0x00000100)
#define     NCP_NLINK_IPCQ_RSP_ACCESS_RATE                      (0x00000104)
#define     NCP_NLINK_IPCQ_RSP_XFACE_CTL                        (0x00000108)
#define     NCP_NLINK_IPCQ_RSP_S_AXI_STATUS                     (0x00000200)
#define     NCP_NLINK_IPCQ_RSP_M_AXI_STATUS                     (0x00000204)
#define     NCP_NLINK_IPCQ_RSP_LOQC0_FIFO_STAT                  (0x00000400)
#define     NCP_NLINK_IPCQ_RSP_LOQC0_FIFO_WM                    (0x00000404)
#define     NCP_NLINK_IPCQ_RSP_LINK_PACKET_DATA_FIFO0_FIFO_STAT  (0x00000600)
#define     NCP_NLINK_IPCQ_RSP_LINK_PACKET_DATA_FIFO0_FIFO_WM   (0x00000604)
#define     NCP_NLINK_IPCQ_RSP_MESSAGE_OUTPUT_QUEUE_CREDIT_FIFO_FIFO_STAT  (0x00000800)
#define     NCP_NLINK_IPCQ_RSP_MESSAGE_OUTPUT_QUEUE_CREDIT_FIFO_FIFO_WM  (0x00000804)
#define     NCP_NLINK_IPCQ_RSP_SLAVE_WRITE_REQUEST_FIFO_FIFO_STAT  (0x00000808)
#define     NCP_NLINK_IPCQ_RSP_SLAVE_WRITE_REQUEST_FIFO_FIFO_WM  (0x0000080c)
#define     NCP_NLINK_IPCQ_RSP_SLAVE_WRITE_DATA_FIFO_FIFO_STAT  (0x00000810)
#define     NCP_NLINK_IPCQ_RSP_SLAVE_WRITE_DATA_FIFO_FIFO_WM    (0x00000814)
#define     NCP_NLINK_IPCQ_RSP_SLAVE_WRITE_RESPONSE_FIFO_FIFO_STAT  (0x00000818)
#define     NCP_NLINK_IPCQ_RSP_SLAVE_WRITE_RESPONSE_FIFO_FIFO_WM  (0x0000081c)
#define     NCP_NLINK_IPCQ_RSP_MASTER_WRITE_REQUEST_FIFO_FIFO_STAT  (0x00000820)
#define     NCP_NLINK_IPCQ_RSP_MASTER_WRITE_REQUEST_FIFO_FIFO_WM  (0x00000824)
#define     NCP_NLINK_IPCQ_RSP_MASTER_WRITE_DATA_FIFO_FIFO_STAT  (0x00000828)
#define     NCP_NLINK_IPCQ_RSP_MASTER_WRITE_DATA_FIFO_FIFO_WM   (0x0000082c)
#define     NCP_NLINK_IPCQ_RSP_MASTER_WRITE_RESPONSE_FIFO_FIFO_STAT  (0x00000830)
#define     NCP_NLINK_IPCQ_RSP_MASTER_WRITE_RESPONSE_FIFO_FIFO_WM  (0x00000834)
#define     NCP_NLINK_IPCQ_RSP_SLAVE_AW_DBL_BUFFER_STATUS       (0x00000900)
#define     NCP_NLINK_IPCQ_RSP_SLAVE_WC_DBL_BUFFER_STATUS       (0x00000904)
#define     NCP_NLINK_IPCQ_RSP_MASTER_AW_DBL_BUFFER_STATUS      (0x00000908)
#define     NCP_NLINK_IPCQ_RSP_MASTER_W_DBL_BUFFER_STATUS       (0x0000090c)
#define     NCP_NLINK_IPCQ_RSP_MASTER_BRESP_DBL_BUFFER_STATUS   (0x00000910)
#define     NCP_NLINK_IPCQ_RSP_LPD_FIFO_DBL_BUFFER_STATUS       (0x00000a00)
#define     NCP_NLINK_IPCQ_RSP_AW_SMON00_NLINK                  (0x00000b00)
#define     NCP_NLINK_IPCQ_RSP_AW_SMON01_NLINK                  (0x00000b04)
#define     NCP_NLINK_IPCQ_RSP_AW_SMON02_NLINK                  (0x00000b08)
#define     NCP_NLINK_IPCQ_RSP_AW_SMON03_NLINK                  (0x00000b0c)
#define     NCP_NLINK_IPCQ_RSP_AW_SMON04_NLINK                  (0x00000b10)
#define     NCP_NLINK_IPCQ_RSP_AW_SMON05_NLINK                  (0x00000b14)
#define     NCP_NLINK_IPCQ_RSP_AW_SMON06_NLINK                  (0x00000b18)
#define     NCP_NLINK_IPCQ_RSP_AW_SMON07_NLINK                  (0x00000b1c)
#define     NCP_NLINK_IPCQ_RSP_LPI_HIST_CNT                     (0x00000c00)
#define     NCP_NLINK_IPCQ_RSP_LPI_SETUP_CNT                    (0x00000c04)
#define     NCP_NLINK_IPCQ_RSP_AW_PEVLPI_STATUS                 (0x00000c10)
#define     NCP_NLINK_IPCQ_RSP_AW_NEXTLPI_STATUS                (0x00000c14)
#define     NCP_NLINK_IPCQ_RSP_OVERFLOW_UNDERFLOW_STATUS        (0x00000c18)
#define     NCP_NLINK_IPCQ_RSP_CORE_ERROR_STATUS                (0x00000c1c)
#define     NCP_NLINK_IPCQ_RSP_INT_STATUS                       (0x00000010)
#define     NCP_NLINK_IPCQ_RSP_INT_STATUS_ALARM_MASK            (0x000003fe)
#define     NCP_NLINK_IPCQ_RSP_INT_STATUS_SERVICE_MASK          (0x00000001)
#define     NCP_NLINK_IPCQ_RSP_INT_EN                           (0x00000014)
#define     NCP_NLINK_IPCQ_RSP_INT_EN_ALARM_MASK                (0x000003fe)
#define     NCP_NLINK_IPCQ_RSP_INT_EN_SERVICE_MASK              (0x00000001)
#define     NCP_NLINK_IPCQ_RSP_INT_FRC                          (0x00000018)
#define     NCP_NLINK_IPCQ_RSP_INT_FRC_ALARM_MASK               (0x000003fe)
#define     NCP_NLINK_IPCQ_RSP_INT_FRC_SERVICE_MASK             (0x00000001)
#ifdef __cplusplus
}
#endif

#endif /* _NCP_NLINK_IPCQ_RSP_REG_DEFINES_H_ */
