// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Trabalho 1

#ifndef TRABALHO_I___ED1_LISTAPESSOAS_H
#define TRABALHO_I___ED1_LISTAPESSOAS_H

typedef struct listaPessoas ListaPessoas;

#include "pessoa.h"

/* Inicializa uma lista de pessoas
 * input: nenhum
 * output: ponteiro para a lista de pessoas inicializada
 * pre-condicao: nenhuma
 * pos-condicao: a lista de pessoas é alocada e inicializada vazia
 */
ListaPessoas* inicializaListaPessoas(void);

/* Insere uma pessoa na lista de pessoas
 * input: uma lista de pessoas e a pessoa a ser adicionada na lista
 * output: nenhum
 * pre-condicao: lista e pessoa são válidas
 * pos-condicao: a pessoa é adicionada na lista
 */
void inserirPessoaNaLista(ListaPessoas* lista, Pessoa* pessoa);

/* Libera toda a memoria alocada pela lista de pessoas
 * input: uma lista de pessoas
 * output: nenhum
 * pre-condicao: a lista de pessoas é válida
 * pos-condicao: toda a memória alocada para a lista de pessoas é liberada
 */
void liberarListaPessoas(ListaPessoas* lista);

/* Define toda a rede de amizades presente no arquivo 'amizade.txt'
 * input: uma lista de pessoas
 * output: nenhum
 * pre-condicao: a lista de pessoas é válida e existe o arquivo 'amizade.txt' no diretorio do programa
 * pos-condicao: toda a rede de amizades é definida e montada na lista de pessoas
 */
void definirRedeDeAmizades(ListaPessoas* lista);

/* Adiciona todas as playlists das pessoas presentes no arquivo 'playlists.txt' e adiciona as musicas a essas playlists
 * input: uma lista de pessoas
 * output: nenhum
 * pre-condicao: a lista de pessoas é válida e existe o arquivo 'playlists.txt' no diretorio do programa contendo as playlists das pessoas e os arquivos correspondentes de cada playlist
 * pos-condicao: todas as playlists e musicas são inseridas na lista de pessoas
 */
void carregarPlaylists(ListaPessoas* lista);

/* Imprime toda a lista de pessoas, inclusive os amigos e suas playlists
 * input: uma lista de pessoas
 * output: nenhum
 * pre-condicao: a lista é válida
 * pos-condicao: nenhuma
 */
void imprimirListaPessoas(ListaPessoas* lista);

/* Gera playlists divididas por artistas para todas as pessoas da lista
 * input: uma lista de pessoas
 * output: nenhum
 * pre-condicao: a lista de pessoas é valida
 * pos-condicao: as playlists iniciais das pessoas sao apagadas e novas playlists divididas por artistas sao adicionadas, onde o nome da playlist é o nome do artista
 */
void gerarPlaylistsPorArtista(ListaPessoas* lista);

/* Escreve em um arquivo chamado "played-refatorada.txt" o nome de cada pessoa da lista, a quantidade de playlists de cada pessoa e o nome de todas as suas playlists (separadas por ';')
 * input: uma lista de pessoas
 * output: nenhum
 * pre-condicao: a lista de pessoas é valida
 * pos-condicao: nenhuma
 */
void gerarPlayedRefatorada(ListaPessoas* lista);

/* Cria uma pasta com o nome de cada pessoa da lista e cria arquivos textos com os nomes das playlists da pessoa e inclui as musicas das playlists dentro dos arquivos
 * input: uma lista de pessoas
 * output: nenhum
 * pre-condicao: a lista de pessoas é válida
 * pos-condicao: nenhuma
 */
void gerarPastasPlaylists(ListaPessoas* lista);

/* Verifica e escreve em um arquivo 'similaridades.txt' a quantidade de musicas iguais entre os amigos de uma lista de pessoas
 * input: uma lista de pessoas
 * output: nenhum
 * pre-condicao: a lista de pessoas é válida
 * pos-condicao: nada é modificado
 */
void gerarSimilaridades(ListaPessoas* lista);

#endif //TRABALHO_I___ED1_LISTAPESSOAS_H
