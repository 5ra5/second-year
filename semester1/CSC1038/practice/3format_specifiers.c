#include <stdio.h>

int main(){

    // Format specifier = Special tokens that begin with a % symbol,
    //                    followed by a character that specifies the data type
    //                    and optional modifiers (width, precision, flags).
    //                    They control how data is displayed or interpeted.

    // general
    int age = 25;
    float price = 19.99;
    double pi = 3.1415926535;
    char currency = '$';
    char name[] = "Petra";

    // width
    int num1 = 1;
    int num2 = 10;
    int num3 = -100;

    // precision
    float price1 = 19.99;
    float price2 = 1.50;
    float price3 = -100.00;

    // general
    printf("%d\n", age);
    printf("%f\n", price);
    printf("%lf\n", pi);
    printf("%c\n", currency);
    printf("%s\n\n", name);

    // width
    printf("%04d\n", num1); // zeros in front of the number
    printf("%4d\n", num2); // spaces in front of the number
    printf("%-4d\n", num2); // spaces after the number
    printf("%+d\n\n", num3); // if the number is positive it returns "+100", if it's negative it returns "-100"


    // width precision flags combined
    printf("%.1f\n", price1);
    printf("%+7.2f\n", price2);
    printf("%.2f\n", price3);
    return 0;
}