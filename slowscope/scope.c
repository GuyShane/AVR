#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"

int main(void) {
  uart_init();

  ADMUX|=(1<<REFS0); //Use AVCC for reference voltage
  ADMUX|=(1<<MUX1); //Read from PC2
  ADMUX|=(1<<ADLAR); //Left adjust data - use the first 8 bits
  ADCSRA|=(1<<ADPS1)|(1<<ADPS0); //Divide the clock by 8
  ADCSRA|=(1<<ADATE); //Auto trigger mode
  ADCSRA|=(1<<ADEN); //Enable the ADC
  ADCSRA|=(1<<ADSC); //Start conversion

  while(1) {
    uart_transmit(ADCH);
    _delay_ms(20);
  }

  return 0;
}
