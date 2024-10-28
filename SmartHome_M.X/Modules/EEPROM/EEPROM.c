#include "EEPROM.h"
uint8_t EEPROM_Read_1Byte(uint8_t address,uint8_t reg){
    return I2C_Read1ByteRegister(address,reg);
}
void EEPROM_Write_1Byte(uint8_t address,uint8_t reg,uint8_t data){
    I2C_Write1ByteRegister(address,reg,data);
}
