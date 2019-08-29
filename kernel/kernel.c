#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "oopsh.h"
#include "app.h"
#include "dsph.h"
#include "types.h"
#include "irq.h"

struct gdt_description_structure_t {
  uint16_t size;
  uint32_t offset;
} __attribute__((packed)) gdt_description_structure;

struct idt_description_structure_t {
  uint16_t size;
  uint32_t offset;
} __attribute__((packed)) idt_description_structure;

struct segment_descriptor_t {
  uint16_t limit_0_15;
  uint16_t base_0_15;
  uint8_t base_16_23;
  uint8_t access_byte;
  uint8_t flags_and_limit_16_19;
  uint8_t base_24_31;
} __attribute__((packed));

// See http://wiki.osdev.org/Interrupt_Descriptor_Table#Structure_IA-32

struct interrupt_descriptor_t {
  uint16_t offset_0_15;
  uint16_t selector;
  uint8_t zero;
  uint8_t type_attr;
  uint16_t offset_16_31;
} __attribute__((packed));

enum segment_selector_t {
  NULL_DESCRIPTOR,
  KERNAL_CODE_SEGMENT_INDEX,
  KERNAL_DATA_SEGMENT_INDEX
};

struct segment_descriptor_t gdt[3];
const uint16_t NULL_SEGMENT_SELECTOR = 0x0;
const uint16_t KERNAL_CODE_SEGMENT_SELECTOR = sizeof(struct segment_descriptor_t) * 1;
const uint16_t KERNAL_DATA_SEGMENT_SELECTOR = sizeof(struct segment_descriptor_t) * 2;
struct interrupt_descriptor_t idt[256];

void initialize_gdt() {
  gdt_description_structure.size = sizeof(gdt) - 1;
  gdt_description_structure.offset = (uint32_t) gdt;
  gdt[KERNAL_CODE_SEGMENT_INDEX].limit_0_15 = 0xFFFF;
  gdt[KERNAL_CODE_SEGMENT_INDEX].base_0_15 = 0x0000;
  gdt[KERNAL_CODE_SEGMENT_INDEX].base_16_23 = 0x00;
  gdt[KERNAL_CODE_SEGMENT_INDEX].access_byte = 0b10011010;
  gdt[KERNAL_CODE_SEGMENT_INDEX].flags_and_limit_16_19 = 0xCF;
  gdt[KERNAL_CODE_SEGMENT_INDEX].base_24_31 = 0x00;
  gdt[KERNAL_DATA_SEGMENT_INDEX].limit_0_15 = 0xFFFF;
  gdt[KERNAL_DATA_SEGMENT_INDEX].base_0_15 = 0x0000;
  gdt[KERNAL_DATA_SEGMENT_INDEX].base_16_23 = 0x00;
  gdt[KERNAL_DATA_SEGMENT_INDEX].access_byte = 0b10010010;
  gdt[KERNAL_DATA_SEGMENT_INDEX].flags_and_limit_16_19 = 0xCF;
  gdt[KERNAL_DATA_SEGMENT_INDEX].base_24_31 = 0x00;
	
  lgdt(&gdt_description_structure);
}
void initialize_idt() {
	
  idt_description_structure.size = sizeof(idt) - 1;
  idt_description_structure.offset = (uint32_t) idt;
  uint32_t interrupt_handler_address = (uint32_t) &interrupt_handler;
  uint16_t offset_0_15 = interrupt_handler_address & 0x0000FFFF;
  uint16_t offset_16_31 = interrupt_handler_address >> 16;
  uint16_t selector = KERNAL_CODE_SEGMENT_SELECTOR;
  uint8_t zero = 0x00;
  uint8_t type_attr = 0x8E;
  for (int i = 0; i < 256; i++) {
    idt[i].offset_0_15 = offset_0_15;
    idt[i].selector = selector;
    idt[i].zero = zero;
    idt[i].type_attr = type_attr;
    idt[i].offset_16_31 = offset_16_31;
  }
  load_idt(&idt_description_structure);
}

void kernel_main(void) 
{
	init();
	initialize_gdt();
	initialize_idt();
  	log("Loaded interrupt descriptor table.");
	log("Loading app");
	printf("Kernel module OK. Loading app...\n");
	warn("Bad app name!");
	printf("Hello World!\n");
	warn("Bad app name!");
}
 
