#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "UART.h"

void random_wait() {
  uint8_t time=TCNT1L;
  _delay_ms(1000);
  while(time--) {
    _delay_ms(10);
  }
}

int main(void) {
  uint16_t time;
  
  uart_init();
  
  TCCR1B|=(1<<CS12)|(1<<CS10);

  DDRB=0xff;
  PORTC=(1<<PC1);

  uart_printsln("---===== Reaction timer! =====---");
  NL;
  uart_printsln("Press any key to start...");

  while(1) {
    uart_receive();
    uart_printsln("Get ready...");
    random_wait();
    PORTB=0xff;
    uart_printsln("Go!");
    TCNT1=0;
    if (!(PINC&(1<<PC1))) {
      uart_printsln("Yeah right man.");
    }
    else {
      while (PINC&(1<<PC1)) {}
      time=TCNT1;
      char out[20];
      snprintf(out,20,"You took %dms",time);
      uart_printsln(out);
    }
    PORTB=0;
    uart_printsln("Press any button to play again");
  }

  return 0;
}
