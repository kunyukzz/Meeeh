.PHONY: all clean

CC := gcc
CFLAGS := -g -Wall -Wextra -std=c99

# LDFLAGS := -s - # enable this flags if you don't need to debug using gdb debugging
#LIBS := -lraylib -lGL -lpthread -lm

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin/debug
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
TARGET := $(BIN_DIR)/meeeh.out

# Detect the OS and set platform-specific flags and libraries
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux) # Linux
	LIBS := -lraylib -lGL -lpthread -lm
	#LDFLAGS := -s # Strip binary to reduce size, enable for non-debug builds
else ifeq ($(UNAME_S), Darwin) # macOS
	LIBS := -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
	LDFLAGS := 
	TARGET := $(BIN_DIR)/meeeh
else ifeq ($(OS), Windows_NT) # Windows
	LIBS := -lraylib -lopengl32 -lgdi32 -lwinmm
	CFLAGS += -DPLATFORM_DESKTOP
	TARGET := $(BIN_DIR)/meeeh.exe
endif

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

