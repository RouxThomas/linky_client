ROOT_DIR=$(CURDIR)/../..

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

ENCODER_SRC_DIR = $(CURDIR)
ENCODER_INCLUDES = -I $(CURDIR) \
                   -I $(UTILS_DIR)

VPATH = $(subst ' ',':',$(ENCODER_SRC_DIR))
ENCODER_OBJ_DIR = $(ROOT_OBJ_DIR)/encoder
ENCODER_SRC_LIST=$(foreach dir, $(ENCODER_SRC_DIR), $(wildcard $(dir)/*.cpp))
ENCODER_SCR_BLACK_LIST=
ENCODER_FILTERED_SRC_LIST=$(sort $(filter-out $(ENCODER_SCR_BLACK_LIST),$(ENCODER_SRC_LIST)))
ENCODER_FILTERED_OBJ_LIST=$(foreach src, $(ENCODER_FILTERED_SRC_LIST), $(addprefix $(ENCODER_OBJ_DIR)/,$(subst .cpp,.o,$(notdir $(src)))))
ENCODER_FILTERED_DEP_LIST=$(foreach obj, $(ENCODER_FILTERED_OBJ_LIST), $(subst .o,.d,$(obj)))

$(ENCODER_OBJ_DIR)/%.o: %.cpp
	$(CCPP) $(CPPFLAGS) $(ENCODER_INCLUDES) $< -o $@

build: env $(ENCODER_FILTERED_OBJ_LIST)

coverage: env
	make -C $(ROOT_DIR) -f coverage.mk compute_info_cov OBJ_DIR=$(ENCODER_OBJ_DIR) SRC_DIR=$(ENCODER_SRC_DIR) 

env:
	mkdir -p $(ENCODER_OBJ_DIR)

clean:
	@rm -rf $(ENCODER_FILTERED_OBJ_LIST)
	@rm -rf $(ENCODER_FILTERED_DEP_LIST)

#endif of inputs checks
endif
endif
