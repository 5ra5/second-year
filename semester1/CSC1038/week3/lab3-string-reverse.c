/*lab3-string-reverse.c
Author: Petra Sartori*/

/*Including input/output and string library*/
#include <stdio.h>
#include <string.h>

/*Function reverse that takes a string from input and returns the letters
in the reversed order*/

void reverse(char s[], int len) {
    int start = 0;
    int end = len - 1;
    char temp;

    // Swapping letters
    while (start < end){
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

int main(int argc, char *argv[]){

    char s[51]; // Storing the input of maximum 50 letters (51 in brackets to account for /0)
    strncpy(s, argv[1], 50); // Reading input
    s[50] = '\0';
    int len = strlen(s); //Getting length of the string

    
    reverse(s, len); // Calling the reverse function
    
    printf("%s\n", s); // Printing the output

    return 0;
}
 