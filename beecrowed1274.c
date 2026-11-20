#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;

    while (scanf("%d", &n) == 1 && n != 0) {
        int target[25];
        bool seen[25] = {false};
        bool possible = true;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &target[i]);
            if (target[i] < 1 || target[i] > n || seen[target[i]]) {
                possible = false;
            } else {
                seen[target[i]] = true;
            }
        }

        if (!possible) {
            printf("No solution\n");
            continue;
        }

        int swaps[400];
        int swap_count = 0;

        // Sort the target permutation back to 1..n using adjacent swaps
        for (int i = 1; i <= n; i++) {
            int pos = i;
            // Find where value 'i' is currently located
            while (target[pos] != i) {
                pos++;
            }
            // Bubble 'i' leftwards to index i
            while (pos > i) {
                int temp = target[pos];
                target[pos] = target[pos - 1];
                target[pos - 1] = temp;

                swaps[swap_count++] = pos - 1;
                pos--;
            }
        }

        // Print the total swaps followed by the bridges in reverse order
        printf("%d", swap_count);
        for (int i = swap_count - 1; i >= 0; i--) {
            printf(" %d", swaps[i]);
        }
        printf("\n");
    }

    return 0;
}
