#include <stdio.h>
#include <stdlib.h>

// Function to find the Greatest Common Divisor
int gcd(int a, int b) {
    if (b == 0) return a < 0 ? -a : a; // Return positive GCD
    return gcd(b, a % b);
}

int main() {
    int n, n1, d1, n2, d2, resNum, resDen, common;
    char op, slash;

    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        // Read format: N1 / D1 [OP] N2 / D2
        scanf("%d %c %d %c %d %c %d", &n1, &slash, &d1, &op, &n2, &slash, &d2);

        if (op == '+') {
            resNum = (n1 * d2 + n2 * d1);
            resDen = (d1 * d2);
        } else if (op == '-') {
            resNum = (n1 * d2 - n2 * d1);
            resDen = (d1 * d2);
        } else if (op == '*') {
            resNum = (n1 * n2);
            resDen = (d1 * d2);
        } else if (op == '/') {
            resNum = (n1 * d2);
            resDen = (n2 * d1);
        }

        // Find the absolute GCD to simplify the fraction
        common = gcd(resNum, resDen);

        printf("%d/%d = %d/%d\n", resNum, resDen, resNum / common, resDen / common);
    }

    return 0;
}

