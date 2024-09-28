// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Trabalho 1

#ifndef TRABALHO_I___ED1_MUSICA_H
#define TRABALHO_I___ED1_MUSICA_H

typedef struct musica Musica;

/* Inicializa uma musica com artista e descricao
 * input: nome do artista e a descricao da musica
 * output: ponteiro para a musica inicializada
 * pre-condicao: strings validas para o artista e para a descricao
 * pos-condicao: a musica é inicializada com o nome do artista e a descricao da musica
 */
Musica* inicializaMusica(char* artista, char* descricao);

/* Retorna o nome do artista da musica
 * input: uma musica
 * output: nome do artista da musica
 * pre-condicao: a musica deve ser valida
 * pos-condicao: a musica não é modificada
 */
char* retornaArtista(Musica* musica);

/* Retorna a descricao da musica
 * input: uma musica
 * output: a descricao da musica
 * pre-condicao: a musica deve ser valida
 * pos-condicao: a musica não é modificada
 */
char* retornaDescricao(Musica* musica);

/* Libera a memoria alocada para a musica
 * input: uma musica
 * output: nenhum
 * pre-condicao: a musica deve ser valida
 * pos-condicao: toda a memoria alocada para a musica é liberada
 */
void liberarMusica(Musica* musica);

/* Imprime a musica (o artista e a descricao)
 * input: uma musica
 * output: nenhum
 * pre-condicao: a musica deve ser valida
 * pos-condicao: nenhuma
 */
void imprimirMusica(Musica* musica);

#endif //TRABALHO_I___ED1_MUSICA_H
