/*lab4-count-character.c
Author: Petra Sartori*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int counter(char* s, char* c);

int main(int argc, char * argv[])
{
    /*Reading from input: first argument is a string we're searching through
    second argument is the character we're looking for*/
    char* c = argv[1];
    char* s = argv[2];
    
    int count = counter(s, c); // Calling the counter function and passing the 2 arguments
    printf("%d\n", count); // Printing the output


    return 0;

}

/*Counter function which takes a string and a character and returns the number
of times the character appears in the string*/
int counter(char* s, char* c){

    int count = 0;
    char *ps = s; // A pointer that moves through the string s

    // Strchr looks for a specified character in a string, starting at ps
    // Loop goes on as long as the character found is not NULL
    while((ps = strchr(ps, *c)) != NULL)
    {
        ++count; // Increment the count
        ++ps; // Moving past the character and looking for the next one
    }

    return count;
}
