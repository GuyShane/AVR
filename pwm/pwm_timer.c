#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t on;
volatile uint8_t touch;

void init_int0() {
  EICRA|=(1<<ISC01)|(1<<ISC00);
  EIMSK|=(1<<INT0);
}

ISR(INT0_vect) {
  if (on) {
    touch^=1;
  }
}

void init_timer1() {
  TCCR1A|=(1<<WGM11)|(1<<WGM10);
  TCCR1B|=(1<<WGM12);
  TCCR1A|=(1<<COM1A1);
  TCCR1B|=(1<<CS10);
}

void init_adc() {
  ADMUX|=(1<<REFS0);
  ADCSRA|=(1<<ADPS1)|(1<<ADPS0);
  ADCSRA|=(1<<ADEN);
}

uint16_t adc_read(uint8_t pin) {
  ADMUX&=0xf0;
  ADMUX|=pin;
  ADCSRA|=(1<<ADSC);
  while(ADCSRA&(1<<ADSC)){}
  return ADC;
}

int main(void) {
  PORTC|=(1<<PC6);

  init_timer1();
  init_adc();
  init_int0();

  sei();

  int led_level;
  int brightness;
  int thresh;

  touch=1;
  on=0;

  while(1) {
    brightness=adc_read(PC0);
    led_level=adc_read(PC1);
    thresh=adc_read(PC2);
    if (brightness<thresh) {
      on=1;
    }
    else {
      on=0;
      touch=1;
    }
    if (on && touch) {
      DDRB|=(1<<PB1);
      OCR1A=led_level;
    }
    else {
      DDRB&=~(1<<PB1);      
    }
  }

  return 0;
}
