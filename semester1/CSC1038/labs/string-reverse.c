# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void reverse(char *str);

int main(int argc, char *argv[])
{
    // remember not to initialise str as a pointer here because
    // you'll get segmentation fault
    char str[50];
    strncpy(str, argv[1], 50);
    reverse(str);
    printf("%s\n", str);
    return 0;
}

// use 2 pointers to swap the corresponding characters starting
// from beginning and the end while moving the indexes towards each other
// until they meet each other
void reverse(char *str)
{
    // initialise l and r pointers
    int left = 0;
    int right = strlen(str) - 1;
    char temp;

    // swap characters until l and r meet
    while(left < right)
    {
        // swap characters by their indexes
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        // move pointers towards each other
        left++;
        right--;
    }
}