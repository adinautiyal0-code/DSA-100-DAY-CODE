// Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

#include <stdio.h>

int adj[100][100];
int visited[100];
int stack[100];
int top = -1;
int n;

// Push to stack
void push(int v) {
    stack[++top] = v;
}

// DFS function
void dfs(int v) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }

    // Push after visiting all neighbors
    push(v);
}

// Topological sort
void topoSort() {
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i);
    }

    // Print stack (reverse order)
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    scanf("%d", &n);

    // Initialize
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
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

    topoSort();

    return 0;
}