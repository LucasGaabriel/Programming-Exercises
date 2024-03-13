#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

int main() {
    int n, r;

    srand(time(NULL));

    Arvore* arvore = criarArvoreVazia();

//    printf("Digite um numero N de chaves para gerar: ");
//    scanf("%d", &n);

    n = 1000000;

    for(int i=0; i<n; i++){
        r = rand();
        arvore = inserirChave(arvore, r);
    }

    printf("Altura da Arvore: %d\n", alturaBST(arvore));

    liberarArvore(arvore);

    return 0;
}
