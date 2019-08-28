#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "kernel.h"
#include "rw.h"
#include "serial.h"
void kernel_main(void) 
{
	ok = init();
	if(ok)
	{
		call_app(true);
	}
	else
	{
		panic("TERMINAL_ERR");
	}
}
 
