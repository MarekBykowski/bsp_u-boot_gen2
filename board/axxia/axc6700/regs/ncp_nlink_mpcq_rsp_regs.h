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


#ifndef _NCP_NLINK_MPCQ_RSP_REGS_H_
#define _NCP_NLINK_MPCQ_RSP_REGS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"

/*! @struct ncp_nlink_mpcq_rsp_double_buffer_status_r_t
 *  @brief Double buffer status
 *  @details This register reflects status of the corresponding AXI channel double buffer. This buffer is used for timing isolation.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nlink_mpcq_rsp_double_buffer_status_r_t\n
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
 *     <td width="30%"> @param input_stalled </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Input stalled (in_valid & ~in_rady) </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param input_taken </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Input taken (in_vaid & in_ready) </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param output_stalled </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Output stalled (out_vaid & ~out_ready) </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param output_taken </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Output taken (out_valid & out_ready) </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param out_ready_q </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Registered value of out_ready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param depth </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Current depth value </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nlink_mpcq_rsp_double_buffer_status_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 25;
     unsigned      input_stalled                             :  1;
     unsigned      input_taken                               :  1;
     unsigned      output_stalled                            :  1;
     unsigned      output_taken                              :  1;
     unsigned      out_ready_q                               :  1;
     unsigned      depth                                     :  2;
#else    /* Little Endian */
     unsigned      depth                                     :  2;
     unsigned      out_ready_q                               :  1;
     unsigned      output_taken                              :  1;
     unsigned      output_stalled                            :  1;
     unsigned      input_taken                               :  1;
     unsigned      input_stalled                             :  1;
     unsigned      reserved0                                 : 25;
#endif
} ncp_nlink_mpcq_rsp_double_buffer_status_r_t;

/*! @struct ncp_nlink_mpcq_rsp_nlink_xface_ctl_r_t
 *  @brief Interface Enable register
 *  @details This register is used to enable of disable the local interfaces
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nlink_mpcq_rsp_nlink_xface_ctl_r_t\n
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
 *     <td width="30%"> @param m_axi_enable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Master AXI interface enable </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nlink_mpcq_rsp_nlink_xface_ctl_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 31;
     unsigned      m_axi_enable                              :  1;
#else    /* Little Endian */
     unsigned      m_axi_enable                              :  1;
     unsigned      reserved0                                 : 31;
#endif
} ncp_nlink_mpcq_rsp_nlink_xface_ctl_r_t;

/*! @struct ncp_nlink_mpcq_rsp_access_rate_r_t
 *  @brief NLINK local access rate register
 *  @details This register is used to program the NLINK local access rate
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nlink_mpcq_rsp_access_rate_r_t\n
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
 *     <td width="30%"> @param access_rate </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Access Rate </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nlink_mpcq_rsp_access_rate_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 24;
     unsigned      access_rate                               :  8;
#else    /* Little Endian */
     unsigned      access_rate                               :  8;
     unsigned      reserved0                                 : 24;
#endif
} ncp_nlink_mpcq_rsp_access_rate_r_t;

/*! @struct ncp_nlink_mpcq_rsp_nlink_ctl_r_t
 *  @brief NLINK configuration register
 *  @details NLINK control register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nlink_mpcq_rsp_nlink_ctl_r_t\n
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
 *     <td width="30%"> @param update_mode </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Rate update Mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param parity_type </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Parity Type 1-odd parity, 0-ever parity </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nlink_mpcq_rsp_nlink_ctl_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 23;
     unsigned      update_mode                               :  1;
     unsigned      reserved1                                 :  7;
     unsigned      parity_type                               :  1;
#else    /* Little Endian */
     unsigned      parity_type                               :  1;
     unsigned      reserved1                                 :  7;
     unsigned      update_mode                               :  1;
     unsigned      reserved0                                 : 23;
#endif
} ncp_nlink_mpcq_rsp_nlink_ctl_r_t;

