#include <stdio.h>
#include <string.h>

#define MAX_SIZE 305

// Function to check if two bases can form a valid bond
int can_bond(char a, char b) {
    if ((a == 'B' && b == 'S') || (a == 'S' && b == 'B')) return 1;
    if ((a == 'C' && b == 'F') || (a == 'F' && b == 'C')) return 1;
    return 0;
}

int main() {
    char rna[MAX_SIZE];
    char stack[MAX_SIZE];

    // Read input until End of File (EOF)
    while (scanf("%s", rna) != EOF) {
        int top = -1;  // Simulates an empty stack
        int bond_count = 0;
        int length = strlen(rna);

        for (int i = 0; i < length; i++) {
            // If stack is not empty and the current base bonds with the top of the stack
            if (top >= 0 && can_bond(stack[top], rna[i])) {
                bond_count++;  // Valid pair found
                top--;        // Pop from stack
            } else {
                top++;        // Push current character onto the stack
                stack[top] = rna[i];
            }
        }

        // Output total number of connections for the current test case
        printf("%d\n", bond_count);
    }

    return 0;
}

