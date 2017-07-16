/*
 * main.c
 *
 * Created: 7/6/2017 12:03:38 AM
 * Author : dornback
 */ 

#include <avr/io.h>
#include "states.h"
#include "spi.h" // TODO probably won't need this
#include "led.h"

int main(void)
{
    // TODO move these to general purpose init()
    DDRB = 0x00; // Inputs
	DDRC = 0x20; // ON Indicator LED
	DDRD = 0xE1; // State indicator LEDs
    SET_BIT(PORTC, 5);

    SPIMasterInit();

	while (1) 
    {
        ReadState();
        state_table[State]();
    }
}








