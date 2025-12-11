// ex3-max-inc-pair.c
// Author: Petra Sartori
// Date: 10/12/2025

// This program takes integers from the command line and uses dynamic memory allocation to store them into an array.
// For each number it checks whether the number next to it is greater, and if it is, it records their sum.
// It compares the current sum to the maximum one, and if it is bigger, it updates the maximum one.
// At the end, it prints the biggest sum.

// Required libraries for this task.
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int* create_array(int length);
int* read_input(int *arr, int argc, char *argv[], int length);
int calculate_sum(int *arr, int length);

// Main function determines the length of the string, calls the other functions and prints the result.
int main(int argc, char *argv[])
{
    // The length of the array will be the number of arguments passed to the program.
    int length = argc - 1;

    // Calling functions to allocate memory and fill the array.
    int *arr = create_array(length);
    arr = read_input(arr, argc, argv, length);

    // Calling a function to calculate the sum
    int max_sum = calculate_sum(arr, length);
    
    // Printing the output.
    printf("%d\n", max_sum);

    // Freeing the memory that was used for the array.
    free(arr);
}

// Create array function takes the expected length of the array and allocates just enough memory according to that number.
// It returns a pointer to the first number of the array.
int* create_array(int length)
{
    int *arr = calloc(length, sizeof(int));

    // Checking if the memory allocation worked. If it didn't, we print an error message and exit the code safely.
    if (!arr) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Returning the array.
    return arr;
}

// Read input function fills the array by iterating through the command line and assigning an index to each number.
int* read_input(int *arr, int argc, char *argv[], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = atoi(argv[i + 1]);
    }

    return arr;
}

// Calculate sum function takes a pointer to the first number of the list and the length of the list.
// It checks if the number next to the current number is greater. If it is it calculates their sum.
// It compares that sum to the maximum sum and updates it if it needs.
// It returns a maximum sum that is to be printed.
int calculate_sum(int *arr, int length)
{
    // Initialising max_sum to 0. If no other sum is calculated, the program will return this 0.
    int max_sum = 0;

    // Loop to check whether the next number is greater than the current one.
    for (int i = 0; i < length; i++)
    {
        // Current sum is inside of the loop because it has to be intialised to 0 at every iteration.
        int sum = 0;

        // If the next value is greater than the current one, add them together.
        if (arr[i] < arr[i+1])
        {
            sum = arr[i] + arr[i+1];

            // Checking whether the current sum is greater than the max sum
            if (sum > max_sum)
            {
                // If it is, it is updated
                max_sum = sum;
            }
        }
    }

    // Returning the max sum.
    return max_sum;
}