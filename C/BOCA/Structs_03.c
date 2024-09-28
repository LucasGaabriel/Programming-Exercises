#include <stdio.h>

/* 
   Racional de qualquer numero da forma p/q, sendo p inteiro e q inteiro nao nulo. Vamos
   convencionar que o campo q de todo racional eh estritamente positivo e que o maximo 
   divisor comum dos campos p e q eh 1.
*/

typedef struct {
   int p, q;
} racional;

/* INSIRA SEU CODIGO AQUI, CASO PRECISE CRIAR ALGUMA FUNCAO AUXILIAR */

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

int mmc(int a, int b){
   int i;

   if(a > 0 && b > 0){
      for(i=1; (i%a != 0) || (i%b != 0); i++);
   }
   else{

   }

   return i;
}

/* Recebe os racionais x e y e devolve o racional que representa a soma de x e y */
racional soma (racional x, racional y) {
	racional rSoma;
   int numMmc;

   if(x.q < 0){
      x.p = -x.p;
      x.q = -x.q;
   }
   if(y.q < 0){
      y.p = -y.p;
      y.q = -y.q;
   }

   if(x.q == y.q){
      rSoma.p = x.p + y.p;
      rSoma.q = x.q;
   }
   else{
      numMmc = mmc(x.q, y.q);

      rSoma.p = ((numMmc/x.q)*x.p) + ((numMmc/y.q)*y.p);
      rSoma.q = numMmc;
   }

   rSoma = reduz(rSoma.p, rSoma.q);
	
	return rSoma;
}

void main(){
   racional x, y, rSoma;

   scanf("%d %d %d %d", &x.p, &x.q, &y.p, &y.q);

   rSoma = soma(x, y);

   printf("%d/%d", rSoma.p, rSoma.q);
}
