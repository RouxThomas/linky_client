ROOT_DIR=$(CURDIR)/../../..

ifndef PLATFORM
$(error PLATFORM shall be defined !)
else

ifndef EXECUTABLE
 $(error EXECUTABLE shall be defined !)
else

include $(ROOT_DIR)/def_path.mk

UTESTS_INCLUDES = -I $(CURDIR) \
                  -I $(CURDIR)/stubs \
                  -I $(UT_FRAMEWORD_SRC_DIR) \
                  -I $(UTILS_DIR) \
                  -I $(EDF_REQUEST_DIR) \
                  -I $(EDF_REQUEST_TRANSMITTER_DIR) \
                  -I $(EDF_CONNECTABLE_DIR) \
                  -I $(EDF_STREAMS_DIR) \
                  -I $(EDF_DIR) \
                  -I $(EDF_READER_DIR) \
                  -I $(EDF_ENCODER_DIR) \
                  -I $(EDF_URI_DIR) \
                  -I $(EDF_STREAMS_DIR)

ifeq ($(PLATFORM),cross)
   include $(ROOT_DIR)/def_cross.mk
else
   include $(ROOT_DIR)/def_native.mk
endif

UTESTS_SRC_DIR = $(CURDIR) $(CURDIR)/stubs

VPATH = $(subst ' ',':',$(UTESTS_SRC_DIR))
OBJ_DIR = $(ROOT_OBJ_DIR)/tests
UTESTS_SRC_LIST=$(foreach dir, $(UTESTS_SRC_DIR), $(wildcard $(dir)/*.cpp))
UTESTS_OBJ_LIST=$(foreach src, $(UTESTS_SRC_LIST), $(addprefix $(OBJ_DIR)/,$(subst .cpp,.o,$(notdir $(src)))))
UTESTS_DEP_LIST=$(foreach obj, $(UTESTS_OBJ_LIST), $(subst .o,.d,$(obj)))

$(OBJ_DIR)/%.o: %.cpp
	$(CCPP) $(CPPFLAGS) $(UTESTS_INCLUDES) $< -o $@

build: env $(UTESTS_OBJ_LIST)

coverage:
	@make -C $(ROOT_DIR) -f coverage.mk compute_info_cov OBJ_DIR=$(OBJ_DIR) SRC_DIR=$(UTESTS_SRC_DIR) 
	
env:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(EXE_DIR)

clean:
	@rm -rf $(UTESTS_OBJ_LIST)
	@rm -rf $(UTESTS_DEP_LIST)

#endif of inputs checks
endif
endif