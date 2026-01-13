// lab7-largest-twice.c
// Petra Sartori

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void read_input(int n, char *argv[], float *numbers);
int twice_as_large(int n, float *numbers);

// Main function
// Dyanmically assigns memory to the array of numbers
// Calls other functions and prints the result
int main(int argc, char*argv[]){

    int n =  argc - 1;
    float *numbers = malloc(n * sizeof(float));

    if (numbers == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    read_input(n, argv, numbers);
    int output  = twice_as_large(n, numbers);
    printf("%d\n", output);

    free(numbers);
    return 0;
}


// function read_input which reads input from command line and adds it to the array of numbers
void read_input(int n, char *argv[], float *numbers){

    for (int i = 0; i < n; i++){
       numbers[i] = atof(argv[i + 1]);
    }
}


// function twice_as_large which finds the largest number
// and compares it to every number to check if it's twice as large as any other number
int twice_as_large(int n, float *numbers){

    int largest = 0;

    // Largest number
    for (int i = 1; i < n; i++){
        if (numbers[i] > largest){
            largest = numbers[i];
        }
    }

    // Comparing the largest number to all of the other elements
    // to check if it is twice as large as another number
    for (int i = 0; i < n; i++){
        // if the current number is not the largest element and the largest element
        // is greated than current number times 2
        if (numbers[i] != largest && largest >= 2 * numbers[i]){
            return largest;
        }

    
    }
    return 0; // If there is no twice as large number, return 0
}