ROOT_DIR=$(CURDIR)/../../..

ifndef PLATFORM
$(error PLATFORM shall be defined !)
else

ifndef EXECUTABLE
 $(error EXECUTABLE shall be defined !)
else

ifeq ($(PLATFORM),cross)

include $(ROOT_DIR)/def_path.mk
include $(ROOT_DIR)/def_cross.mk

UART_SRC_DIR = $(CURDIR)
UART_INCLUDES = -I $(CURDIR)

VPATH = $(subst ' ',':',$(UART_SRC_DIR))
OBJ_DIR = $(ROOT_OBJ_DIR)/uart
UART_SRC_LIST=$(foreach dir, $(UART_SRC_DIR), $(wildcard $(dir)/*.c))
UART_SCR_BLACK_LIST=
UART_FILTERED_SRC_LIST=$(sort $(filter-out $(UART_SCR_BLACK_LIST),$(UART_SRC_LIST)))
UART_FILTERED_OBJ_LIST=$(foreach src, $(UART_FILTERED_SRC_LIST), $(addprefix $(OBJ_DIR)/,$(subst .c,.o,$(notdir $(src)))))
UART_FILTERED_DEP_LIST=$(foreach obj, $(UART_FILTERED_OBJ_LIST), $(subst .o,.d,$(obj)))

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(UART_INCLUDES) $< -o $@

build: env $(UART_FILTERED_OBJ_LIST)

env:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(EXE_DIR)

clean:
	@rm -rf $(UART_FILTERED_OBJ_LIST)
	@rm -rf $(UART_FILTERED_DEP_LIST)

else

build: 
	@echo "build : nothing to do when PLATFORM="$(PLATFORM)

env:
	@echo "env : nothing to do when PLATFORM="$(PLATFORM)

clean:
	@echo "clean : nothing to do when PLATFORM="$(PLATFORM)

#endif of inputs checks
endif
endif
endif