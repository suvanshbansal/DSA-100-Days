/*
Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations
*/
#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

/* Check if deque is empty */
int empty() {
    return (front == -1);
}

/* Check if deque is full */
int isFull() {
    return (front == 0 && rear == MAX - 1);
}

/* push_front */
void push_front(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }
    else if (front > 0) {
        front--;
    }
    else {
        printf("No space at front\n");
        return;
    }

    deque[front] = value;
}

/* push_back */
void push_back(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = value;
}

/* pop_front */
void pop_front() {
    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[front]);

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

/* pop_back */
void pop_back() {
    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

/* front element */
int frontElement() {
    if (empty()) return -1;
    return deque[front];
}

/* back element */
int backElement() {
    if (empty()) return -1;
    return deque[rear];
}

/* size */
int size() {
    if (empty()) return 0;
    return rear - front + 1;
}

/* display deque */
void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);

    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);
    push_front(1);

    display();

    pop_front();
    pop_back();

    display();

    printf("Front element: %d\n", frontElement());
    printf("Back element: %d\n", backElement());
    printf("Size: %d\n", size());

    return 0;
}