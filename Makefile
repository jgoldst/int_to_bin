CC=gcc
CFLAGS=-Wall -Wextra

int_to_bin: int_to_bin.o
	gcc -o int_to_bin int_to_bin.c

clean:
	$(RM) int_to_bin int_to_bin.o
