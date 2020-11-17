ROOT_DIR=$(CURDIR)/../../..

ifndef PLATFORM
  $(error PLATFORM shall be defined !)
else

ifndef EXECUTABLE
  $(error EXECUTABLE shall be defined !)
else

include $(ROOT_DIR)/def_path.mk

ifeq ($(PLATFORM),cross)
   include $(ROOT_DIR)/def_cross.mk
else
   include $(ROOT_DIR)/def_native.mk
endif

EDF_MAIN_SRC_DIR = $(CURDIR) $(SOFTWARE_SERIAL_DIR)
EDF_MAIN_INCLUDES = -I $(CURDIR) \
                    -I $(CURDIR)/.. \
                    -I $(EDF_READER_DIR) \
			        -I $(EDF_ENCODER_DIR) \
                    -I $(EDF_REQUEST_DIR) \
			        -I $(EDF_URI_DIR) \
			        -I $(EDF_STREAMS_DIR) \
                    -I $(EDF_CONNECTABLE_DIR) \
			        -I $(EDF_STREAMS_DIR) \
			        -I $(EDF_ADAPTER_DIR) \
			        -I $(EDF_REQUEST_TRANSMITTER_DIR) \
			        -I $(ARDUINO_CORE_DIR) \
			        -I $(ARDUINO_CORE_VARIANT_STD_DIR) \
                    -I $(SOFTWARE_SERIAL_DIR) \
                    -I $(ETHERNET_LIB_DIR) \
                    -I $(UTILS_MEMORY_DIR)

VPATH = $(subst ' ',':',$(EDF_MAIN_SRC_DIR))
OBJ_DIR = $(ROOT_OBJ_DIR)/$(EXECUTABLE)
EDF_SRC_LIST=$(foreach dir, $(EDF_MAIN_SRC_DIR), $(wildcard $(dir)/*.cpp))
EDF_SCR_BLACK_LIST=
EDF_FILTERED_SRC_LIST=$(sort $(filter-out $(EDF_SCR_BLACK_LIST),$(EDF_SRC_LIST)))
EDF_FILTERED_OBJ_LIST=$(foreach src, $(EDF_FILTERED_SRC_LIST), $(addprefix $(OBJ_DIR)/,$(subst .cpp,.o,$(notdir $(src)))))
EDF_FILTERED_DEP_LIST=$(foreach obj, $(EDF_FILTERED_OBJ_LIST), $(subst .o,.d,$(obj)))

$(OBJ_DIR)/%.o: %.cpp
	$(CCPP) $(CPPFLAGS) $(EDF_MAIN_INCLUDES) $< -o $@

build: env \
       avr_core \
       utils \
       utils_memory \
       spi \
       ethernet \
       edf \
       edf_reader \
       edf_encoder \
       edf_adapter \
       edf_uri \
       edf_transmitter \
       $(EDF_FILTERED_OBJ_LIST) \
       hex \
       size

env:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(EXE_DIR)

edf:
	@make -C $(CURDIR)/.. build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)

edf_reader:
	@make -C $(EDF_READER_IMPL_DIR)/ build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)

edf_encoder:
	@make -C $(EDF_ENCODER_DIR) build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)

edf_adapter:
	@make -C $(EDF_ADAPTER_DIR) build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)

edf_uri:
	@make -C $(EDF_URI_DIR) build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)

edf_transmitter:
	@make -C $(EDF_REQUEST_TRANSMITTER_DIR) build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)

avr_core:
	@make -C $(ARDUINO_CORE_AVR_MAKER) build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)

utils:
	@make -C $(UTILS_DIR) build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)

utils_memory:
	@make -C $(UTILS_MEMORY_DIR) build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)

spi:
	@make -C $(ARDUINO_CORE_SPI_MAKER) build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)

ethernet:
	@make -C $(ETHERNET_LIB_MAKER)  build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)	

hex:
	@make -C $(ROOT_DIR) -f download.mk hex EXECUTABLE=$(EXECUTABLE)

size:
	$(SIZE) $(EXE_DIR)/$(HEX)

download:
	@make -C $(ROOT_DIR) -f download.mk telech_ram PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)

clean:
	@rm -rf $(EDF_FILTERED_OBJ_LIST)
	@rm -rf $(EDF_FILTERED_DEP_LIST)

#endif of inputs checks
endif
endif
