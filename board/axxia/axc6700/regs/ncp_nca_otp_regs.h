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


#ifndef _NCP_NCA_OTP_REGS_H_
#define _NCP_NCA_OTP_REGS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"

/*! @struct ncp_nca_otp_interface_0000_r_t
 *  @brief null
 *  @details CFG access to Interface Activity. Read the current value of interface.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_interface_0000_r_t\n
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
 *   <td width="30%"> otp_mtp_req_awvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_30 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> otp_mtp_req_awready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_29 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> otp_itp_tx_bvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_28 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> otp_itp_tx_bready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_27 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> otp_itp_tx_wvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_26 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> otp_itp_tx_wready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_25 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> otp_itp_tx_awvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_24 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> otp_itp_tx_awready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_23 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> cmn_cpcq_resp_bvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_22 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> cmn_cpcq_resp_bready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_21 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> cmn_cpcq_resp_wvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_20 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> cmn_cpcq_resp_wready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_19 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> cmn_cpcq_resp_awvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_18 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> cmn_cpcq_resp_awready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_17 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> cmn_cpcq_req_bready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_16 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> cmn_cpcq_req_bvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_15 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> cmn_cpcq_req_wvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_14 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> cmn_cpcq_req_wready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_13 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> cmn_cpcq_req_awvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_12 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> cmn_cpcq_req_awready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_11 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> tdgl_eng_bp </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_10 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> eng_tdgl_cmd_v </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_9 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> otp_system_crd_valid[1] </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_8 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> otp_system_crd_valid[0] </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_7 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> otp_system_crr_ready[1] </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_6 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> otp_system_crr_ready[0] </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_5 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> otp_system_crr_valid[1] </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_4 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> otp_system_crr_valid[0] </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_3 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> ncav3_opcq_res_awvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_2 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> ncav3_opcq_res_awready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ncav3_opcq_req_awvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ncav3_opcq_req_awready </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_interface_0000_r_t
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
     unsigned      if_9                                      :  1;
     unsigned      if_8                                      :  1;
     unsigned      if_7                                      :  1;
     unsigned      if_6                                      :  1;
     unsigned      if_5                                      :  1;
     unsigned      if_4                                      :  1;
     unsigned      if_3                                      :  1;
     unsigned      if_2                                      :  1;
     unsigned      if_1                                      :  1;
     unsigned      if_0                                      :  1;
#else    /* Little Endian */
     unsigned      if_0                                      :  1;
     unsigned      if_1                                      :  1;
     unsigned      if_2                                      :  1;
     unsigned      if_3                                      :  1;
     unsigned      if_4                                      :  1;
     unsigned      if_5                                      :  1;
     unsigned      if_6                                      :  1;
     unsigned      if_7                                      :  1;
     unsigned      if_8                                      :  1;
     unsigned      if_9                                      :  1;
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
} ncp_nca_otp_interface_0000_r_t;

