#ifndef KERNEL_H
#define KERNEL_H
void oops(char* errmsg);
extern halt();
void outb(unsigned short port, unsigned char data);
#endif
