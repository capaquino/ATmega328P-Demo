/*
 * spi.h
 *
 * Created: 7/14/2017 10:20:48 AM
 *  Author: dornback
 */ 


#ifndef SPI_H_
#define SPI_H_

#define MOSI    PINB3
#define MISO    PINB4
#define SCK     PINB5

void SPIMasterInit();
void SPISlaveInit();
void SPIWrite(char);
char SPIRead();


#endif /* SPI_H_ */