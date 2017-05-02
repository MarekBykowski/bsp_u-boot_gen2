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


#ifndef _NCP_CMN_AXI_REGS_H_
#define _NCP_CMN_AXI_REGS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"

/*! @struct ncp_cmn_axi_param_NUM_OUTSTANDING_CPCQ_REQS_r_t
 *  @brief NUM_OUTSTANDING_CPCQ_REQS parameter
 *  @details Build-time parameter that defines the depth of the CMN's cPCQ request and response FIFO's
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_param_NUM_OUTSTANDING_CPCQ_REQS_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param num_outstanding_cpcq_reqs </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> null </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_param_NUM_OUTSTANDING_CPCQ_REQS_r_t
 *
 * Implemented by: 
 *      param_NUM_OUTSTANDING_CPCQ_REQS
 */
 
typedef struct
{
     unsigned  int      num_outstanding_cpcq_reqs;
} ncp_cmn_axi_param_NUM_OUTSTANDING_CPCQ_REQS_r_t;

/*! @struct ncp_cmn_axi_outstanding_cpcqs_count_r_t
 *  @brief Outstanding cPCQs count
 *  @details Number of outstanding cPCQ requests in the CMN
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_outstanding_cpcqs_count_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param outstanding_cpcqs_count </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> null </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_outstanding_cpcqs_count_r_t
 *
 * Implemented by: 
 *      outstanding_cpcqs_count
 */
 
typedef struct
{
     unsigned  int      outstanding_cpcqs_count;
} ncp_cmn_axi_outstanding_cpcqs_count_r_t;

/*! @struct ncp_cmn_axi_outstanding_cpcqs_counter_status_r_t
 *  @brief Outstanding cPCQs counter status
 *  @details Status of the counter for outstanding cPCQ requests in the CMN. If there is an error in the counter (bits 0 or 1 are asserted), all cPCQ requests coming into the CMN will be backpressued, and any existing (buffered) requests currently in the CMN that have not already started execution will be effectively frozen for debugging purposes until the chip is reset. The status registers (including cpcq_req_fifo_status) will be accessible via PIO commands in such a case.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_outstanding_cpcqs_counter_status_r_t\n
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
 *     <td width="30%"> @param full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> full (counter register is greater than or equal to
 *        cfg_full_threshold)
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param afull </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> almost full (counter regsiter is greater than or equal
 *        to cfg_afull_threshold)
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param aempty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> almost empty (counter regsiter is less than or equal
 *        to cfg_aempty_threshold)
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param empty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> empty (counter regsiter is less than or equal to cfg_empty_threshold) </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> counter overflow. This is sticky and can be cleared
 *        by rst_n.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_underflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> counter underflow. This is sticky and can be cleared
 *        by rst_n.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_outstanding_cpcqs_counter_status_r_t
 *
 * Implemented by: 
 *      outstanding_cpcqs_counter_status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 26;
     unsigned      full                                      :  1;
     unsigned      afull                                     :  1;
     unsigned      aempty                                    :  1;
     unsigned      empty                                     :  1;
     unsigned      cnt_overflow                              :  1;
     unsigned      cnt_underflow                             :  1;
#else    /* Little Endian */
     unsigned      cnt_underflow                             :  1;
     unsigned      cnt_overflow                              :  1;
     unsigned      empty                                     :  1;
     unsigned      aempty                                    :  1;
     unsigned      afull                                     :  1;
     unsigned      full                                      :  1;
     unsigned      reserved0                                 : 26;
#endif
} ncp_cmn_axi_outstanding_cpcqs_counter_status_r_t;

/*! @struct ncp_cmn_axi_counter_reset_r_t
 *  @brief CMN counter reset
 *  @details Reset the CMN counters that track issued and completed PIO and cPCQ instructions. Note: after resetting a counter, software must write a 0 back to the counter's reset bit to take it out of reset.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_counter_reset_r_t\n
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
 *     <td width="30%"> @param cpcq_completed_instructions </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> completed cPCQ instructions </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cpcq_issued_instructions </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> issued cPCQ instructions </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pio_completed_instructions </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> completed PIO instructions </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pio_issued_instructions </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> issued PIO instructions </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_counter_reset_r_t
 *
 * Implemented by: 
 *      counter_reset
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 28;
     unsigned      cpcq_completed_instructions               :  1;
     unsigned      cpcq_issued_instructions                  :  1;
     unsigned      pio_completed_instructions                :  1;
     unsigned      pio_issued_instructions                   :  1;
#else    /* Little Endian */
     unsigned      pio_issued_instructions                   :  1;
     unsigned      pio_completed_instructions                :  1;
     unsigned      cpcq_issued_instructions                  :  1;
     unsigned      cpcq_completed_instructions               :  1;
     unsigned      reserved0                                 : 28;
#endif
} ncp_cmn_axi_counter_reset_r_t;

/*! @struct ncp_cmn_axi_cpcq_issued_instructions_cnt_r_t
 *  @brief Issued cPCQ instructions
 *  @details Total number of cPCQ instructions issued to the CMN since reset
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cpcq_issued_instructions_cnt_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cpcq_issued_instructions </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> null </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cpcq_issued_instructions_cnt_r_t
 *
 * Implemented by: 
 *      cpcq_issued_instructions_cnt
 */
 
typedef struct
{
     unsigned  int      cpcq_issued_instructions;
} ncp_cmn_axi_cpcq_issued_instructions_cnt_r_t;

/*! @struct ncp_cmn_axi_cpcq_completed_instructions_cnt_r_t
 *  @brief Completed cPCQ instructions
 *  @details Total number of cPCQ instructions completed by the CMN since reset
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cpcq_completed_instructions_cnt_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cpcq_completed_instructions </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> null </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cpcq_completed_instructions_cnt_r_t
 *
 * Implemented by: 
 *      cpcq_completed_instructions_cnt
 */
 
typedef struct
{
     unsigned  int      cpcq_completed_instructions;
} ncp_cmn_axi_cpcq_completed_instructions_cnt_r_t;

/*! @struct ncp_cmn_axi_pio_issued_instructions_cnt_r_t
 *  @brief Issued PIO instructions
 *  @details Total number of PIO instructions issued to the CMN since reset
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_pio_issued_instructions_cnt_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param pio_issued_instructions </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> null </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_pio_issued_instructions_cnt_r_t
 *
 * Implemented by: 
 *      pio_issued_instructions_cnt
 */
 
typedef struct
{
     unsigned  int      pio_issued_instructions;
} ncp_cmn_axi_pio_issued_instructions_cnt_r_t;

/*! @struct ncp_cmn_axi_pio_completed_instructions_cnt_r_t
 *  @brief Completed PIO instructions
 *  @details Total number of PIO instructions completed by the CMN since reset
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_pio_completed_instructions_cnt_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param pio_completed_instructions </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> null </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_pio_completed_instructions_cnt_r_t
 *
 * Implemented by: 
 *      pio_completed_instructions_cnt
 */
 
typedef struct
{
     unsigned  int      pio_completed_instructions;
} ncp_cmn_axi_pio_completed_instructions_cnt_r_t;

/*! @struct ncp_cmn_axi_sm_var_delay_state_r_t
 *  @brief CMN sm_var_delay_state state
 *  @details Current state of the sm_var_delay_state state machine
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_sm_var_delay_state_r_t\n
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
 *     <td width="30%"> @param sm_var_delay_state </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> null </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_sm_var_delay_state_r_t
 *
 * Implemented by: 
 *      sm_var_delay_state
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 29;
     unsigned      sm_var_delay_state                        :  3;
#else    /* Little Endian */
     unsigned      sm_var_delay_state                        :  3;
     unsigned      reserved0                                 : 29;
#endif
} ncp_cmn_axi_sm_var_delay_state_r_t;

/*! @struct ncp_cmn_axi_axi_rstate_r_t
 *  @brief CMN Read Engine axi_rstate state
 *  @details Current state of the axi_rstate state machine
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_axi_rstate_r_t\n
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
 *     <td width="30%"> @param axi_rstate </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> null </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_axi_rstate_r_t
 *
 * Implemented by: 
 *      axi_rstate
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 27;
     unsigned      axi_rstate                                :  5;
#else    /* Little Endian */
     unsigned      axi_rstate                                :  5;
     unsigned      reserved0                                 : 27;
#endif
} ncp_cmn_axi_axi_rstate_r_t;

/*! @struct ncp_cmn_axi_cstate_r_t
 *  @brief CMN cstate state
 *  @details Current state of the cstate state machine
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cstate_r_t\n
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
 *     <td width="30%"> @param cstate </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> null </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cstate_r_t
 *
 * Implemented by: 
 *      cstate
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      cstate                                    : 16;
#else    /* Little Endian */
     unsigned      cstate                                    : 16;
     unsigned      reserved0                                 : 16;
#endif
} ncp_cmn_axi_cstate_r_t;

/*! @struct ncp_cmn_axi_split_state_r_t
 *  @brief CMN split_state state
 *  @details Current state of the split_state state machine
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_split_state_r_t\n
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
 *     <td width="30%"> @param split_state </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> null </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_split_state_r_t
 *
 * Implemented by: 
 *      split_state
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 24;
     unsigned      split_state                               :  8;
#else    /* Little Endian */
     unsigned      split_state                               :  8;
     unsigned      reserved0                                 : 24;
#endif
} ncp_cmn_axi_split_state_r_t;

/*! @struct ncp_cmn_axi_axi_read_state_r_t
 *  @brief CMN axi_read_state state
 *  @details Current state of the axi_read_state state machine
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_axi_read_state_r_t\n
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
 *     <td width="30%"> @param axi_read_state </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> null </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_axi_read_state_r_t
 *
 * Implemented by: 
 *      axi_read_state
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 27;
     unsigned      axi_read_state                            :  5;
#else    /* Little Endian */
     unsigned      axi_read_state                            :  5;
     unsigned      reserved0                                 : 27;
#endif
} ncp_cmn_axi_axi_read_state_r_t;

/*! @struct ncp_cmn_axi_axi_write_state_r_t
 *  @brief CMN axi_write_state state
 *  @details Current state of the axi_write_state state machine
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_axi_write_state_r_t\n
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
 *     <td width="30%"> @param axi_write_state </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> null </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_axi_write_state_r_t
 *
 * Implemented by: 
 *      axi_write_state
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 29;
     unsigned      axi_write_state                           :  3;
#else    /* Little Endian */
     unsigned      axi_write_state                           :  3;
     unsigned      reserved0                                 : 29;
#endif
} ncp_cmn_axi_axi_write_state_r_t;

/*! @struct ncp_cmn_axi_reng_read_op_state_r_t
 *  @brief CMN Read Engine reng_read_op_state state
 *  @details This register shows the current state of the Read Engine's reng_read_op_state state machine.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_reng_read_op_state_r_t\n
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
 *     <td width="30%"> @param reng_read_op_state </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> null </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_reng_read_op_state_r_t
 *
 * Implemented by: 
 *      reng_read_op_state
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 27;
     unsigned      reng_read_op_state                        :  5;
#else    /* Little Endian */
     unsigned      reng_read_op_state                        :  5;
     unsigned      reserved0                                 : 27;
#endif
} ncp_cmn_axi_reng_read_op_state_r_t;

/*! @struct ncp_cmn_axi_weng_write_op_state_r_t
 *  @brief CMN Write Engine weng_write_op_state state
 *  @details This register shows the current state of the Write Engine's weng_write_op_state state machine.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_weng_write_op_state_r_t\n
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
 *     <td width="30%"> @param weng_write_op_state </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> null </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_weng_write_op_state_r_t
 *
 * Implemented by: 
 *      weng_write_op_state
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 29;
     unsigned      weng_write_op_state                       :  3;
#else    /* Little Endian */
     unsigned      weng_write_op_state                       :  3;
     unsigned      reserved0                                 : 29;
#endif
} ncp_cmn_axi_weng_write_op_state_r_t;

