/*
ex1-max-diff.c
Author: Petra Sartori
Date: 30/10/2025
This program is to calculate the greatest difference between two numbers
from an array of integers
*/

/* Relevant libraries for this program */
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes*/
/* To calculate the the greatest difference between two numbers
First I need to find the greatest and the smallest number in the array using
findMax and findMin respectively, and then I find their difference using findDifference */
int findMax(int numbers[], int length);
int findMin(int numbers[], int length);
int findDifference(int max, int min);

int main(int argc, char *argv[]){
    
    int numbers[100]; // Array is initialised and accepts 100 elements
    int length = argc - 1;

    // Reading input and adding it in the array
    for(int i = 0; i < length; i++){
        numbers[i] = atoi(argv[i + 1]);
    }

    // Calling functions to determine the max, the min, and their difference
    int max = findMax(numbers, length);
    int min = findMin(numbers, length);
    int result = findDifference(max, min);

    // Printing the result
    printf("%d\n", result);

    return 0;
}

/* findMax accepts the array of integers numbers and the length of the array and returns the greatest value.
The max is initialised to the first element of the array.*/
int findMax(int numbers[], int length){
    int max = numbers[0];

    // Loop through every element, if the current element is greater than the max, it becomes max
    for (int i = 0; i < length; i++){
        if (max < numbers[i]){
            max = numbers[i];
        }
    }
    
    return max;
}

/* findMin accepts the array of integers numbers and the length of the array and returns the smallest value.
The min is initialised to the first element of the array.*/
int findMin(int numbers[], int length){
    int min = numbers[0];

    // Loop through every element, if the current element is smaller than the min, it becomes min
    for (int i = 0; i < length; i++){
        if (min > numbers[i]){
            min = numbers[i];
        }
    }
    return min;
}

/* findDifference takes the max and the min we got from other two functions and simply subtracts min from max
and returns the result.*/
int findDifference(int max, int min){
    int result = max - min;
    return result;
}