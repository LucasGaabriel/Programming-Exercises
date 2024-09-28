#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "graph.h"
#include "vPagina.h"

#define TAM_MAX_LEITURA 256
#define MAX_VERTICES_INICIAL 50
#define MAX_ADJACENCIAS_INICIAL 20

// Definicao do Vertice - Cada vertice possui um nome, quantidade de nós que saem dele e
// um vetor de adjacências (inteiros que correspondem ao índice do nó no grafo)
struct vertice {
    char *source;
    int qtdAdjacencias;
    int *adjacencias;
    int len;
    int max;
};

// Grafo sendo representado como um vetor de vértices
struct graph {
    int V;
    int E;
    int max;
    Vertice **vertices;
};

Graph *Graph_ReadFile(char *enderecoArquivo) {
    FILE *file = fopen(enderecoArquivo, "r");

    if (!file) {
        printf("Não foi possível ler o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    Graph *graph = Graph_init();

    char sourceVert[TAM_MAX_LEITURA];
    char targetVert[TAM_MAX_LEITURA];
    int qtdVertices, idxTarget;

    while (fscanf(file, "%s %d ", sourceVert, &qtdVertices) != EOF) {

        //Busca se o vertice já esta no grafo
        idxTarget = Graph_buscaIndicePorNome(graph, sourceVert);

        //Se nao estiver, adiciona um novo vertice
        if (idxTarget == -1) {
            Graph_newNode(graph, sourceVert);
            graph->vertices[graph->V - 1]->qtdAdjacencias = qtdVertices;
        } else { //Se o vertice ja estiver, só atualiza as adjacencias
            graph->vertices[idxTarget]->qtdAdjacencias = qtdVertices;
        }

        for (int i = 0; i < qtdVertices; i++) {
            fscanf(file, "%s ", targetVert);

            //Busca se o vértice já está no grafo
            idxTarget = Graph_buscaIndicePorNome(graph, targetVert);

            //Se nao estiver, adiciona um novo nó
            if (idxTarget == -1) {
                Graph_newNode(graph, targetVert);
            }

            idxTarget = Graph_buscaIndicePorNome(graph, sourceVert);

            //Salva o grafo "invertido" para o cálculo mais fácil dos PageRanks
            Graph_newEdge(graph, targetVert, idxTarget);

            graph->E++;
        }
    }

    fclose(file);

    return graph;
}

Graph *Graph_init() {
    Graph *graph = (Graph *) malloc(sizeof(Graph));

    graph->V = 0;
    graph->E = 0;

    graph->max = MAX_VERTICES_INICIAL;

    graph->vertices = malloc(sizeof(Vertice *) * MAX_VERTICES_INICIAL);

    return graph;
}

void Graph_finish(Graph *graph) {

    for (int i = 0; i < graph->V; i++) {
        free(graph->vertices[i]->adjacencias);
        free(graph->vertices[i]->source);
        free(graph->vertices[i]);
    }

    free(graph->vertices);
    free(graph);
}

Vertice *Graph_buscaVerticePorNome(Graph *graph, char *sourceVert) {

    // Busca o vertice no grafo
    for (int i = 0; i < graph->V; i++) {
        if (strcmp(graph->vertices[i]->source, sourceVert) == 0) {
            return graph->vertices[i];
        }
    }

    return NULL;
}

int Graph_buscaIndicePorNome(Graph *graph, char *name) {

    for (int i = 0; i < graph->V; i++) {
        if (strcmp(graph->vertices[i]->source, name) == 0)
            return i;
    }

    return -1;
}

Vertice *Graph_newNode(Graph *graph, char *source) {

    // Se o tamanho alocado for insuficiente, realoca
    if (graph->V >= graph->max) {
        graph->max *= 2;
        graph->vertices = realloc(graph->vertices, sizeof(Vertice) * graph->max);
    }

    Vertice *newVert = malloc(sizeof(Vertice));

    // Inicializa o nome do vertice
    int size = (int) strlen(source);
    newVert->source = malloc(sizeof(char) * (size + 1));
    strcpy(newVert->source, source);

    // Inicializa o vetor de adjacencias
    newVert->adjacencias = malloc(sizeof(int) * MAX_ADJACENCIAS_INICIAL);

    newVert->max = MAX_ADJACENCIAS_INICIAL;
    newVert->len = 0;

    graph->vertices[graph->V++] = newVert;

    return newVert;
}

void Graph_newEdge(Graph *graph, char *sourceVert, int targetVert) {
    Vertice *newVert = Graph_buscaVerticePorNome(graph, sourceVert);

    // Se o espaco alocado for insuficiente, realoca.
    if (newVert->len >= newVert->max) {
        newVert->max *= 2;
        newVert->adjacencias = realloc(newVert->adjacencias, sizeof(int) * newVert->max);
    }

    newVert->adjacencias[newVert->len] = targetVert;
    newVert->len++;
}

int Graph_getNumV(Graph *graph) {
    return graph->V;
}

int Graph_getNumE(Graph *graph) {
    return graph->E;
}

static bool verificarParadaPageRank(Graph *graph, double *pr, double *pr_previous) {
    const double stop = 1e-6; //Valor de parada da iteração

    double soma = 0;

    for (int i = 0; i < graph->V; i++) {
        soma += fabs(pr[i] - pr_previous[i]);
    }

    double result = (1 / (double) graph->V) * soma;

    if (result < stop)
        return false; //Para o processo iterativo se o resultado for menor que 'stop'
    else
        return true; //Caso contrário, continua o processo iterativo
}

double *Graph_pageRanks(Graph *graph) {
    double *pr = calloc(graph->V, sizeof(double));
    double *pr_previous = calloc(graph->V, sizeof(double));

    double a = 0.85; // Fator de amortecimento

    // Inicializa cada pageRank com 1/n (n = número de vértices)
    for (int i = 0; i < graph->V; i++) {
        pr_previous[i] = 1 / (double) graph->V;
    }

    bool continuarIteracao; //Define se a iteracao deve ou não continuar

    do {
        for (int i = 0; i < graph->V; i++) {
            pr[i] = 0;

            for (int j = 0; j < graph->vertices[i]->len; j++) {

                int idxTarget = graph->vertices[i]->adjacencias[j];
                pr[i] += pr_previous[idxTarget] / graph->vertices[idxTarget]->qtdAdjacencias;

            }

            if (graph->vertices[i]->qtdAdjacencias != 0)
                pr[i] = ((1 - a) / graph->V) + (a * pr[i]);
            else
                pr[i] = ((1 - a) / graph->V) + (a * pr_previous[i]) + (a * pr[i]);
        }

        continuarIteracao = verificarParadaPageRank(graph, pr, pr_previous);

        for (int i = 0; i < graph->V; i++) {
            pr_previous[i] = pr[i];
        }

    } while (continuarIteracao);

    free(pr_previous);

    return pr;
}

void inserePageRanks(Graph *graph, vPagina *vPag, double *pageRanks) {
    for (int i = 0; i < vPag_len(vPag); i++) {

        //Transforma a String da Pagina em um Char*
        String *s = vPag_pag_str(vPag, i);
        int len = str_getLen(s);
        char *nameStr = str_getStr(s);
        char *nameChar = malloc(sizeof(char) * (len + 1));
        for (int j = 0; j < len; j++) nameChar[j] = nameStr[j];
        nameChar[len] = '\0';

        //Adiciona o PageRank na Pagina
        int index = Graph_buscaIndicePorNome(graph, nameChar);
        vPag_pag_somaD(vPag, pageRanks[index], i);

        free(nameChar);
    }
}