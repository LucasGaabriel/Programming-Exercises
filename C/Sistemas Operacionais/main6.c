#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int s=0;

static void sig_quit(int sig){
    printf("\nIn sig_quit, s=%d. Now sleeping...\n", ++s);
    sleep(10);
    printf("\nSig_quit, s=%d: Exiting!\n", s);
}

static void sig_int(int sig){
    printf("\nNow in sig_int, s=%d. Returning Immediately!\n", ++s);
}

int main(){
    printf("Establishing signal handlers via signal.\n");
    if(signal(SIGQUIT, sig_quit) == SIG_ERR){
        fprintf(stderr, "can't set signal handler.\n");
        exit(EXIT_FAILURE);
    }

    if(signal(SIGINT, sig_int) == SIG_ERR){
        fprintf(stderr, "can't set signal handler.\n");
        exit(EXIT_FAILURE);
    }

    sleep(60);

    printf("\nTime for a second interruption.\n");
    sleep(60);

    printf("\nNow exiting.\n");

    return 0;
}