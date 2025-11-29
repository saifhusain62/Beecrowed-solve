#include <stdio.h>

int main() {
    int N;
    while (scanf("%d", &N) == 1 && N != 0) {
        int matrix[N][N];
        int i, j, layer;

        // Fill the matrix layer by layer
        for (layer = 1; layer <= (N + 1) / 2; layer++) {
            int start_row = layer - 1;
            int end_row = N - layer;
            int start_col = layer - 1;
            int end_col = N - layer;

            for (i = start_row; i <= end_row; i++) {
                for (j = start_col; j <= end_col; j++) {
                    matrix[i][j] = layer;
                }
            }
        }

        // Print the matrix with proper formatting
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (j == 0) {
                    printf("%3d", matrix[i][j]);
                } else {
                    printf(" %3d", matrix[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n"); // Print an empty line after each matrix
    }
    return 0;
}

