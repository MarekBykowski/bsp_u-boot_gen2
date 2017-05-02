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


#ifndef _NCP_NCA_CFG_REGS_H_
#define _NCP_NCA_CFG_REGS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"

/*! @struct ncp_nca_cfg_interface0004_r_t
 *  @brief interface0004
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_interface0004_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_interface0004_r_t
 *
 * Implemented by: 
 *      interface0004
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_interface0004_r_t;

/*! @struct ncp_nca_cfg_interface0008_r_t
 *  @brief interface0008
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_interface0008_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_interface0008_r_t
 *
 * Implemented by: 
 *      interface0008
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_interface0008_r_t;

/*! @struct ncp_nca_cfg_interface000c_r_t
 *  @brief interface000c
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_interface000c_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_interface000c_r_t
 *
 * Implemented by: 
 *      interface000c
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_interface000c_r_t;

/*! @struct ncp_nca_cfg_interrupt0_status_r_t
 *  @brief Interrupt Status Register
 *  @details This register holds interrupt status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_interrupt0_status_r_t\n
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
 *   <td width="30%"> CFG read_err Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int30 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> CFG write_err Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int29 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int28 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int27 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int26 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int25 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int24 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int23 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int22 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int21 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> CMN BYTE aligned write access detected Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int20 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> CMN BYTE alinged read access detected Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int19 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int18 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> MTP flush pool activity interrupt Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int17 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> OTP flush pool activity interrupt Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int16 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> ITP flush pool activity interrupt Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int15 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int14 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int13 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int12 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Trace (short) fatal interrupt Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int11 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Trace (long) datal interrupt Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int10 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> MTP fatal interrupt Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int09 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> OTP fatal interrupt Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int08 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ITP fatal interrupt Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int07 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int06 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int05 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int04 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Trace (short) service interrupt Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int03 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Trace (long) service interrupt Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int02 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> MTP service interrupt Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int01 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> OTP service interrupt Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int00 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ITP service interrupt Status </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_cfg_interrupt0_status_r_t
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
     unsigned      int09                                     :  1;
     unsigned      int08                                     :  1;
     unsigned      int07                                     :  1;
     unsigned      int06                                     :  1;
     unsigned      int05                                     :  1;
     unsigned      int04                                     :  1;
     unsigned      int03                                     :  1;
     unsigned      int02                                     :  1;
     unsigned      int01                                     :  1;
     unsigned      int00                                     :  1;
#else    /* Little Endian */
     unsigned      int00                                     :  1;
     unsigned      int01                                     :  1;
     unsigned      int02                                     :  1;
     unsigned      int03                                     :  1;
     unsigned      int04                                     :  1;
     unsigned      int05                                     :  1;
     unsigned      int06                                     :  1;
     unsigned      int07                                     :  1;
     unsigned      int08                                     :  1;
     unsigned      int09                                     :  1;
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
} ncp_nca_cfg_interrupt0_status_r_t;

/*! @struct ncp_nca_cfg_interrupt1_status_r_t
 *  @brief Interrupt Status Register
 *  @details This register holds interrupt status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_interrupt1_status_r_t\n
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
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int60 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int59 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int58 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int57 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int56 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int55 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int54 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int53 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int52 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int51 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int50 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int49 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int48 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int47 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int46 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int45 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int44 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int43 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int42 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int41 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int40 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int39 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int38 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int37 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int36 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int35 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int34 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int33 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int32 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_cfg_interrupt1_status_r_t
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
} ncp_nca_cfg_interrupt1_status_r_t;

/*! @struct ncp_nca_cfg_interrupt2_status_r_t
 *  @brief Interrupt Status Register
 *  @details This register holds interrupt status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_interrupt2_status_r_t\n
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
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int89 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int88 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int87 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int86 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int85 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int84 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int83 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int82 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int81 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int80 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int79 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int78 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int77 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int76 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int75 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int74 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int73 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int72 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int71 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int70 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int69 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int68 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int67 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> INFO: MTP prefetch complete. Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int66 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int65 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int64 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_cfg_interrupt2_status_r_t
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
} ncp_nca_cfg_interrupt2_status_r_t;

/*! @struct ncp_nca_cfg_interrupt3_status_r_t
 *  @brief Interrupt Status Register
 *  @details This register holds interrupt status
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_interrupt3_status_r_t\n
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
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int118 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int117 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int116 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int115 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int114 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int113 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int112 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int111 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int110 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int109 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int108 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int107 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int106 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int105 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int104 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int103 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int102 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int101 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int100 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int99 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int98 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int97 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int96 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Status </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_cfg_interrupt3_status_r_t
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
} ncp_nca_cfg_interrupt3_status_r_t;

/*! @struct ncp_nca_cfg_interrupt0_en_r_t
 *  @brief Interrupt Enable Register
 *  @details This register enables interrupts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_interrupt0_en_r_t\n
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
 *   <td width="30%"> CFG read_err Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int30 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> CFG write_err Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int29 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int28 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int27 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int26 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int25 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int24 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int23 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int22 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int21 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> CMN BYTE aligned write access detected Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int20 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> CMN BYTE alinged read access detected Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int19 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int18 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> MTP flush pool activity interrupt Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int17 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> OTP flush pool activity interrupt Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int16 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> ITP flush pool activity interrupt Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int15 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int14 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int13 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int12 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Trace (short) fatal interrupt Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int11 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Trace (long) datal interrupt Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int10 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> MTP fatal interrupt Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int09 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> OTP fatal interrupt Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int08 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ITP fatal interrupt Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int07 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int06 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int05 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int04 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Trace (short) service interrupt Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int03 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Trace (long) service interrupt Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int02 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> MTP service interrupt Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int01 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> OTP service interrupt Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int00 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ITP service interrupt Enable </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_cfg_interrupt0_en_r_t
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
     unsigned      int09                                     :  1;
     unsigned      int08                                     :  1;
     unsigned      int07                                     :  1;
     unsigned      int06                                     :  1;
     unsigned      int05                                     :  1;
     unsigned      int04                                     :  1;
     unsigned      int03                                     :  1;
     unsigned      int02                                     :  1;
     unsigned      int01                                     :  1;
     unsigned      int00                                     :  1;
#else    /* Little Endian */
     unsigned      int00                                     :  1;
     unsigned      int01                                     :  1;
     unsigned      int02                                     :  1;
     unsigned      int03                                     :  1;
     unsigned      int04                                     :  1;
     unsigned      int05                                     :  1;
     unsigned      int06                                     :  1;
     unsigned      int07                                     :  1;
     unsigned      int08                                     :  1;
     unsigned      int09                                     :  1;
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
} ncp_nca_cfg_interrupt0_en_r_t;

