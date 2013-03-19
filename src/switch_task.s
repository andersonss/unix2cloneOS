.global switch_task
switch_task:
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
