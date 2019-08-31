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
                                ; whereever 'MAGIC_NUMBER' shows up, in the code
                                ; it will be replaced with 0x1BADB002
FLAGS        equ 0x0            ; multiboot flags
CHECKSUM     equ -MAGIC_NUMBER  ; calculate the checksum
                                ; (magic number + checksum + flags should equal 0)
KERNEL_STACK_SIZE equ 4096      ; size of stack in bytes (1 kilobyte)
section .text                   ; start of the text (code) section
                                ; .data is for initialized variables
                                ; .bss is for uninitialized variables
align 4                         ; the code must be 4 byte aligned
                                ; the 'align' directive inserts NOOPS or NULLs
                                ; until we are aligned on the operand (4).
                                ; operand must be a power of 2
    dd MAGIC_NUMBER             ; write the magic number to the machine code

                                ; 'dd' declares initialized date
    dd FLAGS                    ; the flags,
    dd CHECKSUM                 ; and the checksum
loader:
    mov eax, 0xCAFEBABE
    mov esp, kernel_stack + KERNEL_STACK_SIZE
    jmp kernel_main
section .bss                        ; Use the 'bss' section for the stack
    align 4                         ; align at 4 bytes for performance reasons
    kernel_stack:                   ; label points to beginning of memory
        resb KERNEL_STACK_SIZE
