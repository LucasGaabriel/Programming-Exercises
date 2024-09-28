#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include "MonitorBanheiro.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_corintianos = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_palmeirenses = PTHREAD_COND_INITIALIZER;

int corintianos_banheiro = 0;
int palmeirenses_banheiro = 0;

#define CAPACIDADE_MAX 3

void corintianoQuerEntrar() {
    // Bloqueia acesso a região critica (Variável corintianos_banheiro)
    pthread_mutex_lock(&mutex);
    while (palmeirenses_banheiro > 0 || corintianos_banheiro == CAPACIDADE_MAX) {
        // Espera a condição ser sinalizada ou transmitida
        pthread_cond_wait(&cond_corintianos, &mutex);
    }
    corintianos_banheiro++;
    printf("Entrou um corintiano. Corintianos: %d, Palmeirenses: %d\n", corintianos_banheiro, palmeirenses_banheiro);
    // Libera acesso a região critica (Variável corintianos_banheiro)
    pthread_mutex_unlock(&mutex);
}

void corintianoSai() {
    // Bloqueia acesso a região critica (Variável corintianos_banheiro)
    pthread_mutex_lock(&mutex);
    corintianos_banheiro--;
    printf("Saiu um corintiano. Corintianos: %d, Palmeirenses: %d\n", corintianos_banheiro, palmeirenses_banheiro);
    // Acorda as threads esperando por uma condição
    pthread_cond_broadcast(&cond_palmeirenses);
    // Libera acesso a região critica (Variável corintianos_banheiro)
    pthread_mutex_unlock(&mutex);
}

void palmeirenseQuerEntrar() {
    // Bloqueia acesso a região critica (Variável palmeirenses_banheiro)
    pthread_mutex_lock(&mutex);
    while (corintianos_banheiro > 0 || palmeirenses_banheiro == CAPACIDADE_MAX) {
        // Espera a condição ser sinalizada ou transmitida
        pthread_cond_wait(&cond_palmeirenses, &mutex);
    }
    palmeirenses_banheiro++;
    printf("Entrou um palmeirense. Corintianos: %d, Palmeirenses: %d\n", corintianos_banheiro, palmeirenses_banheiro);
    // Libera acesso a região critica (Variável palmeirenses_banheiro)
    pthread_mutex_unlock(&mutex);
}

void palmeirenseSai() {
    // Bloqueia acesso a região critica (Variável palmeirenses_banheiro)
    pthread_mutex_lock(&mutex);
    palmeirenses_banheiro--;
    printf("Saiu um palmeirense. Corintianos: %d, Palmeirenses: %d\n", corintianos_banheiro, palmeirenses_banheiro);
    // Acorda as threads esperando por uma condição
    pthread_cond_broadcast(&cond_corintianos);
    // Libera acesso a região critica (Variável palmeirenses_banheiro)
    pthread_mutex_unlock(&mutex);
}
