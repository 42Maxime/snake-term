CC = cc
CFLAGS = -std=c99 -Wall -Wextra -Werror

all: snake

snake: snake.c move.c draw.c error.c terminal.c snake.h
	$(CC) $(CFLAGS) -D_POSIX_C_SOURCE=200809L snake.c move.c draw.c error.c terminal.c -o snake

clean:
	rm -f snake snake.exe

.PHONY: all clean
