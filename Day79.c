// Find shortest distances from source vertex in a weighted graph with non-negative weights.

#include <stdio.h>
#include <limits.h>

#define MAX 1000

typedef struct {
    int v;
    int dist;
} Node;

int n, m;
int adj[MAX][MAX];

// Min Heap
Node heap[MAX];
int size = 0;

// Swap nodes
void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void pushUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent].dist <= heap[i].dist)
            break;
        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

// Heapify down
void pushDown(int i) {
    int smallest = i;

    while (1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < size && heap[l].dist < heap[smallest].dist)
            smallest = l;
        if (r < size && heap[r].dist < heap[smallest].dist)
            smallest = r;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

// Push into heap
void push(int v, int dist) {
    heap[size].v = v;
    heap[size].dist = dist;
    pushUp(size);
    size++;
}

// Pop min
Node pop() {
    Node root = heap[0];
    heap[0] = heap[--size];
    pushDown(0);
    return root;
}

int empty() {
    return size == 0;
}

void dijkstra(int src) {
    int dist[MAX];
    int visited[MAX] = {0};

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (!empty()) {
        Node curr = pop();
        int u = curr.v;

        if (visited[u])
            continue;

        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (adj[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + adj[u][v] < dist[v]) {

                dist[v] = dist[u] + adj[u][v];
                push(v, dist[v]);
            }
        }
    }

    // Output distances
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = 0;

    int u, v, w;

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