# TODO Fix makefile

# FLAGS
CC = gcc
CC_FLAGS = -Wall -g -Wextra -std=c11
CRYPTO_FLAG = -lcrypt

# DIRECTORIES
SRC_DIR = src
BIN_DIR = bin
BUILD_DIR = build

#FILES
TARGET = main

# RUN CMD
main: 
	#$(CC) $(CC_FLAGS) src/main.c src/split.c src/dictionary.c src/bruteForce.c -o bin/dictionary -lcrypt
	$(CC) $(CC_FLAGS) -o $(BIN_DIR)/main $(BUILD_DIR)/main.o $(BUILD_DIR)/split.o $(BUILD_DIR)/dictionary.o $(BUILD_DIR)/bruteForce.o $(CRYPTO_FLAG)

main.o: ./src/main.c
	$(CC) $(CC_FLAGS) -c $(BUILD_DIR)/main.o $(SRC_DIR)/main.c

split.o: ./src/split.c
	$(CC) $(CC_FLAGS) -c $(BUILD_DIR)/split.o $(SRC_DIR)/split.c

dictionary.o: ./src/dictionary.c
	$(CC) $(CC_FLAGS) -c $(BUILD_DIR)/dictionary.o $(SRC_DIR)/dictionary.c

bruteForce.o: ./src/bruteForce.c
	$(CC) $(CC_FLAGS) -c $(BUILD_DIR)/bruteForce.o $(SRC_DIR)/bruteForce.c

# GENERATE .o FILES
#main.o: ./$(SRC_DIR)/main.c
#	$(CC) $(CC_FLAGS) -c $(BUILD_DIR)/$(TARGET).o $(SRC_DIR)/$(TARGET).c

# UTIL CMDS
clean:
	rm ./$(BUILD_DIR)/*.o

remake: 
	clean $(TARGET)