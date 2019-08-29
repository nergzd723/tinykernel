#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "kernel.h"
#include "rw.h"
#include "serialif.h"
#include "app.h"
void kernel_main(void) 
{
	serial_init(SERIAL_COM1_BASE);
	serial_print(SERIAL_COM1_BASE, "Hello World!\n");
	_Bool ok = init();
	if(ok)
	{
		serial_print(SERIAL_COM1_BASE, "Loading app\n");
		write("Kernel module OK. Loading app...");
		call_app(4);
	}
	else
	{
		oops("TERMINAL_ERR");
	}
}
 
