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


#ifndef _NCP_AW_TRACE1_REGS_H_
#define _NCP_AW_TRACE1_REGS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"

/*! @struct ncp_aw_trace1_req_fifo_status_r_t
 *  @brief ACE-Lite request FIFO status
 *  @details FIFO to buffer incoming ACE-Lite write requests before submitting them to the trace state machine.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_aw_trace1_req_fifo_status_r_t\n
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
 * Applies to: xlf --> ncp_aw_trace1_req_fifo_status_r_t
 *
 * Implemented by: 
 *      req_fifo_status
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
} ncp_aw_trace1_req_fifo_status_r_t;

/*! @struct ncp_aw_trace1_req_fifo_control_r_t
 *  @brief ACE-Lite request FIFO control
 *  @details FIFO to buffer incoming ACE-Lite write requests before submitting them to the trace state machine.
           Note that for a given ACE-Lite write request of N beats, ony up to the first 7 beats will be pushed onto
           this request FIFO; any subsequent beats in the transaction will be dropped. The high watermark must
	   be set to a value that reserves enough space for the amount of data beats in a full transaction (with
	   a cap of 7 beats in a full transaction).
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_aw_trace1_req_fifo_control_r_t\n
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
 *     <td width="30%"> @param fifo_hwm </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> high watermark </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_lwm </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> low watermark </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_req_fifo_control_r_t
 *
 * Implemented by: 
 *      req_fifo_control
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 11;
     unsigned      fifo_hwm                                  :  5;
     unsigned      reserved1                                 : 11;
     unsigned      fifo_lwm                                  :  5;
#else    /* Little Endian */
     unsigned      fifo_lwm                                  :  5;
     unsigned      reserved1                                 : 11;
     unsigned      fifo_hwm                                  :  5;
     unsigned      reserved0                                 : 11;
#endif
} ncp_aw_trace1_req_fifo_control_r_t;

/*! @struct ncp_aw_trace1_resp_fifo_1_status_r_t
 *  @brief State machine internal response FIFO status
 *  @details Internally generated responses are pushed onto this FIFO if an in-flight trace record was dropped for any reason.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_aw_trace1_resp_fifo_1_status_r_t\n
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
 * Applies to: xlf --> ncp_aw_trace1_resp_fifo_1_status_r_t
 *
 * Implemented by: 
 *      resp_fifo_1_status
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
} ncp_aw_trace1_resp_fifo_1_status_r_t;

/*! @struct ncp_aw_trace1_resp_fifo_1_control_r_t
 *  @brief State machine internal response FIFO control
 *  @details Internally generated responses are pushed onto this FIFO if an in-flight trace reocrd was dropped for any reason.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_aw_trace1_resp_fifo_1_control_r_t\n
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
 *     <td width="30%"> @param fifo_hwm </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> high watermark; must be greater than or equal to the
 *        high watermark for the ACE-Lite request FIFO.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_lwm </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> low watermark </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_resp_fifo_1_control_r_t
 *
 * Implemented by: 
 *      resp_fifo_1_control
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 11;
     unsigned      fifo_hwm                                  :  5;
     unsigned      reserved1                                 : 11;
     unsigned      fifo_lwm                                  :  5;
#else    /* Little Endian */
     unsigned      fifo_lwm                                  :  5;
     unsigned      reserved1                                 : 11;
     unsigned      fifo_hwm                                  :  5;
     unsigned      reserved0                                 : 11;
#endif
} ncp_aw_trace1_resp_fifo_1_control_r_t;

/*! @struct ncp_aw_trace1_order_fifo_control_r_t
 *  @brief ACE-Lite write response ordering FIFO control
 *  @details This ordering FIFO takes in write responses from 3 sources: (1) the CMSI write slave, (2) resp_fifo_1,
            and (3) resp_fifo_0.
            From the ordering FIFO description:
            The watermark value is subtracted from the fifo_rdepth output, effectively masking that many
            locations in the FIFO from being available to the client.  The watermark does not affect
            the overflow error checking, but does provide a new simulation assertion if the engine tries to
            allocate more rows than are available after the watermark is subtracted from the total.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_aw_trace1_order_fifo_control_r_t\n
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
 *     <td width="30%"> @param wm </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> watermark; possible values: 0-16 inclusive; this should
 *        ALWAYS be set to 0 but is left exposed here for debug
 *        purposes.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_order_fifo_control_r_t
 *
 * Implemented by: 
 *      order_fifo_control
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 27;
     unsigned      wm                                        :  5;
#else    /* Little Endian */
     unsigned      wm                                        :  5;
     unsigned      reserved0                                 : 27;
