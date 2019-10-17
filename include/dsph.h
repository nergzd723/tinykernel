#ifndef LOGH_H
#define LOGH_H
#include "rw.h"
#include "serialif.h"
#include "oopsh.h"
#include "serial.h"
#include "fb.h"

void logd(long data)
{
  char* c = inttostr(data);
  log(c);
  log(" ");
}
void cls()
{
  clsdrv();
}
void init()
{
  t_init();
  serial_init(SERIAL_COM1_BASE);
  log("GDT, terminal and serial init!");
}
void log(char* data)
{
  serial_write(SERIAL_COM1_BASE, data);
  serial_write(SERIAL_COM1_BASE, " ");
}
void printf(char* data)
{
  fb_write(data);
  log("Wrote to screen");
}
void warn(char* data)
{
  log(data);
  log("Warning!");
  write("\n\n\nWarning!\n");
  write(data);
}
#endif
