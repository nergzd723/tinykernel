#ifndef RW_H
#define RW_H
void write(const char* data);
char* inttostr(int zahl);
void t_init(void);
void printart();
void clsdrv();
void lgdt(void * gdt);
void serial_print(unsigned short com, char * s);
void writed(const int data);
void terminal_setcolor(int colorbg, int colorfg);
#endif
