#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	int n1, n2, n3, CM, rCM, DM, rDM, UM, rUM, C1, C2, C3, menor;
	scanf("%d %d %d", &n1, &n2, &n3);
	
	CM = n1/100000;
	rCM = n1%100000;
	DM = rCM/10000;
	rDM = rCM%10000;
	UM = rDM/1000;
	rUM = rDM%1000;
	C1 = rUM/100;

	CM = n2/100000;
	rCM = n2%100000;
	DM = rCM/10000;
	rDM = rCM%10000;
	UM = rDM/1000;
	rUM = rDM%1000;
	C2 = rUM/100;

	CM = n3/100000;
	rCM = n3%100000;
	DM = rCM/10000;
	rDM = rCM%10000;
	UM = rDM/1000;
	rUM = rDM%1000;
	C3 = rUM/100;

	if(C1 == 0 && C2 == 0 && C3 == 0)
		printf("Nenhum");

	if(C1 == 0)
		C1 = 99;
	if(C2 == 0)
		C2 = 99;
	if(C3 == 0)
		C3 = 99;

	menor = C1;

	if(C2 < menor)
		menor = C2;
	if(C3 < menor)
		menor = C3;

	if(menor == C1 && C1 != 99)
		printf("N1");
	else if(menor == C2 && C2 != 99)
		printf("N2");
	else if(menor == C3 && C3 != 99)
		printf("N3");

	return 0;
}