#endif
} ncp_aw_trace1_order_fifo_control_r_t;

/*! @struct ncp_aw_trace1_order_fifo_status_r_t
 *  @brief State machine internal response FIFO status
 *  @details Internally generated responses are pushed onto this FIFO if an in-flight trace reocrd was dropped for any reason.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_aw_trace1_order_fifo_status_r_t\n
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
 *     <td width="30%"> @param unallocated_fifo_depth </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> Unallocated FIFO depth </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param current_fifo_depth </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Current FIFO depth </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_overflow_2 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> FIFO overflow: Wrote already valid location </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_overflow_1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> FIFO overflow: Allocated more than rdepth </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_overflow_0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> FIFO overflow: rdepth+depth > DEPTH </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param fifo_underflow </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> FIFO underflow </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_order_fifo_status_r_t
 *
 * Implemented by: 
 *      order_fifo_status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 18;
     unsigned      unallocated_fifo_depth                    :  5;
     unsigned      current_fifo_depth                        :  5;
     unsigned      fifo_overflow_2                           :  1;
     unsigned      fifo_overflow_1                           :  1;
     unsigned      fifo_overflow_0                           :  1;
     unsigned      fifo_underflow                            :  1;
#else    /* Little Endian */
     unsigned      fifo_underflow                            :  1;
     unsigned      fifo_overflow_0                           :  1;
     unsigned      fifo_overflow_1                           :  1;
     unsigned      fifo_overflow_2                           :  1;
     unsigned      current_fifo_depth                        :  5;
     unsigned      unallocated_fifo_depth                    :  5;
     unsigned      reserved0                                 : 18;
#endif
} ncp_aw_trace1_order_fifo_status_r_t;

/*! @struct ncp_aw_trace1_control_r_t
 *  @brief ATM Control Register
 *  @details This register provides control options for modifying the behavior of
          the ATM both at configuration time and at run time.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_aw_trace1_control_r_t\n
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
 *     <td width="30%"> @param trace_format </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Trace format </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param interrupt_service_pulse </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Pulse width of service interrupt (number of cycles
 *        - 1); possible values: 0-7 inclusive
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param interrupt_alarm_pulse </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> Pulse width of alarm interrupt (number of cycles -
 *        1); possible values: 0-7 inclusive
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param metadata_pos </td>
 *     <td width="20%" align="center"> 3 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Controls the position of metadata in the trace record </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param sync_report_enable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> 1: Enable change in AWUSER[63:19] to trigger a diagnostic
 *        trace record. 0: Diagnostic trace records are not
 *        issued.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param enable_trace </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> 1: Enable tracing. 0: Discard all commands with OKAY
 *        response.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param restart_trace </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Setting this to a 1 creates a pulse that removes the
 *        stop condition generated by any stop trace event (command,
 *        stop_trace edge-detect, counter wrap). After the stop
 *        condition is cleared, this signal returns to a 0.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param enable_clk_off </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> 1: enable clk_off to shut off the clocks. 0: do not
 *        allow clk_off to turn off the clocks. Note that the
 *        other AW_trace regs should not be configured while
 *        enable_clk_off is set to 1! If it is desired to enable
 *        the clk_off behavior, configure the rest of the registers
 *        before setting enable_clk_off, and reset enable_clk_off
 *        before any subsequent reconfiguration.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param no_backpressure </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> 1: Do not drop AWREADY. Discard commands if the ATM
 *        processing pipeline is backed up. 0: Drop AW_READY
 *        when the ATM processing pipeline is oversubscribed.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param stop_on_wrap </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 1: Stop tracing when the circular buffer has wrapped
 *        wrapThresh times. 0: Do not stop tracing on a wrap
 *        condition.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_control_r_t
 *
 * Implemented by: 
 *      control
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 16;
     unsigned      trace_format                              :  1;
     unsigned      interrupt_service_pulse                   :  3;
     unsigned      interrupt_alarm_pulse                     :  3;
     unsigned      metadata_pos                              :  3;
     unsigned      sync_report_enable                        :  1;
     unsigned      enable_trace                              :  1;
     unsigned      restart_trace                             :  1;
     unsigned      enable_clk_off                            :  1;
     unsigned      no_backpressure                           :  1;
     unsigned      stop_on_wrap                              :  1;
#else    /* Little Endian */
     unsigned      stop_on_wrap                              :  1;
     unsigned      no_backpressure                           :  1;
     unsigned      enable_clk_off                            :  1;
     unsigned      restart_trace                             :  1;
     unsigned      enable_trace                              :  1;
     unsigned      sync_report_enable                        :  1;
     unsigned      metadata_pos                              :  3;
     unsigned      interrupt_alarm_pulse                     :  3;
     unsigned      interrupt_service_pulse                   :  3;
     unsigned      trace_format                              :  1;
     unsigned      reserved0                                 : 16;
