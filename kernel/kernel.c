#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "oopsh.h"
#include "app.h"
#include "dsph.h"

void kernel_main(void) 
{
	init();
	log("Loading app\n");
	printf("Kernel module OK. Loading app...");
	call_app(4);
}
 
