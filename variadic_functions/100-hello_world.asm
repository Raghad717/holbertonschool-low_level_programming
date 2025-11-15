section .data
    msg db 'Hello, World', 10
    len equ $ - msg      ; calculate length automatically

section .text
    global _start

_start:
    ; write system call using int 0x80
    mov eax, 4          ; sys_write
    mov ebx, 1          ; stdout
    mov ecx, msg        ; message pointer
    mov edx, len        ; message length
    int 0x80            ; interrupt for system call

    ; exit system call
    mov eax, 1          ; sys_exit
    mov ebx, 0          ; exit status
    int 0x80
