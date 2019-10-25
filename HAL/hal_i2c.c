
#include "hal_i2c.h"

static I2C_Module1_Init(void){

}

static I2C_Module2_Init(void){}
static I2C_Module3_Init(void){}

void I2C_Init(i2c_module_t module){
    switch(module){
        case I2C_MODULE1: I2C_Module1_Init(); break;
        case I2C_MODULE2: I2C_Module2_Init(); break;
        case I2C_MODULE3: I2C_Module3_Init(); break;
    }
}

static void I2C_Ack(void){
    /* Acknowledge */
    SSPCON2_REG_PTR->Register_Bits.Bit5 = 0; /* ACKDT */
    /* Enable ACK to send */
    SSPCON2_REG_PTR->Register_Bits.Bit4 = 1; /* ACKEN */
    /* Waiting to be automatically cleared by hardware */
    while(SSPCON2_REG_PTR->Register_Bits.Bit4);
}

static void I2C_Nack(void){
    /* Not Acknowledge */
    SSPCON2_REG_PTR->Register_Bits.Bit5 = 1; /* ACKDT */
    /* Enable ACK to send */
    SSPCON2_REG_PTR->Register_Bits.Bit4 = 1; /* ACKEN */
    /* Waiting to be automatically cleared by hardware */
    while(SSPCON2_REG_PTR->Register_Bits.Bit4);
}

unsigned short I2C1_Start(void){
    /* Send start pulse */
    SSPCON2_REG_PTR->Register_Bits.Bit0 = 1;
    /* Wait for completion of start pulse */
    while(SSPCON2_REG_PTR->Register_Bits.Bit0);
    /* Waiting to transmit/receive */
    PIR1_REG_PTR->Register_Bits.Bit3 = 0;
    /* Check whether START detected last */
    if(!(SSPSTAT_REG_PTR->Register_Bits.Bit3)){
       return 0;  /* Return 0 to indicate start failed */
    }
    else{
       return 1;  /* Return 1 to indicate start successuful */
    }
}

void I2C1_Repeated_Start(void){}
unsigned short I2C1_Is_Idle(void){}
unsigned short I2C1_Rd(unsigned short ack){}

static void I2C1_Ready_Check(void){
    /* Wait the SSPBUF when is full or Transmit is in progress */
    while((SSPSTAT_REG_PTR->Register_Bits.Bit0) || 
          (SSPSTAT_REG_PTR->Register_Bits.Bit2));
    /* Waiting to transmit/receive */
    while(!(PIR1_REG_PTR->Register_Bits.Bit3));
    PIR1_REG_PTR->Register_Bits.Bit3 = 0;
}

unsigned short I2C1_Wr(unsigned short value){
    /* Write data to SSPBUF*/
    SSPBUF_REG_PTR->Register = value;
    /* Waiting to transmit/receive */
    I2C1_Ready_Check();
    /* Check for acknowledge bit*/
    if(SSPCON2_REG_PTR->Register_Bits.Bit6){
        return 0; /* Acknowledge was not received from slave */
    }
    else{
        return 1; /* Acknowledge was received from slave */
    }
}

unsigned short I2C1_Stop(void){
    /* Waiting to transmit/receive */
    I2C1_Ready_Check();
    /* Send stop pulse */
    SSPCON2_REG_PTR->Register_Bits.Bit2 = 1;
    /* Wait for completion of stop pulse */
    while(SSPCON2_REG_PTR->Register_Bits.Bit2);
    /* Waiting to transmit/receive */
    PIR1_REG_PTR->Register_Bits.Bit3 = 0;
    /* Check whether stop detected last */
    if(!(SSPSTAT_REG_PTR->Register_Bits.Bit3)){
       return 0;  /* Return 0 to indicate stp failed */
    }
    else{
       return 1;  /* Return 1 to indicate stop successuful */
    }
}

