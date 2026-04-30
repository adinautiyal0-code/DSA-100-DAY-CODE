// Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

#include <stdio.h>

#define MAX 1000

// Simple hash map using arrays
int prefix[MAX];
int indexMap[2001]; // to handle negative sums

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Initialize map with -1
    for (int i = 0; i < 2001; i++)
        indexMap[i] = -2;

    int sum = 0, maxLen = 0;

    // Special case: sum = 0 at index -1
    indexMap[1000] = -1;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        int key = sum + 1000; // shift to handle negative

        if (indexMap[key] != -2) {
            int len = i - indexMap[key];
            if (len > maxLen)
                maxLen = len;
        } else {
            indexMap[key] = i;
        }
    }

    printf("%d", maxLen);

    return 0;
}