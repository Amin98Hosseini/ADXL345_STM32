## Adxl345 library for STM32 HAL

![GY906](https://www.apogeeweb.net/upload/image/20210112/2021011210411046.jpg)


*	Author:     Amin Hosseini
*	WebSite:    https://www.elecomp-tech.ir
*	Instagram:  https://www.instagram.com/Elecomp_Tech
*	Youtube:    https://www.youtube.com/channel/UCbASsLHmmKg_32L6RTsmUrA
--------------------------------------------------------------------------------
* [x] Super Loop Supported.
* [ ] RTOS Supported.
--------------------------------------------------------------------------------
* [x] Adxl345 Tested.
* [ ] Adxl335 Tested.
-------------------------------------------------------------------------------- 
* Enable i2c Channel .
* Configure `ADXL345.h` files.
* Add 'adxl_init()' to Main File.
--------------------------------------------------------------------------------
## Super Loop example:
* file ADXL345.h
``` 
//Adxl345 Device Address 
#define adxl_address 0x53<<1

//Set i2c Handeler here
extern I2C_HandleTypeDef hi2c1;

```
* file main.c   
```
#include "ADXL345.h"
int16_t x, y, z;
int main()
{
  adxl_init()
  while (1)
  {
    x=adxl_readx();
    y=adxl_ready();
    z=adxl_readz();
  }  
}

```
