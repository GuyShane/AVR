#include <avr/io.h>
#include <util/delay.h>
#include "pins.h"

void delay_us(uint16_t time) {
  while(time--){
    _delay_us(1);
  }
}

void play_note(uint16_t period, uint16_t duration) {
  uint16_t time;
  uint16_t i;
  for (time=0;time<duration*1000;time+=period) {
    for (i=0;i<period;i++) {
      _delay_us(1);
    }
    SPEAKER_PORT^=(1<<SPEAKER_PIN);
  }
}
