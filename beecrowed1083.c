#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1005

char stack[MAX];
int top;

int isOperand(char c) {
    return isalnum((unsigned char)c);
}

int isOperator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/' ||
           c=='^' || c=='<' || c=='>' || c=='=' ||
           c=='#' || c=='.' || c=='|';
}

int precedence(char c) {
    switch(c) {
        case '^': return 6;
        case '*':
        case '/': return 5;
        case '+':
        case '-': return 4;
        case '<':
        case '>':
        case '=':
        case '#': return 3;
        case '.': return 2;
        case '|': return 1;
    }
    return 0;
}

int lexicalError(char *s) {
    int i;
    for(i = 0; s[i]; i++) {
        if(!isOperand(s[i]) &&
           !isOperator(s[i]) &&
           s[i] != '(' &&
           s[i] != ')')
            return 1;
    }
    return 0;
}

int syntaxError(char *s) {
    int i, bal = 0;
    int expectOperand = 1;

    for(i = 0; s[i]; i++) {
        char c = s[i];

        if(isOperand(c)) {
            if(!expectOperand)
                return 1;
            expectOperand = 0;
        }
        else if(c == '(') {
            if(!expectOperand)
                return 1;
            bal++;
        }
        else if(c == ')') {
            if(expectOperand)
                return 1;
            bal--;
            if(bal < 0)
                return 1;
        }
        else if(isOperator(c)) {
            if(expectOperand)
                return 1;
            expectOperand = 1;
        }
    }

    if(bal != 0 || expectOperand)
        return 1;

    return 0;
}

void infixToPostfix(char *s) {
    char out[MAX];
    int k = 0;

    top = -1;

    for(int i = 0; s[i]; i++) {
        char c = s[i];

        if(isOperand(c)) {
            out[k++] = c;
        }
        else if(c == '(') {
            stack[++top] = c;
        }
        else if(c == ')') {
            while(top >= 0 && stack[top] != '(')
                out[k++] = stack[top--];

            if(top >= 0)
                top--;
        }
        else {
            while(top >= 0 &&
                  stack[top] != '(' &&
                  (
                    precedence(stack[top]) > precedence(c) ||
                    (precedence(stack[top]) == precedence(c) && c != '^')
                  )) {
                out[k++] = stack[top--];
            }

            stack[++top] = c;
        }
    }

    while(top >= 0)
        out[k++] = stack[top--];

    out[k] = '\0';

    printf("%s\n", out);
}

int main() {
    char expr[MAX];

    while(scanf("%s", expr) != EOF) {

        if(lexicalError(expr)) {
            printf("Lexical Error!\n");
            continue;
        }

        if(syntaxError(expr)) {
            printf("Syntax Error!\n");
            continue;
        }

        infixToPostfix(expr);
    }

    return 0;
}
