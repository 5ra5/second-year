# include <stdio.h>
# include <stdlib.h>

int findMax(int *numbers, int length);

int main(int argc, char *argv[])
{
    int length = argc - 1;
    int numbers[50];
    for(int i = 0; i < length; i++)
    {
        numbers[i] = atoi(argv[i + 1]);
    }

    int max = findMax(numbers, length);
    printf("%d\n", max);
}

int findMax(int *numbers, int length)
{
    // remember to initialise max to 0 to avoid getting random number for it
    // that was saved in memory
    int max = 0;
    for(int i = 0; i < length; i++)
    {
        if(numbers[i] > max)
        {
            max = numbers[i];
        }
    }

    return max;
}