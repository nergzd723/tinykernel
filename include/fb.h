// Documentation:
// http://wiki.osdev.org/Printing_To_Screen
#ifndef INCLUDE_FRAME_BUFFER_H
#define INCLUDE_FRAME_BUFFER_H
#include "types.h"
#include "irq.h"
#define FB_COLS 80

#define FB_ROWS 25

#define FB_CELLS FB_COLS * FB_ROWS



#define FB_BLACK 0

#define FB_BLUE 1

#define FB_GREEN 2

#define FB_CYAN 3

#define FB_RED 4

#define FB_MAGENTA 5

#define FB_BROWN 6

#define FB_LIGHT_GREY 7

#define FB_DARK_GREY 8

#define FB_LIGHT_BLUE 9

#define FB_LIGHT_GREEN 10

#define FB_LIGHT_CYAN 11

#define FB_LIGHT_RED 12

#define FB_LIGHT_MAGENTA 13

#define FB_LIGHT_BROWN 14

#define FB_WHITE 15
/* The I/O ports */
#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5
/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15
// Start of memory that maps to the frame buffer
char *fb = (char *) 0x000B8000;

/** fb_write_cell:

 *  Writes a character with the given foreground and background to position i

 *  in the framebuffer.

 *

 *  @param i  The location in the framebuffer

 *  @param c  The character

 *  @param fg The foreground color

 *  @param bg The background color

 */

void fb_write_cell(unsigned int cell, char c, unsigned char fg, unsigned char bg)

{

    int i = cell*2;

    fb[i] = c;

    fb[i + 1] = ((bg & 0x0F) << 4) | (fg & 0x0F);

}



void clear_screen()

{

  for (int i = 0; i < FB_CELLS; i++) {

    fb_write_cell(i, ' ', FB_BLACK, FB_BLACK);

  }

}



void fb_write(char * s) {

  int i = 0;

  while (s[i]) {

    fb_write_cell(i, s[i], FB_WHITE, FB_BLACK);

    i++;

  }

}



/** move_cursor:

 *  Moves the cursor of the framebuffer to the given position

 *

 *  @param pos The new position of the cursor

 */

void move_cursor_to_pos(unsigned short pos)

{

  outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);

  outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));

  outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);

  outb(FB_DATA_PORT,    pos & 0x00FF);

}



void move_cursor(unsigned short row, unsigned short col) {

  move_cursor_to_pos(row*FB_COLS + col);

}
#endif