#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float multiply(float number1, float number2);
float divide(float number1, float number2);

int main(int argc, char *argv[])
{
    float result = 0.0; // initialise result
    char option[10]; // initialise string array
    strncpy(option, argv[1], 10); // read the value in the string

    // get 2 numbers from input
    float number1 = atof(argv[2]);
    float number2 = atof(argv[3]);

    // when comparing a string to something, you first have to put the string you saved
    // and then the string you're comparing it to!!!
    if(strcmp(option, "multiply") == 0)
    {
        result = multiply(number1, number2);
        printf("%.2f\n", result);
    }
    else if(strcmp(option, "divide") == 0)
    {
        if(number1 == 0 || number2 == 0)
        {
            printf("invalid\n");
        }
        else
        {
            result = divide(number1, number2);
            printf("%.2f\n", result);
        }
        
    }
}

float multiply(float number1, float number2)
{
    return number1 * number2;
}

float divide(float number1, float number2)
{
    return number1 / number2;
}