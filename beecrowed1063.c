#include <stdio.h>

#define MAX_N 1005

int main() {
    int n;

    // Loop continues until N is 0
    while (scanf("%int", &n) && n != 0) {
        char incoming[MAX_N];
        char outgoing[MAX_N];
        char stack[MAX_N];
        int top = -1;

        // Read the incoming car sequence
        for (int i = 0; i < n; i++) {
            scanf(" %c", &incoming[i]);
        }

        // Read the target outgoing car sequence
        for (int i = 0; i < n; i++) {
            scanf(" %c", &outgoing[i]);
        }

        int in_ptr = 0;
        int out_ptr = 0;

        // Simulate the train movements
        while (in_ptr < n) {
            // Push incoming train car to stack (Movement 'I')
            stack[++top] = incoming[in_ptr++];
            printf("I");

            // Pop from stack if top car matches the current target outgoing car (Movement 'R')
            while (top >= 0 && stack[top] == outgoing[out_ptr]) {
                printf("R");
                top--;
                out_ptr++;
            }
        }

        // If stack is not empty, the configuration is impossible
        if (top >= 0) {
            printf(" Impossible\n");
        } else {
            printf("\n");
        }
    }

    return 0;
}

