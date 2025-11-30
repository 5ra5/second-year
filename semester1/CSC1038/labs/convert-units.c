# include <stdio.h>
# include <stdlib.h>

// print numbers in a specific format, converted from cm to inches

void printNumbers(float lower, float upper);

int main(int argc, char *argv[])
{
    float lower = 30.00;
    float upper = 50.00;
    printNumbers(lower, upper);

    return 0;
}

void printNumbers(float lower, float upper)
{
    int count = 0;
    for (float i = lower; i < upper; i++)
    {
        printf("%.2f\t", i / 2.54);
        count++;

        if(count % 5 == 0)
        {
            printf("\n");
        }
    }
}