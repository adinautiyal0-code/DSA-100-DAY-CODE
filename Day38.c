// A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.


#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int empty() {
    return (front == -1);
}

// Check full
int full() {
    return (rear == MAX - 1);
}

// push_front
void push_front(int x) {
    if (front == 0) {
        printf("Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        front--;
    }
    deque[front] = x;
}

// push_back
void push_back(int x) {
    if (full()) {
        printf("Overflow\n");
        return;
    }
    if (rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
}

// pop_front
void pop_front() {
    if (empty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

// pop_back
void pop_back() {
    if (empty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

// front()
void get_front() {
    if (empty()) printf("-1\n");
    else printf("%d\n", deque[front]);
}

// back()
void get_back() {
    if (empty()) printf("-1\n");
    else printf("%d\n", deque[rear]);
}

// size()
void size() {
    if (empty()) printf("0\n");
    else printf("%d\n", rear - front + 1);
}

// display (final state)
void display() {
    if (empty()) return;
    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'p' && op[5] == 'f') { // push_front
            scanf("%d", &x);
            push_front(x);
        } 
        else if (op[0] == 'p' && op[5] == 'b') { // push_back
            scanf("%d", &x);
            push_back(x);
        } 
        else if (op[0] == 'p' && op[1] == 'o' && op[4] == 'f') { // pop_front
            pop_front();
        } 
        else if (op[0] == 'p' && op[1] == 'o' && op[4] == 'b') { // pop_back
            pop_back();
        } 
        else if (op[0] == 'f') { // front
            get_front();
        } 
        else if (op[0] == 'b') { // back
            get_back();
        } 
        else if (op[0] == 's') { // size
            size();
        }
    }

    // Final state
    display();

    return 0;
}