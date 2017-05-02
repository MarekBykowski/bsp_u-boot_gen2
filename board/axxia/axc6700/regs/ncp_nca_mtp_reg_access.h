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


#ifndef _NCP_NCA_MTP_REG_ACCESS_H_
#define _NCP_NCA_MTP_REG_ACCESS_H_

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




static ncp_access_map_t  ncpNcaMtp[] = {

    { 0x00200000,  0x00200000, 4, 1 },
    { 0x00000000,  0x00000010, 4, 1 },
    { 0x00000070,  0x00000074, 4, 1 },
    { 0x00000090,  0x0000009c, 4, 1 },
    { 0x000000e0,  0x00000130, 4, 1 },
    { 0x00000700,  0x00000740, 4, 1 },
    { 0x00000800,  0x000009e8, 4, 1 },
    { 0x00000e00,  0x00000e60, 4, 1 },
    { 0x00000f00,  0x00000f60, 4, 1 },
    { 0x00000ffc,  0x00001000, 4, 1 },
    { 0x00002000,  0x00002180, 4, 1 },
    { 0x00002200,  0x00002380, 4, 1 },
    { 0x00002400,  0x00002580, 4, 1 },
    { 0x00003000,  0x00005004, 4, 1 },
    { 0x00007000,  0x00007300, 4, 1 },
    { 0x00007400,  0x00007700, 4, 1 },
    { 0x00007800,  0x00007b00, 4, 1 },
    { 0x00007c00,  0x00007f00, 4, 1 },
    { 0x00008000,  0x00008300, 4, 1 },
    { 0x00008400,  0x00008700, 4, 1 },
    { 0x00008800,  0x00008b00, 4, 1 },
    { 0x00008c00,  0x00008f00, 4, 1 },
    { 0x00009000,  0x00009400, 4, 1 },
    { 0x0000a000,  0x0000a400, 4, 1 },
    { 0x0000f000,  0x0000f180, 4, 1 },
    { 0x00000010,  0x00000070, 4, 1 },
    { 0x00001000,  0x00001300, 4, 2 },
    { 0x00001400,  0x00001700, 4, 2 },
    { 0x00001800,  0x00001b00, 4, 2 },
    { 0x0000b000,  0x0000b100, 4, 8 },
    { 0x0000b200,  0x0000b300, 4, 8 },
    { 0x0000c000,  0x0000c400, 4, 2 },
    { 0x0000c800,  0x0000cc00, 4, 2 },
    { 0x0000d000,  0x0000d100, 4, 8 },
    { 0x0000e000,  0x0000e400, 4, 2 },

};

#ifdef __cplusplus
}
#endif

#endif /* _NCP_NCA_MTP_REG_ACCESS_H_ */
