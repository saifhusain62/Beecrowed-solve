#include <stdio.h>

/**
 * beecrowd 1161 - Factorial Sum
 * Solved using long long to prevent overflow.
 */
int main() {
    long long m, n, factM, factN;
    int i;

    // Read two integers until End of File (EOF)
    while (scanf("%lld %lld", &m, &n) != EOF) {
        factM = 1;
        factN = 1;

        // Calculate factorial for M
        for (i = 1; i <= m; i++) {
            factM *= i;
        }

        // Calculate factorial for N
        for (i = 1; i <= n; i++) {
            factN *= i;
        }

        // Output the sum of both factorials
        printf("%lld\n", factM + factN);
    }

    return 0;
}

