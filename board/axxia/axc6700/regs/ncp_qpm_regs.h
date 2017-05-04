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


#ifndef _NCP_QPM_REGS_H_
#define _NCP_QPM_REGS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"

/*! @struct ncp_qpm_init_r_t
 *  @brief QPM Initialization-Register
 *  @details Initialization register for QPM. Autofills of Resource-FIFOs and auto-clear of memory-structure valid-flags are programmed into this register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_init_r_t\n
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
 *     <td width="20%" align="center"> 44 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param init_intq_fl_done </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> QPM Set indicates QPM done initializing of the Interrupt
 *        Queue freelist. Software write clears this bit.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param init_flc_done </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> QPM Set indicates QPM done initializing Free-List
 *        Structure. Software write clears this bit.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param init_thc_done </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> QPM Set indicate QPM done initializing per-Queue Memory-Structures.
 *        Software write clears this bit.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved2 </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param init_intq_fl_2x </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Sets if the init_intq_fl bit is written to 1 after
 *        the init_intq_fl_done bit is already set, and is sticky.
 *        This programming error will corrupt the Interrupt
 *        Queue freelist.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved3 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param init_flc_2x </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> Sets if the init_flc bit is written to 1 after the
 *        init_flc_done bit is already set, and is sticky. This
 *        programming error will corrupt the free list.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved4 </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param init_intq_fl </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Setting init_intq_fl results in initialization of
 *        the Interrupt Queue freelist. This bit clears itself
 *        when the initialization is complete.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved5 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param init_flc </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Setting init_flc results in initialization of the
 *        free-list Structure. This bit clears itself when
 *        the initialization is complete.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param init_thc </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Setting init_thc results in initialization of the
 *        Linked List Controller Structures. This bit clears
 *        itself when the initialization is complete.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_init_r_t
 *
 * Implemented by: 
 *      init_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 44;
     ncp_uint64_t    init_intq_fl_done                         :  1;
     ncp_uint64_t    reserved1                                 :  1;
     ncp_uint64_t    init_flc_done                             :  1;
     ncp_uint64_t    init_thc_done                             :  1;
     ncp_uint64_t    reserved2                                 :  4;
     ncp_uint64_t    init_intq_fl_2x                           :  1;
     ncp_uint64_t    reserved3                                 :  1;
     ncp_uint64_t    init_flc_2x                               :  1;
     ncp_uint64_t    reserved4                                 :  5;
     ncp_uint64_t    init_intq_fl                              :  1;
     ncp_uint64_t    reserved5                                 :  1;
     ncp_uint64_t    init_flc                                  :  1;
     ncp_uint64_t    init_thc                                  :  1;
#else    /* Little Endian */
     ncp_uint64_t    init_thc                                  :  1;
     ncp_uint64_t    init_flc                                  :  1;
     ncp_uint64_t    reserved5                                 :  1;
     ncp_uint64_t    init_intq_fl                              :  1;
     ncp_uint64_t    reserved4                                 :  5;
     ncp_uint64_t    init_flc_2x                               :  1;
     ncp_uint64_t    reserved3                                 :  1;
     ncp_uint64_t    init_intq_fl_2x                           :  1;
     ncp_uint64_t    reserved2                                 :  4;
     ncp_uint64_t    init_thc_done                             :  1;
     ncp_uint64_t    init_flc_done                             :  1;
     ncp_uint64_t    reserved1                                 :  1;
     ncp_uint64_t    init_intq_fl_done                         :  1;
     ncp_uint64_t    reserved0                                 : 44;
#endif
} ncp_qpm_init_r_t;

/*! @struct ncp_qpm_control_r_t
 *  @brief QPM Control Register
 *  @details Control register for QPM.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_control_r_t\n
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
 *     <td width="20%" align="center"> 43 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param enab_tp_read </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Enable TP Read </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param dbg_write </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Debug write mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param dbg_read </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Debug read mode </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmp_smon_qacc </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> Enable SMON compare on qacc. For indicated smon mode(s),
 *        includes qacc bit in the comparison condition. This
 *        bit is used by QPM do differentiate between commands
 *        which functionally access event queues and related
 *        structures.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmp_smon_port </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Enable SMON compare on port number. For indicated
 *        smon mode(s), includes port number bit in the comparison
 *        condition.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmp_smon_ms_qnum </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Enable SMON compare on ms queue number bit. For indicated
 *        smon mode(s), includes most-significant queue number
 *        bit in the comparison condition. This is not actually
 *        a queue number bit, but is used to differentiate some
 *        commands issued by NCA.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cmp_smon_qnum </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Enable SMON compare on queue number. For indicated
 *        smon mode(s), includes queue number in the comparison
 *        condition.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param en_slverr_wr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Enable Slave Error Response on Write. If this bit
 *        is 1, allows QPM to return a SLVERR response when
 *        certain errors occur on a write command. If this bit
 *        is 0 QPM returns an OKAY response in all cases. By
 *        default QPM already returns an OKAY response for most
 *        error cases regardless of the setting of this bit.
 *        The only write errors which return SLVERR unless
 *        this bit is 1 are AXI protocol errors.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param en_slverr_rd </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Enable Slave Error Response on Read. If this bit is
 *        1, allows QPM to return a SLVERR response when errors
 *        occur on a read command. If this bit is 0 QPM returns
 *        an OKAY response in all cases.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param svc_pw </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Service Pulse Width. Specifies the width of the pulse
 *        generated on the service interrupt output when a service
 *        interrupt occurs. The width of the pulse is the number
 *        of clocks specified in this field plus 1.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param nsa_wr_en </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Non-secure Write Access Enable. If this bit is 1,
 *        nonsecure write accesses are enabled. Otherwise they
 *        are disabled.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param nsa_rd_en </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Non-secure Read Access Enable. If this bit is 1, nonsecure
 *        read accesses are enabled. Otherwise they are disabled.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_control_r_t
 *
 * Implemented by: 
 *      control_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 43;
     ncp_uint64_t    enab_tp_read                              :  1;
     ncp_uint64_t    dbg_write                                 :  1;
     ncp_uint64_t    dbg_read                                  :  1;
     ncp_uint64_t    cmp_smon_qacc                             :  1;
     ncp_uint64_t    cmp_smon_port                             :  1;
     ncp_uint64_t    cmp_smon_ms_qnum                          :  1;
     ncp_uint64_t    cmp_smon_qnum                             :  1;
     ncp_uint64_t    en_slverr_wr                              :  1;
     ncp_uint64_t    en_slverr_rd                              :  1;
     ncp_uint64_t    svc_pw                                    :  4;
     ncp_uint64_t    reserved1                                 :  6;
     ncp_uint64_t    nsa_wr_en                                 :  1;
     ncp_uint64_t    nsa_rd_en                                 :  1;
#else    /* Little Endian */
     ncp_uint64_t    nsa_rd_en                                 :  1;
     ncp_uint64_t    nsa_wr_en                                 :  1;
     ncp_uint64_t    reserved1                                 :  6;
     ncp_uint64_t    svc_pw                                    :  4;
     ncp_uint64_t    en_slverr_rd                              :  1;
     ncp_uint64_t    en_slverr_wr                              :  1;
     ncp_uint64_t    cmp_smon_qnum                             :  1;
     ncp_uint64_t    cmp_smon_ms_qnum                          :  1;
     ncp_uint64_t    cmp_smon_port                             :  1;
     ncp_uint64_t    cmp_smon_qacc                             :  1;
     ncp_uint64_t    dbg_read                                  :  1;
     ncp_uint64_t    dbg_write                                 :  1;
     ncp_uint64_t    enab_tp_read                              :  1;
     ncp_uint64_t    reserved0                                 : 43;
#endif
} ncp_qpm_control_r_t;

/*! @struct ncp_qpm_service_int_status_r_t
 *  @brief Service Interrupt Status Register
 *  @details Service Interrupt Status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_service_int_status_r_t\n
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
 *     <td width="20%" align="center"> 48 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param status </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Status for each interrupt queue. If a bit is 1 there
 *        are one or more pending interrupts in that queue waiting
 *        for service.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_service_int_status_r_t
 *
 * Implemented by: 
 *      status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 48;
     ncp_uint64_t    status                                    : 16;
#else    /* Little Endian */
     ncp_uint64_t    status                                    : 16;
     ncp_uint64_t    reserved0                                 : 48;
#endif
} ncp_qpm_service_int_status_r_t;

/*! @struct ncp_qpm_service_int_en_r_t
 *  @brief Service Interrupt Enable Register
 *  @details Service Interrupt Enable control
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_service_int_en_r_t\n
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
 *     <td width="20%" align="center"> 48 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param en </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Interrupt enable. If a bit is 1, that interrupt queue
 *        is allowed to signal (pulse) service interrupts. If
 *        a bit is 0 that interrupt queue is blocked from
 *        signalling interrupts. This does not affect the ability
 *        of the queue to accumulate interrupts or to have entries
 *        popped.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_service_int_en_r_t
 *
 * Implemented by: 
 *      en
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 48;
     ncp_uint64_t    en                                        : 16;
#else    /* Little Endian */
     ncp_uint64_t    en                                        : 16;
     ncp_uint64_t    reserved0                                 : 48;
#endif
} ncp_qpm_service_int_en_r_t;

/*! @struct ncp_qpm_service_int_frc_r_t
 *  @brief Service Interrupt Force Register
 *  @details Service Interrupt Force control
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_service_int_frc_r_t\n
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
 *     <td width="20%" align="center"> 48 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param frc </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Interrupt force. If a bit is written to 1, that queue
 *        will signal (pulse) a service request on the corresponding
 *        interrupt service pin, it the en bit is also 1.
 *        The force bit clears itself.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_service_int_frc_r_t
 *
 * Implemented by: 
 *      frc
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 48;
     ncp_uint64_t    frc                                       : 16;
#else    /* Little Endian */
     ncp_uint64_t    frc                                       : 16;
     ncp_uint64_t    reserved0                                 : 48;
#endif
} ncp_qpm_service_int_frc_r_t;

/*! @struct ncp_qpm_err_cntl_ecc_r_t
 *  @brief QPM ECC-Control-Register
 *  @details QPM Control Register For RAM's with ECC
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_err_cntl_ecc_r_t\n
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
 *     <td width="20%" align="center"> 35 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_fl_ecc_corr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Intq LL Free List RAM ECC Correction Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_hp_ecc_corr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Intq LL Head Ptr RAM ECC Correction Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_state_ecc_corr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> Intq LL State RAM ECC Correction Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param extask_info_ecc_corr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> Extask Info RAM ECC Correction Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ex_rptd_ecc_corr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Exception Reported RAM ECC Correction Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fl_ecc_corr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Free List RAM ECC Correction Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qem_ecc_corr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Queue Except Mask RAM ECC Correction Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param thresh_ecc_corr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Threshold RAM ECC Correction Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_ecc_corr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Count RAM ECC Correction Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param tp_ecc_corr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Tail Ptr RAM ECC Correction Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp_ecc_corr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Head Ptr RAM ECC Correction Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param lnk_ecc_corr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> Link RAM ECC Correction Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qm_ecc_corr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Queue RAM ECC Correction Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_fl_ecc_chk </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Intq LL Free List RAM ECC Check Enable Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_hp_ecc_chk </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Intq LL Head Ptr RAM ECC Check Enable Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_state_ecc_chk </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Intq LL State RAM ECC Check Enable Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param extask_info_ecc_chk </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> Extask Info RAM ECC Check Enable Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ex_rptd_ecc_chk </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Exception Reported RAM ECC Check Enable Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fl_ecc_chk </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Free List RAM ECC Check Enable Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qem_ecc_chk </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Queue Except Mask RAM ECC Check Enable Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param thresh_ecc_chk </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Threshold RAM ECC Check Enable Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_ecc_chk </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Count RAM ECC Check Enable Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param tp_ecc_chk </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Tail Ptr RAM ECC Check Enable Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp_ecc_chk </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Head Ptr RAM ECC Check Enable Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param lnk_ecc_chk </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Link RAM ECC Check Enable Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qm_ecc_chk </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Queue RAM ECC Check Enable Control bit </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_err_cntl_ecc_r_t
 *
 * Implemented by: 
 *      err_cntl_ecc_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 35;
     ncp_uint64_t    intq_fl_ecc_corr                          :  1;
     ncp_uint64_t    intq_hp_ecc_corr                          :  1;
     ncp_uint64_t    intq_state_ecc_corr                       :  1;
     ncp_uint64_t    extask_info_ecc_corr                      :  1;
     ncp_uint64_t    ex_rptd_ecc_corr                          :  1;
     ncp_uint64_t    fl_ecc_corr                               :  1;
     ncp_uint64_t    qem_ecc_corr                              :  1;
     ncp_uint64_t    thresh_ecc_corr                           :  1;
     ncp_uint64_t    cnt_ecc_corr                              :  1;
     ncp_uint64_t    tp_ecc_corr                               :  1;
     ncp_uint64_t    hp_ecc_corr                               :  1;
     ncp_uint64_t    lnk_ecc_corr                              :  1;
     ncp_uint64_t    qm_ecc_corr                               :  1;
     ncp_uint64_t    reserved1                                 :  3;
     ncp_uint64_t    intq_fl_ecc_chk                           :  1;
     ncp_uint64_t    intq_hp_ecc_chk                           :  1;
     ncp_uint64_t    intq_state_ecc_chk                        :  1;
     ncp_uint64_t    extask_info_ecc_chk                       :  1;
     ncp_uint64_t    ex_rptd_ecc_chk                           :  1;
     ncp_uint64_t    fl_ecc_chk                                :  1;
     ncp_uint64_t    qem_ecc_chk                               :  1;
     ncp_uint64_t    thresh_ecc_chk                            :  1;
     ncp_uint64_t    cnt_ecc_chk                               :  1;
     ncp_uint64_t    tp_ecc_chk                                :  1;
     ncp_uint64_t    hp_ecc_chk                                :  1;
     ncp_uint64_t    lnk_ecc_chk                               :  1;
     ncp_uint64_t    qm_ecc_chk                                :  1;
#else    /* Little Endian */
     ncp_uint64_t    qm_ecc_chk                                :  1;
     ncp_uint64_t    lnk_ecc_chk                               :  1;
     ncp_uint64_t    hp_ecc_chk                                :  1;
     ncp_uint64_t    tp_ecc_chk                                :  1;
     ncp_uint64_t    cnt_ecc_chk                               :  1;
     ncp_uint64_t    thresh_ecc_chk                            :  1;
     ncp_uint64_t    qem_ecc_chk                               :  1;
     ncp_uint64_t    fl_ecc_chk                                :  1;
     ncp_uint64_t    ex_rptd_ecc_chk                           :  1;
     ncp_uint64_t    extask_info_ecc_chk                       :  1;
     ncp_uint64_t    intq_state_ecc_chk                        :  1;
     ncp_uint64_t    intq_hp_ecc_chk                           :  1;
     ncp_uint64_t    intq_fl_ecc_chk                           :  1;
     ncp_uint64_t    reserved1                                 :  3;
     ncp_uint64_t    qm_ecc_corr                               :  1;
     ncp_uint64_t    lnk_ecc_corr                              :  1;
     ncp_uint64_t    hp_ecc_corr                               :  1;
     ncp_uint64_t    tp_ecc_corr                               :  1;
     ncp_uint64_t    cnt_ecc_corr                              :  1;
     ncp_uint64_t    thresh_ecc_corr                           :  1;
     ncp_uint64_t    qem_ecc_corr                              :  1;
     ncp_uint64_t    fl_ecc_corr                               :  1;
     ncp_uint64_t    ex_rptd_ecc_corr                          :  1;
     ncp_uint64_t    extask_info_ecc_corr                      :  1;
     ncp_uint64_t    intq_state_ecc_corr                       :  1;
     ncp_uint64_t    intq_hp_ecc_corr                          :  1;
     ncp_uint64_t    intq_fl_ecc_corr                          :  1;
     ncp_uint64_t    reserved0                                 : 35;
