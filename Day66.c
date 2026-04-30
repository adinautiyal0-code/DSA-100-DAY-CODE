// detect cycle in directed graph using DFS and recursion stack.

#include <stdio.h>

int adj[100][100];
int visited[100];
int recStack[100];
int n;

// DFS function
int dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i] && dfs(i))
                return 1;
            else if (recStack[i])
                return 1;
        }
    }

    recStack[v] = 0; // remove from recursion stack
    return 0;
}

// Check cycle
int hasCycle() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d", &n);

    // Initialize
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    // Input adjacency list → convert to matrix
    for (int i = 0; i < n; i++) {
        int x;
        while (1) {
            scanf("%d", &x);
            if (x == -1) break;
            adj[i][x] = 1;
        }
    }

    if (hasCycle())
        printf("YES");
    else
        printf("NO");

    return 0;
}