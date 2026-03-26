// Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Get length
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Rotate right by k
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || k == 0)
        return head;

    int n = getLength(head);

    // Handle k > n
    k = k % n;
    if (k == 0)
        return head;

    struct Node* temp = head;

    // Go to last node
    while (temp->next != NULL)
        temp = temp->next;

    // Make circular
    temp->next = head;

    // Find (n-k)th node
    int steps = n - k;
    struct Node* newTail = head;

    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    // New head
    struct Node* newHead = newTail->next;

    // Break the circle
    newTail->next = NULL;

    return newHead;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k, x;
    struct Node* head = NULL;

    // Input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insert(head, x);
    }

    scanf("%d", &k);

    // Rotate
    head = rotateRight(head, k);

    // Output
    printList(head);

    return 0;
}