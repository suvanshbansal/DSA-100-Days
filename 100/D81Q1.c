/*Problem: Implement Bubble Sort - Implement the algorithm.

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
12 22 25 34 64*/
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        int swapped = 0;  // optimization

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1;
            }
        }

        // if no swaps, array is already sorted
        if (swapped == 0)
            break;
    }
}

int main() {
    int n, i;

    // input size
    scanf("%d", &n);

    int arr[n];

    // input array
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // sorting
    bubbleSort(arr, n);

    // output sorted array
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}