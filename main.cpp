#include "mbed.h"

DigitalOut led(LED1);

Thread thread_uart1;
Thread thread_uart2;

#define UART1_BAUD 19200
#define UART2_BAUD 115200

Serial uart1(USBTX, USBRX, "first serial object uart1", UART1_BAUD);
Serial uart2(USBTX, USBRX, "second serial object uart2", UART2_BAUD);

void uart1_thread()
{
    while (true)
    {
        if (uart1.writeable())
        {
            uart1.printf("UART1_BAUD %d\r\n", UART1_BAUD);
            wait(1);
        }
    }
}

void uart2_thread()
{
    while (true)
    {
        if (uart2.writeable())
        {
            uart2.printf("UART2_BAUD %d\r\n", UART2_BAUD);
            wait(1);
        }
    }
}

int main()
{
    thread_uart1.start(uart1_thread);
    thread_uart2.start(uart2_thread);

    while (true)
    {
        led = !led;
        wait_ms(500);
    }
}