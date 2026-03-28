// Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure for stack
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push operation
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop operation
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

// Evaluate postfix
int evaluatePostfix(char exp[]) {
    int i = 0;

    while (exp[i] != '\0') {

        // Skip spaces
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // If operand (single digit)
        if (isdigit(exp[i])) {
            int num = 0;

            // Handle multi-digit numbers
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(num);
            continue;
        }

        // Operator
        int val2 = pop();
        int val1 = pop();

        switch (exp[i]) {
            case '+': push(val1 + val2); break;
            case '-': push(val1 - val2); break;
            case '*': push(val1 * val2); break;
            case '/': push(val1 / val2); break;
        }

        i++;
    }

    return pop(); // Final result
}

int main() {
    char exp[100];

    // Read full line (with spaces)
    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);

    printf("%d", result);

    return 0;
}