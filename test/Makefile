MCU=m168
MMCU=atmega168
PROGRAMMER=usbasp
SPEED=4
HEADERS=USART

test:
	sudo avrdude -p $(MCU) -c $(PROGRAMMER) -B $(SPEED)

elf: test.c
	avr-gcc -mmcu=$(MMCU) -DF_CPU=1000000UL -Wall -Os -o test.elf test.c 

hex: elf
	avr-objcopy -j .text -j .data -O ihex test.elf test.hex

flash: hex
	sudo avrdude -p $(MCU) -c $(PROGRAMMER) -B $(SPEED) -e -U flash:w:test.hex

clean:
	rm -rf *.elf *.hex *.o *~
