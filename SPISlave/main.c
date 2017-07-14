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
    SPISlaveInit();
    
    while (1) 
    {
        SPIRead();
        // parse CMD
        // send response        
    }
}