#endif
} ncp_qpm_err_cntl_ecc_r_t;

/*! @struct ncp_qpm_err_inj_ecc_r_t
 *  @brief QPM ECC-Error-Inject-Register
 *  @details QPM ECC Error Injection Control Register For RAM's with ECC
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_err_inj_ecc_r_t\n
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
 *     <td width="20%" align="center"> 35 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_fl_inj_mb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Intq LL Free List RAM ECC MB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_hp_inj_mb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Intq LL Head Ptr RAM ECC MB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_state_inj_mb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> Intq LL State RAM ECC MB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param extask_info_inj_mb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> Extask Info State RAM ECC MB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ex_rptd_inj_mb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Exception Reported RAM ECC MB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fl_inj_mb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Free List RAM ECC MB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qem_inj_mb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Queue Except Mask RAM ECC MB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param thresh_inj_mb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Threshold RAM ECC MB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_inj_mb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Cnt RAM ECC MB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param tp_inj_mb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Tail Ptr RAM ECC MB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp_inj_mb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Head Ptr RAM ECC MB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param lnk_inj_mb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> Link RAM ECC MB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qm_inj_mb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Queue RAM ECC MB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_fl_inj_sb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Intq LL Free List RAM ECC SB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_hp_inj_sb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Intq LL Head Ptr RAM ECC SB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_state_inj_sb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Intq LL State RAM ECC SB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param extask_info_inj_sb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> Extask Info State RAM ECC SB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ex_rptd_inj_sb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Exception Reported RAM ECC SB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fl_inj_sb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Free List RAM ECC SB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qem_inj_sb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Queue Except Mask RAM ECC SB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param thresh_inj_sb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Threshold RAM ECC SB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_inj_sb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Cnt RAM ECC SB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param tp_inj_sb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Tail Ptr RAM ECC SB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp_inj_sb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Head Ptr RAM ECC SB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param lnk_inj_sb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Link RAM ECC SB Inject Control bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qm_inj_sb </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Queue RAM ECC SB Inject Control bit </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_err_inj_ecc_r_t
 *
 * Implemented by: 
 *      err_inj_ecc_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 35;
     ncp_uint64_t    intq_fl_inj_mb                            :  1;
     ncp_uint64_t    intq_hp_inj_mb                            :  1;
     ncp_uint64_t    intq_state_inj_mb                         :  1;
     ncp_uint64_t    extask_info_inj_mb                        :  1;
     ncp_uint64_t    ex_rptd_inj_mb                            :  1;
     ncp_uint64_t    fl_inj_mb                                 :  1;
     ncp_uint64_t    qem_inj_mb                                :  1;
     ncp_uint64_t    thresh_inj_mb                             :  1;
     ncp_uint64_t    cnt_inj_mb                                :  1;
     ncp_uint64_t    tp_inj_mb                                 :  1;
     ncp_uint64_t    hp_inj_mb                                 :  1;
     ncp_uint64_t    lnk_inj_mb                                :  1;
     ncp_uint64_t    qm_inj_mb                                 :  1;
     ncp_uint64_t    reserved1                                 :  3;
     ncp_uint64_t    intq_fl_inj_sb                            :  1;
     ncp_uint64_t    intq_hp_inj_sb                            :  1;
     ncp_uint64_t    intq_state_inj_sb                         :  1;
     ncp_uint64_t    extask_info_inj_sb                        :  1;
     ncp_uint64_t    ex_rptd_inj_sb                            :  1;
     ncp_uint64_t    fl_inj_sb                                 :  1;
     ncp_uint64_t    qem_inj_sb                                :  1;
     ncp_uint64_t    thresh_inj_sb                             :  1;
     ncp_uint64_t    cnt_inj_sb                                :  1;
     ncp_uint64_t    tp_inj_sb                                 :  1;
     ncp_uint64_t    hp_inj_sb                                 :  1;
     ncp_uint64_t    lnk_inj_sb                                :  1;
     ncp_uint64_t    qm_inj_sb                                 :  1;
#else    /* Little Endian */
     ncp_uint64_t    qm_inj_sb                                 :  1;
     ncp_uint64_t    lnk_inj_sb                                :  1;
     ncp_uint64_t    hp_inj_sb                                 :  1;
     ncp_uint64_t    tp_inj_sb                                 :  1;
     ncp_uint64_t    cnt_inj_sb                                :  1;
     ncp_uint64_t    thresh_inj_sb                             :  1;
     ncp_uint64_t    qem_inj_sb                                :  1;
     ncp_uint64_t    fl_inj_sb                                 :  1;
     ncp_uint64_t    ex_rptd_inj_sb                            :  1;
     ncp_uint64_t    extask_info_inj_sb                        :  1;
     ncp_uint64_t    intq_state_inj_sb                         :  1;
     ncp_uint64_t    intq_hp_inj_sb                            :  1;
     ncp_uint64_t    intq_fl_inj_sb                            :  1;
     ncp_uint64_t    reserved1                                 :  3;
     ncp_uint64_t    qm_inj_mb                                 :  1;
     ncp_uint64_t    lnk_inj_mb                                :  1;
     ncp_uint64_t    hp_inj_mb                                 :  1;
     ncp_uint64_t    tp_inj_mb                                 :  1;
     ncp_uint64_t    cnt_inj_mb                                :  1;
     ncp_uint64_t    thresh_inj_mb                             :  1;
     ncp_uint64_t    qem_inj_mb                                :  1;
     ncp_uint64_t    fl_inj_mb                                 :  1;
     ncp_uint64_t    ex_rptd_inj_mb                            :  1;
     ncp_uint64_t    extask_info_inj_mb                        :  1;
     ncp_uint64_t    intq_state_inj_mb                         :  1;
     ncp_uint64_t    intq_hp_inj_mb                            :  1;
     ncp_uint64_t    intq_fl_inj_mb                            :  1;
     ncp_uint64_t    reserved0                                 : 35;
#endif
} ncp_qpm_err_inj_ecc_r_t;

/*! @struct ncp_qpm_err_cntl_parity_r_t
 *  @brief QPM Parity-Control-Register
 *  @details QPM Control Register For RAM's with Parity
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_err_cntl_parity_r_t\n
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
 *     <td width="20%" align="center"> 58 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param minqd_parity_chk </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Min-Queue-Depth-Ram Parity Check-Enable Control-bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_d_parity_chk </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Intq LL Data Ram Parity Check-Enable Control-bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param maxqd_parity_chk </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Max-Queue-Depth-Ram Parity Check-Enable Control-bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param peq_parity_chk </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Pop-Empty-Queue-Ram Parity Check-Enable Control-bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pnq_parity_chk </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Pop-NonEmpty-Queue-Ram Parity Check-Enable Control-bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param adq_parity_chk </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Adds-To-Queue-Ram Parity Check-Enable Control-bit </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_err_cntl_parity_r_t
 *
 * Implemented by: 
 *      err_cntl_parity_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 58;
     ncp_uint64_t    minqd_parity_chk                          :  1;
     ncp_uint64_t    intq_d_parity_chk                         :  1;
     ncp_uint64_t    maxqd_parity_chk                          :  1;
     ncp_uint64_t    peq_parity_chk                            :  1;
     ncp_uint64_t    pnq_parity_chk                            :  1;
     ncp_uint64_t    adq_parity_chk                            :  1;
#else    /* Little Endian */
     ncp_uint64_t    adq_parity_chk                            :  1;
     ncp_uint64_t    pnq_parity_chk                            :  1;
     ncp_uint64_t    peq_parity_chk                            :  1;
     ncp_uint64_t    maxqd_parity_chk                          :  1;
     ncp_uint64_t    intq_d_parity_chk                         :  1;
     ncp_uint64_t    minqd_parity_chk                          :  1;
     ncp_uint64_t    reserved0                                 : 58;
#endif
} ncp_qpm_err_cntl_parity_r_t;

/*! @struct ncp_qpm_err_inj_parity_r_t
 *  @brief QPM Parity-Error-Inject-Register
 *  @details QPM Parity Error Injection Control Register For RAM's with Parity
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_err_inj_parity_r_t\n
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
 *     <td width="20%" align="center"> 58 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param minqd_inj_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Min-Queue-Depth-Ram Parity-Error-Inject Control-bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_d_inj_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Intq LL Data Ram Parity-Error-Inject Control-bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param maxqd_inj_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Max-Queue-Depth-Ram Parity-Error-Inject Control-bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param peq_inj_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Pop-Empty-Queue-Ram Parity-Error-Inject Control-bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pnq_inj_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Pop-NonEmpty-Queue-Ram Parity-Error-Inject Control-bit </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param adq_inj_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Adds-To-Queue-Ram Parity-Error-Inject Control-bit </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_err_inj_parity_r_t
 *
 * Implemented by: 
 *      err_inj_parity_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 58;
     ncp_uint64_t    minqd_inj_parity_err                      :  1;
     ncp_uint64_t    intq_d_inj_parity_err                     :  1;
     ncp_uint64_t    maxqd_inj_parity_err                      :  1;
     ncp_uint64_t    peq_inj_parity_err                        :  1;
     ncp_uint64_t    pnq_inj_parity_err                        :  1;
     ncp_uint64_t    adq_inj_parity_err                        :  1;
#else    /* Little Endian */
     ncp_uint64_t    adq_inj_parity_err                        :  1;
     ncp_uint64_t    pnq_inj_parity_err                        :  1;
     ncp_uint64_t    peq_inj_parity_err                        :  1;
     ncp_uint64_t    maxqd_inj_parity_err                      :  1;
     ncp_uint64_t    intq_d_inj_parity_err                     :  1;
     ncp_uint64_t    minqd_inj_parity_err                      :  1;
     ncp_uint64_t    reserved0                                 : 58;
#endif
} ncp_qpm_err_inj_parity_r_t;

/*! @struct ncp_qpm_max_qaddr_r_t
 *  @brief qpm_max_qaddr_r
 *  @details Maximum event queue address to use
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_max_qaddr_r_t\n
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
 *     <td width="20%" align="center"> 50 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_max_qaddr </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Maximum event queue address to use. The number of
 *        queue addresses may only be specified in units of
 *        64, so the ls 6 bits of this register are internally
 *        treated as 6'h3f. This value specifies the maximum
 *        queue address to use. For example, if this field
 *        is set to 3, the maximum address will be 0xff, meaning
 *        there are 0x100 addresses supported - 0 through 0xff.
 *        When the number of addresses is reduced in this manner,
 *        the actual addresses excluded are those at the least
 *        significant end of the memories, starting at address
 *        0.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_max_qaddr_r_t
 *
 * Implemented by: 
 *      qpm_max_qaddr_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 50;
     ncp_uint64_t    qpm_max_qaddr                             :  8;
     ncp_uint64_t    reserved1                                 :  6;
#else    /* Little Endian */
     ncp_uint64_t    reserved1                                 :  6;
     ncp_uint64_t    qpm_max_qaddr                             :  8;
     ncp_uint64_t    reserved0                                 : 50;
