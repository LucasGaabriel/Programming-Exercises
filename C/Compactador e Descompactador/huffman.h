// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Trabalho 2 - O Compactador de Huffman

#ifndef TRABALHO2_ED1_HUFFMAN_H
#define TRABALHO2_ED1_HUFFMAN_H

#include <stdio.h>
#include "listaArvores.h"

/* Funcao que compacta um arquivo, passando como parametro o nome do arquivo
 * input: o nome do arquivo a ser compactado
 * output: nenhum
 * pre-condicao: nome do arquivo deve ser valido e o arquivo deve estar no mesmo diretorio do programa
 * pos-condicao: o arquivo original não é modificado. É gerado um arquivo compactado com mesmo nome (extensao original gravada no nome) com a extensao ".comp"
 */
void compactador(char* nomeArquivo);

/* Funcao que descompacta um arquivo, passando como parametro o nome do arquivo
 * input: o nome do arquivo a ser descompactado
 * output: nenhum
 * pre-condicao: nome do arquivo deve ser valido e o arquivo deve estar no mesmo diretorio do programa
 * pos-condicao: o arquivo compactado não é modificado. É gerado um arquivo descompactado com mesmo nome e extensao anterior a compactacao
 */
void descompactador(char* nomeArquivo);

/* Define os pesos de cada caracter do arquivo, onde o peso é a quantidade de vezes que o caracter aparece no arquivo
 * input: um ponteiro para o arquivo
 * output: vetor de inteiros com os pesos de cada caracter, com indice variando de 0 a 255, onde o indice representa o caracter da tabela ASCII
 * pre-condicao: o ponteiro para o arquivo deve ser valido
 * pos-condicao: memoria alocada dinamicamente para o vetor de pesos
 */
unsigned int* definirPesosCaracteres(FILE* arquivo);

/* Faz a leitura dos pesos de cada caracter do arquivo compactado, onde o peso é a quantidade de vezes que o caracter aparece no arquivo
 * input: um ponteiro para o arquivo
 * output: vetor de inteiros com os pesos de cada caracter, com indice variando de 0 a 255, onde o indice representa o caracter da tabela ASCII
 * pre-condicao: o ponteiro para o arquivo deve ser valido, e o marcador de leitura do arquivo deve estar no inicio
 * pos-condicao: memoria alocada dinamicamente para o vetor de pesos
 */
unsigned int* lerPesosCaracteres(FILE* arquivo);

/* Cria uma lista de arvores inicial ordenada por peso, a partir do vetor de pesos
 * input: um vetor de inteiro (pesos) com indice variando de 0 a 255
 * output: uma lista de arvores ordenada por peso
 * pre-condicao: vetor de inteiros deve ser valido e ter tamanho de 256 (0 a 255)
 * pos-condicao: lista de arvores e arvores da lista alocada dinamicamente
 */
ListaArvores* montarListaDeArvoresInicial(unsigned int* pesosCaracteres);

/* Cria a Arvore Otima utilizando a Codificacao de Huffman
 * input: uma lista de arvores
 * output: a arvore otima induzida pela codificacao de Huffman
 * pre-condicao: lista de Arvores deve ser valida
 * pos-condicao: a memoria da lista de arvores usada inicialmente não é liberada
 */
Arvore* codificacaoDeHuffman(ListaArvores* listaDeArvores);

/* Funcao que gera o arquivo compactado usando a arvoreOtima de Huffman, os pesos e o arquivo Inicial
 * input: uma arvore otima induzida pela codificacao de Huffman, o ponteiro para o arquivo inicial, o nome do arquivo e o vetor de pesos
 * output: nenhum
 * pre-condicao: todos os parametros devem ser validos
 * pos-condicao: o arquivo original não é modificado. É gerado um arquivo compactado com mesmo nome (extensao original gravada no nome) com a extensao ".comp"
 */
void gerarArquivoCompactado(Arvore* arvoreOtima, FILE* arquivo, char* nomeArquivo, unsigned int* pesos);

/* Funcao que gera o arquivo descompactado usando a arvoreOtima de Huffman e o arquivo Inicial
 * input: uma arvore otima induzida pela codificacao de Huffman (retirada do arquivo compactado), o ponteiro para o arquivo inicial e o nome do arquivo
 * output: nenhum
 * pre-condicao: todos os parametros devem ser validos
 * pos-condicao: o arquivo compactado não é modificado. É gerado um arquivo descompactado com mesmo nome e extensao anterior a compactacao
 */
void gerarArquivoDescompactado(Arvore* arvoreOtima, FILE* arquivo, char* nomeArquivo);

#endif //TRABALHO2_ED1_HUFFMAN_H
