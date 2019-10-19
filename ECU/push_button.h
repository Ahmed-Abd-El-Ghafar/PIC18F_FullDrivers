
#ifndef _PUSH_BUTTON_H
#define _PUSH_BUTTON_H

#include "hal_gpio.h"

typedef enum{
   NOT_PRESSED = 0,
   PRESSED
}button_status_t;

button_status_t read_push_button(Register_t *reg, pins_t pin);

#endif