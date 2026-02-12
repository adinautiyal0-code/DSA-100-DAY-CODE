// Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

#include <stdio.h>

int main() {
    int n;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input sorted array
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // If array is empty
    if(n == 0) {
        return 0;
    }

    int j = 0;  // pointer for unique elements

    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    // Print unique elements (0 to j)
    for(int i = 0; i <= j; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
