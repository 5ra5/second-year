#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
};

Node* get_numbers(int argc, char *argv[]);
int sum_evens(Node *start);
void free_list(Node *start);

int main(int argc, char *argv[])
{
    Node *start = NULL;
    start = get_numbers(argc, argv);
    int sum = sum_evens(start);
    free_list(start);

    printf("%d\n", sum);
    return 0;
}

Node* get_numbers(int argc, char *argv[])
{
    Node *first = NULL;
    Node *current = NULL;

    for (int i = 1; i < argc; i++) {
        Node *new_node = calloc(1, sizeof(Node));

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

int sum_evens(Node *start)
{
    int sum = 0;

    Node *p = NULL;
    for(p = start; p != NULL; p = p->next)
    {
        if(p->value % 2 == 0)
        {
            sum += p->value;
        }
    }

    return sum;
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