// Construct a Binary Tree from the given level-order traversal.

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue for tree nodes
struct Node* queue[100];
int front = 0, rear = 0;

// Enqueue
void enqueue(struct Node* node) {
    queue[rear++] = node;
}

// Dequeue
struct Node* dequeue() {
    return queue[front++];
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        struct Node* current = dequeue();

        // Left child
        if (i < n) {
            current->left = createNode(arr[i++]);
            enqueue(current->left);
        }

        // Right child
        if (i < n) {
            current->right = createNode(arr[i++]);
            enqueue(current->right);
        }
    }

    return root;
}

// Inorder traversal (for verification)
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    // Print inorder traversal
    inorder(root);

    return 0;
}