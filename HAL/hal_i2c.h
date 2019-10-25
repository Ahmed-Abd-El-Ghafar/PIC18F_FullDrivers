#ifndef _HAL_I2C_H
#define _HAL_I2C_H

#include "reg.h"

typedef enum{
   I2C_MODULE1 = 0,
   I2C_MODULE2 = 1,
   I2C_MODULE3
}i2c_module_t;

static I2C_Module1_Init(void);
static I2C_Module2_Init(void);
static I2C_Module3_Init(void);

void I2C_Init(i2c_module_t module);
static void I2C_Ack(void);
static void I2C_Nack(void);
unsigned short I2C1_Start(void);
void I2C1_Repeated_Start(void);
unsigned short I2C1_Is_Idle(void);
unsigned short I2C1_Rd(unsigned short ack);
static void I2C1_Ready_Check(void);
unsigned short I2C1_Wr(unsigned short value);
unsigned short I2C1_Stop(void);

#endif