/*! @struct ncp_nca_otp_interface_0020_r_t
 *  @brief null
 *  @details CFG access to Interface Activity. Read the current value of interface.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_interface_0020_r_t\n
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
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_62 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_61 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_60 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_59 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_58 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_57 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_56 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_55 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_54 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_53 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_52 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_51 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_50 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_49 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_48 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_47 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_46 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_45 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_44 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_43 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_41 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> mtp_otp_res_bvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_40 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> mtp_otp_res_bready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_39 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> mtp_otp_res_wvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_38 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> mtp_otp_res_wready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_37 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> mtp_otp_res_awvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_36 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> mtp_otp_res_awready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_35 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> otp_mtp_req_bvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_34 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> otp_mtp_req_bready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_33 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> otp_mtp_req_wvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_32 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> otp_mtp_req_wready </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_interface_0020_r_t
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
     unsigned      reserved0                                 :  1;
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
     unsigned      reserved0                                 :  1;
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
} ncp_nca_otp_interface_0020_r_t;

/*! @struct ncp_nca_otp_interface_0040_r_t
 *  @brief null
 *  @details CFG access to Interface Activity. Read the current value of interface.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_interface_0040_r_t\n
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
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_82 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_81 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_80 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_79 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_78 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_77 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_76 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_75 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_74 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_73 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_72 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_71 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_70 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_69 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_68 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_67 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_66 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_65 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param if_64 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> null </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_interface_0040_r_t
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
} ncp_nca_otp_interface_0040_r_t;

/*! @struct ncp_nca_otp_interrupt0_status_r_t
 *  @brief Interrupt Status Register
 *  @details This register holds interrupt status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_interrupt0_status_r_t\n
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
 *   <td width="30%"> oll_sndtsk_error. The SendTask oPCQ LL (sndtsk) returns
 *        an error. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int30 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> oll_rsel_error. The output LL (rsel) returns an error.
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int29 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> oll_isel_error. The Input LL (isel) returns an error.
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int28 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> addrconvert_data1_out_error. Address Convert translating
 *        the oPCQ TaskHeader pointer returns an error. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int27 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> addrconvert_data0_out_error. Address Convert translating
 *        the oPCQ TaskHeader pointer returns an error. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int26 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> addrconvert_entry_out_error. Address Convert translating
 *        the oPCQ TaskEntry pointer returns an error. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int25 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> dma_read_cpu_CFG_err. DMA engine reading task header
 *        returns an error. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int24 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> dma_read_data_CFG_err. DMA engine reading task data
 *        returns an error. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int23 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> err_teth. oPCQ TaskEntry and oPCQ TaskHeader size
 *        are inconsistent. TaskEntry.size=0 and TaskHeader=128B
 *        or TaskEntry.size=1 and TaskHeader=64B. DROP oPCQ
 *        TaskEntry. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int22 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> err_ptrcnt. oPCQ TaskHeader pointer count is illegal.
 *        DROP oPCQ TaskEntry. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int21 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> err_destipcq. oPCQ TaskEntry is confiured to use the
 *        TaskEntry.DestiPCQ field the DestiPCQ is not configured
 *        to be online. DROP oPCQ TaskEntry. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int20 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> err_illegalcmd. oPCQ TaskEntry has an illegal command.
 *        DROP oPCQ TaskEntry. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int19 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> err_pdulenmax. oPCQ TaskHeader sum of pointer length
 *        exceed maximum supported length of 63kB. DROP oPCQ
 *        TaskEntry. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int18 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> err_pdulensum. oPCQ TaskHeader sum of pointer length
 *        does not equal the TaskHeader.PduLength. DROP oPCQ
 *        TaskEntry. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int17 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> err_segsizemax. oPCQ TaskHeader conatins a pointer
 *        with a length that exceedes the size of the pointer
 *        data block. DROP oPCQ TaskEntry. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int16 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> err_segsizeis0. oPCQ TaskHeader contains a pointer
 *        with length of zero. DROP oPCQ TaskEntry. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int15 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> err_addrconvert. Address Convert module returns and
 *        error indication. DROP oPCQ TaskEntry. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int14 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> err_calculated_pdulength. The sum of oPCQ TaskHeader
 *        pointer length overflow. DROP oPCQ TaskEntry. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int13 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> err_illegalpool. oPCQ TaskHeader contains pointer
 *        with an illegal pool (0,1,24-30). DROP oPCQ TaskEntry.
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int12 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> NLINK parity error detected on task. Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int11 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> err_cpcq. Illegal cPCQ task recevied. Either CFG setup
 *        to drop cPCQ task or cPCQ.dba is illegal. DROP oPCQ
 *        TaskEntry. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int10 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> flowcontrol task command processed. Flow control task
 *        returned to NCAP. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int9 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> copy task performed. task data copied during SendTask
 *        command Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int8 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> completion task command porocessed. Task completion
 *        delivered to ITP Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int7 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> adpae task command processed. Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int6 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> adpah task command processed. Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int5 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> cpcq task command processed. Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int4 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> sndtsk task command processed. Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int3 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> noop task command processed. Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int2 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> drop task performed. Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> read_err Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> write_err Status </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_interrupt0_status_r_t
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
} ncp_nca_otp_interrupt0_status_r_t;

/*! @struct ncp_nca_otp_interrupt1_status_r_t
 *  @brief Interrupt Status Register
 *  @details This register holds interrupt status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_interrupt1_status_r_t\n
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
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int62 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int61 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> err_maxcpcq. Total number of active cPCQ task is above
 *        configured threshold control_general_01.maxcpcq. DROP
 *        oPCQ TaskEntry. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int60 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> err_split. oPCQ TaskHeader has a pointer that is split.
 *        The same pointer data block is used as multiple segments.
 *        At least one of the segments has its MREF bit set
 *        to zero. DROP oPCQ TaskEntry. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int59 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> err_hs. oPCQ TaskEntry and oPCQ TaskHeader are inconsistent.
 *        TaskEntry.H not consistent with TaskHeader.CH OR TaskEntry.pointer
 *        and TaskHEader.pointer0 are the same and TaskEntry.H=1
 *        or they are different and TaskEntry.H=0. DROP oPCQ
 *        TaskEntry. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int58 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> err_dynamic. Error obsered processing dynamic command.
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int57 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> multi_fifo_fifo_underflow Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int56 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> multi_fifo_fifo_overflow Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int55 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> COLLISION ram_odtd_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int54 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> COLLISION ram_odts_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int53 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> COLLISION addrconvert_data1_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int52 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> COLLISION addrconvert_data1_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int51 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> COLLISION addrconvert_data0_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int50 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> COLLISION addrconvert_data0_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int49 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> COLLISION addrconvert_entry_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int48 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> COLLISION addrconvert_entry_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int47 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> COLLISION ram_dma_read_cpu_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int46 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> COLLISION multi_fifo_fifo_mem_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int45 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> COLLISION multi_fifo_state_mem_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int44 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> COLLISION multi_fifo_cfg_mem_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int43 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> COLLISION oll_isel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int42 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> COLLISION oll_isel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int41 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> COLLISION oll_isel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int40 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> COLLISION oll_isel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int39 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> COLLISION oll_rsel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int38 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> COLLISION oll_rsel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int37 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> COLLISION oll_rsel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int36 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> COLLISION oll_rsel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int35 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> COLLISION oll_sndtsk_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int34 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> COLLISION oll_sndtsk_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int33 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> COLLISION oll_sndtsk_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int32 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> COLLISION oll_sndtsk_ram_error Status </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_interrupt1_status_r_t
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
} ncp_nca_otp_interrupt1_status_r_t;

/*! @struct ncp_nca_otp_interrupt2_status_r_t
 *  @brief Interrupt Status Register
 *  @details This register holds interrupt status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_interrupt2_status_r_t\n
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
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int94 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int93 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int92 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int91 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int90 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> MBE oll_isel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int89 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> SBE oll_isel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int88 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> COLLISION oll_isel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int87 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> SBE ram_odtd_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int86 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> SBE ram_odts_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int85 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> SBE addrconvert_data1_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int84 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> SBE addrconvert_data1_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int83 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> SBE addrconvert_data0_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int82 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> SBE addrconvert_data0_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int81 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> SBE addrconvert_entry_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int80 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> SBE addrconvert_entry_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int79 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> SBE ram_dma_read_cpu_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int78 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> SBE multi_fifo_fifo_mem_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int77 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> SBE multi_fifo_state_mem_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int76 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> SBE multi_fifo_cfg_mem_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int75 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> SBE oll_isel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int74 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> SBE oll_isel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int73 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> SBE oll_isel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int72 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> SBE oll_isel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int71 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> SBE oll_rsel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int70 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> SBE oll_rsel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int69 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> SBE oll_rsel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int68 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> SBE oll_rsel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int67 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> SBE oll_sndtsk_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int66 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> SBE oll_sndtsk_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int65 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> SBE oll_sndtsk_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int64 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> SBE oll_sndtsk_ram_error Status </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_interrupt2_status_r_t
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
} ncp_nca_otp_interrupt2_status_r_t;

/*! @struct ncp_nca_otp_interrupt3_status_r_t
 *  @brief Interrupt Status Register
 *  @details This register holds interrupt status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_interrupt3_status_r_t\n
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
 *   <td width="30%"> NCAV3 CFG FIFO OF Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int126 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> NCAV3 CFG FIFO UF Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int125 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int124 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int123 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int122 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int121 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int120 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int119 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> MBE ram_odtd_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int118 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> MBE ram_odts_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int117 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> MBE addrconvert_data1_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int116 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> MBE addrconvert_data1_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int115 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> MBE addrconvert_data0_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int114 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> MBE addrconvert_data0_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int113 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> MBE addrconvert_entry_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int112 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> MBE addrconvert_entry_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int111 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> MBE ram_dma_read_cpu_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int110 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> MBE multi_fifo_fifo_mem_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int109 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> MBE multi_fifo_state_mem_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int108 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> MBE multi_fifo_cfg_mem_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int107 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> MBE oll_isel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int106 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> MBE oll_isel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int105 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> MBE oll_isel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int104 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> MBE oll_isel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int103 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> MBE oll_rsel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int102 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> MBE oll_rsel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int101 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> MBE oll_rsel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int100 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> MBE oll_rsel_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int99 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> MBE oll_sndtsk_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int98 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> MBE oll_sndtsk_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int97 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> MBE oll_sndtsk_ram_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int96 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> MBE oll_sndtsk_ram_error Status </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_interrupt3_status_r_t
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
} ncp_nca_otp_interrupt3_status_r_t;

/*! @struct ncp_nca_otp_interrupt0_en_r_t
 *  @brief Interrupt Enable Register
 *  @details This register enables interrupts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_interrupt0_en_r_t\n
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
 *   <td width="30%"> oll_sndtsk_error. The SendTask oPCQ LL (sndtsk) returns
 *        an error. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int30 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> oll_rsel_error. The output LL (rsel) returns an error.
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int29 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> oll_isel_error. The Input LL (isel) returns an error.
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int28 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> addrconvert_data1_out_error. Address Convert translating
 *        the oPCQ TaskHeader pointer returns an error. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int27 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> addrconvert_data0_out_error. Address Convert translating
 *        the oPCQ TaskHeader pointer returns an error. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int26 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> addrconvert_entry_out_error. Address Convert translating
 *        the oPCQ TaskEntry pointer returns an error. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int25 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> dma_read_cpu_CFG_err. DMA engine reading task header
 *        returns an error. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int24 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> dma_read_data_CFG_err. DMA engine reading task data
 *        returns an error. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int23 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> err_teth. oPCQ TaskEntry and oPCQ TaskHeader size
 *        are inconsistent. TaskEntry.size=0 and TaskHeader=128B
 *        or TaskEntry.size=1 and TaskHeader=64B. DROP oPCQ
 *        TaskEntry. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int22 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> err_ptrcnt. oPCQ TaskHeader pointer count is illegal.
 *        DROP oPCQ TaskEntry. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int21 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> err_destipcq. oPCQ TaskEntry is confiured to use the
 *        TaskEntry.DestiPCQ field the DestiPCQ is not configured
 *        to be online. DROP oPCQ TaskEntry. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int20 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> err_illegalcmd. oPCQ TaskEntry has an illegal command.
 *        DROP oPCQ TaskEntry. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int19 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> err_pdulenmax. oPCQ TaskHeader sum of pointer length
 *        exceed maximum supported length of 63kB. DROP oPCQ
 *        TaskEntry. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int18 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> err_pdulensum. oPCQ TaskHeader sum of pointer length
 *        does not equal the TaskHeader.PduLength. DROP oPCQ
 *        TaskEntry. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int17 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> err_segsizemax. oPCQ TaskHeader conatins a pointer
 *        with a length that exceedes the size of the pointer
 *        data block. DROP oPCQ TaskEntry. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int16 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> err_segsizeis0. oPCQ TaskHeader contains a pointer
 *        with length of zero. DROP oPCQ TaskEntry. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int15 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> err_addrconvert. Address Convert module returns and
 *        error indication. DROP oPCQ TaskEntry. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int14 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> err_calculated_pdulength. The sum of oPCQ TaskHeader
 *        pointer length overflow. DROP oPCQ TaskEntry. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int13 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> err_illegalpool. oPCQ TaskHeader contains pointer
 *        with an illegal pool (0,1,24-30). DROP oPCQ TaskEntry.
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int12 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> NLINK parity error detected on task. Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int11 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> err_cpcq. Illegal cPCQ task recevied. Either CFG setup
 *        to drop cPCQ task or cPCQ.dba is illegal. DROP oPCQ
 *        TaskEntry. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int10 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> flowcontrol task command processed. Flow control task
 *        returned to NCAP. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int9 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> copy task performed. task data copied during SendTask
 *        command Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int8 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> completion task command porocessed. Task completion
 *        delivered to ITP Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int7 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> adpae task command processed. Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int6 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> adpah task command processed. Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int5 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> cpcq task command processed. Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int4 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> sndtsk task command processed. Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int3 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> noop task command processed. Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int2 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> drop task performed. Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> read_err Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> write_err Enable </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_interrupt0_en_r_t
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
} ncp_nca_otp_interrupt0_en_r_t;

/*! @struct ncp_nca_otp_interrupt1_en_r_t
 *  @brief Interrupt Enable Register
 *  @details This register enables interrupts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_interrupt1_en_r_t\n
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
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int62 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int61 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> err_maxcpcq. Total number of active cPCQ task is above
 *        configured threshold control_general_01.maxcpcq. DROP
 *        oPCQ TaskEntry. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int60 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> err_split. oPCQ TaskHeader has a pointer that is split.
 *        The same pointer data block is used as multiple segments.
 *        At least one of the segments has its MREF bit set
 *        to zero. DROP oPCQ TaskEntry. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int59 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> err_hs. oPCQ TaskEntry and oPCQ TaskHeader are inconsistent.
 *        TaskEntry.H not consistent with TaskHeader.CH OR TaskEntry.pointer
 *        and TaskHEader.pointer0 are the same and TaskEntry.H=1
 *        or they are different and TaskEntry.H=0. DROP oPCQ
 *        TaskEntry. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int58 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> err_dynamic. Error obsered processing dynamic command.
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int57 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> multi_fifo_fifo_underflow Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int56 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> multi_fifo_fifo_overflow Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int55 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> COLLISION ram_odtd_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int54 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> COLLISION ram_odts_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int53 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> COLLISION addrconvert_data1_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int52 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> COLLISION addrconvert_data1_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int51 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> COLLISION addrconvert_data0_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int50 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> COLLISION addrconvert_data0_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int49 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> COLLISION addrconvert_entry_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int48 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> COLLISION addrconvert_entry_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int47 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> COLLISION ram_dma_read_cpu_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int46 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> COLLISION multi_fifo_fifo_mem_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int45 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> COLLISION multi_fifo_state_mem_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int44 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> COLLISION multi_fifo_cfg_mem_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int43 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> COLLISION oll_isel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int42 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> COLLISION oll_isel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int41 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> COLLISION oll_isel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int40 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> COLLISION oll_isel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int39 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> COLLISION oll_rsel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int38 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> COLLISION oll_rsel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int37 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> COLLISION oll_rsel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int36 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> COLLISION oll_rsel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int35 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> COLLISION oll_sndtsk_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int34 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> COLLISION oll_sndtsk_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int33 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> COLLISION oll_sndtsk_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int32 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> COLLISION oll_sndtsk_ram_error Enable </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_interrupt1_en_r_t
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
} ncp_nca_otp_interrupt1_en_r_t;

/*! @struct ncp_nca_otp_interrupt2_en_r_t
 *  @brief Interrupt Enable Register
 *  @details This register enables interrupts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_interrupt2_en_r_t\n
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
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int94 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int93 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int92 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int91 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int90 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> MBE oll_isel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int89 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> SBE oll_isel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int88 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> COLLISION oll_isel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int87 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> SBE ram_odtd_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int86 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> SBE ram_odts_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int85 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> SBE addrconvert_data1_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int84 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> SBE addrconvert_data1_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int83 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> SBE addrconvert_data0_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int82 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> SBE addrconvert_data0_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int81 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> SBE addrconvert_entry_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int80 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> SBE addrconvert_entry_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int79 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> SBE ram_dma_read_cpu_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int78 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> SBE multi_fifo_fifo_mem_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int77 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> SBE multi_fifo_state_mem_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int76 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> SBE multi_fifo_cfg_mem_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int75 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> SBE oll_isel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int74 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> SBE oll_isel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int73 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> SBE oll_isel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int72 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> SBE oll_isel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int71 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> SBE oll_rsel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int70 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> SBE oll_rsel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int69 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> SBE oll_rsel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int68 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> SBE oll_rsel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int67 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> SBE oll_sndtsk_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int66 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> SBE oll_sndtsk_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int65 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> SBE oll_sndtsk_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int64 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> SBE oll_sndtsk_ram_error Enable </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_interrupt2_en_r_t
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
} ncp_nca_otp_interrupt2_en_r_t;

/*! @struct ncp_nca_otp_interrupt3_en_r_t
 *  @brief Interrupt Enable Register
 *  @details This register enables interrupts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_interrupt3_en_r_t\n
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
 *   <td width="30%"> NCAV3 CFG FIFO OF Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int126 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> NCAV3 CFG FIFO UF Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int125 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int124 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int123 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int122 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int121 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int120 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int119 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> MBE ram_odtd_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int118 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> MBE ram_odts_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int117 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> MBE addrconvert_data1_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int116 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> MBE addrconvert_data1_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int115 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> MBE addrconvert_data0_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int114 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> MBE addrconvert_data0_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int113 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> MBE addrconvert_entry_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int112 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> MBE addrconvert_entry_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int111 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> MBE ram_dma_read_cpu_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int110 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> MBE multi_fifo_fifo_mem_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int109 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> MBE multi_fifo_state_mem_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int108 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> MBE multi_fifo_cfg_mem_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int107 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> MBE oll_isel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int106 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> MBE oll_isel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int105 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> MBE oll_isel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int104 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> MBE oll_isel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int103 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> MBE oll_rsel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int102 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> MBE oll_rsel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int101 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> MBE oll_rsel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int100 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> MBE oll_rsel_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int99 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> MBE oll_sndtsk_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int98 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> MBE oll_sndtsk_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int97 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> MBE oll_sndtsk_ram_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int96 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> MBE oll_sndtsk_ram_error Enable </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_interrupt3_en_r_t
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
} ncp_nca_otp_interrupt3_en_r_t;

/*! @struct ncp_nca_otp_interrupt0_force_r_t
 *  @brief Interrupt Force Register
 *  @details This address is an alias for the Interrupt Status register
		that allows normal CFG writes (as opposed to the Clear-On-Write-One
		behavior if the Interrupt Status register address is used).  This
		allows CFG to set interrupt bits for testing purposes.  Reading this
		address returns the current value of the Interrupt Status Register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_interrupt0_force_r_t\n
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
 *   <td width="30%"> oll_sndtsk_error. The SendTask oPCQ LL (sndtsk) returns
 *        an error. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int30 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> oll_rsel_error. The output LL (rsel) returns an error.
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int29 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> oll_isel_error. The Input LL (isel) returns an error.
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int28 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> addrconvert_data1_out_error. Address Convert translating
 *        the oPCQ TaskHeader pointer returns an error. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int27 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> addrconvert_data0_out_error. Address Convert translating
 *        the oPCQ TaskHeader pointer returns an error. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int26 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> addrconvert_entry_out_error. Address Convert translating
 *        the oPCQ TaskEntry pointer returns an error. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int25 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> dma_read_cpu_CFG_err. DMA engine reading task header
 *        returns an error. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int24 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> dma_read_data_CFG_err. DMA engine reading task data
 *        returns an error. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int23 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> err_teth. oPCQ TaskEntry and oPCQ TaskHeader size
 *        are inconsistent. TaskEntry.size=0 and TaskHeader=128B
 *        or TaskEntry.size=1 and TaskHeader=64B. DROP oPCQ
 *        TaskEntry. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int22 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> err_ptrcnt. oPCQ TaskHeader pointer count is illegal.
 *        DROP oPCQ TaskEntry. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int21 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> err_destipcq. oPCQ TaskEntry is confiured to use the
 *        TaskEntry.DestiPCQ field the DestiPCQ is not configured
 *        to be online. DROP oPCQ TaskEntry. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int20 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> err_illegalcmd. oPCQ TaskEntry has an illegal command.
 *        DROP oPCQ TaskEntry. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int19 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> err_pdulenmax. oPCQ TaskHeader sum of pointer length
 *        exceed maximum supported length of 63kB. DROP oPCQ
 *        TaskEntry. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int18 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> err_pdulensum. oPCQ TaskHeader sum of pointer length
 *        does not equal the TaskHeader.PduLength. DROP oPCQ
 *        TaskEntry. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int17 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> err_segsizemax. oPCQ TaskHeader conatins a pointer
 *        with a length that exceedes the size of the pointer
 *        data block. DROP oPCQ TaskEntry. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int16 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> err_segsizeis0. oPCQ TaskHeader contains a pointer
 *        with length of zero. DROP oPCQ TaskEntry. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int15 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> err_addrconvert. Address Convert module returns and
 *        error indication. DROP oPCQ TaskEntry. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int14 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> err_calculated_pdulength. The sum of oPCQ TaskHeader
 *        pointer length overflow. DROP oPCQ TaskEntry. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int13 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> err_illegalpool. oPCQ TaskHeader contains pointer
 *        with an illegal pool (0,1,24-30). DROP oPCQ TaskEntry.
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int12 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> NLINK parity error detected on task. Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int11 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> err_cpcq. Illegal cPCQ task recevied. Either CFG setup
 *        to drop cPCQ task or cPCQ.dba is illegal. DROP oPCQ
 *        TaskEntry. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int10 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> flowcontrol task command processed. Flow control task
 *        returned to NCAP. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int9 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> copy task performed. task data copied during SendTask
 *        command Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int8 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> completion task command porocessed. Task completion
 *        delivered to ITP Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int7 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> adpae task command processed. Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int6 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> adpah task command processed. Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int5 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> cpcq task command processed. Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int4 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> sndtsk task command processed. Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int3 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> noop task command processed. Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int2 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> drop task performed. Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> read_err Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> write_err Force </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_interrupt0_force_r_t
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
} ncp_nca_otp_interrupt0_force_r_t;

/*! @struct ncp_nca_otp_interrupt1_force_r_t
 *  @brief Interrupt Force Register
 *  @details This address is an alias for the Interrupt Status register
		that allows normal CFG writes (as opposed to the Clear-On-Write-One
		behavior if the Interrupt Status register address is used).  This
		allows CFG to set interrupt bits for testing purposes.  Reading this
		address returns the current value of the Interrupt Status Register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_interrupt1_force_r_t\n
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
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int62 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int61 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> err_maxcpcq. Total number of active cPCQ task is above
 *        configured threshold control_general_01.maxcpcq. DROP
 *        oPCQ TaskEntry. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int60 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> err_split. oPCQ TaskHeader has a pointer that is split.
 *        The same pointer data block is used as multiple segments.
 *        At least one of the segments has its MREF bit set
 *        to zero. DROP oPCQ TaskEntry. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int59 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> err_hs. oPCQ TaskEntry and oPCQ TaskHeader are inconsistent.
 *        TaskEntry.H not consistent with TaskHeader.CH OR TaskEntry.pointer
 *        and TaskHEader.pointer0 are the same and TaskEntry.H=1
 *        or they are different and TaskEntry.H=0. DROP oPCQ
 *        TaskEntry. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int58 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> err_dynamic. Error obsered processing dynamic command.
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int57 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> multi_fifo_fifo_underflow Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int56 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> multi_fifo_fifo_overflow Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int55 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> COLLISION ram_odtd_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int54 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> COLLISION ram_odts_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int53 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> COLLISION addrconvert_data1_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int52 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> COLLISION addrconvert_data1_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int51 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> COLLISION addrconvert_data0_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int50 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> COLLISION addrconvert_data0_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int49 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> COLLISION addrconvert_entry_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int48 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> COLLISION addrconvert_entry_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int47 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> COLLISION ram_dma_read_cpu_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int46 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> COLLISION multi_fifo_fifo_mem_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int45 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> COLLISION multi_fifo_state_mem_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int44 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> COLLISION multi_fifo_cfg_mem_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int43 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> COLLISION oll_isel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int42 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> COLLISION oll_isel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int41 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> COLLISION oll_isel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int40 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> COLLISION oll_isel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int39 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> COLLISION oll_rsel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int38 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> COLLISION oll_rsel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int37 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> COLLISION oll_rsel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int36 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> COLLISION oll_rsel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int35 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> COLLISION oll_sndtsk_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int34 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> COLLISION oll_sndtsk_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int33 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> COLLISION oll_sndtsk_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int32 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> COLLISION oll_sndtsk_ram_error Force </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_interrupt1_force_r_t
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
} ncp_nca_otp_interrupt1_force_r_t;

/*! @struct ncp_nca_otp_interrupt2_force_r_t
 *  @brief Interrupt Force Register
 *  @details This address is an alias for the Interrupt Status register
		that allows normal CFG writes (as opposed to the Clear-On-Write-One
		behavior if the Interrupt Status register address is used).  This
		allows CFG to set interrupt bits for testing purposes.  Reading this
		address returns the current value of the Interrupt Status Register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_interrupt2_force_r_t\n
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
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int94 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int93 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int92 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int91 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int90 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> MBE oll_isel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int89 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> SBE oll_isel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int88 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> COLLISION oll_isel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int87 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> SBE ram_odtd_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int86 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> SBE ram_odts_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int85 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> SBE addrconvert_data1_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int84 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> SBE addrconvert_data1_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int83 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> SBE addrconvert_data0_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int82 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> SBE addrconvert_data0_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int81 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> SBE addrconvert_entry_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int80 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> SBE addrconvert_entry_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int79 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> SBE ram_dma_read_cpu_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int78 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> SBE multi_fifo_fifo_mem_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int77 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> SBE multi_fifo_state_mem_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int76 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> SBE multi_fifo_cfg_mem_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int75 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> SBE oll_isel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int74 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> SBE oll_isel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int73 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> SBE oll_isel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int72 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> SBE oll_isel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int71 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> SBE oll_rsel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int70 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> SBE oll_rsel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int69 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> SBE oll_rsel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int68 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> SBE oll_rsel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int67 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> SBE oll_sndtsk_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int66 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> SBE oll_sndtsk_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int65 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> SBE oll_sndtsk_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int64 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> SBE oll_sndtsk_ram_error Force </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_interrupt2_force_r_t
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
} ncp_nca_otp_interrupt2_force_r_t;

/*! @struct ncp_nca_otp_interrupt3_force_r_t
 *  @brief Interrupt Force Register
 *  @details This address is an alias for the Interrupt Status register
		that allows normal CFG writes (as opposed to the Clear-On-Write-One
		behavior if the Interrupt Status register address is used).  This
		allows CFG to set interrupt bits for testing purposes.  Reading this
		address returns the current value of the Interrupt Status Register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_interrupt3_force_r_t\n
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
 *   <td width="30%"> NCAV3 CFG FIFO OF Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int126 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> NCAV3 CFG FIFO UF Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int125 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int124 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int123 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int122 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int121 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int120 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int119 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> MBE ram_odtd_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int118 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> MBE ram_odts_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int117 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> MBE addrconvert_data1_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int116 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> MBE addrconvert_data1_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int115 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> MBE addrconvert_data0_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int114 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> MBE addrconvert_data0_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int113 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> MBE addrconvert_entry_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int112 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> MBE addrconvert_entry_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int111 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> MBE ram_dma_read_cpu_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int110 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> MBE multi_fifo_fifo_mem_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int109 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> MBE multi_fifo_state_mem_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int108 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> MBE multi_fifo_cfg_mem_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int107 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> MBE oll_isel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int106 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> MBE oll_isel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int105 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> MBE oll_isel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int104 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> MBE oll_isel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int103 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> MBE oll_rsel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int102 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> MBE oll_rsel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int101 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> MBE oll_rsel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int100 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> MBE oll_rsel_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int99 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> MBE oll_sndtsk_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int98 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> MBE oll_sndtsk_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int97 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> MBE oll_sndtsk_ram_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int96 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> MBE oll_sndtsk_ram_error Force </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_interrupt3_force_r_t
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
} ncp_nca_otp_interrupt3_force_r_t;

/*! @struct ncp_nca_otp_syndrome_cfg_r_t
 *  @brief null
 *  @details CFG access to Status. Syndrome Configuration register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_syndrome_cfg_r_t\n
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
 * Applies to: xlf --> ncp_nca_otp_syndrome_cfg_r_t
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
} ncp_nca_otp_syndrome_cfg_r_t;

/*! @struct ncp_nca_otp_syndrome_event_r_t
 *  @brief null
 *  @details CFG access to Status. Syndrome Captured Event register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_syndrome_event_r_t\n
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
 * Applies to: xlf --> ncp_nca_otp_syndrome_event_r_t
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
} ncp_nca_otp_syndrome_event_r_t;

/*! @struct ncp_nca_otp_syndrome_data00_r_t
 *  @brief null
 *  @details CFG access to Status. Syndrome Captured Event Data register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_syndrome_data00_r_t\n
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
 * Applies to: xlf --> ncp_nca_otp_syndrome_data00_r_t
 *
 * Implemented by: 
 *      syndrome_data00
 */
 
typedef struct
{
     unsigned  int                 synd_data;
} ncp_nca_otp_syndrome_data00_r_t;

/*! @struct ncp_nca_otp_syndrome_data01_r_t
 *  @brief null
 *  @details CFG access to Status. Syndrome Captured Event Data register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_syndrome_data01_r_t\n
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
 * Applies to: xlf --> ncp_nca_otp_syndrome_data01_r_t
 *
 * Implemented by: 
 *      syndrome_data01
 */
 
typedef struct
{
     unsigned  int                 synd_data;
} ncp_nca_otp_syndrome_data01_r_t;

