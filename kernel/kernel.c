#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "kernel.h"
#include "rw.h"
#include "video.h"

void kernel_main(void) 
{
	init();
	printart();
	clsdrv();
	printart();
	clsdrv();
	printart();
}
 
