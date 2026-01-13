// lab9-float-doubly-linked-list.c
// Author: Petra Sartori
// Date: 8 November 2025

// libraries I need for this task
#include <stdio.h>
#include <stdlib.h>

// initialising a Node structure
typedef struct Node Node;

struct Node{
    float value;
    Node *next;
    Node *prev; // this time we are storing a previous value as well
};

// Function prototypes
Node* get_numbers(int argc, char *argv[], Node *start);
void print_numbers(Node *start);

// main function just calls functions I wrote to read and print values for a linked list
int main(int argc, char *argv[])
{
    Node *start = NULL; // initialising a pointer to the Node struct

    start = get_numbers(argc, argv, start);
    print_numbers(start);
    return 0;
}

Node* get_numbers(int argc, char *argv[], Node *start)
{
    Node *current, *first, *prev;

    int length = atoi(argv[1]); // the length of input is given as the first number in input

    first = (Node*)calloc(1, sizeof(Node)); // first node, dynamic memory allocation
    current = first; // at the start the current node is also the first one
    current->value = atoi(argv[2]); // the first node is given as the second number in input
    current->prev = NULL;

    // processing the rest of the nodes, starting from index 3
    for(int i = 2; i <= length; i++)
    {
        current->next = (Node*)calloc(1, sizeof(Node)); // dynamic memory allocation for each
        prev = current; // current becomes previous
        current = current->next; // the node that's next to it becomes current
        current->value = atoi(argv[i + 1]); // we read the value for that current
        current->prev = prev; // current is now previous again
    }
    current->next = NULL; // last node
    return current; // returning the address of the last node
}

// print_numbers function prints the values in reversed order
void print_numbers(Node *last)
{
    Node* p = NULL;
    // starting from the last value and iterating in reverse by using a pointer to a previous value
    for(p = last; p != NULL; p = p->prev)
    {
        printf("%.2f\n", p->value);
    }
}