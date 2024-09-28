#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "index.h"

#define TAM_DIR 500
#define SIZE 50

struct index {
    tTermo *RBT_termos;
    tTermo *tStop;
    vPagina *vPag;
};

Index *index_inicia() {
    Index *p = (Index *) malloc(sizeof(Index));
    p->RBT_termos = tTermo_inicia();
    p->tStop = tTermo_inicia();
    p->vPag = vPag_inicia();
    return p;
}

void cria_tTermo_stopWords(Index *i, char *dir) {
    char *stop = (char *) malloc(sizeof(char) * TAM_DIR);
    strcpy(stop, dir);
    strcat(stop, "/stopwords.txt");
    FILE *file = fopen(stop, "r");
    if (!file) { printf("ERRO: Não foi possível abrir %s\n", stop); exit(0); }

    size_t size = SIZE;
    char *line = (char *) malloc(sizeof(char) * size);
    char *word;
    while (getline(&line, &size, file) > 0) {
        word = strtok(line, " \n");
        while (word != NULL) {
            Termo *termo = termo_cria_converte(word);
            i->tStop = tTermo_insere(i->tStop, termo);
            word = strtok(NULL, " \n");
        }
    }
    free(stop);
    free(line);
    fclose(file);
}

Index *index_leitura(char *dir) {
    Index *index = index_inicia();
    cria_tTermo_stopWords(index, dir);

    char *ind = (char*) malloc(sizeof(char) * TAM_DIR);
    strcpy(ind, dir);
    strcat(ind, "/index.txt");

    char *pages = (char*) malloc(sizeof(char) * TAM_DIR);
    strcpy(pages, dir);
    strcat(pages, "/pages/");
    char *pagesPath = (char*) malloc(sizeof(char) * TAM_DIR);

    FILE *in = fopen(ind, "r");
    if (!in) { printf("ERRO: Não foi possível abrir %s\n", ind); exit(0); }
    FILE *in2;

    size_t size1 = SIZE;
    size_t size2 = SIZE;
    char *line1 = (char *) malloc(sizeof(char) * size1);
    char *line2 = (char *) malloc(sizeof(char) * size2);

    char *word;

    while (getline(&line1, &size1, in) > 0) {
        Pagina *pag = pag_cria(line1);
        vPag_insere(index->vPag, pag);
        strcpy(pagesPath, pages);
        strcat(pagesPath, line1);

        //Caso seja um \n ele substitui por \0
        if(pagesPath[strlen(pagesPath) -1] == '\n'){
            pagesPath[strlen(pagesPath) -1] = '\0';
        }
        else{ //Caso seja o EOF ele substitui o proximo pelo \0 para nao cortar o .txt
            pagesPath[strlen(pagesPath)] = '\0';
        }


        in2 = fopen(pagesPath, "r");
        if (!in2) { printf("ERRO: Não foi possível abrir %s\n", pagesPath); exit(0); }
        while (getline(&line2, &size2, in2) > 0) {
            word = strtok(line2, " \n");
            while (word != NULL) {
                Termo *termo = termo_cria_converte(word);
                // Verifica se o termo eh uma stopWord.
                if (tTermo_busca(index->tStop, termo) == NULL) {
                    termo_insere(termo, pag);
                    index->RBT_termos = tTermo_insere(index->RBT_termos, termo);
                } else {
                    termo_libera(termo);
                }
                word = strtok(NULL, " \n");
            }
        }
        fclose(in2);
    }

    free(line1);
    free(line2);
    fclose(in);
    free(ind);
    free(pages);
    free(pagesPath);
    return index;
}

vPagina *index_consulta(Index *ind, char *line) {
    int count = 0;
    vPagina *vPag;
    vPagina *vSaida;
    Termo *chave_busca;
    Termo *result;

    char *word = strtok(line, " \n");
    while (word != NULL) {
        // Cria termo com uma palavra da consulta.
        chave_busca = termo_cria_converte(word);
        // Busca termo na arvore de stopwords.
        result = tTermo_busca(ind->tStop, chave_busca);
        if (result == NULL) {    // Nao eh uma stopword.
            vPag = vPag_inicia();
            count++;
            // Busca termo na arvore de termos.
            result = tTermo_busca(ind->RBT_termos, chave_busca);
            if (result != NULL) {    // Eh um termo do indexador.
                // Faz copia por referencia de todas as paginas que contem o termo para
                // o vetor de paginas 'vPag'.
                termo_parse_vPag(result, vPag);
                // Soma 1 ao value de todas as paginas que contem o termo buscado.
                vPag_allPag_somaD(vPag, 1.0);
            }
            // Libera o vetor de pagina sem liberar as paginas.
            vPag_libera_mantemPags(vPag);
        }
        termo_libera(chave_busca);
        word = strtok(NULL, " \n");
    }
    // Compara o valor de todas as paginas, se for igual ao N de termos da
    // consulta, entao esta pagina contem todos os termos buscados.
    vSaida = vPag_comparaValue(ind->vPag, count);
    vPag_resetaValue(ind->vPag);
    return vSaida;
}

vPagina *index_vPag(Index *index) {
    return index->vPag;
}

void index_imprime(Index *p, FILE *out) {
    if (!p) return;
    fprintf(out,"STOPWORDS:\n");
    tTermo_imprime(p->tStop, out);
    fprintf(out, "\n");
    fprintf(out,"\nTERMOS:\n");
    tTermo_imprime(p->RBT_termos, out);
    fprintf(out, "\n");
    fprintf(out,"\nVETOR de PAGINAS:\n");
    vPag_imprime(p->vPag, out);
    fprintf(out,"\n");
}

void index_libera(Index *p) {
    tTermo_libera(p->RBT_termos);
    tTermo_libera(p->tStop);
    vPag_libera(p->vPag);
    free(p);
}