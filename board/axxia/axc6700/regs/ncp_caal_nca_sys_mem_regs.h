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


#ifndef _NCP_CAAL_NCA_SYS_MEM_REGS_H_
#define _NCP_CAAL_NCA_SYS_MEM_REGS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"

/*! @struct ncp_caal_nca_sys_mem_control_r_t
 *  @brief CAAL Control Register
 *  @details This register contains fields that control the CAAL arbitration and error checking.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_control_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param reserved_1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> Reserved. Formerly disable invalidate. Because of
 *        a hw issue, block invalidate will now have to be disabled
 *        from its source which is the mcip.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param disable_cla_table </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> Disable CLA table. Disable write request and CLA table
 *        address comparison. Write request with overlapping
 *        address will not use same ID to enforce ordering.
 *        Normal usage is 0
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved_0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> Reserved. Formerly disable padded write. No longer
 *        needed. Clearing the pad bit in ACELITE write control
 *        register instead
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param disable_16b_aligned_check </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Disable 16 byte aligned check. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param disable_clk_gating </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Disable clock gating. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_addr_check </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> Read address range check enable. The ACE-Lite read
 *        address range check passes if the addess setup in
 *        the Minimum ACE-Lite Read Address Register <= ACE-Lite
 *        read address [msb:8] <= the address setup in the Maximum
 *        ACE-Lite Read Address register. If the crr_addr_exc
 *        bit is set, the sense of this check is inverted
 *        (ACE-Lite address [msb:8] must be < Minimum Read Address
 *        or > Maxmum Read Address).
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_addr_exc </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Read address range is exclusive versus inclusive </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_addr_resp </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Read address range error response type (0:ignore,
 *        1:discard, 2:halt RFSM)
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_addr_check </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Write address range check enable. The ACE-Lite write
 *        address range check passes if the addess setup in
 *        the Minimum ACE-Lite Write Address Register <=
 *        ACE-Lite write address [msb:8] <= the address setup
 *        in the Maximum ACE-Lite Write Address register.
 *        If the cwr_addr_exc bit is set, the sense of this
 *        check is inverted (ACE-Lite write address [msb:8]
 *        must be < Minimum Write Address or > Maxmum Write
 *        Address).
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_addr_exc </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Write address range is exclusive versus inclusive </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_addr_resp </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Write address range error response type (0:ignore,
 *        1:discard, 2:halt WFSM)
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param caal_reserved </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Reserved 0. This bit can be used to distinguish between
 *        cnal and caal
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param vat_ecc_check </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> VAT ECC check enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param vat_ecc_correct </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> VAT ECC single bit error correct enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> CRR arbitration mode. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_arb_mode </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> CWR arbitration mode. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_control_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved_1                                :  1;
     unsigned      disable_cla_table                         :  1;
     unsigned      reserved_0                                :  1;
     unsigned      disable_16b_aligned_check                 :  1;
     unsigned      disable_clk_gating                        :  1;
     unsigned      reserved0                                 :  9;
     unsigned      crr_addr_check                            :  1;
     unsigned      crr_addr_exc                              :  1;
     unsigned      crr_addr_resp                             :  2;
     unsigned      cwr_addr_check                            :  1;
     unsigned      cwr_addr_exc                              :  1;
     unsigned      cwr_addr_resp                             :  2;
     unsigned      reserved1                                 :  3;
     unsigned      caal_reserved                             :  1;
     unsigned      vat_ecc_check                             :  1;
     unsigned      vat_ecc_correct                           :  1;
     unsigned      crr_arb_mode                              :  2;
     unsigned      cwr_arb_mode                              :  2;
#else    /* Little Endian */
     unsigned      cwr_arb_mode                              :  2;
     unsigned      crr_arb_mode                              :  2;
     unsigned      vat_ecc_correct                           :  1;
     unsigned      vat_ecc_check                             :  1;
     unsigned      caal_reserved                             :  1;
     unsigned      reserved1                                 :  3;
     unsigned      cwr_addr_resp                             :  2;
     unsigned      cwr_addr_exc                              :  1;
     unsigned      cwr_addr_check                            :  1;
     unsigned      crr_addr_resp                             :  2;
     unsigned      crr_addr_exc                              :  1;
     unsigned      crr_addr_check                            :  1;
     unsigned      reserved0                                 :  9;
     unsigned      disable_clk_gating                        :  1;
     unsigned      disable_16b_aligned_check                 :  1;
     unsigned      reserved_0                                :  1;
     unsigned      disable_cla_table                         :  1;
     unsigned      reserved_1                                :  1;
#endif
} ncp_caal_nca_sys_mem_control_r_t;

/*! @struct ncp_caal_nca_sys_mem_ort_limit_r_t
 *  @brief CAAL Maximum Outstanding Read Transaction Limit Register
 *  @details This register contains values that limit the maximum number of outstanding ACE-Lite read transactions the CAAL can
	have at one time.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_ort_limit_r_t\n
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
 *     <td width="30%"> @param ort_limit </td>
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Maximum number of outstanding ACE-Lite read requests. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_ort_limit_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 25;
     unsigned      ort_limit                                 :  7;
#else    /* Little Endian */
     unsigned      ort_limit                                 :  7;
     unsigned      reserved0                                 : 25;
#endif
} ncp_caal_nca_sys_mem_ort_limit_r_t;

/*! @struct ncp_caal_nca_sys_mem_owt_limit_r_t
 *  @brief CAAL Maximum Outstanding Write Transaction Limit Register
 *  @details This register contains values that limit the maximum number of outstanding ACE-Lite write transactions the CAAL can
	have at one time.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_owt_limit_r_t\n
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
 *     <td width="30%"> @param owt_limit </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Maximum number of total outstanding ACE-Lite write
 *        requests.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_owt_limit_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 27;
     unsigned      owt_limit                                 :  5;
#else    /* Little Endian */
     unsigned      owt_limit                                 :  5;
     unsigned      reserved0                                 : 27;
#endif
} ncp_caal_nca_sys_mem_owt_limit_r_t;

/*! @struct ncp_caal_nca_sys_mem_addr_chk_enb_r_t
 *  @brief CAAL Address Check Enable
 *  @details This register contains a bit per read or write requestor interface that enables the address checks for that interface.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_addr_chk_enb_r_t\n
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
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_addr_chk_enb </td>
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Enable read address checks per requestor interface. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_addr_chk_enb </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Enable write address checks per requestor interface. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_addr_chk_enb_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  9;
     unsigned      crr_addr_chk_enb                          :  7;
     unsigned      reserved1                                 : 11;
     unsigned      cwr_addr_chk_enb                          :  5;
#else    /* Little Endian */
     unsigned      cwr_addr_chk_enb                          :  5;
     unsigned      reserved1                                 : 11;
     unsigned      crr_addr_chk_enb                          :  7;
     unsigned      reserved0                                 :  9;
#endif
} ncp_caal_nca_sys_mem_addr_chk_enb_r_t;

/*! @struct ncp_caal_nca_sys_mem_counter_ctl_r_t
 *  @brief CAAL Counter Control Register
 *  @details This register contains the fields that control the clock counter and the four general purpose counters.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_counter_ctl_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param avg_lat_binary_transaction_cnt </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Average latency binary transaction count. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param clk_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Clock counter overflowed. Cleared on leading edge
 *        of cnt_enable.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt3_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> General purpose counter 3 overflowed. Cleared on leading
 *        edge of cnt_enable.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt2_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> General purpose counter 2 overflowed. Cleared on leading
 *        edge of cnt_enable.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt1_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> General purpose counter 1 overflowed. Cleared on leading
 *        edge of cnt_enable.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt0_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> General purpose counter 0 overflowed. Cleared on leading
 *        edge of cnt_enable.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_lat_enable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> If set, the counters are in ACE-Lite latency mode,
 *        with cnt_wlat specifying if write versus read latency
 *        is being counted,  and none of the other control
 *        fields are valid. When in latency mode, counter0 contains
 *        the minimum latency seen,  counter1 contains the
 *        maximum latency seen, counter2 contains the total
 *        latency seen, and counter3 contains the number 
 *        of transactions seen for all ACE-Lite transactions
 *        with ID 0.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_wlat </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> If set along with the cnt_lat_enable bit, the ACE-Lite
 *        write latency is being counted instead of the ACE-Lite
 *        read latency.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_rid_enable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> If set, the CMSI requestor ID must match the value
 *        in the Counter ID register for CMSI events to be counted.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_eid_enable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> If set, the CMSI engine ID must match the value in
 *        the Counter ID register for CMSI events to be counted.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved2 </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_scale </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Number of system clocks that cause a clock counter
 *        increment (0: 1, 1: 256, 2: 8K, 3: 64K).
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_halt </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> If set, halt all counters when any counter overflows
 *        (>2**32-1). Note that the overflow indication for
 *        each counter  is available as the *_overflow bits
 *        in this register
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_enable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Enable all counters (1: run, 0: stop). </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_counter_ctl_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      avg_lat_binary_transaction_cnt            :  4;
     unsigned      reserved0                                 :  7;
     unsigned      clk_overflow                              :  1;
     unsigned      cnt3_overflow                             :  1;
     unsigned      cnt2_overflow                             :  1;
     unsigned      cnt1_overflow                             :  1;
     unsigned      cnt0_overflow                             :  1;
     unsigned      reserved1                                 :  3;
     unsigned      cnt_lat_enable                            :  1;
     unsigned      cnt_wlat                                  :  1;
     unsigned      cnt_rid_enable                            :  1;
     unsigned      cnt_eid_enable                            :  1;
     unsigned      reserved2                                 :  5;
     unsigned      cnt_scale                                 :  2;
     unsigned      cnt_halt                                  :  1;
     unsigned      cnt_enable                                :  1;
#else    /* Little Endian */
     unsigned      cnt_enable                                :  1;
     unsigned      cnt_halt                                  :  1;
     unsigned      cnt_scale                                 :  2;
     unsigned      reserved2                                 :  5;
     unsigned      cnt_eid_enable                            :  1;
     unsigned      cnt_rid_enable                            :  1;
     unsigned      cnt_wlat                                  :  1;
     unsigned      cnt_lat_enable                            :  1;
     unsigned      reserved1                                 :  3;
     unsigned      cnt0_overflow                             :  1;
     unsigned      cnt1_overflow                             :  1;
     unsigned      cnt2_overflow                             :  1;
     unsigned      cnt3_overflow                             :  1;
     unsigned      clk_overflow                              :  1;
     unsigned      reserved0                                 :  7;
     unsigned      avg_lat_binary_transaction_cnt            :  4;
#endif
} ncp_caal_nca_sys_mem_counter_ctl_r_t;

/*! @struct ncp_caal_nca_sys_mem_counter_sel_r_t
 *  @brief CAAL Counter Select Register
 *  @details This register contains the fields that control what events are counted by the general purpose counters.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_counter_sel_r_t\n
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
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt3_sel </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> General purpose counter 3 increment select. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt2_sel </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> General purpose counter 2 increment select. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved2 </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt1_sel </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> General purpose counter 1 increment select. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved3 </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt0_sel </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> General purpose counter 0 increment select. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_counter_sel_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  2;
     unsigned      cnt3_sel                                  :  6;
     unsigned      reserved1                                 :  2;
     unsigned      cnt2_sel                                  :  6;
     unsigned      reserved2                                 :  2;
     unsigned      cnt1_sel                                  :  6;
     unsigned      reserved3                                 :  2;
     unsigned      cnt0_sel                                  :  6;
#else    /* Little Endian */
     unsigned      cnt0_sel                                  :  6;
     unsigned      reserved3                                 :  2;
     unsigned      cnt1_sel                                  :  6;
     unsigned      reserved2                                 :  2;
     unsigned      cnt2_sel                                  :  6;
     unsigned      reserved1                                 :  2;
     unsigned      cnt3_sel                                  :  6;
     unsigned      reserved0                                 :  2;
#endif
} ncp_caal_nca_sys_mem_counter_sel_r_t;