/*! @struct ncp_nlink_mpcq_rsp_axi_status_r_t
 *  @brief Interface status
 *  @details Status of the AXI interface
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nlink_mpcq_rsp_axi_status_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param write_req_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> Write_req_protocl_error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param write_data_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> Write_data_protocl_error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 27 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param awready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> flopped awready status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> flopped wready status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param bready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> flopped bready status </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nlink_mpcq_rsp_axi_status_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      write_req_err                             :  1;
     unsigned      write_data_err                            :  1;
     unsigned      reserved0                                 : 27;
     unsigned      awready                                   :  1;
     unsigned      wready                                    :  1;
     unsigned      bready                                    :  1;
#else    /* Little Endian */
     unsigned      bready                                    :  1;
     unsigned      wready                                    :  1;
     unsigned      awready                                   :  1;
     unsigned      reserved0                                 : 27;
     unsigned      write_data_err                            :  1;
     unsigned      write_req_err                             :  1;
#endif
} ncp_nlink_mpcq_rsp_axi_status_r_t;

/*! @struct ncp_nlink_mpcq_rsp_hist_cnt_r_t
 *  @brief Histerisis count register
 *  @details LPI Shutdown hysterisis count register. Use this register to specify how many clocks to wait before entering the shutdown state
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nlink_mpcq_rsp_hist_cnt_r_t\n
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
 *     <td width="30%"> @param hist_cnt </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Shutdown histerisis count register </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nlink_mpcq_rsp_hist_cnt_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 24;
     unsigned      hist_cnt                                  :  8;
#else    /* Little Endian */
     unsigned      hist_cnt                                  :  8;
     unsigned      reserved0                                 : 24;
#endif
} ncp_nlink_mpcq_rsp_hist_cnt_r_t;

/*! @struct ncp_nlink_mpcq_rsp_setup_cnt_r_t
 *  @brief Setup count register
 *  @details LPI setup ount register. Use this register to specify how many clocks to wait before entering the shutdown state
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nlink_mpcq_rsp_setup_cnt_r_t\n
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
 *     <td width="30%"> @param setup_cnt </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Setup count register </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nlink_mpcq_rsp_setup_cnt_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 24;
     unsigned      setup_cnt                                 :  8;
#else    /* Little Endian */
     unsigned      setup_cnt                                 :  8;
     unsigned      reserved0                                 : 24;
#endif
} ncp_nlink_mpcq_rsp_setup_cnt_r_t;

/*! @struct ncp_nlink_mpcq_rsp_overflow_underflow_status_r_t
 *  @brief Status Register
 *  @details This is sticky registers for capturinng overflow and underflow information
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nlink_mpcq_rsp_overflow_underflow_status_r_t\n
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
 *     <td width="30%"> @param status10 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> loq_credits_d_minus_loqc_used_q </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param status9 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> loq_credits_d_plus_loqc_fifo_pop_data_q </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param status8 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> moq_credits_q_minus_moqc_used_q </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param status7 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> moq_credits_q_plus_moqc_fifo_pop_data_q </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param status6 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> moq_credits_q_plus_moqc_fifo_pop_data_q_minus_moqc_used_q </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param status5 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> prev_len_plus_1_overflow_q </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param status4 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> s_axi_awlen_plus_1_overflow_q </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param status0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> lpd_fifo_len_plus_1_overflow_q </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nlink_mpcq_rsp_overflow_underflow_status_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 21;
     unsigned      status10                                  :  1;
     unsigned      status9                                   :  1;
     unsigned      status8                                   :  1;
     unsigned      status7                                   :  1;
     unsigned      status6                                   :  1;
     unsigned      status5                                   :  1;
     unsigned      status4                                   :  1;
     unsigned      reserved1                                 :  3;
     unsigned      status0                                   :  1;
#else    /* Little Endian */
     unsigned      status0                                   :  1;
     unsigned      reserved1                                 :  3;
     unsigned      status4                                   :  1;
     unsigned      status5                                   :  1;
     unsigned      status6                                   :  1;
     unsigned      status7                                   :  1;
     unsigned      status8                                   :  1;
     unsigned      status9                                   :  1;
     unsigned      status10                                  :  1;
     unsigned      reserved0                                 : 21;
#endif
} ncp_nlink_mpcq_rsp_overflow_underflow_status_r_t;