/*! @struct ncp_nca_cfg_interrupt1_en_r_t
 *  @brief Interrupt Enable Register
 *  @details This register enables interrupts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_interrupt1_en_r_t\n
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
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int60 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int59 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int58 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int57 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int56 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int55 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int54 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int53 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int52 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int51 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int50 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int49 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int48 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int47 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int46 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int45 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int44 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int43 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int42 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int41 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int40 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int39 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int38 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int37 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int36 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int35 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int34 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int33 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int32 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_cfg_interrupt1_en_r_t
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
} ncp_nca_cfg_interrupt1_en_r_t;

/*! @struct ncp_nca_cfg_interrupt2_en_r_t
 *  @brief Interrupt Enable Register
 *  @details This register enables interrupts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_interrupt2_en_r_t\n
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
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int89 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int88 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int87 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int86 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int85 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int84 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int83 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int82 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int81 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int80 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int79 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int78 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int77 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int76 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int75 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int74 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int73 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int72 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int71 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int70 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int69 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int68 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int67 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> INFO: MTP prefetch complete. Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int66 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int65 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int64 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_cfg_interrupt2_en_r_t
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
} ncp_nca_cfg_interrupt2_en_r_t;

/*! @struct ncp_nca_cfg_interrupt3_en_r_t
 *  @brief Interrupt Enable Register
 *  @details This register enables interrupts
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_interrupt3_en_r_t\n
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
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int118 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int117 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int116 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int115 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int114 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int113 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int112 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int111 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int110 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int109 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int108 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int107 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int106 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int105 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int104 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int103 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int102 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int101 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int100 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int99 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int98 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int97 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int96 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Enable </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_cfg_interrupt3_en_r_t
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
} ncp_nca_cfg_interrupt3_en_r_t;

/*! @struct ncp_nca_cfg_interrupt0_force_r_t
 *  @brief Interrupt Force Register
 *  @details This address is an alias for the Interrupt Status register
		that allows normal CFG writes (as opposed to the Clear-On-Write-One
		behavior if the Interrupt Status register address is used).  This
		allows CFG to set interrupt bits for testing purposes.  Reading this
		address returns the current value of the Interrupt Status Register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_interrupt0_force_r_t\n
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
 *   <td width="30%"> CFG read_err Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int30 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> CFG write_err Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int29 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int28 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int27 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int26 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int25 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int24 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int23 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int22 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int21 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> CMN BYTE aligned write access detected Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int20 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> CMN BYTE alinged read access detected Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int19 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int18 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> MTP flush pool activity interrupt Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int17 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> OTP flush pool activity interrupt Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int16 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> ITP flush pool activity interrupt Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int15 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int14 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int13 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int12 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Trace (short) fatal interrupt Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int11 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Trace (long) datal interrupt Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int10 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> MTP fatal interrupt Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int09 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> OTP fatal interrupt Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int08 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> ITP fatal interrupt Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int07 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int06 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int05 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int04 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Trace (short) service interrupt Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int03 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Trace (long) service interrupt Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int02 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> MTP service interrupt Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int01 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> OTP service interrupt Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int00 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ITP service interrupt Force </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_cfg_interrupt0_force_r_t
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
     unsigned      int09                                     :  1;
     unsigned      int08                                     :  1;
     unsigned      int07                                     :  1;
     unsigned      int06                                     :  1;
     unsigned      int05                                     :  1;
     unsigned      int04                                     :  1;
     unsigned      int03                                     :  1;
     unsigned      int02                                     :  1;
     unsigned      int01                                     :  1;
     unsigned      int00                                     :  1;
#else    /* Little Endian */
     unsigned      int00                                     :  1;
     unsigned      int01                                     :  1;
     unsigned      int02                                     :  1;
     unsigned      int03                                     :  1;
     unsigned      int04                                     :  1;
     unsigned      int05                                     :  1;
     unsigned      int06                                     :  1;
     unsigned      int07                                     :  1;
     unsigned      int08                                     :  1;
     unsigned      int09                                     :  1;
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
} ncp_nca_cfg_interrupt0_force_r_t;

