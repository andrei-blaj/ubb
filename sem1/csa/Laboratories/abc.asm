assume cs: code, ds: data
data segment

a db 8
b dd 14
c dw ?
r dw ?

data ends

code segment
start:

mov ax, data
mov ds,ax
;(a*a-b+7)/(2+a)
mov AL,a
mul a ; AX=a*a
add AX,7 ; AX=a*a+7
mov DX,0 ; DX:AX=a*a+7
sub AX,word ptr b 
sbb DX,word ptr b+2 ; DX:AX=a*a+7-b
mov BX,0 
mov BL,a
add BX,2 ; BX=2+a
div BX 
mov c,AX ; c=(a*a+7-b)/(2+a)
mov r,DX ; r=(a*a+7-b)%(2+a)

mov ax,4C00h
int 21h

code ends

end start

