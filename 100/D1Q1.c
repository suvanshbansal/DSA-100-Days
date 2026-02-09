#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n + 1];

    // Input array
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int pos, x;
    printf("Enter position (1-based): ");
    scanf("%d", &pos);

    printf("Enter element to insert: ");
    scanf("%d", &x);

    // Shift elements to the right
    for(int i = n - 1; i >= pos - 1; i--)
    {
        arr[i + 1] = arr[i];
    }

    // Insert element
    arr[pos - 1] = x;

    // Print updated array
    printf("Updated array:\n");
    for(int i = 0; i < n + 1; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
