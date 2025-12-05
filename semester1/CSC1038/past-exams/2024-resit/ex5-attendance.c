#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** createArray(int argc, char *argv[], int *outCount);
void attendance(char **arr, int count);
void freeArr(char **arr, int count);

int main(int argc, char *argv[])
{
    int count = 0;
    char **arr = createArray(argc, argv, &count);
    attendance(arr, count);
    freeArr(arr, count);
}

char** createArray(int argc, char *argv[], int *outCount)
{
    int count = argc - 1;
    *outCount = count;

    char **arr = calloc(count, sizeof(char*));

    for (int i = 0; i < count; i++) {
        size_t len = strlen(argv[i + 1]);

        // allocate each string directly here
        arr[i] = calloc(len + 1, sizeof(char));
        if (!arr[i]) {
            fprintf(stderr, "String allocation failed.\n");
            exit(1);
        }

        strcpy(arr[i], argv[i + 1]);
    }

    return arr;
}

void attendance(char **arr, int count)
{

    for(int i = 0; i < count; i++)
    {
        int absent = 0;
        int present = 0;

        for(int j = 0; j < strlen(arr[i]); j++)
        {
            if(arr[i][j] == 'A')
            {
                absent++;
            }
            else if(arr[i][j] == 'L' && arr[i][j+1] == 'L')
            {
                absent++;
                j++;
            }
        }

        if(absent >= 4)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
}

void freeArr(char **arr, int count)
{
    for (int i = 0; i < count; i++)
    {
        free(arr[i]);
    }
    free(arr);
}