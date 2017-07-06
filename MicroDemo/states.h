/*
 * states.h
 *
 * Created: 7/6/2017 11:39:27 AM
 *  Author: dornback
 */ 


#ifndef STATES_H_
#define STATES_H_

void SpiState();
void I2cState();
void IdleState();

typedef enum {SPI_STATE, I2C_STATE, IDLE_STATE} DemoState;
extern DemoState State;
extern void * state_table[];




#endif /* STATES_H_ */