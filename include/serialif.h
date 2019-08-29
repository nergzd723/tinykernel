#ifndef SERIALIF_H
#define SERIALIF_H
#define SERIAL_COM1_BASE                0x3F8 
void serial_init(unsigned short com);
void log(unsigned short com, char * s);
void logc(unsigned short com, char c);
#endif
