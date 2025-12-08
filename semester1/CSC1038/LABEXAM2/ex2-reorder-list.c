// ex2-reorder-list.c (practice after the exam)
// Petra Sartori
//6/12/2025

#include <stdio.h>
#include <stdlib.h>

typedef struct Customer Customer;

struct Customer
{
    int id;
    Customer *next;
};

Customer* get_id(int argc, char *argv[]);
Customer* sort_id(Customer *head);
void print_id(Customer *sorted);
void free_id(Customer *head);

int main(int argc, char *argv[])
{
    Customer *head = NULL;
    head = get_id(argc, argv);

    // not making a new linked list, this is just a pointer to the same linked list
    // but the head is now different - still in place
    Customer *sorted = sort_id(head);

    print_id(sorted);
    free_id(head);

    return 0;
}

Customer* get_id(int argc, char *argv[])
{
    Customer *first = NULL;
    Customer *current = NULL;

    for (int i = 1; i < argc; i++)
    {
        Customer *new_customer = calloc(1, sizeof(Customer));
        if (!new_customer) exit(1);

        new_customer->id = atoi(argv[i]);
        new_customer->next = NULL;

        if (!first)
        {
            first = new_customer;
            current = new_customer;
        }
        else
        {
            current->next = new_customer;
            current = new_customer;
        }
    }

    return first;
}

Customer* sort_id(Customer *head)
{
    // pointers to determine the start and end of evens and odds
    Customer *even_head = NULL, *even_tail = NULL;
    Customer *odd_head = NULL, *odd_tail = NULL;

    Customer *current = head;

    while (current != NULL)
    {
        Customer *next = current->next;
        current->next = NULL;

        // if the current id is even
        if(current->id % 2 == 0)
        {
            // append it to the even part of the list
            if(!even_head)
            {
                even_head = even_tail = current;
            }
            else
            {
                even_tail->next = current;
                even_tail = current;
            }
        }
        else
        {
            // append it to the odd part of the list
            if(!odd_head)
            {
                odd_head = odd_tail = current;
            }
            else
            {
                odd_tail->next = current;
                odd_tail = current;
            }
        }

        current = next;
    }

    // merging two parts together
    if(even_tail)
    {
        even_tail->next = odd_head;
    }

    return even_head ? even_head : odd_head;
}

void print_id(Customer *sorted)
{
    Customer *c = NULL;
    for(c = sorted; c != NULL; c = c->next)
    {
        printf("%d\n", c->id);
    }
}

void free_id(Customer *head)
{
    while(head)
    {
        Customer *tmp = head;
        head = head->next;
        free(tmp);
    }
}