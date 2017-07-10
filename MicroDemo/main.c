/*
 * MicroDemo.c
 *
 * Created: 7/6/2017 12:03:38 AM
 * Author : dornback
 */ 

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>
#include "states.h"

int main(void)
{
    DDRB = 0x00; // Inputs
	DDRC = 0x20; // Heartbeat
	DDRD = 0xE0; // State indicator LEDs
	
    for (int i=0; i<10; i++)
    {
        PORTC |= 1<<PINC5;
        _delay_ms(50);
        PORTC |= 0<<PINC5;
        _delay_ms(50);
    }
    PORTC = 1<<PINC5;

	while (1) 
    {
        ReadState();
        state_table[State]();
    }
}








