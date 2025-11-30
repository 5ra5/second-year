# include <stdio.h>
# include <stdlib.h>

void drawSquare(int width);

int main(int argc, char *argv[])
{
    int width = atoi(argv[1]);

    drawSquare(width);

}

void drawSquare(int width)
{
    // draw the upper line
    for(int j = 0; j < width; ++j)
    {
        printf("*");
    }
    printf("\n");

    // draw the horizontal lines
    // int i = 1 because we're starting to draw from the second row
    // i < width - 1 because we're drawing the lower line after
    for (int i = 1; i < width - 1; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if((j == 0) || (j == width - 1))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    // draw the lower line
    for(int j = 0; j < width; ++j)
    {
        printf("*");
    }
    printf("\n");
}