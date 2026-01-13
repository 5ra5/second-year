// lab7-second-largest.c
// Petra Sartori

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void read_input(int n, char *argv[], float *numbers);
float second_largest(int n, float *numbers);

// Main function
int main(int argc, char*argv[]){

    int n =  argc - 1;
    float *numbers = malloc(n * sizeof(float));

    if (numbers == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    read_input(n, argv, numbers);
    float second  = second_largest(n, numbers);
    printf("%.1f\n", second);

    free(numbers);
    return 0;
}


// function read_input which reads input from command line and adds it to the array of numbers
void read_input(int n, char *argv[], float *numbers){

    for (int i = 0; i < n; i++){
       numbers[i] = atof(argv[i + 1]);
    }
}

// function second_largest which saves the largest number, and checks
// for the second largest number bu comparison through a for loop
float second_largest(int n, float *numbers){

    float largest = 0.0f;
    float second = 0.0f;

    for(int i = 0; i < n; i++){
        if(numbers[i] > largest){
            second = largest;
            largest = numbers[i];
        }else if(numbers[i] < largest && numbers[i] > second){
            second = numbers[i];
        }
        
    }

    return second;
}