#include <avr/io.h>
#include <util/delay.h>

#define DELAY 80

void pwm(uint8_t level) {
  uint8_t i;
  PORTB=(1<<PB0);
  for (i=0;i<255;i++) {
    if (i>level) {
      PORTB=0;
    }
    _delay_us(DELAY);
  }
}

int main(void) {
  PORTC|=(1<<PC6);
  DDRB=(1<<PB0);
  
  uint8_t brightness=0;
  int8_t dir=1;

  while(1) {
    /*brightness+=dir;
    pwm(brightness);
    if (brightness==0 || brightness==255) {
      dir*=-1;
      }*/
    pwm(20);
  }

  return 0;
}
