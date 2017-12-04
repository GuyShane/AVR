#include <avr/io.h>
#include <util/delay.h>

/*
  A function for doing integer exponentiation
 */
int raise(int base, int exp) {
  int i;
  int num=1;
  for (i=0;i<exp;i++) {
    num*=base;
  }
  return num;
}

/*
  A function to take in an analog reading from 0-1023
  and return a value for lighting up a line of 8 LEDs
 */
uint8_t get_lights(uint16_t value) {
  uint8_t shift;
  if (value<=1020) {
    shift=value>>7;
  }
  else {
    shift=8;
  }
  return raise(2,shift)-1;
}

int main(void) {
  ADMUX|=(1<<REFS0);
  ADMUX|=(1<<MUX1);
  ADCSRA|=(1<<ADPS1)|(1<<ADPS0);
  ADCSRA|=(1<<ADEN);

  DDRB=0xff;

  uint16_t adc;
  int led_shift;

  while(1) {
    ADCSRA|=(1<<ADSC);
    while(!(ADCSRA&(1<<ADSC))) {}
    PORTB=get_lights(ADC);
    _delay_ms(50);
  }

  return 0;
}
