
#include "seven_segment.h"

uint8_t seg_values_a[10] = {192, 249, 164, 176, 153,
                            146, 130, 248, 128, 144};

void write_digit_seven_segment(Register_t *reg, uint8_t val){
    write_value_to_port(reg, val);
}