global outb             ; make the label outb visible outside this file



; outb - send a byte to an I/O port

; stack: [esp + 8] the data byte

;        [esp + 4] the I/O port

;        [esp    ] return address

outb:

    mov al, [esp + 8]    ; move the data to be sent into the al register

    mov dx, [esp + 4]    ; move the address of the I/O port into the dx register

    out dx, al           ; send the data to the I/O port

    ret                  ; return to the calling function



global inb



; inb - returns a byte from the given I/O port

; stack: [esp + 4] The address of the I/O port

;        [esp    ] The return address

inb:

    mov dx, [esp + 4]       ; move the address of the I/O port to the dx register

    in  al, dx              ; read a byte from the I/O port and store it in the al register

    ret



global lgdt



; lgdt - load global descriptor table

; stack: [esp + 4] the address of the gdt description structure

;        [esp    ] return address

lgdt:

  mov edx, [esp + 4]

  lgdt [edx]

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

; stack: [esp + 4] the software interrupt that should be generated (0-255)

;        [esp    ] the return address

interrupt:
  mov eax, [esp+4]
  int 49
global keyboard_handler



keyboard_handler:
  push eax
  in al, 60h   ;; read information from the keyboard
  mov dx, 3F8h
  out dx, al 
  mov al, 20h
  mov dx, 20h
  out dx, al
  pop eax
  iret
  
global enable_hardware_interrupts
enable_hardware_interrupts:
