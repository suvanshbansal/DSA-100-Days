/*
Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.
*/
#include <stdio.h>
#include <stdlib.h>

// Structure for meeting
typedef struct {
    int start;
    int end;
} Meeting;

// Compare function for sorting by start time
int compare(const void *a, const void *b)
{
    return ((Meeting *)a)->start - ((Meeting *)b)->start;
}

// Swap function
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Min-heapify
void heapify(int heap[], int n, int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

// Insert into min-heap
void insertHeap(int heap[], int *size, int value)
{
    int i = (*size)++;
    heap[i] = value;

    // Fix heap upwards
    while (i != 0 && heap[(i-1)/2] > heap[i])
    {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Extract minimum (root)
int extractMin(int heap[], int *size)
{
    int root = heap[0];
    heap[0] = heap[--(*size)];
    heapify(heap, *size, 0);
    return root;
}

// Get minimum
int getMin(int heap[])
{
    return heap[0];
}

// Function to find minimum rooms
int minMeetingRooms(Meeting arr[], int n)
{
    // Step 1: Sort meetings by start time
    qsort(arr, n, sizeof(Meeting), compare);

    // Min-heap for end times
    int *heap = (int *)malloc(n * sizeof(int));
    int size = 0;

    // Add first meeting
    insertHeap(heap, &size, arr[0].end);

    // Process remaining meetings
    for (int i = 1; i < n; i++)
    {
        // If current meeting starts after earliest end
        if (arr[i].start >= getMin(heap))
        {
            extractMin(heap, &size);
        }

        insertHeap(heap, &size, arr[i].end);
    }

    int result = size;
    free(heap);
    return result;
}

// Driver code
int main()
{
    Meeting arr[] = {{0, 30}, {5, 10}, {15, 20}};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum meeting rooms required: %d\n", minMeetingRooms(arr, n));
    return 0;
}