#endif
} ncp_qpm_max_qaddr_r_t;

/*! @struct ncp_qpm_max_val_r_t
 *  @brief qpm_max_val_r
 *  @details Maximum event queue number to use.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_max_val_r_t\n
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
 *     <td width="20%" align="center"> 49 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_max_val </td>
 *     <td width="20%" align="center"> 9 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Maximum event queue number to use. The number of queues
 *        may only be specified in units of 64, so the ls 6
 *        bits of this register are internally treated as 6'h3f.
 *        This value specifies the maximum queue number to
 *        use. For example, if this field is set to 3, the maximum
 *        queue number will be 0xff, meaning there are 0x100
 *        queues supported - 0 through 0xff. When the number
 *        of queues is reduced in this manner, the actual queues
 *        excluded are those at the least significant end of
 *        the memories, starting at address 0.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_max_val_r_t
 *
 * Implemented by: 
 *      qpm_max_val_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 49;
     ncp_uint64_t    qpm_max_val                               :  9;
     ncp_uint64_t    reserved1                                 :  6;
#else    /* Little Endian */
     ncp_uint64_t    reserved1                                 :  6;
     ncp_uint64_t    qpm_max_val                               :  9;
     ncp_uint64_t    reserved0                                 : 49;
#endif
} ncp_qpm_max_val_r_t;

/*! @struct ncp_qpm_cfg_ram_cntl_r_t
 *  @brief QPM-RAM-Power-Control
 *  @details ram power-control enables.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_cfg_ram_cntl_r_t\n
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
 *     <td width="20%" align="center"> 61 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_sd </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> qpm_shut_down </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_ds </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> qpm_deep_sleep </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_ls </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> qpm_lite_sleep </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_cfg_ram_cntl_r_t
 *
 * Implemented by: 
 *      cfg_ram_cntl_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 61;
     ncp_uint64_t    qpm_sd                                    :  1;
     ncp_uint64_t    qpm_ds                                    :  1;
     ncp_uint64_t    qpm_ls                                    :  1;
#else    /* Little Endian */
     ncp_uint64_t    qpm_ls                                    :  1;
     ncp_uint64_t    qpm_ds                                    :  1;
     ncp_uint64_t    qpm_sd                                    :  1;
     ncp_uint64_t    reserved0                                 : 61;
#endif
} ncp_qpm_cfg_ram_cntl_r_t;

/*! @struct ncp_qpm_thresh_init_val_ls_r_t
 *  @brief QPM Threshold Initialize Value Least Significant Register
 *  @details Threshold initialize value register, least significant bits.  This value will be written to the least significant bits (31:0) of the
	threshold memory when the init_thc bit of the init register is set.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_thresh_init_val_ls_r_t\n
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
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param thresh_ls </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Threshold RAM initial value, least-significant bits </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_thresh_init_val_ls_r_t
 *
 * Implemented by: 
 *      thresh_init_val_ls_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 32;
     ncp_uint64_t    thresh_ls                                 : 32;
#else    /* Little Endian */
     ncp_uint64_t    thresh_ls                                 : 32;
     ncp_uint64_t    reserved0                                 : 32;
#endif
} ncp_qpm_thresh_init_val_ls_r_t;

/*! @struct ncp_qpm_thresh_init_val_ms_r_t
 *  @brief QPM Threshold Initialize Value Most Significant Register
 *  @details Threshold initialize value register, most significant bits.  This value will be written to the most significant bits (31:0) of the
	threshold memory when the init_thc bit of the init register is set.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_thresh_init_val_ms_r_t\n
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
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param thresh_ms </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Threshold RAM initial value, most-significant bits </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_thresh_init_val_ms_r_t
 *
 * Implemented by: 
 *      thresh_init_val_ms_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 32;
     ncp_uint64_t    thresh_ms                                 : 32;
#else    /* Little Endian */
     ncp_uint64_t    thresh_ms                                 : 32;
     ncp_uint64_t    reserved0                                 : 32;
#endif
} ncp_qpm_thresh_init_val_ms_r_t;

/*! @struct ncp_qpm_cfg_ia_arb_mode_r_t
 *  @brief Input-Arbiter Mode-Control
 *  @details Mode-Control for Port-Selection Arbiter.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_cfg_ia_arb_mode_r_t\n
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
 *     <td width="20%" align="center"> 62 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ia_port_sel </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Mode-Control for Port-Selection Arbiter. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_cfg_ia_arb_mode_r_t
 *
 * Implemented by: 
 *      cfg_ia_arb_mode_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 62;
     ncp_uint64_t    ia_port_sel                               :  2;
#else    /* Little Endian */
     ncp_uint64_t    ia_port_sel                               :  2;
     ncp_uint64_t    reserved0                                 : 62;
#endif
} ncp_qpm_cfg_ia_arb_mode_r_t;

/*! @struct ncp_qpm_qstatus_delta_loc_r_t
 *  @brief qstatus delta
 *  @details Delta value used when calculating a queue's 'full' status as indicated on the qstatus output.  This value is subtracted from
	the queue's full threshold when comparing with the actual count for the full status.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_qstatus_delta_loc_r_t\n
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
 *     <td width="20%" align="center"> 48 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param delta </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> delta. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_qstatus_delta_loc_r_t
 *
 * Implemented by: 
 *      qstatus_delta_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 48;
     ncp_uint64_t    delta                                     : 16;
#else    /* Little Endian */
     ncp_uint64_t    delta                                     : 16;
     ncp_uint64_t    reserved0                                 : 48;
#endif
} ncp_qpm_qstatus_delta_loc_r_t;

/*! @struct ncp_qpm_qstatus_global_delta_r_t
 *  @brief qstatus global_delta
 *  @details Delta value used when calculating a global free list empty condition as indicated on the qstatus output.  This value is compared to the
	free list available count to determine the free list empty status.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_qstatus_global_delta_r_t\n
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
 *     <td width="20%" align="center"> 48 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param delta </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> delta. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_qstatus_global_delta_r_t
 *
 * Implemented by: 
 *      qstatus_global_delta_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 48;
     ncp_uint64_t    delta                                     : 16;
#else    /* Little Endian */
     ncp_uint64_t    delta                                     : 16;
     ncp_uint64_t    reserved0                                 : 48;
#endif
} ncp_qpm_qstatus_global_delta_r_t;

/*! @struct ncp_qpm_qm_totPushed_r_t
 *  @brief Total number of event queue pushes
 *  @details Total number of event queue pushes.
	Note: Configuration register reads which require multiple beats are not atomic. If a configuration read of this register
	is performed with a bus width less than 64 bits, the data returned during the multiple beats will not necessarily reflect the
	value of the entire register from any one point in time.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_qm_totPushed_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param totpushed </td>
 *     <td width="20%" align="center"> 64 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Total number of event queue pushes. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_qm_totPushed_r_t
 *
 * Implemented by: 
 *      qm_totPushed_reg
 */
 
typedef struct
{
     ncp_uint64_t                  totpushed;
} ncp_qpm_qm_totPushed_r_t;

/*! @struct ncp_qpm_qm_totPopped_r_t
 *  @brief Total number of event queue pops
 *  @details Total number of event queue pops.
	Note: Configuration register reads which require multiple beats are not atomic. If a configuration read of this register
	is performed with a bus width less than 64 bits, the data returned during the multiple beats will not necessarily reflect the
	value of the entire register from any one point in time.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_qm_totPopped_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param totpopped </td>
 *     <td width="20%" align="center"> 64 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Total number of event queue pops </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_qm_totPopped_r_t
 *
 * Implemented by: 
 *      qm_totPopped_reg
 */
 
typedef struct
{
     ncp_uint64_t                  totpopped;
} ncp_qpm_qm_totPopped_r_t;

/*! @struct ncp_qpm_qm_totQm_r_t
 *  @brief QM Total number of entries
 *  @details Total number of entries in the QM.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_qm_totQm_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param totqm </td>
 *     <td width="20%" align="center"> 64 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Total number of entries in the QM. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_qm_totQm_r_t
 *
 * Implemented by: 
 *      qm_totQm_reg
 */
 
typedef struct
{
     ncp_uint64_t                      totqm;
} ncp_qpm_qm_totQm_r_t;

/*! @struct ncp_qpm_qm_totDropped_r_t
 *  @brief Total number of event queue drops.
 *  @details Total number of event queue drops: attempts to push items to an event queue which were not executed because either the
	event queue was full or the free list was empty.
	Note: Configuration register reads which require multiple beats are not atomic. If a configuration read of this register
	is performed with a bus width less than 64 bits, the data returned during the multiple beats will not necessarily reflect the
	value of the entire register from any one point in time.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_qm_totDropped_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param totdropped </td>
 *     <td width="20%" align="center"> 64 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Total number of event queue drops </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_qm_totDropped_r_t
 *
 * Implemented by: 
 *      qm_totDropped_reg
 */
 
typedef struct
{
     ncp_uint64_t                 totdropped;
} ncp_qpm_qm_totDropped_r_t;

/*! @struct ncp_qpm_qm_totFree_r_t
 *  @brief QPM Total number of free list entries
 *  @details Total number of available free list entries
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_qm_totFree_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param totfree </td>
 *     <td width="20%" align="center"> 64 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Total number of available free list entries </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_qm_totFree_r_t
 *
 * Implemented by: 
 *      qm_totFree_reg
 */
 
typedef struct
{
     ncp_uint64_t                    totfree;
} ncp_qpm_qm_totFree_r_t;

/*! @struct ncp_qpm_fl_free_count_r_t
 *  @brief FLC free list count
 *  @details Free list count managed by FLC.  When initialized and idle should equal qm_totFree
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_fl_free_count_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param totfree </td>
 *     <td width="20%" align="center"> 64 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Total number of available free list entries according
 *        to FLC
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_fl_free_count_r_t
 *
 * Implemented by: 
 *      fl_free_count_reg
 */
 
typedef struct
{
     ncp_uint64_t                    totfree;
} ncp_qpm_fl_free_count_r_t;

/*! @struct ncp_qpm_sticky_hw_err_r_t
 *  @brief QPM Hardware Error Sticky Register
 *  @details AXI information for the request which experienced a hardware error
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_sticky_hw_err_r_t\n
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
 *     <td width="20%" align="center"> 41 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param port </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> AXI port number of request. 0 = write port 1, 1 =
 *        write port 0, 2 = read port
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param addr </td>
 *     <td width="20%" align="center"> 21 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> AXI address [23:3] of request. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_sticky_hw_err_r_t
 *
 * Implemented by: 
 *      sticky_hw_err_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 41;
     ncp_uint64_t    port                                      :  2;
     ncp_uint64_t    addr                                      : 21;
#else    /* Little Endian */
     ncp_uint64_t    addr                                      : 21;
     ncp_uint64_t    port                                      :  2;
     ncp_uint64_t    reserved0                                 : 41;
#endif
} ncp_qpm_sticky_hw_err_r_t;

/*! @struct ncp_qpm_sticky_icf_cnt_r_t
 *  @brief QPM Integrity Check Failure Count Sticky Register
 *  @details Contains event queue count when an Integrity Check Failure occurs
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_sticky_icf_cnt_r_t\n
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
 *     <td width="20%" align="center"> 49 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param count </td>
 *     <td width="20%" align="center"> 15 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Queue count </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_sticky_icf_cnt_r_t
 *
 * Implemented by: 
 *      sticky_icf_cnt_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 49;
     ncp_uint64_t    count                                     : 15;
#else    /* Little Endian */
     ncp_uint64_t    count                                     : 15;
     ncp_uint64_t    reserved0                                 : 49;
#endif
} ncp_qpm_sticky_icf_cnt_r_t;

/*! @struct ncp_qpm_sticky_icf_tp_r_t
 *  @brief QPM Integrity Check Failure Tail Pointer Sticky Register
 *  @details Contains tail pointer value when an Integrity Check Failure occurs
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_sticky_icf_tp_r_t\n
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
 *     <td width="20%" align="center"> 50 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param tp </td>
 *     <td width="20%" align="center"> 14 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Tail pointer </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_sticky_icf_tp_r_t
 *
 * Implemented by: 
 *      sticky_icf_tp_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 50;
     ncp_uint64_t    tp                                        : 14;
#else    /* Little Endian */
     ncp_uint64_t    tp                                        : 14;
     ncp_uint64_t    reserved0                                 : 50;
#endif
} ncp_qpm_sticky_icf_tp_r_t;

/*! @struct ncp_qpm_sticky_icf_hp_r_t
 *  @brief QPM Integrity Check Failure Head Pointer Sticky Register
 *  @details Contains head pointer value when an Integrity Check Failure occurs
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_sticky_icf_hp_r_t\n
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
 *     <td width="20%" align="center"> 50 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp </td>
 *     <td width="20%" align="center"> 14 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Head pointer </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_sticky_icf_hp_r_t
 *
 * Implemented by: 
 *      sticky_icf_hp_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 50;
     ncp_uint64_t    hp                                        : 14;
#else    /* Little Endian */
     ncp_uint64_t    hp                                        : 14;
     ncp_uint64_t    reserved0                                 : 50;
#endif
} ncp_qpm_sticky_icf_hp_r_t;

