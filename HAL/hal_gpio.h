#ifndef _HAL_GPIO_H
#define _HAL_GPIO_H

#include "reg.h"

#define PORT_OUTPUT (uint8_t)(0x00)
#define PORT_INPUT  (uint8_t)(0xFF)
#define PORT_OFF    (uint8_t)(0x00)
#define PORT_ON     (uint8_t)(0xFF)
#define BIT_OFF     (uint8_t)(0U)
#define BIT_ON      (uint8_t)(1U)
#define BIT_OUTPUT  (uint8_t)(0U)
#define BIT_INPUT   (uint8_t)(1U)

#define RA0_BIT ((*(PORTA_REG_PTR)).Register_Bits.Bit0)
#define RA1_BIT ((*(PORTA_REG_PTR)).Register_Bits.Bit1)
#define RA2_BIT ((*(PORTA_REG_PTR)).Register_Bits.Bit2)
#define RA3_BIT ((*(PORTA_REG_PTR)).Register_Bits.Bit3)
#define RA4_BIT ((*(PORTA_REG_PTR)).Register_Bits.Bit4)
#define RA5_BIT ((*(PORTA_REG_PTR)).Register_Bits.Bit5)
#define RA6_BIT ((*(PORTA_REG_PTR)).Register_Bits.Bit6)
#define RA7_BIT ((*(PORTA_REG_PTR)).Register_Bits.Bit7)
#define RA0_BIT_DIR ((*(TRISA_REG_PTR)).Register_Bits.Bit0)
#define RA1_BIT_DIR ((*(TRISA_REG_PTR)).Register_Bits.Bit1)
#define RA2_BIT_DIR ((*(TRISA_REG_PTR)).Register_Bits.Bit2)
#define RA3_BIT_DIR ((*(TRISA_REG_PTR)).Register_Bits.Bit3)
#define RA4_BIT_DIR ((*(TRISA_REG_PTR)).Register_Bits.Bit4)
#define RA5_BIT_DIR ((*(TRISA_REG_PTR)).Register_Bits.Bit5)
#define RA6_BIT_DIR ((*(TRISA_REG_PTR)).Register_Bits.Bit6)
#define RA7_BIT_DIR ((*(TRISA_REG_PTR)).Register_Bits.Bit7)

#define RB0_BIT ((*(PORTB_REG_PTR)).Register_Bits.Bit0)
#define RB1_BIT ((*(PORTB_REG_PTR)).Register_Bits.Bit1)
#define RB2_BIT ((*(PORTB_REG_PTR)).Register_Bits.Bit2)
#define RB3_BIT ((*(PORTB_REG_PTR)).Register_Bits.Bit3)
#define RB4_BIT ((*(PORTB_REG_PTR)).Register_Bits.Bit4)
#define RB5_BIT ((*(PORTB_REG_PTR)).Register_Bits.Bit5)
#define RB6_BIT ((*(PORTB_REG_PTR)).Register_Bits.Bit6)
#define RB7_BIT ((*(PORTB_REG_PTR)).Register_Bits.Bit7)
#define RB0_BIT_DIR ((*(TRISB_REG_PTR)).Register_Bits.Bit0)
#define RB1_BIT_DIR ((*(TRISB_REG_PTR)).Register_Bits.Bit1)
#define RB2_BIT_DIR ((*(TRISB_REG_PTR)).Register_Bits.Bit2)
#define RB3_BIT_DIR ((*(TRISB_REG_PTR)).Register_Bits.Bit3)
#define RB4_BIT_DIR ((*(TRISB_REG_PTR)).Register_Bits.Bit4)
#define RB5_BIT_DIR ((*(TRISB_REG_PTR)).Register_Bits.Bit5)
#define RB6_BIT_DIR ((*(TRISB_REG_PTR)).Register_Bits.Bit6)
#define RB7_BIT_DIR ((*(TRISB_REG_PTR)).Register_Bits.Bit7)

