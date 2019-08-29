#include <stdint.h>
#include "rw.h"
#include "kernel.h"
#include "serial.h"
void oops(char* errmsg){
    serial_print(SERIAL_COM1_BASE, "Got exception");
    serial_print(SERIAL_COM1_BASE, errmsg);
    clsdrv();
    write("\n\n\n\n\n\n\n\n\n\n");
    write("An error occured!\nThe error code is");
    write("\n\n");
    write(errmsg);
    halt();
}
