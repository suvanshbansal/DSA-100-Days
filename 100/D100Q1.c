/*
Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

void merge(Pair arr[], int left, int mid, int right, int count[])
{
    int n = right - left + 1;
    Pair *temp = (Pair *)malloc(n * sizeof(Pair));

    int i = left, j = mid + 1, k = 0;
    int rightCount = 0;

    while (i <= mid && j <= right)
    {
        if (arr[j].val < arr[i].val)
        {
            temp[k++] = arr[j++];
            rightCount++; // smaller element from right
        }
        else
        {
            count[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid)
    {
        count[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    // Copy back
    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];

    free(temp);
}

void mergeSort(Pair arr[], int left, int right, int count[])
{
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid + 1, right, count);
    merge(arr, left, mid, right, count);
}

void countSmaller(int nums[], int n)
{
    Pair *arr = (Pair *)malloc(n * sizeof(Pair));
    int *count = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    mergeSort(arr, 0, n - 1, count);

    printf("Count of smaller elements on right:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", count[i]);

    free(arr);
    free(count);
}

// Driver code
int main()
{
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    countSmaller(nums, n);
    return 0;
}