/*! @struct ncp_nca_cfg_interrupt1_force_r_t
 *  @brief Interrupt Force Register
 *  @details This address is an alias for the Interrupt Status register
		that allows normal CFG writes (as opposed to the Clear-On-Write-One
		behavior if the Interrupt Status register address is used).  This
		allows CFG to set interrupt bits for testing purposes.  Reading this
		address returns the current value of the Interrupt Status Register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_interrupt1_force_r_t\n
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
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int60 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int59 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int58 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int57 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int56 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int55 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int54 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int53 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int52 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int51 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int50 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int49 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int48 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int47 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int46 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int45 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int44 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int43 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int42 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int41 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int40 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int39 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int38 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int37 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int36 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int35 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int34 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int33 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int32 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_cfg_interrupt1_force_r_t
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
} ncp_nca_cfg_interrupt1_force_r_t;

/*! @struct ncp_nca_cfg_interrupt2_force_r_t
 *  @brief Interrupt Force Register
 *  @details This address is an alias for the Interrupt Status register
		that allows normal CFG writes (as opposed to the Clear-On-Write-One
		behavior if the Interrupt Status register address is used).  This
		allows CFG to set interrupt bits for testing purposes.  Reading this
		address returns the current value of the Interrupt Status Register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_interrupt2_force_r_t\n
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
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int89 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int88 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int87 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int86 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int85 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int84 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int83 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int82 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int81 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int80 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int79 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int78 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int77 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int76 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int75 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int74 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int73 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int72 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int71 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int70 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int69 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int68 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int67 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> INFO: MTP prefetch complete. Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int66 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int65 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int64 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_cfg_interrupt2_force_r_t
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
} ncp_nca_cfg_interrupt2_force_r_t;

/*! @struct ncp_nca_cfg_interrupt3_force_r_t
 *  @brief Interrupt Force Register
 *  @details This address is an alias for the Interrupt Status register
		that allows normal CFG writes (as opposed to the Clear-On-Write-One
		behavior if the Interrupt Status register address is used).  This
		allows CFG to set interrupt bits for testing purposes.  Reading this
		address returns the current value of the Interrupt Status Register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_interrupt3_force_r_t\n
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
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int118 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int117 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int116 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int115 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int114 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int113 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int112 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int111 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int110 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int109 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int108 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int107 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int106 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int105 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int104 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int103 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int102 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int101 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int100 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int99 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int98 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int97 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param int96 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> Force </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_cfg_interrupt3_force_r_t
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
} ncp_nca_cfg_interrupt3_force_r_t;

/*! @struct ncp_nca_cfg_control0100_r_t
 *  @brief global configuration register
 *  @details control bits for NCAv3 operation
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_control0100_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param control31 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> control bit 031. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control30 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> control bit 030. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control29 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> control bit 029. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control28 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> control bit 028. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control27 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> control bit 027. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control26 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> control bit 026. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control25 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> control bit 025. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control24 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> control bit 024. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control23 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> control bit 023. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control22 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> control bit 022. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control21 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> control bit 021. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control20 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> control bit 020. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control19 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> control bit 019. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control18 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> control bit 018. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control17 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> control bit 017. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control16 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> control bit 016. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control15 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> control bit 015. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control14 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> control bit 014. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control13 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> control bit 013. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control12 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> control bit 012. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control11 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> control bit 011. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control10 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> control bit 010. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control9 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> control bit 009. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control8 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> control bit 008. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control7 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> control bit 007. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control6 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> control bit 006. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control5 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> control bit 005. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control4 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> control bit 004. Globally inject a single bit error
 *        in RAM write
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control3 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> control bit 003. Globally inject a single bit error
 *        in RAM write
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control2 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> control bit 002. Enable global RAM ECC checking </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> control bit 001. Enable global RAM configuration write
 *        access
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> control bit 000. Enable global RAM configuration read
 *        access
 *   </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_cfg_control0100_r_t
 *
 * Implemented by: 
 *      control0100
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      control31                                 :  1;
     unsigned      control30                                 :  1;
     unsigned      control29                                 :  1;
     unsigned      control28                                 :  1;
     unsigned      control27                                 :  1;
     unsigned      control26                                 :  1;
     unsigned      control25                                 :  1;
     unsigned      control24                                 :  1;
     unsigned      control23                                 :  1;
     unsigned      control22                                 :  1;
     unsigned      control21                                 :  1;
     unsigned      control20                                 :  1;
     unsigned      control19                                 :  1;
     unsigned      control18                                 :  1;
     unsigned      control17                                 :  1;
     unsigned      control16                                 :  1;
     unsigned      control15                                 :  1;
     unsigned      control14                                 :  1;
     unsigned      control13                                 :  1;
     unsigned      control12                                 :  1;
     unsigned      control11                                 :  1;
     unsigned      control10                                 :  1;
     unsigned      control9                                  :  1;
     unsigned      control8                                  :  1;
     unsigned      control7                                  :  1;
     unsigned      control6                                  :  1;
     unsigned      control5                                  :  1;
     unsigned      control4                                  :  1;
     unsigned      control3                                  :  1;
     unsigned      control2                                  :  1;
     unsigned      control1                                  :  1;
     unsigned      control0                                  :  1;
#else    /* Little Endian */
     unsigned      control0                                  :  1;
     unsigned      control1                                  :  1;
     unsigned      control2                                  :  1;
     unsigned      control3                                  :  1;
     unsigned      control4                                  :  1;
     unsigned      control5                                  :  1;
     unsigned      control6                                  :  1;
     unsigned      control7                                  :  1;
     unsigned      control8                                  :  1;
     unsigned      control9                                  :  1;
     unsigned      control10                                 :  1;
     unsigned      control11                                 :  1;
     unsigned      control12                                 :  1;
     unsigned      control13                                 :  1;
     unsigned      control14                                 :  1;
     unsigned      control15                                 :  1;
     unsigned      control16                                 :  1;
     unsigned      control17                                 :  1;
     unsigned      control18                                 :  1;
     unsigned      control19                                 :  1;
     unsigned      control20                                 :  1;
     unsigned      control21                                 :  1;
     unsigned      control22                                 :  1;
     unsigned      control23                                 :  1;
     unsigned      control24                                 :  1;
     unsigned      control25                                 :  1;
     unsigned      control26                                 :  1;
     unsigned      control27                                 :  1;
     unsigned      control28                                 :  1;
     unsigned      control29                                 :  1;
     unsigned      control30                                 :  1;
     unsigned      control31                                 :  1;
