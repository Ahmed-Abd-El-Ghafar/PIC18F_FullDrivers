
#include "l298_motor.h"

/**
  * @brief control motor direction in forward mode
  * @param arr : has 2 elemnts
                 arr[0] : PORTA_REG_PTR, PORTB_REG_PTR, PORTB_REG_PTR, ....
                 arr[1] : TRISA_REG_PTR, TRISB_REG_PTR, TRISC_REG_PTR
  * @param PIN1 : The first pin for the motor : PIN0, PIN1, PIN2, ....
  * @param PIN2 : The first pin for the motor : PIN0, PIN1, PIN2, ....
  * @retval Non
  */
/*void motor_forward_advance(Register_t *arr[], pins_t PIN1,pins_t PIN2){
    pin_init_input_output(arr[1], PIN1, OUTPUT);
    pin_init_input_output(arr[1], PIN2, OUTPUT);
    write_pin(arr[0], PIN1, ON);
    write_pin(arr[0], PIN2, OFF);
}*/

void motor_forward(Register_t *reg, pins_t PIN1,pins_t PIN2){
    if(reg == PORTA_REG_PTR){
        pin_init_input_output(TRISA_REG_PTR, PIN1, OUTPUT);
        pin_init_input_output(TRISA_REG_PTR, PIN2, OUTPUT);
    }
    else if(reg == PORTB_REG_PTR){
        pin_init_input_output(TRISB_REG_PTR, PIN1, OUTPUT);
        pin_init_input_output(TRISB_REG_PTR, PIN2, OUTPUT);
    }
    else if(reg == PORTC_REG_PTR){
        pin_init_input_output(TRISC_REG_PTR, PIN1, OUTPUT);
        pin_init_input_output(TRISC_REG_PTR, PIN2, OUTPUT);
    }
    else if(reg == PORTD_REG_PTR){
        pin_init_input_output(TRISD_REG_PTR, PIN1, OUTPUT);
        pin_init_input_output(TRISD_REG_PTR, PIN2, OUTPUT);
    }
    else{}
    write_pin(reg, PIN1, ON);
    write_pin(reg, PIN2, OFF);
}

void motor_backword(Register_t *reg, pins_t PIN1,pins_t pin2){
    if(reg == PORTA_REG_PTR){
        pin_init_input_output(TRISA_REG_PTR, PIN1, OUTPUT);
        pin_init_input_output(TRISA_REG_PTR, PIN2, OUTPUT);
    }
    else if(reg == PORTB_REG_PTR){
        pin_init_input_output(TRISB_REG_PTR, PIN1, OUTPUT);
        pin_init_input_output(TRISB_REG_PTR, PIN2, OUTPUT);
    }
    else if(reg == PORTC_REG_PTR){
        pin_init_input_output(TRISC_REG_PTR, PIN1, OUTPUT);
        pin_init_input_output(TRISC_REG_PTR, PIN2, OUTPUT);
    }
    else if(reg == PORTD_REG_PTR){
        pin_init_input_output(TRISD_REG_PTR, PIN1, OUTPUT);
        pin_init_input_output(TRISD_REG_PTR, PIN2, OUTPUT);
    }
    else{}
    pin_init_input_output(reg, PIN1, OUTPUT);
    pin_init_input_output(reg, PIN2, OUTPUT);
    write_pin(reg, PIN1, OFF);
    write_pin(reg, PIN2, ON);
}

void motor_stop(Register_t *reg, pins_t PIN1,pins_t pin2){
    if(reg == PORTA_REG_PTR){
        pin_init_input_output(TRISA_REG_PTR, PIN1, OUTPUT);
        pin_init_input_output(TRISA_REG_PTR, PIN2, OUTPUT);
    }
    else if(reg == PORTB_REG_PTR){
        pin_init_input_output(TRISB_REG_PTR, PIN1, OUTPUT);
        pin_init_input_output(TRISB_REG_PTR, PIN2, OUTPUT);
    }
    else if(reg == PORTC_REG_PTR){
        pin_init_input_output(TRISC_REG_PTR, PIN1, OUTPUT);
        pin_init_input_output(TRISC_REG_PTR, PIN2, OUTPUT);
    }
    else if(reg == PORTD_REG_PTR){
        pin_init_input_output(TRISD_REG_PTR, PIN1, OUTPUT);
        pin_init_input_output(TRISD_REG_PTR, PIN2, OUTPUT);
    }
    else{}
    pin_init_input_output(reg, PIN1, OUTPUT);
    pin_init_input_output(reg, PIN2, OUTPUT);
    write_pin(reg, PIN1, OFF);
    write_pin(reg, PIN2, OFF);
}