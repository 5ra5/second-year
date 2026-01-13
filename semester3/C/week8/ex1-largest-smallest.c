// ex1-largest-smallest.c
// Author: Petra Sartori
// Date: 29 October 2025

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void read_input(int n, char *argv[], const char *requirement, float numbers[]);
float find(int n, const char *requirement, float *numbers);

// main() function
int main(int argc, char *argv[]){

    // Since the first argument is a requirement, we start from the second argument
    int n = argc - 2;
    const char *requirement = argv[1];
    float numbers[n]; // array of numbers
    read_input(n, argv, requirement, numbers);
    float output = find(n, requirement, numbers);
    printf("%.2f\n", output);
    
    return 0;
}

// Other functions
void read_input(int n, char *argv[], const char *requirement, float numbers[]){

    for (int i = 0; i < n; i++){
        numbers[i] = atof(argv[i + 2]);
    }
}

float find(int n, const char *requirement, float *numbers){
    
    float largest = 0.0f;
    float smallest = numbers[1];

    if(strcmp(requirement, "largest") == 0){
        for(int i = 0; i < n; i++){
            if(numbers[i] > largest){
                largest = numbers[i];
            }
        }
        return largest;

    }else if(strcmp(requirement, "smallest") == 0){
        for(int i = 0; i < n; i++){
            if(smallest > numbers[i]){
                smallest = numbers[i];
            }
        }
        return smallest;
    }

}