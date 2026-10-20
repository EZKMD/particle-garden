CC = clang
CFLAGS = -std=c11 -Wall -Wextra -O2
RAYLIB = $(shell pkg-config --cflags --libs raylib)

particles: main.c
	$(CC) $(CFLAGS) main.c -o particles $(RAYLIB) -lm

run: particles
	./particles

clean:
	rm -f particles

.PHONY: run clean
