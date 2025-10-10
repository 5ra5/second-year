#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])

{
    int width;
    int length;

    width = atoi(argv[1]);
    length = atoi(argv[2]);

    for(int i = 0; i < length; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            printf("*");
        }
        printf("\n");
    }
}

// try different shapes - empty square, triangle, star, all of that empty and reversed etc.