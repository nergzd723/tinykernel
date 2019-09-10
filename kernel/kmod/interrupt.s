global interrupt_handler
interrupt_handler:
    mov eax, 0xDEADBEEF
    iret
    
global asm_lgdt
asm_lgdt:
  mov edx, [esp + 4]
  lgdt [edx]
  ret
  
GLOBAL tss_flush   ; Allows our C code to call tss_flush().
tss_flush:
  mov ax, 0x2B      ; Load the index of our TSS structure - The index is
                   ; 0x28, as it is the 5th selector and each is 8 bytes
                   ; long, but we set the bottom two bits (making 0x2B)
                   ; so that it has an RPL of 3, not zero.
  ltr ax            ; Load 0x2B into the task state register.
  ret

global  load_idt
; load_idt - Loads the interrupt descriptor table (IDT).
; stack: [esp + 4] the address of the idt description structure
;        [esp    ] the return address
load_idt:
  mov     eax, [esp+4]    ; load the address of the IDT into register eax
  lidt    [eax]             ; load the IDT
  ret                     ; return to the calling function
global interrupt
; interrupt - Generates a software interrupt
interrupt:
  push ebp ; make the caller show up in the stack trace
  mov ebp, esp
  int 49
  pop ebp
  ret
