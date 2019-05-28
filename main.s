	.file	"main.cpp"
	.text
	.p2align 4,,15
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB2026:
	.cfi_startproc
	movl	$__ZStL8__ioinit, %ecx
	jmp	__ZNSt8ios_base4InitD1Ev
	.cfi_endproc
LFE2026:
	.section .rdata,"dr"
LC0:
	.ascii "Airhokey\0"
	.section	.text.unlikely,"x"
LCOLDB1:
	.text
LHOTB1:
	.p2align 4,,15
	.globl	_SDL_main
	.def	_SDL_main;	.scl	2;	.type	32;	.endef
_SDL_main:
LFB1557:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1557
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$24, (%esp)
LEHB0:
	call	__Znwj
LEHE0:
	movl	%eax, %ecx
	movl	%eax, %ebx
LEHB1:
	call	__ZN4GameC1Ev
LEHE1:
	movl	$0, 20(%esp)
	movl	%ebx, %ecx
	movl	$720, 16(%esp)
	movl	$1280, 12(%esp)
	movl	$805240832, 8(%esp)
	movl	$805240832, 4(%esp)
	movl	$LC0, (%esp)
	movl	%ebx, _game
LEHB2:
	call	__ZN4Game4initEPKciiiib
	.cfi_def_cfa_offset 24
	movl	_game, %ecx
	subl	$24, %esp
	.cfi_def_cfa_offset 48
	cmpb	$0, 8(%ecx)
	je	L4
	.p2align 4,,10
L5:
	call	__ZN4Game12handleEventsEv
	movl	_game, %ecx
	call	__ZN4Game6updateEv
	movl	_game, %ecx
	call	__ZN4Game6renderEv
	movl	_game, %ecx
	cmpb	$0, 8(%ecx)
	jne	L5
L4:
	call	__ZN4Game5cleanEv
LEHE2:
	addl	$36, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
L7:
	.cfi_restore_state
	movl	%eax, %esi
	jmp	L6
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA1557:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1557-LLSDACSB1557
LLSDACSB1557:
	.uleb128 LEHB0-LFB1557
	.uleb128 LEHE0-LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB1-LFB1557
	.uleb128 LEHE1-LEHB1
	.uleb128 L7-LFB1557
	.uleb128 0
	.uleb128 LEHB2-LFB1557
	.uleb128 LEHE2-LEHB2
	.uleb128 0
	.uleb128 0
LLSDACSE1557:
	.text
	.cfi_endproc
	.section	.text.unlikely,"x"
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDAC1557
	.def	_SDL_main.cold.1;	.scl	3;	.type	32;	.endef
_SDL_main.cold.1:
L6:
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -12
	.cfi_offset 6, -8
	movl	$24, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvj
	movl	%esi, (%esp)
LEHB3:
	call	__Unwind_Resume
LEHE3:
	.cfi_endproc
LFE1557:
	.section	.gcc_except_table,"w"
LLSDAC1557:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSEC1557-LLSDACSBC1557
LLSDACSBC1557:
	.uleb128 LEHB3-LCOLDB1
	.uleb128 LEHE3-LEHB3
	.uleb128 0
	.uleb128 0
LLSDACSEC1557:
	.section	.text.unlikely,"x"
	.text
	.section	.text.unlikely,"x"
LCOLDE1:
	.text
LHOTE1:
	.section	.text.startup,"x"
	.p2align 4,,15
	.def	__GLOBAL__sub_I_game;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_game:
LFB2027:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2027:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_game
	.globl	_game
	.bss
	.align 4
_game:
	.space 4
.lcomm __ZStL8__ioinit,1,1
	.ident	"GCC: (MinGW.org GCC-8.2.0-3) 8.2.0"
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__Znwj;	.scl	2;	.type	32;	.endef
	.def	__ZN4GameC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZN4Game4initEPKciiiib;	.scl	2;	.type	32;	.endef
	.def	__ZN4Game12handleEventsEv;	.scl	2;	.type	32;	.endef
	.def	__ZN4Game6updateEv;	.scl	2;	.type	32;	.endef
	.def	__ZN4Game6renderEv;	.scl	2;	.type	32;	.endef
	.def	__ZN4Game5cleanEv;	.scl	2;	.type	32;	.endef
	.def	__ZdlPvj;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
