# include <stdio.h>
# include <stdlib.h>

int main(int argc, char *argv[])
{
    int dimension = atoi(argv[1]);
    int matrix[dimension][dimension];

    for(int i; i < argc - 1; i++)
    {
        for(int j; j < argc - 1; i++)
        {
            matrix[i][j] = i, j;
        }
    }

    printf("%d\n", matrix[1][2]);
}