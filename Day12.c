// Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).

#include <stdio.h>

int main()
{
    int m, n;
    
    // Input rows and columns
    scanf("%d %d", &m, &n);

    int a[m][n];

    // Input matrix elements
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Check if square matrix
    if(m != n)
    {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    // Check symmetry
    int isSymmetric = 1;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] != a[j][i])
            {
                isSymmetric = 0;
                break;
            }
        }
        if(isSymmetric == 0)
            break;
    }

    // Output result
    if(isSymmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}
