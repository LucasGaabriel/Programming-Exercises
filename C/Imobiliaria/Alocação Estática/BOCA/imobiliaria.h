#ifndef _IMOBILIARIA
    #define _IMOBILIARIA

    #define MaxImoveis 301
    #include "catalogo.h"

    typedef struct {
        tCatalogo imoveis[MaxImoveis];
        int numImoveis;
    } tImobiliaria;

    void lerDados(tImobiliaria *);
    void lerOperacoes(tImobiliaria *);
    void adicionarPreco(tImobiliaria *);
    void ordenarCatalogo(tImobiliaria *, int (*troca)(tCatalogo *, tCatalogo *));
    int comparaPreco(tCatalogo *, tCatalogo *);
    int comparaQuartos(tCatalogo *, tCatalogo *);
    void ordenarPorAreas(tImobiliaria *, float *);

#endif