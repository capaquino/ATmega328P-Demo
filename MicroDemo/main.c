/*
 * main.c
 *
 * Created: 7/6/2017 12:03:38 AM
 * Author : dornback
 */ 

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>
#include "states.h"
#include "spi.h" // TODO probably won't need this


int main(void)
{
    // TODO move these to led.c/h
    DDRB = 0x00; // Inputs
	DDRC = 0x20; // ON Indicator LED
	DDRD = 0xE1; // State indicator LEDs
    PORTC = 1<<PINC5;

    SPIMasterInit();

	while (1) 
    {
        ReadState();
        state_table[State]();
    }
}








