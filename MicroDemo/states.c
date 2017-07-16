/*
 * states.c
 *
 * Created: 7/6/2017 11:39:40 AM
 *  Author: dornback
 */ 

#define F_CPU 1000000

#include "states.h"
#include <avr/io.h>
#include "util/delay.h" // TODO move this to led.c/h
#include "spi.h"

DemoState State;
void (*state_table[])() = {SpiState, I2cState, IdleState};

void ReadState(void)
{
    uint8_t temp;
    temp = PINC;
    
    /* This is flawed.  If PB1 and PB2 are HIGH, it will still go to SPI State and not IDLE State */
    if ((temp & 0x02) == 0x02)  
        State = SPI_STATE;      
    else if ((temp & 0x04) == 0x04 )
        State = I2C_STATE;
    else
        State = IDLE_STATE;
}

void SpiState(void)
{
    SPIWrite(0x01);
    char read = SPIRead();
    if (read == 0x02)
        PORTD |= 1<<PIND0;
    else
        PORTD &= ~(1<<PIND0);
    
    
	PORTD |= 0x20;
	_delay_ms(200);
	PORTD &= ~0x20;
	_delay_ms(200);
}

void I2cState(void)
{
	PORTD |= 0x40;
	_delay_ms(200);
	PORTD &= ~0x40;
	_delay_ms(200);
}

void IdleState(void)
{
	PORTD |= 0x80;
	_delay_ms(200);
	PORTD &= ~0x80;
	_delay_ms(200);
}
    // Need a state reset function upon entry to new state

    // possible way to call SPIMasterInit() here to allow pin sharing if needed
    // and allow initialization code to be run only once when you switch states
    // I2cStateFlag = 0;
    // IdleStateFlag = 0;
    // if (SpiStateFlag = 0)
    // {
    //     SpiStateFlag = 1;
    //     SPIMasterInit();
    // }