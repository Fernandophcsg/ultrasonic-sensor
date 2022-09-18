#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define TRIGGER_PIN PA4
#define ECHO_PIN PD6
#define ULTRASONIC_INIT() { DDRA |= (1 << TRIGGER_PIN);PORTD |= (1 << ECHO_PIN);}

float ultrasonic_getDistance(void);
void ultrasonic_init();


#endif /* ULTRASONIC_H_ */