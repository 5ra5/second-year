# include <stdio.h>
# include <stdlib.h>
# define PI 3.1415

float CalculateArea(float radius, float height);

int main(int argc, char *argv[])
{
    // remember to first check whether there is enough arguments given, then initialise the variables
    if(argc == 1)
    {
        printf("No input given!\n");
        return 1;
    }
    else if(argc == 2)
    {
        printf("Two arguments needed!\n");
        return 1;
    }

    // initialising variables after handling cases where the input is incomplete
    float radius = atof(argv[1]);
    float height = atof(argv[2]);

    // now check whether there is negative numbers, if not continue
    if(radius < 0 || height < 0)
    {
        float radius = atof(argv[1]);
        float height = atof(argv[2]);
        printf("The radius or height cannot be negative!\n");
        return 1;
    }
    else
    {
        float radius = atof(argv[1]);
        float height = atof(argv[2]);
        float area = CalculateArea(radius, height);
        printf("%.2f\n", area);
        return 0;
    }
}

float CalculateArea(float radius, float height)
{
    float radiusSquared = radius * radius;
    float area = 2*PI*radius*height + 2*PI*radiusSquared;
    return area;
}