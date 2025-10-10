#include <stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{
    int numbers[10] = {0}; // Initialising all to 0
    int total = 0;


    /*Makes sure that input less than 10 arguments doesn't cause
    segmentation fault*/
    int input = argc - 1; 

    for(int i = 0; i < input; ++i)
    {
        numbers[i] = atoi(argv[i+1]); //Looping through input 
        if(numbers[i] % 2 != 0) //Identifying odd numbers
        {
            total += 1;
        }
    }

    printf("%d\n", total);

    return 0;
}