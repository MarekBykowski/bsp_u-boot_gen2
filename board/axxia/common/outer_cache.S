#include <config.h>
#include <linux/linkage.h>


dgb_set:
	/* x0: set, x1: way, x2: tag
	   value: set address for L3
	   tag: 0b01 L3 data read. 0b10 L3 tag read 
	 */
	mov	x10, 0x20
1:	mov	x11, 0x10000
	mul	x11, x10, x11
	ldr	x12, =(DICKENS + 0x300) /*read hn_cfg_l3sf_dbgrd*/
	add x11, x11, x12
	mov x13, x0
	orr x13, x13, x1
	orr x13, x13, x2
	orr x13, x13, x3, lsl #24
	bic x13, x13, #0x100000 /*OW: presumably a don't-care for tag access*/ 
	str x13, [x11]		/*write hn_cfg_l4sf_dbgrd*/
	add	w10, w10, 1
	cmp	w10, 0x27
	ble	1b
	ret

calc_hnf:
	ret	


ENTRY(__asm_dbg_set_tag_l3)
	mov x9, x30
	bic x0, x0, 0xfffffffffffff000
	bic x1, x1, 0xfffffffffffffff0
	lsl x1, x1, #16
	bic x2, x2, 0xfffffffffffffff8
	lsl x2, x2, #20
	bl calc_hnf
	bl dgb_set
	mov x30, x9
	ret
ENDPROC(__asm_dbg_set_tag_l3)

ENTRY(__diable_ecc_parity_l3)
	mov x9, x30
	mov	x10, 0x20
1:	mov	x11, 0x10000
	mul	x11, x10, x11
	ldr	x12, =(DICKENS + 0x0) /*hnf_cfg_ctrl*/
	add	x11, x11, x12
	ldr x13, [x11]
	orr x13, x13, #0x2<<13 /*set bits*/
	str x13, [x11] 
	add	w10, w10, 1
	cmp	w10, 0x27
	ble	1b
	mov x30, x9
	ret
ENDPROC(__diable_ecc_parity_l3)

/*
  ------------------------------------------------------------------------------
  set_outer_cache_state

  Set the mode in (0x10000 * offset) + 0x10, bits 1:0.  Verify that it
  got set by reading (0x10000 * offset) + 0x18), bits 3:2.

  The modes are as follows.

  0b00 - OFF
  0b01 - SFONLY
  0b10 - HALF
  0b11 - FULL
*/

set_outer_cache_state:
#ifndef CONFIG_TARGET_SIMULATION
	/* Make sure the give state is valid (0, 1, 2, or 3). */
	mov	w10, ~0x3
	and	w10, w0, w10
	cbnz	w10, set_outer_cache_state_failed

	/* Set the state. */
	mov	x10, 0x20
1:	mov	x11, 0x10000
	mul	x11, x10, x11
	/*ldr	x12, =(DICKENS + 0x10)*/
	mov x12, #0x10
	movk x12, #0x40, lsl #32 /*40_0000_0000*/
	add	x11, x11, x12
	str	w0, [x11]
	add	w10, w10, 1
	cmp	w10, 0x27
	ble	1b

	/* Wait for completion. */
	mov	x10, 0x20
1:	mov	x11, 0x10000
	mul	x11, x10, x11
	/*ldr	x12, =(DICKENS + 0x18)*/
	mov x12, #0x18
	movk x12, #0x40, lsl #32 /*40_0000_0000*/
	add	x11, x11, x12
2:	ldr	w13, [x11]
	and 	w13, w13, 0xf
	lsr	w13, w13, 2
	cmp	w0, w13
	bne	2b
	add	x10, x10, 1
	cmp	x10, 0x27
	ble	1b
	b	set_outer_cache_state_succeeded

set_outer_cache_state_failed:
	mov	x0, -1
	ret
set_outer_cache_state_succeeded:
#endif /* CONFIG_TARGET_SIMULATION */
	dsb sy
	isb
	mov	x0, 0
	ret

ENTRY(__asm_flush_l3_cache)
	mov	x9, x30
	mov	x0, 0
	bl	set_outer_cache_state
#ifndef LEAVE_L3_IN_SFONLY
	mov	x0, 3
	bl	set_outer_cache_state
#endif
	mov	x30, x9
	ret
ENDPROC(__asm_flush_l3_cache)

ENTRY(__asm_disable_l3_cache)
	mov	x9, x30
	mov	x0, 0
	bl	set_outer_cache_state
	mov	x30, x9
	ret
ENDPROC(__asm_disable_l3_cache)

ENTRY(__asm_enable_l3_cache)
#ifndef LEAVE_L3_IN_SFONLY
	mov	x9, x30
	mov	x0, 3
	bl	set_outer_cache_state
	mov	x30, x9
#endif
	ret
ENDPROC(__asm_enable_l3_cache)
