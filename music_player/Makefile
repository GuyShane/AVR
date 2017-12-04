MCU=m168
MMCU=atmega168
PROGRAMMER=usbasp
SPEED=4
FILE=player

test:
	sudo avrdude -p $(MCU) -c $(PROGRAMMER) -B $(SPEED)

elf: $(FILE).c speaker.c
	avr-gcc -mmcu=$(MMCU) -DF_CPU=1000000UL -Wall -Os -o $(FILE).elf $(FILE).c speaker.c

hex: elf
	avr-objcopy -j .text -j .data -O ihex $(FILE).elf $(FILE).hex

flash: hex
	sudo avrdude -p $(MCU) -c $(PROGRAMMER) -B $(SPEED) -e -U flash:w:$(FILE).hex

clean:
	rm -rf *.elf *.hex *.o *~
