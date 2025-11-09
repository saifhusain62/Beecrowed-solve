#include <stdio.h>

int main() {
    int a, b, q, r;

    // Read the two integers
    scanf("%d %d", &a, &b);

    // Calculate the quotient and remainder using standard division
    q = a / b;
    r = a % b;

    // Adjust q and r if the remainder is negative and the divisor is positive
    // This ensures r is non-negative and satisfies the Euclidean division property
    if (r < 0 && b > 0) {
        q--;
        r += b;
    }
    // Adjust q and r if the remainder is negative and the divisor is negative
    else if (r < 0 && b < 0) {
        q++;
        r -= b; // Subtracting a negative b is equivalent to adding its absolute value
    }

    // Print the calculated quotient and remainder
    printf("%d %d\n", q, r);

    return 0;
}
