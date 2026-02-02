/*Delete an Element from an Array

Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left
*/
#include<stdio.h>

int main()
{

    int N;
    printf("enter the size of array \n");
    scanf("%d", &N);

    int LA[N];
    printf("enter elements\n");
    for(int i=0;i<N;i++)
    {
       scanf("%d", &LA[i]);
    }

    int item,j,k;
    printf("enter the index where element is to be deleted");
    scanf("%d", &k);
    item=LA[k];
    for(j=k;j<N-1;j++)
    {
        LA[j]=LA[j+1];
    
    }

    for(int i=0;i<N-1;i++)
    {

        printf("%d\t", LA[i]);
    }
    printf("\n deleted item is %d", item);
return 0;
    
}