#endif
} ncp_aw_trace1_control_r_t;

/*! @struct ncp_aw_trace1_reset_atm_r_t
 *  @brief ATM Reset Register
 *  @details Reset the ATM's control register to its initial condition.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_aw_trace1_reset_atm_r_t\n
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
 *     <td width="30%"> @param reset_atm </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 1: Reset control register to initial condition. 0:
 *        Local ATM reset is not asserted.
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_reset_atm_r_t
 *
 * Implemented by: 
 *      reset_atm
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 31;
     unsigned      reset_atm                                 :  1;
#else    /* Little Endian */
     unsigned      reset_atm                                 :  1;
     unsigned      reserved0                                 : 31;
#endif
} ncp_aw_trace1_reset_atm_r_t;

/*! @struct ncp_aw_trace1_status_r_t
 *  @brief ATM Status Register
 *  @details Live (non-sticky) status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_aw_trace1_status_r_t\n
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
 *     <td width="30%"> @param cactive </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> The pipeline is active </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_status_r_t
 *
 * Implemented by: 
 *      status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 31;
     unsigned      cactive                                   :  1;
#else    /* Little Endian */
     unsigned      cactive                                   :  1;
     unsigned      reserved0                                 : 31;
#endif
} ncp_aw_trace1_status_r_t;

/*! @struct ncp_aw_trace1_pool_id_r_t
 *  @brief ATM poolID
 *  @details poolID for all memory requests
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_aw_trace1_pool_id_r_t\n
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
 *     <td width="30%"> @param poolid </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> poolID for all memory requests </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_pool_id_r_t
 *
 * Implemented by: 
 *      pool_id
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 24;
     unsigned      poolid                                    :  8;
#else    /* Little Endian */
     unsigned      poolid                                    :  8;
     unsigned      reserved0                                 : 24;
#endif
} ncp_aw_trace1_pool_id_r_t;

/*! @struct ncp_aw_trace1_ttype_trace_record_r_t
 *  @brief ATM ttype_trace_record
 *  @details transaction types for trace records
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_aw_trace1_ttype_trace_record_r_t\n
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
 *     <td width="30%"> @param ttype_long_trace </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> TTYPE for long trace record </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ttype_short_trace_beat3 </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> TTYPE for short trace record at 16B block 3 of 64B
 *        cache
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ttype_short_trace_beat2 </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> TTYPE for short trace record at 16B block 2 of 64B
 *        cache
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ttype_short_trace_beat1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> TTYPE for short trace record at 16B block 1 of 64B
 *        cache
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ttype_short_trace_beat0 </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> TTYPE for short trace record at 16B block 0 of 64B
 *        cache
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_ttype_trace_record_r_t
 *
 * Implemented by: 
 *      ttype_trace_record
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 :  7;
     unsigned      ttype_long_trace                          :  5;
     unsigned      ttype_short_trace_beat3                   :  5;
     unsigned      ttype_short_trace_beat2                   :  5;
     unsigned      ttype_short_trace_beat1                   :  5;
     unsigned      ttype_short_trace_beat0                   :  5;
#else    /* Little Endian */
     unsigned      ttype_short_trace_beat0                   :  5;
     unsigned      ttype_short_trace_beat1                   :  5;
     unsigned      ttype_short_trace_beat2                   :  5;
     unsigned      ttype_short_trace_beat3                   :  5;
     unsigned      ttype_long_trace                          :  5;
     unsigned      reserved0                                 :  7;
