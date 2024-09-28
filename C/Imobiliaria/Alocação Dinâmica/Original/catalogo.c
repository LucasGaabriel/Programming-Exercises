#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"
#include "imovel.h"
#include "triangular.h"
#include "retangular.h"
#include "trapezoidal.h"
#include "casa.h"
#include "apartamento.h"

struct catalogo {
    tImovel *imoveis;
    int numImoveis;
    int maxImoveis;
};

//Aloca espaco para a estrutura e Inicializa o Numero de Imoveis e a Qtd Maxima de Imoveis
tCatalogo inicializaCatalogo(){
    tCatalogo aux = (tCatalogo) malloc (sizeof(struct catalogo));
    if(!aux){
        printf("Nao foi possivel alocar o tCatalogo");
        exit(1);
    }
    aux->numImoveis = 0;
    aux->maxImoveis = EXP_CAT;

    aux->imoveis = (tImovel *) malloc ( sizeof(tImovel) * aux->maxImoveis );
    if(!aux->imoveis){
        printf("Nao foi possivel alocar os Imoveis");
    }

    return aux;
}

//Aumenta o espaco alocado disponivel para os Imoveis do catalogo
void aumentaCatalogo(tCatalogo cat){
    cat->maxImoveis += EXP_CAT;
    tImovel *aux = (tImovel *) malloc ( sizeof(tImovel) * cat->maxImoveis );

    for(int i=0; i<cat->numImoveis; i++){
        aux[i] = cat->imoveis[i];
    }

    free(cat->imoveis);
    cat->imoveis = aux;
}

//Libera o espaco alocado para o catalogo;
void liberaCatalogo(tCatalogo cat){
    free(cat->imoveis);
    free(cat);
}

//Libera os espacos alocados dos Proprietarios de um Catalogo
void liberaProprietariosCatalogo(tCatalogo cat){
    for(int i=0; i<cat->numImoveis; i++){
        liberaProprietario(&cat->imoveis[i]);
    }
}

//Inicializa o Primeiro Imovel, para fins de verificacao de Leitura correta
void inicializaPrimeiroImovel(tCatalogo cat){
    cat->imoveis[0].identificador = 0;
    strcpy(cat->imoveis[0].tipo, "\0");
}

//Leitura de informacoes referentes ao TIPO de Imovel: Terrenos (triangular, retangular ou trapezoidal) ou Imovel (Casa ou Apartamento)
void lerInfoTipo(FILE *file, tCatalogo cat, int i){

    if( !strcmp(cat->imoveis[i].tipo, "triang") ){
        lerTriangular(file, &cat->imoveis[i].categoria.triang);
    }
    else if( !strcmp(cat->imoveis[i].tipo, "retang") ){
        lerRetangular(file, &cat->imoveis[i].categoria.retang);
    }
    else if( !strcmp(cat->imoveis[i].tipo, "trapez") ){
        lerTrapezoidal(file, &cat->imoveis[i].categoria.trapez);
    }
    else if( !strcmp(cat->imoveis[i].tipo, "casa") ){
        lerCasa(file, &cat->imoveis[i].categoria.casa);
    }
    else if( !strcmp(cat->imoveis[i].tipo, "apto") ){
        lerApartamento(file, &cat->imoveis[i].categoria.apto);
    }

    fscanf(file, "\n");
}

//Leitura das informacoes Comuns p/ todos os tipos do Catalogo
void lerInfoImovel(FILE *file, tCatalogo cat, int i){ // i = Numero do imovel a ser lido

    lerTipo(file, &cat->imoveis[i]);
    lerIdentificador(file, &cat->imoveis[i]);

    if(cat->imoveis[i].identificador) //Le o proprietario apenas se conseguir ler o Identificador
        lerProprietario(file, &cat->imoveis[i]);

    fscanf(file, "\n");
}

//Faz a leitura de todos os dados do arquivo "Catalogo.txt"
void lerCatalogo(tCatalogo cat){
    FILE *file;
    int i;

    file = fopen("catalogo.txt", "r");

    if(!file){ //Se o programa nao conseguir ler o arquivo, o programa e encerrado.
        printf("Nao foi possivel abrir o arquivo 'catalogo.txt'. Encerrando o programa.\n");
        exit (1);
    }

    inicializaPrimeiroImovel(cat);

    for(i=0; !feof(file); i++){

        if(obterNumImoveis(cat) == obterMaxImoveis(cat)){
            aumentaCatalogo(cat);
        }

        lerInfoImovel(file, cat, i);
        lerInfoTipo(file, cat, i);

        cat->numImoveis += 1;
    }

    if(!cat->imoveis[0].identificador)//Se o primeiro Identificador nao for lido, entende-se que nao houve leitura alguma.
        cat->numImoveis = 0;

    fclose(file);
}

//Remove um Imovel do Catalogo
void removeImovel(tCatalogo cat, int j){
    free(cat->imoveis[j].proprietario);//Libera o Proprietario alocado.

    for(int i=j; i < cat->numImoveis-1; i++){ //Remove o Identificador copiando todos os itens a frente dele
        cat->imoveis[i] = cat->imoveis[i + 1];
    }

    cat->numImoveis--; //Remove o numero de Imoveis do Catalogo
}

