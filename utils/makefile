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

UTILS_SRC_DIR = $(CURDIR)
UTILS_INCLUDES = -I $(CURDIR)

VPATH = $(subst ' ',':',$(UTILS_SRC_DIR))
UTIL_OBJ_DIR = $(ROOT_OBJ_DIR)/utils
UTILS_SRC_LIST=$(foreach dir, $(UTILS_SRC_DIR), $(wildcard $(dir)/*.cpp))
UTILS_SCR_BLACK_LIST=
UTILS_FILTERED_SRC_LIST=$(sort $(filter-out $(UTILS_SCR_BLACK_LIST),$(UTILS_SRC_LIST)))
UTILS_FILTERED_OBJ_LIST=$(foreach src, $(UTILS_FILTERED_SRC_LIST), $(addprefix $(UTIL_OBJ_DIR)/,$(subst .cpp,.o,$(notdir $(src)))))
UTILS_FILTERED_DEP_LIST=$(foreach obj, $(UTILS_FILTERED_OBJ_LIST), $(subst .o,.d,$(obj)))

$(UTIL_OBJ_DIR)/%.o: %.cpp
	$(CCPP) $(CPPFLAGS) $(UTILS_INCLUDES) $< -o $@

build: env $(UTILS_FILTERED_OBJ_LIST) 

env:
	@mkdir -p $(UTIL_OBJ_DIR)

coverage:
	@make -C $(ROOT_DIR) -f coverage.mk compute_info_cov OBJ_DIR=$(UTIL_OBJ_DIR) SRC_DIR=$(UTILS_SRC_DIR) 

clean:
	@rm -rf $(UTILS_FILTERED_OBJ_LIST)
	@rm -rf $(UTILS_FILTERED_DEP_LIST)

#endif of inputs checks
endif
endif
