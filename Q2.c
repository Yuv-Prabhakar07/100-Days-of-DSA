// Delete an Element from an Array

// Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer pos (1-based position to delete)

// Output:
// - Print the updated array with (n-1) elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 10 30 40 50

// Explanation: Delete position 2 (element 20), remaining elements shift left

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[1000];  // assuming maximum size
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int pos;
    scanf("%d", &pos);

    // Convert 1-based position to 0-based index
    int idx = pos - 1;

    // Shift elements to the left
    for (int i = idx; i < n - 1; i++) {
        a[i] = a[i + 1];
    }

    // Print the updated array (size n-1)
    for (int i = 0; i < n - 1; i++) {
        printf("%d", a[i]);
        if (i != n - 2) printf(" ");
    }

    return 0;
}
