/*
 * led.h
 *
 * Created: 7/15/2017 9:27:24 PM
 *  Author: dornback
 */ 


#ifndef LED_H_
#define LED_H_

#define F_CPU 1000000
#include <util/delay.h>

#define SET_BIT(port, ofs)      ((port) |= (1<<ofs))
#define CLR_BIT(port, ofs)      ((port) &= ~(1<<ofs))
#define TOGGLE_BIT(port, ofs)   ((port) ^= (1<<ofs))
#define WRITE_BIT_IF_TRUE(cond, port, ofs) (cond ? SET_BIT(port, ofs) : CLR_BIT(port, ofs))

void Blink_LED(volatile uint8_t * port, uint8_t pin);



#endif /* LED_H_ */