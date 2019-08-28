#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "kernel.h"
#include "rw.h"
#include "serial.h"
void call_app(bool m)
{
  if(m)
  {
    printart();
  }
  else
  {
    oops("STRANGE_THINGS_HAPPEN")
  }
}
