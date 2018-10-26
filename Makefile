# FLAGS
CC = gcc
CC_FLAGS = -Wall -g -Wextra
CRYPTO_FLAG = -lcrypt

# DIRECTORIES
SRC_DIR = src
BIN_DIR = bin
BUILD_DIR = build

#FILES
TARGET = main

# RUN CMD
$(TARGET): main.o 
	$(CC) $(CC_FLAGS) -o $(BIN_DIR)/$(TARGET) $(BUILD_DIR)/$(TARGET).o $(CRYPTO_FLAG)

# GENERATE .o FILES
main.o: ./$(SRC_DIR)/main.c
	$(CC) $(CC_FLAGS) -c $(BUILD_DIR)/$(TARGET).o $(SRC_DIR)/$(TARGET).c

# UTIL CMDS
clean:
	rm ./$(BUILD_DIR)/*.o

remake: 
	clean $(TARGET)