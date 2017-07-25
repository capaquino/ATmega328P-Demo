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
    WRITE_BIT_IF_TRUE(SPIRead() == 0x02, PORTD, 0);
    Blink_LED(&PORTD, 5);
}

void I2cState(void)
{
    Blink_LED(&PORTD, 6);
}

void IdleState(void)
{
    Blink_LED(&PORTD, 7);
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