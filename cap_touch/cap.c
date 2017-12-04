#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/power.h>
#include "UART.h"

#define CAP PD7
#define SENSE_TIME 10
#define THRESHOLD 4000

volatile uint16_t count;

ISR(PCINT2_vect) {
  count++;
  DDRD|=(1<<CAP);
  _delay_us(1);
  DDRD&=~(1<<CAP);
  PCIFR|=(1<<PCIF2);
}

int main(void) {
  clock_prescale_set(clock_div_1);
  //uart_init();
  //uart_printsln("==========- Capacitive sensor -==========");

  DDRB=0xff;
  MCUCR|=(1<<PUD);
  PORTD|=(1<<CAP);

  PCICR|=(1<<PCIE2);
  PCMSK2|=(1<<PCINT23);

  while(1) {
    count=0;
    DDRD|=(1<<CAP);
    sei();
    _delay_ms(SENSE_TIME);
    cli();
    if (count<THRESHOLD) {
      PORTB=0xff;
    }
    else {
      PORTB=0;
    }
    //uart_printint(count);
    NL;
  }

  return 0;
}
