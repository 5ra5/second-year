/*lab5-sort-numbers.c
Author: Petra Sartori*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Comparison functions
int ascending(int a, int b)
{
    // Swap if current element is greater than the next
    return a > b;
}

int descending(int a, int b)
{
    // Swap if current element is smaller than the next
    return a < b;
}

// Sorting function
// Takes an array arr of length n and sorts it using cmp
// I used bubble sort algorithm
void sorting(int arr[], int n, int (*cmp)(int, int))
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            // If comparison returns true, swap
            if (cmp(arr[j], arr[j + 1])){
                int current = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = current;
            }
        }
    }
}

int main(int argc, char *argv[]){
    
    int n = atoi(argv[1]); // The number of integers
    int numbers[n]; // Array takes n number of integers
    
    // Reading numbers from command line
    for (int i = 0; i < n; i++)
    {
        numbers[i] = atoi(argv[i + 2]);
    }

    // Sorting order
    // Pointer to comparison function
    int (*cmp)(int, int) = NULL;

    // If the last argument is asc, then set cmp to ascending, else descdending
    if (strcmp(argv[argc - 1], "asc") == 0)
    {
        cmp = ascending;
    }
    else if (strcmp(argv[argc - 1], "desc") == 0)
    {
        cmp = descending;
    }

    // Calling the sorting function
    sorting(numbers, n, cmp);

    // Printing numbers
    printf("Sorted numbers:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", numbers[i]);
    }
    printf("\n");

    return 0;
}