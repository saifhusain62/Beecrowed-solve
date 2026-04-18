#include <stdio.h>

int main() {
    int A, C;
    // Read Height (A) and Length (C)
    while (scanf("%d %d", &A, &C) == 2 && (A != 0 || C != 0)) {
        int last_height = A;
        int total_activations = 0;
        int current_height;

        for (int i = 0; i < C; i++) {
            scanf("%d", &current_height);
            // If current height is lower than previous, laser turns on
            if (current_height < last_height) {
                total_activations += (last_height - current_height);
            }
            last_height = current_height;
        }
        printf("%d\n", total_activations);
    }
    return 0;
}

