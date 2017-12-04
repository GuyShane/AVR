/*
A simple test of serial-port functionality.
Takes in a character at a time and sends it right back out,
 displaying the ASCII value on the LEDs.
*/

// ------- Preamble -------- //
#include <avr/io.h>
#include <util/delay.h>
#include "pinDefines.h"
#include "USART.h"

int main(void) {
  char serialCharacter;

  // -------- Inits --------- //
  LED_DDR = 0xff;                            /* set up LEDs for output */
  initUSART();
  //printString("Hello World!\r\n");                          /* to test */
  printString("UCSR0A: ");
  printBinaryByte(UCSR0A);
  newLine();
  printString("UCSR0B: ");
  printBinaryByte(UCSR0B);
  newLine();
  printString("UCSR0C: ");
  printBinaryByte(UCSR0C);
  newLine();
  printString("UBRR0H: ");
  printBinaryByte(UBRR0H);
  newLine();
  printString("UBRR0L: ");
  printBinaryByte(UBRR0L);
  newLine();

  // ------ Event loop ------ //
  while (1) {

    serialCharacter = receiveByte();
    transmitByte(serialCharacter);
    LED_PORT = serialCharacter;
                           /* display ascii/numeric value of character */

  }                                                  /* End event loop */
  return (0);
}
