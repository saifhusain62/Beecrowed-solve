#include <stdio.h>

int main() {
    int k, n, m, x, y;

    // Read the number of queries, break if K is 0
    while (scanf("%d", &k) == 1 && k != 0) {
        scanf("%d %d", &n, &m); // Division point

        for (int i = 0; i < k; i++) {
            scanf("%d %d", &x, &y); // Query point

            // Check if on the division line
            if (x == n || y == m) {
                printf("divisa\n");
            }
            // Check quadrants
            else if (x > n && y > m) {
                printf("NE\n"); // Northeast
            }
            else if (x < n && y > m) {
                printf("NO\n"); // Northwest
            }
            else if (x < n && y < m) {
                printf("SO\n"); // Southwest
            }
            else if (x > n && y < m) {
                printf("SE\n"); // Southeast
            }
        }
    }
    return 0;
}

