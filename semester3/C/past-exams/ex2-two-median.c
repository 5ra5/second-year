#include <stdio.h>
#include <stdlib.h>

int *get_numbers(int argc, char *argv[], int length);
void sort_numbers(int *numbers, int length);
void print_median(int *numbers, int length);


int main(int argc, char *argv[])
{
    int length = argc - 1;
    int *numbers = get_numbers(argc, argv, length);
    sort_numbers(numbers, length);
    print_median(numbers, length);
    free(numbers);
    return 0;
}

int *get_numbers(int argc, char *argv[], int length)
{
    int *numbers = calloc(length, sizeof(int));
    if(!numbers)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for(int i = 0; i < length; i++)
    {
        numbers[i] = atoi(argv[i+1]);
    }

    return numbers;
}

void sort_numbers(int *numbers, int length)
{
    for(int i = 0; i < length - 1; i++)
    {
        for(int j = 0; j < length - i - 1; j++)
        {
            if(numbers[j] > numbers[j+1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }
}

void print_median(int *numbers, int length)
{
    int index = (length / 2) - 1;
    printf("%d\n%d\n", numbers[index], numbers[index+1]);
}