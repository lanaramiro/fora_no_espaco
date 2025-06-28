CC = gcc
CFLAGS = -Wall -pthread
SRC = src/
INC = include/

all:
	$(CC) $(SRC)*.c -I$(INC) -o fora_no_espaco $(CFLAGS) -lncurses

clean:
	rm -f fora_no_espaco