bits 16
org 0x7c00

boot:

    mov ax, 0x2401
    int 0x15 ;enable 20 bits
    int 0x10 ;vga text mode 3
    mov [disk],dl;
    mov dl,[disk]
    cli
    or eax,0x1
    mov cr0, eax
    mov ax, 0x2401
    mov bx,cpoy;
    jmp CODE_SEG:boot2
halt:
    cli
    hlt

st:
    dq 0x0       ;start
gdt_c:
    db 0x0
    db 10011010b
    dw 0xFFFF
    dw 0x0    
    db 11001111b
    db 0x0        ;code
    
CODE_SEG equ gdt_c - st
gdt_d            
    db 0x0
    db 10010010b
    dw 0xFFFF
    dw 0x0
    db 11001111b
    db 0x0       ;data
    
DATA_SEG equ gdt_d - st
disk:
db 0x0
gdt_end:
hi: db "Hello world!",0

p:
    dw gdt_end - st
    dd st        ;pointer

cpoy:
bits 32
boot2:
    mov ax, DATA_SEG
    add ax,2
    sub ax,2
    mov gs, ax
    mov ds, ax
    add ax,2
    sub ax,2
    mov fs, ax
    mov ss, ax
    add ax,2
    sub ax,2
    mov es, ax
    mov esi,hi
    add ax,2
    sub ax,2


    mov es, ax
    mov ebx,0xb8000
    mov es,ax
    mov es,ax
.loop:

    lodsb
    add ebx,2
    sub ebx,2
    or al,al
    jz halt
    add ebx,2
    sub ebx,2
    or eax,0x0900 ;defines colour 
    mov word [ebx], ax
    add ebx,3
    add ebx,2
    sub ebx,3
    jmp .loop 
    mov ax, DATA_SEG
    mov es, ax
    

       

times 510 - ($-$$) db 0
dw 0xaa55
times 1024 - ($-$$) db 0
