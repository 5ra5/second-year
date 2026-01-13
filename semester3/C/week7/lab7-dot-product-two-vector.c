//lab7-dot-product-two-vector.c
// Author: Petra Sartori

#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void read_input(int n, char *argv[], int *vector1, int *vector2);
int dot_product(int n, int *vector1, int *vector2);

// Main function
int main(int argc, char*argv[]){

    int n = atoi(argv[1]); // size of vectors
    
    // using malloc to initialise vectors
    int *vector1 = malloc(n * sizeof(int));
    int *vector2 = malloc(n * sizeof(int));

    // avoiding segmentation fault if the memory allocation fails
    if (vector1 == NULL || vector2 == NULL){
        printf("Memory allocation fail\n");
        return 1;
    }

    read_input(n, argv, vector1, vector2);
    int product = dot_product(n, vector1, vector2);
    printf("%d\n", product);

    // releasing memory I borrowed with malloc()
    free(vector1);
    free(vector2);
    

    return 0;
}

// Other functions
// read_input function to extract elements of each vector from input
void read_input(int n, char *argv[], int *vector1, int *vector2){

    for (int i = 0; i < n; i++){
        vector1[i] = atoi(argv[2 + i]);
        vector2[i] = atoi(argv[2 + n + i]); // [2 + n + i] skips the first vector
    }
}

// dot_product function which takes size n and 2 vectors
// and multiplies the values of the same indexes of those 2 vectors 
int dot_product(int n, int *vector1, int *vector2){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += vector1[i] * vector2[i];
    }
    return sum;
}