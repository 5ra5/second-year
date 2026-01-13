/*lab4-find-most-character.c
Author: Petra Sartori*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int most_freq(char* s);

int main(int argc, char *argv[])
{
    char* s = argv[1]; // Input is the first argument from the command line
    
    int most_frequent = most_freq(s); // Calling the most_freq function
    printf("%c\n", most_frequent); // Printing the result

    return 0;
}


// most_freq function that takes a string and returns the character that occurs the most
int most_freq(char* s){
    int count[256] = {0}; // An array in which every index represents the count of one ASCII characters out of 256 available
    int* pcount = count; // A pointer of count which we use to iterate
    int max = 0; // Stores the highest frequency
    int i; // character we're currently dealing with, used for iteration in for loops
    char most_frequent = 0; // Stores the most frequent char

    // Loop counting the frequency of every character in a string
    for(i=0; s[i] != '\0'; i++){
        // If the current char is a space, ignore it
        if (s[i] == ' '){
            continue;
        }
        count[(char)s[i]]++; 
    }

    // Loop finding which character has the greatest count value using the *pcount pointer
    // i < 256 because there is 256 ASCII characters
    for(i=0; i < 256; i++, pcount++){
        // If the current character has a greater count value than max, most_frequent becomes that character and the loop continues
        if (*pcount > max){
            max = *pcount;
            most_frequent = i;
        }
    }
    return most_frequent; // Returning the character with the max value
}
