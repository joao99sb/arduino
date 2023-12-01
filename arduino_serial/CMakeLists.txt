cmake_minimum_required(VERSION 3.12)
project(SeuProjeto)

add_custom_target(default
    COMMAND avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o led.o led.c
    COMMAND avr-gcc -o led.bin led.o
    COMMAND avr-objcopy -O ihex -R .eeprom led.bin led.hex
    COMMAND sudo avrdude -F -V -c arduino -p ATMEGA328p -P /dev/ttyUSB0 -b 115200 -U flash:w:led.hex
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Building and flashing led.hex"
)
