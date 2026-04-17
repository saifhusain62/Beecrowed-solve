#include <stdio.h>

int main() {
    int B, N, i, d, c, v;

    // Read number of banks (B) and debentures (N)
    while (scanf("%d %d", &B, &N) == 2 && (B != 0 || N != 0)) {
        int reserves[B + 1];

        // Read initial reserves
        for (i = 1; i <= B; i++) {
            scanf("%d", &reserves[i]);
        }

        // Process each debenture
        for (i = 0; i < N; i++) {
            scanf("%d %d %d", &d, &c, &v);
            reserves[d] -= v; // Debtor loses money
            reserves[c] += v; // Creditor gains money
        }

        // Check for bankruptcy
        int possible = 1;
        for (i = 1; i <= B; i++) {
            if (reserves[i] < 0) {
                possible = 0;
                break;
            }
        }

        if (possible) printf("S\n");
        else printf("N\n");
    }

    return 0;
}

