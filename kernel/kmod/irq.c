#include "dsp.h"
#include "rw.h"
#include "types.h"
#include "irq.h"
#include "apic.h"
#include "kbd.h"

void interrupt_handler(uint32_t interrupt_number, uint32_t error_code)
{
  switch(interrupt_number) {
    case(0x00000020):
    case(0x00000021):
      consume_scan_code();
      log("returned from consume_scan_code()");
      pic_acknowledge();
      log("returned from pic_acknowledge()");
      break;
    default:
      //pic_acknowledge();
      logd(interrupt_number);
      logd(error_code);
      break;
  }
  return;
}
void enable_keyboard_interrupts() {
  outb(0x21,0xfd);
  outb(0xa1,0xff);
  enable_hardware_interrupts();
}
