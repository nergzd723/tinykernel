#include "dsp.h"
#include "rw.h"
#include "types.h"
#include "irq.h"

void interrupt_handler(uint32_t interrupt_number, uint32_t error_code)
{
  warn("Got IRQ, DINFO in serial");
  log("error_code: ");
  log(error_code);
  log("interrupt_number: ");
  log(interrupt_number);
  return;
}
void enable_keyboard_interrupts() {
  outb(0x21,0xfd);
  outb(0xa1,0xff);
  enable_hardware_interrupts();
}
