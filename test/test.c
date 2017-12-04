#include <avr/io.h>
#include <util/delay.h>

int main(int argc, char *argv[]) {
  DDRB=1;
  PORTC|=(1<<PC6); //Pullup resistor for reset pin
  while (1) {
    PORTB^=1;
    _delay_ms(500);
  }

  return 0;
}
