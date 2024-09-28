//Nome: Lucas Gabriel de Oliveira Costa
//Matrícula: 2019109482
//Disciplina: Estruturas de Dados II

#ifndef NETWORK_H
#define NETWORK_H

#include "graph.h"

typedef struct network Network;

//Inicializa um conjunto Network. 'Map' é o vetor que possui os 'IDs' dos nós que pertencem ao conjunto. 'Qtd' é a quantidade de nós do conjunto
Network* Network_init(int* map, int qtd);

//Libera a memória alocada para o conjunto
void Network_finish(Network* network);

//Calculo da Inflação dos RTTs
void InflacaoRTTs(char* arquivoEntrada, char* arquivoSaida);

//Algoritmo de Dijkstra (Retorna pesos do menor caminho possível partindo de 'source'
double* Dijkstra(Graph* graph, int source);

#endif //NETWORK_H
