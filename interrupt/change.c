#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(PCINT1_vect) {
  if (!(PINC&(1<<PC1))) {
    PORTB|=(1<<PB7);
  }
  else {
    PORTB&=~(1<<PB7);
  }
}

int main(void) {
  DDRB=0xff;
  PORTC|=(1<<PC1);
  
  PCICR|=(1<<PCIE1);
  PCMSK1|=(1<<PCINT9);
  sei();

  while(1) {
    PORTB^=1;
    _delay_ms(500);
  }

  return 0;
}
