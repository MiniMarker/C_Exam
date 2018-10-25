# FLAGS
CC = gcc
CC_FLAGS = -Wall -g -Wextra
CRYPTO_FLAG = -lcrypt

# DIRECTORIES
SRC_DIR = src
BIN_DIR = bin
BUILD_DIR = build

#FILES
TARGET = crypto

# RUN CMD
$(TARGET): crypto.o 
	$(CC) $(CC_FLAGS) -o $(BIN_DIR)/$(TARGET) $(BUILD_DIR)/$(TARGET).o $(CRYPTO_FLAG)

# GENERATE .o FILES
crypto.o: ./$(SRC_DIR)/crypto.c
	$(CC) $(CC_FLAGS) -c $(BUILD_DIR)/$(TARGET).o $(SRC_DIR)/$(TARGET).c

# UTIL CMDS
clean:
	rm ./$(BUILD_DIR)/*.o

remake: 
	clean $(TARGET)

############################################## TESTS

TST_LIBS = -lcheck -lm -lpthread -lrt 

demo.o : ./spike/demo.c
	$(CC) $(CC_FLAGS) -c build/demo.o spike/demo.c


