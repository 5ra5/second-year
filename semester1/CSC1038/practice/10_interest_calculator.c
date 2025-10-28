#include <stdio.h>
#include <math.h>

int main()
{
    // COMPOUND INTEREST CALCULATOR

    double principal = 0.0;
    double interest_rate = 0.0;
    int years = 0;
    int times_compounded = 0;
    double compound = 0.0;
    int power = 0;

    printf("Compound Interest Calculator\n");
    printf("Enter the principal (P): ");
    scanf("%lf", &principal);

    printf("Enter the interest rate % (r): ");
    scanf("%lf", &interest_rate);
    interest_rate /= 100;

    printf("Enter the # of years (t): ");
    scanf("%d", &years);

    printf("Enter # of times compounded per year (n): ");
    scanf("%d", &times_compounded);

    power = times_compounded * years;
    compound = principal * pow((1 + interest_rate / times_compounded), power);

    printf("After %d years, the total will be $%.2lf\n", years, compound);

    return 0;
}