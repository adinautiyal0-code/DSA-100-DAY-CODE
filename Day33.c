// Convert an infix expression to postfix notation using stack.

#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char x) {
    stack[++top] = x;
}

// Pop
char pop() {
    return stack[top--];
}

// Peek
char peek() {
    return stack[top];
}

// Check precedence
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {

        // If operand → add to postfix
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }

        // If '(' → push
        else if (ch == '(') {
            push(ch);
        }

        // If ')' → pop until '('
        else if (ch == ')') {
            while (top != -1 && peek() != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        }

        // Operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(ch))
                postfix[k++] = pop();

            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("%s", postfix);

    return 0;
}