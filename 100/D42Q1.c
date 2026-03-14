/*
Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10
*/
#include <stdio.h>

#define MAX 100

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Queue structure
struct Queue {
    int arr[MAX];
    int front, rear;
};

// Stack functions
void push(struct Stack *s, int x) {
    s->arr[++s->top] = x;
}

int pop(struct Stack *s) {
    return s->arr[s->top--];
}

// Queue functions
void enqueue(struct Queue *q, int x) {
    q->arr[++q->rear] = x;
}

int dequeue(struct Queue *q) {
    return q->arr[q->front++];
}

int main() {
    int n, i, x;

    struct Queue q;
    struct Stack s;

    q.front = 0;
    q.rear = -1;
    s.top = -1;

    // Input
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
    }

    // Move queue elements to stack
    for(i = 0; i < n; i++) {
        push(&s, dequeue(&q));
    }

    // Move stack elements back to queue
    for(i = 0; i < n; i++) {
        enqueue(&q, pop(&s));
    }

    // Print reversed queue
    for(i = q.front; i <= q.rear; i++) {
        printf("%d ", q.arr[i]);
    }

    return 0;
}