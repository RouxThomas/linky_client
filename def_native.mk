
ifndef EXECUTABLE
 $(error EXECUTABLE shall be defined !)
else

include $(ROOT_DIR)/def_path.mk
include $(ROOT_DIR)/def_common.mk

CC       = gcc
CCPP     = g++
AR       = ar

ifdef COVERAGE
   CFLAGS_FOR_COV = -fprofile-arcs -ftest-coverage
   LDFLAGS_FOR_COV = -coverage   
   LCOV=lcov
   GENHTML=genhtml
   COVERAGE_RESULT_DIR=$(LOCAL_BUILD_DIR)/coverage_result
   COVERAGE_CONFIG_FILE = $(LCOV_DIR)/config.txt
   GLOBAL_COVERAGE_INFO_FILE=$(COVERAGE_RESULT_DIR)/global_coverage.info  
endif

CFLAGS   = $(C_COMMON_FLAGS) \
          -ffunction-sections \
          -fdata-sections \
          -DDEBUG \
          $(CFLAGS_FOR_COV)

CPPFLAGS =  $(CFLAGS) \
            -std=c++11 \
            -Werror \
            $(CFLAGS_FOR_COV)

LDFLAGS = -g $(LDFLAGS_FOR_COV)

EXE = $(EXECUTABLE)


#endif of inputs checks
endif