/*! @struct ncp_nca_otp_syndrome_data02_r_t
 *  @brief null
 *  @details CFG access to Status. Syndrome Captured Event Data register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_syndrome_data02_r_t\n
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
 * Applies to: xlf --> ncp_nca_otp_syndrome_data02_r_t
 *
 * Implemented by: 
 *      syndrome_data02
 */
 
typedef struct
{
     unsigned  int                 synd_data;
} ncp_nca_otp_syndrome_data02_r_t;

/*! @struct ncp_nca_otp_syndrome_data03_r_t
 *  @brief null
 *  @details CFG access to Status. Syndrome Captured Event Data register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_syndrome_data03_r_t\n
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
 * Applies to: xlf --> ncp_nca_otp_syndrome_data03_r_t
 *
 * Implemented by: 
 *      syndrome_data03
 */
 
typedef struct
{
     unsigned  int                 synd_data;
} ncp_nca_otp_syndrome_data03_r_t;

/*! @struct ncp_nca_otp_parameter_00_r_t
 *  @brief null
 *  @details parameter_00
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_parameter_00_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param parm_num_ncap_pgit_opcq </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> NUM_NCAP_PGIT_OPCQ </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param parm_num_total_opcq </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> NUM_TOTAL_OPCQ </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param parm_size_otp_input_ll </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> SIZE_OTP_INPUT_LL </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param parm_size_otp_return_ll </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> SIZE_OTP_RETURN_LL </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_parameter_00_r_t
 *
 * Implemented by: 
 *      parameter_00
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      parm_num_ncap_pgit_opcq                   :  8;
     unsigned      parm_num_total_opcq                       :  8;
     unsigned      parm_size_otp_input_ll                    :  8;
     unsigned      parm_size_otp_return_ll                   :  8;
#else    /* Little Endian */
     unsigned      parm_size_otp_return_ll                   :  8;
     unsigned      parm_size_otp_input_ll                    :  8;
     unsigned      parm_num_total_opcq                       :  8;
     unsigned      parm_num_ncap_pgit_opcq                   :  8;
#endif
} ncp_nca_otp_parameter_00_r_t;

/*! @struct ncp_nca_otp_parameter_01_r_t
 *  @brief null
 *  @details parameter_01
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_parameter_01_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param parm_num_nlink_opcq </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> NUM_NLINK_OPCQ </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param parm_num_nlink_opcq_credits </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> NUM_NLINK_OPCQ_CREDITS </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param parm_num_ncap </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> NUM_NCAP </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param parm_num_ncap_pgit </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> NUM_NCAP_PGIT </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_parameter_01_r_t
 *
 * Implemented by: 
 *      parameter_01
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      parm_num_nlink_opcq                       :  8;
     unsigned      parm_num_nlink_opcq_credits               :  8;
     unsigned      parm_num_ncap                             :  8;
     unsigned      parm_num_ncap_pgit                        :  8;
#else    /* Little Endian */
     unsigned      parm_num_ncap_pgit                        :  8;
     unsigned      parm_num_ncap                             :  8;
     unsigned      parm_num_nlink_opcq_credits               :  8;
     unsigned      parm_num_nlink_opcq                       :  8;
#endif
} ncp_nca_otp_parameter_01_r_t;

/*! @struct ncp_nca_otp_AW_smon01_smon_r_t
 *  @brief AW_smon CONTROL1 register
 *  @details This is used to configure the operation of the 2 internal counters in the SMON
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_AW_smon01_smon_r_t\n
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
 * Applies to: xlf --> ncp_nca_otp_AW_smon01_smon_r_t
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
} ncp_nca_otp_AW_smon01_smon_r_t;

/*! @struct ncp_nca_otp_control_general_00_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_control_general_00_r_t\n
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
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param earlysyndrome </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> enable syndrome modes that capture data BEFORE the
 *        task drop. Will lost the task entry address when sydrome
 *        captures
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param copy64k </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> force copy for 64k pointers </td>
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
 *     <td width="30%"> @param reserved2 </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_control_general_00_r_t
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
     unsigned      reserved1                                 : 22;
     unsigned      earlysyndrome                             :  1;
     unsigned      copy64k                                   :  1;
     unsigned      raminitdone                               :  1;
     unsigned      raminit                                   :  1;
     unsigned      reserved2                                 :  2;
#else    /* Little Endian */
     unsigned      reserved2                                 :  2;
     unsigned      raminit                                   :  1;
     unsigned      raminitdone                               :  1;
     unsigned      copy64k                                   :  1;
     unsigned      earlysyndrome                             :  1;
     unsigned      reserved1                                 : 22;
     unsigned      paritymode                                :  1;
     unsigned      parityenable                              :  1;
     unsigned      disablecounters                           :  1;
     unsigned      reserved0                                 :  1;
#endif
} ncp_nca_otp_control_general_00_r_t;

/*! @struct ncp_nca_otp_control_general_01_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_control_general_01_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cpcqdba </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> 0:drop cpcq req with dba=1 1:allow cpcq req with dba=1 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cpcq </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> 0:allow cpcq req 1:drop cpcq req </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 22 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param maxcpcq </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> maximum cPCQ in flight before dropping </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_control_general_01_r_t
 *
 * Implemented by: 
 *      control_general_01
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      cpcqdba                                   :  1;
     unsigned      cpcq                                      :  1;
     unsigned      reserved0                                 : 22;
     unsigned      maxcpcq                                   :  8;
#else    /* Little Endian */
     unsigned      maxcpcq                                   :  8;
     unsigned      reserved0                                 : 22;
     unsigned      cpcq                                      :  1;
     unsigned      cpcqdba                                   :  1;
#endif
} ncp_nca_otp_control_general_01_r_t;

/*! @struct ncp_nca_otp_control_memintf_00_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register  for DMA engine fetching task header
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_control_memintf_00_r_t\n
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
 *     <td width="20%" align="center"> 15 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param memenable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param mempriority </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> priority </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wrap </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> wrap </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ttype </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ttype </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_control_memintf_00_r_t
 *
 * Implemented by: 
 *      control_memintf_00
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 15;
     unsigned      memenable                                 :  1;
     unsigned      mempriority                               :  1;
     unsigned      wrap                                      :  1;
     unsigned      ttype                                     :  6;
     unsigned      reserved1                                 :  8;
#else    /* Little Endian */
     unsigned      reserved1                                 :  8;
     unsigned      ttype                                     :  6;
     unsigned      wrap                                      :  1;
     unsigned      mempriority                               :  1;
     unsigned      memenable                                 :  1;
     unsigned      reserved0                                 : 15;
#endif
} ncp_nca_otp_control_memintf_00_r_t;

/*! @struct ncp_nca_otp_control_memintf_01_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register  for DMA engine fetching task header
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_control_memintf_01_r_t\n
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
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifoout </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> DMA read header FIFOout control </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fiford </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> DMA read header FIFOrd control </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fiforr </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> DMA read header FIFOrr control </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_control_memintf_01_r_t
 *
 * Implemented by: 
 *      control_memintf_01
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  8;
     unsigned      fifoout                                   :  8;
     unsigned      fiford                                    :  8;
     unsigned      fiforr                                    :  8;
#else    /* Little Endian */
     unsigned      fiforr                                    :  8;
     unsigned      fiford                                    :  8;
     unsigned      fifoout                                   :  8;
     unsigned      reserved0                                 :  8;
#endif
} ncp_nca_otp_control_memintf_01_r_t;

/*! @struct ncp_nca_otp_control_memintf_02_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register  for DMA engine fetching copy data
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_control_memintf_02_r_t\n
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
 *     <td width="20%" align="center"> 15 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param memenable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param mempriority </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> priority </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wrap </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> wrap </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ttype </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ttype </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_control_memintf_02_r_t
 *
 * Implemented by: 
 *      control_memintf_02
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 15;
     unsigned      memenable                                 :  1;
     unsigned      mempriority                               :  1;
     unsigned      wrap                                      :  1;
     unsigned      ttype                                     :  6;
     unsigned      reserved1                                 :  8;
#else    /* Little Endian */
     unsigned      reserved1                                 :  8;
     unsigned      ttype                                     :  6;
     unsigned      wrap                                      :  1;
     unsigned      mempriority                               :  1;
     unsigned      memenable                                 :  1;
     unsigned      reserved0                                 : 15;
#endif
} ncp_nca_otp_control_memintf_02_r_t;

/*! @struct ncp_nca_otp_control_memintf_03_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register  for DMA engine fetching copy data
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_control_memintf_03_r_t\n
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
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifoout </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> DMA read header FIFOout control </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fiford </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> DMA read header FIFOrd control </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fiforr </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> DMA read header FIFOrr control </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_control_memintf_03_r_t
 *
 * Implemented by: 
 *      control_memintf_03
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  8;
     unsigned      fifoout                                   :  8;
     unsigned      fiford                                    :  8;
     unsigned      fiforr                                    :  8;
#else    /* Little Endian */
     unsigned      fiforr                                    :  8;
     unsigned      fiford                                    :  8;
     unsigned      fifoout                                   :  8;
     unsigned      reserved0                                 :  8;
#endif
} ncp_nca_otp_control_memintf_03_r_t;

/*! @struct ncp_nca_otp_control_general_04_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register for arbs
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_control_general_04_r_t\n
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
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_fifo_itp_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> arb_fifo_itp_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_outputin_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> arb_outputIn_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_mtpin_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> arb_mtpIn_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_ram_odtin_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> arb_ram_odtIn_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_multi_fifoout_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> arb_multi_fifoOut_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_multi_fifoin_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> arb_multi_fifoIn_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_ll_sndtskout_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> arb_ll_sndtskOut_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_ll_sndtskin_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> arb_ll_sndtskIn_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_ll_rselout_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> arb_ll_rselOut_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_ll_rselin_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> arb_ll_rselIn_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_ll_iselout_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> arb_ll_iselOut_arb_mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_ll_iselin_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> arb_ll_iselIn_arb_mode </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_control_general_04_r_t
 *
 * Implemented by: 
 *      control_general_04
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  8;
     unsigned      arb_fifo_itp_arb_mode                     :  2;
     unsigned      arb_outputin_arb_mode                     :  2;
     unsigned      arb_mtpin_arb_mode                        :  2;
     unsigned      arb_ram_odtin_arb_mode                    :  2;
     unsigned      arb_multi_fifoout_arb_mode                :  2;
     unsigned      arb_multi_fifoin_arb_mode                 :  2;
     unsigned      arb_ll_sndtskout_arb_mode                 :  2;
     unsigned      arb_ll_sndtskin_arb_mode                  :  2;
     unsigned      arb_ll_rselout_arb_mode                   :  2;
     unsigned      arb_ll_rselin_arb_mode                    :  2;
     unsigned      arb_ll_iselout_arb_mode                   :  2;
     unsigned      arb_ll_iselin_arb_mode                    :  2;
#else    /* Little Endian */
     unsigned      arb_ll_iselin_arb_mode                    :  2;
     unsigned      arb_ll_iselout_arb_mode                   :  2;
     unsigned      arb_ll_rselin_arb_mode                    :  2;
     unsigned      arb_ll_rselout_arb_mode                   :  2;
     unsigned      arb_ll_sndtskin_arb_mode                  :  2;
     unsigned      arb_ll_sndtskout_arb_mode                 :  2;
     unsigned      arb_multi_fifoin_arb_mode                 :  2;
     unsigned      arb_multi_fifoout_arb_mode                :  2;
     unsigned      arb_ram_odtin_arb_mode                    :  2;
     unsigned      arb_mtpin_arb_mode                        :  2;
     unsigned      arb_outputin_arb_mode                     :  2;
     unsigned      arb_fifo_itp_arb_mode                     :  2;
     unsigned      reserved0                                 :  8;
#endif
} ncp_nca_otp_control_general_04_r_t;

/*! @struct ncp_nca_otp_control_general_05_r_t
 *  @brief null
 *  @details CFG access to control registers. SMON Mask
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_control_general_05_r_t\n
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
 *   <td width="30%"> SMON Mask </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_control_general_05_r_t
 *
 * Implemented by: 
 *      control_general_05
 */
 
typedef struct
{
     unsigned  int                  smonmask;
} ncp_nca_otp_control_general_05_r_t;

/*! @struct ncp_nca_otp_control_destipcq_00_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register to enable destination iPCQ for ADHAH and ADPAE commands. sparse 31:0
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_control_destipcq_00_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param enable_destipcq </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> RESERVED </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_control_destipcq_00_r_t
 *
 * Implemented by: 
 *      control_destipcq_00
 */
 
typedef struct
{
     unsigned  int           enable_destipcq;
} ncp_nca_otp_control_destipcq_00_r_t;

/*! @struct ncp_nca_otp_control_destipcq_01_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register to enable destination iPCQ for ADHAH and ADPAE commands. sparse 63:32
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_control_destipcq_01_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param enable_destipcq </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> RESERVED </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_control_destipcq_01_r_t
 *
 * Implemented by: 
 *      control_destipcq_01
 */
 
typedef struct
{
     unsigned  int           enable_destipcq;
} ncp_nca_otp_control_destipcq_01_r_t;

/*! @struct ncp_nca_otp_control_destipcq_02_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register to enable destination iPCQ for ADHAH and ADPAE commands. sparse 95:64
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_control_destipcq_02_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param enable_destipcq </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> RESERVED </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_control_destipcq_02_r_t
 *
 * Implemented by: 
 *      control_destipcq_02
 */
 
typedef struct
{
     unsigned  int           enable_destipcq;
} ncp_nca_otp_control_destipcq_02_r_t;

/*! @struct ncp_nca_otp_control_destipcq_03_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register to enable destination iPCQ for ADHAH and ADPAE commands. sparse 127:96
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_control_destipcq_03_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param enable_destipcq </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> RESERVED </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_control_destipcq_03_r_t
 *
 * Implemented by: 
 *      control_destipcq_03
 */
 
typedef struct
{
     unsigned  int           enable_destipcq;
} ncp_nca_otp_control_destipcq_03_r_t;

/*! @struct ncp_nca_otp_control_destipcq_04_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register to enable destination iPCQ for ADHAH and ADPAE commands. sparse 159:128
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_control_destipcq_04_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param enable_destipcq </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> RESERVED </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_control_destipcq_04_r_t
 *
 * Implemented by: 
 *      control_destipcq_04
 */
 
typedef struct
{
     unsigned  int           enable_destipcq;
} ncp_nca_otp_control_destipcq_04_r_t;

/*! @struct ncp_nca_otp_control_destipcq_05_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register to enable destination iPCQ for ADHAH and ADPAE commands. sparse 191:160
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_control_destipcq_05_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param enable_destipcq </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> RESERVED </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_control_destipcq_05_r_t
 *
 * Implemented by: 
 *      control_destipcq_05
 */
 
typedef struct
{
     unsigned  int           enable_destipcq;
} ncp_nca_otp_control_destipcq_05_r_t;

/*! @struct ncp_nca_otp_control_destipcq_06_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register to enable destination iPCQ for ADHAH and ADPAE commands. sparse 223:192
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_control_destipcq_06_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param enable_destipcq </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> RESERVED </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_control_destipcq_06_r_t
 *
 * Implemented by: 
 *      control_destipcq_06
 */
 
typedef struct
{
     unsigned  int           enable_destipcq;
} ncp_nca_otp_control_destipcq_06_r_t;

/*! @struct ncp_nca_otp_control_destipcq_07_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register to enable destination iPCQ for ADHAH and ADPAE commands. sparse 255:224
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_control_destipcq_07_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param enable_destipcq </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> RESERVED </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_control_destipcq_07_r_t
 *
 * Implemented by: 
 *      control_destipcq_07
 */
 
typedef struct
{
     unsigned  int           enable_destipcq;
} ncp_nca_otp_control_destipcq_07_r_t;

/*! @struct ncp_nca_otp_control_general_16_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_control_general_16_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ll_rsel_afull </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> ll_rsel afull </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ll_isel_afull </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ll_isel afull </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_control_general_16_r_t
 *
 * Implemented by: 
 *      control_general_16
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ll_rsel_afull                             : 16;
     unsigned      ll_isel_afull                             : 16;
#else    /* Little Endian */
     unsigned      ll_isel_afull                             : 16;
     unsigned      ll_rsel_afull                             : 16;
#endif
} ncp_nca_otp_control_general_16_r_t;

/*! @struct ncp_nca_otp_control_general_17_r_t
 *  @brief null
 *  @details CFG access to control registers. general control register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_control_general_17_r_t\n
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
 *     <td width="30%"> @param ll_sndtsk_afull </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ll_sndtsk afull </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_control_general_17_r_t
 *
 * Implemented by: 
 *      control_general_17
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      ll_sndtsk_afull                           : 16;
#else    /* Little Endian */
     unsigned      ll_sndtsk_afull                           : 16;
     unsigned      reserved0                                 : 16;
#endif
} ncp_nca_otp_control_general_17_r_t;

