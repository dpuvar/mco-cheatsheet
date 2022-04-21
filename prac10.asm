
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt


.model factorial
.stack 100h
.data 
ans dw 1 dup(0) 
two db 1 dup(2) 
tcx dw 1 dup(2)
.code 
mov ax,@data 
mov ds,ax
mov cx,0010h
mov ax,0001h
next: mov dx,cx 
 mov ax,dx 
 div two 
 cmp ah,01h 
 jne for_even 
 mov tcx,cx 
 call factorial_fun 
 mov cx,tcx 
 for_even: 
 sub ans,dx 
 loop next
hlt
factorial_fun proc 
 mov ax,0001h 
 mov bx,cx 
 sub bx,0001h 
 lb: mul cx 
 loop lb
 add ans,ax 
 ret
factorial_fun endp
                     
