#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "kernel.h"
#include "rw.h"
#include "video.h"

void kernel_main(void) 
{
	init();
	write("Hello, kernel World!\n");
	for (int i = 0; i<1000000; i++){
		writed(i);
		write("\n");
		if (i == 10000){
			oops("BUFF_OVERFLOW")
		}
	}
	oops("BAD_FILENAME");
	
}
 
