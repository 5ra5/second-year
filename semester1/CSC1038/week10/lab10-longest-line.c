// lab10-longest-line.c
// Author: Petra Sartori
// Date: 14/11/2025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Assuming the maximum length of each sentence to be 200
#define MAX 200

int main()
{
    char line[MAX]; // Initializing line
    int length; // A variable to store a length of a certain line
    int max = 0; // A variable to store a maximum length
    char longest[MAX]; // A variable to store the line with the max length

    // Opening a text file
    FILE *pfile = NULL;
    char *filename = "paragraph.txt";
    pfile = fopen(filename, "r");

    // Handling a case where the file doesn't exist
    if (!pfile)
    {
        printf("Failed to open %s.\n", filename);
    }

    // Iterating through the file and reading each line
    while(fgets(line, sizeof(line), pfile))
    {
        // Checking the length of the current line
        length = strlen(line);

        // If the length of the current line is greater than the max one
        if(length > max)
        {
            // Max becomes the current length
            max = length;

            // Current line is copied into the longest variable
            strcpy(longest, line);
        }
    }

    fclose(pfile);

    printf("%d\n", max);
    printf("%s\n", longest);

    return 0;
}