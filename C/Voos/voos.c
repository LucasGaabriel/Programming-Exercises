#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5
#define M 50

typedef struct {
    int num;
    char origem[N];
    char destino[N];
    char companhia[N];
    int conexoes;
    float tarifa1;
    float tarifa2;
    float tarifa3;
    float media;
} voo;

int preencheVetor(FILE *arquivo, voo v[]){
    int numVoos, i;

    arquivo = fopen("voos.txt", "r");

    fscanf(arquivo,"%d", &numVoos);

    for(i=0; i<numVoos; i++){
        fscanf(arquivo,"%d", &v[i].num);
        fscanf(arquivo,"%s %s %s", v[i].origem, v[i].destino, v[i].companhia);
        fscanf(arquivo,"%d", &v[i].conexoes);
        fscanf(arquivo,"%f %f %f", &v[i].tarifa1, &v[i].tarifa2, &v[i].tarifa3);
    }

    fclose(arquivo);

    return numVoos;
}

void saida(FILE *arquivo, int nVoos, char origemVoo[], voo v[], voo voosOrigem[]){
    int i, j, k, menorConexao, menorVoo;
    float soma = 0, media;
    voo aux[M];

    for(i=0, j=0; i<nVoos; i++){
        if(strcmp(v[i].origem, origemVoo) == 0){
            voosOrigem[j] = v[i];

            j++;
        }
    }

    arquivo = fopen("melhores-tarifas.txt", "w");

    fprintf(arquivo,"Codigo fornecido: %s\n", origemVoo);

    if(j > 0){

        for(i=0; i<j; i++){
            soma = 0;
            soma += voosOrigem[i].tarifa1;
            soma += voosOrigem[i].tarifa2;
            soma += voosOrigem[i].tarifa3;
            media = soma/3;

            voosOrigem[i].media = media;
        }

        for(k=0; k<j; k++){
            for(i=0; i<j-1; i++){
                if(voosOrigem[i].media > voosOrigem[i+1].media){
                    aux[i] = voosOrigem[i];
                    voosOrigem[i] = voosOrigem[i+1];
                    voosOrigem[i+1] = aux[i];
                }
            }
        }

        for(i=0; i<j; i++){
            fprintf(arquivo,"%d %s %s %d %.2f\n", voosOrigem[i].num, voosOrigem[i].destino, voosOrigem[i].companhia, voosOrigem[i].conexoes, voosOrigem[i].media);
        }

        menorConexao = voosOrigem[0].conexoes;
        menorVoo = voosOrigem[0].num;

        for(i=0; i<j; i++){
            if(voosOrigem[i].conexoes < menorConexao){
                menorConexao = voosOrigem[i].conexoes;
                menorVoo = voosOrigem[i].num;
            }
        }

        fprintf(arquivo,"Melhor voo: numero %d com %d conexao.", menorVoo, menorConexao);

    }
    else{
        fprintf(arquivo,"Essa companhia aerea nao realiza voos partindo dessa origem!");
    }

    fclose(arquivo);
}

int main(){
    voo v[M], voosOrigem[M];
    FILE *arquivo;
    char origemVoo[N];
    int nVoos;

    nVoos = preencheVetor(arquivo, v);

    scanf("%s", origemVoo);

    saida(arquivo, nVoos, origemVoo, v, voosOrigem);

    return 0;
}