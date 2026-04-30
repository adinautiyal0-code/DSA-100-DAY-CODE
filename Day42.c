// Given a queue of integers, reverse the queue using a stack.

#include <stdio.h>

#define MAX 100

// Queue
int queue[MAX];
int front = -1, rear = -1;

// Stack
int stack[MAX];
int top = -1;

// Queue operations
void enqueue(int x) {
    if (rear == MAX - 1) return;

    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1) return -1;

    int val = queue[front++];
    if (front > rear) front = rear = -1;

    return val;
}

int isQueueEmpty() {
    return (front == -1);
}

// Stack operations
void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int isStackEmpty() {
    return (top == -1);
}

// Reverse queue using stack
void reverseQueue() {
    // Step 1: Queue → Stack
    while (!isQueueEmpty()) {
        push(dequeue());
    }

    // Step 2: Stack → Queue
    while (!isStackEmpty()) {
        enqueue(pop());
    }
}

// Display queue
void display() {
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}

int main() {
    int n, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    reverseQueue();

    display();

    return 0;
}