/*
Problem Statement:
Convert a binary tree into its mirror image by swapping left and right children at every node.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print inorder traversal of mirrored tree

Example:
Input:
7
1 2 3 4 5 6 7

Output:
7 3 6 1 5 2 4

Explanation:
Each node’s left and right children are swapped recursively.
*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue for level order construction
struct node* queue[1000];
int front = -1, rear = -1;

void enqueue(struct node* n) {
    queue[++rear] = n;
}

struct node* dequeue() {
    return queue[++front];
}

// Build tree from level order
struct node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        struct node* current = dequeue();

        // Left child
        if (arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(current->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(current->right);
        }
        i++;
    }

    return root;
}

// Mirror function
void mirror(struct node* root) {
    if (root == NULL)
        return;

    // Swap left and right
    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recur for children
    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal
void inorder(struct node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct node* root = buildTree(arr, n);

    mirror(root);

    inorder(root);

    return 0;
}