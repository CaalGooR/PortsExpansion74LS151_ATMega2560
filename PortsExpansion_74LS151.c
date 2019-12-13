#include "UART.h"
#include "Utility.h"
#include "74LS151.h"

volatile static uint8_t nbit  = 0;
char str[20];
int main()
{
	INs74xx151_Init((uint8_t *) 0x30,PF3,PF2,PF1,PF0,PF4);
	UART_Ini(0,19200,8,0,1);
	sei();
	clrscr();
	gotoxy(0,0);
	setColor(WHITE);
	UART0_puts("IO Expansion ATMega2560 \n\r");
	UART0_getch();
	while (1)
	{
		gotoxy(0,2);
		setColor(WHITE);
		UART0_puts("Byte ");
		UART0_puts(" = ");
		setColor(RED);
		UART0_puts(itoa(str,INs74xxx151_rdbyte(),16));
		UART0_getch();
	}
	return 0;
}
