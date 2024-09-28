// Trabalho 1
// Sistemas Operacionais
//
// -- Alunos --
// Daniel Siqueira de Oliveira
// Heitor Felix Lopes
// Lucas Gabriel de Oliveira Costa

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_COMMANDS 5
#define MAX_COMMAND_ARGS 3
#define MAX_COMMANDS_LENGTH 100

bool foreground = false;
int nProcess = 0;

void handle_sig(int sig) {
    if(sig == 2)
        printf("\nNão adianta me enviar o sinal por Ctrl-C. Estou vacinado!!”.\n");
    else if(sig == 3)
        printf("\nNão adianta me enviar o sinal por Ctrl-\\. Estou vacinado!!”.\n");
    else if(sig == 20)
        printf("\nNão adianta me enviar o sinal por Ctrl-Z. Estou vacinado!!”.\n");
    else if(sig == SIGUSR1){
        printf("Signal SIGUSR1 recebido. Encerrando todo o grupo.\n");
        killpg(getpid(), SIGKILL);
    }
}

void execute_command(char* command) {

    // Guarda o comando e os argumentos separados
    char *args[MAX_COMMAND_ARGS+3];
    int i = 0;
    char *token = strtok(command, " ");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    
    args[i] = NULL; // Argumentos devem terminar com NULL

    // Executa o comando usando o execvp()
    execvp(args[0], args);
    
    // Se o execvp() retornar, significa que houve um erro
    perror("Erro ao executar o execvp().\n");
    exit(EXIT_FAILURE);
}

int main() {
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = &handle_sig;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGTSTP, &sa, NULL);
    sigaction(SIGQUIT, &sa, NULL);
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGUSR1, &sa, NULL);

    pid_t leaderPid = 0;
    int status;

    char line[MAX_COMMANDS_LENGTH];

    while (true) {
        printf("acsh> ");
        fgets(line, sizeof(line), stdin);

        // Ignora comandos vazios (apenas com o caractere de nova linha)
        if (line[0] == '\n') {
            continue;
        }

        // Adiciona caractere de final de string no lugar do '\n'
        line[strcspn(line, "\n")] = '\0';

        if(line[strlen(line)-1] == '%') {
            foreground = true;
            line[strlen(line)-1] = '\0';
        } else {
            foreground = false;
        }

        // Verifica se o comando é um comando interno do shell
        if (strcmp(line, "exit") == 0) {
            // Termina todos os processos em background antes de terminar a execucao do acsh
            kill(0, SIGUSR1);
            exit(0);
        } else if (strncmp(line, "cd ", 3) == 0) {
            // Muda o diretorio atual usando chdir()
            char *path = line + 3;
            chdir(path);
        } else {
            // // Guarda os comandos em um ponteiro para strings
            char *commands[MAX_COMMANDS];
            int nProcess = 0;
            char *token = line;
            char *found;

            while ((found = strstr(token, "<3")) != NULL) {
                *found = '\0';  // Substitui "<3" por um caractere nulo para separar a string
                commands[nProcess++] = token;
                token = found + 2;  // Avança para o próximo token após "<3"
            }

            if (*token != '\0') {
                commands[nProcess++] = token;
            }

            // Cria o processo Lider (Primeiro filho)
            leaderPid = fork();

            if (leaderPid < 0) { // Erro
                fprintf(stderr, "Falha ao criar primeiro processo filho.\n");
                return 1;
            } else if (leaderPid == 0) {
                // Cria uma sessão para o primeiro 
                // filho, caso estiver em background
                if(!foreground) {
                    if (setpgid(0, 0) < 0) {
                        fprintf(stderr, "Falha ao criar o grupo.\n");
                        return 1;
                    }
                }

                char *command = commands[0]; 
                execute_command(command);
                exit(EXIT_FAILURE);

            } else {
                if(foreground) {
                    /* Muda o handler pois quando em foreground o
                    /  principal deve ignorar os sinais de teclado. */
                    sa.sa_handler = SIG_IGN;
                    sigaction(SIGTSTP, &sa, NULL);
                    sigaction(SIGQUIT, &sa, NULL);
                    sigaction(SIGINT, &sa, NULL);
                    sigaction(SIGUSR1, &sa, NULL);
                    waitpid(leaderPid, NULL, 0); // Espera pelo filho, bloqueando o pai (foreground)

                    // Volta a tratar os sinais de teclado
                    sa.sa_handler = &handle_sig;
                    sigaction(SIGTSTP, &sa, NULL);
                    sigaction(SIGQUIT, &sa, NULL);
                    sigaction(SIGINT, &sa, NULL);
                    sigaction(SIGUSR1, &sa, NULL);
                } else {
                    // Quando o filho estiver em background, o acsh deve continuar
                    // executando comandos, para isso usamos a macro 'WNOHANG'.
                    waitpid(leaderPid, &status, WNOHANG); // Espera pelo filho, sem bloquear o pai (background)
                    if (WIFSIGNALED(status) && WTERMSIG(status) == SIGUSR1) {
                        kill(leaderPid, SIGUSR1);
                    }
                }
            }

            /* Cria os outros processos, estarão
            /  em background como pede a especificação. */
            for (int j = 1; j < nProcess; j++) {
                char *command = commands[j];    

                pid_t pid = fork();

                if(pid < 0){ // Erro
                    perror("Erro ao criar novo processo.\n");
                    exit(EXIT_FAILURE);
                }
                else if(pid == 0){ // Filho
                    // Verificação de segurança
                    if(!foreground)
                        setpgid(0, leaderPid);

                    execute_command(command);
                    exit(EXIT_FAILURE);
                }
                else { // Pai
                    /* Quando tiver mais de 1 comando eles
                    / serão executados em background */
                    waitpid(pid, NULL, WNOHANG); // Espera pelo filho, sem bloquear o pai (background)
                    if (WIFSIGNALED(status) && WTERMSIG(status) == SIGUSR1) {
                        kill(leaderPid, SIGUSR1);
                    }
                }
            }

            for(int i=0; i<nProcess; i++){
                // Como os processos rodam em background, precisa de um wait para nao criar processos zumbis
                waitpid(-1, NULL, WNOHANG);
            }

            // Dorme por 1 seg, só pra garantir a execução correta dos processos
            // Removendo isso, o printf("acsh> ") pode ser exibido antes de terminar a execucao de um comando
            // Mesmo que esse comando seja um simples 'ls'
            sleep(1);
        }
    }

    return 0;
}