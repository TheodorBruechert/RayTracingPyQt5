TARGET = render
BUILD_DIR = ./build
C_FILES = ./src/*.cpp
CFLAGS = -Wall -Wextra -pedantic -ansi -O3 
INCLUDE_FLAGS = -I./include


build:
	g++ $(C_FILES) $(CFLAGS) $(INCLUDE_FLAGS) -o $(BUILD_DIR)/$(TARGET) 