TARGET = crypto
CFLAGS = -g -Wall -g -Wextra
CC = gcc
CRYPTOFLAG = -lcrypt

$(TARGET): crypto.o 
	$(CC) $(CFLAGS) -o bin/$(TARGET) build/$(TARGET).o $(CRYPTOFLAG)

crypto.o: ./src/crypto.c
	$(CC) $(CFLAGS) -c -o build/$(TARGET).o src/$(TARGET).c

clean:
	rm ./build/*.o

remake: clean $(TARGET)