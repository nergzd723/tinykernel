#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "kernel.h"
#include "rw.h"
#include "serial.h"
#include "app.h"
void kernel_main(void) 
{
	_Bool ok = init();
	if(ok)
	{
		write("Kernel module OK. Loading app...");
		call_app(1);
	}
	else
	{
		oops("TERMINAL_ERR");
	}
}
 