#endif
} ncp_nca_cfg_control0100_r_t;

/*! @struct ncp_nca_cfg_control0104_r_t
 *  @brief global configuration register
 *  @details control bits for NCAv3 operation
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_control0104_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param control63 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> control bit 063. Enable cPCQ DBA host memory space
 *        usage
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control62 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> control bit 062. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control61 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> control bit 061. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control60 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> control bit 060. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control59 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> control bit 059. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control58 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> control bit 058. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control57 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> control bit 057. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control56 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> control bit 056. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control55 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> control bit 055. Enable OTP cPCQ response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control54 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> control bit 054. Enable OTP cPCQ request interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control53 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> control bit 053. Enable OTP to MTP response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control52 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> control bit 052. Enable OTP to MTP request interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control51 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> control bit 051. Enable OTP task completion to ITP
 *        interface
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control50 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> control bit 050. Enable COW TDGL interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control49 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> control bit 049. Enable OTP NLINK response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control48 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> control bit 048. Enable OTP NLINK request interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control47 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> control bit 047. Enable ITP BP ring status update </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control46 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> control bit 046. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control45 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> control bit 045. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control44 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> control bit 044. QPM lock, the write interface lock </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control43 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> control bit 043. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control42 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> control bit 042. Enable ITP completion SM </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control41 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> control bit 041. Enable ITP schedule SM </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control40 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> control bit 040. Enable ITP enqueue SM </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control39 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> control bit 039. Enable ITP to MTP pointer request
 *        interface
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control38 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> control bit 038. Enable ITP to MTP transmit interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control37 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> control bit 037. Enable ITP task completion from OTP
 *        interface
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control36 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> control bit 036. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control35 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> control bit 035. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control34 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> control bit 034. Enable COW TIL start task interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control33 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> control bit 033. Enable ITP NLINK request interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control32 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> control bit 032. Enable ITP NLINK request interface </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_cfg_control0104_r_t
 *
 * Implemented by: 
 *      control0104
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      control63                                 :  1;
     unsigned      control62                                 :  1;
     unsigned      control61                                 :  1;
     unsigned      control60                                 :  1;
     unsigned      control59                                 :  1;
     unsigned      control58                                 :  1;
     unsigned      control57                                 :  1;
     unsigned      control56                                 :  1;
     unsigned      control55                                 :  1;
     unsigned      control54                                 :  1;
     unsigned      control53                                 :  1;
     unsigned      control52                                 :  1;
     unsigned      control51                                 :  1;
     unsigned      control50                                 :  1;
     unsigned      control49                                 :  1;
     unsigned      control48                                 :  1;
     unsigned      control47                                 :  1;
     unsigned      control46                                 :  1;
     unsigned      control45                                 :  1;
     unsigned      control44                                 :  1;
     unsigned      control43                                 :  1;
     unsigned      control42                                 :  1;
     unsigned      control41                                 :  1;
     unsigned      control40                                 :  1;
     unsigned      control39                                 :  1;
     unsigned      control38                                 :  1;
     unsigned      control37                                 :  1;
     unsigned      control36                                 :  1;
     unsigned      control35                                 :  1;
     unsigned      control34                                 :  1;
     unsigned      control33                                 :  1;
     unsigned      control32                                 :  1;
#else    /* Little Endian */
     unsigned      control32                                 :  1;
     unsigned      control33                                 :  1;
     unsigned      control34                                 :  1;
     unsigned      control35                                 :  1;
     unsigned      control36                                 :  1;
     unsigned      control37                                 :  1;
     unsigned      control38                                 :  1;
     unsigned      control39                                 :  1;
     unsigned      control40                                 :  1;
     unsigned      control41                                 :  1;
     unsigned      control42                                 :  1;
     unsigned      control43                                 :  1;
     unsigned      control44                                 :  1;
     unsigned      control45                                 :  1;
     unsigned      control46                                 :  1;
     unsigned      control47                                 :  1;
     unsigned      control48                                 :  1;
     unsigned      control49                                 :  1;
     unsigned      control50                                 :  1;
     unsigned      control51                                 :  1;
     unsigned      control52                                 :  1;
     unsigned      control53                                 :  1;
     unsigned      control54                                 :  1;
     unsigned      control55                                 :  1;
     unsigned      control56                                 :  1;
     unsigned      control57                                 :  1;
     unsigned      control58                                 :  1;
     unsigned      control59                                 :  1;
     unsigned      control60                                 :  1;
     unsigned      control61                                 :  1;
     unsigned      control62                                 :  1;
     unsigned      control63                                 :  1;