/*! @struct ncp_cmn_axi_cpcq_ctl_state_reg_t
 *  @brief Configuration Master Node cPCQ Control State Register
 *  @details This register shows the current state of the cpcq_state and arb_state state machines.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cpcq_ctl_state_reg_t\n
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
 *     <td width="30%"> @param cpcq_state </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Current state of the cpcq_state state machine. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arb_state </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Current state of the arb_state state machine. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cpcq_ctl_state_reg_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 12;
     unsigned      cpcq_state                                :  4;
     unsigned      reserved1                                 : 11;
     unsigned      arb_state                                 :  5;
#else    /* Little Endian */
     unsigned      arb_state                                 :  5;
     unsigned      reserved1                                 : 11;
     unsigned      cpcq_state                                :  4;
     unsigned      reserved0                                 : 12;
#endif
} ncp_cmn_axi_cpcq_ctl_state_reg_t;

/*! @struct ncp_cmn_axi_cfg_master_state_reg_t
 *  @brief Configuration Master Node cPCQ State Register
 *  @details This register shows the current state of the sm_var_delay_state_q, split_state, and cstate state machines.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cfg_master_state_reg_t\n
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
 *     <td width="30%"> @param sm_var_delay_state_q </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Current state of the sm_var_delay_state_q state machine. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param split_state </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Current state of the split_state state machine. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cstate </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Current state of the cstate state machine. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cfg_master_state_reg_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  5;
     unsigned      sm_var_delay_state_q                      :  3;
     unsigned      split_state                               :  8;
     unsigned      cstate                                    : 16;
#else    /* Little Endian */
     unsigned      cstate                                    : 16;
     unsigned      split_state                               :  8;
     unsigned      sm_var_delay_state_q                      :  3;
     unsigned      reserved0                                 :  5;
#endif
} ncp_cmn_axi_cfg_master_state_reg_t;

/*! @struct ncp_cmn_axi_cfg_master_axi_state_reg_t
 *  @brief Configuration Master Node Read and Write Engine State Register
 *  @details This register shows the current state of the axi_write_state, axi_read_state, and axi_rstate state machines.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cfg_master_axi_state_reg_t\n
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
 *     <td width="20%" align="center"> 13 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param axi_write_state </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Current state of the axi_write_state state machine. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param axi_read_state </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Current state of the axi_read_state state machine. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved2 </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param axi_rstate </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Current state of the axi_rstate state machine. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cfg_master_axi_state_reg_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 13;
     unsigned      axi_write_state                           :  3;
     unsigned      reserved1                                 :  3;
     unsigned      axi_read_state                            :  5;
     unsigned      reserved2                                 :  3;
     unsigned      axi_rstate                                :  5;
#else    /* Little Endian */
     unsigned      axi_rstate                                :  5;
     unsigned      reserved2                                 :  3;
     unsigned      axi_read_state                            :  5;
     unsigned      reserved1                                 :  3;
     unsigned      axi_write_state                           :  3;
     unsigned      reserved0                                 : 13;
#endif
} ncp_cmn_axi_cfg_master_axi_state_reg_t;

/*! @struct ncp_cmn_axi_cfg_ringphy_state_reg_t
 *  @brief Configuration Master Node Ringphy State Register
 *  @details This register shows the current state of the state state machine in the ncav2_cfg_ringphy block.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cfg_ringphy_state_reg_t\n
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
 *     <td width="30%"> @param state </td>
 *     <td width="20%" align="center"> 12 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Current state of the the state state machine in the
 *        ncav2_cfg_ringphy block.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cfg_ringphy_state_reg_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 20;
     unsigned      state                                     : 12;
#else    /* Little Endian */
     unsigned      state                                     : 12;
     unsigned      reserved0                                 : 20;
#endif
} ncp_cmn_axi_cfg_ringphy_state_reg_t;

/*! @struct ncp_cmn_axi_weng_req_fifo_status_r_t
 *  @brief CMN Write Engine request FIFO status
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_weng_req_fifo_status_r_t\n
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
 *     <td width="30%"> @param fifo_depth </td>
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> FIFO depth </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> FIFO full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_afull </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> FIFO almost full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_aempty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> FIFO almost empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_empty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> FIFO empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> FIFO parity error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> FIFO overflow </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_underflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> FIFO underflow </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_weng_req_fifo_status_r_t
 *
 * Implemented by: 
 *      cmn_weng_req_fifo_status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      fifo_depth                                :  9;
     unsigned      fifo_full                                 :  1;
     unsigned      fifo_afull                                :  1;
     unsigned      fifo_aempty                               :  1;
     unsigned      fifo_empty                                :  1;
     unsigned      fifo_parity_err                           :  1;
     unsigned      fifo_overflow                             :  1;
     unsigned      fifo_underflow                            :  1;
#else    /* Little Endian */
     unsigned      fifo_underflow                            :  1;
     unsigned      fifo_overflow                             :  1;
     unsigned      fifo_parity_err                           :  1;
     unsigned      fifo_empty                                :  1;
     unsigned      fifo_aempty                               :  1;
     unsigned      fifo_afull                                :  1;
     unsigned      fifo_full                                 :  1;
     unsigned      fifo_depth                                :  9;
     unsigned      reserved0                                 : 16;
#endif
} ncp_cmn_axi_weng_req_fifo_status_r_t;

/*! @struct ncp_cmn_axi_weng_req_fifo_control_r_t
 *  @brief CMN Write Engine request FIFO control
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_weng_req_fifo_control_r_t\n
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
 *     <td width="30%"> @param fifo_hwm </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> high watermark </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_weng_req_fifo_control_r_t
 *
 * Implemented by: 
 *      cmn_weng_req_fifo_control
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      fifo_hwm                                  : 16;
#else    /* Little Endian */
     unsigned      fifo_hwm                                  : 16;
     unsigned      reserved0                                 : 16;
#endif
} ncp_cmn_axi_weng_req_fifo_control_r_t;

/*! @struct ncp_cmn_axi_weng_wdb_fifo_status_r_t
 *  @brief CMN Write Engine write data buffer FIFO status
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_weng_wdb_fifo_status_r_t\n
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
 *     <td width="30%"> @param fifo_depth </td>
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> FIFO depth </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> FIFO full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_afull </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> FIFO almost full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_aempty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> FIFO almost empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_empty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> FIFO empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> FIFO parity error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> FIFO overflow </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_underflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> FIFO underflow </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_weng_wdb_fifo_status_r_t
 *
 * Implemented by: 
 *      cmn_weng_wdb_fifo_status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      fifo_depth                                :  9;
     unsigned      fifo_full                                 :  1;
     unsigned      fifo_afull                                :  1;
     unsigned      fifo_aempty                               :  1;
     unsigned      fifo_empty                                :  1;
     unsigned      fifo_parity_err                           :  1;
     unsigned      fifo_overflow                             :  1;
     unsigned      fifo_underflow                            :  1;
#else    /* Little Endian */
     unsigned      fifo_underflow                            :  1;
     unsigned      fifo_overflow                             :  1;
     unsigned      fifo_parity_err                           :  1;
     unsigned      fifo_empty                                :  1;
     unsigned      fifo_aempty                               :  1;
     unsigned      fifo_afull                                :  1;
     unsigned      fifo_full                                 :  1;
     unsigned      fifo_depth                                :  9;
     unsigned      reserved0                                 : 16;
#endif
} ncp_cmn_axi_weng_wdb_fifo_status_r_t;

/*! @struct ncp_cmn_axi_weng_wdb_fifo_control_r_t
 *  @brief CMN Write Engine write data buffer FIFO control
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_weng_wdb_fifo_control_r_t\n
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
 *     <td width="30%"> @param fifo_hwm </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> high watermark </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_weng_wdb_fifo_control_r_t
 *
 * Implemented by: 
 *      cmn_weng_wdb_fifo_control
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      fifo_hwm                                  : 16;
#else    /* Little Endian */
     unsigned      fifo_hwm                                  : 16;
     unsigned      reserved0                                 : 16;
#endif
} ncp_cmn_axi_weng_wdb_fifo_control_r_t;

/*! @struct ncp_cmn_axi_reng_req_fifo_status_r_t
 *  @brief CMN Read Engine request FIFO status
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_reng_req_fifo_status_r_t\n
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
 *     <td width="30%"> @param fifo_depth </td>
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> FIFO depth </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> FIFO full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_afull </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> FIFO almost full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_aempty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> FIFO almost empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_empty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> FIFO empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> FIFO parity error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> FIFO overflow </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_underflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> FIFO underflow </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_reng_req_fifo_status_r_t
 *
 * Implemented by: 
 *      cmn_reng_req_fifo_status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      fifo_depth                                :  9;
     unsigned      fifo_full                                 :  1;
     unsigned      fifo_afull                                :  1;
     unsigned      fifo_aempty                               :  1;
     unsigned      fifo_empty                                :  1;
     unsigned      fifo_parity_err                           :  1;
     unsigned      fifo_overflow                             :  1;
     unsigned      fifo_underflow                            :  1;
#else    /* Little Endian */
     unsigned      fifo_underflow                            :  1;
     unsigned      fifo_overflow                             :  1;
     unsigned      fifo_parity_err                           :  1;
     unsigned      fifo_empty                                :  1;
     unsigned      fifo_aempty                               :  1;
     unsigned      fifo_afull                                :  1;
     unsigned      fifo_full                                 :  1;
     unsigned      fifo_depth                                :  9;
     unsigned      reserved0                                 : 16;
#endif
} ncp_cmn_axi_reng_req_fifo_status_r_t;

/*! @struct ncp_cmn_axi_reng_req_fifo_control_r_t
 *  @brief CMN Read Engine request FIFO control
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_reng_req_fifo_control_r_t\n
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
 *     <td width="30%"> @param fifo_hwm </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> high watermark </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_reng_req_fifo_control_r_t
 *
 * Implemented by: 
 *      cmn_reng_req_fifo_control
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      fifo_hwm                                  : 16;
#else    /* Little Endian */
     unsigned      fifo_hwm                                  : 16;
     unsigned      reserved0                                 : 16;
#endif
} ncp_cmn_axi_reng_req_fifo_control_r_t;

/*! @struct ncp_cmn_axi_reng_sys_mem_reorder_buf_fifo_status_r_t
 *  @brief CMN Read Engine system memory reorder buffer FIFO status
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_reng_sys_mem_reorder_buf_fifo_status_r_t\n
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
 *     <td width="30%"> @param fifo_depth </td>
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> FIFO depth </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> FIFO full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_afull </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> FIFO almost full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_aempty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> FIFO almost empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_empty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> FIFO empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> FIFO parity error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> FIFO overflow </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_underflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> FIFO underflow </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_reng_sys_mem_reorder_buf_fifo_status_r_t
 *
 * Implemented by: 
 *      cmn_reng_sys_mem_reorder_buf_fifo_status_00
 *      cmn_reng_sys_mem_reorder_buf_fifo_status_01
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      fifo_depth                                :  9;
     unsigned      fifo_full                                 :  1;
     unsigned      fifo_afull                                :  1;
     unsigned      fifo_aempty                               :  1;
     unsigned      fifo_empty                                :  1;
     unsigned      fifo_parity_err                           :  1;
     unsigned      fifo_overflow                             :  1;
     unsigned      fifo_underflow                            :  1;
#else    /* Little Endian */
     unsigned      fifo_underflow                            :  1;
     unsigned      fifo_overflow                             :  1;
     unsigned      fifo_parity_err                           :  1;
     unsigned      fifo_empty                                :  1;
     unsigned      fifo_aempty                               :  1;
     unsigned      fifo_afull                                :  1;
     unsigned      fifo_full                                 :  1;
     unsigned      fifo_depth                                :  9;
     unsigned      reserved0                                 : 16;
#endif
} ncp_cmn_axi_reng_sys_mem_reorder_buf_fifo_status_r_t;

/*! @struct ncp_cmn_axi_reng_sys_mem_reorder_buf_fifo_control_r_t
 *  @brief CMN Read Engine system memory reorder buffer FIFO control
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_reng_sys_mem_reorder_buf_fifo_control_r_t\n
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
 *     <td width="30%"> @param fifo_hwm </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> high watermark </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_reng_sys_mem_reorder_buf_fifo_control_r_t
 *
 * Implemented by: 
 *      cmn_reng_sys_mem_reorder_buf_fifo_control_00
 *      cmn_reng_sys_mem_reorder_buf_fifo_control_01
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      fifo_hwm                                  : 16;
#else    /* Little Endian */
     unsigned      fifo_hwm                                  : 16;
     unsigned      reserved0                                 : 16;
