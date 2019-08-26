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
	int b = 0;
	int a = 1/0;
	for (int i = 0; i<100000; i++)
	{
		b++;
		b = b/2;
		writed(b);
	}
}
 
