#include <avr/io.h>
#include "UART.h"
#include "speaker.h"

int main(void)
{
  char data;

  DDRB=0xFF;
  DDRC=1;

  uart_init();

  prints("Hello");
  printsln(" world");
  printint(-255);
  NL;
  printint_bin(-1);
  NL;
  while(1)
    {
      data=uart_receive();
      play_note(data,20);
      PORTB=data;
    }
  return(0);
}
