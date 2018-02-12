/*
 * states.c
 *
 * Created: 7/6/2017 11:39:40 AM
 *  Author: dornback
 */ 

#include <avr/io.h>
#include "states.h"
#include "spi.h"
#include "led.h"

DemoState State;
void (*state_table[])() = {SpiState, I2cState, IdleState, InvalidState};

void ReadState(void)
{
    uint8_t temp;
    temp = PINC;
    
    switch (temp & 0b00000111) // PC0-2
    {
        case 0b0001: State = IDLE_STATE;    break; //PC0 hi
        case 0b0010: State = SPI_STATE;     break; //PC1 hi
        case 0b0100: State = I2C_STATE;     break; //PC2 hi
        default: State = INVALID_STATE;
    }
}

void SpiState(void)
{
    SPIWrite(0x01);
    if (SPIRead() ==  0x02)
    {
        Blink_LED(&PORTD, 0);
    }
    Blink_LED(&PORTD, 6); // state led
}

void I2cState(void)
{
    Blink_LED(&PORTD, 5); // state led
}

void IdleState(void)
{
    Blink_LED(&PORTD, 7); // state led
}

void InvalidState(void)
{
    Blink_LED(&PORTB, 0);
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