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


#ifndef _NCP_NCA_OTP_REG_ACCESS_H_
#define _NCP_NCA_OTP_REG_ACCESS_H_

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




static ncp_access_map_t  ncpNcaOtp[] = {

    { 0x00180000,  0x00180000, 4, 1 },
    { 0x00000000,  0x00000010, 4, 1 },
    { 0x00000070,  0x00000088, 4, 1 },
    { 0x00000090,  0x00000098, 4, 1 },
    { 0x000000e0,  0x00000148, 4, 1 },
    { 0x00000700,  0x00000760, 4, 1 },
    { 0x00000800,  0x00000838, 4, 1 },
    { 0x00000e00,  0x00000eb8, 4, 1 },
    { 0x00000f00,  0x00000fb8, 4, 1 },
    { 0x00000ffc,  0x00001000, 4, 1 },
    { 0x00002000,  0x00002040, 4, 1 },
    { 0x0000e800,  0x0000ec00, 4, 1 },
    { 0x0000f000,  0x0000f400, 4, 1 },
    { 0x00010000,  0x00010040, 4, 1 },
    { 0x00013000,  0x00013200, 4, 1 },
    { 0x00014000,  0x00014040, 4, 1 },
    { 0x00018000,  0x00018400, 4, 1 },
    { 0x00019000,  0x00019040, 4, 1 },
    { 0x00000010,  0x00000070, 4, 1 },
    { 0x00001000,  0x00001080, 4, 2 },
    { 0x00003000,  0x00007000, 4, 8 },
    { 0x0000b000,  0x0000b300, 4, 8 },
    { 0x0000b600,  0x0000ba00, 4, 2 },
    { 0x0000bc00,  0x0000bf00, 4, 8 },
    { 0x0000c200,  0x0000c600, 4, 2 },
    { 0x0000c800,  0x0000cb00, 4, 8 },
    { 0x0000ce00,  0x0000d200, 4, 2 },
    { 0x0000e000,  0x0000e800, 4, 2 },
    { 0x00011000,  0x00011800, 4, 32 },
    { 0x00012000,  0x00012200, 4, 8 },
    { 0x00016000,  0x00016080, 4, 2 },
    { 0x0001b000,  0x0001b800, 4, 32 },
    { 0x0001c000,  0x0001c200, 4, 2 },

};

#ifdef __cplusplus
}
#endif

#endif /* _NCP_NCA_OTP_REG_ACCESS_H_ */
