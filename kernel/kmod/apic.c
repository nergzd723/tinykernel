
#include "apic.h"
#include "rw.h"
#define PIC1_PORT_A 0x20
#define PIC2_PORT_A 0xA0
/* The PIC interrupts have been remapped */
#define PIC1_START_INTERRUPT 0x20
#define PIC2_START_INTERRUPT 0x28
#define PIC2_END_INTERRUPT   PIC2_START_INTERRUPT + 7
#define PIC_ACK     0x20
void pic_acknowledge(uint32_t interrupt)
{
  if (interrupt < PIC1_START_INTERRUPT || interrupt > PIC2_END_INTERRUPT) {
    return;
  }
  if (interrupt < PIC2_START_INTERRUPT) {
    outb(PIC1_PORT_A, PIC_ACK);
  } 
  else {
    outb(PIC2_PORT_A, PIC_ACK);
  }
} 
