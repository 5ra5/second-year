// ex2-patient-queue.c (practice after the exam)
// Author: Petra Sartori
// Date: 5/12/2025

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

Patient* get_patients(int argc, char *argv[]);
int count_highs(Patient *head);
void print_patients(Patient *head, int high_priority);
void free_patients(Patient *head);

int main(int argc, char *argv[])
{
    Patient *head = NULL;
    head = get_patients(argc, argv);
    int high_priority = count_highs(head);
    print_patients(head, high_priority);
    free_patients(head);

    return 0;
}

Patient* get_patients(int argc, char *argv[])
{
    int size = atoi(argv[1]);
    Patient *current, *head;

    head = calloc(1, sizeof(Patient));
    current = head;
    current->id = 1;
    strcpy(current->name, argv[2]);
    current->priority = atoi(argv[3]);

    int index = 0;

    for (int i = 1; i < size; i++)
    {
        current->next = calloc(1, sizeof(Patient));
        current = current->next;
        current->id = i+1;
        strcpy(current->name, argv[index+4]);
        current->priority = atoi(argv[index+5]);
        index += 2;
    }
    current->next = NULL;
    return head;
}

int count_highs(Patient *head)
{
    int sum = 0;

    Patient *p = NULL;
    for(p = head; p != NULL; p = p->next)
    {
        if(p->priority >= 4)
        {
            sum++;
        }
    }

    return sum;
}

void print_patients(Patient *head, int high_priority)
{
    Patient *p = NULL;
    for(p = head; p != NULL; p = p->next)
    {
        printf("ID: %d, Name: %s, Priority: %d\n", p->id, p->name, p->priority);
    }
    printf("High priority count: %d\n", high_priority);
}

void free_patients(Patient *head)
{
    while(head)
    {
        Patient *tmp = head;
        head = head->next;
        free(tmp);
    }
}