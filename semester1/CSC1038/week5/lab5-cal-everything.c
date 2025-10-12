/*lab5-cal-everything.c
Author: Petra Sartori*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function prototypes
// I used double instead of int for all operations to keep decimals
double sum(double x, double y);
double difference(double x, double y);
double product(double x, double y);
double division(double x, double y);
double power(double x, double y);
double log_sum(double x, double y);

double any_function(double (*pfun)(double, double), double x, double y);

int main(int argc, char *argv[])
{
    // Reading values we're working with
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double result = 0.0; // Storing results
    double (*pf)(double, double); // Pointer to function

    pf = sum;
    result = any_function(pf, a, b);
    printf("%.2f\n", result);

    pf = difference;
    result = any_function(pf, a, b);
    printf("%.2f\n", result);

    pf = product;
    result = any_function(pf, a, b);
    printf("%.2f\n", result);

    pf = division;
    result = any_function(pf, a, b);
    printf("%.2f\n", result);

    pf = power;
    result = any_function(pf, a, b);
    printf("%.2f\n", result);

    pf = log_sum;
    result = any_function(pf, a, b);
    printf("%.2f\n", result);

    return 0;

}


// Defining a function to call a function
double any_function(double (*pfun)(double, double), double x, double y)
{
    return pfun(x, y);
}


// Defining the functions to calculate and return 2 nunbers x and y
double sum(double x, double y)
{
    return x + y;
}

double difference(double x, double y)
{
    return x - y;
}

double product(double x, double y)
{
    return x * y;
}

double division(double x, double y)
{
    return x / y;
}

double power(double x, double y)
{
    return pow(x, y);
}

double log_sum(double x, double y)
{
    return log(x) + log(y);
}