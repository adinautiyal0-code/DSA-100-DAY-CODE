// Given an array of n integers, reverse the array in-place using two-pointer approach.

#include <stdio.h>

int main() {
    int n;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Two-pointer approach
    int start = 0;
    int end = n - 1;

    while(start < end) {
        // Swap arr[start] and arr[end]
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    // Print reversed array
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
