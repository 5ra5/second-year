// lab9-push-pop.c
// Author: Petra Sartori
// Date: 8 November 2025

// libraries I need for this task
#include <stdio.h>
#include <stdlib.h>

// initialising a Node structure
typedef struct Node Node;

// using a singly linked list for this task because I'm essentially making a stack
struct Node{
    int value;
    Node *next;
};

// function prototypes
Node* get_numbers(int argc, char *argv[], Node *start);
void print_numbers(Node *start);
void push(int number, Node *start);
void pop(Node *last);

// main function just calls other functions
int main(int argc, char *argv[])
{
    Node *start = NULL; // initialising a pointer to the Node struct
    
    // numbers i'm passing to push
    int number1 = atoi(argv[argc - 2]);
    int number2 = atoi(argv[argc - 1]);

    start = get_numbers(argc, argv, start); // reading in the initial list
    
    // popping twice
    pop(start);
    pop(start);

    // pushing the last two numbers from input
    push(number1, start);
    push(number2, start);

    print_numbers(start); // printing the final list
    return 0;
}

// get_numbers takes specified values and stores them in a linked list
// specified values: the number of values given from the first argument in the command line
Node* get_numbers(int argc, char *argv[], Node *start)
{
    Node *current, *first;
    int length = atoi(argv[1]);

    // first node
    first = (Node*)calloc(1, sizeof(Node));
    current = first;
    current->value = atoi(argv[2]);


    // the rest of the nodes, we're stopping at the index that is specified in the first argument
    for(int i = 2; i <= length; i++)
    {
        current->next = (Node*)calloc(1, sizeof(Node));
        current = current->next;
        current->value = atoi(argv[i + 1]);
    }
    current->next = NULL;
    return first; // returning the address of the first node
}

// function push takes a number we want to push and a pointer to the list, and then adds that number to the end
// of the linked list
void push(int number, Node *start)
{
    Node *temp = start;

    // creating a new node
    Node *new = (Node*)calloc(1, sizeof(Node));
    new->value = number;
    new->next = NULL;
    
    // traversing to the last node
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    // adding a new node to the end of the list
    temp->next = new;
}

// function pop takes a pointer to the list and deletes the last node
void pop(Node *start)
{
    Node *temp = start;
    Node *prev; // initialising a previous node to the temporary one

    // traversing to the last node
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    // deleting the number
    // the value of the next node is now NULL
    prev->next = NULL;
    free(temp); // letting go of the memory that was used for that node
    
}

// function print_numbers prints all nodes of the linked list line by line
void print_numbers(Node *start)
{
    Node* p = NULL;
    for(p = start; p != NULL; p = p->next)
    {
        printf("%d\n", p->value);
    }
}

