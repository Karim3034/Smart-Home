/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F46K20
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/
#include "mcc_generated_files/mcc.h"
#include "Modules/RTC/RTC.h"
#include "Modules/UART_Logging_Print/UART_Log.h"
#include "Modules/Temprature_Sensor/Temp_Sensor.h"
#include "Modules/EEPROM/EEPROM.h"
#include "mcc_generated_files/examples/i2c_master_example.h"
/*
                         Main application
 */
RTC_t rtc_obj;
char*res;
uint8 temp_value=0,eevalue=0;
char data[4];
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    INTERRUPT_GlobalInterruptLowEnable();

    // Disable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighDisable();

    // Disable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    EUART_Send_String("Karim Ramadan -> Smart Home\r");
    lcd_4bit_intialize(&lcd_obj);
    while (1)
    {
        lcd_4bit_send_command(&lcd_obj, _LCD_CLEAR);
        rtc_obj = Set_RTC_Date_Time();
        Print_RTC_Date_Time(rtc_obj);
        temp_value = Read_Temprature(0x9A);
        EEPROM_Write_1Byte(0xA2,0x08,0x11);
        eevalue = EEPROM_Read_1Byte(0xA2,0x08);
        I2C_Write1ByteRegister(0x10,0x00,temp_value);
        lcd_4bit_send_command(&lcd_obj,0x94);
        lcd_4bit_send_string(&lcd_obj,"Temperature: ");
        convert_byte_to_string(temp_value,&data);
        lcd_4bit_send_string(&lcd_obj,data);
        __delay_ms(100);
    }
}
/**
 End of File
*/