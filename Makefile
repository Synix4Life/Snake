CC = g++
CFLAGS = -std=c++17 -O2

SRC_DIR = src
BUILD_DIR = build/obj
BIN_DIR = build/bin

SRC = $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJ = $(BUILD_DIR)/main.o $(BUILD_DIR)/Snake.o $(BUILD_DIR)/Field.o

all: $(BIN_DIR)/out run

$(BIN_DIR)/out: $(OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/out $(OBJ)

$(BUILD_DIR) $(BIN_DIR):
	mkdir -p $@

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build

run:
	clear
	@echo "Type 'make help' for Instructions"
	$(BIN_DIR)/out $(ARGS)

help:
	@echo "===================================="
	@echo "       Run Program Instructions     "
	@echo "===================================="
	@echo "Usage: make run ARGS='<arguments>'"
	@echo "Arguments:"
	@echo "  --speed <slow/fast> : Adjusts the game speed"
	@echo "  --dynamic           : Makes the game speed dynamic (independent from --speed)"
	@echo "===================================="
