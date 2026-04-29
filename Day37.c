// Implement a Priority Queue using an array. An element with smaller value has higher priority.

#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert element in sorted order
void insert(int x) {
    int i = size - 1;

    // Shift elements to maintain ascending order
    while (i >= 0 && pq[i] > x) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = x;
    size++;
}

// Delete highest priority (smallest element)
void delete() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[0]);

    // Shift left
    for (int i = 1; i < size; i++) {
        pq[i - 1] = pq[i];
    }

    size--;
}

// Peek highest priority
void peek() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", pq[0]);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    char op[10];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (op[0] == 'i') { // insert
            scanf("%d", &x);
            insert(x);
        } 
        else if (op[0] == 'd') { // delete
            delete();
        } 
        else if (op[0] == 'p') { // peek
            peek();
        }
    }

    return 0;
}