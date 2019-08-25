#ifndef RW_H
#define RW_H
void write(const char* data);
void init(enum vga_color cfg, enum vga_color cbg);
void printart();
void clsdrv();
void terminal_setcolor(int colorbg, int colorfg);
#endif
