#include <avr/io.h>
#include <util/delay.h>

uint16_t adc_read(uint8_t pin) {
  ADMUX&=0xf0; //Clear the multiplexer
  ADMUX|=pin; //Write the pin into the multiplexer
  ADCSRA|=(1<<ADSC); //Start the conversion
  while(ADCSRA&(1<<ADSC)) {} //Wait until the conversion is done
  return ADC;
}

int main(void) {
  uint16_t threshold;
  uint16_t light;

  ADMUX|=(1<<REFS0);
  ADCSRA|=(1<<ADPS1)|(1<<ADPS0);
  ADCSRA|=(1<<ADEN);

  DDRB=0xff;

  while(1) {
    threshold=adc_read(PC3); //The value from the poteniometer
    light=adc_read(PC2); //The light level

    if (light<threshold) {
      PORTB=0xff;
    }
    else {
      PORTB=0;
    }
  }

  return 0;
}
