# Makefile for JamesM's kernel tutorials.
# The C and C++ rules are already setup by default.
# The only one that needs changing is the assembler 
# rule, as we use nasm instead of GNU as.

SOURCES=boot.o main.o monitor.o common.o descriptor_tables.o isr.o interrupt.o gdt.o timer.o \
        kheap.o paging.o ordered_array.o fs.o initrd.o task.o process.o syscall.o keyboard.o 

CFLAGS=-nostdlib -nostdinc -fno-builtin
LDFLAGS=-Tlink.ld
ASFLAGS=-felf

all: $(SOURCES) link

clean:
	-rm *.o *~ kernel

link:
	as -L inb.s -o inb.o
	as -L outb.s -o outb.o
	as -L inw.s -o inw.o
	as -L cli.s -o cli.o
	ld $(LDFLAGS) -o kernel $(SOURCES) inb.o outb.o inw.o cli.o

.s.o:
	nasm $(ASFLAGS) $<
