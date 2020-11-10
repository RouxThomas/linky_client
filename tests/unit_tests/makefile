export ROOT_DIR=$(CURDIR)/../..

ifndef PLATFORM
$(error PLATFORM shall be defined !)
else

ifdef EXECUTABLE
 $(error EXECUTABLE shall NOT be defined !)
else

ifndef COVERAGE
   EXECUTABLE=unit_tests
else
   EXECUTABLE=unit_tests_coverage
endif

include $(ROOT_DIR)/def_path.mk

#-------------------------------------- CROSS ---------------
ifeq ($(PLATFORM),cross)
include $(ROOT_DIR)/def_cross.mk
build_avr_core:
	@make -C $(ARDUINO_CORE_AVR_MAKER) -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)

download:
	@make -C $(ROOT_DIR) -f download.mk telech_ram PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)

build: env build_avr_core build_utils build_edf build_ut_framework_lib build_ut_tests build_uart build_main hex size

clean:
	@make -C $(ARDUINO_CORE_AVR_MAKER)      -f makefile clean PLATFORM=cross       EXECUTABLE=$(EXECUTABLE)
	@make -C $(UART_DIR)                    -f makefile clean PLATFORM=cross       EXECUTABLE=$(EXECUTABLE)
	@make -C $(EDF_ENCODER_DIR)             -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(EDF_URI_DIR)                 -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(EDF_READER_IMPL_DIR)         -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(EDF_REQUEST_TRANSMITTER_DIR) -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(EDF_DIR)                     -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(UTILS_DIR)                   -f makefile clean PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(UT_FRAMEWORD_SRC_DIR)        -f makefile clean PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(UT_TEST_DIR)                 -f makefile clean PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(UT_MAIN_DIR)                 -f makefile clean PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@rm -rf $(EXE_DIR)/$(EXE)
	@rm -rf $(EXE_DIR)/$(HEX)
	@rm -rf $(ROOT_OBJ_DIR)

else
#-------------------------------------- NATIVE ---------------
include $(ROOT_DIR)/def_native.mk

build: env build_avr_core build_utils build_edf build_ut_framework_lib build_ut_tests build_uart build_main hex

run:
	$(EXE_DIR)/$(EXE)

build_avr_core:
	@echo "no need to build build_avr_core in " $(PLATFORM)

download:
	$(error download target only in PLATFORM=cross)

ifdef COVERAGE

build: env build_avr_core build_utils build_edf build_ut_framework_lib build_ut_tests build_uart build_main compute_coverage concat_coverage generate_html

generate_html:
	$(GENHTML) $(GLOBAL_COVERAGE_INFO_FILE) --config-file=$(COVERAGE_CONFIG_FILE) --output-directory=$(COVERAGE_RESULT_DIR);

concat_coverage:
	$(LCOV) $(addprefix  -a ,$(shell find $(ROOT_OBJ_DIR) -name "*.info" | grep -v "framework" )) -o $(GLOBAL_COVERAGE_INFO_FILE)

compute_coverage: hex run
	@make -C $(UT_FRAMEWORD_SRC_DIR)        -f makefile coverage PLATFORM=native EXECUTABLE=$(EXECUTABLE)
	@make -C $(UTILS_DIR)                   -f makefile coverage PLATFORM=native EXECUTABLE=$(EXECUTABLE) 
	@make -C $(UT_TEST_DIR)                 -f makefile coverage PLATFORM=native EXECUTABLE=$(EXECUTABLE)
	@make -C $(UT_MAIN_DIR)                 -f makefile coverage PLATFORM=native EXECUTABLE=$(EXECUTABLE)
	@make -C $(EDF_ENCODER_DIR)             -f makefile coverage PLATFORM=native EXECUTABLE=$(EXECUTABLE)
	@make -C $(EDF_URI_DIR)                 -f makefile coverage PLATFORM=native EXECUTABLE=$(EXECUTABLE)
	@make -C $(EDF_READER_IMPL_DIR)         -f makefile coverage PLATFORM=native EXECUTABLE=$(EXECUTABLE)
	@make -C $(EDF_REQUEST_TRANSMITTER_DIR) -f makefile coverage PLATFORM=native EXECUTABLE=$(EXECUTABLE)
	@make -C $(EDF_DIR)                     -f makefile coverage PLATFORM=native EXECUTABLE=$(EXECUTABLE)

env:
	@mkdir -p $(EXE_DIR)
	@mkdir -p $(ROOT_OBJ_DIR)
	@mkdir -p $(COVERAGE_RESULT_DIR)

clean:
	@make -C $(EDF_ENCODER_DIR)             -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(EDF_URI_DIR)                 -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(EDF_READER_IMPL_DIR)         -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(EDF_REQUEST_TRANSMITTER_DIR) -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(EDF_DIR)                     -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(UTILS_DIR)                   -f makefile clean PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(UT_FRAMEWORD_SRC_DIR)        -f makefile clean PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(UT_TEST_DIR)                 -f makefile clean PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(UT_MAIN_DIR)                 -f makefile clean PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@rm -rf $(EXE_DIR)/$(EXE)
	@rm -rf $(EXE_DIR)/$(HEX)
	@rm -rf $(ROOT_OBJ_DIR)
	@rm -rf $(GLOBAL_COVERAGE_INFO_FILE)

else

build: env build_avr_core build_utils build_edf build_ut_framework_lib build_ut_tests build_uart build_main hex 

env:
	@mkdir -p $(EXE_DIR)
	@mkdir -p $(ROOT_OBJ_DIR)

clean:
	@make -C $(EDF_ENCODER_DIR)             -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(EDF_URI_DIR)                 -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(EDF_READER_IMPL_DIR)         -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(EDF_REQUEST_TRANSMITTER_DIR) -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(EDF_DIR)                     -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(UTILS_DIR)                   -f makefile clean PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(UT_FRAMEWORD_SRC_DIR)        -f makefile clean PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(UT_TEST_DIR)                 -f makefile clean PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(UT_MAIN_DIR)                 -f makefile clean PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@rm -rf $(EXE_DIR)/$(EXE)
	@rm -rf $(EXE_DIR)/$(HEX)
	@rm -rf $(ROOT_OBJ_DIR)
	
endif

endif

size:
	$(SIZE) $(EXE_DIR)/$(HEX)

build_utils:
	@make -C $(UTILS_DIR) -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)

build_edf:
	@make -C $(EDF_ENCODER_DIR)             -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(EDF_URI_DIR)                 -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(EDF_READER_IMPL_DIR)         -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(EDF_REQUEST_TRANSMITTER_DIR) -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	@make -C $(EDF_DIR)                     -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)
	
build_ut_framework_lib:
	@make -C $(UT_FRAMEWORD_SRC_DIR) -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)

build_ut_tests:
	@make -C $(UT_TEST_DIR) -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)

build_uart:
	@make -C $(UART_DIR) -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)

build_main:
	@make -C $(UT_MAIN_DIR) -f makefile build PLATFORM=$(PLATFORM) EXECUTABLE=$(EXECUTABLE)

hex:
	@make -C $(ROOT_DIR) -f download.mk hex EXECUTABLE=$(EXECUTABLE)

#endif of inputs checks
endif
endif