#endif
} ncp_aw_trace1_ttype_trace_record_r_t;

/*! @struct ncp_aw_trace1_ttype_diagnostic_record_r_t
 *  @brief ATM ttype_diagnostic_record
 *  @details transaction types for diagnostic records
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_aw_trace1_ttype_diagnostic_record_r_t\n
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
 *     <td width="30%"> @param ttype_diagnostic_beat3 </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> TTYPE for diagnostic record at 16B block 3 of 64B
 *        cache
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ttype_diagnostic_beat2 </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> TTYPE for diagnostic record at 16B block 2 of 64B
 *        cache
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ttype_diagnostic_beat1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> TTYPE for diagnostic record at 16B block 1 of 64B
 *        cache
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param ttype_diagnostic_beat0 </td>
 *     <td width="20%" align="center"> 5 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> TTYPE for diagnostic record at 16B block 0 of 64B
 *        cache
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_ttype_diagnostic_record_r_t
 *
 * Implemented by: 
 *      ttype_diagnostic_record
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 12;
     unsigned      ttype_diagnostic_beat3                    :  5;
     unsigned      ttype_diagnostic_beat2                    :  5;
     unsigned      ttype_diagnostic_beat1                    :  5;
     unsigned      ttype_diagnostic_beat0                    :  5;
#else    /* Little Endian */
     unsigned      ttype_diagnostic_beat0                    :  5;
     unsigned      ttype_diagnostic_beat1                    :  5;
     unsigned      ttype_diagnostic_beat2                    :  5;
     unsigned      ttype_diagnostic_beat3                    :  5;
     unsigned      reserved0                                 : 12;
#endif
} ncp_aw_trace1_ttype_diagnostic_record_r_t;

/*! @struct ncp_aw_trace1_match_enable_r_t
 *  @brief ATM match enable register
 *  @details Control local pattern matching in trace records.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_aw_trace1_match_enable_r_t\n
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
 *     <td width="30%"> @param match_long_enable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Enable local pattern matching in long trace records. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param match_short_enable </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Enable local pattern matching in short trace records. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_match_enable_r_t
 *
 * Implemented by: 
 *      match_enable
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 30;
     unsigned      match_long_enable                         :  1;
     unsigned      match_short_enable                        :  1;
#else    /* Little Endian */
     unsigned      match_short_enable                        :  1;
     unsigned      match_long_enable                         :  1;
     unsigned      reserved0                                 : 30;
#endif
} ncp_aw_trace1_match_enable_r_t;

/*! @struct ncp_aw_trace1_trace_int_reg_status_r_t
 *  @brief Interrupt Status Register
 *  @details This register holds interrupt status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_aw_trace1_trace_int_reg_status_r_t\n
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
 *     <td width="30%"> @param fifo_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ALARM: Some sort of FIFO-related error occurred (overflow
 *        or underflow). Check resp_fifo_1_status, resp_fifo_0_status,
 *        req_fifo_status, and order_fifo_status. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> ALARM: Generic config (read or write) error. Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param acelite_awerr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ALARM: The internal ACE-Lite write slave returned
 *        an error. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param illegal_cmd </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> ALARM: An illegal command was detected. Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param trace_break </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Trace discontinuity: commands were discarded. Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param stop_for_local_match </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Tracing was stopped by a local trace record pattern
 *        match. Status
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param stop_for_wrap </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Tracing was stopped by wrapCntr match. Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param stop_for_event </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Tracing was stopped by stop_trace signal. Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param stop_for_cmd </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Tracing was stopped by STOP_TRACE command. Status </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_trace_int_reg_status_r_t
 *
 * Implemented by: 
 *      status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 23;
     unsigned      fifo_error                                :  1;
     unsigned      cfg_error                                 :  1;
     unsigned      acelite_awerr                             :  1;
     unsigned      illegal_cmd                               :  1;
     unsigned      trace_break                               :  1;
     unsigned      stop_for_local_match                      :  1;
     unsigned      stop_for_wrap                             :  1;
     unsigned      stop_for_event                            :  1;
     unsigned      stop_for_cmd                              :  1;
#else    /* Little Endian */
     unsigned      stop_for_cmd                              :  1;
     unsigned      stop_for_event                            :  1;
     unsigned      stop_for_wrap                             :  1;
     unsigned      stop_for_local_match                      :  1;
     unsigned      trace_break                               :  1;
     unsigned      illegal_cmd                               :  1;
     unsigned      acelite_awerr                             :  1;
     unsigned      cfg_error                                 :  1;
     unsigned      fifo_error                                :  1;
     unsigned      reserved0                                 : 23;
