/*
Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

// Simple hash map using array (for simplicity)
typedef struct {
    int sum;
    int index;
} Hash;

int maxLenZeroSumSubarray(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Create hash array
    Hash hash[MAX];
    int size = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: If sum becomes 0
        if (sum == 0) {
            maxLen = i + 1;
        }

        // Check if this sum already exists
        int found = 0;
        for (int j = 0; j < size; j++) {
            if (hash[j].sum == sum) {
                int len = i - hash[j].index;
                if (len > maxLen)
                    maxLen = len;
                found = 1;
                break;
            }
        }

        // If sum not found, store it
        if (!found) {
            hash[size].sum = sum;
            hash[size].index = i;
            size++;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = maxLenZeroSumSubarray(arr, n);
    printf("Length of longest subarray with sum 0: %d\n", result);

    return 0;
}