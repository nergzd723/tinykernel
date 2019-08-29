extern interrupt_handler
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
global lgdt
lgdt:
  mov edx, [esp + 4]
  lgdt [edx]
  ret
global interrupt_handler
global  load_idt
load_idt:
  mov     eax, [esp+4]
  lidt    [eax]
  ret
global interrupt
interrupt:
  mov eax, [esp+4]
  int 49

global interrupt_handler_49
interrupt_handler_49:
  push    dword 0
  push    dword 49
  jmp     common_interrupt_handler

common_interrupt_handler:
  push    eax
  push    ebx
  push    ecx
  push    edx
  push    esi
  push    edi
  push    esp
  push    ebp
  
  call    interrupt_handler
  
  pop    ebp
  pop    esp
  pop    edi
  pop    esi
  pop    edx
  pop    ecx
  pop    ebx
  pop    eax
  
  add     esp, 8
  
  iret

global enable_hardware_interrupts
enable_hardware_interrupts:
  sti
