cc = i686-x0r3d-elf
boot = $(kernel)bootstrap/
kernel = kernel/
kmod = $(kernel)kmod/
TDIR = ~/i686-x0r3d-elf/bin/
all:
	$(TDIR)$(cc)-as $(boot) boot.S -o boot.o
	$(TDIR)$(cc)-gcc -c $(kernel)kernel.c $(kmod)panic.c $(kmod)write.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Iinclude
	$(TDIR)$(cc)-gcc -T $(boot)linker.ld -o tinykernel.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc
	grub-file --is-x86-multiboot myos.bin
	mkdir -p isodir/boot/grub
	cp myos.bin isodir/boot/tinykernel.bin
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o tinykernel.iso isodir
	cp isodir/boot/tinykernel.iso tinykernel.iso
