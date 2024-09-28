// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Trabalho 1

#include <stdlib.h>
#include <string.h>
#include "listaMusicas.h"

typedef struct celula Celula;

struct listaMusicas{
    Celula* primeira;
    Celula* ultima;
};

struct celula{
    Musica* musica;
    Celula* proxima;
};

ListaMusicas* inicializaListaMusicas(void){
    ListaMusicas* musicas = (ListaMusicas*) malloc (sizeof(ListaMusicas));
    musicas->primeira = NULL;
    musicas->ultima = NULL;

    return musicas;
}

void inserirMusicaNaLista(ListaMusicas* lista, Musica* musica){
    Celula* nova = (Celula*) malloc (sizeof(Celula));
    nova->musica = musica;

    if(lista->primeira == NULL){
        lista->primeira = nova;
    }
    else{
        lista->ultima->proxima = nova;
    }

    lista->ultima = nova;
    nova->proxima = NULL;
}

void liberarListaMusicas(ListaMusicas* lista){
    Celula* aux = lista->primeira;
    Celula* prox;

    while(aux != NULL){
        prox = aux->proxima;

        liberarMusica(aux->musica);
        free(aux);

        aux = prox;
    }

    free(lista);
}

void liberarListaMusicasSemLiberarMusicas(ListaMusicas* lista){
    Celula* p = lista->primeira;
    Celula* prox;

    while(p != NULL){
        prox = p->proxima;
        free(p);
        p = prox;
    }

    free(lista);
}

void imprimirListaMusicas(ListaMusicas* lista){
    Celula* p = lista->primeira;

    while(p != NULL){
        imprimirMusica(p->musica);
        p = p->proxima;
    }
}

void gerarPlaylistsPorArtistaMusicas(ListaMusicas* listaMusicas, Pessoa* pessoa){
    Celula* p = listaMusicas->primeira;
    ListaPlaylists* listaPlaylists = retornaListaPlaylists(pessoa);

    while(p != NULL){

        ListaMusicas* buscaMusicas = buscaPlaylist(listaPlaylists, retornaArtista(p->musica));

        if(buscaMusicas){
            inserirMusicaNaLista(buscaMusicas, p->musica);
        }
        else{
            inserirPlaylistNaLista(listaPlaylists, retornaArtista(p->musica));
            inserirMusicaNaLista( buscaPlaylist(listaPlaylists, retornaArtista(p->musica)), p->musica);
        }

        p = p->proxima;
    }
}

void escreverNasPlaylistsDaPessoa(ListaMusicas* listaMusicas, FILE* arquivo){
    Celula* p = listaMusicas->primeira;

    while(p != NULL){
        fprintf(arquivo, "%s - ", retornaArtista(p->musica));
        fprintf(arquivo, "%s\n", retornaDescricao(p->musica));
        p = p->proxima;
    }
}

int verificaSimilaridades(ListaMusicas* lista1, ListaMusicas* lista2){
    Celula* p1 = lista1->primeira;

    int similaridades = 0;

    while(p1 != NULL){

        Celula* p2 = lista2->primeira;
        while(p2 != NULL){

            if(strcmp(retornaArtista(p1->musica), retornaArtista(p2->musica)) == 0){
                if(strcmp(retornaDescricao(p1->musica), retornaDescricao(p2->musica)) == 0){
                    similaridades++;
                }
            }

            p2 = p2->proxima;
        }

        p1 = p1->proxima;
    }

    return similaridades;
}