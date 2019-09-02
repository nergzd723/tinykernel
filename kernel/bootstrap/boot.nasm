global loader                   ; the entry symbol for ELF
                                ; 'global' is a directive that includes this
                                ; symbol in the symbol table. Directives appear
                                ; at the start of the file. 'global' exports and
                                ; 'extern' imports.
extern kernel_main                    ; the starting point in our C code

MAGIC_NUMBER equ 0x1BADB002     ; define the magic number constant
                                ; 'equ' is a pseduo-instruction which does not
                                ; correspond to an x86 instruction. This one
                                ; defines a literal value for a symbol, so
                                ; whereever 'MAGIC_NUMBER' shows up, in the code,
                                ; it will be replaced with 0x1BADB002
FLAGS        equ 0x0            ; multiboot flags
CHECKSUM     equ -MAGIC_NUMBER  ; calculate the checksum
                                ; (magic number + checksum + flags should equal 0)
KERNEL_STACK_SIZE equ 4096      ; size of stack in bytes (1 kilobyte)
section .text
align 4
    dd MAGIC_NUMBER
    dd FLAGS
    dd CHECKSUM 
global halt
halt:
    cli
    hlt
global protectedmode
protectedmode:
    cli
    lgdt [gdt]
    mov eax, cr0
    or al, 1
    mov cr0, eax
loader:
    mov eax, 0xCAFEBABE
    mov esp, kernel_stack + KERNEL_STACK_SIZE   
    jmp kernel_main
    cli
    jmp $

section .bss
    align 4
    kernel_stack:
        resb KERNEL_STACK_SIZE
