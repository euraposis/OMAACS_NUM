
C_COMPILER =clang

UNITY_ROOT=../../Unity/src
OMAACS_NUM_ROOT=../../../src

C_FLAGS=-std=c17
C_FLAGS += -Wall
C_FLAGS += -Wextra
C_FLAGS += -Wpointer-arith
C_FLAGS += -Wcast-align
C_FLAGS += -Wwrite-strings
C_FLAGS += -Wswitch-default
C_FLAGS += -Wunreachable-code
C_FLAGS += -Winit-self
C_FLAGS += -Wmissing-field-initializers
C_FLAGS += -Wno-unknown-pragmas
C_FLAGS += -Wstrict-prototypes
C_FLAGS += -Wundef
C_FLAGS += -Wold-style-definition

TARGET_BASE1=numerics_test
TARGET1=$(TARGET_BASE1).out
SRC_FILES1=$(UNITY_ROOT)/unity.c numerics_test.c $(OMAACS_NUM_ROOT)/numerics.c
INC_DIRS=-I. -I.. -I$(UNITY_ROOT)/src -I$(OMAACS_NUM_ROOT)
UNITY_INCLUDE_CONFIG = -D UNITY_INCLUDE_CONFIG_H
LIB_INCLUDES = -lm

BIN_DIR=../build

all: name_test clean build run

name_test:
	@echo "\nRunning $(TARGET_BASE1) Test\n"

clean:
	@rm -f $(BIN_DIR)$(TARGET1)

build:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SRC_FILES1) $(LIB_INCLUDES) $(UNITY_INCLUDE_CONFIG) -o $(BIN_DIR)/$(TARGET1)

run:
	@$(BIN_DIR)/$(TARGET1)