#endif
} ncp_aw_trace1_trace_int_reg_status_r_t;

/*! @struct ncp_aw_trace1_trace_int_reg_en_r_t
 *  @brief Interrupt Enable Register
 *  @details This register enables interrupts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_aw_trace1_trace_int_reg_en_r_t\n
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
 *     <td width="30%"> @param fifo_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ALARM: Some sort of FIFO-related error occurred (overflow
 *        or underflow). Check resp_fifo_1_status, resp_fifo_0_status,
 *        req_fifo_status, and order_fifo_status. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> ALARM: Generic config (read or write) error. Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param acelite_awerr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ALARM: The internal ACE-Lite write slave returned
 *        an error. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param illegal_cmd </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> ALARM: An illegal command was detected. Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param trace_break </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Trace discontinuity: commands were discarded. Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param stop_for_local_match </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Tracing was stopped by a local trace record pattern
 *        match. Enable
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param stop_for_wrap </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Tracing was stopped by wrapCntr match. Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param stop_for_event </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Tracing was stopped by stop_trace signal. Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param stop_for_cmd </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Tracing was stopped by STOP_TRACE command. Enable </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_trace_int_reg_en_r_t
 *
 * Implemented by: 
 *      en
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 23;
     unsigned      fifo_error                                :  1;
     unsigned      cfg_error                                 :  1;
     unsigned      acelite_awerr                             :  1;
     unsigned      illegal_cmd                               :  1;
     unsigned      trace_break                               :  1;
     unsigned      stop_for_local_match                      :  1;
     unsigned      stop_for_wrap                             :  1;
     unsigned      stop_for_event                            :  1;
     unsigned      stop_for_cmd                              :  1;
#else    /* Little Endian */
     unsigned      stop_for_cmd                              :  1;
     unsigned      stop_for_event                            :  1;
     unsigned      stop_for_wrap                             :  1;
     unsigned      stop_for_local_match                      :  1;
     unsigned      trace_break                               :  1;
     unsigned      illegal_cmd                               :  1;
     unsigned      acelite_awerr                             :  1;
     unsigned      cfg_error                                 :  1;
     unsigned      fifo_error                                :  1;
     unsigned      reserved0                                 : 23;
#endif
} ncp_aw_trace1_trace_int_reg_en_r_t;

/*! @struct ncp_aw_trace1_trace_int_reg_force_r_t
 *  @brief Interrupt Force Register
 *  @details This address is an alias for the Interrupt Status register
		that allows normal CFG writes (as opposed to the Clear-On-Write-One
		behavior if the Interrupt Status register address is used).  This
		allows CFG to set interrupt bits for testing purposes.  Reading this
		address returns the current value of the Interrupt Status Register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_aw_trace1_trace_int_reg_force_r_t\n
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
 *     <td width="30%"> @param fifo_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ALARM: Some sort of FIFO-related error occurred (overflow
 *        or underflow). Check resp_fifo_1_status, resp_fifo_0_status,
 *        req_fifo_status, and order_fifo_status. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param cfg_error </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> ALARM: Generic config (read or write) error. Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param acelite_awerr </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> ALARM: The internal ACE-Lite write slave returned
 *        an error. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param illegal_cmd </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> ALARM: An illegal command was detected. Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param trace_break </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Trace discontinuity: commands were discarded. Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param stop_for_local_match </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Tracing was stopped by a local trace record pattern
 *        match. Force
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param stop_for_wrap </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Tracing was stopped by wrapCntr match. Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param stop_for_event </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Tracing was stopped by stop_trace signal. Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param stop_for_cmd </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Tracing was stopped by STOP_TRACE command. Force </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_trace_int_reg_force_r_t
 *
 * Implemented by: 
 *      frc
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      reserved0                                 : 23;
     unsigned      fifo_error                                :  1;
     unsigned      cfg_error                                 :  1;
     unsigned      acelite_awerr                             :  1;
     unsigned      illegal_cmd                               :  1;
     unsigned      trace_break                               :  1;
     unsigned      stop_for_local_match                      :  1;
     unsigned      stop_for_wrap                             :  1;
     unsigned      stop_for_event                            :  1;
     unsigned      stop_for_cmd                              :  1;
#else    /* Little Endian */
     unsigned      stop_for_cmd                              :  1;
     unsigned      stop_for_event                            :  1;
     unsigned      stop_for_wrap                             :  1;
     unsigned      stop_for_local_match                      :  1;
     unsigned      trace_break                               :  1;
     unsigned      illegal_cmd                               :  1;
     unsigned      acelite_awerr                             :  1;
     unsigned      cfg_error                                 :  1;
     unsigned      fifo_error                                :  1;
     unsigned      reserved0                                 : 23;
