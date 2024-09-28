#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char* argv[]) {
    printf("Vou dormir por 5 segundos!\n");
    sleep(5);
    printf("Acordei! Vou encerrar!\n");
    exit(0);
}