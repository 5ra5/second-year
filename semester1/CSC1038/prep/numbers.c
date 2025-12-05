// DYNAMICALLY ALLOCATING AN ARRAY OF NUMBERS

// create new array
int* createIntArray(int length)
{
    int *arr = calloc(length, sizeof(int));  // initializes all to 0
    if (!arr) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    return arr;
}

// resize array
int* resizeIntArray(int *arr, int newLength)
{
    int *newArr = realloc(arr, newLength * sizeof(int));
    if (!newArr) {
        fprintf(stderr, "Reallocation failed.\n");
        exit(1);
    }
    return newArr;
}

// free
void freeIntArray(int *arr)
{
    free(arr);
}

// PASSING ARRAYS TO FUNCTIONS
void printNumbers(int *arr, int length)
{
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

