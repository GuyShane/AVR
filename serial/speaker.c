#include <avr/io.h>
#include <util/delay.h>

void delay_us(int time)
{
  while(time--)
    _delay_us(1);
}

void play_note(char key,float duration)
{
  float period;
  switch(key)
    {
    case 'a':
      period=477.8;
      break;
    case 'w':
      period=451.0;
      break;
    case 's':
      period=425.7;
      break;
    case 'e':
      period=401.8;
      break;
    case 'd':
      period=379.2;
      break;
    case 'f':
      period=357.9;
      break;
    case 't':
      period=337.8;
      break;
    case 'g':
      period=318.9;
      break;
    case 'y':
      period=301.0;
      break;
    case 'h':
      period=284.1;
      break;
    case 'u':
      period=268.1;
      break;
    case 'j':
      period=253.1;
      break;
    case 'k':
      period=238.9;
      break;
    default:
      period=500.0;
    }
  int times=duration/(period/1000);
  int i;
  for (i=0;i<times;i++) {
    PORTC^=1;
    delay_us((int)period);
  }
  /*for (i=0;i<duration*1000;i+=period)
    {
      PORTC^=1;
      delay_us((int)period);
      }*/
}
