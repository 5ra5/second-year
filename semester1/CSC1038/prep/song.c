#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char *song;
    struct Node *next;
}Node;

Node* buildList(int length, char*argv[]);
void printList(Node *head);
void freeSongs(Node *head);

// get the length, initialise node *head by calling a function to build a list starting from argv[1]
int main(int argc, char *argv[]){

    int length = argc - 1;
    Node* head = buildList(length, &argv[1]);
    printList(head);
    freeSongs(head);

    return 0;
}

// build a singly linked list with songs (arrays of characters)
Node* buildList(int length, char*argv[])
{
    Node *head = NULL;
    Node *tail = NULL;

    for(int i = 0; i < length; ++i)
    {
        // create a new node
        Node *newNode = calloc(1, sizeof(Node));
        if (!newNode){
            printf("Calloc failed!\n");
        }

        // allocate memory for the name
        newNode->song = malloc(strlen(argv[i]) + 1);
        strcpy(newNode->song, argv[i]);

        newNode->id = 
        newNode->next = NULL;

        // append to list
        if(tail){
            tail->next = newNode;
        }else{
            head = newNode;
        }
        tail = newNode;
    }

    return head;
}

// iterate through the list and print
void printList(Node *head){
    Node *current = head;
    while (current) {
        printf("ID: %d, Name: %s, Priority: %d\n", current->id, current->name, current->priority);
        current = current->next;
    }
}

// free the memory after using
void freeList(Node *head){
    Node *current = head;
    while(current){
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}



