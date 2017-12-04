#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t toggle;
volatile uint8_t on;
volatile uint8_t touch;

void init_interrupt() {
  GIMSK|=(1<<PCIE);
  PCMSK|=(1<<PCINT1);
}

void init_timer0() {
  TCCR0A|=(1<<WGM01)|(1<<WGM00);
  TCCR0A|=(1<<COM0A1);
  TCCR0B|=(1<<CS00);
}

void init_adc() {
  ADMUX|=(1<<ADLAR);
  ADCSRA|=(1<<ADPS1)|(1<<ADPS0);
  ADCSRA|=(1<<ADEN);
}

uint8_t adc_read(uint8_t pin) {
  ADMUX&=0xf0;
  uint8_t mux;
  switch (pin) {
  case PB5:
    mux=0;
    break;
  case PB2:
    mux=1;
    break;
  case PB4:
    mux=2;
    break;
  case PB3:
    mux=3;
    break;
  }
  ADMUX|=mux;
  ADCSRA|=(1<<ADSC);
  while (ADCSRA&(1<<ADSC)){}
  return ADCH;
}

ISR(PCINT0_vect) {
  if (toggle && on) {
    touch^=1;
  }
  toggle^=1;
}

int main(void) {
  init_interrupt();
  init_timer0();
  init_adc();

  sei();

  uint8_t led_level;
  uint8_t brightness;
  uint8_t threshold;

  toggle=1;
  touch=1;
  on=0;

  while(1) {
    brightness=adc_read(PB4);
    led_level=adc_read(PB2);
    threshold=adc_read(PB3);
    if (brightness<threshold) {
      on=1;
    }
    else {
      on=0;
      touch=1;
    }
    if (on && touch) {
      DDRB|=(1<<PB0);
      OCR0A=led_level;
    }
    else {
      DDRB&=~(1<<PB0);
    }
  }

  return 0;
}
