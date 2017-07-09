/*
 * states.h
 *
 * Created: 7/6/2017 11:39:27 AM
 *  Author: dornback
 */ 


#ifndef STATES_H_
#define STATES_H_

typedef enum {SPI_STATE = 0, I2C_STATE, IDLE_STATE} DemoState;

void ReadState(void);
void SpiState(void);
void I2cState(void);
void IdleState(void);

extern DemoState State;
extern void (*state_table[])();




#endif /* STATES_H_ */