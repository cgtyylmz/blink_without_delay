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

void main()
{
	DDRB |=1<<PB5;
	while(1)
	{
		PORTB &= ~(1<<PB5);
		sleep(1000);
		PORTB |= (1<<PB5);
		sleep(1000);
		}
}
