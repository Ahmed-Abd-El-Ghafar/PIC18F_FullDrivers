#ifndef _CHAR_LCD_CONF_H
#define _CHAR_LCD_CONF_H

#include "types.h"

#define CHAR_LCD_MODE   8

#define PIN_ON  0x01
#define PIN_OFF 0x00
#define PORT_ON  0xFF
#define PORT_OFF 0x00

#define LCD_RS_PIN        PIN0
#define LCD_RS_PORT_NAME  PORTC_REG_PTR
#define LCD_RS_PIN_DIR    TRISC_REG_PTR
#define LCD_EN_PIN        PIN1
#define LCD_EN_PORT_NAME  PORTC_REG_PTR
#define LCD_EN_PIN_DIR    TRISC_REG_PTR
#define LCD_DATA_PORT     PORTD_REG_PTR
#define LCD_DATA_PORT_DIR TRISD_REG_PTR

#endif