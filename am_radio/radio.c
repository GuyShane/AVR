#include <avr/io.h>
#include <avr/power.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "notes16.h"

#define F_CARRIER 3

void init_timer0() {
  TCCR0A|=(1<<WGM01);
  TCCR0A|=(1<<COM0B0);
  TCCR0B|=(1<<CS00);
  OCR0B=F_CARRIER;
}

void init_timer1() {
  TCCR1B|=(1<<WGM12);
  TCCR1B|=(1<<CS11);
  TIMSK1|=(1<<OCIE1A);
}

ISR(TIMER1_COMPA_vect) {
  DDRD^=(1<<PD5);
}

void transmit(uint16_t pitch, uint16_t duration) {
  OCR1A=pitch;
  sei();
  while(duration--) {
    _delay_ms(1);
  }
  cli();
  DDRD&=~(1<<PD5);
}

void quarter_note(uint16_t note) {
  transmit(note,435);
  TCNT1=0;
}

void dotted_quarter_note(uint16_t note) {
  transmit(note,652);
  TCNT1=0;
}

void eighth_note(uint16_t note) {
  transmit(note,217);
  TCNT1=0;
}

void half_note(uint16_t note) {
  transmit(note,870);
  TCNT1=0;
}

void dotted_half_note(uint16_t note) {
  transmit(note,1304);
  TCNT1=0;
}

int main(void) {
  PORTC|=(1<<PC6);
  clock_prescale_set(clock_div_1);
  init_timer0();
  init_timer1();

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
