# Blinky Led Application

Blinky led application using timer.(whitout delay function)

I'm using Raspberry Pi Zero W GPIOs as ICSP programmer. Target device is ATmega328p-au based Arduino Nano(CH340 chip not working).

![alt text](./doc/atmega328p.jpg "Atmega328p Pinout")

## Wiring
Rpi  |  Arduino ICSP
--- | ---
+5V | VCC
GND | GND
GPIO 23 | MOSI
GPIO 18 | MISO
GPIO 24 | SCK
GPIO 12 | RESET

Also you can use Arduino.

# Makefile 

### Help

`make help`	:print commands.

### Hex

`make hex`	:Compile C file to .hex file.

In this project available with delay and without delay blinky led code. Which one you want, edit Makefile.

```makefile
# Project name.
src=blink_timer
#src=blink
```
### Flash  

Available 2 flash method.

* `make flash_pi`	:Flash hex file to Arduino using Raspberry pi GPIOs

* `make flash_arduino`	:Flash hex file to Arduino.

For `flash_arduino` you must be edit makefile for change Arduino serial port variable devPot

For `flash_pi` check avrdude configuration file location.

```makefile
avrType=atmega328p # cpu
avrFreq=16000000 # 16MHz crystal freq.
programmerType=pi_1

devPort=/dev/USB0
avrConf=/home/pi/Project/avr/blink_whitout_delay/avrdude.conf
cflags=-g -DF_CPU=$(avrFreq) -Wall -Os -Werror -Wextra
```

# AVR Timer Examination


