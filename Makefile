# FLAGS
CC = gcc
CC_FLAGS = -Wall -std=c11
CRYPTO_FLAG = -lcrypt

# DIRECTORIES
SRC_DIR = src
BIN_DIR = bin
BUILD_DIR = build

#FILES
TARGET = main

# RUN CMD
$(TARGET): main.o split.o dictionary.o bruteForce.o
	#$(CC) $(CC_FLAGS) src/main.c src/split.c src/dictionary.c src/bruteForce.c -o bin/dictionary -lcrypt
	$(CC) $(CC_FLAGS) -o $(BIN_DIR)/main $(BUILD_DIR)/main.o $(BUILD_DIR)/split.o $(BUILD_DIR)/dictionary.o $(BUILD_DIR)/bruteForce.o $(CRYPTO_FLAG)

# GENERATE .o FILES
main.o: ./src/main.c
	$(CC) $(CC_FLAGS) -c -o $(BUILD_DIR)/main.o $(SRC_DIR)/main.c

split.o: ./src/split.c
	$(CC) $(CC_FLAGS) -c -o $(BUILD_DIR)/split.o $(SRC_DIR)/split.c

dictionary.o: ./src/dictionary.c
	$(CC) $(CC_FLAGS) -c -o $(BUILD_DIR)/dictionary.o $(SRC_DIR)/dictionary.c

bruteForce.o: ./src/bruteForce.c
	$(CC) $(CC_FLAGS) -c -o $(BUILD_DIR)/bruteForce.o $(SRC_DIR)/bruteForce.c


# UTIL CMDS
clean:
	rm $(BUILD_DIR)/*.o $(BIN_DIR)/main

remake: cle	clean $(TARGET)