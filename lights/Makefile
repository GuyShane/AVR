MCU=m168
MMCU=atmega168
PROGRAMMER=usbasp
SPEED=4
HEADERS=USART
FILE=cylon

$(FILE):
	sudo avrdude -p $(MCU) -c $(PROGRAMMER) -B $(SPEED)

elf: $(FILE).c
	avr-gcc -mmcu=$(MMCU) -Wall -Os -o $(FILE).elf $(FILE).c 

hex: elf
	avr-objcopy -j .text -j .data -O ihex $(FILE).elf $(FILE).hex

flash: hex
	sudo avrdude -p $(MCU) -c $(PROGRAMMER) -B $(SPEED) -e -U flash:w:$(FILE).hex

clean:
	rm -rf *.elf *.hex *.o *~
