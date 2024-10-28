#include "UART_Log.h"

void EUART_Send_String(uint8_t *text){
    while(*text !='\0'){
        EUSART_Write(*text++);
   }
}