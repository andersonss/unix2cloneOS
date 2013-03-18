// main.c -- Defines the C-code kernel entry point, calls initialisation routines.
//           Made for JamesM's tutorials <www.jamesmolloy.co.uk>

#include "monitor.h"
#include "descriptor_tables.h"
#include "timer.h"
#include "paging.h"
#include "multiboot.h"
#include "fs.h"
#include "initrd.h"
#include "task.h"
#include "syscall.h"
#include "keyboard.h"

extern u32int placement_address;
u32int initial_esp;

int main(struct multiboot *mboot_ptr, u32int initial_stack)
{
    initial_esp = initial_stack;

    // Initialise all the ISRs and segmentation
    init_descriptor_tables();
    
    // Initialise the screen (by clearing it)
    monitor_clear();

    //sti();

    //init_timer(50);

    initialise_paging();
    monitor_write("Hello, paging world!\n");

    u32int *ptr = (u32int*)0xA0000000;
    u32int do_page_fault = *ptr;
    //keyboard_install();

    //for(;;);

    return 0;
}
