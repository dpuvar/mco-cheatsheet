
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

.model prac9

.data
 
str db "shail$"
str1 db "palindrome$"
str2 db "not palindrome$"

.code

mov ax,@data
mov ds,ax
mov si,offset str
again:
   cmp [si],'$'
   je label1
   inc si
   jmp again
   
label1:
   mov di,offset str
   dec si
   
loop2:
  cmp si,di
  jl  output1
  mov al,[si]
  mov bl,[di]
  cmp al,bl
  jne output2
  inc di
  dec si
  jmp loop2
  
output1:
lea dx,str1
mov ah,09h
int 21h  
ret

output2:
lea dx,str2
mov ah,09h
int 21h 
ret       
      