#endif
} ncp_nca_cfg_control0104_r_t;

/*! @struct ncp_nca_cfg_control0108_r_t
 *  @brief global configuration register
 *  @details control bits for NCAv3's Memory Task Processor (MTP)
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_control0108_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param control95 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 31 </td>
 *   <td width="30%"> control bit 095. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control94 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> control bit 094. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control93 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 29 </td>
 *   <td width="30%"> control bit 093. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control92 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> control bit 092. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control91 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 27 </td>
 *   <td width="30%"> control bit 091. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control90 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> control bit 090. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control89 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> control bit 089. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control88 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> control bit 088. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control87 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> control bit 087. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control86 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> control bit 086. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control85 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> control bit 085. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control84 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> control bit 084. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control83 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> control bit 083. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control82 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> control bit 082. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control81 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> control bit 081. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control80 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> control bit 080. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control79 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> control bit 079. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control78 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> control bit 078. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control77 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> control bit 077. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control76 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> control bit 076. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control75 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> control bit 075. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control74 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> control bit 074. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control73 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> control bit 073. Initiate MTP prefetch initialization. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control72 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> control bit 072. Enable Memory Quota Groups (MQG) </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control71 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> control bit 071. Enable MTP transmit request interface
 *        from OTP
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control70 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> control bit 070. Enable MTP command request interface
 *        from ITP
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control69 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 5 </td>
 *   <td width="30%"> control bit 069. Enable MTP transmit reqeust interface
 *        from ITP
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control68 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 4 </td>
 *   <td width="30%"> control bit 068. Enable MTP Direct memory map allocate
 *        interface
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control67 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 3 </td>
 *   <td width="30%"> control bit 067. Enable MTP prefetch buffer; should
 *        be turned on only after all fifo_cfg_ram and fifo_state_ram
 *        has been initialized.
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control66 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> control bit 066. Enable COW MCIP online </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control65 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> control bit 065. Enable MTP NLINK response interface </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control64 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> control bit 064. Enable MTP NLINK reqeust interface </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_cfg_control0108_r_t
 *
 * Implemented by: 
 *      control0108
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      control95                                 :  1;
     unsigned      control94                                 :  1;
     unsigned      control93                                 :  1;
     unsigned      control92                                 :  1;
     unsigned      control91                                 :  1;
     unsigned      control90                                 :  1;
     unsigned      control89                                 :  1;
     unsigned      control88                                 :  1;
     unsigned      control87                                 :  1;
     unsigned      control86                                 :  1;
     unsigned      control85                                 :  1;
     unsigned      control84                                 :  1;
     unsigned      control83                                 :  1;
     unsigned      control82                                 :  1;
     unsigned      control81                                 :  1;
     unsigned      control80                                 :  1;
     unsigned      control79                                 :  1;
     unsigned      control78                                 :  1;
     unsigned      control77                                 :  1;
     unsigned      control76                                 :  1;
     unsigned      control75                                 :  1;
     unsigned      control74                                 :  1;
     unsigned      control73                                 :  1;
     unsigned      control72                                 :  1;
     unsigned      control71                                 :  1;
     unsigned      control70                                 :  1;
     unsigned      control69                                 :  1;
     unsigned      control68                                 :  1;
     unsigned      control67                                 :  1;
     unsigned      control66                                 :  1;
     unsigned      control65                                 :  1;
     unsigned      control64                                 :  1;
#else    /* Little Endian */
     unsigned      control64                                 :  1;
     unsigned      control65                                 :  1;
     unsigned      control66                                 :  1;
     unsigned      control67                                 :  1;
     unsigned      control68                                 :  1;
     unsigned      control69                                 :  1;
     unsigned      control70                                 :  1;
     unsigned      control71                                 :  1;
     unsigned      control72                                 :  1;
     unsigned      control73                                 :  1;
     unsigned      control74                                 :  1;
     unsigned      control75                                 :  1;
     unsigned      control76                                 :  1;
     unsigned      control77                                 :  1;
     unsigned      control78                                 :  1;
     unsigned      control79                                 :  1;
     unsigned      control80                                 :  1;
     unsigned      control81                                 :  1;
     unsigned      control82                                 :  1;
     unsigned      control83                                 :  1;
     unsigned      control84                                 :  1;
     unsigned      control85                                 :  1;
     unsigned      control86                                 :  1;
     unsigned      control87                                 :  1;
     unsigned      control88                                 :  1;
     unsigned      control89                                 :  1;
     unsigned      control90                                 :  1;
     unsigned      control91                                 :  1;
     unsigned      control92                                 :  1;
     unsigned      control93                                 :  1;
     unsigned      control94                                 :  1;
     unsigned      control95                                 :  1;
