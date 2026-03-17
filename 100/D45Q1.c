/*
Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3
*/
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to calculate the height of the binary tree
int getHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    
    // Return the larger of the two heights plus 1 for the current node
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    int n;
    // Read the number of elements
    if (scanf("%d", &n) != 1) return 1;

    if (n <= 0) {
        printf("0\n");
        return 0;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // If the root is NULL (-1), the height is 0
    if (arr[0] == -1) {
        printf("0\n");
        free(arr);
        return 0;
    }

    // Array-based queue for level-order tree construction
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    // Create the root node and add it to the queue
    struct Node* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (front < rear && i < n) {
        struct Node* curr = queue[front++];

        // Process the left child
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        // Process the right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    // Calculate and print the height
    printf("%d\n", getHeight(root));

    // Cleanup (Free memory)
    free(arr);
    free(queue);
    
    return 0;
}