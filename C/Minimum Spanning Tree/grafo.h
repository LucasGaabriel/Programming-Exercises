#ifndef GRAFO_H
#define GRAFO_H

#include <math.h> //Necessário para calcular a distância euclidiana entre pontos.
#include <string.h>
#include "ponto.h" //Dependencias

typedef struct edge{
  int in, out; // Inteiros que representam um indice. Pra saber o que contem em in e out basta passar uma função map[in] ou map[out] que ele retorna uma String.
  double distancia; //Distancia entre os vértices da aresta.
}Edge;

typedef struct graph{
  int V; //Numero de vértices do grafo
  int E; //Numero de arestas do grafo
  Edge* edge; //Lista de arestas
}Graph;

// Calcula a distância entre dois pontos.
double calcula_distancia(PONTO* a,PONTO* b, int m);
// Transforma uma lista de pontos em um grafo completo.
Graph* constructEdgeList(PONTO* input, int m, int vertices);
// Funcao auxiliar para o qsort da ordenaEdgeList, ordena pela distancia
int cmpfunc (const void * a, const void * b);
// Ordena um Grafo do tipo lista de arestas
void ordenaEdgeList(Graph* graph);
// Imprime um Grafo.
void imprimeEdgeList(Graph* graph, char* map[]);
// Retorna o numero de edges
int nEdges(int nvertices);
// Libera o Grafo
void destructGraph(Graph* graph);
#endif