/*
 * spi.c
 *
 * Created: 7/14/2017 10:21:06 AM
 *  Author: dornback
 */ 

#include <avr/io.h>
#include "spi.h"

void SPIMasterInit()
{
     DDRB |= (1<<MOSI) | (1<<SCK);  // MOSI, SCK -> Outputs, MISO left as input
     SPCR = (1<<SPE) | (1<<MSTR);   // SPI Enable, Master -> True
}

void SPISlaveInit()
{
    DDRB = (1<<MISO);
    SPCR = (1<<SPE);
}

void SPIWrite(char data)
{
    SPDR = data;
    while( !(SPSR & (1<<SPIF) ));       // Wait, SPIF is set 1 on transfer complete
}

char SPIRead()
{
    // TODO not sure if need to wait for read, test this
    while( !(SPSR & (1<<SPIF) ));       // Wait, SPIF is set 1 on transfer complete
    return SPDR;
}
