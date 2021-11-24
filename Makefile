SRC=$(wildcard src/*.c)
OBJS=$(addprefix obj/, $(SRC:.c=.o))

CC=gcc
CFLAGS=-std=gnu17 -ggdb -Wall -Werror
LIBS=-lm -lSDL2

all:
	mkdir -p obj/src
	$(MAKE) stars

stars: $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $@

obj/src/%.o: src/%.c src/%.h
	$(CC) $(CFLAGS) $(LIBS) -c $< -o $@

clean:
	rm -rf obj
	rm stars