#endif
} ncp_cmn_axi_reng_sys_mem_reorder_buf_fifo_control_r_t;

/*! @struct ncp_cmn_axi_reng_ext_mem_reorder_buf_fifo_status_r_t
 *  @brief CMN Read Engine external memory reorder buffer FIFO status
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_reng_ext_mem_reorder_buf_fifo_status_r_t\n
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
 *     <td width="30%"> @param fifo_depth </td>
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> FIFO depth </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> FIFO full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_afull </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> FIFO almost full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_aempty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> FIFO almost empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_empty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> FIFO empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> FIFO parity error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> FIFO overflow </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_underflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> FIFO underflow </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_reng_ext_mem_reorder_buf_fifo_status_r_t
 *
 * Implemented by: 
 *      cmn_reng_ext_mem_reorder_buf_fifo_status_00
 *      cmn_reng_ext_mem_reorder_buf_fifo_status_01
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      fifo_depth                                :  9;
     unsigned      fifo_full                                 :  1;
     unsigned      fifo_afull                                :  1;
     unsigned      fifo_aempty                               :  1;
     unsigned      fifo_empty                                :  1;
     unsigned      fifo_parity_err                           :  1;
     unsigned      fifo_overflow                             :  1;
     unsigned      fifo_underflow                            :  1;
#else    /* Little Endian */
     unsigned      fifo_underflow                            :  1;
     unsigned      fifo_overflow                             :  1;
     unsigned      fifo_parity_err                           :  1;
     unsigned      fifo_empty                                :  1;
     unsigned      fifo_aempty                               :  1;
     unsigned      fifo_afull                                :  1;
     unsigned      fifo_full                                 :  1;
     unsigned      fifo_depth                                :  9;
     unsigned      reserved0                                 : 16;
#endif
} ncp_cmn_axi_reng_ext_mem_reorder_buf_fifo_status_r_t;

/*! @struct ncp_cmn_axi_reng_ext_mem_reorder_buf_fifo_control_r_t
 *  @brief CMN Read Engine external memory reorder buffer FIFO control
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_reng_ext_mem_reorder_buf_fifo_control_r_t\n
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
 *     <td width="30%"> @param fifo_hwm </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> high watermark </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_reng_ext_mem_reorder_buf_fifo_control_r_t
 *
 * Implemented by: 
 *      cmn_reng_ext_mem_reorder_buf_fifo_control_00
 *      cmn_reng_ext_mem_reorder_buf_fifo_control_01
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      fifo_hwm                                  : 16;
#else    /* Little Endian */
     unsigned      fifo_hwm                                  : 16;
     unsigned      reserved0                                 : 16;
#endif
} ncp_cmn_axi_reng_ext_mem_reorder_buf_fifo_control_r_t;

/*! @struct ncp_cmn_axi_cpcq_req_fifo_status_r_t
 *  @brief cPCQ request FIFO status
 *  @details FIFO for cPCQ requests from the NCA
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cpcq_req_fifo_status_r_t\n
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
 *     <td width="30%"> @param fifo_depth </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> FIFO depth </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> FIFO full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_afull </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> FIFO almost full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_aempty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> FIFO almost empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_empty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> FIFO empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> FIFO overflow </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_underflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> FIFO underflow </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cpcq_req_fifo_status_r_t
 *
 * Implemented by: 
 *      cpcq_req_fifo_status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      fifo_depth                                : 10;
     unsigned      fifo_full                                 :  1;
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
     unsigned      fifo_full                                 :  1;
     unsigned      fifo_depth                                : 10;
     unsigned      reserved0                                 : 16;
#endif
} ncp_cmn_axi_cpcq_req_fifo_status_r_t;

/*! @struct ncp_cmn_axi_cpcq_req_fifo_control_r_t
 *  @brief cPCQ request FIFO control
 *  @details FIFO for cPCQ requests from the NCA
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cpcq_req_fifo_control_r_t\n
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
 *     <td width="30%"> @param fifo_hwm </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> high watermark </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cpcq_req_fifo_control_r_t
 *
 * Implemented by: 
 *      cpcq_req_fifo_control
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      fifo_hwm                                  : 16;
#else    /* Little Endian */
     unsigned      fifo_hwm                                  : 16;
     unsigned      reserved0                                 : 16;
#endif
} ncp_cmn_axi_cpcq_req_fifo_control_r_t;

/*! @struct ncp_cmn_axi_cpcq_req_bresp_fifo_status_r_t
 *  @brief cPCQ request response FIFO status
 *  @details FIFO for responding to cPCQ requests from the NCA
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cpcq_req_bresp_fifo_status_r_t\n
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
 *     <td width="30%"> @param fifo_depth </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> FIFO depth </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> FIFO full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_afull </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> FIFO almost full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_aempty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> FIFO almost empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_empty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> FIFO empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> FIFO overflow </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_underflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> FIFO underflow </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cpcq_req_bresp_fifo_status_r_t
 *
 * Implemented by: 
 *      cpcq_req_bresp_fifo_status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      fifo_depth                                : 10;
     unsigned      fifo_full                                 :  1;
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
     unsigned      fifo_full                                 :  1;
     unsigned      fifo_depth                                : 10;
     unsigned      reserved0                                 : 16;
#endif
} ncp_cmn_axi_cpcq_req_bresp_fifo_status_r_t;

/*! @struct ncp_cmn_axi_cpcq_req_bresp_fifo_control_r_t
 *  @brief cPCQ request response FIFO control
 *  @details FIFO for responding to cPCQ requests from the NCA
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cpcq_req_bresp_fifo_control_r_t\n
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
 *     <td width="30%"> @param fifo_hwm </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> high watermark </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cpcq_req_bresp_fifo_control_r_t
 *
 * Implemented by: 
 *      cpcq_req_bresp_fifo_control
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      fifo_hwm                                  : 16;
#else    /* Little Endian */
     unsigned      fifo_hwm                                  : 16;
     unsigned      reserved0                                 : 16;
#endif
} ncp_cmn_axi_cpcq_req_bresp_fifo_control_r_t;

/*! @struct ncp_cmn_axi_cpcq_resp_fifo_status_r_t
 *  @brief cPCQ response FIFO status
 *  @details FIFO for cPCQ responses to the NCA
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cpcq_resp_fifo_status_r_t\n
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
 *     <td width="30%"> @param fifo_depth </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> FIFO depth </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> FIFO full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_afull </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> FIFO almost full </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_aempty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> FIFO almost empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_empty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> FIFO empty </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> FIFO overflow </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_underflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> FIFO underflow </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cpcq_resp_fifo_status_r_t
 *
 * Implemented by: 
 *      cpcq_resp_fifo_status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      fifo_depth                                : 10;
     unsigned      fifo_full                                 :  1;
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
     unsigned      fifo_full                                 :  1;
     unsigned      fifo_depth                                : 10;
     unsigned      reserved0                                 : 16;
#endif
} ncp_cmn_axi_cpcq_resp_fifo_status_r_t;

/*! @struct ncp_cmn_axi_cpcq_resp_fifo_control_r_t
 *  @brief cPCQ response FIFO control
 *  @details FIFO for cPCQ responses to the NCA
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cpcq_resp_fifo_control_r_t\n
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
 *     <td width="30%"> @param fifo_hwm </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> high watermark </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cpcq_resp_fifo_control_r_t
 *
 * Implemented by: 
 *      cpcq_resp_fifo_control
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      fifo_hwm                                  : 16;
#else    /* Little Endian */
     unsigned      fifo_hwm                                  : 16;
     unsigned      reserved0                                 : 16;
#endif
} ncp_cmn_axi_cpcq_resp_fifo_control_r_t;

/*! @struct ncp_cmn_axi_cfg_ttype_system_0_r_t
 *  @brief ttype system 0
 *  @details ttype, priority, and wrap for CAAL system memory interface used for cPCQ data
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cfg_ttype_system_0_r_t\n
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
 *     <td width="20%" align="center"> 18 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param priority_write </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> priority bit for write accesses </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ttype_write </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ttype for write accesses </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wrap_read </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> wrap bit for read accesses </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param priority_read </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> priority bit for read accesses </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ttype_read </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ttype for read accesses </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cfg_ttype_system_0_r_t
 *
 * Implemented by: 
 *      cfg_ttype_system_0_r
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 18;
     unsigned      priority_write                            :  1;
     unsigned      ttype_write                               :  5;
     unsigned      wrap_read                                 :  1;
     unsigned      priority_read                             :  1;
     unsigned      ttype_read                                :  6;
#else    /* Little Endian */
     unsigned      ttype_read                                :  6;
     unsigned      priority_read                             :  1;
     unsigned      wrap_read                                 :  1;
     unsigned      ttype_write                               :  5;
     unsigned      priority_write                            :  1;
     unsigned      reserved0                                 : 18;
#endif
} ncp_cmn_axi_cfg_ttype_system_0_r_t;

/*! @struct ncp_cmn_axi_cfg_ttype_system_1_r_t
 *  @brief ttype system 1
 *  @details ttype, priority, and wrap for CAAL interface used for memory-to-memory CMN commands
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cfg_ttype_system_1_r_t\n
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
 *     <td width="20%" align="center"> 18 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param priority_write </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> priority bit for write accesses </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ttype_write </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ttype for write accesses </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wrap_read </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> wrap bit for read accesses </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param priority_read </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> priority bit for read accesses </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ttype_read </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ttype for read accesses </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cfg_ttype_system_1_r_t
 *
 * Implemented by: 
 *      cfg_ttype_system_1_r
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 18;
     unsigned      priority_write                            :  1;
     unsigned      ttype_write                               :  5;
     unsigned      wrap_read                                 :  1;
     unsigned      priority_read                             :  1;
     unsigned      ttype_read                                :  6;
#else    /* Little Endian */
     unsigned      ttype_read                                :  6;
     unsigned      priority_read                             :  1;
     unsigned      wrap_read                                 :  1;
     unsigned      ttype_write                               :  5;
     unsigned      priority_write                            :  1;
     unsigned      reserved0                                 : 18;
#endif
} ncp_cmn_axi_cfg_ttype_system_1_r_t;

/*! @struct ncp_cmn_axi_cfg_ttype_external_0_r_t
 *  @brief ttype external 0
 *  @details ttype, priority, and wrap for CAAL external memory interface used for cPCQ data
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cfg_ttype_external_0_r_t\n
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
 *     <td width="20%" align="center"> 18 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param priority_write </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> priority bit for write accesses </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ttype_write </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ttype for write accesses </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wrap_read </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> wrap bit for read accesses </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param priority_read </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> priority bit for read accesses </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ttype_read </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ttype for read accesses </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cfg_ttype_external_0_r_t
 *
 * Implemented by: 
 *      cfg_ttype_external_0_r
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 18;
     unsigned      priority_write                            :  1;
     unsigned      ttype_write                               :  5;
     unsigned      wrap_read                                 :  1;
     unsigned      priority_read                             :  1;
     unsigned      ttype_read                                :  6;
#else    /* Little Endian */
     unsigned      ttype_read                                :  6;
     unsigned      priority_read                             :  1;
     unsigned      wrap_read                                 :  1;
     unsigned      ttype_write                               :  5;
     unsigned      priority_write                            :  1;
     unsigned      reserved0                                 : 18;
#endif
} ncp_cmn_axi_cfg_ttype_external_0_r_t;

/*! @struct ncp_cmn_axi_pio_cpcq_arb_control_r_t
 *  @brief PIO-cPCQ request arbiter control
 *  @details Weighted Round-Robin arbiter that arbitrates between PIO and cPCQ requests based on a configurable mode.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_pio_cpcq_arb_control_r_t\n
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
 *     <td width="30%"> @param mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> arbitration mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param weight_cpcq </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> weight for cPCQ requests </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param weight_pio </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> weight for PIO requests </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_pio_cpcq_arb_control_r_t
 *
 * Implemented by: 
 *      pio_cpcq_arb_control
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 14;
     unsigned      mode                                      :  2;
     unsigned      weight_cpcq                               :  8;
     unsigned      weight_pio                                :  8;
#else    /* Little Endian */
     unsigned      weight_pio                                :  8;
     unsigned      weight_cpcq                               :  8;
     unsigned      mode                                      :  2;
     unsigned      reserved0                                 : 14;