/*! @struct ncp_qpm_sticky_intq_err_r_t
 *  @brief QPM Interrupt Queue Linked List Sticky Error Register
 *  @details Vector indicating which type of error(s) occurred in the Interrupt Queue Linked List.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_sticky_intq_err_r_t\n
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
 *     <td width="20%" align="center"> 56 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ll_err_spare </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Unused </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param del_empty_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Interrupt Queue LL attempted to delete an entry from
 *        a queue which was empty (count=0)
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param del_inv_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Interrupt Queue LL attempted to delete an entry from
 *        a queue which was invalid
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param del_busy_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Interrupt Queue LL attempted to delete an entry from
 *        a queue which was busy
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param alloc_busy_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Interrupt Queue LL attempted to allocate an entry
 *        in a queue which was busy
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param req_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Interrupt Queue LL attempted to allocate and delete
 *        an entry to/from a queue on the same clock
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param del_all_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Interrupt Queue LL attempted to delete an entry when
 *        the total size of all interrupt queues was 0
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param alloc_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Interrupt Queue LL attempted to allocate an entry
 *        in a queue which was already full
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_sticky_intq_err_r_t
 *
 * Implemented by: 
 *      sticky_intq_err_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 56;
     ncp_uint64_t    ll_err_spare                              :  1;
     ncp_uint64_t    del_empty_err                             :  1;
     ncp_uint64_t    del_inv_err                               :  1;
     ncp_uint64_t    del_busy_err                              :  1;
     ncp_uint64_t    alloc_busy_err                            :  1;
     ncp_uint64_t    req_err                                   :  1;
     ncp_uint64_t    del_all_err                               :  1;
     ncp_uint64_t    alloc_err                                 :  1;
#else    /* Little Endian */
     ncp_uint64_t    alloc_err                                 :  1;
     ncp_uint64_t    del_all_err                               :  1;
     ncp_uint64_t    req_err                                   :  1;
     ncp_uint64_t    alloc_busy_err                            :  1;
     ncp_uint64_t    del_busy_err                              :  1;
     ncp_uint64_t    del_inv_err                               :  1;
     ncp_uint64_t    del_empty_err                             :  1;
     ncp_uint64_t    ll_err_spare                              :  1;
     ncp_uint64_t    reserved0                                 : 56;
#endif
} ncp_qpm_sticky_intq_err_r_t;

/*! @struct ncp_qpm_sticky_of_cond_r_t
 *  @brief QPM Event Queue Overflow Sticky Register
 *  @details AXI information for the request which experienced an event queue overflow
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_sticky_of_cond_r_t\n
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
 *     <td width="20%" align="center"> 41 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param port </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> AXI port number of request. 0 = write port 1, 1 =
 *        write port 0, 2 = read port
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param addr </td>
 *     <td width="20%" align="center"> 21 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> AXI address [23:3] of request. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_sticky_of_cond_r_t
 *
 * Implemented by: 
 *      sticky_of_cond_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 41;
     ncp_uint64_t    port                                      :  2;
     ncp_uint64_t    addr                                      : 21;
#else    /* Little Endian */
     ncp_uint64_t    addr                                      : 21;
     ncp_uint64_t    port                                      :  2;
     ncp_uint64_t    reserved0                                 : 41;
#endif
} ncp_qpm_sticky_of_cond_r_t;

/*! @struct ncp_qpm_sticky_uf_cond_r_t
 *  @brief QPM Event Queue Underflow Sticky Register
 *  @details AXI information for the request which experienced an event queue underflow
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_sticky_uf_cond_r_t\n
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
 *     <td width="20%" align="center"> 41 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param port </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> AXI port number of request. 0 = write port 1, 1 =
 *        write port 0, 2 = read port
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param addr </td>
 *     <td width="20%" align="center"> 21 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> AXI address [23:3] of request. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_sticky_uf_cond_r_t
 *
 * Implemented by: 
 *      sticky_uf_cond_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 41;
     ncp_uint64_t    port                                      :  2;
     ncp_uint64_t    addr                                      : 21;
#else    /* Little Endian */
     ncp_uint64_t    addr                                      : 21;
     ncp_uint64_t    port                                      :  2;
     ncp_uint64_t    reserved0                                 : 41;
#endif
} ncp_qpm_sticky_uf_cond_r_t;

/*! @struct ncp_qpm_sticky_fl_uf_cond_r_t
 *  @brief QPM Free List Underflow Sticky Register
 *  @details AXI information for the request which experienced a Free List underflow
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_sticky_fl_uf_cond_r_t\n
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
 *     <td width="20%" align="center"> 41 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param port </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> AXI port number of request. 0 = write port 1, 1 =
 *        write port 0, 2 = read port
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param addr </td>
 *     <td width="20%" align="center"> 21 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> AXI address [23:3] of request. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_sticky_fl_uf_cond_r_t
 *
 * Implemented by: 
 *      sticky_fl_uf_cond_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 41;
     ncp_uint64_t    port                                      :  2;
     ncp_uint64_t    addr                                      : 21;
#else    /* Little Endian */
     ncp_uint64_t    addr                                      : 21;
     ncp_uint64_t    port                                      :  2;
     ncp_uint64_t    reserved0                                 : 41;
#endif
} ncp_qpm_sticky_fl_uf_cond_r_t;

/*! @struct ncp_qpm_sticky_sw_err_r_t
 *  @brief QPM Software Error Sticky Register
 *  @details AXI information for the request which experienced a software error
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_sticky_sw_err_r_t\n
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
 *     <td width="20%" align="center"> 41 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param port </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> AXI port number of request. 0 = write port 1, 1 =
 *        write port 0, 2 = read port
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param addr </td>
 *     <td width="20%" align="center"> 21 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> AXI address [23:3] of request. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_sticky_sw_err_r_t
 *
 * Implemented by: 
 *      sticky_sw_err_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 41;
     ncp_uint64_t    port                                      :  2;
     ncp_uint64_t    addr                                      : 21;
#else    /* Little Endian */
     ncp_uint64_t    addr                                      : 21;
     ncp_uint64_t    port                                      :  2;
     ncp_uint64_t    reserved0                                 : 41;
#endif
} ncp_qpm_sticky_sw_err_r_t;

/*! @struct ncp_qpm_sticky_misconfig_r_t
 *  @brief QPM Misconfigured Queue Sticky Register
 *  @details AXI information for the request which accessed an event queue which was misconfigured.  This occurs when 'delta' register
	which is selected for the event queue is greater than or equal to the queue's full threshold.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_sticky_misconfig_r_t\n
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
 *     <td width="20%" align="center"> 41 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param port </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> AXI port number of request. 0 = write port 1, 1 =
 *        write port 0, 2 = read port
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param addr </td>
 *     <td width="20%" align="center"> 21 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> AXI address [23:3] of request. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_sticky_misconfig_r_t
 *
 * Implemented by: 
 *      sticky_misconfig_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 41;
     ncp_uint64_t    port                                      :  2;
     ncp_uint64_t    addr                                      : 21;
#else    /* Little Endian */
     ncp_uint64_t    addr                                      : 21;
     ncp_uint64_t    port                                      :  2;
     ncp_uint64_t    reserved0                                 : 41;
#endif
} ncp_qpm_sticky_misconfig_r_t;

/*! @struct ncp_qpm_sticky_empty_cond_r_t
 *  @brief QPM Event Queue Empty Condition Sticky Register
 *  @details AXI information for the request which experienced an event queue empty condition
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_sticky_empty_cond_r_t\n
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
 *     <td width="20%" align="center"> 41 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param port </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> AXI port number of request. 0 = write port 1, 1 =
 *        write port 0, 2 = read port
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param addr </td>
 *     <td width="20%" align="center"> 21 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> AXI address [23:3] of request. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_sticky_empty_cond_r_t
 *
 * Implemented by: 
 *      sticky_empty_cond_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 41;
     ncp_uint64_t    port                                      :  2;
     ncp_uint64_t    addr                                      : 21;
#else    /* Little Endian */
     ncp_uint64_t    addr                                      : 21;
     ncp_uint64_t    port                                      :  2;
     ncp_uint64_t    reserved0                                 : 41;
#endif
} ncp_qpm_sticky_empty_cond_r_t;

/*! @struct ncp_qpm_sticky_aempty_cond_r_t
 *  @brief QPM Event Queue Almost Empty Condition Sticky Register
 *  @details AXI information for the request which experienced an event queue almost empty condition
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_sticky_aempty_cond_r_t\n
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
 *     <td width="20%" align="center"> 41 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param port </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> AXI port number of request. 0 = write port 1, 1 =
 *        write port 0, 2 = read port
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param addr </td>
 *     <td width="20%" align="center"> 21 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> AXI address [23:3] of request. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_sticky_aempty_cond_r_t
 *
 * Implemented by: 
 *      sticky_aempty_cond_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 41;
     ncp_uint64_t    port                                      :  2;
     ncp_uint64_t    addr                                      : 21;
#else    /* Little Endian */
     ncp_uint64_t    addr                                      : 21;
     ncp_uint64_t    port                                      :  2;
     ncp_uint64_t    reserved0                                 : 41;
#endif
} ncp_qpm_sticky_aempty_cond_r_t;

/*! @struct ncp_qpm_sticky_afull_cond_r_t
 *  @brief QPM Event Queue Almost Full Condition Sticky Register
 *  @details AXI information for the request which experienced an event queue almost full condition
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_sticky_afull_cond_r_t\n
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
 *     <td width="20%" align="center"> 41 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param port </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> AXI port number of request. 0 = write port 1, 1 =
 *        write port 0, 2 = read port
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param addr </td>
 *     <td width="20%" align="center"> 21 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> AXI address [23:3] of request. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_sticky_afull_cond_r_t
 *
 * Implemented by: 
 *      sticky_afull_cond_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 41;
     ncp_uint64_t    port                                      :  2;
     ncp_uint64_t    addr                                      : 21;
#else    /* Little Endian */
     ncp_uint64_t    addr                                      : 21;
     ncp_uint64_t    port                                      :  2;
     ncp_uint64_t    reserved0                                 : 41;
#endif
} ncp_qpm_sticky_afull_cond_r_t;

/*! @struct ncp_qpm_sticky_full_cond_r_t
 *  @brief QPM Event Queue Full Condition Sticky Register
 *  @details AXI information for the request which experienced an event queue full condition
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_sticky_full_cond_r_t\n
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
 *     <td width="20%" align="center"> 41 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param port </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> AXI port number of request. 0 = write port 1, 1 =
 *        write port 0, 2 = read port
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param addr </td>
 *     <td width="20%" align="center"> 21 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> AXI address [23:3] of request. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_sticky_full_cond_r_t
 *
 * Implemented by: 
 *      sticky_full_cond_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 41;
     ncp_uint64_t    port                                      :  2;
     ncp_uint64_t    addr                                      : 21;
#else    /* Little Endian */
     ncp_uint64_t    addr                                      : 21;
     ncp_uint64_t    port                                      :  2;
     ncp_uint64_t    reserved0                                 : 41;
#endif
} ncp_qpm_sticky_full_cond_r_t;

/*! @struct ncp_qpm_sticky_parity_r_t
 *  @brief QPM Sticky Parity-Error Register
 *  @details Vector indicating which specific parity error(s) occurred.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_sticky_parity_r_t\n
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
 *     <td width="20%" align="center"> 58 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param minqd_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Min-Queue-Depth RAM Parity Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_d_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Intq LL Data RAM Parity Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param maxqd_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Max-Queue-Depth RAM Parity Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param peq_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Pop-Empty-Queue RAM Parity Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pnq_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Pop-NonEmpty-Queue RAM Parity Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param adq_parity_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Adds-To-Queue RAM Parity Error </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_sticky_parity_r_t
 *
 * Implemented by: 
 *      sticky_parity_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 58;
     ncp_uint64_t    minqd_parity_err                          :  1;
     ncp_uint64_t    intq_d_parity_err                         :  1;
     ncp_uint64_t    maxqd_parity_err                          :  1;
     ncp_uint64_t    peq_parity_err                            :  1;
     ncp_uint64_t    pnq_parity_err                            :  1;
     ncp_uint64_t    adq_parity_err                            :  1;
#else    /* Little Endian */
     ncp_uint64_t    adq_parity_err                            :  1;
     ncp_uint64_t    pnq_parity_err                            :  1;
     ncp_uint64_t    peq_parity_err                            :  1;
     ncp_uint64_t    maxqd_parity_err                          :  1;
     ncp_uint64_t    intq_d_parity_err                         :  1;
     ncp_uint64_t    minqd_parity_err                          :  1;
     ncp_uint64_t    reserved0                                 : 58;
#endif
} ncp_qpm_sticky_parity_r_t;

