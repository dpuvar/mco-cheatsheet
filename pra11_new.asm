
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

.model pract-11 
.data 
a dw 05h 
b dw 1 dup(?)
.code 
mov ax,@data 
mov ds,ax
mov b,01h 
mov cx,05h 
mov ax,a 
mov bx,b 
mov dx,00h
next:
 mul cx 
 dec ax 
 cmp ax,dx 
 je finish 
 jmp next
finish:
 mov b,bx 
 mov a,cx
 
hlt 




