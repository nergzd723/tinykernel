#ifndef SERIALIF_H
#define SERIALIF_H
#define SERIAL_COM1_BASE                0x3F8 
void serial_init(unsigned short com);
void serial_print(unsigned short com, char * s);
void serial_write_char(unsigned short com, char c);
#endif
