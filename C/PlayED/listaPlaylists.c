// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Trabalho 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaPlaylists.h"

#define TAM 101

typedef struct celula Celula;

struct listaPlaylists{
    Celula* primeira;
    Celula* ultima;
};

struct celula{
    char* nome;
    ListaMusicas* musicas;
    Celula* proxima;
};

ListaPlaylists* inicializaListaPlaylists(void){
    ListaPlaylists* playlists = (ListaPlaylists*) malloc (sizeof(ListaPlaylists));

    playlists->primeira = NULL;
    playlists->ultima = NULL;

    return playlists;
}

void inserirPlaylistNaLista(ListaPlaylists* lista, char* nome){
    Celula* nova = (Celula*) malloc (sizeof(Celula));
    nova->nome = strdup(nome);
    nova->musicas = inicializaListaMusicas();

    if(lista->primeira == NULL){
        lista->primeira = nova;
    }
    else{
        lista->ultima->proxima = nova;
    }

    lista->ultima = nova;
    nova->proxima = NULL;
}

static void removeUltimoEspacoNomeArtista(char* nomeArtista){
    if(nomeArtista[strlen(nomeArtista) - 1] == ' ')
        nomeArtista[strlen(nomeArtista) - 1] = '\0';
}

ListaMusicas* buscaPlaylist(ListaPlaylists* lista, char* nomePlaylist){
    Celula* p = lista->primeira;

    while(p != NULL && strcmp(p->nome, nomePlaylist) != 0){
        p = p->proxima;
    }

    if(p != NULL)
        return p->musicas;
    else
        return NULL;
}

void adicionarMusicasPlaylist(ListaPlaylists* lista, char* nomePlaylist){
    FILE* playlist = fopen(nomePlaylist, "r");

    if(playlist == NULL){
        printf("Nao foi possivel abrir o arquivo '%s'. Encerrando o programa...\n", nomePlaylist);
        exit(1);
    }

    char nomeArtista[TAM];
    char descricaoMusica[TAM];

    while(!feof(playlist)){
        fscanf(playlist, "%100[^-]", nomeArtista);
        fscanf(playlist, "- ");
        fscanf(playlist, "%100[^\n]", descricaoMusica);
        fscanf(playlist, "\n");

        removeUltimoEspacoNomeArtista(nomeArtista);

        Musica* musica = inicializaMusica(nomeArtista, descricaoMusica);

        ListaMusicas* p = buscaPlaylist(lista, nomePlaylist);

        inserirMusicaNaLista(p, musica);
    }

    fclose(playlist);
}

void liberarListaPlaylists(ListaPlaylists* lista){
    Celula* aux = lista->primeira;
    Celula* prox;

    while(aux != NULL){
        prox = aux->proxima;

        liberarListaMusicas(aux->musicas);
        free(aux->nome);
        free(aux);

        aux = prox;
    }

    free(lista);
}

void imprimirListaPlaylists(ListaPlaylists* lista){
    Celula* p = lista->primeira;

    while(p != NULL){
        printf("Playlist '%s':\n", p->nome);
        imprimirListaMusicas(p->musicas);
        printf("\n");
        p = p->proxima;
    }
}

int retornaQuantidadePlaylists(ListaPlaylists* listaPlaylists){
    Celula* p = listaPlaylists->primeira;
    int qtdPlaylists = 0;

    while(p != NULL){
        p = p->proxima;
        qtdPlaylists++;
    }

    return qtdPlaylists;
}

static void retirarPrimeiraPlaylistDaLista(ListaPlaylists* lista){
    Celula* aux = lista->primeira;

    if(aux == NULL) {
        return;
    }

    lista->primeira = aux->proxima;

    liberarListaMusicasSemLiberarMusicas(aux->musicas);
    free(aux->nome);
    free(aux);
}

void gerarPlaylistsPorArtistaPlaylists(Pessoa* pessoa){
    ListaPlaylists* listaPlaylists = retornaListaPlaylists(pessoa);
    Celula* p = listaPlaylists->primeira;
    int qtdPlaylists = retornaQuantidadePlaylists(listaPlaylists);
    int i = 0;

    while(p != NULL && i < qtdPlaylists){
        gerarPlaylistsPorArtistaMusicas(p->musicas, pessoa);
        p = p->proxima;
        i++;
        retirarPrimeiraPlaylistDaLista(listaPlaylists);
    }
}

void escreverNaPlayedRefatorada(Pessoa *pessoa, FILE* arquivo){
    ListaPlaylists* listaPlaylists = retornaListaPlaylists(pessoa);
    int qtdPlaylists = retornaQuantidadePlaylists(listaPlaylists);

    Celula* p = listaPlaylists->primeira;

    fprintf(arquivo, "%s;", retornaNomePessoa(pessoa));
    fprintf(arquivo, "%d;", qtdPlaylists);

    qtdPlaylists--;

    while(p != NULL){
        if(qtdPlaylists != 0)
            fprintf(arquivo, "%s.txt;", p->nome);
        else
            fprintf(arquivo, "%s.txt\n", p->nome);

        p = p->proxima;
        qtdPlaylists--;
    }
}

static char* gerarDiretorioArquivo(Pessoa* pessoa, char* nomePlaylist){
    char* diretorio = (char*) malloc (sizeof(char) * (strlen(retornaNomePessoa(pessoa)) + strlen(nomePlaylist) + 6));
    /*  +1 devido ao '\0'
     *  +1 devido ao / (referente ao diretorio)
     *  +4 devido ao ".txt"
     */

    strcpy(diretorio, retornaNomePessoa(pessoa));
    strcat(diretorio, "/");
    strcat(diretorio, nomePlaylist);
    strcat(diretorio, ".txt");

    return diretorio;
}

void gerarPlaylistsDentroDasPastas(Pessoa* pessoa){
    ListaPlaylists* listaPlaylists = retornaListaPlaylists(pessoa);

    FILE* arquivo;

    Celula* p = listaPlaylists->primeira;

    while(p != NULL){
        char* diretorioArquivo = gerarDiretorioArquivo(pessoa, p->nome);

        arquivo = fopen(diretorioArquivo, "w");

        if(!arquivo){
            printf("Nao foi possivel criar o arquivo '%s'!\n", diretorioArquivo);
            exit(1);
        }

        escreverNasPlaylistsDaPessoa(p->musicas, arquivo);

        fclose(arquivo);
        free(diretorioArquivo);

        p = p->proxima;
    }
}

int verificaSimilaridadesPlaylists(Pessoa* pessoa1, Pessoa* pessoa2){
    ListaPlaylists* listaPlaylists1 = retornaListaPlaylists(pessoa1);
    ListaPlaylists* listaPlaylists2 = retornaListaPlaylists(pessoa2);

    Celula* p1 = listaPlaylists1->primeira;

    int qtdSimilaridades = 0;

    while(p1 != NULL){

        Celula* p2 = listaPlaylists2->primeira;
        while(p2 != NULL){
            qtdSimilaridades += verificaSimilaridades(p1->musicas, p2->musicas);
            p2 = p2->proxima;
        }

        p1 = p1->proxima;
    }

    return qtdSimilaridades;
}