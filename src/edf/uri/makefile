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

EDF_ENCODER_SRC_DIR = $(CURDIR)
EDF_ENCODER_INCLUDES = -I $(CURDIR) \
                       -I $(EDF_STREAMS_DIR) \
                       -I $(EDF_ENCODER_DIR)

VPATH = $(subst ' ',':',$(EDF_ENCODER_SRC_DIR))
EDF_ENCODER_OBJ_DIR = $(ROOT_OBJ_DIR)/uri
EDF_ENCODER_SRC_LIST=$(foreach dir, $(EDF_ENCODER_SRC_DIR), $(wildcard $(dir)/*.cpp))
EDF_ENCODER_SCR_BLACK_LIST=
EDF_ENCODER_FILTERED_SRC_LIST=$(sort $(filter-out $(EDF_ENCODER_SCR_BLACK_LIST),$(EDF_ENCODER_SRC_LIST)))
EDF_ENCODER_FILTERED_OBJ_LIST=$(foreach src, $(EDF_ENCODER_FILTERED_SRC_LIST), $(addprefix $(EDF_ENCODER_OBJ_DIR)/,$(subst .cpp,.o,$(notdir $(src)))))
EDF_ENCODER_FILTERED_DEP_LIST=$(foreach obj, $(EDF_ENCODER_FILTERED_OBJ_LIST), $(subst .o,.d,$(obj)))

$(EDF_ENCODER_OBJ_DIR)/%.o: %.cpp
	$(CCPP) $(CPPFLAGS) $(EDF_ENCODER_INCLUDES) $< -o $@

build: env $(EDF_ENCODER_FILTERED_OBJ_LIST)

coverage: env
	make -C $(ROOT_DIR) -f coverage.mk compute_info_cov OBJ_DIR=$(EDF_ENCODER_OBJ_DIR) SRC_DIR=$(EDF_ENCODER_SRC_DIR) 

env:
	mkdir -p $(EDF_ENCODER_OBJ_DIR)

clean:
	@rm -rf $(EDF_ENCODER_FILTERED_OBJ_LIST)
	@rm -rf $(EDF_ENCODER_FILTERED_DEP_LIST)

#endif of inputs checks
endif
endif
