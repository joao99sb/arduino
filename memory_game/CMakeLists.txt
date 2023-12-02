cmake_minimum_required(VERSION 3.16)
project(memory_game)

set(CMAKE_C_STANDARD 11)

# Configuração do compilador AVR
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)

# Configurações específicas do AVR
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_ASM_COMPILER avr-as)
set(CMAKE_OBJCOPY avr-objcopy)

# Definições de compilação
add_definitions(-DF_CPU=16000000UL)

# Opções do compilador AVR
set(CMAKE_C_FLAGS "-mmcu=atmega328p -Os")

# Lista de arquivos fonte
file(GLOB SRC src/*.c)

# Adiciona o executável
add_executable(${PROJECT_NAME}.elf ${SRC})

# Gera o arquivo binário HEX
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex -R .eeprom ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
    COMMENT "Generating HEX file")

# Configuração para upload usando avrdude (ajuste a porta de acordo)
add_custom_target(upload
    COMMAND sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b115200 -U flash:w:${PROJECT_NAME}.hex
    DEPENDS ${PROJECT_NAME}.elf
    COMMENT "Uploading to Arduino")



add_custom_target(make ALL
    DEPENDS upload
    COMMENT "Running make")