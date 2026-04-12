/*
Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.
*/
#include <stdio.h>
#include <string.h>

#define EMPTY -1

int table[100]; // assuming max size

// Hash function
int hash(int key, int m) {
    return key % m;
}

// Insert using quadratic probing
void insert(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }

    printf("Hash table is full\n");
}

// Search using quadratic probing
int search(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == EMPTY)
            return 0; // not found

        if (table[index] == key)
            return 1; // found

        i++;
    }

    return 0;
}

int main() {
    int m, q;
    char operation[10];
    int key;

    scanf("%d", &m);
    scanf("%d", &q);

    // Initialize table
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", operation, &key);

        if (strcmp(operation, "INSERT") == 0) {
            insert(key, m);
        } else if (strcmp(operation, "SEARCH") == 0) {
            if (search(key, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}