//Nome: Lucas Gabriel de Oliveira Costa
//Matrícula: 2019109482
//Disciplina: Estruturas de Dados II

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

//Lista de Adjacências
struct list {
    int vert;
    double value;
    List* next;
};

//Graph sendo representado como uma lista (simplesmente encadeada) de adjacências
struct graph {
    int V;
    int E;
    List** adj;
};

Graph* Graph_init(int qtdVertices, int qtdArestas){
    Graph* graph = (Graph*) malloc (sizeof(Graph));

    graph->V = qtdVertices;
    graph->E = qtdArestas;

    graph->adj = malloc (sizeof(List*) * qtdVertices);

    for(int i=0; i<qtdVertices; i++){
        graph->adj[i] = NULL;
    }

    return graph;
}

void Graph_finish(Graph* graph){

    List* next; //Ponteiro auxiliar para liberação da memória

    for(int i=0; i<graph->V; i++){
        for(List* p = graph->adj[i]; p != NULL; p = next){
            next = p->next;
            free(p);
        }
    }

    free(graph->adj);
    free(graph);
}

void Graph_newNode(Graph* graph, int sourceVert, int targetVert, double value){
    List* list = (List*) malloc (sizeof(List));

    list->vert = targetVert;
    list->value = value;

    //Encadeia a lista de adjacências do vértice (Adiciona o novo vértice no início da lista)
    list->next = graph->adj[sourceVert];
    graph->adj[sourceVert] = list;
}

int Graph_getNumV(Graph* graph){
    return graph->V;
}

int Graph_getNumE(Graph* graph){
    return graph->E;
}

List* Graph_getListAdjNode(Graph* graph, int node){
    return graph->adj[node];
}

List* List_getNextNode(List* list){
    return list->next;
}

int List_getVert(List* list){
    return list->vert;
}

double List_getValue(List* list){
    return list->value;
}