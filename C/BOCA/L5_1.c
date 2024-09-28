#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 int main(){
    int n, i, notas, menor = 100, maior = 0, qtdAcima = 0, reprovados = 0;
    float soma = 0, media, desvio = 0, somatorio = 0, y = 0;
    
    scanf("%d", &n);

    int vetNotas[n];

    for(i=0; i<n; i++){
        scanf("%d", &notas);
        vetNotas[i] = notas;

        if(notas < menor)
        menor = notas;

        if(notas > maior)
        maior = notas;
    }

    //Media
    for(i=0; i<n; i++){
        soma += vetNotas[i];
    }
    media = soma/n;

    //Qtd Acima da Media
    for(i=0; i<n; i++){
        if(vetNotas[i] > media)
        qtdAcima++;
    }

    //Reprovados
    for(i=0; i<n; i++){
        if(vetNotas[i] < 70)
        reprovados++;
    }

    //Desvio Padrão
    for(i=0; i<n; i++){
        y = pow(vetNotas[i] - media, 2);
        somatorio += y;
    }
    somatorio /= n;
    desvio = sqrt(somatorio);
    
     printf("MENOR:%d, MAIOR:%d, MEDIA:%.2f, STD:%.2f, ACIMA_MEDIA_CONC:%d, REPROV:%d", menor, maior, media, desvio, qtdAcima, reprovados);

     return 0;
 }



