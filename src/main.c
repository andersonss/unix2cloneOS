// main.c -- Defines the C-code kernel entry point, calls initialisation routines.
//           Made for JamesM's tutorials <www.jamesmolloy.co.uk>

#include "monitor.h"
#include "descriptor_tables.h"
#include "timer.h"
#include "paging.h"

int main(struct multiboot *mboot_ptr)
{
    // Initialise all the ISRs and segmentation
    init_descriptor_tables();
    // Initialise the screen (by clearing it)
    monitor_clear();
    // Write out a sample string
    //monitor_write("Hello, world!\n");

    //asm volatile("int $0x3");
    //asm volatile("int $0x4");

    //asm volatile("sti");
    //init_timer(50);

    initialise_paging();
    monitor_write("Hello, paging world!\n");

    u32int *ptr = (u32int*)0xA0000000;
    u32int do_page_fault = *ptr;

    return 0;
}
