
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

.model prac11

.data
 
a db 05h
b db dup(1)

.code

mov cx,@data
mov ds,cx
mov dl,05h
mov al,b
mov bl,a 
mov cl,01h
next:
;mov ax,b   
mul dl 
sub bl,01h
cmp bl,cl
jge next  
mov dl,al
mov ah,02h
int 21h
;mov bx,a
 




