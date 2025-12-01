# include <stdio.h>
# include <stdlib.h>

void sort(int *numbers, int length);
void printNumbers(int *numbers, int length);

int main(int argc, char *argv[])
{
    int length = argc - 1;
    int numbers[50];
    for (int i = 0; i < length; i++)
    {
        numbers[i] = atoi(argv[i+1]);
    }

    sort(numbers, length);
    printNumbers(numbers, length);
    
    return 0;
}

void sort(int *numbers, int length)
{
    int temp = 0;

    // compare [j] and [j+1] because they are adjacent elements
    for(int i = 0; i < length - 1; i++)
    {
        for(int j = 0; j < length - i - 1; j++)
        {
            if(numbers[j] > numbers[j + 1])
            {
                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }
}

void printNumbers(int *numbers, int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%d\n", numbers[i]);
    }
}