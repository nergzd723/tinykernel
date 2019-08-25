#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "kernel.h"
#include "rw.h"
#include "video.h"

void kernel_main(void) 
{
	init();
	for (int i = 0; i<24; i++){
		write("Hello, kernel World!\n");
	}
}
 
