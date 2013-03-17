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


    asm volatile("sti");
    init_timer(50);

    monitor_write("Teste\n");
 
    keyboard_install();

    for(;;);

    return 0;
}
