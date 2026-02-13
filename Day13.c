// You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

#include <stdio.h>

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);

    int a[r][c];

    // Input matrix
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    // Spiral traversal
    while(top <= bottom && left <= right)
    {
        // 1. Left to Right
        for(int j = left; j <= right; j++)
            printf("%d ", a[top][j]);
        top++;

        // 2. Top to Bottom
        for(int i = top; i <= bottom; i++)
            printf("%d ", a[i][right]);
        right--;

        // 3. Right to Left (check condition)
        if(top <= bottom)
        {
            for(int j = right; j >= left; j--)
                printf("%d ", a[bottom][j]);
            bottom--;
        }

        // 4. Bottom to Top (check condition)
        if(left <= right)
        {
            for(int i = bottom; i >= top; i--)
                printf("%d ", a[i][left]);
            left++;
        }
    }

    return 0;
}
