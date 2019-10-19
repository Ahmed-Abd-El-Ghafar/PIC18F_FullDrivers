#ifndef _SEVEN_SEGEMENT_H
#define _SEVEN_SEGEMENT_H

#include "hal_gpio.h"

extern uint8_t seg_values_a[10];

typedef enum{
   ANODE = 0,
   CATHODE
}seg_type_t;

void write_digit_seven_segment(Register_t *reg, uint8_t val);

#endif