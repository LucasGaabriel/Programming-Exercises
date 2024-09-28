#ifndef GRAFO_H
#define GRAFO_H

#include "vPagina.h"

typedef struct vertice Vertice;
typedef struct graph Graph;

// Faz a leitura do grafo passando o diretório completo do arquivo 'graph.txt'
Graph *Graph_ReadFile(char *enderecoArquivo);

// Inicializa um Grafo
Graph *Graph_init();

// Libera toda a memória alocada para o grafo
void Graph_finish(Graph *graph);

// Retorna o vertice buscando pelo nome
Vertice *Graph_buscaVerticePorNome(Graph *graph, char *sourceVert);

// Retorna o índice de um vértice no grafo passando o nome do vértice
int Graph_buscaIndicePorNome(Graph *graph, char *name);

// Adiciona um novo nó/vértice no grafo
Vertice *Graph_newNode(Graph *graph, char *source);

// Adiciona uma nova adjacencia no grafo
// (Source = nome do vértice origem, Target = Índice do vértice destino no grafo)
void Graph_newEdge(Graph *graph, char *sourceVert, int targetVert);

// Obtém o número de vértices do grafo
int Graph_getNumV(Graph *graph);

// Obtém o número de arestas do grafo
int Graph_getNumE(Graph *graph);

// Calcula e retorna os PageRanks do Grafo
double *Graph_pageRanks(Graph *graph);

// Insere os PageRanks no vetor de Paginas
void inserePageRanks(Graph *graph, vPagina *vPag, double *pageRanks);

#endif // GRAFO_H