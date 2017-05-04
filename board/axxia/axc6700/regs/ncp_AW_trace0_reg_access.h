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


#ifndef _NCP_AW_TRACE0_REG_ACCESS_H_
#define _NCP_AW_TRACE0_REG_ACCESS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncp_sal_types.h"



/******************************
typedef struct ncp_access_map_s {
    ncp_uint32_t    begin;
    ncp_uint32_t    end;
    ncp_int32_t     word_size_in_bytes;
    ncp_int32_t     access_size_in_words;
} ncp_access_map_t;
******************************/




static ncp_access_map_t  ncpAwTrace0[] = {

    { 0x00000100,  0x00000108, 4, 1 },
    { 0x00000120,  0x00000134, 4, 1 },
    { 0x00000700,  0x00000710, 4, 1 },
    { 0x00000800,  0x00000804, 4, 1 },
    { 0x00000814,  0x00000818, 4, 1 },
    { 0x00000ffc,  0x00001000, 4, 1 },
    { 0x00000010,  0x00000090, 4, 1 },
    { 0x00000108,  0x00000120, 4, 2 },
    { 0x00000804,  0x00000814, 4, 2 },
    { 0x00001000,  0x000010e0, 4, 4 },

};

#ifdef __cplusplus
}
#endif

#endif /* _NCP_AW_TRACE0_REG_ACCESS_H_ */
