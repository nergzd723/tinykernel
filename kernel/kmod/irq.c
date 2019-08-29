#include "dsp.h"
#include "rw.h"
#include "types.h"
void interrupt_handler(uint32_t interrupt_number, uint32_t error_code)
{
  warn("Got IRQ, DINFO in serial");
  log("error_code: ");
  log(error_code);
  log("interrupt_number: ");
  log(interrupt_number);
  return;
}
void load_idt(void * idt);
void interrupt(uint32_t interrupt_number);
