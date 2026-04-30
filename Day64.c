// Perform BFS from a given source using queue.
#include <stdio.h>

int adj[100][100];
int visited[100];
int queue[100];
int front = 0, rear = 0;
int n;

// Enqueue
void enqueue(int x) {
    queue[rear++] = x;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Check if queue is empty
int isEmpty() {
    return front == rear;
}

// BFS function
void bfs(int s) {
    enqueue(s);
    visited[s] = 1;

    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
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

    // Source vertex
    scanf("%d", &s);

    bfs(s);

    return 0;
}