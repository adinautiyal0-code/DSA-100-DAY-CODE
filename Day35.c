// Queue Using Array - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue (Insert)
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) { // Empty queue
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Dequeue (Delete)
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct Node* temp = front;
    printf("%d\n", temp->data);

    front = front->next;

    if (front == NULL) // If queue becomes empty
        rear = NULL;

    free(temp);
}

// Display queue
void display() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, type, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &type);

        if (type == 1) {        // Enqueue
            scanf("%d", &value);
            enqueue(value);
        }
        else if (type == 2) {   // Dequeue
            dequeue();
        }
        else if (type == 3) {   // Display
            display();
        }
    }

    return 0;
}