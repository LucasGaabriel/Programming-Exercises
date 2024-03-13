# flags usadas no g++
# O -Wall ativa todos os warnings, mesmo aqueles que por padrao estao
# desligados por serem questoes menores.
FLAGS = -Wall

# Lista todos os arquivos com extensao .cpp que existem dentro da
# pasta horario
SRC = $(wildcard Horario/*cpp)

# Substitui a extensao dos arquivos .cpp por .o nos arquivos existentes
# em SRC (ver linha acima)
OBJ = $(SRC:.cpp=.o)

# Target principal do makefile. Invoca os targets programa-v1 programa-v2 programa-v3
# listados abaixo.
all: programa

# Para todo arquivo .o, define que ele depende de um .cpp com mesmo nome.
# Sempre que o .cpp for modificado ou quando o .o não existir, sera' executado
# o comando abaixo para compilar o arquivo .cpp e produzir o arquivo .o.
%.o: %.cpp
	g++ $(FLAGS) -c $*.cpp -o $*.o

# A libhorario.a depende de todos os arquivos objeto existentes em OBJ.
# Sempre que os arquivos .o mudarem, e.g., como resultado da regra acima,
# o comando abaixo eh usado para produzir a biblioteca.
libhorario.a: $(OBJ)
	ar rsc libhorario.a $(OBJ)

# O programa depende da biblioteca e do arquivo .cpp . Sempre que um dos dois
# for modificado, sera' executado o comando abaixo do target para compilar o
# arquivo .cpp e linkar o executável.
programa: libhorario.a main.cpp
	g++ $(FLAGS) -o main main.cpp -L . -lhorario

# Remove os arquivos produzidos pelo processo de compilação e linkagem.
clean:
	rm -rf main libhorario.a *.o Horario/*.o