// Implement a hash table using quadratic probing with formula:

// h(k, i) = (h(k) + i*i) % m

#include <stdio.h>
#include <string.h>

#define EMPTY -1

int table[100];

// Insert using quadratic probing
void insert(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (key % m + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }
}

// Search using quadratic probing
int search(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (key % m + i * i) % m;

        if (table[index] == key)
            return 1;

        if (table[index] == EMPTY)
            return 0;

        i++;
    }
    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    // Initialize table
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    char op[10];
    int x;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &x);

        if (strcmp(op, "INSERT") == 0) {
            insert(x, m);
        }
        else if (strcmp(op, "SEARCH") == 0) {
            if (search(x, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}