#include "types.h"
struct stack_state {
  uint32_t error_code;
  uint32_t eip;
  uint32_t cs;
  uint32_t eflags;
} __attribute__((packed));
void interrupt_handler(uint32_t interrupt_number, uint32_t error_code);