/*! @struct ncp_nca_otp_status_oll_isel_status_r_t
 *  @brief null
 *  @details CFG access to Status. Status of oll_isel_status OLL
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_status_oll_isel_status_r_t\n
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
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_resp_v </td>
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
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The current value of the LL pop reqeust interface </td>
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
 * Applies to: xlf --> ncp_nca_otp_status_oll_isel_status_r_t
 *
 * Implemented by: 
 *      status_oll_isel_status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      size                                      : 20;
     unsigned      ll_busy                                   :  1;
     unsigned      ll_valid                                  :  1;
     unsigned      full                                      :  1;
     unsigned      freelist_pop_id_v                         :  1;
     unsigned      reserved0                                 :  1;
     unsigned      pop_resp_v                                :  1;
     unsigned      complete_resp_v                           :  1;
     unsigned      alloc_resp_v                              :  1;
     unsigned      reserved1                                 :  1;
     unsigned      pop_req_v                                 :  1;
     unsigned      complete_req_v                            :  1;
     unsigned      alloc_req_v                               :  1;
#else    /* Little Endian */
     unsigned      alloc_req_v                               :  1;
     unsigned      complete_req_v                            :  1;
     unsigned      pop_req_v                                 :  1;
     unsigned      reserved1                                 :  1;
     unsigned      alloc_resp_v                              :  1;
     unsigned      complete_resp_v                           :  1;
     unsigned      pop_resp_v                                :  1;
     unsigned      reserved0                                 :  1;
     unsigned      freelist_pop_id_v                         :  1;
     unsigned      full                                      :  1;
     unsigned      ll_valid                                  :  1;
     unsigned      ll_busy                                   :  1;
     unsigned      size                                      : 20;
#endif
} ncp_nca_otp_status_oll_isel_status_r_t;

/*! @struct ncp_nca_otp_status_oll_rsel_status_r_t
 *  @brief null
 *  @details CFG access to Status. Status of oll_rsel_status OLL
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_status_oll_rsel_status_r_t\n
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
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_resp_v </td>
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
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The current value of the LL pop reqeust interface </td>
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
 * Applies to: xlf --> ncp_nca_otp_status_oll_rsel_status_r_t
 *
 * Implemented by: 
 *      status_oll_rsel_status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      size                                      : 20;
     unsigned      ll_busy                                   :  1;
     unsigned      ll_valid                                  :  1;
     unsigned      full                                      :  1;
     unsigned      freelist_pop_id_v                         :  1;
     unsigned      reserved0                                 :  1;
     unsigned      pop_resp_v                                :  1;
     unsigned      complete_resp_v                           :  1;
     unsigned      alloc_resp_v                              :  1;
     unsigned      reserved1                                 :  1;
     unsigned      pop_req_v                                 :  1;
     unsigned      complete_req_v                            :  1;
     unsigned      alloc_req_v                               :  1;
#else    /* Little Endian */
     unsigned      alloc_req_v                               :  1;
     unsigned      complete_req_v                            :  1;
     unsigned      pop_req_v                                 :  1;
     unsigned      reserved1                                 :  1;
     unsigned      alloc_resp_v                              :  1;
     unsigned      complete_resp_v                           :  1;
     unsigned      pop_resp_v                                :  1;
     unsigned      reserved0                                 :  1;
     unsigned      freelist_pop_id_v                         :  1;
     unsigned      full                                      :  1;
     unsigned      ll_valid                                  :  1;
     unsigned      ll_busy                                   :  1;
     unsigned      size                                      : 20;
#endif
} ncp_nca_otp_status_oll_rsel_status_r_t;

/*! @struct ncp_nca_otp_status_oll_sndtsk_status_r_t
 *  @brief null
 *  @details CFG access to Status. Status of oll_sndtsk_status OLL
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_status_oll_sndtsk_status_r_t\n
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
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_resp_v </td>
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
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The current value of the LL pop reqeust interface </td>
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
 * Applies to: xlf --> ncp_nca_otp_status_oll_sndtsk_status_r_t
 *
 * Implemented by: 
 *      status_oll_sndtsk_status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      size                                      : 20;
     unsigned      ll_busy                                   :  1;
     unsigned      ll_valid                                  :  1;
     unsigned      full                                      :  1;
     unsigned      freelist_pop_id_v                         :  1;
     unsigned      reserved0                                 :  1;
     unsigned      pop_resp_v                                :  1;
     unsigned      complete_resp_v                           :  1;
     unsigned      alloc_resp_v                              :  1;
     unsigned      reserved1                                 :  1;
     unsigned      pop_req_v                                 :  1;
     unsigned      complete_req_v                            :  1;
     unsigned      alloc_req_v                               :  1;
#else    /* Little Endian */
     unsigned      alloc_req_v                               :  1;
     unsigned      complete_req_v                            :  1;
     unsigned      pop_req_v                                 :  1;
     unsigned      reserved1                                 :  1;
     unsigned      alloc_resp_v                              :  1;
     unsigned      complete_resp_v                           :  1;
     unsigned      pop_resp_v                                :  1;
     unsigned      reserved0                                 :  1;
     unsigned      freelist_pop_id_v                         :  1;
     unsigned      full                                      :  1;
     unsigned      ll_valid                                  :  1;
     unsigned      ll_busy                                   :  1;
     unsigned      size                                      : 20;
#endif
} ncp_nca_otp_status_oll_sndtsk_status_r_t;

/*! @struct ncp_nca_otp_status_fifo_otp_cpu_out_r_t
 *  @brief null
 *  @details CFG access to Status. Status of fifo_otp_cpu_out FIFOstat
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_status_fifo_otp_cpu_out_r_t\n
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
 * Applies to: xlf --> ncp_nca_otp_status_fifo_otp_cpu_out_r_t
 *
 * Implemented by: 
 *      status_fifo_otp_cpu_out
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
} ncp_nca_otp_status_fifo_otp_cpu_out_r_t;

/*! @struct ncp_nca_otp_status_fifo_otp_cpu_rd_r_t
 *  @brief null
 *  @details CFG access to Status. Status of fifo_otp_cpu_rd FIFOstat
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_status_fifo_otp_cpu_rd_r_t\n
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
 *     <td width="20%" align="center"> 14 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_rdepth </td>
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> FIFO REPTH </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_depth </td>
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> FIFO DEPTH </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_overflow </td>
 *     <td width="20%" align="center"> 3 </td>
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
 * Applies to: xlf --> ncp_nca_otp_status_fifo_otp_cpu_rd_r_t
 *
 * Implemented by: 
 *      status_fifo_otp_cpu_rd
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 14;
     unsigned      fifo_rdepth                               :  7;
     unsigned      fifo_depth                                :  7;
     unsigned      fifo_overflow                             :  3;
     unsigned      fifo_underflow                            :  1;
#else    /* Little Endian */
     unsigned      fifo_underflow                            :  1;
     unsigned      fifo_overflow                             :  3;
     unsigned      fifo_depth                                :  7;
     unsigned      fifo_rdepth                               :  7;
     unsigned      reserved0                                 : 14;
#endif
} ncp_nca_otp_status_fifo_otp_cpu_rd_r_t;

/*! @struct ncp_nca_otp_status_fifo_otp_cpu_rr_r_t
 *  @brief null
 *  @details CFG access to Status. Status of fifo_otp_cpu_rr FIFOstat
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_status_fifo_otp_cpu_rr_r_t\n
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
 * Applies to: xlf --> ncp_nca_otp_status_fifo_otp_cpu_rr_r_t
 *
 * Implemented by: 
 *      status_fifo_otp_cpu_rr
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
} ncp_nca_otp_status_fifo_otp_cpu_rr_r_t;

/*! @struct ncp_nca_otp_status_fifo_otp_data_out_r_t
 *  @brief null
 *  @details CFG access to Status. Status of fifo_otp_data_out FIFOstat
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_status_fifo_otp_data_out_r_t\n
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
 * Applies to: xlf --> ncp_nca_otp_status_fifo_otp_data_out_r_t
 *
 * Implemented by: 
 *      status_fifo_otp_data_out
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
} ncp_nca_otp_status_fifo_otp_data_out_r_t;

/*! @struct ncp_nca_otp_status_fifo_otp_data_rd_r_t
 *  @brief null
 *  @details CFG access to Status. Status of fifo_otp_data_rd FIFOstat
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_status_fifo_otp_data_rd_r_t\n
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
 *     <td width="20%" align="center"> 14 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_rdepth </td>
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> FIFO REPTH </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_depth </td>
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> FIFO DEPTH </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_overflow </td>
 *     <td width="20%" align="center"> 3 </td>
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
 * Applies to: xlf --> ncp_nca_otp_status_fifo_otp_data_rd_r_t
 *
 * Implemented by: 
 *      status_fifo_otp_data_rd
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 14;
     unsigned      fifo_rdepth                               :  7;
     unsigned      fifo_depth                                :  7;
     unsigned      fifo_overflow                             :  3;
     unsigned      fifo_underflow                            :  1;
#else    /* Little Endian */
     unsigned      fifo_underflow                            :  1;
     unsigned      fifo_overflow                             :  3;
     unsigned      fifo_depth                                :  7;
     unsigned      fifo_rdepth                               :  7;
     unsigned      reserved0                                 : 14;
#endif
} ncp_nca_otp_status_fifo_otp_data_rd_r_t;

/*! @struct ncp_nca_otp_status_fifo_otp_data_rr_r_t
 *  @brief null
 *  @details CFG access to Status. Status of fifo_otp_data_rr FIFOstat
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_status_fifo_otp_data_rr_r_t\n
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
 * Applies to: xlf --> ncp_nca_otp_status_fifo_otp_data_rr_r_t
 *
 * Implemented by: 
 *      status_fifo_otp_data_rr
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
} ncp_nca_otp_status_fifo_otp_data_rr_r_t;

/*! @struct ncp_nca_otp_status_state00_r_t
 *  @brief null
 *  @details CFG access to Status. Status of state machine
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_status_state00_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param state_dmareq_q </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> current value of dmareq statemachine </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param state_dmaret_q </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> current value of dmaret statemachine </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_status_state00_r_t
 *
 * Implemented by: 
 *      status_state00
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      state_dmareq_q                            : 16;
     unsigned      state_dmaret_q                            : 16;
#else    /* Little Endian */
     unsigned      state_dmaret_q                            : 16;
     unsigned      state_dmareq_q                            : 16;
#endif
} ncp_nca_otp_status_state00_r_t;

/*! @struct ncp_nca_otp_status_state01_r_t
 *  @brief null
 *  @details CFG access to Status. Status of state machine
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_status_state01_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param state_header_q </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> current value of header statemachine </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param state_tdgl_q </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> current value of tdgl statemachine </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_status_state01_r_t
 *
 * Implemented by: 
 *      status_state01
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      state_header_q                            : 16;
     unsigned      state_tdgl_q                              : 16;
#else    /* Little Endian */
     unsigned      state_tdgl_q                              : 16;
     unsigned      state_header_q                            : 16;
#endif
} ncp_nca_otp_status_state01_r_t;

/*! @struct ncp_nca_otp_status_state02_r_t
 *  @brief null
 *  @details CFG access to Status. Status of state machine
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_status_state02_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param seq </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> current value of sequence </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param state_isel_q </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> current value of isel statemachine </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_status_state02_r_t
 *
 * Implemented by: 
 *      status_state02
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      seq                                       :  8;
     unsigned      reserved0                                 :  8;
     unsigned      state_isel_q                              : 16;
#else    /* Little Endian */
     unsigned      state_isel_q                              : 16;
     unsigned      reserved0                                 :  8;
     unsigned      seq                                       :  8;
#endif
} ncp_nca_otp_status_state02_r_t;

/*! @struct ncp_nca_otp_status_state03_r_t
 *  @brief null
 *  @details CFG access to Status. Status of state machine
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_status_state03_r_t\n
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
 *     <td width="30%"> @param state_isel_q </td>
 *     <td width="20%" align="center"> 20 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> current value of header statemachine </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_status_state03_r_t
 *
 * Implemented by: 
 *      status_state03
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 12;
     unsigned      state_isel_q                              : 20;
#else    /* Little Endian */
     unsigned      state_isel_q                              : 20;
     unsigned      reserved0                                 : 12;
#endif
} ncp_nca_otp_status_state03_r_t;

/*! @struct ncp_nca_otp_status_state04_r_t
 *  @brief null
 *  @details CFG access to Status. Status of state machine
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_status_state04_r_t\n
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
 *     <td width="30%"> @param multi_fifo_busy </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> current value of multi FIFO busy </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_status_state04_r_t
 *
 * Implemented by: 
 *      status_state04
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      multi_fifo_busy                           : 16;
#else    /* Little Endian */
     unsigned      multi_fifo_busy                           : 16;
     unsigned      reserved0                                 : 16;
#endif
} ncp_nca_otp_status_state04_r_t;

/*! @struct ncp_nca_otp_status_state10_r_t
 *  @brief null
 *  @details CFG access to Status.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_status_state10_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param otpversion </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> OTP version </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_status_state10_r_t
 *
 * Implemented by: 
 *      status_state10
 */
 
typedef struct
{
     unsigned  int                otpversion;
} ncp_nca_otp_status_state10_r_t;

/*! @struct ncp_nca_otp_counter_drop_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count the number of tasks dropped
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_drop_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_drop </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of tasks dropped </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_drop_r_t
 *
 * Implemented by: 
 *      counter_drop
 */
 
typedef struct
{
     unsigned  int                  cnt_drop;
} ncp_nca_otp_counter_drop_r_t;

/*! @struct ncp_nca_otp_counter_noop_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count the number of NOOP oPCQ task
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_noop_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_noop </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of NOOP oPCQ task </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_noop_r_t
 *
 * Implemented by: 
 *      counter_noop
 */
 
typedef struct
{
     unsigned  int                  cnt_noop;
} ncp_nca_otp_counter_noop_r_t;

/*! @struct ncp_nca_otp_counter_sndtsk_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count the number of SENDTASK oPCQ task
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_sndtsk_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_sndtsk </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of SENDTASK oPCQ task </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_sndtsk_r_t
 *
 * Implemented by: 
 *      counter_sndtsk
 */
 
typedef struct
{
     unsigned  int                cnt_sndtsk;
} ncp_nca_otp_counter_sndtsk_r_t;

/*! @struct ncp_nca_otp_counter_cpcq_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count the number of CPCQ oPCQ task
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_cpcq_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_cpcq </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of CPCQ oPCQ task </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_cpcq_r_t
 *
 * Implemented by: 
 *      counter_cpcq
 */
 
typedef struct
{
     unsigned  int                  cnt_cpcq;
} ncp_nca_otp_counter_cpcq_r_t;

/*! @struct ncp_nca_otp_counter_adpah_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count the number of ADPAH oPCQ task
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_adpah_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_adpah </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of ADPAH oPCQ task </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_adpah_r_t
 *
 * Implemented by: 
 *      counter_adpah
 */
 
typedef struct
{
     unsigned  int                 cnt_adpah;
} ncp_nca_otp_counter_adpah_r_t;

/*! @struct ncp_nca_otp_counter_adpae_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count the number of ADPAE oPCQ task
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_adpae_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_adpae </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of ADPAE oPCQ task </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_adpae_r_t
 *
 * Implemented by: 
 *      counter_adpae
 */
 
typedef struct
{
     unsigned  int                 cnt_adpae;
} ncp_nca_otp_counter_adpae_r_t;

/*! @struct ncp_nca_otp_counter_completion_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count the number of COMPLETION oPCQ task
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_completion_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_completion </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of COMPLETION oPCQ task </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_completion_r_t
 *
 * Implemented by: 
 *      counter_completion
 */
 
typedef struct
{
     unsigned  int            cnt_completion;
} ncp_nca_otp_counter_completion_r_t;

/*! @struct ncp_nca_otp_counter_copy_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. COunt the number of oPCQ SENDTASK copied
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_copy_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_copy </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> COunt the number of oPCQ SENDTASK copied </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_copy_r_t
 *
 * Implemented by: 
 *      counter_copy
 */
 
typedef struct
{
     unsigned  int                  cnt_copy;
} ncp_nca_otp_counter_copy_r_t;

/*! @struct ncp_nca_otp_counter_flowcontrol_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. COunt the nymber of oPCQ task with flow control
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_flowcontrol_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_flowcontrol </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> COunt the nymber of oPCQ task with flow control </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_flowcontrol_r_t
 *
 * Implemented by: 
 *      counter_flowcontrol
 */
 
typedef struct
{
     unsigned  int           cnt_flowcontrol;
} ncp_nca_otp_counter_flowcontrol_r_t;

/*! @struct ncp_nca_otp_counter_nlink_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. COunt the number of operations on the NLINK req
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_nlink_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_nlink </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> COunt the number of operations on the NLINK req </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_nlink_r_t
 *
 * Implemented by: 
 *      counter_nlink
 */
 
typedef struct
{
     unsigned  int                 cnt_nlink;
} ncp_nca_otp_counter_nlink_r_t;

