
#include "char_lcd.h"

/**
  * @brief   
  * @param  
  * @param 
  * @retval 
  */
static void lcd_send_eneble(void){
    write_pin(LCD_EN_PORT, LCD_EN, PIN_ON);
    Delay_us(3);
    write_pin(LCD_EN_PORT, LCD_EN, PIN_OFF);
    Delay_us(3);
}

/**
  * @brief   
  * @param  
  * @param 
  * @retval 
  */
void Lcd_Cmd(uint8_t command){
    write_pin(LCD_RS_PORT, LCD_RS, PIN_OFF);
    #if CHAR_LCD_MODE==4
    port_clear_specific_pins(LCD_DATA, 0xF0);
    port_set_specific_pins(LCD_DATA, ((read_port(LCD_DATA) | command&0xF0)));;
    lcd_send_eneble();
    Delay_us(100);
    port_clear_specific_pins(LCD_DATA, 0xF0);
    port_set_specific_pins(LCD_DATA, (read_port(LCD_DATA) |(command<<4)));
    lcd_send_eneble();
    Delay_us(100);
    #elif CHAR_LCD_MODE==8
    write_value_to_port(LCD_DATA, PORT_OFF);
    write_value_to_port(LCD_DATA, command);
    lcd_send_eneble();
    #endif
}

/**
  * @brief   
  * @param  
  * @param 
  * @retval 
  */
static void Lcd_Data(uint8_t _data){
    write_pin(LCD_RS_PORT, LCD_RS, PIN_ON);
    #if CHAR_LCD_MODE==4
    port_clear_specific_pins(LCD_DATA, 0xF0);
    port_set_specific_pins(LCD_DATA, ((read_port(LCD_DATA) | _data&0xF0)));;
    lcd_send_eneble();
    Delay_us(100);
    port_clear_specific_pins(LCD_DATA, 0xF0);
    port_set_specific_pins(LCD_DATA, (read_port(LCD_DATA) |(_data<<4)));
    lcd_send_eneble();
    Delay_us(100);
    #elif CHAR_LCD_MODE==8
    write_value_to_port(LCD_DATA, PORT_OFF);
    write_value_to_port(LCD_DATA, _data);
    lcd_send_eneble();
    #endif
}

/**
  * @brief   
  * @param  
  * @param 
  * @retval 
  */
void Lcd_Init(void){
    pin_init_input_output(LCD_RS_DIR, LCD_RS, OUTPUT);
    pin_init_input_output(LCD_EN_DIR, LCD_EN, OUTPUT);
    write_pin(LCD_RS_PORT, LCD_RS, PIN_OFF);
    write_pin(LCD_EN_PORT, LCD_EN, PIN_OFF);
    #if CHAR_LCD_MODE==4
    port_clear_specific_pins(LCD_DATA_DIR, 0xF0);
    port_clear_specific_pins(LCD_DATA, 0xF0);
    Delay_ms(20);
    /* Clear display */
    Lcd_Cmd(0x01);  lcd_send_eneble(); Delay_ms(5);
    /* Set DDRAM adress to be 0x00 from the AC and return curssor to home Position */
    Lcd_Cmd(0x02);  lcd_send_eneble(); Delay_ms(5);
    /* Display Shift OFF - Increment Currsor */
    Lcd_Cmd(0x06);  lcd_send_eneble(); Delay_ms(5);
    /* Cursor blink OFF - Underline OFF - Disblay ON */
    Lcd_Cmd(0x0C);  lcd_send_eneble(); Delay_ms(5);
    /* Right Shift - Cursor Move */
    Lcd_Cmd(0x14);  lcd_send_eneble(); Delay_ms(5);
    /* 4Bit mode - 5*7 dot format - 2 Line mode */
    Lcd_Cmd(0x28);  lcd_send_eneble();
    /* Set Display Address */
    Lcd_Cmd(0x80);  lcd_send_eneble(); Delay_ms(5);
    #elif CHAR_LCD_MODE==8
    port_init_input_output(LCD_DATA_DIR, OUTPUT);
    port_init_on_off(LCD_DATA, P_OFF);
    Delay_ms(20);
    port_init_on_off(LCD_DATA, P_OFF);
    /* 8Bit mode - 5*7 dot format - 2 Line mode */
    Lcd_Cmd(0x38); Delay_ms(5);
    lcd_send_eneble();
    Delay_ms(10);
    port_init_on_off(LCD_DATA, P_OFF);
    /* 8Bit mode - 5*7 dot format - 2 Line mode */
    Lcd_Cmd(0x38); Delay_ms(5);
    lcd_send_eneble();
    Delay_us(250); Delay_ms(5);
    port_init_on_off(LCD_DATA, P_OFF);
    /* 8Bit mode - 5*7 dot format - 2 Line mode */
    Lcd_Cmd(0x38); Delay_ms(5);
    lcd_send_eneble();
    /* Clear display */
    Lcd_Cmd(0x01);  lcd_send_eneble(); Delay_ms(5);
    /* Set DDRAM adress to be 0x00 from the AC and return curssor to home Position */
    Lcd_Cmd(0x02);  lcd_send_eneble(); Delay_ms(5);
    /* Display Shift OFF - Increment Currsor */
    Lcd_Cmd(0x06);  lcd_send_eneble(); Delay_ms(5);
    /* Cursor blink OFF - Underline OFF - Disblay ON */
    Lcd_Cmd(0x0C);  lcd_send_eneble(); Delay_ms(5);
    /* Right Shift - Cursor Move */
    Lcd_Cmd(0x14);  lcd_send_eneble(); Delay_ms(5);
    /* Set Display Address */
    Lcd_Cmd(0x80);  lcd_send_eneble(); Delay_ms(5);
    #endif
}

/**
  * @brief   
  * @param  
  * @param 
  * @retval 
  */
static void lcd_set_cursor(uint8_t row, uint8_t col){
    row--;
    col--;
    Lcd_Cmd((0x80 + ((0x40 * row) + col)));
    Delay_ms(5);
}

/**
  * @brief   
  * @param  
  * @param 
  * @retval 
  */
void Lcd_Out(uint8_t row, uint8_t column, uint8_t *text){
    lcd_set_cursor(row, column);
    while(*text) {
        Lcd_Data(*text++);
        Delay_ms(2);
    }
}

/**
  * @brief   
  * @param  
  * @param 
  * @retval 
  */
void Lcd_Out_Cp(uint8_t *text){
    while(*text) {
        Lcd_Data(*text++);
        Delay_ms(2);
    }
}

/**
  * @brief   
  * @param  
  * @param 
  * @retval 
  */
void Lcd_Chr(uint8_t row, uint8_t column, uint8_t out_char){
    lcd_set_cursor(row, column);
    Lcd_Data(out_char);
    Delay_ms(2);
}

/**
  * @brief   
  * @param  
  * @param 
  * @retval 
  */
void Lcd_Chr_Cp(uint8_t out_char){
    Lcd_Data(out_char);
    Delay_ms(2);
}

/**
  * @brief   
  * @param  
  * @param 
  * @retval 
  */
void lcd_build_customChar(uint8_t loc,uint8_t row, uint8_t column, const char array[]){
    short i;
    if(loc < 8){
       Lcd_Cmd(0x40+(loc * 8));
       for(i=0; i<=7; i++){
          Lcd_Chr_Cp(array[i]);
       }
       Lcd_Chr(row,column,loc);
    }
}
