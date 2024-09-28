// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Trabalho 2 - O Compactador de Huffman

#ifndef TRABALHO2_ED1_ARVORE_H
#define TRABALHO2_ED1_ARVORE_H

typedef struct arvore Arvore;

/* Inicializa uma arvore com um caracter, um peso e suas subarvores esquerda e direita
 * input: um caracter, um peso e duas arvores (subarvore esquerda e subarvore direita)
 * output: ponteiro para a arvore inicializada
 * pre-condicao: caracter e peso devem ser validos. Subarvores podem ser NULL
 * pos-condicao: a arvore é inicializada com o caracter, o peso e suas subarvores
 */
Arvore* criaArvore(char caracter, unsigned int peso, Arvore* sae, Arvore* sad);

/* Retorna a subArvore esquerda da Arvore
 * input: ponteiro para uma arvore
 * output: ponteiro para a subarvore Esquerda da Arvore
 * pre-condicao: arvore deve ser valida
 * pos-condicao: a arvore nao é modificada
 */
Arvore* retornaSubarvoreEsquerda(Arvore* arvore);

/* Retorna a subArvore direita da Arvore
 * input: ponteiro para uma arvore
 * output: ponteiro para a subarvore Direita da Arvore
 * pre-condicao: arvore deve ser valida
 * pos-condicao: a arvore nao é modificada
 */
Arvore* retornaSubarvoreDireita(Arvore* arvore);

/* Retorna o caracter da arvore
 * input: ponteiro para uma arvore
 * output: caracter da arvore
 * pre-condicao: arvore deve ser valida
 * pos-condicao: a arvore nao é modificada
 */
unsigned char retornaCaracter(Arvore* arvore);

/* Retorna o peso da arvore se for valida, caso contrario, retorna -1
 * input: ponteiro para uma arvore
 * output: peso da arvore
 * pre-condicao: nenhuma
 * pos-condicao: a arvore nao é modificada
 */
unsigned int retornaPeso(Arvore* arvore);

/* Imprime a arvore e suas subArvores no padrao de sinal de maior (>) e menor (<)
 * input: ponteiro para uma arvore
 * output: nenhum
 * pre-condicao: arvore deve ser valida
 * pos-condicao: a arvore nao é modificada
 */
void imprimeArvore(Arvore* arvore);

/* Libera toda a memoria alocada para a arvore e suas subArvores
 * input: ponteiro para uma arvore
 * output: nenhum
 * pre-condicao: arvore deve ser valida
 * pos-condicao: toda a memória alocada para a arvore e suas subArvores é liberada
 */
void liberaArvore(Arvore* arvore);

#endif //TRABALHO2_ED1_ARVORE_H
