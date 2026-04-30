// Implement a Queue using a linked list supporting enqueue and dequeue operations.

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue
void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

// Dequeue
void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = front;
    printf("%d\n", temp->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

// Display queue
void display() {
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, x;
    char op[10];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'e') { // enqueue
            scanf("%d", &x);
            enqueue(x);
        } else if (op[0] == 'd') { // dequeue
            dequeue();
        }
    }

    // Final state of queue
    display();

    return 0;
}