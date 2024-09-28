//Nome: Lucas Gabriel de Oliveira Costa
//Matrícula: 2019109482
//Disciplina: Estruturas de Dados II

#ifndef GRAFO_H
#define GRAFO_H

#include "item.h"

typedef struct list List;
typedef struct graph Graph;

//Inicializa um Grafo passando como argumentos a quantidade de Vértices e a Quantidade de Arestas
Graph* Graph_init(int qtdVertices, int qtdArestas);

//Libera toda a memória alocada para o grafo
void Graph_finish(Graph* graph);

//Adiciona um novo nó no grafo (ligados por uma aresta). O sourceVert define o nó inicial, o destVert define o nó final e o value define o peso da aresta
void Graph_newNode(Graph* graph, int sourceVert, int targetVert, double value);

//Obtém o número de vértices do grafo
int Graph_getNumV(Graph* graph);

//Obtém o número de arestas do grafo
int Graph_getNumE(Graph* graph);

//Recebe a lista de adjacências do 'node' passado como parâmetro
List* Graph_getListAdjNode(Graph* graph, int node);

//Recebe o próximo item da lista de adjacências
List* List_getNextNode(List* list);

//Recebe o 'id' do vértice do nó da lista
int List_getVert(List* list);

//Recebe o 'peso' da aresta conectada do nó da lista
double List_getValue(List* list);

#endif //GRAFO_H
