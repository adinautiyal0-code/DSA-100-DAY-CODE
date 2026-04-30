// Implement Binary Search Iterative - Implement the algorithm.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];

    // Input array
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Sort array (Bubble Sort for safety)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    int key;
    scanf("%d", &key);

    int low = 0, high = n - 1;
    int found = -1;

    // Binary Search (Iterative)
    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == key) {
            found = mid;
            break;
        }
        else if (a[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (found != -1)
        printf("FOUND at index %d", found);
    else
        printf("-1");

    return 0;
}