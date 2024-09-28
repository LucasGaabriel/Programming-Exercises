// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Trabalho 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"

struct musica{
    char* artista;
    char* descricao;
};

Musica* inicializaMusica(char* artista, char* descricao){
    Musica* musica = (Musica*) malloc (sizeof(Musica));

    musica->artista = strdup(artista);
    musica->descricao = strdup(descricao);

    return musica;
}

char* retornaArtista(Musica* musica){
    return musica->artista;
}

char* retornaDescricao(Musica* musica){
    return musica->descricao;
}

void liberarMusica(Musica* musica){
    free(musica->artista);
    free(musica->descricao);
    free(musica);
}

void imprimirMusica(Musica* musica){
    printf("Musica -> Artista: %s, Descricao: %s\n", musica->artista, musica->descricao);
}