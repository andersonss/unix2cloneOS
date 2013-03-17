# Ler as portas E/S para obter dados 
# de dispositivos tal como o teclado.
.globl	inb
inb:
    movw 4(%esp), %dx
    inb %dx, %al
    ret
