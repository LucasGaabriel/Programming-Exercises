#include "imobiliaria.h"
#include "espec.h"

int main(){
    tImobiliaria imoveis;
    tEspec espec;
    tIdentificadores imoveisCaros, argilososMenorArea, casasLimitEspec;

    lerDados(&imoveis);
    lerOperacoes(&imoveis);
    lerDadosRelativos(&espec);
    adicionarPreco(&imoveis);
    imoveisMaisCaros(&imoveis, &espec, &imoveisCaros);
    terrenosArgilososMenorArea(&imoveis, &espec, &argilososMenorArea);
    casasLimitesEspecificos(&imoveis, &espec, &casasLimitEspec);
    apresentarResultados(&imoveisCaros, &argilososMenorArea, &casasLimitEspec, &espec);
}