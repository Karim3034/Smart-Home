/* 
 * File:   Temp_Sensor.h
 * Author: fathy
 *
 * Created on September 7, 2024, 12:53 AM
 */

#ifndef TEMP_SENSOR_H
#define	TEMP_SENSOR_H

#include "../../mcc_generated_files/mcc.h"
#include "../../mcc_generated_files/examples/i2c_master_example.h"

uint8_t Read_Temprature(i2c_address_t address);
#endif	/* TEMP_SENSOR_H */

