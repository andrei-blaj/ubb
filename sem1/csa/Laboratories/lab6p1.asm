assume DS:data, CS:code

data segment
a db "123"
la equ $-a
b db "45"
lb equ $-b
c db la+lb dup(?)
data ends

code segment
start:

mov AX,data
mov DS,AX

mov BX,0
mov SI,0

loop1:
mov AL,a[BX]
mov c[SI],AL
add BX,1
add SI,1
cmp BX,la
jb loop1

mov BX,0

loop2:
mov AL,b[BX]
mov c[SI],AL
add BX,1
add SI,1
cmp BX,lb
jb loop2

mov AX,4C00h
int 21h

code ends
end start


