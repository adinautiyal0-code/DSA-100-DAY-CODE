 // Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

 #include <stdio.h>
#include <limits.h>

#define MAX 100

int n, m;
int adj[MAX][MAX];

// Min distance vertex (acts like priority queue)
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int src) {
    int dist[MAX], visited[MAX];

    // Initialize
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && adj[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + adj[u][v] < dist[v]) {

                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    // Print result
    for (int i = 0; i < n; i++) {
        printf("%d -> %d = %d\n", src, i, dist[i]);
    }
}

int main() {
    scanf("%d", &n);
    scanf("%d", &m);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    int u, v, w;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; // remove for directed graph
    }

    int src;
    scanf("%d", &src);

    dijkstra(src);

    return 0;
}