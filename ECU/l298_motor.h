
#ifndef _L298_MOTOR_H
#define _L298_MOTOR_H

#include "hal_gpio.h"

/*void motor_forward_advance(Register_t *arr[], pins_t PIN1,pins_t PIN2);*/
void motor_forward(Register_t *reg, pins_t PIN1, pins_t pin2);
void motor_backword(Register_t *reg, pins_t PIN1, pins_t pin2);
void motor_stop(Register_t *reg, pins_t PIN1, pins_t pin2);

#endif