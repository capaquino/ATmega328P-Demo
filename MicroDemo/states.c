/*
 * states.c
 *
 * Created: 7/6/2017 11:39:40 AM
 *  Author: dornback
 */ 

#define F_CPU 1000000

#include "states.h"
#include <avr/io.h>
#include "util/delay.h"

DemoState State;
void (*state_table[])() = {SpiState, I2cState, IdleState};

void ReadState(void)
{
    if (PINB == (1<<PINB1))
        State = SPI_STATE;
    else if (PINB == (1<<PINB2))
        State = I2C_STATE;
    else
        State = IDLE_STATE;
}

void SpiState(void)
{
	PORTD = 0x20;
	_delay_ms(250);
	PORTD = 0x00;
	_delay_ms(250);
}

void I2cState(void)
{
	PORTD = 0x40;
	_delay_ms(250);
	PORTD = 0x00;
	_delay_ms(250);
}

void IdleState(void)
{
	PORTD = 0x80;
	_delay_ms(250);
	PORTD = 0x00;
	_delay_ms(250);
}
