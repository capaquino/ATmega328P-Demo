/*
 * led.c
 *
 * Created: 7/15/2017 9:27:35 PM
 *  Author: dornback
 */ 

#include "led.h"

/**
 * @brief Toggles an LED at a designated rate.
 *
 */
void Blink_LED(volatile uint8_t * port, uint8_t pin)
{
    SET_BIT(*port, pin);
    _delay_ms(200);
    CLR_BIT(*port, pin);
    _delay_ms(200);
}