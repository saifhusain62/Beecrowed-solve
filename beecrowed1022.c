#include <stdio.h>
#include <stdlib.h>

// Function to calculate GCD using Euclidean algorithm
int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n, n1, d1, n2, d2;
    char op, slash;

    // Read number of test cases
    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        // Read input format: N1 / D1 [op] N2 / D2
        scanf("%d %c %d %c %d %c %d", &n1, &slash, &d1, &op, &n2, &slash, &d2);

        int res_num, res_den;

        // Apply operation logic
        switch (op) {
            case '+':
                res_num = (n1 * d2 + n2 * d1);
                res_den = (d1 * d2);
                break;
            case '-':
                res_num = (n1 * d2 - n2 * d1);
                res_den = (d1 * d2);
                break;
            case '*':
                res_num = (n1 * n2);
                res_den = (d1 * d2);
                break;
            case '/':
                res_num = (n1 * d2);
                res_den = (n2 * d1);
                break;
        }

        // Find simplification factor
        int common = gcd(res_num, res_den);

        // Output format: Original = Simplified
        printf("%d/%d = %d/%d\n", res_num, res_den, res_num / common, res_den / common);
    }

    return 0;
}

