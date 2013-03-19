int test(int ebp)
{ 
	asm volatile("mov %%ebp, %0" : "=r"(ebp));
}
