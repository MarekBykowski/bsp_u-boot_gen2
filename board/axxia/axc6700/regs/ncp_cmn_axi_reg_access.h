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


#ifndef _NCP_CMN_AXI_REG_ACCESS_H_
#define _NCP_CMN_AXI_REG_ACCESS_H_

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




static ncp_access_map_t  ncpCmnAxi[] = {

    { 0x00000090,  0x000000a4, 4, 1 },
    { 0x000000e0,  0x00000100, 4, 1 },
    { 0x00001000,  0x00001204, 4, 1 },
    { 0x0000ff00,  0x0000ff04, 4, 1 },
    { 0x0000ff80,  0x00010000, 4, 1 },
    { 0x00010010,  0x00010014, 4, 1 },
    { 0x00010270,  0x00010274, 4, 1 },
    { 0x0001ff00,  0x00020000, 4, 1 },
    { 0x00020090,  0x00020094, 4, 1 },
    { 0x000200e0,  0x00020104, 4, 1 },
    { 0x00020114,  0x0002012c, 4, 1 },
    { 0x000206f0,  0x00020700, 4, 1 },
    { 0x00020818,  0x00020844, 4, 1 },
    { 0x00020e00,  0x00020e50, 4, 1 },
    { 0x00020ffc,  0x00021000, 4, 1 },
    { 0x0001f020,  0x0001f050, 4, 1 },
    { 0x00020010,  0x00020090, 4, 1 },
    { 0x00020004,  0x0002000c, 4, 2 },

};

#ifdef __cplusplus
}
#endif

#endif /* _NCP_CMN_AXI_REG_ACCESS_H_ */
