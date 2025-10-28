// lab3-find-longest-word.c
// Author: Petra Sartori

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find_longest(char *sentence);

int main(int argc, char * argv[])
{
    char sentence[256]; // Storing the input maximum of 256 bytes
    strncpy(sentence, argv[1], 255); // Reading input
    sentence[255] = '\0'; // Last char is null terminator
    int len = strlen(sentence); // length of a sentence

    find_longest(sentence);

    return 0;

}

// find_longest function which splits the sentence and checks every word to find the longest
void find_longest(char *sentence){

    int max = 0;
    int current = 0;
    int start = 0;
    int currentStart = 0;

    for(int i = 0; ; i++){
        char c = sentence[i];

    // if c is a space or null terminator, start again
    if (c == ' ' || c == '\0'){
        if (current > max) {
            max = current;
            start = currentStart;
        }
        current = 0;
        currentStart = i + 1;
    }else{
        current++;
    }

        if (c == '\0') break;
    }

    // extracting the longest word
    char longest[max + 1];
    strncpy(longest, sentence + start, max);
    longest[max] = '\0';
    printf("%s\n", longest);

}