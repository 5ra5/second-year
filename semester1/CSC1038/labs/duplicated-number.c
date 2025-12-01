# include <stdio.h>
# include <stdlib.h>

int findDuplicate(int number, int length, int *numbers);

int main(int argc, char *argv[])
{
    int number = atoi(argv[1]);
    int length = argc - 2;
    int numbers[50];

    for(int i = 0; i < length; i++)
    {
        numbers[i] = atoi(argv[i + 2]);
    }

    int duplicate = findDuplicate(number, length, numbers);
    if(duplicate == -1)
    {
        printf("no duplicated number\n");
    }
    else
    {
        printf("%d\n", duplicate);
    }
}

int findDuplicate(int number, int length, int *numbers)
{
    for(int i = 0; i < length; i++)
    {
        if(numbers[i] == number)
        {
            return numbers[i];
        }
    }

    return -1;
}