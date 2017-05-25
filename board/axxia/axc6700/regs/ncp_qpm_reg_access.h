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


#ifndef _NCP_QPM_REG_ACCESS_H_
#define _NCP_QPM_REG_ACCESS_H_

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




static ncp_access_map_t  ncpQpm[] = {

    { 0x00000100,  0x00000104, 4, 1 },
    { 0x00000108,  0x0000010c, 4, 1 },
    { 0x00000110,  0x00000114, 4, 1 },
    { 0x00000118,  0x0000011c, 4, 1 },
    { 0x00000200,  0x00000204, 4, 1 },
    { 0x00000208,  0x0000020c, 4, 1 },
    { 0x00000210,  0x00000214, 4, 1 },
    { 0x00000218,  0x0000021c, 4, 1 },
    { 0x00000220,  0x00000224, 4, 1 },
    { 0x00000228,  0x0000022c, 4, 1 },
    { 0x00000230,  0x00000234, 4, 1 },
    { 0x00000238,  0x0000023c, 4, 1 },
    { 0x000003f8,  0x000003fc, 4, 1 },
    { 0x00000008,  0x00000020, 4, 1 },
    { 0x00000040,  0x00000060, 4, 2 },
    { 0x00000400,  0x00000500, 4, 2 },
    { 0x00000020,  0x00000028, 4, 2 },
    { 0x00000030,  0x00000038, 4, 2 },
    { 0x00000060,  0x00000080, 4, 2 },
    { 0x00000098,  0x000000a8, 4, 2 },
    { 0x000000b0,  0x000000d0, 4, 2 },
    { 0x000000f0,  0x000000f8, 4, 2 },
    { 0x00000120,  0x00000168, 4, 2 },
    { 0x00000180,  0x00000190, 4, 2 },
    { 0x00000300,  0x00000328, 4, 2 },
    { 0x00001000,  0x00001028, 4, 2 },
    { 0x01000070,  0x01000078, 4, 2 },

};

#ifdef __cplusplus
}
#endif

#endif /* _NCP_QPM_REG_ACCESS_H_ */
