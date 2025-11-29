// ex2-patient-queue.c
// Author: Petra Sartori
// Date: 27/11/2025

// This program takes the priority and name of a patient from the input, stores the information in a linked list and prints it.
// It also assigns ID number to each patient.

// The program does not run as it gives me segmentation fault, but this is my solution for Task 1.

// Libraries needed for this program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// initialise a struct: include a pointer to previous and next node
typedef struct Patient {
    int id;
    char name[50];
    int priority;
    struct Patient *prev; // pointer to the previous patient
    struct Patient *next; // pointer to the next patient
} Patient;

// function prototypes
Patient* createPatient(char *name, int priority, int id);
void appendPatient(Patient **head, Patient **tail, Patient *newPatient);
void printPatients(Patient *head, int count);
void freePatients(Patient *head);
int countHighPriority(Patient *head);


int main(int argc, char *argv[]){
    
    // initialise a head and a tail pointer
    Patient *head = NULL;
    Patient *tail = NULL;

    // loop to get the data from the command line - then pass it to functions
    for (int i = 1; i < argc; i += 2){
        int j = 1;
        int priority = atoi(argv[i]);
        char *name = argv[i + 1];

        // assign ID to each new patient
        int id = j;
        j++;

        // make a new node and append a node to a doubly linked list
        Patient *newPatient = createPatient(name, priority, id);
        appendPatient(&head, &tail, newPatient);
    }

    // calculate the high priority count and print the information
    int count = countHighPriority(head);
    printPatients(head, count);

    // free the memory used in the program
    freePatients(head);

    return 0;
}

// create a new patient node
Patient* createPatient(char *name, int priority, int id){
    
    // allocate memory for a new node, and handle a case where there is no data
    Patient *newPatient = malloc(sizeof(Patient));
    if (!newPatient){
        printf("Memory allocation for a patient failed!\n");
    }

    // borrow memory for the name since it's a string
    newPatient->name = malloc(20 * strlen(name));

    // handling a case where memory allocation fails
    if(!newPatient->name){
        printf("Memory allocation for patient name\n");
    }

    // copy the value for name
    strcpy(newPatient->name, name);

    // get the value for priority and set prev and next to NULL
    newPatient->priority = priority;
    newPatient->id = id;
    newPatient->prev = NULL;
    newPatient->next = NULL;

    // return the node
    return newPatient;
}

// append a patient node to the doubly linked list
// pass a double pointer of head and tail since they were originally pointers
void appendPatient(Patient **head, Patient **tail, Patient *newPatient){

    // the previous node of a new node is the tail of the list
    // the next node of a new node is NULL
    newPatient->prev = *tail;
    newPatient->next = NULL;

    // set the pointer of the previous tail to point to the new node
    // if there is no tail, then the new node is both head and the tail
    if(*tail){
        (*tail)->next = newPatient;
    }else{
        *head = newPatient;
    }

    // in both cases, the new node becomes the new tail of the list
    *tail = newPatient;
}

// this function iterates through the list and prints information about patients
void printPatients(Patient *head, int count){
    
    // iterate through the list and print all patients
    Patient *current = head;
    
    while(current){
        printf("ID: %d, Name: %s, Priority: %d\n", current->id, current->name, current->priority);
        current = current->next;
    }

    // print the count of high priority patients
    printf("Hight priority count: %d\n", count);
}

// this function iterates though the list and increments a count
// whenever the priority is greater or equal to 4
// it returns the count at the end
int countHighPriority(Patient *head){
    
    Patient *current = head;
    int count = 0;
    
    while(current){
        if (current->priority >= 4)
        {
            count++;
        }
    }
    return count;
}

// free the memory used for a linked list
void freePatients(Patient *head){
    Patient *current = head;
    while(current){
        Patient *temp = current;
        // following lines are commented out because the program doesn't compile with them
        //free(temp->id);
        free(temp->name);
        //free(temp->priority);
        current = current->next;
        free(temp);
    }
}