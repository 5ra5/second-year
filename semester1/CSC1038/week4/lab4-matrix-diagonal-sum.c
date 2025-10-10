/*lab4-matrix-diagonal-sum.c
Author: Petra Sartori*/

#include <stdio.h>
#include <stdlib.h>


int diagonal_sum(int* matrix, int n);

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]); // Matrix dimension given by the first argument
    int matrix[n][n];

    int index = 2; // We start from the second arg
    // Looping through the command line args to fill a n*n matrix
    // i is row, j is column
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matrix[i][j] = atoi(argv[index++]);
        }
    }

    int sum = diagonal_sum(&matrix[0][0], n);

    printf("%d\n", sum);

    return 0;
}
 
/*Function diagonal sum which takes a pointer of the first element of the matrix
and the dimension of the matrix and returns the sum of its diagonal*/
int diagonal_sum(int* matrix, int n){
    int sum = 0;

    for (int i = 0; i < n; i++){
        // matrix + i * n skips i rows
        // *(matrix + 0*3 + 0) = 1
        // *(matrix + 1*3 + 1) = 5 etc.
        sum += *(matrix + i * n + i);
    }

    return sum;
}