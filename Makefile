CC = gcc
CFLAGS = -Wall -Wextra -O2 -Wpedantic -std=c99

all:
	$(CC) $(CFLAGS) main.c -o caesarcipher

clean:
	rm -f caesarcipher

.PHONY: all clean
