//  Perform DFS starting from a given source vertex using recursion.

#include <stdio.h>

int visited[100];
int adj[100][100]; // adjacency matrix (simpler input handling)
int n;

// DFS function
void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int s;

    scanf("%d", &n);

    // Initialize
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    // Input adjacency list and convert to matrix
    for (int i = 0; i < n; i++) {
        int x;
        while (1) {
            scanf("%d", &x);
            if (x == -1) break;
            adj[i][x] = 1;
        }
    }

    // Starting vertex
    scanf("%d", &s);

    // DFS call
    dfs(s);

    return 0;
}