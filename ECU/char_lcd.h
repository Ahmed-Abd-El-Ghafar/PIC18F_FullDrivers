#ifndef _CHAR_LCD_H
#define _CHAR_LCD_H

#include "char_lcd_conf.h"
#include "hal_gpio.h"

#define LCD_RS          LCD_RS_PIN
#define LCD_RS_PORT     LCD_RS_PORT_NAME
#define LCD_RS_DIR      LCD_RS_PIN_DIR
#define LCD_EN          LCD_EN_PIN
#define LCD_EN_PORT     LCD_EN_PORT_NAME
#define LCD_EN_DIR      LCD_EN_PIN_DIR
#define LCD_DATA        LCD_DATA_PORT
#define LCD_DATA_DIR    LCD_DATA_PORT_DIR

/* Clear display */
#define _LCD_CLEAR        0x01
/* Return cursor to home position, returns a shifted display to its original position. Display data RAM is unaffected. */
#define _LCD_RETURN_HOME  0x02
/* Display Shift OFF - Cursor Move */
#define _LCD_SHIFT_OFF_INCREMENT_CUR  0x06
/* Display ON - Cursor underline OFF - Cursor blink OFF */
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF  0x0C



static void lcd_send_eneble(void);
void Lcd_Cmd(uint8_t command);
static void Lcd_Data(uint8_t _data);
void Lcd_Init(void);
static void lcd_set_cursor(uint8_t row, uint8_t col);
void Lcd_Out(uint8_t row, uint8_t column, uint8_t *text);
void Lcd_Out_Cp(uint8_t *text);
void Lcd_Chr(uint8_t row, uint8_t column, uint8_t out_char);
void Lcd_Chr_Cp(uint8_t out_char);
void lcd_build_customChar(uint8_t loc,uint8_t row, uint8_t column, const char array[]);

#endif