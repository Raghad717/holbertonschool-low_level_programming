section .data
    hello db 'Hello, World', 10
    hello_len equ $ - hello

section .text
    global _start

_start:
    ; write(1, hello, hello_len)
    mov rax, 1          ; sys_write
    mov rdi, 1          ; stdout
    mov rsi, hello      ; message
    mov rdx, hello_len  ; length
    syscall

    ; exit(0)
    mov rax, 60         ; sys_exit
    xor rdi, rdi        ; return 0
    syscall
