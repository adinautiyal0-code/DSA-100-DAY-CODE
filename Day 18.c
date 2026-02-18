// Given an array of integers, rotate the array to the right by k positions.

#include <stdio.h>

int main() {
    int n, k;

    // Read size of array
    scanf("%d", &n);

    int arr[n], result[n];

    // Read array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read k
    scanf("%d", &k);

    // Handle k greater than n
    k = k % n;

    // Place elements in rotated positions
    for(int i = 0; i < n; i++) {
        result[(i + k) % n] = arr[i];
    }

    // Print rotated array
    for(int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
