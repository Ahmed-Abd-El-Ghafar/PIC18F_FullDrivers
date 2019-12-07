
#include "hal_gpio.h"

/**
  * @brief   
  * @param  
  * @param 
  * @retval 
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

/**
  * @brief   
  * @param  
  * @param 
  * @retval 
  */
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

/**
  * @brief   
  * @param  
  * @param 
  * @retval 
  */
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

/**
  * @brief   
  * @param  
  * @param 
  * @retval 
  */
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

/**
  * @brief   
  * @param  
  * @param 
  * @retval 
  */
void write_value_to_port(Register_t *reg, uint16_t value){
    (*reg).Register = value;
}

/**
  * @brief   
  * @param  
  * @param 
  * @retval 
  */
void port_set_specific_pins(Register_t *reg, uint8_t value){
    (*reg).Register |= (value << 0);
}

/**
  * @brief   
  * @param  
  * @param 
  * @retval 
  */
void port_clear_specific_pins(Register_t *reg, uint8_t value){
    ((*reg).Register) &= ~(value << 0);
}

/**
  * @brief   
  * @param  
  * @param 
  * @retval 
  */
uint8_t read_port(Register_t *reg){
     return (*reg).Register;
}
