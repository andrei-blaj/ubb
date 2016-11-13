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
imul a ;AX=a*a
add AX,7 ;AX=a*a+7
cwd ; DX:AX = a*a+7
sub AX,word ptr b
sbb DX,word ptr b+2 ; DX:AX=a*a+7-b
mov BX,AX 
mov AL,a
add AL,2
cbw
mov CX,AX
mov AX,BX
idiv CX 
mov c,AX ; c=(a*a+7-b)/(2+a)
mov r,DX ; c=(a*a+7-b)%(2+a)

mov ax,4C00h
int 21h

code ends

end start

