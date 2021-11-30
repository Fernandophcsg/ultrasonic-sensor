/*
 * ultrasonic_sensor.c
 *
 * Created: 11/28/2021 6:06:18 PM
 * Author : Chiran
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

int TimerOverflow = 0;

ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;	/* Increment Timer Overflow count */
}

void trigger_and_distance();

int main(void){
	
	DDRA = 0x08;		/* Make trigger pin as output */
	PORTA = 0xFF;		/* Turn on Pull-up */
	
	
	sei();			
	TIMSK = (1 << TOIE1);
	TCCR1A = 0;		

	while(1)
	{
		trigger_and_distance();
	}
	
}
void trigger_and_distance(){
	long count;
	double distance;
	
	PORTA |= (1 << 3);
	_delay_us(10);
	PORTA &= (~(1 << 3));
	
	TCNT1 = 0;
	TCCR1B = 0x41;
	TIFR = 1<<ICF1;
	TIFR = 1<<TOV1;

	
	while ((TIFR & (1 << ICF1)) == 0);
	TCNT1 = 0;
	TCCR1B = 0x01;
	TIFR = 1<<ICF1;
	TIFR = 1<<TOV1;
	TimerOverflow = 0;

	while ((TIFR & (1 << ICF1)) == 0);
	count = ICR1 + (65535 * TimerOverflow);
	
	distance = (double)count / 466.47;
}