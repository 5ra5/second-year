// lab10-load-binary.c
// Author: Petra Sartori
// Date: 14/11/2025

/* This program reads the information about students from a binary file and
displays it. */

// Libraries I need for this task
#include <stdio.h>
#include <stdlib.h>

// Defining the Student struct that contains 4 elements
// Name, College, Age and Grade
typedef struct Student Student;

struct Student{
    int name_length;
    char name[50];
    int college_length;
    char college[50];
    int age;
    float grade;
};

// Function prototype
void read_data(FILE *pfile, char *filename, Student s);

// Main function initialises the pointer to a file we're reading from
// It also calls the read_data function
int main()
{
    FILE *pfile = NULL; // Pointer to a file we're working with
    char *filename = "studentBinary.bin";

    Student s;

    read_data(pfile, filename, s);

    return 0;
}

// read_data function takes the pointer to the file, it's name and the Student struct
// It reads the data from the binary file
// It prints the data
void read_data(FILE *pfile, char *filename, Student s)
{
    // Opening the binary file in read binary mode - "rb"
    pfile = fopen(filename, "rb");

    // Handling the case where the file doesn't exist
    if(!pfile)
    {
        printf("Failed to open %s.\n", filename);
        return;
    }

    // Reading the data one by one
    // First I'm reading the length of the name
    int count1 = fread(&s.name_length, sizeof(int), 1, pfile);
    // Now the length of the name is used as the number of array elements instead of 1
    int count2 = fread(s.name, sizeof(char), s.name_length, pfile);
    
    // Doing the same for college since it's a string as well
    int count3 = fread(&s.college_length, sizeof(int), 1, pfile);
    int count4 = fread(s.college, sizeof(char), s.college_length, pfile);
    
    // Reading the age and grade normally
    int count5 = fread(&s.age, sizeof(int), 1, pfile);
    int count6 = fread(&s.grade, sizeof(float), 1, pfile);

    // Closing the pfile after I'm done
    fclose(pfile);

    // Printing the information
    printf("Name: %s\n", s.name);
    printf("College: %s\n", s.college);
    printf("Age: %d\n", s.age);
    printf("Grade: %.2f\n", s.grade);
}