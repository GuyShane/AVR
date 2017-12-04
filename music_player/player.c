#include <avr/io.h>
#include <util/delay.h>
#include "speaker.h"
#include "durations.h"
#include "pins.h"

int main(void) {
  SPEAKER_DDR=(1<<SPEAKER_PIN);
  
  //float song[]={A1,A2,A3,A4};

  while(1) {
    play_note(148,500);
    _delay_ms(500);
    //SPEAKER_PORT^=(1<<SPEAKER_PIN);
    //delay_us(A4);
  }

  return 0;
}
