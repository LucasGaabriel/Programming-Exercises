// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Trabalho 1

#ifndef TRABALHO_I___ED1_PESSOA_H
#define TRABALHO_I___ED1_PESSOA_H

typedef struct pessoa Pessoa;

#include "listaPessoas.h"
#include "listaPlaylists.h"

/* Inicializa uma pessoa
 * input: nome da pessoa
 * output: ponteiro para a pessoa inicializada
 * pre-condicao: string valida para o nome
 * pos-condicao: pessoa inicializada com nome e uma lista de amigos e playlists vazia
 */
Pessoa* inicializaPessoa(char* nome);

/* Retorna o nome da pessoa
 * input: uma pessoa
 * output: uma string com nome da pessoa
 * pre-condicao: pessoa deve existir e ser valida
 * pos-condicao: a pessoa nao é modificada
 */
char* retornaNomePessoa(Pessoa* pessoa);

/* Retorna um ponteiro para a lista de amigos da pessoa
 * input: uma pessoa
 * output: ponteiro para a lista de amigos da pessoa
 * pre-condicao: pessoa deve existir e ser valida
 * pos-condicao: a pessoa nao é modificada
 */
ListaPessoas* retornaListaAmigos(Pessoa* pessoa);

/* Retorna um ponteiro para a lista de playlists da pessoa
 * input: uma pessoa
 * output: ponteiro para a lista de playlists da pessoa
 * pre-condicao: pessoa deve existir e ser valida
 * pos-condicao: a pessoa nao é modificada
 */
ListaPlaylists* retornaListaPlaylists(Pessoa* pessoa);

/* Insere o amigo na Lista de Amigos da pessoaPrincipal
 * input: uma pessoa principal e uma pessoa a ser adicionada na lista de amigos da pessoa principal
 * output: nenhum
 * pre-condicao: ambas as pessoas devem existir e serem validas
 * pos-condicao: 'pessoaAdicionar' é adicionada na Lista de Amigos da 'pessoaPrincipal'
 */
void inserirPessoaNaListaAmigos(Pessoa* pessoaPrincipal, Pessoa* pessoaAdicionar);

/* Libera a memoria alocada para a Pessoa
 * input: uma pessoa
 * output: nenhum
 * pre-condicao: a pessoa deve existir e ser valida
 * pos-condicao: a memoria alocada para a pessoa é liberada, sem liberar a lista de amigos e de playlists
 */
void liberarPessoa(Pessoa* pessoa);

/* Imprime a pessoa
 * input: uma pessoa
 * output: nenhum
 * pre-condicao: a pessoa deve existir e ser valida
 * pos-condicao: nenhuma
 */
void imprimirPessoa(Pessoa* pessoa);

#endif //TRABALHO_I___ED1_PESSOA_H
