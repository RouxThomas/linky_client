
ifndef EXECUTABLE
 $(error EXECUTABLE shall be defined !)
else

include $(ROOT_DIR)/def_common.mk
            
ARDUINO_CORE_DIR              = $(ROOT_DIR)/arduino_core_avr/cores/arduino
ARDUINO_CORE_VARIANT_DIR      = $(ROOT_DIR)/arduino_core_avr/variants
ARDUINO_CORE_VARIANT_STD_DIR  = $(ARDUINO_CORE_VARIANT_DIR)/standard
ARDUINO_CORE_LIB_DIR          = $(ROOT_DIR)/arduino_core_avr/libraries
SPI_LIB_DIR                   = $(ARDUINO_CORE_LIB_DIR)/SPI/src
SOFTWARE_SERIAL_DIR           = $(ARDUINO_CORE_LIB_DIR)/SoftwareSerial/src
ETHERNET_LIB_DIR              = $(ROOT_DIR)/arduino_libraries/ethernet/src
ETHERNET_LIB_UTIL_DIR         = $(ETHERNET_LIB_DIR)/utility

AVRDUDE_CONF                  = $(RESOURCES_DIR)/avrdude_conf/avrdude.conf

F_CPU    = 16000000L
CC       = avr-gcc
CCPP     = avr-g++
AR       = avr-ar
OBJCOPY  = avr-objcopy
AVRDUDE  = avrdude
SIZE     = avr-size

ATMEGA   = atmega328p

ASMFLAG = -c -g -x assembler-with-cpp \
          -flto -MMD -mmcu=atmega328p \
          -DF_CPU=16000000L \
          -DARDUINO=10804 \
          -DARDUINO_AVR_UNO \
          -DARDUINO_ARCH_AVR
CFLAGS =  -c -g -Os -Wall -Wextra \
          -std=gnu11 \
          -ffunction-sections \
          -fdata-sections \
          -MMD \
          -flto \
          -fno-fat-lto-objects \
          -mmcu=atmega328p \
          -DF_CPU=16000000L \
          -DARDUINO=10804 \
          -DARDUINO_AVR_UNO \
          -DARDUINO_ARCH_AVR
CPPFLAGS = -c -g -Os -Wall -Wextra \
           -std=gnu++11 \
           -fpermissive \
           -fno-exceptions \
           -ffunction-sections \
           -fdata-sections \
           -fno-threadsafe-statics \
           -MMD -flto \
           -mmcu=atmega328p \
           -DF_CPU=16000000L \
           -DARDUINO=10804 \
           -DARDUINO_AVR_UNO \
           -DARDUINO_ARCH_AVR 
LDFLAGS =  -Wall -Wextra -Os \
           -g -flto -fuse-linker-plugin \
           -Wl,--gc-sections -mmcu=atmega328p 
                           
EXE = $(EXECUTABLE).elf

HEX = $(EXECUTABLE).hex
FORMAT = ihex

AVRDUDE_PORT = /dev/ttyACM0
UPLOAD_SPEED = 115200
UPLOAD_PROTOCOL = stk500v1
AVRDUDE_WRITE_FLASH = -U flash:w:$(EXE_DIR)/$(HEX)
AVRDUDE_FLAGS = -v -V -F -D \
               -p $(ATMEGA) -P $(AVRDUDE_PORT) -c $(UPLOAD_PROTOCOL) \
               -b $(UPLOAD_SPEED) -C $(AVRDUDE_CONF)

#endif of inputs checks
endif
