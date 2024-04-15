	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 3
	.globl	_fibonacci                      ; -- Begin function fibonacci
	.p2align	2
_fibonacci:                             ; @fibonacci
	.cfi_startproc
; %bb.0:
	stp	x20, x19, [sp, #-32]!           ; 16-byte Folded Spill
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	mov	x19, x0
	cbz	w0, LBB0_3
; %bb.1:
	subs	w0, w19, #1
	b.eq	LBB0_3
; %bb.2:
	bl	_fibonacci
	mov	x20, x0
	sub	w0, w19, #2
	bl	_fibonacci
	add	w19, w0, w20
LBB0_3:
	mov	x0, x19
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp], #32             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x20, x19, [sp, #16]             ; 16-byte Folded Spill
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	mov	w8, #5
	str	x8, [sp]
Lloh0:
	adrp	x0, l_.str@PAGE
Lloh1:
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	mov	w19, #0
Lloh2:
	adrp	x20, l_.str.1@PAGE
Lloh3:
	add	x20, x20, l_.str.1@PAGEOFF
LBB1_1:                                 ; =>This Inner Loop Header: Depth=1
	mov	x0, x19
	bl	_fibonacci
                                        ; kill: def $w0 killed $w0 def $x0
	str	x0, [sp]
	mov	x0, x20
	bl	_printf
	add	w19, w19, #1
	cmp	w19, #5
	b.ne	LBB1_1
; %bb.2:
	mov	w0, #0
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.loh AdrpAdd	Lloh2, Lloh3
	.loh AdrpAdd	Lloh0, Lloh1
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"Fibonacci of %d: "

l_.str.1:                               ; @.str.1
	.asciz	"%d "

.subsections_via_symbols
