/*
Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.
*/
#include <stdio.h>
#include <stdlib.h>

// Node for linked list (bucket)
struct Node {
    float data;
    struct Node* next;
};

// Insert node in sorted order (insertion sort within bucket)
struct Node* insertSorted(struct Node* head, float value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // Insert at beginning or empty list
    if (head == NULL || value < head->data) {
        newNode->next = head;
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL && current->next->data <= value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

// Bucket Sort function
void bucketSort(float arr[], int n)
{
    // Step 1: Create n buckets
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));

    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    // Step 2: Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];   // bucket index
        buckets[index] = insertSorted(buckets[index], arr[i]);
    }

    // Step 3: Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];
        while (temp != NULL) {
            arr[k++] = temp->data;
            struct Node* t = temp;
            temp = temp->next;
            free(t); // free memory
        }
    }

    free(buckets);
}

// Driver code
int main()
{
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}