// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Trabalho 1

#ifndef TRABALHO_I___ED1_LISTAMUSICAS_H
#define TRABALHO_I___ED1_LISTAMUSICAS_H

typedef struct listaMusicas ListaMusicas;

#include <stdio.h>
#include "listaPessoas.h"
#include "musica.h"

/* Inicializa uma lista de musicas
 * input: nenhum
 * output: ponteiro para a lista de musicas inicializada
 * pre-condicao: nenhuma
 * pos-condicao: a lista de musicas é alocada e inicializada vazia
 */
ListaMusicas* inicializaListaMusicas(void);

/* Insere uma musica na lista de musicas
 * input: uma lista de musicas e a musica a ser adicionada na lista
 * output: nenhum
 * pre-condicao: lista e musica são válidas
 * pos-condicao: a musica é adicionada na lista
 */
void inserirMusicaNaLista(ListaMusicas* lista, Musica* musica);

/* Libera toda a memoria alocada pela lista de musicas
 * input: uma lista de musicas
 * output: nenhum
 * pre-condicao: a lista de musicas é válida
 * pos-condicao: toda a memória alocada para a lista de musicas é liberada
 */
void liberarListaMusicas(ListaMusicas* lista);

/* Libera toda a memoria alocada pela lista de musicas sem liberar as musicas da lista
 * input: uma lista de musicas
 * output: nenhum
 * pre-condicao: a lista de musicas é válida
 * pos-condicao: a memória alocada para a lista de musicas é liberada, sem liberar as musicas da lista
 */
void liberarListaMusicasSemLiberarMusicas(ListaMusicas* musicas);

/* Imprime toda a lista de musicas, que inclui o artista e a descricao
 * input: uma lista de musicas
 * output: nenhum
 * pre-condicao: a lista de musicas é valida
 * pos-condicao: nenhuma
 */
void imprimirListaMusicas(ListaMusicas* lista);

/* Faz a verificacao na lista de musicas para gerar playlists divididas por artistas para a pessoa
 * input: uma lista de musicas e uma pessoa
 * output: nenhum
 * pre-condicao: a lista de musicas e a pessoa são validas
 * pos-condicao: as musicas da lista de musicas ficam separadas por artista dentro das playlists da pessoa
 */
void gerarPlaylistsPorArtistaMusicas(ListaMusicas* listaMusicas, Pessoa* pessoa);

/* Escreve no arquivo de entrada o artista e a descricao das musicas da lista de musicas
 * input: uma lista de musicas e um arquivo
 * output: nenhum
 * pre-condicao: a lista de musicas e o arquivo são validos
 * pos-condicao: a lista de musicas não é alterada
 */
void escreverNasPlaylistsDaPessoa(ListaMusicas* listaMusicas, FILE* arquivo);

/* Verifica e retorna a quantidade de musicas similares entre duas listas de musicas
 * input: duas listas de musicas
 * output: quantidade de musicas similares
 * pre-condicao: as duas listas de musicas são validas
 * pos-condicao: as listas de musicas não são alteradas
 */
int verificaSimilaridades(ListaMusicas* lista1, ListaMusicas* lista2);

#endif //TRABALHO_I___ED1_LISTAMUSICAS_H
