# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void longest(char *sentence);

int main(int argc, char *argv[])
{
    char sentence[100];
    strcpy(sentence, argv[1]);

    longest(sentence);
    return 0;
}

// to find the longest word in the sentence:
void longest(char *sentence)
{
    int length = strlen(sentence);
    // initialise a temporary array to store the current word being processed
    char current[50];

    // initialise the array that will store the longest word so far
    char longest[50];

    // c stores the current value of the current word
    int c = 0;
    
    // use a for loop to go through each character of the sentence
    for(int i = 0; i <= length; i++)
    {
        // if the character is not a space and not a null terminator, append it to current
        // else terminate the word and compare it to the longest word
        if(sentence[i] != ' ' && sentence[i] != '\0')
        {
            current[c] = sentence[i];
            c++;
        }
        else
        {
            // terminating the word, set the c to \0
            current[c] = '\0';

            // if the current word is longer than longest, copy it to longest variable
            if(strlen(current) > strlen(longest))
            {
                strcpy(longest, current);
            }
            c = 0;
        }
    }

    printf("%s\n", longest);
}