	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	cmpl	$0, _i(%rip)
	je	LBB0_2
## BB#1:
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	jmp	LBB0_3
LBB0_2:
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -12(%rbp)         ## 4-byte Spill
LBB0_3:
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_i                      ## @i
.zerofill __DATA,__common,_i,4,2
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"yes\n"

L_.str.1:                               ## @.str.1
	.asciz	"no\n"


.subsections_via_symbols
