	.file	"f.c"
	.text
	.p2align 4,,15
	.globl	f
	.type	f, @function
f:
.LFB51:
	.cfi_startproc
	addl	$1000, n(%rip)
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE51:
	.size	f, .-f
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB52:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8008, %rsp
	.cfi_def_cfa_offset 8032
	leaq	8000(%rsp), %rbp
	movq	%rsp, %rbx
	.p2align 4,,10
	.p2align 3
.L4:
	xorl	%ecx, %ecx
	xorl	%esi, %esi
	movq	%rbx, %rdi
	movl	$f, %edx
	addq	$8, %rbx
	call	pthread_create
	cmpq	%rbp, %rbx
	jne	.L4
	movq	%rsp, %rbx
	.p2align 4,,10
	.p2align 3
.L6:
	movq	(%rbx), %rdi
	xorl	%esi, %esi
	addq	$8, %rbx
	call	pthread_join
	cmpq	%rbp, %rbx
	jne	.L6
	movl	n(%rip), %edx
	movl	$.LC0, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	addq	$8008, %rsp
	.cfi_def_cfa_offset 24
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE52:
	.size	main, .-main
	.globl	n
	.bss
	.align 4
	.type	n, @object
	.size	n, 4
n:
	.zero	4
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
