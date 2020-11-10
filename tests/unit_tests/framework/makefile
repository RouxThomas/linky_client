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
   FW_INCLUDES = -I $(CURDIR) \
                 -I $(UTILS_DIR)
else
   include $(ROOT_DIR)/def_native.mk
   FW_INCLUDES = -I $(CURDIR) \
   				 -I $(UTILS_DIR)
endif

FW_SRC_DIR = $(CURDIR) 

VPATH = $(subst ' ',':',$(FW_SRC_DIR))
OBJ_DIR = $(ROOT_OBJ_DIR)/framework
FW_SRC_LIST=$(foreach dir, $(FW_SRC_DIR), $(wildcard $(dir)/*.cpp))
FW_OBJ_LIST=$(foreach src, $(FW_SRC_LIST), $(addprefix $(OBJ_DIR)/,$(subst .cpp,.o,$(notdir $(src)))))
FW_DEP_LIST=$(foreach obj, $(FW_OBJ_LIST), $(subst .o,.d,$(obj)))

$(OBJ_DIR)/%.o: %.cpp
	$(CCPP) $(CPPFLAGS) $(FW_INCLUDES) $< -o $@

build: env $(FW_OBJ_LIST)

coverage:
	@make -C $(ROOT_DIR) -f coverage.mk compute_info_cov OBJ_DIR=$(OBJ_DIR) SRC_DIR=$(FW_SRC_DIR) 

env:
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(FW_OBJ_LIST)
	@rm -rf $(FW_DEP_LIST)

#endif of inputs checks
endif
endif