/*! @struct ncp_qpm_sticky_ecc1_r_t
 *  @brief QPM ECC1 Sticky Multi-Error Register
 *  @details Vector indicating which specific multi-bit ECC error(s) occurred.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_sticky_ecc1_r_t\n
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
 *     <td width="20%" align="center"> 51 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_fl_multi_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Intq LL Free List RAM Multi ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_hp_multi_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Intq LL Head Ptr RAM Multi ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_state_multi_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Intq LL State RAM Multi ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param extask_info_multi_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> Extask Info State RAM Multi ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ex_rptd_multi_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Exception Reported RAM Multi ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fl_multi_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Free List RAM Multi ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qem_multi_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Queue Event Mask RAM Multi ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param thresh_multi_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Threshold RAM Multi ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_multi_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Count RAM Multi ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param tp_multi_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Tail Ptr RAM Multi ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp_multi_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Head Ptr RAM Multi ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param lnk_multi_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Link RAM Multi ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qm_multi_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Queue RAM Multi ECC Error </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_sticky_ecc1_r_t
 *
 * Implemented by: 
 *      sticky_ecc1_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 51;
     ncp_uint64_t    intq_fl_multi_err                         :  1;
     ncp_uint64_t    intq_hp_multi_err                         :  1;
     ncp_uint64_t    intq_state_multi_err                      :  1;
     ncp_uint64_t    extask_info_multi_err                     :  1;
     ncp_uint64_t    ex_rptd_multi_err                         :  1;
     ncp_uint64_t    fl_multi_err                              :  1;
     ncp_uint64_t    qem_multi_err                             :  1;
     ncp_uint64_t    thresh_multi_err                          :  1;
     ncp_uint64_t    cnt_multi_err                             :  1;
     ncp_uint64_t    tp_multi_err                              :  1;
     ncp_uint64_t    hp_multi_err                              :  1;
     ncp_uint64_t    lnk_multi_err                             :  1;
     ncp_uint64_t    qm_multi_err                              :  1;
#else    /* Little Endian */
     ncp_uint64_t    qm_multi_err                              :  1;
     ncp_uint64_t    lnk_multi_err                             :  1;
     ncp_uint64_t    hp_multi_err                              :  1;
     ncp_uint64_t    tp_multi_err                              :  1;
     ncp_uint64_t    cnt_multi_err                             :  1;
     ncp_uint64_t    thresh_multi_err                          :  1;
     ncp_uint64_t    qem_multi_err                             :  1;
     ncp_uint64_t    fl_multi_err                              :  1;
     ncp_uint64_t    ex_rptd_multi_err                         :  1;
     ncp_uint64_t    extask_info_multi_err                     :  1;
     ncp_uint64_t    intq_state_multi_err                      :  1;
     ncp_uint64_t    intq_hp_multi_err                         :  1;
     ncp_uint64_t    intq_fl_multi_err                         :  1;
     ncp_uint64_t    reserved0                                 : 51;
#endif
} ncp_qpm_sticky_ecc1_r_t;

/*! @struct ncp_qpm_sticky_ecc0_r_t
 *  @brief QPM ECC0 Sticky Single-Error Register
 *  @details Vector indicating which specific singl-bit ECC error(s) occurred.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_sticky_ecc0_r_t\n
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
 *     <td width="20%" align="center"> 51 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_fl_single_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Intq LL Free List RAM Single ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_hp_single_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Intq LL Head Ptr RAM Single ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_state_single_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Intq LL State RAM Single ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param extask_info_single_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> Extask Info State RAM Single ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ex_rptd_single_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Exception Reported RAM Single ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fl_single_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Free List RAM Single ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qem_single_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Queue Event Mask RAM Single ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param thresh_single_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Threshold RAM Single ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_single_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Count RAM Single ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param tp_single_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Tail Ptr RAM Single ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param hp_single_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Head Ptr RAM Single ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param lnk_single_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Link RAM Single ECC Error </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qm_single_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Queue RAM Single ECC Error </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_sticky_ecc0_r_t
 *
 * Implemented by: 
 *      sticky_ecc0_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 51;
     ncp_uint64_t    intq_fl_single_err                        :  1;
     ncp_uint64_t    intq_hp_single_err                        :  1;
     ncp_uint64_t    intq_state_single_err                     :  1;
     ncp_uint64_t    extask_info_single_err                    :  1;
     ncp_uint64_t    ex_rptd_single_err                        :  1;
     ncp_uint64_t    fl_single_err                             :  1;
     ncp_uint64_t    qem_single_err                            :  1;
     ncp_uint64_t    thresh_single_err                         :  1;
     ncp_uint64_t    cnt_single_err                            :  1;
     ncp_uint64_t    tp_single_err                             :  1;
     ncp_uint64_t    hp_single_err                             :  1;
     ncp_uint64_t    lnk_single_err                            :  1;
     ncp_uint64_t    qm_single_err                             :  1;
#else    /* Little Endian */
     ncp_uint64_t    qm_single_err                             :  1;
     ncp_uint64_t    lnk_single_err                            :  1;
     ncp_uint64_t    hp_single_err                             :  1;
     ncp_uint64_t    tp_single_err                             :  1;
     ncp_uint64_t    cnt_single_err                            :  1;
     ncp_uint64_t    thresh_single_err                         :  1;
     ncp_uint64_t    qem_single_err                            :  1;
     ncp_uint64_t    fl_single_err                             :  1;
     ncp_uint64_t    ex_rptd_single_err                        :  1;
     ncp_uint64_t    extask_info_single_err                    :  1;
     ncp_uint64_t    intq_state_single_err                     :  1;
     ncp_uint64_t    intq_hp_single_err                        :  1;
     ncp_uint64_t    intq_fl_single_err                        :  1;
     ncp_uint64_t    reserved0                                 : 51;
#endif
} ncp_qpm_sticky_ecc0_r_t;

/*! @struct ncp_qpm_sticky_cmem_err_addr_r_t
 *  @brief Correctable Memory Error Address Register
 *  @details When a correctable memory error (single-bit ECC) occurs, contains the memory address which experienced the error.
	Except where indicated below, the information saved is the full axi address bits 23:3 and the axi port which initiated
	the request which experienced the error.  For those memories the actual memory address can be calculated from the
	axi address/instruction.  In the event of multiple, simultaneous errors, the address which is recorded
	is according to the following priority (highest to lowest):
	0  - Task Entry queue memory   : port[1:0], axi address[23:3]
	1  - Link memory               : link memory address
	2  - Head Pointer memory       : port[1:0], axi address[23:3]
	3  - Tail Pointer memory       : port[1:0], axi address[23:3]
	4  - Count memory              : port[1:0], axi address[23:3]
	5  - Threshold memory          : port[1:0], axi address[23:3]
	6  - Queue Event Mask memory   : port[1:0], axi address[23:3]
	7  - Free List memory          : free list memory address
	8  - Exception Reported memory : port[1:0], axi address[23:3]
	9  - Extask Info memory        : extask info memory address
	10 - Intq LL State memory      : interrupt queue state memory address
	11 - Intq LL HP memory         : interrupt queue hp memory address
	12 - Intq LL FL memory         : interrupt queue free list memory address
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_sticky_cmem_err_addr_r_t\n
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
 *     <td width="20%" align="center"> 41 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param addr </td>
 *     <td width="20%" align="center"> 23 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Port/Address as described above. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_sticky_cmem_err_addr_r_t
 *
 * Implemented by: 
 *      sticky_cmem_err_addr_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 41;
     ncp_uint64_t    addr                                      : 23;
#else    /* Little Endian */
     ncp_uint64_t    addr                                      : 23;
     ncp_uint64_t    reserved0                                 : 41;
#endif
} ncp_qpm_sticky_cmem_err_addr_r_t;

/*! @struct ncp_qpm_sticky_ucmem_err_addr_r_t
 *  @brief Uncorrectable Memory Error Address Register
 *  @details When an uncorrectable memory error (multi-bit ECC or parity) occurs, contains the memory address which experienced the error.
	Except where indicated below, the information saved is the full axi address bits 23:3 and the axi port which initiated
	the request which experienced the error.  For those memories the actual memory address can be calculated from the
	axi address/instruction.  In the event of multiple, simultaneous errors, ECC error addresses are recorded over parity error
	addresses.  Within the possible ECC errors the priority of the recording (highest to lowest) is:
	0  - Task Entry queue memory   : port[1:0], axi address[23:3]
	1  - Link memory               : link memory address
	2  - Head Pointer memory       : port[1:0], axi address[23:3]
	3  - Tail Pointer memory       : port[1:0], axi address[23:3]
	4  - Count memory              : port[1:0], axi address[23:3]
	5  - Threshold memory          : port[1:0], axi address[23:3]
	6  - Queue Event Mask memory   : port[1:0], axi address[23:3]
	7  - Free List memory          : free list memory address
	8  - Exception Reported memory : port[1:0], axi address[23:3]
	9  - Extask Info memory        : extask info memory address
	10 - Intq LL State memory      : interrupt queue state memory address
	11 - Intq LL HP memory         : interrupt queue hp memory address
	12 - Intq LL FL memory         : interrupt queue free list memory address

	Addresses for parity errors are recorded with the following priority (highest to lowest):
	0 - Adds To Queue memory       : port[1:0], axi address[23:3]
	1 - Pop NonEmpty Queue memory  : port[1:0], axi address[23:3]
	2 - Pop Empty Queue memory     : port[1:0], axi address[23:3]
	3 - Max Queue Depth memory     : port[1:0], axi address[23:3]
	4 - Intq LL Alloc Data memory  : interrupt queue alloc data memory address
	5 - Min Queue Depth memory     : port[1:0], axi address[23:3]
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_sticky_ucmem_err_addr_r_t\n
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
 *     <td width="20%" align="center"> 41 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param addr </td>
 *     <td width="20%" align="center"> 23 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Port/Address as described above. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_sticky_ucmem_err_addr_r_t
 *
 * Implemented by: 
 *      sticky_ucmem_err_addr_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 41;
     ncp_uint64_t    addr                                      : 23;
#else    /* Little Endian */
     ncp_uint64_t    addr                                      : 23;
     ncp_uint64_t    reserved0                                 : 41;
#endif
} ncp_qpm_sticky_ucmem_err_addr_r_t;

/*! @struct ncp_qpm_hw_params_0_r_t
 *  @brief QPM Global Hardware Parameter Register 0
 *  @details QPM Global Hardware Parameter Register 0
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_hw_params_0_r_t\n
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
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_num_queues </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> QPM_NUM_QUEUES parameter value : Number of event queues
 *        supported by the hardware.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_hw_params_0_r_t
 *
 * Implemented by: 
 *      qpm_hw_params_0
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 32;
     ncp_uint64_t    qpm_num_queues                            : 32;
#else    /* Little Endian */
     ncp_uint64_t    qpm_num_queues                            : 32;
     ncp_uint64_t    reserved0                                 : 32;
#endif
} ncp_qpm_hw_params_0_r_t;

/*! @struct ncp_qpm_hw_params_1_r_t
 *  @brief QPM Global Hardware Parameter Register 1
 *  @details QPM Global Hardware Parameter Register 1
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_hw_params_1_r_t\n
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
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_qm_depth </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> QPM_QM_DEPTH parameter value : Total number of event
 *        queue entries supported by the hardware.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_hw_params_1_r_t
 *
 * Implemented by: 
 *      qpm_hw_params_1
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 32;
     ncp_uint64_t    qpm_qm_depth                              : 32;
#else    /* Little Endian */
     ncp_uint64_t    qpm_qm_depth                              : 32;
     ncp_uint64_t    reserved0                                 : 32;
#endif
} ncp_qpm_hw_params_1_r_t;

/*! @struct ncp_qpm_hw_params_2_r_t
 *  @brief QPM Global Hardware Parameter Register 2
 *  @details QPM Global Hardware Parameter Register 2
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_hw_params_2_r_t\n
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
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_num_mon_queues </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> QPM_NUM_MON_QUEUES parameter value : Number of monitored
 *        queues supported by the hardware.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_hw_params_2_r_t
 *
 * Implemented by: 
 *      qpm_hw_params_2
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 32;
     ncp_uint64_t    qpm_num_mon_queues                        : 32;
#else    /* Little Endian */
     ncp_uint64_t    qpm_num_mon_queues                        : 32;
     ncp_uint64_t    reserved0                                 : 32;
#endif
} ncp_qpm_hw_params_2_r_t;

/*! @struct ncp_qpm_hw_params_3_r_t
 *  @brief QPM Global Hardware Parameter Register 3
 *  @details QPM Global Hardware Parameter Register 3
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_hw_params_3_r_t\n
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
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_qm_data_width </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> QPM_QM_DATA_WIDTH parameter value : Width of event
 *        queue data
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_hw_params_3_r_t
 *
 * Implemented by: 
 *      qpm_hw_params_3
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 32;
     ncp_uint64_t    qpm_qm_data_width                         : 32;
#else    /* Little Endian */
     ncp_uint64_t    qpm_qm_data_width                         : 32;
     ncp_uint64_t    reserved0                                 : 32;
#endif
} ncp_qpm_hw_params_3_r_t;

/*! @struct ncp_qpm_llc_intq_status_r_t
 *  @brief LLC Interrupt Queue Linked List Status
 *  @details LLC Interrupt Queue Linked List status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_llc_intq_status_r_t\n
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
 *     <td width="20%" align="center"> 42 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ll_size </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> LL size. Indicates the number of entries in all Interrupt
 *        Queue linked lists.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ll_busy </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> LL busy. Indicates that one of more of the Interrupt
 *        Queue linked lists is busy - an entry is being added
 *        or deleted.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ll_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> LL valid. Indicates that one of more of the Interrupt
 *        Queue linked lists is valid - contains one or more
 *        entries.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ll_full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> LL full. Indicates that the Interrupt Queue linked
 *        list is full, or the associated freelist is empty;
 *        can not add any more entries.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param freelist_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Freelist Valid. Indicates the current status of the
 *        freelist valid input
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param del_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Delete Request Valid. Indicates the current status
 *        of the delete request valid input
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param alloc_req_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Allocate Request Valid. Indicates the current status
 *        of the allocate request valid input
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_llc_intq_status_r_t
 *
 * Implemented by: 
 *      llc_intq_status_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 42;
     ncp_uint64_t    ll_size                                   : 16;
     ncp_uint64_t    ll_busy                                   :  1;
     ncp_uint64_t    ll_v                                      :  1;
     ncp_uint64_t    ll_full                                   :  1;
     ncp_uint64_t    freelist_v                                :  1;
     ncp_uint64_t    del_req_v                                 :  1;
     ncp_uint64_t    alloc_req_v                               :  1;
#else    /* Little Endian */
     ncp_uint64_t    alloc_req_v                               :  1;
     ncp_uint64_t    del_req_v                                 :  1;
     ncp_uint64_t    freelist_v                                :  1;
     ncp_uint64_t    ll_full                                   :  1;
     ncp_uint64_t    ll_v                                      :  1;
     ncp_uint64_t    ll_busy                                   :  1;
     ncp_uint64_t    ll_size                                   : 16;
     ncp_uint64_t    reserved0                                 : 42;
