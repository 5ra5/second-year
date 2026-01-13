/*lab3-calculator.c
Author: Petra Sartori*/

/*Include input/output + standard library + string library*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Function: calculator
Parameters: operands and operator
Returns: float
Description: The function takes an operation (multiplcation or division) and two floats 
from input and returns the result of the operation
*/

float calculator(float a, float b, const char *op){
    if(strcmp(op, "multiply") == 0){
        return a * b;
    }

    // returning 0.0 if we try to divide by 0
    else if(strcmp(op, "divide") == 0){
        if(a == 0.0f || b == 0.0f){
            return 0.0f;
        }
        return a / b;
    }
    return 0.0f;
}

int main(int argc, char *argv[]){
    
    // getting input from argv (atof because they're floats)
    const char *op = argv[1];
    float a = atof(argv[2]);
    float b = atof(argv[3]);
    
    // calling the calculator function main
    float result = calculator(a, b, op);
    
    // if the result is 0.0 (we tried to divide by 0) print "invalid"
    if(result == 0.0f){
        printf("invalid\n");
    } else{
        printf("%f\n", result);
    }


    return 0;

}