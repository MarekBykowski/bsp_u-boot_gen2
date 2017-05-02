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


#ifndef _NCP_CAAL_NCAP_MEM_REG_ACCESS_H_
#define _NCP_CAAL_NCAP_MEM_REG_ACCESS_H_

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




static ncp_access_map_t  ncpCaalNcapMem[] = {

    { 0x00000000,  0x00000010, 4, 1 },
    { 0x0000001c,  0x00000020, 4, 1 },
    { 0x00000040,  0x00000048, 4, 1 },
    { 0x00000080,  0x00000090, 4, 1 },
    { 0x000000c0,  0x000000cc, 4, 1 },
    { 0x000000f8,  0x00000180, 4, 1 },
    { 0x00000200,  0x00000208, 4, 1 },
    { 0x00000240,  0x00000260, 4, 1 },
    { 0x0000026c,  0x00000274, 4, 1 },
    { 0x00000280,  0x000002a0, 4, 1 },
    { 0x000002a4,  0x000002ac, 4, 1 },
    { 0x00000300,  0x00000320, 4, 1 },
    { 0x00000380,  0x0000038c, 4, 1 },
    { 0x000003c0,  0x000003c8, 4, 1 },
    { 0x000003fc,  0x00000400, 4, 1 },
    { 0x00000010,  0x0000001c, 4, 1 },
    { 0x00001000,  0x00001400, 4, 4 },
    { 0x00000020,  0x00000040, 4, 2 },
    { 0x000000d0,  0x000000f8, 4, 2 },
    { 0x00000180,  0x000001e0, 4, 8 },
    { 0x00000320,  0x00000380, 4, 8 },

};

#ifdef __cplusplus
}
#endif

#endif /* _NCP_CAAL_NCAP_MEM_REG_ACCESS_H_ */
