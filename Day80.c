// Given a weighted graph with n vertices, implement the Floyd-Warshall algorithm to compute the shortest distances between every pair of vertices. The graph may contain positive or negative edge weights, but it does not contain any negative weight cycles.

#include <stdio.h>

#define MAX 100
#define INF 99999

int main() {
    int n;
    scanf("%d", &n);

    int dist[MAX][MAX];

    // Input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);

            if (x == -1 && i != j)
                dist[i][j] = INF;
            else
                dist[i][j] = x;
        }
    }

    // Floyd-Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Output
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (dist[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}