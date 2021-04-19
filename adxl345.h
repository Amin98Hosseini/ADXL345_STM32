#include "main.h"

//Adxl345 Device Address 
#define adxl_address 0x53<<1

//Set i2c Handeler here
extern I2C_HandleTypeDef hi2c1;



void adxl_write (uint8_t reg, uint8_t value);
void adxl_read_values (uint8_t reg);
void adxl_read_address (uint8_t reg);
void adxl_init (void);
int16_t adxl_readx(void);
int16_t adxl_ready(void);
int16_t adxl_readz(void);
