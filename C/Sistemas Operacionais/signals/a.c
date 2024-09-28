#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char* argv[]) {
    printf("Vou dormir infinitamente!\n");
    sleep(999999);
    exit(0);
}