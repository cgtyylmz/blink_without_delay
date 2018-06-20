// blink.c an LED blinking program using timer
//
// Cagatay YILMAZ
#include<avr/io.h>
#include<util/delay.h>

void sleep(int millisec)
{
	while(millisec)
	{
		_delay_ms(1);
		millisec--;
	}
}

int main()
{
	DDRB |=1<<5;
	while(1)
	{
		PORTB &= ~(1<<5);
		sleep(100);
		PORTB |= (1<<5);
		sleep(100);
		}
	return 0;
}
