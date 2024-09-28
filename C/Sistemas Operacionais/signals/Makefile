# Trabalho 1
# Sistemas Operacionais
#
# -- Alunos --
# Daniel Siqueira de Oliveira
# Heitor Felix Lopes
# Lucas Gabriel de Oliveira Costa

# Name of the Program
NAME_PROGRAM=main

# .c files
SRC_C = $(wildcard *.c)

# .h files
SRC_H = $(wildcard *.h)

# Object files
OBJ=$(SRC_C:.c=.o)

# Compiler and linker
CC=gcc

# Flags for compiler
CC_FLAGS=-c    \
         -lm   \
         -Wall 

# Compilation and linking
all: $(NAME_PROGRAM)

$(NAME_PROGRAM): $(OBJ)
	@ $(CC) -o $@ $^ -lm
	@ echo "Compiled"
	
  
%.o: %.c %.h 
	@ $(CC) -c -o $@ $< $(CC_FLAGS) 


main.o: main.c $(SRC_H)
	@ $(CC) -o $@ $< $(CC_FLAGS)


clean:
	@ rm -rf *.o *~ $(NAME_PROGRAM)
