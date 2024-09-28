// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Trabalho 1

#include "listaPessoas.h"

int main() {
    ListaPessoas* PlayED = inicializaListaPessoas();
    definirRedeDeAmizades(PlayED);
    carregarPlaylists(PlayED);
    gerarPlaylistsPorArtista(PlayED);
    gerarPlayedRefatorada(PlayED);
    gerarPastasPlaylists(PlayED);
    gerarSimilaridades(PlayED);
    liberarListaPessoas(PlayED);

    return 0;
}
