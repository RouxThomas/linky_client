ROOT_DIR=$(CURDIR)/../../..

ifndef PLATFORM
$(error PLATFORM shall be defined !)
else

ifndef EXECUTABLE
 $(error EXECUTABLE shall be defined !)
else

include $(ROOT_DIR)/def_path.mk

OBJ_DIR = $(ROOT_OBJ_DIR)/main

ifeq ($(PLATFORM),cross)
   include $(ROOT_DIR)/def_cross.mk
   
   UTMAIN_SRC_DIR = $(CURDIR)/cross
   
   UTMAIN_INCLUDES = -I $(CURDIR) \
                     -I $(UT_TEST_DIR) \
                     -I $(UART_DIR)

else
   include $(ROOT_DIR)/def_native.mk
   
   UTMAIN_SRC_DIR = $(CURDIR)/native

   UTMAIN_INCLUDES = -I $(CURDIR) \
                     -I $(UT_TEST_DIR)

coverage:
	@make -C $(ROOT_DIR) -f coverage.mk compute_info_cov OBJ_DIR=$(OBJ_DIR) SRC_DIR=$(UTMAIN_SRC_DIR) 

endif

VPATH = $(subst ' ',':',$(UTMAIN_SRC_DIR))
UTMAIN_SRC_LIST=$(foreach dir, $(UTMAIN_SRC_DIR), $(wildcard $(dir)/*.c))
UTMAIN_SCR_BLACK_LIST=
UTMAIN_FILTERED_SRC_LIST=$(sort $(filter-out $(UTMAIN_SCR_BLACK_LIST),$(UTMAIN_SRC_LIST)))
UTMAIN_FILTERED_OBJ_LIST=$(foreach src, $(UTMAIN_FILTERED_SRC_LIST), $(addprefix $(OBJ_DIR)/,$(subst .c,.o,$(notdir $(src)))))
UTMAIN_FILTERED_DEP_LIST=$(foreach obj, $(UTMAIN_FILTERED_OBJ_LIST), $(subst .o,.d,$(obj)))

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(UTMAIN_INCLUDES) $< -o $@

build: env $(UTMAIN_FILTERED_OBJ_LIST)

env:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(EXE_DIR)

clean:
	@rm -rf $(UTMAIN_FILTERED_OBJ_LIST)
	@rm -rf $(UTMAIN_FILTERED_DEP_LIST)

#endif of inputs checks
endif
endif