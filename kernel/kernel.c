#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "kernel.h"
#include "rw.h"

void kernel_main(void) 
{
	terminal_setcolor(15,0)
	init();
	write("Hello, kernel World!\n");
	printart();
}
 
