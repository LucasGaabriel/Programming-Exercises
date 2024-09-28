// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Trabalho 1

#ifndef TRABALHO_I___ED1_LISTAPLAYLISTS_H
#define TRABALHO_I___ED1_LISTAPLAYLISTS_H

typedef struct listaPlaylists ListaPlaylists;

#include <stdio.h>
#include "listaMusicas.h"
#include "listaPessoas.h"

/* Inicializa uma lista de playlists
 * input: nenhum
 * output: ponteiro para a lista de playlists inicializada
 * pre-condicao: nenhuma
 * pos-condicao: a lista de playlists é alocada e inicializada vazia
 */
ListaPlaylists* inicializaListaPlaylists(void);

/* Insere uma playlist na lista
 * input: a lista na qual a playlist vai ser adicionada e o nome da playlist
 * output: nenhum
 * pre-condicao: a lista e o nome da playlist são válidos
 * pos-condicao: a playlist com o nome é inserida na lista de playlists
 */
void inserirPlaylistNaLista(ListaPlaylists* lista, char* nome);

/* Faz uma busca na lista pelo nome da playlist
 * input: a lista em que vai ser feita a busca e o nome da playlist que quer encontrar
 * output: ponteiro para a lista de musicas da playlist se a playlist for encontrada, ou ponteiro NULL se a playlist não for encontrada
 * pre-condicao: a lista e o nome da playlist são válidos
 * pos-condicao: a lista não é modificada
 */
ListaMusicas* buscaPlaylist(ListaPlaylists* lista, char* nomePlaylist);

/* Adiciona as musicas de um arquivo texto à playlist
 * input: a lista de playlists na qual está a playlist que as musicas serao adicionadas
 * output: nenhum
 * pre-condicao: a lista e o nome da playlist são válidos, o nome do arquivo e da playlist devem ser iguais, o arquivo deve existir e a playlist já deve estar na lista
 * pos-condicao: as musicas do arquivo texto sao adicionadas a playlist da lista
 */
void adicionarMusicasPlaylist(ListaPlaylists* lista, char* nomePlaylist);

/* Libera toda a memoria alocada pela lista de playlists, incluindo as musicas das playlists
 * input: uma lista de playlists
 * output: nenhum
 * pre-condicao: a lista de playlists é valida
 * pos-condicao: toda a memoria alocada para a lista de playlists é liberada, incluindo para as musicas das playlists
 */
void liberarListaPlaylists(ListaPlaylists* lista);

/* Imprime toda a lista de playlists, incluindo o nome de cada playlist e as musicas
 * input: uma lista de playlists
 * output: nenhum
 * pre-condicao: a lista de playlists é valida
 * pos-condicao: nenhuma
 */
void imprimirListaPlaylists(ListaPlaylists* lista);

/* Retorna a quantidade de playlists da lista
 * input: uma lista de playlists
 * output: quantidade de playlists na lista
 * pre-condicao: a lista de playlists é valida
 * pos-condicao: a lista de playlists não é modificada
 */
int retornaQuantidadePlaylists(ListaPlaylists* listaPlaylists);

/* Gera playlists divididas por artistas para a pessoa
 * input: uma pessoa
 * output: nenhum
 * pre-condicao: a pessoa é valida
 * pos-condicao: as playlists iniciais da pessoa sao apagadas e novas playlists divididas por artistas sao adicionadas, onde o nome da playlist é o nome do artista
 */
void gerarPlaylistsPorArtistaPlaylists(Pessoa* pessoa);

/* Escreve no arquivo de entrada o nome da pessoa, a quantidade de playlists e o nome de todas as suas playlists (separadas por ';')
 * input: uma pessoa e um arquivo
 * output: nenhum
 * pre-condicao: a pessoa e o arquivo são válidos
 * pos-condicao: nenhuma
 */
void escreverNaPlayedRefatorada(Pessoa *pessoa, FILE* arquivo);

/* Cria arquivos textos com os nomes das playlists da pessoa e inclui as musicas das playlists dentro dos arquivos
 * input: uma pessoa
 * output: nenhum
 * pre-condicao: a pessoa é válida e existe uma pasta no diretório com o nome da pessoa
 * pos-condicao: nenhuma
 */
void gerarPlaylistsDentroDasPastas(Pessoa* pessoa);

/* Verifica e retorna a quantidade de musicas iguais entre duas pessoas
 * input: duas pessoas
 * output: quantidade de similaridades (musicas iguais) entre as duas pessoas
 * pre-condicao: as duas pessoas são válidas
 * pos-condicao: nada é modificado
 */
int verificaSimilaridadesPlaylists(Pessoa* pessoa1, Pessoa* pessoa2);

#endif //TRABALHO_I___ED1_LISTAPLAYLISTS_H