#endif
} ncp_qpm_llc_intq_status_r_t;

/*! @struct ncp_qpm_llc_intq_fl_status_r_t
 *  @brief LLC Interrupt Queue Free List status
 *  @details LLC Interrupt Queue Free List status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_llc_intq_fl_status_r_t\n
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
 *     <td width="20%" align="center"> 35 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_db_oready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Push DB out ready. Indicates the output ready status
 *        of the pop double buffer. 0 unless doing a pop.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_db_depth </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> Push DB depth. Indicates the depth of the pop double
 *        buffer
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param push_db_oready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> Push DB out ready. Indicates the output ready status
 *        of the push double buffer. 0 unless completing a push.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param push_db_depth </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Push DB depth. Indicates the depth of the push double
 *        buffer
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param initialized </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Initialized. Indicates the current intq freelist Initialized
 *        status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_rd_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Config Read Data Valid. Indicates the current status
 *        of the intq freelist config read data valid output
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param push_ready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Push Ready. Indicates the current status of the intq
 *        freelist push ready output
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param popid_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Popid Valid. Indicates the current status of the intq
 *        freelist popid valid output
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_re </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Config Read Valid. Indicates the current status of
 *        the intq freelist config read request input
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param push_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> Push Valid. Indicates the current status of the intq
 *        freelist push request input
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Pop Valid. Indicates the current status of the intq
 *        freelist pop request input
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param state </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> State. Indicates the current value of the intq freelist
 *        state machine
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_llc_intq_fl_status_r_t
 *
 * Implemented by: 
 *      llc_intq_fl_status_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 35;
     ncp_uint64_t    pop_db_oready                             :  1;
     ncp_uint64_t    pop_db_depth                              :  2;
     ncp_uint64_t    push_db_oready                            :  1;
     ncp_uint64_t    push_db_depth                             :  2;
     ncp_uint64_t    initialized                               :  1;
     ncp_uint64_t    cfg_rd_v                                  :  1;
     ncp_uint64_t    push_ready                                :  1;
     ncp_uint64_t    popid_v                                   :  1;
     ncp_uint64_t    cfg_re                                    :  1;
     ncp_uint64_t    push_v                                    :  1;
     ncp_uint64_t    pop_v                                     :  1;
     ncp_uint64_t    reserved1                                 :  8;
     ncp_uint64_t    state                                     :  8;
#else    /* Little Endian */
     ncp_uint64_t    state                                     :  8;
     ncp_uint64_t    reserved1                                 :  8;
     ncp_uint64_t    pop_v                                     :  1;
     ncp_uint64_t    push_v                                    :  1;
     ncp_uint64_t    cfg_re                                    :  1;
     ncp_uint64_t    popid_v                                   :  1;
     ncp_uint64_t    push_ready                                :  1;
     ncp_uint64_t    cfg_rd_v                                  :  1;
     ncp_uint64_t    initialized                               :  1;
     ncp_uint64_t    push_db_depth                             :  2;
     ncp_uint64_t    push_db_oready                            :  1;
     ncp_uint64_t    pop_db_depth                              :  2;
     ncp_uint64_t    pop_db_oready                             :  1;
     ncp_uint64_t    reserved0                                 : 35;
#endif
} ncp_qpm_llc_intq_fl_status_r_t;

/*! @struct ncp_qpm_fl_status_r_t
 *  @brief Free List Controller status
 *  @details Free List Controller status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_fl_status_r_t\n
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
 *     <td width="20%" align="center"> 35 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_db_oready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Push DB out ready. Indicates the output ready status
 *        of the pop double buffer. 0 unless doing a pop.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_db_depth </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> Push DB depth. Indicates the depth of the pop double
 *        buffer
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param push_db_oready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> Push DB out ready. Indicates the output ready status
 *        of the push double buffer. 0 unless completing a push.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param push_db_depth </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Push DB depth. Indicates the depth of the push double
 *        buffer
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param initialized </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Initialized. Indicates the current freelist Initialized
 *        status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_rd_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Config Read Data Valid. Indicates the current status
 *        of the freelist config read data valid output
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param push_ready </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Push Ready. Indicates the current status of the freelist
 *        push ready output
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param popid_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Popid Valid. Indicates the current status of the freelist
 *        popid valid output
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_re </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Config Read Valid. Indicates the current status of
 *        the freelist config read request input
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param push_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> Push Valid. Indicates the current status of the freelist
 *        push request input
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pop_v </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Pop Valid. Indicates the current status of the freelist
 *        pop request input
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param state </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> State. Indicates the current value of the freelist
 *        state machine
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_fl_status_r_t
 *
 * Implemented by: 
 *      fl_status_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 35;
     ncp_uint64_t    pop_db_oready                             :  1;
     ncp_uint64_t    pop_db_depth                              :  2;
     ncp_uint64_t    push_db_oready                            :  1;
     ncp_uint64_t    push_db_depth                             :  2;
     ncp_uint64_t    initialized                               :  1;
     ncp_uint64_t    cfg_rd_v                                  :  1;
     ncp_uint64_t    push_ready                                :  1;
     ncp_uint64_t    popid_v                                   :  1;
     ncp_uint64_t    cfg_re                                    :  1;
     ncp_uint64_t    push_v                                    :  1;
     ncp_uint64_t    pop_v                                     :  1;
     ncp_uint64_t    reserved1                                 :  8;
     ncp_uint64_t    state                                     :  8;
#else    /* Little Endian */
     ncp_uint64_t    state                                     :  8;
     ncp_uint64_t    reserved1                                 :  8;
     ncp_uint64_t    pop_v                                     :  1;
     ncp_uint64_t    push_v                                    :  1;
     ncp_uint64_t    cfg_re                                    :  1;
     ncp_uint64_t    popid_v                                   :  1;
     ncp_uint64_t    push_ready                                :  1;
     ncp_uint64_t    cfg_rd_v                                  :  1;
     ncp_uint64_t    initialized                               :  1;
     ncp_uint64_t    push_db_depth                             :  2;
     ncp_uint64_t    push_db_oready                            :  1;
     ncp_uint64_t    pop_db_depth                              :  2;
     ncp_uint64_t    pop_db_oready                             :  1;
     ncp_uint64_t    reserved0                                 : 35;
#endif
} ncp_qpm_fl_status_r_t;

/*! @struct ncp_qpm_llc_state_r_t
 *  @brief LLC State Machine current state
 *  @details LLC State Machine current state
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_llc_state_r_t\n
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
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param llc_state </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> llc_state </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_llc_state_r_t
 *
 * Implemented by: 
 *      llc_state_reg
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 32;
     ncp_uint64_t    llc_state                                 : 32;
#else    /* Little Endian */
     ncp_uint64_t    llc_state                                 : 32;
     ncp_uint64_t    reserved0                                 : 32;
#endif
} ncp_qpm_llc_state_r_t;

/*! @struct ncp_qpm_llc_intq_fl_count_r_t
 *  @brief LLC Interrupt Queue Free List count
 *  @details Total number of interrupt queue free list available entries
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_llc_intq_fl_count_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param totfree </td>
 *     <td width="20%" align="center"> 64 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Total number of interrupt queue free list available
 *        entries
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_llc_intq_fl_count_r_t
 *
 * Implemented by: 
 *      llc_intq_fl_count_reg
 */
 
typedef struct
{
     ncp_uint64_t                    totfree;
} ncp_qpm_llc_intq_fl_count_r_t;

/*! @struct ncp_qpm_debug_rdata_r_t
 *  @brief Debug read data
 *  @details Debug read data
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_debug_rdata_r_t\n
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
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param dbg_rdata </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Debug read data </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_debug_rdata_r_t
 *
 * Implemented by: 
 *      debug_rdata_r
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 32;
     ncp_uint64_t    dbg_rdata                                 : 32;
#else    /* Little Endian */
     ncp_uint64_t    dbg_rdata                                 : 32;
     ncp_uint64_t    reserved0                                 : 32;
#endif
} ncp_qpm_debug_rdata_r_t;

/*! @struct ncp_qpm_debug_wdata_r_t
 *  @brief Debug write data
 *  @details Debug write data
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_debug_wdata_r_t\n
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
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param dbg_wdata </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Debug write data </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_debug_wdata_r_t
 *
 * Implemented by: 
 *      debug_wdata_r
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 32;
     ncp_uint64_t    dbg_wdata                                 : 32;
#else    /* Little Endian */
     ncp_uint64_t    dbg_wdata                                 : 32;
     ncp_uint64_t    reserved0                                 : 32;
#endif
} ncp_qpm_debug_wdata_r_t;