/*! @struct ncp_nlink_mpcq_rsp_core_error_status_r_t
 *  @brief Status Register
 *  @details This is sticky registers for capturinng core_error information
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nlink_mpcq_rsp_core_error_status_r_t\n
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
 *     <td width="20%" align="center"> 30 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param core_error </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> core_error bit-0 is awerr on slave interface, bit-1
 *        is brep!=0 on mio interface
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nlink_mpcq_rsp_core_error_status_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 30;
     unsigned      core_error                                :  2;
#else    /* Little Endian */
     unsigned      core_error                                :  2;
     unsigned      reserved0                                 : 30;
#endif
} ncp_nlink_mpcq_rsp_core_error_status_r_t;

/*! @struct ncp_nlink_mpcq_rsp_nlink_int_status_r_t
 *  @brief Interrupt Status Register
 *  @details This register holds interrupt status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nlink_mpcq_rsp_nlink_int_status_r_t\n
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
 *     <td width="30%"> @param nlink_core_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> nlink core error: see core_error_status_r for type
 *        of error Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param mii_message_dstid_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Incoming MII dstID is out of range Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param mii_message_srcid_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Incoming MII srcID is out of range Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param nlink_last_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> It is an error when nlink_last=1 and next_valid=1.
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param nlink_core_under_over_flow_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Underfow/Overflow was detected. See sticky register
 *        for details. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param nlink_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Parity Error was detected on the lincoming link frame.
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param link_message_length_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> The incoming message length field doesn't match the
 *        expected value Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param link_message_srcid_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The incoming message srcId==nlink_id Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param link_message_id_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> The incoming message srcId==dstId Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param aw_smon_interrrupt </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> SMON Interrupt Status </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nlink_mpcq_rsp_nlink_int_status_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 22;
     unsigned      nlink_core_error                          :  1;
     unsigned      mii_message_dstid_err                     :  1;
     unsigned      mii_message_srcid_err                     :  1;
     unsigned      nlink_last_err                            :  1;
     unsigned      nlink_core_under_over_flow_err            :  1;
     unsigned      nlink_parity_err                          :  1;
     unsigned      link_message_length_err                   :  1;
     unsigned      link_message_srcid_err                    :  1;
     unsigned      link_message_id_err                       :  1;
     unsigned      aw_smon_interrrupt                        :  1;
#else    /* Little Endian */
     unsigned      aw_smon_interrrupt                        :  1;
     unsigned      link_message_id_err                       :  1;
     unsigned      link_message_srcid_err                    :  1;
     unsigned      link_message_length_err                   :  1;
     unsigned      nlink_parity_err                          :  1;
     unsigned      nlink_core_under_over_flow_err            :  1;
     unsigned      nlink_last_err                            :  1;
     unsigned      mii_message_srcid_err                     :  1;
     unsigned      mii_message_dstid_err                     :  1;
     unsigned      nlink_core_error                          :  1;
     unsigned      reserved0                                 : 22;
#endif
} ncp_nlink_mpcq_rsp_nlink_int_status_r_t;

/*! @struct ncp_nlink_mpcq_rsp_nlink_int_en_r_t
 *  @brief Interrupt Enable Register
 *  @details This register enables interrupts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nlink_mpcq_rsp_nlink_int_en_r_t\n
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
 *     <td width="30%"> @param nlink_core_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> nlink core error: see core_error_status_r for type
 *        of error Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param mii_message_dstid_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Incoming MII dstID is out of range Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param mii_message_srcid_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Incoming MII srcID is out of range Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param nlink_last_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> It is an error when nlink_last=1 and next_valid=1.
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param nlink_core_under_over_flow_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Underfow/Overflow was detected. See sticky register
 *        for details. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param nlink_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Parity Error was detected on the lincoming link frame.
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param link_message_length_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> The incoming message length field doesn't match the
 *        expected value Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param link_message_srcid_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The incoming message srcId==nlink_id Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param link_message_id_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> The incoming message srcId==dstId Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param aw_smon_interrrupt </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> SMON Interrupt Enable </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nlink_mpcq_rsp_nlink_int_en_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 22;
     unsigned      nlink_core_error                          :  1;
     unsigned      mii_message_dstid_err                     :  1;
     unsigned      mii_message_srcid_err                     :  1;
     unsigned      nlink_last_err                            :  1;
     unsigned      nlink_core_under_over_flow_err            :  1;
     unsigned      nlink_parity_err                          :  1;
     unsigned      link_message_length_err                   :  1;
     unsigned      link_message_srcid_err                    :  1;
     unsigned      link_message_id_err                       :  1;
     unsigned      aw_smon_interrrupt                        :  1;
#else    /* Little Endian */
     unsigned      aw_smon_interrrupt                        :  1;
     unsigned      link_message_id_err                       :  1;
     unsigned      link_message_srcid_err                    :  1;
     unsigned      link_message_length_err                   :  1;
     unsigned      nlink_parity_err                          :  1;
     unsigned      nlink_core_under_over_flow_err            :  1;
     unsigned      nlink_last_err                            :  1;
     unsigned      mii_message_srcid_err                     :  1;
     unsigned      mii_message_dstid_err                     :  1;
     unsigned      nlink_core_error                          :  1;
     unsigned      reserved0                                 : 22;
