// lab7-student.c
// Petra Sartori

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining a Student structure
typedef struct{

    char name[20];
    char programme[20];
    float grade;

}Student;

// function prototypes
void read_input(int n, char *argv[], Student *students);
void print_students(int n, Student *students);

// main function - using malloc() and realloc() to dynamically allocate
// memory for more students to join
int main(int argc, char*argv[]){

    int n = (argc - 1) / 3; // student count: number of arguments divided by 3 because student struct has 3 elements

    int capacity =2; // expecting 2 students
    Student *students = malloc(capacity * sizeof(Student));

    if (!students) {
        printf("Memory allocation fail\n");
        return 1;
    }

    // if there is more than 2 students in input, expand memory using realloc()
    if(n > capacity){
        students = realloc(students, n * sizeof(Student));

        if (!students){
            printf("Memory allocation fail\n");
            return 1;
        }
        capacity = n;
    }

    read_input(n, argv, students);
    print_students(n, students);

    free(students);
    return 0;

}

// function that reads input and adds it to the struct array
void read_input(int n, char *argv[], Student *students){

    for (int i = 0; i < n; i++){
       strcpy(students[i].name, argv[i * 3 + 1]);
       strcpy(students[i].programme, argv[i * 3 + 2]);
       students[i].grade = atof(argv[i * 3 + 3]);
    }
}

// function that prints all elements of the struct array
void print_students(int n, Student *students){

    for(int i = 0; i < n; i++){
        printf("%s, %s, %.2f\n", students[i].name, students[i].programme, students[i].grade);
    }
}
    