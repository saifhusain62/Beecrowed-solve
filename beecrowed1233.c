#include <stdio.h>

// Function to calculate Euler's Totient Function phi(n)
long long phi(long long n) {
    long long result = n;
    long long p;
    
    // Check for prime factors up to sqrt(n)
    for (p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            // If p is a prime factor, subtract multiples of p from result
            while (n % p == 0) {
                n /= p;
            }
            result -= result / p;
        }
    }
    
    // If n has a prime factor greater than sqrt(n) remaining
    if (n > 1) {
        result -= result / n;
    }
    
    return result;
}

int main() {
    long long n;
    
    // Read input until End of File (EOF)
    while (scanf("%lld", &n) != EOF) {
        // The number of unique stars is phi(n) / 2
        printf("%lld\n", phi(n) / 2);
    }
    
    return 0;
}
