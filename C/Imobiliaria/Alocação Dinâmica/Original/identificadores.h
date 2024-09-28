#ifndef TP2_IDENTIFICADORES_H
    #define TP2_IDENTIFICADORES_H

    typedef struct {
        int *identificadores;
        int numIdent;
    } tIdentificadores;

    void inicializaIdentificadores(tIdentificadores *, int);
    void liberaIdentificadores(tIdentificadores *);

#endif //TP2_IDENTIFICADORES_H
