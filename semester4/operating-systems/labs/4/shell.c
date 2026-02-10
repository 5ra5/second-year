#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

int main(int argc, char *argv[]){
    char input[MAX_INPUT];
    char* args[MAX_ARGS];

    while(1) {
        printf("$ ");
        fflush(stdout);

        if(fgets(input, MAX_INPUT, stdin) == NULL) {
            perror("fail\n");
            continue;
        }

        input[strcspn(input, "\n")] = '\0';

        if(strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        if(strcmp(input, "clr") == 0) {
            system("clear");
            continue;
        }

        char* token = strtok(input, " ");
        int i = 0;

        while (token != NULL && i < MAX_ARGS) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }

        args[i] = NULL;

        pid_t pid = fork();

        if (pid == 0) {
            execvp(args[0], args);
            perror("execvp failed!\n");
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            int status;
            waitpid(pid, &status, 0);
            printf("Exit status: %d\n", status);
        } else {
            perror("fork failed!");
        }

        printf("%s\n", input);
    }
    return 0;
}