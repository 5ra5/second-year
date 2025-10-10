#include<stdio.h>
#include<stdlib.h>


int main(int argc, char* argv[])
{
    int numbers2D[3][4] = { /* A 2D array with 3 rows and 4 columns */
	    {1,2,3,4},  /* value for first row */
	    {5,6,7,8},  /* value for second row */
	    {4,5,6,7}   /* value for third row */
    };

    int sumOfEachLine[3] = {0};

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            sumOfEachLine[i] += numbers2D[i][j];
        }
    }

    for(int = 0; i < 3, ++i){
        printf("Sum of line %d is %d\n", i, sumOfEachLine[i]);
    }

}