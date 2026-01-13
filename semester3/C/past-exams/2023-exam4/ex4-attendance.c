#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** get_attendance(int argc, char *argv[], int *outCount);
void print_attendance(char **attendance, int count);
void free_attendance(char **attendance, int count);

int main(int argc, char *argv[])
{
    int count = 0;
    char **attendance = get_attendance(argc, argv, &count);
    print_attendance(attendance, count);
    free_attendance(attendance, count);
}

char ** get_attendance(int argc, char *argv[], int *outCount)
{
    int count = argc - 1;
    *outCount = count;

    char **arr = calloc(count, sizeof(char*));
    if (!arr)
    {
        printf("Array allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < count; i++)
    {
        size_t len = strlen(argv[i+1]);

        arr[i] = calloc(len+1, sizeof(char));
        if(!arr[i])
        {
            printf("String allocation failed.\n");
            exit(1);
        }

        strcpy(arr[i], argv[i+1]);
    }

    return arr;
}

void print_attendance(char **attendance, int count)
{
    for(int i = 0; i < count; i++)
    {
        int absent = 0;
        for(int j = 0; j < strlen(attendance[i]); j++)
        {
            if(attendance[i][j] == 'A')
            {
                absent++;
            }

            else if(attendance[i][j] == 'L' && attendance[i][j+1] == 'L' && attendance[i][j+2] == 'L')
            {
                absent++;
                j++;
            }
        }

        if(absent >= 3)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
}

void free_attendance(char **attendance, int count)
{
    for(int i = 0; i < count; i++)
    {
        free(attendance[i]);
    }
    free(attendance);
}