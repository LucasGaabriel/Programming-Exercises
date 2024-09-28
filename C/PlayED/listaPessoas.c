// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Trabalho 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "listaPessoas.h"

#define TAM 101

typedef struct celula Celula;

struct listaPessoas{
    Celula* primeira;
    Celula* ultima;
};

struct celula{
    Pessoa* pessoa;
    Celula* proxima;
};

ListaPessoas* inicializaListaPessoas(void){
    ListaPessoas* lista = (ListaPessoas*) malloc (sizeof(ListaPessoas));
    lista->primeira = NULL;
    lista->ultima = NULL;

    return lista;
}

void inserirPessoaNaLista(ListaPessoas* lista, Pessoa* pessoa){
    Celula* nova = (Celula*) malloc (sizeof(Celula));
    nova->pessoa = pessoa;

    if(lista->primeira == NULL){
        lista->primeira = nova;
    }
    else{
        lista->ultima->proxima = nova;
    }

    lista->ultima = nova;
    nova->proxima = NULL;
}

void liberarListaPessoas(ListaPessoas* lista){
    Celula* aux = lista->primeira;
    Celula* prox;

    while(aux != NULL){
        ListaPessoas* listaAmigos = retornaListaAmigos(aux->pessoa);
        ListaPlaylists* listaPlays = retornaListaPlaylists(aux->pessoa);

        Celula* aux2 = listaAmigos->primeira;

        while(aux2 != NULL){
            prox = aux2->proxima;
            free(aux2);
            aux2 = prox;
        }

        liberarListaPlaylists(listaPlays);

        free(listaAmigos);

        aux = aux->proxima;
    }

    aux = lista->primeira;

    while(aux != NULL){
        prox = aux->proxima;
        liberarPessoa(aux->pessoa);
        free(aux);
        aux = prox;
    }

    free(lista);
}

static Celula* buscaNomeNaLista(ListaPessoas* lista, char* nome){
    Celula* p = lista->primeira;

    while(p != NULL && strcmp(nome, retornaNomePessoa(p->pessoa)) != 0){
        p = p->proxima;
    }

    return p;
}

void definirRedeDeAmizades(ListaPessoas* lista){
    FILE* amizade = fopen("amizade.txt", "r");

    if(amizade == NULL){
        printf("Nao foi possivel abrir o arquivo 'amizade.txt'. Encerrando o programa...\n");
        exit(1);
    }

    Pessoa* pessoa;
    char nome1[TAM], nome2[TAM];
    char separador = ' ';

    while(!feof(amizade) && separador != '\n'){ //Define a Lista Inicial (Todas as Pessoas da PlayED)
       fscanf(amizade, "%100[^;\n]", nome1);
       fscanf(amizade, "%c", &separador);

       pessoa = inicializaPessoa(nome1);
       inserirPessoaNaLista(lista, pessoa);
    }

    Celula *p1, *p2;

    while(!feof(amizade)){ //Define a amizade entre as pessoas
        fscanf(amizade, "%100[^;\n]", nome1);
        fscanf(amizade, "%c", &separador);

        fscanf(amizade, "%100[^;\n]", nome2);
        fscanf(amizade, "%c", &separador);

        p1 = buscaNomeNaLista(lista, nome1);
        p2 = buscaNomeNaLista(lista, nome2);

        inserirPessoaNaListaAmigos(p1->pessoa, p2->pessoa);
        inserirPessoaNaListaAmigos(p2->pessoa, p1->pessoa);
    }

    fclose(amizade);
}

