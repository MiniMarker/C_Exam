# FLAGS
CFLAGS = -g -Wall -g -Wextra
CC = gcc
CRYPTOFLAG = -lcrypt

# DIRECTORIES
SRC_DIR = src
BIN_DIR = bin
BUILD_DIR = build

#FILES
TARGET = crypto

# RUN CMD
$(TARGET): $(TARGET).o 
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$(TARGET) $(BUILD_DIR)/$(TARGET).o $(CRYPTOFLAG)

# GENERATE .o FILES
crypto.o: ./$(SRC_DIR)/$(TARGET).c
	$(CC) $(CFLAGS) -c -o $(BUILD_DIR)/$(TARGET).o $(SRC_DIR)/$(TARGET).c

# UTIL CMDS
clean:
	rm ./$(BUILD_DIR)/*.o
