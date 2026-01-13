#include <stdio.h>
#include <stdlib.h>

double average(double x, double y);
int sumCal(int a, int b); 

int main(int agrc, char* argv[])
{
    double a = 5.5;
    double b = 6.6;
    double result = average(a,b);

    printf("a = %f\n", a);
    printf("b = %f\n", b);
    printf("average: %f\n", result);
    return 0;
}