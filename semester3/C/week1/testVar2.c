#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){

    int number1, number2, result;

    printf("Number 1: ");
    scanf("%d", &number1);

    printf("Number 2: ");
    scanf("%d", &number2);

    result = number1 + number2;
    printf("The sum result is: %d\n", result);

    return 0;
}