#endif
} ncp_cmn_axi_pio_cpcq_arb_control_r_t;

/*! @struct ncp_cmn_axi_pio_cpcq_arb_status_r_t
 *  @brief PIO-cPCQ request arbiter status
 *  @details Weighted Round-Robin arbiter that arbitrates between PIO and cPCQ requests based on a configurable mode.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_pio_cpcq_arb_status_r_t\n
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
 *     <td width="30%"> @param pio_cpcq_arbiter_req_cpcq_valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> cPCQ requestor is valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pio_cpcq_arbiter_req_pio_valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> PIO requestor is valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pio_cpcq_arbiter_winner_v </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> bit vector with single bit indicating the winner </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pio_cpcq_arbiter_winner </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> winning request type: 0=PIO, 1=cPCQ </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_pio_cpcq_arb_status_r_t
 *
 * Implemented by: 
 *      pio_cpcq_arb_status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 27;
     unsigned      pio_cpcq_arbiter_req_cpcq_valid           :  1;
     unsigned      pio_cpcq_arbiter_req_pio_valid            :  1;
     unsigned      pio_cpcq_arbiter_winner_v                 :  2;
     unsigned      pio_cpcq_arbiter_winner                   :  1;
#else    /* Little Endian */
     unsigned      pio_cpcq_arbiter_winner                   :  1;
     unsigned      pio_cpcq_arbiter_winner_v                 :  2;
     unsigned      pio_cpcq_arbiter_req_pio_valid            :  1;
     unsigned      pio_cpcq_arbiter_req_cpcq_valid           :  1;
     unsigned      reserved0                                 : 27;
#endif
} ncp_cmn_axi_pio_cpcq_arb_status_r_t;

/*! @struct ncp_cmn_axi_cfg_max_outstanding_cpcqs_r_t
 *  @brief Maximum outstanding cPCQ requests
 *  @details The CMN will backpressure cPCQ requests from the NCA if the number of outstanding (incomplete) cPCQ requests reaches this number.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cfg_max_outstanding_cpcqs_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param max_reqs </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Values greater than 8 will have no effect. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cfg_max_outstanding_cpcqs_r_t
 *
 * Implemented by: 
 *      cfg_max_outstanding_cpcqs
 */
 
typedef struct
{
     unsigned  int                  max_reqs;
} ncp_cmn_axi_cfg_max_outstanding_cpcqs_r_t;

/*! @struct ncp_cmn_axi_cfg_ring_parity_reg_t
 *  @brief NCA CFG Master Parity and CNAL ECC Register
 *  @details This register defines CFG Ring Parity Type , CNAL I/F ECC and Enables
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cfg_ring_parity_reg_t\n
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
 *     <td width="30%"> @param singlebit_ecc_correct_en </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> CNAL I/F correct singlebit ECC enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param singlebit_ecc_detect_en </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> CNAL I/F detect singlebit ECC enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param multibit_ecc_detect_en </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> CNAL I/F detect multibit ECC enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_par_err_rst_en </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> cfg_ring_parity_err_reset_exec_enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_parity_type_ring2 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> cfg_parity_type_ring2 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_parity_type_ring1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> cfg_parity_type_ring1 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_parity_type_ring0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> cfg_parity_type_ring0 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_parity_err_en_ring2 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> cfg_parity_err_en_ring3 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_parity_err_en_ring1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> cfg_parity_err_en_ring1 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_parity_err_en_ring0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> cfg_parity_err_en_ring0 </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cfg_ring_parity_reg_t
 *
 * Implemented by: 
 *      cfg_ring_parity
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 22;
     unsigned      singlebit_ecc_correct_en                  :  1;
     unsigned      singlebit_ecc_detect_en                   :  1;
     unsigned      multibit_ecc_detect_en                    :  1;
     unsigned      cfg_par_err_rst_en                        :  1;
     unsigned      cfg_parity_type_ring2                     :  1;
     unsigned      cfg_parity_type_ring1                     :  1;
     unsigned      cfg_parity_type_ring0                     :  1;
     unsigned      cfg_parity_err_en_ring2                   :  1;
     unsigned      cfg_parity_err_en_ring1                   :  1;
     unsigned      cfg_parity_err_en_ring0                   :  1;
#else    /* Little Endian */
     unsigned      cfg_parity_err_en_ring0                   :  1;
     unsigned      cfg_parity_err_en_ring1                   :  1;
     unsigned      cfg_parity_err_en_ring2                   :  1;
     unsigned      cfg_parity_type_ring0                     :  1;
     unsigned      cfg_parity_type_ring1                     :  1;
     unsigned      cfg_parity_type_ring2                     :  1;
     unsigned      cfg_par_err_rst_en                        :  1;
     unsigned      multibit_ecc_detect_en                    :  1;
     unsigned      singlebit_ecc_detect_en                   :  1;
     unsigned      singlebit_ecc_correct_en                  :  1;
     unsigned      reserved0                                 : 22;
#endif
} ncp_cmn_axi_cfg_ring_parity_reg_t;

/*! @struct ncp_cmn_axi_cfg_ring_dbg_stat0_reg_t
 *  @brief NCA CFG Master Debug Status Register0
 *  @details This register holds some internal signals for Debug purpose
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cfg_ring_dbg_stat0_reg_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cmd_out </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> CFG cmd_out </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data_out </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> CFG data_out </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param rcfg_wcdar </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> read into CDAR </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param rcfg_wbuff </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> read into Data BUFF </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param rd_data_cnt </td>
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> read data count </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param rd_data_done </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> read data done indication </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data_done </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> data done indication </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param timed_out </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> ACK time out indication </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param timer_state </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> timer state machine's state </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param state </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> main state machine's state </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cfg_ring_dbg_stat0_reg_t
 *
 * Implemented by: 
 *      cfg_ring_dbg_stat0
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      cmd_out                                   :  3;
     unsigned      data_out                                  :  8;
     unsigned      rcfg_wcdar                                :  1;
     unsigned      rcfg_wbuff                                :  1;
     unsigned      rd_data_cnt                               :  9;
     unsigned      rd_data_done                              :  1;
     unsigned      data_done                                 :  1;
     unsigned      timed_out                                 :  1;
     unsigned      timer_state                               :  3;
     unsigned      state                                     :  4;
#else    /* Little Endian */
     unsigned      state                                     :  4;
     unsigned      timer_state                               :  3;
     unsigned      timed_out                                 :  1;
     unsigned      data_done                                 :  1;
     unsigned      rd_data_done                              :  1;
     unsigned      rd_data_cnt                               :  9;
     unsigned      rcfg_wbuff                                :  1;
     unsigned      rcfg_wcdar                                :  1;
     unsigned      data_out                                  :  8;
     unsigned      cmd_out                                   :  3;
#endif
} ncp_cmn_axi_cfg_ring_dbg_stat0_reg_t;

/*! @struct ncp_cmn_axi_cfg_ring_dbg_stat1_reg_t
 *  @brief NCA CFG Master Debug Status Register1
 *  @details This register holds some internal signals for Debug purpose
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cfg_ring_dbg_stat1_reg_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param ring0_parity_in </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> CFG0_par_in </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ring1_parity_in </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> CFG1_par_in </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ring2_parity_in </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> CFG2_par_in </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmd_in </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> CFG_cmd_in </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param data_in </td>
 *     <td width="20%" align="center"> 26 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> CFG data_in </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cfg_ring_dbg_stat1_reg_t
 *
 * Implemented by: 
 *      cfg_ring_dbg_stat1
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      ring0_parity_in                           :  1;
     unsigned      ring1_parity_in                           :  1;
     unsigned      ring2_parity_in                           :  1;
     unsigned      cmd_in                                    :  3;
     unsigned      data_in                                   : 26;
#else    /* Little Endian */
     unsigned      data_in                                   : 26;
     unsigned      cmd_in                                    :  3;
     unsigned      ring2_parity_in                           :  1;
     unsigned      ring1_parity_in                           :  1;
     unsigned      ring0_parity_in                           :  1;
#endif
} ncp_cmn_axi_cfg_ring_dbg_stat1_reg_t;

/*! @struct ncp_cmn_axi_cnal_if_error_status_reg_t
 *  @brief CNAL Interface SysMem Read/Write Error Status Register
 *  @details This register holds errors from the CNAL interface.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cnal_if_error_status_reg_t\n
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
 *     <td width="30%"> @param read_resp_err_code </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> CNAL Interface Read Response error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param write_resp_err_code </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> CNAL Interface Write Response error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ecc_single_l_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> CNAL Interface lower word ECC Singlebit error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ecc_single_u_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> CNAL Interface upper word ECC Singlebit error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ecc_multiple_l_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> CNAL Interface lower word ECC Multibit error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ecc_multiple_u_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> CNAL Interface upper word ECC Multibit error </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cnal_if_error_status_reg_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 24;
     unsigned      read_resp_err_code                        :  2;
     unsigned      write_resp_err_code                       :  2;
     unsigned      ecc_single_l_err                          :  1;
     unsigned      ecc_single_u_err                          :  1;
     unsigned      ecc_multiple_l_err                        :  1;
     unsigned      ecc_multiple_u_err                        :  1;
#else    /* Little Endian */
     unsigned      ecc_multiple_u_err                        :  1;
     unsigned      ecc_multiple_l_err                        :  1;
     unsigned      ecc_single_u_err                          :  1;
     unsigned      ecc_single_l_err                          :  1;
     unsigned      write_resp_err_code                       :  2;
     unsigned      read_resp_err_code                        :  2;
     unsigned      reserved0                                 : 24;
#endif
} ncp_cmn_axi_cnal_if_error_status_reg_t;

/*! @struct ncp_cmn_axi_cnal_if_status_reg_t
 *  @brief CNAL Interface SysMem Read/Write Status Register
 *  @details This register holds the value returned when CNAL I/F status is asked
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cnal_if_status_reg_t\n
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
 *     <td width="30%"> @param cnal_eng_cwd_ready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> CMSI Write Data Ready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnal_eng_cwr_ready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> CMSI Write Request Ready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnal_eng_crr_ready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> CMSI Read Request Ready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnal_read_transaction_state </td>
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> CNAL Interface Read transaction state </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnal_write_transaction_state </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> CNAL Interface Write transaction state </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cnal_if_status_reg_t
 *
 * Implemented by: 
 *      cnal_if_status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      cnal_eng_cwd_ready                        :  1;
     unsigned      cnal_eng_cwr_ready                        :  1;
     unsigned      cnal_eng_crr_ready                        :  1;
     unsigned      cnal_read_transaction_state               :  7;
     unsigned      cnal_write_transaction_state              :  6;
#else    /* Little Endian */
     unsigned      cnal_write_transaction_state              :  6;
     unsigned      cnal_read_transaction_state               :  7;
     unsigned      cnal_eng_crr_ready                        :  1;
     unsigned      cnal_eng_cwr_ready                        :  1;
     unsigned      cnal_eng_cwd_ready                        :  1;
     unsigned      reserved0                                 : 16;
#endif
} ncp_cmn_axi_cnal_if_status_reg_t;

/*! @struct ncp_cmn_axi_cnal_control_reg_t
 *  @brief NCA CFG Master's CNAL Control Register
 *  @details This register defines cnal_soft_reset bit
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cnal_control_reg_t\n
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
 *     <td width="30%"> @param cnal_soft_reset </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> cnal_soft_reset: if set by sw, hw clears it when reset
 *        done
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cnal_control_reg_t
 *
 * Implemented by: 
 *      cnal_control
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 31;
     unsigned      cnal_soft_reset                           :  1;
#else    /* Little Endian */
     unsigned      cnal_soft_reset                           :  1;
     unsigned      reserved0                                 : 31;
#endif
} ncp_cmn_axi_cnal_control_reg_t;

