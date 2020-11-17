ROOT_DIR=$(CURDIR)/../..

ifndef PLATFORM
   $(error PLATFORM shall be defined !)
else

ifneq ($(PLATFORM),cross)
   $(error PLATFORM shall only be 'cross' !)
else

include $(ROOT_DIR)/def_cross.mk
include $(ROOT_DIR)/def_path.mk

ETHERNET_INCLUDES = -I $(ARDUINO_CORE_DIR) \
                    -I $(ARDUINO_CORE_VARIANT_STD_DIR) \
                    -I $(SPI_LIB_DIR) \
                    -I $(ETHERNET_LIB_DIR)

VPATH = $(subst ' ',':',$(ETHERNET_LIB_DIR) $(ETHERNET_LIB_UTIL_DIR))

OBJ_DIR_CPP = $(ROOT_OBJ_DIR)/ethernet
ETHERNET_SRC_CPP_LIST=$(foreach dir, $(ETHERNET_LIB_DIR) $(ETHERNET_LIB_UTIL_DIR), $(wildcard $(dir)/*.cpp))
ETHERNET_OBJ_CPP_LIST=$(foreach src, $(ETHERNET_SRC_CPP_LIST), $(addprefix $(OBJ_DIR_CPP)/,$(subst .cpp,.o,$(notdir $(src)))))
ETHERNET_DEP_CPP_LIST=$(foreach obj, $(ETHERNET_OBJ_CPP_LIST), $(subst .o,.d,$(obj)))

$(OBJ_DIR_CPP)/%.o: %.cpp
	$(CCPP) $(CPPFLAGS) $(ETHERNET_INCLUDES) $< -o $@
	
build: env $(ETHERNET_OBJ_CPP_LIST)

env:
	@mkdir -p $(OBJ_DIR_CPP)

clean:
	@rm -rf $(ETHERNET_OBJ_CPP_LIST)
	@rm -rf $(ETHERNET_DEP_CPP_LIST)

#endif of inputs checks
endif
endif
