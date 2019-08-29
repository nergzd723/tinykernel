#include "dsp.h"
void interrupt_handler()
{
  oops("Got IRQ");
}
void load_idt(void * idt);
void interrupt(uint32_t interrupt_number);