/*! @struct ncp_caal_nca_sys_mem_counter_id_r_t
 *  @brief CAAL Counter ID Register
 *  @details This register contains the ID fields to compare when counting events from a particular requestor and/or engine.
       Note: there is a hw logic issue as reported in bugz 42767 which affect the definition of this register read return data.
       When reading this register
       cnt[31:20] is cnt_reid (this is a scaled field. Actual width of the counter is specified by REID_WIDTH)
       cnt[19:16] is cnt_rrid (this is a scaled field. Actual width of the counter is specified by RRID_WIDTH)
       cnt[15: 4] is cnt_weid (this is a scaled field. Actual width of the counter is specified by WEID_WIDTH)
       cnt[ 3: 0] is cnt_wrid (this is a scaled field. Actual width of the counter is specified by WRID_WIDTH)
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_counter_id_r_t\n
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
 *     <td width="30%"> @param cnt_wrid </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> The requestor ID value to use in comparisons for CMSI
 *        write events when cnt_rid_enable is set in the Counter
 *        Control register.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_weid </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> The engine ID value to use in comparisons for CMSI
 *        write events when cnt_eid_enable is set in the Counter
 *        Control register.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved2 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_rrid </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> The requestor ID value to use in comparisons for CMSI
 *        read events when cnt_rid_enable is set in the Counter
 *        Control register.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved3 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_reid </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> The engine ID value to use in comparisons for CMSI
 *        read events when cnt_eid_enable is set in the Counter
 *        Control register.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_counter_id_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  1;
     unsigned      cnt_wrid                                  :  3;
     unsigned      reserved1                                 : 10;
     unsigned      cnt_weid                                  :  2;
     unsigned      reserved2                                 :  1;
     unsigned      cnt_rrid                                  :  3;
     unsigned      reserved3                                 : 10;
     unsigned      cnt_reid                                  :  2;
#else    /* Little Endian */
     unsigned      cnt_reid                                  :  2;
     unsigned      reserved3                                 : 10;
     unsigned      cnt_rrid                                  :  3;
     unsigned      reserved2                                 :  1;
     unsigned      cnt_weid                                  :  2;
     unsigned      reserved1                                 : 10;
     unsigned      cnt_wrid                                  :  3;
     unsigned      reserved0                                 :  1;
#endif
} ncp_caal_nca_sys_mem_counter_id_r_t;

/*! @struct ncp_caal_nca_sys_mem_tort_cnt_r_t
 *  @brief CAAL Total Outstanding ACE-Lite Read Transaction Count
 *  @details This register contains the total number of currently outstanding ACE-Lite read transactions.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_tort_cnt_r_t\n
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
 *     <td width="30%"> @param tort </td>
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Total outstanding ACE-Lite read transactions. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_tort_cnt_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 25;
     unsigned      tort                                      :  7;
#else    /* Little Endian */
     unsigned      tort                                      :  7;
     unsigned      reserved0                                 : 25;
#endif
} ncp_caal_nca_sys_mem_tort_cnt_r_t;

/*! @struct ncp_caal_nca_sys_mem_towt_cnt_r_t
 *  @brief CAAL Total Outstanding ACE-Lite Write Transaction Count
 *  @details This register contains the total number of currently outstanding ACE-Lite write transactions.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_towt_cnt_r_t\n
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
 *     <td width="30%"> @param towt </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Total outstanding ACE-Lite write transactions. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_towt_cnt_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 27;
     unsigned      towt                                      :  5;
#else    /* Little Endian */
     unsigned      towt                                      :  5;
     unsigned      reserved0                                 : 27;
#endif
} ncp_caal_nca_sys_mem_towt_cnt_r_t;

/*! @struct ncp_caal_nca_sys_mem_crr_wrr_weight_r_t
 *  @brief CAAL CMSI Read Requestor WRR Weight Register
 *  @details This register contains the WRR arbitration weight value for a CMSI Read Requestor. The index identifies the requestor.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_crr_wrr_weight_r_t\n
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
 *     <td width="30%"> @param weight </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> WRR weight value. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_crr_wrr_weight_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 31;
     unsigned      weight                                    :  1;
#else    /* Little Endian */
     unsigned      weight                                    :  1;
     unsigned      reserved0                                 : 31;
#endif
} ncp_caal_nca_sys_mem_crr_wrr_weight_r_t;

/*! @struct ncp_caal_nca_sys_mem_cwr_wrr_weight_r_t
 *  @brief CAAL CMSI Write Requestor WRR Weight Register
 *  @details This register contains the WRR arbitration weight value for a CMSI Write Requestor. The index identifies the requestor.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_cwr_wrr_weight_r_t\n
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
 *     <td width="30%"> @param weight </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> WRR weight value. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_cwr_wrr_weight_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 31;
     unsigned      weight                                    :  1;
#else    /* Little Endian */
     unsigned      weight                                    :  1;
     unsigned      reserved0                                 : 31;
#endif
} ncp_caal_nca_sys_mem_cwr_wrr_weight_r_t;

/*! @struct ncp_caal_nca_sys_mem_crr_syndrome0_r_t
 *  @brief CAAL CMSI Read Request Syndrome Register 0
 *  @details This register contains the sticky control fields associated with the first occurrence of a CMSI
	read request error (VAT ECC error, VAT invalid error, VAT bounds error, CMSI engine ID error, CMSI address range
	check error, or CMSI maximum bytes error).
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_crr_syndrome0_r_t\n
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
 *     <td width="30%"> @param crr_rid </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Requestor ID for the first CMSI read request error. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_eid </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Engine ID for the first CMSI read request error. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved2 </td>
 *     <td width="20%" align="center"> 12 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_jid </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Job ID for the first CMSI read request error. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_crr_syndrome0_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  1;
     unsigned      crr_rid                                   :  3;
     unsigned      reserved1                                 : 10;
     unsigned      crr_eid                                   :  2;
     unsigned      reserved2                                 : 12;
     unsigned      crr_jid                                   :  4;
#else    /* Little Endian */
     unsigned      crr_jid                                   :  4;
     unsigned      reserved2                                 : 12;
     unsigned      crr_eid                                   :  2;
     unsigned      reserved1                                 : 10;
     unsigned      crr_rid                                   :  3;
     unsigned      reserved0                                 :  1;
#endif
} ncp_caal_nca_sys_mem_crr_syndrome0_r_t;

/*! @struct ncp_caal_nca_sys_mem_crr_syndrome1_r_t
 *  @brief CAAL CMSI Read Request Syndrome Register 1
 *  @details This register contains the sticky control fields associated with the first occurrence of a CMSI
	read request error (VAT ECC error, VAT invalid error, VAT bounds error, CMSI engine ID error, CMSI address range
	check error, or CMSI maximum bytes error).
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_crr_syndrome1_r_t\n
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
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_wrap </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> Wrap indication for the first CMSI read request error. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_ttype </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Transaction type for the first CMSI read request error. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_priority </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Priority for the first CMSI read request error. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_pool </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Pool for the first CMSI read request error. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_bytes </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Bytes for the first CMSI read request error. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_crr_syndrome1_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  2;
     unsigned      crr_wrap                                  :  1;
     unsigned      crr_ttype                                 :  6;
     unsigned      crr_priority                              :  1;
     unsigned      reserved1                                 :  1;
     unsigned      crr_pool                                  :  5;
     unsigned      crr_bytes                                 : 16;
#else    /* Little Endian */
     unsigned      crr_bytes                                 : 16;
     unsigned      crr_pool                                  :  5;
     unsigned      reserved1                                 :  1;
     unsigned      crr_priority                              :  1;
     unsigned      crr_ttype                                 :  6;
     unsigned      crr_wrap                                  :  1;
     unsigned      reserved0                                 :  2;
#endif
} ncp_caal_nca_sys_mem_crr_syndrome1_r_t;

/*! @struct ncp_caal_nca_sys_mem_crr_syndrome2_r_t
 *  @brief CAAL CMSI Read Request Syndrome Register 2
 *  @details This register contains the sticky control fields associated with the first occurrence of a CMSI
	read request error (VAT ECC error, VAT invalid error, VAT bounds error, CMSI engine ID error, CMSI address range
	check error, or CMSI maximum bytes error).
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_crr_syndrome2_r_t\n
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
 *     <td width="30%"> @param crr_vaddr_ms </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> MS bits of the virtual address for the first CMSI
 *        read request error.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_crr_syndrome2_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 28;
     unsigned      crr_vaddr_ms                              :  4;
#else    /* Little Endian */
     unsigned      crr_vaddr_ms                              :  4;
     unsigned      reserved0                                 : 28;
#endif
} ncp_caal_nca_sys_mem_crr_syndrome2_r_t;

/*! @struct ncp_caal_nca_sys_mem_crr_syndrome3_r_t
 *  @brief CAAL CMSI Read Request Syndrome Register 3
 *  @details This register contains the sticky control fields associated with the first occurrence of a CMSI
	read request error (VAT ECC error, VAT invalid error, VAT bounds error, CMSI engine ID error, CMSI address range
	check error, or CMSI maximum bytes error).
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_crr_syndrome3_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param crr_vaddr_ls </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> LS bits of the virtual address for the first CMSI
 *        read request error.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_crr_syndrome3_r_t
 *
 */
 
typedef struct
{
     unsigned  int              crr_vaddr_ls;
} ncp_caal_nca_sys_mem_crr_syndrome3_r_t;

/*! @struct ncp_caal_nca_sys_mem_crr_syndrome4_r_t
 *  @brief CAAL CMSI Read Request Syndrome Register 4
 *  @details This register contains the sticky control fields associated with the first occurrence of a CMSI
	read request error (VAT ECC error, VAT invalid error, VAT bounds error, CMSI engine ID error, CMSI address range
	check error, or CMSI maximum bytes error).
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_crr_syndrome4_r_t\n
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
 *     <td width="30%"> @param crr_addr_ms </td>
 *     <td width="20%" align="center"> 12 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> MS bits of the physical address for the first CMSI
 *        read request error.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_crr_syndrome4_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 20;
     unsigned      crr_addr_ms                               : 12;
#else    /* Little Endian */
     unsigned      crr_addr_ms                               : 12;
     unsigned      reserved0                                 : 20;
#endif
} ncp_caal_nca_sys_mem_crr_syndrome4_r_t;

/*! @struct ncp_caal_nca_sys_mem_crr_syndrome5_r_t
 *  @brief CAAL CMSI Read Request Syndrome Register 5
 *  @details This register contains the sticky control fields associated with the first occurrence of a CMSI
	read request error (VAT ECC error, VAT invalid error, VAT bounds error, CMSI engine ID error, CMSI address range
	check error, or CMSI maximum bytes error).
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_crr_syndrome5_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param crr_addr_ls </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> LS bits of the physical address for the first CMSI
 *        read request error.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_crr_syndrome5_r_t
 *
 */
 
typedef struct
{
     unsigned  int               crr_addr_ls;
} ncp_caal_nca_sys_mem_crr_syndrome5_r_t;

/*! @struct ncp_caal_nca_sys_mem_cwr_syndrome0_r_t
 *  @brief CAAL CMSI Write Request Syndrome Register
 *  @details This register contains the sticky control fields associated with the first occurrence of a CMSI
	write request error (VAT ECC error, VAT invalid error, VAT bounds error, CMSI engine ID error, CMSI address range
	check error, CMSI maximum bytes error, ID mismatch error, or data length error).
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_cwr_syndrome0_r_t\n
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
 *     <td width="30%"> @param cwr_rid </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Requestor ID for the first CMSI write request error. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_eid </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Engine ID for the first CMSI write request error. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved2 </td>
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_jid </td>
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Job ID for the first CMSI write request error. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_cwr_syndrome0_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  1;
     unsigned      cwr_rid                                   :  3;
     unsigned      reserved1                                 : 10;
     unsigned      cwr_eid                                   :  2;
     unsigned      reserved2                                 :  9;
     unsigned      cwr_jid                                   :  7;
#else    /* Little Endian */
     unsigned      cwr_jid                                   :  7;
     unsigned      reserved2                                 :  9;
     unsigned      cwr_eid                                   :  2;
     unsigned      reserved1                                 : 10;
     unsigned      cwr_rid                                   :  3;
     unsigned      reserved0                                 :  1;
