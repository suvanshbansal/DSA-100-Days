/*
Problem: Implement Binary Search Iterative - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64
*/

#include <stdio.h>

// Function to sort array using simple Bubble Sort
void sort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Iterative Binary Search
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while(left <= right) {
        int mid = (left + right) / 2;

        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // Not found
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Sort array
    sort(arr, n);

    printf("Sorted array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Step 2: Search element
    int target;
    printf("\nEnter element to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, n, target);

    if(result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}