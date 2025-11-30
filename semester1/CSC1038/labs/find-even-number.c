#include <stdio.h>
#include <stdlib.h>

void findEven(int *numbers, int length);

int main(int argc, char *argv[])
{
    int length = argc - 1;
    int numbers[length];

    for(int i = 0; i < length; i++)
    {
        numbers[i] = atoi(argv[i+1]);
    }

    findEven(numbers, length);

    return 0;
}


void findEven(int *numbers, int length)
{
    for(int i = 1; i < length; i++)
    {
        if(numbers[i] % 2 == 0)
        {
            printf("%d - %d\n", i, numbers[i]);
        }
    }
}