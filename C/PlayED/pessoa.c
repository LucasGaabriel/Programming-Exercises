// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Trabalho 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

struct pessoa{
    char* nome;
    ListaPessoas* amigos;
    ListaPlaylists* playlists;
};

Pessoa* inicializaPessoa(char* nome){
    Pessoa* pessoa = (Pessoa*) malloc (sizeof(Pessoa));

    pessoa->nome = strdup(nome);
    pessoa->amigos = inicializaListaPessoas();
    pessoa->playlists = inicializaListaPlaylists();

    return pessoa;
}

char* retornaNomePessoa(Pessoa* pessoa){
    return pessoa->nome;
}

ListaPessoas* retornaListaAmigos(Pessoa* pessoa){
    return pessoa->amigos;
}

ListaPlaylists* retornaListaPlaylists(Pessoa* pessoa){
    return pessoa->playlists;
}

void inserirPessoaNaListaAmigos(Pessoa* pessoaPrincipal, Pessoa* pessoaAdicionar){
    inserirPessoaNaLista(pessoaPrincipal->amigos, pessoaAdicionar);
}

void liberarPessoa(Pessoa* pessoa){
    free(pessoa->nome);
    free(pessoa);
}

void imprimirPessoa(Pessoa* pessoa){
    printf("%s\n", pessoa->nome);
}