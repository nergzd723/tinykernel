#include "dsp.h"
#include "rw.h"
#include "types.h"
#include "irq.h"
#include "apic.h"

void interrupt_handler(uint32_t interrupt_number, uint32_t error_code)
{
  switch(interrupt_number) {
    case(0x00000009):
      consume_scan_code();
      pic_acknowledge(interrupt_number);
      break;
    default:
      log("Unhandled Interrupt");
      warn("Got IRQ, DINFO in serial");
      break;
  }
  return;
}
void enable_keyboard_interrupts() {
  outb(0x21,0xfd);
  outb(0xa1,0xff);
  enable_hardware_interrupts();
}
