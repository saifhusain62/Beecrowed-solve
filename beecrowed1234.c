#include <stdio.h>

int main() {
    int n; // Size of the square matrix

    // Read input until End-Of-File (EOF) is reached
    while (scanf("%d", &n) != EOF) {
        int i, j; // Loop counters for rows and columns

        // Iterate through each row
        for (i = 0; i < n; i++) {
            // Iterate through each column
            for (j = 0; j < n; j++) {
                // Check for main diagonal
                if (i == j) {
                    printf("1");
                }
                // Check for anti-diagonal
                else if (i + j == n - 1) {
                    printf("2");
                }
                // All other positions
                else {
                    printf("3");
                }
            }
            printf("\n"); // Newline after each row
        }
    }
    return 0;
}
