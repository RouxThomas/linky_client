export ARDUINO_CORE_AVR_MAKER=$(ROOT_DIR)/arduino_core_avr_maker
export ARDUINO_CORE_SPI_MAKER=$(ROOT_DIR)/arduino_core_spi_maker
export SOURCES_DIR=$(ROOT_DIR)/src
export UTILS_DIR=$(ROOT_DIR)/utils
export UTILS_MEMORY_DIR=$(UTILS_DIR)/memory
export UART_DIR=$(UT_DIR)/uart
export ARDUINO_LIBRARY_DIR=$(ROOT_DIR)/arduino_libraries
export ETHERNET_LIB_MAKER=$(ARDUINO_LIBRARY_DIR)/ethernet_maker
export EDF_DIR=$(SOURCES_DIR)/edf
export EDF_READER_DIR=$(EDF_DIR)/reader
export EDF_READER_IMPL_DIR=$(EDF_DIR)/reader_impl
#--- TODO  : to move out of edf
export EDF_ENCODER_DIR=$(EDF_DIR)/encoder
export EDF_URI_DIR=$(EDF_DIR)/uri
export EDF_STREAMS_DIR=$(EDF_DIR)/streams
export EDF_ADAPTER_DIR=$(EDF_DIR)/adapter
export EDF_CONNECTABLE_DIR=$(EDF_DIR)/connectable
#---
export EDF_REQUEST_DIR=$(EDF_DIR)/request
export EDF_REQUEST_TRANSMITTER_DIR=$(EDF_DIR)/request_transmitter

export BUILD_DIR=$(ROOT_DIR)/build
export LOCAL_BUILD_DIR = $(BUILD_DIR)/$(PLATFORM)/$(EXECUTABLE)
export ROOT_OBJ_DIR=$(LOCAL_BUILD_DIR)/obj
export EXE_DIR=$(LOCAL_BUILD_DIR)/exe

export TESTS_DIR=$(ROOT_DIR)/tests
export UT_DIR=$(TESTS_DIR)/unit_tests
export UT_FRAMEWORD_SRC_DIR=$(UT_DIR)/framework
export UT_TEST_DIR=$(UT_DIR)/tests
export UT_MAIN_DIR=$(UT_DIR)/main

