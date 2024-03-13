#include <stdio.h>
#include <stdlib.h>

#define N 50

int preencheMatriz(FILE *arquivo, int tam, int matriz[][N]){
    int i, j;

    arquivo = fopen("quadmagic.txt", "r");

    fscanf(arquivo,"%d", &tam);

    for(i=0; i<tam; i++){
        for(j=0; j<tam; j++){
            fscanf(arquivo,"%d", &matriz[i][j]);
        }
    }

    fclose(arquivo);

    return tam;
}

int quadradomagico(int tam, int matriz[][N]){
    int i, j, numMagic = 0, soma = 0, ok = 0;

    for(i=0; i<tam; i++){
        numMagic += matriz[0][i];
    }

    for(i=0; i<tam; i++){
        soma = 0;
        for(j=0; j<tam; j++){
            soma += matriz[i][j];
        }
        if(soma == numMagic)
            ok++;
    }

    for(i=0; i<tam; i++){
        soma = 0;
        for(j=0; j<tam; j++){
            soma += matriz[j][i];
        }
        if(soma == numMagic)
            ok++;
    }

    soma = 0;
    for(i=0, j=0; i<tam; i++, j++){
        soma += matriz[i][j];
    }
    if(soma == numMagic)
        ok++;

    soma = 0;
    for(i=0, j=tam-1; j>=0; i++, j--){
        soma += matriz[i][j];
    }
    if(soma == numMagic)
        ok++;

    if(ok == tam*2+2)
        return 1;
    else
        return 0;    

}

void imprimeMatriz(int ok, int tam, int matriz[][N]){
    int i, j;
    
    if(ok == 1){
        printf("A matriz eh quadrado magico\n");
        for(i=0; i<tam; i++){
            for(j=0; j<tam; j++){
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("A matriz nao eh quadrado magico\n");
        for(i=0; i<tam; i++){
            for(j=0; j<tam; j++){
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }
    }

}

int main(){
    FILE *arquivo;
    int tamMatriz, matriz[N][N], ok;

    tamMatriz = preencheMatriz(arquivo, tamMatriz, matriz);

    ok = quadradomagico(tamMatriz, matriz);

    imprimeMatriz(ok, tamMatriz, matriz);

    return 0;
}