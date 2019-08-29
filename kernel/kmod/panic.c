#include <stdint.h>
#include "rw.h"
#include "kernel.h"
#include "serialif.h"
void oops(char* errmsg){
    log(SERIAL_COM1_BASE, "Got exception, \n Panicked successfully!");
    log(SERIAL_COM1_BASE, errmsg);
    clsdrv();
    write("\n\n\n\n\n\n\n\n\n\n");
    write("An error occured!\nThe error code is");
    write("\n\n");
    write(errmsg);
    log(SERIAL_COM1_BASE, "Halting the CPU...");
    halt();
}