/*! @struct ncp_cmn_axi_num_of_cfg_nodes_reg_t
 *  @brief Number of CFG Rings
 *  @details keeps the number of CFG nodes on each CFG Ring
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_num_of_cfg_nodes_reg_t\n
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
 *     <td width="30%"> @param num_nodes_ring2 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> max_num_of_cfg_nodes_ring2 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param num_nodes_ring1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> max_num_of_cfg_nodes_ring1 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param num_nodes_ring0 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> max_num_of_cfg_nodes_ring0 </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_num_of_cfg_nodes_reg_t
 *
 * Implemented by: 
 *      num_of_cfg_nodes
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  8;
     unsigned      num_nodes_ring2                           :  8;
     unsigned      num_nodes_ring1                           :  8;
     unsigned      num_nodes_ring0                           :  8;
#else    /* Little Endian */
     unsigned      num_nodes_ring0                           :  8;
     unsigned      num_nodes_ring1                           :  8;
     unsigned      num_nodes_ring2                           :  8;
     unsigned      reserved0                                 :  8;
#endif
} ncp_cmn_axi_num_of_cfg_nodes_reg_t;

/*! @struct ncp_cmn_axi_cfg_ring_error_stat_reg0_t
 *  @brief CFG Ring Command Error Status Register 0
 *  @details CFG Ring Command Execution error status register 0
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cfg_ring_error_stat_reg0_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param target_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> Target_Error_detected </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param node_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> Node_Error_detected </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param node_err_type_bit_3_2 </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Node Error_Type[3:2] when node error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param time_out_err_or_node_err_type_bit1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> TimeOut Error indication at target error or Node Error_Type_Bit[1] </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param decode_err_or_node_err_type_bit0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> Decode Error indication at target error or Node Error_Type_Bit[0] </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param local_bit </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> Local Bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param instruction </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> CFG Ring instruction </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param inst_len </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Instruction length </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ring_id </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Ring ID </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param node_id </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Target Node ID </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param target_id </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Target ID </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cfg_ring_error_stat_reg0_t
 *
 * Implemented by: 
 *      cfg_ring_error_stat_r0
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      target_error                              :  1;
     unsigned      node_error                                :  1;
     unsigned      node_err_type_bit_3_2                     :  2;
     unsigned      time_out_err_or_node_err_type_bit1        :  1;
     unsigned      decode_err_or_node_err_type_bit0          :  1;
     unsigned      local_bit                                 :  1;
     unsigned      instruction                               :  3;
     unsigned      inst_len                                  :  6;
     unsigned      ring_id                                   :  2;
     unsigned      node_id                                   :  6;
     unsigned      target_id                                 :  8;
#else    /* Little Endian */
     unsigned      target_id                                 :  8;
     unsigned      node_id                                   :  6;
     unsigned      ring_id                                   :  2;
     unsigned      inst_len                                  :  6;
     unsigned      instruction                               :  3;
     unsigned      local_bit                                 :  1;
     unsigned      decode_err_or_node_err_type_bit0          :  1;
     unsigned      time_out_err_or_node_err_type_bit1        :  1;
     unsigned      node_err_type_bit_3_2                     :  2;
     unsigned      node_error                                :  1;
     unsigned      target_error                              :  1;
#endif
} ncp_cmn_axi_cfg_ring_error_stat_reg0_t;

/*! @struct ncp_cmn_axi_cfg_ring_error_stat_reg1_t
 *  @brief CFG Ring Command Error Status Register 1
 *  @details CFG Ring Command Execution error status register 1
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cfg_ring_error_stat_reg1_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param wrong_ack_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> Wrong ACK received error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param acktimeout_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> ACK Time-Out Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param unclaimed_header_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> Unclaimed Header Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param parity_err_ring0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Parity Error Ring0 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param parity_err_ring1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Parity Error Ring1 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param parity_err_ring2 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> Parity Error Ring2 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param local_bit </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> Local Bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param instruction </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> CFG Ring instruction </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param inst_len </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Instruction length </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ring_id </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Ring ID </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param node_id </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Target Node ID </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param target_id </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Target ID </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cfg_ring_error_stat_reg1_t
 *
 * Implemented by: 
 *      cfg_ring_error_stat_r1
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      wrong_ack_err                             :  1;
     unsigned      acktimeout_err                            :  1;
     unsigned      unclaimed_header_err                      :  1;
     unsigned      parity_err_ring0                          :  1;
     unsigned      parity_err_ring1                          :  1;
     unsigned      parity_err_ring2                          :  1;
     unsigned      local_bit                                 :  1;
     unsigned      instruction                               :  3;
     unsigned      inst_len                                  :  6;
     unsigned      ring_id                                   :  2;
     unsigned      node_id                                   :  6;
     unsigned      target_id                                 :  8;
#else    /* Little Endian */
     unsigned      target_id                                 :  8;
     unsigned      node_id                                   :  6;
     unsigned      ring_id                                   :  2;
     unsigned      inst_len                                  :  6;
     unsigned      instruction                               :  3;
     unsigned      local_bit                                 :  1;
     unsigned      parity_err_ring2                          :  1;
     unsigned      parity_err_ring1                          :  1;
     unsigned      parity_err_ring0                          :  1;
     unsigned      unclaimed_header_err                      :  1;
     unsigned      acktimeout_err                            :  1;
     unsigned      wrong_ack_err                             :  1;
#endif
} ncp_cmn_axi_cfg_ring_error_stat_reg1_t;

/*! @struct ncp_cmn_axi_cfg_ring_node_status_reg_t
 *  @brief CFG Ring Node Status Register
 *  @details This register holds the value returned when status is asked, write 1 to bit16 of NCA Interrupt Register at F000 to clear
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cfg_ring_node_status_reg_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param node_status </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Node Status </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cfg_ring_node_status_reg_t
 *
 * Implemented by: 
 *      cfg_ring_node_status
 */
 
typedef struct
{
     unsigned  int               node_status;
} ncp_cmn_axi_cfg_ring_node_status_reg_t;

/*! @struct ncp_cmn_axi_cfg_pio_cdr0_reg_t
 *  @brief PIO Mode Command Data Register 0
 *  @details PIO Mode CFG command descrption register 0
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cfg_pio_cdr0_reg_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param start_done </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> Start/Done, set to 1 to initiate a PIO operation,
 *        cleared by hw when done
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param local_bit </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Local bit that defines Node's Own Address Space </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param status </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Execution Status : 00= inactive 01= ongoing executiondarkreddarkgreen </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param byte_swap_enable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Byte Swap Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_cmpl_int_enable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Interrupt Enable on CFG Command Completion </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmd_type </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> CPU CFG Command Type, encoded as: blue </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param dbs </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Data Buffer Size: length of Data Buffer in Bytes 0
 *        means 1 Byte
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cfg_pio_cdr0_reg_t
 *
 * Implemented by: 
 *      cfg_pio_cdr0
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      start_done                                :  1;
     unsigned      reserved0                                 :  6;
     unsigned      local_bit                                 :  1;
     unsigned      status                                    :  2;
     unsigned      byte_swap_enable                          :  1;
     unsigned      cfg_cmpl_int_enable                       :  1;
     unsigned      cmd_type                                  :  4;
     unsigned      dbs                                       : 16;
#else    /* Little Endian */
     unsigned      dbs                                       : 16;
     unsigned      cmd_type                                  :  4;
     unsigned      cfg_cmpl_int_enable                       :  1;
     unsigned      byte_swap_enable                          :  1;
     unsigned      status                                    :  2;
     unsigned      local_bit                                 :  1;
     unsigned      reserved0                                 :  6;
     unsigned      start_done                                :  1;
#endif
} ncp_cmn_axi_cfg_pio_cdr0_reg_t;

/*! @struct ncp_cmn_axi_cfg_pio_cdr1_reg_t
 *  @brief PIO Mode Command Data Register 1
 *  @details PIO Mode CFG command descrption register 1
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cfg_pio_cdr1_reg_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param target_address </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> For CR* Commands : CFG Ring Target Address, For CS*
 *        and SM* Commands : System Memory Address Lower bits
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cfg_pio_cdr1_reg_t
 *
 * Implemented by: 
 *      cfg_pio_cdr1
 */
 
typedef struct
{
     unsigned  int            target_address;
} ncp_cmn_axi_cfg_pio_cdr1_reg_t;

/*! @struct ncp_cmn_axi_cfg_pio_cdr2_reg_t
 *  @brief PIO Mode Command Data Register 2
 *  @details PIO Mode CFG command descrption register 2
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cfg_pio_cdr2_reg_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param va </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> For CR* Commands : unused, For CS* and SM* Commands
 *        : unused
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param target_node_id </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> For CR* Commands : CFG Ring Target Node ID, For CS*
 *        and SM* Commands : unused
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param target_id_address_upper </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> For CR* Commands : CFG Ring Target ID, For CS* and
 *        SM* Commands : System Memory Virtual Address Upper
 *        bits 35:32 (upper 4 bits not used)
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cfg_pio_cdr2_reg_t
 *
 * Implemented by: 
 *      cfg_pio_cdr2
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      va                                        : 16;
     unsigned      target_node_id                            :  8;
     unsigned      target_id_address_upper                   :  8;
#else    /* Little Endian */
     unsigned      target_id_address_upper                   :  8;
     unsigned      target_node_id                            :  8;
     unsigned      va                                        : 16;
#endif
} ncp_cmn_axi_cfg_pio_cdr2_reg_t;

/*! @struct ncp_cmn_axi_cfg_pio_cdr3_reg_t
 *  @brief PIO Mode Command Data Register 3
 *  @details PIO Mode CFG command descrption register 3
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cfg_pio_cdr3_reg_t\n
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
 *     <td width="30%"> @param spare </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> spare </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pool_id </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> For CR* Commands : unused, For CS* and SM* Commands
 *        : System memory Pool ID
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cfg_pio_cdr3_reg_t
 *
 * Implemented by: 
 *      cfg_pio_cdr3
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 22;
     unsigned      spare                                     :  2;
     unsigned      reserved1                                 :  3;
     unsigned      pool_id                                   :  5;
#else    /* Little Endian */
     unsigned      pool_id                                   :  5;
     unsigned      reserved1                                 :  3;
     unsigned      spare                                     :  2;
     unsigned      reserved0                                 : 22;
#endif
} ncp_cmn_axi_cfg_pio_cdr3_reg_t;

/*! @struct ncp_cmn_axi_cfg_ring_ack_timer_cnt_reg_t
 *  @brief CFG RING ACK Timer Register
 *  @details if enabled, this counter defines a Time-Out value for ACK responses
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cfg_ring_ack_timer_cnt_reg_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_ring_ack_timer_timeout </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> cfg_ring_ack_timer_timeout_value </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cfg_ring_ack_timer_cnt_reg_t
 *
 * Implemented by: 
 *      cfg_ring_ack_timer_cnt
 */
 
typedef struct
{
     unsigned  int      cfg_ring_ack_timer_timeout;
} ncp_cmn_axi_cfg_ring_ack_timer_cnt_reg_t;

/*! @struct ncp_cmn_axi_cdar_entry_t
 *  @brief PIO mode data word
 *  @details CDAR local memory for PIO mode
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cdar_entry_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param pio_mode_word </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> PIO mode word entry </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cdar_entry_t
 *
 * Implemented by: 
 *      cdar_memory
 */
 
typedef struct
{
     unsigned  int             pio_mode_word;
} ncp_cmn_axi_cdar_entry_t;

/*! @struct ncp_cmn_axi_cdar_entry_last_word_t
 *  @brief PIO mode last data word
 *  @details CDAR local memory word 129 for PIO mode
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cdar_entry_last_word_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param pio_mode_word_129 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> PIO mode word 129 entry </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cdar_entry_last_word_t
 *
 * Implemented by: 
 *      cdar_word_129
 */
 
typedef struct
{
     unsigned  int         pio_mode_word_129;
} ncp_cmn_axi_cdar_entry_last_word_t;

/*! @struct ncp_cmn_axi_nca_pio_lock_cown_reg_t
 *  @brief NCA PIO Lock Current Owner Register
 *  @details This register provides the ability to read the nca_pio_lock register without engaging the semaphore mechanism.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_nca_pio_lock_cown_reg_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param proc_id </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Only one bit will ever be set at a time. Indicates
 *        ID of processor that has control of configuration
 *        interface.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_nca_pio_lock_cown_reg_t
 *
 * Implemented by: 
 *      nca_pio_lock_cown
 */
 