/*! @struct ncp_qpm_alarm_int_status_r_t
 *  @brief Interrupt Status Register
 *  @details This register holds interrupt status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_alarm_int_status_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param intq_uninit_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> Received an instruction accessing event queue but
 *        Interrupt Queue Free List has not been initialized
 *        - instruction dropped. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intqfl_pop_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> The Interrupt Queue Free List was popped when not
 *        valid - pop is lost, Interrupt Queue Free List is
 *        corrupted. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intqfl_push_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> The Interrupt Queue Free List was pushed when not
 *        ready - push is lost, Interrupt Queue Free List is
 *        corrupted. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fl_pop_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> The Free List was popped when not valid - pop is lost,
 *        Free List is corrupted. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fl_push_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> The Free List was pushed when not ready - push is
 *        lost, Free List is corrupted. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_of_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> There was an attempt to report a service interrupt,
 *        but the interrupt queue was full. The service interrupt
 *        is not reported. This will occur if software
 *        has issued ExceptionAck instructions without corresponding
 *        IntqRead instructions. See the sticky_sw_err_reg
 *        register for more info. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param unaligned_rd_wr_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> An unaligned AXI read or write was attempted - either
 *        an address which was not 64-bit aligned, or if a memory-mapped
 *        command, not 64 bits wide. See the sticky_sw_err_reg
 *        register for more info. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ex_rptd_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Software/configuration error: received an exception
 *        acknowledge for an event queue which has not reported
 *        an exception. See the sticky_sw_err_reg register
 *        for more info. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param q_misconfig </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Queue misconfigured. Asserts when one of the following
 *        occur: - an event queue is accessed which is
 *        configured with a delta which is >= the queue's full
 *        threshold - an event queue is accessed with the
 *        almost-full and almost-empty thresholds enabled and
 *        almost-empty >= almost-full - a service condition
 *        occurs and the event queue is configured as ackless
 *        with service type = interrupt See the sticky_misconfig_reg
 *        register for more info. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_ll_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> An error occurred with the Interrupt Queue linked
 *        list. See the sticky_intq_err_reg register for
 *        more info. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param nsa_rd_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> A protected read was attempted with nonsecure access
 *        not enabled. See the sticky_sw_err_reg register
 *        for more info. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param nsa_wr_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> A protected write was attempted with nonsecure access
 *        not enabled. See the sticky_sw_err_reg register
 *        for more info. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_init_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> The interrupt queue was initialized while qpm was
 *        active. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_mem_par_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> A memory parity error was detected. See the
 *        sticky_parity_reg and sticky_ucmem_err_addr_reg registers
 *        for more info. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_icf_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> An internal consistency failure was detected in QPM.
 *        See the sticky_icf_cnt_reg, sticky_icf_tp_reg,
 *        sticky_icf_hp_reg and sticky_hw_err_reg registers
 *        for more info. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_smon_intrpt </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> QPM SMON interrupt was detected. Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_ecc_mbe </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> An ECC multi-bit error was detected. See the
 *        sticky_ecc1_reg and sticky_ucmem_err_addr_reg registers
 *        for more info. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_ecc_sbe </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> An ECC single-bit error was detected. See the
 *        sticky_ecc0_reg and sticky_cmem_err_addr_reg registers
 *        for more info. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_fifo_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> A Fifo error in QPM is detected. Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param glob_map_rd_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> A read to an undefined register in global space is
 *        attempted. See the sticky_sw_err_reg register
 *        for more info. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param glob_map_wr_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> A write to an undefined register in global space is
 *        attempted. See the sticky_sw_err_reg register
 *        for more info. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param queue_empty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Asserts when there is an attempt to read from an event
 *        queue and the current (TP_Read) or updated (HP_Read)
 *        count is 0. See the sticky_empty_cond_reg register
 *        for more info. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param queue_full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> Asserts when there is an attempt to add to an event
 *        queue and the updated count is >= the full threshold.
 *        See the sticky_full_cond_reg register for more
 *        info. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param free_list_empty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Asserts when there is an attempt to add to an event
 *        queue but the free list is empty. See the sticky_fl_uf_cond_reg
 *        register for more info. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param spare_7 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Spare Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_axi_rd_wr_illegal </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> An AXI read- or write-access with illegal combination
 *        of (AxBURST, AxSIZE, AxLEN). See the sticky_hw_err_reg
 *        register for more info. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_undefined_instr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Asserts when the instruction supplied is not defined.
 *        See the sticky_hw_err_reg register for more
 *        info. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_queue_out_range </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Asserts when there is an attempt to access an event
 *        queue with a qnum parameter which is >= QPM_NUM_QUEUES.
 *        See the sticky_sw_err_reg register for more
 *        info. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param queue_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Asserts when there is an attempt to add to an event
 *        queue which is already full (updated count > full
 *        threshold). See the sticky_of_cond_reg register
 *        for more info. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param queue_underflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Asserts when there is an attempt to read from an empty
 *        event queue (current count == 0). See the sticky_uf_cond_reg
 *        register for more info. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param queue_afull </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Asserts when there is an attempt to add to an event
 *        queue and the updated count is >= the almost full
 *        threshold (or the full threshold for an un-monitored
 *        queue). See the sticky_afull_cond_reg register
 *        for more info. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param queue_aempty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Asserts when there is an attempt to read from an event
 *        queue and the current (TP_Read) or updated (HP_Read)
 *        count is <= the almost empty threshold (or 0
 *        for an un-monitored queue). See the sticky_aempty_cond_reg
 *        register for more info. Status
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_alarm_int_status_r_t
 *
 * Implemented by: 
 *      status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    intq_uninit_err                           :  1;
     ncp_uint64_t    intqfl_pop_err                            :  1;
     ncp_uint64_t    intqfl_push_err                           :  1;
     ncp_uint64_t    fl_pop_err                                :  1;
     ncp_uint64_t    fl_push_err                               :  1;
     ncp_uint64_t    intq_of_err                               :  1;
     ncp_uint64_t    unaligned_rd_wr_err                       :  1;
     ncp_uint64_t    ex_rptd_err                               :  1;
     ncp_uint64_t    q_misconfig                               :  1;
     ncp_uint64_t    intq_ll_err                               :  1;
     ncp_uint64_t    nsa_rd_err                                :  1;
     ncp_uint64_t    nsa_wr_err                                :  1;
     ncp_uint64_t    intq_init_err                             :  1;
     ncp_uint64_t    qpm_mem_par_err                           :  1;
     ncp_uint64_t    qpm_icf_err                               :  1;
     ncp_uint64_t    qpm_smon_intrpt                           :  1;
     ncp_uint64_t    qpm_ecc_mbe                               :  1;
     ncp_uint64_t    qpm_ecc_sbe                               :  1;
     ncp_uint64_t    qpm_fifo_err                              :  1;
     ncp_uint64_t    glob_map_rd_err                           :  1;
     ncp_uint64_t    glob_map_wr_err                           :  1;
     ncp_uint64_t    queue_empty                               :  1;
     ncp_uint64_t    queue_full                                :  1;
     ncp_uint64_t    free_list_empty                           :  1;
     ncp_uint64_t    spare_7                                   :  1;
     ncp_uint64_t    qpm_axi_rd_wr_illegal                     :  1;
     ncp_uint64_t    qpm_undefined_instr                       :  1;
     ncp_uint64_t    qpm_queue_out_range                       :  1;
     ncp_uint64_t    queue_overflow                            :  1;
     ncp_uint64_t    queue_underflow                           :  1;
     ncp_uint64_t    queue_afull                               :  1;
     ncp_uint64_t    queue_aempty                              :  1;
#else    /* Little Endian */
     ncp_uint64_t    queue_aempty                              :  1;
     ncp_uint64_t    queue_afull                               :  1;
     ncp_uint64_t    queue_underflow                           :  1;
     ncp_uint64_t    queue_overflow                            :  1;
     ncp_uint64_t    qpm_queue_out_range                       :  1;
     ncp_uint64_t    qpm_undefined_instr                       :  1;
     ncp_uint64_t    qpm_axi_rd_wr_illegal                     :  1;
     ncp_uint64_t    spare_7                                   :  1;
     ncp_uint64_t    free_list_empty                           :  1;
     ncp_uint64_t    queue_full                                :  1;
     ncp_uint64_t    queue_empty                               :  1;
     ncp_uint64_t    glob_map_wr_err                           :  1;
     ncp_uint64_t    glob_map_rd_err                           :  1;
     ncp_uint64_t    qpm_fifo_err                              :  1;
     ncp_uint64_t    qpm_ecc_sbe                               :  1;
     ncp_uint64_t    qpm_ecc_mbe                               :  1;
     ncp_uint64_t    qpm_smon_intrpt                           :  1;
     ncp_uint64_t    qpm_icf_err                               :  1;
     ncp_uint64_t    qpm_mem_par_err                           :  1;
     ncp_uint64_t    intq_init_err                             :  1;
     ncp_uint64_t    nsa_wr_err                                :  1;
     ncp_uint64_t    nsa_rd_err                                :  1;
     ncp_uint64_t    intq_ll_err                               :  1;
     ncp_uint64_t    q_misconfig                               :  1;
     ncp_uint64_t    ex_rptd_err                               :  1;
     ncp_uint64_t    unaligned_rd_wr_err                       :  1;
     ncp_uint64_t    intq_of_err                               :  1;
     ncp_uint64_t    fl_push_err                               :  1;
     ncp_uint64_t    fl_pop_err                                :  1;
     ncp_uint64_t    intqfl_push_err                           :  1;
     ncp_uint64_t    intqfl_pop_err                            :  1;
     ncp_uint64_t    intq_uninit_err                           :  1;
#endif
} ncp_qpm_alarm_int_status_r_t;

/*! @struct ncp_qpm_alarm_int_en_r_t
 *  @brief Interrupt Enable Register
 *  @details This register enables interrupts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_alarm_int_en_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param intq_uninit_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> Received an instruction accessing event queue but
 *        Interrupt Queue Free List has not been initialized
 *        - instruction dropped. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intqfl_pop_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> The Interrupt Queue Free List was popped when not
 *        valid - pop is lost, Interrupt Queue Free List is
 *        corrupted. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intqfl_push_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> The Interrupt Queue Free List was pushed when not
 *        ready - push is lost, Interrupt Queue Free List is
 *        corrupted. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fl_pop_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> The Free List was popped when not valid - pop is lost,
 *        Free List is corrupted. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fl_push_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> The Free List was pushed when not ready - push is
 *        lost, Free List is corrupted. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_of_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> There was an attempt to report a service interrupt,
 *        but the interrupt queue was full. The service interrupt
 *        is not reported. This will occur if software
 *        has issued ExceptionAck instructions without corresponding
 *        IntqRead instructions. See the sticky_sw_err_reg
 *        register for more info. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param unaligned_rd_wr_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> An unaligned AXI read or write was attempted - either
 *        an address which was not 64-bit aligned, or if a memory-mapped
 *        command, not 64 bits wide. See the sticky_sw_err_reg
 *        register for more info. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ex_rptd_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Software/configuration error: received an exception
 *        acknowledge for an event queue which has not reported
 *        an exception. See the sticky_sw_err_reg register
 *        for more info. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param q_misconfig </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Queue misconfigured. Asserts when one of the following
 *        occur: - an event queue is accessed which is
 *        configured with a delta which is >= the queue's full
 *        threshold - an event queue is accessed with the
 *        almost-full and almost-empty thresholds enabled and
 *        almost-empty >= almost-full - a service condition
 *        occurs and the event queue is configured as ackless
 *        with service type = interrupt See the sticky_misconfig_reg
 *        register for more info. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_ll_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> An error occurred with the Interrupt Queue linked
 *        list. See the sticky_intq_err_reg register for
 *        more info. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param nsa_rd_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> A protected read was attempted with nonsecure access
 *        not enabled. See the sticky_sw_err_reg register
 *        for more info. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param nsa_wr_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> A protected write was attempted with nonsecure access
 *        not enabled. See the sticky_sw_err_reg register
 *        for more info. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_init_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> The interrupt queue was initialized while qpm was
 *        active. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_mem_par_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> A memory parity error was detected. See the
 *        sticky_parity_reg and sticky_ucmem_err_addr_reg registers
 *        for more info. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_icf_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> An internal consistency failure was detected in QPM.
 *        See the sticky_icf_cnt_reg, sticky_icf_tp_reg,
 *        sticky_icf_hp_reg and sticky_hw_err_reg registers
 *        for more info. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_smon_intrpt </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> QPM SMON interrupt was detected. Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_ecc_mbe </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> An ECC multi-bit error was detected. See the
 *        sticky_ecc1_reg and sticky_ucmem_err_addr_reg registers
 *        for more info. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_ecc_sbe </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> An ECC single-bit error was detected. See the
 *        sticky_ecc0_reg and sticky_cmem_err_addr_reg registers
 *        for more info. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_fifo_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> A Fifo error in QPM is detected. Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param glob_map_rd_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> A read to an undefined register in global space is
 *        attempted. See the sticky_sw_err_reg register
 *        for more info. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param glob_map_wr_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> A write to an undefined register in global space is
 *        attempted. See the sticky_sw_err_reg register
 *        for more info. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param queue_empty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Asserts when there is an attempt to read from an event
 *        queue and the current (TP_Read) or updated (HP_Read)
 *        count is 0. See the sticky_empty_cond_reg register
 *        for more info. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param queue_full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> Asserts when there is an attempt to add to an event
 *        queue and the updated count is >= the full threshold.
 *        See the sticky_full_cond_reg register for more
 *        info. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param free_list_empty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Asserts when there is an attempt to add to an event
 *        queue but the free list is empty. See the sticky_fl_uf_cond_reg
 *        register for more info. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param spare_7 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Spare Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_axi_rd_wr_illegal </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> An AXI read- or write-access with illegal combination
 *        of (AxBURST, AxSIZE, AxLEN). See the sticky_hw_err_reg
 *        register for more info. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_undefined_instr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Asserts when the instruction supplied is not defined.
 *        See the sticky_hw_err_reg register for more
 *        info. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_queue_out_range </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Asserts when there is an attempt to access an event
 *        queue with a qnum parameter which is >= QPM_NUM_QUEUES.
 *        See the sticky_sw_err_reg register for more
 *        info. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param queue_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Asserts when there is an attempt to add to an event
 *        queue which is already full (updated count > full
 *        threshold). See the sticky_of_cond_reg register
 *        for more info. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param queue_underflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Asserts when there is an attempt to read from an empty
 *        event queue (current count == 0). See the sticky_uf_cond_reg
 *        register for more info. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param queue_afull </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Asserts when there is an attempt to add to an event
 *        queue and the updated count is >= the almost full
 *        threshold (or the full threshold for an un-monitored
 *        queue). See the sticky_afull_cond_reg register
 *        for more info. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param queue_aempty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Asserts when there is an attempt to read from an event
 *        queue and the current (TP_Read) or updated (HP_Read)
 *        count is <= the almost empty threshold (or 0
 *        for an un-monitored queue). See the sticky_aempty_cond_reg
 *        register for more info. Enable
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_alarm_int_en_r_t
 *
 * Implemented by: 
 *      en
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    intq_uninit_err                           :  1;
     ncp_uint64_t    intqfl_pop_err                            :  1;
     ncp_uint64_t    intqfl_push_err                           :  1;
     ncp_uint64_t    fl_pop_err                                :  1;
     ncp_uint64_t    fl_push_err                               :  1;
     ncp_uint64_t    intq_of_err                               :  1;
     ncp_uint64_t    unaligned_rd_wr_err                       :  1;
     ncp_uint64_t    ex_rptd_err                               :  1;
     ncp_uint64_t    q_misconfig                               :  1;
     ncp_uint64_t    intq_ll_err                               :  1;
     ncp_uint64_t    nsa_rd_err                                :  1;
     ncp_uint64_t    nsa_wr_err                                :  1;
     ncp_uint64_t    intq_init_err                             :  1;
     ncp_uint64_t    qpm_mem_par_err                           :  1;
     ncp_uint64_t    qpm_icf_err                               :  1;
     ncp_uint64_t    qpm_smon_intrpt                           :  1;
     ncp_uint64_t    qpm_ecc_mbe                               :  1;
     ncp_uint64_t    qpm_ecc_sbe                               :  1;
     ncp_uint64_t    qpm_fifo_err                              :  1;
     ncp_uint64_t    glob_map_rd_err                           :  1;
     ncp_uint64_t    glob_map_wr_err                           :  1;
     ncp_uint64_t    queue_empty                               :  1;
     ncp_uint64_t    queue_full                                :  1;
     ncp_uint64_t    free_list_empty                           :  1;
     ncp_uint64_t    spare_7                                   :  1;
     ncp_uint64_t    qpm_axi_rd_wr_illegal                     :  1;
     ncp_uint64_t    qpm_undefined_instr                       :  1;
     ncp_uint64_t    qpm_queue_out_range                       :  1;
     ncp_uint64_t    queue_overflow                            :  1;
     ncp_uint64_t    queue_underflow                           :  1;
     ncp_uint64_t    queue_afull                               :  1;
     ncp_uint64_t    queue_aempty                              :  1;
#else    /* Little Endian */
     ncp_uint64_t    queue_aempty                              :  1;
     ncp_uint64_t    queue_afull                               :  1;
     ncp_uint64_t    queue_underflow                           :  1;
     ncp_uint64_t    queue_overflow                            :  1;
     ncp_uint64_t    qpm_queue_out_range                       :  1;
     ncp_uint64_t    qpm_undefined_instr                       :  1;
     ncp_uint64_t    qpm_axi_rd_wr_illegal                     :  1;
     ncp_uint64_t    spare_7                                   :  1;
     ncp_uint64_t    free_list_empty                           :  1;
     ncp_uint64_t    queue_full                                :  1;
     ncp_uint64_t    queue_empty                               :  1;
     ncp_uint64_t    glob_map_wr_err                           :  1;
     ncp_uint64_t    glob_map_rd_err                           :  1;
     ncp_uint64_t    qpm_fifo_err                              :  1;
     ncp_uint64_t    qpm_ecc_sbe                               :  1;
     ncp_uint64_t    qpm_ecc_mbe                               :  1;
     ncp_uint64_t    qpm_smon_intrpt                           :  1;
     ncp_uint64_t    qpm_icf_err                               :  1;
     ncp_uint64_t    qpm_mem_par_err                           :  1;
     ncp_uint64_t    intq_init_err                             :  1;
     ncp_uint64_t    nsa_wr_err                                :  1;
     ncp_uint64_t    nsa_rd_err                                :  1;
     ncp_uint64_t    intq_ll_err                               :  1;
     ncp_uint64_t    q_misconfig                               :  1;
     ncp_uint64_t    ex_rptd_err                               :  1;
     ncp_uint64_t    unaligned_rd_wr_err                       :  1;
     ncp_uint64_t    intq_of_err                               :  1;
     ncp_uint64_t    fl_push_err                               :  1;
     ncp_uint64_t    fl_pop_err                                :  1;
     ncp_uint64_t    intqfl_push_err                           :  1;
     ncp_uint64_t    intqfl_pop_err                            :  1;
     ncp_uint64_t    intq_uninit_err                           :  1;
