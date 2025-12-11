// ex3-remove-duplicates.c
// Author: Petra Sartori
// Date: 10 December 2025

// This program takes integers from the command line and stores them in a singly linked list using dynamic memory allocation.
// It iterates through the linked list recording the occurence of each character, and if the occurence is greater than 1, it removes all
// of the duplicates from the list.

// Required libraries for this task:
#include <stdio.h>
#include <stdlib.h>

// Defining the struct Node which stores the value of the integer and the pointer to the next node.
typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
};

// Function prototypes: more explanation about functions below
Node* get_numbers(int argc, char *argv[]);
void remove_all_duplicates(Node **head);
void print_numbers(Node *head);
void free_numbers(Node *head);

// Main function calls all of the other functions by passing arguments.
int main(int argc, char *argv[])
{
    // Node *head is the pointer to the head of the linked list.
    Node *head = get_numbers(argc, argv);
    remove_all_duplicates(&head);

    print_numbers(head);
    free_numbers(head);
    return 0;
}

// Function get_numbers takes argc and *argv[] because it processes integers from the command line.
// It creates dynamically allocates memory for each new node in a loop, and stores values of integers into a newly made node.
// It returns a pointer to the first node in the linked list (head).
Node* get_numbers(int argc, char *argv[])
{
    // First is a pointer to the first node of the linked list - a head
    // Current is a pointer to the node we are currently working with - it can also be referred to as a tail of the list
    // They are initialised to NULL at the start before we read any values in.
    Node *first = NULL;
    Node *current = NULL;

    for (int i = 1; i < argc; i++)
    {
        // Using calloc to allocate enough memory for one node the size of Node.
        Node *new_node = calloc(1, sizeof(Node));

        // Checking if memory allocation was successful. If it is not, print a error message and exit the code.
        if (!new_node)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        // Assigning the value of the node as argv[i] as we iterate through the input. The pointer to the next value is NULL.
        // This is because the current value is now at the end of the list.
        new_node->value = atoi(argv[i]);
        new_node->next = NULL;

        // Special case where there is no nodes in the linked list - the current node is also the head of the node.
        if(!first)
        {
            first = new_node;
            current = new_node;
        }
        else
        {
            // Normally appending the node to the end of the list.
            current->next = new_node;
            current = new_node;
        }
    }
    // Returning a pointer to the first node of the linked list.
    return first;
}

// Remove all duplicates function takes a double pointer of a head in case the head changes.
// It iterates thorugh every node, recording a count of its occurrence.
void remove_all_duplicates(Node **head)
{
    // Starting iteration from the head of the list
    Node *current = *head;

    // While there is nodes in the list - do the operation
    while(current)
    {
        // Initialising count to 0
        int count = 0;
        Node *p = *head;

        // Count occurrences of current->value
        while(p)
        {
            if(p->value == current->value)
                count++;
            p = p->next;
        }

        // If the occurence is greater than 1:
        if(count > 1)
        {
            // Delete all nodes with this value
            Node *tmp = *head;
            
            // Keeping a pointer to the previous value for easier deletion
            Node *prev = NULL;

            while(tmp)
            {
                // If the value we're iterating through currently is the same as the current value, we delete it.
                if(tmp->value == current->value)
                {
                    // Clarifying which to delete
                    Node *to_delete = tmp;

                    // If there is a previous node - if the node is not the head, move the pointer
                    if(prev)
                        prev->next = tmp->next;
                    else
                        // make the next value the head of the list if there is no previous value
                        *head = tmp->next;

                    tmp = tmp->next;

                    // Free the memory to delete the node
                    free(to_delete);
                }
                else
                {
                    // Continue iterating
                    prev = tmp;
                    tmp = tmp->next;
                }
            }

            // Restart from head after deletion because the linked list is changed, so another iteration is needed
            current = *head;
        }
        else
        {
            // If there is no duplicates, continue iterating.
            current = current->next;
        }
    }
}

// Function print_numbers iterates through the linked list starting from the head and prints the value of the node.
void print_numbers(Node *head)
{
    Node *p = head;
    while(p)
    {
        // Print the value
        printf("%d\n", p->value);

        // Continue iterating
        p = p->next;
    }
}

// Function free_numbers frees the memory that was allocated for the nodes of the linked list one by one, starting from the head.
// The process is similar to deletion as it uses a tmp value and frees the memory of the tmp value after the pointers of the current value are changed.
void free_numbers(Node *head)
{
    while(head)
    {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }
}