#endif
} ncp_nlink_mpcq_rsp_nlink_int_en_r_t;

/*! @struct ncp_nlink_mpcq_rsp_nlink_int_force_r_t
 *  @brief Interrupt Force Register
 *  @details This address is an alias for the Interrupt Status register
		that allows normal CFG writes (as opposed to the Clear-On-Write-One
		behavior if the Interrupt Status register address is used).  This
		allows CFG to set interrupt bits for testing purposes.  Reading this
		address returns the current value of the Interrupt Status Register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nlink_mpcq_rsp_nlink_int_force_r_t\n
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
 *     <td width="30%"> @param nlink_core_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> nlink core error: see core_error_status_r for type
 *        of error Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param mii_message_dstid_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Incoming MII dstID is out of range Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param mii_message_srcid_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Incoming MII srcID is out of range Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param nlink_last_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> It is an error when nlink_last=1 and next_valid=1.
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param nlink_core_under_over_flow_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Underfow/Overflow was detected. See sticky register
 *        for details. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param nlink_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Parity Error was detected on the lincoming link frame.
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param link_message_length_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> The incoming message length field doesn't match the
 *        expected value Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param link_message_srcid_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The incoming message srcId==nlink_id Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param link_message_id_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> The incoming message srcId==dstId Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param aw_smon_interrrupt </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> SMON Interrupt Force </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nlink_mpcq_rsp_nlink_int_force_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 22;
     unsigned      nlink_core_error                          :  1;
     unsigned      mii_message_dstid_err                     :  1;
     unsigned      mii_message_srcid_err                     :  1;
     unsigned      nlink_last_err                            :  1;
     unsigned      nlink_core_under_over_flow_err            :  1;
     unsigned      nlink_parity_err                          :  1;
     unsigned      link_message_length_err                   :  1;
     unsigned      link_message_srcid_err                    :  1;
     unsigned      link_message_id_err                       :  1;
     unsigned      aw_smon_interrrupt                        :  1;
#else    /* Little Endian */
     unsigned      aw_smon_interrrupt                        :  1;
     unsigned      link_message_id_err                       :  1;
     unsigned      link_message_srcid_err                    :  1;
     unsigned      link_message_length_err                   :  1;
     unsigned      nlink_parity_err                          :  1;
     unsigned      nlink_core_under_over_flow_err            :  1;
     unsigned      nlink_last_err                            :  1;
     unsigned      mii_message_srcid_err                     :  1;
     unsigned      mii_message_dstid_err                     :  1;
     unsigned      nlink_core_error                          :  1;
     unsigned      reserved0                                 : 22;
#endif
} ncp_nlink_mpcq_rsp_nlink_int_force_r_t;

/*! @struct ncp_nlink_mpcq_rsp_AW_smon01_NLINK_r_t
 *  @brief AW_smon CONTROL1 register
 *  @details This is used to configure the operation of the 2 internal counters in the SMON
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nlink_mpcq_rsp_AW_smon01_NLINK_r_t\n
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
 * Applies to: xlf --> ncp_nlink_mpcq_rsp_AW_smon01_NLINK_r_t
 *
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
} ncp_nlink_mpcq_rsp_AW_smon01_NLINK_r_t;

#ifdef __cplusplus
}
#endif

#endif /* _NCP_NLINK_MPCQ_RSP_REGS_H_ */
