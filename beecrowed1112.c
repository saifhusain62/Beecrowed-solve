#include <stdio.h>
#include <string.h>

#define MAX 1005

int bit[MAX][MAX];
int max_x, max_y;

// Update the number of occurrences at (x, y)
void update(int x, int y, int val) {
    for (int i = x; i <= max_x; i += i & -i) {
        for (int j = y; j <= max_y; j += j & -j) {
            bit[i][j] += val;
        }
    }
}

// Query the prefix sum from (1,1) to (x, y)
int query(int x, int y) {
    int sum = 0;
    for (int i = x; i > 0; i -= i & -i) {
        for (int j = y; j > 0; j -= j & -j) {
            sum += bit[i][j];
        }
    }
    return sum;
}

// Query the subgrid sum between (x1, y1) and (x2, y2)
int query_range(int x1, int y1, int x2, int y2) {
    return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
}

int main() {
    int p, q;

    while (scanf("%d %d %d", &max_x, &max_y, &p) && (max_x || max_y || p)) {
        // Reset the BIT array for each test case
        memset(bit, 0, sizeof(bit));

        scanf("%d", &q);
        while (q--) {
            char type;
            scanf(" %c", &type);

            if (type == 'A') {
                int n, x, y;
                scanf("%d %d %d", &n, &x, &y);
                // 1-based indexing for BIT
                update(x + 1, y + 1, n);
            }
            else if (type == 'P') {
                int x1, y1, x2, y2;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

                // Ensure coordinates are ordered correctly
                int r1 = (x1 < x2) ? x1 : x2;
                int r2 = (x1 > x2) ? x1 : x2;
                int c1 = (y1 < y2) ? y1 : y2;
                int c2 = (y1 > y2) ? y1 : y2;

                int total_schweizers = query_range(r1 + 1, c1 + 1, r2 + 1, c2 + 1);
                printf("%d\n", total_schweizers * p);
            }
        }
        printf("\n");
    }
    return 0;
}

