#include <stdio.h>

int main() {
    int n, l, i, j, swaps, temp;
    int train[50];

    // Read the number of test cases
    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        // Read the length of the train
        if (scanf("%d", &l) != 1) break;

        // Read the initial permutation of the carriage numbers
        for (i = 0; i < l; i++) {
            if (scanf("%d", &train[i]) != 1) break;
        }

        swaps = 0;

        // Bubble sort simulation to count adjacent swaps
        for (i = 0; i < l - 1; i++) {
            for (j = 0; j < l - i - 1; j++) {
                if (train[j] > train[j + 1]) {
                    // Swap adjacent elements
                    temp = train[j];
                    train[j] = train[j + 1];
                    train[j + 1] = temp;
                    swaps++;
                }
            }
        }

        // Print the result exactly as required
        printf("Optimal train swapping takes %d swaps.\n", swaps);
    }

    return 0;
}