//Faz a leitura de todas as operacoes do arquivo "atual.txt"
void lerOperacoes(tCatalogo cat){
    FILE *file;
    char operacao = '\0';
    char tipoAux[nomeTipo];
    int identAux;

    file = fopen("atual.txt", "r");

    if(!file){ //Se o programa nao conseguir ler o arquivo, o programa e encerrado.
        printf("Nao foi possivel abrir o arquivo 'atual.txt'. Encerrando o programa.\n");
        exit (1);
    }

    while(!feof(file)){
        fscanf(file, "%c\n", &operacao);

        if(operacao == 'i'){ //Inclusao
            if(cat->numImoveis == cat->maxImoveis){
                aumentaCatalogo(cat);
            }
            lerInfoImovel(file, cat, cat->numImoveis);
            lerInfoTipo(file, cat, cat->numImoveis);
            cat->numImoveis+=1; //Adiciona mais um item no catalogo
        }
        else if(operacao == 'e'){ //Exclusao
            fscanf(file, "%d\n", &identAux); //Leitura do identificador a ser excluido

            for(int i=0; i < cat->numImoveis; i++){ //Busca pelo Identificador no Catalogo
                if(obterIdentificador(cat, i) == identAux){
                    removeImovel(cat, i); //Quando encontra o Identificador, ele e removido do Catalogo
                }
            }

            fscanf(file, "\n");
        }
        else if(operacao == 'a'){ //Alteracao
            fscanf(file, "%s\n", tipoAux); //Leitura do tipo a ser alterado
            fscanf(file, "%d\n", &identAux); //Leitura do Identificador a ser alterado

            for(int i=0; i < cat->numImoveis; i++){
                if(obterIdentificador(cat, i) == identAux){ //Busca o Identificador no Catalogo para alterar suas informacoes
                    strcpy(cat->imoveis[i].tipo, tipoAux); //Faz a copia do tipo lido para o tipo do imovel do catalogo
                    fscanf(file, "%[^\n]\n", cat->imoveis[i].proprietario); //Faz a leitura do proprietario alterado
                    lerInfoTipo(file, cat, i);
                }
            }
        }
    }

    fclose(file);
}

//Retorna numero de Imoveis de um Catalogo
int obterNumImoveis(tCatalogo cat){
    return cat->numImoveis;
}

//Retorna numero Maximo de Imoveis que um Catalogo pode ter
int obterMaxImoveis(tCatalogo cat){
    return cat->maxImoveis;
}

//Retorna identificador de um Imovel do Catalogo
int obterIdentificador(tCatalogo cat, int i){
    return cat->imoveis[i].identificador;
}

//Retorna o tipo do Imovel
char* obterTipo(tCatalogo cat, int i){
    return cat->imoveis[i].tipo;
}

//Retorna o tipo de Solo para os Terrenos
char obterTipoSolo(tCatalogo cat, int i){
    if( !strcmp(cat->imoveis[i].tipo, "triang") ){
        return cat->imoveis[i].categoria.triang.solo;
    }
    else if( !strcmp(cat->imoveis[i].tipo, "retang") ){
        return cat->imoveis[i].categoria.retang.solo;
    }
    else if( !strcmp(cat->imoveis[i].tipo, "trapez") ){
        return cat->imoveis[i].categoria.trapez.solo;
    }
    return '\0';
}

//Retorna preco de um imovel
float obterPreco(tCatalogo cat, int i){
    return cat->imoveis[i].preco;
}

//Retorna um Imovel especifico
tImovel obterImovel(tCatalogo cat, int i){
    return cat->imoveis[i];
}

//Define um Imovel especifico
void definirImovel(tCatalogo cat, tImovel im, int i){
    cat->imoveis[i] = im;
}

//Aumenta qtd de imoveis de um Catalogo
void acrescentarNumImoveis(tCatalogo cat, int i){
    cat->numImoveis += i;
}

//Adiciona o Preco a todos os Imoveis
void adicionarPreco(tCatalogo cat){

    for(int i=0; i < cat->numImoveis; i++){
        if( !strcmp(obterTipo(cat, i), "triang") ){//Se for triangulo, acessa a opcao triangulo
            cat->imoveis[i].preco = calculaPrecoTriangular(&cat->imoveis[i].categoria.triang);
        }
        else if( !strcmp(obterTipo(cat, i), "retang") ){//Se for retangulo, acessa a opcao retangulo
            cat->imoveis[i].preco = calculaPrecoRetangular(&cat->imoveis[i].categoria.retang);
        }
        else if( !strcmp(obterTipo(cat, i), "trapez") ){//Se for trapezio, acessa a opcao trapezio
            cat->imoveis[i].preco = calculaPrecoTrapezoidal(&cat->imoveis[i].categoria.trapez);
        }
        else if( !strcmp(obterTipo(cat, i), "casa") ){//Se for casa, acessa a opcao casa
            cat->imoveis[i].preco = calculaPrecoCasa(&cat->imoveis[i].categoria.casa);
        }
        else if( !strcmp(obterTipo(cat, i), "apto") ){//Se for apartamento, acessa a opcao apartamento
            cat->imoveis[i].preco = calculaPrecoApartamento(&cat->imoveis[i].categoria.apto);
        }
    }
}

//Adiciona a Area de Todos os imoveis
void adicionarAreas(tCatalogo cat){
    for(int i=0; i<obterNumImoveis(cat); i++){
        cat->imoveis[i].area = calculaArea(cat->imoveis[i]);
    }
}

//Ordenacao do Catalogo de acordo com a funcao passada
void ordenarCatalogo(tCatalogo cat, int (*troca)(tImovel *, tImovel *) ){
    tImovel aux;

    for(int i=0; i < cat->numImoveis - 1; i++){
        for(int j=0; j < cat->numImoveis - 1; j++){
            if(troca(&cat->imoveis[j], &cat->imoveis[j + 1])){
                aux = cat->imoveis[j];
                cat->imoveis[j] = cat->imoveis[j + 1];
                cat->imoveis[j + 1] = aux;
            }
        }
    }
}