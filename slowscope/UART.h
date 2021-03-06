#include <avr/io.h>
#include <util/setbaud.h>

#ifndef BAUD
#define BAUD 9600
#endif

#define NL printsln("") //Prints a newline

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

void prints(const char s[]);
/*Transmits a string over the USART*/

void printsln(const char s[]);
/*Transmits a newline terminated string
  over the USART*/

void printint(int num);
/*Prints an ASCII representation of an integer*/

void printint_bin(int num);
/*Prints a number in binary*/
