/*
 * states.h
 *
 * Created: 7/6/2017 11:39:27 AM
 *  Author: dornback
 */ 


#ifndef STATES_H_
#define STATES_H_

typedef enum {SPI_STATE, I2C_STATE, IDLE_STATE} DemoState;

void SpiState();
void I2cState();
void IdleState();


extern DemoState State;
extern void * state_table[];




#endif /* STATES_H_ */