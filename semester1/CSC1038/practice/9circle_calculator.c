#include <stdio.h>
#include <math.h>

int main()
{
    double radius = 0.0;
    double area = 0.0;
    double surfaceArea = 0.0;
    double volume = 0.0;
    const double pi = 3.14159; // if you don't want to change the value of pi at all

    printf("Enter the radius: ");
    scanf("%lf", &radius);

    area = pi * pow(radius, 2);
    surfaceArea = 4.0 * pi * pow(radius, 2);
    volume = (4.0 / 3.0) * pi * pow(radius, 3);

    printf("Area: %.2lfcm\n", area);
    printf("Surface Area: %.2lfcm\n", surfaceArea);
    printf("Volume: %.2lfcm\n", volume);

    return 0;
}