// SINGLY LINKED LIST

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int value)
{
    Node *n = calloc(1, sizeof(Node));
    if (!n) exit(1);
    n->data = value;
    return n;
}

void pushFront(Node **head, int value)
{
    Node *n = createNode(value);
    n->next = *head;
    *head = n;
}

void pushBack(Node **head, int value)
{
    Node *n = createNode(value);

    if (*head == NULL) {
        *head = n;
        return;
    }
    Node *curr = *head;
    while (curr->next)
        curr = curr->next;
    curr->next = n;
}

void printList(Node *head)
{
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(Node *head)
{
    while (head) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }
}
