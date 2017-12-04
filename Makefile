MCU=m168
MMCU=atmega168
PROGRAMMER=usbasp

SPEED=1000000Ul
BAUD=9600

FLASH_OPS=-B 4 -e -U

IDIR=../include/
_INCLUDES=
INCLUDES=$(patsubst %,$(IDIR)%.c,$(_INCLUDES))

FILE=

test:
	sudo avrdude -p $(MCU) -c $(PROGRAMMER) -B 4

elf: $(FILE).c $(INCLUDES)
	avr-gcc -mmcu=$(MMCU) -DF_CPU=$(SPEED) -DBAUD=$(BAUD) -I. -I$(IDIR) -Wall -Os -o $(FILE).elf $(FILE).c $(INCLUDES)

hex: elf
	avr-objcopy -j .text -j .data -O ihex $(FILE).elf $(FILE).hex

flash: hex
	sudo avrdude -p $(MCU) -c $(PROGRAMMER) $(FLASH_OPS) flash:w:$(FILE).hex

clean:
	rm -rf *.elf *.hex *.o *~
