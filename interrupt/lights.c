#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

/*
  Blinks LED connected to PB 0, and turns LED connected to
  PB7 on and off when INT0 receives a rising or falling signal. 
  Timer0 is used to debounce the button presses
  in the ISR. Checks for presses more than ~50ms apart.
 */

volatile uint16_t time;

ISR(INT0_vect) {
  uint16_t delta=TCNT1-time;
  if (delta>50) {
    PORTB^=(1<<PB7);
    TCNT1=0;
  }
  time=TCNT1;
}

int main(void) {
  DDRB=0xff;
  PORTD|=(1<<PD2);

  TCCR1B|=(1<<CS12)|(1<<CS10); //Clock speed - 1MHz/1024
  TCNT1=0;
  time=TCNT1;
  
  EIMSK|=(1<<INT0);
  EICRA|=(1<<ISC01); //On button press - falling edge
  //EICRA|=(1<<ISC01)|(1<<ISC00) //On button release - rising edge
  sei();

  while(1) {
    PORTB^=1;
    _delay_ms(500);
  }

  return 0;
}
