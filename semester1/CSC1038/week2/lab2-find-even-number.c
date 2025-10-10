#include <stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{
    int numbers[10] = {0};
    int total = 0; 

    int input = argc - 1; // Avoiding segmentation fault

    for(int i = 0; i < input; ++i)
    {
        numbers[i] = atoi(argv[i+1]);
        if(numbers[i] % 2 == 0) // Checking if the number is even
        {
            // Printing the index and the even number
            printf("%d - %d\n", i, numbers[i]);
            total += 1; // Keeping track of even numbers

        }
    }

    if(total == 0) // If there was no even numbers in the input
    {
        printf("Not found!\n");
    }

    return 0;
}