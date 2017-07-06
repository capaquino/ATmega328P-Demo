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
void * state_table[] = {SpiState, I2cState, IdleState};
DemoState State;





#endif /* STATES_H_ */