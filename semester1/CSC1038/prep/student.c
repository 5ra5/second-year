#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student Student;

struct Student
{
    char name[20];
    char programme[20];
    float grade;
    Student *next;
};

Student* get_students(int argc, char *argv[]);
float get_average(Student *head, int numStudents);
void print_students(Student *head, float average);
void free_students(Student *head);

int main(int argc, char *argv[])
{
    int numStudents = (argc - 1) / 3;
    Student *head = get_students(argc, argv);
    float average = get_average(head, numStudents);
    print_students(head, average);
    free_students(head);
}

Student* get_students(int argc, char *argv[])
{
    int numStudents = (argc - 1) / 3;
    Student *head = NULL;
    Student *current = NULL;

    for (int i = 0; i < numStudents; i++)
    {
        Student *new_student = calloc(1, sizeof(Student));
        if (!new_student)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        int base = 1 + i*3;
        strcpy(new_student->name, argv[base]);
        strcpy(new_student->programme, argv[base+1]);
        new_student->grade = atof(argv[base+2]);
        new_student->next = NULL;

        if (!head)
        {
            head = new_student;
            current = new_student;
        }
        else
        {
            current->next = new_student;
            current = new_student;
        }
    }

    return head;
}

float get_average(Student *head, int numStudents)
{
    float sum = 0.0f;

    Student *s = NULL;
    for(s = head; s != NULL; s = s->next)
    {
        sum += s->grade;
    }

    return sum / numStudents;
}

void print_students(Student *head, float average)
{
    Student *s = NULL;
    for(s = head; s != NULL; s = s->next)
    {
        if(s->grade > average)
        {
            printf("%s, %s, %.2f\n", s->name, s->programme, s->grade);
        }
    }
    printf("Average grade: %.2f\n", average);
}

void free_students(Student *head)
{
    while(head)
    {
        Student *tmp = head;
        head = head->next;
        free(tmp);
    }
}