/*
Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)
*/
#include<stdio.h>


int main()
{
    int N;
    printf("enter array size");
    scanf("%d", &N);
    int arr[N],i,element,loc=-1;
    //input array
    printf("enter elements in this array of 5 => \n");
    for (i=0;i<N;i++)
    {
scanf("%d", &arr[i]);
    }

    //element input 
    printf("enter element to search=>\n");
    scanf("%d", &element);

    //search
    for(i=0;i<N;i++)
    {
        if(arr[i]==element)
        {
        loc=i;
        }
    }
   
   if(loc==-1)
    {
        printf("elment not present");
    }
    else
    {
        printf("element is present at index %d", loc);
    }

return 0;
    
}