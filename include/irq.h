#include "types.h"
void interrupt_handler(uint32_t interrupt_number, uint32_t error_code);
void load_idt(void * idt);
void interrupt(uint32_t interrupt_number);
