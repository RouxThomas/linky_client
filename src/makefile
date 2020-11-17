ROOT_DIR=$(CURDIR)/..

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

EDF_SRC_DIR  = $(CURDIR) 
EDF_INCLUDES = -I $(CURDIR) \
               -I $(EDF_READER_DIR) \
               -I $(EDF_READER_IMPL_DIR) \
               -I $(EDF_ENCODER_DIR) \
               -I $(EDF_REQUEST_DIR) \
               -I $(EDF_REQUEST_TRANSMITTER_DIR) \
               -I $(EDF_PRINTER_DIR) \
               -I $(EDF_ADAPTER_DIR) \
               -I $(EDF_STREAMS_DIR) \
               -I $(EDF_CONNECTABLE_DIR) \
               -I $(EDF_URI_DIR) \
               -I $(UTILS_DIR) \
               -I $(ETHERNET_LIB_DIR) \
               -I $(ARDUINO_CORE_DIR) \
               -I $(ARDUINO_CORE_VARIANT_STD_DIR) \
               -I $(UTILS_MEMORY_DIR)

ifeq ($(PLATFORM),cross)
   EDF_INCLUDES += -I $(SOFTWARE_SERIAL_DIR)
endif

VPATH = $(subst ' ',':',$(EDF_SRC_DIR))
EDF_OBJ_DIR = $(ROOT_OBJ_DIR)/edf
EDF_SRC_LIST=$(foreach dir, $(EDF_SRC_DIR), $(wildcard $(dir)/*.cpp))
EDF_SCR_BLACK_LIST=
EDF_FILTERED_SRC_LIST=$(sort $(filter-out $(EDF_SCR_BLACK_LIST),$(EDF_SRC_LIST)))
EDF_FILTERED_OBJ_LIST=$(foreach src, $(EDF_FILTERED_SRC_LIST), $(addprefix $(EDF_OBJ_DIR)/,$(subst .cpp,.o,$(notdir $(src)))))
EDF_FILTERED_DEP_LIST=$(foreach obj, $(EDF_FILTERED_OBJ_LIST), $(subst .o,.d,$(obj)))

$(EDF_OBJ_DIR)/%.o: %.cpp
	$(CCPP) $(CPPFLAGS) $(EDF_INCLUDES) $< -o $@

build: env $(EDF_FILTERED_OBJ_LIST)

coverage: env
	make -C $(ROOT_DIR) -f coverage.mk compute_info_cov OBJ_DIR=$(EDF_OBJ_DIR) SRC_DIR=$(EDF_SRC_DIR) 
	
env:
	@mkdir -p $(EDF_OBJ_DIR)
	@mkdir -p $(EXE_DIR)

clean:
	@rm -rf $(EDF_FILTERED_OBJ_LIST)
	@rm -rf $(EDF_FILTERED_DEP_LIST)
	@rm -rf $(EDF_OBJ_DIR)
	@rm -rf $(EXE_DIR)

#endif of inputs checks
endif
endif
