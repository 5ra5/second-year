#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Patient Patient;

struct Patient
{
    int id;
    char name[50];
    int priority;
    Patient *next;
};

int main(int argc, char *argv[])
{
    Patient *patient;
    return 0;
}