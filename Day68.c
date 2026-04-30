// Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>

int adj[100][100];
int indegree[100];
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

int isEmpty() {
    return front == rear;
}

// Topological Sort using Kahn's Algorithm
void topoSort() {
    // Step 1: Calculate indegree
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            if (adj[j][i])
                indegree[i]++;
        }
    }

    // Step 2: Add nodes with indegree 0 to queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    int count = 0;

    // Step 3: Process queue
    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);
        count++;

        // Reduce indegree of neighbors
        for (int i = 0; i < n; i++) {
            if (adj[v][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    // If not all vertices processed → cycle exists
    if (count != n)
        printf("\nCycle detected, topological sort not possible");
}

// Main
int main() {
    scanf("%d", &n);

    // Initialize
    for (int i = 0; i < n; i++) {
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