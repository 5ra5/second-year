#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])

{
    int student_id = 0;

    printf("Input your student ID: ");
    scanf("%d", &student_id);

    printf("This is your student ID %d\n", student_id);

    return(0);
}