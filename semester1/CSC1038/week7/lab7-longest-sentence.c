// lab7-longest-sentence.c
// Petra Sartori

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
void read_input(int n, char *argv[], char **strings);
int longest(int n, char **strings);

// main function
int main(int argc, char*argv[]){
    
    int n = argc - 1;

    char **strings = malloc(n * sizeof(char*));

    if (!strings) {
        printf("Memory allocation fail");
        return 1;
    }

    read_input(n, argv, strings);
    
    int longest_len = longest(n, strings);

    // if there are multiple largest strings
    for(int i = 0; i < n; i++){
        if(strlen(strings[i]) == longest_len) {
            printf("%s\n", strings[i]);
        }
    }


    // releasing the memory for each string individually first
    for(int i = 0; i < n; i++){
        free(strings[i]);
    }

    free(strings);

    return 0;
}

// function read_input that takes input from command line and
// puts it in an array of strings using malloc()
void read_input(int n, char *argv[], char **strings){

    for (int i = 0; i < n; i++){
       strings[i] = malloc(strlen(argv[i + 1]) + 1);
       if (!strings[i]){
        printf("Memory allocation fail");
        break;
       }
       strcpy(strings[i], argv[i + 1]);
    }
}

// function longest that finds the longest word in a string array
int longest(int n, char **strings){
    
    int longest = 0;

    for(int i = 1; i < n; i++){
        int len = strlen(strings[i]);
        if(len > longest){
            longest = len;
        }
    }
    return longest;
}