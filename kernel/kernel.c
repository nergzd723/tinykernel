#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "oopsh.h"
#include "rw.h"
#include "serialif.h"
#include "app.h"
#include "log.h"

struct gdt_t {
  int32 address;
  int16 size;
} __attribute__((packed)) gdt;

// See http://wiki.osdev.org/Global_Descriptor_Table#Structure
struct segment_descriptor_t {
  int16 base_0_15; // bits 0-15 of base
  int16 limit_0_15;
  int8 base_24_31;
  int8 flags_and_limit_16_19;
  int8 access_byte;
  int8 base_16_23;
} __attribute__((packed));

enum segment_selector_t {
  NULL_DESCRIPTOR, // Not but has to be here
  KERNAL_CODE_SEGMENT, // Offset 0x8
  KERNAL_DATA_SEGMENT // Offset 0x10
};
struct segment_descriptor_t segment_descriptors[3];

void initialize_gdt() {
  gdt.address = (int16) segment_descriptors;
  gdt.size = sizeof(segment_descriptors);

  segment_descriptors[KERNAL_CODE_SEGMENT].base_0_15 = 0x0;
  segment_descriptors[KERNAL_CODE_SEGMENT].base_24_31 = 0x0;
  segment_descriptors[KERNAL_CODE_SEGMENT].limit_0_15 = 0xFFFF;
  segment_descriptors[KERNAL_CODE_SEGMENT].flags_and_limit_16_19 = 0b1000 << 4;
  segment_descriptors[KERNAL_CODE_SEGMENT].flags_and_limit_16_19 &= 0xF;
  segment_descriptors[KERNAL_CODE_SEGMENT].access_byte &= 0b10010110;

  segment_descriptors[KERNAL_DATA_SEGMENT].base_0_15 = 0x0;
  segment_descriptors[KERNAL_DATA_SEGMENT].base_24_31 = 0x0;
  segment_descriptors[KERNAL_DATA_SEGMENT].limit_0_15 = 0xFFFF;
  segment_descriptors[KERNAL_DATA_SEGMENT].flags_and_limit_16_19 = 0b1000 << 4;
  segment_descriptors[KERNAL_DATA_SEGMENT].flags_and_limit_16_19 &= 0xF;
  segment_descriptors[KERNAL_DATA_SEGMENT].access_byte &= 0b10010010;
  lgdt(&gdt);

  // Grub has already loaded the segment registers
  // with the correct values (0x8 for cs, 0x10 for the others)
}struct gdt_t {
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
	log("Hello World!\n");
	log("Loaded global descriptor table.\n");
	log("Loading app\n");
	printf("Kernel module OK. Loading app...");
	halt();
}
 
