#include <stdio.h>

int main() {
    int N, X, i, sum_divisors;

    // Read the number of test cases
    scanf("%d", &N);

    // Loop through each test case
    while (N--) {
        // Read the number to check
        scanf("%d", &X);

        sum_divisors = 0; // Reset sum for each new number

        // Iterate from 1 up to (X - 1) to find proper divisors
        for (i = 1; i < X; i++) {
            if (X % i == 0) { // If 'i' is a divisor of 'X'
                sum_divisors += i; // Add it to the sum
            }
        }

        // Check if the sum of proper divisors equals the number itself
        if (sum_divisors == X) {
            printf("%d eh perfeito\n", X);
        } else {
            printf("%d nao eh perfeito\n", X);
        }
    }

    return 0;
}
