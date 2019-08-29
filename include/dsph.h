#ifndef LOGH_H
#define LOGH_H
#include "rw.h"
#include "serialif.h"
#include "oopsh.h"

void init()
{
  t_init();
  serial_init(SERIAL_COM1_BASE);
  log("GDT, terminal and serial init!");
}
void log(char* data)
{
  serial_write(SERIAL_COM1_BASE, data);
}
void printf(char* data)
{
  write(data);
  log("Wrote to screen");
}
void warn(char* data)
{
  log(data);
  write("\n\n\nWarning!");
  write(data);
}
#endif
