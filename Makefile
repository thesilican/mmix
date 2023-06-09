SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
EXEC_NAME := mmix

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
ASMS := $(OBJS:.o=.s)
DEPS := $(OBJS:.o=.d)

CC := gcc
CFLAGS := -MMD -MP -Wall

.PHONY: clean test

build: $(BIN_DIR)/$(EXEC_NAME)

asm: $(ASMS)

clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*

run: $(BIN_DIR)/$(EXEC_NAME)
	$(BIN_DIR)/$(EXEC_NAME)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.s: $(SRC_DIR)/%.c $(OBJ_DIR)
	$(CC) -S -c $< -o $@

$(BIN_DIR)/$(EXEC_NAME): $(OBJS) $(BIN_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

-include $(DEPS)
