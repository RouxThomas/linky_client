ROOT_DIR=$(CURDIR)/..

ifndef PLATFORM
   $(error PLATFORM shall be defined !)
else

ifneq ($(PLATFORM),cross)
   $(error PLATFORM shall only be 'cross' !)
else

include $(ROOT_DIR)/def_cross.mk
include $(ROOT_DIR)/def_path.mk

SPI_INCLUDES = -I $(ARDUINO_CORE_DIR) \
               -I $(ARDUINO_CORE_VARIANT_STD_DIR) \
               -I $(SPI_LIB_DIR) \
               -I $(ETHERNET_LIB_DIR)
               

VPATH = $(subst ' ',':',$(SPI_LIB_DIR))

OBJ_DIR_CPP = $(ROOT_OBJ_DIR)/spi
SPI_SRC_CPP_LIST=$(foreach dir, $(SPI_LIB_DIR), $(wildcard $(dir)/*.cpp))
SPI_OBJ_CPP_LIST=$(foreach src, $(SPI_SRC_CPP_LIST), $(addprefix $(OBJ_DIR_CPP)/,$(subst .cpp,.o,$(notdir $(src)))))
SPI_DEP_CPP_LIST=$(foreach obj, $(SPI_OBJ_CPP_LIST), $(subst .o,.d,$(obj)))

$(OBJ_DIR_CPP)/%.o: %.cpp
	$(CCPP) $(CPPFLAGS) $(SPI_INCLUDES) $< -o $@
	
build: env $(SPI_OBJ_CPP_LIST)

env:
	@mkdir -p $(OBJ_DIR_CPP)

clean:
	@rm -rf $(SPI_OBJ_CPP_LIST)
	@rm -rf $(SPI_DEP_CPP_LIST)

#endif of inputs checks
endif
endif
