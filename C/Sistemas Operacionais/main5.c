#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void trata_signal(int num) {
    printf("Operação negada.");
    signal(SIGINT, trata_signal);
    // exit(1);
}

int main(void) {
    printf("OIII\n\n");

    if (signal(SIGINT, trata_signal) == SIG_ERR){
        printf("Erro no signal");
    }

    for (;;) {
        sleep(10);
    }

    exit(0);
}