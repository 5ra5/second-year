#include<stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{
    char str[] = "hello world";
    unsigned count = 0;

    while((str[count] != '\0'))
    {
        if(str[count] != 32){
            ++count;
        }
    }

    printf("The length of the string...");

    return 0;
}