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


#ifndef _NCP_NCAP_REG_ACCESS_H_
#define _NCP_NCAP_REG_ACCESS_H_

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




static ncp_access_map_t  ncpNcap[] = {

    { 0x00010010,  0x0001001c, 4, 1 },
    { 0x00010020,  0x00010024, 4, 1 },
    { 0x00010028,  0x0001002c, 4, 1 },
    { 0x00010030,  0x00010034, 4, 1 },
    { 0x00010040,  0x00010050, 4, 1 },
    { 0x00010080,  0x000100a0, 4, 1 },
    { 0x00010100,  0x00010120, 4, 1 },
    { 0x00010180,  0x000101a0, 4, 1 },
    { 0x00010270,  0x00010274, 4, 1 },
    { 0x00010278,  0x00010284, 4, 1 },
    { 0x00010290,  0x00010294, 4, 1 },
    { 0x00010298,  0x0001029c, 4, 1 },
    { 0x00010300,  0x00010320, 4, 1 },
    { 0x00018000,  0x00018024, 4, 1 },
    { 0x00018038,  0x0001803c, 4, 1 },
    { 0x00018040,  0x00018060, 4, 1 },
    { 0x00018078,  0x0001807c, 4, 1 },
    { 0x000180c0,  0x000180c4, 4, 1 },
    { 0x00018100,  0x00018120, 4, 1 },
    { 0x00018180,  0x000181a0, 4, 1 },
    { 0x00018200,  0x00018220, 4, 1 },
    { 0x00018280,  0x000182a0, 4, 1 },
    { 0x00018300,  0x00018320, 4, 1 },
    { 0x00018400,  0x00018404, 4, 1 },
    { 0x00018480,  0x00018484, 4, 1 },
    { 0x00018500,  0x00018508, 4, 1 },
    { 0x00018600,  0x00018604, 4, 1 },
    { 0x00018700,  0x00018704, 4, 1 },
    { 0x0001a000,  0x0001a02c, 4, 1 },
    { 0x0001a200,  0x0001a218, 4, 1 },
    { 0x0001a280,  0x0001a2c0, 4, 1 },
    { 0x0001a300,  0x0001a340, 4, 1 },
    { 0x0001a400,  0x0001a410, 4, 1 },
    { 0x0001a480,  0x0001a490, 4, 1 },
    { 0x0001a500,  0x0001a510, 4, 1 },
    { 0x0001a800,  0x0001a828, 4, 1 },
    { 0x0001a880,  0x0001a8c0, 4, 1 },
    { 0x0001a900,  0x0001a940, 4, 1 },
    { 0x0001b000,  0x0001b034, 4, 1 },
    { 0x0001b200,  0x0001b21c, 4, 1 },
    { 0x0001b218,  0x0001b230, 4, 1 },
    { 0x0001b22c,  0x0001b244, 4, 1 },
    { 0x0001b240,  0x0001b248, 4, 1 },
    { 0x0001b280,  0x0001b2a0, 4, 1 },
    { 0x0001b300,  0x0001b320, 4, 1 },
    { 0x0001b400,  0x0001b418, 4, 1 },
    { 0x0001b480,  0x0001b488, 4, 1 },
    { 0x0001b4a0,  0x0001b4a8, 4, 1 },
    { 0x0001b800,  0x0001b828, 4, 1 },
    { 0x0001b880,  0x0001b8a0, 4, 1 },
    { 0x0001c000,  0x0001c020, 4, 1 },
    { 0x0001c200,  0x0001c21c, 4, 1 },
    { 0x0001c218,  0x0001c248, 4, 1 },
    { 0x0001c244,  0x0001c25c, 4, 1 },
    { 0x0001c400,  0x0001c410, 4, 1 },
    { 0x0001c800,  0x0001c824, 4, 1 },
    { 0x0001cc00,  0x0001ccc0, 4, 1 },
    { 0x0001d000,  0x0001d300, 4, 1 },
    { 0x0001d400,  0x0001d700, 4, 1 },
    { 0x0001d800,  0x0001d8c0, 4, 1 },
    { 0x0001e000,  0x0001e010, 4, 1 },
    { 0x0001e200,  0x0001e20c, 4, 1 },
    { 0x0001e400,  0x0001e40c, 4, 1 },
    { 0x0001e480,  0x0001e4b0, 4, 1 },
    { 0x0001f000,  0x0001f004, 4, 1 },
    { 0x0001f008,  0x0001f010, 4, 1 },
    { 0x0001f200,  0x0001f204, 4, 1 },
    { 0x0001f210,  0x0001f214, 4, 1 },
    { 0x0001f220,  0x0001f230, 4, 1 },
    { 0x0001f238,  0x0001f23c, 4, 1 },
    { 0x0001f300,  0x0001f304, 4, 1 },
    { 0x0001f310,  0x0001f314, 4, 1 },
    { 0x0001f320,  0x0001f334, 4, 1 },
    { 0x0001f338,  0x0001f33c, 4, 1 },
    { 0x00010400,  0x00010500, 4, 1 },
    { 0x00011000,  0x00011080, 4, 1 },
    { 0x00011400,  0x00011440, 4, 1 },
    { 0x00011800,  0x00011880, 4, 1 },
    { 0x00011c00,  0x00011c40, 4, 1 },
    { 0x00012000,  0x00012100, 4, 1 },
    { 0x00012800,  0x00012880, 4, 1 },
    { 0x00014000,  0x00014c00, 4, 1 },
    { 0x00016000,  0x00016600, 4, 1 },
    { 0x00018800,  0x00018880, 4, 1 },
    { 0x0001ac00,  0x0001ac40, 4, 1 },
    { 0x0001bc00,  0x0001bc40, 4, 1 },
    { 0x0001ca00,  0x0001ca40, 4, 1 },
    { 0x0001e600,  0x0001e610, 4, 1 },
    { 0x0001f010,  0x0001f018, 4, 1 },
    { 0x0001f020,  0x0001f028, 4, 1 },
    { 0x0001f030,  0x0001f038, 4, 1 },
    { 0x0001f040,  0x0001f048, 4, 1 },
    { 0x0001f240,  0x0001f248, 4, 1 },
    { 0x0001f340,  0x0001f348, 4, 1 },

};

#ifdef __cplusplus
}
#endif

#endif /* _NCP_NCAP_REG_ACCESS_H_ */
