#include <avr/io.h>
#include <util/delay.h>

void timer_init() {
  TCCR1A|=(1<<COM1A0);
  TCCR1B|=(1<<WGM12);
  TCCR1B|=(1<<CS11);
}

uint16_t adc_read(uint8_t pin) {
  ADMUX&=0xf0;
  ADMUX|=pin;
  ADCSRA|=(1<<ADSC);
  while (ADCSRA&(1<<ADSC)) {}
  return ADC;
}

int main(void) {
  uint16_t pitch;

  ADMUX|=(1<<REFS0);
  ADCSRA|=(1<<ADPS1)|(1<<ADPS0);
  ADCSRA|=(1<<ADEN);

  timer_init();

  DDRB|=(1<<PB1);

  while(1) {
    pitch=adc_read(PC2);
    if (TCNT1>=pitch) {
      TCNT1=0;
    }
    OCR1A=pitch;
  }
  
  return 0;
}
