assume CS:code, DS:data

data segment
s db "123456"
len equ $-s
d db len dup(?)
data ends

code segment
start:

mov AX,data
mov DS,AX

mov BX,0
mov SI,0

repeat:
mov AL,s[BX]
mov d[SI],AL
add BX,2
add SI,1
cmp BX,len
jb repeat

mov BX,1

abc:
mov AL,s[BX]
mov d[SI],AL
add BX,2
add SI,1
cmp BX,len
jb abc

mov AX,4C00h
int 21h
code ends
end start

