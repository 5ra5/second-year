// ex1-is-symmetric.c
// Petra Sartori

/*This program takes a string from the command line and checks whether the string
is symmetric or not by comparing its first and last characters iteatively*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype of is_symmetric
int is_symmetric(char s[], int len);

// main function which initializes the array I'm keeping the string in
// It also outputs the final message after calling a is_symmetric() function
int main(int argc, char *argv[]){

    char s[50];
    strcpy(s, argv[1]);
    int len = strlen(s);
    int symmetric = is_symmetric(s, len);
    if(symmetric == 0){
        printf("no\n");
    }else{
        printf("yes\n");
    }
    
    return 0;
}

// is_symmetric function which takes a string and iteratively checks if
// the character from the front of the string matches a character from the back of the string
int is_symmetric(char s[], int len){

   for(int i = 0; i < len / 2; i++){
        if(s[i] != s[len - 1 - i]){
            return 0; // not symmetric
        }
    }

   return 1; //symmetric
}

