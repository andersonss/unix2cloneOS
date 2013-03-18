void switch_page_directory(int *dir)
{
    //current_directory = dir;
    //asm volatile("mov %0, %%cr3":: "r"(dir));
    int cr0;
    asm volatile("mov %%cr0, %0": "=r"(cr0));
    //cr0 |= 0x80000000; // Enable paging!
    //asm volatile("mov %0, %%cr0":: "r"(cr0));
}