#endif
} ncp_qpm_alarm_int_en_r_t;

/*! @struct ncp_qpm_alarm_int_force_r_t
 *  @brief Interrupt Force Register
 *  @details This address is an alias for the Interrupt Status register
		that allows normal CFG writes (as opposed to the Clear-On-Write-One
		behavior if the Interrupt Status register address is used).  This
		allows CFG to set interrupt bits for testing purposes.  Reading this
		address returns the current value of the Interrupt Status Register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_alarm_int_force_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param intq_uninit_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> Received an instruction accessing event queue but
 *        Interrupt Queue Free List has not been initialized
 *        - instruction dropped. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intqfl_pop_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> The Interrupt Queue Free List was popped when not
 *        valid - pop is lost, Interrupt Queue Free List is
 *        corrupted. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intqfl_push_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> The Interrupt Queue Free List was pushed when not
 *        ready - push is lost, Interrupt Queue Free List is
 *        corrupted. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fl_pop_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> The Free List was popped when not valid - pop is lost,
 *        Free List is corrupted. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fl_push_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> The Free List was pushed when not ready - push is
 *        lost, Free List is corrupted. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_of_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> There was an attempt to report a service interrupt,
 *        but the interrupt queue was full. The service interrupt
 *        is not reported. This will occur if software
 *        has issued ExceptionAck instructions without corresponding
 *        IntqRead instructions. See the sticky_sw_err_reg
 *        register for more info. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param unaligned_rd_wr_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> An unaligned AXI read or write was attempted - either
 *        an address which was not 64-bit aligned, or if a memory-mapped
 *        command, not 64 bits wide. See the sticky_sw_err_reg
 *        register for more info. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ex_rptd_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Software/configuration error: received an exception
 *        acknowledge for an event queue which has not reported
 *        an exception. See the sticky_sw_err_reg register
 *        for more info. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param q_misconfig </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Queue misconfigured. Asserts when one of the following
 *        occur: - an event queue is accessed which is
 *        configured with a delta which is >= the queue's full
 *        threshold - an event queue is accessed with the
 *        almost-full and almost-empty thresholds enabled and
 *        almost-empty >= almost-full - a service condition
 *        occurs and the event queue is configured as ackless
 *        with service type = interrupt See the sticky_misconfig_reg
 *        register for more info. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_ll_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> An error occurred with the Interrupt Queue linked
 *        list. See the sticky_intq_err_reg register for
 *        more info. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param nsa_rd_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> A protected read was attempted with nonsecure access
 *        not enabled. See the sticky_sw_err_reg register
 *        for more info. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param nsa_wr_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> A protected write was attempted with nonsecure access
 *        not enabled. See the sticky_sw_err_reg register
 *        for more info. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param intq_init_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> The interrupt queue was initialized while qpm was
 *        active. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_mem_par_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> A memory parity error was detected. See the
 *        sticky_parity_reg and sticky_ucmem_err_addr_reg registers
 *        for more info. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_icf_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> An internal consistency failure was detected in QPM.
 *        See the sticky_icf_cnt_reg, sticky_icf_tp_reg,
 *        sticky_icf_hp_reg and sticky_hw_err_reg registers
 *        for more info. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_smon_intrpt </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> QPM SMON interrupt was detected. Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_ecc_mbe </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> An ECC multi-bit error was detected. See the
 *        sticky_ecc1_reg and sticky_ucmem_err_addr_reg registers
 *        for more info. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_ecc_sbe </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> An ECC single-bit error was detected. See the
 *        sticky_ecc0_reg and sticky_cmem_err_addr_reg registers
 *        for more info. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_fifo_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> A Fifo error in QPM is detected. Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param glob_map_rd_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> A read to an undefined register in global space is
 *        attempted. See the sticky_sw_err_reg register
 *        for more info. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param glob_map_wr_err </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> A write to an undefined register in global space is
 *        attempted. See the sticky_sw_err_reg register
 *        for more info. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param queue_empty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Asserts when there is an attempt to read from an event
 *        queue and the current (TP_Read) or updated (HP_Read)
 *        count is 0. See the sticky_empty_cond_reg register
 *        for more info. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param queue_full </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> Asserts when there is an attempt to add to an event
 *        queue and the updated count is >= the full threshold.
 *        See the sticky_full_cond_reg register for more
 *        info. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param free_list_empty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Asserts when there is an attempt to add to an event
 *        queue but the free list is empty. See the sticky_fl_uf_cond_reg
 *        register for more info. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param spare_7 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Spare Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_axi_rd_wr_illegal </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> An AXI read- or write-access with illegal combination
 *        of (AxBURST, AxSIZE, AxLEN). See the sticky_hw_err_reg
 *        register for more info. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_undefined_instr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Asserts when the instruction supplied is not defined.
 *        See the sticky_hw_err_reg register for more
 *        info. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param qpm_queue_out_range </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Asserts when there is an attempt to access an event
 *        queue with a qnum parameter which is >= QPM_NUM_QUEUES.
 *        See the sticky_sw_err_reg register for more
 *        info. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param queue_overflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Asserts when there is an attempt to add to an event
 *        queue which is already full (updated count > full
 *        threshold). See the sticky_of_cond_reg register
 *        for more info. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param queue_underflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Asserts when there is an attempt to read from an empty
 *        event queue (current count == 0). See the sticky_uf_cond_reg
 *        register for more info. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param queue_afull </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Asserts when there is an attempt to add to an event
 *        queue and the updated count is >= the almost full
 *        threshold (or the full threshold for an un-monitored
 *        queue). See the sticky_afull_cond_reg register
 *        for more info. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param queue_aempty </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Asserts when there is an attempt to read from an event
 *        queue and the current (TP_Read) or updated (HP_Read)
 *        count is <= the almost empty threshold (or 0
 *        for an un-monitored queue). See the sticky_aempty_cond_reg
 *        register for more info. Force
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_alarm_int_force_r_t
 *
 * Implemented by: 
 *      frc
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    intq_uninit_err                           :  1;
     ncp_uint64_t    intqfl_pop_err                            :  1;
     ncp_uint64_t    intqfl_push_err                           :  1;
     ncp_uint64_t    fl_pop_err                                :  1;
     ncp_uint64_t    fl_push_err                               :  1;
     ncp_uint64_t    intq_of_err                               :  1;
     ncp_uint64_t    unaligned_rd_wr_err                       :  1;
     ncp_uint64_t    ex_rptd_err                               :  1;
     ncp_uint64_t    q_misconfig                               :  1;
     ncp_uint64_t    intq_ll_err                               :  1;
     ncp_uint64_t    nsa_rd_err                                :  1;
     ncp_uint64_t    nsa_wr_err                                :  1;
     ncp_uint64_t    intq_init_err                             :  1;
     ncp_uint64_t    qpm_mem_par_err                           :  1;
     ncp_uint64_t    qpm_icf_err                               :  1;
     ncp_uint64_t    qpm_smon_intrpt                           :  1;
     ncp_uint64_t    qpm_ecc_mbe                               :  1;
     ncp_uint64_t    qpm_ecc_sbe                               :  1;
     ncp_uint64_t    qpm_fifo_err                              :  1;
     ncp_uint64_t    glob_map_rd_err                           :  1;
     ncp_uint64_t    glob_map_wr_err                           :  1;
     ncp_uint64_t    queue_empty                               :  1;
     ncp_uint64_t    queue_full                                :  1;
     ncp_uint64_t    free_list_empty                           :  1;
     ncp_uint64_t    spare_7                                   :  1;
     ncp_uint64_t    qpm_axi_rd_wr_illegal                     :  1;
     ncp_uint64_t    qpm_undefined_instr                       :  1;
     ncp_uint64_t    qpm_queue_out_range                       :  1;
     ncp_uint64_t    queue_overflow                            :  1;
     ncp_uint64_t    queue_underflow                           :  1;
     ncp_uint64_t    queue_afull                               :  1;
     ncp_uint64_t    queue_aempty                              :  1;
#else    /* Little Endian */
     ncp_uint64_t    queue_aempty                              :  1;
     ncp_uint64_t    queue_afull                               :  1;
     ncp_uint64_t    queue_underflow                           :  1;
     ncp_uint64_t    queue_overflow                            :  1;
     ncp_uint64_t    qpm_queue_out_range                       :  1;
     ncp_uint64_t    qpm_undefined_instr                       :  1;
     ncp_uint64_t    qpm_axi_rd_wr_illegal                     :  1;
     ncp_uint64_t    spare_7                                   :  1;
     ncp_uint64_t    free_list_empty                           :  1;
     ncp_uint64_t    queue_full                                :  1;
     ncp_uint64_t    queue_empty                               :  1;
     ncp_uint64_t    glob_map_wr_err                           :  1;
     ncp_uint64_t    glob_map_rd_err                           :  1;
     ncp_uint64_t    qpm_fifo_err                              :  1;
     ncp_uint64_t    qpm_ecc_sbe                               :  1;
     ncp_uint64_t    qpm_ecc_mbe                               :  1;
     ncp_uint64_t    qpm_smon_intrpt                           :  1;
     ncp_uint64_t    qpm_icf_err                               :  1;
     ncp_uint64_t    qpm_mem_par_err                           :  1;
     ncp_uint64_t    intq_init_err                             :  1;
     ncp_uint64_t    nsa_wr_err                                :  1;
     ncp_uint64_t    nsa_rd_err                                :  1;
     ncp_uint64_t    intq_ll_err                               :  1;
     ncp_uint64_t    q_misconfig                               :  1;
     ncp_uint64_t    ex_rptd_err                               :  1;
     ncp_uint64_t    unaligned_rd_wr_err                       :  1;
     ncp_uint64_t    intq_of_err                               :  1;
     ncp_uint64_t    fl_push_err                               :  1;
     ncp_uint64_t    fl_pop_err                                :  1;
     ncp_uint64_t    intqfl_push_err                           :  1;
     ncp_uint64_t    intqfl_pop_err                            :  1;
     ncp_uint64_t    intq_uninit_err                           :  1;
#endif
} ncp_qpm_alarm_int_force_r_t;

/*! @struct ncp_qpm_AW_smon01_qpm_smon_r_t
 *  @brief AW_smon CONTROL1 register
 *  @details This is used to configure the operation of the 2 internal counters in the SMON
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_AW_smon01_qpm_smon_r_t\n
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
 * Applies to: xlf --> ncp_qpm_AW_smon01_qpm_smon_r_t
 *
 * Implemented by: 
 *      AW_SMON01_qpm_smon
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 16;
     ncp_uint64_t    mode1                                     :  8;
     ncp_uint64_t    mode0                                     :  8;
#else    /* Little Endian */
     ncp_uint64_t    mode0                                     :  8;
     ncp_uint64_t    mode1                                     :  8;
     ncp_uint64_t    reserved0                                 : 16;
#endif
} ncp_qpm_AW_smon01_qpm_smon_r_t;

/*! @struct ncp_qpm_global_lock_ctrl_r_t
 *  @brief global Lock Control Register
 *  @details When the lock bit = 1, blocks configuration writes to all indicated registers/bits.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_qpm_global_lock_ctrl_r_t\n
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
 *   <td width="30%"> Block configuration writes to all QPM registers/bits
 *        except: - alarm_int status
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_qpm_global_lock_ctrl_r_t
 *
 * Implemented by: 
 *      global_lock_ctrl
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     ncp_uint64_t    reserved0                                 : 31;
     ncp_uint64_t    write_lock                                :  1;
#else    /* Little Endian */
     ncp_uint64_t    write_lock                                :  1;
     ncp_uint64_t    reserved0                                 : 31;
#endif
} ncp_qpm_global_lock_ctrl_r_t;

#ifdef __cplusplus
}
#endif

#endif /* _NCP_QPM_REGS_H_ */
