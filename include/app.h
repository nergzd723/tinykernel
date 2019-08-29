#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "dsph.h"
#include "rw.h"
#include "video.h"

void call_app(int m)
{
  if(m == 1)
  {
    printart();
  }
  else if (m == 2)
  {
    clsdrv();
  }
  else if (m == 3)
  {
    matrix();
  }
  else
  {
    oops("STRANGE_THINGS_HAPPEN");
  }
}
