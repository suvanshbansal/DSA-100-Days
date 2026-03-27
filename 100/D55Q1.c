/*
Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Create new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Build tree from array
Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    Node* root = createNode(arr[i]);

    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Queue for BFS
Node* queue[1000];
int front = 0, rear = 0;

void enqueue(Node* node) {
    queue[rear++] = node;
}

Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Right View Function
void rightView(Node* root) {
    if (root == NULL)
        return;

    enqueue(root);

    while (!isEmpty()) {
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++) {
            Node* current = dequeue();

            // Last node of this level
            if (i == levelSize - 1)
                printf("%d ", current->data);

            if (current->left)
                enqueue(current->left);

            if (current->right)
                enqueue(current->right);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n, 0);

    rightView(root);

    return 0;
}