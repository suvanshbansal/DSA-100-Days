/*
Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

int preIndex = 0;

// Create new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Find index in inorder array
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree
struct node* buildTree(int preorder[], int inorder[], int start, int end) {
    if (start > end)
        return NULL;

    // Pick current root from preorder
    int curr = preorder[preIndex++];
    struct node* root = createNode(curr);

    // If leaf node
    if (start == end)
        return root;

    // Find root in inorder
    int pos = search(inorder, start, end, curr);

    // Build left and right subtrees
    root->left = buildTree(preorder, inorder, start, pos - 1);
    root->right = buildTree(preorder, inorder, pos + 1, end);

    return root;
}

// Postorder traversal
void postorder(struct node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    struct node* root = buildTree(preorder, inorder, 0, n - 1);

    postorder(root);

    return 0;
}