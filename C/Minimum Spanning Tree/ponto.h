#ifndef PONTO_H
#define PONTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definicao da estrutura de lista de pontos
typedef struct ponto PONTO;

//estrutura da lista de pontos
struct ponto{
  char* name;//ponteiro para o nome do ponto
  double * vet;//ponteiro para o vetor de double do ponto
  PONTO* prox;//ponteiro para o proximo ponto
};

/*funcao que inicializa um elemento da lista de pontos
input: não precisa
output: um ponto inicializado.*/
PONTO* InicializaPonto();

/* funcao para criar um vetor de strings  
input: a lista de pontos e um ponteiro para o vetor de strings vazio
output: vetor de strings preenchido*/
void InicializaMap(PONTO* lista,char* vet[]);

/*funcao para inserir pontos na lista de pontos
input: lista de pontos já inicializada e vazia e ponto a ser inserido na lista
output: lista de pontos com o ponto passado como parametro inserido
*/
PONTO* InserePonto(PONTO* lista,PONTO* pont);

/*funcao que retorna o numero de pontos(quantidade de elementos) da lista de pontos
input: lista de pontos já inicializada e preenchida
output: quantidade de elementos da lista de pontos*/
int NumeroPontos(PONTO* lista);

/*Le a primeira linha do  arquivo e retorna a dimensão do vetor de double de cada ponto a partir da contagem da quantidade de virgulas da linha
input: ponteiro para a string que nomeia o arquivo de entrada
ouput: inteiro que indica a dimensão do vetor de doubles dos pontos*/
int retornaDimensao(char *argv);

/*funcao que retorna o nome que identica um ponto
input: o ponto a ser analisado
output: o nome que identifica esse ponto
*/
char* retornaNome(PONTO* pont);


/*funcao que retorna o vetor de double de um ponto
input: o ponto a ser analisado
output:o vetor de double desse ponto
*/
double* retornaVet(PONTO* pont);

/*Funcao para escrever no terminal o nome que identifica determinado ponto     
input: um ponto a ser analisado
output: a escrita do nome desse ponto no terminal*/
void EscreveNome(PONTO* pont);

/*Funcao para escrever no terminal os valores presentes no vetor de double de um ponto
Input:um ponto a ser analisado e o numero de elementos do vetor de double 
Output: a escrita dos valores do vetor de double desse ponto no terminal*/
void EscreveValores(PONTO * pont,int m);

/* Funcao para escrever  o nome e os valores do vetor de double de todos os pontos de uma lista de pontos no terminal
Input: um ponteiro para uma lista de pontos já inicializada e um inteiro que indica o numero de elementos do vetor de double de cada ponto da lista
Output: a escrita dos nomes e valores do vetor de double de todos os pontos da lista no terminal*/
void EscreveListaPontos (PONTO* lista,int m);

/*Funcao que escreve no terminal os nomes presentes no vetor de strings
Input: um ponteiro para o vetor de strings e o numero de nomes presente no vetor que equivale ao numero de pontos da lista de pontos
Output: a escrita dos nomes presentes no vetor de nomes no terminal*/
void printMap(char* map[],int v);

/* Funcao que realiza a leitura do arquivo de entrada e gera a lista de pontos
Input: lista de pontos ja inicializada mas sem elementos, ponteiro para a string que equivale ao nome do arquivo de entrada e o numero de elementos do vetor de double de cada ponto
Output: a lista de pontos com todos os pontos já inicializados e inseridos na lista*/
PONTO* Leitura(PONTO* lista,char* argv,int m);

/* Funcao para liberar a lista de pontos
Input: uma lista de pontos
Output: a lista de pontos liberada*/
void LiberaListaPonto(PONTO* lista);

/*Funcao para liberar o vetor de strings 
Input:o vetor de strings e a quantidade de strings nesse vetor
Output: o vetor de strings ja liberado*/
void LiberaMap(char* map[],int v);

// Verifica se a entrada do stdin é válida.
void isKValid(PONTO* lista,int k, int v);

#endif