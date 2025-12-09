#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int value;
    struct DNode *next;
    struct DNode *prev;
} DNode;

DNode* get_numbers(int argc, char *argv[]);
void print_numbers_forward(DNode *start);
void print_numbers_backward(DNode *end);
void delete_node(DNode **head, int val);
void free_list(DNode *start);

int main(int argc, char *argv[])
{
    DNode *head = get_numbers(argc, argv);

    print_numbers_forward(head);

    // find tail for backward printing
    DNode *tail = head;
    while (tail && tail->next)
        tail = tail->next;

    print_numbers_backward(tail);

    delete_node(&head, 5); // example

    free_list(head);
    return 0;
}

DNode* get_numbers(int argc, char *argv[])
{
    DNode *head = NULL;
    DNode *tail = NULL;

    for (int i = 1; i < argc; i++) {
        DNode *node = calloc(1, sizeof(DNode));
        if (!node) exit(1);

        node->value = atoi(argv[i]);

        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    return head;
}

void print_numbers_forward(DNode *start)
{
    for (DNode *p = start; p != NULL; p = p->next)
        printf("%d\n", p->value);
}

void print_numbers_backward(DNode *end)
{
    for (DNode *p = end; p != NULL; p = p->prev)
        printf("%d\n", p->value);
}

void delete_node(DNode **head, int val)
{
    DNode *curr = *head;

    while (curr) {
        if (curr->value == val) {
            DNode *del = curr;

            // update head
            if (curr == *head)
                *head = curr->next;

            // fix neighbors
            if (curr->prev)
                curr->prev->next = curr->next;

            if (curr->next)
                curr->next->prev = curr->prev;

            curr = curr->next;
            free(del);
        } else {
            curr = curr->next;
        }
    }
}

void free_list(DNode *start)
{
    while (start) {
        DNode *next = start->next;
        free(start);
        start = next;
    }
}

void push(int sum, DNode *head)
{
    DNode *current = head;

    DNode *new = calloc(1, sizeof(DNode));
    if (!new)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    new->value = sum;
    new->next = NULL;

    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = new;
}

// function pop takes a pointer to the list and deletes the last node
void pop(DNode *start)
{
    DNode *temp = start;
    DNode *prev; // initialising a previous node to the temporary one

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

/* ---------------------------
   PARTITIONING (stable, in-place)
   --------------------------- */

DNode* partition_list(DNode *head, int (*predicate)(int))
{
    DNode *yes_head = NULL, *yes_tail = NULL;
    DNode *no_head  = NULL, *no_tail  = NULL;

    DNode *curr = head;

    while (curr) {
        DNode *next = curr->next;
        curr->next = curr->prev = NULL;  // detach

        if (predicate(curr->value)) {
            if (!yes_head) yes_head = yes_tail = curr;
            else {
                yes_tail->next = curr;
                curr->prev = yes_tail;
                yes_tail = curr;
            }
        } else {
            if (!no_head) no_head = no_tail = curr;
            else {
                no_tail->next = curr;
                curr->prev = no_tail;
                no_tail = curr;
            }
        }

        curr = next;
    }

    // Stitch lists
    if (yes_tail) {
        yes_tail->next = no_head;
        if (no_head) no_head->prev = yes_tail;
        return yes_head;
    }

    return no_head;
}
