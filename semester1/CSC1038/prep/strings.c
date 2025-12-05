// DYNAMICALLY ALLOCATING AN ARRAY OF STRINGS

// create array of string pointers
char** createStringArray(int count)
{
    char **arr = calloc(count, sizeof(char*));
    if (!arr) {
        fprintf(stderr, "Allocation failed.\n");
        exit(1);
    }
    return arr;
}

// allocate space for one string
char* allocateString(size_t length)
{
    char *str = calloc(length + 1, sizeof(char));  // +1 for '\0'
    if (!str) {
        fprintf(stderr, "String allocation failed.\n");
        exit(1);
    }
    return str;
}

// resize array of strings
char** resizeStringArray(char **arr, int newCount)
{
    char **newArr = realloc(arr, newCount * sizeof(char*));
    if (!newArr) {
        fprintf(stderr, "String array reallocation failed.\n");
        exit(1);
    }
    return newArr;
}

// free all strings + array
void freeStringArray(char **arr, int count)
{
    for (int i = 0; i < count; i++)
        free(arr[i]);

    free(arr);
}


// PASSING ARRAYS TO FUNCTIONS
void printStrings(char **arr, int count)
{
    for (int i = 0; i < count; i++)
        printf("%s\n", arr[i]);
}

