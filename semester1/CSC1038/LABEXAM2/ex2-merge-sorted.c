#include <stdio.h>
#include <stdlib.h>

int* read_array(int argc, char *argv[], int size, int start);
int* merge(int *array1, int *array2, int first_size, int second_size, int third_size);
void print_array(int *array3, int third_size);

int main(int argc, char *argv[])
{
    int first_size = atoi(argv[1]);
    int second_size = atoi(argv[2 + first_size]);
    int third_size = first_size + second_size;
    
    int *array1 = read_array(argc, argv, first_size, 2);
    int *array2 = read_array(argc, argv, second_size, 3 + first_size);

    int *array3 = merge(array1, array2, first_size, second_size, third_size);
    print_array(array3, third_size);

    free(array1);
    free(array2);
    free(array3);
}

int* read_array(int argc, char*argv[], int size, int start)
{
    int *array = calloc(size, sizeof(int));
    if(!array)
    {
        printf("Memory allocation failed.\n");
        exit (1);
    }

    for(int i = 0; i < size; i++)
    {
        array[i] = atoi(argv[start+i]);
    }

    return array;
}

int* merge(int *array1, int *array2, int first_size, int second_size, int third_size)
{
    int *array3 = calloc(third_size, sizeof(int));
    if(!array3)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int i = 0, j = 0, k = 0;

    while(i < first_size && j < second_size)
    {
        if(array1[i] < array2[j])
        {
            array3[k++] = array1[i++];
        }
        else
        {
            array3[k++] = array2[j++];
        }
    }

    while(i < first_size)
    {
        array3[k++] = array1[i++];
    }

    while(j < second_size)
    {
        array3[k++] = array2[j++];
    }

    return array3;
}

void print_array(int *array3, int third_size)
{
    for(int i = 0; i < third_size; i++)
    {
        printf("%d\n", array3[i]);
    }
}