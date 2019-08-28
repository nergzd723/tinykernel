#ifndef KERNEL_H
#define KERNEL_H
void oops(char* errmsg);
extern int halt();
void outb(unsigned short port, unsigned char data);
#endif
