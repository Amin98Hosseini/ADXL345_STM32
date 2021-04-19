#include "adxl345.h"

uint8_t data_rec[6];
uint8_t chipid=0;
char x_char[3], y_char[3], z_char[3];

void adxl_write (uint8_t reg, uint8_t value)
{
	uint8_t data[2];
	data[0] = reg;
	data[1] = value;
	HAL_I2C_Master_Transmit (&hi2c1, adxl_address, data, 2, 100);
}

void adxl_read_values (uint8_t reg)
{
	HAL_I2C_Mem_Read (&hi2c1, adxl_address, reg, 1, (uint8_t *)data_rec, 6, 100);
}

void adxl_read_address (uint8_t reg)
{
	HAL_I2C_Mem_Read (&hi2c1, adxl_address, reg, 1, &chipid, 1, 100);
}

void adxl_init (void)
{
	adxl_read_address (0x00); // read the DEVID

	adxl_write (0x31, 0x01);  // data_format range= +- 4g
	adxl_write (0x2d, 0x00);  // reset all bits
	adxl_write (0x2d, 0x08);  // power_cntl measure and wake up 8hz

}

int16_t adxl_readx(void)
{
	int16_t x;
	adxl_read_values (0x32);
	x = ((data_rec[1]<<8)|data_rec[0]);
	return x;
}

int16_t adxl_ready(void)
{
	int16_t y;
	adxl_read_values (0x32);
	y = ((data_rec[3]<<8)|data_rec[2]);
	return y;
}

int16_t adxl_readz(void)
{
	int16_t z;
	adxl_read_values (0x32);
	z = ((data_rec[5]<<8)|data_rec[4]);
	return z;
}
