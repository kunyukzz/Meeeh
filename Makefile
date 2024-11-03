# Compiler
CC := gcc

# Compiler flags
CFLAGS := -Wall -std=c99  

# Linker flags
LDFLAGS := -s
LIBS := -lraylib -lGL -lpthread -lm

# Directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin/debug

# Source and object files
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Target executable
TARGET := $(BIN_DIR)/main

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CC) $(OBJ) -o $@ $(LDFLAGS) $(LIBS)
	
# Compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create directories if they don't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
	rm -rf $(OBJ_DIR)

# Phony targets
.PHONY: all clean
