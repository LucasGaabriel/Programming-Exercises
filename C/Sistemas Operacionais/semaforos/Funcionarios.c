#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include "MonitorBanheiro.h"

#define NUM_MAX 10

void* thread_corintiano(void* arg) {
    int* id = (int*)arg; // Converte o argumento para um inteiro
    while (true) {
        corintianoQuerEntrar();
        printf("Eu sou corintiano-%d: ... UFA! Entrei no banheiro!\n", *id);
        sleep(3);
        corintianoSai();
        printf("Eu sou corintiano-%d: ... Estou aliviado! Vou trabalhar!\n", *id);
        sleep(5);
    }
}

void* thread_palmeirense(void* arg) {
    int* id = (int*)arg; // Converte o argumento para um inteiro
    while (true) {
        palmeirenseQuerEntrar();
        printf("Eu sou palmeirense-%d: ... UFA! Entrei no banheiro!\n", *id);
        sleep(3);
        palmeirenseSai();
        printf("Eu sou palmeirense-%d: ... Estou aliviado! Vou trabalhar!\n", *id);
        sleep(5);
    }
}

int main() {
    pthread_t corintianos[NUM_MAX];
    pthread_t palmeirenses[NUM_MAX];
    int i, id[NUM_MAX];

    // Inicialização dos identificadores
    for(i=0; i<NUM_MAX; i++){
        id[i] = i+1;
    }

    // Criar threads dos corintianos
    for(i=0; i<NUM_MAX; i++){
        if (pthread_create(&corintianos[i], NULL, &thread_corintiano, &id[i]) != 0) {
            perror("Erro ao criar a thread do corintiano.");
            exit(EXIT_FAILURE);
        }
    }

    // Criar threads dos palmeirenses
    for(i=0; i<NUM_MAX; i++){
        if (pthread_create(&palmeirenses[i], NULL, &thread_palmeirense, &id[i]) != 0) {
            perror("Erro ao criar a thread do palmeirense.");
            exit(EXIT_FAILURE);
        }
    }

    // Aguardar o término das threads corintianos
    for(i=0; i<NUM_MAX; i++){
        if (pthread_join(corintianos[i], NULL) != 0) {
            perror("Erro no join de corintiano.");
            exit(EXIT_FAILURE);
        }
    }

    // Aguardar o término das threads palmeirenses
    for(i=0; i<NUM_MAX; i++){
        if (pthread_join(palmeirenses[i], NULL) != 0) {
            perror("Erro no join de palmeirense.");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
