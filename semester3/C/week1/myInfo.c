/*Include standard input and output*/
#include <stdio.h>
/*
Function: Main
Parameters: none
returns: int
description: Declare and print out some variables with different types
*/

int main(int argc, char*argv[])

{
    int age = 30;
    unsigned long studentId = 17312594;
    float height = 1.75f;
    char initial = 'T';
    char first_name[10] = "Tai";
    char last_name[10] = "Mai";

    printf("I have a first name %s. \n", first_name);
    printf("I have a last name %s.\n", last_name);
    printf("I have an initial %c.\n", initial);
    printf("My whole name is %s %c. %s.\n", first_name, initial, last_name);
    printf("I am %d years old\n", age);
    printf("I am %f m tall.\n", height);
    printf("My student ID is %lu.\n", studentId);

    float monthlySalary;
    double annualSalary;

    monthlySalary = 3456.78;
    annualSalary = monthlySalary*12;

    printf("My monthly salary is %f euros.\n", monthlySalary);
    printf("My annual gross salary is %f euros.\n", annualSalary);

    return 0;
}