#endif
} ncp_caal_nca_sys_mem_cwr_syndrome0_r_t;

/*! @struct ncp_caal_nca_sys_mem_cwr_syndrome1_r_t
 *  @brief CAAL CMSI Write Request Syndrome Register 1
 *  @details This register contains the sticky control fields associated with the first occurrence of a CMSI
	write request error (VAT ECC error, VAT invalid error, VAT bounds error, CMSI engine ID error, CMSI address range
	check error, CMSI maximum bytes error, ID mismatch error, or data length error).
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_cwr_syndrome1_r_t\n
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
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_soj </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> Start of job indication for the first CMSI write request
 *        error.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_eoj </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> End of job indication for the first CMSI write request
 *        error.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_ttype </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Transaction type for the first CMSI write request
 *        error.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_priority </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Priority for the first CMSI write request error. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_pool </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Pool for the first CMSI write request error. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_bytes </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Bytes for the first CMSI write request error. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_cwr_syndrome1_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  2;
     unsigned      cwr_soj                                   :  1;
     unsigned      cwr_eoj                                   :  1;
     unsigned      cwr_ttype                                 :  5;
     unsigned      cwr_priority                              :  1;
     unsigned      reserved1                                 :  1;
     unsigned      cwr_pool                                  :  5;
     unsigned      cwr_bytes                                 : 16;
#else    /* Little Endian */
     unsigned      cwr_bytes                                 : 16;
     unsigned      cwr_pool                                  :  5;
     unsigned      reserved1                                 :  1;
     unsigned      cwr_priority                              :  1;
     unsigned      cwr_ttype                                 :  5;
     unsigned      cwr_eoj                                   :  1;
     unsigned      cwr_soj                                   :  1;
     unsigned      reserved0                                 :  2;
#endif
} ncp_caal_nca_sys_mem_cwr_syndrome1_r_t;

/*! @struct ncp_caal_nca_sys_mem_cwr_syndrome2_r_t
 *  @brief CAAL CMSI Write Request Syndrome Register 2
 *  @details This register contains the sticky control fields associated with the first occurrence of a CMSI
	write request error (VAT ECC error, VAT invalid error, VAT bounds error, CMSI engine ID error, CMSI address range
	check error, CMSI maximum bytes error, ID mismatch error, or data length error).
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_cwr_syndrome2_r_t\n
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
 *     <td width="30%"> @param cwr_vaddr_ms </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> MS bits of the virtual address for the first CMSI
 *        write request error.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_cwr_syndrome2_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 28;
     unsigned      cwr_vaddr_ms                              :  4;
#else    /* Little Endian */
     unsigned      cwr_vaddr_ms                              :  4;
     unsigned      reserved0                                 : 28;
#endif
} ncp_caal_nca_sys_mem_cwr_syndrome2_r_t;

/*! @struct ncp_caal_nca_sys_mem_cwr_syndrome3_r_t
 *  @brief CAAL CMSI Write Request Syndrome Register 3
 *  @details This register contains the sticky control fields associated with the first occurrence of a CMSI
	write request error (VAT ECC error, VAT invalid error, VAT bounds error, CMSI engine ID error, CMSI address range
	check error, CMSI maximum bytes error, ID mismatch error, or data length error).
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_cwr_syndrome3_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_vaddr_ls </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> LS bits of the virtual address for the first CMSI
 *        write request error.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_cwr_syndrome3_r_t
 *
 */
 
typedef struct
{
     unsigned  int              cwr_vaddr_ls;
} ncp_caal_nca_sys_mem_cwr_syndrome3_r_t;

/*! @struct ncp_caal_nca_sys_mem_cwr_syndrome4_r_t
 *  @brief CAAL CMSI Write Request Syndrome Register 4
 *  @details This register contains the sticky control fields associated with the first occurrence of a CMSI
	write request error (VAT ECC error, VAT invalid error, VAT bounds error, CMSI engine ID error, CMSI address range
	check error, CMSI maximum bytes error, ID mismatch error, or data length error).
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_cwr_syndrome4_r_t\n
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
 *     <td width="30%"> @param cwr_addr_ms </td>
 *     <td width="20%" align="center"> 12 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> MS bits of the physical address for the first CMSI
 *        write request error.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_cwr_syndrome4_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 20;
     unsigned      cwr_addr_ms                               : 12;
#else    /* Little Endian */
     unsigned      cwr_addr_ms                               : 12;
     unsigned      reserved0                                 : 20;
#endif
} ncp_caal_nca_sys_mem_cwr_syndrome4_r_t;

/*! @struct ncp_caal_nca_sys_mem_cwr_syndrome5_r_t
 *  @brief CAAL CMSI Write Request Syndrome Register 5
 *  @details This register contains the sticky control fields associated with the first occurrence of a CMSI
	write request error (VAT ECC error, VAT invalid error, VAT bounds error, CMSI engine ID error, CMSI address range
	check error, CMSI maximum bytes error, ID mismatch error, or data length error).
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_cwr_syndrome5_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_addr_ls </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> LS bits of the physical address for the first CMSI
 *        write request error.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_cwr_syndrome5_r_t
 *
 */
 
typedef struct
{
     unsigned  int               cwr_addr_ls;
} ncp_caal_nca_sys_mem_cwr_syndrome5_r_t;

/*! @struct ncp_caal_nca_sys_mem_cwd_syndrome_r_t
 *  @brief CAAL CMSI Write Data Syndrome Register
 *  @details This register contains the sticky requestor, engine and job ID fields associated with the first occurrence of a CMSI
	write data error (ID mismatch error or data length error).
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_cwd_syndrome_r_t\n
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
 *     <td width="30%"> @param cwd_rid </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Requestor ID for the first CMSI write data error. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwd_eid </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Engine ID for the first CMSI write data error. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved2 </td>
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwd_jid </td>
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Job ID for the first CMSI write data error. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_cwd_syndrome_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  1;
     unsigned      cwd_rid                                   :  3;
     unsigned      reserved1                                 : 10;
     unsigned      cwd_eid                                   :  2;
     unsigned      reserved2                                 :  9;
     unsigned      cwd_jid                                   :  7;
#else    /* Little Endian */
     unsigned      cwd_jid                                   :  7;
     unsigned      reserved2                                 :  9;
     unsigned      cwd_eid                                   :  2;
     unsigned      reserved1                                 : 10;
     unsigned      cwd_rid                                   :  3;
     unsigned      reserved0                                 :  1;
#endif
} ncp_caal_nca_sys_mem_cwd_syndrome_r_t;

/*! @struct ncp_caal_nca_sys_mem_r_syndrome_r_t
 *  @brief CAAL ACE-Lite Read Response Syndrome Register
 *  @details This register contains the sticky CMSI requestor, engine and job ID fields associated with the first occurrence of
	an ACE-Lite read or block invalidate response slave or decode error.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_r_syndrome_r_t\n
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
 *     <td width="30%"> @param rid </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> CMSI requestor ID for the first ACE-Lite read response
 *        error.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param eid </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> CMSI engine ID for the first ACE-Lite read response
 *        error.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved2 </td>
 *     <td width="20%" align="center"> 12 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param jid </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> CMSI job ID for the first ACE-Lite read response error. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_r_syndrome_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  1;
     unsigned      rid                                       :  3;
     unsigned      reserved1                                 : 10;
     unsigned      eid                                       :  2;
     unsigned      reserved2                                 : 12;
     unsigned      jid                                       :  4;
#else    /* Little Endian */
     unsigned      jid                                       :  4;
     unsigned      reserved2                                 : 12;
     unsigned      eid                                       :  2;
     unsigned      reserved1                                 : 10;
     unsigned      rid                                       :  3;
     unsigned      reserved0                                 :  1;
#endif
} ncp_caal_nca_sys_mem_r_syndrome_r_t;

/*! @struct ncp_caal_nca_sys_mem_b_syndrome_r_t
 *  @brief CAAL ACE-Lite Write Response Syndrome Register
 *  @details This register contains the sticky CMSI requestor, engine and job ID fields associated with the first occurrence of
	an ACE-Lite write response slave or decode error.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_b_syndrome_r_t\n
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
 *     <td width="30%"> @param rid </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> CMSI requestor ID for the first ACE-Lite write response
 *        error.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param eid </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> CMSI engine ID for the first ACE-Lite write response
 *        error.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved2 </td>
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param jid </td>
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> CMSI job ID for the first ACE-Lite write response
 *        error.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_b_syndrome_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  1;
     unsigned      rid                                       :  3;
     unsigned      reserved1                                 : 10;
     unsigned      eid                                       :  2;
     unsigned      reserved2                                 :  9;
     unsigned      jid                                       :  7;
#else    /* Little Endian */
     unsigned      jid                                       :  7;
     unsigned      reserved2                                 :  9;
     unsigned      eid                                       :  2;
     unsigned      reserved1                                 : 10;
     unsigned      rid                                       :  3;
     unsigned      reserved0                                 :  1;
#endif
} ncp_caal_nca_sys_mem_b_syndrome_r_t;

/*! @struct ncp_caal_nca_sys_mem_wecc_r_t
 *  @brief VAT Write ECC
 *  @details This register will be used as the ECC for the next VAT table write instead of the generated ECC if the write
	address is in the raw address range for the VAT table instead of the normal address range.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_wecc_r_t\n
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
 *     <td width="30%"> @param vat_wecc </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ECC from next raw VAT write </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_wecc_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 24;
     unsigned      vat_wecc                                  :  8;
#else    /* Little Endian */
     unsigned      vat_wecc                                  :  8;
     unsigned      reserved0                                 : 24;
#endif
} ncp_caal_nca_sys_mem_wecc_r_t;

/*! @struct ncp_caal_nca_sys_mem_crr_req_status_r_t
 *  @brief CAAL CMSI Read Request Status Register
 *  @details This register contains read-only status for the CMSI read requestors.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_crr_req_status_r_t\n
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
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_ready </td>
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> A bit per requestor indicating the current value of
 *        the crr_ready signal for that requestor.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_valid </td>
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> A bit per requestor indicating which requestors currently
 *        have at least one valid read request.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_crr_req_status_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  9;
     unsigned      crr_ready                                 :  7;
     unsigned      reserved1                                 :  9;
     unsigned      crr_valid                                 :  7;
#else    /* Little Endian */
     unsigned      crr_valid                                 :  7;
     unsigned      reserved1                                 :  9;
     unsigned      crr_ready                                 :  7;
     unsigned      reserved0                                 :  9;
#endif
} ncp_caal_nca_sys_mem_crr_req_status_r_t;

/*! @struct ncp_caal_nca_sys_mem_cwr_req_status_r_t
 *  @brief CAAL CMSI Write Request Status Register
 *  @details This register contains read-only status for the CMSI write requestors.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_cwr_req_status_r_t\n
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
 *     <td width="20%" align="center"> 11 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_ready </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> A bit per requestor indicating the current value of
 *        the cwr_ready signal for that requestor.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_valid </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> A bit per requestor indicating which requestors currently
 *        have at least one valid write request.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_cwr_req_status_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 11;
     unsigned      cwr_ready                                 :  5;
     unsigned      reserved1                                 : 11;
     unsigned      cwr_valid                                 :  5;
#else    /* Little Endian */
     unsigned      cwr_valid                                 :  5;
     unsigned      reserved1                                 : 11;
     unsigned      cwr_ready                                 :  5;
     unsigned      reserved0                                 : 11;
#endif
} ncp_caal_nca_sys_mem_cwr_req_status_r_t;