typedef struct
{
     unsigned  int                   proc_id;
} ncp_cmn_axi_nca_pio_lock_cown_reg_t;

/*! @struct ncp_cmn_axi_nca_pio_lock_reg_t
 *  @brief NCA PIO Lock Register
 *  @details Provides a semaphore mechanism for multiprocessor sharing of the configuration interface in PIO mode.  Address bits 6:2 form the ID address which indicates the ID of the processor accessing this register.  A processor    reads this register to acquire control.  Reading a 0 indicates that the processor has control, and the register bit selected by the ID address is set.  Reading other than zero means that the interface is not available.  The          processor in control must write anything to its ID address to clear the register to allow control to pass to another processor.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_nca_pio_lock_reg_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param proc_id </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Only one bit will ever be set at a time. Indicates
 *        ID of processor that has control of configuration
 *        interface.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_nca_pio_lock_reg_t
 *
 * Implemented by: 
 *      nca_pio_lock
 */
 
typedef struct
{
     unsigned  int                   proc_id;
} ncp_cmn_axi_nca_pio_lock_reg_t;

/*! @struct ncp_cmn_axi_cfg_enablesecure_r_t
 *  @brief CMN secure access enable
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cfg_enablesecure_r_t\n
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
 *     <td width="30%"> @param cfg_enablenonsecure </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Enable nonsecure configuration access for CMN registers. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cfg_enablesecure_r_t
 *
 * Implemented by: 
 *      cfg_enablesecure
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 31;
     unsigned      cfg_enablenonsecure                       :  1;
#else    /* Little Endian */
     unsigned      cfg_enablenonsecure                       :  1;
     unsigned      reserved0                                 : 31;
#endif
} ncp_cmn_axi_cfg_enablesecure_r_t;

/*! @struct ncp_cmn_axi_config_init_reg_t
 *  @brief NCA Configuration and Initialization Control
 *  @details This register contains memory access burst beat numbers and block enables.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_config_init_reg_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param spare6 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> spare </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param itask_end_data_fill_off </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> Turn off filling of dummy data on last quadword of
 *        an itask that makes the last write 16 bytes.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_ring_ack_timer_en </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> Configuration ring acknowledge timer enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ita_ord_wr_disable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Input task accumulator ordered write disable. Makes
 *        the input task accumulator not wait for itask header/data
 *        write response before writing iPCQ entry.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param opcq_entry_wr_dis </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> oPCQ entry write disable. If set, software must set
 *        the pcq_grp_r1 register upload_nca_pgit_en bit for
 *        all active PCQ groups.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cpcq_en </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> cPCQ processing enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param otask_accum_en </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> Output task accumulator enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param itask_accum_en </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Input task accumulator enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param spare4 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> spare </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param otbp_soft_reset </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Output task backpressure soft reset </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param spare3 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> spare </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param mpbf_en </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> MME pool buffer FIFO enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param otbp_ext_mem_wen </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Output task backpressure external memory write enable.
 *        Turning this bit on immediatly causes a write of otask_opcq_bp
 *        to memory at the address defined by otbp_vi_upper
 *        and otbp_vi_lower. Subsequent writes will occur any
 *        time the state of otask_opcq_bp changes.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param spare2 </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> spare </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cpcq_exec_disable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> cpcq execution disable bit : NOTE: This bit is supposed
 *        to be used sparingly (for debugging etc.) to temporarily
 *        halt the execution from cfg request fifo of the cpcq
 *        entries
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param spare1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> spare </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param opcq_num_ent_per_req_m1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> oPCQ number of entries per request minus 1. Sets the
 *        maximum number of oPCQ entries to be fetched per request
 *        to the oPCQ entry read engine. (0 = 1, 1 = 2, 2 =
 *        3, etc.)
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ota_num_beat </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> output task acumulator memory access number of beats
 *        per burst:00:1,01:2,1X:4
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ita_num_beat </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> input task acumulator memory access number of beats
 *        per burst:00:1,01:2,1X:4
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param spare0 </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> spare </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pgit_w_num_beat </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> NCA pgit memory write access number of beats per burst:00:1,01:2,1X:4 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pgit_r_num_beat </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> NCA pgit memory read access number of beats per burst:00:1,01:2,1X:4 </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_config_init_reg_t
 *
 * Implemented by: 
 *      config_init
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      spare6                                    :  1;
     unsigned      itask_end_data_fill_off                   :  1;
     unsigned      cfg_ring_ack_timer_en                     :  1;
     unsigned      ita_ord_wr_disable                        :  1;
     unsigned      opcq_entry_wr_dis                         :  1;
     unsigned      cpcq_en                                   :  1;
     unsigned      otask_accum_en                            :  1;
     unsigned      itask_accum_en                            :  1;
     unsigned      spare4                                    :  1;
     unsigned      otbp_soft_reset                           :  1;
     unsigned      spare3                                    :  1;
     unsigned      mpbf_en                                   :  1;
     unsigned      otbp_ext_mem_wen                          :  1;
     unsigned      spare2                                    :  2;
     unsigned      cpcq_exec_disable                         :  1;
     unsigned      spare1                                    :  2;
     unsigned      opcq_num_ent_per_req_m1                   :  2;
     unsigned      ota_num_beat                              :  2;
     unsigned      ita_num_beat                              :  2;
     unsigned      spare0                                    :  4;
     unsigned      pgit_w_num_beat                           :  2;
     unsigned      pgit_r_num_beat                           :  2;
#else    /* Little Endian */
     unsigned      pgit_r_num_beat                           :  2;
     unsigned      pgit_w_num_beat                           :  2;
     unsigned      spare0                                    :  4;
     unsigned      ita_num_beat                              :  2;
     unsigned      ota_num_beat                              :  2;
     unsigned      opcq_num_ent_per_req_m1                   :  2;
     unsigned      spare1                                    :  2;
     unsigned      cpcq_exec_disable                         :  1;
     unsigned      spare2                                    :  2;
     unsigned      otbp_ext_mem_wen                          :  1;
     unsigned      mpbf_en                                   :  1;
     unsigned      spare3                                    :  1;
     unsigned      otbp_soft_reset                           :  1;
     unsigned      spare4                                    :  1;
     unsigned      itask_accum_en                            :  1;
     unsigned      otask_accum_en                            :  1;
     unsigned      cpcq_en                                   :  1;
     unsigned      opcq_entry_wr_dis                         :  1;
     unsigned      ita_ord_wr_disable                        :  1;
     unsigned      cfg_ring_ack_timer_en                     :  1;
     unsigned      itask_end_data_fill_off                   :  1;
     unsigned      spare6                                    :  1;
#endif
} ncp_cmn_axi_config_init_reg_t;

/*! @struct ncp_cmn_axi_int_stat_reg_t
 *  @brief Configuration Ring Master Node Int Stat/Syndrome
 *  @details Provides additional syndrome information related to corresponding interrupts.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_int_stat_reg_t\n
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
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param eng_cnal_if_int_grp_num </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> eng_cnal_if_int_grp_num. When eng_cnal_if_int_is_pio
 *        is clear, and at least one of the grp_interrupt_status_table.status_r2.eng_cnal_if_grp_int
 *        bits is set, this field indicates for which group
 *        number the cnal_if_status register contains error
 *        data.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param eng_cnal_if_int_is_pio </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> eng_cnal_if interrupt is for pio mode. When this bit
 *        and the grp_interrupt_status_table.status_r3.eng_cnal_if_pio_int
 *        bit are both set, the cnal_if_status register contains
 *        error data for that interrupt.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_ring_err_int_grp_num </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> cfg_ring_err_int_grp_num. When cfg_ring_err_int_is_pio
 *        is clear, and at least one of the grp_interrupt_status_table.status_r2.cfg_ring_err_grp_int
 *        bits is set, this field indicates for which group
 *        number the cfg_ring_error_stat_r|0..1| registers contain
 *        error data.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_ring_err_int_is_pio </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> cfg_ring_err interrupt is for pio mode. When this
 *        bit and the grp_interrupt_status_table.status_r3.cfg_ring_err_pio_int
 *        bit are both set, the cfg_ring_error_stat_r|0..1|
 *        registers contain error data for that interrupt.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved2 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cpcq_mem_rd_err_mem_sel </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> cPCQ memory read error memory select. 0 - system memory,
 *        1 - AXI memory.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cpcq_mem_rd_err_resp </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> cPCQ memory read error response code. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cpcq_mem_rd_err_group_num </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> cPCQ memory read error group number. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved3 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_mem_wr_err_mem_sel </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> CMN memory write error memory select. 0 - system memory,
 *        1 - AXI memory.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_mem_wr_err_resp </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> CMN memory write error response code. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved4 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_mem_rd_err_mem_sel </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> CMN memory read error memory select. 0 - system memory,
 *        1 - AXI memory.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_mem_rd_err_resp </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> CMN memory read error response code. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_int_stat_reg_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  3;
     unsigned      eng_cnal_if_int_grp_num                   :  4;
     unsigned      eng_cnal_if_int_is_pio                    :  1;
     unsigned      reserved1                                 :  3;
     unsigned      cfg_ring_err_int_grp_num                  :  4;
     unsigned      cfg_ring_err_int_is_pio                   :  1;
     unsigned      reserved2                                 :  1;
     unsigned      cpcq_mem_rd_err_mem_sel                   :  1;
     unsigned      cpcq_mem_rd_err_resp                      :  2;
     unsigned      cpcq_mem_rd_err_group_num                 :  4;
     unsigned      reserved3                                 :  1;
     unsigned      cmn_mem_wr_err_mem_sel                    :  1;
     unsigned      cmn_mem_wr_err_resp                       :  2;
     unsigned      reserved4                                 :  1;
     unsigned      cmn_mem_rd_err_mem_sel                    :  1;
     unsigned      cmn_mem_rd_err_resp                       :  2;
#else    /* Little Endian */
     unsigned      cmn_mem_rd_err_resp                       :  2;
     unsigned      cmn_mem_rd_err_mem_sel                    :  1;
     unsigned      reserved4                                 :  1;
     unsigned      cmn_mem_wr_err_resp                       :  2;
     unsigned      cmn_mem_wr_err_mem_sel                    :  1;
     unsigned      reserved3                                 :  1;
     unsigned      cpcq_mem_rd_err_group_num                 :  4;
     unsigned      cpcq_mem_rd_err_resp                      :  2;
     unsigned      cpcq_mem_rd_err_mem_sel                   :  1;
     unsigned      reserved2                                 :  1;
     unsigned      cfg_ring_err_int_is_pio                   :  1;
     unsigned      cfg_ring_err_int_grp_num                  :  4;
     unsigned      reserved1                                 :  3;
     unsigned      eng_cnal_if_int_is_pio                    :  1;
     unsigned      eng_cnal_if_int_grp_num                   :  4;
     unsigned      reserved0                                 :  3;
#endif
} ncp_cmn_axi_int_stat_reg_t;

/*! @struct ncp_cmn_axi_cpcq_state_reg_t
 *  @brief Configuration Master Node cPCQ State Register
 *  @details This register shows the current state of the cpcq_load_index_tbl_state_q, cpcq_pcq_entry_add_state_q, and cpcq_as_access_state_q state machines.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cpcq_state_reg_t\n
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
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cpcq_load_index_tbl_state_q </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Current state of the cpcq_load_index_tbl_state_q state
 *        machine.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cpcq_pcq_entry_add_state_q </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Current state of the cpcq_pcq_entry_add_state_q state
 *        machine.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved2 </td>
 *     <td width="20%" align="center"> 13 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cpcq_as_access_state_q </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Current state of the cpcq_as_access_state_q state
 *        machine.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_cpcq_state_reg_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  7;
     unsigned      cpcq_load_index_tbl_state_q               :  1;
     unsigned      reserved1                                 :  5;
     unsigned      cpcq_pcq_entry_add_state_q                :  3;
     unsigned      reserved2                                 : 13;
     unsigned      cpcq_as_access_state_q                    :  3;
#else    /* Little Endian */
     unsigned      cpcq_as_access_state_q                    :  3;
     unsigned      reserved2                                 : 13;
     unsigned      cpcq_pcq_entry_add_state_q                :  3;
     unsigned      reserved1                                 :  5;
     unsigned      cpcq_load_index_tbl_state_q               :  1;
     unsigned      reserved0                                 :  7;
