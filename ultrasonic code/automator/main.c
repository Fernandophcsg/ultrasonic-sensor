#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 8000000L
#endif

#include <util/delay.h>

#include "lcdlib.h"
#include "ultrasonic.h"

int main(void)
{
	double distance;
	char string[10];
	
	sei();
	
	LCD_init();
	ULTRASONIC_INIT();
	
	
	while(1)
	{
		distance = (double)ultrasonic_getDistance();
		
		dtostrf(distance, 2, 0, string);
		LCD_write_string("Distance= ", 1, 1);
		LCD_write_string(string, 12, 1);
		LCD_write_string("cm", 14, 1);	/* Print distance */
		_delay_ms(200);
	}
}