/*! @struct ncp_nca_otp_counter_tdgl_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. COunt the number of operations on TDGL interface
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_tdgl_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_tdgl </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> COunt the number of operations on TDGL interface </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_tdgl_r_t
 *
 * Implemented by: 
 *      counter_tdgl
 */
 
typedef struct
{
     unsigned  int                  cnt_tdgl;
} ncp_nca_otp_counter_tdgl_r_t;

/*! @struct ncp_nca_otp_counter_ncav3_opcq_req_awready_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Counter when oPCQ NLINK req ready is low
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_ncav3_opcq_req_awready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_ncav3_opcq_req_awready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when oPCQ NLINK req ready is low </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_ncav3_opcq_req_awready_r_t
 *
 * Implemented by: 
 *      counter_ncav3_opcq_req_awready
 */
 
typedef struct
{
     unsigned  int      cnt_ncav3_opcq_req_awready;
} ncp_nca_otp_counter_ncav3_opcq_req_awready_r_t;

/*! @struct ncp_nca_otp_counter_ncav3_opcq_res_awready_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Counter when oPCQ NLINK resp ready is low
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_ncav3_opcq_res_awready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_ncav3_opcq_res_awready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when oPCQ NLINK resp ready is low </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_ncav3_opcq_res_awready_r_t
 *
 * Implemented by: 
 *      counter_ncav3_opcq_res_awready
 */
 
typedef struct
{
     unsigned  int      cnt_ncav3_opcq_res_awready;
} ncp_nca_otp_counter_ncav3_opcq_res_awready_r_t;

/*! @struct ncp_nca_otp_counter_tdgl_eng_bp_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Counter when TDGL bp is asserted
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_tdgl_eng_bp_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_tdgl_eng_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when TDGL bp is asserted </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_tdgl_eng_bp_r_t
 *
 * Implemented by: 
 *      counter_tdgl_eng_bp
 */
 
typedef struct
{
     unsigned  int           cnt_tdgl_eng_bp;
} ncp_nca_otp_counter_tdgl_eng_bp_r_t;

/*! @struct ncp_nca_otp_counter_cmn_cpcq_req_awready_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Counter when CMN req ready is low
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_cmn_cpcq_req_awready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_cmn_cpcq_req_awready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when CMN req ready is low </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_cmn_cpcq_req_awready_r_t
 *
 * Implemented by: 
 *      counter_cmn_cpcq_req_awready
 */
 
typedef struct
{
     unsigned  int      cnt_cmn_cpcq_req_awready;
} ncp_nca_otp_counter_cmn_cpcq_req_awready_r_t;

/*! @struct ncp_nca_otp_counter_cmn_cpcq_resp_awready_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Counter when CMN resp ready is low
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_cmn_cpcq_resp_awready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_cmn_cpcq_resp_awready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when CMN resp ready is low </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_cmn_cpcq_resp_awready_r_t
 *
 * Implemented by: 
 *      counter_cmn_cpcq_resp_awready
 */
 
typedef struct
{
     unsigned  int      cnt_cmn_cpcq_resp_awready;
} ncp_nca_otp_counter_cmn_cpcq_resp_awready_r_t;

/*! @struct ncp_nca_otp_counter_otp_itp_tx_awready_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Counter when OTP to ITP completion ready is low
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_otp_itp_tx_awready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_otp_itp_tx_awready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when OTP to ITP completion ready
 *        is low
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_otp_itp_tx_awready_r_t
 *
 * Implemented by: 
 *      counter_otp_itp_tx_awready
 */
 
typedef struct
{
     unsigned  int      cnt_otp_itp_tx_awready;
} ncp_nca_otp_counter_otp_itp_tx_awready_r_t;

/*! @struct ncp_nca_otp_counter_otp_mtp_req_awready_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Counter when OTP to MTP req ready is low
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_otp_mtp_req_awready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_otp_mtp_req_awready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when OTP to MTP req ready is low </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_otp_mtp_req_awready_r_t
 *
 * Implemented by: 
 *      counter_otp_mtp_req_awready
 */
 
typedef struct
{
     unsigned  int      cnt_otp_mtp_req_awready;
} ncp_nca_otp_counter_otp_mtp_req_awready_r_t;

/*! @struct ncp_nca_otp_counter_mtp_otp_res_awready_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Counter when MTP to OTP response ready is low
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_mtp_otp_res_awready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_mtp_otp_res_awready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when MTP to OTP response ready
 *        is low
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_mtp_otp_res_awready_r_t
 *
 * Implemented by: 
 *      counter_mtp_otp_res_awready
 */
 
typedef struct
{
     unsigned  int      cnt_mtp_otp_res_awready;
} ncp_nca_otp_counter_mtp_otp_res_awready_r_t;

/*! @struct ncp_nca_otp_counter_dma_read_cpu_rr_ready_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Counter when dma engine for CPU  task header is bp
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_dma_read_cpu_rr_ready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_dma_read_cpu_rr_ready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when dma engine for CPU task header
 *        is bp
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_dma_read_cpu_rr_ready_r_t
 *
 * Implemented by: 
 *      counter_dma_read_cpu_rr_ready
 */
 
typedef struct
{
     unsigned  int      cnt_dma_read_cpu_rr_ready;
} ncp_nca_otp_counter_dma_read_cpu_rr_ready_r_t;

/*! @struct ncp_nca_otp_counter_dma_read_data_rr_ready_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Counter when dma engine for copy data is bp
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_dma_read_data_rr_ready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_dma_read_data_rr_ready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when dma engine for copy data is
 *        bp
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_dma_read_data_rr_ready_r_t
 *
 * Implemented by: 
 *      counter_dma_read_data_rr_ready
 */
 
typedef struct
{
     unsigned  int      cnt_dma_read_data_rr_ready;
} ncp_nca_otp_counter_dma_read_data_rr_ready_r_t;

/*! @struct ncp_nca_otp_counter_multi_fifo_fifo_afull_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Counter when multi FIFO is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_multi_fifo_fifo_afull_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_multi_fifo_fifo_afull </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when multi FIFO is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_multi_fifo_fifo_afull_r_t
 *
 * Implemented by: 
 *      counter_multi_fifo_fifo_afull
 */
 
typedef struct
{
     unsigned  int      cnt_multi_fifo_fifo_afull;
} ncp_nca_otp_counter_multi_fifo_fifo_afull_r_t;

/*! @struct ncp_nca_otp_counter_oll_isel_full_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Counter when ISEL LL is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_oll_isel_full_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_oll_isel_full </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when ISEL LL is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_oll_isel_full_r_t
 *
 * Implemented by: 
 *      counter_oll_isel_full
 */
 
typedef struct
{
     unsigned  int         cnt_oll_isel_full;
} ncp_nca_otp_counter_oll_isel_full_r_t;

/*! @struct ncp_nca_otp_counter_oll_rsel_full_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Counter when RSEL LL is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_oll_rsel_full_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_oll_rsel_full </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when RSEL LL is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_oll_rsel_full_r_t
 *
 * Implemented by: 
 *      counter_oll_rsel_full
 */
 
typedef struct
{
     unsigned  int         cnt_oll_rsel_full;
} ncp_nca_otp_counter_oll_rsel_full_r_t;

/*! @struct ncp_nca_otp_counter_oll_sndtsk_full_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Counter when SENDTASK LL is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_oll_sndtsk_full_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_oll_sndtsk_full </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when SENDTASK LL is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_oll_sndtsk_full_r_t
 *
 * Implemented by: 
 *      counter_oll_sndtsk_full
 */
 
typedef struct
{
     unsigned  int       cnt_oll_sndtsk_full;
} ncp_nca_otp_counter_oll_sndtsk_full_r_t;

/*! @struct ncp_nca_otp_counter_fifoafull0_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Count when FIFO 00 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_fifoafull0_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 00 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_fifoafull0_r_t
 *
 * Implemented by: 
 *      counter_fifoafull0
 */
 
typedef struct
{
     unsigned  int            cnt_fifoafull0;
} ncp_nca_otp_counter_fifoafull0_r_t;

/*! @struct ncp_nca_otp_counter_fifoafull1_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Count when FIFO 01 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_fifoafull1_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull1 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 01 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_fifoafull1_r_t
 *
 * Implemented by: 
 *      counter_fifoafull1
 */
 
typedef struct
{
     unsigned  int            cnt_fifoafull1;
} ncp_nca_otp_counter_fifoafull1_r_t;

/*! @struct ncp_nca_otp_counter_fifoafull2_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Count when FIFO 02 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_fifoafull2_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull2 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 02 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_fifoafull2_r_t
 *
 * Implemented by: 
 *      counter_fifoafull2
 */
 
typedef struct
{
     unsigned  int            cnt_fifoafull2;
} ncp_nca_otp_counter_fifoafull2_r_t;

/*! @struct ncp_nca_otp_counter_fifoafull3_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Count when FIFO 03 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_fifoafull3_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull3 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 03 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_fifoafull3_r_t
 *
 * Implemented by: 
 *      counter_fifoafull3
 */
 
typedef struct
{
     unsigned  int            cnt_fifoafull3;
} ncp_nca_otp_counter_fifoafull3_r_t;

/*! @struct ncp_nca_otp_counter_fifoafull4_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Count when FIFO 04 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_fifoafull4_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull4 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 04 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_fifoafull4_r_t
 *
 * Implemented by: 
 *      counter_fifoafull4
 */
 
typedef struct
{
     unsigned  int            cnt_fifoafull4;
} ncp_nca_otp_counter_fifoafull4_r_t;

/*! @struct ncp_nca_otp_counter_fifoafull5_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Count when FIFO 05 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_fifoafull5_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull5 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 05 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_fifoafull5_r_t
 *
 * Implemented by: 
 *      counter_fifoafull5
 */
 
typedef struct
{
     unsigned  int            cnt_fifoafull5;
} ncp_nca_otp_counter_fifoafull5_r_t;

/*! @struct ncp_nca_otp_counter_fifoafull6_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Count when FIFO 06 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_fifoafull6_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull6 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 06 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_fifoafull6_r_t
 *
 * Implemented by: 
 *      counter_fifoafull6
 */
 
typedef struct
{
     unsigned  int            cnt_fifoafull6;
} ncp_nca_otp_counter_fifoafull6_r_t;

/*! @struct ncp_nca_otp_counter_fifoafull7_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Count when FIFO 07 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_fifoafull7_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull7 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 07 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_fifoafull7_r_t
 *
 * Implemented by: 
 *      counter_fifoafull7
 */
 
typedef struct
{
     unsigned  int            cnt_fifoafull7;
} ncp_nca_otp_counter_fifoafull7_r_t;

/*! @struct ncp_nca_otp_counter_fifoafull8_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Count when FIFO 08 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_fifoafull8_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull8 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 08 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_fifoafull8_r_t
 *
 * Implemented by: 
 *      counter_fifoafull8
 */
 
typedef struct
{
     unsigned  int            cnt_fifoafull8;
} ncp_nca_otp_counter_fifoafull8_r_t;

/*! @struct ncp_nca_otp_counter_fifoafull9_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Count when FIFO 09 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_fifoafull9_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull9 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 09 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_fifoafull9_r_t
 *
 * Implemented by: 
 *      counter_fifoafull9
 */
 
typedef struct
{
     unsigned  int            cnt_fifoafull9;
} ncp_nca_otp_counter_fifoafull9_r_t;

/*! @struct ncp_nca_otp_counter_fifoafull10_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Count when FIFO 10 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_fifoafull10_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull10 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 10 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_fifoafull10_r_t
 *
 * Implemented by: 
 *      counter_fifoafull10
 */
 
typedef struct
{
     unsigned  int           cnt_fifoafull10;
} ncp_nca_otp_counter_fifoafull10_r_t;

/*! @struct ncp_nca_otp_counter_fifoafull11_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. BOTTLENECK Count when FIFO 11 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_fifoafull11_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull11 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 11 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_fifoafull11_r_t
 *
 * Implemented by: 
 *      counter_fifoafull11
 */
 
typedef struct
{
     unsigned  int           cnt_fifoafull11;
} ncp_nca_otp_counter_fifoafull11_r_t;

/*! @struct ncp_nca_otp_counter_pointer_entry_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. POINTER Count the number of pointers delivered in oPCQ task entry
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_pointer_entry_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_pointer_entry </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> POINTER Count the number of pointers delivered in
 *        oPCQ task entry
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_pointer_entry_r_t
 *
 * Implemented by: 
 *      counter_pointer_entry
 */
 
typedef struct
{
     unsigned  int         cnt_pointer_entry;
} ncp_nca_otp_counter_pointer_entry_r_t;

/*! @struct ncp_nca_otp_counter_pointer_header0_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. POINTER Count the number of pointers delivered in task header
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_pointer_header0_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_pointer_header0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> POINTER Count the number of pointers delivered in
 *        task header
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_pointer_header0_r_t
 *
 * Implemented by: 
 *      counter_pointer_header0
 */
 
typedef struct
{
     unsigned  int       cnt_pointer_header0;
} ncp_nca_otp_counter_pointer_header0_r_t;

/*! @struct ncp_nca_otp_counter_pointer_header1_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. POINTER Count the number of pointers delivered in task header
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_pointer_header1_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_pointer_header1 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> POINTER Count the number of pointers delivered in
 *        task header
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_pointer_header1_r_t
 *
 * Implemented by: 
 *      counter_pointer_header1
 */
 
typedef struct
{
     unsigned  int       cnt_pointer_header1;
} ncp_nca_otp_counter_pointer_header1_r_t;

/*! @struct ncp_nca_otp_counter_pointer_itp_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. POINTER Count the number of pointers delivred from ITP to deallocate
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_pointer_itp_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_pointer_itp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> POINTER Count the number of pointers delivred from
 *        ITP to deallocate
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_pointer_itp_r_t
 *
 * Implemented by: 
 *      counter_pointer_itp
 */
 
typedef struct
{
     unsigned  int           cnt_pointer_itp;
} ncp_nca_otp_counter_pointer_itp_r_t;

/*! @struct ncp_nca_otp_counter_pointer_mtp_inc_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. POINTER Count the number of pointer increments sent to MTP
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_pointer_mtp_inc_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_pointer_mtp_inc </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> POINTER Count the number of pointer increments sent
 *        to MTP
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_pointer_mtp_inc_r_t
 *
 * Implemented by: 
 *      counter_pointer_mtp_inc
 */
 
typedef struct
{
     unsigned  int       cnt_pointer_mtp_inc;
} ncp_nca_otp_counter_pointer_mtp_inc_r_t;

/*! @struct ncp_nca_otp_counter_pointer_mtp_dec_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. POINTER Count the number of pointer decrements sent to MTP
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_pointer_mtp_dec_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_pointer_mtp_dec </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> POINTER Count the number of pointer decrements sent
 *        to MTP
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_pointer_mtp_dec_r_t
 *
 * Implemented by: 
 *      counter_pointer_mtp_dec
 */
 
typedef struct
{
     unsigned  int       cnt_pointer_mtp_dec;
} ncp_nca_otp_counter_pointer_mtp_dec_r_t;

/*! @struct ncp_nca_otp_counter_pointer_tdgl_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. POINTER Count the number of pointers sent to TDGL
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_pointer_tdgl_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_pointer_tdgl </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> POINTER Count the number of pointers sent to TDGL </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_pointer_tdgl_r_t
 *
 * Implemented by: 
 *      counter_pointer_tdgl
 */
 
typedef struct
{
     unsigned  int          cnt_pointer_tdgl;
} ncp_nca_otp_counter_pointer_tdgl_r_t;

/*! @struct ncp_nca_otp_counter_pointer_sndtsk_rccd1_pktcopy_mrefis0_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. POINTER Count the number of times MREF correction is performed on the case where cmd=SNDTSK RCCD=1 copy packet data and segment MREF=0
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_pointer_sndtsk_rccd1_pktcopy_mrefis0_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_pointer_sndtsk_rccd1_pktcopy_mrefis0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> POINTER Count the number of times MREF correction
 *        is performed on the case where cmd=SNDTSK RCCD=1 copy
 *        packet data and segment MREF=0
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_pointer_sndtsk_rccd1_pktcopy_mrefis0_r_t
 *
 * Implemented by: 
 *      counter_pointer_sndtsk_rccd1_pktcopy_mrefis0
 */
 
typedef struct
{
     unsigned  int      cnt_pointer_sndtsk_rccd1_pktcopy_mrefis0;
} ncp_nca_otp_counter_pointer_sndtsk_rccd1_pktcopy_mrefis0_r_t;

/*! @struct ncp_nca_otp_counter_cp_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count the number of COMPLETION oPCQ task
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_cp_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_cp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of COMPLETION oPCQ task </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_cp_r_t
 *
 * Implemented by: 
 *      counter_cp
 */
 
typedef struct
{
     unsigned  int                    cnt_cp;
} ncp_nca_otp_counter_cp_r_t;

/*! @struct ncp_nca_otp_counter_refcnti_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count the number of refcnt increments
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_refcnti_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_refcnti </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of refcnt increments </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_refcnti_r_t
 *
 * Implemented by: 
 *      counter_refcnti
 */
 
