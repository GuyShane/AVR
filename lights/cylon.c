#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  DDRB=0xFF;
  int bit=0;
  int move=1;
  while(1)
    {
      PORTB=_BV(bit);
      _delay_ms(85);
      bit+=move;
      if (bit>=7||bit<=0)
	move=-move;
    }
  return(0);
}
