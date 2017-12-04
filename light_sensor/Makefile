MCU=m168
MMCU=atmega168
PROGRAMMER=usbasp
SPEED=4
FILE=light

test:
	sudo avrdude -p $(MCU) -c $(PROGRAMMER) -B $(SPEED)

elf: $(FILE).c UART.c
	avr-gcc -mmcu=$(MMCU) -DF_CPU=1000000UL -DBAUD=9600 -Wall -Os -o $(FILE).elf $(FILE).c UART.c

hex: elf
	avr-objcopy -j .text -j .data -O ihex $(FILE).elf $(FILE).hex

flash: hex
	sudo avrdude -p $(MCU) -c $(PROGRAMMER) -B $(SPEED) -e -U flash:w:$(FILE).hex

clean:
	rm -rf *.elf *.hex *.o *~
