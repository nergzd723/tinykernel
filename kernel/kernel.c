#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "kernel.h"
#include "rw.h"
#include "video.h"

void kernel_main(void) 
{
	init(VGA_COLOR_BLACK, VGA_COLOR_WHITE);
	write("Hello, kernel World!\n");
	clsdrv();
	printart();
}
 
