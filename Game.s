	.file	"Game.cpp"
	.text
	.section	.text$_ZNKSt5ctypeIcE8do_widenEc,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNKSt5ctypeIcE8do_widenEc
	.def	__ZNKSt5ctypeIcE8do_widenEc;	.scl	2;	.type	32;	.endef
__ZNKSt5ctypeIcE8do_widenEc:
LFB1313:
	.cfi_startproc
	movzbl	4(%esp), %eax
	ret	$4
	.cfi_endproc
LFE1313:
	.text
	.p2align 4,,15
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB2044:
	.cfi_startproc
	movl	$__ZStL8__ioinit, %ecx
	jmp	__ZNSt8ios_base4InitD1Ev
	.cfi_endproc
LFE2044:
	.align 2
	.p2align 4,,15
	.globl	__ZN4GameC2Ev
	.def	__ZN4GameC2Ev;	.scl	2;	.type	32;	.endef
__ZN4GameC2Ev:
LFB1558:
	.cfi_startproc
	ret
	.cfi_endproc
LFE1558:
	.globl	__ZN4GameC1Ev
	.def	__ZN4GameC1Ev;	.scl	2;	.type	32;	.endef
	.set	__ZN4GameC1Ev,__ZN4GameC2Ev
	.align 2
	.p2align 4,,15
	.globl	__ZN4GameD2Ev
	.def	__ZN4GameD2Ev;	.scl	2;	.type	32;	.endef
__ZN4GameD2Ev:
LFB1561:
	.cfi_startproc
	ret
	.cfi_endproc
LFE1561:
	.globl	__ZN4GameD1Ev
	.def	__ZN4GameD1Ev;	.scl	2;	.type	32;	.endef
	.set	__ZN4GameD1Ev,__ZN4GameD2Ev
	.section .rdata,"dr"
LC0:
	.ascii "Subsysten Initialised!\0"
LC1:
	.ascii "Window created!\0"
LC2:
	.ascii "Renderer created!\0"
	.text
	.align 2
	.p2align 4,,15
	.globl	__ZN4Game4initEPKciiiib
	.def	__ZN4Game4initEPKciiiib;	.scl	2;	.type	32;	.endef
__ZN4Game4initEPKciiiib:
LFB1563:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	%ecx, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$62001, (%esp)
	movl	68(%esp), %esi
	call	_SDL_Init
	testl	%eax, %eax
	je	L38
	movb	$0, 8(%ebx)
	addl	$32, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret	$24
	.p2align 4,,10
L38:
	.cfi_restore_state
	movl	$22, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	__ZSt4cout, %eax
	movl	-12(%eax), %eax
	movl	__ZSt4cout+124(%eax), %edi
	testl	%edi, %edi
	je	L12
	cmpb	$0, 28(%edi)
	je	L9
	movsbl	39(%edi), %eax
L10:
	movl	%eax, (%esp)
	movl	$__ZSt4cout, %ecx
	call	__ZNSo3putEc
	.cfi_def_cfa_offset 44
	subl	$4, %esp
	.cfi_def_cfa_offset 48
	movl	%eax, %ecx
	call	__ZNSo5flushEv
	movl	%esi, %eax
	movzbl	%al, %esi
	movl	64(%esp), %eax
	movl	%esi, 20(%esp)
	movl	%eax, 16(%esp)
	movl	60(%esp), %eax
	movl	%eax, 12(%esp)
	movl	56(%esp), %eax
	movl	%eax, 8(%esp)
	movl	52(%esp), %eax
	movl	%eax, 4(%esp)
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	_SDL_CreateWindow
	movl	%eax, 12(%ebx)
	testl	%eax, %eax
	je	L11
	movl	$15, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	__ZSt4cout, %eax
	movl	-12(%eax), %eax
	movl	__ZSt4cout+124(%eax), %esi
	testl	%esi, %esi
	je	L12
	cmpb	$0, 28(%esi)
	je	L13
	movsbl	39(%esi), %eax
