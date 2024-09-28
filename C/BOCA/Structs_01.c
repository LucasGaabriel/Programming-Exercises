#include <stdio.h>

/* 
   Racional de qualquer numero da forma p/q, sendo p inteiro e q inteiro nao nulo. Vamos
   convencionar que o campo q de todo racional eh estritamente positivo e que o maximo 
   divisor comum dos campos p e q eh 1.   
*/

typedef struct {
   int p, q;
} racional;

/* INSIRA SEU CODIGO AQUI, CASO DESEJE CRIAR ALGUMA FUNCAO AUXILIAR */



/* Recebe inteiros a e b e devolve o racional que representa a/b */
racional reduz (int a, int b) {
   racional x;
   int i, menor, negativoA = 0, negativoB = 0;
   
   if(a < 0){
      negativoA = 1;
      a = -a;
   }
   if(b < 0){
      negativoB = 1;
      b = -b;
   }

   menor = a;

   if(b < menor){
      menor = b;
   }

   for(i=2; i<=menor; i++){
      if( (a%i == 0) && (b%i == 0) ){
         a = a/i;
         b = b/i;
      }
   }
	
if( (negativoA == 1 && negativoB == 1) || (negativoA == 0 && negativoB == 0) ){
   x.p = a;
   x.q = b;
}
else{
   x.p = -a;
   x.q = b;
}

   return x;
}

void main(){
   racional x;
   int a, b;
   
   scanf("%d %d", &a, &b);

   x = reduz(a, b);

   printf("%d/%d", x.p, x.q);

}
