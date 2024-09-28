all: listaArvores.o arvore.o huffman.o
	gcc listaArvores.o arvore.o huffman.o main_Compactador.c -o Compacta
	gcc listaArvores.o arvore.o huffman.o main_Descompactador.c -o Descompacta
	rm -rf *.o

listaArvores.o: listaArvores.c
	gcc -c listaArvores.c

arvore.o: arvore.c
	gcc -c arvore.c

huffman.o: huffman.c
	gcc -c huffman.c

clean:
	rm -rf *.o

run:
	./playED