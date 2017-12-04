#define F_CPU 1000000Ul

#include <avr/io.h>
#include <util/delay.h>

void PovDisplay(uint8_t byte)
{
  PORTB=byte;
  _delay_ms(5);
}

int main(void)
{
  DDRB|=0xFF;
  while(1)
    {
      PovDisplay(0b00001110);
      PovDisplay(0b00011000);
      PovDisplay(0b10111101);
      PovDisplay(0b01110110);
      PovDisplay(0b00111100);
      PovDisplay(0b00111100);
      PovDisplay(0b00111100);
      PovDisplay(0b01110110);
      PovDisplay(0b10111101);
      PovDisplay(0b00011000);
      PovDisplay(0b00001110);
      PORTB=0;
      _delay_ms(15);
    }
  return(0);
}
