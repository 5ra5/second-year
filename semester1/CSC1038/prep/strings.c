#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char** createStringArray(int argc, char *argv[], int *outCount);
char** resizeStringArray(char **arr, int newCount);
void freeStringArray(char **arr, int count);
void toUppercase(char **arr, int count);
void printStrings(char **arr, int count);
void findLongestString(char **arr, int count);
void reverseStrings(char **arr, int count);
void sortStrings(char **arr, int count);
int totalCharacters(char **arr, int count);
int countContainingChar(char **arr, int count, char c);
void findShortestString(char **arr, int count);


int main(int argc, char *argv[])
{
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
        printf("Array allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        size_t len = strlen(argv[i + 1]);

        // allocate each string directly here
        arr[i] = calloc(len + 1, sizeof(char));   // +1 for '\0'
        if (!arr[i]) {
            printf("String allocation failed.\n");
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
        printf("String array reallocation failed.\n");
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

void findLongestString(char **arr, int count)
{
    if (count == 0)
        return;

    int maxIndex = 0;
    size_t maxLen = strlen(arr[0]);

    for (int i = 1; i < count; i++) {
        size_t len = strlen(arr[i]);
        if (len > maxLen) {
            maxLen = len;
            maxIndex = i;
        }
    }

    printf("Longest string: %s (length %zu)\n", arr[maxIndex], maxLen);
}

void reverseStrings(char **arr, int count)
{
    for (int i = 0; i < count; i++) {
        char *s = arr[i];
        int left = 0;
        int right = strlen(s) - 1;

        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
}

// sort strings alphabetically
void sortStrings(char **arr, int count)
{
    for (int i = 1; i < count; i++) {
        char *key = arr[i];
        int j = i - 1;

        while (j >= 0 && strcmp(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// count total characters across all strings
int totalCharacters(char **arr, int count)
{
    int total = 0;
    for (int i = 0; i < count; i++)
        total += strlen(arr[i]);
    return total;
}

// count how many strings contain a given character
int countContainingChar(char **arr, int count, char c)
{
    int hits = 0;
    for (int i = 0; i < count; i++)
        if (strchr(arr[i], c) != NULL)
            hits++;
    return hits;
}

// find shortest string
void findShortestString(char **arr, int count)
{
    if (count == 0) return;

    int minIndex = 0;
    size_t minLen = strlen(arr[0]);

    for (int i = 1; i < count; i++) {
        size_t len = strlen(arr[i]);
        if (len < minLen) {
            minLen = len;
            minIndex = i;
        }
    }

    printf("Shortest string: %s (length %zu)\n", arr[minIndex], minLen);
}
