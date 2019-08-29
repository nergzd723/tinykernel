.set ALIGN, 1<<0
.set MEMINFO, 1<<1
.set FLAGS, ALIGN | MEMINFO
.set MAGIC, 0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM
.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:
.section .text
.global _start
global outb
outb:
    mov al, [esp + 8]
    mov dx, [esp + 4]
    out dx, al 
    ret
global inb
inb:
    mov dx, [esp + 4]
    in  al, dx
    ret

.global halt
halt:
    cli
1:  hlt
    jmp 1b
.type _start, @function
_start:
    mov $stack_top, %esp
    call kernel_main
    cli
    hlt


.size _start, . - _start
