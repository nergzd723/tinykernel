#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "kernel.h"
#include "rw.h"
#include "video.h"

void kernel_main(void) 
{
	init();
	int b = 0;
	for (int i = 0; i<100000; i++)
	{
		b++
	}
	printart();
}
 
