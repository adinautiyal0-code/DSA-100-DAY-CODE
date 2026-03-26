// Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end (circular)
struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    // If list is empty
    if (head == NULL) {
        head = newNode;
        head->next = head; // Point to itself
        return head;
    }

    struct Node* temp = head;

    // Traverse to last node
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head; // Make it circular

    return head;
}

// Traverse circular linked list
void traverse(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head); // Stop when back to head
}

int main() {
    int n, x;
    struct Node* head = NULL;

    // Input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insert(head, x);
    }

    // Output
    traverse(head);

    return 0;
}