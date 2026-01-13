// lab9-inside-the-queue.c
// Author: Petra Sartori
// Date: 8 November 2025

// libraries i need for this task
#include <stdio.h>
#include <stdlib.h>

// initialising a node structure
typedef struct Node Node;

// using a singly linked list for this task, so i
struct Node
{
    int value;
    Node *next;
};

// function prototypes
void print_numbers(Node *start);
void insert(int index, int number, Node *start);

// main function holds the linked lists i'm working with
// it also calls the insert and print functions
int main(int argc, char *argv[])
{
    // hard coding the linked list i'm working with
    Node node10 = {12, NULL};
    Node node9 = {14, &node10};
    Node node8 = {2, &node9};
    Node node7 = {9, &node8};
    Node node6 = {6, &node7};
    Node node5 = {5, &node6};
    Node node4 = {4, &node5};
    Node node3 = {3, &node4};
    Node node2 = {7, &node3};
    Node node1 = {8, &node2};

    Node *start = &node1; // the first node is now the start

    // a position of the number we want to insert the new node behind
    int index = atoi(argv[1]);

    // a number we want to insert
    int number = atoi(argv[2]);

    insert(index, number, start);
    print_numbers(start);

    return 0;
}

// insert function takes index, number and the addres of the first node of the linked list
// it traverses through the list until it gets to the position we want to insert after
// it creates a new node and inserts it in the specified index
void insert(int index, int number, Node *start)
{
    Node *current = start;

    // loop while the current value is not the same as the one we gave the function
    while(current != NULL && current->value != index)
    {
        current = current->next;
    }
    
    // we found the value we want to insert behind
    // making a new node
    Node *new = calloc(1, sizeof(Node));
    new->value = number;

    // setting a new pointer to the next node
    new->next = current->next;
    current->next = new;
}

void print_numbers(Node *start)
{
    Node* p = NULL;
    for(p = start; p != NULL; p = p->next)
    {
        printf("%d\n", p->value);
    }
}

