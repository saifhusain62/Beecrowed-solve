#include <stdio.h>

// Function to calculate Ackermann function values efficiently using closed formulas
long long ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    if (m == 1) {
        return n + 2;
    }
    if (m == 2) {
        return 2 * n + 3;
    }
    if (m == 3) {
        return (1LL << (n + 3)) - 3; // 2^(n+3) - 3
    }
    if (m == 4) {
        if (n == 0) return 13;       // A(4, 0) = A(3, 1) = 13
        if (n == 1) return 65533;    // A(4, 1) = A(3, 13) = 2^16 - 3 = 65533
    }
    return 0;
}

int main() {
    int t;
    // Read the number of test cases
    if (scanf("%d", &t) != 1) return 0;
    
    while (t--) {
        int m, n;
        if (scanf("%d %d", &m, &n) == 2) {
            printf("%lld\n", ackermann(m, n));
        }
    }
    
    return 0;
}
