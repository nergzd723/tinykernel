#ifndef LOGH_H
#define LOGH_H
#include "rw.h"
#include "serialif.h"
#include "oopsh.h"
#include "serial.h"

void cls()
{
  clsdrv();
}
void init()
{
  t_init();
  serial_init(SERIAL_COM1_BASE);
  log("GDT, terminal and serial init!\n");
}
void log(char* data)
{
  serial_write(SERIAL_COM1_BASE, data);
}
void printf(char* data)
{
  write(data);
  log("Wrote to screen\n");
}
void warn(char* data)
{
  log(data);
  log("Warning!\n");
  write("\n\n\nWarning!\n");
  write(data);
}
#endif
