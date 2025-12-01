#include <stdio.h>
#include <stdlib.h>

void leap_year(int number1, int number2);

int main(int argc, char *argv[])
{
    int number1 = atoi(argv[1]);
    int number2 = atoi(argv[2]);
    
    leap_year(number1, number2);
}

void leap_year(int number1, int number2)
{
    for(int i = number1; i <= number2; i++)
    {
        if((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
        {
            printf("%d\n", i);
        }
    }
}