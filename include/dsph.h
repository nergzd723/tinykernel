#ifndef LOGH_H
#define LOGH_H
#include "rw.h"
#include "serialif.h"
#include "oopsh.h"
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

void init()
{
  t_init();
  serial_init(SERIAL_COM1_BASE);
  initialize_gdt();
  log("GDT, terminal and serial init!")
}
void log(char* data)
{
  serial_write(SERIAL_COM1_BASE, data);
}
void printf(char* data)
{
  write(data);
  log("Wrote to screen")
}
void warn(char* data)
{
  log(data);
  write("\n\n\nWarning!");
  write(data);
}
#endif
