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


#ifndef _NCP_NCA_ITP_REGS_H_
#define _NCP_NCA_ITP_REGS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"

/*! @struct ncp_nca_itp_interface_0000_r_t
 *  @brief null
 *  @details CFG access to Interface Activity. Read the current value of interface.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interface_0000_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param if_31 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> itp_system_cwd_ready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_30 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> itp_system_cwd_valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_29 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> itp_system_cwd_valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_28 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> itp_system_cwd_valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_27 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> itp_system_cwr_ready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_26 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> itp_system_cwr_ready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_25 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> itp_system_cwr_ready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_24 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> itp_system_cwr_valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_23 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> itp_system_cwr_valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_22 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> itp_system_cwr_valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_21 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> ncav3_ipcq_res_bready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_20 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> ncav3_ipcq_res_bvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_19 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> ncav3_ipcq_res_wready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_18 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> ncav3_ipcq_res_wvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_17 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> ncav3_ipcq_res_awready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_16 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> ncav3_ipcq_res_awvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_15 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> ncav3_ipcq_req_bready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_14 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> ncav3_ipcq_req_bvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_13 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> ncav3_ipcq_req_wready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_12 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> ncav3_ipcq_req_wvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_11 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> ncav3_ipcq_req_awready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_10 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> ncav3_ipcq_req_awvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_09 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_08 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_07 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_06 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_05 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_04 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_03 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_02 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_01 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_00 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> null </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interface_0000_r_t
 *
 * Implemented by: 
 *      interface_0000
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      if_31                                     :  1;
     unsigned      if_30                                     :  1;
     unsigned      if_29                                     :  1;
     unsigned      if_28                                     :  1;
     unsigned      if_27                                     :  1;
     unsigned      if_26                                     :  1;
     unsigned      if_25                                     :  1;
     unsigned      if_24                                     :  1;
     unsigned      if_23                                     :  1;
     unsigned      if_22                                     :  1;
     unsigned      if_21                                     :  1;
     unsigned      if_20                                     :  1;
     unsigned      if_19                                     :  1;
     unsigned      if_18                                     :  1;
     unsigned      if_17                                     :  1;
     unsigned      if_16                                     :  1;
     unsigned      if_15                                     :  1;
     unsigned      if_14                                     :  1;
     unsigned      if_13                                     :  1;
     unsigned      if_12                                     :  1;
     unsigned      if_11                                     :  1;
     unsigned      if_10                                     :  1;
     unsigned      if_09                                     :  1;
     unsigned      if_08                                     :  1;
     unsigned      if_07                                     :  1;
     unsigned      if_06                                     :  1;
     unsigned      if_05                                     :  1;
     unsigned      if_04                                     :  1;
     unsigned      if_03                                     :  1;
     unsigned      if_02                                     :  1;
     unsigned      if_01                                     :  1;
     unsigned      if_00                                     :  1;
#else    /* Little Endian */
     unsigned      if_00                                     :  1;
     unsigned      if_01                                     :  1;
     unsigned      if_02                                     :  1;
     unsigned      if_03                                     :  1;
     unsigned      if_04                                     :  1;
     unsigned      if_05                                     :  1;
     unsigned      if_06                                     :  1;
     unsigned      if_07                                     :  1;
     unsigned      if_08                                     :  1;
     unsigned      if_09                                     :  1;
     unsigned      if_10                                     :  1;
     unsigned      if_11                                     :  1;
     unsigned      if_12                                     :  1;
     unsigned      if_13                                     :  1;
     unsigned      if_14                                     :  1;
     unsigned      if_15                                     :  1;
     unsigned      if_16                                     :  1;
     unsigned      if_17                                     :  1;
     unsigned      if_18                                     :  1;
     unsigned      if_19                                     :  1;
     unsigned      if_20                                     :  1;
     unsigned      if_21                                     :  1;
     unsigned      if_22                                     :  1;
     unsigned      if_23                                     :  1;
     unsigned      if_24                                     :  1;
     unsigned      if_25                                     :  1;
     unsigned      if_26                                     :  1;
     unsigned      if_27                                     :  1;
     unsigned      if_28                                     :  1;
     unsigned      if_29                                     :  1;
     unsigned      if_30                                     :  1;
     unsigned      if_31                                     :  1;
#endif
} ncp_nca_itp_interface_0000_r_t;

/*! @struct ncp_nca_itp_interface_0020_r_t
 *  @brief null
 *  @details CFG access to Interface Activity. Read the current value of interface.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interface_0020_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param if_63 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> otp_itp_tx_wready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_62 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> otp_itp_tx_wvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_61 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> otp_itp_tx_awready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_60 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> otp_itp_tx_awvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_59 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> itp_mtp_tx_bready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_58 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> itp_mtp_tx_bvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_57 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> itp_mtp_tx_wready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_56 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> itp_mtp_tx_wvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_55 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> itp_mtp_tx_awready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_54 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> itp_mtp_tx_awvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_53 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> itp_mtp_req_rready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_52 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> itp_mtp_req_rvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_51 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> itp_mtp_req_arready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_50 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> itp_mtp_req_arvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_49 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> eng_til_ret_bp_p0 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_48 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> til_eng_ret_v_p0 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_47 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> til_eng_bp_p0 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_46 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> eng_til_v_p0 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_45 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> tcl_eng_bpvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_44 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> tram_eng_ret_v </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_43 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> tram_eng_bp </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_42 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> eng_tram_v </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_41 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> til_eng_del_bp </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_40 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> eng_til_del_v </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_39 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> |eng_til_start_bp </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_38 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> til_start_ptr_v </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_37 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> til_start_v </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_36 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> itp_system_cwa_valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_35 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> itp_system_cwa_valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_34 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> itp_system_cwa_valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_33 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> itp_system_cwd_ready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_32 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> itp_system_cwd_ready </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interface_0020_r_t
 *
 * Implemented by: 
 *      interface_0020
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      if_63                                     :  1;
     unsigned      if_62                                     :  1;
     unsigned      if_61                                     :  1;
     unsigned      if_60                                     :  1;
     unsigned      if_59                                     :  1;
     unsigned      if_58                                     :  1;
     unsigned      if_57                                     :  1;
     unsigned      if_56                                     :  1;
     unsigned      if_55                                     :  1;
     unsigned      if_54                                     :  1;
     unsigned      if_53                                     :  1;
     unsigned      if_52                                     :  1;
     unsigned      if_51                                     :  1;
     unsigned      if_50                                     :  1;
     unsigned      if_49                                     :  1;
     unsigned      if_48                                     :  1;
     unsigned      if_47                                     :  1;
     unsigned      if_46                                     :  1;
     unsigned      if_45                                     :  1;
     unsigned      if_44                                     :  1;
     unsigned      if_43                                     :  1;
     unsigned      if_42                                     :  1;
     unsigned      if_41                                     :  1;
     unsigned      if_40                                     :  1;
     unsigned      if_39                                     :  1;
     unsigned      if_38                                     :  1;
     unsigned      if_37                                     :  1;
     unsigned      if_36                                     :  1;
     unsigned      if_35                                     :  1;
     unsigned      if_34                                     :  1;
     unsigned      if_33                                     :  1;
     unsigned      if_32                                     :  1;
#else    /* Little Endian */
     unsigned      if_32                                     :  1;
     unsigned      if_33                                     :  1;
     unsigned      if_34                                     :  1;
     unsigned      if_35                                     :  1;
     unsigned      if_36                                     :  1;
     unsigned      if_37                                     :  1;
     unsigned      if_38                                     :  1;
     unsigned      if_39                                     :  1;
     unsigned      if_40                                     :  1;
     unsigned      if_41                                     :  1;
     unsigned      if_42                                     :  1;
     unsigned      if_43                                     :  1;
     unsigned      if_44                                     :  1;
     unsigned      if_45                                     :  1;
     unsigned      if_46                                     :  1;
     unsigned      if_47                                     :  1;
     unsigned      if_48                                     :  1;
     unsigned      if_49                                     :  1;
     unsigned      if_50                                     :  1;
     unsigned      if_51                                     :  1;
     unsigned      if_52                                     :  1;
     unsigned      if_53                                     :  1;
     unsigned      if_54                                     :  1;
     unsigned      if_55                                     :  1;
     unsigned      if_56                                     :  1;
     unsigned      if_57                                     :  1;
     unsigned      if_58                                     :  1;
     unsigned      if_59                                     :  1;
     unsigned      if_60                                     :  1;
     unsigned      if_61                                     :  1;
     unsigned      if_62                                     :  1;
     unsigned      if_63                                     :  1;
#endif
} ncp_nca_itp_interface_0020_r_t;

/*! @struct ncp_nca_itp_interface_0040_r_t
 *  @brief null
 *  @details CFG access to Interface Activity. Read the current value of interface.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interface_0040_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param if_95 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_94 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_93 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_92 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_91 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_90 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_89 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_88 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_87 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_86 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_85 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_84 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_83 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> trace_data_bready1 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_82 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> trace_data_bvalid1 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_81 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> trace_data_wready1 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_80 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> trace_data_wvalid1 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_79 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> trace_data_awready1 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_78 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> trace_data_awvalid1 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_77 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> trace_data_bready0 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_76 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> trace_data_bvalid0 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_75 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> trace_data_wready0 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_74 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> trace_data_wvalid0 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_73 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> trace_data_awready0 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_72 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> trace_data_awvalid0 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_71 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> qpm_bready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_70 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> qpm_bvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_69 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> qpm_wready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_68 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> qpm_wvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_67 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> qpm_awready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_66 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> qpm_awvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_65 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> otp_itp_tx_bready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_64 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> otp_itp_tx_bvalid </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interface_0040_r_t
 *
 * Implemented by: 
 *      interface_0040
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      if_95                                     :  1;
     unsigned      if_94                                     :  1;
     unsigned      if_93                                     :  1;
     unsigned      if_92                                     :  1;
     unsigned      if_91                                     :  1;
     unsigned      if_90                                     :  1;
     unsigned      if_89                                     :  1;
     unsigned      if_88                                     :  1;
     unsigned      if_87                                     :  1;
     unsigned      if_86                                     :  1;
     unsigned      if_85                                     :  1;
     unsigned      if_84                                     :  1;
     unsigned      if_83                                     :  1;
     unsigned      if_82                                     :  1;
     unsigned      if_81                                     :  1;
     unsigned      if_80                                     :  1;
     unsigned      if_79                                     :  1;
     unsigned      if_78                                     :  1;
     unsigned      if_77                                     :  1;
     unsigned      if_76                                     :  1;
     unsigned      if_75                                     :  1;
     unsigned      if_74                                     :  1;
     unsigned      if_73                                     :  1;
     unsigned      if_72                                     :  1;
     unsigned      if_71                                     :  1;
     unsigned      if_70                                     :  1;
     unsigned      if_69                                     :  1;
     unsigned      if_68                                     :  1;
     unsigned      if_67                                     :  1;
     unsigned      if_66                                     :  1;
     unsigned      if_65                                     :  1;
     unsigned      if_64                                     :  1;
#else    /* Little Endian */
     unsigned      if_64                                     :  1;
     unsigned      if_65                                     :  1;
     unsigned      if_66                                     :  1;
     unsigned      if_67                                     :  1;
     unsigned      if_68                                     :  1;
     unsigned      if_69                                     :  1;
     unsigned      if_70                                     :  1;
     unsigned      if_71                                     :  1;
     unsigned      if_72                                     :  1;
     unsigned      if_73                                     :  1;
     unsigned      if_74                                     :  1;
     unsigned      if_75                                     :  1;
     unsigned      if_76                                     :  1;
     unsigned      if_77                                     :  1;
     unsigned      if_78                                     :  1;
     unsigned      if_79                                     :  1;
     unsigned      if_80                                     :  1;
     unsigned      if_81                                     :  1;
     unsigned      if_82                                     :  1;
     unsigned      if_83                                     :  1;
     unsigned      if_84                                     :  1;
     unsigned      if_85                                     :  1;
     unsigned      if_86                                     :  1;
     unsigned      if_87                                     :  1;
     unsigned      if_88                                     :  1;
     unsigned      if_89                                     :  1;
     unsigned      if_90                                     :  1;
     unsigned      if_91                                     :  1;
     unsigned      if_92                                     :  1;
     unsigned      if_93                                     :  1;
     unsigned      if_94                                     :  1;
     unsigned      if_95                                     :  1;
#endif
} ncp_nca_itp_interface_0040_r_t;

/*! @struct ncp_nca_itp_interrupt0_status_r_t
 *  @brief Interrupt Status Register
 *  @details This register holds interrupt status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt0_status_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int31 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> cfg_smon_int Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int30 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> cfg_synd_status_int Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int29 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> task Copied Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int28 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> NLINK parity error observed Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int27 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> db_in_qpm_qstatus_ready=0. QPM should not drop this
 *        ready, this is HW misconnect or QPM error Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int26 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> MTP returns a ERROR response Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int25 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> MTP returns a NACK response Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int24 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> err_completion_check_opcq. When aPCQ task is returned
 *        the sequence number does not match the stored task.
 *        THis can occur when task with task completion are
 *        returned out of order or are missing/duplicated. Causes
 *        system corruption Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int23 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> err_completion_check_apcq. When aPCQ task is returned
 *        the sequence number does not match the stored task.
 *        THis can occur when task with consumer pointer advance
 *        are returned out of order or are missing/duplicated.
 *        Causes system corruption Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int22 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> err_ieordready_empty. When scheduling a iPCQ & GID
 *        selected Ordered-Ready that have no task avaible.
 *        deselect the iPCQ & GID, Clean up state and return
 *        to begining of scheduling. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int21 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> err_ieordsched_empty. When scheduling a iPCQ & GID
 *        selected Ordered-Scheduled that have no task avaible.
 *        deselect the iPCQ & GID, Clean up state and return
 *        to begining of scheduling. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int20 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> err_schedsort. WHen scheduling a iPCQ & GID selected
 *        flow with all LL empty. THis could result from inconsistency
 *        in config IPC vs ipcq2god. Clean up state and return
 *        to begining of scheduling. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int19 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> err_notqpri. When scheduling a iPCQ & GID selected
 *        flow with no task availble. THis could result from
 *        inconsistency in config IPC vs ipcq2god. Clean up
 *        state and return to begining of scheduling. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int18 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> err_ieunord_empty. When scheduling a iPCQ & GID selected
 *        Unordered that have no task avaible. deselect the
 *        iPCQ & GID, Clean up state and return to begining
 *        of scheduling. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int17 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> err_activitycount. One of the activity counters reported
 *        an error. No recovery possible, must be a misconfigure
 *        of the threshold Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int16 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> AW_fifo FIFO of Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int15 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> err_hitidle. Ordered flow HIT in BCAM and the state
 *        is IDLE. THis is not expected but not illegal, continue
 *        normal operation Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int14 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> err_c_enqcnt_of. ieOrdered state updated during task
 *        completion and overflow of enqueue count. Continue
 *        normal operation Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int13 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> err_c_schcnt_of. ieOrdered state updated during task
 *        completion and overflow of scheduled count. Continue
 *        normal operation Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int12 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> err_s_enqcnt_of. ieOrdered state updated during task
 *        scheudle and overflow of enqueue count. Continue normal
 *        operation Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int11 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> err_s_schcnt_of. ieOrdered state updated during task
 *        scheudle and overflow of scheduled count. Continue
 *        normal operation Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int10 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> err_e_enqcnt_of. ieOrdered state updated during task
 *        enqueue and overflow of enqueue count. Continue normal
 *        operation Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int9 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> err_e_schcnt_of. ieOrdered state updated during task
 *        enqueue and overflow of scheduled count. Continue
 *        normal operation Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int8 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> err_complete_empty. Task completion arrives from OTP
 *        and the NCAP,PGIT list in LL_completion is empty.
 *        drop the reqeust and continue normal operation Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int7 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> err_ieord_empty. When scheduling a iPCQ & GID selected
 *        Ordered that have no task avaible. deselect the iPCQ
 *        & GID, Clean up state and return to begining of scheduling.
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int6 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> err_ord_flowid. After scheduling the flowID popped
 *        from the ieUnordered LL does not match the flowID
 *        from the scheudling (ieOrdReady or ieOrdSched LL).
 *        continue normal operation. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int5 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> err_unord_flowid. After scheduling the flowID popped
 *        from the ieUnordered LL does not match the flowID
 *        from the scheudling. Should always be zero. continue
 *        normal operation. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int4 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> err_dynamic. error triggered during dynamic operation
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int3 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> multi_output_fifo_overflow Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int2 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> multi_output_fifo_underflow Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ncav3_cfg for read_err Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ncav3_cfg write_err Status </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt0_status_r_t
 *
 * Implemented by: 
 *      status0
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int31                                     :  1;
     unsigned      int30                                     :  1;
     unsigned      int29                                     :  1;
     unsigned      int28                                     :  1;
     unsigned      int27                                     :  1;
     unsigned      int26                                     :  1;
     unsigned      int25                                     :  1;
     unsigned      int24                                     :  1;
     unsigned      int23                                     :  1;
     unsigned      int22                                     :  1;
     unsigned      int21                                     :  1;
     unsigned      int20                                     :  1;
     unsigned      int19                                     :  1;
     unsigned      int18                                     :  1;
     unsigned      int17                                     :  1;
     unsigned      int16                                     :  1;
     unsigned      int15                                     :  1;
     unsigned      int14                                     :  1;
     unsigned      int13                                     :  1;
     unsigned      int12                                     :  1;
     unsigned      int11                                     :  1;
     unsigned      int10                                     :  1;
     unsigned      int9                                      :  1;
     unsigned      int8                                      :  1;
     unsigned      int7                                      :  1;
     unsigned      int6                                      :  1;
     unsigned      int5                                      :  1;
     unsigned      int4                                      :  1;
     unsigned      int3                                      :  1;
     unsigned      int2                                      :  1;
     unsigned      int1                                      :  1;
     unsigned      int0                                      :  1;
#else    /* Little Endian */
     unsigned      int0                                      :  1;
     unsigned      int1                                      :  1;
     unsigned      int2                                      :  1;
     unsigned      int3                                      :  1;
     unsigned      int4                                      :  1;
     unsigned      int5                                      :  1;
     unsigned      int6                                      :  1;
     unsigned      int7                                      :  1;
     unsigned      int8                                      :  1;
     unsigned      int9                                      :  1;
     unsigned      int10                                     :  1;
     unsigned      int11                                     :  1;
     unsigned      int12                                     :  1;
     unsigned      int13                                     :  1;
     unsigned      int14                                     :  1;
     unsigned      int15                                     :  1;
     unsigned      int16                                     :  1;
     unsigned      int17                                     :  1;
     unsigned      int18                                     :  1;
     unsigned      int19                                     :  1;
     unsigned      int20                                     :  1;
     unsigned      int21                                     :  1;
     unsigned      int22                                     :  1;
     unsigned      int23                                     :  1;
     unsigned      int24                                     :  1;
     unsigned      int25                                     :  1;
     unsigned      int26                                     :  1;
     unsigned      int27                                     :  1;
     unsigned      int28                                     :  1;
     unsigned      int29                                     :  1;
     unsigned      int30                                     :  1;
     unsigned      int31                                     :  1;
#endif
} ncp_nca_itp_interrupt0_status_r_t;

/*! @struct ncp_nca_itp_interrupt1_status_r_t
 *  @brief Interrupt Status Register
 *  @details This register holds interrupt status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt1_status_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int63 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> drop unscheduled Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int62 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> drop ordered Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int61 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> drop unordered Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int60 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int59 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int58 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int57 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int56 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int55 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int54 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int53 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> SYND21 err_ipcq_credits_of_zero Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int52 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> SYND20 ipcq_multifull_Q Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int51 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> SYND19 ipcq_full_Q Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int50 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> SYND18 err_ipcqsizeof_c1 Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int49 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> SYND17 err_ipcqsizeof_c0 Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int48 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> SYND16 err_ipcqsizeof_e Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int47 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> SYND15 err_ipcq_credits_of_inc Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int46 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> SYND14 err_ipcq_credits_of_dec Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int45 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> SYND13 err_of Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int44 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> SYND12 err_copyerror Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int43 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> SYND11 cam_ieordered_ERROR Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int42 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> SYND10 addrconvert_in_out_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int41 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> SYND09 addrconvert_alloc_out_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int40 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> SYND08 ll_completion_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int39 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> SYND07 ll_ieordsched_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int38 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> SYND06 ll_ieordready_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int37 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> SYND05 ll_ieord_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int36 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> SYND04 ll_ieunord_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int35 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> SYND03 ll_preproc_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int34 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> SYND02 itp_system_error_2 Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int33 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> SYND01 itp_system_error_1 Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int32 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> SYND00 itp_system_error_0 Status </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt1_status_r_t
 *
 * Implemented by: 
 *      status1
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int63                                     :  1;
     unsigned      int62                                     :  1;
     unsigned      int61                                     :  1;
     unsigned      int60                                     :  1;
     unsigned      int59                                     :  1;
     unsigned      int58                                     :  1;
     unsigned      int57                                     :  1;
     unsigned      int56                                     :  1;
     unsigned      int55                                     :  1;
     unsigned      int54                                     :  1;
     unsigned      int53                                     :  1;
     unsigned      int52                                     :  1;
     unsigned      int51                                     :  1;
     unsigned      int50                                     :  1;
     unsigned      int49                                     :  1;
     unsigned      int48                                     :  1;
     unsigned      int47                                     :  1;
     unsigned      int46                                     :  1;
     unsigned      int45                                     :  1;
     unsigned      int44                                     :  1;
     unsigned      int43                                     :  1;
     unsigned      int42                                     :  1;
     unsigned      int41                                     :  1;
     unsigned      int40                                     :  1;
     unsigned      int39                                     :  1;
     unsigned      int38                                     :  1;
     unsigned      int37                                     :  1;
     unsigned      int36                                     :  1;
     unsigned      int35                                     :  1;
     unsigned      int34                                     :  1;
     unsigned      int33                                     :  1;
     unsigned      int32                                     :  1;
#else    /* Little Endian */
     unsigned      int32                                     :  1;
     unsigned      int33                                     :  1;
     unsigned      int34                                     :  1;
     unsigned      int35                                     :  1;
     unsigned      int36                                     :  1;
     unsigned      int37                                     :  1;
     unsigned      int38                                     :  1;
     unsigned      int39                                     :  1;
     unsigned      int40                                     :  1;
     unsigned      int41                                     :  1;
     unsigned      int42                                     :  1;
     unsigned      int43                                     :  1;
     unsigned      int44                                     :  1;
     unsigned      int45                                     :  1;
     unsigned      int46                                     :  1;
     unsigned      int47                                     :  1;
     unsigned      int48                                     :  1;
     unsigned      int49                                     :  1;
     unsigned      int50                                     :  1;
     unsigned      int51                                     :  1;
     unsigned      int52                                     :  1;
     unsigned      int53                                     :  1;
     unsigned      int54                                     :  1;
     unsigned      int55                                     :  1;
     unsigned      int56                                     :  1;
     unsigned      int57                                     :  1;
     unsigned      int58                                     :  1;
     unsigned      int59                                     :  1;
     unsigned      int60                                     :  1;
     unsigned      int61                                     :  1;
     unsigned      int62                                     :  1;
     unsigned      int63                                     :  1;
#endif
} ncp_nca_itp_interrupt1_status_r_t;

/*! @struct ncp_nca_itp_interrupt2_status_r_t
 *  @brief Interrupt Status Register
 *  @details This register holds interrupt status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt2_status_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int95 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> ll_completion_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int94 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> ll_ieordsched_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int93 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> ll_ieordsched_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int92 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> ll_ieordsched_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int91 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> ll_ieordsched_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int90 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> ll_ieordready_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int89 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> ll_ieordready_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int88 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> ll_ieordready_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int87 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> ll_ieordready_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int86 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> ll_ieord_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int85 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> ll_ieord_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int84 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> ll_ieord_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int83 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> ll_ieord_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int82 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> ll_ieunord_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int81 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> ll_ieunord_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int80 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> ll_ieunord_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int79 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> ll_ieunord_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int78 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> ll_preproc_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int77 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> ll_preproc_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int76 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> ll_preproc_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int75 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> ll_preproc_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int74 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> addrconvert_in_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int73 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> addrconvert_in_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int72 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> addrconvert_alloc_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int71 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> addrconvert_alloc_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int70 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ram_tqbp_pertq0_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int69 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> ram_tqbp_pertq0thresh_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int68 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> ram_ncap2ipcq_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int67 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> ram_gid2tq access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int66 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> ram_ieordered_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int65 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ram_ipd_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int64 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ram_tpd_error access error Status </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt2_status_r_t
 *
 * Implemented by: 
 *      status2
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int95                                     :  1;
     unsigned      int94                                     :  1;
     unsigned      int93                                     :  1;
     unsigned      int92                                     :  1;
     unsigned      int91                                     :  1;
     unsigned      int90                                     :  1;
     unsigned      int89                                     :  1;
     unsigned      int88                                     :  1;
     unsigned      int87                                     :  1;
     unsigned      int86                                     :  1;
     unsigned      int85                                     :  1;
     unsigned      int84                                     :  1;
     unsigned      int83                                     :  1;
     unsigned      int82                                     :  1;
     unsigned      int81                                     :  1;
     unsigned      int80                                     :  1;
     unsigned      int79                                     :  1;
     unsigned      int78                                     :  1;
     unsigned      int77                                     :  1;
     unsigned      int76                                     :  1;
     unsigned      int75                                     :  1;
     unsigned      int74                                     :  1;
     unsigned      int73                                     :  1;
     unsigned      int72                                     :  1;
     unsigned      int71                                     :  1;
     unsigned      int70                                     :  1;
     unsigned      int69                                     :  1;
     unsigned      int68                                     :  1;
     unsigned      int67                                     :  1;
     unsigned      int66                                     :  1;
     unsigned      int65                                     :  1;
     unsigned      int64                                     :  1;
#else    /* Little Endian */
     unsigned      int64                                     :  1;
     unsigned      int65                                     :  1;
     unsigned      int66                                     :  1;
     unsigned      int67                                     :  1;
     unsigned      int68                                     :  1;
     unsigned      int69                                     :  1;
     unsigned      int70                                     :  1;
     unsigned      int71                                     :  1;
     unsigned      int72                                     :  1;
     unsigned      int73                                     :  1;
     unsigned      int74                                     :  1;
     unsigned      int75                                     :  1;
     unsigned      int76                                     :  1;
     unsigned      int77                                     :  1;
     unsigned      int78                                     :  1;
     unsigned      int79                                     :  1;
     unsigned      int80                                     :  1;
     unsigned      int81                                     :  1;
     unsigned      int82                                     :  1;
     unsigned      int83                                     :  1;
     unsigned      int84                                     :  1;
     unsigned      int85                                     :  1;
     unsigned      int86                                     :  1;
     unsigned      int87                                     :  1;
     unsigned      int88                                     :  1;
     unsigned      int89                                     :  1;
     unsigned      int90                                     :  1;
     unsigned      int91                                     :  1;
     unsigned      int92                                     :  1;
     unsigned      int93                                     :  1;
     unsigned      int94                                     :  1;
     unsigned      int95                                     :  1;
#endif
} ncp_nca_itp_interrupt2_status_r_t;

/*! @struct ncp_nca_itp_interrupt3_status_r_t
 *  @brief Interrupt Status Register
 *  @details This register holds interrupt status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt3_status_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int127 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> bresp trace1 Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int126 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> bresp trace0 Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int125 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> bresp QPM Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int124 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> bresp otp_itp_tx Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int123 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> bresp itp_mtp_tx Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int122 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> bresp itp_mtp_req Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int121 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> bresp ncav3_ipcq_res Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int120 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> bresp ncav3_ipcq_req Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int119 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int118 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int117 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int116 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int115 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int114 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int113 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int112 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int111 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int110 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int109 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> ram_qpm_online_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int108 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> ram_ipd2_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int107 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> ram_tqbp_pergidthresh_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int106 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> ram_tqbp_pergid_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int105 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> ram_tqbp_perrq1thresh_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int104 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ram_tqbp_pertq1_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int103 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> ram_qpm_qstatus access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int102 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ram_tpdq_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int101 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> multi_output_fifo_mem_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int100 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> multi_output_state_mem_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int99 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> multi_output_cfg_mem_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int98 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> ll_completion_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int97 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ll_completion_ram_error access error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int96 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ll_completion_ram_error access error Status </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt3_status_r_t
 *
 * Implemented by: 
 *      status3
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int127                                    :  1;
     unsigned      int126                                    :  1;
     unsigned      int125                                    :  1;
     unsigned      int124                                    :  1;
     unsigned      int123                                    :  1;
     unsigned      int122                                    :  1;
     unsigned      int121                                    :  1;
     unsigned      int120                                    :  1;
     unsigned      int119                                    :  1;
     unsigned      int118                                    :  1;
     unsigned      int117                                    :  1;
     unsigned      int116                                    :  1;
     unsigned      int115                                    :  1;
     unsigned      int114                                    :  1;
     unsigned      int113                                    :  1;
     unsigned      int112                                    :  1;
     unsigned      int111                                    :  1;
     unsigned      int110                                    :  1;
     unsigned      int109                                    :  1;
     unsigned      int108                                    :  1;
     unsigned      int107                                    :  1;
     unsigned      int106                                    :  1;
     unsigned      int105                                    :  1;
     unsigned      int104                                    :  1;
     unsigned      int103                                    :  1;
     unsigned      int102                                    :  1;
     unsigned      int101                                    :  1;
     unsigned      int100                                    :  1;
     unsigned      int99                                     :  1;
     unsigned      int98                                     :  1;
     unsigned      int97                                     :  1;
     unsigned      int96                                     :  1;
#else    /* Little Endian */
     unsigned      int96                                     :  1;
     unsigned      int97                                     :  1;
     unsigned      int98                                     :  1;
     unsigned      int99                                     :  1;
     unsigned      int100                                    :  1;
     unsigned      int101                                    :  1;
     unsigned      int102                                    :  1;
     unsigned      int103                                    :  1;
     unsigned      int104                                    :  1;
     unsigned      int105                                    :  1;
     unsigned      int106                                    :  1;
     unsigned      int107                                    :  1;
     unsigned      int108                                    :  1;
     unsigned      int109                                    :  1;
     unsigned      int110                                    :  1;
     unsigned      int111                                    :  1;
     unsigned      int112                                    :  1;
     unsigned      int113                                    :  1;
     unsigned      int114                                    :  1;
     unsigned      int115                                    :  1;
     unsigned      int116                                    :  1;
     unsigned      int117                                    :  1;
     unsigned      int118                                    :  1;
     unsigned      int119                                    :  1;
     unsigned      int120                                    :  1;
     unsigned      int121                                    :  1;
     unsigned      int122                                    :  1;
     unsigned      int123                                    :  1;
     unsigned      int124                                    :  1;
     unsigned      int125                                    :  1;
     unsigned      int126                                    :  1;
     unsigned      int127                                    :  1;
#endif
} ncp_nca_itp_interrupt3_status_r_t;

/*! @struct ncp_nca_itp_interrupt4_status_r_t
 *  @brief Interrupt Status Register
 *  @details This register holds interrupt status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt4_status_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int159 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> ll_completion_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int158 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> ll_ieordsched_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int157 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> ll_ieordsched_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int156 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> ll_ieordsched_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int155 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> ll_ieordsched_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int154 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> ll_ieordready_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int153 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> ll_ieordready_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int152 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> ll_ieordready_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int151 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> ll_ieordready_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int150 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> ll_ieord_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int149 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> ll_ieord_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int148 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> ll_ieord_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int147 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> ll_ieord_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int146 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> ll_ieunord_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int145 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> ll_ieunord_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int144 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> ll_ieunord_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int143 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> ll_ieunord_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int142 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> ll_preproc_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int141 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> ll_preproc_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int140 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> ll_preproc_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int139 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> ll_preproc_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int138 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> addrconvert_in_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int137 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> addrconvert_in_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int136 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> addrconvert_alloc_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int135 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> addrconvert_alloc_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int134 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ram_tqbp_pertq0_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int133 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> ram_tqbp_pertq0thresh_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int132 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> ram_ncap2ipcq_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int131 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> ram_gid2tq sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int130 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> ram_ieordered_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int129 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ram_ipd_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int128 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ram_tpd_error sbe Status </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt4_status_r_t
 *
 * Implemented by: 
 *      status4
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int159                                    :  1;
     unsigned      int158                                    :  1;
     unsigned      int157                                    :  1;
     unsigned      int156                                    :  1;
     unsigned      int155                                    :  1;
     unsigned      int154                                    :  1;
     unsigned      int153                                    :  1;
     unsigned      int152                                    :  1;
     unsigned      int151                                    :  1;
     unsigned      int150                                    :  1;
     unsigned      int149                                    :  1;
     unsigned      int148                                    :  1;
     unsigned      int147                                    :  1;
     unsigned      int146                                    :  1;
     unsigned      int145                                    :  1;
     unsigned      int144                                    :  1;
     unsigned      int143                                    :  1;
     unsigned      int142                                    :  1;
     unsigned      int141                                    :  1;
     unsigned      int140                                    :  1;
     unsigned      int139                                    :  1;
     unsigned      int138                                    :  1;
     unsigned      int137                                    :  1;
     unsigned      int136                                    :  1;
     unsigned      int135                                    :  1;
     unsigned      int134                                    :  1;
     unsigned      int133                                    :  1;
     unsigned      int132                                    :  1;
     unsigned      int131                                    :  1;
     unsigned      int130                                    :  1;
     unsigned      int129                                    :  1;
     unsigned      int128                                    :  1;
#else    /* Little Endian */
     unsigned      int128                                    :  1;
     unsigned      int129                                    :  1;
     unsigned      int130                                    :  1;
     unsigned      int131                                    :  1;
     unsigned      int132                                    :  1;
     unsigned      int133                                    :  1;
     unsigned      int134                                    :  1;
     unsigned      int135                                    :  1;
     unsigned      int136                                    :  1;
     unsigned      int137                                    :  1;
     unsigned      int138                                    :  1;
     unsigned      int139                                    :  1;
     unsigned      int140                                    :  1;
     unsigned      int141                                    :  1;
     unsigned      int142                                    :  1;
     unsigned      int143                                    :  1;
     unsigned      int144                                    :  1;
     unsigned      int145                                    :  1;
     unsigned      int146                                    :  1;
     unsigned      int147                                    :  1;
     unsigned      int148                                    :  1;
     unsigned      int149                                    :  1;
     unsigned      int150                                    :  1;
     unsigned      int151                                    :  1;
     unsigned      int152                                    :  1;
     unsigned      int153                                    :  1;
     unsigned      int154                                    :  1;
     unsigned      int155                                    :  1;
     unsigned      int156                                    :  1;
     unsigned      int157                                    :  1;
     unsigned      int158                                    :  1;
     unsigned      int159                                    :  1;
#endif
} ncp_nca_itp_interrupt4_status_r_t;

/*! @struct ncp_nca_itp_interrupt5_status_r_t
 *  @brief Interrupt Status Register
 *  @details This register holds interrupt status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt5_status_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int191 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> err_drop[10] nack COPY pointer request Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int190 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> err_drop[9] nack HS pointer request, or task error
 *        from err_drop[8:0] Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int189 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> err_drop[8] copy error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int188 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> err_drop[7] addrconvert Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int187 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> err_drop[6] task ptrcnt=0 & TPD HS=0 Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int186 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> err_drop[5] unscheduled task (exception ACK) and ptrcnt
 *        is not zero Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int185 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> err_drop[4] malformed task Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int184 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> err_drop[3] unscheduled task and QUEUE not online
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int183 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> err_drop[2] unscheudled task (not exception ACK) and
 *        QPM issued drop command Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int182 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> err_drop[1] VPP task had taskerror set Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int181 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> err_drop[0] TPD TQ not online Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int180 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> err_purge[1] detect NCAP,PGIT traffic on task completion
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int179 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> err_purge[0] detect NCAP,PGIT traffic on NLINK ipcq
 *        req interface Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int178 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> err_drop[11] Task with PTR0=Fixed Pool & TPD HS=0
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int177 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int176 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int175 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int174 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int173 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> ram_qpm_online_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int172 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> ram_ipd2_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int171 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> ram_tqbp_pergidthresh_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int170 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> ram_tqbp_pergid_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int169 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> ram_tqbp_pertq1thresh_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int168 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ram_tqbp_pertq1_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int167 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> ram_qpm_qstatus sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int166 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ram_tpdq sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int165 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> multi_output_fifo_mem_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int164 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> multi_output_state_mem_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int163 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> multi_output_cfg_mem_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int162 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> ll_completion_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int161 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ll_completion_ram_error sbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int160 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ll_completion_ram_error sbe Status </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt5_status_r_t
 *
 * Implemented by: 
 *      status5
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int191                                    :  1;
     unsigned      int190                                    :  1;
     unsigned      int189                                    :  1;
     unsigned      int188                                    :  1;
     unsigned      int187                                    :  1;
     unsigned      int186                                    :  1;
     unsigned      int185                                    :  1;
     unsigned      int184                                    :  1;
     unsigned      int183                                    :  1;
     unsigned      int182                                    :  1;
     unsigned      int181                                    :  1;
     unsigned      int180                                    :  1;
     unsigned      int179                                    :  1;
     unsigned      int178                                    :  1;
     unsigned      int177                                    :  1;
     unsigned      int176                                    :  1;
     unsigned      int175                                    :  1;
     unsigned      int174                                    :  1;
     unsigned      int173                                    :  1;
     unsigned      int172                                    :  1;
     unsigned      int171                                    :  1;
     unsigned      int170                                    :  1;
     unsigned      int169                                    :  1;
     unsigned      int168                                    :  1;
     unsigned      int167                                    :  1;
     unsigned      int166                                    :  1;
     unsigned      int165                                    :  1;
     unsigned      int164                                    :  1;
     unsigned      int163                                    :  1;
     unsigned      int162                                    :  1;
     unsigned      int161                                    :  1;
     unsigned      int160                                    :  1;
#else    /* Little Endian */
     unsigned      int160                                    :  1;
     unsigned      int161                                    :  1;
     unsigned      int162                                    :  1;
     unsigned      int163                                    :  1;
     unsigned      int164                                    :  1;
     unsigned      int165                                    :  1;
     unsigned      int166                                    :  1;
     unsigned      int167                                    :  1;
     unsigned      int168                                    :  1;
     unsigned      int169                                    :  1;
     unsigned      int170                                    :  1;
     unsigned      int171                                    :  1;
     unsigned      int172                                    :  1;
     unsigned      int173                                    :  1;
     unsigned      int174                                    :  1;
     unsigned      int175                                    :  1;
     unsigned      int176                                    :  1;
     unsigned      int177                                    :  1;
     unsigned      int178                                    :  1;
     unsigned      int179                                    :  1;
     unsigned      int180                                    :  1;
     unsigned      int181                                    :  1;
     unsigned      int182                                    :  1;
     unsigned      int183                                    :  1;
     unsigned      int184                                    :  1;
     unsigned      int185                                    :  1;
     unsigned      int186                                    :  1;
     unsigned      int187                                    :  1;
     unsigned      int188                                    :  1;
     unsigned      int189                                    :  1;
     unsigned      int190                                    :  1;
     unsigned      int191                                    :  1;
#endif
} ncp_nca_itp_interrupt5_status_r_t;

/*! @struct ncp_nca_itp_interrupt6_status_r_t
 *  @brief Interrupt Status Register
 *  @details This register holds interrupt status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt6_status_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int223 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> ll_completion_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int222 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> ll_ieordsched_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int221 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> ll_ieordsched_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int220 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> ll_ieordsched_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int219 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> ll_ieordsched_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int218 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> ll_ieordready_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int217 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> ll_ieordready_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int216 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> ll_ieordready_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int215 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> ll_ieordready_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int214 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> ll_ieord_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int213 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> ll_ieord_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int212 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> ll_ieord_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int211 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> ll_ieord_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int210 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> ll_ieunord_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int209 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> ll_ieunord_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int208 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> ll_ieunord_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int207 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> ll_ieunord_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int206 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> ll_preproc_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int205 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> ll_preproc_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int204 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> ll_preproc_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int203 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> ll_preproc_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int202 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> addrconvert_in_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int201 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> addrconvert_in_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int200 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> addrconvert_alloc_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int199 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> addrconvert_alloc_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int198 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ram_tqbp_pertq0_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int197 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> ram_tqbpthresh_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int196 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> ram_ncap2ipcq_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int195 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> ram_tq2gid mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int194 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> ram_ieordered_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int193 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ram_ipd_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int192 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ram_tpd_error mbe Status </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt6_status_r_t
 *
 * Implemented by: 
 *      status6
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int223                                    :  1;
     unsigned      int222                                    :  1;
     unsigned      int221                                    :  1;
     unsigned      int220                                    :  1;
     unsigned      int219                                    :  1;
     unsigned      int218                                    :  1;
     unsigned      int217                                    :  1;
     unsigned      int216                                    :  1;
     unsigned      int215                                    :  1;
     unsigned      int214                                    :  1;
     unsigned      int213                                    :  1;
     unsigned      int212                                    :  1;
     unsigned      int211                                    :  1;
     unsigned      int210                                    :  1;
     unsigned      int209                                    :  1;
     unsigned      int208                                    :  1;
     unsigned      int207                                    :  1;
     unsigned      int206                                    :  1;
     unsigned      int205                                    :  1;
     unsigned      int204                                    :  1;
     unsigned      int203                                    :  1;
     unsigned      int202                                    :  1;
     unsigned      int201                                    :  1;
     unsigned      int200                                    :  1;
     unsigned      int199                                    :  1;
     unsigned      int198                                    :  1;
     unsigned      int197                                    :  1;
     unsigned      int196                                    :  1;
     unsigned      int195                                    :  1;
     unsigned      int194                                    :  1;
     unsigned      int193                                    :  1;
     unsigned      int192                                    :  1;
#else    /* Little Endian */
     unsigned      int192                                    :  1;
     unsigned      int193                                    :  1;
     unsigned      int194                                    :  1;
     unsigned      int195                                    :  1;
     unsigned      int196                                    :  1;
     unsigned      int197                                    :  1;
     unsigned      int198                                    :  1;
     unsigned      int199                                    :  1;
     unsigned      int200                                    :  1;
     unsigned      int201                                    :  1;
     unsigned      int202                                    :  1;
     unsigned      int203                                    :  1;
     unsigned      int204                                    :  1;
     unsigned      int205                                    :  1;
     unsigned      int206                                    :  1;
     unsigned      int207                                    :  1;
     unsigned      int208                                    :  1;
     unsigned      int209                                    :  1;
     unsigned      int210                                    :  1;
     unsigned      int211                                    :  1;
     unsigned      int212                                    :  1;
     unsigned      int213                                    :  1;
     unsigned      int214                                    :  1;
     unsigned      int215                                    :  1;
     unsigned      int216                                    :  1;
     unsigned      int217                                    :  1;
     unsigned      int218                                    :  1;
     unsigned      int219                                    :  1;
     unsigned      int220                                    :  1;
     unsigned      int221                                    :  1;
     unsigned      int222                                    :  1;
     unsigned      int223                                    :  1;
#endif
} ncp_nca_itp_interrupt6_status_r_t;

/*! @struct ncp_nca_itp_interrupt7_status_r_t
 *  @brief Interrupt Status Register
 *  @details This register holds interrupt status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt7_status_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int255 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> NCAV3 CFG FIFO OF Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int254 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> NCAV3 CFG FIFO UF Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int253 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> TIL START task bp asserted: ll_ieord_size>thresh Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int252 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> TIL START task bp asserted: ll_ieunord_size>thresh
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int251 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> TIL START task bp asserted: ncav3_activitycounter_bcam_current_value>thresh
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int250 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> TIL START task bp asserted: ncav3_activitycounter_bcam_current_value>thresh
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int249 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> TIL START task bp asserted: tqbp_pergid_unissued_Q
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int248 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> TIL START task bp asserted: tqbp_pertq_unissuedqueued_Q
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int247 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> TIL START task bp asserted: tqbp_pertq_unissued_Q
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int246 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> TIL START task bp asserted. eng_til_start_bp Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int245 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> format0 Header Separate override: Task Error or Nack
 *        Task: HS 1 -> 0 Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int244 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> format0 Header Separate override: SEG[0]=FixedPool
 *        task: HS 0 -> 1 Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int243 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> format0 Header Separate override: PTRCNT=0 task: HS
 *        0 -> 1 Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int242 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> format0 Header Separate override: QPM exception task:
 *        HS 1->0 Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int241 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int240 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int239 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int238 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> reserved Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int237 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> ram_qpm_online_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int236 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> ram_ipd2_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int235 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> ram_tqbp_pergidthresh_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int234 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> ram_tqbp_pergid_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int233 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> ram_tqbp_pertq1thresh_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int232 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ram_tqbp_pertq1_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int231 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> ram_qpm_qstatus mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int230 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ram_tpdq mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int229 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> multi_output_fifo_mem_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int228 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> multi_output_state_mem_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int227 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> multi_output_cfg_mem_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int226 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> ll_completion_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int225 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ll_completion_ram_error mbe Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int224 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ll_completion_ram_error mbe Status </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt7_status_r_t
 *
 * Implemented by: 
 *      status7
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int255                                    :  1;
     unsigned      int254                                    :  1;
     unsigned      int253                                    :  1;
     unsigned      int252                                    :  1;
     unsigned      int251                                    :  1;
     unsigned      int250                                    :  1;
     unsigned      int249                                    :  1;
     unsigned      int248                                    :  1;
     unsigned      int247                                    :  1;
     unsigned      int246                                    :  1;
     unsigned      int245                                    :  1;
     unsigned      int244                                    :  1;
     unsigned      int243                                    :  1;
     unsigned      int242                                    :  1;
     unsigned      int241                                    :  1;
     unsigned      int240                                    :  1;
     unsigned      int239                                    :  1;
     unsigned      int238                                    :  1;
     unsigned      int237                                    :  1;
     unsigned      int236                                    :  1;
     unsigned      int235                                    :  1;
     unsigned      int234                                    :  1;
     unsigned      int233                                    :  1;
     unsigned      int232                                    :  1;
     unsigned      int231                                    :  1;
     unsigned      int230                                    :  1;
     unsigned      int229                                    :  1;
     unsigned      int228                                    :  1;
     unsigned      int227                                    :  1;
     unsigned      int226                                    :  1;
     unsigned      int225                                    :  1;
     unsigned      int224                                    :  1;
#else    /* Little Endian */
     unsigned      int224                                    :  1;
     unsigned      int225                                    :  1;
     unsigned      int226                                    :  1;
     unsigned      int227                                    :  1;
     unsigned      int228                                    :  1;
     unsigned      int229                                    :  1;
     unsigned      int230                                    :  1;
     unsigned      int231                                    :  1;
     unsigned      int232                                    :  1;
     unsigned      int233                                    :  1;
     unsigned      int234                                    :  1;
     unsigned      int235                                    :  1;
     unsigned      int236                                    :  1;
     unsigned      int237                                    :  1;
     unsigned      int238                                    :  1;
     unsigned      int239                                    :  1;
     unsigned      int240                                    :  1;
     unsigned      int241                                    :  1;
     unsigned      int242                                    :  1;
     unsigned      int243                                    :  1;
     unsigned      int244                                    :  1;
     unsigned      int245                                    :  1;
     unsigned      int246                                    :  1;
     unsigned      int247                                    :  1;
     unsigned      int248                                    :  1;
     unsigned      int249                                    :  1;
     unsigned      int250                                    :  1;
     unsigned      int251                                    :  1;
     unsigned      int252                                    :  1;
     unsigned      int253                                    :  1;
     unsigned      int254                                    :  1;
     unsigned      int255                                    :  1;
#endif
} ncp_nca_itp_interrupt7_status_r_t;

/*! @struct ncp_nca_itp_interrupt0_en_r_t
 *  @brief Interrupt Enable Register
 *  @details This register enables interrupts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt0_en_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int31 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> cfg_smon_int Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int30 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> cfg_synd_status_int Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int29 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> task Copied Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int28 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> NLINK parity error observed Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int27 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> db_in_qpm_qstatus_ready=0. QPM should not drop this
 *        ready, this is HW misconnect or QPM error Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int26 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> MTP returns a ERROR response Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int25 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> MTP returns a NACK response Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int24 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> err_completion_check_opcq. When aPCQ task is returned
 *        the sequence number does not match the stored task.
 *        THis can occur when task with task completion are
 *        returned out of order or are missing/duplicated. Causes
 *        system corruption Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int23 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> err_completion_check_apcq. When aPCQ task is returned
 *        the sequence number does not match the stored task.
 *        THis can occur when task with consumer pointer advance
 *        are returned out of order or are missing/duplicated.
 *        Causes system corruption Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int22 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> err_ieordready_empty. When scheduling a iPCQ & GID
 *        selected Ordered-Ready that have no task avaible.
 *        deselect the iPCQ & GID, Clean up state and return
 *        to begining of scheduling. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int21 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> err_ieordsched_empty. When scheduling a iPCQ & GID
 *        selected Ordered-Scheduled that have no task avaible.
 *        deselect the iPCQ & GID, Clean up state and return
 *        to begining of scheduling. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int20 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> err_schedsort. WHen scheduling a iPCQ & GID selected
 *        flow with all LL empty. THis could result from inconsistency
 *        in config IPC vs ipcq2god. Clean up state and return
 *        to begining of scheduling. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int19 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> err_notqpri. When scheduling a iPCQ & GID selected
 *        flow with no task availble. THis could result from
 *        inconsistency in config IPC vs ipcq2god. Clean up
 *        state and return to begining of scheduling. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int18 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> err_ieunord_empty. When scheduling a iPCQ & GID selected
 *        Unordered that have no task avaible. deselect the
 *        iPCQ & GID, Clean up state and return to begining
 *        of scheduling. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int17 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> err_activitycount. One of the activity counters reported
 *        an error. No recovery possible, must be a misconfigure
 *        of the threshold Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int16 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> AW_fifo FIFO of Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int15 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> err_hitidle. Ordered flow HIT in BCAM and the state
 *        is IDLE. THis is not expected but not illegal, continue
 *        normal operation Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int14 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> err_c_enqcnt_of. ieOrdered state updated during task
 *        completion and overflow of enqueue count. Continue
 *        normal operation Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int13 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> err_c_schcnt_of. ieOrdered state updated during task
 *        completion and overflow of scheduled count. Continue
 *        normal operation Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int12 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> err_s_enqcnt_of. ieOrdered state updated during task
 *        scheudle and overflow of enqueue count. Continue normal
 *        operation Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int11 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> err_s_schcnt_of. ieOrdered state updated during task
 *        scheudle and overflow of scheduled count. Continue
 *        normal operation Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int10 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> err_e_enqcnt_of. ieOrdered state updated during task
 *        enqueue and overflow of enqueue count. Continue normal
 *        operation Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int9 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> err_e_schcnt_of. ieOrdered state updated during task
 *        enqueue and overflow of scheduled count. Continue
 *        normal operation Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int8 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> err_complete_empty. Task completion arrives from OTP
 *        and the NCAP,PGIT list in LL_completion is empty.
 *        drop the reqeust and continue normal operation Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int7 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> err_ieord_empty. When scheduling a iPCQ & GID selected
 *        Ordered that have no task avaible. deselect the iPCQ
 *        & GID, Clean up state and return to begining of scheduling.
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int6 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> err_ord_flowid. After scheduling the flowID popped
 *        from the ieUnordered LL does not match the flowID
 *        from the scheudling (ieOrdReady or ieOrdSched LL).
 *        continue normal operation. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int5 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> err_unord_flowid. After scheduling the flowID popped
 *        from the ieUnordered LL does not match the flowID
 *        from the scheudling. Should always be zero. continue
 *        normal operation. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int4 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> err_dynamic. error triggered during dynamic operation
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int3 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> multi_output_fifo_overflow Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int2 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> multi_output_fifo_underflow Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ncav3_cfg for read_err Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ncav3_cfg write_err Enable </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt0_en_r_t
 *
 * Implemented by: 
 *      en0
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int31                                     :  1;
     unsigned      int30                                     :  1;
     unsigned      int29                                     :  1;
     unsigned      int28                                     :  1;
     unsigned      int27                                     :  1;
     unsigned      int26                                     :  1;
     unsigned      int25                                     :  1;
     unsigned      int24                                     :  1;
     unsigned      int23                                     :  1;
     unsigned      int22                                     :  1;
     unsigned      int21                                     :  1;
     unsigned      int20                                     :  1;
     unsigned      int19                                     :  1;
     unsigned      int18                                     :  1;
     unsigned      int17                                     :  1;
     unsigned      int16                                     :  1;
     unsigned      int15                                     :  1;
     unsigned      int14                                     :  1;
     unsigned      int13                                     :  1;
     unsigned      int12                                     :  1;
     unsigned      int11                                     :  1;
     unsigned      int10                                     :  1;
     unsigned      int9                                      :  1;
     unsigned      int8                                      :  1;
     unsigned      int7                                      :  1;
     unsigned      int6                                      :  1;
     unsigned      int5                                      :  1;
     unsigned      int4                                      :  1;
     unsigned      int3                                      :  1;
     unsigned      int2                                      :  1;
     unsigned      int1                                      :  1;
     unsigned      int0                                      :  1;
#else    /* Little Endian */
     unsigned      int0                                      :  1;
     unsigned      int1                                      :  1;
     unsigned      int2                                      :  1;
     unsigned      int3                                      :  1;
     unsigned      int4                                      :  1;
     unsigned      int5                                      :  1;
     unsigned      int6                                      :  1;
     unsigned      int7                                      :  1;
     unsigned      int8                                      :  1;
     unsigned      int9                                      :  1;
     unsigned      int10                                     :  1;
     unsigned      int11                                     :  1;
     unsigned      int12                                     :  1;
     unsigned      int13                                     :  1;
     unsigned      int14                                     :  1;
     unsigned      int15                                     :  1;
     unsigned      int16                                     :  1;
     unsigned      int17                                     :  1;
     unsigned      int18                                     :  1;
     unsigned      int19                                     :  1;
     unsigned      int20                                     :  1;
     unsigned      int21                                     :  1;
     unsigned      int22                                     :  1;
     unsigned      int23                                     :  1;
     unsigned      int24                                     :  1;
     unsigned      int25                                     :  1;
     unsigned      int26                                     :  1;
     unsigned      int27                                     :  1;
     unsigned      int28                                     :  1;
     unsigned      int29                                     :  1;
     unsigned      int30                                     :  1;
     unsigned      int31                                     :  1;
#endif
} ncp_nca_itp_interrupt0_en_r_t;

/*! @struct ncp_nca_itp_interrupt1_en_r_t
 *  @brief Interrupt Enable Register
 *  @details This register enables interrupts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt1_en_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int63 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> drop unscheduled Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int62 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> drop ordered Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int61 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> drop unordered Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int60 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int59 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int58 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int57 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int56 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int55 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int54 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int53 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> SYND21 err_ipcq_credits_of_zero Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int52 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> SYND20 ipcq_multifull_Q Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int51 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> SYND19 ipcq_full_Q Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int50 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> SYND18 err_ipcqsizeof_c1 Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int49 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> SYND17 err_ipcqsizeof_c0 Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int48 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> SYND16 err_ipcqsizeof_e Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int47 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> SYND15 err_ipcq_credits_of_inc Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int46 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> SYND14 err_ipcq_credits_of_dec Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int45 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> SYND13 err_of Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int44 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> SYND12 err_copyerror Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int43 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> SYND11 cam_ieordered_ERROR Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int42 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> SYND10 addrconvert_in_out_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int41 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> SYND09 addrconvert_alloc_out_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int40 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> SYND08 ll_completion_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int39 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> SYND07 ll_ieordsched_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int38 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> SYND06 ll_ieordready_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int37 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> SYND05 ll_ieord_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int36 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> SYND04 ll_ieunord_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int35 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> SYND03 ll_preproc_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int34 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> SYND02 itp_system_error_2 Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int33 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> SYND01 itp_system_error_1 Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int32 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> SYND00 itp_system_error_0 Enable </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt1_en_r_t
 *
 * Implemented by: 
 *      en1
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int63                                     :  1;
     unsigned      int62                                     :  1;
     unsigned      int61                                     :  1;
     unsigned      int60                                     :  1;
     unsigned      int59                                     :  1;
     unsigned      int58                                     :  1;
     unsigned      int57                                     :  1;
     unsigned      int56                                     :  1;
     unsigned      int55                                     :  1;
     unsigned      int54                                     :  1;
     unsigned      int53                                     :  1;
     unsigned      int52                                     :  1;
     unsigned      int51                                     :  1;
     unsigned      int50                                     :  1;
     unsigned      int49                                     :  1;
     unsigned      int48                                     :  1;
     unsigned      int47                                     :  1;
     unsigned      int46                                     :  1;
     unsigned      int45                                     :  1;
     unsigned      int44                                     :  1;
     unsigned      int43                                     :  1;
     unsigned      int42                                     :  1;
     unsigned      int41                                     :  1;
     unsigned      int40                                     :  1;
     unsigned      int39                                     :  1;
     unsigned      int38                                     :  1;
     unsigned      int37                                     :  1;
     unsigned      int36                                     :  1;
     unsigned      int35                                     :  1;
     unsigned      int34                                     :  1;
     unsigned      int33                                     :  1;
     unsigned      int32                                     :  1;
#else    /* Little Endian */
     unsigned      int32                                     :  1;
     unsigned      int33                                     :  1;
     unsigned      int34                                     :  1;
     unsigned      int35                                     :  1;
     unsigned      int36                                     :  1;
     unsigned      int37                                     :  1;
     unsigned      int38                                     :  1;
     unsigned      int39                                     :  1;
     unsigned      int40                                     :  1;
     unsigned      int41                                     :  1;
     unsigned      int42                                     :  1;
     unsigned      int43                                     :  1;
     unsigned      int44                                     :  1;
     unsigned      int45                                     :  1;
     unsigned      int46                                     :  1;
     unsigned      int47                                     :  1;
     unsigned      int48                                     :  1;
     unsigned      int49                                     :  1;
     unsigned      int50                                     :  1;
     unsigned      int51                                     :  1;
     unsigned      int52                                     :  1;
     unsigned      int53                                     :  1;
     unsigned      int54                                     :  1;
     unsigned      int55                                     :  1;
     unsigned      int56                                     :  1;
     unsigned      int57                                     :  1;
     unsigned      int58                                     :  1;
     unsigned      int59                                     :  1;
     unsigned      int60                                     :  1;
     unsigned      int61                                     :  1;
     unsigned      int62                                     :  1;
     unsigned      int63                                     :  1;
#endif
} ncp_nca_itp_interrupt1_en_r_t;

/*! @struct ncp_nca_itp_interrupt2_en_r_t
 *  @brief Interrupt Enable Register
 *  @details This register enables interrupts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt2_en_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int95 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> ll_completion_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int94 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> ll_ieordsched_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int93 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> ll_ieordsched_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int92 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> ll_ieordsched_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int91 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> ll_ieordsched_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int90 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> ll_ieordready_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int89 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> ll_ieordready_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int88 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> ll_ieordready_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int87 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> ll_ieordready_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int86 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> ll_ieord_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int85 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> ll_ieord_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int84 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> ll_ieord_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int83 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> ll_ieord_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int82 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> ll_ieunord_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int81 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> ll_ieunord_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int80 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> ll_ieunord_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int79 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> ll_ieunord_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int78 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> ll_preproc_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int77 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> ll_preproc_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int76 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> ll_preproc_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int75 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> ll_preproc_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int74 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> addrconvert_in_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int73 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> addrconvert_in_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int72 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> addrconvert_alloc_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int71 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> addrconvert_alloc_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int70 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ram_tqbp_pertq0_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int69 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> ram_tqbp_pertq0thresh_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int68 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> ram_ncap2ipcq_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int67 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> ram_gid2tq access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int66 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> ram_ieordered_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int65 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ram_ipd_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int64 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ram_tpd_error access error Enable </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt2_en_r_t
 *
 * Implemented by: 
 *      en2
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int95                                     :  1;
     unsigned      int94                                     :  1;
     unsigned      int93                                     :  1;
     unsigned      int92                                     :  1;
     unsigned      int91                                     :  1;
     unsigned      int90                                     :  1;
     unsigned      int89                                     :  1;
     unsigned      int88                                     :  1;
     unsigned      int87                                     :  1;
     unsigned      int86                                     :  1;
     unsigned      int85                                     :  1;
     unsigned      int84                                     :  1;
     unsigned      int83                                     :  1;
     unsigned      int82                                     :  1;
     unsigned      int81                                     :  1;
     unsigned      int80                                     :  1;
     unsigned      int79                                     :  1;
     unsigned      int78                                     :  1;
     unsigned      int77                                     :  1;
     unsigned      int76                                     :  1;
     unsigned      int75                                     :  1;
     unsigned      int74                                     :  1;
     unsigned      int73                                     :  1;
     unsigned      int72                                     :  1;
     unsigned      int71                                     :  1;
     unsigned      int70                                     :  1;
     unsigned      int69                                     :  1;
     unsigned      int68                                     :  1;
     unsigned      int67                                     :  1;
     unsigned      int66                                     :  1;
     unsigned      int65                                     :  1;
     unsigned      int64                                     :  1;
#else    /* Little Endian */
     unsigned      int64                                     :  1;
     unsigned      int65                                     :  1;
     unsigned      int66                                     :  1;
     unsigned      int67                                     :  1;
     unsigned      int68                                     :  1;
     unsigned      int69                                     :  1;
     unsigned      int70                                     :  1;
     unsigned      int71                                     :  1;
     unsigned      int72                                     :  1;
     unsigned      int73                                     :  1;
     unsigned      int74                                     :  1;
     unsigned      int75                                     :  1;
     unsigned      int76                                     :  1;
     unsigned      int77                                     :  1;
     unsigned      int78                                     :  1;
     unsigned      int79                                     :  1;
     unsigned      int80                                     :  1;
     unsigned      int81                                     :  1;
     unsigned      int82                                     :  1;
     unsigned      int83                                     :  1;
     unsigned      int84                                     :  1;
     unsigned      int85                                     :  1;
     unsigned      int86                                     :  1;
     unsigned      int87                                     :  1;
     unsigned      int88                                     :  1;
     unsigned      int89                                     :  1;
     unsigned      int90                                     :  1;
     unsigned      int91                                     :  1;
     unsigned      int92                                     :  1;
     unsigned      int93                                     :  1;
     unsigned      int94                                     :  1;
     unsigned      int95                                     :  1;
#endif
} ncp_nca_itp_interrupt2_en_r_t;

/*! @struct ncp_nca_itp_interrupt3_en_r_t
 *  @brief Interrupt Enable Register
 *  @details This register enables interrupts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt3_en_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int127 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> bresp trace1 Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int126 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> bresp trace0 Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int125 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> bresp QPM Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int124 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> bresp otp_itp_tx Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int123 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> bresp itp_mtp_tx Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int122 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> bresp itp_mtp_req Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int121 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> bresp ncav3_ipcq_res Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int120 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> bresp ncav3_ipcq_req Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int119 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int118 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int117 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int116 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int115 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int114 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int113 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int112 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int111 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int110 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int109 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> ram_qpm_online_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int108 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> ram_ipd2_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int107 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> ram_tqbp_pergidthresh_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int106 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> ram_tqbp_pergid_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int105 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> ram_tqbp_perrq1thresh_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int104 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ram_tqbp_pertq1_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int103 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> ram_qpm_qstatus access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int102 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ram_tpdq_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int101 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> multi_output_fifo_mem_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int100 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> multi_output_state_mem_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int99 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> multi_output_cfg_mem_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int98 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> ll_completion_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int97 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ll_completion_ram_error access error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int96 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ll_completion_ram_error access error Enable </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt3_en_r_t
 *
 * Implemented by: 
 *      en3
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int127                                    :  1;
     unsigned      int126                                    :  1;
     unsigned      int125                                    :  1;
     unsigned      int124                                    :  1;
     unsigned      int123                                    :  1;
     unsigned      int122                                    :  1;
     unsigned      int121                                    :  1;
     unsigned      int120                                    :  1;
     unsigned      int119                                    :  1;
     unsigned      int118                                    :  1;
     unsigned      int117                                    :  1;
     unsigned      int116                                    :  1;
     unsigned      int115                                    :  1;
     unsigned      int114                                    :  1;
     unsigned      int113                                    :  1;
     unsigned      int112                                    :  1;
     unsigned      int111                                    :  1;
     unsigned      int110                                    :  1;
     unsigned      int109                                    :  1;
     unsigned      int108                                    :  1;
     unsigned      int107                                    :  1;
     unsigned      int106                                    :  1;
     unsigned      int105                                    :  1;
     unsigned      int104                                    :  1;
     unsigned      int103                                    :  1;
     unsigned      int102                                    :  1;
     unsigned      int101                                    :  1;
     unsigned      int100                                    :  1;
     unsigned      int99                                     :  1;
     unsigned      int98                                     :  1;
     unsigned      int97                                     :  1;
     unsigned      int96                                     :  1;
#else    /* Little Endian */
     unsigned      int96                                     :  1;
     unsigned      int97                                     :  1;
     unsigned      int98                                     :  1;
     unsigned      int99                                     :  1;
     unsigned      int100                                    :  1;
     unsigned      int101                                    :  1;
     unsigned      int102                                    :  1;
     unsigned      int103                                    :  1;
     unsigned      int104                                    :  1;
     unsigned      int105                                    :  1;
     unsigned      int106                                    :  1;
     unsigned      int107                                    :  1;
     unsigned      int108                                    :  1;
     unsigned      int109                                    :  1;
     unsigned      int110                                    :  1;
     unsigned      int111                                    :  1;
     unsigned      int112                                    :  1;
     unsigned      int113                                    :  1;
     unsigned      int114                                    :  1;
     unsigned      int115                                    :  1;
     unsigned      int116                                    :  1;
     unsigned      int117                                    :  1;
     unsigned      int118                                    :  1;
     unsigned      int119                                    :  1;
     unsigned      int120                                    :  1;
     unsigned      int121                                    :  1;
     unsigned      int122                                    :  1;
     unsigned      int123                                    :  1;
     unsigned      int124                                    :  1;
     unsigned      int125                                    :  1;
     unsigned      int126                                    :  1;
     unsigned      int127                                    :  1;
#endif
} ncp_nca_itp_interrupt3_en_r_t;

/*! @struct ncp_nca_itp_interrupt4_en_r_t
 *  @brief Interrupt Enable Register
 *  @details This register enables interrupts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt4_en_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int159 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> ll_completion_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int158 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> ll_ieordsched_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int157 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> ll_ieordsched_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int156 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> ll_ieordsched_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int155 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> ll_ieordsched_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int154 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> ll_ieordready_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int153 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> ll_ieordready_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int152 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> ll_ieordready_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int151 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> ll_ieordready_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int150 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> ll_ieord_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int149 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> ll_ieord_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int148 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> ll_ieord_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int147 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> ll_ieord_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int146 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> ll_ieunord_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int145 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> ll_ieunord_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int144 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> ll_ieunord_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int143 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> ll_ieunord_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int142 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> ll_preproc_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int141 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> ll_preproc_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int140 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> ll_preproc_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int139 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> ll_preproc_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int138 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> addrconvert_in_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int137 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> addrconvert_in_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int136 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> addrconvert_alloc_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int135 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> addrconvert_alloc_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int134 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ram_tqbp_pertq0_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int133 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> ram_tqbp_pertq0thresh_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int132 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> ram_ncap2ipcq_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int131 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> ram_gid2tq sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int130 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> ram_ieordered_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int129 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ram_ipd_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int128 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ram_tpd_error sbe Enable </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt4_en_r_t
 *
 * Implemented by: 
 *      en4
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int159                                    :  1;
     unsigned      int158                                    :  1;
     unsigned      int157                                    :  1;
     unsigned      int156                                    :  1;
     unsigned      int155                                    :  1;
     unsigned      int154                                    :  1;
     unsigned      int153                                    :  1;
     unsigned      int152                                    :  1;
     unsigned      int151                                    :  1;
     unsigned      int150                                    :  1;
     unsigned      int149                                    :  1;
     unsigned      int148                                    :  1;
     unsigned      int147                                    :  1;
     unsigned      int146                                    :  1;
     unsigned      int145                                    :  1;
     unsigned      int144                                    :  1;
     unsigned      int143                                    :  1;
     unsigned      int142                                    :  1;
     unsigned      int141                                    :  1;
     unsigned      int140                                    :  1;
     unsigned      int139                                    :  1;
     unsigned      int138                                    :  1;
     unsigned      int137                                    :  1;
     unsigned      int136                                    :  1;
     unsigned      int135                                    :  1;
     unsigned      int134                                    :  1;
     unsigned      int133                                    :  1;
     unsigned      int132                                    :  1;
     unsigned      int131                                    :  1;
     unsigned      int130                                    :  1;
     unsigned      int129                                    :  1;
     unsigned      int128                                    :  1;
#else    /* Little Endian */
     unsigned      int128                                    :  1;
     unsigned      int129                                    :  1;
     unsigned      int130                                    :  1;
     unsigned      int131                                    :  1;
     unsigned      int132                                    :  1;
     unsigned      int133                                    :  1;
     unsigned      int134                                    :  1;
     unsigned      int135                                    :  1;
     unsigned      int136                                    :  1;
     unsigned      int137                                    :  1;
     unsigned      int138                                    :  1;
     unsigned      int139                                    :  1;
     unsigned      int140                                    :  1;
     unsigned      int141                                    :  1;
     unsigned      int142                                    :  1;
     unsigned      int143                                    :  1;
     unsigned      int144                                    :  1;
     unsigned      int145                                    :  1;
     unsigned      int146                                    :  1;
     unsigned      int147                                    :  1;
     unsigned      int148                                    :  1;
     unsigned      int149                                    :  1;
     unsigned      int150                                    :  1;
     unsigned      int151                                    :  1;
     unsigned      int152                                    :  1;
     unsigned      int153                                    :  1;
     unsigned      int154                                    :  1;
     unsigned      int155                                    :  1;
     unsigned      int156                                    :  1;
     unsigned      int157                                    :  1;
     unsigned      int158                                    :  1;
     unsigned      int159                                    :  1;
#endif
} ncp_nca_itp_interrupt4_en_r_t;

/*! @struct ncp_nca_itp_interrupt5_en_r_t
 *  @brief Interrupt Enable Register
 *  @details This register enables interrupts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt5_en_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int191 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> err_drop[10] nack COPY pointer request Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int190 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> err_drop[9] nack HS pointer request, or task error
 *        from err_drop[8:0] Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int189 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> err_drop[8] copy error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int188 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> err_drop[7] addrconvert Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int187 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> err_drop[6] task ptrcnt=0 & TPD HS=0 Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int186 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> err_drop[5] unscheduled task (exception ACK) and ptrcnt
 *        is not zero Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int185 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> err_drop[4] malformed task Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int184 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> err_drop[3] unscheduled task and QUEUE not online
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int183 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> err_drop[2] unscheudled task (not exception ACK) and
 *        QPM issued drop command Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int182 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> err_drop[1] VPP task had taskerror set Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int181 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> err_drop[0] TPD TQ not online Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int180 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> err_purge[1] detect NCAP,PGIT traffic on task completion
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int179 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> err_purge[0] detect NCAP,PGIT traffic on NLINK ipcq
 *        req interface Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int178 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> err_drop[11] Task with PTR0=Fixed Pool & TPD HS=0
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int177 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int176 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int175 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int174 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int173 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> ram_qpm_online_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int172 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> ram_ipd2_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int171 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> ram_tqbp_pergidthresh_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int170 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> ram_tqbp_pergid_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int169 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> ram_tqbp_pertq1thresh_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int168 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ram_tqbp_pertq1_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int167 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> ram_qpm_qstatus sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int166 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ram_tpdq sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int165 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> multi_output_fifo_mem_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int164 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> multi_output_state_mem_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int163 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> multi_output_cfg_mem_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int162 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> ll_completion_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int161 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ll_completion_ram_error sbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int160 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ll_completion_ram_error sbe Enable </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt5_en_r_t
 *
 * Implemented by: 
 *      en5
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int191                                    :  1;
     unsigned      int190                                    :  1;
     unsigned      int189                                    :  1;
     unsigned      int188                                    :  1;
     unsigned      int187                                    :  1;
     unsigned      int186                                    :  1;
     unsigned      int185                                    :  1;
     unsigned      int184                                    :  1;
     unsigned      int183                                    :  1;
     unsigned      int182                                    :  1;
     unsigned      int181                                    :  1;
     unsigned      int180                                    :  1;
     unsigned      int179                                    :  1;
     unsigned      int178                                    :  1;
     unsigned      int177                                    :  1;
     unsigned      int176                                    :  1;
     unsigned      int175                                    :  1;
     unsigned      int174                                    :  1;
     unsigned      int173                                    :  1;
     unsigned      int172                                    :  1;
     unsigned      int171                                    :  1;
     unsigned      int170                                    :  1;
     unsigned      int169                                    :  1;
     unsigned      int168                                    :  1;
     unsigned      int167                                    :  1;
     unsigned      int166                                    :  1;
     unsigned      int165                                    :  1;
     unsigned      int164                                    :  1;
     unsigned      int163                                    :  1;
     unsigned      int162                                    :  1;
     unsigned      int161                                    :  1;
     unsigned      int160                                    :  1;
#else    /* Little Endian */
     unsigned      int160                                    :  1;
     unsigned      int161                                    :  1;
     unsigned      int162                                    :  1;
     unsigned      int163                                    :  1;
     unsigned      int164                                    :  1;
     unsigned      int165                                    :  1;
     unsigned      int166                                    :  1;
     unsigned      int167                                    :  1;
     unsigned      int168                                    :  1;
     unsigned      int169                                    :  1;
     unsigned      int170                                    :  1;
     unsigned      int171                                    :  1;
     unsigned      int172                                    :  1;
     unsigned      int173                                    :  1;
     unsigned      int174                                    :  1;
     unsigned      int175                                    :  1;
     unsigned      int176                                    :  1;
     unsigned      int177                                    :  1;
     unsigned      int178                                    :  1;
     unsigned      int179                                    :  1;
     unsigned      int180                                    :  1;
     unsigned      int181                                    :  1;
     unsigned      int182                                    :  1;
     unsigned      int183                                    :  1;
     unsigned      int184                                    :  1;
     unsigned      int185                                    :  1;
     unsigned      int186                                    :  1;
     unsigned      int187                                    :  1;
     unsigned      int188                                    :  1;
     unsigned      int189                                    :  1;
     unsigned      int190                                    :  1;
     unsigned      int191                                    :  1;
#endif
} ncp_nca_itp_interrupt5_en_r_t;

/*! @struct ncp_nca_itp_interrupt6_en_r_t
 *  @brief Interrupt Enable Register
 *  @details This register enables interrupts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt6_en_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int223 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> ll_completion_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int222 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> ll_ieordsched_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int221 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> ll_ieordsched_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int220 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> ll_ieordsched_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int219 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> ll_ieordsched_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int218 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> ll_ieordready_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int217 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> ll_ieordready_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int216 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> ll_ieordready_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int215 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> ll_ieordready_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int214 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> ll_ieord_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int213 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> ll_ieord_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int212 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> ll_ieord_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int211 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> ll_ieord_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int210 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> ll_ieunord_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int209 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> ll_ieunord_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int208 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> ll_ieunord_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int207 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> ll_ieunord_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int206 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> ll_preproc_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int205 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> ll_preproc_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int204 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> ll_preproc_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int203 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> ll_preproc_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int202 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> addrconvert_in_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int201 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> addrconvert_in_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int200 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> addrconvert_alloc_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int199 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> addrconvert_alloc_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int198 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ram_tqbp_pertq0_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int197 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> ram_tqbpthresh_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int196 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> ram_ncap2ipcq_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int195 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> ram_tq2gid mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int194 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> ram_ieordered_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int193 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ram_ipd_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int192 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ram_tpd_error mbe Enable </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt6_en_r_t
 *
 * Implemented by: 
 *      en6
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int223                                    :  1;
     unsigned      int222                                    :  1;
     unsigned      int221                                    :  1;
     unsigned      int220                                    :  1;
     unsigned      int219                                    :  1;
     unsigned      int218                                    :  1;
     unsigned      int217                                    :  1;
     unsigned      int216                                    :  1;
     unsigned      int215                                    :  1;
     unsigned      int214                                    :  1;
     unsigned      int213                                    :  1;
     unsigned      int212                                    :  1;
     unsigned      int211                                    :  1;
     unsigned      int210                                    :  1;
     unsigned      int209                                    :  1;
     unsigned      int208                                    :  1;
     unsigned      int207                                    :  1;
     unsigned      int206                                    :  1;
     unsigned      int205                                    :  1;
     unsigned      int204                                    :  1;
     unsigned      int203                                    :  1;
     unsigned      int202                                    :  1;
     unsigned      int201                                    :  1;
     unsigned      int200                                    :  1;
     unsigned      int199                                    :  1;
     unsigned      int198                                    :  1;
     unsigned      int197                                    :  1;
     unsigned      int196                                    :  1;
     unsigned      int195                                    :  1;
     unsigned      int194                                    :  1;
     unsigned      int193                                    :  1;
     unsigned      int192                                    :  1;
#else    /* Little Endian */
     unsigned      int192                                    :  1;
     unsigned      int193                                    :  1;
     unsigned      int194                                    :  1;
     unsigned      int195                                    :  1;
     unsigned      int196                                    :  1;
     unsigned      int197                                    :  1;
     unsigned      int198                                    :  1;
     unsigned      int199                                    :  1;
     unsigned      int200                                    :  1;
     unsigned      int201                                    :  1;
     unsigned      int202                                    :  1;
     unsigned      int203                                    :  1;
     unsigned      int204                                    :  1;
     unsigned      int205                                    :  1;
     unsigned      int206                                    :  1;
     unsigned      int207                                    :  1;
     unsigned      int208                                    :  1;
     unsigned      int209                                    :  1;
     unsigned      int210                                    :  1;
     unsigned      int211                                    :  1;
     unsigned      int212                                    :  1;
     unsigned      int213                                    :  1;
     unsigned      int214                                    :  1;
     unsigned      int215                                    :  1;
     unsigned      int216                                    :  1;
     unsigned      int217                                    :  1;
     unsigned      int218                                    :  1;
     unsigned      int219                                    :  1;
     unsigned      int220                                    :  1;
     unsigned      int221                                    :  1;
     unsigned      int222                                    :  1;
     unsigned      int223                                    :  1;
#endif
} ncp_nca_itp_interrupt6_en_r_t;

/*! @struct ncp_nca_itp_interrupt7_en_r_t
 *  @brief Interrupt Enable Register
 *  @details This register enables interrupts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt7_en_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int255 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> NCAV3 CFG FIFO OF Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int254 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> NCAV3 CFG FIFO UF Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int253 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> TIL START task bp asserted: ll_ieord_size>thresh Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int252 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> TIL START task bp asserted: ll_ieunord_size>thresh
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int251 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> TIL START task bp asserted: ncav3_activitycounter_bcam_current_value>thresh
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int250 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> TIL START task bp asserted: ncav3_activitycounter_bcam_current_value>thresh
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int249 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> TIL START task bp asserted: tqbp_pergid_unissued_Q
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int248 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> TIL START task bp asserted: tqbp_pertq_unissuedqueued_Q
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int247 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> TIL START task bp asserted: tqbp_pertq_unissued_Q
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int246 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> TIL START task bp asserted. eng_til_start_bp Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int245 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> format0 Header Separate override: Task Error or Nack
 *        Task: HS 1 -> 0 Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int244 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> format0 Header Separate override: SEG[0]=FixedPool
 *        task: HS 0 -> 1 Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int243 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> format0 Header Separate override: PTRCNT=0 task: HS
 *        0 -> 1 Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int242 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> format0 Header Separate override: QPM exception task:
 *        HS 1->0 Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int241 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int240 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int239 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int238 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> reserved Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int237 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> ram_qpm_online_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int236 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> ram_ipd2_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int235 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> ram_tqbp_pergidthresh_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int234 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> ram_tqbp_pergid_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int233 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> ram_tqbp_pertq1thresh_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int232 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ram_tqbp_pertq1_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int231 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> ram_qpm_qstatus mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int230 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ram_tpdq mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int229 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> multi_output_fifo_mem_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int228 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> multi_output_state_mem_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int227 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> multi_output_cfg_mem_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int226 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> ll_completion_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int225 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ll_completion_ram_error mbe Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int224 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ll_completion_ram_error mbe Enable </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt7_en_r_t
 *
 * Implemented by: 
 *      en7
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int255                                    :  1;
     unsigned      int254                                    :  1;
     unsigned      int253                                    :  1;
     unsigned      int252                                    :  1;
     unsigned      int251                                    :  1;
     unsigned      int250                                    :  1;
     unsigned      int249                                    :  1;
     unsigned      int248                                    :  1;
     unsigned      int247                                    :  1;
     unsigned      int246                                    :  1;
     unsigned      int245                                    :  1;
     unsigned      int244                                    :  1;
     unsigned      int243                                    :  1;
     unsigned      int242                                    :  1;
     unsigned      int241                                    :  1;
     unsigned      int240                                    :  1;
     unsigned      int239                                    :  1;
     unsigned      int238                                    :  1;
     unsigned      int237                                    :  1;
     unsigned      int236                                    :  1;
     unsigned      int235                                    :  1;
     unsigned      int234                                    :  1;
     unsigned      int233                                    :  1;
     unsigned      int232                                    :  1;
     unsigned      int231                                    :  1;
     unsigned      int230                                    :  1;
     unsigned      int229                                    :  1;
     unsigned      int228                                    :  1;
     unsigned      int227                                    :  1;
     unsigned      int226                                    :  1;
     unsigned      int225                                    :  1;
     unsigned      int224                                    :  1;
#else    /* Little Endian */
     unsigned      int224                                    :  1;
     unsigned      int225                                    :  1;
     unsigned      int226                                    :  1;
     unsigned      int227                                    :  1;
     unsigned      int228                                    :  1;
     unsigned      int229                                    :  1;
     unsigned      int230                                    :  1;
     unsigned      int231                                    :  1;
     unsigned      int232                                    :  1;
     unsigned      int233                                    :  1;
     unsigned      int234                                    :  1;
     unsigned      int235                                    :  1;
     unsigned      int236                                    :  1;
     unsigned      int237                                    :  1;
     unsigned      int238                                    :  1;
     unsigned      int239                                    :  1;
     unsigned      int240                                    :  1;
     unsigned      int241                                    :  1;
     unsigned      int242                                    :  1;
     unsigned      int243                                    :  1;
     unsigned      int244                                    :  1;
     unsigned      int245                                    :  1;
     unsigned      int246                                    :  1;
     unsigned      int247                                    :  1;
     unsigned      int248                                    :  1;
     unsigned      int249                                    :  1;
     unsigned      int250                                    :  1;
     unsigned      int251                                    :  1;
     unsigned      int252                                    :  1;
     unsigned      int253                                    :  1;
     unsigned      int254                                    :  1;
     unsigned      int255                                    :  1;
#endif
} ncp_nca_itp_interrupt7_en_r_t;

/*! @struct ncp_nca_itp_interrupt0_force_r_t
 *  @brief Interrupt Force Register
 *  @details This address is an alias for the Interrupt Status register
		that allows normal CFG writes (as opposed to the Clear-On-Write-One
		behavior if the Interrupt Status register address is used).  This
		allows CFG to set interrupt bits for testing purposes.  Reading this
		address returns the current value of the Interrupt Status Register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt0_force_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int31 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> cfg_smon_int Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int30 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> cfg_synd_status_int Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int29 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> task Copied Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int28 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> NLINK parity error observed Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int27 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> db_in_qpm_qstatus_ready=0. QPM should not drop this
 *        ready, this is HW misconnect or QPM error Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int26 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> MTP returns a ERROR response Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int25 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> MTP returns a NACK response Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int24 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> err_completion_check_opcq. When aPCQ task is returned
 *        the sequence number does not match the stored task.
 *        THis can occur when task with task completion are
 *        returned out of order or are missing/duplicated. Causes
 *        system corruption Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int23 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> err_completion_check_apcq. When aPCQ task is returned
 *        the sequence number does not match the stored task.
 *        THis can occur when task with consumer pointer advance
 *        are returned out of order or are missing/duplicated.
 *        Causes system corruption Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int22 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> err_ieordready_empty. When scheduling a iPCQ & GID
 *        selected Ordered-Ready that have no task avaible.
 *        deselect the iPCQ & GID, Clean up state and return
 *        to begining of scheduling. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int21 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> err_ieordsched_empty. When scheduling a iPCQ & GID
 *        selected Ordered-Scheduled that have no task avaible.
 *        deselect the iPCQ & GID, Clean up state and return
 *        to begining of scheduling. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int20 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> err_schedsort. WHen scheduling a iPCQ & GID selected
 *        flow with all LL empty. THis could result from inconsistency
 *        in config IPC vs ipcq2god. Clean up state and return
 *        to begining of scheduling. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int19 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> err_notqpri. When scheduling a iPCQ & GID selected
 *        flow with no task availble. THis could result from
 *        inconsistency in config IPC vs ipcq2god. Clean up
 *        state and return to begining of scheduling. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int18 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> err_ieunord_empty. When scheduling a iPCQ & GID selected
 *        Unordered that have no task avaible. deselect the
 *        iPCQ & GID, Clean up state and return to begining
 *        of scheduling. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int17 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> err_activitycount. One of the activity counters reported
 *        an error. No recovery possible, must be a misconfigure
 *        of the threshold Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int16 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> AW_fifo FIFO of Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int15 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> err_hitidle. Ordered flow HIT in BCAM and the state
 *        is IDLE. THis is not expected but not illegal, continue
 *        normal operation Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int14 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> err_c_enqcnt_of. ieOrdered state updated during task
 *        completion and overflow of enqueue count. Continue
 *        normal operation Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int13 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> err_c_schcnt_of. ieOrdered state updated during task
 *        completion and overflow of scheduled count. Continue
 *        normal operation Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int12 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> err_s_enqcnt_of. ieOrdered state updated during task
 *        scheudle and overflow of enqueue count. Continue normal
 *        operation Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int11 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> err_s_schcnt_of. ieOrdered state updated during task
 *        scheudle and overflow of scheduled count. Continue
 *        normal operation Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int10 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> err_e_enqcnt_of. ieOrdered state updated during task
 *        enqueue and overflow of enqueue count. Continue normal
 *        operation Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int9 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> err_e_schcnt_of. ieOrdered state updated during task
 *        enqueue and overflow of scheduled count. Continue
 *        normal operation Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int8 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> err_complete_empty. Task completion arrives from OTP
 *        and the NCAP,PGIT list in LL_completion is empty.
 *        drop the reqeust and continue normal operation Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int7 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> err_ieord_empty. When scheduling a iPCQ & GID selected
 *        Ordered that have no task avaible. deselect the iPCQ
 *        & GID, Clean up state and return to begining of scheduling.
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int6 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> err_ord_flowid. After scheduling the flowID popped
 *        from the ieUnordered LL does not match the flowID
 *        from the scheudling (ieOrdReady or ieOrdSched LL).
 *        continue normal operation. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int5 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> err_unord_flowid. After scheduling the flowID popped
 *        from the ieUnordered LL does not match the flowID
 *        from the scheudling. Should always be zero. continue
 *        normal operation. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int4 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> err_dynamic. error triggered during dynamic operation
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int3 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> multi_output_fifo_overflow Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int2 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> multi_output_fifo_underflow Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ncav3_cfg for read_err Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ncav3_cfg write_err Force </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt0_force_r_t
 *
 * Implemented by: 
 *      frc0
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int31                                     :  1;
     unsigned      int30                                     :  1;
     unsigned      int29                                     :  1;
     unsigned      int28                                     :  1;
     unsigned      int27                                     :  1;
     unsigned      int26                                     :  1;
     unsigned      int25                                     :  1;
     unsigned      int24                                     :  1;
     unsigned      int23                                     :  1;
     unsigned      int22                                     :  1;
     unsigned      int21                                     :  1;
     unsigned      int20                                     :  1;
     unsigned      int19                                     :  1;
     unsigned      int18                                     :  1;
     unsigned      int17                                     :  1;
     unsigned      int16                                     :  1;
     unsigned      int15                                     :  1;
     unsigned      int14                                     :  1;
     unsigned      int13                                     :  1;
     unsigned      int12                                     :  1;
     unsigned      int11                                     :  1;
     unsigned      int10                                     :  1;
     unsigned      int9                                      :  1;
     unsigned      int8                                      :  1;
     unsigned      int7                                      :  1;
     unsigned      int6                                      :  1;
     unsigned      int5                                      :  1;
     unsigned      int4                                      :  1;
     unsigned      int3                                      :  1;
     unsigned      int2                                      :  1;
     unsigned      int1                                      :  1;
     unsigned      int0                                      :  1;
#else    /* Little Endian */
     unsigned      int0                                      :  1;
     unsigned      int1                                      :  1;
     unsigned      int2                                      :  1;
     unsigned      int3                                      :  1;
     unsigned      int4                                      :  1;
     unsigned      int5                                      :  1;
     unsigned      int6                                      :  1;
     unsigned      int7                                      :  1;
     unsigned      int8                                      :  1;
     unsigned      int9                                      :  1;
     unsigned      int10                                     :  1;
     unsigned      int11                                     :  1;
     unsigned      int12                                     :  1;
     unsigned      int13                                     :  1;
     unsigned      int14                                     :  1;
     unsigned      int15                                     :  1;
     unsigned      int16                                     :  1;
     unsigned      int17                                     :  1;
     unsigned      int18                                     :  1;
     unsigned      int19                                     :  1;
     unsigned      int20                                     :  1;
     unsigned      int21                                     :  1;
     unsigned      int22                                     :  1;
     unsigned      int23                                     :  1;
     unsigned      int24                                     :  1;
     unsigned      int25                                     :  1;
     unsigned      int26                                     :  1;
     unsigned      int27                                     :  1;
     unsigned      int28                                     :  1;
     unsigned      int29                                     :  1;
     unsigned      int30                                     :  1;
     unsigned      int31                                     :  1;
#endif
} ncp_nca_itp_interrupt0_force_r_t;

/*! @struct ncp_nca_itp_interrupt1_force_r_t
 *  @brief Interrupt Force Register
 *  @details This address is an alias for the Interrupt Status register
		that allows normal CFG writes (as opposed to the Clear-On-Write-One
		behavior if the Interrupt Status register address is used).  This
		allows CFG to set interrupt bits for testing purposes.  Reading this
		address returns the current value of the Interrupt Status Register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt1_force_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int63 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> drop unscheduled Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int62 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> drop ordered Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int61 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> drop unordered Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int60 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int59 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int58 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int57 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int56 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int55 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int54 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int53 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> SYND21 err_ipcq_credits_of_zero Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int52 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> SYND20 ipcq_multifull_Q Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int51 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> SYND19 ipcq_full_Q Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int50 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> SYND18 err_ipcqsizeof_c1 Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int49 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> SYND17 err_ipcqsizeof_c0 Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int48 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> SYND16 err_ipcqsizeof_e Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int47 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> SYND15 err_ipcq_credits_of_inc Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int46 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> SYND14 err_ipcq_credits_of_dec Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int45 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> SYND13 err_of Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int44 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> SYND12 err_copyerror Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int43 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> SYND11 cam_ieordered_ERROR Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int42 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> SYND10 addrconvert_in_out_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int41 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> SYND09 addrconvert_alloc_out_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int40 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> SYND08 ll_completion_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int39 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> SYND07 ll_ieordsched_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int38 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> SYND06 ll_ieordready_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int37 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> SYND05 ll_ieord_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int36 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> SYND04 ll_ieunord_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int35 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> SYND03 ll_preproc_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int34 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> SYND02 itp_system_error_2 Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int33 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> SYND01 itp_system_error_1 Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int32 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> SYND00 itp_system_error_0 Force </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt1_force_r_t
 *
 * Implemented by: 
 *      frc1
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int63                                     :  1;
     unsigned      int62                                     :  1;
     unsigned      int61                                     :  1;
     unsigned      int60                                     :  1;
     unsigned      int59                                     :  1;
     unsigned      int58                                     :  1;
     unsigned      int57                                     :  1;
     unsigned      int56                                     :  1;
     unsigned      int55                                     :  1;
     unsigned      int54                                     :  1;
     unsigned      int53                                     :  1;
     unsigned      int52                                     :  1;
     unsigned      int51                                     :  1;
     unsigned      int50                                     :  1;
     unsigned      int49                                     :  1;
     unsigned      int48                                     :  1;
     unsigned      int47                                     :  1;
     unsigned      int46                                     :  1;
     unsigned      int45                                     :  1;
     unsigned      int44                                     :  1;
     unsigned      int43                                     :  1;
     unsigned      int42                                     :  1;
     unsigned      int41                                     :  1;
     unsigned      int40                                     :  1;
     unsigned      int39                                     :  1;
     unsigned      int38                                     :  1;
     unsigned      int37                                     :  1;
     unsigned      int36                                     :  1;
     unsigned      int35                                     :  1;
     unsigned      int34                                     :  1;
     unsigned      int33                                     :  1;
     unsigned      int32                                     :  1;
#else    /* Little Endian */
     unsigned      int32                                     :  1;
     unsigned      int33                                     :  1;
     unsigned      int34                                     :  1;
     unsigned      int35                                     :  1;
     unsigned      int36                                     :  1;
     unsigned      int37                                     :  1;
     unsigned      int38                                     :  1;
     unsigned      int39                                     :  1;
     unsigned      int40                                     :  1;
     unsigned      int41                                     :  1;
     unsigned      int42                                     :  1;
     unsigned      int43                                     :  1;
     unsigned      int44                                     :  1;
     unsigned      int45                                     :  1;
     unsigned      int46                                     :  1;
     unsigned      int47                                     :  1;
     unsigned      int48                                     :  1;
     unsigned      int49                                     :  1;
     unsigned      int50                                     :  1;
     unsigned      int51                                     :  1;
     unsigned      int52                                     :  1;
     unsigned      int53                                     :  1;
     unsigned      int54                                     :  1;
     unsigned      int55                                     :  1;
     unsigned      int56                                     :  1;
     unsigned      int57                                     :  1;
     unsigned      int58                                     :  1;
     unsigned      int59                                     :  1;
     unsigned      int60                                     :  1;
     unsigned      int61                                     :  1;
     unsigned      int62                                     :  1;
     unsigned      int63                                     :  1;
#endif
} ncp_nca_itp_interrupt1_force_r_t;

/*! @struct ncp_nca_itp_interrupt2_force_r_t
 *  @brief Interrupt Force Register
 *  @details This address is an alias for the Interrupt Status register
		that allows normal CFG writes (as opposed to the Clear-On-Write-One
		behavior if the Interrupt Status register address is used).  This
		allows CFG to set interrupt bits for testing purposes.  Reading this
		address returns the current value of the Interrupt Status Register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt2_force_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int95 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> ll_completion_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int94 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> ll_ieordsched_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int93 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> ll_ieordsched_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int92 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> ll_ieordsched_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int91 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> ll_ieordsched_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int90 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> ll_ieordready_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int89 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> ll_ieordready_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int88 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> ll_ieordready_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int87 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> ll_ieordready_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int86 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> ll_ieord_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int85 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> ll_ieord_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int84 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> ll_ieord_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int83 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> ll_ieord_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int82 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> ll_ieunord_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int81 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> ll_ieunord_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int80 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> ll_ieunord_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int79 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> ll_ieunord_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int78 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> ll_preproc_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int77 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> ll_preproc_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int76 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> ll_preproc_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int75 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> ll_preproc_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int74 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> addrconvert_in_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int73 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> addrconvert_in_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int72 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> addrconvert_alloc_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int71 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> addrconvert_alloc_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int70 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ram_tqbp_pertq0_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int69 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> ram_tqbp_pertq0thresh_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int68 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> ram_ncap2ipcq_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int67 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> ram_gid2tq access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int66 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> ram_ieordered_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int65 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ram_ipd_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int64 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ram_tpd_error access error Force </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt2_force_r_t
 *
 * Implemented by: 
 *      frc2
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int95                                     :  1;
     unsigned      int94                                     :  1;
     unsigned      int93                                     :  1;
     unsigned      int92                                     :  1;
     unsigned      int91                                     :  1;
     unsigned      int90                                     :  1;
     unsigned      int89                                     :  1;
     unsigned      int88                                     :  1;
     unsigned      int87                                     :  1;
     unsigned      int86                                     :  1;
     unsigned      int85                                     :  1;
     unsigned      int84                                     :  1;
     unsigned      int83                                     :  1;
     unsigned      int82                                     :  1;
     unsigned      int81                                     :  1;
     unsigned      int80                                     :  1;
     unsigned      int79                                     :  1;
     unsigned      int78                                     :  1;
     unsigned      int77                                     :  1;
     unsigned      int76                                     :  1;
     unsigned      int75                                     :  1;
     unsigned      int74                                     :  1;
     unsigned      int73                                     :  1;
     unsigned      int72                                     :  1;
     unsigned      int71                                     :  1;
     unsigned      int70                                     :  1;
     unsigned      int69                                     :  1;
     unsigned      int68                                     :  1;
     unsigned      int67                                     :  1;
     unsigned      int66                                     :  1;
     unsigned      int65                                     :  1;
     unsigned      int64                                     :  1;
#else    /* Little Endian */
     unsigned      int64                                     :  1;
     unsigned      int65                                     :  1;
     unsigned      int66                                     :  1;
     unsigned      int67                                     :  1;
     unsigned      int68                                     :  1;
     unsigned      int69                                     :  1;
     unsigned      int70                                     :  1;
     unsigned      int71                                     :  1;
     unsigned      int72                                     :  1;
     unsigned      int73                                     :  1;
     unsigned      int74                                     :  1;
     unsigned      int75                                     :  1;
     unsigned      int76                                     :  1;
     unsigned      int77                                     :  1;
     unsigned      int78                                     :  1;
     unsigned      int79                                     :  1;
     unsigned      int80                                     :  1;
     unsigned      int81                                     :  1;
     unsigned      int82                                     :  1;
     unsigned      int83                                     :  1;
     unsigned      int84                                     :  1;
     unsigned      int85                                     :  1;
     unsigned      int86                                     :  1;
     unsigned      int87                                     :  1;
     unsigned      int88                                     :  1;
     unsigned      int89                                     :  1;
     unsigned      int90                                     :  1;
     unsigned      int91                                     :  1;
     unsigned      int92                                     :  1;
     unsigned      int93                                     :  1;
     unsigned      int94                                     :  1;
     unsigned      int95                                     :  1;
#endif
} ncp_nca_itp_interrupt2_force_r_t;

/*! @struct ncp_nca_itp_interrupt3_force_r_t
 *  @brief Interrupt Force Register
 *  @details This address is an alias for the Interrupt Status register
		that allows normal CFG writes (as opposed to the Clear-On-Write-One
		behavior if the Interrupt Status register address is used).  This
		allows CFG to set interrupt bits for testing purposes.  Reading this
		address returns the current value of the Interrupt Status Register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt3_force_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int127 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> bresp trace1 Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int126 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> bresp trace0 Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int125 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> bresp QPM Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int124 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> bresp otp_itp_tx Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int123 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> bresp itp_mtp_tx Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int122 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> bresp itp_mtp_req Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int121 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> bresp ncav3_ipcq_res Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int120 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> bresp ncav3_ipcq_req Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int119 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int118 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int117 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int116 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int115 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int114 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int113 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int112 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int111 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int110 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int109 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> ram_qpm_online_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int108 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> ram_ipd2_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int107 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> ram_tqbp_pergidthresh_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int106 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> ram_tqbp_pergid_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int105 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> ram_tqbp_perrq1thresh_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int104 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ram_tqbp_pertq1_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int103 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> ram_qpm_qstatus access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int102 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ram_tpdq_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int101 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> multi_output_fifo_mem_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int100 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> multi_output_state_mem_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int99 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> multi_output_cfg_mem_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int98 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> ll_completion_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int97 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ll_completion_ram_error access error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int96 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ll_completion_ram_error access error Force </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt3_force_r_t
 *
 * Implemented by: 
 *      frc3
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int127                                    :  1;
     unsigned      int126                                    :  1;
     unsigned      int125                                    :  1;
     unsigned      int124                                    :  1;
     unsigned      int123                                    :  1;
     unsigned      int122                                    :  1;
     unsigned      int121                                    :  1;
     unsigned      int120                                    :  1;
     unsigned      int119                                    :  1;
     unsigned      int118                                    :  1;
     unsigned      int117                                    :  1;
     unsigned      int116                                    :  1;
     unsigned      int115                                    :  1;
     unsigned      int114                                    :  1;
     unsigned      int113                                    :  1;
     unsigned      int112                                    :  1;
     unsigned      int111                                    :  1;
     unsigned      int110                                    :  1;
     unsigned      int109                                    :  1;
     unsigned      int108                                    :  1;
     unsigned      int107                                    :  1;
     unsigned      int106                                    :  1;
     unsigned      int105                                    :  1;
     unsigned      int104                                    :  1;
     unsigned      int103                                    :  1;
     unsigned      int102                                    :  1;
     unsigned      int101                                    :  1;
     unsigned      int100                                    :  1;
     unsigned      int99                                     :  1;
     unsigned      int98                                     :  1;
     unsigned      int97                                     :  1;
     unsigned      int96                                     :  1;
#else    /* Little Endian */
     unsigned      int96                                     :  1;
     unsigned      int97                                     :  1;
     unsigned      int98                                     :  1;
     unsigned      int99                                     :  1;
     unsigned      int100                                    :  1;
     unsigned      int101                                    :  1;
     unsigned      int102                                    :  1;
     unsigned      int103                                    :  1;
     unsigned      int104                                    :  1;
     unsigned      int105                                    :  1;
     unsigned      int106                                    :  1;
     unsigned      int107                                    :  1;
     unsigned      int108                                    :  1;
     unsigned      int109                                    :  1;
     unsigned      int110                                    :  1;
     unsigned      int111                                    :  1;
     unsigned      int112                                    :  1;
     unsigned      int113                                    :  1;
     unsigned      int114                                    :  1;
     unsigned      int115                                    :  1;
     unsigned      int116                                    :  1;
     unsigned      int117                                    :  1;
     unsigned      int118                                    :  1;
     unsigned      int119                                    :  1;
     unsigned      int120                                    :  1;
     unsigned      int121                                    :  1;
     unsigned      int122                                    :  1;
     unsigned      int123                                    :  1;
     unsigned      int124                                    :  1;
     unsigned      int125                                    :  1;
     unsigned      int126                                    :  1;
     unsigned      int127                                    :  1;
#endif
} ncp_nca_itp_interrupt3_force_r_t;

/*! @struct ncp_nca_itp_interrupt4_force_r_t
 *  @brief Interrupt Force Register
 *  @details This address is an alias for the Interrupt Status register
		that allows normal CFG writes (as opposed to the Clear-On-Write-One
		behavior if the Interrupt Status register address is used).  This
		allows CFG to set interrupt bits for testing purposes.  Reading this
		address returns the current value of the Interrupt Status Register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt4_force_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int159 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> ll_completion_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int158 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> ll_ieordsched_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int157 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> ll_ieordsched_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int156 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> ll_ieordsched_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int155 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> ll_ieordsched_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int154 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> ll_ieordready_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int153 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> ll_ieordready_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int152 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> ll_ieordready_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int151 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> ll_ieordready_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int150 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> ll_ieord_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int149 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> ll_ieord_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int148 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> ll_ieord_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int147 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> ll_ieord_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int146 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> ll_ieunord_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int145 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> ll_ieunord_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int144 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> ll_ieunord_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int143 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> ll_ieunord_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int142 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> ll_preproc_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int141 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> ll_preproc_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int140 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> ll_preproc_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int139 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> ll_preproc_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int138 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> addrconvert_in_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int137 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> addrconvert_in_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int136 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> addrconvert_alloc_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int135 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> addrconvert_alloc_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int134 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ram_tqbp_pertq0_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int133 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> ram_tqbp_pertq0thresh_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int132 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> ram_ncap2ipcq_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int131 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> ram_gid2tq sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int130 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> ram_ieordered_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int129 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ram_ipd_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int128 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ram_tpd_error sbe Force </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt4_force_r_t
 *
 * Implemented by: 
 *      frc4
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int159                                    :  1;
     unsigned      int158                                    :  1;
     unsigned      int157                                    :  1;
     unsigned      int156                                    :  1;
     unsigned      int155                                    :  1;
     unsigned      int154                                    :  1;
     unsigned      int153                                    :  1;
     unsigned      int152                                    :  1;
     unsigned      int151                                    :  1;
     unsigned      int150                                    :  1;
     unsigned      int149                                    :  1;
     unsigned      int148                                    :  1;
     unsigned      int147                                    :  1;
     unsigned      int146                                    :  1;
     unsigned      int145                                    :  1;
     unsigned      int144                                    :  1;
     unsigned      int143                                    :  1;
     unsigned      int142                                    :  1;
     unsigned      int141                                    :  1;
     unsigned      int140                                    :  1;
     unsigned      int139                                    :  1;
     unsigned      int138                                    :  1;
     unsigned      int137                                    :  1;
     unsigned      int136                                    :  1;
     unsigned      int135                                    :  1;
     unsigned      int134                                    :  1;
     unsigned      int133                                    :  1;
     unsigned      int132                                    :  1;
     unsigned      int131                                    :  1;
     unsigned      int130                                    :  1;
     unsigned      int129                                    :  1;
     unsigned      int128                                    :  1;
#else    /* Little Endian */
     unsigned      int128                                    :  1;
     unsigned      int129                                    :  1;
     unsigned      int130                                    :  1;
     unsigned      int131                                    :  1;
     unsigned      int132                                    :  1;
     unsigned      int133                                    :  1;
     unsigned      int134                                    :  1;
     unsigned      int135                                    :  1;
     unsigned      int136                                    :  1;
     unsigned      int137                                    :  1;
     unsigned      int138                                    :  1;
     unsigned      int139                                    :  1;
     unsigned      int140                                    :  1;
     unsigned      int141                                    :  1;
     unsigned      int142                                    :  1;
     unsigned      int143                                    :  1;
     unsigned      int144                                    :  1;
     unsigned      int145                                    :  1;
     unsigned      int146                                    :  1;
     unsigned      int147                                    :  1;
     unsigned      int148                                    :  1;
     unsigned      int149                                    :  1;
     unsigned      int150                                    :  1;
     unsigned      int151                                    :  1;
     unsigned      int152                                    :  1;
     unsigned      int153                                    :  1;
     unsigned      int154                                    :  1;
     unsigned      int155                                    :  1;
     unsigned      int156                                    :  1;
     unsigned      int157                                    :  1;
     unsigned      int158                                    :  1;
     unsigned      int159                                    :  1;
#endif
} ncp_nca_itp_interrupt4_force_r_t;

/*! @struct ncp_nca_itp_interrupt5_force_r_t
 *  @brief Interrupt Force Register
 *  @details This address is an alias for the Interrupt Status register
		that allows normal CFG writes (as opposed to the Clear-On-Write-One
		behavior if the Interrupt Status register address is used).  This
		allows CFG to set interrupt bits for testing purposes.  Reading this
		address returns the current value of the Interrupt Status Register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt5_force_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int191 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> err_drop[10] nack COPY pointer request Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int190 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> err_drop[9] nack HS pointer request, or task error
 *        from err_drop[8:0] Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int189 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> err_drop[8] copy error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int188 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> err_drop[7] addrconvert Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int187 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> err_drop[6] task ptrcnt=0 & TPD HS=0 Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int186 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> err_drop[5] unscheduled task (exception ACK) and ptrcnt
 *        is not zero Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int185 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> err_drop[4] malformed task Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int184 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> err_drop[3] unscheduled task and QUEUE not online
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int183 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> err_drop[2] unscheudled task (not exception ACK) and
 *        QPM issued drop command Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int182 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> err_drop[1] VPP task had taskerror set Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int181 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> err_drop[0] TPD TQ not online Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int180 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> err_purge[1] detect NCAP,PGIT traffic on task completion
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int179 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> err_purge[0] detect NCAP,PGIT traffic on NLINK ipcq
 *        req interface Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int178 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> err_drop[11] Task with PTR0=Fixed Pool & TPD HS=0
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int177 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int176 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int175 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int174 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int173 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> ram_qpm_online_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int172 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> ram_ipd2_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int171 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> ram_tqbp_pergidthresh_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int170 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> ram_tqbp_pergid_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int169 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> ram_tqbp_pertq1thresh_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int168 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ram_tqbp_pertq1_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int167 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> ram_qpm_qstatus sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int166 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ram_tpdq sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int165 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> multi_output_fifo_mem_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int164 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> multi_output_state_mem_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int163 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> multi_output_cfg_mem_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int162 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> ll_completion_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int161 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ll_completion_ram_error sbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int160 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ll_completion_ram_error sbe Force </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt5_force_r_t
 *
 * Implemented by: 
 *      frc5
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int191                                    :  1;
     unsigned      int190                                    :  1;
     unsigned      int189                                    :  1;
     unsigned      int188                                    :  1;
     unsigned      int187                                    :  1;
     unsigned      int186                                    :  1;
     unsigned      int185                                    :  1;
     unsigned      int184                                    :  1;
     unsigned      int183                                    :  1;
     unsigned      int182                                    :  1;
     unsigned      int181                                    :  1;
     unsigned      int180                                    :  1;
     unsigned      int179                                    :  1;
     unsigned      int178                                    :  1;
     unsigned      int177                                    :  1;
     unsigned      int176                                    :  1;
     unsigned      int175                                    :  1;
     unsigned      int174                                    :  1;
     unsigned      int173                                    :  1;
     unsigned      int172                                    :  1;
     unsigned      int171                                    :  1;
     unsigned      int170                                    :  1;
     unsigned      int169                                    :  1;
     unsigned      int168                                    :  1;
     unsigned      int167                                    :  1;
     unsigned      int166                                    :  1;
     unsigned      int165                                    :  1;
     unsigned      int164                                    :  1;
     unsigned      int163                                    :  1;
     unsigned      int162                                    :  1;
     unsigned      int161                                    :  1;
     unsigned      int160                                    :  1;
#else    /* Little Endian */
     unsigned      int160                                    :  1;
     unsigned      int161                                    :  1;
     unsigned      int162                                    :  1;
     unsigned      int163                                    :  1;
     unsigned      int164                                    :  1;
     unsigned      int165                                    :  1;
     unsigned      int166                                    :  1;
     unsigned      int167                                    :  1;
     unsigned      int168                                    :  1;
     unsigned      int169                                    :  1;
     unsigned      int170                                    :  1;
     unsigned      int171                                    :  1;
     unsigned      int172                                    :  1;
     unsigned      int173                                    :  1;
     unsigned      int174                                    :  1;
     unsigned      int175                                    :  1;
     unsigned      int176                                    :  1;
     unsigned      int177                                    :  1;
     unsigned      int178                                    :  1;
     unsigned      int179                                    :  1;
     unsigned      int180                                    :  1;
     unsigned      int181                                    :  1;
     unsigned      int182                                    :  1;
     unsigned      int183                                    :  1;
     unsigned      int184                                    :  1;
     unsigned      int185                                    :  1;
     unsigned      int186                                    :  1;
     unsigned      int187                                    :  1;
     unsigned      int188                                    :  1;
     unsigned      int189                                    :  1;
     unsigned      int190                                    :  1;
     unsigned      int191                                    :  1;
#endif
} ncp_nca_itp_interrupt5_force_r_t;

/*! @struct ncp_nca_itp_interrupt6_force_r_t
 *  @brief Interrupt Force Register
 *  @details This address is an alias for the Interrupt Status register
		that allows normal CFG writes (as opposed to the Clear-On-Write-One
		behavior if the Interrupt Status register address is used).  This
		allows CFG to set interrupt bits for testing purposes.  Reading this
		address returns the current value of the Interrupt Status Register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt6_force_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int223 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> ll_completion_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int222 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> ll_ieordsched_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int221 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> ll_ieordsched_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int220 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> ll_ieordsched_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int219 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> ll_ieordsched_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int218 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> ll_ieordready_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int217 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> ll_ieordready_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int216 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> ll_ieordready_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int215 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> ll_ieordready_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int214 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> ll_ieord_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int213 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> ll_ieord_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int212 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> ll_ieord_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int211 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> ll_ieord_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int210 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> ll_ieunord_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int209 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> ll_ieunord_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int208 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> ll_ieunord_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int207 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> ll_ieunord_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int206 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> ll_preproc_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int205 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> ll_preproc_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int204 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> ll_preproc_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int203 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> ll_preproc_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int202 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> addrconvert_in_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int201 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> addrconvert_in_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int200 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> addrconvert_alloc_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int199 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> addrconvert_alloc_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int198 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ram_tqbp_pertq0_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int197 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> ram_tqbpthresh_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int196 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> ram_ncap2ipcq_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int195 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> ram_tq2gid mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int194 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> ram_ieordered_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int193 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ram_ipd_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int192 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ram_tpd_error mbe Force </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt6_force_r_t
 *
 * Implemented by: 
 *      frc6
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int223                                    :  1;
     unsigned      int222                                    :  1;
     unsigned      int221                                    :  1;
     unsigned      int220                                    :  1;
     unsigned      int219                                    :  1;
     unsigned      int218                                    :  1;
     unsigned      int217                                    :  1;
     unsigned      int216                                    :  1;
     unsigned      int215                                    :  1;
     unsigned      int214                                    :  1;
     unsigned      int213                                    :  1;
     unsigned      int212                                    :  1;
     unsigned      int211                                    :  1;
     unsigned      int210                                    :  1;
     unsigned      int209                                    :  1;
     unsigned      int208                                    :  1;
     unsigned      int207                                    :  1;
     unsigned      int206                                    :  1;
     unsigned      int205                                    :  1;
     unsigned      int204                                    :  1;
     unsigned      int203                                    :  1;
     unsigned      int202                                    :  1;
     unsigned      int201                                    :  1;
     unsigned      int200                                    :  1;
     unsigned      int199                                    :  1;
     unsigned      int198                                    :  1;
     unsigned      int197                                    :  1;
     unsigned      int196                                    :  1;
     unsigned      int195                                    :  1;
     unsigned      int194                                    :  1;
     unsigned      int193                                    :  1;
     unsigned      int192                                    :  1;
#else    /* Little Endian */
     unsigned      int192                                    :  1;
     unsigned      int193                                    :  1;
     unsigned      int194                                    :  1;
     unsigned      int195                                    :  1;
     unsigned      int196                                    :  1;
     unsigned      int197                                    :  1;
     unsigned      int198                                    :  1;
     unsigned      int199                                    :  1;
     unsigned      int200                                    :  1;
     unsigned      int201                                    :  1;
     unsigned      int202                                    :  1;
     unsigned      int203                                    :  1;
     unsigned      int204                                    :  1;
     unsigned      int205                                    :  1;
     unsigned      int206                                    :  1;
     unsigned      int207                                    :  1;
     unsigned      int208                                    :  1;
     unsigned      int209                                    :  1;
     unsigned      int210                                    :  1;
     unsigned      int211                                    :  1;
     unsigned      int212                                    :  1;
     unsigned      int213                                    :  1;
     unsigned      int214                                    :  1;
     unsigned      int215                                    :  1;
     unsigned      int216                                    :  1;
     unsigned      int217                                    :  1;
     unsigned      int218                                    :  1;
     unsigned      int219                                    :  1;
     unsigned      int220                                    :  1;
     unsigned      int221                                    :  1;
     unsigned      int222                                    :  1;
     unsigned      int223                                    :  1;
#endif
} ncp_nca_itp_interrupt6_force_r_t;

/*! @struct ncp_nca_itp_interrupt7_force_r_t
 *  @brief Interrupt Force Register
 *  @details This address is an alias for the Interrupt Status register
		that allows normal CFG writes (as opposed to the Clear-On-Write-One
		behavior if the Interrupt Status register address is used).  This
		allows CFG to set interrupt bits for testing purposes.  Reading this
		address returns the current value of the Interrupt Status Register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_interrupt7_force_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param int255 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> NCAV3 CFG FIFO OF Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int254 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> NCAV3 CFG FIFO UF Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int253 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> TIL START task bp asserted: ll_ieord_size>thresh Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int252 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> TIL START task bp asserted: ll_ieunord_size>thresh
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int251 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> TIL START task bp asserted: ncav3_activitycounter_bcam_current_value>thresh
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int250 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> TIL START task bp asserted: ncav3_activitycounter_bcam_current_value>thresh
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int249 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> TIL START task bp asserted: tqbp_pergid_unissued_Q
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int248 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> TIL START task bp asserted: tqbp_pertq_unissuedqueued_Q
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int247 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> TIL START task bp asserted: tqbp_pertq_unissued_Q
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int246 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> TIL START task bp asserted. eng_til_start_bp Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int245 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> format0 Header Separate override: Task Error or Nack
 *        Task: HS 1 -> 0 Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int244 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> format0 Header Separate override: SEG[0]=FixedPool
 *        task: HS 0 -> 1 Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int243 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> format0 Header Separate override: PTRCNT=0 task: HS
 *        0 -> 1 Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int242 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> format0 Header Separate override: QPM exception task:
 *        HS 1->0 Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int241 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int240 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int239 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int238 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> reserved Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int237 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> ram_qpm_online_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int236 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> ram_ipd2_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int235 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> ram_tqbp_pergidthresh_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int234 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> ram_tqbp_pergid_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int233 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> ram_tqbp_pertq1thresh_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int232 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ram_tqbp_pertq1_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int231 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> ram_qpm_qstatus mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int230 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ram_tpdq mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int229 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> multi_output_fifo_mem_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int228 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> multi_output_state_mem_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int227 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> multi_output_cfg_mem_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int226 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> ll_completion_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int225 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ll_completion_ram_error mbe Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int224 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ll_completion_ram_error mbe Force </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_interrupt7_force_r_t
 *
 * Implemented by: 
 *      frc7
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      int255                                    :  1;
     unsigned      int254                                    :  1;
     unsigned      int253                                    :  1;
     unsigned      int252                                    :  1;
     unsigned      int251                                    :  1;
     unsigned      int250                                    :  1;
     unsigned      int249                                    :  1;
     unsigned      int248                                    :  1;
     unsigned      int247                                    :  1;
     unsigned      int246                                    :  1;
     unsigned      int245                                    :  1;
     unsigned      int244                                    :  1;
     unsigned      int243                                    :  1;
     unsigned      int242                                    :  1;
     unsigned      int241                                    :  1;
     unsigned      int240                                    :  1;
     unsigned      int239                                    :  1;
     unsigned      int238                                    :  1;
     unsigned      int237                                    :  1;
     unsigned      int236                                    :  1;
     unsigned      int235                                    :  1;
     unsigned      int234                                    :  1;
     unsigned      int233                                    :  1;
     unsigned      int232                                    :  1;
     unsigned      int231                                    :  1;
     unsigned      int230                                    :  1;
     unsigned      int229                                    :  1;
     unsigned      int228                                    :  1;
     unsigned      int227                                    :  1;
     unsigned      int226                                    :  1;
     unsigned      int225                                    :  1;
     unsigned      int224                                    :  1;
#else    /* Little Endian */
     unsigned      int224                                    :  1;
     unsigned      int225                                    :  1;
     unsigned      int226                                    :  1;
     unsigned      int227                                    :  1;
     unsigned      int228                                    :  1;
     unsigned      int229                                    :  1;
     unsigned      int230                                    :  1;
     unsigned      int231                                    :  1;
     unsigned      int232                                    :  1;
     unsigned      int233                                    :  1;
     unsigned      int234                                    :  1;
     unsigned      int235                                    :  1;
     unsigned      int236                                    :  1;
     unsigned      int237                                    :  1;
     unsigned      int238                                    :  1;
     unsigned      int239                                    :  1;
     unsigned      int240                                    :  1;
     unsigned      int241                                    :  1;
     unsigned      int242                                    :  1;
     unsigned      int243                                    :  1;
     unsigned      int244                                    :  1;
     unsigned      int245                                    :  1;
     unsigned      int246                                    :  1;
     unsigned      int247                                    :  1;
     unsigned      int248                                    :  1;
     unsigned      int249                                    :  1;
     unsigned      int250                                    :  1;
     unsigned      int251                                    :  1;
     unsigned      int252                                    :  1;
     unsigned      int253                                    :  1;
     unsigned      int254                                    :  1;
     unsigned      int255                                    :  1;
#endif
} ncp_nca_itp_interrupt7_force_r_t;

/*! @struct ncp_nca_itp_syndrome_cfg_r_t
 *  @brief null
 *  @details CFG access to Status. Syndrome Configuration register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_syndrome_cfg_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 26 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param synd_interruptenable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> 1:static interrupt generated when event is recorded.
 *        cfg_clear will clear. 0: do not enable interrupt
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param synd_capturetest </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> 1:capture on syndrome_capture_v or syndrome_capture_testv
 *        0:only capture real events syndrome_capture_v
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param synd_forcecapture </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> 1: capture data on every cycle (syndrome_capture_v
 *        is ignored) 0: capture data only when syndrome_capture_v
 *        specifies an event is active
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param synd_freecapture </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> 1: capture and hold data on all syndrome_capture_v
 *        events. 0: capture and hold data only on first event
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param synd_clear </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> 1: static clear of all state in AW_syndrome 0: allow
 *        for normal operation
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param synd_enable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 1: enable AW_syndrome for operation 0:disable AW_syndrome </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_syndrome_cfg_r_t
 *
 * Implemented by: 
 *      syndrome_cfg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 26;
     unsigned      synd_interruptenable                      :  1;
     unsigned      synd_capturetest                          :  1;
     unsigned      synd_forcecapture                         :  1;
     unsigned      synd_freecapture                          :  1;
     unsigned      synd_clear                                :  1;
     unsigned      synd_enable                               :  1;
#else    /* Little Endian */
     unsigned      synd_enable                               :  1;
     unsigned      synd_clear                                :  1;
     unsigned      synd_freecapture                          :  1;
     unsigned      synd_forcecapture                         :  1;
     unsigned      synd_capturetest                          :  1;
     unsigned      synd_interruptenable                      :  1;
     unsigned      reserved0                                 : 26;
#endif
} ncp_nca_itp_syndrome_cfg_r_t;

/*! @struct ncp_nca_itp_syndrome_event_r_t
 *  @brief null
 *  @details CFG access to Status. Syndrome Captured Event register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_syndrome_event_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param synd_event </td>
 *     <td width="20%" align="center"> 30 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Syndrome Captured Event </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param synd_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Syndrome Captured interrupt </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param synd_valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Syndrome Captured valid </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_syndrome_event_r_t
 *
 * Implemented by: 
 *      syndrome_event
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      synd_event                                : 30;
     unsigned      synd_int                                  :  1;
     unsigned      synd_valid                                :  1;
#else    /* Little Endian */
     unsigned      synd_valid                                :  1;
     unsigned      synd_int                                  :  1;
     unsigned      synd_event                                : 30;
#endif
} ncp_nca_itp_syndrome_event_r_t;

/*! @struct ncp_nca_itp_syndrome_data00_r_t
 *  @brief null
 *  @details CFG access to Status. Syndrome Captured Event Data register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_syndrome_data00_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param synd_data </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Syndrome Captured Data </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_syndrome_data00_r_t
 *
 * Implemented by: 
 *      syndrome_data00
 */
 
typedef struct
{
     unsigned  int                 synd_data;
} ncp_nca_itp_syndrome_data00_r_t;

/*! @struct ncp_nca_itp_syndrome_data01_r_t
 *  @brief null
 *  @details CFG access to Status. Syndrome Captured Event Data register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_syndrome_data01_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param synd_data </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Syndrome Captured Data </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_syndrome_data01_r_t
 *
 * Implemented by: 
 *      syndrome_data01
 */
 
typedef struct
{
     unsigned  int                 synd_data;
} ncp_nca_itp_syndrome_data01_r_t;

/*! @struct ncp_nca_itp_syndrome_data02_r_t
 *  @brief null
 *  @details CFG access to Status. Syndrome Captured Event Data register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_syndrome_data02_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param synd_data </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Syndrome Captured Data </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_syndrome_data02_r_t
 *
 * Implemented by: 
 *      syndrome_data02
 */
 
typedef struct
{
     unsigned  int                 synd_data;
} ncp_nca_itp_syndrome_data02_r_t;

/*! @struct ncp_nca_itp_syndrome_data03_r_t
 *  @brief null
 *  @details CFG access to Status. Syndrome Captured Event Data register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_syndrome_data03_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param synd_data </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Syndrome Captured Data </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_syndrome_data03_r_t
 *
 * Implemented by: 
 *      syndrome_data03
 */
 
typedef struct
{
     unsigned  int                 synd_data;
} ncp_nca_itp_syndrome_data03_r_t;

/*! @struct ncp_nca_itp_parameter_SIZE_ITP_COMPLETION_LL_r_t
 *  @brief null
 *  @details CFG read only access to paramter values. parameter for the amount of storage in the completion LL. This impacts the number of tasks which can be delivered that have not received a task completion response from PE
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_parameter_SIZE_ITP_COMPLETION_LL_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param parm_size_itp_completion_ll </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> parameter for the amount of storage in the completion
 *        LL. This impacts the number of tasks which can be
 *        delivered that have not received a task completion
 *        response from PE
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_parameter_SIZE_ITP_COMPLETION_LL_r_t
 *
 * Implemented by: 
 *      parameter_SIZE_ITP_COMPLETION_LL
 */
 
typedef struct
{
     unsigned  int      parm_size_itp_completion_ll;
} ncp_nca_itp_parameter_SIZE_ITP_COMPLETION_LL_r_t;

/*! @struct ncp_nca_itp_parameter_SIZE_ITP_ORDERED_BCAM_r_t
 *  @brief null
 *  @details CFG read only access to paramter values. parameter for the amount of storage for the BCAM. This impacts the number of flows which can be active int he system
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_parameter_SIZE_ITP_ORDERED_BCAM_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param parm_size_itp_ordered_bcam </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> parameter for the amount of storage for the BCAM.
 *        This impacts the number of flows which can be active
 *        int he system
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_parameter_SIZE_ITP_ORDERED_BCAM_r_t
 *
 * Implemented by: 
 *      parameter_SIZE_ITP_ORDERED_BCAM
 */
 
typedef struct
{
     unsigned  int      parm_size_itp_ordered_bcam;
} ncp_nca_itp_parameter_SIZE_ITP_ORDERED_BCAM_r_t;

/*! @struct ncp_nca_itp_parameter_SIZE_ITP_ORDERED_LL_r_t
 *  @brief null
 *  @details CFG read only access to paramter values. parameter for the amount of storage in the ordered task LL
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_parameter_SIZE_ITP_ORDERED_LL_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param parm_size_itp_ordered_ll </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> parameter for the amount of storage in the ordered
 *        task LL
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_parameter_SIZE_ITP_ORDERED_LL_r_t
 *
 * Implemented by: 
 *      parameter_SIZE_ITP_ORDERED_LL
 */
 
typedef struct
{
     unsigned  int      parm_size_itp_ordered_ll;
} ncp_nca_itp_parameter_SIZE_ITP_ORDERED_LL_r_t;

/*! @struct ncp_nca_itp_parameter_SIZE_ITP_UNORDERED_LL_r_t
 *  @brief null
 *  @details CFG read only access to paramter values. parameter for the amount of storage in the unordered task LL
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_parameter_SIZE_ITP_UNORDERED_LL_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param parm_size_itp_unordered_ll </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> parameter for the amount of storage in the unordered
 *        task LL
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_parameter_SIZE_ITP_UNORDERED_LL_r_t
 *
 * Implemented by: 
 *      parameter_SIZE_ITP_UNORDERED_LL
 */
 
typedef struct
{
     unsigned  int      parm_size_itp_unordered_ll;
} ncp_nca_itp_parameter_SIZE_ITP_UNORDERED_LL_r_t;

/*! @struct ncp_nca_itp_parameter_SIZE_ITP_UNSCHED_LL_r_t
 *  @brief null
 *  @details CFG read only access to paramter values. parameter for the amount of storage in the unscheduled LL (QPM)
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_parameter_SIZE_ITP_UNSCHED_LL_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param parm_size_itp_unsched_ll </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> parameter for the amount of storage in the unscheduled
 *        LL (QPM)
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_parameter_SIZE_ITP_UNSCHED_LL_r_t
 *
 * Implemented by: 
 *      parameter_SIZE_ITP_UNSCHED_LL
 */
 
typedef struct
{
     unsigned  int      parm_size_itp_unsched_ll;
} ncp_nca_itp_parameter_SIZE_ITP_UNSCHED_LL_r_t;

/*! @struct ncp_nca_itp_parameter_SIZE_ITP_COPY_LL_r_t
 *  @brief null
 *  @details CFG read only access to paramter values. parameter for the amount of storage in the copy link list
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_parameter_SIZE_ITP_COPY_LL_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param parm_size_itp_copy_ll </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> parameter for the amount of storage in the copy link
 *        list
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_parameter_SIZE_ITP_COPY_LL_r_t
 *
 * Implemented by: 
 *      parameter_SIZE_ITP_COPY_LL
 */
 
typedef struct
{
     unsigned  int      parm_size_itp_copy_ll;
} ncp_nca_itp_parameter_SIZE_ITP_COPY_LL_r_t;

/*! @struct ncp_nca_itp_parameter_SIZE_ITP_PREPROC_LL_r_t
 *  @brief null
 *  @details CFG read only access to paramter values. parameter for the amount of storage in the preprocessing link list
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_parameter_SIZE_ITP_PREPROC_LL_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param parm_size_itp_preproc_ll </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> parameter for the amount of storage in the preprocessing
 *        link list
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_parameter_SIZE_ITP_PREPROC_LL_r_t
 *
 * Implemented by: 
 *      parameter_SIZE_ITP_PREPROC_LL
 */
 
typedef struct
{
     unsigned  int      parm_size_itp_preproc_ll;
} ncp_nca_itp_parameter_SIZE_ITP_PREPROC_LL_r_t;

/*! @struct ncp_nca_itp_parameter_NUM_GIDPRI_r_t
 *  @brief null
 *  @details CFG read only access to paramter values. parameter for the numer of priority which can be assigned to GID in a iPCQ.This must be base 2.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_parameter_NUM_GIDPRI_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param parm_num_gidpri </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> parameter for the numer of priority which can be assigned
 *        to GID in a iPCQ.This must be base 2.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_parameter_NUM_GIDPRI_r_t
 *
 * Implemented by: 
 *      parameter_NUM_GIDPRI
 */
 
typedef struct
{
     unsigned  int           parm_num_gidpri;
} ncp_nca_itp_parameter_NUM_GIDPRI_r_t;

/*! @struct ncp_nca_itp_parameter_NUM_TQPRI_r_t
 *  @brief null
 *  @details CFG read only access to paramter values. parameter for the numer of priority which can be assigned to TQ.This must be base 2.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_parameter_NUM_TQPRI_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param parm_num_tqpri </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> parameter for the numer of priority which can be assigned
 *        to TQ.This must be base 2.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_parameter_NUM_TQPRI_r_t
 *
 * Implemented by: 
 *      parameter_NUM_TQPRI
 */
 
typedef struct
{
     unsigned  int            parm_num_tqpri;
} ncp_nca_itp_parameter_NUM_TQPRI_r_t;

/*! @struct ncp_nca_itp_parameter_NUM_GIDPERIPCQ_r_t
 *  @brief null
 *  @details CFG read only access to paramter values. parameter for the number of GID that can be assigned to a iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_parameter_NUM_GIDPERIPCQ_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param parm_num_gidperipcq </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> parameter for the number of GID that can be assigned
 *        to a iPCQ
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_parameter_NUM_GIDPERIPCQ_r_t
 *
 * Implemented by: 
 *      parameter_NUM_GIDPERIPCQ
 */
 
typedef struct
{
     unsigned  int       parm_num_gidperipcq;
} ncp_nca_itp_parameter_NUM_GIDPERIPCQ_r_t;

/*! @struct ncp_nca_itp_parameter_NUM_GID_r_t
 *  @brief null
 *  @details CFG read only access to paramter values. parameter for the number of group ID. The group ID is used to map TQ to iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_parameter_NUM_GID_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param parm_num_gid </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> parameter for the number of group ID. The group ID
 *        is used to map TQ to iPCQ
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_parameter_NUM_GID_r_t
 *
 * Implemented by: 
 *      parameter_NUM_GID
 */
 
typedef struct
{
     unsigned  int              parm_num_gid;
} ncp_nca_itp_parameter_NUM_GID_r_t;

/*! @struct ncp_nca_itp_parameter_NUM_TQ_r_t
 *  @brief null
 *  @details CFG read only access to paramter values. parameter for the number of COW TQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_parameter_NUM_TQ_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param parm_num_tq </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> parameter for the number of COW TQ </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_parameter_NUM_TQ_r_t
 *
 * Implemented by: 
 *      parameter_NUM_TQ
 */
 
typedef struct
{
     unsigned  int               parm_num_tq;
} ncp_nca_itp_parameter_NUM_TQ_r_t;

/*! @struct ncp_nca_itp_AW_smon01_smon2_r_t
 *  @brief AW_smon CONTROL1 register
 *  @details This is used to configure the operation of the 2 internal counters in the SMON
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_AW_smon01_smon2_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param mode1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> select input signal for SMON1 engine </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param mode0 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> select input signal for SMON0 engine </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_AW_smon01_smon2_r_t
 *
 * Implemented by: 
 *      AW_SMON01_smon2
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      mode1                                     :  8;
     unsigned      mode0                                     :  8;
#else    /* Little Endian */
     unsigned      mode0                                     :  8;
     unsigned      mode1                                     :  8;
     unsigned      reserved0                                 : 16;
#endif
} ncp_nca_itp_AW_smon01_smon2_r_t;

/*! @struct ncp_nca_itp_AW_smon01_smon_r_t
 *  @brief AW_smon CONTROL1 register
 *  @details This is used to configure the operation of the 2 internal counters in the SMON
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_AW_smon01_smon_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param mode1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> select input signal for SMON1 engine </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param mode0 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> select input signal for SMON0 engine </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_AW_smon01_smon_r_t
 *
 * Implemented by: 
 *      AW_SMON01_smon
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      mode1                                     :  8;
     unsigned      mode0                                     :  8;
#else    /* Little Endian */
     unsigned      mode0                                     :  8;
     unsigned      mode1                                     :  8;
     unsigned      reserved0                                 : 16;
#endif
} ncp_nca_itp_AW_smon01_smon_r_t;

/*! @struct ncp_nca_itp_control_general_00_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_general_00_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param disablecounters </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> disable dedicated counters </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param parityenable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> parity enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param paritymode </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> parity mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpmdrop </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> disable dropping unscheuded task when QPM queue is
 *        full.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param disablescheduledoptbypass </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> disable blocking moving a flow from scheduled to ready
 *        when the iPCQ is currently being scheduled. When dynamic
 *        GID delete is used can result in an interrupt
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param disablescheduledopt </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> disbale moving a orderd flow from scheduled to ready
 *        state when (1) all task completions are received and
 *        (2) tasks in flow are currently enqueued
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param trace </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> enable trace mode, connects to bit0 of 4b trace input
 *        port awaddr[7:4]
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param trace_toid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> replace trace (long trace) data Bytes 1 & 0 with TOID </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved2 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpmformat </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> QPM format. 0: do not include poolID in QPM task Virtual
 *        Address. 1: include poolID in QPM Virtual Address
 *        bits [3:0]
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param idformat </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> iPCQ task entry ID[23:0] format. 0: QID[7:0],3'd0,TPD.gen[0:0],1'd0,TASK.PRI[2:0],GID[7:0].
 *        1: 3'd0,TPD.gen[0:0],TOID[11:0],GID[7:0]. 2:3'd0,TPD.gen[0:0],TOID[11:0],QID[7:0].
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param force_hs1_fixed </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> when set will force the header seperate configuation
 *        to on for task with pointer0 = fixed pool
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completion_check_opcq </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> when set will check the 4b sequence ID of aPCQ task
 *        completions. iPCQ (LE format) bits 23:20 have a seqeunce
 *        which can optionally be retunred in oPCQ message wht
 *        task Completion enabled and can be enabled to be verified
 *        in NCA. If the sequence ID do not match a interrupt
 *        is generated
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completion_check_apcq </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> when set will check the 4b sequence ID of aPCQ task
 *        completions. iPCQ (LE format) bits 23:20 have a seqeunce
 *        which is retunred in aPCQ message and can be enabled
 *        to be verified in NCA. If the sequence ID do not match
 *        a interrupt is generated
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param force_hs1_ptrcnt0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> when set will force the header seperate configuation
 *        to on for task with pointer count of zero
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param debug </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> set to control what is loaded in the indexed debug
 *        status registers 0x0880 to 0xa80
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpmsecure </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> QPM secure access control AWprot security setting </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param raminitdone </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> inidcation that raminit has completed. Will reset
 *        raminit to zero
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param raminit </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> set to issue static iniitialize all RAms with data
 *        pattern zero and good ECC
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param bcaminitb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> issue a static reset sequence to the BCAM </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param bcaminita </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> issue a static reset sequence to the BCAM </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_general_00_r_t
 *
 * Implemented by: 
 *      control_general_00
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  1;
     unsigned      disablecounters                           :  1;
     unsigned      parityenable                              :  1;
     unsigned      paritymode                                :  1;
     unsigned      qpmdrop                                   :  1;
     unsigned      disablescheduledoptbypass                 :  1;
     unsigned      disablescheduledopt                       :  1;
     unsigned      reserved1                                 :  3;
     unsigned      trace                                     :  1;
     unsigned      trace_toid                                :  1;
     unsigned      reserved2                                 :  1;
     unsigned      qpmformat                                 :  1;
     unsigned      idformat                                  :  2;
     unsigned      force_hs1_fixed                           :  1;
     unsigned      completion_check_opcq                     :  1;
     unsigned      completion_check_apcq                     :  1;
     unsigned      force_hs1_ptrcnt0                         :  1;
     unsigned      debug                                     :  5;
     unsigned      qpmsecure                                 :  3;
     unsigned      raminitdone                               :  1;
     unsigned      raminit                                   :  1;
     unsigned      bcaminitb                                 :  1;
     unsigned      bcaminita                                 :  1;
#else    /* Little Endian */
     unsigned      bcaminita                                 :  1;
     unsigned      bcaminitb                                 :  1;
     unsigned      raminit                                   :  1;
     unsigned      raminitdone                               :  1;
     unsigned      qpmsecure                                 :  3;
     unsigned      debug                                     :  5;
     unsigned      force_hs1_ptrcnt0                         :  1;
     unsigned      completion_check_apcq                     :  1;
     unsigned      completion_check_opcq                     :  1;
     unsigned      force_hs1_fixed                           :  1;
     unsigned      idformat                                  :  2;
     unsigned      qpmformat                                 :  1;
     unsigned      reserved2                                 :  1;
     unsigned      trace_toid                                :  1;
     unsigned      trace                                     :  1;
     unsigned      reserved1                                 :  3;
     unsigned      disablescheduledopt                       :  1;
     unsigned      disablescheduledoptbypass                 :  1;
     unsigned      qpmdrop                                   :  1;
     unsigned      paritymode                                :  1;
     unsigned      parityenable                              :  1;
     unsigned      disablecounters                           :  1;
     unsigned      reserved0                                 :  1;
#endif
} ncp_nca_itp_control_general_00_r_t;

/*! @struct ncp_nca_itp_control_general_01_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_general_01_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param arb_tqbpin_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> arb_tqbpIn_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_ram_ieorderedrdin_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> arb_ram_ieorderedrdIn_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_ram_ieorderedwrin_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> arb_ram_ieorderedwrIn_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_cam_ieorderedin_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> arb_cam_ieorderedIn_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_ipcq_task_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> arb_ipcq_task_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_ipcq_notempty_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> arb_ipcq_notempty_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_ipcq_empty_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> arb_ipcq_empty_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_multi_outputout_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> arb_multi_outputOut_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_multi_outputin_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> arb_multi_outputIn_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_ll_completionin_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> arb_ll_completionIn_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_ll_ieordschedin_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> arb_ll_ieordschedIn_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_ll_ieordreadyin_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> arb_ll_ieordreadyIn_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_ll_ieordin_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> arb_ll_ieordIn_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_ll_ieunordin_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> arb_ll_ieunordIn_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_ll_preprocin_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> arb_ll_preprocIn_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_ll_preprocout_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> arb_ll_preprocOut_arb_mode </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_general_01_r_t
 *
 * Implemented by: 
 *      control_general_01
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      arb_tqbpin_arb_mode                       :  2;
     unsigned      arb_ram_ieorderedrdin_arb_mode            :  2;
     unsigned      arb_ram_ieorderedwrin_arb_mode            :  2;
     unsigned      arb_cam_ieorderedin_arb_mode              :  2;
     unsigned      arb_ipcq_task_arb_mode                    :  2;
     unsigned      arb_ipcq_notempty_arb_mode                :  2;
     unsigned      arb_ipcq_empty_arb_mode                   :  2;
     unsigned      arb_multi_outputout_arb_mode              :  2;
     unsigned      arb_multi_outputin_arb_mode               :  2;
     unsigned      arb_ll_completionin_arb_mode              :  2;
     unsigned      arb_ll_ieordschedin_arb_mode              :  2;
     unsigned      arb_ll_ieordreadyin_arb_mode              :  2;
     unsigned      arb_ll_ieordin_arb_mode                   :  2;
     unsigned      arb_ll_ieunordin_arb_mode                 :  2;
     unsigned      arb_ll_preprocin_arb_mode                 :  2;
     unsigned      arb_ll_preprocout_arb_mode                :  2;
#else    /* Little Endian */
     unsigned      arb_ll_preprocout_arb_mode                :  2;
     unsigned      arb_ll_preprocin_arb_mode                 :  2;
     unsigned      arb_ll_ieunordin_arb_mode                 :  2;
     unsigned      arb_ll_ieordin_arb_mode                   :  2;
     unsigned      arb_ll_ieordreadyin_arb_mode              :  2;
     unsigned      arb_ll_ieordschedin_arb_mode              :  2;
     unsigned      arb_ll_completionin_arb_mode              :  2;
     unsigned      arb_multi_outputin_arb_mode               :  2;
     unsigned      arb_multi_outputout_arb_mode              :  2;
     unsigned      arb_ipcq_empty_arb_mode                   :  2;
     unsigned      arb_ipcq_notempty_arb_mode                :  2;
     unsigned      arb_ipcq_task_arb_mode                    :  2;
     unsigned      arb_cam_ieorderedin_arb_mode              :  2;
     unsigned      arb_ram_ieorderedwrin_arb_mode            :  2;
     unsigned      arb_ram_ieorderedrdin_arb_mode            :  2;
     unsigned      arb_tqbpin_arb_mode                       :  2;
#endif
} ncp_nca_itp_control_general_01_r_t;

/*! @struct ncp_nca_itp_control_general_02_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_general_02_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved18 </td>
 *     <td width="20%" align="center"> 14 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved17 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> reserved17 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param forcefullcopy </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> force ITP to copy entire packet data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param disablebestfit11 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> disable best fit command=11 1(64kB) </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param disablebestfit10 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> disable best fit command=10 4(16kB) </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param disablebestfit9 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> disable best fit command=9 3(16kB) </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param disablebestfit8 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> disable best fit command=8 2(16kB) </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param disablebestfit7 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> disable best fit command=7 1(16kB) </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param disablebestfit6 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> disable best fit command=6 6(2kB) </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param disablebestfit5 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> disable best fit command=5 5(2kB) </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param disablebestfit4 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> disable best fit command=4 4(2kB) </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param disablebestfit3 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> disable best fit command=3 3(2kB) </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param disablebestfit2 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> disable best fit command=2 2(2kB) </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param disablebestfit1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> disable best fit command=1 1(2kB) </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param disablebestfit0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> disable best fit command=0 1(256B) </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param disablepartialptrcopy </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> set to disable splitting a poionter when copy is performed </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param usefixedreadyunord </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> reandomize selection bettwe unordered and ready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param disablemultiafull </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> disable multi output fifo afull </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_general_02_r_t
 *
 * Implemented by: 
 *      control_general_02
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved18                                : 14;
     unsigned      reserved17                                :  1;
     unsigned      forcefullcopy                             :  1;
     unsigned      disablebestfit11                          :  1;
     unsigned      disablebestfit10                          :  1;
     unsigned      disablebestfit9                           :  1;
     unsigned      disablebestfit8                           :  1;
     unsigned      disablebestfit7                           :  1;
     unsigned      disablebestfit6                           :  1;
     unsigned      disablebestfit5                           :  1;
     unsigned      disablebestfit4                           :  1;
     unsigned      disablebestfit3                           :  1;
     unsigned      disablebestfit2                           :  1;
     unsigned      disablebestfit1                           :  1;
     unsigned      disablebestfit0                           :  1;
     unsigned      disablepartialptrcopy                     :  1;
     unsigned      usefixedreadyunord                        :  1;
     unsigned      disablemultiafull                         :  1;
#else    /* Little Endian */
     unsigned      disablemultiafull                         :  1;
     unsigned      usefixedreadyunord                        :  1;
     unsigned      disablepartialptrcopy                     :  1;
     unsigned      disablebestfit0                           :  1;
     unsigned      disablebestfit1                           :  1;
     unsigned      disablebestfit2                           :  1;
     unsigned      disablebestfit3                           :  1;
     unsigned      disablebestfit4                           :  1;
     unsigned      disablebestfit5                           :  1;
     unsigned      disablebestfit6                           :  1;
     unsigned      disablebestfit7                           :  1;
     unsigned      disablebestfit8                           :  1;
     unsigned      disablebestfit9                           :  1;
     unsigned      disablebestfit10                          :  1;
     unsigned      disablebestfit11                          :  1;
     unsigned      forcefullcopy                             :  1;
     unsigned      reserved17                                :  1;
     unsigned      reserved18                                : 14;
#endif
} ncp_nca_itp_control_general_02_r_t;

/*! @struct ncp_nca_itp_control_general_03_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register. Address for aggregated bp message
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_general_03_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param address </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Address to write aggregated BP messaage in memory.
 *        Uses pool=0
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_general_03_r_t
 *
 * Implemented by: 
 *      control_general_03
 */
 
typedef struct
{
     unsigned  int                   address;
} ncp_nca_itp_control_general_03_r_t;

/*! @struct ncp_nca_itp_control_general_04_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register. AND Mask for SMON compare
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_general_04_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param smonmask </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> SMON MASK. Apply to SMON compare filds to apply AND
 *        function
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_general_04_r_t
 *
 * Implemented by: 
 *      control_general_04
 */
 
typedef struct
{
     unsigned  int                  smonmask;
} ncp_nca_itp_control_general_04_r_t;

/*! @struct ncp_nca_itp_control_memintf_00_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register. Control for CMSI interface 0. Task header write
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_memintf_00_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param arb_fifo_ptrsin_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> arb_fifo_ptrsIn_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_itp_mtp_reqin_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> arb_itp_mtp_reqIn_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_fifo_input_cpuheaderin_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> arb_fifo_input_cpuheaderIn_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_ipcq_hp_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> arb_ipcq_hp_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wr_outfifowm </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> write DMA out FIFO WM </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wr_infifowm </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> write DMA in FIFO WM </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wr_ttype </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> write DMA ttype </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wr_priority </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> write DMA priority </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wr_online </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> write DMA online </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_memintf_00_r_t
 *
 * Implemented by: 
 *      control_memintf_00
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      arb_fifo_ptrsin_arb_mode                  :  2;
     unsigned      arb_itp_mtp_reqin_arb_mode                :  2;
     unsigned      arb_fifo_input_cpuheaderin_arb_mode       :  2;
     unsigned      arb_ipcq_hp_mode                          :  2;
     unsigned      wr_outfifowm                              :  8;
     unsigned      wr_infifowm                               :  8;
     unsigned      reserved0                                 :  1;
     unsigned      wr_ttype                                  :  5;
     unsigned      wr_priority                               :  1;
     unsigned      wr_online                                 :  1;
#else    /* Little Endian */
     unsigned      wr_online                                 :  1;
     unsigned      wr_priority                               :  1;
     unsigned      wr_ttype                                  :  5;
     unsigned      reserved0                                 :  1;
     unsigned      wr_infifowm                               :  8;
     unsigned      wr_outfifowm                              :  8;
     unsigned      arb_ipcq_hp_mode                          :  2;
     unsigned      arb_fifo_input_cpuheaderin_arb_mode       :  2;
     unsigned      arb_itp_mtp_reqin_arb_mode                :  2;
     unsigned      arb_fifo_ptrsin_arb_mode                  :  2;
#endif
} ncp_nca_itp_control_memintf_00_r_t;

/*! @struct ncp_nca_itp_control_memintf_01_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register. Control for CMSI interface 0. Data pointer copy
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_memintf_01_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_ll_preproc02_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> arb_ll_preproc02 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_ll_preproc01_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> arb_ll_preproc01 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wr_outfifowm </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> write DMA out FIFO WM </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wr_infifowm </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> write DMA in FIFO WM </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wr_ttype </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> write DMA ttype </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wr_priority </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> write DMA priority </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wr_online </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> write DMA online </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_memintf_01_r_t
 *
 * Implemented by: 
 *      control_memintf_01
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  4;
     unsigned      arb_ll_preproc02_arb_mode                 :  2;
     unsigned      arb_ll_preproc01_arb_mode                 :  2;
     unsigned      wr_outfifowm                              :  8;
     unsigned      wr_infifowm                               :  8;
     unsigned      reserved1                                 :  1;
     unsigned      wr_ttype                                  :  5;
     unsigned      wr_priority                               :  1;
     unsigned      wr_online                                 :  1;
#else    /* Little Endian */
     unsigned      wr_online                                 :  1;
     unsigned      wr_priority                               :  1;
     unsigned      wr_ttype                                  :  5;
     unsigned      reserved1                                 :  1;
     unsigned      wr_infifowm                               :  8;
     unsigned      wr_outfifowm                              :  8;
     unsigned      arb_ll_preproc01_arb_mode                 :  2;
     unsigned      arb_ll_preproc02_arb_mode                 :  2;
     unsigned      reserved0                                 :  4;
#endif
} ncp_nca_itp_control_memintf_01_r_t;

/*! @struct ncp_nca_itp_control_memintf_02_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register. Control for CMSI interface 0. aggregated bp message
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_memintf_02_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_sort02_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> arb_sort02 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_sort01_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> arb_sort01 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wr_outfifowm </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> write DMA out FIFO WM </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wr_infifowm </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> write DMA in FIFO WM </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wr_ttype </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> write DMA ttype </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wr_priority </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> write DMA priority </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wr_online </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> write DMA online </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_memintf_02_r_t
 *
 * Implemented by: 
 *      control_memintf_02
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  4;
     unsigned      arb_sort02_arb_mode                       :  2;
     unsigned      arb_sort01_arb_mode                       :  2;
     unsigned      wr_outfifowm                              :  8;
     unsigned      wr_infifowm                               :  8;
     unsigned      reserved1                                 :  1;
     unsigned      wr_ttype                                  :  5;
     unsigned      wr_priority                               :  1;
     unsigned      wr_online                                 :  1;
#else    /* Little Endian */
     unsigned      wr_online                                 :  1;
     unsigned      wr_priority                               :  1;
     unsigned      wr_ttype                                  :  5;
     unsigned      reserved1                                 :  1;
     unsigned      wr_infifowm                               :  8;
     unsigned      wr_outfifowm                              :  8;
     unsigned      arb_sort01_arb_mode                       :  2;
     unsigned      arb_sort02_arb_mode                       :  2;
     unsigned      reserved0                                 :  4;
#endif
} ncp_nca_itp_control_memintf_02_r_t;

/*! @struct ncp_nca_itp_control_general_08_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_general_08_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param forcefullcopyretain1stub </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> force a full copy if retain 1 pointer & non-copy stub
 *        size is below amount
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param forcefullcopyretain0stub </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> force a full copy if non-copy stub size is below amount </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_general_08_r_t
 *
 * Implemented by: 
 *      control_general_08
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      forcefullcopyretain1stub                  : 16;
     unsigned      forcefullcopyretain0stub                  : 16;
#else    /* Little Endian */
     unsigned      forcefullcopyretain0stub                  : 16;
     unsigned      forcefullcopyretain1stub                  : 16;
#endif
} ncp_nca_itp_control_general_08_r_t;

/*! @struct ncp_nca_itp_control_general_09_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_general_09_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param forcefullcopyretain3stub </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> force a full copy if retain 3 pointer & non-copy stub
 *        size is below amount
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param forcefullcopyretain2stub </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> force a full copy if retain 2 pointer & non-copy stub
 *        size is below amount
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_general_09_r_t
 *
 * Implemented by: 
 *      control_general_09
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      forcefullcopyretain3stub                  : 16;
     unsigned      forcefullcopyretain2stub                  : 16;
#else    /* Little Endian */
     unsigned      forcefullcopyretain2stub                  : 16;
     unsigned      forcefullcopyretain3stub                  : 16;
#endif
} ncp_nca_itp_control_general_09_r_t;

/*! @struct ncp_nca_itp_control_general_10_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_general_10_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param forcefullcopyretain5stub </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> force a full copy if retain 5 pointer & non-copy stub
 *        size is below amount
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param forcefullcopyretain4stub </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> force a full copy if retain 4 pointer & non-copy stub
 *        size is below amount
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_general_10_r_t
 *
 * Implemented by: 
 *      control_general_10
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      forcefullcopyretain5stub                  : 16;
     unsigned      forcefullcopyretain4stub                  : 16;
#else    /* Little Endian */
     unsigned      forcefullcopyretain4stub                  : 16;
     unsigned      forcefullcopyretain5stub                  : 16;
#endif
} ncp_nca_itp_control_general_10_r_t;

/*! @struct ncp_nca_itp_control_general_11_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_general_11_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param forcefullcopyretain1size </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> force a full copy if retain 1 pointer & packet size
 *        above amount
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param forcefullcopyretain0size </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> force a full copy if packet size above amount </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_general_11_r_t
 *
 * Implemented by: 
 *      control_general_11
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      forcefullcopyretain1size                  : 16;
     unsigned      forcefullcopyretain0size                  : 16;
#else    /* Little Endian */
     unsigned      forcefullcopyretain0size                  : 16;
     unsigned      forcefullcopyretain1size                  : 16;
#endif
} ncp_nca_itp_control_general_11_r_t;

/*! @struct ncp_nca_itp_control_general_12_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_general_12_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param forcefullcopyretain3size </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> force a full copy if retain 3 pointer & packet size
 *        above amount
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param forcefullcopyretain2size </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> force a full copy if retain 2 pointer & packet size
 *        above amount
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_general_12_r_t
 *
 * Implemented by: 
 *      control_general_12
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      forcefullcopyretain3size                  : 16;
     unsigned      forcefullcopyretain2size                  : 16;
#else    /* Little Endian */
     unsigned      forcefullcopyretain2size                  : 16;
     unsigned      forcefullcopyretain3size                  : 16;
#endif
} ncp_nca_itp_control_general_12_r_t;

/*! @struct ncp_nca_itp_control_general_13_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_general_13_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param forcefullcopyretain5size </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> force a full copy if retain 5 pointer & packet size
 *        above amount
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param forcefullcopyretain4size </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> force a full copy if retain 4 pointer & packet size
 *        above amount
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_general_13_r_t
 *
 * Implemented by: 
 *      control_general_13
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      forcefullcopyretain5size                  : 16;
     unsigned      forcefullcopyretain4size                  : 16;
#else    /* Little Endian */
     unsigned      forcefullcopyretain4size                  : 16;
     unsigned      forcefullcopyretain5size                  : 16;
#endif
} ncp_nca_itp_control_general_13_r_t;

/*! @struct ncp_nca_itp_control_general_qos_01_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_general_qos_01_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 12 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param maxbcam_full </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> maximum number of BCAM flows active full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param maxbcam_afull </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> maximum number of BCAM flows active afull </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_general_qos_01_r_t
 *
 * Implemented by: 
 *      control_general_qos_01
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 12;
     unsigned      maxbcam_full                              : 10;
     unsigned      maxbcam_afull                             : 10;
#else    /* Little Endian */
     unsigned      maxbcam_afull                             : 10;
     unsigned      maxbcam_full                              : 10;
     unsigned      reserved0                                 : 12;
#endif
} ncp_nca_itp_control_general_qos_01_r_t;

/*! @struct ncp_nca_itp_control_general_qos_02_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_general_qos_02_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param maxieunord_full </td>
 *     <td width="20%" align="center"> 11 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> maximum number of IEUNORD flows active full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param maxieord_full </td>
 *     <td width="20%" align="center"> 11 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> maximum number of IEORD flows active full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_general_qos_02_r_t
 *
 * Implemented by: 
 *      control_general_qos_02
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 10;
     unsigned      maxieunord_full                           : 11;
     unsigned      maxieord_full                             : 11;
#else    /* Little Endian */
     unsigned      maxieord_full                             : 11;
     unsigned      maxieunord_full                           : 11;
     unsigned      reserved0                                 : 10;
#endif
} ncp_nca_itp_control_general_qos_02_r_t;

/*! @struct ncp_nca_itp_maxbcam_afull_bp_00_r_t
 *  @brief null
 *  @details CFG access to maxbcam_afull_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxbcam_afull_bp_00_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxbcam_afull_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when BCAM size exceedes maxbcam_afull threshold ,
 *        issue bp to TQ bits 031:000
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxbcam_afull_bp_00_r_t
 *
 * Implemented by: 
 *      maxbcam_afull_bp_00
 */
 
typedef struct
{
     unsigned  int          maxbcam_afull_bp;
} ncp_nca_itp_maxbcam_afull_bp_00_r_t;

/*! @struct ncp_nca_itp_maxbcam_afull_bp_01_r_t
 *  @brief null
 *  @details CFG access to maxbcam_afull_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxbcam_afull_bp_01_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxbcam_afull_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when BCAM size exceedes maxbcam_afull threshold ,
 *        issue bp to TQ bits 063:032
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxbcam_afull_bp_01_r_t
 *
 * Implemented by: 
 *      maxbcam_afull_bp_01
 */
 
typedef struct
{
     unsigned  int          maxbcam_afull_bp;
} ncp_nca_itp_maxbcam_afull_bp_01_r_t;

/*! @struct ncp_nca_itp_maxbcam_afull_bp_02_r_t
 *  @brief null
 *  @details CFG access to maxbcam_afull_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxbcam_afull_bp_02_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxbcam_afull_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when BCAM size exceedes maxbcam_afull threshold ,
 *        issue bp to TQ bits 095:064
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxbcam_afull_bp_02_r_t
 *
 * Implemented by: 
 *      maxbcam_afull_bp_02
 */
 
typedef struct
{
     unsigned  int          maxbcam_afull_bp;
} ncp_nca_itp_maxbcam_afull_bp_02_r_t;

/*! @struct ncp_nca_itp_maxbcam_afull_bp_03_r_t
 *  @brief null
 *  @details CFG access to maxbcam_afull_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxbcam_afull_bp_03_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxbcam_afull_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when BCAM size exceedes maxbcam_afull threshold ,
 *        issue bp to TQ bits 127:096
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxbcam_afull_bp_03_r_t
 *
 * Implemented by: 
 *      maxbcam_afull_bp_03
 */
 
typedef struct
{
     unsigned  int          maxbcam_afull_bp;
} ncp_nca_itp_maxbcam_afull_bp_03_r_t;

/*! @struct ncp_nca_itp_maxbcam_afull_bp_04_r_t
 *  @brief null
 *  @details CFG access to maxbcam_afull_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxbcam_afull_bp_04_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxbcam_afull_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when BCAM size exceedes maxbcam_afull threshold ,
 *        issue bp to TQ bits 159:128
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxbcam_afull_bp_04_r_t
 *
 * Implemented by: 
 *      maxbcam_afull_bp_04
 */
 
typedef struct
{
     unsigned  int          maxbcam_afull_bp;
} ncp_nca_itp_maxbcam_afull_bp_04_r_t;

/*! @struct ncp_nca_itp_maxbcam_afull_bp_05_r_t
 *  @brief null
 *  @details CFG access to maxbcam_afull_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxbcam_afull_bp_05_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxbcam_afull_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when BCAM size exceedes maxbcam_afull threshold ,
 *        issue bp to TQ bits 191:160
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxbcam_afull_bp_05_r_t
 *
 * Implemented by: 
 *      maxbcam_afull_bp_05
 */
 
typedef struct
{
     unsigned  int          maxbcam_afull_bp;
} ncp_nca_itp_maxbcam_afull_bp_05_r_t;

/*! @struct ncp_nca_itp_maxbcam_afull_bp_06_r_t
 *  @brief null
 *  @details CFG access to maxbcam_afull_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxbcam_afull_bp_06_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 20 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param maxbcam_afull_bp </td>
 *     <td width="20%" align="center"> 12 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when BCAM size exceedes maxbcam_afull threshold ,
 *        issue bp to TQ bits 203:192
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxbcam_afull_bp_06_r_t
 *
 * Implemented by: 
 *      maxbcam_afull_bp_06
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 20;
     unsigned      maxbcam_afull_bp                          : 12;
#else    /* Little Endian */
     unsigned      maxbcam_afull_bp                          : 12;
     unsigned      reserved0                                 : 20;
#endif
} ncp_nca_itp_maxbcam_afull_bp_06_r_t;

/*! @struct ncp_nca_itp_control_general_23_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_general_23_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param monitor1_addr </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> addr </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param monitor1_pgit </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> pgit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param monitor1_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> enable montior task completion interface to check
 *        for NCAP, PGIT traffic
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param monitor0_addr </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> addr </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param monitor0_pgit </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> pgit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param monitor0_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> enable montior NLINK ipcq req interface to check for
 *        NCAP, PGIT traffic
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_general_23_r_t
 *
 * Implemented by: 
 *      control_general_23
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      monitor1_addr                             :  4;
     unsigned      monitor1_pgit                             :  3;
     unsigned      monitor1_v                                :  1;
     unsigned      monitor0_addr                             :  4;
     unsigned      monitor0_pgit                             :  3;
     unsigned      monitor0_v                                :  1;
#else    /* Little Endian */
     unsigned      monitor0_v                                :  1;
     unsigned      monitor0_pgit                             :  3;
     unsigned      monitor0_addr                             :  4;
     unsigned      monitor1_v                                :  1;
     unsigned      monitor1_pgit                             :  3;
     unsigned      monitor1_addr                             :  4;
     unsigned      reserved0                                 : 16;
#endif
} ncp_nca_itp_control_general_23_r_t;

/*! @struct ncp_nca_itp_maxbcam_full_bp_00_r_t
 *  @brief null
 *  @details CFG access to maxbcam_full_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxbcam_full_bp_00_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxbcam_full_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when BCAM size exceedes maxbcam_full threshold, issue
 *        bp to TQ bits 031:000
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxbcam_full_bp_00_r_t
 *
 * Implemented by: 
 *      maxbcam_full_bp_00
 */
 
typedef struct
{
     unsigned  int           maxbcam_full_bp;
} ncp_nca_itp_maxbcam_full_bp_00_r_t;

/*! @struct ncp_nca_itp_maxbcam_full_bp_01_r_t
 *  @brief null
 *  @details CFG access to maxbcam_full_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxbcam_full_bp_01_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxbcam_full_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when BCAM size exceedes maxbcam_full threshold, issue
 *        bp to TQ bits 063:032
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxbcam_full_bp_01_r_t
 *
 * Implemented by: 
 *      maxbcam_full_bp_01
 */
 
typedef struct
{
     unsigned  int           maxbcam_full_bp;
} ncp_nca_itp_maxbcam_full_bp_01_r_t;

/*! @struct ncp_nca_itp_maxbcam_full_bp_02_r_t
 *  @brief null
 *  @details CFG access to maxbcam_full_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxbcam_full_bp_02_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxbcam_full_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when BCAM size exceedes maxbcam_full threshold, issue
 *        bp to TQ bits 095:064
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxbcam_full_bp_02_r_t
 *
 * Implemented by: 
 *      maxbcam_full_bp_02
 */
 
typedef struct
{
     unsigned  int           maxbcam_full_bp;
} ncp_nca_itp_maxbcam_full_bp_02_r_t;

/*! @struct ncp_nca_itp_maxbcam_full_bp_03_r_t
 *  @brief null
 *  @details CFG access to maxbcam_full_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxbcam_full_bp_03_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxbcam_full_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when BCAM size exceedes maxbcam_full threshold, issue
 *        bp to TQ bits 127:096
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxbcam_full_bp_03_r_t
 *
 * Implemented by: 
 *      maxbcam_full_bp_03
 */
 
typedef struct
{
     unsigned  int           maxbcam_full_bp;
} ncp_nca_itp_maxbcam_full_bp_03_r_t;

/*! @struct ncp_nca_itp_maxbcam_full_bp_04_r_t
 *  @brief null
 *  @details CFG access to maxbcam_full_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxbcam_full_bp_04_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxbcam_full_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when BCAM size exceedes maxbcam_full threshold, issue
 *        bp to TQ bits 159:128
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxbcam_full_bp_04_r_t
 *
 * Implemented by: 
 *      maxbcam_full_bp_04
 */
 
typedef struct
{
     unsigned  int           maxbcam_full_bp;
} ncp_nca_itp_maxbcam_full_bp_04_r_t;

/*! @struct ncp_nca_itp_maxbcam_full_bp_05_r_t
 *  @brief null
 *  @details CFG access to maxbcam_full_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxbcam_full_bp_05_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxbcam_full_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when BCAM size exceedes maxbcam_full threshold, issue
 *        bp to TQ bits 191:160
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxbcam_full_bp_05_r_t
 *
 * Implemented by: 
 *      maxbcam_full_bp_05
 */
 
typedef struct
{
     unsigned  int           maxbcam_full_bp;
} ncp_nca_itp_maxbcam_full_bp_05_r_t;

/*! @struct ncp_nca_itp_maxbcam_full_bp_06_r_t
 *  @brief null
 *  @details CFG access to maxbcam_full_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxbcam_full_bp_06_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 20 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param maxbcam_full_bp </td>
 *     <td width="20%" align="center"> 12 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when BCAM size exceedes maxbcam_full threshold, issue
 *        bp to TQ bits 203:192
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxbcam_full_bp_06_r_t
 *
 * Implemented by: 
 *      maxbcam_full_bp_06
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 20;
     unsigned      maxbcam_full_bp                           : 12;
#else    /* Little Endian */
     unsigned      maxbcam_full_bp                           : 12;
     unsigned      reserved0                                 : 20;
#endif
} ncp_nca_itp_maxbcam_full_bp_06_r_t;

/*! @struct ncp_nca_itp_control_general_31_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_general_31_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param activitycounter_pgitpurge </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> activity counter default values </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param activitycounter_bcam </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> activity counter default values </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param activitycounter_mtp </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> activity counter default values </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param activitycounter_writeack1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> activity counter default values </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param activitycounter_writeack0 </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> activity counter default values </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_general_31_r_t
 *
 * Implemented by: 
 *      control_general_31
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      activitycounter_pgitpurge                 :  6;
     unsigned      activitycounter_bcam                      : 10;
     unsigned      activitycounter_mtp                       :  6;
     unsigned      activitycounter_writeack1                 :  5;
     unsigned      activitycounter_writeack0                 :  5;
#else    /* Little Endian */
     unsigned      activitycounter_writeack0                 :  5;
     unsigned      activitycounter_writeack1                 :  5;
     unsigned      activitycounter_mtp                       :  6;
     unsigned      activitycounter_bcam                      : 10;
     unsigned      activitycounter_pgitpurge                 :  6;
#endif
} ncp_nca_itp_control_general_31_r_t;

/*! @struct ncp_nca_itp_maxieord_full_bp_00_r_t
 *  @brief null
 *  @details CFG access to maxieord_full_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxieord_full_bp_00_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxieord_full_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when IEORD LL size exceedes maxieord_full threshold,
 *        issue bp to TQ bits 031:000
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxieord_full_bp_00_r_t
 *
 * Implemented by: 
 *      maxieord_full_bp_00
 */
 
typedef struct
{
     unsigned  int          maxieord_full_bp;
} ncp_nca_itp_maxieord_full_bp_00_r_t;

/*! @struct ncp_nca_itp_maxieord_full_bp_01_r_t
 *  @brief null
 *  @details CFG access to maxieord_full_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxieord_full_bp_01_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxieord_full_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when IEORD LL size exceedes maxieord_full threshold,
 *        issue bp to TQ bits 063:032
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxieord_full_bp_01_r_t
 *
 * Implemented by: 
 *      maxieord_full_bp_01
 */
 
typedef struct
{
     unsigned  int          maxieord_full_bp;
} ncp_nca_itp_maxieord_full_bp_01_r_t;

/*! @struct ncp_nca_itp_maxieord_full_bp_02_r_t
 *  @brief null
 *  @details CFG access to maxieord_full_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxieord_full_bp_02_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxieord_full_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when IEORD LL size exceedes maxieord_full threshold,
 *        issue bp to TQ bits 095:064
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxieord_full_bp_02_r_t
 *
 * Implemented by: 
 *      maxieord_full_bp_02
 */
 
typedef struct
{
     unsigned  int          maxieord_full_bp;
} ncp_nca_itp_maxieord_full_bp_02_r_t;

/*! @struct ncp_nca_itp_maxieord_full_bp_03_r_t
 *  @brief null
 *  @details CFG access to maxieord_full_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxieord_full_bp_03_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxieord_full_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when IEORD LL size exceedes maxieord_full threshold,
 *        issue bp to TQ bits 127:096
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxieord_full_bp_03_r_t
 *
 * Implemented by: 
 *      maxieord_full_bp_03
 */
 
typedef struct
{
     unsigned  int          maxieord_full_bp;
} ncp_nca_itp_maxieord_full_bp_03_r_t;

/*! @struct ncp_nca_itp_maxieord_full_bp_04_r_t
 *  @brief null
 *  @details CFG access to maxieord_full_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxieord_full_bp_04_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxieord_full_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when IEORD LL size exceedes maxieord_full threshold,
 *        issue bp to TQ bits 159:128
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxieord_full_bp_04_r_t
 *
 * Implemented by: 
 *      maxieord_full_bp_04
 */
 
typedef struct
{
     unsigned  int          maxieord_full_bp;
} ncp_nca_itp_maxieord_full_bp_04_r_t;

/*! @struct ncp_nca_itp_maxieord_full_bp_05_r_t
 *  @brief null
 *  @details CFG access to maxieord_full_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxieord_full_bp_05_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxieord_full_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when IEORD LL size exceedes maxieord_full threshold,
 *        issue bp to TQ bits 191:160
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxieord_full_bp_05_r_t
 *
 * Implemented by: 
 *      maxieord_full_bp_05
 */
 
typedef struct
{
     unsigned  int          maxieord_full_bp;
} ncp_nca_itp_maxieord_full_bp_05_r_t;

/*! @struct ncp_nca_itp_maxieord_full_bp_06_r_t
 *  @brief null
 *  @details CFG access to maxieord_full_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxieord_full_bp_06_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 20 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param maxieord_full_bp </td>
 *     <td width="20%" align="center"> 12 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when IEORD LL size exceedes maxieord_full threshold,
 *        issue bp to TQ bits 203:192
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxieord_full_bp_06_r_t
 *
 * Implemented by: 
 *      maxieord_full_bp_06
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 20;
     unsigned      maxieord_full_bp                          : 12;
#else    /* Little Endian */
     unsigned      maxieord_full_bp                          : 12;
     unsigned      reserved0                                 : 20;
#endif
} ncp_nca_itp_maxieord_full_bp_06_r_t;

/*! @struct ncp_nca_itp_control_general_40_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_general_40_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> RESERVED </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_general_40_r_t
 *
 * Implemented by: 
 *      control_general_40
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_itp_control_general_40_r_t;

/*! @struct ncp_nca_itp_maxieunord_full_bp_00_r_t
 *  @brief null
 *  @details CFG access to maxieunord_full_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxieunord_full_bp_00_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxieunord_full_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when IEUNORD LL size exceedes maxieunord_full threshold,
 *        issue bp to TQ bits 031:000
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxieunord_full_bp_00_r_t
 *
 * Implemented by: 
 *      maxieunord_full_bp_00
 */
 
typedef struct
{
     unsigned  int        maxieunord_full_bp;
} ncp_nca_itp_maxieunord_full_bp_00_r_t;

/*! @struct ncp_nca_itp_maxieunord_full_bp_01_r_t
 *  @brief null
 *  @details CFG access to maxieunord_full_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxieunord_full_bp_01_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxieunord_full_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when IEUNORD LL size exceedes maxieunord_full threshold,
 *        issue bp to TQ bits 063:032
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxieunord_full_bp_01_r_t
 *
 * Implemented by: 
 *      maxieunord_full_bp_01
 */
 
typedef struct
{
     unsigned  int        maxieunord_full_bp;
} ncp_nca_itp_maxieunord_full_bp_01_r_t;

/*! @struct ncp_nca_itp_maxieunord_full_bp_02_r_t
 *  @brief null
 *  @details CFG access to maxieunord_full_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxieunord_full_bp_02_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxieunord_full_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when IEUNORD LL size exceedes maxieunord_full threshold,
 *        issue bp to TQ bits 095:064
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxieunord_full_bp_02_r_t
 *
 * Implemented by: 
 *      maxieunord_full_bp_02
 */
 
typedef struct
{
     unsigned  int        maxieunord_full_bp;
} ncp_nca_itp_maxieunord_full_bp_02_r_t;

/*! @struct ncp_nca_itp_maxieunord_full_bp_03_r_t
 *  @brief null
 *  @details CFG access to maxieunord_full_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxieunord_full_bp_03_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxieunord_full_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when IEUNORD LL size exceedes maxieunord_full threshold,
 *        issue bp to TQ bits 127:096
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxieunord_full_bp_03_r_t
 *
 * Implemented by: 
 *      maxieunord_full_bp_03
 */
 
typedef struct
{
     unsigned  int        maxieunord_full_bp;
} ncp_nca_itp_maxieunord_full_bp_03_r_t;

/*! @struct ncp_nca_itp_maxieunord_full_bp_04_r_t
 *  @brief null
 *  @details CFG access to maxieunord_full_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxieunord_full_bp_04_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxieunord_full_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when IEUNORD LL size exceedes maxieunord_full threshold,
 *        issue bp to TQ bits 159:128
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxieunord_full_bp_04_r_t
 *
 * Implemented by: 
 *      maxieunord_full_bp_04
 */
 
typedef struct
{
     unsigned  int        maxieunord_full_bp;
} ncp_nca_itp_maxieunord_full_bp_04_r_t;

/*! @struct ncp_nca_itp_maxieunord_full_bp_05_r_t
 *  @brief null
 *  @details CFG access to maxieunord_full_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxieunord_full_bp_05_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param maxieunord_full_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when IEUNORD LL size exceedes maxieunord_full threshold,
 *        issue bp to TQ bits 191:160
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxieunord_full_bp_05_r_t
 *
 * Implemented by: 
 *      maxieunord_full_bp_05
 */
 
typedef struct
{
     unsigned  int        maxieunord_full_bp;
} ncp_nca_itp_maxieunord_full_bp_05_r_t;

/*! @struct ncp_nca_itp_maxieunord_full_bp_06_r_t
 *  @brief null
 *  @details CFG access to maxieunord_full_bp register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_maxieunord_full_bp_06_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 20 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param maxieunord_full_bp </td>
 *     <td width="20%" align="center"> 12 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> when IEUNORD LL size exceedes maxieunord_full threshold,
 *        issue bp to TQ bits 203:192
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_maxieunord_full_bp_06_r_t
 *
 * Implemented by: 
 *      maxieunord_full_bp_06
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 20;
     unsigned      maxieunord_full_bp                        : 12;
#else    /* Little Endian */
     unsigned      maxieunord_full_bp                        : 12;
     unsigned      reserved0                                 : 20;
#endif
} ncp_nca_itp_maxieunord_full_bp_06_r_t;

/*! @struct ncp_nca_itp_control_general_47_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_general_47_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 20 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param modifytemplaiteid </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> control for the creation of the templateID in the
 *        iPCQ TaskHeader
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param modifytemplaiteidvalue </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> amount to modify the templateId in the iPCQ TaskHeader </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_general_47_r_t
 *
 * Implemented by: 
 *      control_general_47
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 20;
     unsigned      modifytemplaiteid                         :  4;
     unsigned      modifytemplaiteidvalue                    :  8;
#else    /* Little Endian */
     unsigned      modifytemplaiteidvalue                    :  8;
     unsigned      modifytemplaiteid                         :  4;
     unsigned      reserved0                                 : 20;
#endif
} ncp_nca_itp_control_general_47_r_t;

/*! @struct ncp_nca_itp_control_general_48_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_general_48_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param enable_tqbp_pergid_unissued </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> enable_tqbp_pergid_unissued </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param enable_tqbp_pertq_unissuedqueued </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> enable_tqbp_pertq_unissuedqueued </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param enable_tqbp_pertq_unissued </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> enable_tqbp_pertq_unissued </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param maxtqsequnce </td>
 *     <td width="20%" align="center"> 24 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> maxtqsequnce </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_general_48_r_t
 *
 * Implemented by: 
 *      control_general_48
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  5;
     unsigned      enable_tqbp_pergid_unissued               :  1;
     unsigned      enable_tqbp_pertq_unissuedqueued          :  1;
     unsigned      enable_tqbp_pertq_unissued                :  1;
     unsigned      maxtqsequnce                              : 24;
#else    /* Little Endian */
     unsigned      maxtqsequnce                              : 24;
     unsigned      enable_tqbp_pertq_unissued                :  1;
     unsigned      enable_tqbp_pertq_unissuedqueued          :  1;
     unsigned      enable_tqbp_pergid_unissued               :  1;
     unsigned      reserved0                                 :  5;
#endif
} ncp_nca_itp_control_general_48_r_t;

/*! @struct ncp_nca_itp_control_general_49_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_general_49_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ll_completion_afull </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> ll_completion afull </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ll_preproc_afull </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ll_preproc afull </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_general_49_r_t
 *
 * Implemented by: 
 *      control_general_49
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ll_completion_afull                       : 16;
     unsigned      ll_preproc_afull                          : 16;
#else    /* Little Endian */
     unsigned      ll_preproc_afull                          : 16;
     unsigned      ll_completion_afull                       : 16;
#endif
} ncp_nca_itp_control_general_49_r_t;

/*! @struct ncp_nca_itp_control_general_50_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_general_50_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ll_ieord_afull </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> ll_ieord afull </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ll_ieunord_afull </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ll_ieunord afull </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_general_50_r_t
 *
 * Implemented by: 
 *      control_general_50
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ll_ieord_afull                            : 16;
     unsigned      ll_ieunord_afull                          : 16;
#else    /* Little Endian */
     unsigned      ll_ieunord_afull                          : 16;
     unsigned      ll_ieord_afull                            : 16;
#endif
} ncp_nca_itp_control_general_50_r_t;

/*! @struct ncp_nca_itp_control_general_51_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_control_general_51_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ll_ieordsched_afull </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> ll_ieordsched afull </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ll_ieordready_afull </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ll_ieordready afull </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_control_general_51_r_t
 *
 * Implemented by: 
 *      control_general_51
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ll_ieordsched_afull                       : 16;
     unsigned      ll_ieordready_afull                       : 16;
#else    /* Little Endian */
     unsigned      ll_ieordready_afull                       : 16;
     unsigned      ll_ieordsched_afull                       : 16;
#endif
} ncp_nca_itp_control_general_51_r_t;

/*! @struct ncp_nca_itp_status_ll_preproc_status_r_t
 *  @brief null
 *  @details CFG access to Status. Status of ll_preproc_status OLL
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_ll_preproc_status_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param size </td>
 *     <td width="20%" align="center"> 20 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Current number of entries stored in LL </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ll_busy </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Any LL is currently processing a request </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ll_valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Any LL has a HP which is allocated and complete and
 *        ready to be popped
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> The LL is full and has no remaining entries </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param freelist_pop_id_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> The freelist used to allocate new entries status.
 *        0: empty. 1:entry available
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_write_resp_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> The current value of LL pop write response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_read_resp_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> The current value of LL pop read response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param complete_resp_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> The current value of LL complete response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param alloc_resp_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> The current value of LL allocate response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_write_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> The current value of the LL pop write reqeust interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_read_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The current value of the LL pop read reqeust interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param complete_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> The current value of the LL complete reqeust interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param alloc_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> The current value of the LL allocate reqeust interface </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_ll_preproc_status_r_t
 *
 * Implemented by: 
 *      status_ll_preproc_status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      size                                      : 20;
     unsigned      ll_busy                                   :  1;
     unsigned      ll_valid                                  :  1;
     unsigned      full                                      :  1;
     unsigned      freelist_pop_id_v                         :  1;
     unsigned      pop_write_resp_v                          :  1;
     unsigned      pop_read_resp_v                           :  1;
     unsigned      complete_resp_v                           :  1;
     unsigned      alloc_resp_v                              :  1;
     unsigned      pop_write_req_v                           :  1;
     unsigned      pop_read_req_v                            :  1;
     unsigned      complete_req_v                            :  1;
     unsigned      alloc_req_v                               :  1;
#else    /* Little Endian */
     unsigned      alloc_req_v                               :  1;
     unsigned      complete_req_v                            :  1;
     unsigned      pop_read_req_v                            :  1;
     unsigned      pop_write_req_v                           :  1;
     unsigned      alloc_resp_v                              :  1;
     unsigned      complete_resp_v                           :  1;
     unsigned      pop_read_resp_v                           :  1;
     unsigned      pop_write_resp_v                          :  1;
     unsigned      freelist_pop_id_v                         :  1;
     unsigned      full                                      :  1;
     unsigned      ll_valid                                  :  1;
     unsigned      ll_busy                                   :  1;
     unsigned      size                                      : 20;
#endif
} ncp_nca_itp_status_ll_preproc_status_r_t;

/*! @struct ncp_nca_itp_status_ll_ieunord_status_r_t
 *  @brief null
 *  @details CFG access to Status. Status of ll_ieunord_status OLL
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_ll_ieunord_status_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param size </td>
 *     <td width="20%" align="center"> 20 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Current number of entries stored in LL </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ll_busy </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Any LL is currently processing a request </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ll_valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Any LL has a HP which is allocated and complete and
 *        ready to be popped
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> The LL is full and has no remaining entries </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param freelist_pop_id_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> The freelist used to allocate new entries status.
 *        0: empty. 1:entry available
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_write_resp_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> The current value of LL pop write response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_read_resp_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> The current value of LL pop read response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param complete_resp_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> The current value of LL complete response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param alloc_resp_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> The current value of LL allocate response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_write_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> The current value of the LL pop write reqeust interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_read_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The current value of the LL pop read reqeust interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param complete_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> The current value of the LL complete reqeust interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param alloc_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> The current value of the LL allocate reqeust interface </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_ll_ieunord_status_r_t
 *
 * Implemented by: 
 *      status_ll_ieunord_status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      size                                      : 20;
     unsigned      ll_busy                                   :  1;
     unsigned      ll_valid                                  :  1;
     unsigned      full                                      :  1;
     unsigned      freelist_pop_id_v                         :  1;
     unsigned      pop_write_resp_v                          :  1;
     unsigned      pop_read_resp_v                           :  1;
     unsigned      complete_resp_v                           :  1;
     unsigned      alloc_resp_v                              :  1;
     unsigned      pop_write_req_v                           :  1;
     unsigned      pop_read_req_v                            :  1;
     unsigned      complete_req_v                            :  1;
     unsigned      alloc_req_v                               :  1;
#else    /* Little Endian */
     unsigned      alloc_req_v                               :  1;
     unsigned      complete_req_v                            :  1;
     unsigned      pop_read_req_v                            :  1;
     unsigned      pop_write_req_v                           :  1;
     unsigned      alloc_resp_v                              :  1;
     unsigned      complete_resp_v                           :  1;
     unsigned      pop_read_resp_v                           :  1;
     unsigned      pop_write_resp_v                          :  1;
     unsigned      freelist_pop_id_v                         :  1;
     unsigned      full                                      :  1;
     unsigned      ll_valid                                  :  1;
     unsigned      ll_busy                                   :  1;
     unsigned      size                                      : 20;
#endif
} ncp_nca_itp_status_ll_ieunord_status_r_t;

/*! @struct ncp_nca_itp_status_ll_ieord_status_r_t
 *  @brief null
 *  @details CFG access to Status. Status of ll_ieord_status OLL
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_ll_ieord_status_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param size </td>
 *     <td width="20%" align="center"> 20 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Current number of entries stored in LL </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ll_busy </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Any LL is currently processing a request </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ll_valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Any LL has a HP which is allocated and complete and
 *        ready to be popped
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> The LL is full and has no remaining entries </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param freelist_pop_id_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> The freelist used to allocate new entries status.
 *        0: empty. 1:entry available
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_write_resp_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> The current value of LL pop write response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_read_resp_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> The current value of LL pop read response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param complete_resp_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> The current value of LL complete response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param alloc_resp_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> The current value of LL allocate response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_write_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> The current value of the LL pop write reqeust interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_read_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The current value of the LL pop read reqeust interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param complete_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> The current value of the LL complete reqeust interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param alloc_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> The current value of the LL allocate reqeust interface </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_ll_ieord_status_r_t
 *
 * Implemented by: 
 *      status_ll_ieord_status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      size                                      : 20;
     unsigned      ll_busy                                   :  1;
     unsigned      ll_valid                                  :  1;
     unsigned      full                                      :  1;
     unsigned      freelist_pop_id_v                         :  1;
     unsigned      pop_write_resp_v                          :  1;
     unsigned      pop_read_resp_v                           :  1;
     unsigned      complete_resp_v                           :  1;
     unsigned      alloc_resp_v                              :  1;
     unsigned      pop_write_req_v                           :  1;
     unsigned      pop_read_req_v                            :  1;
     unsigned      complete_req_v                            :  1;
     unsigned      alloc_req_v                               :  1;
#else    /* Little Endian */
     unsigned      alloc_req_v                               :  1;
     unsigned      complete_req_v                            :  1;
     unsigned      pop_read_req_v                            :  1;
     unsigned      pop_write_req_v                           :  1;
     unsigned      alloc_resp_v                              :  1;
     unsigned      complete_resp_v                           :  1;
     unsigned      pop_read_resp_v                           :  1;
     unsigned      pop_write_resp_v                          :  1;
     unsigned      freelist_pop_id_v                         :  1;
     unsigned      full                                      :  1;
     unsigned      ll_valid                                  :  1;
     unsigned      ll_busy                                   :  1;
     unsigned      size                                      : 20;
#endif
} ncp_nca_itp_status_ll_ieord_status_r_t;

/*! @struct ncp_nca_itp_status_ll_ieordready_status_r_t
 *  @brief null
 *  @details CFG access to Status. Status of ll_ieordready_status AW_ll
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_ll_ieordready_status_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param size </td>
 *     <td width="20%" align="center"> 20 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Current number of entries stored in LL </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ll_busy </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Any LL is currently processing a request </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ll_valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Any LL has a HP which is allocated and complete and
 *        ready to be popped
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> The LL is full and has no remaining entries </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param freelist_pop_id_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> The freelist used to allocate new entries status.
 *        0: empty. 1:entry available
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_write_resp_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> The current value of LL pop write response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_read_resp_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> The current value of LL pop read response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param complete_resp_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> The current value of LL complete response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param alloc_resp_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> The current value of LL allocate response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_write_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> The current value of the LL pop write reqeust interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_read_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The current value of the LL pop read reqeust interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param complete_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> The current value of the LL complete reqeust interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param alloc_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> The current value of the LL allocate reqeust interface </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_ll_ieordready_status_r_t
 *
 * Implemented by: 
 *      status_ll_ieordready_status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      size                                      : 20;
     unsigned      ll_busy                                   :  1;
     unsigned      ll_valid                                  :  1;
     unsigned      full                                      :  1;
     unsigned      freelist_pop_id_v                         :  1;
     unsigned      pop_write_resp_v                          :  1;
     unsigned      pop_read_resp_v                           :  1;
     unsigned      complete_resp_v                           :  1;
     unsigned      alloc_resp_v                              :  1;
     unsigned      pop_write_req_v                           :  1;
     unsigned      pop_read_req_v                            :  1;
     unsigned      complete_req_v                            :  1;
     unsigned      alloc_req_v                               :  1;
#else    /* Little Endian */
     unsigned      alloc_req_v                               :  1;
     unsigned      complete_req_v                            :  1;
     unsigned      pop_read_req_v                            :  1;
     unsigned      pop_write_req_v                           :  1;
     unsigned      alloc_resp_v                              :  1;
     unsigned      complete_resp_v                           :  1;
     unsigned      pop_read_resp_v                           :  1;
     unsigned      pop_write_resp_v                          :  1;
     unsigned      freelist_pop_id_v                         :  1;
     unsigned      full                                      :  1;
     unsigned      ll_valid                                  :  1;
     unsigned      ll_busy                                   :  1;
     unsigned      size                                      : 20;
#endif
} ncp_nca_itp_status_ll_ieordready_status_r_t;

/*! @struct ncp_nca_itp_status_ll_ieordsched_status_r_t
 *  @brief null
 *  @details CFG access to Status. Status of ll_ieordsched_status OLL
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_ll_ieordsched_status_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param size </td>
 *     <td width="20%" align="center"> 26 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Current number of entries stored in LL </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ll_busy </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Any LL is currently processing a request </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ll_valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Any LL has a HP which is allocated and complete and
 *        ready to be popped
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> The LL is full and has no remaining entries </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param freelist_pop_id_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The freelist used to allocate new entries status.
 *        0: empty. 1:entry available
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param complete_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> The current value of the LL delete reqeust interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param alloc_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> The current value of the LL allocate reqeust interface </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_ll_ieordsched_status_r_t
 *
 * Implemented by: 
 *      status_ll_ieordsched_status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      size                                      : 26;
     unsigned      ll_busy                                   :  1;
     unsigned      ll_valid                                  :  1;
     unsigned      full                                      :  1;
     unsigned      freelist_pop_id_v                         :  1;
     unsigned      complete_req_v                            :  1;
     unsigned      alloc_req_v                               :  1;
#else    /* Little Endian */
     unsigned      alloc_req_v                               :  1;
     unsigned      complete_req_v                            :  1;
     unsigned      freelist_pop_id_v                         :  1;
     unsigned      full                                      :  1;
     unsigned      ll_valid                                  :  1;
     unsigned      ll_busy                                   :  1;
     unsigned      size                                      : 26;
#endif
} ncp_nca_itp_status_ll_ieordsched_status_r_t;

/*! @struct ncp_nca_itp_status_ll_completion_status_r_t
 *  @brief null
 *  @details CFG access to Status. Status of ll_completion_status OLL
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_ll_completion_status_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param size </td>
 *     <td width="20%" align="center"> 20 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Current number of entries stored in LL </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ll_busy </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Any LL is currently processing a request </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ll_valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Any LL has a HP which is allocated and complete and
 *        ready to be popped
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> The LL is full and has no remaining entries </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param freelist_pop_id_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> The freelist used to allocate new entries status.
 *        0: empty. 1:entry available
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_write_resp_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> The current value of LL pop write response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_read_resp_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> The current value of LL pop read response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param complete_resp_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> The current value of LL complete response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param alloc_resp_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> The current value of LL allocate response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_write_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> The current value of the LL pop write reqeust interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_read_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The current value of the LL pop read reqeust interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param complete_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> The current value of the LL complete reqeust interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param alloc_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> The current value of the LL allocate reqeust interface </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_ll_completion_status_r_t
 *
 * Implemented by: 
 *      status_ll_completion_status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      size                                      : 20;
     unsigned      ll_busy                                   :  1;
     unsigned      ll_valid                                  :  1;
     unsigned      full                                      :  1;
     unsigned      freelist_pop_id_v                         :  1;
     unsigned      pop_write_resp_v                          :  1;
     unsigned      pop_read_resp_v                           :  1;
     unsigned      complete_resp_v                           :  1;
     unsigned      alloc_resp_v                              :  1;
     unsigned      pop_write_req_v                           :  1;
     unsigned      pop_read_req_v                            :  1;
     unsigned      complete_req_v                            :  1;
     unsigned      alloc_req_v                               :  1;
#else    /* Little Endian */
     unsigned      alloc_req_v                               :  1;
     unsigned      complete_req_v                            :  1;
     unsigned      pop_read_req_v                            :  1;
     unsigned      pop_write_req_v                           :  1;
     unsigned      alloc_resp_v                              :  1;
     unsigned      complete_resp_v                           :  1;
     unsigned      pop_read_resp_v                           :  1;
     unsigned      pop_write_resp_v                          :  1;
     unsigned      freelist_pop_id_v                         :  1;
     unsigned      full                                      :  1;
     unsigned      ll_valid                                  :  1;
     unsigned      ll_busy                                   :  1;
     unsigned      size                                      : 20;
#endif
} ncp_nca_itp_status_ll_completion_status_r_t;

/*! @struct ncp_nca_itp_status_cam_ieordered_r_t
 *  @brief null
 *  @details CFG access to Status. Status of cam_ieordered CAM
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_cam_ieordered_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param count </td>
 *     <td width="20%" align="center"> 25 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> The current value of the CAM count </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param aval_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> The current value of the CAM AVAL output </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param miss </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> The current value of the CAM MISS output </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> The current value of the CAM VALID output </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param unload </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> The current value of the CAM UNLOAD </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param compare </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The current value of the CAM COMPARE </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param re </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> The current value of the CAM RE </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param we </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> The current value of the CAM WE </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_cam_ieordered_r_t
 *
 * Implemented by: 
 *      status_cam_ieordered
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      count                                     : 25;
     unsigned      aval_v                                    :  1;
     unsigned      miss                                      :  1;
     unsigned      valid                                     :  1;
     unsigned      unload                                    :  1;
     unsigned      compare                                   :  1;
     unsigned      re                                        :  1;
     unsigned      we                                        :  1;
#else    /* Little Endian */
     unsigned      we                                        :  1;
     unsigned      re                                        :  1;
     unsigned      compare                                   :  1;
     unsigned      unload                                    :  1;
     unsigned      valid                                     :  1;
     unsigned      miss                                      :  1;
     unsigned      aval_v                                    :  1;
     unsigned      count                                     : 25;
#endif
} ncp_nca_itp_status_cam_ieordered_r_t;

/*! @struct ncp_nca_itp_status_fifo_itp_system_in0_r_t
 *  @brief null
 *  @details CFG access to Status. Status of fifo_itp_system_in0 FIFOstat
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_fifo_itp_system_in0_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_depth </td>
 *     <td width="20%" align="center"> 26 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> FIFO Depth </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifio_full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> FIFO Full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_afull </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> FIFO Almost Full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_aempty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> FIFO Almost Empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_empty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> FIFO Empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> FIFO Overflow </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_underflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> FIFO Underflow </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_fifo_itp_system_in0_r_t
 *
 * Implemented by: 
 *      status_fifo_itp_system_in0
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      fifo_depth                                : 26;
     unsigned      fifio_full                                :  1;
     unsigned      fifo_afull                                :  1;
     unsigned      fifo_aempty                               :  1;
     unsigned      fifo_empty                                :  1;
     unsigned      fifo_overflow                             :  1;
     unsigned      fifo_underflow                            :  1;
#else    /* Little Endian */
     unsigned      fifo_underflow                            :  1;
     unsigned      fifo_overflow                             :  1;
     unsigned      fifo_empty                                :  1;
     unsigned      fifo_aempty                               :  1;
     unsigned      fifo_afull                                :  1;
     unsigned      fifio_full                                :  1;
     unsigned      fifo_depth                                : 26;
#endif
} ncp_nca_itp_status_fifo_itp_system_in0_r_t;

/*! @struct ncp_nca_itp_status_fifo_itp_system_out0_r_t
 *  @brief null
 *  @details CFG access to Status. Status of fifo_itp_system_out0 FIFOstat
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_fifo_itp_system_out0_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_depth </td>
 *     <td width="20%" align="center"> 26 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> FIFO Depth </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifio_full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> FIFO Full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_afull </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> FIFO Almost Full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_aempty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> FIFO Almost Empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_empty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> FIFO Empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> FIFO Overflow </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_underflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> FIFO Underflow </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_fifo_itp_system_out0_r_t
 *
 * Implemented by: 
 *      status_fifo_itp_system_out0
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      fifo_depth                                : 26;
     unsigned      fifio_full                                :  1;
     unsigned      fifo_afull                                :  1;
     unsigned      fifo_aempty                               :  1;
     unsigned      fifo_empty                                :  1;
     unsigned      fifo_overflow                             :  1;
     unsigned      fifo_underflow                            :  1;
#else    /* Little Endian */
     unsigned      fifo_underflow                            :  1;
     unsigned      fifo_overflow                             :  1;
     unsigned      fifo_empty                                :  1;
     unsigned      fifo_aempty                               :  1;
     unsigned      fifo_afull                                :  1;
     unsigned      fifio_full                                :  1;
     unsigned      fifo_depth                                : 26;
#endif
} ncp_nca_itp_status_fifo_itp_system_out0_r_t;

/*! @struct ncp_nca_itp_status_fifo_itp_system_in1_r_t
 *  @brief null
 *  @details CFG access to Status. Status of fifo_itp_system_in1 FIFOstat
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_fifo_itp_system_in1_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_depth </td>
 *     <td width="20%" align="center"> 26 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> FIFO Depth </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifio_full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> FIFO Full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_afull </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> FIFO Almost Full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_aempty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> FIFO Almost Empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_empty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> FIFO Empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> FIFO Overflow </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_underflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> FIFO Underflow </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_fifo_itp_system_in1_r_t
 *
 * Implemented by: 
 *      status_fifo_itp_system_in1
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      fifo_depth                                : 26;
     unsigned      fifio_full                                :  1;
     unsigned      fifo_afull                                :  1;
     unsigned      fifo_aempty                               :  1;
     unsigned      fifo_empty                                :  1;
     unsigned      fifo_overflow                             :  1;
     unsigned      fifo_underflow                            :  1;
#else    /* Little Endian */
     unsigned      fifo_underflow                            :  1;
     unsigned      fifo_overflow                             :  1;
     unsigned      fifo_empty                                :  1;
     unsigned      fifo_aempty                               :  1;
     unsigned      fifo_afull                                :  1;
     unsigned      fifio_full                                :  1;
     unsigned      fifo_depth                                : 26;
#endif
} ncp_nca_itp_status_fifo_itp_system_in1_r_t;

/*! @struct ncp_nca_itp_status_fifo_itp_system_out1_r_t
 *  @brief null
 *  @details CFG access to Status. Status of fifo_itp_system_out1 FIFOstat
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_fifo_itp_system_out1_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_depth </td>
 *     <td width="20%" align="center"> 26 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> FIFO Depth </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifio_full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> FIFO Full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_afull </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> FIFO Almost Full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_aempty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> FIFO Almost Empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_empty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> FIFO Empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> FIFO Overflow </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_underflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> FIFO Underflow </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_fifo_itp_system_out1_r_t
 *
 * Implemented by: 
 *      status_fifo_itp_system_out1
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      fifo_depth                                : 26;
     unsigned      fifio_full                                :  1;
     unsigned      fifo_afull                                :  1;
     unsigned      fifo_aempty                               :  1;
     unsigned      fifo_empty                                :  1;
     unsigned      fifo_overflow                             :  1;
     unsigned      fifo_underflow                            :  1;
#else    /* Little Endian */
     unsigned      fifo_underflow                            :  1;
     unsigned      fifo_overflow                             :  1;
     unsigned      fifo_empty                                :  1;
     unsigned      fifo_aempty                               :  1;
     unsigned      fifo_afull                                :  1;
     unsigned      fifio_full                                :  1;
     unsigned      fifo_depth                                : 26;
#endif
} ncp_nca_itp_status_fifo_itp_system_out1_r_t;

/*! @struct ncp_nca_itp_status_fifo_itp_system_in2_r_t
 *  @brief null
 *  @details CFG access to Status. Status of fifo_itp_system_in2 FIFOstat
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_fifo_itp_system_in2_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_depth </td>
 *     <td width="20%" align="center"> 26 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> FIFO Depth </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifio_full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> FIFO Full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_afull </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> FIFO Almost Full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_aempty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> FIFO Almost Empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_empty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> FIFO Empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> FIFO Overflow </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_underflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> FIFO Underflow </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_fifo_itp_system_in2_r_t
 *
 * Implemented by: 
 *      status_fifo_itp_system_in2
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      fifo_depth                                : 26;
     unsigned      fifio_full                                :  1;
     unsigned      fifo_afull                                :  1;
     unsigned      fifo_aempty                               :  1;
     unsigned      fifo_empty                                :  1;
     unsigned      fifo_overflow                             :  1;
     unsigned      fifo_underflow                            :  1;
#else    /* Little Endian */
     unsigned      fifo_underflow                            :  1;
     unsigned      fifo_overflow                             :  1;
     unsigned      fifo_empty                                :  1;
     unsigned      fifo_aempty                               :  1;
     unsigned      fifo_afull                                :  1;
     unsigned      fifio_full                                :  1;
     unsigned      fifo_depth                                : 26;
#endif
} ncp_nca_itp_status_fifo_itp_system_in2_r_t;

/*! @struct ncp_nca_itp_status_fifo_itp_system_out2_r_t
 *  @brief null
 *  @details CFG access to Status. Status of fifo_itp_system_out2 FIFOstat
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_fifo_itp_system_out2_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_depth </td>
 *     <td width="20%" align="center"> 26 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> FIFO Depth </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifio_full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> FIFO Full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_afull </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> FIFO Almost Full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_aempty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> FIFO Almost Empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_empty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> FIFO Empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> FIFO Overflow </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_underflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> FIFO Underflow </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_fifo_itp_system_out2_r_t
 *
 * Implemented by: 
 *      status_fifo_itp_system_out2
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      fifo_depth                                : 26;
     unsigned      fifio_full                                :  1;
     unsigned      fifo_afull                                :  1;
     unsigned      fifo_aempty                               :  1;
     unsigned      fifo_empty                                :  1;
     unsigned      fifo_overflow                             :  1;
     unsigned      fifo_underflow                            :  1;
#else    /* Little Endian */
     unsigned      fifo_underflow                            :  1;
     unsigned      fifo_overflow                             :  1;
     unsigned      fifo_empty                                :  1;
     unsigned      fifo_aempty                               :  1;
     unsigned      fifo_afull                                :  1;
     unsigned      fifio_full                                :  1;
     unsigned      fifo_depth                                : 26;
#endif
} ncp_nca_itp_status_fifo_itp_system_out2_r_t;

/*! @struct ncp_nca_itp_status_state00_r_t
 *  @brief null
 *  @details CFG access to Status. Status of input & preprocess state machine
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_state00_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param state_ipcq_preproc_cpuheader_q </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> current value of preproc statemachine </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param state_input_q </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> current value of input statmemachine </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_state00_r_t
 *
 * Implemented by: 
 *      status_state00
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      state_ipcq_preproc_cpuheader_q            : 16;
     unsigned      state_input_q                             : 16;
#else    /* Little Endian */
     unsigned      state_input_q                             : 16;
     unsigned      state_ipcq_preproc_cpuheader_q            : 16;
#endif
} ncp_nca_itp_status_state00_r_t;

/*! @struct ncp_nca_itp_status_state01_r_t
 *  @brief null
 *  @details CFG access to Status. Status of preprocess copy & enqueue state machine
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_state01_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param state_ipcq_enqueue_q </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> current value of enqueue statemachine </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param state_ipcq_preproc_ptrcopy_q </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> current value of preprocess copy statmemachine </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_state01_r_t
 *
 * Implemented by: 
 *      status_state01
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      state_ipcq_enqueue_q                      : 16;
     unsigned      state_ipcq_preproc_ptrcopy_q              : 16;
#else    /* Little Endian */
     unsigned      state_ipcq_preproc_ptrcopy_q              : 16;
     unsigned      state_ipcq_enqueue_q                      : 16;
#endif
} ncp_nca_itp_status_state01_r_t;

/*! @struct ncp_nca_itp_status_state02_r_t
 *  @brief null
 *  @details CFG access to Status. Status of completion & schedule state machine
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_state02_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param state_ipcq_completion_q </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> current value of completion statemachine </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param state_ipcq_schedule0_q </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> current value of schedule statmemachine </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_state02_r_t
 *
 * Implemented by: 
 *      status_state02
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      state_ipcq_completion_q                   : 16;
     unsigned      state_ipcq_schedule0_q                    : 16;
#else    /* Little Endian */
     unsigned      state_ipcq_schedule0_q                    : 16;
     unsigned      state_ipcq_completion_q                   : 16;
#endif
} ncp_nca_itp_status_state02_r_t;

/*! @struct ncp_nca_itp_status_state03_r_t
 *  @brief null
 *  @details CFG access to Status.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_state03_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param state_sm_schedule1_q </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> current value of completion statemachine </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param state_ipcq_ptrs_q </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> current value of MTP pointers statmemachine </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_state03_r_t
 *
 * Implemented by: 
 *      status_state03
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      state_sm_schedule1_q                      : 16;
     unsigned      state_ipcq_ptrs_q                         : 16;
#else    /* Little Endian */
     unsigned      state_ipcq_ptrs_q                         : 16;
     unsigned      state_sm_schedule1_q                      : 16;
#endif
} ncp_nca_itp_status_state03_r_t;

/*! @struct ncp_nca_itp_status_state04_r_t
 *  @brief null
 *  @details CFG access to Status.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_state04_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param data_sm_dealloc_q </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> current value of deallocstatemachine </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data_sm_dynamic_q </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> current value of dynamic statmemachine </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_state04_r_t
 *
 * Implemented by: 
 *      status_state04
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      data_sm_dealloc_q                         : 16;
     unsigned      data_sm_dynamic_q                         : 16;
#else    /* Little Endian */
     unsigned      data_sm_dynamic_q                         : 16;
     unsigned      data_sm_dealloc_q                         : 16;
#endif
} ncp_nca_itp_status_state04_r_t;

/*! @struct ncp_nca_itp_status_state05_r_t
 *  @brief null
 *  @details CFG access to Status.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_state05_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param bcam </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> activity counter </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param mtp </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> activity counter </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param writeack0 </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> activity counter </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param writeack1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> activity counter </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_state05_r_t
 *
 * Implemented by: 
 *      status_state05
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  6;
     unsigned      bcam                                      : 10;
     unsigned      mtp                                       :  6;
     unsigned      writeack0                                 :  5;
     unsigned      writeack1                                 :  5;
#else    /* Little Endian */
     unsigned      writeack1                                 :  5;
     unsigned      writeack0                                 :  5;
     unsigned      mtp                                       :  6;
     unsigned      bcam                                      : 10;
     unsigned      reserved0                                 :  6;
#endif
} ncp_nca_itp_status_state05_r_t;

/*! @struct ncp_nca_itp_status_state06_r_t
 *  @brief null
 *  @details CFG access to Status.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_state06_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 31 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_qpm_qstatus_all_q </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> QPM message to drop ALL unshceuded task </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_state06_r_t
 *
 * Implemented by: 
 *      status_state06
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 31;
     unsigned      if_qpm_qstatus_all_q                      :  1;
#else    /* Little Endian */
     unsigned      if_qpm_qstatus_all_q                      :  1;
     unsigned      reserved0                                 : 31;
#endif
} ncp_nca_itp_status_state06_r_t;

/*! @struct ncp_nca_itp_status_state07_r_t
 *  @brief null
 *  @details CFG access to Status.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_state07_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param state_sm_task_q </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> current value of task statmemachine </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_state07_r_t
 *
 * Implemented by: 
 *      status_state07
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      state_sm_task_q                           : 16;
#else    /* Little Endian */
     unsigned      state_sm_task_q                           : 16;
     unsigned      reserved0                                 : 16;
#endif
} ncp_nca_itp_status_state07_r_t;

/*! @struct ncp_nca_itp_status_state08_r_t
 *  @brief null
 *  @details CFG access to Status.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_state08_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 22 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ncav3_activitycounter_bcam_current_value </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> current value of task BCAM counter </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_state08_r_t
 *
 * Implemented by: 
 *      status_state08
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 22;
     unsigned      ncav3_activitycounter_bcam_current_value  : 10;
#else    /* Little Endian */
     unsigned      ncav3_activitycounter_bcam_current_value  : 10;
     unsigned      reserved0                                 : 22;
#endif
} ncp_nca_itp_status_state08_r_t;

/*! @struct ncp_nca_itp_status_state09_r_t
 *  @brief null
 *  @details CFG access to Status.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_state09_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 25 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param db_in_qpm_qstatus_status </td>
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> current value of task DB QPM status </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_state09_r_t
 *
 * Implemented by: 
 *      status_state09
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 25;
     unsigned      db_in_qpm_qstatus_status                  :  7;
#else    /* Little Endian */
     unsigned      db_in_qpm_qstatus_status                  :  7;
     unsigned      reserved0                                 : 25;
#endif
} ncp_nca_itp_status_state09_r_t;

/*! @struct ncp_nca_itp_status_state10_r_t
 *  @brief null
 *  @details CFG access to Status.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_state10_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param itpversion </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ITP version </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_state10_r_t
 *
 * Implemented by: 
 *      status_state10
 */
 
typedef struct
{
     unsigned  int                itpversion;
} ncp_nca_itp_status_state10_r_t;

/*! @struct ncp_nca_itp_status_tqbp0_r_t
 *  @brief null
 *  @details TQBP bit arry
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_tqbp0_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param tqbp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> tqbp [31:0] </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_tqbp0_r_t
 *
 * Implemented by: 
 *      status_tqbp0
 */
 
typedef struct
{
     unsigned  int                      tqbp;
} ncp_nca_itp_status_tqbp0_r_t;

/*! @struct ncp_nca_itp_status_tqbp1_r_t
 *  @brief null
 *  @details TQBP bit arry
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_tqbp1_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param tqbp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> tqbp [63:32] </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_tqbp1_r_t
 *
 * Implemented by: 
 *      status_tqbp1
 */
 
typedef struct
{
     unsigned  int                      tqbp;
} ncp_nca_itp_status_tqbp1_r_t;

/*! @struct ncp_nca_itp_status_tqbp2_r_t
 *  @brief null
 *  @details TQBP bit arry
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_tqbp2_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param tqbp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> tqbp [95:64] </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_tqbp2_r_t
 *
 * Implemented by: 
 *      status_tqbp2
 */
 
typedef struct
{
     unsigned  int                      tqbp;
} ncp_nca_itp_status_tqbp2_r_t;

/*! @struct ncp_nca_itp_status_tqbp3_r_t
 *  @brief null
 *  @details TQBP bit arry
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_tqbp3_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param tqbp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> tqbp [127:96] </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_tqbp3_r_t
 *
 * Implemented by: 
 *      status_tqbp3
 */
 
typedef struct
{
     unsigned  int                      tqbp;
} ncp_nca_itp_status_tqbp3_r_t;

/*! @struct ncp_nca_itp_status_tqbp4_r_t
 *  @brief null
 *  @details TQBP bit arry
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_tqbp4_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param tqbp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> tqbp [159:128] </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_tqbp4_r_t
 *
 * Implemented by: 
 *      status_tqbp4
 */
 
typedef struct
{
     unsigned  int                      tqbp;
} ncp_nca_itp_status_tqbp4_r_t;

/*! @struct ncp_nca_itp_status_tqbp5_r_t
 *  @brief null
 *  @details TQBP bit arry
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_tqbp5_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param tqbp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> tqbp [191:160] </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_tqbp5_r_t
 *
 * Implemented by: 
 *      status_tqbp5
 */
 
typedef struct
{
     unsigned  int                      tqbp;
} ncp_nca_itp_status_tqbp5_r_t;

/*! @struct ncp_nca_itp_status_tqbp6_r_t
 *  @brief null
 *  @details TQBP bit arry
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_tqbp6_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param tqbp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> tqbp [223:192] </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_tqbp6_r_t
 *
 * Implemented by: 
 *      status_tqbp6
 */
 
typedef struct
{
     unsigned  int                      tqbp;
} ncp_nca_itp_status_tqbp6_r_t;

/*! @struct ncp_nca_itp_status_tqsequence_r_t
 *  @brief null
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_status_tqsequence_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param tqsequence </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> tqsequence </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_status_tqsequence_r_t
 *
 * Implemented by: 
 *      status_tqsequence
 */
 
typedef struct
{
     unsigned  int                tqsequence;
} ncp_nca_itp_status_tqsequence_r_t;

/*! @struct ncp_nca_itp_ipcq_size00_r_t
 *  @brief null
 *  @details iPCQ size for specified compressed iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_size00_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq03 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq02 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq01 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq00 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_size00_r_t
 *
 * Implemented by: 
 *      ipcq_size00
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq03                                    :  8;
     unsigned      ipcq02                                    :  8;
     unsigned      ipcq01                                    :  8;
     unsigned      ipcq00                                    :  8;
#else    /* Little Endian */
     unsigned      ipcq00                                    :  8;
     unsigned      ipcq01                                    :  8;
     unsigned      ipcq02                                    :  8;
     unsigned      ipcq03                                    :  8;
#endif
} ncp_nca_itp_ipcq_size00_r_t;

/*! @struct ncp_nca_itp_ipcq_size01_r_t
 *  @brief null
 *  @details iPCQ size for specified compressed iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_size01_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq07 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq06 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq05 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq04 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_size01_r_t
 *
 * Implemented by: 
 *      ipcq_size01
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq07                                    :  8;
     unsigned      ipcq06                                    :  8;
     unsigned      ipcq05                                    :  8;
     unsigned      ipcq04                                    :  8;
#else    /* Little Endian */
     unsigned      ipcq04                                    :  8;
     unsigned      ipcq05                                    :  8;
     unsigned      ipcq06                                    :  8;
     unsigned      ipcq07                                    :  8;
#endif
} ncp_nca_itp_ipcq_size01_r_t;

/*! @struct ncp_nca_itp_ipcq_size02_r_t
 *  @brief null
 *  @details iPCQ size for specified compressed iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_size02_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq11 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq10 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq09 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq08 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_size02_r_t
 *
 * Implemented by: 
 *      ipcq_size02
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq11                                    :  8;
     unsigned      ipcq10                                    :  8;
     unsigned      ipcq09                                    :  8;
     unsigned      ipcq08                                    :  8;
#else    /* Little Endian */
     unsigned      ipcq08                                    :  8;
     unsigned      ipcq09                                    :  8;
     unsigned      ipcq10                                    :  8;
     unsigned      ipcq11                                    :  8;
#endif
} ncp_nca_itp_ipcq_size02_r_t;

/*! @struct ncp_nca_itp_ipcq_size03_r_t
 *  @brief null
 *  @details iPCQ size for specified compressed iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_size03_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq15 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq14 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq13 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq12 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_size03_r_t
 *
 * Implemented by: 
 *      ipcq_size03
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq15                                    :  8;
     unsigned      ipcq14                                    :  8;
     unsigned      ipcq13                                    :  8;
     unsigned      ipcq12                                    :  8;
#else    /* Little Endian */
     unsigned      ipcq12                                    :  8;
     unsigned      ipcq13                                    :  8;
     unsigned      ipcq14                                    :  8;
     unsigned      ipcq15                                    :  8;
#endif
} ncp_nca_itp_ipcq_size03_r_t;

/*! @struct ncp_nca_itp_ipcq_size04_r_t
 *  @brief null
 *  @details iPCQ size for specified compressed iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_size04_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq19 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq18 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq17 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq16 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_size04_r_t
 *
 * Implemented by: 
 *      ipcq_size04
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq19                                    :  8;
     unsigned      ipcq18                                    :  8;
     unsigned      ipcq17                                    :  8;
     unsigned      ipcq16                                    :  8;
#else    /* Little Endian */
     unsigned      ipcq16                                    :  8;
     unsigned      ipcq17                                    :  8;
     unsigned      ipcq18                                    :  8;
     unsigned      ipcq19                                    :  8;
#endif
} ncp_nca_itp_ipcq_size04_r_t;

/*! @struct ncp_nca_itp_ipcq_size05_r_t
 *  @brief null
 *  @details iPCQ size for specified compressed iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_size05_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq23 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq22 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq21 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq20 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_size05_r_t
 *
 * Implemented by: 
 *      ipcq_size05
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq23                                    :  8;
     unsigned      ipcq22                                    :  8;
     unsigned      ipcq21                                    :  8;
     unsigned      ipcq20                                    :  8;
#else    /* Little Endian */
     unsigned      ipcq20                                    :  8;
     unsigned      ipcq21                                    :  8;
     unsigned      ipcq22                                    :  8;
     unsigned      ipcq23                                    :  8;
#endif
} ncp_nca_itp_ipcq_size05_r_t;

/*! @struct ncp_nca_itp_ipcq_size06_r_t
 *  @brief null
 *  @details iPCQ size for specified compressed iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_size06_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq27 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq26 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq25 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq24 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_size06_r_t
 *
 * Implemented by: 
 *      ipcq_size06
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq27                                    :  8;
     unsigned      ipcq26                                    :  8;
     unsigned      ipcq25                                    :  8;
     unsigned      ipcq24                                    :  8;
#else    /* Little Endian */
     unsigned      ipcq24                                    :  8;
     unsigned      ipcq25                                    :  8;
     unsigned      ipcq26                                    :  8;
     unsigned      ipcq27                                    :  8;
#endif
} ncp_nca_itp_ipcq_size06_r_t;

/*! @struct ncp_nca_itp_ipcq_size07_r_t
 *  @brief null
 *  @details iPCQ size for specified compressed iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_size07_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq31 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq30 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq29 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq28 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_size07_r_t
 *
 * Implemented by: 
 *      ipcq_size07
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq31                                    :  8;
     unsigned      ipcq30                                    :  8;
     unsigned      ipcq29                                    :  8;
     unsigned      ipcq28                                    :  8;
#else    /* Little Endian */
     unsigned      ipcq28                                    :  8;
     unsigned      ipcq29                                    :  8;
     unsigned      ipcq30                                    :  8;
     unsigned      ipcq31                                    :  8;
#endif
} ncp_nca_itp_ipcq_size07_r_t;

/*! @struct ncp_nca_itp_ipcq_size08_r_t
 *  @brief null
 *  @details iPCQ size for specified compressed iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_size08_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq35 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq34 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq33 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq32 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_size08_r_t
 *
 * Implemented by: 
 *      ipcq_size08
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq35                                    :  8;
     unsigned      ipcq34                                    :  8;
     unsigned      ipcq33                                    :  8;
     unsigned      ipcq32                                    :  8;
#else    /* Little Endian */
     unsigned      ipcq32                                    :  8;
     unsigned      ipcq33                                    :  8;
     unsigned      ipcq34                                    :  8;
     unsigned      ipcq35                                    :  8;
#endif
} ncp_nca_itp_ipcq_size08_r_t;

/*! @struct ncp_nca_itp_ipcq_size09_r_t
 *  @brief null
 *  @details iPCQ size for specified compressed iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_size09_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq39 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq38 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq37 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq36 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_size09_r_t
 *
 * Implemented by: 
 *      ipcq_size09
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq39                                    :  8;
     unsigned      ipcq38                                    :  8;
     unsigned      ipcq37                                    :  8;
     unsigned      ipcq36                                    :  8;
#else    /* Little Endian */
     unsigned      ipcq36                                    :  8;
     unsigned      ipcq37                                    :  8;
     unsigned      ipcq38                                    :  8;
     unsigned      ipcq39                                    :  8;
#endif
} ncp_nca_itp_ipcq_size09_r_t;

/*! @struct ncp_nca_itp_ipcq_size10_r_t
 *  @brief null
 *  @details iPCQ size for specified compressed iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_size10_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq43 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq42 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq41 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq40 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_size10_r_t
 *
 * Implemented by: 
 *      ipcq_size10
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq43                                    :  8;
     unsigned      ipcq42                                    :  8;
     unsigned      ipcq41                                    :  8;
     unsigned      ipcq40                                    :  8;
#else    /* Little Endian */
     unsigned      ipcq40                                    :  8;
     unsigned      ipcq41                                    :  8;
     unsigned      ipcq42                                    :  8;
     unsigned      ipcq43                                    :  8;
#endif
} ncp_nca_itp_ipcq_size10_r_t;

/*! @struct ncp_nca_itp_ipcq_size11_r_t
 *  @brief null
 *  @details iPCQ size for specified compressed iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_size11_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq47 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq46 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq45 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq44 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_size11_r_t
 *
 * Implemented by: 
 *      ipcq_size11
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq47                                    :  8;
     unsigned      ipcq46                                    :  8;
     unsigned      ipcq45                                    :  8;
     unsigned      ipcq44                                    :  8;
#else    /* Little Endian */
     unsigned      ipcq44                                    :  8;
     unsigned      ipcq45                                    :  8;
     unsigned      ipcq46                                    :  8;
     unsigned      ipcq47                                    :  8;
#endif
} ncp_nca_itp_ipcq_size11_r_t;

/*! @struct ncp_nca_itp_ipcq_size12_r_t
 *  @brief null
 *  @details iPCQ size for specified compressed iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_size12_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq51 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq50 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq49 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq48 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_size12_r_t
 *
 * Implemented by: 
 *      ipcq_size12
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq51                                    :  8;
     unsigned      ipcq50                                    :  8;
     unsigned      ipcq49                                    :  8;
     unsigned      ipcq48                                    :  8;
#else    /* Little Endian */
     unsigned      ipcq48                                    :  8;
     unsigned      ipcq49                                    :  8;
     unsigned      ipcq50                                    :  8;
     unsigned      ipcq51                                    :  8;
#endif
} ncp_nca_itp_ipcq_size12_r_t;

/*! @struct ncp_nca_itp_ipcq_size13_r_t
 *  @brief null
 *  @details iPCQ size for specified compressed iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_size13_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq55 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq54 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq53 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq52 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_size13_r_t
 *
 * Implemented by: 
 *      ipcq_size13
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq55                                    :  8;
     unsigned      ipcq54                                    :  8;
     unsigned      ipcq53                                    :  8;
     unsigned      ipcq52                                    :  8;
#else    /* Little Endian */
     unsigned      ipcq52                                    :  8;
     unsigned      ipcq53                                    :  8;
     unsigned      ipcq54                                    :  8;
     unsigned      ipcq55                                    :  8;
#endif
} ncp_nca_itp_ipcq_size13_r_t;

/*! @struct ncp_nca_itp_ipcq_size14_r_t
 *  @brief null
 *  @details iPCQ size for specified compressed iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_size14_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq59 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq58 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq57 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq56 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_size14_r_t
 *
 * Implemented by: 
 *      ipcq_size14
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq59                                    :  8;
     unsigned      ipcq58                                    :  8;
     unsigned      ipcq57                                    :  8;
     unsigned      ipcq56                                    :  8;
#else    /* Little Endian */
     unsigned      ipcq56                                    :  8;
     unsigned      ipcq57                                    :  8;
     unsigned      ipcq58                                    :  8;
     unsigned      ipcq59                                    :  8;
#endif
} ncp_nca_itp_ipcq_size14_r_t;

/*! @struct ncp_nca_itp_ipcq_size15_r_t
 *  @brief null
 *  @details iPCQ size for specified compressed iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_size15_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq63 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq62 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq61 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq60 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_size15_r_t
 *
 * Implemented by: 
 *      ipcq_size15
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq63                                    :  8;
     unsigned      ipcq62                                    :  8;
     unsigned      ipcq61                                    :  8;
     unsigned      ipcq60                                    :  8;
#else    /* Little Endian */
     unsigned      ipcq60                                    :  8;
     unsigned      ipcq61                                    :  8;
     unsigned      ipcq62                                    :  8;
     unsigned      ipcq63                                    :  8;
#endif
} ncp_nca_itp_ipcq_size15_r_t;

/*! @struct ncp_nca_itp_ipcq_size16_r_t
 *  @brief null
 *  @details iPCQ size for specified compressed iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_size16_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq67 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq66 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq65 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq64 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_size16_r_t
 *
 * Implemented by: 
 *      ipcq_size16
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq67                                    :  8;
     unsigned      ipcq66                                    :  8;
     unsigned      ipcq65                                    :  8;
     unsigned      ipcq64                                    :  8;
#else    /* Little Endian */
     unsigned      ipcq64                                    :  8;
     unsigned      ipcq65                                    :  8;
     unsigned      ipcq66                                    :  8;
     unsigned      ipcq67                                    :  8;
#endif
} ncp_nca_itp_ipcq_size16_r_t;

/*! @struct ncp_nca_itp_ipcq_size17_r_t
 *  @brief null
 *  @details iPCQ size for specified compressed iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_size17_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq71 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq70 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq69 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq68 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_size17_r_t
 *
 * Implemented by: 
 *      ipcq_size17
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq71                                    :  8;
     unsigned      ipcq70                                    :  8;
     unsigned      ipcq69                                    :  8;
     unsigned      ipcq68                                    :  8;
#else    /* Little Endian */
     unsigned      ipcq68                                    :  8;
     unsigned      ipcq69                                    :  8;
     unsigned      ipcq70                                    :  8;
     unsigned      ipcq71                                    :  8;
#endif
} ncp_nca_itp_ipcq_size17_r_t;

/*! @struct ncp_nca_itp_ipcq_size18_r_t
 *  @brief null
 *  @details iPCQ size for specified compressed iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_size18_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq75 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq74 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq73 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq72 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_size18_r_t
 *
 * Implemented by: 
 *      ipcq_size18
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq75                                    :  8;
     unsigned      ipcq74                                    :  8;
     unsigned      ipcq73                                    :  8;
     unsigned      ipcq72                                    :  8;
#else    /* Little Endian */
     unsigned      ipcq72                                    :  8;
     unsigned      ipcq73                                    :  8;
     unsigned      ipcq74                                    :  8;
     unsigned      ipcq75                                    :  8;
#endif
} ncp_nca_itp_ipcq_size18_r_t;

/*! @struct ncp_nca_itp_ipcq_size19_r_t
 *  @brief null
 *  @details iPCQ size for specified compressed iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_size19_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq79 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq78 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq77 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq76 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_size19_r_t
 *
 * Implemented by: 
 *      ipcq_size19
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq79                                    :  8;
     unsigned      ipcq78                                    :  8;
     unsigned      ipcq77                                    :  8;
     unsigned      ipcq76                                    :  8;
#else    /* Little Endian */
     unsigned      ipcq76                                    :  8;
     unsigned      ipcq77                                    :  8;
     unsigned      ipcq78                                    :  8;
     unsigned      ipcq79                                    :  8;
#endif
} ncp_nca_itp_ipcq_size19_r_t;

/*! @struct ncp_nca_itp_ipcq_size20_r_t
 *  @brief null
 *  @details iPCQ size for specified compressed iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_size20_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq83 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq82 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq81 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq80 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_size20_r_t
 *
 * Implemented by: 
 *      ipcq_size20
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq83                                    :  8;
     unsigned      ipcq82                                    :  8;
     unsigned      ipcq81                                    :  8;
     unsigned      ipcq80                                    :  8;
#else    /* Little Endian */
     unsigned      ipcq80                                    :  8;
     unsigned      ipcq81                                    :  8;
     unsigned      ipcq82                                    :  8;
     unsigned      ipcq83                                    :  8;
#endif
} ncp_nca_itp_ipcq_size20_r_t;

/*! @struct ncp_nca_itp_ipcq_size21_r_t
 *  @brief null
 *  @details iPCQ size for specified compressed iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_size21_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq85 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq84 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> size of iPCQ. increment when task is scheudled to
 *        iPCQ and decrement when task completion is received
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_size21_r_t
 *
 * Implemented by: 
 *      ipcq_size21
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      ipcq85                                    :  8;
     unsigned      ipcq84                                    :  8;
#else    /* Little Endian */
     unsigned      ipcq84                                    :  8;
     unsigned      ipcq85                                    :  8;
     unsigned      reserved0                                 : 16;
#endif
} ncp_nca_itp_ipcq_size21_r_t;

/*! @struct ncp_nca_itp_counter_counter_copy_header_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count tasks copied due to no space for task header
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_copy_header_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_copy_header </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count tasks copied due to no space for task header </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_copy_header_r_t
 *
 * Implemented by: 
 *      counter_counter_copy_header
 */
 
typedef struct
{
     unsigned  int      cnt_counter_copy_header;
} ncp_nca_itp_counter_counter_copy_header_r_t;

/*! @struct ncp_nca_itp_counter_counter_copy_B32A_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count tasks copied due to B32 align requirement
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_copy_B32A_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_copy_b32a </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count tasks copied due to B32 align requirement </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_copy_B32A_r_t
 *
 * Implemented by: 
 *      counter_counter_copy_B32A
 */
 
typedef struct
{
     unsigned  int      cnt_counter_copy_b32a;
} ncp_nca_itp_counter_counter_copy_B32A_r_t;

/*! @struct ncp_nca_itp_counter_counter_copy_format1_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count tasks copied due to FORMAT01, or modifible requirement
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_copy_format1_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_copy_format1 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count tasks copied due to FORMAT01, or modifible requirement </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_copy_format1_r_t
 *
 * Implemented by: 
 *      counter_counter_copy_format1
 */
 
typedef struct
{
     unsigned  int      cnt_counter_copy_format1;
} ncp_nca_itp_counter_counter_copy_format1_r_t;

/*! @struct ncp_nca_itp_counter_counter_copy_format2_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count tasks copied due to FORMAT02, or continuous requirement
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_copy_format2_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_copy_format2 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count tasks copied due to FORMAT02, or continuous
 *        requirement
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_copy_format2_r_t
 *
 * Implemented by: 
 *      counter_counter_copy_format2
 */
 
typedef struct
{
     unsigned  int      cnt_counter_copy_format2;
} ncp_nca_itp_counter_counter_copy_format2_r_t;

/*! @struct ncp_nca_itp_counter_counter_copy_format3_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count tasks copied due to FORMAT03 or B32 padd, or seperation requirement
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_copy_format3_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_copy_format3 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count tasks copied due to FORMAT03 or B32 padd, or
 *        seperation requirement
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_copy_format3_r_t
 *
 * Implemented by: 
 *      counter_counter_copy_format3
 */
 
typedef struct
{
     unsigned  int      cnt_counter_copy_format3;
} ncp_nca_itp_counter_counter_copy_format3_r_t;

/*! @struct ncp_nca_itp_counter_counter_copy_format4_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count tasks copied due to FORMAT04, or restricted pool requirement
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_copy_format4_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_copy_format4 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count tasks copied due to FORMAT04, or restricted
 *        pool requirement
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_copy_format4_r_t
 *
 * Implemented by: 
 *      counter_counter_copy_format4
 */
 
typedef struct
{
     unsigned  int      cnt_counter_copy_format4;
} ncp_nca_itp_counter_counter_copy_format4_r_t;

/*! @struct ncp_nca_itp_counter_counter_starttask_drop_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count tasks dropped due to task error, format violation, or nack recieved on header seperate or data copy allocate request
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_starttask_drop_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_starttask_drop </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count tasks dropped due to task error, format violation,
 *        or nack recieved on header seperate or data copy allocate
 *        request
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_starttask_drop_r_t
 *
 * Implemented by: 
 *      counter_counter_starttask_drop
 */
 
typedef struct
{
     unsigned  int      cnt_counter_starttask_drop;
} ncp_nca_itp_counter_counter_starttask_drop_r_t;

/*! @struct ncp_nca_itp_counter_counter_copy_format5_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count tasks copied due to FORMAT05, or forced copy
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_copy_format5_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_copy_format5 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count tasks copied due to FORMAT05, or forced copy </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_copy_format5_r_t
 *
 * Implemented by: 
 *      counter_counter_copy_format5
 */
 
typedef struct
{
     unsigned  int      cnt_counter_copy_format5;
} ncp_nca_itp_counter_counter_copy_format5_r_t;

/*! @struct ncp_nca_itp_counter_counter_TILbp_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK. Increment when the TIL TID delete or TRAM interface issues bp.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_TILbp_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_tilbp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK COW TIL bp </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_TILbp_r_t
 *
 * Implemented by: 
 *      counter_counter_TILbp
 */
 
typedef struct
{
     unsigned  int         cnt_counter_tilbp;
} ncp_nca_itp_counter_counter_TILbp_r_t;

/*! @struct ncp_nca_itp_counter_counter_TCRIbp_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK. Increment when the COW TIL TCRI backpressures the ITP copy logic.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_TCRIbp_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_tcribp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK COW TCRI bp </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_TCRIbp_r_t
 *
 * Implemented by: 
 *      counter_counter_TCRIbp
 */
 
typedef struct
{
     unsigned  int        cnt_counter_tcribp;
} ncp_nca_itp_counter_counter_TCRIbp_r_t;

/*! @struct ncp_nca_itp_counter_counter_inputfifo_afull_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK. Increment when the ITP input FIFO is afull. THe input FIFO stores the reconstructred input task from COW.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_inputfifo_afull_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_inputfifo_afull </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK input fifo full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_inputfifo_afull_r_t
 *
 * Implemented by: 
 *      counter_counter_inputfifo_afull
 */
 
typedef struct
{
     unsigned  int      cnt_counter_inputfifo_afull;
} ncp_nca_itp_counter_counter_inputfifo_afull_r_t;

/*! @struct ncp_nca_itp_counter_counter_cam_ieordered_AVAL_V_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK. Increment when the ordered task BCAM is full.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_cam_ieordered_AVAL_V_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_cam_ieordered_aval_v </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK CAM full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_cam_ieordered_AVAL_V_r_t
 *
 * Implemented by: 
 *      counter_counter_cam_ieordered_AVAL_V
 */
 
typedef struct
{
     unsigned  int      cnt_counter_cam_ieordered_aval_v;
} ncp_nca_itp_counter_counter_cam_ieordered_AVAL_V_r_t;

/*! @struct ncp_nca_itp_counter_counter_ll_ieord_full_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK. Increment when the ordered task LL is full.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_ll_ieord_full_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_ll_ieord_full </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK ordered task LL full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_ll_ieord_full_r_t
 *
 * Implemented by: 
 *      counter_counter_ll_ieord_full
 */
 
typedef struct
{
     unsigned  int      cnt_counter_ll_ieord_full;
} ncp_nca_itp_counter_counter_ll_ieord_full_r_t;

/*! @struct ncp_nca_itp_counter_counter_ll_ieunord_full_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK. Increment when the unordered task LL is full.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_ll_ieunord_full_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_ll_ieunord_full </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK unordered task LL full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_ll_ieunord_full_r_t
 *
 * Implemented by: 
 *      counter_counter_ll_ieunord_full
 */
 
typedef struct
{
     unsigned  int      cnt_counter_ll_ieunord_full;
} ncp_nca_itp_counter_counter_ll_ieunord_full_r_t;

/*! @struct ncp_nca_itp_counter_counter_ll_preproc_full_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK. Increment when the task preprocessing LL is full.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_ll_preproc_full_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_ll_preproc_full </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK preprocessing LL full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_ll_preproc_full_r_t
 *
 * Implemented by: 
 *      counter_counter_ll_preproc_full
 */
 
typedef struct
{
     unsigned  int      cnt_counter_ll_preproc_full;
} ncp_nca_itp_counter_counter_ll_preproc_full_r_t;

/*! @struct ncp_nca_itp_counter_counter_ll_completion_full_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count BOTTLENECK. Increment when the task completion LL is full.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_ll_completion_full_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_ll_completion_full </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK complettion LL full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_ll_completion_full_r_t
 *
 * Implemented by: 
 *      counter_counter_ll_completion_full
 */
 
typedef struct
{
     unsigned  int      cnt_counter_ll_completion_full;
} ncp_nca_itp_counter_counter_ll_completion_full_r_t;

/*! @struct ncp_nca_itp_counter_counter_tqbp_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count BOTTLENECK. Increment when ITP backpressures TIL start task.nterface
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_tqbp_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_tqbp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK TQ BP caused by enqueued tasks from
 *        TQ greater than threshold
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_tqbp_r_t
 *
 * Implemented by: 
 *      counter_counter_tqbp
 */
 
typedef struct
{
     unsigned  int          cnt_counter_tqbp;
} ncp_nca_itp_counter_counter_tqbp_r_t;

/*! @struct ncp_nca_itp_counter_counter_ipcqfull_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count BOTTLENECK. Increment when ANY iPCQ is detected as full. (iPCQ_size. increment when send iPCQ task entry to NCAP, decrement when consumer pointer advance is returned. Compare iPCQ_size value with IPD.threshold to determine when full)
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_ipcqfull_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_ipcqfull </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK any iPCQ full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_ipcqfull_r_t
 *
 * Implemented by: 
 *      counter_counter_ipcqfull
 */
 
typedef struct
{
     unsigned  int      cnt_counter_ipcqfull;
} ncp_nca_itp_counter_counter_ipcqfull_r_t;

/*! @struct ncp_nca_itp_counter_counter_multifull_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count BOTTLENECK. Increment when ouptut multiFIFO servicing all NCAP has any FIFO full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_multifull_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_multifull </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK ouptut multiFIFO servicing all NCAP
 *        has any FIFO full
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_multifull_r_t
 *
 * Implemented by: 
 *      counter_counter_multifull
 */
 
typedef struct
{
     unsigned  int      cnt_counter_multifull;
} ncp_nca_itp_counter_counter_multifull_r_t;

/*! @struct ncp_nca_itp_counter_counter_nlinkready_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count BOTTLENECK. Increment when iPCQ NLINK write reqeust ready drops (this count unconditionally, may not have a task to send)
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_nlinkready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_nlinkready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK iPCQ req NLINK ready is low </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_nlinkready_r_t
 *
 * Implemented by: 
 *      counter_counter_nlinkready
 */
 
typedef struct
{
     unsigned  int      cnt_counter_nlinkready;
} ncp_nca_itp_counter_counter_nlinkready_r_t;

/*! @struct ncp_nca_itp_counter_counter_credits_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count BOTTLENECK. Increment when any NCAP credit is exhausted
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_credits_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_credits </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK any NCAP credit is exhausted </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_credits_r_t
 *
 * Implemented by: 
 *      counter_counter_credits
 */
 
typedef struct
{
     unsigned  int       cnt_counter_credits;
} ncp_nca_itp_counter_counter_credits_r_t;

/*! @struct ncp_nca_itp_counter_counter_itp_otp_dealloc_bp_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count BOTTLENECK. Increment when OTP issues backpressure on the deallocate pointer interface. (May not be issuing command)
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_itp_otp_dealloc_bp_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_itp_otp_dealloc_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK OTP backpressures deallocate </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_itp_otp_dealloc_bp_r_t
 *
 * Implemented by: 
 *      counter_counter_itp_otp_dealloc_bp
 */
 
typedef struct
{
     unsigned  int      cnt_counter_itp_otp_dealloc_bp;
} ncp_nca_itp_counter_counter_itp_otp_dealloc_bp_r_t;

/*! @struct ncp_nca_itp_counter_counter_mmbr_eng_bp_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count BOTTLENECK. Increment when MCIP issues backpressure on the deallocate pointer interface. (May not be issuing command)
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_mmbr_eng_bp_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_mmbr_eng_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK MCIP backpressure deallocate </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_mmbr_eng_bp_r_t
 *
 * Implemented by: 
 *      counter_counter_mmbr_eng_bp
 */
 
typedef struct
{
     unsigned  int      cnt_counter_mmbr_eng_bp;
} ncp_nca_itp_counter_counter_mmbr_eng_bp_r_t;

/*! @struct ncp_nca_itp_counter_counter_itp_mtp_req_core_arready_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count BOTTLENECK. Increment when MTP backpressure allocate pointer interface by dropping ready. (May not be issuing command)
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_itp_mtp_req_core_arready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_itp_mtp_req_core_arready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK MTP backpressure allocate </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_itp_mtp_req_core_arready_r_t
 *
 * Implemented by: 
 *      counter_counter_itp_mtp_req_core_arready
 */
 
typedef struct
{
     unsigned  int      cnt_counter_itp_mtp_req_core_arready;
} ncp_nca_itp_counter_counter_itp_mtp_req_core_arready_r_t;

/*! @struct ncp_nca_itp_counter_counter_itp_mtp_tx_core_awready_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count BOTTLENECK. Increment when MTP backpressure MQG command interface by dropping ready. (May not be issuing command)
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_itp_mtp_tx_core_awready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_itp_mtp_tx_core_awready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK MTP backpressure MQG commands </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_itp_mtp_tx_core_awready_r_t
 *
 * Implemented by: 
 *      counter_counter_itp_mtp_tx_core_awready
 */
 
typedef struct
{
     unsigned  int      cnt_counter_itp_mtp_tx_core_awready;
} ncp_nca_itp_counter_counter_itp_mtp_tx_core_awready_r_t;

/*! @struct ncp_nca_itp_counter_counter_qpm_core_awready_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count BOTTLENECK. Increment when QPM backpressure unscheudled task interface by dropping ready. (May not be issuing command)
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_qpm_core_awready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_qpm_core_awready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK QPM backpressure </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_qpm_core_awready_r_t
 *
 * Implemented by: 
 *      counter_counter_qpm_core_awready
 */
 
typedef struct
{
     unsigned  int      cnt_counter_qpm_core_awready;
} ncp_nca_itp_counter_counter_qpm_core_awready_r_t;

/*! @struct ncp_nca_itp_counter_counter_trace_data_core_awready_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count BOTTLENECK. Increment when TRACE backpressure the write interface by dropping ready. (May not be issuing command)
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_trace_data_core_awready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_trace_data_core_awready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK TRACE backpressure </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_trace_data_core_awready_r_t
 *
 * Implemented by: 
 *      counter_counter_trace_data_core_awready
 */
 
typedef struct
{
     unsigned  int      cnt_counter_trace_data_core_awready;
} ncp_nca_itp_counter_counter_trace_data_core_awready_r_t;

/*! @struct ncp_nca_itp_counter_counter_activitycounter_writeack0_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count BOTTLENECK writeack for header write is at threshold
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_activitycounter_writeack0_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_activitycounter_writeack0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK writeack for header write is at threshold </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_activitycounter_writeack0_r_t
 *
 * Implemented by: 
 *      counter_counter_activitycounter_writeack0
 */
 
typedef struct
{
     unsigned  int      cnt_counter_activitycounter_writeack0;
} ncp_nca_itp_counter_counter_activitycounter_writeack0_r_t;

/*! @struct ncp_nca_itp_counter_counter_activitycounter_writeack1_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count BOTTLENECK writeack for data copy write is at threshold
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_activitycounter_writeack1_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_activitycounter_writeack1 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK writeack for data copy write is at
 *        threshold
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_activitycounter_writeack1_r_t
 *
 * Implemented by: 
 *      counter_counter_activitycounter_writeack1
 */
 
typedef struct
{
     unsigned  int      cnt_counter_activitycounter_writeack1;
} ncp_nca_itp_counter_counter_activitycounter_writeack1_r_t;

/*! @struct ncp_nca_itp_counter_counter_activitycounter_mtp_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count BOTTLENECK data copy pointer prefetch is at threshold
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_activitycounter_mtp_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_activitycounter_mtp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK data copy pointer prefetch is at
 *        threshold
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_activitycounter_mtp_r_t
 *
 * Implemented by: 
 *      counter_counter_activitycounter_mtp
 */
 
typedef struct
{
     unsigned  int      cnt_counter_activitycounter_mtp;
} ncp_nca_itp_counter_counter_activitycounter_mtp_r_t;

/*! @struct ncp_nca_itp_counter_counter_tilstart_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count TIL start tasks
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_tilstart_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_tilstart </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count TIL start tasks </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_tilstart_r_t
 *
 * Implemented by: 
 *      counter_counter_tilstart
 */
 
typedef struct
{
     unsigned  int      cnt_counter_tilstart;
} ncp_nca_itp_counter_counter_tilstart_r_t;

/*! @struct ncp_nca_itp_counter_counter_pp_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count tasks complete preprocessing
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_pp_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_pp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count tasks complete preprocessing </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_pp_r_t
 *
 * Implemented by: 
 *      counter_counter_pp
 */
 
typedef struct
{
     unsigned  int            cnt_counter_pp;
} ncp_nca_itp_counter_counter_pp_r_t;

/*! @struct ncp_nca_itp_counter_counter_pp_ptrcnt0_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count tasks complete preprocessing with no pointers
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_pp_ptrcnt0_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_pp_ptrcnt0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count tasks complete preprocessing with no pointers </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_pp_ptrcnt0_r_t
 *
 * Implemented by: 
 *      counter_counter_pp_ptrcnt0
 */
 
typedef struct
{
     unsigned  int      cnt_counter_pp_ptrcnt0;
} ncp_nca_itp_counter_counter_pp_ptrcnt0_r_t;

/*! @struct ncp_nca_itp_counter_counter_pp_copy_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count task complete preprocessing that were copied
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_pp_copy_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_pp_copy </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count task complete preprocessing that were copied </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_pp_copy_r_t
 *
 * Implemented by: 
 *      counter_counter_pp_copy
 */
 
typedef struct
{
     unsigned  int       cnt_counter_pp_copy;
} ncp_nca_itp_counter_counter_pp_copy_r_t;

/*! @struct ncp_nca_itp_counter_counter_pp_hs_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count complete preprocessing that had Header Sperate FORMAT00 enabled
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_pp_hs_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_pp_hs </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count complete preprocessing that had Header Sperate
 *        FORMAT00 enabled
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_pp_hs_r_t
 *
 * Implemented by: 
 *      counter_counter_pp_hs
 */
 
typedef struct
{
     unsigned  int         cnt_counter_pp_hs;
} ncp_nca_itp_counter_counter_pp_hs_r_t;

/*! @struct ncp_nca_itp_counter_counter_pp_err_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count complete preprocessing that were dtected as an error
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_pp_err_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_pp_err </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count complete preprocessing that were dtected as
 *        an error
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_pp_err_r_t
 *
 * Implemented by: 
 *      counter_counter_pp_err
 */
 
typedef struct
{
     unsigned  int        cnt_counter_pp_err;
} ncp_nca_itp_counter_counter_pp_err_r_t;

/*! @struct ncp_nca_itp_counter_counter_enqueue_camhit_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count ordered task CAM hit
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_enqueue_camhit_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_enqueue_camhit </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered task CAM hit </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_enqueue_camhit_r_t
 *
 * Implemented by: 
 *      counter_counter_enqueue_camhit
 */
 
typedef struct
{
     unsigned  int      cnt_counter_enqueue_camhit;
} ncp_nca_itp_counter_counter_enqueue_camhit_r_t;

/*! @struct ncp_nca_itp_counter_counter_enqueue_cammiss_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count ordered task CAM miss
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_enqueue_cammiss_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_enqueue_cammiss </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered task CAM miss </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_enqueue_cammiss_r_t
 *
 * Implemented by: 
 *      counter_counter_enqueue_cammiss
 */
 
typedef struct
{
     unsigned  int      cnt_counter_enqueue_cammiss;
} ncp_nca_itp_counter_counter_enqueue_cammiss_r_t;

/*! @struct ncp_nca_itp_counter_counter_enqueue_ordered_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count ordered task enqueued
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_enqueue_ordered_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_enqueue_ordered </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered task enqueued </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_enqueue_ordered_r_t
 *
 * Implemented by: 
 *      counter_counter_enqueue_ordered
 */
 
typedef struct
{
     unsigned  int      cnt_counter_enqueue_ordered;
} ncp_nca_itp_counter_counter_enqueue_ordered_r_t;

/*! @struct ncp_nca_itp_counter_counter_enqueue_unorder_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count unordered task enqueued
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_enqueue_unorder_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_enqueue_unorder </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count unordered task enqueued </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_enqueue_unorder_r_t
 *
 * Implemented by: 
 *      counter_counter_enqueue_unorder
 */
 
typedef struct
{
     unsigned  int      cnt_counter_enqueue_unorder;
} ncp_nca_itp_counter_counter_enqueue_unorder_r_t;

/*! @struct ncp_nca_itp_counter_counter_enqueue_unsched_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count unscheduled task enqueued
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_enqueue_unsched_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_enqueue_unsched </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count unscheduled task enqueued </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_enqueue_unsched_r_t
 *
 * Implemented by: 
 *      counter_counter_enqueue_unsched
 */
 
typedef struct
{
     unsigned  int      cnt_counter_enqueue_unsched;
} ncp_nca_itp_counter_counter_enqueue_unsched_r_t;

/*! @struct ncp_nca_itp_counter_counter_enqueue_unsched_ack_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count unscheduled exception ack task enqueued
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_enqueue_unsched_ack_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_enqueue_unsched_ack </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count unscheduled exception ack task enqueued </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_enqueue_unsched_ack_r_t
 *
 * Implemented by: 
 *      counter_counter_enqueue_unsched_ack
 */
 
typedef struct
{
     unsigned  int      cnt_counter_enqueue_unsched_ack;
} ncp_nca_itp_counter_counter_enqueue_unsched_ack_r_t;

/*! @struct ncp_nca_itp_counter_counter_sched_orderedsched_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count ordered task in scheduled state scheduled
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_sched_orderedsched_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_sched_orderedsched </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered task in scheduled state scheduled </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_sched_orderedsched_r_t
 *
 * Implemented by: 
 *      counter_counter_sched_orderedsched
 */
 
typedef struct
{
     unsigned  int      cnt_counter_sched_orderedsched;
} ncp_nca_itp_counter_counter_sched_orderedsched_r_t;

/*! @struct ncp_nca_itp_counter_counter_sched_orderedready_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count ordered task in ready state scheduled
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_sched_orderedready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_sched_orderedready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered task in ready state scheduled </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_sched_orderedready_r_t
 *
 * Implemented by: 
 *      counter_counter_sched_orderedready
 */
 
typedef struct
{
     unsigned  int      cnt_counter_sched_orderedready;
} ncp_nca_itp_counter_counter_sched_orderedready_r_t;

/*! @struct ncp_nca_itp_counter_counter_sched_unorder_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count unordered task scheduled
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_sched_unorder_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_sched_unorder </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count unordered task scheduled </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_sched_unorder_r_t
 *
 * Implemented by: 
 *      counter_counter_sched_unorder
 */
 
typedef struct
{
     unsigned  int      cnt_counter_sched_unorder;
} ncp_nca_itp_counter_counter_sched_unorder_r_t;

/*! @struct ncp_nca_itp_counter_counter_nlinkreq_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count NLINK tasks delivered
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_nlinkreq_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_nlinkreq </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count NLINK tasks delivered </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_nlinkreq_r_t
 *
 * Implemented by: 
 *      counter_counter_nlinkreq
 */
 
typedef struct
{
     unsigned  int      cnt_counter_nlinkreq;
} ncp_nca_itp_counter_counter_nlinkreq_r_t;

/*! @struct ncp_nca_itp_counter_counter_complete_ordered_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count ordered task completions received
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_complete_ordered_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_complete_ordered </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered task completions received </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_complete_ordered_r_t
 *
 * Implemented by: 
 *      counter_counter_complete_ordered
 */
 
typedef struct
{
     unsigned  int      cnt_counter_complete_ordered;
} ncp_nca_itp_counter_counter_complete_ordered_r_t;

/*! @struct ncp_nca_itp_counter_counter_complete_unorder_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count unordered task completions received
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_complete_unorder_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_complete_unorder </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count unordered task completions received </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_complete_unorder_r_t
 *
 * Implemented by: 
 *      counter_counter_complete_unorder
 */
 
typedef struct
{
     unsigned  int      cnt_counter_complete_unorder;
} ncp_nca_itp_counter_counter_complete_unorder_r_t;

/*! @struct ncp_nca_itp_counter_counter_pointeralloc_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count number of pointers allocated by ITP
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_pointeralloc_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_pointeralloc </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count number of pointers allocated by ITP </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_pointeralloc_r_t
 *
 * Implemented by: 
 *      counter_counter_pointeralloc
 */
 
typedef struct
{
     unsigned  int      cnt_counter_pointeralloc;
} ncp_nca_itp_counter_counter_pointeralloc_r_t;

/*! @struct ncp_nca_itp_counter_counter_pointerdealloc0_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count number of pointers deallcoated by ITP
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_pointerdealloc0_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_pointerdealloc0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count number of pointers deallcoated by ITP </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_pointerdealloc0_r_t
 *
 * Implemented by: 
 *      counter_counter_pointerdealloc0
 */
 
typedef struct
{
     unsigned  int      cnt_counter_pointerdealloc0;
} ncp_nca_itp_counter_counter_pointerdealloc0_r_t;

/*! @struct ncp_nca_itp_counter_counter_pointerdealloc1_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count number of pointers deallcoated by ITP
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_pointerdealloc1_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_pointerdealloc1 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count number of pointers deallcoated by ITP </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_pointerdealloc1_r_t
 *
 * Implemented by: 
 *      counter_counter_pointerdealloc1
 */
 
typedef struct
{
     unsigned  int      cnt_counter_pointerdealloc1;
} ncp_nca_itp_counter_counter_pointerdealloc1_r_t;

/*! @struct ncp_nca_itp_counter_counter_pointertask_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count number of pointers sent to ITP in VPP task
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_pointertask_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_pointertask </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count number of pointers sent to ITP in VPP task </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_pointertask_r_t
 *
 * Implemented by: 
 *      counter_counter_pointertask
 */
 
typedef struct
{
     unsigned  int      cnt_counter_pointertask;
} ncp_nca_itp_counter_counter_pointertask_r_t;

/*! @struct ncp_nca_itp_counter_counter_mqg_inc_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count number of pointers delivered by ITP to iPCQ task
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_mqg_inc_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_mqg_inc </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count number of pointers delivered by ITP to iPCQ
 *        task
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_mqg_inc_r_t
 *
 * Implemented by: 
 *      counter_counter_mqg_inc
 */
 
typedef struct
{
     unsigned  int       cnt_counter_mqg_inc;
} ncp_nca_itp_counter_counter_mqg_inc_r_t;

/*! @struct ncp_nca_itp_counter_counter_pointernack_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count number of allocate NACKs received
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_pointernack_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_pointernack </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count number of allocate NACKs received </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_pointernack_r_t
 *
 * Implemented by: 
 *      counter_counter_pointernack
 */
 
typedef struct
{
     unsigned  int      cnt_counter_pointernack;
} ncp_nca_itp_counter_counter_pointernack_r_t;

/*! @struct ncp_nca_itp_counter_counter_statetrans_00_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count ordered state transition: Enqueue SM Ready -> Ready
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_statetrans_00_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_statetrans_00 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered state transition: Enqueue SM Ready ->
 *        Ready
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_statetrans_00_r_t
 *
 * Implemented by: 
 *      counter_counter_statetrans_00
 */
 
typedef struct
{
     unsigned  int      cnt_counter_statetrans_00;
} ncp_nca_itp_counter_counter_statetrans_00_r_t;

/*! @struct ncp_nca_itp_counter_counter_statetrans_01_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count ordered state transition: Enqueue SM, Scheduled -> Scheduled
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_statetrans_01_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_statetrans_01 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered state transition: Enqueue SM, Scheduled
 *        -> Scheduled
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_statetrans_01_r_t
 *
 * Implemented by: 
 *      counter_counter_statetrans_01
 */
 
typedef struct
{
     unsigned  int      cnt_counter_statetrans_01;
} ncp_nca_itp_counter_counter_statetrans_01_r_t;

/*! @struct ncp_nca_itp_counter_counter_statetrans_02_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count ordered state transition: Enqueue SM, IDLE/ScheduledIdle -> Scheduled
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_statetrans_02_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_statetrans_02 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered state transition: Enqueue SM, IDLE/ScheduledIdle
 *        -> Scheduled
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_statetrans_02_r_t
 *
 * Implemented by: 
 *      counter_counter_statetrans_02
 */
 
typedef struct
{
     unsigned  int      cnt_counter_statetrans_02;
} ncp_nca_itp_counter_counter_statetrans_02_r_t;

/*! @struct ncp_nca_itp_counter_counter_statetrans_03_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count ordered state transition: Enqueue SM, IDLE -> Ready
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_statetrans_03_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_statetrans_03 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered state transition: Enqueue SM, IDLE ->
 *        Ready
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_statetrans_03_r_t
 *
 * Implemented by: 
 *      counter_counter_statetrans_03
 */
 
typedef struct
{
     unsigned  int      cnt_counter_statetrans_03;
} ncp_nca_itp_counter_counter_statetrans_03_r_t;

/*! @struct ncp_nca_itp_counter_counter_statetrans_04_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count ordered state transition: Schedule1 SM, Ready -> Scheduled
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_statetrans_04_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_statetrans_04 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered state transition: Schedule1 SM, Ready
 *        -> Scheduled
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_statetrans_04_r_t
 *
 * Implemented by: 
 *      counter_counter_statetrans_04
 */
 
typedef struct
{
     unsigned  int      cnt_counter_statetrans_04;
} ncp_nca_itp_counter_counter_statetrans_04_r_t;

/*! @struct ncp_nca_itp_counter_counter_statetrans_05_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count ordered state transition: Schedule1 SM, Ready -> ScheduledIdle
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_statetrans_05_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_statetrans_05 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered state transition: Schedule1 SM, Ready
 *        -> ScheduledIdle
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_statetrans_05_r_t
 *
 * Implemented by: 
 *      counter_counter_statetrans_05
 */
 
typedef struct
{
     unsigned  int      cnt_counter_statetrans_05;
} ncp_nca_itp_counter_counter_statetrans_05_r_t;

/*! @struct ncp_nca_itp_counter_counter_statetrans_06_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count ordered state transition: Completion SM, Scheduled -> Scheduled
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_statetrans_06_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_statetrans_06 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered state transition: Completion SM, Scheduled
 *        -> Scheduled
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_statetrans_06_r_t
 *
 * Implemented by: 
 *      counter_counter_statetrans_06
 */
 
typedef struct
{
     unsigned  int      cnt_counter_statetrans_06;
} ncp_nca_itp_counter_counter_statetrans_06_r_t;

/*! @struct ncp_nca_itp_counter_counter_statetrans_07_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count ordered state transition: Completion SM, Scheduled -> Ready
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_statetrans_07_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_statetrans_07 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered state transition: Completion SM, Scheduled
 *        -> Ready
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_statetrans_07_r_t
 *
 * Implemented by: 
 *      counter_counter_statetrans_07
 */
 
typedef struct
{
     unsigned  int      cnt_counter_statetrans_07;
} ncp_nca_itp_counter_counter_statetrans_07_r_t;

/*! @struct ncp_nca_itp_counter_counter_statetrans_08_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count ordered state transition: Completion SM, Scheudled -> IDLE
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_counter_counter_statetrans_08_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_statetrans_08 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered state transition: Completion SM, Scheudled
 *        -> IDLE
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_counter_counter_statetrans_08_r_t
 *
 * Implemented by: 
 *      counter_counter_statetrans_08
 */
 
typedef struct
{
     unsigned  int      cnt_counter_statetrans_08;
} ncp_nca_itp_counter_counter_statetrans_08_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_copy_header_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count tasks copied due to no space for task header
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_copy_header_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_copy_header </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count tasks copied due to no space for task header </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_copy_header_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_copy_header
 */
 
typedef struct
{
     unsigned  int      cnt_counter_copy_header;
} ncp_nca_itp_cor_counter_counter_copy_header_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_copy_B32A_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count tasks copied due to B32 align requirement
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_copy_B32A_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_copy_b32a </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count tasks copied due to B32 align requirement </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_copy_B32A_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_copy_B32A
 */
 
typedef struct
{
     unsigned  int      cnt_counter_copy_b32a;
} ncp_nca_itp_cor_counter_counter_copy_B32A_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_copy_format1_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count tasks copied due to FORMAT01, or modifible requirement
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_copy_format1_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_copy_format1 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count tasks copied due to FORMAT01, or modifible requirement </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_copy_format1_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_copy_format1
 */
 
typedef struct
{
     unsigned  int      cnt_counter_copy_format1;
} ncp_nca_itp_cor_counter_counter_copy_format1_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_copy_format2_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count tasks copied due to FORMAT02, or continuous requirement
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_copy_format2_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_copy_format2 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count tasks copied due to FORMAT02, or continuous
 *        requirement
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_copy_format2_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_copy_format2
 */
 
typedef struct
{
     unsigned  int      cnt_counter_copy_format2;
} ncp_nca_itp_cor_counter_counter_copy_format2_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_copy_format3_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count tasks copied due to FORMAT03 or B32 padd, or seperation requirement
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_copy_format3_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_copy_format3 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count tasks copied due to FORMAT03 or B32 padd, or
 *        seperation requirement
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_copy_format3_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_copy_format3
 */
 
typedef struct
{
     unsigned  int      cnt_counter_copy_format3;
} ncp_nca_itp_cor_counter_counter_copy_format3_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_copy_format4_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count tasks copied due to FORMAT04, or restricted pool requirement
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_copy_format4_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_copy_format4 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count tasks copied due to FORMAT04, or restricted
 *        pool requirement
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_copy_format4_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_copy_format4
 */
 
typedef struct
{
     unsigned  int      cnt_counter_copy_format4;
} ncp_nca_itp_cor_counter_counter_copy_format4_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_starttask_drop_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count tasks dropped due to task error, format violation, or nack recieved on header seperate or data copy allocate request
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_starttask_drop_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_starttask_drop </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count tasks dropped due to task error, format violation,
 *        or nack recieved on header seperate or data copy allocate
 *        request
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_starttask_drop_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_starttask_drop
 */
 
typedef struct
{
     unsigned  int      cnt_counter_starttask_drop;
} ncp_nca_itp_cor_counter_counter_starttask_drop_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_copy_format5_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count tasks copied due to FORMAT05, or forced copy
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_copy_format5_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_copy_format5 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count tasks copied due to FORMAT05, or forced copy </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_copy_format5_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_copy_format5
 */
 
typedef struct
{
     unsigned  int      cnt_counter_copy_format5;
} ncp_nca_itp_cor_counter_counter_copy_format5_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_TILbp_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count BOTTLENECK COW TIL bp
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_TILbp_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_tilbp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK COW TIL bp </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_TILbp_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_TILbp
 */
 
typedef struct
{
     unsigned  int         cnt_counter_tilbp;
} ncp_nca_itp_cor_counter_counter_TILbp_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_TCRIbp_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count BOTTLENECK COW TCRI bp
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_TCRIbp_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_tcribp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK COW TCRI bp </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_TCRIbp_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_TCRIbp
 */
 
typedef struct
{
     unsigned  int        cnt_counter_tcribp;
} ncp_nca_itp_cor_counter_counter_TCRIbp_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_inputfifo_afull_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count BOTTLENECK input fifo full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_inputfifo_afull_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_inputfifo_afull </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK input fifo full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_inputfifo_afull_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_inputfifo_afull
 */
 
typedef struct
{
     unsigned  int      cnt_counter_inputfifo_afull;
} ncp_nca_itp_cor_counter_counter_inputfifo_afull_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_cam_ieordered_AVAL_V_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count BOTTLENECK CAM full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_cam_ieordered_AVAL_V_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_cam_ieordered_aval_v </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK CAM full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_cam_ieordered_AVAL_V_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_cam_ieordered_AVAL_V
 */
 
typedef struct
{
     unsigned  int      cnt_counter_cam_ieordered_aval_v;
} ncp_nca_itp_cor_counter_counter_cam_ieordered_AVAL_V_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_ll_ieord_full_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count BOTTLENECK ordered task LL full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_ll_ieord_full_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_ll_ieord_full </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK ordered task LL full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_ll_ieord_full_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_ll_ieord_full
 */
 
typedef struct
{
     unsigned  int      cnt_counter_ll_ieord_full;
} ncp_nca_itp_cor_counter_counter_ll_ieord_full_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_ll_ieunord_full_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count BOTTLENECK unordered task LL full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_ll_ieunord_full_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_ll_ieunord_full </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK unordered task LL full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_ll_ieunord_full_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_ll_ieunord_full
 */
 
typedef struct
{
     unsigned  int      cnt_counter_ll_ieunord_full;
} ncp_nca_itp_cor_counter_counter_ll_ieunord_full_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_ll_preproc_full_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count BOTTLENECK preprocessing LL full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_ll_preproc_full_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_ll_preproc_full </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK preprocessing LL full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_ll_preproc_full_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_ll_preproc_full
 */
 
typedef struct
{
     unsigned  int      cnt_counter_ll_preproc_full;
} ncp_nca_itp_cor_counter_counter_ll_preproc_full_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_ll_completion_full_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count BOTTLENECK complettion LL full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_ll_completion_full_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_ll_completion_full </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK complettion LL full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_ll_completion_full_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_ll_completion_full
 */
 
typedef struct
{
     unsigned  int      cnt_counter_ll_completion_full;
} ncp_nca_itp_cor_counter_counter_ll_completion_full_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_tqbp_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count BOTTLENECK TQ BP caused by enqueued tasks from TQ greater than threshold
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_tqbp_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_tqbp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK TQ BP caused by enqueued tasks from
 *        TQ greater than threshold
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_tqbp_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_tqbp
 */
 
typedef struct
{
     unsigned  int          cnt_counter_tqbp;
} ncp_nca_itp_cor_counter_counter_tqbp_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_ipcqfull_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count BOTTLENECK any iPCQ full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_ipcqfull_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_ipcqfull </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK any iPCQ full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_ipcqfull_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_ipcqfull
 */
 
typedef struct
{
     unsigned  int      cnt_counter_ipcqfull;
} ncp_nca_itp_cor_counter_counter_ipcqfull_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_multifull_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count BOTTLENECK ouptut multiFIFO servicing all NCAP has any FIFO full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_multifull_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_multifull </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK ouptut multiFIFO servicing all NCAP
 *        has any FIFO full
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_multifull_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_multifull
 */
 
typedef struct
{
     unsigned  int      cnt_counter_multifull;
} ncp_nca_itp_cor_counter_counter_multifull_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_nlinkready_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count BOTTLENECK iPCQ req NLINK ready is low
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_nlinkready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_nlinkready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK iPCQ req NLINK ready is low </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_nlinkready_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_nlinkready
 */
 
typedef struct
{
     unsigned  int      cnt_counter_nlinkready;
} ncp_nca_itp_cor_counter_counter_nlinkready_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_credits_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count BOTTLENECK any NCAP credit is exhausted
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_credits_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_credits </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK any NCAP credit is exhausted </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_credits_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_credits
 */
 
typedef struct
{
     unsigned  int       cnt_counter_credits;
} ncp_nca_itp_cor_counter_counter_credits_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_itp_otp_dealloc_bp_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count BOTTLENECK OTP backpressures deallocate
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_itp_otp_dealloc_bp_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_itp_otp_dealloc_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK OTP backpressures deallocate </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_itp_otp_dealloc_bp_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_itp_otp_dealloc_bp
 */
 
typedef struct
{
     unsigned  int      cnt_counter_itp_otp_dealloc_bp;
} ncp_nca_itp_cor_counter_counter_itp_otp_dealloc_bp_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_mmbr_eng_bp_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count BOTTLENECK MCIP backpressure deallocate
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_mmbr_eng_bp_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_mmbr_eng_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK MCIP backpressure deallocate </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_mmbr_eng_bp_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_mmbr_eng_bp
 */
 
typedef struct
{
     unsigned  int      cnt_counter_mmbr_eng_bp;
} ncp_nca_itp_cor_counter_counter_mmbr_eng_bp_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_itp_mtp_req_core_arready_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count BOTTLENECK MTP backpressure allocate
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_itp_mtp_req_core_arready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_itp_mtp_req_core_arready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK MTP backpressure allocate </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_itp_mtp_req_core_arready_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_itp_mtp_req_core_arready
 */
 
typedef struct
{
     unsigned  int      cnt_counter_itp_mtp_req_core_arready;
} ncp_nca_itp_cor_counter_counter_itp_mtp_req_core_arready_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_itp_mtp_tx_core_awready_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count BOTTLENECK MTP backpressure MQG commands
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_itp_mtp_tx_core_awready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_itp_mtp_tx_core_awready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK MTP backpressure MQG commands </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_itp_mtp_tx_core_awready_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_itp_mtp_tx_core_awready
 */
 
typedef struct
{
     unsigned  int      cnt_counter_itp_mtp_tx_core_awready;
} ncp_nca_itp_cor_counter_counter_itp_mtp_tx_core_awready_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_qpm_core_awready_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count BOTTLENECK QPM backpressure
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_qpm_core_awready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_qpm_core_awready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK QPM backpressure </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_qpm_core_awready_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_qpm_core_awready
 */
 
typedef struct
{
     unsigned  int      cnt_counter_qpm_core_awready;
} ncp_nca_itp_cor_counter_counter_qpm_core_awready_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_trace_data_core_awready_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count BOTTLENECK TRACE backpressure
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_trace_data_core_awready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_trace_data_core_awready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK TRACE backpressure </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_trace_data_core_awready_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_trace_data_core_awready
 */
 
typedef struct
{
     unsigned  int      cnt_counter_trace_data_core_awready;
} ncp_nca_itp_cor_counter_counter_trace_data_core_awready_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_activitycounter_writeack0_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count BOTTLENECK writeack for header write is at threshold
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_activitycounter_writeack0_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_activitycounter_writeack0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK writeack for header write is at threshold </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_activitycounter_writeack0_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_activitycounter_writeack0
 */
 
typedef struct
{
     unsigned  int      cnt_counter_activitycounter_writeack0;
} ncp_nca_itp_cor_counter_counter_activitycounter_writeack0_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_activitycounter_writeack1_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count BOTTLENECK writeack for data copy write is at threshold
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_activitycounter_writeack1_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_activitycounter_writeack1 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK writeack for data copy write is at
 *        threshold
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_activitycounter_writeack1_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_activitycounter_writeack1
 */
 
typedef struct
{
     unsigned  int      cnt_counter_activitycounter_writeack1;
} ncp_nca_itp_cor_counter_counter_activitycounter_writeack1_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_activitycounter_mtp_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count BOTTLENECK data copy pointer prefetch is at threshold
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_activitycounter_mtp_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_activitycounter_mtp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count BOTTLENECK data copy pointer prefetch is at
 *        threshold
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_activitycounter_mtp_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_activitycounter_mtp
 */
 
typedef struct
{
     unsigned  int      cnt_counter_activitycounter_mtp;
} ncp_nca_itp_cor_counter_counter_activitycounter_mtp_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_tilstart_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count TIL start tasks
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_tilstart_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_tilstart </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count TIL start tasks </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_tilstart_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_tilstart
 */
 
typedef struct
{
     unsigned  int      cnt_counter_tilstart;
} ncp_nca_itp_cor_counter_counter_tilstart_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_pp_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count tasks complete preprocessing
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_pp_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_pp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count tasks complete preprocessing </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_pp_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_pp
 */
 
typedef struct
{
     unsigned  int            cnt_counter_pp;
} ncp_nca_itp_cor_counter_counter_pp_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_pp_ptrcnt0_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count tasks complete preprocessing with no pointers
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_pp_ptrcnt0_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_pp_ptrcnt0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count tasks complete preprocessing with no pointers </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_pp_ptrcnt0_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_pp_ptrcnt0
 */
 
typedef struct
{
     unsigned  int      cnt_counter_pp_ptrcnt0;
} ncp_nca_itp_cor_counter_counter_pp_ptrcnt0_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_pp_copy_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count task complete preprocessing that were copied
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_pp_copy_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_pp_copy </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count task complete preprocessing that were copied </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_pp_copy_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_pp_copy
 */
 
typedef struct
{
     unsigned  int       cnt_counter_pp_copy;
} ncp_nca_itp_cor_counter_counter_pp_copy_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_pp_hs_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count complete preprocessing that had Header Sperate FORMAT00 enabled
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_pp_hs_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_pp_hs </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count complete preprocessing that had Header Sperate
 *        FORMAT00 enabled
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_pp_hs_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_pp_hs
 */
 
typedef struct
{
     unsigned  int         cnt_counter_pp_hs;
} ncp_nca_itp_cor_counter_counter_pp_hs_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_pp_err_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count complete preprocessing that were dtected as an error
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_pp_err_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_pp_err </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count complete preprocessing that were dtected as
 *        an error
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_pp_err_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_pp_err
 */
 
typedef struct
{
     unsigned  int        cnt_counter_pp_err;
} ncp_nca_itp_cor_counter_counter_pp_err_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_enqueue_camhit_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count ordered task CAM hit
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_enqueue_camhit_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_enqueue_camhit </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered task CAM hit </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_enqueue_camhit_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_enqueue_camhit
 */
 
typedef struct
{
     unsigned  int      cnt_counter_enqueue_camhit;
} ncp_nca_itp_cor_counter_counter_enqueue_camhit_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_enqueue_cammiss_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count ordered task CAM miss
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_enqueue_cammiss_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_enqueue_cammiss </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered task CAM miss </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_enqueue_cammiss_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_enqueue_cammiss
 */
 
typedef struct
{
     unsigned  int      cnt_counter_enqueue_cammiss;
} ncp_nca_itp_cor_counter_counter_enqueue_cammiss_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_enqueue_ordered_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count ordered task enqueued
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_enqueue_ordered_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_enqueue_ordered </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered task enqueued </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_enqueue_ordered_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_enqueue_ordered
 */
 
typedef struct
{
     unsigned  int      cnt_counter_enqueue_ordered;
} ncp_nca_itp_cor_counter_counter_enqueue_ordered_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_enqueue_unorder_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count unordered task enqueued
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_enqueue_unorder_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_enqueue_unorder </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count unordered task enqueued </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_enqueue_unorder_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_enqueue_unorder
 */
 
typedef struct
{
     unsigned  int      cnt_counter_enqueue_unorder;
} ncp_nca_itp_cor_counter_counter_enqueue_unorder_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_enqueue_unsched_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count unscheduled task enqueued
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_enqueue_unsched_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_enqueue_unsched </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count unscheduled task enqueued </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_enqueue_unsched_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_enqueue_unsched
 */
 
typedef struct
{
     unsigned  int      cnt_counter_enqueue_unsched;
} ncp_nca_itp_cor_counter_counter_enqueue_unsched_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_enqueue_unsched_ack_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count unscheduled exception ack task enqueued
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_enqueue_unsched_ack_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_enqueue_unsched_ack </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count unscheduled exception ack task enqueued </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_enqueue_unsched_ack_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_enqueue_unsched_ack
 */
 
typedef struct
{
     unsigned  int      cnt_counter_enqueue_unsched_ack;
} ncp_nca_itp_cor_counter_counter_enqueue_unsched_ack_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_sched_orderedsched_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count ordered task in scheduled state scheduled
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_sched_orderedsched_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_sched_orderedsched </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered task in scheduled state scheduled </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_sched_orderedsched_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_sched_orderedsched
 */
 
typedef struct
{
     unsigned  int      cnt_counter_sched_orderedsched;
} ncp_nca_itp_cor_counter_counter_sched_orderedsched_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_sched_orderedready_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count ordered task in ready state scheduled
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_sched_orderedready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_sched_orderedready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered task in ready state scheduled </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_sched_orderedready_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_sched_orderedready
 */
 
typedef struct
{
     unsigned  int      cnt_counter_sched_orderedready;
} ncp_nca_itp_cor_counter_counter_sched_orderedready_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_sched_unorder_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count unordered task scheduled
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_sched_unorder_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_sched_unorder </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count unordered task scheduled </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_sched_unorder_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_sched_unorder
 */
 
typedef struct
{
     unsigned  int      cnt_counter_sched_unorder;
} ncp_nca_itp_cor_counter_counter_sched_unorder_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_nlinkreq_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count NLINK tasks delivered
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_nlinkreq_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_nlinkreq </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count NLINK tasks delivered </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_nlinkreq_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_nlinkreq
 */
 
typedef struct
{
     unsigned  int      cnt_counter_nlinkreq;
} ncp_nca_itp_cor_counter_counter_nlinkreq_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_complete_ordered_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count ordered task completions received
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_complete_ordered_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_complete_ordered </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered task completions received </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_complete_ordered_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_complete_ordered
 */
 
typedef struct
{
     unsigned  int      cnt_counter_complete_ordered;
} ncp_nca_itp_cor_counter_counter_complete_ordered_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_complete_unorder_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count unordered task completions received
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_complete_unorder_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_complete_unorder </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count unordered task completions received </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_complete_unorder_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_complete_unorder
 */
 
typedef struct
{
     unsigned  int      cnt_counter_complete_unorder;
} ncp_nca_itp_cor_counter_counter_complete_unorder_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_pointeralloc_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count number of pointers allocated by ITP
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_pointeralloc_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_pointeralloc </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count number of pointers allocated by ITP </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_pointeralloc_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_pointeralloc
 */
 
typedef struct
{
     unsigned  int      cnt_counter_pointeralloc;
} ncp_nca_itp_cor_counter_counter_pointeralloc_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_pointerdealloc0_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count number of pointers deallcoated by ITP
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_pointerdealloc0_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_pointerdealloc0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count number of pointers deallcoated by ITP </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_pointerdealloc0_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_pointerdealloc0
 */
 
typedef struct
{
     unsigned  int      cnt_counter_pointerdealloc0;
} ncp_nca_itp_cor_counter_counter_pointerdealloc0_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_pointerdealloc1_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count number of pointers deallcoated by ITP
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_pointerdealloc1_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_pointerdealloc1 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count number of pointers deallcoated by ITP </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_pointerdealloc1_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_pointerdealloc1
 */
 
typedef struct
{
     unsigned  int      cnt_counter_pointerdealloc1;
} ncp_nca_itp_cor_counter_counter_pointerdealloc1_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_pointertask_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count number of pointers sent to ITP in VPP task
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_pointertask_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_pointertask </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count number of pointers sent to ITP in VPP task </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_pointertask_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_pointertask
 */
 
typedef struct
{
     unsigned  int      cnt_counter_pointertask;
} ncp_nca_itp_cor_counter_counter_pointertask_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_mqg_inc_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count number of pointers delivered by ITP to iPCQ task
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_mqg_inc_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_mqg_inc </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count number of pointers delivered by ITP to iPCQ
 *        task
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_mqg_inc_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_mqg_inc
 */
 
typedef struct
{
     unsigned  int       cnt_counter_mqg_inc;
} ncp_nca_itp_cor_counter_counter_mqg_inc_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_pointernack_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count number of allocate NACKs received
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_pointernack_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_pointernack </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count number of allocate NACKs received </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_pointernack_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_pointernack
 */
 
typedef struct
{
     unsigned  int      cnt_counter_pointernack;
} ncp_nca_itp_cor_counter_counter_pointernack_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_statetrans_00_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count ordered state transition
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_statetrans_00_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_statetrans_00 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered state transition </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_statetrans_00_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_statetrans_00
 */
 
typedef struct
{
     unsigned  int      cnt_counter_statetrans_00;
} ncp_nca_itp_cor_counter_counter_statetrans_00_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_statetrans_01_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count ordered state transition
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_statetrans_01_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_statetrans_01 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered state transition </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_statetrans_01_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_statetrans_01
 */
 
typedef struct
{
     unsigned  int      cnt_counter_statetrans_01;
} ncp_nca_itp_cor_counter_counter_statetrans_01_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_statetrans_02_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count ordered state transition
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_statetrans_02_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_statetrans_02 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered state transition </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_statetrans_02_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_statetrans_02
 */
 
typedef struct
{
     unsigned  int      cnt_counter_statetrans_02;
} ncp_nca_itp_cor_counter_counter_statetrans_02_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_statetrans_03_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count ordered state transition
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_statetrans_03_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_statetrans_03 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered state transition </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_statetrans_03_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_statetrans_03
 */
 
typedef struct
{
     unsigned  int      cnt_counter_statetrans_03;
} ncp_nca_itp_cor_counter_counter_statetrans_03_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_statetrans_04_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count ordered state transition
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_statetrans_04_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_statetrans_04 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered state transition </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_statetrans_04_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_statetrans_04
 */
 
typedef struct
{
     unsigned  int      cnt_counter_statetrans_04;
} ncp_nca_itp_cor_counter_counter_statetrans_04_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_statetrans_05_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count ordered state transition
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_statetrans_05_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_statetrans_05 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered state transition </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_statetrans_05_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_statetrans_05
 */
 
typedef struct
{
     unsigned  int      cnt_counter_statetrans_05;
} ncp_nca_itp_cor_counter_counter_statetrans_05_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_statetrans_06_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count ordered state transition
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_statetrans_06_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_statetrans_06 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered state transition </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_statetrans_06_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_statetrans_06
 */
 
typedef struct
{
     unsigned  int      cnt_counter_statetrans_06;
} ncp_nca_itp_cor_counter_counter_statetrans_06_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_statetrans_07_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count ordered state transition
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_statetrans_07_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_statetrans_07 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered state transition </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_statetrans_07_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_statetrans_07
 */
 
typedef struct
{
     unsigned  int      cnt_counter_statetrans_07;
} ncp_nca_itp_cor_counter_counter_statetrans_07_r_t;

/*! @struct ncp_nca_itp_cor_counter_counter_statetrans_08_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count ordered state transition
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cor_counter_counter_statetrans_08_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_statetrans_08 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count ordered state transition </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cor_counter_counter_statetrans_08_r_t
 *
 * Implemented by: 
 *      cor_counter_counter_statetrans_08
 */
 
typedef struct
{
     unsigned  int      cnt_counter_statetrans_08;
} ncp_nca_itp_cor_counter_counter_statetrans_08_r_t;

/*! @struct ncp_nca_itp_cfg_setup_r_t
 *  @brief null
 *  @details cfg_setup reigster for CFG block
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_cfg_setup_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 29 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param enable_read_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> enable read error. When this is set to 1 then illegal
 *        CFG read access will return an error indication
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param enable_nsa </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> enable non-secure CFG access. When this is set to
 *        1 non-secure CFG access are processed. When this is
 *        set to 0 then non-secure CFG access are not processed
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param disable_write </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> disable CFG write access. When this is set to 1 (sticky)
 *        then CFG write access to specified registers is disabled
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_cfg_setup_r_t
 *
 * Implemented by: 
 *      cfg_setup
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 29;
     unsigned      enable_read_error                         :  1;
     unsigned      enable_nsa                                :  1;
     unsigned      disable_write                             :  1;
#else    /* Little Endian */
     unsigned      disable_write                             :  1;
     unsigned      enable_nsa                                :  1;
     unsigned      enable_read_error                         :  1;
     unsigned      reserved0                                 : 29;
#endif
} ncp_nca_itp_cfg_setup_r_t;

/*! @struct ncp_nca_itp_fifo_state_ram_r_t
 *  @brief Current state for shared-RAM FIFO
 *  @details Current depth, read pointer, and write pointer for a shared-RAM FIFO.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_fifo_state_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_wptr </td>
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> FIFO Write Pointer </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_rptr </td>
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> FIFO Read Pointer </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_depth </td>
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> FIFO Depth </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_fifo_state_ram_r_t
 *
 * Implemented by: 
 *      multi_ouptut_fifo_state_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  5;
     unsigned      fifo_wptr                                 :  9;
     unsigned      fifo_rptr                                 :  9;
     unsigned      fifo_depth                                :  9;
#else    /* Little Endian */
     unsigned      fifo_depth                                :  9;
     unsigned      fifo_rptr                                 :  9;
     unsigned      fifo_wptr                                 :  9;
     unsigned      reserved0                                 :  5;
#endif
} ncp_nca_itp_fifo_state_ram_r_t;

/*! @struct ncp_nca_itp_ipd2_ram_r_t
 *  @brief null
 *  @details iPCQ Descriptor Table
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipd2_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 17 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq </td>
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ipcq </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param threshold </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> threshold </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipd2_ram_r_t
 *
 * Implemented by: 
 *      ipd2_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 17;
     unsigned      ipcq                                      :  7;
     unsigned      threshold                                 :  8;
#else    /* Little Endian */
     unsigned      threshold                                 :  8;
     unsigned      ipcq                                      :  7;
     unsigned      reserved0                                 : 17;
#endif
} ncp_nca_itp_ipd2_ram_r_t;

/*! @struct ncp_nca_itp_ll_preproc_state_ram_r_t
 *  @brief preprocessing LL state RAM
 *  @details LL state RAM. OLL is defined by 2 parameters: LL:specifies the number of linked lists supported. ENTRY: specifies the number of data entry supported. The state ram has the HP,TP,COUNT, and VALID bit for each LL. The number of ENTRY determines the width of the pointers and count
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ll_preproc_state_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 19 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param count </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> count </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param tp </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> tp </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> hp </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_preproc_state_ram_r_t
 *
 * Implemented by: 
 *      ll_preproc_state_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 19;
     unsigned      valid                                     :  1;
     unsigned      count                                     :  4;
     unsigned      tp                                        :  4;
     unsigned      hp                                        :  4;
#else    /* Little Endian */
     unsigned      hp                                        :  4;
     unsigned      tp                                        :  4;
     unsigned      count                                     :  4;
     unsigned      valid                                     :  1;
     unsigned      reserved0                                 : 19;
#endif
} ncp_nca_itp_ll_preproc_state_ram_r_t;

/*! @struct ncp_nca_itp_ll_preproc_pointer_ram_r_t
 *  @brief preprocessing LL pointer RAM
 *  @details LL pointer RAM.  has the next HP for each ENTRY
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ll_preproc_pointer_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 28 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> hp </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_preproc_pointer_ram_r_t
 *
 * Implemented by: 
 *      ll_preproc_pointer_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 28;
     unsigned      hp                                        :  4;
#else    /* Little Endian */
     unsigned      hp                                        :  4;
     unsigned      reserved0                                 : 28;
#endif
} ncp_nca_itp_ll_preproc_pointer_ram_r_t;

/*! @struct ncp_nca_itp_ll_preproc_complete_ram_r_t
 *  @brief preprocessing LL complete RAM
 *  @details LL complete data RAM.   stores the complete data for each ENTRY
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ll_preproc_complete_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 31 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> hp </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_preproc_complete_ram_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 31;
     unsigned      hp                                        :  1;
#else    /* Little Endian */
     unsigned      hp                                        :  1;
     unsigned      reserved0                                 : 31;
#endif
} ncp_nca_itp_ll_preproc_complete_ram_r_t;

/*! @struct ncp_nca_itp_tqbp_pertq_unissued_thresh_ram_r_t
 *  @brief null
 *  @details per TQ threshold. Issue BP to TQ when tqbp_pertq_unissued_cnt exceede this threshold
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_tqbp_pertq_unissued_thresh_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 21 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data </td>
 *     <td width="20%" align="center"> 11 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> per TQ threshold. Issue BP to TQ when tqbp_pertq_unissued_cnt
 *        exceede this threshold
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_tqbp_pertq_unissued_thresh_ram_r_t
 *
 * Implemented by: 
 *      tqbp_pertq_unissued_thresh_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 21;
     unsigned      data                                      : 11;
#else    /* Little Endian */
     unsigned      data                                      : 11;
     unsigned      reserved0                                 : 21;
#endif
} ncp_nca_itp_tqbp_pertq_unissued_thresh_ram_r_t;

/*! @struct ncp_nca_itp_tqbp_pertq_unissuedqueued_thresh_ram_r_t
 *  @brief null
 *  @details per TQ threshold. Issue BP to TQ when tqbp_pertq_unissuedqueued_cnt exceede this threshold
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_tqbp_pertq_unissuedqueued_thresh_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 21 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data </td>
 *     <td width="20%" align="center"> 11 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> per TQ threshold. Issue BP to TQ when tqbp_pertq_unissuedqueued_cnt
 *        exceede this threshold
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_tqbp_pertq_unissuedqueued_thresh_ram_r_t
 *
 * Implemented by: 
 *      tqbp_pertq_unissuedqueued_thresh_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 21;
     unsigned      data                                      : 11;
#else    /* Little Endian */
     unsigned      data                                      : 11;
     unsigned      reserved0                                 : 21;
#endif
} ncp_nca_itp_tqbp_pertq_unissuedqueued_thresh_ram_r_t;

/*! @struct ncp_nca_itp_tqbp_pergid_unissued_thresh_ram_r_t
 *  @brief null
 *  @details per TQ threshold. Issue BP to TQ (translate with gid2tq) when tqbp_pergid_unissued_cnt exceede this threshold
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_tqbp_pergid_unissued_thresh_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 21 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data </td>
 *     <td width="20%" align="center"> 11 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> per TQ threshold. Issue BP to TQ (translate with gid2tq)
 *        when tqbp_pergid_unissued_cnt exceede this threshold
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_tqbp_pergid_unissued_thresh_ram_r_t
 *
 * Implemented by: 
 *      tqbp_pergid_unissued_thresh_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 21;
     unsigned      data                                      : 11;
#else    /* Little Endian */
     unsigned      data                                      : 11;
     unsigned      reserved0                                 : 21;
#endif
} ncp_nca_itp_tqbp_pergid_unissued_thresh_ram_r_t;

/*! @struct ncp_nca_itp_tqbp_pertq_unissued_cnt_ram_r_t
 *  @brief null
 *  @details per TQ current count. Increment when a task arrives on the TIL start task. Decrement when the task is delivered to NCAP on NLINK, delivered to QPM, or if the task is determined to be an error and dropped
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_tqbp_pertq_unissued_cnt_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 21 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data </td>
 *     <td width="20%" align="center"> 11 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> per TQ current count. Increment when a task arrives
 *        on the TIL start task. Decrement when the task is
 *        delivered to NCAP on NLINK, delivered to QPM, or if
 *        the task is determined to be an error and dropped
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_tqbp_pertq_unissued_cnt_ram_r_t
 *
 * Implemented by: 
 *      tqbp_pertq_unissued_cnt_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 21;
     unsigned      data                                      : 11;
#else    /* Little Endian */
     unsigned      data                                      : 11;
     unsigned      reserved0                                 : 21;
#endif
} ncp_nca_itp_tqbp_pertq_unissued_cnt_ram_r_t;

/*! @struct ncp_nca_itp_tqbp_pertq_unissuedqueued_cnt_ram_r_t
 *  @brief null
 *  @details per TQ current count. Increment when a ordered task hits in the BCAM. Decrement when the task is delivered to NCAP on NLINK, delivered to QPM, or if the task is determined to be an error and dropped
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_tqbp_pertq_unissuedqueued_cnt_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 21 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data </td>
 *     <td width="20%" align="center"> 11 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> per TQ current count. Increment when a ordered task
 *        hits in the BCAM. Decrement when the task is delivered
 *        to NCAP on NLINK, delivered to QPM, or if the task
 *        is determined to be an error and dropped
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_tqbp_pertq_unissuedqueued_cnt_ram_r_t
 *
 * Implemented by: 
 *      tqbp_pertq_unissuedqueued_cnt_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 21;
     unsigned      data                                      : 11;
#else    /* Little Endian */
     unsigned      data                                      : 11;
     unsigned      reserved0                                 : 21;
#endif
} ncp_nca_itp_tqbp_pertq_unissuedqueued_cnt_ram_r_t;

/*! @struct ncp_nca_itp_tqbp_pergid_unissued_cnt_ram_r_t
 *  @brief null
 *  @details per GID current count. Increment when a task arrives on the TIL start task. Decrement when the task is delivered to NCAP on NLINK, delivered to QPM, or if the task is determined to be an error and dropped
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_tqbp_pergid_unissued_cnt_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 21 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data </td>
 *     <td width="20%" align="center"> 11 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> per GID current count. Increment when a task arrives
 *        on the TIL start task. Decrement when the task is
 *        delivered to NCAP on NLINK, delivered to QPM, or if
 *        the task is determined to be an error and dropped
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_tqbp_pergid_unissued_cnt_ram_r_t
 *
 * Implemented by: 
 *      tqbp_pergid_unissued_cnt_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 21;
     unsigned      data                                      : 11;
#else    /* Little Endian */
     unsigned      data                                      : 11;
     unsigned      reserved0                                 : 21;
#endif
} ncp_nca_itp_tqbp_pergid_unissued_cnt_ram_r_t;

/*! @struct ncp_nca_itp_ll_ieunord_state_ram_r_t
 *  @brief ieunord LL state RAM
 *  @details LL state RAM. OLL is defined by 2 parameters: LL:specifies the number of linked lists supported. ENTRY: specifies the number of data entry supported. The state ram has the HP,TP,COUNT, and VALID bit for each LL. The number of ENTRY determines the width of the pointers and count
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ll_ieunord_state_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param count </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> count </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param tp </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> tp </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> hp </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_ieunord_state_ram_r_t
 *
 * Implemented by: 
 *      ll_ieunord_state_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  1;
     unsigned      valid                                     :  1;
     unsigned      count                                     : 10;
     unsigned      tp                                        : 10;
     unsigned      hp                                        : 10;
#else    /* Little Endian */
     unsigned      hp                                        : 10;
     unsigned      tp                                        : 10;
     unsigned      count                                     : 10;
     unsigned      valid                                     :  1;
     unsigned      reserved0                                 :  1;
#endif
} ncp_nca_itp_ll_ieunord_state_ram_r_t;

/*! @struct ncp_nca_itp_ll_ieunord_pointer_ram_r_t
 *  @brief ieunord LL pointer RAM
 *  @details LL pointer RAM.  has the next HP for each ENTRY
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ll_ieunord_pointer_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 22 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> hp </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_ieunord_pointer_ram_r_t
 *
 * Implemented by: 
 *      ll_ieunord_pointer_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 22;
     unsigned      hp                                        : 10;
#else    /* Little Endian */
     unsigned      hp                                        : 10;
     unsigned      reserved0                                 : 22;
#endif
} ncp_nca_itp_ll_ieunord_pointer_ram_r_t;

/*! @struct ncp_nca_itp_ll_ieunord_complete_ram_r_t
 *  @brief ieunord LL complete RAM
 *  @details LL complete data RAM.   stores the complete data for each ENTRY
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ll_ieunord_complete_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 31 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> hp </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_ieunord_complete_ram_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 31;
     unsigned      hp                                        :  1;
#else    /* Little Endian */
     unsigned      hp                                        :  1;
     unsigned      reserved0                                 : 31;
#endif
} ncp_nca_itp_ll_ieunord_complete_ram_r_t;

/*! @struct ncp_nca_itp_ll_ieord_state_ram_r_t
 *  @brief ieord LL state RAM
 *  @details LL state RAM. OLL is defined by 2 parameters: LL:specifies the number of linked lists supported. ENTRY: specifies the number of data entry supported. The state ram has the HP,TP,COUNT, and VALID bit for each LL. The number of ENTRY determines the width of the pointers and count
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ll_ieord_state_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param count </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> count </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param tp </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> tp </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> hp </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_ieord_state_ram_r_t
 *
 * Implemented by: 
 *      ll_ieord_state_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  1;
     unsigned      valid                                     :  1;
     unsigned      count                                     : 10;
     unsigned      tp                                        : 10;
     unsigned      hp                                        : 10;
#else    /* Little Endian */
     unsigned      hp                                        : 10;
     unsigned      tp                                        : 10;
     unsigned      count                                     : 10;
     unsigned      valid                                     :  1;
     unsigned      reserved0                                 :  1;
#endif
} ncp_nca_itp_ll_ieord_state_ram_r_t;

/*! @struct ncp_nca_itp_ll_ieord_pointer_ram_r_t
 *  @brief ieord LL pointer RAM
 *  @details LL pointer RAM.  has the next HP for each ENTRY
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ll_ieord_pointer_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 22 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> hp </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_ieord_pointer_ram_r_t
 *
 * Implemented by: 
 *      ll_ieord_pointer_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 22;
     unsigned      hp                                        : 10;
#else    /* Little Endian */
     unsigned      hp                                        : 10;
     unsigned      reserved0                                 : 22;
#endif
} ncp_nca_itp_ll_ieord_pointer_ram_r_t;

/*! @struct ncp_nca_itp_ll_ieord_complete_ram_r_t
 *  @brief ieord LL complete RAM
 *  @details LL complete data RAM.   stores the complete data for each ENTRY
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ll_ieord_complete_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 31 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> hp </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_ieord_complete_ram_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 31;
     unsigned      hp                                        :  1;
#else    /* Little Endian */
     unsigned      hp                                        :  1;
     unsigned      reserved0                                 : 31;
#endif
} ncp_nca_itp_ll_ieord_complete_ram_r_t;

/*! @struct ncp_nca_itp_ll_ieordready_state_ram_r_t
 *  @brief ieordready LL state RAM
 *  @details LL state RAM. OLL is defined by 2 parameters: LL:specifies the number of linked lists supported. ENTRY: specifies the number of data entry supported. The state ram has the HP,TP,COUNT, and VALID bit for each LL. The number of ENTRY determines the width of the pointers and count
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ll_ieordready_state_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param count </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> count </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param tp </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> tp </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> hp </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_ieordready_state_ram_r_t
 *
 * Implemented by: 
 *      ll_ieordready_state_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  1;
     unsigned      valid                                     :  1;
     unsigned      count                                     : 10;
     unsigned      tp                                        : 10;
     unsigned      hp                                        : 10;
#else    /* Little Endian */
     unsigned      hp                                        : 10;
     unsigned      tp                                        : 10;
     unsigned      count                                     : 10;
     unsigned      valid                                     :  1;
     unsigned      reserved0                                 :  1;
#endif
} ncp_nca_itp_ll_ieordready_state_ram_r_t;

/*! @struct ncp_nca_itp_ll_ieordready_pointer_ram_r_t
 *  @brief ieordready LL pointer RAM
 *  @details LL pointer RAM.  has the next HP for each ENTRY
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ll_ieordready_pointer_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 22 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> hp </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_ieordready_pointer_ram_r_t
 *
 * Implemented by: 
 *      ll_ieordready_pointer_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 22;
     unsigned      hp                                        : 10;
#else    /* Little Endian */
     unsigned      hp                                        : 10;
     unsigned      reserved0                                 : 22;
#endif
} ncp_nca_itp_ll_ieordready_pointer_ram_r_t;

/*! @struct ncp_nca_itp_ll_ieordready_complete_ram_r_t
 *  @brief ieordready LL complete RAM
 *  @details LL complete data RAM.   stores the complete data for each ENTRY
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ll_ieordready_complete_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 31 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> hp </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_ieordready_complete_ram_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 31;
     unsigned      hp                                        :  1;
#else    /* Little Endian */
     unsigned      hp                                        :  1;
     unsigned      reserved0                                 : 31;
#endif
} ncp_nca_itp_ll_ieordready_complete_ram_r_t;

/*! @struct ncp_nca_itp_ll_ieordready_allocate_ram_r_t
 *  @brief ieordready LL allocate data RAM
 *  @details LL allocate data RAM.  stores the allocate data for each ENTRY
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ll_ieordready_allocate_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 23 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata </td>
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> allocate data </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_ieordready_allocate_ram_r_t
 *
 * Implemented by: 
 *      ll_ieordready_allocate_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 23;
     unsigned      allocatedata                              :  9;
#else    /* Little Endian */
     unsigned      allocatedata                              :  9;
     unsigned      reserved0                                 : 23;
#endif
} ncp_nca_itp_ll_ieordready_allocate_ram_r_t;

/*! @struct ncp_nca_itp_ll_ieordscheduled_state_ram_r_t
 *  @brief ieordscheduled LL state RAM
 *  @details LL state RAM. OLL is defined by 2 parameters: LL:specifies the number of linked lists supported. ENTRY: specifies the number of data entry supported. The state ram has the HP,TP,COUNT, and VALID bit for each LL. The number of ENTRY determines the width of the pointers and count
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ll_ieordscheduled_state_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param count </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> count </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param tp </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> tp </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> hp </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_ieordscheduled_state_ram_r_t
 *
 * Implemented by: 
 *      ll_ieordscheduled_state_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  1;
     unsigned      valid                                     :  1;
     unsigned      count                                     : 10;
     unsigned      tp                                        : 10;
     unsigned      hp                                        : 10;
#else    /* Little Endian */
     unsigned      hp                                        : 10;
     unsigned      tp                                        : 10;
     unsigned      count                                     : 10;
     unsigned      valid                                     :  1;
     unsigned      reserved0                                 :  1;
#endif
} ncp_nca_itp_ll_ieordscheduled_state_ram_r_t;

/*! @struct ncp_nca_itp_ll_ieordscheduled_pointer_ram_r_t
 *  @brief ieordscheduled LL pointer RAM
 *  @details LL pointer RAM.  has the next HP for each ENTRY
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ll_ieordscheduled_pointer_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 22 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> hp </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_ieordscheduled_pointer_ram_r_t
 *
 * Implemented by: 
 *      ll_ieordscheduled_pointer_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 22;
     unsigned      hp                                        : 10;
#else    /* Little Endian */
     unsigned      hp                                        : 10;
     unsigned      reserved0                                 : 22;
#endif
} ncp_nca_itp_ll_ieordscheduled_pointer_ram_r_t;

/*! @struct ncp_nca_itp_ll_ieordscheduled_tpointer_ram_r_t
 *  @brief ieordscheduled LL pointer RAM
 *  @details LL pointer RAM.  has the next HP for each ENTRY
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ll_ieordscheduled_tpointer_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 22 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param tp </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> tp </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_ieordscheduled_tpointer_ram_r_t
 *
 * Implemented by: 
 *      ll_ieordscheduled_tpointer_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 22;
     unsigned      tp                                        : 10;
#else    /* Little Endian */
     unsigned      tp                                        : 10;
     unsigned      reserved0                                 : 22;
#endif
} ncp_nca_itp_ll_ieordscheduled_tpointer_ram_r_t;

/*! @struct ncp_nca_itp_ll_ieordscheduled_allocate_ram_r_t
 *  @brief ieordscheduled LL allocate data RAM
 *  @details LL allocate data RAM.  stores the allocate data for each ENTRY
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ll_ieordscheduled_allocate_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 23 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata </td>
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> allocate data </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_ieordscheduled_allocate_ram_r_t
 *
 * Implemented by: 
 *      ll_ieordscheduled_allocate_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 23;
     unsigned      allocatedata                              :  9;
#else    /* Little Endian */
     unsigned      allocatedata                              :  9;
     unsigned      reserved0                                 : 23;
#endif
} ncp_nca_itp_ll_ieordscheduled_allocate_ram_r_t;

/*! @struct ncp_nca_itp_ll_completion_pointer_ram_r_t
 *  @brief completion LL pointer RAM
 *  @details LL pointer RAM.  has the next HP for each ENTRY
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ll_completion_pointer_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 21 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp </td>
 *     <td width="20%" align="center"> 11 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> hp </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_completion_pointer_ram_r_t
 *
 * Implemented by: 
 *      ll_completion_pointer_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 21;
     unsigned      hp                                        : 11;
#else    /* Little Endian */
     unsigned      hp                                        : 11;
     unsigned      reserved0                                 : 21;
#endif
} ncp_nca_itp_ll_completion_pointer_ram_r_t;

/*! @struct ncp_nca_itp_ll_completion_complete_ram_r_t
 *  @brief completion LL complete RAM
 *  @details LL complete data RAM.   stores the complete data for each ENTRY
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ll_completion_complete_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 31 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> hp </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_completion_complete_ram_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 31;
     unsigned      hp                                        :  1;
#else    /* Little Endian */
     unsigned      hp                                        :  1;
     unsigned      reserved0                                 : 31;
#endif
} ncp_nca_itp_ll_completion_complete_ram_r_t;

/*! @struct ncp_nca_itp_qpm_qstatus_ram_r_t
 *  @brief null
 *  @details QPM Qstatus RAM
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_qpm_qstatus_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param array </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> bit array for QPM QUEUE full. Read this RAM when processing
 *        an unscheuded task. If the desintation QPM queue bit
 *        is set then drop the task
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_qpm_qstatus_ram_r_t
 *
 * Implemented by: 
 *      qpm_qstatus_ram
 */
 
typedef struct
{
     unsigned  int                     array;
} ncp_nca_itp_qpm_qstatus_ram_r_t;

/*! @struct ncp_nca_itp_qpm_online_ram_r_t
 *  @brief null
 *  @details QPM Qstatus RAM
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_qpm_online_ram_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param array </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> bit array for QPM QUEUE online. Read this RAM when
 *        processing an unscheuded task. If the desintation
 *        QPM queue bit is not set then drop the task
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_qpm_online_ram_r_t
 *
 * Implemented by: 
 *      qpm_online_ram
 */
 
typedef struct
{
     unsigned  int                     array;
} ncp_nca_itp_qpm_online_ram_r_t;

/*! @struct ncp_nca_itp_bcam_r_t
 *  @brief null
 *  @details read contents of BCAM
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_bcam_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 12 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param toid </td>
 *     <td width="20%" align="center"> 12 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> TOID </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> GID </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_bcam_r_t
 *
 * Implemented by: 
 *      bcam
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 12;
     unsigned      toid                                      : 12;
     unsigned      gid                                       :  8;
#else    /* Little Endian */
     unsigned      gid                                       :  8;
     unsigned      toid                                      : 12;
     unsigned      reserved0                                 : 12;
#endif
} ncp_nca_itp_bcam_r_t;

/*! @struct ncp_nca_itp_ipcq_online00_r_t
 *  @brief null
 *  @details online bit for each of the iPCQ 31-0. THis will prevent task from being sent to iPCQ.  The iPCQ will not be available in the schduling and no tasks will be delivered
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_online00_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param online </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> iPCQ[31:0] </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_online00_r_t
 *
 * Implemented by: 
 *      ipcq_online00
 */
 
typedef struct
{
     unsigned  int                    online;
} ncp_nca_itp_ipcq_online00_r_t;

/*! @struct ncp_nca_itp_ipcq_online01_r_t
 *  @brief null
 *  @details online bit for each of the iPCQ 63-32. THis will prevent task from being sent to iPCQ.  The iPCQ will not be available in the schduling and no tasks will be delivered
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_online01_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param online </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> iPCQ[63:32] </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_online01_r_t
 *
 * Implemented by: 
 *      ipcq_online01
 */
 
typedef struct
{
     unsigned  int                    online;
} ncp_nca_itp_ipcq_online01_r_t;

/*! @struct ncp_nca_itp_ipcq_online02_r_t
 *  @brief null
 *  @details online bit for each of the iPCQ 85-64. THis will prevent task from being sent to iPCQ.  The iPCQ will not be available in the schduling and no tasks will be delivered
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_online02_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param online </td>
 *     <td width="20%" align="center"> 22 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> iPCQ[85:64] </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_online02_r_t
 *
 * Implemented by: 
 *      ipcq_online02
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 10;
     unsigned      online                                    : 22;
#else    /* Little Endian */
     unsigned      online                                    : 22;
     unsigned      reserved0                                 : 10;
#endif
} ncp_nca_itp_ipcq_online02_r_t;

/*! @struct ncp_nca_itp_ipcq_valid00_r_t
 *  @brief null
 *  @details valid bit for each of the iPCQ 31-0. This will disable the iPCQ from having a new flow assigned.  No new ordered flows will be assigned to the iPCQ,  all active assigned flows & unordered task will continue to be delviered to iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_valid00_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param valid </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> iPCQ[31:0] </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_valid00_r_t
 *
 * Implemented by: 
 *      ipcq_valid00
 */
 
typedef struct
{
     unsigned  int                     valid;
} ncp_nca_itp_ipcq_valid00_r_t;

/*! @struct ncp_nca_itp_ipcq_valid01_r_t
 *  @brief null
 *  @details valid bit for each of the iPCQ 63-32. This will disable the iPCQ from having a new flow assigned.  No new ordered flows will be assigned to the iPCQ,  all active assigned flows & unordered task will continue to be delviered to iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_valid01_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param valid </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> iPCQ[63:32] </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_valid01_r_t
 *
 * Implemented by: 
 *      ipcq_valid01
 */
 
typedef struct
{
     unsigned  int                     valid;
} ncp_nca_itp_ipcq_valid01_r_t;

/*! @struct ncp_nca_itp_ipcq_valid02_r_t
 *  @brief null
 *  @details valid bit for each of the iPCQ 85-64. This will disable the iPCQ from having a new flow assigned.  No new ordered flows will be assigned to the iPCQ,  all active assigned flows & unordered task will continue to be delviered to iPCQ
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_valid02_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param valid </td>
 *     <td width="20%" align="center"> 22 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> iPCQ[85:64] </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_valid02_r_t
 *
 * Implemented by: 
 *      ipcq_valid02
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 10;
     unsigned      valid                                     : 22;
#else    /* Little Endian */
     unsigned      valid                                     : 22;
     unsigned      reserved0                                 : 10;
#endif
} ncp_nca_itp_ipcq_valid02_r_t;

/*! @struct ncp_nca_itp_ipcq_empty00_r_t
 *  @brief null
 *  @details empty bit for each of the iPCQ 31-0
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_empty00_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param empty </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> iPCQ[31:0] </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_empty00_r_t
 *
 * Implemented by: 
 *      ipcq_empty00
 */
 
typedef struct
{
     unsigned  int                     empty;
} ncp_nca_itp_ipcq_empty00_r_t;

/*! @struct ncp_nca_itp_ipcq_empty01_r_t
 *  @brief null
 *  @details empty bit for each of the iPCQ 63-32
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_empty01_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param empty </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> iPCQ[63:32] </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_empty01_r_t
 *
 * Implemented by: 
 *      ipcq_empty01
 */
 
typedef struct
{
     unsigned  int                     empty;
} ncp_nca_itp_ipcq_empty01_r_t;

/*! @struct ncp_nca_itp_ipcq_empty02_r_t
 *  @brief null
 *  @details empty bit for each of the iPCQ 85-64
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_empty02_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param empty </td>
 *     <td width="20%" align="center"> 22 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> iPCQ[85:64] </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_empty02_r_t
 *
 * Implemented by: 
 *      ipcq_empty02
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 10;
     unsigned      empty                                     : 22;
#else    /* Little Endian */
     unsigned      empty                                     : 22;
     unsigned      reserved0                                 : 10;
#endif
} ncp_nca_itp_ipcq_empty02_r_t;

/*! @struct ncp_nca_itp_ipcq_full00_r_t
 *  @brief null
 *  @details full bit for each of the iPCQ 31-0
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_full00_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param full </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> iPCQ[31:0] </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_full00_r_t
 *
 * Implemented by: 
 *      ipcq_full00
 */
 
typedef struct
{
     unsigned  int                      full;
} ncp_nca_itp_ipcq_full00_r_t;

/*! @struct ncp_nca_itp_ipcq_full01_r_t
 *  @brief null
 *  @details full bit for each of the iPCQ 63-32
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_full01_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param full </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> iPCQ[63:32] </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_full01_r_t
 *
 * Implemented by: 
 *      ipcq_full01
 */
 
typedef struct
{
     unsigned  int                      full;
} ncp_nca_itp_ipcq_full01_r_t;

/*! @struct ncp_nca_itp_ipcq_full02_r_t
 *  @brief null
 *  @details full bit for each of the iPCQ 85-64
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ipcq_full02_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param full </td>
 *     <td width="20%" align="center"> 22 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> iPCQ[85:64] </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq_full02_r_t
 *
 * Implemented by: 
 *      ipcq_full02
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 10;
     unsigned      full                                      : 22;
#else    /* Little Endian */
     unsigned      full                                      : 22;
     unsigned      reserved0                                 : 10;
#endif
} ncp_nca_itp_ipcq_full02_r_t;

/*! @struct ncp_nca_itp_ncap_size00_r_t
 *  @brief null
 *  @details multi FIFO size for each NCAP 0-3
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ncap_size00_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_size03 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> NCAP 03 ipcq_size </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_size02 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> NCAP 02 ipcq_size </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_size01 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> NCAP 01 ipcq_size </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_size00 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> NCAP 00 ipcq_size </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ncap_size00_r_t
 *
 * Implemented by: 
 *      ncap_size00
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq_size03                               :  8;
     unsigned      ipcq_size02                               :  8;
     unsigned      ipcq_size01                               :  8;
     unsigned      ipcq_size00                               :  8;
#else    /* Little Endian */
     unsigned      ipcq_size00                               :  8;
     unsigned      ipcq_size01                               :  8;
     unsigned      ipcq_size02                               :  8;
     unsigned      ipcq_size03                               :  8;
#endif
} ncp_nca_itp_ncap_size00_r_t;

/*! @struct ncp_nca_itp_ncap_size01_r_t
 *  @brief null
 *  @details multi FIFO size for each NCAP 4-7
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ncap_size01_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_size07 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> NCAP 07 ipcq_size </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_size06 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> NCAP 06 ipcq_size </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_size0f </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> NCAP 05 ipcq_size </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_size04 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> NCAP 04 ipcq_size </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ncap_size01_r_t
 *
 * Implemented by: 
 *      ncap_size01
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq_size07                               :  8;
     unsigned      ipcq_size06                               :  8;
     unsigned      ipcq_size0f                               :  8;
     unsigned      ipcq_size04                               :  8;
#else    /* Little Endian */
     unsigned      ipcq_size04                               :  8;
     unsigned      ipcq_size0f                               :  8;
     unsigned      ipcq_size06                               :  8;
     unsigned      ipcq_size07                               :  8;
#endif
} ncp_nca_itp_ncap_size01_r_t;

/*! @struct ncp_nca_itp_ncap_size02_r_t
 *  @brief null
 *  @details multi FIFO size for each NCAP 8-11
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ncap_size02_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_size11 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> NCAP 11 ipcq_size </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_size10 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> NCAP 10 ipcq_size </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_size09 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> NCAP 09 ipcq_size </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_size08 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> NCAP 08 ipcq_size </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ncap_size02_r_t
 *
 * Implemented by: 
 *      ncap_size02
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq_size11                               :  8;
     unsigned      ipcq_size10                               :  8;
     unsigned      ipcq_size09                               :  8;
     unsigned      ipcq_size08                               :  8;
#else    /* Little Endian */
     unsigned      ipcq_size08                               :  8;
     unsigned      ipcq_size09                               :  8;
     unsigned      ipcq_size10                               :  8;
     unsigned      ipcq_size11                               :  8;
#endif
} ncp_nca_itp_ncap_size02_r_t;

/*! @struct ncp_nca_itp_ncap_size03_r_t
 *  @brief null
 *  @details multi FIFO size for each NCAP 12
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ncap_size03_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 24 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_size12 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> NCAP 12 ipcq_size </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ncap_size03_r_t
 *
 * Implemented by: 
 *      ncap_size03
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 24;
     unsigned      ipcq_size12                               :  8;
#else    /* Little Endian */
     unsigned      ipcq_size12                               :  8;
     unsigned      reserved0                                 : 24;
#endif
} ncp_nca_itp_ncap_size03_r_t;

/*! @struct ncp_nca_itp_ncap_credits00_r_t
 *  @brief null
 *  @details NLINK credits for each NCAP 0-3
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ncap_credits00_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_credits03 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> NCAP 04 ipcq_credits </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_credits02 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> NCAP 03 ipcq_credits </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_credits01 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> NCAP 02 ipcq_credits </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_credits00 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> NCAP 01 ipcq_credits </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ncap_credits00_r_t
 *
 * Implemented by: 
 *      ncap_credits00
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq_credits03                            :  8;
     unsigned      ipcq_credits02                            :  8;
     unsigned      ipcq_credits01                            :  8;
     unsigned      ipcq_credits00                            :  8;
#else    /* Little Endian */
     unsigned      ipcq_credits00                            :  8;
     unsigned      ipcq_credits01                            :  8;
     unsigned      ipcq_credits02                            :  8;
     unsigned      ipcq_credits03                            :  8;
#endif
} ncp_nca_itp_ncap_credits00_r_t;

/*! @struct ncp_nca_itp_ncap_credits01_r_t
 *  @brief null
 *  @details NLINK credits for each NCAP 4-7
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ncap_credits01_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_credits07 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> NCAP 08 ipcq_credits </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_credits06 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> NCAP 07 ipcq_credits </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_credits05 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> NCAP 06 ipcq_credits </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_credits04 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> NCAP 05 ipcq_credits </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ncap_credits01_r_t
 *
 * Implemented by: 
 *      ncap_credits01
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq_credits07                            :  8;
     unsigned      ipcq_credits06                            :  8;
     unsigned      ipcq_credits05                            :  8;
     unsigned      ipcq_credits04                            :  8;
#else    /* Little Endian */
     unsigned      ipcq_credits04                            :  8;
     unsigned      ipcq_credits05                            :  8;
     unsigned      ipcq_credits06                            :  8;
     unsigned      ipcq_credits07                            :  8;
#endif
} ncp_nca_itp_ncap_credits01_r_t;

/*! @struct ncp_nca_itp_ncap_credits02_r_t
 *  @brief null
 *  @details NLINK credits for each NCAP 8-11
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ncap_credits02_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_credits11 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> NCAP 12 ipcq_credits </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_credits10 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> NCAP 11 ipcq_credits </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_credits09 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> NCAP 10 ipcq_credits </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_credits08 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> NCAP 09 ipcq_credits </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ncap_credits02_r_t
 *
 * Implemented by: 
 *      ncap_credits02
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ipcq_credits11                            :  8;
     unsigned      ipcq_credits10                            :  8;
     unsigned      ipcq_credits09                            :  8;
     unsigned      ipcq_credits08                            :  8;
#else    /* Little Endian */
     unsigned      ipcq_credits08                            :  8;
     unsigned      ipcq_credits09                            :  8;
     unsigned      ipcq_credits10                            :  8;
     unsigned      ipcq_credits11                            :  8;
#endif
} ncp_nca_itp_ncap_credits02_r_t;

/*! @struct ncp_nca_itp_ncap_credits03_r_t
 *  @brief null
 *  @details NLINK credits for each NCAP 12
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_itp_ncap_credits03_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 24 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ipcq_credits12 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> NCAP 13 ipcq_credits </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ncap_credits03_r_t
 *
 * Implemented by: 
 *      ncap_credits03
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 24;
     unsigned      ipcq_credits12                            :  8;
#else    /* Little Endian */
     unsigned      ipcq_credits12                            :  8;
     unsigned      reserved0                                 : 24;
#endif
} ncp_nca_itp_ncap_credits03_r_t;

/*! @struct ncp_nca_itp_tpd_ram_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_itp_tpd_ram_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param reserved2 </td>
 *     <td width="20%" align="center"> 19 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1_15_3 </td>
 *     <td width="20%" align="center"> 13 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 13 bits of reserved1. reserved </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1_2_0 </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> 3 bits of reserved1. reserved </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> reserved </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement4_7 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Format Requirement 4: Allowed Pools array. bit for
 *        Shared Pool 7. 0: pool is not supported. Any task
 *        pointer using this pool will be copied. 1: pool is
 *        supported.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement4_6 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Format Requirement 4: Allowed Pools array. bit for
 *        Shared Pool 6. 0: pool is not supported. Any task
 *        pointer using this pool will be copied. 1: pool is
 *        supported.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement4_5 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Format Requirement 4: Allowed Pools array. bit for
 *        Shared Pool 5. 0: pool is not supported. Any task
 *        pointer using this pool will be copied. 1: pool is
 *        supported.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement4_4 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Format Requirement 4: Allowed Pools array. bit for
 *        Shared Pool 4. 0: pool is not supported. Any task
 *        pointer using this pool will be copied. 1: pool is
 *        supported.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement4_3 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Format Requirement 4: Allowed Pools array. bit for
 *        Shared Pool 3. 0: pool is not supported. Any task
 *        pointer using this pool will be copied. 1: pool is
 *        supported.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement4_2 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Format Requirement 4: Allowed Pools array. bit for
 *        Shared Pool 2. 0: pool is not supported. Any task
 *        pointer using this pool will be copied. 1: pool is
 *        supported.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement4_1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> Format Requirement 4: Allowed Pools array. bit for
 *        Dummy Pool. 0: pool is not supported. Any task pointer
 *        using this pool will be copied. 1: pool is supported.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement5 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Format Requirement 5: Force Copy. 0: do not force
 *        copy. 1: force any task on this TQ to be copied.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement3 </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Format Requirement 3: Seperation </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement2 </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Format Requirement 2: Continuous </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Format Requirement 1: Modifiable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> Format Requirement 0: Header seperate. 0: tak header
 *        is written into the the head of the first task pointer.
 *        1: task header is written in the head of a new, seperate
 *        7th pointer
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param size </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> size of header seperate blocks </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param copypool </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> pool to copy into if Format Requirement is violated </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param endianparameter </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Endian Foramt of CPU task header paramters. 0:big
 *        1:little
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param endiantaskdata </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Endian Foramt of CPU task header 1:big 0:little </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param orparam </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Reserved For Hardware. write TQ sequence into task
 *        paramter bytes 28,29,30
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved3 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param virtualregion </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> The virtual region of the TQ. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param generation </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Generation bit. This bit is transfered to the iPCQ
 *        task entry and CPU header in the ID field bit[15].
 *        This is used by SW to determine when all of the tasks
 *        from a previous generation (prior to reconfigure a
 *        GID) are exhausted. SW will toggle as GID is reconfigured
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param traceordered </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> enable tracing </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param online </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> The TQ is online and can processes tasks from COW. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param priority </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> The priority of the TQ </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The Group ID (GID) associated with the TQ. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param class </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> The type of task processed on TQ. 0:unordered 1:ordered
 *        2:unscheduled
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_tpd_ram_r_t
 *
 * Implemented by: 
 *      tpd_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved2                                 : 19;
     unsigned      reserved1_15_3                            : 13;
          /* word 1 */
     unsigned      reserved1_2_0                             :  3;
     unsigned      reserved0                                 :  5;
     unsigned      formatrequirement4_7                      :  1;
     unsigned      formatrequirement4_6                      :  1;
     unsigned      formatrequirement4_5                      :  1;
     unsigned      formatrequirement4_4                      :  1;
     unsigned      formatrequirement4_3                      :  1;
     unsigned      formatrequirement4_2                      :  1;
     unsigned      formatrequirement4_1                      :  1;
     unsigned      formatrequirement5                        :  1;
     unsigned      formatrequirement3                        : 16;
          /* word 2 */
     unsigned      formatrequirement2                        : 16;
     unsigned      formatrequirement1                        : 16;
          /* word 3 */
     unsigned      formatrequirement0                        :  1;
     unsigned      size                                      :  2;
     unsigned      copypool                                  :  5;
     unsigned      endianparameter                           :  1;
     unsigned      endiantaskdata                            :  1;
     unsigned      orparam                                   :  1;
     unsigned      reserved3                                 :  1;
     unsigned      virtualregion                             :  4;
     unsigned      generation                                :  1;
     unsigned      traceordered                              :  1;
     unsigned      online                                    :  1;
     unsigned      priority                                  :  3;
     unsigned      gid                                       :  8;
     unsigned      class                                     :  2;
#else    /* Little Endian */
          /* word 0 */
     unsigned      reserved1_15_3                            : 13;
     unsigned      reserved2                                 : 19;
          /* word 1 */
     unsigned      formatrequirement3                        : 16;
     unsigned      formatrequirement5                        :  1;
     unsigned      formatrequirement4_1                      :  1;
     unsigned      formatrequirement4_2                      :  1;
     unsigned      formatrequirement4_3                      :  1;
     unsigned      formatrequirement4_4                      :  1;
     unsigned      formatrequirement4_5                      :  1;
     unsigned      formatrequirement4_6                      :  1;
     unsigned      formatrequirement4_7                      :  1;
     unsigned      reserved0                                 :  5;
     unsigned      reserved1_2_0                             :  3;
          /* word 2 */
     unsigned      formatrequirement1                        : 16;
     unsigned      formatrequirement2                        : 16;
          /* word 3 */
     unsigned      class                                     :  2;
     unsigned      gid                                       :  8;
     unsigned      priority                                  :  3;
     unsigned      online                                    :  1;
     unsigned      traceordered                              :  1;
     unsigned      generation                                :  1;
     unsigned      virtualregion                             :  4;
     unsigned      reserved3                                 :  1;
     unsigned      orparam                                   :  1;
     unsigned      endiantaskdata                            :  1;
     unsigned      endianparameter                           :  1;
     unsigned      copypool                                  :  5;
     unsigned      size                                      :  2;
     unsigned      formatrequirement0                        :  1;
#endif
} ncp_nca_itp_tpd_ram_r_t;

/*! @struct ncp_nca_itp_addrconvert_poolbaseindex_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_itp_addrconvert_poolbaseindex_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_107_76 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_75_44 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_43_12 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_11_0 </td>
 *     <td width="20%" align="center"> 12 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> 12 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param poolmaxindex_35_16 </td>
 *     <td width="20%" align="center"> 20 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 20 bits of poolmaxindex. POOL maximum indedx. This
 *        is the maximum index of the pool
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param poolmaxindex_15_0 </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> 16 bits of poolmaxindex. POOL maximum indedx. This
 *        is the maximum index of the pool
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param poolbaseindex256_27_12 </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 16 bits of poolbaseindex256. POOL 256 data block size
 *        base index. This is the starting index of the 256B
 *        memory space of the pool. This is the most significant
 *        28b of the index base, bits 35:8
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param poolbaseindex256_11_0 </td>
 *     <td width="20%" align="center"> 12 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> 12 bits of poolbaseindex256. POOL 256 data block size
 *        base index. This is the starting index of the 256B
 *        memory space of the pool. This is the most significant
 *        28b of the index base, bits 35:8
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param poolbaseindex2k_27_8 </td>
 *     <td width="20%" align="center"> 20 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 20 bits of poolbaseindex2k. POOL 2k data block size
 *        base index. This is the starting index of the 2k memory
 *        space of the pool. This is the most significant 28b
 *        of the index base, bits 35:8
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param poolbaseindex2k_7_0 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> 8 bits of poolbaseindex2k. POOL 2k data block size
 *        base index. This is the starting index of the 2k memory
 *        space of the pool. This is the most significant 28b
 *        of the index base, bits 35:8
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param poolbaseindex16k_27_4 </td>
 *     <td width="20%" align="center"> 24 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 24 bits of poolbaseindex16k. POOL 16k data block size
 *        base index. This is the starting index of the 16k
 *        memory space of the pool. This is the most significant
 *        28b of the index base, bits 35:8
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param poolbaseindex16k_3_0 </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> 4 bits of poolbaseindex16k. POOL 16k data block size
 *        base index. This is the starting index of the 16k
 *        memory space of the pool. This is the most significant
 *        28b of the index base, bits 35:8
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param poolbaseindex64k </td>
 *     <td width="20%" align="center"> 28 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> POOL 64k data block size base index. This is the starting
 *        index of the 64k memory space of the pool. This is
 *        the most significant 28b of the index base, bits 35:8
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_addrconvert_poolbaseindex_r_t
 *
 * Implemented by: 
 *      addrconvert_in_poolbaseindex
 *      addrconvert_copy_poolbaseindex
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0_107_76                          : 32;
          /* word 1 */
     unsigned      reserved0_75_44                           : 32;
          /* word 2 */
     unsigned      reserved0_43_12                           : 32;
          /* word 3 */
     unsigned      reserved0_11_0                            : 12;
     unsigned      poolmaxindex_35_16                        : 20;
          /* word 4 */
     unsigned      poolmaxindex_15_0                         : 16;
     unsigned      poolbaseindex256_27_12                    : 16;
          /* word 5 */
     unsigned      poolbaseindex256_11_0                     : 12;
     unsigned      poolbaseindex2k_27_8                      : 20;
          /* word 6 */
     unsigned      poolbaseindex2k_7_0                       :  8;
     unsigned      poolbaseindex16k_27_4                     : 24;
          /* word 7 */
     unsigned      poolbaseindex16k_3_0                      :  4;
     unsigned      poolbaseindex64k                          : 28;
#else    /* Little Endian */
          /* word 0 */
     unsigned      reserved0_107_76                          : 32;
          /* word 1 */
     unsigned      reserved0_75_44                           : 32;
          /* word 2 */
     unsigned      reserved0_43_12                           : 32;
          /* word 3 */
     unsigned      poolmaxindex_35_16                        : 20;
     unsigned      reserved0_11_0                            : 12;
          /* word 4 */
     unsigned      poolbaseindex256_27_12                    : 16;
     unsigned      poolmaxindex_15_0                         : 16;
          /* word 5 */
     unsigned      poolbaseindex2k_27_8                      : 20;
     unsigned      poolbaseindex256_11_0                     : 12;
          /* word 6 */
     unsigned      poolbaseindex16k_27_4                     : 24;
     unsigned      poolbaseindex2k_7_0                       :  8;
          /* word 7 */
     unsigned      poolbaseindex64k                          : 28;
     unsigned      poolbaseindex16k_3_0                      :  4;
#endif
} ncp_nca_itp_addrconvert_poolbaseindex_r_t;

/*! @struct ncp_nca_itp_addrconvert_virtualbase_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_itp_addrconvert_virtualbase_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param poolbase_63_32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of poolbase. This is the pool virtual base
 *        address used to convert between VA and VI.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param poolbase_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of poolbase. This is the pool virtual base
 *        address used to convert between VA and VI.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_addrconvert_virtualbase_r_t
 *
 * Implemented by: 
 *      addrconvert_in_virtualbase
 *      addrconvert_copy_virtualbase
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      poolbase_63_32                            : 32;
          /* word 1 */
     unsigned      poolbase_31_0                             : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      poolbase_63_32                            : 32;
          /* word 1 */
     unsigned      poolbase_31_0                             : 32;
#endif
} ncp_nca_itp_addrconvert_virtualbase_r_t;

/*! @struct ncp_nca_itp_ncap2ipcq_ram_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_itp_ncap2ipcq_ram_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_41_10 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_9_0 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> 10 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data_85_64 </td>
 *     <td width="20%" align="center"> 22 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 22 bits of data. per NCAP bit aray of iPCQ valid for
 *        the NCAP
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data_63_32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of data. per NCAP bit aray of iPCQ valid for
 *        the NCAP
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of data. per NCAP bit aray of iPCQ valid for
 *        the NCAP
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ncap2ipcq_ram_r_t
 *
 * Implemented by: 
 *      ncap2ipcq_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0_41_10                           : 32;
          /* word 1 */
     unsigned      reserved0_9_0                             : 10;
     unsigned      data_85_64                                : 22;
          /* word 2 */
     unsigned      data_63_32                                : 32;
          /* word 3 */
     unsigned      data_31_0                                 : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      reserved0_41_10                           : 32;
          /* word 1 */
     unsigned      data_85_64                                : 22;
     unsigned      reserved0_9_0                             : 10;
          /* word 2 */
     unsigned      data_63_32                                : 32;
          /* word 3 */
     unsigned      data_31_0                                 : 32;
#endif
} ncp_nca_itp_ncap2ipcq_ram_r_t;

/*! @struct ncp_nca_itp_fifo_cfg_ram_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_itp_fifo_cfg_ram_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 28 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_base_8_5 </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 4 bits of fifo_base. FIFO Base Address </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_base_4_0 </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> 5 bits of fifo_base. FIFO Base Address </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_size </td>
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> FIFO Size </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_high_wm </td>
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> FIFO High Watermark </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_low_wm </td>
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> FIFO Low Watermark </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_fifo_cfg_ram_r_t
 *
 * Implemented by: 
 *      multi_output_fifo_cfg_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0                                 : 28;
     unsigned      fifo_base_8_5                             :  4;
          /* word 1 */
     unsigned      fifo_base_4_0                             :  5;
     unsigned      fifo_size                                 :  9;
     unsigned      fifo_high_wm                              :  9;
     unsigned      fifo_low_wm                               :  9;
#else    /* Little Endian */
          /* word 0 */
     unsigned      fifo_base_8_5                             :  4;
     unsigned      reserved0                                 : 28;
          /* word 1 */
     unsigned      fifo_low_wm                               :  9;
     unsigned      fifo_high_wm                              :  9;
     unsigned      fifo_size                                 :  9;
     unsigned      fifo_base_4_0                             :  5;
#endif
} ncp_nca_itp_fifo_cfg_ram_r_t;

/*! @struct ncp_nca_itp_fifo_data_ram_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_itp_fifo_data_ram_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data_245_224 </td>
 *     <td width="20%" align="center"> 22 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 22 bits of data. data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data_223_192 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of data. data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data_191_160 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of data. data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data_159_128 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of data. data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data_127_96 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of data. data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data_95_64 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of data. data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data_63_32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of data. data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of data. data </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_fifo_data_ram_r_t
 *
 * Implemented by: 
 *      multi_ouptut_fifo_data_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0                                 : 10;
     unsigned      data_245_224                              : 22;
          /* word 1 */
     unsigned      data_223_192                              : 32;
          /* word 2 */
     unsigned      data_191_160                              : 32;
          /* word 3 */
     unsigned      data_159_128                              : 32;
          /* word 4 */
     unsigned      data_127_96                               : 32;
          /* word 5 */
     unsigned      data_95_64                                : 32;
          /* word 6 */
     unsigned      data_63_32                                : 32;
          /* word 7 */
     unsigned      data_31_0                                 : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      data_245_224                              : 22;
     unsigned      reserved0                                 : 10;
          /* word 1 */
     unsigned      data_223_192                              : 32;
          /* word 2 */
     unsigned      data_191_160                              : 32;
          /* word 3 */
     unsigned      data_159_128                              : 32;
          /* word 4 */
     unsigned      data_127_96                               : 32;
          /* word 5 */
     unsigned      data_95_64                                : 32;
          /* word 6 */
     unsigned      data_63_32                                : 32;
          /* word 7 */
     unsigned      data_31_0                                 : 32;
#endif
} ncp_nca_itp_fifo_data_ram_r_t;

/*! @struct ncp_nca_itp_ipd_ram_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_itp_ipd_ram_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid7_enable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> GID7 enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid7_pri </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> GID7 priority </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid7 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> GID7 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid6_enable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> GID6 enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid6_pri </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> GID6 priority </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid6 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> GID6 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid5_enable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> GID5 enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid5_pri </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> GID5 priority </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid5 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> GID5 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid4_enable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> GID4 enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid4_pri </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> GID4 priority </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid4 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> GID4 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid3_enable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> GID3 enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid3_pri </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> GID3 priority </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid3_7_4 </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 4 bits of Gid3. GID3 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid3_3_0 </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> 4 bits of Gid3. GID3 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid2_enable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> GID2 enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid2_pri </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> GID2 priority </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid2 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> GID2 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid1_enable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> GID1 enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid1_pri </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> GID1 priority </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> GID1 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid0_enable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> GID0 enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid0_pri </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> GID0 priority </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid0 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> GID0 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param mqg </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> MQG </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param threshold </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> threshold </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pgit </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> PGIT. Specify which NLINK.NCAP.PGIT to assign iPCQ </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ncapaddr </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> NCAP address. Specify which NLINK.NCAP to assign iPCQ </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipd_ram_r_t
 *
 * Implemented by: 
 *      ipd_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0                                 :  8;
     unsigned      gid7_enable                               :  1;
     unsigned      gid7_pri                                  :  3;
     unsigned      gid7                                      :  8;
     unsigned      gid6_enable                               :  1;
     unsigned      gid6_pri                                  :  3;
     unsigned      gid6                                      :  8;
          /* word 1 */
     unsigned      gid5_enable                               :  1;
     unsigned      gid5_pri                                  :  3;
     unsigned      gid5                                      :  8;
     unsigned      gid4_enable                               :  1;
     unsigned      gid4_pri                                  :  3;
     unsigned      gid4                                      :  8;
     unsigned      gid3_enable                               :  1;
     unsigned      gid3_pri                                  :  3;
     unsigned      gid3_7_4                                  :  4;
          /* word 2 */
     unsigned      gid3_3_0                                  :  4;
     unsigned      gid2_enable                               :  1;
     unsigned      gid2_pri                                  :  3;
     unsigned      gid2                                      :  8;
     unsigned      gid1_enable                               :  1;
     unsigned      gid1_pri                                  :  3;
     unsigned      gid1                                      :  8;
     unsigned      gid0_enable                               :  1;
     unsigned      gid0_pri                                  :  3;
          /* word 3 */
     unsigned      gid0                                      :  8;
     unsigned      reserved1                                 :  4;
     unsigned      mqg                                       :  5;
     unsigned      threshold                                 :  8;
     unsigned      pgit                                      :  3;
     unsigned      ncapaddr                                  :  4;
#else    /* Little Endian */
          /* word 0 */
     unsigned      gid6                                      :  8;
     unsigned      gid6_pri                                  :  3;
     unsigned      gid6_enable                               :  1;
     unsigned      gid7                                      :  8;
     unsigned      gid7_pri                                  :  3;
     unsigned      gid7_enable                               :  1;
     unsigned      reserved0                                 :  8;
          /* word 1 */
     unsigned      gid3_7_4                                  :  4;
     unsigned      gid3_pri                                  :  3;
     unsigned      gid3_enable                               :  1;
     unsigned      gid4                                      :  8;
     unsigned      gid4_pri                                  :  3;
     unsigned      gid4_enable                               :  1;
     unsigned      gid5                                      :  8;
     unsigned      gid5_pri                                  :  3;
     unsigned      gid5_enable                               :  1;
          /* word 2 */
     unsigned      gid0_pri                                  :  3;
     unsigned      gid0_enable                               :  1;
     unsigned      gid1                                      :  8;
     unsigned      gid1_pri                                  :  3;
     unsigned      gid1_enable                               :  1;
     unsigned      gid2                                      :  8;
     unsigned      gid2_pri                                  :  3;
     unsigned      gid2_enable                               :  1;
     unsigned      gid3_3_0                                  :  4;
          /* word 3 */
     unsigned      ncapaddr                                  :  4;
     unsigned      pgit                                      :  3;
     unsigned      threshold                                 :  8;
     unsigned      mqg                                       :  5;
     unsigned      reserved1                                 :  4;
     unsigned      gid0                                      :  8;
#endif
} ncp_nca_itp_ipd_ram_r_t;

/*! @struct ncp_nca_itp_gid2tq_ram_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_itp_gid2tq_ram_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_51_20 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_19_0 </td>
 *     <td width="20%" align="center"> 20 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> 20 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data_203_192 </td>
 *     <td width="20%" align="center"> 12 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 12 bits of data. per GID bit aray of TQ valid for
 *        the GID
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data_191_160 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of data. per GID bit aray of TQ valid for
 *        the GID
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data_159_128 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of data. per GID bit aray of TQ valid for
 *        the GID
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data_127_96 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of data. per GID bit aray of TQ valid for
 *        the GID
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data_95_64 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of data. per GID bit aray of TQ valid for
 *        the GID
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data_63_32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of data. per GID bit aray of TQ valid for
 *        the GID
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of data. per GID bit aray of TQ valid for
 *        the GID
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_gid2tq_ram_r_t
 *
 * Implemented by: 
 *      gid2tq_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0_51_20                           : 32;
          /* word 1 */
     unsigned      reserved0_19_0                            : 20;
     unsigned      data_203_192                              : 12;
          /* word 2 */
     unsigned      data_191_160                              : 32;
          /* word 3 */
     unsigned      data_159_128                              : 32;
          /* word 4 */
     unsigned      data_127_96                               : 32;
          /* word 5 */
     unsigned      data_95_64                                : 32;
          /* word 6 */
     unsigned      data_63_32                                : 32;
          /* word 7 */
     unsigned      data_31_0                                 : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      reserved0_51_20                           : 32;
          /* word 1 */
     unsigned      data_203_192                              : 12;
     unsigned      reserved0_19_0                            : 20;
          /* word 2 */
     unsigned      data_191_160                              : 32;
          /* word 3 */
     unsigned      data_159_128                              : 32;
          /* word 4 */
     unsigned      data_127_96                               : 32;
          /* word 5 */
     unsigned      data_95_64                                : 32;
          /* word 6 */
     unsigned      data_63_32                                : 32;
          /* word 7 */
     unsigned      data_31_0                                 : 32;
#endif
} ncp_nca_itp_gid2tq_ram_r_t;

/*! @struct ncp_nca_itp_ram_ieordered_ram_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_itp_ram_ieordered_ram_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_83_52 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_51_20 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_19_0 </td>
 *     <td width="20%" align="center"> 20 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> 20 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_enqcount0 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> def_ieord_state_enqcount0 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_schcount0_9_8 </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 2 bits of def_ieord_state_schcount0. def_ieord_state_schcount0 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_schcount0_7_0 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> 8 bits of def_ieord_state_schcount0. def_ieord_state_schcount0 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_enqcount1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> def_ieord_state_enqcount1 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_schcount1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> def_ieord_state_schcount1 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_enqcount2_9_6 </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 4 bits of def_ieord_state_enqcount2. def_ieord_state_enqcount2 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_enqcount2_5_0 </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> 6 bits of def_ieord_state_enqcount2. def_ieord_state_enqcount2 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_schcount2 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> def_ieord_state_schcount2 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_enqcount3 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> def_ieord_state_enqcount3 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_schcount3_9_4 </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 6 bits of def_ieord_state_schcount3. def_ieord_state_schcount3 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_schcount3_3_0 </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> 4 bits of def_ieord_state_schcount3. def_ieord_state_schcount3 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_enqcount4 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> def_ieord_state_enqcount4 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_schcount4 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> def_ieord_state_schcount4 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_enqcount5_9_2 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 8 bits of def_ieord_state_enqcount5. def_ieord_state_enqcount5 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_enqcount5_1_0 </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> 2 bits of def_ieord_state_enqcount5. def_ieord_state_enqcount5 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_schcount5 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> def_ieord_state_schcount5 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_enqcount6 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> def_ieord_state_enqcount6 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_schcount6 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> def_ieord_state_schcount6 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_enqcount7 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> def_ieord_state_enqcount7 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_schcount7 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> def_ieord_state_schcount7 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_state </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> def_ieord_state_state </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_ipcqpri </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> def_ieord_state_ipcqpri </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param def_ieord_state_ipcq </td>
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> def_ieord_state_ipcq </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ram_ieordered_ram_r_t
 *
 * Implemented by: 
 *      ram_ieordered_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0_83_52                           : 32;
          /* word 1 */
     unsigned      reserved0_51_20                           : 32;
          /* word 2 */
     unsigned      reserved0_19_0                            : 20;
     unsigned      def_ieord_state_enqcount0                 : 10;
     unsigned      def_ieord_state_schcount0_9_8             :  2;
          /* word 3 */
     unsigned      def_ieord_state_schcount0_7_0             :  8;
     unsigned      def_ieord_state_enqcount1                 : 10;
     unsigned      def_ieord_state_schcount1                 : 10;
     unsigned      def_ieord_state_enqcount2_9_6             :  4;
          /* word 4 */
     unsigned      def_ieord_state_enqcount2_5_0             :  6;
     unsigned      def_ieord_state_schcount2                 : 10;
     unsigned      def_ieord_state_enqcount3                 : 10;
     unsigned      def_ieord_state_schcount3_9_4             :  6;
          /* word 5 */
     unsigned      def_ieord_state_schcount3_3_0             :  4;
     unsigned      def_ieord_state_enqcount4                 : 10;
     unsigned      def_ieord_state_schcount4                 : 10;
     unsigned      def_ieord_state_enqcount5_9_2             :  8;
          /* word 6 */
     unsigned      def_ieord_state_enqcount5_1_0             :  2;
     unsigned      def_ieord_state_schcount5                 : 10;
     unsigned      def_ieord_state_enqcount6                 : 10;
     unsigned      def_ieord_state_schcount6                 : 10;
          /* word 7 */
     unsigned      def_ieord_state_enqcount7                 : 10;
     unsigned      def_ieord_state_schcount7                 : 10;
     unsigned      def_ieord_state_state                     :  2;
     unsigned      def_ieord_state_ipcqpri                   :  3;
     unsigned      def_ieord_state_ipcq                      :  7;
#else    /* Little Endian */
          /* word 0 */
     unsigned      reserved0_83_52                           : 32;
          /* word 1 */
     unsigned      reserved0_51_20                           : 32;
          /* word 2 */
     unsigned      def_ieord_state_schcount0_9_8             :  2;
     unsigned      def_ieord_state_enqcount0                 : 10;
     unsigned      reserved0_19_0                            : 20;
          /* word 3 */
     unsigned      def_ieord_state_enqcount2_9_6             :  4;
     unsigned      def_ieord_state_schcount1                 : 10;
     unsigned      def_ieord_state_enqcount1                 : 10;
     unsigned      def_ieord_state_schcount0_7_0             :  8;
          /* word 4 */
     unsigned      def_ieord_state_schcount3_9_4             :  6;
     unsigned      def_ieord_state_enqcount3                 : 10;
     unsigned      def_ieord_state_schcount2                 : 10;
     unsigned      def_ieord_state_enqcount2_5_0             :  6;
          /* word 5 */
     unsigned      def_ieord_state_enqcount5_9_2             :  8;
     unsigned      def_ieord_state_schcount4                 : 10;
     unsigned      def_ieord_state_enqcount4                 : 10;
     unsigned      def_ieord_state_schcount3_3_0             :  4;
          /* word 6 */
     unsigned      def_ieord_state_schcount6                 : 10;
     unsigned      def_ieord_state_enqcount6                 : 10;
     unsigned      def_ieord_state_schcount5                 : 10;
     unsigned      def_ieord_state_enqcount5_1_0             :  2;
          /* word 7 */
     unsigned      def_ieord_state_ipcq                      :  7;
     unsigned      def_ieord_state_ipcqpri                   :  3;
     unsigned      def_ieord_state_state                     :  2;
     unsigned      def_ieord_state_schcount7                 : 10;
     unsigned      def_ieord_state_enqcount7                 : 10;
#endif
} ncp_nca_itp_ram_ieordered_ram_r_t;

/*! @struct ncp_nca_itp_ll_preproc_allocate_ram_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_itp_ll_preproc_allocate_ram_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_252_221 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_220_189 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_188_157 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_156_125 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_124_93 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_92_61 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_60_29 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_28_0 </td>
 *     <td width="20%" align="center"> 29 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> 29 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_258_256 </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 3 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_255_224 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_223_192 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_191_160 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_159_128 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_127_96 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_95_64 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_63_32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_preproc_allocate_ram_r_t
 *
 * Implemented by: 
 *      ll_preproc_allocate_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0_252_221                         : 32;
          /* word 1 */
     unsigned      reserved0_220_189                         : 32;
          /* word 2 */
     unsigned      reserved0_188_157                         : 32;
          /* word 3 */
     unsigned      reserved0_156_125                         : 32;
          /* word 4 */
     unsigned      reserved0_124_93                          : 32;
          /* word 5 */
     unsigned      reserved0_92_61                           : 32;
          /* word 6 */
     unsigned      reserved0_60_29                           : 32;
          /* word 7 */
     unsigned      reserved0_28_0                            : 29;
     unsigned      allocatedata_258_256                      :  3;
          /* word 8 */
     unsigned      allocatedata_255_224                      : 32;
          /* word 9 */
     unsigned      allocatedata_223_192                      : 32;
          /* word 10 */
     unsigned      allocatedata_191_160                      : 32;
          /* word 11 */
     unsigned      allocatedata_159_128                      : 32;
          /* word 12 */
     unsigned      allocatedata_127_96                       : 32;
          /* word 13 */
     unsigned      allocatedata_95_64                        : 32;
          /* word 14 */
     unsigned      allocatedata_63_32                        : 32;
          /* word 15 */
     unsigned      allocatedata_31_0                         : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      reserved0_252_221                         : 32;
          /* word 1 */
     unsigned      reserved0_220_189                         : 32;
          /* word 2 */
     unsigned      reserved0_188_157                         : 32;
          /* word 3 */
     unsigned      reserved0_156_125                         : 32;
          /* word 4 */
     unsigned      reserved0_124_93                          : 32;
          /* word 5 */
     unsigned      reserved0_92_61                           : 32;
          /* word 6 */
     unsigned      reserved0_60_29                           : 32;
          /* word 7 */
     unsigned      allocatedata_258_256                      :  3;
     unsigned      reserved0_28_0                            : 29;
          /* word 8 */
     unsigned      allocatedata_255_224                      : 32;
          /* word 9 */
     unsigned      allocatedata_223_192                      : 32;
          /* word 10 */
     unsigned      allocatedata_191_160                      : 32;
          /* word 11 */
     unsigned      allocatedata_159_128                      : 32;
          /* word 12 */
     unsigned      allocatedata_127_96                       : 32;
          /* word 13 */
     unsigned      allocatedata_95_64                        : 32;
          /* word 14 */
     unsigned      allocatedata_63_32                        : 32;
          /* word 15 */
     unsigned      allocatedata_31_0                         : 32;
#endif
} ncp_nca_itp_ll_preproc_allocate_ram_r_t;

/*! @struct ncp_nca_itp_ll_ieunord_allocate_ram_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_itp_ll_ieunord_allocate_ram_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_245_224 </td>
 *     <td width="20%" align="center"> 22 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 22 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_223_192 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_191_160 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_159_128 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_127_96 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_95_64 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_63_32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_ieunord_allocate_ram_r_t
 *
 * Implemented by: 
 *      ll_ieunord_allocate_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0                                 : 10;
     unsigned      allocatedata_245_224                      : 22;
          /* word 1 */
     unsigned      allocatedata_223_192                      : 32;
          /* word 2 */
     unsigned      allocatedata_191_160                      : 32;
          /* word 3 */
     unsigned      allocatedata_159_128                      : 32;
          /* word 4 */
     unsigned      allocatedata_127_96                       : 32;
          /* word 5 */
     unsigned      allocatedata_95_64                        : 32;
          /* word 6 */
     unsigned      allocatedata_63_32                        : 32;
          /* word 7 */
     unsigned      allocatedata_31_0                         : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      allocatedata_245_224                      : 22;
     unsigned      reserved0                                 : 10;
          /* word 1 */
     unsigned      allocatedata_223_192                      : 32;
          /* word 2 */
     unsigned      allocatedata_191_160                      : 32;
          /* word 3 */
     unsigned      allocatedata_159_128                      : 32;
          /* word 4 */
     unsigned      allocatedata_127_96                       : 32;
          /* word 5 */
     unsigned      allocatedata_95_64                        : 32;
          /* word 6 */
     unsigned      allocatedata_63_32                        : 32;
          /* word 7 */
     unsigned      allocatedata_31_0                         : 32;
#endif
} ncp_nca_itp_ll_ieunord_allocate_ram_r_t;

/*! @struct ncp_nca_itp_ll_ieord_allocate_ram_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_itp_ll_ieord_allocate_ram_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_245_224 </td>
 *     <td width="20%" align="center"> 22 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 22 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_223_192 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_191_160 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_159_128 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_127_96 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_95_64 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_63_32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_ieord_allocate_ram_r_t
 *
 * Implemented by: 
 *      ll_ieord_allocate_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0                                 : 10;
     unsigned      allocatedata_245_224                      : 22;
          /* word 1 */
     unsigned      allocatedata_223_192                      : 32;
          /* word 2 */
     unsigned      allocatedata_191_160                      : 32;
          /* word 3 */
     unsigned      allocatedata_159_128                      : 32;
          /* word 4 */
     unsigned      allocatedata_127_96                       : 32;
          /* word 5 */
     unsigned      allocatedata_95_64                        : 32;
          /* word 6 */
     unsigned      allocatedata_63_32                        : 32;
          /* word 7 */
     unsigned      allocatedata_31_0                         : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      allocatedata_245_224                      : 22;
     unsigned      reserved0                                 : 10;
          /* word 1 */
     unsigned      allocatedata_223_192                      : 32;
          /* word 2 */
     unsigned      allocatedata_191_160                      : 32;
          /* word 3 */
     unsigned      allocatedata_159_128                      : 32;
          /* word 4 */
     unsigned      allocatedata_127_96                       : 32;
          /* word 5 */
     unsigned      allocatedata_95_64                        : 32;
          /* word 6 */
     unsigned      allocatedata_63_32                        : 32;
          /* word 7 */
     unsigned      allocatedata_31_0                         : 32;
#endif
} ncp_nca_itp_ll_ieord_allocate_ram_r_t;

/*! @struct ncp_nca_itp_ll_completion_state_ram_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_itp_ll_completion_state_ram_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 30 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param count_10_10 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 1 bits of count. count </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param count_9_0 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> 10 bits of count. count </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param tp </td>
 *     <td width="20%" align="center"> 11 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> tp </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp </td>
 *     <td width="20%" align="center"> 11 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> hp </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_completion_state_ram_r_t
 *
 * Implemented by: 
 *      ll_completion_state_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0                                 : 30;
     unsigned      valid                                     :  1;
     unsigned      count_10_10                               :  1;
          /* word 1 */
     unsigned      count_9_0                                 : 10;
     unsigned      tp                                        : 11;
     unsigned      hp                                        : 11;
#else    /* Little Endian */
          /* word 0 */
     unsigned      count_10_10                               :  1;
     unsigned      valid                                     :  1;
     unsigned      reserved0                                 : 30;
          /* word 1 */
     unsigned      hp                                        : 11;
     unsigned      tp                                        : 11;
     unsigned      count_9_0                                 : 10;
#endif
} ncp_nca_itp_ll_completion_state_ram_r_t;

/*! @struct ncp_nca_itp_ll_completion_allocate_ram_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_itp_ll_completion_allocate_ram_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_43_12 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_11_0 </td>
 *     <td width="20%" align="center"> 12 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> 12 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_83_64 </td>
 *     <td width="20%" align="center"> 20 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 20 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_63_32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ll_completion_allocate_ram_r_t
 *
 * Implemented by: 
 *      ll_completion_allocate_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0_43_12                           : 32;
          /* word 1 */
     unsigned      reserved0_11_0                            : 12;
     unsigned      allocatedata_83_64                        : 20;
          /* word 2 */
     unsigned      allocatedata_63_32                        : 32;
          /* word 3 */
     unsigned      allocatedata_31_0                         : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      reserved0_43_12                           : 32;
          /* word 1 */
     unsigned      allocatedata_83_64                        : 20;
     unsigned      reserved0_11_0                            : 12;
          /* word 2 */
     unsigned      allocatedata_63_32                        : 32;
          /* word 3 */
     unsigned      allocatedata_31_0                         : 32;
#endif
} ncp_nca_itp_ll_completion_allocate_ram_r_t;

/*! @struct ncp_nca_itp_tpdq_ram_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_itp_tpdq_ram_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param reserved2 </td>
 *     <td width="20%" align="center"> 19 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1_15_3 </td>
 *     <td width="20%" align="center"> 13 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 13 bits of reserved1. reserved </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1_2_0 </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> 3 bits of reserved1. reserved </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param mqg </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> QPM MQG </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement4_7 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Format Requirement 4: Allowed Pools array. bit for
 *        Shared Pool 7. 0: pool is not supported. Any task
 *        pointer using this pool will be copied. 1: pool is
 *        supported.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement4_6 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Format Requirement 4: Allowed Pools array. bit for
 *        Shared Pool 6. 0: pool is not supported. Any task
 *        pointer using this pool will be copied. 1: pool is
 *        supported.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement4_5 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Format Requirement 4: Allowed Pools array. bit for
 *        Shared Pool 5. 0: pool is not supported. Any task
 *        pointer using this pool will be copied. 1: pool is
 *        supported.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement4_4 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Format Requirement 4: Allowed Pools array. bit for
 *        Shared Pool 4. 0: pool is not supported. Any task
 *        pointer using this pool will be copied. 1: pool is
 *        supported.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement4_3 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Format Requirement 4: Allowed Pools array. bit for
 *        Shared Pool 3. 0: pool is not supported. Any task
 *        pointer using this pool will be copied. 1: pool is
 *        supported.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement4_2 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Format Requirement 4: Allowed Pools array. bit for
 *        Shared Pool 2. 0: pool is not supported. Any task
 *        pointer using this pool will be copied. 1: pool is
 *        supported.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement4_1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> Format Requirement 4: Allowed Pools array. bit for
 *        Dummy Pool. 0: pool is not supported. Any task pointer
 *        using this pool will be copied. 1: pool is supported.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement5 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Format Requirement 5: Force Copy. 0: do not force
 *        copy. 1: force any task on this TQ to be copied.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement3 </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Format Requirement 3: Seperation. amount of bytes
 *        that are unused after the task header (when applicable)
 *        and before the start of packet data
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement2 </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Format Requirement 2: Continuous. amount of bytes
 *        from the start of packet which must exist in a single
 *        data block
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Format Requirement 1: Modifiable. amount of bytes
 *        from start of packet which must exist in data block
 *        with reference count=0 and are free to modify without
 *        making a data copy.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param formatrequirement0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> Format Requirement 0: Header seperate. 0: tak header
 *        is written into the the head of the first task pointer.
 *        1: task header is written in the head of a new, seperate
 *        7th pointer
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param size </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> size of header seperate blocks </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param copypool </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> pool to copy into if Format Requirement is violated </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param endianparameter </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Endian Foramt of CPU task header paramters. 0:big
 *        1:little
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param endiantaskdata </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Endian Foramt of CPU task header 1:big 0:little </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved3 </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param virtualregion </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> The virtual region of the TQ. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param generation </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Generation bit. This bit is transfered to the iPCQ
 *        task entry and CPU header in the ID field bit[15].
 *        This is used by SW to determine when all of the tasks
 *        from a previous generation (prior to reconfigure a
 *        GID) are exhausted. SW will toggle as GID is reconfigured
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param traceordered </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> enable tracing </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param online </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> The TQ is online and can processes tasks from COW. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param priority </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> The priority of the TQ </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gid </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The Group ID (GID) associated with the TQ. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param class </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> The type of task processed on TQ. 0:unordered 1:ordered
 *        2:unscheduled
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_tpdq_ram_r_t
 *
 * Implemented by: 
 *      tpdq_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved2                                 : 19;
     unsigned      reserved1_15_3                            : 13;
          /* word 1 */
     unsigned      reserved1_2_0                             :  3;
     unsigned      mqg                                       :  5;
     unsigned      formatrequirement4_7                      :  1;
     unsigned      formatrequirement4_6                      :  1;
     unsigned      formatrequirement4_5                      :  1;
     unsigned      formatrequirement4_4                      :  1;
     unsigned      formatrequirement4_3                      :  1;
     unsigned      formatrequirement4_2                      :  1;
     unsigned      formatrequirement4_1                      :  1;
     unsigned      formatrequirement5                        :  1;
     unsigned      formatrequirement3                        : 16;
          /* word 2 */
     unsigned      formatrequirement2                        : 16;
     unsigned      formatrequirement1                        : 16;
          /* word 3 */
     unsigned      formatrequirement0                        :  1;
     unsigned      size                                      :  2;
     unsigned      copypool                                  :  5;
     unsigned      endianparameter                           :  1;
     unsigned      endiantaskdata                            :  1;
     unsigned      reserved3                                 :  2;
     unsigned      virtualregion                             :  4;
     unsigned      generation                                :  1;
     unsigned      traceordered                              :  1;
     unsigned      online                                    :  1;
     unsigned      priority                                  :  3;
     unsigned      gid                                       :  8;
     unsigned      class                                     :  2;
#else    /* Little Endian */
          /* word 0 */
     unsigned      reserved1_15_3                            : 13;
     unsigned      reserved2                                 : 19;
          /* word 1 */
     unsigned      formatrequirement3                        : 16;
     unsigned      formatrequirement5                        :  1;
     unsigned      formatrequirement4_1                      :  1;
     unsigned      formatrequirement4_2                      :  1;
     unsigned      formatrequirement4_3                      :  1;
     unsigned      formatrequirement4_4                      :  1;
     unsigned      formatrequirement4_5                      :  1;
     unsigned      formatrequirement4_6                      :  1;
     unsigned      formatrequirement4_7                      :  1;
     unsigned      mqg                                       :  5;
     unsigned      reserved1_2_0                             :  3;
          /* word 2 */
     unsigned      formatrequirement1                        : 16;
     unsigned      formatrequirement2                        : 16;
          /* word 3 */
     unsigned      class                                     :  2;
     unsigned      gid                                       :  8;
     unsigned      priority                                  :  3;
     unsigned      online                                    :  1;
     unsigned      traceordered                              :  1;
     unsigned      generation                                :  1;
     unsigned      virtualregion                             :  4;
     unsigned      reserved3                                 :  2;
     unsigned      endiantaskdata                            :  1;
     unsigned      endianparameter                           :  1;
     unsigned      copypool                                  :  5;
     unsigned      size                                      :  2;
     unsigned      formatrequirement0                        :  1;
#endif
} ncp_nca_itp_tpdq_ram_r_t;

/*! @struct ncp_nca_itp_ipcq2gid_ram_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_itp_ipcq2gid_ram_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param gidv255to224 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> GID valid for iPCQ </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gidv223to192 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> GID valid for iPCQ </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gidv191to160 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> GID valid for iPCQ </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gidv159to128 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> GID valid for iPCQ </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gidv127to096 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> GID valid for iPCQ </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gidv095to064 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> GID valid for iPCQ </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gidv063to032 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> GID valid for iPCQ </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param gidv031to000 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> GID valid for iPCQ </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_itp_ipcq2gid_ram_r_t
 *
 * Implemented by: 
 *      ipcq2gid_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      gidv255to224                              : 32;
          /* word 1 */
     unsigned      gidv223to192                              : 32;
          /* word 2 */
     unsigned      gidv191to160                              : 32;
          /* word 3 */
     unsigned      gidv159to128                              : 32;
          /* word 4 */
     unsigned      gidv127to096                              : 32;
          /* word 5 */
     unsigned      gidv095to064                              : 32;
          /* word 6 */
     unsigned      gidv063to032                              : 32;
          /* word 7 */
     unsigned      gidv031to000                              : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      gidv255to224                              : 32;
          /* word 1 */
     unsigned      gidv223to192                              : 32;
          /* word 2 */
     unsigned      gidv191to160                              : 32;
          /* word 3 */
     unsigned      gidv159to128                              : 32;
          /* word 4 */
     unsigned      gidv127to096                              : 32;
          /* word 5 */
     unsigned      gidv095to064                              : 32;
          /* word 6 */
     unsigned      gidv063to032                              : 32;
          /* word 7 */
     unsigned      gidv031to000                              : 32;
#endif
} ncp_nca_itp_ipcq2gid_ram_r_t;

#ifdef __cplusplus
}
#endif

#endif /* _NCP_NCA_ITP_REGS_H_ */
