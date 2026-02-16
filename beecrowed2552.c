#include <stdio.h>

int main() {
    int n, m, i, j, k;
    // Read n and m until EOF
    while (scanf("%d %d", &n, &m) != EOF) {
        int ar[n][m];
        // Read the matrix
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                scanf("%d", &ar[i][j]);
            }
        }

        // Process each cell
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                k = 0;
                if (ar[i][j] == 1) {
                    printf("9");
                } else {
                    // Check adjacent cells (up, down, left, right)
                    if (i + 1 < n && ar[i + 1][j] == 1) k++;
                    if (i - 1 >= 0 && ar[i - 1][j] == 1) k++;
                    if (j + 1 < m && ar[i][j + 1] == 1) k++;
                    if (j - 1 >= 0 && ar[i][j - 1] == 1) k++;
                    printf("%d", k);
                }
            }
            printf("\n"); // Newline after each row
        }
    }
    return 0;
}

