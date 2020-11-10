ROOT_DIR=$(CURDIR)/../..

ifneq ($(PLATFORM),cross)
 $(error PLATFORM shall be cross !)   
else

ifndef EXECUTABLE
 $(error EXECUTABLE shall be defined !)
else 
 
include $(ROOT_DIR)/def_path.mk
include $(ROOT_DIR)/def_cross.mk

UTILS_MEMORY_SRC_DIR = $(CURDIR)   
UTILS_MEMORY_INCLUDES = -I $(CURDIR) \
			            -I $(ARDUINO_CORE_DIR) \
			            -I $(ARDUINO_CORE_VARIANT_STD_DIR)

VPATH = $(subst ' ',':',$(UTILS_MEMORY_SRC_DIR))
OBJ_DIR = $(ROOT_OBJ_DIR)/utils_memory
UTILS_MEM_SRC_LIST=$(foreach dir, $(UTILS_MEMORY_SRC_DIR), $(wildcard $(dir)/*.cpp))
UTILS_MEM_SRC_BLACK_LIST=
UTILS_MEM_FILTERED_SRC_LIST=$(sort $(filter-out $(UTILS_MEM_SRC_BLACK_LIST),$(UTILS_MEM_SRC_LIST)))
UTILS_MEM_FILTERED_OBJ_LIST=$(foreach src, $(UTILS_MEM_FILTERED_SRC_LIST), $(addprefix $(OBJ_DIR)/,$(subst .cpp,.o,$(notdir $(src)))))
UTILS_MEM_FILTERED_DEP_LIST=$(foreach obj, $(UTILS_MEM_FILTERED_OBJ_LIST), $(subst .o,.d,$(obj)))

$(OBJ_DIR)/%.o: %.cpp
	$(CCPP) $(CPPFLAGS) $(UTILS_MEMORY_INCLUDES) $< -o $@

build: env $(UTILS_MEM_FILTERED_OBJ_LIST)

env:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(EXE_DIR)

clean:
	@rm -rf $(UTILS_MEM_FILTERED_OBJ_LIST)
	@rm -rf $(UTILS_MEM_FILTERED_DEP_LIST)
	@rm -rf $(EXE_DIR)

#endif of inputs checks
endif
endif
