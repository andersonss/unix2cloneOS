.globl	get_register_cr0
get_register_cr0:
	movl	%cr0, %eax
	ret

.globl set_register_cr0
set_register_cr0:
	movl	4(%esp), %eax
	mov %eax, %cr0
	ret

.globl	get_register_cr2
get_register_cr2:
	movl	%cr2, %eax
	ret

.globl	set_register_cr3
set_register_cr3:
	movl	4(%esp), %eax
	mov %eax, %cr3
	ret