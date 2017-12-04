MCU=m168
MMCU=atmega168
PROGRAMMER=usbasp
SPEED=4
FILE=cap
IDIR=../include/

test:
	sudo avrdude -p $(MCU) -c $(PROGRAMMER) -B $(SPEED)

elf: $(FILE).c 
	avr-gcc -mmcu=$(MMCU) -DF_CPU=8000000UL -DBAUD=38400 -I. -I$(IDIR) -Wall -Os -o $(FILE).elf $(FILE).c $(IDIR)UART.c

hex: elf
	avr-objcopy -j .text -j .data -O ihex $(FILE).elf $(FILE).hex

flash: hex
	sudo avrdude -p $(MCU) -c $(PROGRAMMER) -B $(SPEED) -e -U flash:w:$(FILE).hex

clean:
	rm -rf *.elf *.hex *.o *~
