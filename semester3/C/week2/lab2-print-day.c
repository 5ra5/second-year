#include <stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{
    //Setting up an array containing names of days of the week
    //Index is the number of the day of the week
    // There is 7 strings, each can hold up to 10 characters
    char days[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int index = atoi(argv[1]);

    /*Printing the day that corresponds with the
    index given in the input*/
    // index - 1 is used to avoid Sunday being at index 0
    printf("%s\n", days[index - 1]);

    return 0;
}