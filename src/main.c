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
    
    /* Handle interrupts*/
    //asm volatile("int $0x3");
    //asm volatile("int $0x4");

    /* Timer interrupt*/
    //asm volatile("sti");
    //init_timer(50);

    /* Paging*/
    //initialise_paging();
    //monitor_write("Hello, paging world!\n");

    //u32int *ptr = (u32int*)0xA0000000;
    //u32int do_page_fault = *ptr;

    u32int a = kmalloc(8);
    initialise_paging();   
    u32int b = kmalloc(8);
    u32int c = kmalloc(8);
    monitor_write("a: ");
    monitor_write_hex(a);
    monitor_write(", b: ");
    monitor_write_hex(b);
    monitor_write("\nc: ");
    monitor_write_hex(c);

    kfree(c);
    kfree(b);
    u32int d = kmalloc(12);
    monitor_write(", d: ");
    monitor_write_hex(d);

    return 0;
}
