# Escrever em portas E/S para 
# enviar dados para dispositivos.
.globl outb
outb:
    movw 4(%esp), %dx
    movb 8(%esp), %al
    outb %al, %dx
    ret
