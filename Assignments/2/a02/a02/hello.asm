section .data
hello: db '.'
helloLen: equ $-hello

section .text
global _start

_start:
mov ecx, 500000

l1:
    mov esi, ecx

    mov eax, 4
    mov ebx, 1
    mov ecx, hello
    mov edx, helloLen
    int 80h

    mov ecx, esi
loop l1

mov eax, 1
mov ebx, 0
int 80h
