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


#ifndef _NCP_NLINK_MPCQ_REQ_REG_ACCESS_H_
#define _NCP_NLINK_MPCQ_REQ_REG_ACCESS_H_

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




static ncp_access_map_t  ncpNlinkMpcqReq[] = {

    { 0x00024000,  0x00024000, 4, 1 },
    { 0x00000100,  0x0000010c, 4, 1 },
    { 0x00000200,  0x00000208, 4, 1 },
    { 0x00000400,  0x00000408, 4, 1 },
    { 0x00000600,  0x00000608, 4, 1 },
    { 0x00000800,  0x00000838, 4, 1 },
    { 0x00000900,  0x00000914, 4, 1 },
    { 0x00000a00,  0x00000a04, 4, 1 },
    { 0x00000b00,  0x00000b20, 4, 1 },
    { 0x00000c00,  0x00000c08, 4, 1 },
    { 0x00000c10,  0x00000c20, 4, 1 },
    { 0x00000010,  0x00000020, 4, 1 },

};

#ifdef __cplusplus
}
#endif

#endif /* _NCP_NLINK_MPCQ_REQ_REG_ACCESS_H_ */
