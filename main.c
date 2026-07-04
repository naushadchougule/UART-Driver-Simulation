#include <stdio.h>
#include "uart.h"

int main(void)
{
    uint8_t data;

    UART_Init();

    UART_SendString("UART Driver Simulation\n");

    // Fill the receive buffer with 20 characters
    for (int i = 0; i < 20; i++)
    {
        UART_ReceiveByte('A' + (i % 26));
    }

    printf("\nReading data from buffer...\n\n");

    // Read all data from the buffer
    while (UART_ReadByte(&data))
    {
        printf("Received: %c\n", data);
    }

    return 0;
}
