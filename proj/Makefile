
CC = gcc
CFLAGS = -Wall -g

all: main test1 test2

main: src/main.c src/user_auth.c src/file_management.c src/input_parsing.c
	$(CC) $(CFLAGS) -o main src/main.c src/user_auth.c src/file_management.c src/input_parsing.c -lsqlite3

test1: tests/test1.c src/user_auth.c
	$(CC) $(CFLAGS) -o test1 tests/test1.c src/user_auth.c -lsqlite3

test2: tests/test2.c src/file_management.c
	$(CC) $(CFLAGS) -o test2 tests/test2.c src/file_management.c

clean:
	rm -f main test1 test2
