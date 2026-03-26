/*
Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.
*/
#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for level order
struct Queue {
    struct Node* arr[100];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == 99) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct Node* temp = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

// Zigzag Traversal
void zigzagTraversal(struct Node* root) {
    if (!root) return;

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);
    int leftToRight = 1;

    while (!isEmpty(&q)) {
        int size = q.rear - q.front + 1;
        int arr[size];

        for (int i = 0; i < size; i++) {
            struct Node* temp = dequeue(&q);

            // store in correct direction
            int index = leftToRight ? i : (size - i - 1);
            arr[index] = temp->data;

            if (temp->left) enqueue(&q, temp->left);
            if (temp->right) enqueue(&q, temp->right);
        }

        // print level
        for (int i = 0; i < size; i++)
            printf("%d ", arr[i]);
    }
}

// Driver code
int main() {
    // Example Tree:
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4  5  6  7

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    zigzagTraversal(root);

    return 0;
}