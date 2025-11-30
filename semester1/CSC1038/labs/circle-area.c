#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

float calculateArea(float radius);

int main(int argc, char *argv[])
{
    float radius = atof(argv[1]);
    if(radius < 0)
    {
        printf("The radius must be positive! Changing the sign...\n");
        float area = calculateArea(radius);
        printf("%.2f\n", area);
        return 0;
    }else
    {
        float area = calculateArea(radius);
        printf("%.2f\n", area);
        return 0;
    }
}

float calculateArea(float radius)
{
    float area = 0.0;
    radius = radius * radius;
    area = PI * radius;
    return area;
}