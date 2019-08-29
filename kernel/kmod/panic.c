#include <stdint.h>
#include "oopsh.h"
#include "dsp.h"
void oops(char* errmsg){
    log("Got exception, \n Panicked successfully!");
    log(errmsg);
    cls();
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("An error occured!\nThe error code is");
    printf("\n\n");
    printf(errmsg);
    log("Halting the CPU...");
    halt();
}
