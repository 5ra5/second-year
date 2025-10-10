/*lab4-search-sub-string.c
Author: Petra Sartori*/

#include <stdio.h>
#include <string.h>

int search_sub(char *s, char *sub, int *start, int *end);

int main(int argc, char *argv[]){

    int start, end; // Storing the first and last positions of the sub-string
    // Calling the function, argv[1] and argv[2] are strings we're working with
    int found = search_sub(argv[1], argv[2], &start, &end);
    
    // Printing the start and end index if the sub-string is found
    if (found){
        printf("%d %d\n", start, end);
    }

    return 0;
}

/*Function search_sub which takes a string and a smaller string and determines
whether the smaller string is a sub-string od a bigger one*/
int search_sub(char *s, char *sub, int *start, int *end){

    // s is the string we're searching in, sub is the string we're searching for
    char *found = strstr(s, sub);

    // If the sub-string is found:
    if (found != NULL){
        *start = found - s; // found - s = n of char between the start of s and start of sub
        *end = *start + strlen(sub) - 1; // start + length of sub - 1
        // Since functions can return only one value, we return 1 if sub-string is found
        return 1;
    } else {
        return 0;
    }
}

