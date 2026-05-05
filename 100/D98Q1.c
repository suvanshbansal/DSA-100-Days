/*
Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.
*/
#include <stdio.h>
#include <stdlib.h>

// Structure for interval
typedef struct {
    int start;
    int end;
} Interval;

// Compare function for sorting by start time
int compare(const void *a, const void *b)
{
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

// Function to merge intervals
void mergeIntervals(Interval arr[], int n)
{
    if (n <= 0) return;

    // Step 1: Sort intervals by start time
    qsort(arr, n, sizeof(Interval), compare);

    // Temporary array to store result
    Interval *result = (Interval *)malloc(n * sizeof(Interval));
    int index = 0;

    // Step 2: Merge
    result[index] = arr[0];

    for (int i = 1; i < n; i++)
    {
        // If overlap, merge
        if (arr[i].start <= result[index].end)
        {
            if (arr[i].end > result[index].end)
                result[index].end = arr[i].end;
        }
        else
        {
            // No overlap → move to next
            index++;
            result[index] = arr[i];
        }
    }

    // Print merged intervals
    printf("Merged intervals:\n");
    for (int i = 0; i <= index; i++)
    {
        printf("[%d, %d] ", result[i].start, result[i].end);
    }

    free(result);
}

// Driver code
int main()
{
    Interval arr[] = {{1,3}, {2,6}, {8,10}, {15,18}};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeIntervals(arr, n);
    return 0;
}