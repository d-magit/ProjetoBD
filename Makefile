TARGET_EXEC := exec
SRC_DIRS := ./src/
BUILD_DIR := ./build

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c')  
HSRCS := $(shell find $(SRC_DIRS) -name '*.h')  
#CCFLAGS

all:
	g++ $(SRCS) -o exec


clean:
	rm -r $(BUILD_DIR)
