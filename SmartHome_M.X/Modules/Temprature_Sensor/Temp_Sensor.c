#include "Temp_Sensor.h"
uint8_t Read_Temprature(uint8_t address){
    return I2C_Read1ByteRegister(address,0x00);
}