typedef struct
{
     unsigned  int               cnt_refcnti;
} ncp_nca_otp_counter_refcnti_r_t;

/*! @struct ncp_nca_otp_counter_refcntd_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count the number of refcnt decrements
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_refcntd_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_refcntd </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of refcnt decrements </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_refcntd_r_t
 *
 * Implemented by: 
 *      counter_refcntd
 */
 
typedef struct
{
     unsigned  int               cnt_refcntd;
} ncp_nca_otp_counter_refcntd_r_t;

/*! @struct ncp_nca_otp_counter_mqgi_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count the number of mqg increments
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_mqgi_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_mqgi </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of mqg increments </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_mqgi_r_t
 *
 * Implemented by: 
 *      counter_mqgi
 */
 
typedef struct
{
     unsigned  int                  cnt_mqgi;
} ncp_nca_otp_counter_mqgi_r_t;

/*! @struct ncp_nca_otp_counter_mqgd_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count the number of mqg decrements
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_mqgd_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_mqgd </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of mqg decrements </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_mqgd_r_t
 *
 * Implemented by: 
 *      counter_mqgd
 */
 
typedef struct
{
     unsigned  int                  cnt_mqgd;
} ncp_nca_otp_counter_mqgd_r_t;

/*! @struct ncp_nca_otp_counter_ptrcnt0_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. Count the number of task header with PTRCNT=0
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_counter_ptrcnt0_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_ptrcnt0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of task header with PTRCNT=0 </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_counter_ptrcnt0_r_t
 *
 * Implemented by: 
 *      counter_ptrcnt0
 */
 
typedef struct
{
     unsigned  int               cnt_ptrcnt0;
} ncp_nca_otp_counter_ptrcnt0_r_t;

/*! @struct ncp_nca_otp_cor_counter_drop_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count the number of tasks dropped
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_drop_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_drop </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of tasks dropped </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_drop_r_t
 *
 * Implemented by: 
 *      cor_counter_drop
 */
 
typedef struct
{
     unsigned  int                  cnt_drop;
} ncp_nca_otp_cor_counter_drop_r_t;

/*! @struct ncp_nca_otp_cor_counter_noop_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count the number of NOOP oPCQ task
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_noop_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_noop </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of NOOP oPCQ task </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_noop_r_t
 *
 * Implemented by: 
 *      cor_counter_noop
 */
 
typedef struct
{
     unsigned  int                  cnt_noop;
} ncp_nca_otp_cor_counter_noop_r_t;

/*! @struct ncp_nca_otp_cor_counter_sndtsk_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count the number of SENDTASK oPCQ task
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_sndtsk_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_sndtsk </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of SENDTASK oPCQ task </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_sndtsk_r_t
 *
 * Implemented by: 
 *      cor_counter_sndtsk
 */
 
typedef struct
{
     unsigned  int                cnt_sndtsk;
} ncp_nca_otp_cor_counter_sndtsk_r_t;

/*! @struct ncp_nca_otp_cor_counter_cpcq_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count the number of CPCQ oPCQ task
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_cpcq_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_cpcq </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of CPCQ oPCQ task </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_cpcq_r_t
 *
 * Implemented by: 
 *      cor_counter_cpcq
 */
 
typedef struct
{
     unsigned  int                  cnt_cpcq;
} ncp_nca_otp_cor_counter_cpcq_r_t;

/*! @struct ncp_nca_otp_cor_counter_adpah_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count the number of ADPAH oPCQ task
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_adpah_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_adpah </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of ADPAH oPCQ task </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_adpah_r_t
 *
 * Implemented by: 
 *      cor_counter_adpah
 */
 
typedef struct
{
     unsigned  int                 cnt_adpah;
} ncp_nca_otp_cor_counter_adpah_r_t;

/*! @struct ncp_nca_otp_cor_counter_adpae_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count the number of ADPAE oPCQ task
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_adpae_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_adpae </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of ADPAE oPCQ task </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_adpae_r_t
 *
 * Implemented by: 
 *      cor_counter_adpae
 */
 
typedef struct
{
     unsigned  int                 cnt_adpae;
} ncp_nca_otp_cor_counter_adpae_r_t;

/*! @struct ncp_nca_otp_cor_counter_completion_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count the number of COMPLETION oPCQ task
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_completion_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_completion </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of COMPLETION oPCQ task </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_completion_r_t
 *
 * Implemented by: 
 *      cor_counter_completion
 */
 
typedef struct
{
     unsigned  int            cnt_completion;
} ncp_nca_otp_cor_counter_completion_r_t;

/*! @struct ncp_nca_otp_cor_counter_copy_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  COunt the number of oPCQ SENDTASK copied
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_copy_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_copy </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> COunt the number of oPCQ SENDTASK copied </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_copy_r_t
 *
 * Implemented by: 
 *      cor_counter_copy
 */
 
typedef struct
{
     unsigned  int                  cnt_copy;
} ncp_nca_otp_cor_counter_copy_r_t;

/*! @struct ncp_nca_otp_cor_counter_flowcontrol_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  COunt the nymber of oPCQ task with flow control
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_flowcontrol_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_flowcontrol </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> COunt the nymber of oPCQ task with flow control </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_flowcontrol_r_t
 *
 * Implemented by: 
 *      cor_counter_flowcontrol
 */
 
typedef struct
{
     unsigned  int           cnt_flowcontrol;
} ncp_nca_otp_cor_counter_flowcontrol_r_t;

/*! @struct ncp_nca_otp_cor_counter_nlink_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  COunt the number of operations on the NLINK req
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_nlink_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_nlink </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> COunt the number of operations on the NLINK req </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_nlink_r_t
 *
 * Implemented by: 
 *      cor_counter_nlink
 */
 
typedef struct
{
     unsigned  int                 cnt_nlink;
} ncp_nca_otp_cor_counter_nlink_r_t;

/*! @struct ncp_nca_otp_cor_counter_tdgl_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  COunt the number of operations on TDGL interface
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_tdgl_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_tdgl </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> COunt the number of operations on TDGL interface </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_tdgl_r_t
 *
 * Implemented by: 
 *      cor_counter_tdgl
 */
 
typedef struct
{
     unsigned  int                  cnt_tdgl;
} ncp_nca_otp_cor_counter_tdgl_r_t;

/*! @struct ncp_nca_otp_cor_counter_ncav3_opcq_req_awready_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Counter when oPCQ NLINK req ready is low
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_ncav3_opcq_req_awready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_ncav3_opcq_req_awready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when oPCQ NLINK req ready is low </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_ncav3_opcq_req_awready_r_t
 *
 * Implemented by: 
 *      cor_counter_ncav3_opcq_req_awready
 */
 
typedef struct
{
     unsigned  int      cnt_ncav3_opcq_req_awready;
} ncp_nca_otp_cor_counter_ncav3_opcq_req_awready_r_t;

/*! @struct ncp_nca_otp_cor_counter_ncav3_opcq_res_awready_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Counter when oPCQ NLINK resp ready is low
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_ncav3_opcq_res_awready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_ncav3_opcq_res_awready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when oPCQ NLINK resp ready is low </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_ncav3_opcq_res_awready_r_t
 *
 * Implemented by: 
 *      cor_counter_ncav3_opcq_res_awready
 */
 
typedef struct
{
     unsigned  int      cnt_ncav3_opcq_res_awready;
} ncp_nca_otp_cor_counter_ncav3_opcq_res_awready_r_t;

/*! @struct ncp_nca_otp_cor_counter_tdgl_eng_bp_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Counter when TDGL bp is asserted
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_tdgl_eng_bp_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_tdgl_eng_bp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when TDGL bp is asserted </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_tdgl_eng_bp_r_t
 *
 * Implemented by: 
 *      cor_counter_tdgl_eng_bp
 */
 
typedef struct
{
     unsigned  int           cnt_tdgl_eng_bp;
} ncp_nca_otp_cor_counter_tdgl_eng_bp_r_t;

/*! @struct ncp_nca_otp_cor_counter_cmn_cpcq_req_awready_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Counter when CMN req ready is low
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_cmn_cpcq_req_awready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_cmn_cpcq_req_awready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when CMN req ready is low </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_cmn_cpcq_req_awready_r_t
 *
 * Implemented by: 
 *      cor_counter_cmn_cpcq_req_awready
 */
 
typedef struct
{
     unsigned  int      cnt_cmn_cpcq_req_awready;
} ncp_nca_otp_cor_counter_cmn_cpcq_req_awready_r_t;

/*! @struct ncp_nca_otp_cor_counter_cmn_cpcq_resp_awready_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Counter when CMN resp ready is low
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_cmn_cpcq_resp_awready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_cmn_cpcq_resp_awready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when CMN resp ready is low </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_cmn_cpcq_resp_awready_r_t
 *
 * Implemented by: 
 *      cor_counter_cmn_cpcq_resp_awready
 */
 
typedef struct
{
     unsigned  int      cnt_cmn_cpcq_resp_awready;
} ncp_nca_otp_cor_counter_cmn_cpcq_resp_awready_r_t;

/*! @struct ncp_nca_otp_cor_counter_otp_itp_tx_awready_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Counter when OTP to ITP completion ready is low
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_otp_itp_tx_awready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_otp_itp_tx_awready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when OTP to ITP completion ready
 *        is low
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_otp_itp_tx_awready_r_t
 *
 * Implemented by: 
 *      cor_counter_otp_itp_tx_awready
 */
 
typedef struct
{
     unsigned  int      cnt_otp_itp_tx_awready;
} ncp_nca_otp_cor_counter_otp_itp_tx_awready_r_t;

/*! @struct ncp_nca_otp_cor_counter_otp_mtp_req_awready_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Counter when OTP to MTP req ready is low
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_otp_mtp_req_awready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_otp_mtp_req_awready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when OTP to MTP req ready is low </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_otp_mtp_req_awready_r_t
 *
 * Implemented by: 
 *      cor_counter_otp_mtp_req_awready
 */
 
typedef struct
{
     unsigned  int      cnt_otp_mtp_req_awready;
} ncp_nca_otp_cor_counter_otp_mtp_req_awready_r_t;

/*! @struct ncp_nca_otp_cor_counter_mtp_otp_res_awready_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Counter when MTP to OTP response ready is low
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_mtp_otp_res_awready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_mtp_otp_res_awready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when MTP to OTP response ready
 *        is low
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_mtp_otp_res_awready_r_t
 *
 * Implemented by: 
 *      cor_counter_mtp_otp_res_awready
 */
 
typedef struct
{
     unsigned  int      cnt_mtp_otp_res_awready;
} ncp_nca_otp_cor_counter_mtp_otp_res_awready_r_t;

/*! @struct ncp_nca_otp_cor_counter_dma_read_cpu_rr_ready_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Counter when dma engine for CPU  task header is bp
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_dma_read_cpu_rr_ready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_dma_read_cpu_rr_ready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when dma engine for CPU task header
 *        is bp
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_dma_read_cpu_rr_ready_r_t
 *
 * Implemented by: 
 *      cor_counter_dma_read_cpu_rr_ready
 */
 
typedef struct
{
     unsigned  int      cnt_dma_read_cpu_rr_ready;
} ncp_nca_otp_cor_counter_dma_read_cpu_rr_ready_r_t;

/*! @struct ncp_nca_otp_cor_counter_dma_read_data_rr_ready_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Counter when dma engine for copy data is bp
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_dma_read_data_rr_ready_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_dma_read_data_rr_ready </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when dma engine for copy data is
 *        bp
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_dma_read_data_rr_ready_r_t
 *
 * Implemented by: 
 *      cor_counter_dma_read_data_rr_ready
 */
 
typedef struct
{
     unsigned  int      cnt_dma_read_data_rr_ready;
} ncp_nca_otp_cor_counter_dma_read_data_rr_ready_r_t;

/*! @struct ncp_nca_otp_cor_counter_multi_fifo_fifo_afull_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Counter when multi FIFO is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_multi_fifo_fifo_afull_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_multi_fifo_fifo_afull </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when multi FIFO is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_multi_fifo_fifo_afull_r_t
 *
 * Implemented by: 
 *      cor_counter_multi_fifo_fifo_afull
 */
 
typedef struct
{
     unsigned  int      cnt_multi_fifo_fifo_afull;
} ncp_nca_otp_cor_counter_multi_fifo_fifo_afull_r_t;

/*! @struct ncp_nca_otp_cor_counter_oll_isel_full_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Counter when ISEL LL is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_oll_isel_full_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_oll_isel_full </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when ISEL LL is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_oll_isel_full_r_t
 *
 * Implemented by: 
 *      cor_counter_oll_isel_full
 */
 
typedef struct
{
     unsigned  int         cnt_oll_isel_full;
} ncp_nca_otp_cor_counter_oll_isel_full_r_t;

/*! @struct ncp_nca_otp_cor_counter_oll_rsel_full_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Counter when RSEL LL is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_oll_rsel_full_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_oll_rsel_full </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when RSEL LL is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_oll_rsel_full_r_t
 *
 * Implemented by: 
 *      cor_counter_oll_rsel_full
 */
 
typedef struct
{
     unsigned  int         cnt_oll_rsel_full;
} ncp_nca_otp_cor_counter_oll_rsel_full_r_t;

/*! @struct ncp_nca_otp_cor_counter_oll_sndtsk_full_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Counter when SENDTASK LL is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_oll_sndtsk_full_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_oll_sndtsk_full </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Counter when SENDTASK LL is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_oll_sndtsk_full_r_t
 *
 * Implemented by: 
 *      cor_counter_oll_sndtsk_full
 */
 
typedef struct
{
     unsigned  int       cnt_oll_sndtsk_full;
} ncp_nca_otp_cor_counter_oll_sndtsk_full_r_t;

/*! @struct ncp_nca_otp_cor_counter_fifoafull0_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Count when FIFO 00 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_fifoafull0_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 00 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_fifoafull0_r_t
 *
 * Implemented by: 
 *      cor_counter_fifoafull0
 */
 
typedef struct
{
     unsigned  int            cnt_fifoafull0;
} ncp_nca_otp_cor_counter_fifoafull0_r_t;

/*! @struct ncp_nca_otp_cor_counter_fifoafull1_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Count when FIFO 01 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_fifoafull1_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull1 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 01 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_fifoafull1_r_t
 *
 * Implemented by: 
 *      cor_counter_fifoafull1
 */
 
typedef struct
{
     unsigned  int            cnt_fifoafull1;
} ncp_nca_otp_cor_counter_fifoafull1_r_t;

/*! @struct ncp_nca_otp_cor_counter_fifoafull2_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Count when FIFO 02 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_fifoafull2_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull2 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 02 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_fifoafull2_r_t
 *
 * Implemented by: 
 *      cor_counter_fifoafull2
 */
 
typedef struct
{
     unsigned  int            cnt_fifoafull2;
} ncp_nca_otp_cor_counter_fifoafull2_r_t;

/*! @struct ncp_nca_otp_cor_counter_fifoafull3_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Count when FIFO 03 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_fifoafull3_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull3 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 03 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_fifoafull3_r_t
 *
 * Implemented by: 
 *      cor_counter_fifoafull3
 */
 
typedef struct
{
     unsigned  int            cnt_fifoafull3;
} ncp_nca_otp_cor_counter_fifoafull3_r_t;

/*! @struct ncp_nca_otp_cor_counter_fifoafull4_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Count when FIFO 04 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_fifoafull4_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull4 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 04 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_fifoafull4_r_t
 *
 * Implemented by: 
 *      cor_counter_fifoafull4
 */
 
typedef struct
{
     unsigned  int            cnt_fifoafull4;
} ncp_nca_otp_cor_counter_fifoafull4_r_t;

/*! @struct ncp_nca_otp_cor_counter_fifoafull5_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Count when FIFO 05 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_fifoafull5_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull5 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 05 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_fifoafull5_r_t
 *
 * Implemented by: 
 *      cor_counter_fifoafull5
 */
 
typedef struct
{
     unsigned  int            cnt_fifoafull5;
} ncp_nca_otp_cor_counter_fifoafull5_r_t;

/*! @struct ncp_nca_otp_cor_counter_fifoafull6_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Count when FIFO 06 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_fifoafull6_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull6 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 06 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_fifoafull6_r_t
 *
 * Implemented by: 
 *      cor_counter_fifoafull6
 */
 
typedef struct
{
     unsigned  int            cnt_fifoafull6;
} ncp_nca_otp_cor_counter_fifoafull6_r_t;

/*! @struct ncp_nca_otp_cor_counter_fifoafull7_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Count when FIFO 07 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_fifoafull7_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull7 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 07 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_fifoafull7_r_t
 *
 * Implemented by: 
 *      cor_counter_fifoafull7
 */
 
typedef struct
{
     unsigned  int            cnt_fifoafull7;
} ncp_nca_otp_cor_counter_fifoafull7_r_t;

