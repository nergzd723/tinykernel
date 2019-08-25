#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "kernel.h"
#include "rw.h"

void kernel_main(void) 
{
	init();
	write("Hello, kernel World!\n");
    	oops('Test err');
}
 
