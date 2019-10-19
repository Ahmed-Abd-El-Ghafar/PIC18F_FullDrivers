
#ifndef _REG_H
#define _REG_H

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;

typedef union{
    uint8_t Register;
    struct{
        uint8_t Bit0 : 1;
        uint8_t Bit1 : 1;
        uint8_t Bit2 : 1;
        uint8_t Bit3 : 1;
        uint8_t Bit4 : 1;
        uint8_t Bit5 : 1;
        uint8_t Bit6 : 1;
        uint8_t Bit7 : 1;
    }Register_Bits;
}Register_t;

#define TRISD_REG_PTR     ((volatile Register_t *)0xF95)
#define TRISC_REG_PTR     ((volatile Register_t *)0xF94)
#define TRISB_REG_PTR     ((volatile Register_t *)0xF93)
#define TRISA_REG_PTR     ((volatile Register_t *)0xF92)

#define PORTD_REG_PTR     ((volatile Register_t *)0xF83)
#define PORTC_REG_PTR     ((volatile Register_t *)0xF82)
#define PORTB_REG_PTR     ((volatile Register_t *)0xF81)
#define PORTA_REG_PTR     ((volatile Register_t *)0xF80)
 
#endif