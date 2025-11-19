// lab9-integer-singly-linked-list.c
// Author: Petra Sartori
// Date: 6 November 2025

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
    int value;
    Node *next;
};

// Function prototypes
Node* get_numbers(int argc, char *argv[], Node *start);
void print_numbers(Node *start);

int main(int argc, char *argv[])
{
    Node *start = NULL;

    start = get_numbers(argc, argv, start);
    print_numbers(start);
    return 0;
}

Node* get_numbers(int argc, char *argv[], Node *start)
{
    Node *current, *first;

    first = (Node*)calloc(1, sizeof(Node));
    current = first;

    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = (Node*)calloc(1, sizeof(Node));
    current = current->next;
    current->value = value;

    current->next = NULL;
    return first;
}

void print_numbers(Node *start)
{
    int count = 0;
    Node* p = NULL;
    for(p = start; p != NULL; p = p->next)
    {
        ++count;
        printf("%d\n", p->value);
    }
}