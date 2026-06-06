#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 400

// Stack definition
char stack[MAX];
int top = -1;

void push(char item) {
    stack[++top] = item;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

char peek() {
    if (top == -1) return -1;
    return stack[top];
}

// Function to determine operator precedence
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Main processing function for conversion
void infixToPostfix(char* infix) {
    int i = 0, j = 0;
    char postfix[MAX];
    char ch;

    top = -1; // Reset stack for each test case

    while ((ch = infix[i++]) != '\0' && ch != '\n' && ch != '\r') {
        // If character is alphanumeric, it is an operand; add it directly to output
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If opening parenthesis, push onto the stack
        else if (ch == '(') {
            push(ch);
        }
        // If closing parenthesis, pop and output until an opening parenthesis is found
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '(' from stack
        }
        // If operator encountered
        else {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop all remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate string
    printf("%s\n", postfix);
}

int main() {
    int t;
    char infix[MAX];

    if (scanf("%d", &t) != 1) return 0;

    // Clear newline buffer remaining from scanf
    while (getchar() != '\n');

    while (t--) {
        if (fgets(infix, sizeof(infix), stdin) != NULL) {
            infixToPostfix(infix);
        }
    }

    return 0;
}

