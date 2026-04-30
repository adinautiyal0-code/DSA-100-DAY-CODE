// Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.

//Lower Bound: The index of the first element in the array that is greater than or equal to x.
//Upper Bound: The index of the first element in the array that is strictly greater than x.
#include <stdio.h>

// Lower Bound
int lowerBound(int a[], int n, int x) {
    int l = 0, r = n;

    while (l < r) {
        int mid = (l + r) / 2;

        if (a[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }

    return l;
}

// Upper Bound
int upperBound(int a[], int n, int x) {
    int l = 0, r = n;

    while (l < r) {
        int mid = (l + r) / 2;

        if (a[mid] > x)
            r = mid;
        else
            l = mid + 1;
    }

    return l;
}

int main() {
    int n, x;

    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &x);

    int lb = lowerBound(a, n, x);
    int ub = upperBound(a, n, x);

    printf("%d %d", lb, ub);

    return 0;
}