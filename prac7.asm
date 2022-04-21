
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov [0200h],0a5h
mov al,[0200h]
rol al,1
mov [0201h],al
mov al,[0200h]
ror al,1
mov [0202h],al
mov al,[0200h]
rcl al,1
mov [0203h],al
mov al,[0200h]
rcr al,1
mov [0204h],al
mov al,[0200h]
mov cl,03h
rcl al,cl
mov [0205h],al
mov al,[0200h]
mov cl,03h 
rcr al,cl
mov [0206h],al






