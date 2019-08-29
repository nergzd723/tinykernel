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
}

void kernel_main(void) 
{
	init();
	initialize_gdt();
	log("Loading app");
	printf("Kernel module OK. Loading app...\n");
	warn("Bad app name!");
	printf("Hello World!\n");
	warn("Bad app name!");
	
}
 
