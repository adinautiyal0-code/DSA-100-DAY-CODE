//Implement Selection Sort - Implement the algorithm.


#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];

    // Input array
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }

        // Swap
        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}