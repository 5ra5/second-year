#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
};

Node* get_numbers(int argc, char *argv[]);
void remove_duplicates(Node *head);
void print_numbers(Node *head);
void free_numbers(Node *head);

int main(int argc, char *argv[])
{
    Node *head = NULL;
    head = get_numbers(argc, argv);
    remove_duplicates(head);

    print_numbers(head);
    free_numbers(head);
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

        if(!first)
        {
            first = new_node;
            current = new_node;
        }
        else
        {
            current->next = new_node;
            current = new_node;
        }
    }

    return first;
}

void remove_duplicates(Node *head)
{
    Node *current = head;
    while(current && current->next)
    {
        if(current->value == current->next->value)
        {
            Node *temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        else
        {
            current = current->next;
        }
    }
}

void print_numbers(Node *head)
{
    Node *p = NULL;
    for(p = head; p != NULL; p = p->next)
    {
        printf("%d\n", p->value);
    }
}

void free_numbers(Node *head)
{
    while(head)
    {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }
}