L14:
	movl	%eax, (%esp)
	movl	$__ZSt4cout, %ecx
	call	__ZNSo3putEc
	.cfi_def_cfa_offset 44
	subl	$4, %esp
	.cfi_def_cfa_offset 48
	movl	%eax, %ecx
	call	__ZNSo5flushEv
	movl	12(%ebx), %eax
L11:
	movl	$0, 8(%esp)
	movl	$-1, 4(%esp)
	movl	%eax, (%esp)
	call	_SDL_CreateRenderer
	movl	%eax, 16(%ebx)
	testl	%eax, %eax
	je	L15
	movl	$255, 16(%esp)
	movl	$255, 12(%esp)
	movl	$255, 8(%esp)
	movl	$255, 4(%esp)
	movl	%eax, (%esp)
	call	_SDL_SetRenderDrawColor
	movl	$17, 8(%esp)
	movl	$LC2, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	__ZSt4cout, %eax
	movl	-12(%eax), %eax
	movl	__ZSt4cout+124(%eax), %esi
	testl	%esi, %esi
	je	L12
	cmpb	$0, 28(%esi)
	je	L16
	movsbl	39(%esi), %eax
L17:
	movl	%eax, (%esp)
	movl	$__ZSt4cout, %ecx
	call	__ZNSo3putEc
	.cfi_def_cfa_offset 44
	subl	$4, %esp
	.cfi_def_cfa_offset 48
	movl	%eax, %ecx
	call	__ZNSo5flushEv
L15:
	movb	$1, 8(%ebx)
	addl	$32, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret	$24
	.p2align 4,,10
L9:
	.cfi_restore_state
	movl	%edi, %ecx
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%edi), %eax
	movl	24(%eax), %edx
	movl	$10, %eax
	cmpl	$__ZNKSt5ctypeIcE8do_widenEc, %edx
	je	L10
	movl	$10, (%esp)
	movl	%edi, %ecx
	call	*%edx
	.cfi_def_cfa_offset 44
	subl	$4, %esp
	.cfi_def_cfa_offset 48
	movsbl	%al, %eax
	jmp	L10
	.p2align 4,,10
L13:
	movl	%esi, %ecx
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%esi), %eax
	movl	24(%eax), %edx
	movl	$10, %eax
	cmpl	$__ZNKSt5ctypeIcE8do_widenEc, %edx
	je	L14
	movl	$10, (%esp)
	movl	%esi, %ecx
	call	*%edx
	.cfi_def_cfa_offset 44
	subl	$4, %esp
	.cfi_def_cfa_offset 48
	movsbl	%al, %eax
	jmp	L14
	.p2align 4,,10
L16:
	movl	%esi, %ecx
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%esi), %eax
	movl	24(%eax), %edx
	movl	$10, %eax
	cmpl	$__ZNKSt5ctypeIcE8do_widenEc, %edx
	je	L17
	movl	$10, (%esp)
	movl	%esi, %ecx
	call	*%edx
	.cfi_def_cfa_offset 44
	subl	$4, %esp
	.cfi_def_cfa_offset 48
	movsbl	%al, %eax
	jmp	L17
L12:
	call	__ZSt16__throw_bad_castv
	.cfi_endproc
LFE1563:
	.align 2
	.p2align 4,,15
	.globl	__ZN4Game12handleEventsEv
	.def	__ZN4Game12handleEventsEv;	.scl	2;	.type	32;	.endef
__ZN4Game12handleEventsEv:
LFB1564:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	%ecx, %ebx
	subl	$88, %esp
	.cfi_def_cfa_offset 96
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_SDL_PollEvent
	cmpl	$256, 24(%esp)
	jne	L39
	movb	$0, 8(%ebx)
L39:
	addl	$88, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE1564:
	.align 2
	.p2align 4,,15
	.globl	__ZN4Game6updateEv
	.def	__ZN4Game6updateEv;	.scl	2;	.type	32;	.endef
__ZN4Game6updateEv:
LFB1565:
	.cfi_startproc
	ret
	.cfi_endproc
