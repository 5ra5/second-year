#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
};

Node* get_numbers(int argc, char *argv[]);
void print_numbers(Node *start);
void free_list(Node *start);

int main(int argc, char *argv[])
{
    Node *start = NULL;
    start = get_numbers(argc, argv);
    print_numbers(start);
    free_list(start);
    return 0;
}

Node* get_numbers(int argc, char *argv[])
{
    Node *first = NULL;
    Node *current = NULL;

    for (int i = 1; i < argc; i++) 
    {
        Node *new_node = calloc(1, sizeof(Node));
        if (!new_node) exit(1);

        new_node->value = atoi(argv[i]);
        new_node->next = NULL;

        if (!first) {
            first = new_node;
            current = new_node;
        } else {
            current->next = new_node;
            current = new_node;
        }
    }

    return first;
}

void print_numbers(Node *start)
{
    Node *p = NULL;
    for(p = start; p != NULL; p = p->next)
    {
        printf("%d\n", p->value);

    }
}

void free_list(Node *start)
{
    while(start)
    {
        Node *tmp = start;
        start = start->next;
        free(tmp);
    }
}

void delete_node(Node **head, int val) {
    // Special case: first node
    while (*head && (*head)->value == val) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    Node *current = *head;
    while (current && current->next) {
        if (current->next->value == val) {
            Node *temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}


// PARTITIONING - use when you are not sorting by value
// in place and stable

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node* partition_list(Node *head, int (*predicate)(int)) 
{
    Node *yes_head = NULL, *yes_tail = NULL;
    Node *no_head  = NULL, *no_tail  = NULL;

    Node *curr = head;

    while (curr != NULL) {
        Node *next = curr->next;   // save next pointer
        curr->next = NULL;         // detach current node (important)

        if (predicate(curr->value)) {
            // append to YES list
            if (!yes_head) {
                yes_head = yes_tail = curr;
            } else {
                yes_tail->next = curr;
                yes_tail = curr;
            }
        } else {
            // append to NO list
            if (!no_head) {
                no_head = no_tail = curr;
            } else {
                no_tail->next = curr;
                no_tail = curr;
            }
        }

        curr = next;  // move forward
    }

    // Stitch lists together: YES first, then NO
    if (yes_tail)
        yes_tail->next = no_head;

    // Return new head (YES list if exists, else NO list)
    return yes_head ? yes_head : no_head;
}
