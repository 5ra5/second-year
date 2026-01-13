# include <stdio.h>
# include <stdlib.h>

typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
    Node *prev;
};

Node* get_numbers(int argc, char *argv[]);
void delete_evens(Node **head);
int sum_odds(Node *head);
void push(int sum, Node *head);
void print_numbers(Node *head);
void free_numbers(Node *head);

int main(int argc, char *argv[])
{
    Node *head = get_numbers(argc, argv);
    delete_evens(&head);
    int sum = sum_odds(head);
    push(sum, head);
    print_numbers(head);
    free_numbers(head);
}

Node* get_numbers(int argc, char *argv[])
{
    Node *head = NULL;
    Node *tail = NULL;

    for(int i = 1; i < argc; i++)
    {
        Node *node = calloc(1, sizeof(Node));
        if(!node)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        node->value = atoi(argv[i]);

        if (!head)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    return head;
}

void delete_evens(Node **head)
{
    Node *current = *head;

    while(current)
    {
        if(current->value % 2 == 0)
        {
            Node *del = current;

            if(current == *head)
            {
                *head = current->next;
            }

            if(current->prev)
            {
                current->prev->next = current->next;
            }

            if(current->next)
            {
                current->next->prev = current->prev;
            }

            current = current->next;
            free(del);
        }
        else
        {
            current = current->next;
        }
    }
}

int sum_odds(Node *head)
{
    int sum = 0;
    Node *current = head;

    while(current)
    {
        if(current->value % 2 != 0)
        {
            sum += current->value;
        }
        current = current->next;
    }

    return sum;
}

void push(int sum, Node *head)
{
    Node *current = head;

    Node *new = calloc(1, sizeof(Node));
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

void print_numbers(Node *head)
{
    for(Node *p = head; p != NULL; p = p->next)
    {
        printf("%d\n", p->value);
    }
}

void free_numbers(Node *head)
{
    while(head)
    {
        Node *next = head->next;
        free(head);
        head = next;
    }
}