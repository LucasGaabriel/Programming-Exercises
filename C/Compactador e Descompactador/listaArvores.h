// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Trabalho 2 - O Compactador de Huffman

#ifndef TRABALHO2_ED1_LISTAARVORES_H
#define TRABALHO2_ED1_LISTAARVORES_H

#include "arvore.h"

typedef struct listaArvores ListaArvores;

/* Inicializa uma lista de arvores vazia (simplesmente encadeada com sentinela)
 * input: nenhum
 * output: ponteiro para uma lista de arvores
 * pre-condicao: nenhuma
 * pos-condicao: uma lista de arvores vazia é inicializada
 */
ListaArvores* inicializaLista();

/* Insere uma arvore no final da lista
 * input: uma lista de arvores e a arvore a ser adicionada na lista
 * output: nenhum
 * pre-condicao: lista e arvore devem ser validas
 * pos-condicao: a arvore é inserida na lista
 */
void inserirNoFinalDaLista(ListaArvores* lista, Arvore* arvore);

/* Insere uma arvore na lista no lugar correto, de modo que a lista fique ordenada por peso
 * input: uma lista de arvores e a arvore a ser adicionada na lista
 * output: nenhum
 * pre-condicao: lista e arvore devem ser validas, lista deve estar ordenada por peso
 * pos-condicao: a arvore é inserida na lista já ordenada
 */
void inserirNaListaOrdenadoPorPeso(ListaArvores* lista, Arvore* arvore);

/* Retira uma arvore da lista sem liberar a memoria alocada para essa arvore
 * input: uma lista de arvores e a arvore a ser removida da lista
 * output: nenhum
 * pre-condicao: lista e arvore devem ser validas
 * pos-condicao: a arvore é removida da lista sem liberar a memoria da arvore
 */
void retirarDaListaSemLiberarArvore(ListaArvores* lista, Arvore* arvore);

/* Imprime todas as arvores da lista
 * input: uma lista de arvores
 * output: nenhum
 * pre-condicao: lista deve ser valida
 * pos-condicao: a lista nao é modificada
 */
void imprimirLista(ListaArvores* lista);

/* Libera toda a memória alocada pela lista, incluindo as árvores da lista
 * input: uma lista de arvores
 * output: nenhum
 * pre-condicao: lista deve ser valida
 * pos-condicao: toda a memória alocada pela lista é liberada, incluindo as árvores
 */
void liberarLista(ListaArvores* lista);

/* Ordena a lista de arvores por pesos de forma crescente (Bubble sort)
 * input: uma lista de arvores
 * output: nenhum
 * pre-condicao: lista deve ser valida
 * pos-condicao: toda a lista fica ordenada por peso de forma crescente
 */
void ordenarListaCrescente(ListaArvores* lista);

/* Retorna a arvore presente no 'indice' se for um indice valido, ou NULL, caso não seja um indice válido
 * input: uma lista de arvores e um indice
 * output: ponteiro para a arvore do indice se for um indice valido, ou NULL, caso seja um indice invalido
 * pre-condicao: lista deve ser valida
 * pos-condicao: a lista nao é modificada
 */
Arvore* retornaArvoreDoIndice(ListaArvores* lista, int indice);

/* Retorna a quantidade de arvores da lista
 * input: uma lista de arvores
 * output: quantidade de arvores presente na lista
 * pre-condicao: lista deve ser valida
 * pos-condicao: a lista nao é modificada
 */
int retornaQuantidadeArvoresDaLista(ListaArvores* lista);

#endif //TRABALHO2_ED1_LISTAARVORES_H
