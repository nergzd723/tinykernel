#ifndef IRQ_H
#define IRQ_H
#include "types.h"
void interrupt_handler(uint32_t interrupt_number, uint32_t error_code);
void load_idt(void * idt);
void interrupt(uint32_t interrupt_number);
void enable_hardware_interrupts();
void enable_keyboard_interrupts();
void outb(unsigned short port, unsigned char data);
unsigned char inb(unsigned short port);
#endif