#endif
} ncp_cmn_axi_cpcq_state_reg_t;

/*! @struct ncp_cmn_axi_status_reg0_t
 *  @brief Interrupt Status Register
 *  @details This register holds interrupt status. When the int_output_mode register is set to a5500_compatible mode, the status maps diretly to interrupt pins on a group number basis; otherwise, the status maps directly to interrupt pins
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_status_reg0_t\n
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
 *   <td width="30%"> null </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_status_reg0_t
 *
 * Implemented by: 
 *      status_r0
 *      status_r1
 *      status_r2
 *      status_r3
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_cmn_axi_status_reg0_t;

/*! @struct ncp_cmn_axi_en_reg0_t
 *  @brief Interrupt Enable Register
 *  @details This register enables interrupts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_en_reg0_t\n
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
 *   <td width="30%"> null </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_en_reg0_t
 *
 * Implemented by: 
 *      en_r0
 *      en_r1
 *      en_r2
 *      en_r3
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_cmn_axi_en_reg0_t;

/*! @struct ncp_cmn_axi_force_reg0_t
 *  @brief Interrupt Force Register
 *  @details This address is an alias for the Interrupt Status Register that allows normal CFG writes (as opposed to the Clear-On-Write-One behavior if the Interrupt Status Register address is used). This allows CFG to set interrupt bits for testing purposes. Reading  this address returns the current value of the Interrupt Status Register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_force_reg0_t\n
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
 *   <td width="30%"> null </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_force_reg0_t
 *
 * Implemented by: 
 *      frc_r0
 *      frc_r1
 *      frc_r2
 *      frc_r3
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_cmn_axi_force_reg0_t;

/*! @struct ncp_cmn_axi_en_reg0_woclr_t
 *  @brief Interrupt Enable Register
 *  @details This is an alias of grp_interrupt_enable_table.en_r0 which performs write one to clear.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_en_reg0_woclr_t\n
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
 *   <td width="30%"> null </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_en_reg0_woclr_t
 *
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_cmn_axi_en_reg0_woclr_t;

/*! @struct ncp_cmn_axi_sw_scratch_r_t
 *  @brief null
 *  @details SW scratch area. NON FUNCTIONAL. RESERVED for future use
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_sw_scratch_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param sw_scratch </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> SW scratch area. NON FUNCTIONAL. RESERVED for future
 *        use
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_sw_scratch_r_t
 *
 * Implemented by: 
 *      sw_scratch
 */
 
typedef struct
{
     unsigned  int                sw_scratch;
} ncp_cmn_axi_sw_scratch_r_t;

/*! @struct ncp_cmn_axi_int_reg0_status_r_t
 *  @brief Interrupt Status Register
 *  @details This register holds interrupt status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_int_reg0_status_r_t\n
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
 *     <td width="30%"> @param read_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> cfg read error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param write_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> cfg write error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param eng_cnal_if_stat </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> eng_cnal_if_stat Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pio_inst_done </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> A CMN instruction completed (not an error). Does not
 *        require interrupt enable to be set in PIO/cPCQ instruction
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cpcq_command_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> cpcq_command_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cpcq_valid_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> cpcq_valid_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cpcq_fc_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> cpcq_fc_error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param outstanding_cpcqs_counter_overflow_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> ALARM: The CMN's outstanding cPCQ counter overflowed.
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param outstanding_cpcqs_counter_underflow_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> ALARM: The CMN's outstanding cPCQ counter underflowed.
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param smon_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> The CMN's SMON triggered an interrupt. Read the SMON's
 *        status for more details. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param invalid_pio_start_not_done_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Software attempted to write CDR0 while a PIO instruction
 *        was still active. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_axi_read_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Received an error response for a CMN read access on
 *        either the system_0 or external_0 memory interface.
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_axi_write_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Received an error response for a CMN write access
 *        on either the system_0 or external_0 memory interface.
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_inst_compl_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> A CMN instruction completed (not an error). Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param eng_cnal_if_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Received an error response for a CMN read or write
 *        access on the system_1 memory interface. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param eng_cnal_if_pio_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Same as eng_cnal_if_int but specifically in PIO mode.
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_ring_err_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Either a config ring error or eng_cnal_if_int occurred.
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_ring_err_pio_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Same as cfg_ring_err_int but specifically in PIO mode.
 *        Status
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_int_reg0_status_r_t
 *
 * Implemented by: 
 *      status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 14;
     unsigned      read_err                                  :  1;
     unsigned      write_err                                 :  1;
     unsigned      eng_cnal_if_stat                          :  1;
     unsigned      pio_inst_done                             :  1;
     unsigned      cpcq_command_error                        :  1;
     unsigned      cpcq_valid_error                          :  1;
     unsigned      cpcq_fc_error                             :  1;
     unsigned      outstanding_cpcqs_counter_overflow_int    :  1;
     unsigned      outstanding_cpcqs_counter_underflow_int   :  1;
     unsigned      smon_int                                  :  1;
     unsigned      invalid_pio_start_not_done_int            :  1;
     unsigned      cmn_axi_read_int                          :  1;
     unsigned      cmn_axi_write_int                         :  1;
     unsigned      cfg_inst_compl_int                        :  1;
     unsigned      eng_cnal_if_int                           :  1;
     unsigned      eng_cnal_if_pio_int                       :  1;
     unsigned      cfg_ring_err_int                          :  1;
     unsigned      cfg_ring_err_pio_int                      :  1;
#else    /* Little Endian */
     unsigned      cfg_ring_err_pio_int                      :  1;
     unsigned      cfg_ring_err_int                          :  1;
     unsigned      eng_cnal_if_pio_int                       :  1;
     unsigned      eng_cnal_if_int                           :  1;
     unsigned      cfg_inst_compl_int                        :  1;
     unsigned      cmn_axi_write_int                         :  1;
     unsigned      cmn_axi_read_int                          :  1;
     unsigned      invalid_pio_start_not_done_int            :  1;
     unsigned      smon_int                                  :  1;
     unsigned      outstanding_cpcqs_counter_underflow_int   :  1;
     unsigned      outstanding_cpcqs_counter_overflow_int    :  1;
     unsigned      cpcq_fc_error                             :  1;
     unsigned      cpcq_valid_error                          :  1;
     unsigned      cpcq_command_error                        :  1;
     unsigned      pio_inst_done                             :  1;
     unsigned      eng_cnal_if_stat                          :  1;
     unsigned      write_err                                 :  1;
     unsigned      read_err                                  :  1;
     unsigned      reserved0                                 : 14;
#endif
} ncp_cmn_axi_int_reg0_status_r_t;

/*! @struct ncp_cmn_axi_int_reg0_en_r_t
 *  @brief Interrupt Enable Register
 *  @details This register enables interrupts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_int_reg0_en_r_t\n
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
 *     <td width="30%"> @param read_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> cfg read error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param write_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> cfg write error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param eng_cnal_if_stat </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> eng_cnal_if_stat Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pio_inst_done </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> A CMN instruction completed (not an error). Does not
 *        require interrupt enable to be set in PIO/cPCQ instruction
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cpcq_command_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> cpcq_command_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cpcq_valid_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> cpcq_valid_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cpcq_fc_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> cpcq_fc_error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param outstanding_cpcqs_counter_overflow_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> ALARM: The CMN's outstanding cPCQ counter overflowed.
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param outstanding_cpcqs_counter_underflow_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> ALARM: The CMN's outstanding cPCQ counter underflowed.
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param smon_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> The CMN's SMON triggered an interrupt. Read the SMON's
 *        status for more details. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param invalid_pio_start_not_done_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Software attempted to write CDR0 while a PIO instruction
 *        was still active. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_axi_read_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Received an error response for a CMN read access on
 *        either the system_0 or external_0 memory interface.
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_axi_write_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Received an error response for a CMN write access
 *        on either the system_0 or external_0 memory interface.
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_inst_compl_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> A CMN instruction completed (not an error). Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param eng_cnal_if_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Received an error response for a CMN read or write
 *        access on the system_1 memory interface. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param eng_cnal_if_pio_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Same as eng_cnal_if_int but specifically in PIO mode.
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_ring_err_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Either a config ring error or eng_cnal_if_int occurred.
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_ring_err_pio_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Same as cfg_ring_err_int but specifically in PIO mode.
 *        Enable
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_int_reg0_en_r_t
 *
 * Implemented by: 
 *      en
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 14;
     unsigned      read_err                                  :  1;
     unsigned      write_err                                 :  1;
     unsigned      eng_cnal_if_stat                          :  1;
     unsigned      pio_inst_done                             :  1;
     unsigned      cpcq_command_error                        :  1;
     unsigned      cpcq_valid_error                          :  1;
     unsigned      cpcq_fc_error                             :  1;
     unsigned      outstanding_cpcqs_counter_overflow_int    :  1;
     unsigned      outstanding_cpcqs_counter_underflow_int   :  1;
     unsigned      smon_int                                  :  1;
     unsigned      invalid_pio_start_not_done_int            :  1;
     unsigned      cmn_axi_read_int                          :  1;
     unsigned      cmn_axi_write_int                         :  1;
     unsigned      cfg_inst_compl_int                        :  1;
     unsigned      eng_cnal_if_int                           :  1;
     unsigned      eng_cnal_if_pio_int                       :  1;
     unsigned      cfg_ring_err_int                          :  1;
     unsigned      cfg_ring_err_pio_int                      :  1;
#else    /* Little Endian */
     unsigned      cfg_ring_err_pio_int                      :  1;
     unsigned      cfg_ring_err_int                          :  1;
     unsigned      eng_cnal_if_pio_int                       :  1;
     unsigned      eng_cnal_if_int                           :  1;
     unsigned      cfg_inst_compl_int                        :  1;
     unsigned      cmn_axi_write_int                         :  1;
     unsigned      cmn_axi_read_int                          :  1;
     unsigned      invalid_pio_start_not_done_int            :  1;
     unsigned      smon_int                                  :  1;
     unsigned      outstanding_cpcqs_counter_underflow_int   :  1;
     unsigned      outstanding_cpcqs_counter_overflow_int    :  1;
     unsigned      cpcq_fc_error                             :  1;
     unsigned      cpcq_valid_error                          :  1;
     unsigned      cpcq_command_error                        :  1;
     unsigned      pio_inst_done                             :  1;
     unsigned      eng_cnal_if_stat                          :  1;
     unsigned      write_err                                 :  1;
     unsigned      read_err                                  :  1;
     unsigned      reserved0                                 : 14;
#endif
} ncp_cmn_axi_int_reg0_en_r_t;

