#include <avr/io.h>
#include <util/setbaud.h>

#ifndef BAUD
#define BAUD 9600
#endif

#define NL uart_printsln("") //Prints a newline

void uart_init();
/*Initializes the UART of the AVR to be able
  to send and receive with one stop bit and
  8 frame bits and a baud rate as defined above*/

void uart_transmit(uint8_t data);
/*Busy waits until register ready then sends
  data*/

uint8_t uart_receive(void);
/*Waits until all data bits received then
  reads data*/

void uart_gets(char *s, int len);
/*Gets a string over USART. s is the
 string to be filled with data, and len
 is the maximum length. The maximum
 string length will be 1 less than len*/

int uart_getint(void);
/*Returns an int received over the USART*/

void uart_prints(const char s[]);
/*Transmits a string over the USART*/

void uart_printsln(const char s[]);
/*Transmits a newline terminated string
  over the USART*/

void uart_printint(int num);
/*Prints an ASCII representation of an integer*/

void uart_printint_bin(int num);
/*Prints a number in binary*/

void uart_printint_hex(int num);
/*Prints a number in hexadecimal*/
