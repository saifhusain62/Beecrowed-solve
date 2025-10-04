#include <stdio.h>

int main() {
    int T, N, i;
    long long int fib[61]; // Array to store Fibonacci numbers up to index 60

    // Pre-calculate Fibonacci numbers
    fib[0] = 0;
    fib[1] = 1;
    for (i = 2; i <= 60; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Read the number of test cases
    scanf("%d", &T);

    // Process each test case
    while (T--) {
        scanf("%d", &N); // Read the index N
        printf("Fib(%d) = %lld\n", N, fib[N]); // Print the N-th Fibonacci number
    }

    return 0;
}
