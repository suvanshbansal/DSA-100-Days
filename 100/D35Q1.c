/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.
*/
#include<stdio.h>

int main()
{
    int n;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int queue[n];
    int front = 0, rear = -1;

    // Enqueue elements
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        rear++;
        queue[rear] = val;
    }

    // Display queue
    printf("Queue elements from front to rear:\n");
    for(int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}