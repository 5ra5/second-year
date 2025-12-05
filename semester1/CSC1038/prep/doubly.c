// DOUBLY LINKED LIST

typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

DNode* createDNode(int value)
{
    DNode *n = calloc(1, sizeof(DNode));
    if (!n) exit(1);
    n->data = value;
    return n;
}

void pushFrontD(DNode **head, int value)
{
    DNode *n = createDNode(value);
    n->next = *head;
    if (*head)
        (*head)->prev = n;
    *head = n;
}

void pushBackD(DNode **head, int value)
{
    DNode *n = createDNode(value);

    if (*head == NULL) {
        *head = n;
        return;
    }

    DNode *curr = *head;
    while (curr->next)
        curr = curr->next;

    curr->next = n;
    n->prev = curr;
}

void printForwardD(DNode *head)
{
    while (head) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeListD(DNode *head)
{
    while (head) {
        DNode *tmp = head;
        head = head->next;
        free(tmp);
    }
}
