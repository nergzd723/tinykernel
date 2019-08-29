#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "kernel.h"
#include "app.h"

void kernel_main(void) 
{
	init();
	log("Loading app\n");
	printf("Kernel module OK. Loading app...");
	call_app(4);
}
 
