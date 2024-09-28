#ifndef TP2_CATALOGO_H
    #define TP2_CATALOGO_H

    #include "imovel.h"

    #define EXP_CAT 25

    typedef struct catalogo * tCatalogo;

    tCatalogo inicializaCatalogo();
    void aumentaCatalogo(tCatalogo);
    void liberaCatalogo(tCatalogo);
    void liberaProprietariosCatalogo(tCatalogo);
    void lerCatalogo(tCatalogo);
    void lerOperacoes(tCatalogo);
    int obterNumImoveis(tCatalogo);
    int obterMaxImoveis(tCatalogo);
    int obterIdentificador(tCatalogo, int);
    char* obterTipo(tCatalogo, int);
    char obterTipoSolo(tCatalogo, int);
    float obterPreco(tCatalogo, int);
    tImovel obterImovel(tCatalogo, int);
    void definirImovel(tCatalogo, tImovel, int);
    void acrescentarNumImoveis(tCatalogo, int);
    void adicionarPreco(tCatalogo);
    void adicionarAreas(tCatalogo cat);
    void ordenarCatalogo(tCatalogo, int (*troca)(tImovel *, tImovel *));

#endif //TP2_CATALOGO_H
