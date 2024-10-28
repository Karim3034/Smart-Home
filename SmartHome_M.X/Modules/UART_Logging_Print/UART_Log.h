/* 
 * File:   UART_Log.h
 * Author: fathy
 *
 * Created on September 6, 2024, 9:46 PM
 */

#ifndef UART_LOG_H
#define	UART_LOG_H

#include "../../mcc_generated_files/eusart.h"
#include "../../mcc_generated_files/mcc.h"

void EUART_Send_String(uint8_t *text);
#endif	/* UART_LOG_H */