LFE1565:
	.align 2
	.p2align 4,,15
	.globl	__ZN4Game6renderEv
	.def	__ZN4Game6renderEv;	.scl	2;	.type	32;	.endef
__ZN4Game6renderEv:
LFB1566:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	%ecx, %ebx
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	16(%ecx), %eax
	movl	%eax, (%esp)
	call	_SDL_RenderClear
	movl	16(%ebx), %eax
	movl	%eax, (%esp)
	call	_SDL_RenderPresent
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE1566:
	.section .rdata,"dr"
LC3:
	.ascii "Game Cleaned!\0"
	.text
	.align 2
	.p2align 4,,15
	.globl	__ZN4Game5cleanEv
	.def	__ZN4Game5cleanEv;	.scl	2;	.type	32;	.endef
__ZN4Game5cleanEv:
LFB1567:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	%ecx, %ebx
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	12(%ecx), %eax
	movl	%eax, (%esp)
	call	_SDL_DestroyWindow
	movl	16(%ebx), %eax
	movl	%eax, (%esp)
	call	_SDL_DestroyRenderer
	call	_SDL_Quit
	movl	$13, 8(%esp)
	movl	$LC3, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	__ZSt4cout, %eax
	movl	-12(%eax), %eax
	movl	__ZSt4cout+124(%eax), %ebx
	testl	%ebx, %ebx
	je	L52
	cmpb	$0, 28(%ebx)
	je	L47
	movsbl	39(%ebx), %eax
L48:
	movl	%eax, (%esp)
	movl	$__ZSt4cout, %ecx
	call	__ZNSo3putEc
	.cfi_def_cfa_offset 28
	subl	$4, %esp
	.cfi_def_cfa_offset 32
	movl	%eax, %ecx
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	jmp	__ZNSo5flushEv
	.p2align 4,,10
L47:
	.cfi_restore_state
	movl	%ebx, %ecx
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%ebx), %eax
	movl	24(%eax), %edx
	movl	$10, %eax
	cmpl	$__ZNKSt5ctypeIcE8do_widenEc, %edx
	je	L48
	movl	$10, (%esp)
	movl	%ebx, %ecx
	call	*%edx
	.cfi_def_cfa_offset 28
	subl	$4, %esp
	.cfi_def_cfa_offset 32
	movsbl	%al, %eax
	jmp	L48
L52:
	call	__ZSt16__throw_bad_castv
	.cfi_endproc
LFE1567:
	.section	.text.startup,"x"
	.p2align 4,,15
	.def	__GLOBAL__sub_I__ZN4GameC2Ev;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__ZN4GameC2Ev:
LFB2045:
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
LFE2045:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__ZN4GameC2Ev
.lcomm __ZStL8__ioinit,1,1
	.ident	"GCC: (MinGW.org GCC-8.2.0-3) 8.2.0"
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_SDL_Init;	.scl	2;	.type	32;	.endef
	.def	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i;	.scl	2;	.type	32;	.endef
	.def	__ZNSo3putEc;	.scl	2;	.type	32;	.endef
	.def	__ZNSo5flushEv;	.scl	2;	.type	32;	.endef
	.def	_SDL_CreateWindow;	.scl	2;	.type	32;	.endef
	.def	_SDL_CreateRenderer;	.scl	2;	.type	32;	.endef
	.def	_SDL_SetRenderDrawColor;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt5ctypeIcE13_M_widen_initEv;	.scl	2;	.type	32;	.endef
	.def	__ZSt16__throw_bad_castv;	.scl	2;	.type	32;	.endef
	.def	_SDL_PollEvent;	.scl	2;	.type	32;	.endef
	.def	_SDL_RenderClear;	.scl	2;	.type	32;	.endef
	.def	_SDL_RenderPresent;	.scl	2;	.type	32;	.endef
	.def	_SDL_DestroyWindow;	.scl	2;	.type	32;	.endef
	.def	_SDL_DestroyRenderer;	.scl	2;	.type	32;	.endef
	.def	_SDL_Quit;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
