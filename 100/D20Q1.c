/*
Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long prefixSum = 0;
    long long count = 0;

    // Using array as hash map (assuming prefix sum range not huge)
    // Shift by MAX to handle negative sums
    long long *freq = (long long *)calloc(2 * MAX + 1, sizeof(long long));

    freq[MAX] = 1;  // prefix sum 0 occurs once initially

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if(freq[prefixSum + MAX] > 0) {
            count += freq[prefixSum + MAX];
        }

        freq[prefixSum + MAX]++;
    }

    printf("%lld\n", count);

    free(freq);
    return 0;
}