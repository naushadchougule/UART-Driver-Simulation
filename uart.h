#ifndef UART_H
#define UART_H

#include <stdint.h>
#include "ring_buffer.h"

void UART_Init(void);

void UART_SendByte(uint8_t data);

void UART_SendString(const char *str);

void UART_ReceiveByte(uint8_t data);

int UART_ReadByte(uint8_t *data);

#endif
