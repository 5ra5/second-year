#include <stdio.h>
#include <stdlib.h>

int* createArray(int length);
int* resizeIntArray(int *arr, int newLength);
int* readNumbers(int *arr, int length, int argc, char *argv[]);

int main(int argc, char *argv[])
{
    int length = 5;
    int *arr = createArray(length);
    arr = readNumbers(arr, length, argc, argv);
    return 0;
}

int* createArray(int length)
{
    int *arr = calloc(length, sizeof(int));
    if(!arr)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    return arr;
}

int* resizeIntArray(int *arr, int newLength)
{
    int *newArr = realloc(arr, newLength * sizeof(int));
    if(!newArr)
    {
        printf("Reallocation of memory failed!\n");
        exit(1);
    }

    return newArr;
}

int* readNumbers(int *arr, int length, int argc, char *argv[])
{
    for(int i = 0; i < length; i++)
    {
        
        arr[i] = atoi(argv[i+1]);
    }

    return arr;
}