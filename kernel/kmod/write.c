#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

enum vga_color {                    //some VGA color enum
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) 
{
	return fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color) 
{
	return (uint16_t) uc | (uint16_t) color << 8;
}

size_t strlen(const char* str) 
{
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
 

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

void init(void) 
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_BLACK, VGA_COLOR_WHITE);            //init a terminal
	terminal_buffer = (uint16_t*) 0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

void terminal_setcolor(int colorbg, int colorfg) 
{
	terminal_color = colorbg;
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y)             //piece of code to compute where the entry char would be
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_putchar(char c) 
{
	if (c == '\n'){
        	terminal_row++;
		terminal_column = 0; 
	}
	else{
		terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
		if (terminal_column >= VGA_WIDTH) {
			terminal_column = 0;
			terminal_row++;
		if (++terminal_row == VGA_HEIGHT)
			terminal_row = 0;
		}
		if(terminal_row >= VGA_HEIGHT) {
        	for(int i = 0; i < VGA_HEIGHT; i++){
        		for (int m = 0; m < VGA_WIDTH; m++){
            		terminal_buffer[i * VGA_WIDTH + m] = terminal_buffer[(i + 1) * vga_width + m];
        		}
    		}
    		}
		}
	}

void terminal_write(const char* data, size_t size) 
{
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}
 
void write(const char* data) 
{
	terminal_write(data, strlen(data));
}

char* inttostr( int zahl ) 
{ 
   static char text[20];
   int loc=19;
   text[19] = 0;
   while (zahl)
   {
       --loc;
       text[loc] = (zahl%10)+'0';
       zahl/=10;
   }
   if (loc==19)
   {
      --loc;
       text[loc] = '0';
   }
   return &text[loc];
}

void writed(const int data){
	char* m = inttostr(data);
	terminal_write(m, strlen(m));
}


void clsdrv()
{
	for (int c = 0; c < 2000; c++){
		
		write(" ");
	}
	terminal_row = 0;
	terminal_column = 0;

}
