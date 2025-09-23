#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N); // Read the input integer N

    // Iterate from 1 to N to check for divisors
    for (int i = 1; i <= N; i++) {
        // If i divides N evenly, then i is a divisor
        if (N % i == 0) {
            printf("%d\n", i); // Print the divisor
        }
    }

    return 0;
}
