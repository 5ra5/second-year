# include <stdio.h>
# include <stdlib.h>

typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
};

Node* get_numbers(int argc, char *argv[]);
int find_degree(Node *head);
void free_numbers(Node *head);

int main(int argc, char *argv[])
{
    Node *head = get_numbers(argc, argv);
    int degree = find_degree(head);
    printf("%d\n", degree);

    free_numbers(head);

    return 0;
}

Node* get_numbers(int argc, char *argv[])
{
    Node *head = NULL;
    Node *current = NULL;

    for (int i = 1; i < argc; i++)
    {
        Node *new_node = calloc(1, sizeof(Node));
        if(!new_node)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        new_node->value = atoi(argv[i]);
        new_node->next = NULL;

        if (!head)
        {
            head = new_node;
            current = new_node;
        }
        else
        {
            current->next = new_node;
            current = new_node;
        }
    }

    return head;
}

int find_degree(Node *head)
{
    int max = 0;

    for(Node *p = head; p != NULL; p = p->next)
    {
        int count = 0;

        for(Node *j = head; j != NULL; j = j->next)
        {
            if(p->value == j->value)
            {
                count++;
            }
        }

        if(count > max)
        {
            max = count;
        }
    }

    return max;
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