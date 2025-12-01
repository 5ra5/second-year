# include <stdio.h>
# include <stdlib.h>

int search(int number, int length, int *numbers);

int main(int argc, char *argv[])
{
    int number = atoi(argv[1]); // the number we're searching for
    int length = argc - 2; // length is -2 because we're ignoring argv[0] and argv[1]
    int numbers[50]; // initialise the array

    for(int i = 0; i < length; i++)
    {
        // [i+2] because the array begins at [i + 2]
        numbers[i] = atoi(argv[i + 2]);
    }

    int index = search(number, length, numbers);
 
    if (index == -1)
    {
        printf("%d not found\n", number);
    }
    else
    {
        printf("%d found at %d\n", number, index);
    }

}

int search(int number, int length, int *numbers)
{
    // don't initialise an index variable because if you intitalise it to 0,
    // you can never properly return the number with index 0!!

    for(int i = 0; i < length; i++)
    {
        if(numbers[i] == number)
        {
            // if the number is found, just return the index right away since we're not expecting duplicates
            return i;
        }
    }
    return -1; // in the case that the index isn't found
}