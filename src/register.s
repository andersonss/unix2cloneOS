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

.globl	get_register_cr3
get_register_cr3:
	movl	%cr3, %eax
	ret

.globl	set_register_cr3
set_register_cr3:
	movl	4(%esp), %eax
	mov %eax, %cr3
	ret

.globl get_register_esp
get_register_esp:
	movl %esp, %eax
	addl $4, %eax
	ret

.globl set_register_esp
set_register_esp:
	movl 4(%esp), %eax
	popl %ecx
	movl %eax, %esp
	pushl %ecx
	ret

.globl get_register_ebp
get_register_ebp:
	movl %ebp, %eax
	ret

.globl set_register_ebp
set_register_ebp:
	movl 4(%esp), %eax
	movl %eax, %ebp
	ret

.global register_task
register_task:
	cli
	movl 4(%esp),%ecx
	movl 8(%esp),%ebx
	movl 12(%esp),%ebp
	movl 16(%esp),%edx
 
	movl %ebx, %esp;       
	movl %edx, %cr3;       
	movl $0x12345, %eax;
	sti
	jmp *%ecx

