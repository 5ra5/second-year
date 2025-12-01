// READING AND COMPARING A STRING
// when you want to work with a string from command line:
// first initialise a string
char option[10];

// then read in the value from the command line using strncpy
strncpy(option, argv[1], 10);

// if you want to check whether the string matches an option
// it is important that you put the string you saved first and then
// compare it to some string
if(strcmp(option, "multiply") == 0);

// REVERSE A STRING
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