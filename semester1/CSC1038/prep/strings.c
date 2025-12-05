#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char** createStringArray(int argc, char *argv[], int *outCount);
char** resizeStringArray(char **arr, int newCount);
void freeStringArray(char **arr, int count);
void toUppercase(char **arr, int count);
void printStrings(char **arr, int count);


int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <words>\n", argv[0]);
        return 0;
    }

    int count = 0;

    // create and copy argv strings
    char **strings = createStringArray(argc, argv, &count);

    // example processing
    toUppercase(strings, count);

    // print results
    printStrings(strings, count);

    // free memory
    freeStringArray(strings, count);

    return 0;
}

// create array of strings AND copy argv into them
char** createStringArray(int argc, char *argv[], int *outCount)
{
    int count = argc - 1;    // ignore program name
    *outCount = count;

    char **arr = calloc(count, sizeof(char*));
    if (!arr) {
        fprintf(stderr, "Array allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        size_t len = strlen(argv[i + 1]);

        // allocate each string directly here
        arr[i] = calloc(len + 1, sizeof(char));   // +1 for '\0'
        if (!arr[i]) {
            fprintf(stderr, "String allocation failed.\n");
            exit(1);
        }

        strcpy(arr[i], argv[i + 1]);
    }

    return arr;
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

// free all strings + pointer array
void freeStringArray(char **arr, int count)
{
    for (int i = 0; i < count; i++)
        free(arr[i]);
    free(arr);
}

// example processing: make each string uppercase
void toUppercase(char **arr, int count)
{
    for (int i = 0; i < count; i++)
        for (char *p = arr[i]; *p; p++)
            *p = toupper((unsigned char)*p);
}

// print array of strings
void printStrings(char **arr, int count)
{
    for (int i = 0; i < count; i++)
        printf("%s\n", arr[i]);
}