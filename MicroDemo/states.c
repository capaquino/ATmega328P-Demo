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
    uint8_t temp;
    temp = PINB;
    
    // something is wrong with this logic
    // or electrically something is causing PINB to flip voltages, may need pull down resistors or define their behaviour
    if ((temp & 0x02) == 0x02)
        State = SPI_STATE;
    else if ((temp & 0x04) == 0x04 )
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
