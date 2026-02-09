/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored*/

#include <stdio.h>

int main() {
    char str[100];
    int i, len = 0;
    char temp;

    // Input string
    scanf("%s", str);

    // Find length of string
    while (str[len] != '\0') {
        len++;
    }

    // Reverse the string
    for (i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    // Output reversed string
    printf("%s", str);

    return 0;
}
