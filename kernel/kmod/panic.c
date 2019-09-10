#include <stdint.h>
#include "rw.h"
#include "oopsh.h"
#include "serialif.h"
#include "dsp.h"
void oops(char* errmsg){
    log("Got exception, \n Panicked successfully!");
    log(errmsg);
    clsdrv();
    write("\n\n\n\n\n\n\n\n\n\n");
    write("An error occured!\nThe error code is");
    write("\n\n");
    write(errmsg);
    log("Halting the CPU...");
    halt();
}
