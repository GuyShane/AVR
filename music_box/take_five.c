#include <avr/io.h>
#include <util/delay.h>
#include "notes16.h"

void timer_init() {
  TCCR1A|=(1<<COM1A0);
  TCCR1B|=(1<<WGM12);
  TCCR1B|=(1<<CS10);
}

void play_note(uint16_t note, uint16_t duration) {
  OCR1A=note;
  DDRB|=(1<<PB1);
  while(duration--) {
    _delay_ms(1);
  }
  DDRB&=~(1<<PB1);
}

void quarter_note(uint16_t note) {
  play_note(note,385);
  TCNT1=0;
}

void eighth_note(uint16_t note) {
  play_note(note,192);
  TCNT1=0;
}

void sixteenth_note(uint16_t note) {
  play_note(note,96);
  TCNT1=0;
}

void half_note(uint16_t note) {
  play_note(note,769);
  TCNT1=0;
}

void dotted_half_note(uint16_t note) {
  play_note(note,1154);
  TCNT1=0;
}

void half_rest() {
  _delay_ms(769);
  TCNT1=0;
}

void quarter_rest() {
  _delay_ms(385);
  TCNT1=0;
}

int main(void) {
  timer_init();

  while(1) {
    half_rest();
    quarter_rest();

    eighth_note(B4);
    eighth_note(E5);
    eighth_note(G5);
    eighth_note(A5);
    eighth_note(Ax5);
    eighth_note(B5);
    eighth_note(Ax5);
    eighth_note(A5);
    quarter_note(G5);
    quarter_note(B4);
    quarter_note(D5);
    dotted_half_note(E5);

    sixteenth_note(Fx5);
    sixteenth_note(G5);
    sixteenth_note(Fx5);
    sixteenth_note(E5);
    quarter_note(D5);
    dotted_half_note(E5);

    sixteenth_note(D5);
    sixteenth_note(E5);
    sixteenth_note(D5);
    sixteenth_note(B4);
    quarter_note(A4);
    dotted_half_note(B4);

    eighth_note(B4);
    eighth_note(E5);
    eighth_note(G5);
    eighth_note(A5);
    eighth_note(Ax5);
    eighth_note(B5);
    eighth_note(Ax5);
    eighth_note(A5);
    quarter_note(G5);
    quarter_note(B4);
    quarter_note(D5);
    dotted_half_note(E5);

    sixteenth_note(D5);
    sixteenth_note(E5);
    sixteenth_note(D5);
    sixteenth_note(B4);
    quarter_note(A4);
    dotted_half_note(B4);

    sixteenth_note(Fx5);
    sixteenth_note(G5);
    sixteenth_note(Fx5);
    sixteenth_note(E5);
    quarter_note(D5);
    dotted_half_note(E5);
    half_note(E5);

    eighth_note(E6);
    quarter_note(G6);
    eighth_note(E6);
    quarter_note(C6);
    eighth_note(A5);
    eighth_note(B5);
    eighth_note(C6);
    eighth_note(Cx6);

    eighth_note(D6);
    quarter_note(Fx6);
    eighth_note(D6);
    quarter_note(B5);
    eighth_note(G5);
    eighth_note(A5);
    eighth_note(Ax5);
    eighth_note(B5);

    eighth_note(C6);
    quarter_note(E6);
    eighth_note(C6);
    quarter_note(A5);
    eighth_note(Fx5);
    eighth_note(G5);
    eighth_note(A5);
    eighth_note(Ax5); 

    eighth_note(B5);
    eighth_note(Ax5);
    eighth_note(B5);
    eighth_note(C6);
    quarter_note(D6);
    eighth_note(D6);
    eighth_note(Cx6);
    eighth_note(D6);
    eighth_note(Dx6);

    eighth_note(E6);
    quarter_note(G6);
    eighth_note(E6);
    quarter_note(C6);
    eighth_note(A5);
    eighth_note(B5);
    eighth_note(C6);
    eighth_note(Cx6);

    eighth_note(D6);
    quarter_note(Fx6);
    eighth_note(D6);
    quarter_note(B5);
    eighth_note(G5);
    eighth_note(A5);
    eighth_note(Ax5);
    eighth_note(B5);

    eighth_note(C6);
    quarter_note(E6);
    eighth_note(C6);
    quarter_note(A5);
    eighth_note(Fx5);
    eighth_note(G5);
    eighth_note(A5);
    eighth_note(Ax5); 

    eighth_note(Fx5);
    eighth_note(A5);    
    eighth_note(D6);
    eighth_note(C6);
    dotted_half_note(B5);

    eighth_note(B4);
    eighth_note(E5);
    eighth_note(G5);
    eighth_note(A5);
    eighth_note(Ax5);
    eighth_note(B5);
    eighth_note(Ax5);
    eighth_note(A5);
    quarter_note(G5);
    quarter_note(B4);
    quarter_note(D5);
    dotted_half_note(E5);

    sixteenth_note(Fx5);
    sixteenth_note(G5);
    sixteenth_note(Fx5);
    sixteenth_note(E5);
    quarter_note(D5);
    dotted_half_note(E5);

    sixteenth_note(D5);
    sixteenth_note(E5);
    sixteenth_note(D5);
    sixteenth_note(B4);
    quarter_note(A4);
    dotted_half_note(B4);

    eighth_note(B4);
    eighth_note(E5);
    eighth_note(G5);
    eighth_note(A5);
    eighth_note(Ax5);
    eighth_note(B5);
    eighth_note(Ax5);
    eighth_note(A5);
    quarter_note(G5);
    quarter_note(B4);
    quarter_note(D5);
    dotted_half_note(E5);

    sixteenth_note(Fx5);
    sixteenth_note(G5);
    sixteenth_note(Fx5);
    sixteenth_note(E5);
    quarter_note(D5);
    dotted_half_note(E5);

    sixteenth_note(D5);
    sixteenth_note(E5);
    sixteenth_note(D5);
    sixteenth_note(B4);
    quarter_note(A4);
    dotted_half_note(B4);
    half_note(B4);

    half_rest();
    half_rest();
    quarter_rest();
  }

  return 0;
}