void carregarPlaylists(ListaPessoas* lista){
    FILE* arqPlaylists = fopen("playlists.txt", "r");

    if(arqPlaylists == NULL){
        printf("Nao foi possivel abrir o arquivo 'playlists.txt'. Encerrando o programa...\n");
        exit(1);
    }

    char nome[TAM], nomePlaylist[TAM], separador = ' ';
    int numPlaylists;

    while(!feof(arqPlaylists)){
        fscanf(arqPlaylists, "%100[^;\n]", nome);
        fscanf(arqPlaylists, ";%d;", &numPlaylists);

        Celula* p = buscaNomeNaLista(lista, nome);

        for(int i=0; i<numPlaylists; i++){
            fscanf(arqPlaylists, "%100[^;\n]", nomePlaylist);
            fscanf(arqPlaylists, "%c", &separador);
            inserirPlaylistNaLista(retornaListaPlaylists(p->pessoa), nomePlaylist);
            adicionarMusicasPlaylist(retornaListaPlaylists(p->pessoa), nomePlaylist);
        }
    }

    fclose(arqPlaylists);
}

void imprimirListaPessoas(ListaPessoas* lista){
    Celula* p = lista->primeira, *aux;

    while(p != NULL){
        imprimirPessoa(p->pessoa);

        printf("\nAmigos:\n");
        ListaPessoas* amigos = retornaListaAmigos(p->pessoa);
        aux = amigos->primeira;
        while(aux != NULL){
            imprimirPessoa(aux->pessoa);
            aux = aux->proxima;
        }

        printf("\nPlaylists:\n");
        imprimirListaPlaylists(retornaListaPlaylists(p->pessoa));
        printf("\n\n");
        p = p->proxima;
    }
}

void gerarPlaylistsPorArtista(ListaPessoas* lista){
    Celula* p = lista->primeira;

    while(p != NULL){
        gerarPlaylistsPorArtistaPlaylists(p->pessoa);
        p = p->proxima;
    }
}

void gerarPlayedRefatorada(ListaPessoas* lista){
    Celula* p = lista->primeira;

    FILE* arquivo = fopen("played-refatorada.txt", "w");

    if(!arquivo){
        printf("Nao foi possivel criar o arquivo 'played-refatorada.txt'.\n");
    }

    while(p != NULL){
        escreverNaPlayedRefatorada(p->pessoa, arquivo);
        p = p->proxima;
    }

    fclose(arquivo);
}

void gerarPastasPlaylists(ListaPessoas* lista){
    Celula* p = lista->primeira;
    while(p != NULL){
        mkdir(retornaNomePessoa(p->pessoa), S_IRWXU);
        gerarPlaylistsDentroDasPastas(p->pessoa);

        p = p->proxima;
    }
}

static int verificaSimilaridadeJaFeita(ListaPessoas* lista, Pessoa* pessoa1, Pessoa* pessoa2){
    Celula* p = lista->primeira;
    int i=1, j=1;

    while(p != NULL && strcmp(retornaNomePessoa(p->pessoa), retornaNomePessoa(pessoa1)) != 0){
        i++;
        p = p->proxima;
    }

    p = lista->primeira;

    while(p != NULL && strcmp(retornaNomePessoa(p->pessoa), retornaNomePessoa(pessoa2)) != 0){
        j++;
        p = p->proxima;
    }

    if(i <= j){
        return 1; //Similaridade nao foi feita
    }
    else{
        return 0; //Similaridade ja foi feita
    }
}

void gerarSimilaridades(ListaPessoas* lista){
    Celula* p = lista->primeira;
    int qtdSimilaridade = 0;
    FILE* arquivo = fopen("similaridades.txt", "w");

    if(!arquivo){
        printf("Nao foi possivel criar o arquivo 'similaridades.txt'!\n");
        exit(1);
    }

    while(p != NULL){

        ListaPessoas* listaAmigos = retornaListaAmigos(p->pessoa);

        Celula* aux = listaAmigos->primeira;
        while(aux != NULL){

            if(verificaSimilaridadeJaFeita(lista, p->pessoa, aux->pessoa)){
                qtdSimilaridade = verificaSimilaridadesPlaylists(p->pessoa, aux->pessoa);

                fprintf(arquivo, "%s;%s;%d\n", retornaNomePessoa(p->pessoa), retornaNomePessoa(aux->pessoa), qtdSimilaridade);
            }
            aux = aux->proxima;
        }

        p = p->proxima;
    }
}