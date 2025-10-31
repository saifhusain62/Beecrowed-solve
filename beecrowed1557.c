#include <stdio.h>
#include <math.h> // For pow function
#include <string.h> // For strlen

int main() {
    int N;

    while (scanf("%d", &N) == 1 && N != 0) {
        long long matrix[N][N];
        int max_digits = 0;

        // Calculate matrix elements and find max_digits for formatting
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = (long long)pow(2, i + j);
                // Calculate digits of the largest number
                if (i == N - 1 && j == N - 1) {
                    char temp[20]; // Buffer to hold string representation of number
                    sprintf(temp, "%lld", matrix[i][j]);
                    max_digits = strlen(temp);
                }
            }
        }

        // Print the matrix with proper formatting
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%*lld", max_digits, matrix[i][j]);
                if (j < N - 1) {
                    printf(" "); // Space between numbers in a row
                }
            }
            printf("\n"); // Newline after each row
        }
        printf("\n"); // Blank line between test cases
    }

    return 0;
}
