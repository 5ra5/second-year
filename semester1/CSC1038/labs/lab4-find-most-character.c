#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostFrequent(char *string);

int main(int argc, char *argv[])
{
    char string[50];
    strcpy(string, argv[1]);

    mostFrequent(string);

}

void mostFrequent(char *string)
{
    // set every value of the int array to 0
    int count[256] = {0};
    int max = 0;
    char maxChar;
    int length = strlen(string);

    // traverse the string
    for(int i = 0; i < length; i++)
    {
        // increment the count of each character of the string
        count[(int)string[i]]++;
    }

    for(int i = 0; i < length; i++)
    {
        if(count[(int)string[i]] > max)
        {
            max = count[(int)string[i]];
            maxChar = string[i];
        }
    }

    printf("%c\n", maxChar);
}