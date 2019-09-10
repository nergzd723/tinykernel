#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "oopsh.h"
#include "rw.h"
#include "serialif.h"
#include "app.h"

struct gdt_t {
  unsigned int address;
  unsigned short size;
} __attribute__((packed)) gdt;

struct segment_selector {
  unsigned short address;
  unsigned short size;
} __attribute__((packed));

unsigned short segment_selectors[] = {
  0x0, // null descriptor
  (0x08 << 4), // kernel code segment
  (0x10 << 4), // kernel data segment
};

void initialize_gdt() {
  gdt.address = (unsigned short) segment_selectors;
  gdt.size = sizeof(segment_selectors);
  lgdt(&gdt);
}

void kernel_main(void) 
{
	serial_init(SERIAL_COM1_BASE);
	log(SERIAL_COM1_BASE, "Hello World!\n");
	_Bool ok = init();
	initialize_gdt();
	log(SERIAL_COM1_BASE, "Loaded global descriptor table.\n");
	
	if(ok)
	{
		log(SERIAL_COM1_BASE, "Loading app\n");
		write("Kernel module OK. Loading app...");
		call_app(4);
	}
	else
	{
		oops("TERMINAL_ERR");
	}
}
 
