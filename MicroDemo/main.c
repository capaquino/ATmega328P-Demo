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

void heartbeat()
{
    PORTC |= 0x20;
    _delay_ms(250);
    PORTC &= 0xDF;
    _delay_ms(250);
}

int main(void)
{
    // State indicator LEDs
	DDRD = 0xE0;
	
	// Heartbeat
	DDRC = 0x20;
	
	while (1) 
    {
        heartbeat();
        ReadState();
        state_table[State]();
    }
}