#endif
} ncp_nca_cfg_control0108_r_t;

/*! @struct ncp_nca_cfg_control010c_r_t
 *  @brief global configuration register
 *  @details control bits for NCAv3 operation
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_control010c_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param tdglarb </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 30 </td>
 *   <td width="30%"> TDGL arbitration control bits. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param readresp </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 28 </td>
 *   <td width="30%"> AND mask for read response master output from NIC400 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param writeresp </td>
 *     <td width="20%" align="center"> 2 </td>
 *     <td width="20%" align="center"> 26 </td>
 *   <td width="30%"> AND mask for write resonsep master output from NIC400 </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control121 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 25 </td>
 *   <td width="30%"> control bit 121. disable autoinit for atomic RAMs.
 *        ipd->ncap2ipcq, ipd->ipd2, ipd->ipcq2gid
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control120 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> control bit 120. disable autoinit for non-atomic RAMs.
 *        odts->odtd
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control119 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> control bit 119. Disable OTP on interrupt </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control118 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> control bit 118. Disable ITP on interrupt </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control117 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> control bit 117. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control116 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> control bit 116. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control115 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> control bit 115. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control114 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> control bit 114. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control113 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 17 </td>
 *   <td width="30%"> control bit 113. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control112 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> control bit 112. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control111 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 15 </td>
 *   <td width="30%"> control bit 111. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control110 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> control bit 110. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control109 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> control bit 109. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control108 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> control bit 108. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control107 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 11 </td>
 *   <td width="30%"> control bit 107. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control106 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 10 </td>
 *   <td width="30%"> control bit 106. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control105 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 9 </td>
 *   <td width="30%"> control bit 105. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param control104 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> control bit 104. RESERVED </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param flushvalid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> flush valid </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param flushpool </td>
 *     <td width="20%" align="center"> 7 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> flush poolID </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_cfg_control010c_r_t
 *
 * Implemented by: 
 *      control010c
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      tdglarb                                   :  2;
     unsigned      readresp                                  :  2;
     unsigned      writeresp                                 :  2;
     unsigned      control121                                :  1;
     unsigned      control120                                :  1;
     unsigned      control119                                :  1;
     unsigned      control118                                :  1;
     unsigned      control117                                :  1;
     unsigned      control116                                :  1;
     unsigned      control115                                :  1;
     unsigned      control114                                :  1;
     unsigned      control113                                :  1;
     unsigned      control112                                :  1;
     unsigned      control111                                :  1;
     unsigned      control110                                :  1;
     unsigned      control109                                :  1;
     unsigned      control108                                :  1;
     unsigned      control107                                :  1;
     unsigned      control106                                :  1;
     unsigned      control105                                :  1;
     unsigned      control104                                :  1;
     unsigned      flushvalid                                :  1;
     unsigned      flushpool                                 :  7;
#else    /* Little Endian */
     unsigned      flushpool                                 :  7;
     unsigned      flushvalid                                :  1;
     unsigned      control104                                :  1;
     unsigned      control105                                :  1;
     unsigned      control106                                :  1;
     unsigned      control107                                :  1;
     unsigned      control108                                :  1;
     unsigned      control109                                :  1;
     unsigned      control110                                :  1;
     unsigned      control111                                :  1;
     unsigned      control112                                :  1;
     unsigned      control113                                :  1;
     unsigned      control114                                :  1;
     unsigned      control115                                :  1;
     unsigned      control116                                :  1;
     unsigned      control117                                :  1;
     unsigned      control118                                :  1;
     unsigned      control119                                :  1;
     unsigned      control120                                :  1;
     unsigned      control121                                :  1;
     unsigned      writeresp                                 :  2;
     unsigned      readresp                                  :  2;
     unsigned      tdglarb                                   :  2;
#endif
} ncp_nca_cfg_control010c_r_t;

/*! @struct ncp_nca_cfg_fifo0700_r_t
 *  @brief fifo0700
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_fifo0700_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param hwm </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 16 </td>
 *   <td width="30%"> null </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param status </td>
 *     <td width="20%" align="center"> 16 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> null </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_cfg_fifo0700_r_t
 *
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      hwm                                       : 16;
     unsigned      status                                    : 16;
#else    /* Little Endian */
     unsigned      status                                    : 16;
     unsigned      hwm                                       : 16;
#endif
} ncp_nca_cfg_fifo0700_r_t;

