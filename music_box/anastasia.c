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
  play_note(note,435);
  TCNT1=0;
}

void dotted_quarter_note(uint16_t note) {
  play_note(note,652);
  TCNT1=0;
}

void eighth_note(uint16_t note) {
  play_note(note,217);
  TCNT1=0;
}

void half_note(uint16_t note) {
  play_note(note,870);
  TCNT1=0;
}

void dotted_half_note(uint16_t note) {
  play_note(note,1304);
  TCNT1=0;
}

int main(void) {
  timer_init();

  while(1) {
    quarter_note(B4);
    quarter_note(D5);
    quarter_note(Fx5);
    quarter_note(Fx4);
    quarter_note(D5);
    quarter_note(Fx5);
    quarter_note(B4);
    quarter_note(D5);
    quarter_note(Fx5);
    quarter_note(Fx4);
    quarter_note(D5);
    quarter_note(Fx5);

    eighth_note(B4);
    eighth_note(B5);
    eighth_note(G6);
    eighth_note(B5);
    eighth_note(Fx6);
    eighth_note(B5);
    eighth_note(Fx4);
    eighth_note(B5);
    eighth_note(G6);
    eighth_note(B5);
    eighth_note(Fx6);
    eighth_note(B5);
    eighth_note(B4);
    eighth_note(B5);
    eighth_note(G6);
    eighth_note(B5);
    eighth_note(Fx6);
    eighth_note(B5);
    eighth_note(Fx4);
    eighth_note(B5);
    eighth_note(G6);
    eighth_note(B5);
    eighth_note(Fx6);
    eighth_note(B5);

    eighth_note(Cx5);
    eighth_note(B5);
    eighth_note(G6);
    eighth_note(B5);
    eighth_note(Fx6);
    eighth_note(B5);
    eighth_note(Fx4);
    eighth_note(Ax5);
    eighth_note(G6);
    eighth_note(Ax5);
    eighth_note(Fx6);
    eighth_note(Ax5);
    eighth_note(Cx5);
    eighth_note(B5);
    eighth_note(G6);
    eighth_note(B5);
    eighth_note(Fx6);
    eighth_note(B5);
    eighth_note(Fx4);
    eighth_note(Ax5);
    eighth_note(G6);
    eighth_note(Ax5);
    eighth_note(Fx6);
    eighth_note(Ax5);

    eighth_note(B3);
    eighth_note(B5);
    eighth_note(G6);
    eighth_note(B5);
    eighth_note(Fx6);
    eighth_note(B5);
    eighth_note(Fx3);
    eighth_note(Ax5);
    eighth_note(G6);
    eighth_note(Ax5);
    eighth_note(Fx6);
    eighth_note(Ax5);
    eighth_note(B3);
    eighth_note(B5);
    eighth_note(G6);
    eighth_note(B5);
    eighth_note(Fx6);
    eighth_note(B5);
    eighth_note(Fx3);
    eighth_note(Ax5);
    eighth_note(G6);
    eighth_note(Ax5);
    eighth_note(Fx6);
    eighth_note(Ax5);

    half_note(Fx4);
    quarter_note(G4);
    dotted_half_note(Fx4);

    half_note(A4);
    quarter_note(G4);
    dotted_half_note(E4);

    half_note(G4);
    quarter_note(E4);
    quarter_note(Fx4);
    dotted_quarter_note(D4);
    eighth_note(B3);
    dotted_half_note(E4);
    dotted_half_note(Fx4);

    half_note(Fx4);
    quarter_note(G4);
    dotted_half_note(Fx4);

    half_note(Fx4);
    quarter_note(B4);
    dotted_half_note(E4);

    half_note(G4);
    quarter_note(E4);
    dotted_quarter_note(Fx4);
    eighth_note(D4);
    quarter_note(B3);
    half_note(Cx4);
    quarter_note(D4);
    dotted_half_note(B3);

    half_note(A4);
    quarter_note(G4);
    half_note(A4);
    quarter_note(G4);
    half_note(G4);
    quarter_note(Fx4);
    dotted_half_note(Fx4);

    half_note(G4);
    quarter_note(Fx4);
    quarter_note(Fx4);
    dotted_quarter_note(A4);
    eighth_note(G4);
    half_note(G4);
    quarter_note(Fx4);
    dotted_half_note(Fx4);

    half_note(A4);
    quarter_note(G4);
    half_note(A4);
    quarter_note(G4);
    half_note(G4);
    quarter_note(Fx4);
    half_note(Fx4);

    quarter_note(D4);
    half_note(Cx4);
    quarter_note(D4);
    half_note(Cx4);
    quarter_note(D4);
    dotted_half_note(Fx4);
    dotted_half_note(Fx4);

    _delay_ms(1304);
  }

  return 0;
}
