all: listaMusicas.o listaPessoas.o listaPlaylists.o musica.o pessoa.o
	gcc listaMusicas.o listaPessoas.o listaPlaylists.o musica.o pessoa.o main.c -o playED

listaMusicas.o: listaMusicas.h
	gcc -c listaMusicas.c

listaPessoas.o: listaPessoas.h
	gcc -c listaPessoas.c

listaPlaylists.o: listaPlaylists.h
	gcc -c listaPlaylists.c

musica.o: musica.h
	gcc -c musica.c

pessoa.o: pessoa.h
	gcc -c pessoa.c

clean:
	rm -rf *.o

run:
	./playED