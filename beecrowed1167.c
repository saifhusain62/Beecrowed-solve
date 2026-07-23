#include <stdio.h>
#include <string.h>

#define MAX_CHILDREN 105

// Structure to model the circular doubly linked list using an array
typedef struct {
    char name[31];
    int token;
    int prev;
    int next;
} Child;

int main() {
    int n;

    // Continue reading until the user enters 0
    while (scanf("%d", &n) && n != 0) {
        Child children[MAX_CHILDREN];

        // Populate the circular list links sequentially
        for (int i = 0; i < n; i++) {
            scanf("%s %d", children[i].name, &children[i].token);
            children[i].prev = (i - 1 + n) % n;
            children[i].next = (i + 1) % n;
        }

        int current_idx = 0;
        int steps = children[current_idx].token;
        int remaining = n;

        // Eliminate children one by one until only one is left
        while (remaining > 1) {
            // Count steps to find the child to eliminate
            if (steps % 2 == 1) { // Odd token -> Clockwise
                for (int i = 0; i < steps; i++) {
                    current_idx = children[current_idx].next;
                }
            } else { // Even token -> Counter-clockwise
                for (int i = 0; i < steps; i++) {
                    current_idx = children[current_idx].prev;
                }
            }

            // Save the token value of the eliminated child for the next round
            steps = children[current_idx].token;

            // Decouple the eliminated child from the circular list
            children[children[current_idx].prev].next = children[current_idx].next;
            children[children[current_idx].next].prev = children[current_idx].prev;

            remaining--;
        }

        // Print the winner (the only remaining child in the list structure)
        printf("Vencedor(a): %s\n", children[children[current_idx].next].name);
    }

    return 0;
}

