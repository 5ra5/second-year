# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int count(char c, char *sentence);

int main(int argc, char *argv[])
{
    // get the first character of argv[1]
    char c = argv[1][0];

    char sentence[50];
    strcpy(sentence, argv[2]);

    int number = count(c, sentence);
    printf("%d\n", number);
}

int count(char c, char *sentence)
{
    int countt = 0;
    for(int i = 0; sentence[i] != '\0'; i++)
    {
        if(sentence[i] == c)
        {
            countt++;
        }
    }

    return countt;
}