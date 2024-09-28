SRC_C = $(wildcard src/*.c)
SRC_H = $(wildcard src/*.h)

SRC_C-indexador = $(wildcard src-indexador/*.c)
SRC_C-pagerank = $(wildcard src-pagerank/*.c)


SRC_H-indexador = $(wildcard src-indexador/*.c)
SRC_H-pagerank = $(wildcard src-pagerank/*.c)

OBJ=$(SRC_C:.c=.o)

OBJ-indexador=$(SRC_C-indexador:.c=.o)
OBJ-pagerank=$(SRC_C-pagerank:.c=.o)

CC = gcc

CFLAGS=-c -lm  -Wall 

VALGRIND_FLAGS = VALGRIND_FLAGS=-s \
               --leak-check=full \
               --show-leak-kinds=all \
			   --show-reachable=yes \
               --track-origins=yes \
               --verbose

NAME_PROGRAM=trab3

all:$(NAME_PROGRAM)

$(NAME_PROGRAM): $(OBJ)
	$(CC) -o $@ $^ -lm
	mv src/*.o bin/

%.o: %.c %.h 
	$(CC) -c -o $@ $< $(CFLAGS)

main.o: main.c $(SRC_H)
	$(CC) -o $@ $< $(CFLAGS)

run:
	@./${NAME_PROGRAM} input/ex-0

run-%:
	@./${NAME_PROGRAM} input/$*

valgrind: all
	@ clear
	@ valgrind ./${NAME_PROGRAM} input/ex-0 --leak-check=full

clean:
	rm -rf *.o bin/*.o *~ $(NAME_PROGRAM)