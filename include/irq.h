void interrupt_handler(); 
void load_idt(void * idt);
void lgdt(void * gdt);
void interrupt(unsigned short* m);
