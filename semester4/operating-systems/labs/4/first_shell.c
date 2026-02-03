#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    char s[51];
    strncpy(s, argv[1], 50);

    if (strcmp(s, "clr") == 0){
        system("clear");
    }
    return 0;
}