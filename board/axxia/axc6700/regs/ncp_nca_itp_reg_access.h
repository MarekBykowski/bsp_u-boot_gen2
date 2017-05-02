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


#ifndef _NCP_NCA_ITP_REG_ACCESS_H_
#define _NCP_NCA_ITP_REG_ACCESS_H_

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




static ncp_access_map_t  ncpNcaItp[] = {

    { 0x00100000,  0x00100000, 4, 1 },
    { 0x00000000,  0x00000010, 4, 1 },
    { 0x00000070,  0x00000088, 4, 1 },
    { 0x00000090,  0x000001d0, 4, 1 },
    { 0x00000700,  0x000007c0, 4, 1 },
    { 0x00000800,  0x00000850, 4, 1 },
    { 0x00000880,  0x000008d8, 4, 1 },
    { 0x00000e00,  0x00000efc, 4, 1 },
    { 0x00000f00,  0x00001000, 4, 1 },
    { 0x00003e00,  0x00003e34, 4, 1 },
    { 0x00008800,  0x00008a00, 4, 1 },
    { 0x00010000,  0x00010330, 4, 1 },
    { 0x00014000,  0x00014040, 4, 1 },
    { 0x0001e000,  0x0001e804, 4, 1 },
    { 0x0001e800,  0x0001ec00, 4, 1 },
    { 0x0001f000,  0x0001f804, 4, 1 },
    { 0x0001f800,  0x0001fc00, 4, 1 },
    { 0x00020000,  0x00022000, 4, 1 },
    { 0x00024000,  0x00025000, 4, 1 },
    { 0x00030000,  0x00035004, 4, 1 },
    { 0x00040000,  0x00040400, 4, 1 },
    { 0x00044000,  0x00045000, 4, 1 },
    { 0x00048000,  0x00049000, 4, 1 },
    { 0x00050000,  0x00050ac0, 4, 1 },
    { 0x00054000,  0x00056004, 4, 1 },
    { 0x00058000,  0x00059000, 4, 1 },
    { 0x00064000,  0x00066000, 4, 1 },
    { 0x00071000,  0x00072000, 4, 1 },
    { 0x00073000,  0x00074000, 4, 1 },
    { 0x0007f000,  0x0007f800, 4, 1 },
    { 0x0007ff40,  0x0007ff4c, 4, 1 },
    { 0x0007ff60,  0x0007ff6c, 4, 1 },
    { 0x0007ff80,  0x0007ff8c, 4, 1 },
    { 0x0007ffa0,  0x0007ffac, 4, 1 },
    { 0x0007ffe0,  0x00080000, 4, 1 },
    { 0x00000010,  0x00000070, 4, 1 },
    { 0x00001000,  0x00001cc0, 4, 4 },
    { 0x00003000,  0x00003100, 4, 8 },
    { 0x00003100,  0x00003500, 4, 2 },
    { 0x00003500,  0x00003800, 4, 8 },
    { 0x00003800,  0x00003c00, 4, 2 },
    { 0x00003c00,  0x00003cd0, 4, 4 },
    { 0x00003d00,  0x00003d68, 4, 2 },
    { 0x00004000,  0x00007400, 4, 8 },
    { 0x00008000,  0x00008560, 4, 4 },
    { 0x00009000,  0x0000b000, 4, 8 },
    { 0x0000c000,  0x00010000, 4, 8 },
    { 0x00018000,  0x00018400, 4, 16 },
    { 0x00028000,  0x00030000, 4, 8 },
    { 0x00038000,  0x00040000, 4, 8 },
    { 0x00060000,  0x00060800, 4, 2 },
    { 0x00068000,  0x00070800, 4, 4 },
    { 0x0007e000,  0x0007eac0, 4, 8 },

};

#ifdef __cplusplus
}
#endif

#endif /* _NCP_NCA_ITP_REG_ACCESS_H_ */