/*! @struct ncp_caal_nca_sys_mem_cwd_req_status_r_t
 *  @brief CAAL CMSI Write Data Status Register
 *  @details This register contains read-only status for the CMSI write data requestors.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_cwd_req_status_r_t\n
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
 *     <td width="20%" align="center"> 11 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwd_ready </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> A bit per requestor indicating the current value of
 *        the cwd_ready signal for that requestor.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwd_valid </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> A bit per requestor indicating which requestors currently
 *        have at least one valid write data request.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_cwd_req_status_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 11;
     unsigned      cwd_ready                                 :  5;
     unsigned      reserved1                                 : 11;
     unsigned      cwd_valid                                 :  5;
#else    /* Little Endian */
     unsigned      cwd_valid                                 :  5;
     unsigned      reserved1                                 : 11;
     unsigned      cwd_ready                                 :  5;
     unsigned      reserved0                                 : 11;
#endif
} ncp_caal_nca_sys_mem_cwd_req_status_r_t;

/*! @struct ncp_caal_nca_sys_mem_ar_channel_status_r_t
 *  @brief CAAL ACE-Lite Read Request Channel Status Register
 *  @details This register contains read-only status for the ACE-Lite read request channel.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_ar_channel_status_r_t\n
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
 *     <td width="30%"> @param rfsm_state </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> The current state of the RFSM state machine. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The current status of the arready bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ardepth </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> The current number of ACE-Lite read requests in the
 *        double buffer.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_ar_channel_status_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 19;
     unsigned      rfsm_state                                :  5;
     unsigned      reserved1                                 :  5;
     unsigned      arready                                   :  1;
     unsigned      ardepth                                   :  2;
#else    /* Little Endian */
     unsigned      ardepth                                   :  2;
     unsigned      arready                                   :  1;
     unsigned      reserved1                                 :  5;
     unsigned      rfsm_state                                :  5;
     unsigned      reserved0                                 : 19;
#endif
} ncp_caal_nca_sys_mem_ar_channel_status_r_t;

/*! @struct ncp_caal_nca_sys_mem_aw_channel_status_r_t
 *  @brief CAAL ACE-Lite Write Request Channel Status Register
 *  @details This register contains read-only status for the ACE-Lite write request channel.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_aw_channel_status_r_t\n
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
 *     <td width="30%"> @param wfsm_state </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> The current state of the WFSM state machine. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param awready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The current status of the awready bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param awdepth </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> The current number of ACE-Lite write requests in the
 *        double buffer.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_aw_channel_status_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 21;
     unsigned      wfsm_state                                :  3;
     unsigned      reserved1                                 :  5;
     unsigned      awready                                   :  1;
     unsigned      awdepth                                   :  2;
#else    /* Little Endian */
     unsigned      awdepth                                   :  2;
     unsigned      awready                                   :  1;
     unsigned      reserved1                                 :  5;
     unsigned      wfsm_state                                :  3;
     unsigned      reserved0                                 : 21;
#endif
} ncp_caal_nca_sys_mem_aw_channel_status_r_t;

/*! @struct ncp_caal_nca_sys_mem_w_channel_status_r_t
 *  @brief CAAL ACE-Lite Write Data Channel Status Register
 *  @details This register contains read-only status for the ACE-Lite write data channel.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_w_channel_status_r_t\n
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
 *     <td width="30%"> @param wready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The current status of the wready bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wdepth </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> The current number of ACE-Lite write data words in
 *        the double buffer.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_w_channel_status_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 29;
     unsigned      wready                                    :  1;
     unsigned      wdepth                                    :  2;
#else    /* Little Endian */
     unsigned      wdepth                                    :  2;
     unsigned      wready                                    :  1;
     unsigned      reserved0                                 : 29;
#endif
} ncp_caal_nca_sys_mem_w_channel_status_r_t;

/*! @struct ncp_caal_nca_sys_mem_r_channel_status_r_t
 *  @brief CAAL ACE-Lite Read Data Channel Status Register
 *  @details This register contains read-only status for the ACE-Lite read data channel.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_r_channel_status_r_t\n
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
 *     <td width="30%"> @param rready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The current status of the internal ready bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param rdepth </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> The current number of ACE-Lite read data words in
 *        the double buffer.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_r_channel_status_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 29;
     unsigned      rready                                    :  1;
     unsigned      rdepth                                    :  2;
#else    /* Little Endian */
     unsigned      rdepth                                    :  2;
     unsigned      rready                                    :  1;
     unsigned      reserved0                                 : 29;
#endif
} ncp_caal_nca_sys_mem_r_channel_status_r_t;

/*! @struct ncp_caal_nca_sys_mem_b_channel_status_r_t
 *  @brief CAAL ACE-Lite Write Response Channel Status Register
 *  @details This register contains read-only status for the ACE-Lite write response channel.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_b_channel_status_r_t\n
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
 *     <td width="30%"> @param bready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The current status of the internal ready bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param bdepth </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> The current number of ACE-Lite write responses in
 *        the double buffer.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_b_channel_status_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 29;
     unsigned      bready                                    :  1;
     unsigned      bdepth                                    :  2;
#else    /* Little Endian */
     unsigned      bdepth                                    :  2;
     unsigned      bready                                    :  1;
     unsigned      reserved0                                 : 29;
#endif
} ncp_caal_nca_sys_mem_b_channel_status_r_t;

/*! @struct ncp_caal_nca_sys_mem_params0_r_t
 *  @brief CAAL Params 0
 *  @details This register contains parameter values used to build the CAAL.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_params0_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param wt_width </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Arbitration weigth value width </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param bytes_width </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> CMSI bytes width </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmsi_addr_width </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> CMSI address width </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param acel_addr_width </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ACE-Lite address width </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_params0_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      wt_width                                  :  8;
     unsigned      bytes_width                               :  8;
     unsigned      cmsi_addr_width                           :  8;
     unsigned      acel_addr_width                           :  8;
#else    /* Little Endian */
     unsigned      acel_addr_width                           :  8;
     unsigned      cmsi_addr_width                           :  8;
     unsigned      bytes_width                               :  8;
     unsigned      wt_width                                  :  8;
#endif
} ncp_caal_nca_sys_mem_params0_r_t;

/*! @struct ncp_caal_nca_sys_mem_params1_r_t
 *  @brief CAAL Params 1
 *  @details This register contains parameter values used to build the CAAL.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_params1_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param num_rreqs </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Number of CMSI read requestors </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param num_wreqs </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Number of CMSI write requestors </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_params1_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      num_rreqs                                 : 16;
     unsigned      num_wreqs                                 : 16;
#else    /* Little Endian */
     unsigned      num_wreqs                                 : 16;
     unsigned      num_rreqs                                 : 16;
#endif
} ncp_caal_nca_sys_mem_params1_r_t;

/*! @struct ncp_caal_nca_sys_mem_params2_r_t
 *  @brief CAAL Params 2
 *  @details This register contains parameter values used to build the CAAL.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_params2_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param num_rjobs </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Number of CMSI read job IDs </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param num_wjobs </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Number of CMSI write job IDs </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_params2_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      num_rjobs                                 : 16;
     unsigned      num_wjobs                                 : 16;
#else    /* Little Endian */
     unsigned      num_wjobs                                 : 16;
     unsigned      num_rjobs                                 : 16;
#endif
} ncp_caal_nca_sys_mem_params2_r_t;

/*! @struct ncp_caal_nca_sys_mem_params3_r_t
 *  @brief CAAL Params 3
 *  @details This register contains parameter values used to build the CAAL.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_params3_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param num_reids </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Number of CMSI read engine IDs </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param num_weids </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Number of CMSI write engine IDs </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_params3_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      num_reids                                 : 16;
     unsigned      num_weids                                 : 16;
#else    /* Little Endian */
     unsigned      num_weids                                 : 16;
     unsigned      num_reids                                 : 16;
#endif
} ncp_caal_nca_sys_mem_params3_r_t;

/*! @struct ncp_caal_nca_sys_mem_params4_r_t
 *  @brief CAAL Params 4
 *  @details This register contains parameter values used to build the CAAL.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_params4_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param num_rids </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Number of ACE-Lite read IDs </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param num_wids </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Number of ACE-Lite write IDs </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_params4_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      num_rids                                  : 16;
     unsigned      num_wids                                  : 16;
#else    /* Little Endian */
     unsigned      num_wids                                  : 16;
     unsigned      num_rids                                  : 16;
#endif
} ncp_caal_nca_sys_mem_params4_r_t;

/*! @struct ncp_caal_nca_sys_mem_params5_r_t
 *  @brief CAAL Params 5
 *  @details This register contains parameter values used to build the CAAL.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_params5_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param min_blk_size </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Minimum block size </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param num_pools </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Number of POOLs </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_params5_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      min_blk_size                              : 16;
     unsigned      num_pools                                 : 16;
#else    /* Little Endian */
     unsigned      num_pools                                 : 16;
     unsigned      min_blk_size                              : 16;
#endif
} ncp_caal_nca_sys_mem_params5_r_t;

/*! @struct ncp_caal_nca_sys_mem_params6_r_t
 *  @brief CAAL Params 6
 *  @details This register contains parameter values used to build the CAAL.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_params6_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cla_table_present </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> CLA table present. Cache Line Address table present
 *        bit. CLA table is used for write address comparison.
 *        Write request with overlapping address will use
 *        same ID to enforce ordering.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param vat_rprot_present </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> VAT RPORT field present. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param vat_wprot_present </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> VAT WPORT field present. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param default_pool_present </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Default pool present. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 28 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_params6_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      cla_table_present                         :  1;
     unsigned      vat_rprot_present                         :  1;
     unsigned      vat_wprot_present                         :  1;
     unsigned      default_pool_present                      :  1;
     unsigned      reserved0                                 : 28;
#else    /* Little Endian */
     unsigned      reserved0                                 : 28;
     unsigned      default_pool_present                      :  1;
     unsigned      vat_wprot_present                         :  1;
     unsigned      vat_rprot_present                         :  1;
     unsigned      cla_table_present                         :  1;
#endif
} ncp_caal_nca_sys_mem_params6_r_t;

/*! @struct ncp_caal_nca_sys_mem_recc_r_t
 *  @brief VAT Read ECC
 *  @details This read-only register contains the ECC associate with the last VAT read.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_recc_r_t\n
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
 *     <td width="30%"> @param vat_default_recc </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ECC from last VAT default pool read </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param vat_recc </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ECC from last VAT read </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_recc_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      vat_default_recc                          :  8;
     unsigned      vat_recc                                  :  8;
#else    /* Little Endian */
     unsigned      vat_recc                                  :  8;
     unsigned      vat_default_recc                          :  8;
     unsigned      reserved0                                 : 16;
#endif
} ncp_caal_nca_sys_mem_recc_r_t;

/*! @struct ncp_caal_nca_sys_mem_cla_table_read_ptr_r_t
 *  @brief CLA Table Read Pointer
 *  @details This register is the configuration access read pointer for the CLA table.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_cla_table_read_ptr_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param read_ptr </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> CLA table read pointer. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_cla_table_read_ptr_r_t
 *
 */
 
typedef struct
{
     unsigned  int                  read_ptr;
} ncp_caal_nca_sys_mem_cla_table_read_ptr_r_t;

/*! @struct ncp_caal_nca_sys_mem_cla_table_count_high_wm_r_t
 *  @brief CLA Table Count High Water Mark
 *  @details This register is the high water mark for the CLA Table Count.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_cla_table_count_high_wm_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param high_wm </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> CLA table count high water mark. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_cla_table_count_high_wm_r_t
 *
 */
 
typedef struct
{
     unsigned  int                   high_wm;
} ncp_caal_nca_sys_mem_cla_table_count_high_wm_r_t;

