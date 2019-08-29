#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "oopsh.h"
#include "app.h"
#include "dsph.h"
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
	init();
	initialize_gdt();
	log("Loading app\n");
	printf("Kernel module OK. Loading app...\n");
	warn("Bad app name!");
	printf("Hello World!\n");
}
 
