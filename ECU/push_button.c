
#include "push_button.h"

/**
  * @brief   
  * @param  
  * @param 
  * @retval 
  */
button_status_t read_push_button(Register_t *reg, pins_t pin){
    switch(pin){
         case PIN0 : return reg->Register_Bits.Bit0; break;
         case PIN1 : return reg->Register_Bits.Bit1; break;
         case PIN2 : return reg->Register_Bits.Bit2; break;
         case PIN3 : return reg->Register_Bits.Bit3; break;
         case PIN4 : return reg->Register_Bits.Bit4; break;
         case PIN5 : return reg->Register_Bits.Bit5; break;
         case PIN6 : return reg->Register_Bits.Bit6; break;
         case PIN7 : return reg->Register_Bits.Bit7; break;
    }
}