/*! @struct ncp_caal_nca_sys_mem_acelite_read_control_r_t
 *  @brief ACELITE Read Control Register
 *  @details This register controls the ACELITE read channel signals .
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_acelite_read_control_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param rr_ttype </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> CMSI read ttype. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param rr_revserved_1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> reserved. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param inv </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Block Invalidate. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param u_sel </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> user field selection. select aruser_1 over aruser_0
 *        when crossing or finishing a cache line read
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param rr_reserved </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> reserved. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ardomain </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> ACELITE read channel domain signal. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arcache </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ACELITE read channel cache signal. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param aruser_1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ACELITE read channel alternative user signal. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param aruser_0 </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> ACELITE read channel default user signal. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arsnoop </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ACELITE read channel snoop signal. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_acelite_read_control_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      rr_ttype                                  :  8;
     unsigned      rr_revserved_1                            :  2;
     unsigned      inv                                       :  1;
     unsigned      u_sel                                     :  1;
     unsigned      rr_reserved                               :  6;
     unsigned      ardomain                                  :  2;
     unsigned      arcache                                   :  4;
     unsigned      aruser_1                                  :  2;
     unsigned      aruser_0                                  :  2;
     unsigned      arsnoop                                   :  4;
#else    /* Little Endian */
     unsigned      arsnoop                                   :  4;
     unsigned      aruser_0                                  :  2;
     unsigned      aruser_1                                  :  2;
     unsigned      arcache                                   :  4;
     unsigned      ardomain                                  :  2;
     unsigned      rr_reserved                               :  6;
     unsigned      u_sel                                     :  1;
     unsigned      inv                                       :  1;
     unsigned      rr_revserved_1                            :  2;
     unsigned      rr_ttype                                  :  8;
#endif
} ncp_caal_nca_sys_mem_acelite_read_control_r_t;

/*! @struct ncp_caal_nca_sys_mem_acelite_read_qos_control_r_t
 *  @brief ACELITE Read qos Control Register
 *  @details This register controls the ACELITE read channel qos signal .
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_acelite_read_qos_control_r_t\n
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
 *     <td width="30%"> @param arqos </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ACELITE read channel qos signal. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_acelite_read_qos_control_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 28;
     unsigned      arqos                                     :  4;
#else    /* Little Endian */
     unsigned      arqos                                     :  4;
     unsigned      reserved0                                 : 28;
#endif
} ncp_caal_nca_sys_mem_acelite_read_qos_control_r_t;

/*! @struct ncp_caal_nca_sys_mem_acelite_write_control_r_t
 *  @brief ACELITE Write Control Register
 *  @details This register controls the ACELITE write channel signals .
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_acelite_write_control_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param wr_ttype </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> CMSI write ttype. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pad </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Write Pad. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param sixteen_byte_aligned </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> 16 Byte Aligned. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wr_reserved </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> reserved. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param alternative_ttype </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> alternative ttype. if 16 byte aligned write is more
 *        than 64 byte, use this ttype instead
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wr_reserved_1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> reserved. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param awdomain </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> ACELITE write channel domain signal. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param awcache </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ACELITE write channel cache signal. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_acelite_write_control_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      wr_ttype                                  :  8;
     unsigned      pad                                       :  1;
     unsigned      sixteen_byte_aligned                      :  1;
     unsigned      wr_reserved                               :  6;
     unsigned      alternative_ttype                         :  8;
     unsigned      wr_reserved_1                             :  2;
     unsigned      awdomain                                  :  2;
     unsigned      awcache                                   :  4;
#else    /* Little Endian */
     unsigned      awcache                                   :  4;
     unsigned      awdomain                                  :  2;
     unsigned      wr_reserved_1                             :  2;
     unsigned      alternative_ttype                         :  8;
     unsigned      wr_reserved                               :  6;
     unsigned      sixteen_byte_aligned                      :  1;
     unsigned      pad                                       :  1;
     unsigned      wr_ttype                                  :  8;
#endif
} ncp_caal_nca_sys_mem_acelite_write_control_r_t;

/*! @struct ncp_caal_nca_sys_mem_acelite_write_qos_control_r_t
 *  @brief ACELITE Write qos Control Register
 *  @details This register controls the ACELITE write channel qos signal .
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_acelite_write_qos_control_r_t\n
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
 *     <td width="30%"> @param awqos </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ACELITE write channel qos signal. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_acelite_write_qos_control_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 28;
     unsigned      awqos                                     :  4;
#else    /* Little Endian */
     unsigned      awqos                                     :  4;
     unsigned      reserved0                                 : 28;
#endif
} ncp_caal_nca_sys_mem_acelite_write_qos_control_r_t;

/*! @struct ncp_caal_nca_sys_mem_max_cla_table_count_r_t
 *  @brief Max CLA Table Count
 *  @details This register indicates the maxinum number of write request with overlapping address that is supported by the hardware.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_max_cla_table_count_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param max_cla </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Maxinum number of overlapping request supported by
 *        the hardware. This is a hardware build parameter
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_max_cla_table_count_r_t
 *
 */
 
typedef struct
{
     unsigned  int                   max_cla;
} ncp_caal_nca_sys_mem_max_cla_table_count_r_t;

/*! @struct ncp_caal_nca_sys_mem_cla_table_count_r_t
 *  @brief CLA Table Count
 *  @details This register contains the CLA Table Count. cla_table_read_ptr is the CLA Table read pointer
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_cla_table_count_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cla_table_count </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> CLA Table Count. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_cla_table_count_r_t
 *
 */
 
typedef struct
{
     unsigned  int           cla_table_count;
} ncp_caal_nca_sys_mem_cla_table_count_r_t;

/*! @struct ncp_caal_nca_sys_mem_cla_table_hptr_r_t
 *  @brief CLA Table Head Pointer
 *  @details This register contains the CLA Table Head Pointer. cla_table_read_ptr is the CLA Table read pointer
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_cla_table_hptr_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cla_table_hptr </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> CLA Table Head Pointer. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_cla_table_hptr_r_t
 *
 */
 
typedef struct
{
     unsigned  int            cla_table_hptr;
} ncp_caal_nca_sys_mem_cla_table_hptr_r_t;

/*! @struct ncp_caal_nca_sys_mem_cla_table_tptr_r_t
 *  @brief CLA Table Tail Pointer
 *  @details This register contains the CLA Table Tail Pointer. cla_table_read_ptr is the CLA Table read pointer
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_cla_table_tptr_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cla_table_tptr </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> CLA Table Tail Pointer. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_cla_table_tptr_r_t
 *
 */
 
typedef struct
{
     unsigned  int            cla_table_tptr;
} ncp_caal_nca_sys_mem_cla_table_tptr_r_t;

/*! @struct ncp_caal_nca_sys_mem_cla_table_count_full_r_t
 *  @brief CLA Table Count Full
 *  @details This register contains the CLA Table count full status bit vector.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_cla_table_count_full_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cla_table_count_full </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> CLA Table Count Full status bits. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_cla_table_count_full_r_t
 *
 */
 
typedef struct
{
     unsigned  int      cla_table_count_full;
} ncp_caal_nca_sys_mem_cla_table_count_full_r_t;

/*! @struct ncp_caal_nca_sys_mem_cla_table_count_empty_r_t
 *  @brief CLA Table Count Empty
 *  @details This register contains the CLA Table count empty status bit vector.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_cla_table_count_empty_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cla_table_count_empty </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> CLA Table Count Empty status bits. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_cla_table_count_empty_r_t
 *
 */
 
typedef struct
{
     unsigned  int      cla_table_count_empty;
} ncp_caal_nca_sys_mem_cla_table_count_empty_r_t;

/*! @struct ncp_caal_nca_sys_mem_cla_table_count_overflow_r_t
 *  @brief CLA Table Count Overflow
 *  @details This register contains the CLA Table count overflow status bit vector.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_cla_table_count_overflow_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cla_table_count_overflow </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> CLA Table Count Overflow status bits. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_cla_table_count_overflow_r_t
 *
 */
 
typedef struct
{
     unsigned  int      cla_table_count_overflow;
} ncp_caal_nca_sys_mem_cla_table_count_overflow_r_t;

/*! @struct ncp_caal_nca_sys_mem_cla_table_count_underflow_r_t
 *  @brief CLA Table Count Underflow
 *  @details This register contains the CLA Table count underflow status bit vector.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_cla_table_count_underflow_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cla_table_count_underflow </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> CLA Table Count Underflow status bits. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_cla_table_count_underflow_r_t
 *
 */
 
typedef struct
{
     unsigned  int      cla_table_count_underflow;
} ncp_caal_nca_sys_mem_cla_table_count_underflow_r_t;

/*! @struct ncp_caal_nca_sys_mem_read_req_sent_cnt_r_t
 *  @brief CAAL ACE-Lite Read Request Sent Count
 *  @details This register contains the number of ACE-Lite read request sent.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_read_req_sent_cnt_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param sent_cnt </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ACE-Lite read request sent. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_read_req_sent_cnt_r_t
 *
 */
 
typedef struct
{
     unsigned  int                  sent_cnt;
} ncp_caal_nca_sys_mem_read_req_sent_cnt_r_t;

/*! @struct ncp_caal_nca_sys_mem_write_req_sent_cnt_r_t
 *  @brief CAAL ACE-Lite Write Request Sent Count
 *  @details This register contains the number of ACE-Lite write request sent.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_write_req_sent_cnt_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param sent_cnt </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ACE-Lite write request sent. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_write_req_sent_cnt_r_t
 *
 */
 
typedef struct
{
     unsigned  int                  sent_cnt;
} ncp_caal_nca_sys_mem_write_req_sent_cnt_r_t;

/*! @struct ncp_caal_nca_sys_mem_id_freelist_error_r_t
 *  @brief CAAL Read Write ID Freelist Error
 *  @details This register contains the read and write module ID free list error flags.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_id_freelist_error_r_t\n
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
 *     <td width="30%"> @param ijid_push_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> ijid freelist push error flag. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ijid_pop_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ijid freelist pop error flag. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param awid_push_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> awid freelist push error flag. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param awid_pop_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> awid freelist pop error flag. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param invalidate_ijid_push_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> invalidate ijid freelist push error flag. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param invalidate_ijid_pop_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> invalidate ijid freelist pop error flag. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arid_push_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> arid freelist push error flag. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param arid_pop_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> arid freelist pop error flag. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_id_freelist_error_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 24;
     unsigned      ijid_push_error                           :  1;
     unsigned      ijid_pop_error                            :  1;
     unsigned      awid_push_error                           :  1;
     unsigned      awid_pop_error                            :  1;
     unsigned      invalidate_ijid_push_error                :  1;
     unsigned      invalidate_ijid_pop_error                 :  1;
     unsigned      arid_push_error                           :  1;
     unsigned      arid_pop_error                            :  1;
#else    /* Little Endian */
     unsigned      arid_pop_error                            :  1;
     unsigned      arid_push_error                           :  1;
     unsigned      invalidate_ijid_pop_error                 :  1;
     unsigned      invalidate_ijid_push_error                :  1;
     unsigned      awid_pop_error                            :  1;
     unsigned      awid_push_error                           :  1;
     unsigned      ijid_pop_error                            :  1;
     unsigned      ijid_push_error                           :  1;
     unsigned      reserved0                                 : 24;
#endif
} ncp_caal_nca_sys_mem_id_freelist_error_r_t;

/*! @struct ncp_caal_nca_sys_mem_lat_int_ctl_r_t
 *  @brief CAAL Read Latency Interrupt Control Register
 *  @details This register register control the setting of latency interrupt bit in the interrupt register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_lat_int_ctl_r_t\n
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
 *     <td width="30%"> @param int_ctl </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> latency interrupt control. 1: average latency counter
 *        equal or exceed the latency thresholdi field in the
 *        latency interrupt control register, 2: max latency
 *        counter equal or exceed the specified latency threshold
 *        field in the latency interrupt control register, 3:
 *        min latency counter equal or exceed the specified
 *        latency threshold filed in the latency interrupt control
 *        register, others: no interrupt
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param lat_thresh </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> latency threshold. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_lat_int_ctl_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 12;
     unsigned      int_ctl                                   :  4;
     unsigned      lat_thresh                                : 16;
#else    /* Little Endian */
     unsigned      lat_thresh                                : 16;
     unsigned      int_ctl                                   :  4;
     unsigned      reserved0                                 : 12;
#endif
} ncp_caal_nca_sys_mem_lat_int_ctl_r_t;

