#include <stdio.h>

struct aluno {
char nome[81];
char matricula[8];
char turma;
float p1;
float p2;
float p3;
};
typedef struct aluno Aluno;

void imprime_aprovados (int n, Aluno* turma){
    int i;

    for(i=0; i<n; i++){
        if(((turma[i].p1+turma[i].p2+turma[i].p3)/3) > 7){
            printf("Mat: %s, Nome: %s, Turma: %c, MF: %.2f\n", turma[i].matricula, turma[i].nome, turma[i].turma, (turma[i].p1+turma[i].p2+turma[i].p3)/3 );
        }
    }
}

void main(){
    
}