/*! @struct ncp_nca_cfg_status0800_r_t
 *  @brief status0800
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0800_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0800_r_t
 *
 * Implemented by: 
 *      status0800
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0800_r_t;

/*! @struct ncp_nca_cfg_status0804_r_t
 *  @brief status0804
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0804_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0804_r_t
 *
 * Implemented by: 
 *      status0804
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0804_r_t;

/*! @struct ncp_nca_cfg_status0808_r_t
 *  @brief status0808
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0808_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0808_r_t
 *
 * Implemented by: 
 *      status0808
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0808_r_t;

/*! @struct ncp_nca_cfg_status080c_r_t
 *  @brief status080c
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status080c_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status080c_r_t
 *
 * Implemented by: 
 *      status080c
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status080c_r_t;

/*! @struct ncp_nca_cfg_status0810_r_t
 *  @brief status0810
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0810_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0810_r_t
 *
 * Implemented by: 
 *      status0810
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0810_r_t;

/*! @struct ncp_nca_cfg_status0814_r_t
 *  @brief status0814
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0814_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0814_r_t
 *
 * Implemented by: 
 *      status0814
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0814_r_t;

/*! @struct ncp_nca_cfg_status0818_r_t
 *  @brief status0818
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0818_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0818_r_t
 *
 * Implemented by: 
 *      status0818
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0818_r_t;

/*! @struct ncp_nca_cfg_status081c_r_t
 *  @brief status081c
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status081c_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status081c_r_t
 *
 * Implemented by: 
 *      status081c
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status081c_r_t;

/*! @struct ncp_nca_cfg_status0820_r_t
 *  @brief status0820
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0820_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0820_r_t
 *
 * Implemented by: 
 *      status0820
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0820_r_t;

/*! @struct ncp_nca_cfg_status0824_r_t
 *  @brief status0824
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0824_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0824_r_t
 *
 * Implemented by: 
 *      status0824
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0824_r_t;

/*! @struct ncp_nca_cfg_status0828_r_t
 *  @brief status0828
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0828_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0828_r_t
 *
 * Implemented by: 
 *      status0828
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0828_r_t;

/*! @struct ncp_nca_cfg_status082c_r_t
 *  @brief status082c
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status082c_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status082c_r_t
 *
 * Implemented by: 
 *      status082c
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status082c_r_t;

/*! @struct ncp_nca_cfg_status0830_r_t
 *  @brief status0830
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0830_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0830_r_t
 *
 * Implemented by: 
 *      status0830
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0830_r_t;

/*! @struct ncp_nca_cfg_status0834_r_t
 *  @brief status0834
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0834_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0834_r_t
 *
 * Implemented by: 
 *      status0834
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0834_r_t;

/*! @struct ncp_nca_cfg_status0838_r_t
 *  @brief status0838
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0838_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0838_r_t
 *
 * Implemented by: 
 *      status0838
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0838_r_t;

/*! @struct ncp_nca_cfg_status083c_r_t
 *  @brief status083c
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status083c_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status083c_r_t
 *
 * Implemented by: 
 *      status083c
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status083c_r_t;

/*! @struct ncp_nca_cfg_status0840_r_t
 *  @brief status0840
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0840_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0840_r_t
 *
 * Implemented by: 
 *      status0840
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0840_r_t;

/*! @struct ncp_nca_cfg_status0844_r_t
 *  @brief status0844
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0844_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0844_r_t
 *
 * Implemented by: 
 *      status0844
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0844_r_t;

/*! @struct ncp_nca_cfg_status0848_r_t
 *  @brief status0848
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0848_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0848_r_t
 *
 * Implemented by: 
 *      status0848
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0848_r_t;

/*! @struct ncp_nca_cfg_status084c_r_t
 *  @brief status084c
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status084c_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status084c_r_t
 *
 * Implemented by: 
 *      status084c
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status084c_r_t;

/*! @struct ncp_nca_cfg_status0850_r_t
 *  @brief status0850
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0850_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0850_r_t
 *
 * Implemented by: 
 *      status0850
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0850_r_t;

/*! @struct ncp_nca_cfg_status0854_r_t
 *  @brief status0854
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0854_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0854_r_t
 *
 * Implemented by: 
 *      status0854
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0854_r_t;

/*! @struct ncp_nca_cfg_status0858_r_t
 *  @brief status0858
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0858_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0858_r_t
 *
 * Implemented by: 
 *      status0858
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0858_r_t;

/*! @struct ncp_nca_cfg_status085c_r_t
 *  @brief status085c
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status085c_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status085c_r_t
 *
 * Implemented by: 
 *      status085c
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status085c_r_t;

/*! @struct ncp_nca_cfg_status0860_r_t
 *  @brief status0860
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0860_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0860_r_t
 *
 * Implemented by: 
 *      status0860
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0860_r_t;

/*! @struct ncp_nca_cfg_status0864_r_t
 *  @brief status0864
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0864_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0864_r_t
 *
 * Implemented by: 
 *      status0864
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0864_r_t;

/*! @struct ncp_nca_cfg_status0868_r_t
 *  @brief status0868
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0868_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0868_r_t
 *
 * Implemented by: 
 *      status0868
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0868_r_t;

/*! @struct ncp_nca_cfg_status086c_r_t
 *  @brief status086c
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status086c_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status086c_r_t
 *
 * Implemented by: 
 *      status086c
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status086c_r_t;

/*! @struct ncp_nca_cfg_status0870_r_t
 *  @brief status0870
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0870_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0870_r_t
 *
 * Implemented by: 
 *      status0870
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0870_r_t;

/*! @struct ncp_nca_cfg_status0874_r_t
 *  @brief status0874
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0874_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0874_r_t
 *
 * Implemented by: 
 *      status0874
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0874_r_t;

/*! @struct ncp_nca_cfg_status0878_r_t
 *  @brief status0878
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status0878_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status0878_r_t
 *
 * Implemented by: 
 *      status0878
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status0878_r_t;

/*! @struct ncp_nca_cfg_status087c_r_t
 *  @brief status087c
 *  @details null
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_status087c_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_status087c_r_t
 *
 * Implemented by: 
 *      status087c
 */
 
