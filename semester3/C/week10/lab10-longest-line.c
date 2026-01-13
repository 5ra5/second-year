// lab10-longest-line.c
// Author: Petra Sartori
// Date: 14/11/2025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Assuming the maximum length of each sentence to be 200
#define MAX 200

int findLongestLine(FILE *pfile, char longest[]);
int writeTextFile(int max, char longest[], const char *filename);
int writeBinFile(int max, char longest[], const char *filename);

int main()
{
    int max; 
    char longest[MAX] = "";
    FILE *pfile = NULL;
    char *filename = "test.txt";
    const char *outputFile = "output.txt";
    const char *binOutputFile = "binOutput.bin";

    pfile = fopen(filename, "r");


    if (!pfile)
    {
        printf("Failed to open %s.\n", filename);
        return 1;
    }

    max = findLongestLine(pfile, longest);

    fclose(pfile);

    printf("%d\n", max);
    printf("%s\n", longest);

    writeTextFile(max, longest, outputFile);
    writeBinFile(max, longest, binOutputFile);

    return 0;
}


int findLongestLine(FILE *pfile, char longest[]){
    char line[MAX];
    int max = 0;
    int length;

    while(fgets(line, sizeof(line), pfile)){
        length = strlen(line);

        if (length > max){
            max = length;
            strcpy(longest, line);
        }
    }

    return max;
}

int writeTextFile(int max, char longest[], const char *filename){

    FILE *tfile = fopen(filename, "w");

    if (!tfile){
        printf("Failed to open the file.\n");
        return 0;
    }

    fprintf(tfile, "%d\n", max);
    fprintf(tfile, "%s\n", longest);

    fclose(tfile);
    return 1;
}

int writeBinFile(int max, char longest[], const char *filename){

    FILE *bfile = fopen(filename, "wb");

    fwrite(&max, sizeof(int), 1, bfile);

    fwrite(longest, 1, max, bfile);

    fclose(bfile);
    return 1;
}