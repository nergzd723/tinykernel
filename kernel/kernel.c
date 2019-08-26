#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "kernel.h"
#include "rw.h"
#include "video.h"
int divide(int a, int b)
{
	int c;
	c = a/b;
	return c;
}
void kernel_main(void) 
{
	init();
	long b = 0;
	int a = 1/0;
	for (long i = 0; i<1000000000; i++)
	{
		b++;
		writed(b);
	}
}
 
