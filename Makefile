# Makefile AVR 
# written by cgtyylmz

# Project name.
src=blink
avrType=atmega328p # cpu
avrFreq=16000000 # 16MHz crystal freq.
programmerType=pi_1

cflags=-g -DF_CPU=$(avrFreq) -Wall -Os -Werror -Wextra

help:
	@echo 'clean        Delete automatically created files.'
	@echo 'edit     	Edit the .c source file.'
	@echo 'eeprom       Extract EEPROM data from .elf file and program the device with it.'
	@echo 'elf      	Create $(src).elf'
	@echo 'flash        Program $(src).hex to controller flash memory.'
	@echo 'fuses        Extract FUSES data from .elf file and program the device with it.'
	@echo 'help     	Show this text.'
	@echo 'hex      	Create all hex files for flash, eeprom and fuses.'
	@echo 'object       Create $(src).o'
	@echo 'program      Do all programming to controller.'

edit:
	vim $(src).c

makefile:
	vim Makefile


clean: 
	rm  $(src).o $(src).hex $(src).elf

object:
	avr-gcc $(cflags) -mmcu=$(avrType) -c -o $(src).o $(src).c 

elf: object
	avr-gcc $(cflags) -mmcu=$(avrType) -o $(src).elf $(src).o
	chmod a-x $(src).elf 2>&1

hex: elf
	avr-objcopy -j .text -j .data -O ihex $(src).elf $(src).hex

flash: hex
	sudo avrdude -p atmega328p -C /home/pi/Project/avr/blink_whitout_delay/avrdude.conf -c pi_1 -v -U flash:w:$(src).hex:i
	
