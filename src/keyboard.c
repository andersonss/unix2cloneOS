#include "irq.h"
#include "monitor.h"
#include "common.h"

/* KBDUS é o Layout de Teclado dos EUA. Este é uma tabela de scancode
 * usado para o layout padrão do teclado dos EUA. Eu tenho adicionado alguns
 * comentários para você ter uma idéia de que tecla é qual, ainda
 * que Eu atribui este índice do arranjo para 0. Você pode mudar para você usar
 * qualquer que você deseja usando um macro, se você quiser! */
unsigned char kbdus[128] =
{
	0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
	'9', '0', '-', '=', '\b',	/* Backspace */
	'\t',			/* Tab */
	'q', 'w', 'e', 'r',	/* 19 */
	't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',		/* Enter key */
	0,			/* 29   - Control */
	'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
	'\'', '`',   0,		/* Left shift */
	'\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
	'm', ',', '.', '/',   0,					/* Right shift */
	'*',
	0,	/* Alt */
	' ',	/* Space bar */
	0,	/* Caps lock */
	0,	/* 59 - F1 key ... > */
	0,   0,   0,   0,   0,   0,   0,   0,
	0,	/* < ... F10 */
	0,	/* 69 - Num lock*/
	0,	/* Scroll Lock */
	0,	/* Home key */
	0,	/* Up Arrow */
	0,	/* Page Up */
	'-',
	0,	/* Left Arrow */
	0,
	0,	/* Right Arrow */
	'+',
	0,	/* 79 - End key*/
	0,	/* Down Arrow */
	0,	/* Page Down */
	0,	/* Insert Key */
	0,	/* Delete Key */
	0,   0,   0,
	0,	/* F11 Key */
	0,	/* F12 Key */
	0,	/* All other keys are undefined */
};

/* Trata a interrupção do teclado */
void keyboard_handler(struct regs *r)
{
	unsigned char scancode;

	/* Lê do buffer de dados do teclado */
	scancode = inb(0x60);

	/* Se o bit de topo do byte que nós lemos do teclado é
	 * atribuido, que por meio deste uma tecla foi justamente realizada */
	if (scancode & 0x80)
	{
		//putch('-');
		/* Você pode usar este um para ver se um usuário realizou as
		 * teclas shift, alt, ou control... */

	}
	else
	{
		/* Aqui, uma tecla foi justamente pressionada. Por favor note que se você
		 * segura um tecla, você obterá repetidas interrupções de teclas
		 * pressionadas. */
		/* Justamente para mostrar que este trabalha, nós vamos traduzir
		 * o scancode do teclado para valores ASCII, e então
		 * mostrar este na tela. Você pode ser criativo e
		 * usar algumas flags para ver se um shift é pressionado e usar um
		 * layout diferente, ou você pode adicionar outras 128 entradas
		 * ao layout acima para corresponder ao 'shift' pressionado.
		 * Se o shift é segurado pode-se usar uma grande tabela de procura,
		 * você deverá adicionar 128 para o scancode quando você procurar por isto */
		monitor_put(kbdus[scancode]);
	}
}

/* Installs the keyboard handler into IRQ1 */
void keyboard_install()
{
	irq_install_handler(1, keyboard_handler);
}