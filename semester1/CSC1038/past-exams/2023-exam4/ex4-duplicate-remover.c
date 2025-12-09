#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
};

Node* get_numbers(int argc, char *argv[]);
void remove_all_duplicates(Node **head);
void print_numbers(Node *head);
void free_numbers(Node *head);

int main(int argc, char *argv[])
{
    Node *head = get_numbers(argc, argv);
    remove_all_duplicates(&head);

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

// Delete all nodes whose value occurs more than once
void remove_all_duplicates(Node **head)
{
    Node *current = *head;

    while(current)
    {
        int count = 0;
        Node *p = *head;
        // Count occurrences of current->value
        while(p)
        {
            if(p->value == current->value)
                count++;
            p = p->next;
        }

        if(count > 1)
        {
            // Delete all nodes with this value
            Node *tmp = *head;
            Node *prev = NULL;

            while(tmp)
            {
                if(tmp->value == current->value)
                {
                    Node *to_delete = tmp;
                    if(prev)
                        prev->next = tmp->next;
                    else
                        *head = tmp->next;

                    tmp = tmp->next;
                    free(to_delete);
                }
                else
                {
                    prev = tmp;
                    tmp = tmp->next;
                }
            }

            // Restart from head after deletion
            current = *head;
        }
        else
        {
            current = current->next;
        }
    }
}

void print_numbers(Node *head)
{
    Node *p = head;
    while(p)
    {
        printf("%d\n", p->value);
        p = p->next;
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
