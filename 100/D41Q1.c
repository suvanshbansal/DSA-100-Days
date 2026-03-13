/*
Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

// Enqueue operation
void enqueue(int x)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if(front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

// Dequeue operation
void dequeue()
{
    if(front == NULL)
    {
        printf("-1\n");
        return;
    }

    struct node* temp = front;
    printf("%d\n", front->data);

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

int main()
{
    int n;
    scanf("%d",&n);

    char op[20];
    int x;

    for(int i=0;i<n;i++)
    {
        scanf("%s",op);

        if(strcmp(op,"enqueue")==0)
        {
            scanf("%d",&x);
            enqueue(x);
        }
        else if(strcmp(op,"dequeue")==0)
        {
            dequeue();
        }
    }

    return 0;
}