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


#ifndef _NCP_NCA_REGS_H_
#define _NCP_NCA_REGS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"

/*! @struct ncp_nca_ncav3_dmm_r_t
 *  @brief Multi-word data structure
 *  <table width="70%" align="center">
 *   <tr>
 *     <td colspan="4" align="center">
 *       struct ncp_nca_ncav3_dmm_r_t
 *     </td>
 *   </tr>
 *   <tr>
 *     <td width="30%"><b> Name </b></td>
 *     <td width="20%" align="center"><b> Width </b></td>
 *     <td width="20%" align="center"><b> Start Offset </b></td>
 *     <td width="30%"><b> Description </b></td>
 *   </tr>
 *   <tr>
 *     <td width="30%"> @param pointer_63_32 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of pointer. pointer </td>
 * </tr>
 *   <tr>
 *     <td width="30%"> @param pointer_31_0 </td>
 *     <td width="20%" align="center"> 32 </td>
 *     <td width="20%" align="center"> 0 </td>
 *   <td width="30%"> 32 bits of pointer. pointer </td>
 * </tr>
 * </table>
 * Applies to: xlf --> ncp_nca_ncav3_dmm_r_t
 *
 * Implemented by: 
 *      ncav3_dmm
 */
 
typedef struct
{
#ifdef NCP_BIG_ENDIAN
          /* word 0 */
     unsigned      pointer_63_32                             : 32;
          /* word 1 */
     unsigned      pointer_31_0                              : 32;
#else    /* Little Endian */
          /* word 0 */
     unsigned      pointer_63_32                             : 32;
          /* word 1 */
     unsigned      pointer_31_0                              : 32;
#endif
} ncp_nca_ncav3_dmm_r_t;

#ifdef __cplusplus
}
#endif

#endif /* _NCP_NCA_REGS_H_ */
