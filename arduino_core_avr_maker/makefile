ROOT_DIR=$(CURDIR)/..

ifndef PLATFORM
$(error PLATFORM shall be defined !)
else

ifneq ($(PLATFORM),cross)
   $(error PLATFORM shall only be 'cross' !)
else

include $(ROOT_DIR)/def_cross.mk
include $(ROOT_DIR)/def_path.mk

AVRCORE_INCLUDES = -I $(ARDUINO_CORE_DIR) \
                   -I $(AVR_VARIANT_STD_DIR)

VPATH = $(subst ' ',':',$(ARDUINO_CORE_DIR))

OBJ_DIR_C = $(ROOT_OBJ_DIR)/avr_core_c
AVRCORE_SRC_C_LIST=$(foreach dir, $(ARDUINO_CORE_DIR), $(wildcard $(dir)/*.c))
AVRCORE_SRC_C_BLACK_LIST=
AVRCORE_FILTERED_SRC_C_LIST=$(sort $(filter-out $(AVRCORE_SRC_BLACK_LIST),$(AVRCORE_SRC_C_LIST)))
AVRCORE_FILTERED_OBJ_C_LIST=$(foreach src, $(AVRCORE_FILTERED_SRC_C_LIST), $(addprefix $(OBJ_DIR_C)/,$(subst .c,.o,$(notdir $(src)))))
AVRCORE_FILTERED_DEP_C_LIST=$(foreach obj, $(AVRCORE_FILTERED_OBJ_C_LIST), $(subst .o,.d,$(obj)))

OBJ_DIR_S = $(ROOT_OBJ_DIR)/avr_core_s
AVRCORE_SRC_S_LIST=$(foreach dir, $(ARDUINO_CORE_DIR), $(wildcard $(dir)/*.S))
AVRCORE_SRC_S_BLACK_LIST=
AVRCORE_FILTERED_SRC_S_LIST=$(sort $(filter-out $(AVRCORE_SRC_S_BLACK_LIST),$(AVRCORE_SRC_S_LIST)))
AVRCORE_FILTERED_OBJ_S_LIST=$(foreach src, $(AVRCORE_FILTERED_SRC_S_LIST), $(addprefix $(OBJ_DIR_S)/,$(subst .S,.so,$(notdir $(src)))))
AVRCORE_FILTERED_DEP_S_LIST=$(foreach obj, $(AVRCORE_FILTERED_OBJ_S_LIST), $(subst .so,.d,$(obj)))

OBJ_DIR_CPP = $(ROOT_OBJ_DIR)/avr_core_cpp
AVRCORE_SRC_CPP_LIST=$(foreach dir, $(ARDUINO_CORE_DIR), $(wildcard $(dir)/*.cpp))
AVRCORE_FILTERED_SRC_CPP_LIST=$(sort $(filter-out $(ARDUINO_CORE_DIR)/main.cpp,$(AVRCORE_SRC_CPP_LIST)))
AVRCORE_FILTERED_OBJ_CPP_LIST=$(foreach src, $(AVRCORE_FILTERED_SRC_CPP_LIST), $(addprefix $(OBJ_DIR_CPP)/,$(subst .cpp,.o,$(notdir $(src)))))
AVRCORE_FILTERED_DEP_CPP_LIST=$(foreach obj, $(AVRCORE_FILTERED_OBJ_CPP_LIST), $(subst .o,.d,$(obj)))

$(OBJ_DIR_C)/%.o: %.c
	$(CC) $(CFLAGS) $(AVRCORE_INCLUDES) $< -o $@

$(OBJ_DIR_CPP)/%.o: %.cpp
	$(CCPP) $(CPPFLAGS) $(AVRCORE_INCLUDES) $< -o $@

$(OBJ_DIR_S)/%.so: %.S
	$(CC) $(ASMFLAG) $(AVRCORE_INCLUDES) $< -o $@
	
build: env $(AVRCORE_FILTERED_OBJ_C_LIST) $(AVRCORE_FILTERED_OBJ_S_LIST) $(AVRCORE_FILTERED_OBJ_CPP_LIST)

env:
	@mkdir -p $(OBJ_DIR_C)
	@mkdir -p $(OBJ_DIR_S)
	@mkdir -p $(OBJ_DIR_CPP)

clean:
	@rm -rf $(AVRCORE_FILTERED_OBJ_C_LIST)
	@rm -rf $(AVRCORE_FILTERED_DEP_C_LIST)
	@rm -rf $(AVRCORE_FILTERED_OBJ_S_LIST)
	@rm -rf $(AVRCORE_FILTERED_DEP_S_LIST)
	@rm -rf $(AVRCORE_FILTERED_OBJ_CPP_LIST)
	@rm -rf $(AVRCORE_FILTERED_DEP_CPP_LIST)

#endif of inputs checks
endif
endif
