/*
*  board/common/axxia/l3_cache.c
*
*  Copyright (C) 2013 LSI (john.jacques@lsi.com)
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <config.h>
#include <common.h>

/*static int hnfnum[8] = {2 , 5 , 6 , 9 , 20, 23 , 24 , 27} ;  */

void 
calc_hnf_num_tgt(unsigned long addr, int hnf_num, int hnf_tgt)
{
	/* From documentation: identifier: 
	 * WhichHN[2:0] = {1'b0,addr[43:42]} ^ ... ^ addr[11:9] ^ addr[8:6]; 
	 */
	int i;
	hnf_num = 0;
	for (i=6; i<=42; i+=3)
		hnf_num = hnf_num ^ ( (addr>>i) & 7 );
	
	hnf_tgt = hnf_num + 0x20;
	
	return;
}

int 
calc_set(unsigned long addr)
{
	return (addr >> 6 ) & 0xfff;
}

