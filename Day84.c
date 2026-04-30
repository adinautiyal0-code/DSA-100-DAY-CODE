// Implement Insertion Sort - Implement the algorithm.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];

    // Input array
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Insertion Sort
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        // Shift elements greater than key
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}