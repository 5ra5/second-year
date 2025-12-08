// LINKED LIST

typedef struct Node {
    int value;
    struct Node *next;
} Node;


Node* mergeSort(Node *head);
Node* merge(Node *a, Node *b);
void splitList(Node *source, Node **frontRef, Node **backRef);

// Main merge sort entry point
Node* mergeSort(Node *head)
{
    // Base case: 0 or 1 element = already sorted
    if (head == NULL || head->next == NULL)
        return head;

    Node *a, *b;

    // Split list into two halves
    splitList(head, &a, &b);

    // Recursively sort each half
    a = mergeSort(a);
    b = mergeSort(b);

    // Merge sorted halves
    return merge(a, b);
}

// Merge two sorted lists
Node* merge(Node *a, Node *b)
{
    // Base cases
    if (a == NULL) return b;
    if (b == NULL) return a;

    Node *result = NULL;

    // Choose smaller value and recurse
    if (a->value <= b->value) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}

// Split list into FRONT and BACK halves
void splitList(Node *source, Node **frontRef, Node **backRef)
{
    Node *slow = source;
    Node *fast = source->next;

    // Fast advances 2, slow advances 1
    // When fast hits the end, slow is middle
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;       // Front half starts at head
    *backRef = slow->next;    // Back half starts after slow
    slow->next = NULL;        // Break the list in two
}

// ARRAY

#include <stdio.h>
#include <stdlib.h>

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

// Merge Sort function
void mergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return;  // 0 or 1 element = already sorted

    int mid = left + (right - left) / 2;

    // Sort both halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge halves
    merge(arr, left, mid, right);
}

// Merge two sorted halves
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temp arrays
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    // Copy data
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    // Merge temp arrays back into arr
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy any remaining elements
    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

