#include <stdio.h>
#include <stdlib.h>

// -------------------- Function prototypes --------------------
int* createArray(int length);
int* resizeArray(int *arr, int newLength);
void printArray(int *arr, int length);
void bubbleSort(int *arr, int length);
int* readNumbers(int *arr, int argc, char *argv[], int *count);
int* findFrequent(int *arr, int count, int *freqCount);

// -------------------- Main --------------------
int main(int argc, char *argv[])
{
    int count = 5; // initial allocated memory
    int *numbers = createArray(count);

    // Read numbers from command line
    numbers = readNumbers(numbers, argc, argv, &count);

    // Find frequent elements
    int freqCount;
    int *frequent = findFrequent(numbers, count, &freqCount);

    // Sort frequent elements
    bubbleSort(frequent, freqCount);

    // Print frequent elements
    printArray(frequent, freqCount);

    // Free memory
    free(numbers);
    free(frequent);

    return 0;
}

// -------------------- Function implementations --------------------

// Create a new array
int* createArray(int length)
{
    int *arr = calloc(length, sizeof(int));
    if (!arr) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return arr;
}

// Resize array
int* resizeArray(int *arr, int newLength)
{
    int *newArr = realloc(arr, newLength * sizeof(int));
    if (!newArr) {
        printf("Reallocation failed\n");
        exit(1);
    }
    return newArr;
}

// Print array
void printArray(int *arr, int length)
{
    for (int i = 0; i < length; i++)
        printf("%d\n", arr[i]);
}

// Simple bubble sort
void bubbleSort(int *arr, int length)
{
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

// Read numbers from command line, dynamically reallocating
int* readNumbers(int *arr, int argc, char *argv[], int *count)
{
    int allocatedSize = *count; // initial allocated size
    int len = 0;                 // number of elements added

    for (int i = 1; i < argc; i++) {
        if (len >= allocatedSize) {
            allocatedSize++; // increase memory by 1
            arr = resizeArray(arr, allocatedSize);
        }
        arr[len++] = atoi(argv[i]);
    }

    *count = len;
    return arr;
}

// Find frequent elements (appearing more than 3 times)
int* findFrequent(int *arr, int count, int *freqCount)
{
    int totalFrequent = 0;

    // Count total number of occurrences that are frequent
    for (int i = 0; i < count; i++) {
        int occurrences = 0;
        for (int j = 0; j < count; j++) {
            if (arr[i] == arr[j])
                occurrences++;
        }
        if (occurrences > 3)
            totalFrequent++;
    }

    // Allocate exact memory for frequent elements
    int *frequent = calloc(totalFrequent, sizeof(int));
    if (!frequent) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Fill the frequent array
    int index = 0;
    for (int i = 0; i < count; i++) {
        int occurrences = 0;
        for (int j = 0; j < count; j++) {
            if (arr[i] == arr[j])
                occurrences++;
        }
        if (occurrences > 3) {
            frequent[index++] = arr[i];
        }
    }

    *freqCount = totalFrequent;
    return frequent;
}
