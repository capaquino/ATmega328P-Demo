/*
 * SPISlave.c
 *
 * Created: 7/14/2017 11:07:00 AM
 * Author : dornback
 */ 

#include <avr/io.h>
#include "spi.h"
#include "led.h"


int main(void)
{
    DDRD = 0x01;
    DDRC = 0x20;
    SET_BIT(PORTC, 5);
    
    SPISlaveInit();
    
    while (1) 
    {
        // Almost could use this if it weren't for SPIWrite(0x02)
        // WRITE_BIT_IF_TRUE(SPIRead() == 0x01, PORTD, 0);
        if (SPIRead() ==  0x01)
        {
            SET_BIT(PORTD, 0);
            SPIWrite(0x02);
        }
        else
        {
            CLR_BIT(PORTD, 0);
        }         
    }           
}