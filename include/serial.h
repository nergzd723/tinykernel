#ifndef SERIAL_H
#define SERIAL_H
#define SERIAL_COM1_BASE                0x3F8
#define SERIAL_DATA_PORT(base)          (base)
#define SERIAL_FIFO_COMMAND_PORT(base)  (base + 2)
#define SERIAL_LINE_COMMAND_PORT(base)  (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base)   (base + 5)
#define SERIAL_LINE_ENABLE_DLAB         0x80
void serial_configure_baud_rate(unsigned short com, unsigned short divisor)
{
    outb(SERIAL_LINE_COMMAND_PORT(com),
         SERIAL_LINE_ENABLE_DLAB);
    outb(SERIAL_DATA_PORT(com),
         (divisor >> 8) & 0x00FF);
    outb(SERIAL_DATA_PORT(com),
         divisor & 0x00FF);
}
void serial_configure_line(unsigned short com)
{
    outb(SERIAL_LINE_COMMAND_PORT(com), 0x03);
}
void serial_configure_fifo(unsigned short com)
{
    outb(SERIAL_FIFO_COMMAND_PORT(com), 0xC7);
}
void serial_configure_modem(unsigned short com)
{
    outb(SERIAL_MODEM_COMMAND_PORT(com), 0x03);

}
void serial_init(unsigned short com) {

    serial_configure_baud_rate(com, 2);

    serial_configure_line(com);

    serial_configure_fifo(com);

    serial_configure_modem(com);

}
int serial_is_transmit_fifo_empty(unsigned int com)
{
    return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20;

}

void serial_print(unsigned short com, char * s) {

    int i = 0;

    while (s[i]) {
        while (!serial_is_transmit_fifo_empty(com)) {}
        outb(SERIAL_DATA_PORT(com), s[i]);
        i++;
    }
}
#endif
