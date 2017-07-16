/*
 * SPISlave.c
 *
 * Created: 7/14/2017 11:07:00 AM
 * Author : dornback
 */ 

#include <avr/io.h>
#include "spi.h"


int main(void)
{
    DDRD = 0x01;
    DDRC = 0x20;
    PORTC = 1<<PINC5;
    
    SPISlaveInit();
    char temp;
    
    while (1) 
    {
        temp = PINB;
        if ((temp & 0x02) == 0x02)
        {
            if (SPIRead() ==  0x01)
            {
                PORTD = 0x01;
                SPIWrite(0x02);
            }
        }    
        else
        {
            PORTD = 0x00;        
        }            
    }           
}

