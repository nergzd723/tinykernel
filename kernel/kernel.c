#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "kernel.h"
#include "rw.h"
#include "serial.h"
void kernel_main(void) 
{
	init();
	long b = 0;
	for (long i = 0; i<1000000000; i++)
	{
		b++;
		writed(b);
		
	}
}
 