#endif
} ncp_aw_trace1_trace_int_reg_force_r_t;

/*! @struct ncp_aw_trace1_counter_input_req_r_t
 *  @brief null
 *  @details count input reqeusts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_aw_trace1_counter_input_req_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_input_req </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> count input requests </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_counter_input_req_r_t
 *
 * Implemented by: 
 *      counter_input_req_r
 */
 
typedef struct
{
     unsigned  int      cnt_counter_input_req;
} ncp_aw_trace1_counter_input_req_r_t;

/*! @struct ncp_aw_trace1_counter_output_req_r_t
 *  @brief null
 *  @details count output reqeusts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_aw_trace1_counter_output_req_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_output_req </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> count output requests </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_counter_output_req_r_t
 *
 * Implemented by: 
 *      counter_output_req_r
 */
 
typedef struct
{
     unsigned  int      cnt_counter_output_req;
} ncp_aw_trace1_counter_output_req_r_t;

/*! @struct ncp_aw_trace1_cor_counter_input_req_r_t
 *  @brief null
 *  @details (Clear On Read) count input reqeusts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_aw_trace1_cor_counter_input_req_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_input_req </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> count input requests </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_cor_counter_input_req_r_t
 *
 * Implemented by: 
 *      cor_counter_input_req_r
 */
 
typedef struct
{
     unsigned  int      cnt_counter_input_req;
} ncp_aw_trace1_cor_counter_input_req_r_t;

/*! @struct ncp_aw_trace1_cor_counter_output_req_r_t
 *  @brief null
 *  @details (Clear On Read) count output reqeusts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_aw_trace1_cor_counter_output_req_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param cnt_counter_output_req </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> count output requests </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_cor_counter_output_req_r_t
 *
 * Implemented by: 
 *      cor_counter_output_req_r
 */
 
typedef struct
{
     unsigned  int      cnt_counter_output_req;
} ncp_aw_trace1_cor_counter_output_req_r_t;

/*! @struct ncp_aw_trace1_cfg_setup_r_t
 *  @brief null
 *  @details cfg_setup reigster for CFG block
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_aw_trace1_cfg_setup_r_t\n
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
 * Applies to: xlf --> ncp_aw_trace1_cfg_setup_r_t
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
} ncp_aw_trace1_cfg_setup_r_t;

/*! @struct ncp_aw_trace1_wrap_cntr_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_aw_trace1_wrap_cntr_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param wrapcntrh </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> High half of wrap counter </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wrapcntrl </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Low half of wrap counter </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_wrap_cntr_r_t
 *
 * Implemented by: 
 *      wrap_cntr
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      wrapcntrh                                 : 32;
          /* word 1 */
     unsigned      wrapcntrl                                 : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      wrapcntrh                                 : 32;
          /* word 1 */
     unsigned      wrapcntrl                                 : 32;
#endif
} ncp_aw_trace1_wrap_cntr_r_t;

/*! @struct ncp_aw_trace1_wrap_thresh_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_aw_trace1_wrap_thresh_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param wrapthreshh </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> High half of wrap threshold </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param wrapthreshl </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Low half of wrap threshold </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_wrap_thresh_r_t
 *
 * Implemented by: 
 *      wrap_thresh
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      wrapthreshh                               : 32;
          /* word 1 */
     unsigned      wrapthreshl                               : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      wrapthreshh                               : 32;
          /* word 1 */
     unsigned      wrapthreshl                               : 32;
#endif
} ncp_aw_trace1_wrap_thresh_r_t;

