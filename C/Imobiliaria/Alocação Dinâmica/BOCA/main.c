#include "catalogo.h"
#include "dados.h"

int main() {
    tCatalogo cat;
    tDados dados;
    tIdentificadores imoveisCaros, terrenosArgilosos, casasLimitesEspec;

    cat = inicializaCatalogo();
    lerCatalogo(cat);
    lerOperacoes(cat);
    dados = lerDadosRelativos();
    imoveisCaros = imoveisMaisCaros(cat, &dados);
    terrenosArgilosos = terrenosArgilososMenorArea(cat, &dados);
    casasLimitesEspec = casasLimitesEspecificos(cat, &dados);
    apresentarResultados(&imoveisCaros, &terrenosArgilosos, &casasLimitesEspec, &dados);
    liberaProprietariosCatalogo(cat);
    liberaCatalogo(cat);

    return 0;
}