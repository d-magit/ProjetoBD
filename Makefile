TARGET_EXEC := exec
SRC_DIRS := ./src/

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c')  
#CCFLAGS

all:
	g++ $(SRCS) -o exec
