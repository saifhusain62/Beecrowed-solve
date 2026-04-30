#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n, b;

    // Read N and B; exit if both are 0
    while (scanf("%d %d", &n, &b) == 2 && (n != 0 || b != 0)) {
        int balls[b];
        bool possible[n + 1];

        // Initialize possibility array to false
        for (int i = 0; i <= n; i++) {
            possible[i] = false;
        }

        // Read the balls present in the bag
        for (int i = 0; i < b; i++) {
            scanf("%d", &balls[i]);
        }

        // Calculate all possible absolute differences
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < b; j++) {
                int diff = abs(balls[i] - balls[j]);
                if (diff <= n) {
                    possible[diff] = true;
                }
            }
        }

        // Check if all numbers from 0 to N are possible
        bool all_covered = true;
        for (int i = 0; i <= n; i++) {
            if (!possible[i]) {
                all_covered = false;
                break;
            }
        }

        // Print 'Y' if all numbers can be formed, otherwise 'N'
        if (all_covered) {
            printf("Y\n");
        } else {
            printf("N\n");
        }
    }

    return 0;
}

