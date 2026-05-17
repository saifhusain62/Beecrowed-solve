#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Process each block of train coaches
    while (scanf("%d", &n) == 1 && n != 0) {
        int *target = (int *)malloc(n * sizeof(int));
        int *stack = (int *)malloc(n * sizeof(int));

        while (1) {
            // Read the first element of the permutation
            scanf("%d", &target[0]);
            if (target[0] == 0) {
                printf("\n"); // Empty line after each block
                break;
            }

            // Read the remaining elements of the permutation
            for (int i = 1; i < n; i++) {
                scanf("%d", &target[i]);
            }

            int current_coach = 1; // Incoming coaches: 1, 2, ..., N
            int target_idx = 0;    // Pointer for what we need to output
            int top = -1;          // Stack pointer (-1 means empty)

            // Simulate the railway station logic
            while (current_coach <= n) {
                // Push incoming coach to the station (stack)
                stack[++top] = current_coach++;

                // Move coaches from station to side B as long as they match the target
                while (top >= 0 && stack[top] == target[target_idx]) {
                    top--;
                    target_idx++;
                }
            }

            // If the stack is empty, the target permutation is possible
            if (top == -1) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }

        free(target);
        free(stack);
    }

    return 0;
}

