/* 
 * File:   EEPROM.h
 * Author: fathy
 *
 * Created on September 7, 2024, 1:04 AM
 */

#ifndef EEPROM_H
#define	EEPROM_H
#include "../../mcc_generated_files/mcc.h"
#include "../../mcc_generated_files/examples/i2c_master_example.h"

uint8_t EEPROM_Read_1Byte(uint8_t address,uint8_t reg);
void EEPROM_Write_1Byte(uint8_t address,uint8_t reg,uint8_t data);
#endif	/* EEPROM_H */

