
#include "hal_gpio.h"

/*

*/
void port_init_input_output(Register_t *reg, state_t state){
    if(OUTPUT == state){
        reg->Register = PORT_OUTPUT;
    }
    else if(INPUT == state){
        reg->Register = PORT_INPUT;
    }
    else{
        /* MISRA C Rules */
    }
}

void port_init_on_off(Register_t *reg, power_port_t state){
    if(P_OFF == state){
        reg->Register = PORT_OFF;
    }
    else if(P_ON == state){
        reg->Register = PORT_ON;
    }
    else{
         /* MISRA C Rules */
    }
}

void write_pin(Register_t *reg, pins_t pin, power_t state){
    switch(pin){
         case PIN0 : reg->Register_Bits.Bit0 = state;  break;
         case PIN1 : reg->Register_Bits.Bit1 = state;  break;
         case PIN2 : reg->Register_Bits.Bit2 = state;  break;
         case PIN3 : reg->Register_Bits.Bit3 = state;  break;
         case PIN4 : reg->Register_Bits.Bit4 = state;  break;
         case PIN5 : reg->Register_Bits.Bit5 = state;  break;
         case PIN6 : reg->Register_Bits.Bit6 = state;  break;
         case PIN7 : reg->Register_Bits.Bit7 = state;  break;
    }
}

void pin_init_input_output(Register_t *reg, pins_t pin, state_t state){
    switch(pin){
         case PIN0 : reg->Register_Bits.Bit0 = state;  break;
         case PIN1 : reg->Register_Bits.Bit1 = state;  break;
         case PIN2 : reg->Register_Bits.Bit2 = state;  break;
         case PIN3 : reg->Register_Bits.Bit3 = state;  break;
         case PIN4 : reg->Register_Bits.Bit4 = state;  break;
         case PIN5 : reg->Register_Bits.Bit5 = state;  break;
         case PIN6 : reg->Register_Bits.Bit6 = state;  break;
         case PIN7 : reg->Register_Bits.Bit7 = state;  break;
    }
}

void write_value_to_port(Register_t *reg, uint16_t value){
    (*reg).Register = value;
}