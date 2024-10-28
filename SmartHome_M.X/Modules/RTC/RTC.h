/* 
 * File:   RTC.h
 * Author: fathy
 *
 * Created on September 6, 2024, 9:48 PM
 */

#ifndef RTC_H
#define	RTC_H
#include "../../mcc_generated_files/mcc.h"
#include "../../mcc_generated_files/examples/i2c_master_example.h"
#include "../../Modules/UART_Logging_Print/UART_Log.h"
#include "../../Modules/chr_LCD/ecu_chr_lcd.h"
typedef struct{
    uint8_t Seconds;
    uint8_t Minutes;
    uint8_t Hours;
    uint8_t Day;
    uint8_t Month;
    uint8_t Year;
}RTC_t;
extern chr_lcd_4bit_t lcd_obj = {
  .lcd_rs.direction = GPIO_DIRECTION_OUTPUT,
  .lcd_rs.logic = GPIO_LOW,
  .lcd_rs.port = PORTA_INDEX,
  .lcd_rs.pin = GPIO_PIN0,
  .lcd_en.direction = GPIO_DIRECTION_OUTPUT,
  .lcd_en.logic = GPIO_LOW,
  .lcd_en.port = PORTA_INDEX,
  .lcd_en.pin = GPIO_PIN1,
  .lcd_data[0].direction = GPIO_DIRECTION_OUTPUT,
  .lcd_data[0].logic = GPIO_LOW,
  .lcd_data[0].port = PORTA_INDEX,
  .lcd_data[0].pin = GPIO_PIN2,
  .lcd_data[1].direction = GPIO_DIRECTION_OUTPUT,
  .lcd_data[1].logic = GPIO_LOW,
  .lcd_data[1].port = PORTA_INDEX,
  .lcd_data[1].pin = GPIO_PIN3,
  .lcd_data[2].direction = GPIO_DIRECTION_OUTPUT,
  .lcd_data[2].logic = GPIO_LOW,
  .lcd_data[2].port = PORTA_INDEX,
  .lcd_data[2].pin = GPIO_PIN4,
  .lcd_data[3].direction = GPIO_DIRECTION_OUTPUT,
  .lcd_data[3].logic = GPIO_LOW,
  .lcd_data[3].port = PORTA_INDEX,
  .lcd_data[3].pin = GPIO_PIN5
};
RTC_t Set_RTC_Date_Time(void);
void Print_RTC_Date_Time(RTC_t rtc_obj);
#endif	/* RTC_H */

