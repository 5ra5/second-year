#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char name[20];
    printf("Please type in your name: ");
    scanf("%s", name);

    printf("Hello\n%s\n", name);
    return (0);
}