/*! @struct ncp_aw_trace1_trace_wp_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_aw_trace1_trace_wp_r_t
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
 *     <td width="30%"> @param tracewph </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> High half of write pointer virtual index </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param tracewpl </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Low half of write pointer virtual index </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_trace_wp_r_t
 *
 * Implemented by: 
 *      trace_wp
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0                                 : 28;
     unsigned      tracewph                                  :  4;
          /* word 1 */
     unsigned      tracewpl                                  : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      tracewph                                  :  4;
     unsigned      reserved0                                 : 28;
          /* word 1 */
     unsigned      tracewpl                                  : 32;
#endif
} ncp_aw_trace1_trace_wp_r_t;

/*! @struct ncp_aw_trace1_trace_first_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_aw_trace1_trace_first_r_t
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
 *     <td width="30%"> @param tracefirsth </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> High half of first location virtual index </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param tracefirstl </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Low half of first location virtual index </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_trace_first_r_t
 *
 * Implemented by: 
 *      trace_first
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0                                 : 28;
     unsigned      tracefirsth                               :  4;
          /* word 1 */
     unsigned      tracefirstl                               : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      tracefirsth                               :  4;
     unsigned      reserved0                                 : 28;
          /* word 1 */
     unsigned      tracefirstl                               : 32;
#endif
} ncp_aw_trace1_trace_first_r_t;

/*! @struct ncp_aw_trace1_trace_last_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_aw_trace1_trace_last_r_t
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
 *     <td width="30%"> @param tracelasth </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> High half of last location virtual index </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param tracelastl </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Low half of last location virtual index </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_trace_last_r_t
 *
 * Implemented by: 
 *      trace_last
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      reserved0                                 : 28;
     unsigned      tracelasth                                :  4;
          /* word 1 */
     unsigned      tracelastl                                : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      tracelasth                                :  4;
     unsigned      reserved0                                 : 28;
          /* word 1 */
     unsigned      tracelastl                                : 32;
#endif
} ncp_aw_trace1_trace_last_r_t;

/*! @struct ncp_aw_trace1_match_pattern_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_aw_trace1_match_pattern_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param match_pattern_word_3 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Word 3 of pattern </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param match_pattern_word_2 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Word 2 of pattern </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param match_pattern_word_1 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Word 1 of pattern </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param match_pattern_word_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Word 0 of pattern </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_match_pattern_r_t
 *
 * Implemented by: 
 *      match_pattern_0
 *      match_pattern_1
 *      match_pattern_2
 *      match_pattern_3
 *      match_pattern_4
 *      match_pattern_5
 *      match_pattern_6
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      match_pattern_word_3                      : 32;
          /* word 1 */
     unsigned      match_pattern_word_2                      : 32;
          /* word 2 */
     unsigned      match_pattern_word_1                      : 32;
          /* word 3 */
     unsigned      match_pattern_word_0                      : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      match_pattern_word_3                      : 32;
          /* word 1 */
     unsigned      match_pattern_word_2                      : 32;
          /* word 2 */
     unsigned      match_pattern_word_1                      : 32;
          /* word 3 */
     unsigned      match_pattern_word_0                      : 32;
#endif
} ncp_aw_trace1_match_pattern_r_t;

/*! @struct ncp_aw_trace1_match_mask_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_aw_trace1_match_mask_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param match_mask_word_3 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Word 3 of mask </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param match_mask_word_2 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Word 2 of mask </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param match_mask_word_1 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Word 1 of mask </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param match_mask_word_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Word 0 of mask </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_aw_trace1_match_mask_r_t
 *
 * Implemented by: 
 *      match_mask_0
 *      match_mask_1
 *      match_mask_2
 *      match_mask_3
 *      match_mask_4
 *      match_mask_5
 *      match_mask_6
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      match_mask_word_3                         : 32;
          /* word 1 */
     unsigned      match_mask_word_2                         : 32;
          /* word 2 */
     unsigned      match_mask_word_1                         : 32;
          /* word 3 */
     unsigned      match_mask_word_0                         : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      match_mask_word_3                         : 32;
          /* word 1 */
     unsigned      match_mask_word_2                         : 32;
          /* word 2 */
     unsigned      match_mask_word_1                         : 32;
          /* word 3 */
     unsigned      match_mask_word_0                         : 32;
#endif
} ncp_aw_trace1_match_mask_r_t;

#ifdef __cplusplus
}
#endif

#endif /* _NCP_AW_TRACE1_REGS_H_ */
