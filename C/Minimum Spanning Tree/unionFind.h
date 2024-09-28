#ifndef UNIONFIND_H
#define UNIONFIND_H

#include "grafo.h"
#include "ponto.h"

//Implementação da Weighted Quick-Union
typedef struct {
  int* id; //Componente de cada ponto — A componente de um ponto[i] = id[i] — (id[i] é o pai de i)
  int* sz; //Quantidade de objetos da arvore
} UnionFind;


/* Inicializa uma UnionFind
 * Input: quantidade de Pontos
 * Output: Unionfind inicializada
 */
UnionFind* init_UF(int qtdPontos);


/* Busca a componente do ponto P
 * Input: Uma UnionFind e um ponto P
 * Output: Componente do ponto P
 */
int find_UF(UnionFind* uf, int p);


/* Faz a uniao de 2 pontos
 * Input: Uma UnionFind e dois pontos
 * Output: Sem output / Os pontos p e q agora são conectados
 */
void union_UF(UnionFind* uf, int p, int q);


/* Verifica se 2 pontos estão conectados
 * Input: Uma UnionFind e dois pontos
 * Output: Retorna 1 se os pontos estão conectados ou 0 caso contrário
 */
int connected_UF(UnionFind* uf, int p, int q);


/* Gera a MST e remove as k-1 arestas de maior peso, gerando 'k' grupos
 * Input: Um grafo e um inteiro 'k'
 * Output: Retorna a UnionFind com os grupos separados
 */
UnionFind* algoritmoDeKruskal(Graph* grafo, int k);


/* Libera a memoria alocada para a UnionFind
 * Input: Uma UnionFind
 * Output: Sem retorno / Toda a memória alocada para a UnionFind é liberada
 */
void liberaUnionFind(UnionFind* uf);


/* Imprime os grupos gerados pelo algoritmo de Kruskal no arquivo de saida
 * Input: Uma UnionFind, Um vetor de strings com os nomes dos Pontos, um grafo e um nome para o arquivo de saida
 * Output: Sem retorno / Os grupos são escritos no arquivo de saida, separados por linha e ordenados
 */
void imprimeGrupos(UnionFind* uf, char** nomePontos, Graph* grafo, char* arquivo_saida);

#endif