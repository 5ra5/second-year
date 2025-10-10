#include <stdio.h>
#include <stdlib.h>


int sumCal(int grades[], int length)
{
    int result = 0;
    for(int i = 0; i < length; i++){
        result += grades[i];
    }
    return result;
}

int main(int agrc, char* argv[])
{
    int grades[5] = {10, 20, 30, 40, 50};
    int sum;
    sum = sumCal(grades, 5);
    printf("The sum of grades is: %d\n", sum);
    return 0;
}