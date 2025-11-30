# include <stdio.h>
# include <stdlib.h>

// count odd numbers in an array
// when passing a single number to a function use &number!!

int odds(int *values, int length);

int main(int argc, char *argv[])
{
    int length = argc - 1; // the length of the array is the number of arguments passed
    int values[length]; // initialise the array with the determined length

    // read the input
    for(int i = 0; i < length; i++)
    {
        // argv[i+1] because argv[0] is the name of the program
        values[i] = atoi(argv[i+1]);
    }

    int total = odds(values, length);
    printf("%d\n", total);
}

int odds(int *values, int length)
{
    int count = 0;
    for(int i = 0; i < length; i++)
    {
        if(values[i] % 2 != 0)
        {
            count++;
        }
    }

    return count;
}