
#include "grafo.h"

//Retorna o numero de Edges para construir um grafo completo.
int nEdges(int v){
  return (v*(v -1))/2;
}

//Recebe dois pontos e sua dimensão e retorna a distância
double calcula_distancia(PONTO* a,PONTO* b, int m){
	long double sum = 0; //Soma do valores do vetor, usei um long double pois pode ficar grande.
	for(int i=0;i < m; i++){
		sum += pow((a->vet[i] - b->vet[i]),2);
	}
	double dist = sqrt(sum);
	return dist;
}

// Transforma a entrada bruta em um Grafo Completo do tipo Lista de Arestas.
Graph* constructEdgeList(PONTO* input, int m, int vertices){
  //Cria um Grafo para armazenar a Lista de Edges
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  
  //Cria o Edge para armazenar as informações coletadas.
  Edge* edge = (Edge*)malloc(nEdges(vertices) * sizeof(Edge));

  // Auxiliares:
  int index=0; //Marcador da posição na lista de Edges.
  int i=0; //Auxiliar para mapear os valores de IN
  int j=0; //Auxiliar para mapear os valores de OUT
  
  //Cria dois ponteiros auxiliares para percorrer a lista de distancias, formando uma triangulação evitando perda de memoria.
  for(PONTO* u=input;u != NULL;u=u->prox){
    j=i;
    for(PONTO* v=u->prox;v != NULL;v=v->prox){
      
      edge[index].in = i;
      edge[index].out = j+1;
      edge[index].distancia = calcula_distancia(u,v,m);
      
      j++; //Vai para a proxima posicao do vetor
      index++;
    }
    i++;
  }
  //Importa as informações para um grafo completo.
  graph->V = vertices;
  graph->E = nEdges(vertices);
  graph->edge = edge;

  //Libera a entrada bruta, para economizar espaço na memoria RAM.
  LiberaListaPonto(input);

  //Retorna o grafo.
  return graph;
}

int cmpfunc(const void *a, const void *b)
{
  //Declara os tipos abstratos como uma Aresta
  Edge* a1 = (Edge*)a;
  Edge* b1 = (Edge*)b;
  //Retorna qual Aresta tem a menor distancia
  return (a1->distancia > b1->distancia);
}

void ordenaEdgeList(Graph* graph){
  qsort(graph->edge,graph->E,sizeof(graph->edge[0]),cmpfunc);
}

void imprimeEdgeList(Graph* graph, char* map[]){
  for(int i=0;i<graph->E;i++){
    printf("E%d(In:%d | Out:%d | name_in: %s | name_out: %s| D(in,out):%lf\n",i,graph->edge[i].in,graph->edge[i].out,map[graph->edge[i].in],map[graph->edge[i].out],graph->edge[i].distancia);
  }
}

void destructGraph(Graph* graph){
  free(graph->edge);
  free(graph);
}