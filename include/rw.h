#ifndef RW_H
#define RW_H
void write(const char* data);
void init(void);
void printart();
void clsdrv();
void lgdt(void * gdt);
void outb(unsigned short port, unsigned char data);
unsigned char inb(unsigned short port);
void serial_print(unsigned short com, char * s);
void writed(const int data);
void terminal_setcolor(int colorbg, int colorfg);
#endif
