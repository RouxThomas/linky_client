ROOT_DIR=$(CURDIR)

ifndef EXECUTABLE
 $(error EXECUTABLE shall be defined !)
else

PLATFORM=cross

include $(ROOT_DIR)/def_path.mk

ifeq ($(PLATFORM),cross)
include $(ROOT_DIR)/def_cross.mk

$(EXE_DIR)/$(HEX): $(EXE_DIR)/$(EXE)
	$(OBJCOPY) -O $(FORMAT) -R .eeprom $< $@

hex: $(EXE_DIR)/$(HEX)

else

include $(ROOT_DIR)/def_native.mk
hex: $(EXE_DIR)/$(EXE)

endif

$(EXE_DIR)/$(EXE):
	@echo $(OBJ_LIST)
	$(CCPP) $(LDFLAGS) $(OBJ_LIST) -o $(EXE_DIR)/$(EXE)

SUB_OBJ_DIR = $(wildcard $(ROOT_OBJ_DIR)/*)
OBJ_LIST=$(foreach dir, $(SUB_OBJ_DIR), $(wildcard $(dir)/**.o)) $(foreach dir, $(SUB_OBJ_DIR), $(wildcard $(dir)/**.so))

telech: hex
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_WRITE_FLASH)

telech_ram: hex
	$(AVRDUDE) $(AVRDUDE_FLAGS) -D $(AVRDUDE_WRITE_FLASH)

.PHONY: clean

#endif of inputs checks
endif

