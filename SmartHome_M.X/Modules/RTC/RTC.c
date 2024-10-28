#include "RTC.h"
RTC_t rtc;
static uint8_t date_time[20];
RTC_t Set_RTC_Date_Time(){
    rtc.Seconds = I2C_Read1ByteRegister(0xD0,0x00);
    rtc.Minutes = I2C_Read1ByteRegister(0xD0,0x01);
    rtc.Hours = I2C_Read1ByteRegister(0xD0,0x02);
    rtc.Day = I2C_Read1ByteRegister(0xD0,0x04);
    rtc.Month = I2C_Read1ByteRegister(0xD0,0x05);
    rtc.Year = I2C_Read1ByteRegister(0xD0,0x06);
    return rtc;
}
void Print_RTC_Date_Time(RTC_t rtc_obj){
    date_time[0]  = (rtc_obj.Hours>>4)+'0';
    date_time[1]  = (rtc_obj.Hours&0x0F)+'0';
    date_time[2]  = ':';
    date_time[3]  = (rtc_obj.Minutes>>4)+'0';
    date_time[4]  = (rtc_obj.Minutes&0x0F)+'0';
    date_time[5]  = ':';
    date_time[6]  = (rtc_obj.Seconds>>4)+'0';
    date_time[7]  = (rtc_obj.Seconds&0x0F)+'0';
    date_time[8]  = '\r';
    date_time[9]  =  (rtc_obj.Day>>4)+'0';
    date_time[10]  = (rtc_obj.Day&0x0F)+'0';
    date_time[11]  = ':';
    date_time[12]  = (rtc_obj.Month>>4)+'0';
    date_time[13]  = (rtc_obj.Month&0x0F)+'0';
    date_time[14]  = ':';
    date_time[15]  = (rtc_obj.Year>>4)+'0';
    date_time[16]  = (rtc_obj.Year&0x0F)+'0';
    date_time[17]  = '\r';
    EUART_Send_String("Time: ");
    lcd_4bit_send_string(&lcd_obj,"Time: ");
    for(int i=0;i<9;i++){
        EUSART_Write(date_time[i]);
        if(i!=8)
            lcd_4bit_send_char_data(&lcd_obj,date_time[i]);
    }
    lcd_4bit_send_command(&lcd_obj,0xc0);
    EUART_Send_String("Date: ");
    lcd_4bit_send_string(&lcd_obj,"Date: ");
    for(int i=9;i<18;i++){
        EUSART_Write(date_time[i]);
        if(i!=17)
            lcd_4bit_send_char_data(&lcd_obj,date_time[i]);
    }
}