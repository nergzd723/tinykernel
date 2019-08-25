#include <stdint.h>
#include "rw.h"
void oops(char* errmsg){
    write('An error occured!\nThe error code is');
    write(errmsg);
}