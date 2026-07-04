#include <stdio.h>
#include "uart.h"

static RingBuffer txBuffer;
static RingBuffer rxBuffer;

void UART_Init(void)
{
    RingBuffer_Init(&txBuffer);
    RingBuffer_Init(&rxBuffer);
}

void UART_SendByte(uint8_t data)
{
    if (!RingBuffer_Push(&txBuffer, data))
    {
        printf("TX Buffer Full! Cannot send %c\n", data);
        return;
    }

    printf("%c", data);
}

void UART_SendString(const char *str)
{
    while (*str)
    {
        UART_SendByte(*str);
        str++;
    }
}

void UART_ReceiveByte(uint8_t data)
{
    if (!RingBuffer_Push(&rxBuffer, data))
    {
        printf("RX Buffer Full! Cannot receive %c\n", data);
    }
}

int UART_ReadByte(uint8_t *data)
{
    if (!RingBuffer_Pop(&rxBuffer, data))
    {
        printf("RX Buffer Empty!\n");
        return 0;
    }

    return 1;
}
