#include <avr/io.h>
#include "UART.h"
#include <util/setbaud.h>
#include <stdlib.h>

void uart_init()
{
  UBRR0H=UBRRH_VALUE; //Set baud rate
  UBRR0L=UBRRL_VALUE;
  UCSR0A|=(1<<U2X0); 
  UCSR0B=(1<<TXEN0)|(1<<RXEN0); //Enable transmit and receive
  UCSR0C=(1<<UCSZ01)|(1<<UCSZ00); //8 bit data frame
}

void uart_transmit(uint8_t data)
{
  loop_until_bit_is_set(UCSR0A,UDRE0);
  UDR0=data;
}

uint8_t uart_receive(void)
{
  loop_until_bit_is_set(UCSR0A,RXC0);
  return UDR0;
}

void prints(const char s[])
{
  int i=0;
  while(s[i])
    {
      uart_transmit(s[i++]);
    }
}

void printsln(const char s[])
{
  prints(s);
  prints("\r\n");
}

void printint(int num)
{
  char *s=malloc(20*sizeof(char));
  itoa(num,s,10);
  prints(s);
  free(s);
}

void printint_bin(int num)
{
  char *s=malloc(64*sizeof(char));
  itoa(num,s,2);
  prints(s);
  free(s);  
}