/*! @struct ncp_caal_nca_sys_mem_avg_lat_cnt_r_t
 *  @brief CAAL Average Read Latency Counter
 *  @details This register contains the average read latency over the number of transactions as specified in average latency binary transaction count field in the counter control register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_avg_lat_cnt_r_t\n
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
 *     <td width="30%"> @param lat_cnt </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Average read latency. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_avg_lat_cnt_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      lat_cnt                                   : 16;
#else    /* Little Endian */
     unsigned      lat_cnt                                   : 16;
     unsigned      reserved0                                 : 16;
#endif
} ncp_caal_nca_sys_mem_avg_lat_cnt_r_t;

/*! @struct ncp_caal_nca_sys_mem_interrupt_status_r_t
 *  @brief Interrupt Status Register
 *  @details This register holds interrupt status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_interrupt_status_r_t\n
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
 *     <td width="30%"> @param cfg_lat_int_set </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Set when the latency counter exceed the programmed
 *        level Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param id_freelist_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Set when any of the freelists in read or write logic
 *        encounter a hardware error. This occurs when the read
 *        or write logic tries to pop an empty freelist or push
 *        an id back to the freelist that is already valid.
 *        The id_freelist_error register indicates which of
 *        the freelists encounter the error Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param sixteen_b_aligned_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> The CMSI write request was a 16 byte aligned transaction
 *        type but had illegal size or offset Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param bid_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> The bid table read had a parity error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param rid_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> The rid table read had a parity error Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crd_cc_ack_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> The CMSI read request channel saw a response error
 *        for a cache command operation Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_vat_sb_ecc_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> The CMSI read request channel saw a single bit ECC
 *        error in the VAT Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_vat_mb_ecc_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> The CMSI read request channel saw a multiple bit ECC
 *        error in the VAT Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_vat_table_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> The CMSI read request channel pool did not have a
 *        vlaid VAT entry Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_vat_bounds_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> The CMSI read request channel virtual address was
 *        outside the configured VAT limit Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_eid_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> The CMSI read request channel engine ID was outside
 *        the configured range Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_addr_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> The CMSI read request channel address failed the configured
 *        address range check Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_maxbytes_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> The number of bytes requested by a CMSI read request
 *        exceeded the allowable limit Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param unused_bit_1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Reserved Interrupt Status Bit 15 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_vat_sb_ecc_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> The CMSI write request channel saw a single bit ECC
 *        error in the VAT Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_vat_mb_ecc_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> The CMSI write request channel saw a multiple bit
 *        ECC error in the VAT Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_vat_table_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> The CMSI write request channel pool did not have a
 *        vlaid VAT entry Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_vat_bounds_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> The CMSI write request channel virtual address was
 *        outside the configured VAT limit Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_addr_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> The CMSI write request channel physical address failed
 *        the configured address range check Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_maxbytes_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> The number of bytes requested by a CMSI write request
 *        exceeded the allowable limit Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param unused_bit_0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Reserved Interrupt Status Bit 8 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwd_id_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> The CMSI write data channel job ID did not match the
 *        CMSI write request job ID Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwd_len_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> The number of CMSI write data channel words did not
 *        match the number required by the CMSI write request
 *        Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param r_noreq_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> The ACE-Lite R channel response ID had no outstanding
 *        request Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param r_slverr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> The ACE-Lite R channel response code was SLVERR Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param r_decerr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> The ACE-Lite R channel response code was DECERR Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param b_noreq_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The ACE-Lite B channel response ID had no outstanding
 *        request Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param b_slverr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> The ACE-Lite B channel response code was SLVERR Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param b_decerr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> The ACE-Lite B channel response code was DECERR Status </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_interrupt_status_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  3;
     unsigned      cfg_lat_int_set                           :  1;
     unsigned      id_freelist_error                         :  1;
     unsigned      sixteen_b_aligned_err                     :  1;
     unsigned      bid_parity_err                            :  1;
     unsigned      rid_parity_err                            :  1;
     unsigned      crd_cc_ack_err                            :  1;
     unsigned      crr_vat_sb_ecc_err                        :  1;
     unsigned      crr_vat_mb_ecc_err                        :  1;
     unsigned      crr_vat_table_err                         :  1;
     unsigned      crr_vat_bounds_err                        :  1;
     unsigned      crr_eid_err                               :  1;
     unsigned      crr_addr_err                              :  1;
     unsigned      crr_maxbytes_err                          :  1;
     unsigned      unused_bit_1                              :  1;
     unsigned      cwr_vat_sb_ecc_err                        :  1;
     unsigned      cwr_vat_mb_ecc_err                        :  1;
     unsigned      cwr_vat_table_err                         :  1;
     unsigned      cwr_vat_bounds_err                        :  1;
     unsigned      cwr_addr_err                              :  1;
     unsigned      cwr_maxbytes_err                          :  1;
     unsigned      unused_bit_0                              :  1;
     unsigned      cwd_id_err                                :  1;
     unsigned      cwd_len_err                               :  1;
     unsigned      r_noreq_err                               :  1;
     unsigned      r_slverr                                  :  1;
     unsigned      r_decerr                                  :  1;
     unsigned      b_noreq_err                               :  1;
     unsigned      b_slverr                                  :  1;
     unsigned      b_decerr                                  :  1;
#else    /* Little Endian */
     unsigned      b_decerr                                  :  1;
     unsigned      b_slverr                                  :  1;
     unsigned      b_noreq_err                               :  1;
     unsigned      r_decerr                                  :  1;
     unsigned      r_slverr                                  :  1;
     unsigned      r_noreq_err                               :  1;
     unsigned      cwd_len_err                               :  1;
     unsigned      cwd_id_err                                :  1;
     unsigned      unused_bit_0                              :  1;
     unsigned      cwr_maxbytes_err                          :  1;
     unsigned      cwr_addr_err                              :  1;
     unsigned      cwr_vat_bounds_err                        :  1;
     unsigned      cwr_vat_table_err                         :  1;
     unsigned      cwr_vat_mb_ecc_err                        :  1;
     unsigned      cwr_vat_sb_ecc_err                        :  1;
     unsigned      unused_bit_1                              :  1;
     unsigned      crr_maxbytes_err                          :  1;
     unsigned      crr_addr_err                              :  1;
     unsigned      crr_eid_err                               :  1;
     unsigned      crr_vat_bounds_err                        :  1;
     unsigned      crr_vat_table_err                         :  1;
     unsigned      crr_vat_mb_ecc_err                        :  1;
     unsigned      crr_vat_sb_ecc_err                        :  1;
     unsigned      crd_cc_ack_err                            :  1;
     unsigned      rid_parity_err                            :  1;
     unsigned      bid_parity_err                            :  1;
     unsigned      sixteen_b_aligned_err                     :  1;
     unsigned      id_freelist_error                         :  1;
     unsigned      cfg_lat_int_set                           :  1;
     unsigned      reserved0                                 :  3;
#endif
} ncp_caal_nca_sys_mem_interrupt_status_r_t;

/*! @struct ncp_caal_nca_sys_mem_interrupt_en_r_t
 *  @brief Interrupt Enable Register
 *  @details This register enables interrupts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_interrupt_en_r_t\n
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
 *     <td width="30%"> @param cfg_lat_int_set </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Set when the latency counter exceed the programmed
 *        level Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param id_freelist_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Set when any of the freelists in read or write logic
 *        encounter a hardware error. This occurs when the read
 *        or write logic tries to pop an empty freelist or push
 *        an id back to the freelist that is already valid.
 *        The id_freelist_error register indicates which of
 *        the freelists encounter the error Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param sixteen_b_aligned_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> The CMSI write request was a 16 byte aligned transaction
 *        type but had illegal size or offset Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param bid_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> The bid table read had a parity error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param rid_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> The rid table read had a parity error Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crd_cc_ack_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> The CMSI read request channel saw a response error
 *        for a cache command operation Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_vat_sb_ecc_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> The CMSI read request channel saw a single bit ECC
 *        error in the VAT Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_vat_mb_ecc_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> The CMSI read request channel saw a multiple bit ECC
 *        error in the VAT Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_vat_table_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> The CMSI read request channel pool did not have a
 *        vlaid VAT entry Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_vat_bounds_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> The CMSI read request channel virtual address was
 *        outside the configured VAT limit Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_eid_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> The CMSI read request channel engine ID was outside
 *        the configured range Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_addr_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> The CMSI read request channel address failed the configured
 *        address range check Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_maxbytes_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> The number of bytes requested by a CMSI read request
 *        exceeded the allowable limit Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param unused_bit_1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Reserved Interrupt Enable Bit 15 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_vat_sb_ecc_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> The CMSI write request channel saw a single bit ECC
 *        error in the VAT Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_vat_mb_ecc_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> The CMSI write request channel saw a multiple bit
 *        ECC error in the VAT Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_vat_table_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> The CMSI write request channel pool did not have a
 *        vlaid VAT entry Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_vat_bounds_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> The CMSI write request channel virtual address was
 *        outside the configured VAT limit Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_addr_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> The CMSI write request channel physical address failed
 *        the configured address range check Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_maxbytes_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> The number of bytes requested by a CMSI write request
 *        exceeded the allowable limit Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param unused_bit_0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Reserved Interrupt Enable Bit 8 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwd_id_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> The CMSI write data channel job ID did not match the
 *        CMSI write request job ID Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwd_len_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> The number of CMSI write data channel words did not
 *        match the number required by the CMSI write request
 *        Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param r_noreq_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> The ACE-Lite R channel response ID had no outstanding
 *        request Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param r_slverr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> The ACE-Lite R channel response code was SLVERR Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param r_decerr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> The ACE-Lite R channel response code was DECERR Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param b_noreq_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The ACE-Lite B channel response ID had no outstanding
 *        request Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param b_slverr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> The ACE-Lite B channel response code was SLVERR Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param b_decerr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> The ACE-Lite B channel response code was DECERR Enable </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_interrupt_en_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  3;
     unsigned      cfg_lat_int_set                           :  1;
     unsigned      id_freelist_error                         :  1;
     unsigned      sixteen_b_aligned_err                     :  1;
     unsigned      bid_parity_err                            :  1;
     unsigned      rid_parity_err                            :  1;
     unsigned      crd_cc_ack_err                            :  1;
     unsigned      crr_vat_sb_ecc_err                        :  1;
     unsigned      crr_vat_mb_ecc_err                        :  1;
     unsigned      crr_vat_table_err                         :  1;
     unsigned      crr_vat_bounds_err                        :  1;
     unsigned      crr_eid_err                               :  1;
     unsigned      crr_addr_err                              :  1;
     unsigned      crr_maxbytes_err                          :  1;
     unsigned      unused_bit_1                              :  1;
     unsigned      cwr_vat_sb_ecc_err                        :  1;
     unsigned      cwr_vat_mb_ecc_err                        :  1;
     unsigned      cwr_vat_table_err                         :  1;
     unsigned      cwr_vat_bounds_err                        :  1;
     unsigned      cwr_addr_err                              :  1;
     unsigned      cwr_maxbytes_err                          :  1;
     unsigned      unused_bit_0                              :  1;
     unsigned      cwd_id_err                                :  1;
     unsigned      cwd_len_err                               :  1;
     unsigned      r_noreq_err                               :  1;
     unsigned      r_slverr                                  :  1;
     unsigned      r_decerr                                  :  1;
     unsigned      b_noreq_err                               :  1;
     unsigned      b_slverr                                  :  1;
     unsigned      b_decerr                                  :  1;
#else    /* Little Endian */
     unsigned      b_decerr                                  :  1;
     unsigned      b_slverr                                  :  1;
     unsigned      b_noreq_err                               :  1;
     unsigned      r_decerr                                  :  1;
     unsigned      r_slverr                                  :  1;
     unsigned      r_noreq_err                               :  1;
     unsigned      cwd_len_err                               :  1;
     unsigned      cwd_id_err                                :  1;
     unsigned      unused_bit_0                              :  1;
     unsigned      cwr_maxbytes_err                          :  1;
     unsigned      cwr_addr_err                              :  1;
     unsigned      cwr_vat_bounds_err                        :  1;
     unsigned      cwr_vat_table_err                         :  1;
     unsigned      cwr_vat_mb_ecc_err                        :  1;
     unsigned      cwr_vat_sb_ecc_err                        :  1;
     unsigned      unused_bit_1                              :  1;
     unsigned      crr_maxbytes_err                          :  1;
     unsigned      crr_addr_err                              :  1;
     unsigned      crr_eid_err                               :  1;
     unsigned      crr_vat_bounds_err                        :  1;
     unsigned      crr_vat_table_err                         :  1;
     unsigned      crr_vat_mb_ecc_err                        :  1;
     unsigned      crr_vat_sb_ecc_err                        :  1;
     unsigned      crd_cc_ack_err                            :  1;
     unsigned      rid_parity_err                            :  1;
     unsigned      bid_parity_err                            :  1;
     unsigned      sixteen_b_aligned_err                     :  1;
     unsigned      id_freelist_error                         :  1;
     unsigned      cfg_lat_int_set                           :  1;
     unsigned      reserved0                                 :  3;