#define RC0_BIT ((*(PORTC_REG_PTR)).Register_Bits.Bit0)
#define RC1_BIT ((*(PORTC_REG_PTR)).Register_Bits.Bit1)
#define RC2_BIT ((*(PORTC_REG_PTR)).Register_Bits.Bit2)
#define RC3_BIT ((*(PORTC_REG_PTR)).Register_Bits.Bit3)
#define RC4_BIT ((*(PORTC_REG_PTR)).Register_Bits.Bit4)
#define RC5_BIT ((*(PORTC_REG_PTR)).Register_Bits.Bit5)
#define RC6_BIT ((*(PORTC_REG_PTR)).Register_Bits.Bit6)
#define RC7_BIT ((*(PORTC_REG_PTR)).Register_Bits.Bit7)
#define RC0_BIT_DIR ((*(TRISC_REG_PTR)).Register_Bits.Bit0)
#define RC1_BIT_DIR ((*(TRISC_REG_PTR)).Register_Bits.Bit1)
#define RC2_BIT_DIR ((*(TRISC_REG_PTR)).Register_Bits.Bit2)
#define RC3_BIT_DIR ((*(TRISC_REG_PTR)).Register_Bits.Bit3)
#define RC4_BIT_DIR ((*(TRISC_REG_PTR)).Register_Bits.Bit4)
#define RC5_BIT_DIR ((*(TRISC_REG_PTR)).Register_Bits.Bit5)
#define RC6_BIT_DIR ((*(TRISC_REG_PTR)).Register_Bits.Bit6)
#define RC7_BIT_DIR ((*(TRISC_REG_PTR)).Register_Bits.Bit7)

#define RD0_BIT ((*(PORTD_REG_PTR)).Register_Bits.Bit0)
#define RD1_BIT ((*(PORTD_REG_PTR)).Register_Bits.Bit1)
#define RD2_BIT ((*(PORTD_REG_PTR)).Register_Bits.Bit2)
#define RD3_BIT ((*(PORTD_REG_PTR)).Register_Bits.Bit3)
#define RD4_BIT ((*(PORTD_REG_PTR)).Register_Bits.Bit4)
#define RD5_BIT ((*(PORTD_REG_PTR)).Register_Bits.Bit5)
#define RD6_BIT ((*(PORTD_REG_PTR)).Register_Bits.Bit6)
#define RD7_BIT ((*(PORTD_REG_PTR)).Register_Bits.Bit7)
#define RD0_BIT_DIR ((*(TRISD_REG_PTR)).Register_Bits.Bit0)
#define RD1_BIT_DIR ((*(TRISD_REG_PTR)).Register_Bits.Bit1)
#define RD2_BIT_DIR ((*(TRISD_REG_PTR)).Register_Bits.Bit2)
#define RD3_BIT_DIR ((*(TRISD_REG_PTR)).Register_Bits.Bit3)
#define RD4_BIT_DIR ((*(TRISD_REG_PTR)).Register_Bits.Bit4)
#define RD5_BIT_DIR ((*(TRISD_REG_PTR)).Register_Bits.Bit5)
#define RD6_BIT_DIR ((*(TRISD_REG_PTR)).Register_Bits.Bit6)
#define RD7_BIT_DIR ((*(TRISD_REG_PTR)).Register_Bits.Bit7)

#define RE0_BIT ((*(PORTE_REG_PTR)).Register_Bits.Bit0)
#define RE1_BIT ((*(PORTE_REG_PTR)).Register_Bits.Bit1)
#define RE2_BIT ((*(PORTE_REG_PTR)).Register_Bits.Bit2)
#define RE3_BIT ((*(PORTE_REG_PTR)).Register_Bits.Bit3)
#define RE0_BIT_DIR ((*(TRISE_REG_PTR)).Register_Bits.Bit0)
#define RE1_BIT_DIR ((*(TRISE_REG_PTR)).Register_Bits.Bit1)
#define RE2_BIT_DIR ((*(TRISE_REG_PTR)).Register_Bits.Bit2)
#define RE3_BIT_DIR ((*(TRISE_REG_PTR)).Register_Bits.Bit3)

typedef enum{
   OUTPUT = 0,
   INPUT
}state_t;

typedef enum{
   OFF = 0,
   ON
}power_t;

typedef enum{
   P_OFF = 0x00,
   P_ON  = 0xFF
}power_port_t;

typedef enum{
   PIN0 = 0,
   PIN1,
   PIN2,
   PIN3,
   PIN4,
   PIN5,
   PIN6,
   PIN7,
}pins_t;

void port_init_input_output(Register_t *reg, state_t state);
void port_init_on_off(Register_t *reg, power_port_t state);
void write_pin(Register_t *reg, pins_t pin, power_t state);
void write_value_to_port(Register_t *reg, uint16_t value);
void pin_init_input_output(Register_t *reg, pins_t pin, state_t state);
void port_set_specific_pins(Register_t *reg, uint8_t value);
void port_clear_specific_pins(Register_t *reg, uint8_t value);
uint8_t read_port(Register_t *reg);

#endif