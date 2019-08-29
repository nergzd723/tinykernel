#include <stdint.h>
#include "rw.h"
#include "kernel.h"
void oops(char* errmsg){
    clsdrv();
    write("\n\n\n\n\n\n\n\n\n\n");
    write("An error occured!\nThe error code is");
    write("\n\n");
    write(errmsg);
    halt();
}
