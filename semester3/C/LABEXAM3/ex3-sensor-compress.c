// ex3-sensor-compress.c
// Author: Petra Sartori
// Date: 10 December 2025

// This program takes in strings of integers, stores them in an array of strings, and performs a Run-Length Encoding.
// It checks how many times does a number repeat in sequence: it prints that number and the number of occurrence behind it.
// Each line of output contains all of the numbers of the string array along with their occurences.

// Libraries needed for this task
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
char** createArray(int argc, char *argv[], int *outCount);
void compress(char **arr, int count);
void freeArr(char **arr, int count);

// Main function calls all of the other functions
int main(int argc, char *argv[])
{
    int count = 0;
    char **arr = createArray(argc, argv, &count);
    compress(arr, count);
    freeArr(arr, count);
    return 0;
}

// createArray dynamically allocates memory for both the array that will hold all the strings, and each string individually
// It also reads in all of the strings and assigns them an index in the array of strings
char** createArray(int argc, char *argv[], int *outCount)
{
    // count is the number of arguments in the input
    int count = argc - 1;
    *outCount = count;

    // allocating memory for the array of strings
    char **arr = calloc(count, sizeof(char*));

    // Checking if the memory allocation worked
    if (!arr) {
            printf("String array allocation failed.\n");
            exit(1);
        }

    // individually determining the length of each string, allocating memory for each, and adding them to the list.
    for (int i = 0; i < count; i++) {
        size_t len = strlen(argv[i + 1]);

        // allocate each string directly here
        // len + 1 for '\0'
        arr[i] = calloc(len + 1, sizeof(char));

        // Checking if the memory allocaton worked.
        if (!arr[i]) {
            printf("String allocation failed.\n");
            exit(1);
        }

        // Putting the string into the array
        strcpy(arr[i], argv[i + 1]);
    }

    // Returning the array
    return arr;
}

// Compress function checks how many times does a number repeat in sequence
// It prints the number it's checking and the number of occurences at each iteration of one string, so each string has its values and occurences printed in its own line
void compress(char **arr, int count)
{
    // outer loop iterates through each string
    for (int i = 0; i < count; i++)
    {
        int numCount = 0;

        // inner loop iterates through sequences of numbers in each string
        for (int j = 0; j < strlen(arr[i]); j++)
        {
            // if the value next to the current value is the same, increment the numCount
            if(arr[i][j] == arr[i][j+1])
            {
                numCount++;
            }

            // print the value, and it's count - this prints all of the values and occurences of one string together
            printf("%d %d ", arr[i][j], numCount);
        }
        // this \n divides outputs of each string
        printf("\n");
    }

}

// FreeArr function frees memory for each string in the array, and then the memory for the array itself after
void freeArr(char **arr, int count)
{
    for (int i = 0; i < count; i++)
    {
        free(arr[i]);
    }
    free(arr);
}