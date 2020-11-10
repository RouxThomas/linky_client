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

EDF_ADAPT_SRC_DIR  = $(CURDIR)
EDF_ADAPT_INCLUDES = -I $(CURDIR) \
                           -I $(EDF_STREAMS_DIR) \
                           -I $(EDF_CONNECTABLE_DIR) \
                           -I $(ARDUINO_CORE_DIR) \
                           -I $(UTILS_MEMORY_DIR)

VPATH = $(subst ' ',':',$(EDF_ADAPT_SRC_DIR))
OBJ_DIR = $(ROOT_OBJ_DIR)/edf_adapter
EDF_SRC_LIST=$(foreach dir, $(EDF_ADAPT_SRC_DIR), $(wildcard $(dir)/*.cpp))
EDF_SCR_BLACK_LIST=
EDF_FILTERED_SRC_LIST=$(sort $(filter-out $(EDF_SCR_BLACK_LIST),$(EDF_SRC_LIST)))
EDF_FILTERED_OBJ_LIST=$(foreach src, $(EDF_FILTERED_SRC_LIST), $(addprefix $(OBJ_DIR)/,$(subst .cpp,.o,$(notdir $(src)))))
EDF_FILTERED_DEP_LIST=$(foreach obj, $(EDF_FILTERED_OBJ_LIST), $(subst .o,.d,$(obj)))

$(OBJ_DIR)/%.o: %.cpp
	$(CCPP) $(CPPFLAGS) $(EDF_ADAPT_INCLUDES) $< -o $@

build: env $(EDF_FILTERED_OBJ_LIST)

env:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(EXE_DIR)

clean:
	@rm -rf $(EDF_FILTERED_OBJ_LIST)
	@rm -rf $(EDF_FILTERED_DEP_LIST)
	@rm -rf $(EXE_DIR)

#endif of inputs checks
endif
endif
