// ex2-merge-sorted.c
// Author: Petra Sartori
// Date: 27/11/2025

// this program merges two sorted sequences of integers into one

// libraries needed for this task
# include<stdio.h>
# include<stdlib.h>

// function prototypes
void read_input(int *size, int *size2, char *argv[], int *n, int *m);

int main(int argc, char*argv[]){

    // determining the size of n and m
    int *size = atoi(argv[1]); // size of n
    int *size2 = atoi(argv[size + 1]); // size of m
    
    // using malloc for two arrays
    int *n = malloc(size * sizeof(int));
    int *m = malloc(size2 * sizeof(int));

    // avoiding segmentation fault if the memory allocation fails
    if (n == NULL || m == NULL){
        printf("Memory allocation fail\n");
        return 1;
    }

    read_input(size, size2, argv, n, m);

    // releasing memory i borrowed with malloc
    free(n);
    free(m);
}

void read_input(int *size, int *size2, char *argv[], int *n, int *m){

    for (int i = 0; i < n; i++){
        n[i] = atoi(argv[2 + i]);
        m[i] = atoi(argv[2 + size + i]); // [2 + size + i] skips the first array
    }
}