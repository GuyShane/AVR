#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"

static inline void blink() {
  PORTB=0xff;
  _delay_ms(1000);
  PORTB=0;
}

int main(void) {
  DDRC|=1;
  DDRB=0xff;
  PORTC|=(1<<PC1);
  
  uart_init();
  uart_transmit('O');
  blink();
  
  while(1) {
    if (!(PINC&(1<<PC1))) {
      uart_transmit('X');
      blink();
    }
  }

  return 0;
}
