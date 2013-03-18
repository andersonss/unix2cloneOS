	.file	"p1.c"
	.text
	.globl	switch_page_directory
	.type	switch_page_directory, @function
switch_page_directory:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 3, -12
#APP
# 6 "p1.c" 1
	mov %cr0, %ebx
# 0 "" 2
#NO_APP
	movl	%ebx, -8(%ebp)
	addl	$16, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
.LFE0:
	.size	switch_page_directory, .-switch_page_directory
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
