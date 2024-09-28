#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ponto.h"
#include "grafo.h"
#include "unionFind.h"

int main(int argc, char* argv[]) {
  
  /*calculo da dimensão dos pontos. Ao executar essa funcao teremos acesso ao numero de 
  elementos que devem estar contidos no vetor de double dos pontos*/
  int  m = retornaDimensao(argv[1]);

  //Inicialização do ponteiro da lista de pontos
  PONTO* lista = NULL;
  /*Leitura do arquivo de entrada, inicializacao e 
  alocacao das estruturas de cada um dos pontos, 
  insercao desses pontos na lista de pontos, 
  retorno da lista de pontos ja com todos os elementos inseridos*/
  lista = Leitura(lista, argv[1], m); 
  
  //acesso ao numero de pontos inseridos na lista
  int v = NumeroPontos(lista);

  //Verifica se a entrada k, recebida pelo stdin, é válida
  isKValid(lista,atoi(argv[2]),v);
  
  /*criacao da variavel de vetor de strings, 
  que recebe como parametro para a quantidade de elementos 
  o numero de elementos da lista adquirido anteriormente*/
  char* map[v];

  /*inicializacao e alocacao dos elementos do vetor de strings e insercao desses elementos no vetor*/
  InicializaMap(lista,map);

  
  /*inicializacao, alocacao e construcao do grafo de Edges*/
  Graph* graph = constructEdgeList(lista, m, v);

  /*Ordenacao dos elementos do grafo*/
  ordenaEdgeList(graph);
  
 
  /*inicializacao,alocacao e construcao da estrutura de UnionFind 
  junto com a execucao do algoritmo de Kruskal*/
  UnionFind *uf = algoritmoDeKruskal(graph, atoi(argv[2]));

  /*criacao e abertura do arquivo de saida e impressao dos grupos comuns no arquivo saida.txt*/
  imprimeGrupos(uf, map, graph, argv[3]);

  //liberacao da estrutura de grafo
  destructGraph(graph);
  //liberacao da estrutura de UnionFind
  liberaUnionFind(uf);
  //liberacao do vetor de strings
  LiberaMap(map,v);

  return 0;
}