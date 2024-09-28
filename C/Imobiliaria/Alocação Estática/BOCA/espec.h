#ifndef _ESPEC
    #define _ESPEC
    #include "imobiliaria.h"

    typedef struct {
        int imoveisCaros;
        int menoresArgilosos;
        float areaLimite;
        float precoLimite;
        int i;
        int j;
        int k;
    } tEspec;

    typedef struct {
        int identificadores[MaxImoveis];
        int numIdent;
    } tIdentificadores;

void lerDadosRelativos(tEspec *);
void imoveisMaisCaros(tImobiliaria *, tEspec *, tIdentificadores *);
void terrenosArgilososMenorArea(tImobiliaria *, tEspec *, tIdentificadores *);
void casasLimitesEspecificos(tImobiliaria *, tEspec *, tIdentificadores *);
void apresentarResultados(tIdentificadores *, tIdentificadores *, tIdentificadores *, tEspec *);

#endif