#endif
} ncp_caal_nca_sys_mem_interrupt_en_r_t;

/*! @struct ncp_caal_nca_sys_mem_interrupt_force_r_t
 *  @brief Interrupt Force Register
 *  @details This address is an alias for the Interrupt Status register
		that allows normal CFG writes (as opposed to the Clear-On-Write-One
		behavior if the Interrupt Status register address is used).  This
		allows CFG to set interrupt bits for testing purposes.  Reading this
		address returns the current value of the Interrupt Status Register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_interrupt_force_r_t\n
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
 *     <td width="30%"> @param cfg_lat_int_set </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Set when the latency counter exceed the programmed
 *        level Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param id_freelist_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Set when any of the freelists in read or write logic
 *        encounter a hardware error. This occurs when the read
 *        or write logic tries to pop an empty freelist or push
 *        an id back to the freelist that is already valid.
 *        The id_freelist_error register indicates which of
 *        the freelists encounter the error Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param sixteen_b_aligned_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> The CMSI write request was a 16 byte aligned transaction
 *        type but had illegal size or offset Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param bid_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> The bid table read had a parity error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param rid_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> The rid table read had a parity error Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crd_cc_ack_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> The CMSI read request channel saw a response error
 *        for a cache command operation Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_vat_sb_ecc_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> The CMSI read request channel saw a single bit ECC
 *        error in the VAT Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_vat_mb_ecc_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> The CMSI read request channel saw a multiple bit ECC
 *        error in the VAT Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_vat_table_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> The CMSI read request channel pool did not have a
 *        vlaid VAT entry Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_vat_bounds_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> The CMSI read request channel virtual address was
 *        outside the configured VAT limit Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_eid_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> The CMSI read request channel engine ID was outside
 *        the configured range Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_addr_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> The CMSI read request channel address failed the configured
 *        address range check Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param crr_maxbytes_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> The number of bytes requested by a CMSI read request
 *        exceeded the allowable limit Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param unused_bit_1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Reserved Interrupt Force Bit 15 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_vat_sb_ecc_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> The CMSI write request channel saw a single bit ECC
 *        error in the VAT Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_vat_mb_ecc_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> The CMSI write request channel saw a multiple bit
 *        ECC error in the VAT Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_vat_table_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> The CMSI write request channel pool did not have a
 *        vlaid VAT entry Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_vat_bounds_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> The CMSI write request channel virtual address was
 *        outside the configured VAT limit Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_addr_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> The CMSI write request channel physical address failed
 *        the configured address range check Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwr_maxbytes_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> The number of bytes requested by a CMSI write request
 *        exceeded the allowable limit Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param unused_bit_0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Reserved Interrupt Force Bit 8 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwd_id_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> The CMSI write data channel job ID did not match the
 *        CMSI write request job ID Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cwd_len_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> The number of CMSI write data channel words did not
 *        match the number required by the CMSI write request
 *        Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param r_noreq_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> The ACE-Lite R channel response ID had no outstanding
 *        request Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param r_slverr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> The ACE-Lite R channel response code was SLVERR Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param r_decerr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> The ACE-Lite R channel response code was DECERR Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param b_noreq_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> The ACE-Lite B channel response ID had no outstanding
 *        request Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param b_slverr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> The ACE-Lite B channel response code was SLVERR Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param b_decerr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> The ACE-Lite B channel response code was DECERR Force </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_interrupt_force_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  3;
     unsigned      cfg_lat_int_set                           :  1;
     unsigned      id_freelist_error                         :  1;
     unsigned      sixteen_b_aligned_err                     :  1;
     unsigned      bid_parity_err                            :  1;
     unsigned      rid_parity_err                            :  1;
     unsigned      crd_cc_ack_err                            :  1;
     unsigned      crr_vat_sb_ecc_err                        :  1;
     unsigned      crr_vat_mb_ecc_err                        :  1;
     unsigned      crr_vat_table_err                         :  1;
     unsigned      crr_vat_bounds_err                        :  1;
     unsigned      crr_eid_err                               :  1;
     unsigned      crr_addr_err                              :  1;
     unsigned      crr_maxbytes_err                          :  1;
     unsigned      unused_bit_1                              :  1;
     unsigned      cwr_vat_sb_ecc_err                        :  1;
     unsigned      cwr_vat_mb_ecc_err                        :  1;
     unsigned      cwr_vat_table_err                         :  1;
     unsigned      cwr_vat_bounds_err                        :  1;
     unsigned      cwr_addr_err                              :  1;
     unsigned      cwr_maxbytes_err                          :  1;
     unsigned      unused_bit_0                              :  1;
     unsigned      cwd_id_err                                :  1;
     unsigned      cwd_len_err                               :  1;
     unsigned      r_noreq_err                               :  1;
     unsigned      r_slverr                                  :  1;
     unsigned      r_decerr                                  :  1;
     unsigned      b_noreq_err                               :  1;
     unsigned      b_slverr                                  :  1;
     unsigned      b_decerr                                  :  1;
#else    /* Little Endian */
     unsigned      b_decerr                                  :  1;
     unsigned      b_slverr                                  :  1;
     unsigned      b_noreq_err                               :  1;
     unsigned      r_decerr                                  :  1;
     unsigned      r_slverr                                  :  1;
     unsigned      r_noreq_err                               :  1;
     unsigned      cwd_len_err                               :  1;
     unsigned      cwd_id_err                                :  1;
     unsigned      unused_bit_0                              :  1;
     unsigned      cwr_maxbytes_err                          :  1;
     unsigned      cwr_addr_err                              :  1;
     unsigned      cwr_vat_bounds_err                        :  1;
     unsigned      cwr_vat_table_err                         :  1;
     unsigned      cwr_vat_mb_ecc_err                        :  1;
     unsigned      cwr_vat_sb_ecc_err                        :  1;
     unsigned      unused_bit_1                              :  1;
     unsigned      crr_maxbytes_err                          :  1;
     unsigned      crr_addr_err                              :  1;
     unsigned      crr_eid_err                               :  1;
     unsigned      crr_vat_bounds_err                        :  1;
     unsigned      crr_vat_table_err                         :  1;
     unsigned      crr_vat_mb_ecc_err                        :  1;
     unsigned      crr_vat_sb_ecc_err                        :  1;
     unsigned      crd_cc_ack_err                            :  1;
     unsigned      rid_parity_err                            :  1;
     unsigned      bid_parity_err                            :  1;
     unsigned      sixteen_b_aligned_err                     :  1;
     unsigned      id_freelist_error                         :  1;
     unsigned      cfg_lat_int_set                           :  1;
     unsigned      reserved0                                 :  3;
#endif
} ncp_caal_nca_sys_mem_interrupt_force_r_t;

/*! @struct ncp_caal_nca_sys_mem_cfg_lock_ctrl_r_t
 *  @brief nu_caal_cfg Lock Control Register
 *  @details CAAL Lock Control Register
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_caal_nca_sys_mem_cfg_lock_ctrl_r_t\n
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
 *     <td width="30%"> @param write_lock </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Once set this will disable all cfg write except for
 *        interrupt status.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_cfg_lock_ctrl_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 31;
     unsigned      write_lock                                :  1;
#else    /* Little Endian */
     unsigned      write_lock                                :  1;
     unsigned      reserved0                                 : 31;
#endif
} ncp_caal_nca_sys_mem_cfg_lock_ctrl_r_t;

/*! @struct ncp_caal_nca_sys_mem_min_addr_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_caal_nca_sys_mem_min_addr_r_t
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
 *     <td width="30%"> @param min_addr_35_32 </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 4 bits of min_addr. Minimum 256B ACE-Lite address </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param min_addr_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of min_addr. Minimum 256B ACE-Lite address </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_min_addr_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0                                 : 28;
     unsigned      min_addr_35_32                            :  4;
          /* word 1 */
     unsigned      min_addr_31_0                             : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      min_addr_35_32                            :  4;
     unsigned      reserved0                                 : 28;
          /* word 1 */
     unsigned      min_addr_31_0                             : 32;
#endif
} ncp_caal_nca_sys_mem_min_addr_r_t;

/*! @struct ncp_caal_nca_sys_mem_max_addr_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_caal_nca_sys_mem_max_addr_r_t
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
 *     <td width="30%"> @param max_addr_35_32 </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 4 bits of max_addr. Maximum 256B ACE-Lite address </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param max_addr_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of max_addr. Maximum 256B ACE-Lite address </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_max_addr_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0                                 : 28;
     unsigned      max_addr_35_32                            :  4;
          /* word 1 */
     unsigned      max_addr_31_0                             : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      max_addr_35_32                            :  4;
     unsigned      reserved0                                 : 28;
          /* word 1 */
     unsigned      max_addr_31_0                             : 32;
#endif
} ncp_caal_nca_sys_mem_max_addr_r_t;

/*! @struct ncp_caal_nca_sys_mem_clk_counter_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_caal_nca_sys_mem_clk_counter_r_t
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
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param count_47_32 </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 16 bits of count. Counter value </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param count_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of count. Counter value </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_clk_counter_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0                                 : 16;
     unsigned      count_47_32                               : 16;
          /* word 1 */
     unsigned      count_31_0                                : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      count_47_32                               : 16;
     unsigned      reserved0                                 : 16;
          /* word 1 */
     unsigned      count_31_0                                : 32;
#endif
} ncp_caal_nca_sys_mem_clk_counter_r_t;

/*! @struct ncp_caal_nca_sys_mem_counter0_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_caal_nca_sys_mem_counter0_r_t
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
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param count_47_32 </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 16 bits of count. Counter value. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param count_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of count. Counter value. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_counter0_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0                                 : 16;
     unsigned      count_47_32                               : 16;
          /* word 1 */
     unsigned      count_31_0                                : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      count_47_32                               : 16;
     unsigned      reserved0                                 : 16;
          /* word 1 */
     unsigned      count_31_0                                : 32;
#endif
} ncp_caal_nca_sys_mem_counter0_r_t;

/*! @struct ncp_caal_nca_sys_mem_counter1_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_caal_nca_sys_mem_counter1_r_t
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
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param count_47_32 </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 16 bits of count. Counter value. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param count_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of count. Counter value. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_counter1_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0                                 : 16;
     unsigned      count_47_32                               : 16;
          /* word 1 */
     unsigned      count_31_0                                : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      count_47_32                               : 16;
     unsigned      reserved0                                 : 16;
          /* word 1 */
     unsigned      count_31_0                                : 32;
#endif
} ncp_caal_nca_sys_mem_counter1_r_t;

/*! @struct ncp_caal_nca_sys_mem_counter2_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_caal_nca_sys_mem_counter2_r_t
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
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param count_47_32 </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 16 bits of count. Counter value. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param count_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of count. Counter value. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_counter2_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0                                 : 16;
     unsigned      count_47_32                               : 16;
          /* word 1 */
     unsigned      count_31_0                                : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      count_47_32                               : 16;
     unsigned      reserved0                                 : 16;
          /* word 1 */
     unsigned      count_31_0                                : 32;
#endif
} ncp_caal_nca_sys_mem_counter2_r_t;

/*! @struct ncp_caal_nca_sys_mem_counter3_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_caal_nca_sys_mem_counter3_r_t
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
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param count_47_32 </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 16 bits of count. Counter value. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param count_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of count. Counter value. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_counter3_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0                                 : 16;
     unsigned      count_47_32                               : 16;
          /* word 1 */
     unsigned      count_31_0                                : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      count_47_32                               : 16;
     unsigned      reserved0                                 : 16;
          /* word 1 */
     unsigned      count_31_0                                : 32;
