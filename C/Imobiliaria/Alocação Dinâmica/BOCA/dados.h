#ifndef TP2_DADOS_H
    #define TP2_DADOS_H

    #include "catalogo.h"
    #include "identificadores.h"

    typedef struct {
        int imoveisCaros;
        int menoresArgilosos;
        float areaLimite;
        float precoLimite;
        int i;
        int j;
        int k;
    } tDados;

    tDados lerDadosRelativos();
    tIdentificadores imoveisMaisCaros(tCatalogo, tDados *);
    tIdentificadores terrenosArgilososMenorArea(tCatalogo, tDados *);
    tIdentificadores casasLimitesEspecificos(tCatalogo, tDados *);
    void apresentarResultados(tIdentificadores *, tIdentificadores *, tIdentificadores *, tDados *);

#endif //TP2_DADOS_H
