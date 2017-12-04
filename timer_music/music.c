#include <avr/io.h>
#include <util/delay.h>
#include "notes16.h"

void play_note(uint16_t wavelength, uint16_t duration) {
  OCR1A=wavelength;
  DDRB|=(1<<PB1);
  while(duration--) {
    _delay_ms(1);
  }
  DDRB&=~(1<<PB1);
}

int main(void) {
  TCCR1A|=(1<<COM1A0);
  TCCR1B|=(1<<WGM12);
  TCCR1B|=(1<<CS10);

  while(1) {
    play_note(E5,200);
    _delay_ms(500);
    play_note(E5,200);
    _delay_ms(100);
    play_note(C6,200);
    _delay_ms(120);
    play_note(E5,200);
    _delay_ms(500);
    play_note(E5,200);
    _delay_ms(100);
    play_note(C6,200);
    _delay_ms(120);
    play_note(E5,200);
    _delay_ms(120);
    play_note(C6,200);
    _delay_ms(120);
    play_note(B5,200);
    _delay_ms(120);
    play_note(A5,200);
    _delay_ms(120);
    play_note(G5,200);
    _delay_ms(120);
    play_note(A5,210);
    _delay_ms(110);
    play_note(B5,200);
    _delay_ms(120);
    play_note(G5,200);
    _delay_ms(120);
    play_note(E5,200);
    _delay_ms(500);
    play_note(E5,200);
    _delay_ms(100);
    play_note(B5,220);
    _delay_ms(120);
    play_note(E5,200);
    _delay_ms(500);
    play_note(E5,200);
    _delay_ms(100);
    play_note(B5,220);
    _delay_ms(120);
    play_note(E5,500);
    _delay_ms(2000);
  }

  return 0;
}