/*! @struct ncp_cmn_axi_int_reg0_force_r_t
 *  @brief Interrupt Force Register
 *  @details This address is an alias for the Interrupt Status register
		that allows normal CFG writes (as opposed to the Clear-On-Write-One
		behavior if the Interrupt Status register address is used).  This
		allows CFG to set interrupt bits for testing purposes.  Reading this
		address returns the current value of the Interrupt Status Register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_int_reg0_force_r_t\n
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
 *     <td width="30%"> @param read_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> cfg read error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param write_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> cfg write error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param eng_cnal_if_stat </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> eng_cnal_if_stat Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pio_inst_done </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> A CMN instruction completed (not an error). Does not
 *        require interrupt enable to be set in PIO/cPCQ instruction
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cpcq_command_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> cpcq_command_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cpcq_valid_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> cpcq_valid_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cpcq_fc_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> cpcq_fc_error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param outstanding_cpcqs_counter_overflow_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> ALARM: The CMN's outstanding cPCQ counter overflowed.
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param outstanding_cpcqs_counter_underflow_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> ALARM: The CMN's outstanding cPCQ counter underflowed.
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param smon_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> The CMN's SMON triggered an interrupt. Read the SMON's
 *        status for more details. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param invalid_pio_start_not_done_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Software attempted to write CDR0 while a PIO instruction
 *        was still active. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_axi_read_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Received an error response for a CMN read access on
 *        either the system_0 or external_0 memory interface.
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_axi_write_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Received an error response for a CMN write access
 *        on either the system_0 or external_0 memory interface.
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_inst_compl_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> A CMN instruction completed (not an error). Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param eng_cnal_if_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Received an error response for a CMN read or write
 *        access on the system_1 memory interface. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param eng_cnal_if_pio_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Same as eng_cnal_if_int but specifically in PIO mode.
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_ring_err_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Either a config ring error or eng_cnal_if_int occurred.
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_ring_err_pio_int </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Same as cfg_ring_err_int but specifically in PIO mode.
 *        Force
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_int_reg0_force_r_t
 *
 * Implemented by: 
 *      frc
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 14;
     unsigned      read_err                                  :  1;
     unsigned      write_err                                 :  1;
     unsigned      eng_cnal_if_stat                          :  1;
     unsigned      pio_inst_done                             :  1;
     unsigned      cpcq_command_error                        :  1;
     unsigned      cpcq_valid_error                          :  1;
     unsigned      cpcq_fc_error                             :  1;
     unsigned      outstanding_cpcqs_counter_overflow_int    :  1;
     unsigned      outstanding_cpcqs_counter_underflow_int   :  1;
     unsigned      smon_int                                  :  1;
     unsigned      invalid_pio_start_not_done_int            :  1;
     unsigned      cmn_axi_read_int                          :  1;
     unsigned      cmn_axi_write_int                         :  1;
     unsigned      cfg_inst_compl_int                        :  1;
     unsigned      eng_cnal_if_int                           :  1;
     unsigned      eng_cnal_if_pio_int                       :  1;
     unsigned      cfg_ring_err_int                          :  1;
     unsigned      cfg_ring_err_pio_int                      :  1;
#else    /* Little Endian */
     unsigned      cfg_ring_err_pio_int                      :  1;
     unsigned      cfg_ring_err_int                          :  1;
     unsigned      eng_cnal_if_pio_int                       :  1;
     unsigned      eng_cnal_if_int                           :  1;
     unsigned      cfg_inst_compl_int                        :  1;
     unsigned      cmn_axi_write_int                         :  1;
     unsigned      cmn_axi_read_int                          :  1;
     unsigned      invalid_pio_start_not_done_int            :  1;
     unsigned      smon_int                                  :  1;
     unsigned      outstanding_cpcqs_counter_underflow_int   :  1;
     unsigned      outstanding_cpcqs_counter_overflow_int    :  1;
     unsigned      cpcq_fc_error                             :  1;
     unsigned      cpcq_valid_error                          :  1;
     unsigned      cpcq_command_error                        :  1;
     unsigned      pio_inst_done                             :  1;
     unsigned      eng_cnal_if_stat                          :  1;
     unsigned      write_err                                 :  1;
     unsigned      read_err                                  :  1;
     unsigned      reserved0                                 : 14;
#endif
} ncp_cmn_axi_int_reg0_force_r_t;

/*! @struct ncp_cmn_axi_AW_smon01_cmn_smon_r_t
 *  @brief AW_smon CONTROL1 register
 *  @details This is used to configure the operation of the 2 internal counters in the SMON
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_AW_smon01_cmn_smon_r_t\n
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
 * Applies to: xlf --> ncp_cmn_axi_AW_smon01_cmn_smon_r_t
 *
 * Implemented by: 
 *      AW_SMON01_cmn_smon
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
} ncp_cmn_axi_AW_smon01_cmn_smon_r_t;

/*! @struct ncp_cmn_axi_cfg_setup_r_t
 *  @brief null
 *  @details cfg_setup reigster for CFG block
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_cmn_axi_cfg_setup_r_t\n
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
 * Applies to: xlf --> ncp_cmn_axi_cfg_setup_r_t
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
} ncp_cmn_axi_cfg_setup_r_t;

/*! @struct ncp_cmn_axi_interface_bits_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_cmn_axi_interface_bits_r_t
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
 *     <td width="20%" align="center"> 20 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param axis_nca_s_arvalid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> axis_nca_s_arvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param nca_axis_s_arready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> nca_axis_s_arready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param nca_axis_s_rvalid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> nca_axis_s_rvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param axis_nca_s_rready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> axis_nca_s_rready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param axis_nca_s_awvalid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> axis_nca_s_awvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param nca_axis_s_awready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> nca_axis_s_awready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param axis_nca_s_wvalid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> axis_nca_s_wvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param nca_axis_s_wready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> nca_axis_s_wready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param nca_axis_s_bvalid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> nca_axis_s_bvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param axis_nca_s_bready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> axis_nca_s_bready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_system_crr_valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> cmn_system_crr_valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_system_crr_ready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> cmn_system_crr_ready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_system_crd_valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> cmn_system_crd_valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_external_crr_valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> cmn_external_crr_valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_external_crr_ready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> cmn_external_crr_ready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_external_crd_valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> cmn_external_crd_valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_system_cwr_valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> cmn_system_cwr_valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_system_cwr_ready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> cmn_system_cwr_ready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_system_cwd_valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> cmn_system_cwd_valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_system_cwd_ready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> cmn_system_cwd_ready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_system_cwa_valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> cmn_system_cwa_valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_external_cwr_valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> cmn_external_cwr_valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_external_cwr_ready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> cmn_external_cwr_ready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_external_cwd_valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> cmn_external_cwd_valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_external_cwd_ready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> cmn_external_cwd_ready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_external_cwa_valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> cmn_external_cwa_valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_cpcq_req_awready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> cmn_cpcq_req_awready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_cpcq_req_awvalid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> cmn_cpcq_req_awvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_cpcq_req_wready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> cmn_cpcq_req_wready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_cpcq_req_wvalid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> cmn_cpcq_req_wvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_cpcq_req_bready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> cmn_cpcq_req_bready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_cpcq_req_bvalid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> cmn_cpcq_req_bvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_cpcq_resp_awready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> cmn_cpcq_resp_awready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_cpcq_resp_awvalid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> cmn_cpcq_resp_awvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_cpcq_resp_wready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> cmn_cpcq_resp_wready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_cpcq_resp_wvalid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> cmn_cpcq_resp_wvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_cpcq_resp_bready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> cmn_cpcq_resp_bready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmn_cpcq_resp_bvalid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> cmn_cpcq_resp_bvalid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param as_cdar_r_w </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> as_cdar_r_w </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param as_cdar_acc_val </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> as_cdar_acc_val </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cdar_as_ready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> cdar_as_ready </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param as_cdar_rdata </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> as_cdar_rdata </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param as_cdar_rdata_val </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> as_cdar_rdata_val </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param as_cdar_ready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> as_cdar_ready </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_cmn_axi_interface_bits_r_t
 *
 * Implemented by: 
 *      interface_bits
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0                                 : 20;
     unsigned      axis_nca_s_arvalid                        :  1;
     unsigned      nca_axis_s_arready                        :  1;
     unsigned      nca_axis_s_rvalid                         :  1;
     unsigned      axis_nca_s_rready                         :  1;
     unsigned      axis_nca_s_awvalid                        :  1;
     unsigned      nca_axis_s_awready                        :  1;
     unsigned      axis_nca_s_wvalid                         :  1;
     unsigned      nca_axis_s_wready                         :  1;
     unsigned      nca_axis_s_bvalid                         :  1;
     unsigned      axis_nca_s_bready                         :  1;
     unsigned      cmn_system_crr_valid                      :  1;
     unsigned      cmn_system_crr_ready                      :  1;
          /* word 1 */
     unsigned      cmn_system_crd_valid                      :  1;
     unsigned      cmn_external_crr_valid                    :  1;
     unsigned      cmn_external_crr_ready                    :  1;
     unsigned      cmn_external_crd_valid                    :  1;
     unsigned      cmn_system_cwr_valid                      :  1;
     unsigned      cmn_system_cwr_ready                      :  1;
     unsigned      cmn_system_cwd_valid                      :  1;
     unsigned      cmn_system_cwd_ready                      :  1;
     unsigned      cmn_system_cwa_valid                      :  1;
     unsigned      cmn_external_cwr_valid                    :  1;
     unsigned      cmn_external_cwr_ready                    :  1;
     unsigned      cmn_external_cwd_valid                    :  1;
     unsigned      cmn_external_cwd_ready                    :  1;
     unsigned      cmn_external_cwa_valid                    :  1;
     unsigned      cmn_cpcq_req_awready                      :  1;
     unsigned      cmn_cpcq_req_awvalid                      :  1;
     unsigned      cmn_cpcq_req_wready                       :  1;
     unsigned      cmn_cpcq_req_wvalid                       :  1;
     unsigned      cmn_cpcq_req_bready                       :  1;
     unsigned      cmn_cpcq_req_bvalid                       :  1;
     unsigned      cmn_cpcq_resp_awready                     :  1;
     unsigned      cmn_cpcq_resp_awvalid                     :  1;
     unsigned      cmn_cpcq_resp_wready                      :  1;
     unsigned      cmn_cpcq_resp_wvalid                      :  1;
     unsigned      cmn_cpcq_resp_bready                      :  1;
     unsigned      cmn_cpcq_resp_bvalid                      :  1;
     unsigned      as_cdar_r_w                               :  1;
     unsigned      as_cdar_acc_val                           :  1;
     unsigned      cdar_as_ready                             :  1;
     unsigned      as_cdar_rdata                             :  1;
     unsigned      as_cdar_rdata_val                         :  1;
     unsigned      as_cdar_ready                             :  1;
#else    /* Little Endian */
          /* word 0 */
     unsigned      cmn_system_crr_ready                      :  1;
     unsigned      cmn_system_crr_valid                      :  1;
     unsigned      axis_nca_s_bready                         :  1;
     unsigned      nca_axis_s_bvalid                         :  1;
     unsigned      nca_axis_s_wready                         :  1;
     unsigned      axis_nca_s_wvalid                         :  1;
     unsigned      nca_axis_s_awready                        :  1;
     unsigned      axis_nca_s_awvalid                        :  1;
     unsigned      axis_nca_s_rready                         :  1;
     unsigned      nca_axis_s_rvalid                         :  1;
     unsigned      nca_axis_s_arready                        :  1;
     unsigned      axis_nca_s_arvalid                        :  1;
     unsigned      reserved0                                 : 20;
          /* word 1 */
     unsigned      as_cdar_ready                             :  1;
     unsigned      as_cdar_rdata_val                         :  1;
     unsigned      as_cdar_rdata                             :  1;
     unsigned      cdar_as_ready                             :  1;
     unsigned      as_cdar_acc_val                           :  1;
     unsigned      as_cdar_r_w                               :  1;
     unsigned      cmn_cpcq_resp_bvalid                      :  1;
     unsigned      cmn_cpcq_resp_bready                      :  1;
     unsigned      cmn_cpcq_resp_wvalid                      :  1;
     unsigned      cmn_cpcq_resp_wready                      :  1;
     unsigned      cmn_cpcq_resp_awvalid                     :  1;
     unsigned      cmn_cpcq_resp_awready                     :  1;
     unsigned      cmn_cpcq_req_bvalid                       :  1;
     unsigned      cmn_cpcq_req_bready                       :  1;
     unsigned      cmn_cpcq_req_wvalid                       :  1;
     unsigned      cmn_cpcq_req_wready                       :  1;
     unsigned      cmn_cpcq_req_awvalid                      :  1;
     unsigned      cmn_cpcq_req_awready                      :  1;
     unsigned      cmn_external_cwa_valid                    :  1;
     unsigned      cmn_external_cwd_ready                    :  1;
     unsigned      cmn_external_cwd_valid                    :  1;
     unsigned      cmn_external_cwr_ready                    :  1;
     unsigned      cmn_external_cwr_valid                    :  1;
     unsigned      cmn_system_cwa_valid                      :  1;
     unsigned      cmn_system_cwd_ready                      :  1;
     unsigned      cmn_system_cwd_valid                      :  1;
     unsigned      cmn_system_cwr_ready                      :  1;
     unsigned      cmn_system_cwr_valid                      :  1;
     unsigned      cmn_external_crd_valid                    :  1;
     unsigned      cmn_external_crr_ready                    :  1;
     unsigned      cmn_external_crr_valid                    :  1;
     unsigned      cmn_system_crd_valid                      :  1;
#endif
} ncp_cmn_axi_interface_bits_r_t;

#ifdef __cplusplus
}
#endif

#endif /* _NCP_CMN_AXI_REGS_H_ */