#endif
} ncp_caal_nca_sys_mem_counter3_r_t;

/*! @struct ncp_caal_nca_sys_mem_arid_status_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_caal_nca_sys_mem_arid_status_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_191_160 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_159_128 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_127_96 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_95_64 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_63_32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param freelist_63_32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of freelist. ARID freelist vector. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param freelist_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of freelist. ARID freelist vector. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_arid_status_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0_191_160                         : 32;
          /* word 1 */
     unsigned      reserved0_159_128                         : 32;
          /* word 2 */
     unsigned      reserved0_127_96                          : 32;
          /* word 3 */
     unsigned      reserved0_95_64                           : 32;
          /* word 4 */
     unsigned      reserved0_63_32                           : 32;
          /* word 5 */
     unsigned      reserved0_31_0                            : 32;
          /* word 6 */
     unsigned      freelist_63_32                            : 32;
          /* word 7 */
     unsigned      freelist_31_0                             : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      reserved0_191_160                         : 32;
          /* word 1 */
     unsigned      reserved0_159_128                         : 32;
          /* word 2 */
     unsigned      reserved0_127_96                          : 32;
          /* word 3 */
     unsigned      reserved0_95_64                           : 32;
          /* word 4 */
     unsigned      reserved0_63_32                           : 32;
          /* word 5 */
     unsigned      reserved0_31_0                            : 32;
          /* word 6 */
     unsigned      freelist_63_32                            : 32;
          /* word 7 */
     unsigned      freelist_31_0                             : 32;
#endif
} ncp_caal_nca_sys_mem_arid_status_r_t;

/*! @struct ncp_caal_nca_sys_mem_invalidate_ijid_status_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_caal_nca_sys_mem_invalidate_ijid_status_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_191_160 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_159_128 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_127_96 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_95_64 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_63_32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param freelist_63_32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of freelist. Invalidate freelist vector. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param freelist_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of freelist. Invalidate freelist vector. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_invalidate_ijid_status_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0_191_160                         : 32;
          /* word 1 */
     unsigned      reserved0_159_128                         : 32;
          /* word 2 */
     unsigned      reserved0_127_96                          : 32;
          /* word 3 */
     unsigned      reserved0_95_64                           : 32;
          /* word 4 */
     unsigned      reserved0_63_32                           : 32;
          /* word 5 */
     unsigned      reserved0_31_0                            : 32;
          /* word 6 */
     unsigned      freelist_63_32                            : 32;
          /* word 7 */
     unsigned      freelist_31_0                             : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      reserved0_191_160                         : 32;
          /* word 1 */
     unsigned      reserved0_159_128                         : 32;
          /* word 2 */
     unsigned      reserved0_127_96                          : 32;
          /* word 3 */
     unsigned      reserved0_95_64                           : 32;
          /* word 4 */
     unsigned      reserved0_63_32                           : 32;
          /* word 5 */
     unsigned      reserved0_31_0                            : 32;
          /* word 6 */
     unsigned      freelist_63_32                            : 32;
          /* word 7 */
     unsigned      freelist_31_0                             : 32;
#endif
} ncp_caal_nca_sys_mem_invalidate_ijid_status_r_t;

/*! @struct ncp_caal_nca_sys_mem_awid_status_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_caal_nca_sys_mem_awid_status_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_239_208 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_207_176 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_175_144 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_143_112 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_111_80 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_79_48 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_47_16 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_15_0 </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> 16 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param freelist </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> AWID freelist vector. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_awid_status_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0_239_208                         : 32;
          /* word 1 */
     unsigned      reserved0_207_176                         : 32;
          /* word 2 */
     unsigned      reserved0_175_144                         : 32;
          /* word 3 */
     unsigned      reserved0_143_112                         : 32;
          /* word 4 */
     unsigned      reserved0_111_80                          : 32;
          /* word 5 */
     unsigned      reserved0_79_48                           : 32;
          /* word 6 */
     unsigned      reserved0_47_16                           : 32;
          /* word 7 */
     unsigned      reserved0_15_0                            : 16;
     unsigned      freelist                                  : 16;
#else    /* Little Endian */
          /* word 0 */
     unsigned      reserved0_239_208                         : 32;
          /* word 1 */
     unsigned      reserved0_207_176                         : 32;
          /* word 2 */
     unsigned      reserved0_175_144                         : 32;
          /* word 3 */
     unsigned      reserved0_143_112                         : 32;
          /* word 4 */
     unsigned      reserved0_111_80                          : 32;
          /* word 5 */
     unsigned      reserved0_79_48                           : 32;
          /* word 6 */
     unsigned      reserved0_47_16                           : 32;
          /* word 7 */
     unsigned      freelist                                  : 16;
     unsigned      reserved0_15_0                            : 16;
#endif
} ncp_caal_nca_sys_mem_awid_status_r_t;

/*! @struct ncp_caal_nca_sys_mem_ijid_status_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_caal_nca_sys_mem_ijid_status_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_239_208 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_207_176 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_175_144 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_143_112 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_111_80 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_79_48 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_47_16 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0_15_0 </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> 16 bits of reserved0. Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param freelist </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> IJID freelist vector. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_ijid_status_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0_239_208                         : 32;
          /* word 1 */
     unsigned      reserved0_207_176                         : 32;
          /* word 2 */
     unsigned      reserved0_175_144                         : 32;
          /* word 3 */
     unsigned      reserved0_143_112                         : 32;
          /* word 4 */
     unsigned      reserved0_111_80                          : 32;
          /* word 5 */
     unsigned      reserved0_79_48                           : 32;
          /* word 6 */
     unsigned      reserved0_47_16                           : 32;
          /* word 7 */
     unsigned      reserved0_15_0                            : 16;
     unsigned      freelist                                  : 16;
#else    /* Little Endian */
          /* word 0 */
     unsigned      reserved0_239_208                         : 32;
          /* word 1 */
     unsigned      reserved0_207_176                         : 32;
          /* word 2 */
     unsigned      reserved0_175_144                         : 32;
          /* word 3 */
     unsigned      reserved0_143_112                         : 32;
          /* word 4 */
     unsigned      reserved0_111_80                          : 32;
          /* word 5 */
     unsigned      reserved0_79_48                           : 32;
          /* word 6 */
     unsigned      reserved0_47_16                           : 32;
          /* word 7 */
     unsigned      freelist                                  : 16;
     unsigned      reserved0_15_0                            : 16;
#endif
} ncp_caal_nca_sys_mem_ijid_status_r_t;

/*! @struct ncp_caal_nca_sys_mem_rid_table_v_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_caal_nca_sys_mem_rid_table_v_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param table_v_255_224 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of table_v. RID table valid. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param table_v_223_192 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of table_v. RID table valid. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param table_v_191_160 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of table_v. RID table valid. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param table_v_159_128 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of table_v. RID table valid. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param table_v_127_96 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of table_v. RID table valid. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param table_v_95_64 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of table_v. RID table valid. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param table_v_63_32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of table_v. RID table valid. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param table_v_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of table_v. RID table valid. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_rid_table_v_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      table_v_255_224                           : 32;
          /* word 1 */
     unsigned      table_v_223_192                           : 32;
          /* word 2 */
     unsigned      table_v_191_160                           : 32;
          /* word 3 */
     unsigned      table_v_159_128                           : 32;
          /* word 4 */
     unsigned      table_v_127_96                            : 32;
          /* word 5 */
     unsigned      table_v_95_64                             : 32;
          /* word 6 */
     unsigned      table_v_63_32                             : 32;
          /* word 7 */
     unsigned      table_v_31_0                              : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      table_v_255_224                           : 32;
          /* word 1 */
     unsigned      table_v_223_192                           : 32;
          /* word 2 */
     unsigned      table_v_191_160                           : 32;
          /* word 3 */
     unsigned      table_v_159_128                           : 32;
          /* word 4 */
     unsigned      table_v_127_96                            : 32;
          /* word 5 */
     unsigned      table_v_95_64                             : 32;
          /* word 6 */
     unsigned      table_v_63_32                             : 32;
          /* word 7 */
     unsigned      table_v_31_0                              : 32;
#endif
} ncp_caal_nca_sys_mem_rid_table_v_r_t;

/*! @struct ncp_caal_nca_sys_mem_bid_table_v_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_caal_nca_sys_mem_bid_table_v_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param table_v_255_224 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of table_v. BID table valid. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param table_v_223_192 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of table_v. BID table valid. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param table_v_191_160 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of table_v. BID table valid. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param table_v_159_128 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of table_v. BID table valid. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param table_v_127_96 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of table_v. BID table valid. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param table_v_95_64 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of table_v. BID table valid. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param table_v_63_32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of table_v. BID table valid. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param table_v_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of table_v. BID table valid. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_bid_table_v_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      table_v_255_224                           : 32;
          /* word 1 */
     unsigned      table_v_223_192                           : 32;
          /* word 2 */
     unsigned      table_v_191_160                           : 32;
          /* word 3 */
     unsigned      table_v_159_128                           : 32;
          /* word 4 */
     unsigned      table_v_127_96                            : 32;
          /* word 5 */
     unsigned      table_v_95_64                             : 32;
          /* word 6 */
     unsigned      table_v_63_32                             : 32;
          /* word 7 */
     unsigned      table_v_31_0                              : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      table_v_255_224                           : 32;
          /* word 1 */
     unsigned      table_v_223_192                           : 32;
          /* word 2 */
     unsigned      table_v_191_160                           : 32;
          /* word 3 */
     unsigned      table_v_159_128                           : 32;
          /* word 4 */
     unsigned      table_v_127_96                            : 32;
          /* word 5 */
     unsigned      table_v_95_64                             : 32;
          /* word 6 */
     unsigned      table_v_63_32                             : 32;
          /* word 7 */
     unsigned      table_v_31_0                              : 32;
#endif
} ncp_caal_nca_sys_mem_bid_table_v_r_t;

/*! @struct ncp_caal_nca_sys_mem_vat_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_caal_nca_sys_mem_vat_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param vat_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> Entry is valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param vat_rprot </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Read Protection Type </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param vat_wprot </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Write Protection Type </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param vat_limit_35_32 </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 4 bits of vat_limit. Virtual address space last offset
 *        (limit-1)
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param vat_limit_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of vat_limit. Virtual address space last offset
 *        (limit-1)
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved2 </td>
 *     <td width="20%" align="center"> 20 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param vat_base_43_32 </td>
 *     <td width="20%" align="center"> 12 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 12 bits of vat_base. Physical address space base </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param vat_base_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of vat_base. Physical address space base </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_caal_nca_sys_mem_vat_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      vat_v                                     :  1;
     unsigned      vat_rprot                                 :  3;
     unsigned      reserved0                                 :  1;
     unsigned      vat_wprot                                 :  3;
     unsigned      reserved1                                 : 20;
     unsigned      vat_limit_35_32                           :  4;
          /* word 1 */
     unsigned      vat_limit_31_0                            : 32;
          /* word 2 */
     unsigned      reserved2                                 : 20;
     unsigned      vat_base_43_32                            : 12;
          /* word 3 */
     unsigned      vat_base_31_0                             : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      vat_limit_35_32                           :  4;
     unsigned      reserved1                                 : 20;
     unsigned      vat_wprot                                 :  3;
     unsigned      reserved0                                 :  1;
     unsigned      vat_rprot                                 :  3;
     unsigned      vat_v                                     :  1;
          /* word 1 */
     unsigned      vat_limit_31_0                            : 32;
          /* word 2 */
     unsigned      vat_base_43_32                            : 12;
     unsigned      reserved2                                 : 20;
          /* word 3 */
     unsigned      vat_base_31_0                             : 32;
#endif
} ncp_caal_nca_sys_mem_vat_r_t;

#ifdef __cplusplus
}
#endif

#endif /* _NCP_CAAL_NCA_SYS_MEM_REGS_H_ */
