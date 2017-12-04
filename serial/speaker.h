#include <avr/io.h>
#include <util/delay.h>

void delay_us(int time);
/*delays for time microsedonds*/

void play_note(char key,float duration);
/*Plays a note given a keyboard key for 
  duration milliseconds

  The function assumes pin PC0 is
  configured as output and has a speaker
  connected to it

  The keyboard is mapped to piano keys:
    C# D#    F# G# A#         w e   t y u 
   C  D  E  F  G  A  B  C    a s d f g h j k
*/
