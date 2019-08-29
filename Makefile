cc = i686-x0r3d-elf
boot = $(kernel)bootstrap/
kernel = kernel/
kmod = $(kernel)kmod/
flags = -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Iinclude
TDIR = ~/i686-x0r3d-elf/bin/
all:
	$(TDIR)$(cc)-as $(boot)boot.S -o boot.o
	$(TDIR)$(cc)-gcc -c $(kernel)kernel.c -o kernel.o $(flags)
	$(TDIR)$(cc)-gcc -c $(kmod)irq.c -o irq.o $(flags)
	nasm -f elf $(kmod)io.s && cp $(kmod)io.o io.o
	$(TDIR)$(cc)-gcc -c $(kmod)panic.c -o panic.o $(flags)
	$(TDIR)$(cc)-gcc -c $(kmod)write.c -o write.o $(flags)
	$(TDIR)$(cc)-gcc -c $(kmod)art.c -o art.o $(flags)
	$(TDIR)$(cc)-gcc -T $(boot)linker.ld -o tinykernel.bin -ffreestanding -O2 -nostdlib io.o boot.o panic.o write.o kernel.o irq.o art.o -lgcc
	grub-file --is-x86-multiboot tinykernel.bin
	mkdir -p isodir/boot/grub
	cp tinykernel.bin isodir/boot/tinykernel.bin
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o tinykernel.iso isodir
