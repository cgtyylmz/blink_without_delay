// blink.c LED blinking program using timer
//
//|**********************************************************************************
//F_CPU=16000000UL 16MHz
//prescaler = 64
//microsecont per timer0 overflow = 64*(1/16000000) = 1024 us = 1.024 ms
//
//***********************************************************************************


#include<avr/io.h>
#include<avr/interrupt.h>

volatile uint8_t overflow_count;

void timer0_init()
{

	//timer mode 64 prescler
	TCCR0B |= (1 << CS00) | (1 << CS01);
	
	//enable timer0 overflow interrupt
	TIMSK0 |= (1 << TOIE0);
 
	//initialize counter	
	TCNT0=0;

	sei();

	overflow_count=0;
	  	
}

ISR(TIMER0_OVF_vect)
{
	overflow_count++;
}
int main()
{
	//Port B pin 5 as output
	DDRB |= (1<<PB5);
	timer0_init();
	while(1)
	{
		if(overflow_count == 100)
		{
			PORTB ^= (1<<PB5);
			overflow_count = 0;
		}	
	}

	return 0;
}
