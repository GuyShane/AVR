#include <avr/io.h>
#include <util/delay.h>

#define DEBOUNCE_TIME 2000

uint8_t debounce_press(uint8_t reg, uint8_t pin) {
  if (!(reg&(1<<pin))) {
    _delay_us(DEBOUNCE_TIME);
    if (!(reg&(1<<pin))) {
      return 1;
    }
    else {
      return 0;
    }
  }
  else {
    return 0;
  }
}

int main(void) {
  DDRB=0xff; //LED pins as output
  DDRC|=(1<<PC0); //Speaker output
  PORTC|=((1<<PC6)|(1<<PC1)); //Reset and button pin pullup resistor

  uint8_t pressed=0;
  uint8_t shift=0;

  PORTB=0xff;
  _delay_ms(1000);

  PORTB=0;

  while(1) {
    if (!(PINC&(1<<PC1)) && !(pressed)) {
      shift++;
      if (shift>7) {
	shift=0;
      }
      pressed=1;
    }
    else if (PINC&(1<<PC1)) {
      pressed=0;
    }
    PORTB=(1<<shift);
    /*if (debounce_press(PINC,PC1) && !(pressed)) {
      shift++;
      if (shift>7) {
	shift=0;
      }
      pressed=1;
    }
    else if (PINC&(1<<PC1)) {
      pressed=0;
    }
    PORTB=(1<<shift);*/
  }

  return 0;
}
