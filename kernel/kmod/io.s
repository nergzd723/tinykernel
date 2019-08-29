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