/*! @struct ncp_nca_otp_cor_counter_fifoafull8_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Count when FIFO 08 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_fifoafull8_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull8 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 08 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_fifoafull8_r_t
 *
 * Implemented by: 
 *      cor_counter_fifoafull8
 */
 
typedef struct
{
     unsigned  int            cnt_fifoafull8;
} ncp_nca_otp_cor_counter_fifoafull8_r_t;

/*! @struct ncp_nca_otp_cor_counter_fifoafull9_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Count when FIFO 09 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_fifoafull9_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull9 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 09 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_fifoafull9_r_t
 *
 * Implemented by: 
 *      cor_counter_fifoafull9
 */
 
typedef struct
{
     unsigned  int            cnt_fifoafull9;
} ncp_nca_otp_cor_counter_fifoafull9_r_t;

/*! @struct ncp_nca_otp_cor_counter_fifoafull10_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Count when FIFO 10 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_fifoafull10_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull10 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 10 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_fifoafull10_r_t
 *
 * Implemented by: 
 *      cor_counter_fifoafull10
 */
 
typedef struct
{
     unsigned  int           cnt_fifoafull10;
} ncp_nca_otp_cor_counter_fifoafull10_r_t;

/*! @struct ncp_nca_otp_cor_counter_fifoafull11_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  BOTTLENECK Count when FIFO 11 is full
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_fifoafull11_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_fifoafull11 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> BOTTLENECK Count when FIFO 11 is full </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_fifoafull11_r_t
 *
 * Implemented by: 
 *      cor_counter_fifoafull11
 */
 
typedef struct
{
     unsigned  int           cnt_fifoafull11;
} ncp_nca_otp_cor_counter_fifoafull11_r_t;

/*! @struct ncp_nca_otp_cor_counter_pointer_entry_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  POINTER Count the number of pointers delivered in oPCQ task entry
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_pointer_entry_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_pointer_entry </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> POINTER Count the number of pointers delivered in
 *        oPCQ task entry
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_pointer_entry_r_t
 *
 * Implemented by: 
 *      cor_counter_pointer_entry
 */
 
typedef struct
{
     unsigned  int         cnt_pointer_entry;
} ncp_nca_otp_cor_counter_pointer_entry_r_t;

/*! @struct ncp_nca_otp_cor_counter_pointer_header0_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  POINTER Count the number of pointers delivered in task header
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_pointer_header0_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_pointer_header0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> POINTER Count the number of pointers delivered in
 *        task header
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_pointer_header0_r_t
 *
 * Implemented by: 
 *      cor_counter_pointer_header0
 */
 
typedef struct
{
     unsigned  int       cnt_pointer_header0;
} ncp_nca_otp_cor_counter_pointer_header0_r_t;

/*! @struct ncp_nca_otp_cor_counter_pointer_header1_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  POINTER Count the number of pointers delivered in task header
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_pointer_header1_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_pointer_header1 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> POINTER Count the number of pointers delivered in
 *        task header
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_pointer_header1_r_t
 *
 * Implemented by: 
 *      cor_counter_pointer_header1
 */
 
typedef struct
{
     unsigned  int       cnt_pointer_header1;
} ncp_nca_otp_cor_counter_pointer_header1_r_t;

/*! @struct ncp_nca_otp_cor_counter_pointer_itp_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  POINTER Count the number of pointers delivred from ITP to deallocate
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_pointer_itp_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_pointer_itp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> POINTER Count the number of pointers delivred from
 *        ITP to deallocate
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_pointer_itp_r_t
 *
 * Implemented by: 
 *      cor_counter_pointer_itp
 */
 
typedef struct
{
     unsigned  int           cnt_pointer_itp;
} ncp_nca_otp_cor_counter_pointer_itp_r_t;

/*! @struct ncp_nca_otp_cor_counter_pointer_mtp_inc_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  POINTER Count the number of pointer increments sent to MTP
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_pointer_mtp_inc_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_pointer_mtp_inc </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> POINTER Count the number of pointer increments sent
 *        to MTP
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_pointer_mtp_inc_r_t
 *
 * Implemented by: 
 *      cor_counter_pointer_mtp_inc
 */
 
typedef struct
{
     unsigned  int       cnt_pointer_mtp_inc;
} ncp_nca_otp_cor_counter_pointer_mtp_inc_r_t;

/*! @struct ncp_nca_otp_cor_counter_pointer_mtp_dec_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  POINTER Count the number of pointer decrements sent to MTP
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_pointer_mtp_dec_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_pointer_mtp_dec </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> POINTER Count the number of pointer decrements sent
 *        to MTP
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_pointer_mtp_dec_r_t
 *
 * Implemented by: 
 *      cor_counter_pointer_mtp_dec
 */
 
typedef struct
{
     unsigned  int       cnt_pointer_mtp_dec;
} ncp_nca_otp_cor_counter_pointer_mtp_dec_r_t;

/*! @struct ncp_nca_otp_cor_counter_pointer_tdgl_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  POINTER Count the number of pointers sent to TDGL
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_pointer_tdgl_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_pointer_tdgl </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> POINTER Count the number of pointers sent to TDGL </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_pointer_tdgl_r_t
 *
 * Implemented by: 
 *      cor_counter_pointer_tdgl
 */
 
typedef struct
{
     unsigned  int          cnt_pointer_tdgl;
} ncp_nca_otp_cor_counter_pointer_tdgl_r_t;

/*! @struct ncp_nca_otp_cor_counter_pointer_sndtsk_rccd1_pktcopy_mrefis0_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  POINTER Count the number of times MREF correction is performed on the case where cmd=SNDTSK RCCD=1 copy packet data and segment MREF=0
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_pointer_sndtsk_rccd1_pktcopy_mrefis0_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_pointer_sndtsk_rccd1_pktcopy_mrefis0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> POINTER Count the number of times MREF correction
 *        is performed on the case where cmd=SNDTSK RCCD=1 copy
 *        packet data and segment MREF=0
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_pointer_sndtsk_rccd1_pktcopy_mrefis0_r_t
 *
 * Implemented by: 
 *      cor_counter_pointer_sndtsk_rccd1_pktcopy_mrefis0
 */
 
typedef struct
{
     unsigned  int      cnt_pointer_sndtsk_rccd1_pktcopy_mrefis0;
} ncp_nca_otp_cor_counter_pointer_sndtsk_rccd1_pktcopy_mrefis0_r_t;

/*! @struct ncp_nca_otp_cor_counter_cp_r_t
 *  @brief null
 *  @details CFG access to Read Activity Counters. (Clear On Read).  This register is an alias to a normal counter register and reading the counter using this address as opposed to the counter's normal address results in the counter being cleared after the read.  Count the number of COMPLETION oPCQ task
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_cp_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_cp </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of COMPLETION oPCQ task </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_cp_r_t
 *
 * Implemented by: 
 *      cor_counter_cp
 */
 
typedef struct
{
     unsigned  int                    cnt_cp;
} ncp_nca_otp_cor_counter_cp_r_t;

/*! @struct ncp_nca_otp_cor_counter_refcnti_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. (Clear On Read). Count the number of refcnt increments
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_refcnti_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_refcnti </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of refcnt increments </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_refcnti_r_t
 *
 * Implemented by: 
 *      cor_counter_refcnti
 */
 
typedef struct
{
     unsigned  int               cnt_refcnti;
} ncp_nca_otp_cor_counter_refcnti_r_t;

/*! @struct ncp_nca_otp_cor_counter_refcntd_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. (Clear On Read). Count the number of refcnt decrements
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_refcntd_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_refcntd </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of refcnt decrements </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_refcntd_r_t
 *
 * Implemented by: 
 *      cor_counter_refcntd
 */
 
typedef struct
{
     unsigned  int               cnt_refcntd;
} ncp_nca_otp_cor_counter_refcntd_r_t;

/*! @struct ncp_nca_otp_cor_counter_mqgi_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. (Clear On Read). Count the number of mqg increments
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_mqgi_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_mqgi </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of mqg increments </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_mqgi_r_t
 *
 * Implemented by: 
 *      cor_counter_mqgi
 */
 
typedef struct
{
     unsigned  int                  cnt_mqgi;
} ncp_nca_otp_cor_counter_mqgi_r_t;

/*! @struct ncp_nca_otp_cor_counter_mqgd_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. (Clear On Read). Count the number of mqg decrements
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_mqgd_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_mqgd </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of mqg decrements </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_mqgd_r_t
 *
 * Implemented by: 
 *      cor_counter_mqgd
 */
 
typedef struct
{
     unsigned  int                  cnt_mqgd;
} ncp_nca_otp_cor_counter_mqgd_r_t;

/*! @struct ncp_nca_otp_cor_counter_ptrcnt0_r_t
 *  @brief null
 *  @details CFG access to Readable Activity Counters. (Clear On Read). Count the number of task header with PTRCNT=0
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cor_counter_ptrcnt0_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_ptrcnt0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Count the number of task header with PTRCNT=0 </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_cor_counter_ptrcnt0_r_t
 *
 * Implemented by: 
 *      cor_counter_ptrcnt0
 */
 
typedef struct
{
     unsigned  int               cnt_ptrcnt0;
} ncp_nca_otp_cor_counter_ptrcnt0_r_t;

/*! @struct ncp_nca_otp_cfg_setup_r_t
 *  @brief null
 *  @details cfg_setup reigster for CFG block
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_cfg_setup_r_t\n
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
 * Applies to: xlf --> ncp_nca_otp_cfg_setup_r_t
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
} ncp_nca_otp_cfg_setup_r_t;

/*! @struct ncp_nca_otp_fifo_state_ram_r_t
 *  @brief Current state for shared-RAM FIFO
 *  @details Current depth, read pointer, and write pointer for a shared-RAM FIFO.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_fifo_state_ram_r_t\n
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
 *     <td width="30%"> @param fifo_wptr </td>
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> FIFO Write Pointer </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_rptr </td>
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> FIFO Read Pointer </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_depth </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> FIFO Depth </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_fifo_state_ram_r_t
 *
 * Implemented by: 
 *      multi_fifo_state_ram_0
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  4;
     unsigned      fifo_wptr                                 :  9;
     unsigned      fifo_rptr                                 :  9;
     unsigned      fifo_depth                                : 10;
#else    /* Little Endian */
     unsigned      fifo_depth                                : 10;
     unsigned      fifo_rptr                                 :  9;
     unsigned      fifo_wptr                                 :  9;
     unsigned      reserved0                                 :  4;
#endif
} ncp_nca_otp_fifo_state_ram_r_t;

/*! @struct ncp_nca_otp_odtd_ram_r_t
 *  @brief null
 *  @details AUTOINITIALIZED: with MQG configuration BY ram_odts write.  oPCQ descriptor table indexed by the oPCQ task entry PCQ index
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_odtd_ram_r_t\n
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
 *     <td width="20%" align="center"> 27 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param mqg </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Memory Quota Group </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_odtd_ram_r_t
 *
 * Implemented by: 
 *      odtd_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 27;
     unsigned      mqg                                       :  5;
#else    /* Little Endian */
     unsigned      mqg                                       :  5;
     unsigned      reserved0                                 : 27;
#endif
} ncp_nca_otp_odtd_ram_r_t;

/*! @struct ncp_nca_otp_ll_isel_state_ram_r_t
 *  @brief Input-Selector LL state RAM
 *  @details LL state RAM. OLL is defined by 2 parameters: LL:specifies the number of linked lists supported. ENTRY: specifies the number of data entry supported. The state ram has the HP,TP,COUNT, and VALID bit for each LL. The number of ENTRY determines the width of the pointers and count
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_ll_isel_state_ram_r_t\n
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
 * Applies to: xlf --> ncp_nca_otp_ll_isel_state_ram_r_t
 *
 * Implemented by: 
 *      ll_isel_state_ram
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
} ncp_nca_otp_ll_isel_state_ram_r_t;

/*! @struct ncp_nca_otp_ll_isel_pointer_ram_r_t
 *  @brief Input-Selector LL pointer RAM
 *  @details LL pointer RAM. has the next HP for each ENTRY
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_ll_isel_pointer_ram_r_t\n
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
 * Applies to: xlf --> ncp_nca_otp_ll_isel_pointer_ram_r_t
 *
 * Implemented by: 
 *      ll_isel_pointer_ram
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
} ncp_nca_otp_ll_isel_pointer_ram_r_t;

/*! @struct ncp_nca_otp_ll_rsel_state_ram_r_t
 *  @brief Output-Selector LL state RAM
 *  @details LL state RAM. OLL is defined by 2 parameters: LL:specifies the number of linked lists supported. ENTRY: specifies the number of data entry supported. The state ram has the HP,TP,COUNT, and VALID bit for each LL. The number of ENTRY determines the width of the pointers and count
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_ll_rsel_state_ram_r_t\n
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
 * Applies to: xlf --> ncp_nca_otp_ll_rsel_state_ram_r_t
 *
 * Implemented by: 
 *      ll_rsel_state_ram
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
} ncp_nca_otp_ll_rsel_state_ram_r_t;

/*! @struct ncp_nca_otp_ll_rsel_pointer_ram_r_t
 *  @brief Output-Selector LL pointer RAM
 *  @details LL pointer RAM. has the next HP for each ENTRY
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_ll_rsel_pointer_ram_r_t\n
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
 * Applies to: xlf --> ncp_nca_otp_ll_rsel_pointer_ram_r_t
 *
 * Implemented by: 
 *      ll_rsel_pointer_ram
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
} ncp_nca_otp_ll_rsel_pointer_ram_r_t;

/*! @struct ncp_nca_otp_ll_sndtsk_state_ram_r_t
 *  @brief Sndtsk-Selector LL state RAM
 *  @details LL state RAM. OLL is defined by 2 parameters: LL:specifies the number of linked lists supported. ENTRY: specifies the number of data entry supported. The state ram has the HP,TP,COUNT, and VALID bit for each LL. The number of ENTRY determines the width of the pointers and count
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_ll_sndtsk_state_ram_r_t\n
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
 * Applies to: xlf --> ncp_nca_otp_ll_sndtsk_state_ram_r_t
 *
 * Implemented by: 
 *      ll_sndtsk_state_ram
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
} ncp_nca_otp_ll_sndtsk_state_ram_r_t;

/*! @struct ncp_nca_otp_ll_sndtsk_pointer_ram_r_t
 *  @brief Sndtsk-Selector LL pointer RAM
 *  @details LL pointer RAM. has the next HP for each ENTRY
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_otp_ll_sndtsk_pointer_ram_r_t\n
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
 * Applies to: xlf --> ncp_nca_otp_ll_sndtsk_pointer_ram_r_t
 *
 * Implemented by: 
 *      ll_sndtsk_pointer_ram
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
} ncp_nca_otp_ll_sndtsk_pointer_ram_r_t;

/*! @struct ncp_nca_otp_fifo_cfg_ram_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_otp_fifo_cfg_ram_r_t
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
 *     <td width="20%" align="center"> 25 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_base_8_2 </td>
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 7 bits of fifo_base. FIFO Base Address </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_base_1_0 </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> 2 bits of fifo_base. FIFO Base Address </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_size </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> FIFO Size </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_high_wm </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> FIFO High Watermark </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_low_wm </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> FIFO Low Watermark </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_fifo_cfg_ram_r_t
 *
 * Implemented by: 
 *      multi_fifo_cfg_ram_0
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0                                 : 25;
     unsigned      fifo_base_8_2                             :  7;
          /* word 1 */
     unsigned      fifo_base_1_0                             :  2;
     unsigned      fifo_size                                 : 10;
     unsigned      fifo_high_wm                              : 10;
     unsigned      fifo_low_wm                               : 10;
#else    /* Little Endian */
          /* word 0 */
     unsigned      fifo_base_8_2                             :  7;
     unsigned      reserved0                                 : 25;
          /* word 1 */
     unsigned      fifo_low_wm                               : 10;
     unsigned      fifo_high_wm                              : 10;
     unsigned      fifo_size                                 : 10;
     unsigned      fifo_base_1_0                             :  2;
#endif
} ncp_nca_otp_fifo_cfg_ram_r_t;

/*! @struct ncp_nca_otp_fifo_data_ram_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_otp_fifo_data_ram_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_73_42 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
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
 *     <td width="30%"> @param data_181_160 </td>
 *     <td width="20%" align="center"> 22 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 22 bits of data. data </td>
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
 * Applies to: xlf --> ncp_nca_otp_fifo_data_ram_r_t
 *
 * Implemented by: 
 *      multi_fifo_data_ram_0
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0_73_42                           : 32;
          /* word 1 */
     unsigned      reserved0_41_10                           : 32;
          /* word 2 */
     unsigned      reserved0_9_0                             : 10;
     unsigned      data_181_160                              : 22;
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
     unsigned      reserved0_73_42                           : 32;
          /* word 1 */
     unsigned      reserved0_41_10                           : 32;
          /* word 2 */
     unsigned      data_181_160                              : 22;
     unsigned      reserved0_9_0                             : 10;
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
} ncp_nca_otp_fifo_data_ram_r_t;

/*! @struct ncp_nca_otp_addrconvert_poolbaseindex_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_otp_addrconvert_poolbaseindex_r_t
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
 * Applies to: xlf --> ncp_nca_otp_addrconvert_poolbaseindex_r_t
 *
 * Implemented by: 
 *      addrconvert_entry_poolbaseindex
 *      addrconvert_data0_poolbaseindex
 *      addrconvert_data1_poolbaseindex
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
} ncp_nca_otp_addrconvert_poolbaseindex_r_t;

/*! @struct ncp_nca_otp_addrconvert_virtualbase_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_otp_addrconvert_virtualbase_r_t
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
 * Applies to: xlf --> ncp_nca_otp_addrconvert_virtualbase_r_t
 *
 * Implemented by: 
 *      addrconvert_entry_virtualbase
 *      addrconvert_data0_virtualbase
 *      addrconvert_data1_virtualbase
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
} ncp_nca_otp_addrconvert_virtualbase_r_t;

/*! @struct ncp_nca_otp_odts_ram_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_otp_odts_ram_r_t
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
 *     <td width="20%" align="center"> 25 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param opcq_9_3 </td>
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 7 bits of opcq. opcq </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param opcq_2_0 </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> 3 bits of opcq. opcq </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param endianparameter </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Endian Foramt of CPU task header paramters. 0:big
 *        1:little
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param endiantaskdata </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Endian Foramt of CPU task header 1:big 0:little </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cpupoolid </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> compressed pool CPU translate ID </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param virtualregion </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Virtual RegionID </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param copypool </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Copy PoolID. When a copy is performed use this pool.
 *        Only valid values are shared pools 2-7
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allowedpools </td>
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Allowed Pools. Bit array represing each pool (6:31
 *        7:2 8:3 9:4 10:5 11:6 12:7) when set allows a task
 *        with a pointer in this pool. When not set will force
 *        a copy.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param mqg </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Memory Quota Group </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_odts_ram_r_t
 *
 * Implemented by: 
 *      odts_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0                                 : 25;
     unsigned      opcq_9_3                                  :  7;
          /* word 1 */
     unsigned      opcq_2_0                                  :  3;
     unsigned      endianparameter                           :  1;
     unsigned      endiantaskdata                            :  1;
     unsigned      cpupoolid                                 :  5;
     unsigned      virtualregion                             :  4;
     unsigned      copypool                                  :  5;
     unsigned      allowedpools                              :  7;
     unsigned      reserved1                                 :  1;
     unsigned      mqg                                       :  5;
#else    /* Little Endian */
          /* word 0 */
     unsigned      opcq_9_3                                  :  7;
     unsigned      reserved0                                 : 25;
          /* word 1 */
     unsigned      mqg                                       :  5;
     unsigned      reserved1                                 :  1;
     unsigned      allowedpools                              :  7;
     unsigned      copypool                                  :  5;
     unsigned      virtualregion                             :  4;
     unsigned      cpupoolid                                 :  5;
     unsigned      endiantaskdata                            :  1;
     unsigned      endianparameter                           :  1;
     unsigned      opcq_2_0                                  :  3;
#endif
} ncp_nca_otp_odts_ram_r_t;

/*! @struct ncp_nca_otp_ll_isel_complete_ram_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_otp_ll_isel_complete_ram_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_273_242 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_241_210 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_209_178 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_177_146 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_145_114 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_113_82 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_81_50 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_49_18 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_17_0 </td>
 *     <td width="20%" align="center"> 18 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> 18 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_749_736 </td>
 *     <td width="20%" align="center"> 14 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 14 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_735_704 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_703_672 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_671_640 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_639_608 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_607_576 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_575_544 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_543_512 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_511_480 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_479_448 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_447_416 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_415_384 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_383_352 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_351_320 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_319_288 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_287_256 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_255_224 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_223_192 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_191_160 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_159_128 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_127_96 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_95_64 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_63_32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param completedata_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of completeData. complete data </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_ll_isel_complete_ram_r_t
 *
 * Implemented by: 
 *      ll_isel_complete_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0_273_242                         : 32;
          /* word 1 */
     unsigned      reserved0_241_210                         : 32;
          /* word 2 */
     unsigned      reserved0_209_178                         : 32;
          /* word 3 */
     unsigned      reserved0_177_146                         : 32;
          /* word 4 */
     unsigned      reserved0_145_114                         : 32;
          /* word 5 */
     unsigned      reserved0_113_82                          : 32;
          /* word 6 */
     unsigned      reserved0_81_50                           : 32;
          /* word 7 */
     unsigned      reserved0_49_18                           : 32;
          /* word 8 */
     unsigned      reserved0_17_0                            : 18;
     unsigned      completedata_749_736                      : 14;
          /* word 9 */
     unsigned      completedata_735_704                      : 32;
          /* word 10 */
     unsigned      completedata_703_672                      : 32;
          /* word 11 */
     unsigned      completedata_671_640                      : 32;
          /* word 12 */
     unsigned      completedata_639_608                      : 32;
          /* word 13 */
     unsigned      completedata_607_576                      : 32;
          /* word 14 */
     unsigned      completedata_575_544                      : 32;
          /* word 15 */
     unsigned      completedata_543_512                      : 32;
          /* word 16 */
     unsigned      completedata_511_480                      : 32;
          /* word 17 */
     unsigned      completedata_479_448                      : 32;
          /* word 18 */
     unsigned      completedata_447_416                      : 32;
          /* word 19 */
     unsigned      completedata_415_384                      : 32;
          /* word 20 */
     unsigned      completedata_383_352                      : 32;
          /* word 21 */
     unsigned      completedata_351_320                      : 32;
          /* word 22 */
     unsigned      completedata_319_288                      : 32;
          /* word 23 */
     unsigned      completedata_287_256                      : 32;
          /* word 24 */
     unsigned      completedata_255_224                      : 32;
          /* word 25 */
     unsigned      completedata_223_192                      : 32;
          /* word 26 */
     unsigned      completedata_191_160                      : 32;
          /* word 27 */
     unsigned      completedata_159_128                      : 32;
          /* word 28 */
     unsigned      completedata_127_96                       : 32;
          /* word 29 */
     unsigned      completedata_95_64                        : 32;
          /* word 30 */
     unsigned      completedata_63_32                        : 32;
          /* word 31 */
     unsigned      completedata_31_0                         : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      reserved0_273_242                         : 32;
          /* word 1 */
     unsigned      reserved0_241_210                         : 32;
          /* word 2 */
     unsigned      reserved0_209_178                         : 32;
          /* word 3 */
     unsigned      reserved0_177_146                         : 32;
          /* word 4 */
     unsigned      reserved0_145_114                         : 32;
          /* word 5 */
     unsigned      reserved0_113_82                          : 32;
          /* word 6 */
     unsigned      reserved0_81_50                           : 32;
          /* word 7 */
     unsigned      reserved0_49_18                           : 32;
          /* word 8 */
     unsigned      completedata_749_736                      : 14;
     unsigned      reserved0_17_0                            : 18;
          /* word 9 */
     unsigned      completedata_735_704                      : 32;
          /* word 10 */
     unsigned      completedata_703_672                      : 32;
          /* word 11 */
     unsigned      completedata_671_640                      : 32;
          /* word 12 */
     unsigned      completedata_639_608                      : 32;
          /* word 13 */
     unsigned      completedata_607_576                      : 32;
          /* word 14 */
     unsigned      completedata_575_544                      : 32;
          /* word 15 */
     unsigned      completedata_543_512                      : 32;
          /* word 16 */
     unsigned      completedata_511_480                      : 32;
          /* word 17 */
     unsigned      completedata_479_448                      : 32;
          /* word 18 */
     unsigned      completedata_447_416                      : 32;
          /* word 19 */
     unsigned      completedata_415_384                      : 32;
          /* word 20 */
     unsigned      completedata_383_352                      : 32;
          /* word 21 */
     unsigned      completedata_351_320                      : 32;
          /* word 22 */
     unsigned      completedata_319_288                      : 32;
          /* word 23 */
     unsigned      completedata_287_256                      : 32;
          /* word 24 */
     unsigned      completedata_255_224                      : 32;
          /* word 25 */
     unsigned      completedata_223_192                      : 32;
          /* word 26 */
     unsigned      completedata_191_160                      : 32;
          /* word 27 */
     unsigned      completedata_159_128                      : 32;
          /* word 28 */
     unsigned      completedata_127_96                       : 32;
          /* word 29 */
     unsigned      completedata_95_64                        : 32;
          /* word 30 */
     unsigned      completedata_63_32                        : 32;
          /* word 31 */
     unsigned      completedata_31_0                         : 32;
#endif
} ncp_nca_otp_ll_isel_complete_ram_r_t;

/*! @struct ncp_nca_otp_ll_isel_allocate_ram_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_otp_ll_isel_allocate_ram_r_t
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
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_246_224 </td>
 *     <td width="20%" align="center"> 23 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 23 bits of allocateData. allocate data </td>
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
 * Applies to: xlf --> ncp_nca_otp_ll_isel_allocate_ram_r_t
 *
 * Implemented by: 
 *      ll_isel_oallocate_ram
 *      ll_isel_aallocate_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0                                 :  9;
     unsigned      allocatedata_246_224                      : 23;
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
     unsigned      allocatedata_246_224                      : 23;
     unsigned      reserved0                                 :  9;
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
} ncp_nca_otp_ll_isel_allocate_ram_r_t;

/*! @struct ncp_nca_otp_ll_rsel_allocate_ram_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_otp_ll_rsel_allocate_ram_r_t
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
 *     <td width="20%" align="center"> 18 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_45_32 </td>
 *     <td width="20%" align="center"> 14 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 14 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_ll_rsel_allocate_ram_r_t
 *
 * Implemented by: 
 *      ll_rsel_allocate_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0                                 : 18;
     unsigned      allocatedata_45_32                        : 14;
          /* word 1 */
     unsigned      allocatedata_31_0                         : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      allocatedata_45_32                        : 14;
     unsigned      reserved0                                 : 18;
          /* word 1 */
     unsigned      allocatedata_31_0                         : 32;
#endif
} ncp_nca_otp_ll_rsel_allocate_ram_r_t;

/*! @struct ncp_nca_otp_ll_sndtsk_allocate_ram_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_otp_ll_sndtsk_allocate_ram_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_108_77 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_76_45 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_44_13 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_12_0 </td>
 *     <td width="20%" align="center"> 13 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> 13 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_914_896 </td>
 *     <td width="20%" align="center"> 19 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 19 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_895_864 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_863_832 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_831_800 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_799_768 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_767_736 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_735_704 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_703_672 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_671_640 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_639_608 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_607_576 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_575_544 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_543_512 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_511_480 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_479_448 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_447_416 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_415_384 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_383_352 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_351_320 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_319_288 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param allocatedata_287_256 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of allocateData. allocate data </td>
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
 * Applies to: xlf --> ncp_nca_otp_ll_sndtsk_allocate_ram_r_t
 *
 * Implemented by: 
 *      ll_sndtsk_allocate_ram
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0_108_77                          : 32;
          /* word 1 */
     unsigned      reserved0_76_45                           : 32;
          /* word 2 */
     unsigned      reserved0_44_13                           : 32;
          /* word 3 */
     unsigned      reserved0_12_0                            : 13;
     unsigned      allocatedata_914_896                      : 19;
          /* word 4 */
     unsigned      allocatedata_895_864                      : 32;
          /* word 5 */
     unsigned      allocatedata_863_832                      : 32;
          /* word 6 */
     unsigned      allocatedata_831_800                      : 32;
          /* word 7 */
     unsigned      allocatedata_799_768                      : 32;
          /* word 8 */
     unsigned      allocatedata_767_736                      : 32;
          /* word 9 */
     unsigned      allocatedata_735_704                      : 32;
          /* word 10 */
     unsigned      allocatedata_703_672                      : 32;
          /* word 11 */
     unsigned      allocatedata_671_640                      : 32;
          /* word 12 */
     unsigned      allocatedata_639_608                      : 32;
          /* word 13 */
     unsigned      allocatedata_607_576                      : 32;
          /* word 14 */
     unsigned      allocatedata_575_544                      : 32;
          /* word 15 */
     unsigned      allocatedata_543_512                      : 32;
          /* word 16 */
     unsigned      allocatedata_511_480                      : 32;
          /* word 17 */
     unsigned      allocatedata_479_448                      : 32;
          /* word 18 */
     unsigned      allocatedata_447_416                      : 32;
          /* word 19 */
     unsigned      allocatedata_415_384                      : 32;
          /* word 20 */
     unsigned      allocatedata_383_352                      : 32;
          /* word 21 */
     unsigned      allocatedata_351_320                      : 32;
          /* word 22 */
     unsigned      allocatedata_319_288                      : 32;
          /* word 23 */
     unsigned      allocatedata_287_256                      : 32;
          /* word 24 */
     unsigned      allocatedata_255_224                      : 32;
          /* word 25 */
     unsigned      allocatedata_223_192                      : 32;
          /* word 26 */
     unsigned      allocatedata_191_160                      : 32;
          /* word 27 */
     unsigned      allocatedata_159_128                      : 32;
          /* word 28 */
     unsigned      allocatedata_127_96                       : 32;
          /* word 29 */
     unsigned      allocatedata_95_64                        : 32;
          /* word 30 */
     unsigned      allocatedata_63_32                        : 32;
          /* word 31 */
     unsigned      allocatedata_31_0                         : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      reserved0_108_77                          : 32;
          /* word 1 */
     unsigned      reserved0_76_45                           : 32;
          /* word 2 */
     unsigned      reserved0_44_13                           : 32;
          /* word 3 */
     unsigned      allocatedata_914_896                      : 19;
     unsigned      reserved0_12_0                            : 13;
          /* word 4 */
     unsigned      allocatedata_895_864                      : 32;
          /* word 5 */
     unsigned      allocatedata_863_832                      : 32;
          /* word 6 */
     unsigned      allocatedata_831_800                      : 32;
          /* word 7 */
     unsigned      allocatedata_799_768                      : 32;
          /* word 8 */
     unsigned      allocatedata_767_736                      : 32;
          /* word 9 */
     unsigned      allocatedata_735_704                      : 32;
          /* word 10 */
     unsigned      allocatedata_703_672                      : 32;
          /* word 11 */
     unsigned      allocatedata_671_640                      : 32;
          /* word 12 */
     unsigned      allocatedata_639_608                      : 32;
          /* word 13 */
     unsigned      allocatedata_607_576                      : 32;
          /* word 14 */
     unsigned      allocatedata_575_544                      : 32;
          /* word 15 */
     unsigned      allocatedata_543_512                      : 32;
          /* word 16 */
     unsigned      allocatedata_511_480                      : 32;
          /* word 17 */
     unsigned      allocatedata_479_448                      : 32;
          /* word 18 */
     unsigned      allocatedata_447_416                      : 32;
          /* word 19 */
     unsigned      allocatedata_415_384                      : 32;
          /* word 20 */
     unsigned      allocatedata_383_352                      : 32;
          /* word 21 */
     unsigned      allocatedata_351_320                      : 32;
          /* word 22 */
     unsigned      allocatedata_319_288                      : 32;
          /* word 23 */
     unsigned      allocatedata_287_256                      : 32;
          /* word 24 */
     unsigned      allocatedata_255_224                      : 32;
          /* word 25 */
     unsigned      allocatedata_223_192                      : 32;
          /* word 26 */
     unsigned      allocatedata_191_160                      : 32;
          /* word 27 */
     unsigned      allocatedata_159_128                      : 32;
          /* word 28 */
     unsigned      allocatedata_127_96                       : 32;
          /* word 29 */
     unsigned      allocatedata_95_64                        : 32;
          /* word 30 */
     unsigned      allocatedata_63_32                        : 32;
          /* word 31 */
     unsigned      allocatedata_31_0                         : 32;
#endif
} ncp_nca_otp_ll_sndtsk_allocate_ram_r_t;

/*! @struct ncp_nca_otp_ram_dma_read_cpu_engine_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_otp_ram_dma_read_cpu_engine_r_t
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
 *     <td width="20%" align="center"> 21 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved_42_32 </td>
 *     <td width="20%" align="center"> 11 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 11 bits of reserved. reserved </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved. reserved </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_otp_ram_dma_read_cpu_engine_r_t
 *
 * Implemented by: 
 *      ram_dma_read_cpu_engine
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0                                 : 21;
     unsigned      reserved_42_32                            : 11;
          /* word 1 */
     unsigned      reserved_31_0                             : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      reserved_42_32                            : 11;
     unsigned      reserved0                                 : 21;
          /* word 1 */
     unsigned      reserved_31_0                             : 32;
#endif
} ncp_nca_otp_ram_dma_read_cpu_engine_r_t;

#ifdef __cplusplus
}
#endif

#endif /* _NCP_NCA_OTP_REGS_H_ */
