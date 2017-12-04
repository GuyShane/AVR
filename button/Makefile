MCU=m168
MMCU=atmega168
PROGRAMMER=usbasp
SPEED=4
HEADERS=USART

test:
	sudo avrdude -p $(MCU) -c $(PROGRAMMER) -B $(SPEED)

elf: button.c
	avr-gcc -mmcu=$(MMCU) -DF_CPU=1000000UL -Wall -Os -o button.elf button.c 

hex: elf
	avr-objcopy -j .text -j .data -O ihex button.elf button.hex

flash: hex
	sudo avrdude -p $(MCU) -c $(PROGRAMMER) -B $(SPEED) -e -U flash:w:button.hex

clean:
	rm -rf *.elf *.hex *.o *~
