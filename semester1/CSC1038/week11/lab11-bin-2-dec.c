//lab11-bin-2-dec.c
// Author: Petra Sartori
// 20/11/2025

/*This program accepts up to 8 binary digits (0 or 1) and converts them
into their decimal equivalent*/

// libraries required for this task, not using math.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// defining a Node structure which I will be using for a linked list
typedef struct Node {
    int bit; // value
    struct Node *next; // pointer to the next node
}Node;

// function prototype
void convert(Node *head, int *result);

int main(int argc, char *argv[]){
    
    // the number of digits (-1 to not include the name of the program)
    int digits = argc - 1;

    // handling a case where there is too many digits in input
    if (digits > 8){
        printf("Too many binary digits entered.\n");
        return 0;
    }

    // initialising head and tail of a linked list
    Node *head = NULL;
    Node *tail = NULL;

    // handling a case where the input contains non-binary digits (!= 0 or 1)
    for (int i = 1; i < argc; i++){
        if(strcmp(argv[i], "0") != 0 && strcmp(argv[i], "1") != 0) {
            printf("Only digits 1 and 0 are permitted.\n");
            return 0;
        }
    

        // dynamic memory allocation for a new node
        Node *newNode = malloc(sizeof(Node));
        if (!newNode){
            printf("Memory allocation failed.\n");
            return 1;
        }

        // storing a bit
        newNode->bit = argv[i][0];
        newNode->next = NULL;

        // if the node we're saving is the first node it's going to be both the head and the tail
        // otherwise we extend the linked list by putting the pointer of the current tail to a new node
        // and we make the newest node a tail
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    // calling the convert function and passing the head of a linked list and the result
    int result = 0;
    convert(head, &result);

    printf("%d\n", result);

    // freeing the memory after use
    // we have to do it in a loop for each node of a linked list
    Node *temp;
    while (head != NULL){
        temp = head->next;
        free(head);
        head = temp;
    }

    return 0;
}

// convert function takes a string of 0's and 1's and converts them to their decimal form
void convert(Node *head, int *result){
    *result = 0;

    Node *current = head;
    
    while(current != NULL){
        *result <<= 1; // shifting the result to the left to make space for the next bit

        // if the next bit is 1, we set the lowest bit using OR operation
        // we're appending it to the end of the binary number
        // if it's 0 we do nothing since result is 0 to start with
        if (current -> bit == '1'){
            *result |= 1; 
        }

        current = current->next;
    }
}