typedef struct
{
     unsigned  int                  reserved;
} ncp_nca_cfg_status087c_r_t;

/*! @struct ncp_nca_cfg_cfg_setup_r_t
 *  @brief null
 *  @details cfg_setup reigster for CFG block
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_cfg_setup_r_t\n
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
 * Applies to: xlf --> ncp_nca_cfg_cfg_setup_r_t
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
} ncp_nca_cfg_cfg_setup_r_t;

/*! @struct ncp_nca_cfg_cfg_dynamic_cmd_r_t
 *  @brief null
 *  @details dynamic command register. This register is used to issue dynamic atomic commands to NCA
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_cfg_dynamic_cmd_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param command </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> dynamic command </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param parameters </td>
 *     <td width="20%" align="center"> 24 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> parameters assoicated with command </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_cfg_cfg_dynamic_cmd_r_t
 *
 * Implemented by: 
 *      cfg_dynamic_cmd
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      command                                   :  8;
     unsigned      parameters                                : 24;
#else    /* Little Endian */
     unsigned      parameters                                : 24;
     unsigned      command                                   :  8;
#endif
} ncp_nca_cfg_cfg_dynamic_cmd_r_t;

/*! @struct ncp_nca_cfg_cfg_dynamic_status_r_t
 *  @brief null
 *  @details dynamic status register.
 *  <table width="70%" align="center">
 *  <tr>
 *   <td colspan="4" align="center">
 *    struct ncp_nca_cfg_cfg_dynamic_status_r_t\n
 *   </td>
 *  </tr>
 *  <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *  </tr>
 *   <tr>
 *     <td width="30%"> @param command </td>
 *     <td width="20%" align="center"> 8 </td>
 *     <td width="20%" align="center"> 24 </td>
 *   <td width="30%"> the dynamic command currently active </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param valid </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 23 </td>
 *   <td width="30%"> A dynamic command was issued </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param collision </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 22 </td>
 *   <td width="30%"> A dynamic command was issued and collided with a previous
 *        command. This bit must be cleared to enable dynamic
 *        command operation
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param active </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 21 </td>
 *   <td width="30%"> The dynamic command is active in ALL modules of NCA </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param done </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 20 </td>
 *   <td width="30%"> The dynamic command is done in ALL modules of NCA </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pf </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 19 </td>
 *   <td width="30%"> The dynamic command pass/fail bit. Will indicate a
 *        fail(0) if any module returns a non PASS response
 *        code
 *   </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param reserved0 </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 18 </td>
 *   <td width="30%"> Reserved for future use </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param mtp_code </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 14 </td>
 *   <td width="30%"> MTP done response code </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param mtp_active </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 13 </td>
 *   <td width="30%"> MTP active. ITP has begun operation of command </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param mtp_done </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 12 </td>
 *   <td width="30%"> MTP done processing command. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param otp_code </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 8 </td>
 *   <td width="30%"> OTP done response code </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param otp_active </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 7 </td>
 *   <td width="30%"> OTP active. ITP has begun operation of command </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param otp_done </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 6 </td>
 *   <td width="30%"> OTP done processing command. </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param itp_code </td>
 *     <td width="20%" align="center"> 4 </td>
 *     <td width="20%" align="center"> 2 </td>
 *   <td width="30%"> ITP done response code </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param itp_active </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 1 </td>
 *   <td width="30%"> ITP active. ITP has begun operation of command </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param itp_done </td>
 *     <td width="20%" align="center"> 1 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> ITP done processing command. </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_cfg_cfg_dynamic_status_r_t
 *
 * Implemented by: 
 *      cfg_dynamic_status
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
     unsigned      command                                   :  8;
     unsigned      valid                                     :  1;
     unsigned      collision                                 :  1;
     unsigned      active                                    :  1;
     unsigned      done                                      :  1;
     unsigned      pf                                        :  1;
     unsigned      reserved0                                 :  1;
     unsigned      mtp_code                                  :  4;
     unsigned      mtp_active                                :  1;
     unsigned      mtp_done                                  :  1;
     unsigned      otp_code                                  :  4;
     unsigned      otp_active                                :  1;
     unsigned      otp_done                                  :  1;
     unsigned      itp_code                                  :  4;
     unsigned      itp_active                                :  1;
     unsigned      itp_done                                  :  1;
#else    /* Little Endian */
     unsigned      itp_done                                  :  1;
     unsigned      itp_active                                :  1;
     unsigned      itp_code                                  :  4;
     unsigned      otp_done                                  :  1;
     unsigned      otp_active                                :  1;
     unsigned      otp_code                                  :  4;
     unsigned      mtp_done                                  :  1;
     unsigned      mtp_active                                :  1;
     unsigned      mtp_code                                  :  4;
     unsigned      reserved0                                 :  1;
     unsigned      pf                                        :  1;
     unsigned      done                                      :  1;
     unsigned      active                                    :  1;
     unsigned      collision                                 :  1;
     unsigned      valid                                     :  1;
     unsigned      command                                   :  8;
#endif
} ncp_nca_cfg_cfg_dynamic_status_r_t;

#ifdef __cplusplus
}
#endif

#endif /* _NCP_NCA_CFG_REGS_H_ */
