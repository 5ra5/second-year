#include <stdio.h>
#include <stdlib.h>

// -------------------- Function prototypes --------------------
int* createIntArray(int length);
int* resizeIntArray(int *arr, int newLength);
void freeIntArray(int *arr);
void printNumbers(int *arr, int length);
int* fillArrayFromArgs(int *arr, int argc, char *argv[], int *length);
int* fillArrayFromArgsOneByOne(int *arr, int argc, char *argv[], int *length);
void bubbleSort(int *arr, int length);

// -------------------- Example main --------------------
int main(int argc, char *argv[])
{
    int length = 0;
    int *arr = createIntArray(1);  // start with a small array

    // Fill array from command line, resize if needed
    arr = fillArrayFromArgs(arr, argc, argv, &length);

    printf("Original array:\n");
    printNumbers(arr, length);

    // Sort the array
    bubbleSort(arr, length);

    printf("Sorted array:\n");
    printNumbers(arr, length);

    freeIntArray(arr);
    return 0;
}

// -------------------- Function implementations --------------------

// Create a new array
int* createIntArray(int length)
{
    int *arr = calloc(length, sizeof(int));
    if (!arr) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return arr;
}

// Resize array
int* resizeIntArray(int *arr, int newLength)
{
    int *newArr = realloc(arr, newLength * sizeof(int));
    if (!newArr) {
        printf("Reallocation failed.\n");
        exit(1);
    }
    return newArr;
}

// Free array
void freeIntArray(int *arr)
{
    free(arr);
}

// Print array
void printNumbers(int *arr, int length)
{
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Fill array from command line, resize all at once
int* fillArrayFromArgs(int *arr, int argc, char *argv[], int *length)
{
    int requiredLength = argc - 1; // number of arguments excluding program name

    arr = resizeIntArray(arr, requiredLength);

    for (int i = 0; i < requiredLength; i++)
        arr[i] = atoi(argv[i + 1]);

    if (length)
        *length = requiredLength;

    return arr;
}

int* fillArrayFromArgsOneByOne(int *arr, int argc, char *argv[], int *length)
{
    int len = 0;                     // number of elements filled
    int allocatedSize = *length;     // current allocated memory size

    for (int i = 1; i < argc; i++)
    {
        // Reallocate only if we exceed allocated memory
        if (len >= allocatedSize)
        {
            allocatedSize++;           // increase allocated size by 1 (or double for efficiency)
            arr = resizeIntArray(arr, allocatedSize);
        }

        arr[len] = atoi(argv[i]);
        len++;
    }

    // Update caller with actual number of elements filled
    if (length)
        *length = len;

    return arr;
}