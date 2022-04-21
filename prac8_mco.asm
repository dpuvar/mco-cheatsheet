
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt
 
.model prac8

.data
array db 02h,05h,06h,07h           
ans db 1 dup(0)

.code

mov cx,@data
mov ds,cx 

mov cx,0004h
mov si,offset array  
mov  bl,0000h
next:
     mov al,[si]
     add bl,al  ;considering 1 index 0
     inc si
     inc si
     loop next  
mov ans,bl      




